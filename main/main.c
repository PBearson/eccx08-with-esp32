/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "cryptoauthlib.h"
#include "driver/i2c.h"
#include "crypto_settings.h"

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
