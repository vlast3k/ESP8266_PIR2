void initPIR() {
    pinMode(16, INPUT);
}
unsigned long lastTrigger = 0;
bool hadMotion = false;
unsigned long tiggerInterval = 120000L;
void handlePIR() {
  if ((millis() - lastTrigger) > tiggerInterval) {
    lastTrigger = millis();
    if (hadMotion) {
      Serial.println("111111111111111111");
    } else {
      Serial.println("0");
    }
    String rq = String("http://api.thingspeak.com/update?key=11D6TVFX2AFHKVM8&field1=") + (hadMotion?"1":"0");
    Serial << "rq:" << rq << endl;
    HTTPClient http;
    http.begin(rq);
    int rc = http.GET();
    Serial << "rc: " << rc << endl;
    Serial << http.getString();
    hadMotion = false;
  }
  delay(300);

  hadMotion = hadMotion || digitalRead(16);
}

