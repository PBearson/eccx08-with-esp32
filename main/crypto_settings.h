// I2C master port on host
#define I2C_PORT                0

// SDA pin
#define SDA_GPIO                4

// SCL pin
#define SCL_GPIO                15

// I2C baud rate
#define BAUD_SPEED              400000

// Cryptochip type
#define ECCX08_TYPE             "608"

// Cryptochip address
#define ECCX08_ADDRESS          0XC0

#include "cryptoauthlib.h"

/*
 * Initialize ATCA configuration
 */
ATCAIfaceCfg atca_cfg_init()
{
	ATCADeviceType type;

	if(strcmp(ECCX08_TYPE, "608") == 0) type = ATECC608A;
	else if(strcmp(ECCX08_TYPE, "508") == 0) type = ATECC508A;
	else if(strcmp(ECCX08_TYPE, "204") == 0) type = ATSHA204A;
	else if(strcmp(ECCX08_TYPE, "108") == 0) type = ATECC108A;
	else type = ATCA_DEV_UNKNOWN;

	ATCAIfaceCfg cfg = 
	{
		.iface_type 			= ATCA_I2C_IFACE,
		.devtype			= type,
		.atcai2c.slave_address		= ECCX08_ADDRESS,
		.atcai2c.bus			= I2C_PORT + 1,
		.atcai2c.baud			= BAUD_SPEED,
		.wake_delay			= 1500,
		.rx_retries			= 20
	};
	return cfg;
}

/*
 * Initialize I2C configuration
 */
int i2c_init()
{
	i2c_config_t conf = 
	{
		.mode 				= I2C_MODE_MASTER,
		.sda_io_num			= SDA_GPIO,
		.sda_pullup_en			= GPIO_PULLUP_ENABLE,
		.scl_io_num			= SCL_GPIO,
		.scl_pullup_en			= GPIO_PULLUP_ENABLE,
		.master.clk_speed		= BAUD_SPEED,
	};

	i2c_param_config(I2C_PORT, &conf);

	return i2c_driver_install(I2C_PORT, conf.mode, 0, 0, 0);
}
