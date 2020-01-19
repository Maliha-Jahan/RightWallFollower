int in1 = 4;
int in2 = 5;
int in3 = 6;
int in4 = 7;
int enA = 9;
int enB = 10;

int echo1 = 11;
int echo2 = 12;
int echo3 = 13;
int trigger1 = 2;
int trigger2 = 3;
int trigger3 = 8;
int distance1, distance2, distance3;
int threshold1 =23, threshold2_1 =11, threshold2_2 =17,threshold2_3 =55, threshold3=10, dir;
byte front, right, left;
boolean ON = false, Turn = false;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(trigger1, OUTPUT);
  pinMode(trigger2, OUTPUT);
  pinMode(trigger3, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  pinMode(echo3, INPUT);
}

void loop() {

  getDistance();  
  if(distance2 <= threshold3) turnLeft2();
    else {
      if(distance1 <= threshold1) turnLeft2();
      else {
        if(distance3 <= threshold2_1) turnLeft();
        else if(distance3 > threshold2_2) turnRight();
        else goForwardRightBias(4);
      }
   }
}

void getDistance(){
  digitalWrite(trigger1,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger1,LOW);
  distance1 = (pulseIn(echo1,HIGH))*0.034/2;
  if(distance1 >1000 ){distance1 = 5;}

  digitalWrite(trigger2,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger2,LOW);
  distance2 = (pulseIn(echo2,HIGH))*0.034/2;
  if(distance2 >1000 ){distance2 = 5;}

  digitalWrite(trigger3,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger3,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger3,LOW);
  distance3 = (pulseIn(echo3,HIGH))*0.034/2;
  if(distance3 >1000 ){distance3 = 5;}
}


void goForwardRightBias(int bias){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  int power = 60;
  analogWrite(enA,power);
  analogWrite(enB,power+bias);
  }

void turnLeft(){
  Turn = true;
  Serial.println("turning left");
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  int power = 55;
  analogWrite(enA,power);
  analogWrite(enB,0);
}

void turnLeft2(){
  Turn = true;
  Serial.println("turning left");
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  int power = 50;
  analogWrite(enA,power);
  analogWrite(enB,power);
}

void turnRight(){
  Turn = false;
  Serial.println("turning right");
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  int power = 60;
  analogWrite(enA,0);
  analogWrite(enB,power);
}

void carStop(){
  Turn = false;
  Serial.println("stopping");
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  int power = 0;
  analogWrite(enA,power);
  analogWrite(enB,power);
  }

void goForwardNoBias(){
  Turn = false;
  Serial.println("moving forward");
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  int power = 50;
  analogWrite(enA,power);
  analogWrite(enB,power);
}

void turnRight2(){
  Turn = false;
  Serial.println("turning right");
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  int power = 50;
  analogWrite(enA,power);
  analogWrite(enB,power);
}

void goBackward(){
  Turn = false;
  Serial.println("moving backward");
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  int power = 50;
  analogWrite(enA,power);
  analogWrite(enB,power);
  }
