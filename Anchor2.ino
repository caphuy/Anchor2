#include<SoftwareSerial.h>
#include<XBee.h>

int anchorID = 3;

SoftwareSerial mySerial = SoftwareSerial(2, 3);
XBee xbee = XBee();
Rx16Response rx16 = Rx16Response();
int numChairs = 1;
int current = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  xbee.setSerial(mySerial);
}

void loop() {
  // put your main code here, to run repeatedly:
//  xbee.readPacket();
//  if (xbee.getResponse().isAvailable()) {
//    if (xbee.getResponse().getApiId() == RX_16_RESPONSE) {
//      xbee.getResponse().getRx16Response(rx16);
//      uint8_t str_rssi = rx16.getRssi();
//      Serial.println("Received from " + (String) rx16.getRemoteAddress16() + ", rssi = " + str_rssi);
//      int rssi = (int) str_rssi;
//      String r = "";
//      for (int i = 0; i < rx16.getDataLength(); i++) {
//        r += (char) rx16.getData(i);
//      }
//      if (rx16.getRemoteAddress16() == 2) {
//        d12 = (double) pow(10, (double) (a2 + rssi) /(double) (10 * n));
//      } else if (rx16.getRemoteAddress16() == 3) {
//        d13 = (double) pow(10, (double) (a3 + rssi) /(double) (10 * n));
//      }
//      if (d12 != 0 && d13 != 0) {
//      Serial.println((String) d12 + " | " + (String) d13);
//      
//      String wh = String (d12) + "|" + String(d13);
//      Serial.println(wh.c_str());
//      uint8_t *payload = reinterpret_cast<const uint8_t*>(wh.c_str());
//      
//    }
//    }
//  }
  int mydel = 9000;
  uint8_t payload[] = {'a', 'n', 'c', 'h', 'o', 'r', '2'};
  for (int i = 1; i <= numChairs; i++) {
    int destID = i + 5;
    Serial.println("Sending to " + String(destID) + " " + String(mydel));
    Tx16Request tx16 = Tx16Request(destID, payload, sizeof(payload));
    xbee.send(tx16);
  }
  Serial.println("Sending to " + String(1) + " " + String(mydel));
  Tx16Request tx16 = Tx16Request(1, payload, sizeof(payload));
  xbee.send(tx16);
  delay(mydel);
  
}














