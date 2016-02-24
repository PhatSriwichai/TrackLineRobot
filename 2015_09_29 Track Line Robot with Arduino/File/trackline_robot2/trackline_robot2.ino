int sensor1 = 2;
  int sensor2 = 3;
  int sensor3 = 4;
  int enLeft = 6, enRight = 7;
  int leftMotor1 = 8, leftMotor2 = 9;
  int rightMotor1 = 10, rightMotor2 = 11;
   
void setup(){
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  pinMode(sensor3,INPUT);
  pinMode(enLeft,OUTPUT);
  pinMode(enRight,OUTPUT);
  pinMode(leftMotor1,OUTPUT);
  pinMode(leftMotor2,OUTPUT); 
  pinMode(rightMotor1,OUTPUT);
  pinMode(rightMotor2,OUTPUT); 
   Serial.begin(9600);
}

void loop(){
 
  motor1('S',80);
  motor2('L',80); 
  delay(2000);
  motor1('L',80);
  motor2('L',80);
  delay(300);
  motor1('S',80);
  motor2('L',80); 
  delay(2000);
 motor1('S',80);
  motor2('S',80);
  delay(300);
   motor1('S',80);
  motor2('L',80); 
  delay(2000);
  motor1('L',80);
  motor2('S',80); 
  delay(4000);
  m1stop();
  m2stop();
  delay(10000);

 
}

void m1stop(){
 
  digitalWrite(enLeft,LOW);
}
void m2stop(){
  digitalWrite(enRight,LOW);
}

void motor1(char ch,int d){
  if(ch == 'L'){
    digitalWrite(enLeft,HIGH);
    digitalWrite(leftMotor1,LOW);
    digitalWrite(leftMotor2,HIGH);
  }
  else{
    digitalWrite(enLeft,HIGH);
    digitalWrite(leftMotor1,HIGH);
    digitalWrite(leftMotor2,LOW);
  }
 
  delay(110-d);
  
}

void motor2(char ch, int d){
   
  if(ch == 'S'){
    digitalWrite(enRight,HIGH);
    digitalWrite(rightMotor1,LOW);
    digitalWrite(rightMotor2,HIGH);
  }
  else{
    digitalWrite(enRight,HIGH);
    digitalWrite(rightMotor1,HIGH);
    digitalWrite(rightMotor2,LOW);
  }
  delay(110-d);
 
}
