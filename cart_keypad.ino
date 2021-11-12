#include <Keypad.h>

#define Password_Length 5 

int RelayPin    = 10 ;
int RedLEDPin   = 12;
int GreenLEDPin = 11;

char Data[Password_Length]; 
char Master[Password_Length] = "1234"; 
byte data_count = 0, master_count = 0;
bool Pass_is_good = false;
char customKey;

const byte ROWS = 4;
const byte COLS = 3;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3' },
  {'4', '5', '6' },
  {'7', '8', '9' },
  {'*', '0', '#' }
};

//Arduino board
//byte rowPins[ROWS] = {9, 8, 7, 6};
//byte colPins[COLS] = {5, 4, 3   };

//Nano board
byte rowPins[ROWS] = {8, 3, 4 ,6 };
byte colPins[COLS] = {7, 9, 5    };

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);


void setup(){
  pinMode(RelayPin, OUTPUT);
  pinMode(RedLEDPin, OUTPUT);
  pinMode(GreenLEDPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter Password:");
  digitalWrite(RedLEDPin, HIGH);
  digitalWrite(RelayPin, LOW);
}

void loop(){
  customKey = customKeypad.getKey();
  if (customKey){
    Data[data_count] = customKey; 
    Serial.print(Data[data_count]);
    if (Pass_is_good == false){ 
      digitalWrite(RedLEDPin, LOW); 
      delay(100);
      digitalWrite(RedLEDPin, HIGH);
    }
    data_count++; 
    }

  if(data_count == Password_Length-1){
    Serial.println();
    if(!strcmp(Data, Master)){
      Serial.println("Correct");
      digitalWrite(GreenLEDPin, HIGH);
      digitalWrite(RedLEDPin, LOW);
      digitalWrite(RelayPin, HIGH); 
      Pass_is_good = true;
      //delay(5000);
      //digitalWrite(RelayPin, LOW);
      }
    else if (Pass_is_good == false){
      Serial.println("Incorrect");
      digitalWrite(RedLEDPin, LOW);
      delay(50);
      digitalWrite(RedLEDPin, HIGH);
      delay(50);
      digitalWrite(RedLEDPin, LOW);
      delay(50);
      digitalWrite(RedLEDPin, HIGH);
      delay(50);
      digitalWrite(RedLEDPin, LOW);
      delay(50);
      digitalWrite(RedLEDPin, HIGH);
      delay(50);
      digitalWrite(RedLEDPin, LOW);
      delay(50);
      digitalWrite(RedLEDPin, HIGH);
      delay(50);
      digitalWrite(RedLEDPin, LOW);
      delay(50);
      digitalWrite(RedLEDPin, HIGH);
      }
    
    clearData();  
  }
}

void clearData(){
  while(data_count !=0){
    Data[data_count--] = 0; 
  }
  return;
}
