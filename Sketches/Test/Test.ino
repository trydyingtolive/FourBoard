//Led Constants
const int upLED = 2;
const int downLED = 4;
const int leftLED = 3;
const int rightLED = 5;

//Button Constants
const int upButton = 9;
const int downButton = 11;
const int leftButton = 10;
const int rightButton = 12;

//Button light constants
int upLight = 0;
int downLight = 0;
int rightLight = 0;
int leftLight = 0;

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 250;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(upLED, OUTPUT);
  pinMode(downLED, OUTPUT);
  pinMode(leftLED, OUTPUT);
  pinMode(rightLED, OUTPUT);

  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);

  int timer = 25;
  for (int i = 0; i < 20; i++) {

    digitalWrite(upLED, HIGH);
    delay(timer);
    digitalWrite(upLED, LOW);
    delay(timer);

    digitalWrite(leftLED, HIGH);
    delay(timer);
    digitalWrite(leftLED, LOW);
    delay(timer);

    digitalWrite(downLED, HIGH);
    delay(timer);
    digitalWrite(downLED, LOW);
    delay(timer);

    digitalWrite(rightLED, HIGH);
    delay(timer);
    digitalWrite(rightLED, LOW);
    delay(timer);
  }
}

void loop() {

  //Debounce
  if (millis() < lastDebounceTime) {
    return;
  }
  int value;

  value = digitalRead( upButton );
  if (value == HIGH && upLight == 0) {
    digitalWrite(upLED, HIGH);
    upLight = 1;
    SetDebounce();
    return;
  }
  if (value == HIGH && upLight == 1) {
    digitalWrite(upLED, LOW);
    upLight = 0;
    SetDebounce();
    return;
  }

  value = digitalRead( downButton );
  if (value == HIGH && downLight == 0) {
    digitalWrite(downLED, HIGH);
    downLight = 1;
    SetDebounce();
    return;
  }
  if (value == HIGH && downLight == 1) {
    digitalWrite(downLED, LOW);
    downLight = 0;
    SetDebounce();
    return;
  }

  value = digitalRead( leftButton );
  if (value == HIGH && leftLight == 0) {
    digitalWrite(leftLED, HIGH);
    leftLight = 1;
    SetDebounce();
    return;
  }
  if (value == HIGH && leftLight == 1) {
    digitalWrite(leftLED, LOW);
    leftLight = 0;
    SetDebounce();
    return;
  }

  value = digitalRead( rightButton );
  if (value == HIGH && rightLight == 0) {
    digitalWrite(rightLED, HIGH);
    rightLight = 1;
    SetDebounce();
    return;
  }
  if (value == HIGH && rightLight == 1) {
    digitalWrite(rightLED, LOW);
    rightLight = 0;
    SetDebounce();
    return;
  }

}


void SetDebounce() {
  lastDebounceTime = millis() + debounceDelay;
}

