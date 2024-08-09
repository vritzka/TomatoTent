file(GLOB_RECURSE SRC_UI ${CMAKE_SOURCE_DIR} "ui/*.c" "ui/images/*.c" "includes/scd4x/*.c")

idf_component_register(SRCS "main.c"
"guiTask.c"
"timerTask.c"
"general.c"
"otaTask.c"
"sensorTask.c"
"esp_zigbee_gateway.c"
"httpTask.c"
${SRC_UI}

INCLUDE_DIRS "." "ui")

idf_build_get_property(python PYTHON)
if(CONFIG_ZIGBEE_GW_AUTO_UPDATE_RCP)
    add_custom_target(rcp_image_generation ALL
    COMMAND ${python} ${CMAKE_CURRENT_SOURCE_DIR}/../create_ota_image.py
    --rcp-build-dir ${IDF_PATH}/examples/openthread/ot_rcp/build
    --target-file ${CMAKE_CURRENT_BINARY_DIR}/spiffs_image/ot_rcp_0/rcp_image
    )
    spiffs_create_partition_image(rcp_fw ${CMAKE_CURRENT_BINARY_DIR}/spiffs_image FLASH_IN_PROJECT
                                DEPENDS rcp_image_generation)
endif()


