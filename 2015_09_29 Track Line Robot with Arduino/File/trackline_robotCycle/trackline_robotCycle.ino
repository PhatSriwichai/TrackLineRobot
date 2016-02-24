int sensor1 = 2;
  int sensor2 = 3;
  int sensor3 = 4;
  int enLeft = 5, enRight = 6;
  int leftMotor1 = 8, leftMotor2 = 9;
  int rightMotor1 = 10, rightMotor2 = 11;
   
void setup(){
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  pinMode(sensor3,INPUT);
  //pinMode(enLeft,OUTPUT);
  //pinMode(enRight,OUTPUT);
  pinMode(leftMotor1,OUTPUT);
  pinMode(leftMotor2,OUTPUT); 
  pinMode(rightMotor1,OUTPUT);
  pinMode(rightMotor2,OUTPUT); 
   Serial.begin(9600);
}

void loop(){
  int s1 = digitalRead(sensor1);
  int s2 = digitalRead(sensor2);
  int s3 = digitalRead(sensor3);
  
  s1 = digitalRead(2);
  s2 = digitalRead(3);
  s3 = digitalRead(4); 
  
  if(s1 == 0 && s2 == 0 && s3 == 0){
      motor1('S',125);
      motor2('L',125);
      
      Serial.println("000"); 
  }
 
  
  else if(s1 == 0 && s2 == 1 && s3 == 1){
      motor1('S',110);
      motor2('S',110);
      delay(200);
      Serial.println("011");     
  }
  
   else if(s1 == 1 && s2 == 0 && s3 == 1){
      motor1('S',125);
      motor2('L',125);
      
       Serial.println("101");    
  }
   else if(s1 == 1 && s2 == 1 && s3 == 0){
      motor1('L',110);
      motor2('L',110);
      delay(200);
       Serial.println("110");    
  }
  
   else if(s1 == 1 && s2 == 1 && s3 == 1){
      motor1('S',115);
      motor2('L',115);
     
       
       Serial.println("111");    
  }
}

void motor1(char ch,int d){
  if(ch == 'L'){
    analogWrite(enLeft,d);
    digitalWrite(leftMotor1,LOW);
    digitalWrite(leftMotor2,HIGH);
  }
  else{
    analogWrite(enLeft,d);
    digitalWrite(leftMotor1,HIGH);
    digitalWrite(leftMotor2,LOW);
  }
  
}

void motor2(char ch, int d){
    
  if(ch == 'S'){
    analogWrite(enRight,d);
    digitalWrite(rightMotor1,LOW);
    digitalWrite(rightMotor2,HIGH);
  }
  else{
    analogWrite(enRight,d);
    digitalWrite(rightMotor1,HIGH);
    digitalWrite(rightMotor2,LOW);
  }
  
}
