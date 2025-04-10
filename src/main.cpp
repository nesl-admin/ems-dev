#include <Arduino.h>
#include <modbus.h>
#include <buttons.h>
#include <display.h>
#include <console.h>
#include <SPI.h>
#include <can.h>

void setup() {
    Serial.begin(115200);
    Serial.println("Started...setup in 4 secs");
    delay(4000);

    SPI.begin();
    setup_display();
    
    drawBitmap(40, 5, RICK_WIDTH, RICK_HEIGHT, rick); 
    delay(1000);

    setup_modbus_master();
    setup_modbus_client();
    setup_can();

    setup_buttons();
    _console.addLine("      EMS setup done");

}

void loop() {
    loop_buttons();
    loop_modbus_master();
    loop_modbus_client();
    loop_display();
    //loop_can(); //uncomment when ready to talk to transceiver
}
