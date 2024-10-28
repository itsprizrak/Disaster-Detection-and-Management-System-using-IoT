int fire = A1;

void setup() {
  pinMode(fire, INPUT);
  Serial.begin(9600);
}

void loop() {
  int fireval = analogRead(fire);
  Serial.println(fireval);
  delay(200);
}
