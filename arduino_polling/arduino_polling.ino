/*
 * This program implements a blinker using polling
 */
 
#define BLINKER_PIN 2
#define STATE_DUR 500 //time to hold state in ms

volatile int blinkerState = LOW; // LOW=blinker off, HIGH=blinker engaged
volatile int ledState = LOW;
int startTime = millis();

void setup() {
   pinMode(BLINKER_PIN,INPUT);
   pinMode(LED_BUILTIN, OUTPUT);
   digitalWrite(BLINKER_PIN,blinkerState);
   digitalWrite(LED_BUILTIN,ledState);
}

void loop() {
    // poll the blinker control pin
    if ((digitalRead(BLINKER_PIN) == HIGH) && (blinkerState == LOW)) {
       // blinker got turned on
       blinkerState = HIGH;
       startTime = millis();
    }
    if ((digitalRead(BLINKER_PIN) == LOW) && (blinkerState == HIGH)) {
       // blinker got turned off
       blinkerState = LOW;
    }
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
