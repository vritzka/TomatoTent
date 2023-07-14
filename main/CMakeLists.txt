file(GLOB_RECURSE SRC_UI ${CMAKE_SOURCE_DIR} "ui/*.c" "ui/images/*.c" "includes/scd4x/*.c")

idf_component_register(SRCS "main.c" "guiTask.c" "timerTask.c" "general.c" "otaTask.c" "sensorTask.c" ${SRC_UI}
                    INCLUDE_DIRS "." "ui")


