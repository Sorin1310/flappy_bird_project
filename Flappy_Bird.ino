#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define BUTTON_PIN 4
#define BUZZER_PIN 23

#define BIRD_WIDTH 8
#define BIRD_HEIGHT 8

const uint8_t bird_bitmap[] PROGMEM = {
  0b00001110,
  0b00011111,
  0b00111111,
  0b01111111,
  0b11111111,
  0b00111000,
  0b01110100,
  0b00001010
};

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int birdY;
float birdVelocityY;
int gravity = 1;
bool gameStarted = false;
bool gameOver = false;
int obstacleX;
int obstacleGap = 20;
int obstacleWidth = 10;
int obstacleSpeed = 2;

int score = 0;


#define NOTE_C4 262
#define NOTE_E3 165
#define NOTE_G3 196
#define NOTE_E4 330
#define NOTE_G4 392

int melody[] = {
  NOTE_C4, NOTE_E3, NOTE_G3, NOTE_E4,
  NOTE_G4, NOTE_C4, NOTE_E4, NOTE_G4
};

int noteDurations[] = {
  4, 8, 8, 4,
  4, 4, 4, 2
};

int currentNote = 0;
unsigned long noteStartTime = 0;

void setup() {
  Wire.begin();
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for (;;);
  }

  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  birdY = SCREEN_HEIGHT / 2;
  birdVelocityY = 0;
  obstacleX = SCREEN_WIDTH;
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  if (!gameStarted) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 20);
    display.println("Flappy Bird");
    display.setCursor(5, 45);
    display.println("Press to start");
    display.display();

    if (digitalRead(BUTTON_PIN) == LOW) {
      gameStarted = true;
    }
    return;
  }

  if (gameOver) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 20);
    display.println("Game Over");
    display.setCursor(5, 45);
    display.println("Press to play again");
    display.display();

    if (millis() - noteStartTime >= noteDurations[currentNote]) {
      noTone(BUZZER_PIN);
      currentNote++;
      if (currentNote < sizeof(melody) / sizeof(melody[0])) {
        tone(BUZZER_PIN, melody[currentNote]);
        noteStartTime = millis();
      } else {
        currentNote = 0;
        playJumpSound();
      }
    }

    if (digitalRead(BUTTON_PIN) == LOW) {
      resetGame();
    }
    return;
  }

  if (digitalRead(BUTTON_PIN) == LOW && birdY > 0) {
    birdVelocityY = -4.0;
    playJumpSound();
  }

  birdVelocityY += gravity;
  birdY += birdVelocityY;

  if (birdY > SCREEN_HEIGHT - 1) {
    gameOver = true;
  }

  obstacleX -= obstacleSpeed;

  if (obstacleX + obstacleWidth < 0) {
    obstacleX = SCREEN_WIDTH;
    obstacleGap = random(15, 30);
    score++;
  }

  if (birdY < 0 || birdY > SCREEN_HEIGHT - 1 ||
      (birdY < obstacleGap || birdY > obstacleGap + 20) &&
      obstacleX < 20 && obstacleX + obstacleWidth > 0) {
    gameOver = true;
  }

  display.clearDisplay();

  
  display.drawBitmap(20, birdY, bird_bitmap, BIRD_WIDTH, BIRD_HEIGHT, SSD1306_WHITE);

  
  display.fillRect(obstacleX, 0, obstacleWidth, obstacleGap, SSD1306_WHITE);
  display.fillRect(obstacleX, obstacleGap + 20, obstacleWidth, SCREEN_HEIGHT - obstacleGap - 20, SSD1306_WHITE);

  
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(SCREEN_WIDTH - 20, 0);
  display.print(score);

  display.display();
  delay(10);
}

void resetGame() {
  birdY = SCREEN_HEIGHT / 2;
  birdVelocityY = 0;
  obstacleX = SCREEN_WIDTH;
  score = 0;
  gameOver = false;
  currentNote = 0;
  noTone(BUZZER_PIN);
}

void playJumpSound() {
  tone(BUZZER_PIN, NOTE_E4, 10);
  delay(100);
  noTone(BUZZER_PIN);}
