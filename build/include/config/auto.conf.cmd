deps_config := \
	/home/bryan/esp/esp-idf/components/app_trace/Kconfig \
	/home/bryan/esp/esp-idf/components/aws_iot/Kconfig \
	/home/bryan/esp/esp-idf/components/bt/Kconfig \
	/home/bryan/esp/esp-idf/components/driver/Kconfig \
	/home/bryan/esp/esp-idf/components/esp32/Kconfig \
	/home/bryan/esp/esp-idf/components/esp_adc_cal/Kconfig \
	/home/bryan/esp/esp-idf/components/esp_event/Kconfig \
	/home/bryan/esp/esp-idf/components/esp_http_client/Kconfig \
	/home/bryan/esp/esp-idf/components/esp_http_server/Kconfig \
	/home/bryan/esp/esp-idf/components/ethernet/Kconfig \
	/home/bryan/esp/esp-idf/components/fatfs/Kconfig \
	/home/bryan/esp/esp-idf/components/freemodbus/Kconfig \
	/home/bryan/esp/esp-idf/components/freertos/Kconfig \
	/home/bryan/esp/esp-idf/components/heap/Kconfig \
	/home/bryan/esp/esp-idf/components/libsodium/Kconfig \
	/home/bryan/esp/esp-idf/components/log/Kconfig \
	/home/bryan/esp/esp-idf/components/lwip/Kconfig \
	/home/bryan/esp/esp-idf/components/mbedtls/Kconfig \
	/home/bryan/esp/esp-idf/components/mdns/Kconfig \
	/home/bryan/esp/esp-idf/components/mqtt/Kconfig \
	/home/bryan/esp/esp-idf/components/nvs_flash/Kconfig \
	/home/bryan/esp/esp-idf/components/openssl/Kconfig \
	/home/bryan/esp/esp-idf/components/pthread/Kconfig \
	/home/bryan/esp/esp-idf/components/spi_flash/Kconfig \
	/home/bryan/esp/esp-idf/components/spiffs/Kconfig \
	/home/bryan/esp/esp-idf/components/tcpip_adapter/Kconfig \
	/home/bryan/esp/esp-idf/components/vfs/Kconfig \
	/home/bryan/esp/esp-idf/components/wear_levelling/Kconfig \
	/home/bryan/esp/esp-idf/components/bootloader/Kconfig.projbuild \
	/home/bryan/esp/esp-idf/components/esptool_py/Kconfig.projbuild \
	/home/bryan/esp/esp-idf/components/partition_table/Kconfig.projbuild \
	/home/bryan/esp/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)

ifneq "$(IDF_CMAKE)" "n"
include/config/auto.conf: FORCE
endif

$(deps_config): ;
