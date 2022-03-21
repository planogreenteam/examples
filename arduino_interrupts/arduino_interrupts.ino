/*
 * This program implements a turn signal using interrupts
 */
 
#define BLINKER_PIN 2
#define STATE_DUR 500 //time to hold state in ms

volatile int blinkerState = LOW; // LOW=blinker off, HIGH=blinker engaged
volatile int ledState = LOW;
int startTime = millis();

void setup() {
  attachInterrupt(digitalPinToInterrupt(BLINKER_PIN),blinkerSwitchHandler,CHANGE); 
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
}

void loop() {
    if (blinkerState == HIGH){
        if(millis() - startTime >= STATE_DUR) {
            startTime = millis();
            ledState = !ledState;
        }
        digitalWrite(LED_BUILTIN,ledState);
    } else {
        digitalWrite(LED_BUILTIN,LOW);
    }
}

void blinkerSwitchHandler(){
    if (digitalRead(BLINKER_PIN) == HIGH) {
        blinkerState = HIGH;
        ledState = HIGH;
        startTime = millis();
    } else {
        blinkerState = LOW;
        ledState = LOW;
    }
}
