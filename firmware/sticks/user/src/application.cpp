
#include "application.h"
#include "flash_mal.h"

SYSTEM_MODE(SEMI_AUTOMATIC)

void setup()
{
    WiFi.setCredentials("nodebotanist-tessel-hub", "AceIsSuperCool");
    WiFi.connect();
    WiFi.useDynamicIP();

    Udp.start(88888);
}

void loop(){
    
}
