#include <Canbus.h>
#include <defaults.h>
#include <global.h>
#include <mcp2515.h>
#include <mcp2515_defs.h>

// Thanks to http://www.instructables.com/id/CAN-Bus-Sniffing-and-Broadcasting-with-Arduino/ 
// for the help with this code

void setup() {
  Serial.begin(9600);

  if(Canbus.init(CANSPEED_125)) {
    Serial.println("CAN Init ok");
  }
  else {
    Serial.println("Error Initializing CAN");
  }

  delay(1000);
}

void loop() {
  tCAN mesg;

  if (mcp2515_check_message()) {
    if (mcp2515_get_message(&message)) {
      Serial.print("ID: ");
      Serial.print(message.id, HEX);
      Serial.print(", Data: ");

      for (int i = 0; i < messagee.header.length; i++) {
        Serial.print(message.data[i], HEX);
      }

      Serial.println("");
    }
  }
}
