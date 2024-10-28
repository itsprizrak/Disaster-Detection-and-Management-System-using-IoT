int piezo = A1;
int val = 0;

void setup()
{
  pinMode(piezo,INPUT);
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(piezo);
  Serial.println(val);
  delay(100);
}
