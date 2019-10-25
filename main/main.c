#include <stdio.h>
#include "cryptoauthlib.h"
#include "driver/i2c.h"
#include "crypto_settings.h"
#include "freertos/task.h"

void check_error(int ret)
{
	if(ret == 0) return;
	printf("There is a problem. Error code %d. Refer here for more information:\n%s\n", ret, "https://github.com/MicrochipTech/cryptoauthlib/blob/master/lib/atca_status.h");
	while(true) vTaskDelay(1000 / portTICK_PERIOD_MS);
}

/*
 * Start here
 */
void app_main()
{
	ATCAIfaceCfg cfg = atca_cfg_init();	
	i2c_init();
	check_error(atcab_init(&cfg));	
	printf("Your cryptochip is successfully connected!\n\n");

	uint8_t config_zone[128];

	check_error(atcab_read_config_zone(config_zone));

	printf("Config zone:\n");
	for(int i = 0; i < 127; i++) printf("%u, ", config_zone[i]);
	printf("%u\n", config_zone[127]);
}
