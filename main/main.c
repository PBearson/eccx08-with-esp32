/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <unistd.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "cryptoauthlib.h"
#include "driver/i2c.h"
#include "crypto_settings.h"

/*
 * Set ATCA configuration
 */
ATCAIfaceCfg atca_cfg_init()
{
	ATCADeviceType type;
	if (strcmp(ECCX08_TYPE, "608") == 0) type = ATECC608A;
	else if (strcmp(ECCX08_TYPE, "508") == 0) type = ATECC508A;
	else if (strcmp(ECCX08_TYPE, "204") == 0) type = ATSHA204A;
	else if (strcmp(ECCX08_TYPE, "108") == 0) type = ATECC108A;
	else type = ATCA_DEV_UNKNOWN;

	ATCAIfaceCfg cfg = {
		.iface_type		= ATCA_I2C_IFACE,
		.devtype		= type,
		.atcai2c.slave_address	= ECCX08_ADDRESS,
		.atcai2c.bus		= I2C_PORT + 1,
		.atcai2c.baud		= BAUD_SPEED,
		.wake_delay		= 1500,
		.rx_retries		= 20
	};
	return cfg;
}

/*
 * Set I2C configuration
 */
int i2c_init()
{
	i2c_config_t conf;
	conf.mode = I2C_MODE_MASTER;
	conf.sda_io_num = SDA_GPIO;
	conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
	conf.scl_io_num = SCL_GPIO;
	conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
	conf.master.clk_speed = BAUD_SPEED;
	i2c_param_config(I2C_PORT, &conf);
	return i2c_driver_install(I2C_PORT, conf.mode, 0, 0, 0);
}

/*
 * Start here
 */
void app_main()
{
	ATCAIfaceCfg cfg = atca_cfg_init();	
	i2c_init();
	int ret = atcab_init(&cfg);	
	if (ret == 0) printf("Your cryptochip is successfully connected!\n");
	else printf("There is a problem. Error code %d. Refer here for more information:\n%s\n", ret, "https://github.com/MicrochipTech/cryptoauthlib/blob/master/lib/atca_status.h");
}
