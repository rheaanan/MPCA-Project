int analogValue;          // This is where we'll store our audio to digital value.  More sound = higher number

#define LED 2             // Set up the LED indicator

boolean toggle = false;   // setup a boolean function called toggle which will help us to choose which mode we're in

void setup()

{

  pinMode(LED,OUTPUT);    // Pin#2 should be conencted to an LED through a 300-600 ohm resistor    

  Serial.begin(9600);     // This is optional - It just helps you to calibrate sensitivity after the fact

}



void loop()

{

  if (toggle == false)   // When you power up your arduino, boolean "toggle" is set to false, so the following section of code will                          //commence.  The "ELSE" is ignored for now.

    { 

      digitalWrite(LED,LOW);        // Turn the LED off

      analogValue = analogRead(0);  // Take an analog reading from A0 line.  No sounds should be offer a returned value of "0"

      if (analogValue > 8)          // If higher than 8 is returned, then change state of boolean "toggle" to true, display analogValue to                                     // serial monitor and wait 200ms.

      // The higher the value in the above "if" statement, the less sensitive your clapper will be.  Use the serial monitor to calibrate to       // your wanted sensitivity =D

      {

        toggle = true;

        Serial.println(analogValue);

        delay(200);

      }

    }

    else                            // If boolean "toggle" has beenchanged to true, then the above section of code will be ignored, and the                                     // code below will commence.

    {

      digitalWrite(LED,HIGH);       // Turn the LED on

      analogValue = analogRead(0);  // Take an analog reading from A0 line.  No sounds should be offer a returned value of "0"

      if (analogValue > 8)          // If higher than 8 is returned, then change state of boolean "toggle" back to false, print analogValue                                     // to serial monitor and wait 200ms.

      // The higher the value in the above "if" statement, the less sensitive your clapper will be.  Use the serial monitor to calibrate to       // your wanted sensitivity =D

      {

        toggle = false;

        Serial.println(analogValue);

        delay(200);

      }

    }

}
