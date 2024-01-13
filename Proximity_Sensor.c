 #include <stdio.h>
 #include "pico/stdlib.h"
 #include "hardware/adc.h"

#define SENSOR_PIN 26  //GPIO 26 will be mapped to the Proximity Sensor
#define RED_PIN 15  //GPIO 15 will be mapped to the Red part of the RGB LED component

void setup() {
    gpio_init(RED_PIN); // Initialize LED pin
    adc_init();
    adc_gpio_init(SENSOR_PIN);// Initialize LED pin
    gpio_set_dir(RED_PIN, GPIO_OUT); // Setting the pin to be output 
    gpio_set_dir(SENSOR_PIN, GPIO_IN); // Setting the pin to be output 
    gpio_put(RED_PIN, 0); // Initialize RED_PIN with 0 to be turned off initially
    gpio_put(SENSOR_PIN, 0); // Initialize BLUE_PIN with 0 to be turned off initially
}

int main() {
    stdio_init_all(); // Initialize chosen serial port
    setup(); // Calling my setup function

    while (true) {
        uint16_t sensor_value = adc_read();  // Read analog sensor value
        printf("Sensor Value: %d\n", sensor_value);

        if (sensor_value < 500) {  // Adjust this threshold according to your sensor's characteristics
            gpio_put(RED_PIN, 1);
        } else {
            gpio_put(RED_PIN, 0);
        }
       

    }
    return 0;
}
