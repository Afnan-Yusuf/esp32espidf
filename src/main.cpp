#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED_PIN 2 // GPIO number for built-in LED on most ESP32 boards

void blinkTask(void *parameter) {
    while (true) {
        digitalWrite(LED_PIN, HIGH); // Turn the LED on
        Serial.println("LED is ON"); // Print status to Serial Monitor
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay using ESP-IDF's FreeRTOS function

        digitalWrite(LED_PIN, LOW); // Turn the LED off
        Serial.println("LED is OFF"); // Print status to Serial Monitor
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void setup() {
    Serial.begin(115200); // Initialize Serial at 115200 baud rate
    pinMode(LED_PIN, OUTPUT); // Set the LED pin as an output
    xTaskCreate(blinkTask, "Blink Task", 1024, NULL, 1, NULL); // Create FreeRTOS task
}

void loop() {
    // Nothing here, blink is handled by FreeRTOS task
}
