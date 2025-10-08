int ledPins[] = {2,3,4,5,6,7,8,9}; 
int number = 0; 

void setup() {
  for(int i=0; i<8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  Serial.begin(9600); 
}

void loop() {
  if(Serial.available() > 0){
    number = Serial.parseInt(); 
    displayBinary(number);
  }
}

void displayBinary(int n) {
  for(int i=0; i<8; i++){
    int bitValue = (n >> i) & 1; 
    Serial.println(bitValue);
    digitalWrite(ledPins[i], bitValue);
  }
}
