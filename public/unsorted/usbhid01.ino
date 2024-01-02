

/*#include <USBHID.h>
//#include <HID.h>






#include "PluggableUSBHID.h"
#include "USBKeyboard.h"



*/
#include "USBHID.h"

USBHID hid;
HID_REPORT send_report;
HID_REPORT recv_report;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); // Turn off LED initially

  // Setup HID
 // hid.begin();

  // Prepare the HID reports
  send_report.length = 8;
  recv_report.length = 8;
}

void loop() {
  // Check if HID is connected
  if (hid.ready()) {
    // Check for received data
    if (hid.read(&recv_report)) {
      // Process the received data
      if (recv_report.data[0] == 'a') {
        // Toggle LED and send "Hello World"
        digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
        const char *response = "Hello World\n";
        memset(send_report.data, 0, sizeof(send_report.data)); // Clear report
        memcpy(send_report.data, response, strlen(response));
        send_report.length = strlen(response);
        hid.send(&send_report);
      }
    }

    // Send a counting number every second
    static unsigned long last_time = 0;
    if (millis() - last_time >= 1000) {
      last_time = millis();
      static int counter = 0;
      char countMsg[2] = {(char)('0' + (counter % 10)), '\n'};
      memset(send_report.data, 0, sizeof(send_report.data)); // Clear report
      memcpy(send_report.data, countMsg, 2);
      send_report.length = 2;
      hid.send(&send_report);
      counter++;
    }
  }
}
