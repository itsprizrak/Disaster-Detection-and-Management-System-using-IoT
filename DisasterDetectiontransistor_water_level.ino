int base = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(base,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int baseval = digitalRead(base);
  if (baseval == HIGH){
    Serial.println("high");
  }
  else {
    Serial.println("low");
  }
  delay(200);
}
