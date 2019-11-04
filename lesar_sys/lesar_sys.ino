#include <Servo.h>

  // create servo object to control a servo
// twelve servo objects can be created on most boards

 


#include <Keypad.h>
Servo myservo; 
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {2,3,4,5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,7,8}; //connect to the column pinouts of the keypad
int pos;
//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup() {
  // put your setup code here, to run once:
pinMode(11,OUTPUT); //Buzzer Pin
pinMode(7,INPUT); // Light Sensor
delay(500);
Serial.begin(9600);
            myservo.attach(9);
 
}

void loop() {
  // put your main code here, to run repeatedly:

  char key = keypad.getKey();// Read the key
  
          int i=0;
          if(digitalRead(7)==LOW && key=='1')
          {
            myservo.write(120);
           
           delay(10000);
           myservo.write(180);
          
          }

          else if(digitalRead(7)==HIGH)
          {
            
                      for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
              // in steps of 1 degree
                  myservo.write(pos);              // tell servo to go to position in variable 'pos'
                                       // waits 15ms for the servo to reach the position
                }
                a:
                digitalWrite(11,HIGH);
                delay(100);
                digitalWrite(11,LOW);
                delay(100);
                i++;
                      if(i<50){
                      goto a;
                      }
                
              
            }
           

            

}
