/* Arduino USB Keyboard HID demo
 * Volume+/Volume-/Mute keys
 */
#include <IRremote.h>
//Digit remote      keyboard
//      hexa        
//  1  805F807F       30
//  2  805F40BF       31  
//  3  805FC03F       32
//  4  805F20DF       33
//  5  805FA05F       34    
//  6  805F609F       35
//  7  805FE01F       36
//  8  805F10EF       37
//  9  805F906F       38
//  0  805F00FF       39
//  OK  enter 805FDA25  40
//lft arrw  805F7887  backspace 187
//dwn arrw  805FF807  space 44

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

uint8_t buf[8] = { 
  0 }; 	/* Keyboard report buffer */

//#define PIN_VOLUME_UP 5

int state = 0;

void setup() 
{
  Serial.begin(9600);
//  pinMode(PIN_VOLUME_UP, INPUT);
  // enable internal pull-ups
 // digitalWrite(PIN_VOLUME_UP, 1); 
  irrecv.enableIRIn(); // Start the receiver
  delay(200);
}
void loop() 
{   
    if (irrecv.decode(&results)) 
    {
    if (results.value == 0x805F807F){
      buf[2] = 30;    //1
      Serial.write(buf, 8); // Send keypress
      releaseKey();
      
      }
    if(results.value == 0x805F40BF){
      buf[2] = 31;    //2
      Serial.write(buf, 8); // Send keypress
      releaseKey();
      }
    if(results.value == 0x805FC03F){
      buf[2] = 32;    //3
      Serial.write(buf, 8); // Send keypress
      releaseKey();
      }
    if(results.value == 0x805F20DF){
      buf[2] = 33;    //4
      Serial.write(buf, 8); // Send keypress
      releaseKey();
      } 
      ////////      GETTING AN ENTER AFTER 5 EVERYTIME
    if(results.value == 0x805FA05F){
      buf[2] = 34;    //5
      Serial.write(buf, 8); // Send keypress
      releaseKey();
      }
    if(results.value == 0x805F609F){
      buf[2] = 35;    //6
      Serial.write(buf, 8); // Send keypress
      releaseKey();
      }    
    if (results.value == 0x805FE01F){
      buf[2] = 36;    //7
      Serial.write(buf, 8); // Send keypress
      releaseKey(); 
      }
    if(results.value == 0x805F10EF){
      buf[2] = 37;    //8
      Serial.write(buf, 8); // Send keypress
      releaseKey();
      }
    if(results.value == 0x805F906F ){
      buf[2] = 38;    //9
      Serial.write(buf, 8); // Send keypress
      releaseKey();
      }
    if (results.value == 0x805F00FF){
      buf[2] = 39;    //0
      Serial.write(buf, 8); // Send keypress
      releaseKey();
      }
      //// ENTER NOT WORKING
    if(results.value == 0x805FA05F){
      buf[2] = 40;    //Enter  Ok
      Serial.write(buf, 8); // Send keypress
      releaseKey();
      }
    if(results.value == 0x805FF807){
      buf[2] = 44;    //down arrow Space Bar
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    }

    //////    NOT WORKING
    if(results.value == 0x805F7887){
      buf[2] = 187;    //left arrow Backspace
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    }
 //   Serial.println(results.value, HEX);    DON'T UNCOMMENT THIS DUE TO ALOT OF DISTORTION
    irrecv.resume(); // Receive the next value
  }
  
}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);	// Release key 
 // delay(50); 
}
