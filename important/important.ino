//ARDUINO Light Following Car - QUAD Robotics - A unit of Quad Store//
//www.quadstore.in

// YOU HAVE TO INSTALL THE AFMOTOR LIBRARY BEFORE UPLOAD THE CODE//
// GO TO SKETCH >> INCLUDE LIBRARY >> ADD .ZIP LIBRARY >> SELECT AF MOTOR ZIP FILE //


//including the libraries
#include <AFMotor.h>

//defining pins and variables
#define left A0
#define right A1
#define middle A5


//defining motors
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
// AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
// AF_DCMotor motor4(4, MOTOR34_1KHZ);
float env_middle=analogRead(middle);
float env_left=analogRead(left);
float env_right=analogRead(right);
// float left_target=620.0;
// float right_target=820.0;


void setup() {
  //Setting the motor speed
  motor1.setSpeed(180);
  // motor2.setSpeed(180);
  motor3.setSpeed(180);
  // motor4.setSpeed(180);
  //Declaring PIN input types
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  pinMode(middle,INPUT);
  //Begin serial communication
  Serial.begin(9600);
  
  env_middle=0;
  // Serial.print("env_middle:");
  // Serial.println(env_middle);
  
  env_left=0;
  // Serial.print("env_left:");
  // Serial.println(env_left);
  
  env_right=0;
  // Serial.print("env_right:");
  // Serial.println(env_right);
}
float i=1;
int count=0;
void loop(){
  
  if (i<11){
 count++;
   env_middle+=analogRead(middle);
   env_right+=analogRead(right);
   env_left+=analogRead(left);    
   Serial.print("measure env");    

  }else if(i==11){
    env_middle=env_middle/count;
env_left=env_left/count;
env_right=env_right/count;        
  Serial.print("middle");
  Serial.println(analogRead(middle));
  Serial.print("left");
  Serial.println(analogRead(left));
  Serial.print("right");
  Serial.println(analogRead(right));
    Serial.print('\n');    
    Serial.print(i);
    Serial.print("env_middle");
    Serial.println(analogRead(middle));
    Serial.print("env_right");
    Serial.println(analogRead(right));
    Serial.print("env_left");
    Serial.println(analogRead(left));
    delay(2000);
      }else{


    

   if (analogRead(right)>env_right+50 && analogRead(right)>400){
    Serial.print("turn right");
    motor1.run(FORWARD);   
    motor3.run(BACKWARD);
      
   }else if(analogRead(left)>env_left+50 && analogRead(left)>500){
    Serial.print("turn left");
    motor1.run(BACKWARD);   
    motor3.run(FORWARD);
  }else if(analogRead(middle)>env_middle+50 && analogRead(middle)<980){
    Serial.print("forward");
    motor1.run(FORWARD);   
    motor3.run(FORWARD);
  }else{
    Serial.print("RELEASE");
    motor1.run(RELEASE);   
    motor3.run(RELEASE);  
  }
  Serial.print("\n");
  Serial.print("\n");    
  }
  // delay(200);
  i=i+1;
}

