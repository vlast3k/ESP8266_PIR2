void initPIR() {
    pinMode(16, INPUT);
}
unsigned long lastTrigger = 0;
int lastMotion = 2;
unsigned long tiggerInterval = 20000L;
int countMoves = 5;
void handlePIR() {
//  if ((millis() - lastTrigger) > tiggerInterval) {
//    lastTrigger = millis();
//    if (hadMotion) {
//      Serial.println("111111111111111111");
//    } else {
//      Serial.println("0");
//    }
////    String rq = String("http://api.thingspeak.com/update?key=11D6TVFX2AFHKVM8&field1=") + (hadMotion?"1":"0");
////    Serial << "rq:" << rq << endl;
////    HTTPClient http;
////    http.begin(rq);
////    int rc = http.GET();
////    Serial << "rc: " << rc << endl;
////    Serial << http.getString();
//    hadMotion = false;
//  }
  int c = digitalRead(16);
  int m = 0;
  if (c && !countMoves) m = 1;
  else if (c) countMoves --;
  else countMoves = 5;
  if (m != lastMotion) {
    Serial << endl << m << " ";
  } else {
    Serial << m;
  }

  lastMotion = m;

  delay(1000);

//    if (digitalRead(16)) {
//      Serial.println("111111111111111111");
//    } else {
//      Serial.println("0");
//    }
}

