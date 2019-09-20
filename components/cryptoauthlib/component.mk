CRYPTOAUTHLIB_DIR := lib

COMPONENT_SRCDIRS := $(CRYPTOAUTHLIB_DIR)/atcacert \
                     $(CRYPTOAUTHLIB_DIR)/basic \
                     $(CRYPTOAUTHLIB_DIR)/crypto \
                     $(CRYPTOAUTHLIB_DIR)/crypto/hashes \
                     $(CRYPTOAUTHLIB_DIR)/host \
                     $(CRYPTOAUTHLIB_DIR)/mbedtls \
                     $(CRYPTOAUTHLIB_DIR)

COMPONENT_ADD_INCLUDEDIRS := $(CRYPTOAUTHLIB_DIR)

CFLAGS+=-DESP32 -DATCA_HAL_I2C -DATCA_PRINTF
