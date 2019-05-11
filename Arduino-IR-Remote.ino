#include <IRremote.h>
#include <IRremoteInt.h>

int RECV_PIN = A0;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);

    if(results.value == 16580863){
      while(results.value == 16580863){
        Serial.println("statement");
        delay(100);
        
        if (irrecv.decode(&results)) {
        Serial.println(results.value);
        //if(results.value==16597183)
        }
        irrecv.resume();
      }
    }
    
    irrecv.resume(); // Receive the next value
  }
}
