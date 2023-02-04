#include <Servo.h>
#include <LiquidCrystal.h>
const int rs = 2, e = 3, db4 = 4, db5 = 5, db6 = 6, db7 = 7, rightPush = 13, leftPush = 9, servoPin = 11;
int angle;
LiquidCrystal mylcd(rs, e, db4, db5, db6, db7);
Servo myServo;
void setup() {
  myServo.attach(servoPin);
  pinMode(rightPush, INPUT_PULLUP);
  pinMode(leftPush, INPUT_PULLUP);
  mylcd.begin(16,2);
  mylcd.setCursor(0,0);
  mylcd.print("Angle:");
}

void loop() {
  if(digitalRead(leftPush) == HIGH){
    angle++;
    delay(10);
    myServo.write(angle);
    mylcd.setCursor(0,1);
    mylcd.print("                ");
    mylcd.setCursor(0,1);
    if(angle >= 180){
      mylcd.setCursor(0,1);
      mylcd.print("                ");
      mylcd.print("180 degrees");
      mylcd.setCursor(0,1);
    }
    mylcd.print(angle);
    mylcd.print(" degrees");
    delay(10);
  }
  if(digitalRead(rightPush) == HIGH){
    angle--;
    delay(10);
    myServo.write(angle);
    mylcd.setCursor(0,1);
    mylcd.print("                ");
    mylcd.setCursor(0,1);
    if(angle <= 0){
      mylcd.setCursor(0,1);
      mylcd.print("                ");
      mylcd.print("0 degrees");
      mylcd.setCursor(0,1);
    }
    mylcd.print(angle);
    mylcd.print(" degrees");
    delay(10);
  }
}
