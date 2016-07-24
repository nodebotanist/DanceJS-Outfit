
#include "application.h"
#include "flash_mal.h"

SYSTEM_MODE(SEMI_AUTOMATIC)

bool FLASH_WriteProtectMemory(flash_device_t flashDeviceID, uint32_t startAddress, uint32_t length, bool protect);

UDP Udp;

void setup()
{
  Serial.begin(9600);
  WiFi.setCredentials("nodebotanist-outfit-hub", "AceIsSuperCool");
  WiFi.connect();
  WiFi.useDynamicIP();

    IPAddress myAddress(192,168,2,217);
    IPAddress netmask(255,255,255,0);
    IPAddress gateway(192,168,2,1);
    IPAddress dns(192,168,2,1);
    WiFi.setStaticIP(myAddress, netmask, gateway, dns);

    // now let's use the configured IP
//    WiFi.useStaticIP(); 

  // An UDP instance to let us send and receive packets over UDP

  // start the UDP
  Udp.begin(33333);
  pinMode(D7, OUTPUT);

  // Print your device IP Address via serial
}

void loop() {
  // Check if data has been received
  if (Udp.parsePacket() > 0) {
      digitalWrite(D7, HIGH);

    // Read first char of data received
    char c = Udp.read();

    // Ignore other chars
    Udp.flush();

    // Store sender ip and port
    IPAddress ipAddress = Udp.remoteIP();
    int port = Udp.remotePort();

    // Echo back data to sender
    Udp.beginPacket(ipAddress, port);
    Udp.write(c);
    Udp.endPacket();
  }

  char o = 'o';

  IPAddress multicastAddress(192,168,2,1);
  Udp.beginPacket(multicastAddress, 33333);
  Udp.write(o);
  Udp.endPacket();
}

