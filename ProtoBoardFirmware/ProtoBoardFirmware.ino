#include <Keyboard.h>

//ANALOG
#define PIN_ANALOG_SENSOR A4
#define PIN_LIGHT_SENSOR  A5
#define NUM_ANALOG_SENSORS 2
const int ANALOG_SENSORS[] = {PIN_ANALOG_SENSOR,PIN_LIGHT_SENSOR};
int analogSensorsValues[NUM_ANALOG_SENSORS];

//ENCODER
#include <Encoder.h>
#define ENCODER_CHA  4
#define ENCODER_CHB  12
#define ENCODER_SWITCH  6
Encoder myEnc(ENCODER_CHA, ENCODER_CHB);
long oldPosition  = -999;
long encoderPosition  = -999;

//BUTTONS
#define BUTTON_1  A3
#define BUTTON_2  A2
#define BUTTON_3  A1
#define BUTTON_4  A0
#define BUTTON_5  13
#define BUTTON_EN 6
const int BUTTONS[] = {BUTTON_1,BUTTON_2,BUTTON_3,BUTTON_4,BUTTON_5,BUTTON_EN};
const char KEYS[] = {'a', 'd', 'w', 's', ' '};
const int NUM_BUTTONS = 6;

//DEBOUNCING
int buttonStates[NUM_BUTTONS];
unsigned long lastDebounceTime[NUM_BUTTONS];
unsigned long debounceDelay = 50;

//HAPTICS
#define HAP_TRIGGER  11
#define HAP_SCL  3
#define HAP_SDA  2

//SLIDE_SWITCH
#define SLIDE_SWITCH  5

//OPTOCOUPLER
#define OPTO_DRIVE_PIN  8

//SERIAL DELAY
unsigned long lastSentSerial = 0;
unsigned long serialDelay = 50;


//STATES
boolean isKeyboard = false;


void setup() {

  initSerial();
  initLEDs();
  initButtons();
  initSlideSwitch();
  initAnalogSensors();
}

void loop() {
  if(isKeyboard)
  {
    keyboardUpdateButtons();
    keyboardUpdateEncoder();
  }
  else
  {
    serialUpdateButtons();
    serialUpdateAnalogSensors();
    serialUpdateEncoder();
  }
}
