int x = A0;
int y = A2;
int z = A3;

void setup() {
  // put your setup code here, to run once:
pinMode(x,INPUT);
pinMode(y,INPUT);
pinMode(z,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int valx = analogRead(x);
  Serial.println(valx);
  
  int valy = analogRead(y);
 
  
  int valz = analogRead(z);
 
  delay(500);
}
