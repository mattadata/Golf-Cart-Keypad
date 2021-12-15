#include <Keypad.h>

#define ON 1
#define OFF 0
#define Password_Length 5 

int RelayPin    = 13;
int RedLEDPin   = 12;
int GreenLEDPin = 11;
int DoorPin     = 10;

char Data[Password_Length]; 
char Master[Password_Length] = "1234"; 
byte data_count = 0, master_count = 0;
bool Pass_is_good = false;
char customKey;
char doorKey = '*';

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
  pinMode(DoorPin, OUTPUT);
  pinMode(RedLEDPin, OUTPUT);
  pinMode(GreenLEDPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter Password:");
  digitalWrite(RedLEDPin, HIGH);
  digitalWrite(RelayPin, OFF);
  digitalWrite(DoorPin,  OFF);
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
    else if (Pass_is_good == true)
      {if(doorKey == customKey) {
          Serial.println("Door Relay");
          digitalWrite(DoorPin, ON);
          digitalWrite(RedLEDPin, HIGH);
          delay(1500);
          digitalWrite(DoorPin, OFF);}
          digitalWrite(RedLEDPin, LOW);}
    data_count++; 
    }

  if(data_count == Password_Length-1){
    Serial.println();
    if(!strcmp(Data, Master)){
      Serial.println("Correct");
      digitalWrite(GreenLEDPin, HIGH);
      digitalWrite(RedLEDPin, LOW);
      digitalWrite(RelayPin, ON); 
      Pass_is_good = true;
      //delay(5000);
      //digitalWrite(RelayPin, OFF);
      
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
