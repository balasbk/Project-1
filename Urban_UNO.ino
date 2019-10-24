#include <DHT.h>  // Including library for dht
#include<GY80.h>
GY80 sensor = GY80(); //create GY80 instance
float p;
#define DHTPIN 10          //pin where the dht11 is connected

int ldr;
int mq;
DHT dht(DHTPIN, DHT11);

void setup() {
Serial.begin(9600); // sets the serial port to 9600
pinMode(A0, INPUT);
dht.begin();
sensor.begin();
}

void loop() {
ldr = analogRead(A0); 
ldr = 1000 - ldr;// read analog input pin 0
Serial.print("Light intensity = ");
Serial.print(ldr, DEC);               // prints the value read
Serial.println(" lux");

mq = analogRead(A1);       // read analog input pin 0
Serial.print("Air Quality     = ");
Serial.print(mq, DEC);               // prints the value read
Serial.println(" PPM");

float h = dht.readHumidity();
float t = dht.readTemperature();
Serial.print("Temperature     = ");
Serial.print(t);
Serial.print(" C\nHumidity        = ");
Serial.print(h);
Serial.println(" %");

GY80_scaled val = sensor.read_scaled();       
p=val.p * 100000;
Serial.print("Pressure        = ");                           //pressure values
Serial.print(p,2);
Serial.println(" cc");
Serial.println();
    
delay(2000);                                   // wait 100ms for next reading

}
