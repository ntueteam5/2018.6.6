const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
 
}
void loop() {
  int sensorRead = analogRead(A0);
 // Serial.println(sensorRead);
  // read the analog in value:
  if (sensorRead<500) {sensorRead=500;}
  else if (sensorRead>934) {sensorRead=934;}
 // sensorValue = analogRead(analogInPin);
  int ledDimming = map(sensorRead,500,934,0,255);
  // map it to the range of the analog out:
  
  //outputValue = map(sensorValue, 0, 1023, 0, 255);
  
  // change the analog out value:
  
  analogWrite(3, ledDimming);

  // print the results to the serial monitor:

  
  Serial.println(ledDimming);
 // Serial.print(sensorValue);
 // Serial.print("\t output = ");
 // Serial.println(outputValue);


  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);
}

