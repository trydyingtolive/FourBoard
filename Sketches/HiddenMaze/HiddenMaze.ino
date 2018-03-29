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

char maze[12][12] = {
  "XXXXXXXXXXXX",
  "X   X      X",
  "X X X  XXX X",
  "X X XX   X X",
  "X X X X X  X",
  "S X   X XX X",
  "X X X X X  X",
  "X X  X  X XX",
  "X XX   XX XX",
  "X X  XXX   X",
  "X   X    X X",
  "XXXXXXEXXXXX",
};

int x = 0;
int y = 5;

void setup() {
  Serial.begin(9600);
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

  Serial.println(maze[y][x]);

}

void loop() {

  if (maze[y][x] == 'E') {
    ShowWin();
    x = 0;
    y = 5;
    return;
  }

  ShowMaze();
  Serial.println(maze[y][x]);

  while (true) {
    if (digitalRead(upButton) == HIGH && CanUp()) {
      y--;
      delay(250);
      return;
    }

    if (digitalRead(downButton) == HIGH && CanDown()) {
      y++;
      delay(250);
      return ;
    }

    if (digitalRead(leftButton) == HIGH && CanLeft()) {
      x--;
      delay(250);
      return;
    }

    if (digitalRead(rightButton) == HIGH && CanRight()) {
      x++;
      delay(250);
      return;
    }
  }

}

void ShowMaze() {
  Serial.print(x);
  Serial.print(",");
  Serial.print(y);
  Serial.print("\n");
  AllOff();
  delay(100);
  if ( CanUp() ) {
    digitalWrite(upLED, HIGH);
  }

  if ( CanDown() ) {
    digitalWrite(downLED, HIGH);
  }

  if ( CanLeft() ) {
    digitalWrite(leftLED, HIGH);
  }

  if (CanRight() ) {
    digitalWrite(rightLED, HIGH);
  }
}

bool CanUp() {
  if ( y > 0 && maze[y - 1][x] != 'X' ) {
    Serial.println("CanUp");
    return true;
  }
  return false;
}

bool CanDown() {
  if (sizeof(maze) - 1 > y  && maze[y + 1][x] != 'X' ) {
    Serial.println("CanDown");
    return true;
  }
  return false;
}

bool CanLeft() {
  if (x > 0 && maze[y][x - 1] != 'X') {
    Serial.println("CanLeft");
    return true;
  }
  return false;
}

bool CanRight() {
  if (sizeof(maze[y]) - 1 > x && maze[y][x + 1] != 'X' ) {
    Serial.println("CanRight");
    return true;
  }
  return false;
}

void ShowWin() {
  int timer = 25;
  for (int i = 0; i < 25; i++) {

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
