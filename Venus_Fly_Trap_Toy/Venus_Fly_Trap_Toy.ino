//By Peng Cheng 2014/10/27

#include <SoftwareServo.h> 

SoftwareServo myservo;  // create servo object to control a servo 
 
int pos = 0;    // variable to store the servo position 
 
void setup() venus_Fly_Trap_Toy
{ 
   myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
   Serial.begin(9600);
} 
 
 
void loop() 
{ 
  
  int sensorValue = analogRead(A3);
  Serial.println(sensorValue);
  delay(1); 
  
  
  
  if(sensorValue>750){
    
    if(!myservo.attached()){
       myservo.attach(9);
    }
    
    for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
      myservo.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(1);                       // waits 15ms for the servo to reach the position 
    } 
    for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
    {                                
      myservo.write(100);              // tell servo to go to position in variable 'pos' 
      delay(1);                       // waits 15ms for the servo to reach the position 
    } 
  }else{
  
    myservo.detach();
  }
  
} 
