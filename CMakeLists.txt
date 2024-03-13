cmake_minimum_required(VERSION 3.27)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_STANDARD 99)
set(MCU atmega2560)

set(NAME "Colossal-Cave-Adventure")
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 1)
project(${NAME} LANGUAGES C)

option(TESTS "Build ${PROJECT_NAME} Tests with standard gcc" OFF)

set(TOOLCHAIN_PATH "C:/Program Files/JetBrains/CLion 2023.3.4/bin/avr8-gnu-toolchain-win32_x86_64/bin/")
set(AVR_OBJCOPY "${TOOLCHAIN_PATH}avr-objcopy.exe")
set(AVR_SIZE "${TOOLCHAIN_PATH}avr-size.exe")


set(CSTANDARD "-std=gnu99")

if (TESTS)
    set(CDEBUG "-g -ggdb --coverage")
else ()
    set(CDEBUG "-g -ggdb")
    set(CMCU "-mmcu=${MCU}  -B \"C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/ATmega_DFP/2.1.506/gcc/dev/atmega2560\"")
    set(CTUNING "-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -ffunction-sections -fdata-sections")
    set(COPT "-Os -lm")
    set(CWARN "-Wall -Wextra -Wstrict-prototypes -Wl,--gc-sections -Wl,--relax")
endif ()
set(CFLAGS "${CMCU} ${COPT} ${CWARN} ${CSTANDARD} ${CTUNING} ${CDEBUG}")
set(CMAKE_C_FLAGS "${CFLAGS}")

set(INCL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SRC_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(EXTERN_PATH "${CMAKE_CURRENT_SOURCE_DIR}/extern")

set(SRC_FILES
        "${SRC_PATH}/actions.c"
        "${SRC_PATH}/caves.c"
        "${SRC_PATH}/database.c"
        "${SRC_PATH}/english.c"
        "${SRC_PATH}/itverb.c"
        "${SRC_PATH}/long_locations.c"
        "${SRC_PATH}/objects.c"
        "${SRC_PATH}/short_locations.c"
        "${SRC_PATH}/turn.c"
        "${SRC_PATH}/verb.c"
)

set(HEADER_FILES

)

if (TESTS)

else ()
    include_directories(${INCL_PATH})
    set(BUILD_DWARFOS_AS_LIBRARY ON CACHE BOOL "Build DwarfOS as a library")
    add_definitions(-D_TIME_T_DEFINED)
    add_definitions(-DDWARF_TIME)
    add_subdirectory(${EXTERN_PATH}/dwarfOS extern_build)


    add_executable(${PROJECT_NAME} ${SRC_FILES} "${SRC_PATH}/colossal_cave_adventure.c")
    target_include_directories(${PROJECT_NAME} PUBLIC ${INCL_PATH})
    target_link_libraries(${PROJECT_NAME} DwarfOS)
    set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}.elf")


    add_custom_target(hex "${AVR_OBJCOPY}" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures
            "${PROJECT_NAME}.elf" "${PROJECT_NAME}.hex")

    add_custom_target(size "${AVR_SIZE}" "${PROJECT_NAME}.elf")
endif ()

if (TESTS)
    set(TEST_PATH "${CMAKE_CURRENT_SOURCE_DIR}/tests")
    include_directories("${TEST_PATH}/_include" ${INCL_PATH} "${EXTERN_PATH}/dwarfOS/include")
    add_definitions(-DCCA_TEST)
    # adjust to your system
    set(CMAKE_SYSTEM_NAME Windows)


    # build Unity
    add_subdirectory(${EXTERN_PATH}/Unity extern_build_unity)


    # string_repository.c
    add_executable(${PROJECT_NAME}_string_db_conversion
            "${TEST_PATH}/string_db_conversion.c"
            "${SRC_PATH}/long_locations.c"
            "${SRC_PATH}/short_locations.c"
            "${SRC_PATH}/actions.c"
            "${SRC_PATH}/objects.c"
            "${SRC_PATH}/caves.c"
            "${SRC_PATH}/word_code_table.c"

            "extern/dwarfOS/src/string_repository.c"
            "extern/dwarfOS/src/pgm_textfile_generator.c"
            "tests/_src/_flash_helper.c")
    target_link_libraries(${PROJECT_NAME}_string_db_conversion unity)

    include(CTest)
    #    add_test(LongLocations ${PROJECT_NAME}_string_db_conversion)

endif ()
set_directory_properties(PROPERTIES
        ADDITIONAL_MAKE_CLEAN_FILES "${PROJECT_NAME}.hex;${PROJECT_NAME}.eeprom;${PROJECT_NAME}.lst")