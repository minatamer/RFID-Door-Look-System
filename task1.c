#include "pico/stdlib.h"

#define RED_PIN 15  //GPIO 15 will be mapped to the Red part of the RGB LED component
#define GREEN_PIN 14 //GPIO 14 will be mapped to the Green part of the RGB LED component
#define BLUE_PIN 16 //GPIO 16 will be mapped to the Blue part of the RGB LED component

void setup() {
    gpio_init(RED_PIN); // Initialize LED pin
    gpio_init(GREEN_PIN); // Initialize LED pin
    gpio_init(BLUE_PIN); // Initialize LED pin
    gpio_set_dir(RED_PIN, GPIO_OUT); // Setting the pin to be output 
    gpio_set_dir(GREEN_PIN, GPIO_OUT); // Setting the pin to be output 
    gpio_set_dir(BLUE_PIN, GPIO_OUT); // Setting the pin to be output 
    gpio_put(RED_PIN, 0); // Initialize RED_PIN with 0 to be turned off initially
    gpio_put(GREEN_PIN, 0); // Initialize GREEN_PIN with 0 to be turned off initially
    gpio_put(BLUE_PIN, 0); // Initialize BLUE_PIN with 0 to be turned off initially
}

int main() {
    stdio_init_all(); // Initialize chosen serial port
    setup(); // Calling my setup function

    while (true) {
        sleep_ms(5000); //According to milestone, The 3 LEDs are Off for the first 5 seconds 

        gpio_put(RED_PIN, 1); //These 3 lines are reponsible for turning on 
        sleep_ms(1000);       //the Red light by setting the RED_PIN to 1,
        gpio_put(RED_PIN, 0); //then waiting 1 second before turning it off again by setting the RED_PIN to 0 

        gpio_put(GREEN_PIN, 1); //These 3 lines are reponsible for turning on the Green light
        sleep_ms(1000);         //  by setting the GREEN_PIN to 1, then waiting 
        gpio_put(GREEN_PIN, 0); // 1 second before turning it off again by setting the GREEN_PIN to 0

        gpio_put(BLUE_PIN, 1); //These 3 lines are reponsible for turning on the Blue light
        sleep_ms(1000);        //  by setting the BLUE_PINT to 1, then waiting 
        gpio_put(BLUE_PIN, 0); // 1 second before turning it off again by setting the BLUE_PINT to 0

        gpio_put(GREEN_PIN, 1);    //This part is responsible for turning all three LEDs together
        gpio_put(RED_PIN, 1);       // for 2 seconds then turning them off again
        gpio_put(BLUE_PIN, 1);     // produces white light
        sleep_ms(2000);
        gpio_put(RED_PIN, 0);
        gpio_put(GREEN_PIN, 0);
        gpio_put(BLUE_PIN, 0);

    }

    return 0;
}
