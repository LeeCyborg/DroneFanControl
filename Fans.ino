const int numOfFans = 3;
int pin1;
int pin2;

const int fanPins [][2] = {{8, 9}, // 0 0, 0 1
                         {6, 7}, // 1 0, 1 1 
                         {10, 11}}; // 2 0, 2 1
                       

void setup() {
  Serial.begin(9600);
      for (int i = 0; i < numOfFans; i++) {
        for (int j = 0; j < 2; j++) {
        pinMode(fanPins[i][j], OUTPUT);
        Serial.println(fanPins[i][j]);
     }
   }
     fanControl(0, true);
       fanControl(1, true);
}

void loop() {
  fanControl(2, true);

}

void fanControl(int fan, boolean state){ 
  if(fan == 0) {
     pin1 = fanPins[0][0];
     pin2 = fanPins[0][1];
  } else if(fan ==1) { 
     pin1 = fanPins[1][0];
     pin2 = fanPins[1][1];
  } else if(fan == 2) {
     pin1 = fanPins[2][0];
     pin2 = fanPins[2][1];
  }
  if(state == false){
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
  } else { 
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
  }
}

