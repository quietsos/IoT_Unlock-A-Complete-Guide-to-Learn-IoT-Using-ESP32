 /*
 Md Shohanuzzaman
 IoT Engineer @ IoT Lab
*/

//#define relayPin D13
const int relayPin = 13;


void setup() {
  Serial.begin(115200);
  pinMode(relayPin, OUTPUT);

}


void loop() {
  
  // Normally open configuration , Send LOW signal to let current flow
  digitalWrite(relayPin, LOW);  
  Serial.println("Current Flowing");
  delay(5000);

  // Normally open configuration, Send HIGH signal to  stop current flow
  digitalWrite(relayPin, HIGH);
  Serial.println("Current not Flowing");
  delay(5000);
}
