//Set up Constants and variables
const float THRESHOLD = 130.00; 
const int Relay = 6;
const int absDiffPinOut = A0; 
const int inputPin1 = A1;
const int inputPin2 = A2;

float sensorInputOne = 0;
float sensorInputTwo = 0;
float voltageDifference = 0;

void setup() {
 Serial.begin(9600);
 pinMode(Relay, OUTPUT);
 pinMode(absDiffPinOut, OUTPUT);
}

void loop() {

  //Read in Voltages
  sensorInputOne = analogRead(inputPin1);
  sensorInputTwo = analogRead(inputPin2);

  //Take the Difference
  voltageDifference = abs(sensorInputOne - sensorInputTwo);

  //Read out Absolute Voltage Difference and Conditionally change output to Relay
  analogWrite(absDiffPinOut, voltageDifference);

  if (voltageDifference < THRESHOLD){
    digitalWrite(Relay, HIGH);
  }else{
    digitalWrite(Relay, LOW);
  }

  //Check Values:
  Serial.print("Input1:  ");
  Serial.println(sensorInputOne);
  Serial.print("Input2:  ");
  Serial.println(sensorInputTwo);
  Serial.print("Difference:   ");
  Serial.println(voltageDifference);

  //Set cycle with delay -- Recall: 1000 = 1s 
  delay(1000);

}
