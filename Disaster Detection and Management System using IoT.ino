#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
char auth[] = "64f0a49d9ea74cf2a4bdab00a81bcc2b"; //Your Blynk AUTH code
char ssid[] = "Ghost";                            //wifi connection name for ESP8266
char pass[] = "1150633400";                       //wifi connection password for ESP8266
#define EspSerial Serial1
#define ESP8266_BAUD 115200

ESP8266 wifi(&EspSerial);

int piezo = 9;                    //For Earthquake vibration detector
int x = A1;                       //For X axis in accelerometer
int fire = A2;                    //Fire detector
int water = A3;                   //Flood detector
int Earth_Threshold = 1000;
int Accelerometer_Threshold = 300;
int Flood_Threshold = 300;
int Fire_Threshold = 450 ;

void setup() {
  pinMode(piezo, INPUT);

  pinMode(x, INPUT);

  pinMode(water, INPUT);

  pinMode(fire, INPUT);
  Serial.begin(9600);

  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);
}

void loop() {
  Blynk.run();

  //Code for Vibration detection
  long measurement = TP_init();
  if (measurement >= Earth_Threshold)
  {
    Blynk.notify("Earthquake Alert");
  }


  //Code for Landslide detection
  int valx = analogRead(x);
  if (valx <= Accelerometer_Threshold) {
    Blynk.notify("landslide Alert");
  }

  //Code for flood detection
  int waterval = analogRead(water);
  if (waterval <= Flood_Threshold) {
    Blynk.notify("Flood Alert");
  }

  //Code for Fire Detection
  int fireval = analogRead(fire);
  if (fireval >= Fire_Threshold) {
    Blynk.notify("Fire Alert");
  }
}

long TP_init() {
  delay(10);
  long measurement = pulseIn (piezo, HIGH); //wait for the pin to get HIGH and returns measurement
  return measurement;
}
