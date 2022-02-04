// bluetooth pin connections TX-->RX of arduino,,,,,RX--> TX of arduino

const int left_motor_1=2;   // rightside front motor terminal 1
const int left_motor_2=3;   // rightside front motor terminal 2
const int right_motor_1=4;  // rightside back motor terminal 1
const int right_motor_2=5;  // rightside back motor terminal 2

const int  arm_motor_1=8;   // hand movement motor terminal 1
const int  arm_motor_2=9;   // hand movement motor terminal 2
const int  grip_motor_1=10; // gripper motor terminal 1
const int  grip_motor_2=11; // gripper motor terminal 2

void setup() 
{
pinMode(left_motor_1,OUTPUT);
pinMode(left_motor_2,OUTPUT);
pinMode(right_motor_1,OUTPUT);
pinMode(right_motor_2,OUTPUT);

pinMode(arm_motor_1,OUTPUT);
pinMode(arm_motor_2,OUTPUT);
pinMode(grip_motor_1,OUTPUT);
pinMode(grip_motor_2,OUTPUT);
Serial.begin(9600);
}

void default1()
{
digitalWrite(left_motor_1,LOW);
digitalWrite(left_motor_2,LOW);
digitalWrite(right_motor_1,LOW);
digitalWrite(right_motor_2,LOW);

digitalWrite(arm_motor_1,LOW);
digitalWrite(arm_motor_2,LOW);
digitalWrite(grip_motor_1,LOW);
digitalWrite(grip_motor_2,LOW);    
}


void loop() 
{
  {
  forward();
  delay(1000);
  default1();
  }
  while(Serial.available()) 
  { 
    char command = Serial.read();
    switch(command)
    {
      case 'f':
      forward();
      break;

      case 'b':
      backward();
      break;

      case 'l':
      left_turn();
      break;

      case 'r':
      right_turn();
      break;
    }
    if(command == 'u')
    arm_up();

    if (command == 'd')
    arm_down();

    if (command == 'o')
    gripper_open();

    if(command == 'c')
    gripper_close();

    if(command == 's')
    default1();
  }
}
    
void forward()
{
  digitalWrite(left_motor_1,HIGH);
  digitalWrite(left_motor_2,LOW);
  digitalWrite(right_motor_1,HIGH);
  digitalWrite(right_motor_2,LOW);
  delay(200);    
}

void backward()
{
  digitalWrite(left_motor_1,LOW);
  digitalWrite(left_motor_2,HIGH);
  digitalWrite(right_motor_1,LOW);
  digitalWrite(right_motor_2,HIGH);
  delay(200);
}

void left_turn()
{
  digitalWrite(left_motor_1,LOW);
  digitalWrite(left_motor_2,HIGH);
  digitalWrite(right_motor_1,HIGH);
  digitalWrite(right_motor_2,LOW);
  delay(200);
}

void right_turn()
{
  digitalWrite(left_motor_1,HIGH);
  digitalWrite(left_motor_2,LOW);
  digitalWrite(right_motor_1,LOW);
  digitalWrite(right_motor_2,HIGH);
  delay(200);
}
  
void arm_up()
  {
    digitalWrite(arm_motor_1,HIGH);
    digitalWrite(arm_motor_2,LOW);
    delay(200);   
  }
void arm_down()
  {
    digitalWrite(arm_motor_1,LOW);
    digitalWrite(arm_motor_2,HIGH);
    delay(200);
  }
  
void gripper_close()
  {
    digitalWrite(grip_motor_1,HIGH);
    digitalWrite(grip_motor_2,LOW);
    delay(200);
  }
  
void gripper_open()
  {
    digitalWrite(grip_motor_1,LOW);
    digitalWrite(grip_motor_2,HIGH);
    delay(200);
  }
