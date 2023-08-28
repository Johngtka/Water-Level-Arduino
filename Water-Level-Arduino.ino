int ledRPin = 9;
int ledGPin = 10;
int ledBPin = 11;
void setup(){
  pinMode(A0, INPUT); //set A0 pin to analog signal water depth detector
  Serial.begin(9600); //start the serial console
}
void loop(){
//  read from water detector
  int v = (int)((analogRead(A0)*100.0/600.0));
//  printing value from detector
  Serial.println(v);
//  conditions from smallest to largest value
  if(v < 115){
     analogWrite(ledRPin, 0);
     analogWrite(ledGPin, 255);
     analogWrite(ledBPin, 0);
  }
  if(v > 115 && v < 120){
    analogWrite(ledRPin, 0);
    analogWrite(ledGPin, 0);
    analogWrite(ledBPin, 255);
  }
  if(v > 120){
    analogWrite(ledRPin, 255);
    analogWrite(ledGPin, 0);
    analogWrite(ledBPin, 0);
  }
}
