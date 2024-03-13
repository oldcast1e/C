#define SOUND 2 //OUT 핀 설정(디지털신호 받는 핀)
void setup() {
    Serial.begin(9600);
    pinMode(SOUND, INPUT);
}
void loop() {

  if (digitalRead(SOUND) == HIGH) {
        Serial.println("SOUND ON");
  }
  delay(10);
}
