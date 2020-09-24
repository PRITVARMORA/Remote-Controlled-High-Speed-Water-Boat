#include<SoftwareSerial.h>
#include <Servo.h>
#define propeller  2//     engin start/stop    ==> pin D3
#define led 4       ///notification led positive,negetive with d5
#define flappin  6//       servo pin           ==> pin D2
#define bltpown 9
#define bltpowp 8
uint8_t degree = 45;
SoftwareSerial BTR (10,11);//(declared rx  ,   declared tx)
Servo flap;
//test comments____ignore this lines

void setup() {
  flap.attach(flappin);
  pinMode(bltpown,OUTPUT);
  pinMode(bltpowp,OUTPUT);
  digitalWrite(bltpown,LOW);
  digitalWrite(bltpowp,HIGH);
 pinMode(propeller,OUTPUT);
 pinMode (led,OUTPUT);
 pinMode (5,OUTPUT);
 digitalWrite(5, LOW);
 BTR.begin(9600);
 //Serial.begin(9600);
 flap.write(degree);

}

void loop() {
 if (BTR.available())
 {
  char data = BTR.read();
 // Serial.println(data);
 // Serial.println(data);

  if     (data == '1')     {flap.write(degree - 32);/*Serial.println("left");*/}

  else if(data == '2')     {flap.write(degree + 40);/*Serial.println("right");*/}

  else if(data == '5')     {flap.write(degree);/*Serial.println("center");*/}

  else if(data == '3')     {digitalWrite(propeller ,HIGH);digitalWrite(led ,HIGH);/*Serial.println("start");*/}

  else if(data == '4')     { digitalWrite(propeller ,LOW);digitalWrite(led ,LOW);/*Serial.println("stop");*/}

 }


}
