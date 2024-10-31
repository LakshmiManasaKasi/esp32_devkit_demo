#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define IR_SENSOR_GPIO_PIN  23

void ObjectDetection()
{
    // GPIO Pin configuration ---------
    gpio_config_t Pinconfig;
    Pinconfig.intr_type = GPIO_INTR_DISABLE;
    Pinconfig.mode= GPIO_MODE_INPUT;
    Pinconfig.pin_bit_mask = (1UL<<IR_SENSOR_GPIO_PIN);
    Pinconfig.pull_down_en=GPIO_PULLDOWN_ENABLE;
    Pinconfig.pull_up_en=GPIO_PULLUP_DISABLE;
    gpio_config(&Pinconfig);
    //GPIO Configurations complete ------------
    while(1)
    {
        int ir_value = gpio_get_level(IR_SENSOR_GPIO_PIN); //Read the level of GPIO
        if (ir_value ==0)
        {
            printf("Object Detected....STOP....\n");
        }
        else
        {
            printf("No object Detected..You can go\n");
        }
        vTaskDelay(20 * portTICK_PERIOD_MS); //2 sec delay 
    }

}
