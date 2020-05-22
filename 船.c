#include<SoftwareSerial.h>
#define RxD 9
#define TxD 8
SoftwareSerial blueToothSerial(TxD,RxD);

const int lmotor1 = 4;
const int lmotor2 = 5;
const int rmotor1 = 6;
const int rmotor2 = 7;
const int pwmA = 3;
const int pwmB = 10;

char recv;

void stop(){
    digitalWrite(lmotor1,LOW);
    digitalWrite(lmotor2,LOW);
    digitalWrite(rmotor1,LOW);
    digitalWrite(rmotor2,LOW);
}
void forward(){
    analogWrite(pwmA,200);
    analogWrite(pwmB,200);
    digitalWrite(lmotor1,HIGH);
    digitalWrite(lmotor2,LOW);
    digitalWrite(rmotor1,HIGH);
    digitalWrite(rmotor2,LOW);
}
void backward(){
    analogWrite(pwmA,200);
    analogWrite(pwmB,200);
    digitalWrite(lmotor1,LOW);
    digitalWrite(lmotor2,HIGH);
    digitalWrite(rmotor1,LOW);
    digitalWrite(rmotor2,HIGH);
}
void right(){
    analogWrite(pwmA,180);
    analogWrite(pwmB,0);
    digitalWrite(lmotor1,HIGH);
    digitalWrite(lmotor2,LOW);
    digitalWrite(rmotor1,LOW);
    digitalWrite(rmotor2,LOW);
}
void left(){
    analogWrite(pwmA,0);
    analogWrite(pwmB,180);
    digitalWrite(lmotor1,LOW);
    digitalWrite(lmotor2,LOW);
    digitalWrite(rmotor1,HIGH);
    digitalWrite(rmotor2,LOW);
}
void setup(){
    pinMode(lmotor1,OUTPUT);
    pinMode(lmotor2,OUTPUT);
    pinMode(rmotor1,OUTPUT);
    pinMode(rmotor2,OUTPUT);
    pinMode(pwmA,OUTPUT);
    pinMode(pwmB,OUTPUT);
    
    Serial.begin(9600);
    blueToothSerial.begin(9600);
}
void loop(){
   if(blueToothSerial.available())
 {
  recv=blueToothSerial.read();
  Serial.print(recv);
 }
    if(recv=='0'){
        stop();
    }
    else if(recv=='1'){
        left();
    }
    else if(recv=='2'){
        right();
    }
    else if(recv=='3'){
        forward();
    }
    else if(recv=='4'){
        backward();
    }
}
