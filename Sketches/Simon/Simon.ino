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

int memory[256] {};
int timer = 300;

void setup() {
  pinMode(upLED, OUTPUT);
  pinMode(downLED, OUTPUT);
  pinMode(leftLED, OUTPUT);
  pinMode(rightLED, OUTPUT);

  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);

  //seed the generator or it will be the same pattern everytime
  randomSeed(analogRead(A0));
}

void loop() {
  PlayLights();

  bool success = WaitForSolution();

  if (!success) {
    FailAndReset();
  }
}


bool WaitForSolution() {
  int i = 0;

  while (true) {
    int value = memory[i];
    if (value == 0) {
      delay(1000);
      return true;
    }
    int selection = GetSelection();
    if (selection != value) {
      return false;
    }
    i++;
  }
}

int GetSelection() {
  while (true) {
    if (digitalRead(upButton) == HIGH) {
      digitalWrite(upLED, HIGH);
      delay(timer);
      digitalWrite(upLED, LOW);
      delay(timer);
      return 1;
    }

    if (digitalRead(downButton) == HIGH) {
      digitalWrite(downLED, HIGH);
      delay(timer);
      digitalWrite(downLED, LOW);
      delay(timer);
      return 2;
    }

    if (digitalRead(leftButton) == HIGH) {
      digitalWrite(leftLED, HIGH);
      delay(timer);
      digitalWrite(leftLED, LOW);
      delay(timer);
      return 3;
    }

    if (digitalRead(rightButton) == HIGH) {
      digitalWrite(rightLED, HIGH);
      delay(timer);
      digitalWrite(rightLED, LOW);
      delay(timer);
      return 4;
    }
  }

}

void FailAndReset() {
  for (int i = 0; i < 25; i++) {
    AllOn();
    delay(50);
    AllOff();
    delay(50);
  }

  //Blink for score and reset at the same time
  for (int i = 0; i < 256; i++) {
    int value = memory[i];
    if (value != 0) {
      AllOn();
      delay(timer);
      AllOff();
      delay(timer);
      memory[i] = 0;
    }
    else {
      break;
    }
  }
  delay(2000);
}

void AllOn() {
  digitalWrite(upLED, HIGH);
  digitalWrite(downLED, HIGH);
  digitalWrite(leftLED, HIGH);
  digitalWrite(rightLED, HIGH);
}

void AllOff() {
  digitalWrite(upLED, LOW);
  digitalWrite(downLED, LOW);
  digitalWrite(leftLED, LOW);
  digitalWrite(rightLED, LOW);
}

void PlayLights() {
  for (int i = 0; i < 256; i++) {
    int value = memory[i];
    if (value == 0) {
      value = random(1, 5);
      memory[i] = value;
      DisplayLED(value);
      return;
    }
    DisplayLED(value);
  }
}

void DisplayLED(int value) {
  if (value == 1) {
    digitalWrite(upLED, HIGH);
    delay(timer);
    digitalWrite(upLED, LOW);
    delay(timer);
  }

  if (value == 2) {
    digitalWrite(downLED, HIGH);
    delay(timer);
    digitalWrite(downLED, LOW);
    delay(timer);
  }

  if (value == 3) {
    digitalWrite(leftLED, HIGH);
    delay(timer);
    digitalWrite(leftLED, LOW);
    delay(timer);
  }

  if (value == 4) {
    digitalWrite(rightLED, HIGH);
    delay(timer);
    digitalWrite(rightLED, LOW);
    delay(timer);
  }
}
