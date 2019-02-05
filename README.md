# ECCX08 With ESP32

Download or clone this repository into your ESP-IDF workspace in order to begin working with the Microchip ECCX08 cryptochip series on the ESP32!

To get started, you will need to edit the "main/crypto_settings.h" file to reflect your configuration. For example, if you are using the ATECC508A chip, you need to change ECCX08_TYPE to "508". You will also likely need to change the SDA and SCL pins, which are currently configured for the HelTec WiFi Kit 32 board.

The "main/main.c" file does not need to be changed in order to test connectivity. If the configuration is right, this project will output a success message on boot.
