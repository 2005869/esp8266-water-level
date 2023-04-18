#ifndef mqtt_h

    #define mqtt_h
        
        // MQTT Settings
        # define MQTT_BROKER_SERVER "192.168.15.21" // localhost IP
        # define MQTT_SERVER_PORT 1883
        # define MQTT_BROKER "192.168.15.21"        // localhost IP
        # define MQTT_USERNAME "2005869";
        # define MQTT_PASSWD "f1ab26c52b7a60cb762c1722d34db523d8bf7142291fbb635da99578a572f667"

        void mqttConnect();
        void mqttPublish(int value);
        
#endif