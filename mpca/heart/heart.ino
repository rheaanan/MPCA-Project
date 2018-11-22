int analogValue;          // This is where we'll store our audio to digital value.  More sound = higher number

boolean toggle = false;   // setup a boolean function called toggle which will help us to choose which mode we're in

// 2-dimensional array of row pin numbers:
const int row[8] = {
  19, 18, 17, 16, 15, 12, 2, 3
};

// 2-dimensional array of column pin numbers:
const int col[8] = {
  4, 5, 6, 7, 8, 9, 10, 11
};

// 2-dimensional array of pixels:
int pixels[8][8];

int count = 1000;

char str[] = "FABCDEDCBA";
int strLen = sizeof(str);
int ptrChar = 0;


typedef bool charMapType[8][8];

const charMapType charBlank = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

const charMapType heart0 = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

const charMapType heart1 = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

const charMapType heart2 = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 0, 0, 1, 1, 0},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0}
};

const charMapType heart3 = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 0, 0, 1, 1, 0},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

const charMapType heart4 = {
  {0, 1, 1, 0, 0, 1, 1, 0},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

const charMapType *charMap[6] = {&heart0, &heart1, &heart2, &heart3, &heart4, &charBlank};

void setup() {
  // initialize the I/O pins as outputs
  // iterate over the pins:
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    // initialize the output pins:
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);
    // take the row pins (i.e. the cathodes) high to ensure that
    // the LEDS are off:
    digitalWrite(row[thisPin], HIGH);
    Serial.begin(9600);
  }

  //setupScreen();
  setupChar();

}

void loop() {

 
  if (toggle == false)   // When you power up your arduino, boolean "toggle" is set to false, so the following section of code will                          //commence.  The "ELSE" is ignored for now.
    { 
        refreshScreen(); 
      analogValue = analogRead(0);  // Take an analog reading from A0 line.  No sounds should be offer a returned value of "0"
      if (analogValue > 6)          // If higher than 8 is returned, then change state of boolean "toggle" to true, display analogValue to                                     // serial monitor and wait 200ms.
  // The higher the value in the above "if" statement, the less sensitive your clapper will be.  Use the serial monitor to calibrate to       // your wanted sensitivity =D
      {
        toggle = true;
        Serial.println(analogValue);
       
      }
    }
  else                            // If boolean "toggle" has beenchanged to true, then the above section of code will be ignored, and the                                     // code below will commence.
    {
      analogValue = analogRead(0);  // Take an analog reading from A0 line.  No sounds should be offer a returned value of "0"
      if (analogValue > 3)          // If higher than 8 is returned, then change state of boolean "toggle" back to false, print analogValue                                     // to serial monitor and wait 200ms.
      // The higher the value in the above "if" statement, the less sensitive your clapper will be.  Use the serial monitor to calibrate to       // your wanted sensitivity =D
      {
        setupChar();
        toggle = false;
        Serial.println(analogValue);
        delay(2000);
      }
    }
  
}

void setupChar(){
  char c = str[ptrChar];
  int offset = c - 'A';
  
  const charMapType *cMap = charMap[offset];
  //charMapType *cMap = &charDummy;
  
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      bool v = (*cMap)[x][y];
      
      if(v){
        pixels[x][y] = LOW;
      }else{
        pixels[x][y] = HIGH;
      }
    }
  }
  
  ptrChar++;
  if(ptrChar>=strLen-1){
    ptrChar = 0;
  }

}

void refreshScreen() {
  // iterate over the cols (anodes):
  for (int thisCol = 0; thisCol < 8; thisCol++) {
    // take the col pin (anode) high:
    digitalWrite(col[thisCol], HIGH);
    // iterate over the rows (cathodes):
    for (int thisRow = 0; thisRow < 8; thisRow++) {
      // get the state of the current pixel;
      int thisPixel = pixels[thisRow][thisCol];
      // when the col is HIGH and the row is LOW,
      // the LED where they meet turns on:
      digitalWrite(row[thisRow], thisPixel);
      // turn the pixel off:
      if (thisPixel == LOW) {
        digitalWrite(row[thisRow], HIGH);
      }
    }
    // take the col pin low to turn off the whole row:
    digitalWrite(col[thisCol], LOW);
  }
}

