set(
	srcs
	"lib/atca_cfgs.c"
	"lib/atca_command.c"
	"lib/atca_device.c"
	"lib/atca_execution.c"
	"lib/atca_iface.c"

	"lib/basic/atca_basic.c"
	"lib/basic/atca_basic_sign.c"
	"lib/basic/atca_basic_verify.c"
	"lib/basic/atca_basic_nonce.c"
	"lib/basic/atca_basic_random.c"
	"lib/basic/atca_basic_read.c"
	
	"lib/hal/atca_hal.c"
	"lib/hal/hal_esp32_i2c.c"
	"lib/hal/hal_esp32_timer.c")

set(
	dirs
	"lib")

set(
	priv_dirs
	"lib/basic"
	"lib/hal")

idf_component_register(
	SRCS "${srcs}"
	INCLUDE_DIRS "${dirs}"
	PRIV_INCLUDE_DIRS "${priv_dirs}")

target_compile_options(
	${COMPONENT_LIB} PRIVATE -DESP32 -DATCA_HAL_I2C -DATCA_PRINTF)


#CRYPTOAUTHLIB_DIR := lib

#COMPONENT_SRCDIRS := $(CRYPTOAUTHLIB_DIR)/atcacert \
#                     $(CRYPTOAUTHLIB_DIR)/basic \
#                     $(CRYPTOAUTHLIB_DIR)/crypto \
#                     $(CRYPTOAUTHLIB_DIR)/crypto/hashes \
#                     $(CRYPTOAUTHLIB_DIR)/host \
#                     $(CRYPTOAUTHLIB_DIR)/mbedtls \
#                     $(CRYPTOAUTHLIB_DIR)

#COMPONENT_ADD_INCLUDEDIRS := $(CRYPTOAUTHLIB_DIR)

#CFLAGS+=-DESP32 -DATCA_HAL_I2C -DATCA_PRINTF
