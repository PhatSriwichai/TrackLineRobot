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
      
      motor1('S',100);
      motor2('L',100);
      if(s1 == 1 && s2 == 1){
        motor1('G',0);
        motor2('G',0);
      }
      else if(s2 == 1){
        motor1('L',100);
        motor2('L',100);
        //delay(300);
      }
      Serial.println("000"); 
  }
  else if(s1 == 0 && s2 == 0 && s3 == 1){
      motor1('S',100);
      motor2('L',100);
       
       Serial.println("001");   
  }
   else if(s1 == 0 && s2 == 1 && s3 == 0){
      motor1('L',100);
      motor2('L',100);
      delay(300);
      Serial.println("010");  
  }
  else if(s1 == 0 && s2 == 1 && s3 == 1){
      motor1('S',100);
      motor2('S',100);
       
      Serial.println("011");     
  }
  else if(s1 == 1 && s2 == 0 && s3 == 0){
      motor1('L',100);
      motor2('L',100); 
       Serial.println("100");   
  }
   else if(s1 == 1 && s2 == 0 && s3 == 1){
      motor1('S',100);
      motor2('L',100);
      
       Serial.println("101");    
  }
   else if(s1 == 1 && s2 == 1 && s3 == 0){
      motor1('L',100);
      motor2('L',100);
       
      Serial.println("110");     
  }
   else if(s1 == 1 && s2 == 1 && s3 == 1){
      motor1('S',100);
      motor2('L',100);
       
       Serial.println("111");    
  }
}

void motor1(char ch,int d){
  if(ch == 'L'){
    analogWrite(enLeft,d);
    digitalWrite(leftMotor1,LOW);
    digitalWrite(leftMotor2,HIGH);
  }
  else if(ch == 'S'){
    analogWrite(enLeft,d);
    digitalWrite(leftMotor1,HIGH);
    digitalWrite(leftMotor2,LOW);
  }
  else{
    analogWrite(enLeft,d);
    digitalWrite(rightMotor1,LOW);
    digitalWrite(rightMotor2,LOW);
  }
  
}

void motor2(char ch, int d){
    
  if(ch == 'S'){
    analogWrite(enRight,d);
    digitalWrite(rightMotor1,LOW);
    digitalWrite(rightMotor2,HIGH);
  }
  else if(ch == 'L'){
    analogWrite(enRight,d);
    digitalWrite(rightMotor1,HIGH);
    digitalWrite(rightMotor2,LOW);
  }
  else{
    analogWrite(enRight,d);
    digitalWrite(rightMotor1,LOW);
    digitalWrite(rightMotor2,LOW);
  }
  
}
