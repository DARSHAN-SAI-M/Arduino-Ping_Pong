#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

float padel_pix_Left[20] = {};
float padel_pix_Right[20] = {};
float Ball_pix_x[13];
float Ball_pix_y[13];
float Ball_pos[2] = {64, 32};

float Vx = 150.0;
float Vy = 190.0;
float Sx;
float Sy;

int Score_P1 = 0;
int Score_P2 = 0;

bool ballCollidedLeft = false;
bool ballCollidedRight = false;

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  delay(1000);
  
}

void loop() {
  float leftY = analogRead(A1) / 1023.0 * (64 - 20);
  float rightY = analogRead(A2) / 1023.0 * (64 - 20);

  for (int i = 0; i < 20; i++) {
    padel_pix_Left[i] = leftY + i;
    padel_pix_Right[i] = rightY + i;
  }

  for (int i = 0; i < 20; i++) {
    display.drawPixel(5, padel_pix_Left[i], SSD1306_WHITE);    
    display.drawPixel(120, padel_pix_Right[i], SSD1306_WHITE); 
  }

  Ball_pix_x[0] = Ball_pos[0];         Ball_pix_y[0] = Ball_pos[1];
  Ball_pix_x[1] = Ball_pos[0];         Ball_pix_y[1] = Ball_pos[1] + 1;
  Ball_pix_x[2] = Ball_pos[0] + 1;     Ball_pix_y[2] = Ball_pos[1] + 1;
  Ball_pix_x[3] = Ball_pos[0] + 1;     Ball_pix_y[3] = Ball_pos[1];
  Ball_pix_x[4] = Ball_pos[0] + 1;     Ball_pix_y[4] = Ball_pos[1] - 1;
  Ball_pix_x[5] = Ball_pos[0];         Ball_pix_y[5] = Ball_pos[1] - 1;
  Ball_pix_x[6] = Ball_pos[0] - 1;     Ball_pix_y[6] = Ball_pos[1] - 1;
  Ball_pix_x[7] = Ball_pos[0] - 1;     Ball_pix_y[7] = Ball_pos[1];
  Ball_pix_x[8] = Ball_pos[0] - 1;     Ball_pix_y[8] = Ball_pos[1] + 1;
  Ball_pix_x[9] = Ball_pos[0];         Ball_pix_y[9] = Ball_pos[1] + 2;
  Ball_pix_x[10] = Ball_pos[0] + 2;    Ball_pix_y[10] = Ball_pos[1];
  Ball_pix_x[11] = Ball_pos[0];        Ball_pix_y[11] = Ball_pos[1] - 2;
  Ball_pix_x[12] = Ball_pos[0] - 2;    Ball_pix_y[12] = Ball_pos[1];

  for (int i = 0; i < 13; i++) {
    display.drawPixel(Ball_pix_x[i], Ball_pix_y[i], SSD1306_WHITE);
  }

  if (Ball_pos[1] <= 0 || Ball_pos[1] >= 63) {
    Vy = -Vy;
  }

  if (Ball_pos[0] <= 6 && !ballCollidedLeft) {
    for (int j = 0; j < 20; j++) {
      if ((int)Ball_pos[1] == (int)padel_pix_Left[j]) {
        Vx = -Vx;
        ballCollidedLeft = true;
        break;
      }
    }
  } else if (Ball_pos[0] > 6) {
    ballCollidedLeft = false;
  }

  if (Ball_pos[0] >= 119 && !ballCollidedRight) {
    for (int j = 0; j < 20; j++) {
      if ((int)Ball_pos[1] == (int)padel_pix_Right[j]) {
        Vx = -Vx;
        ballCollidedRight = true;
        break;
      }
    }
  } else if (Ball_pos[0] < 119) {
    ballCollidedRight = false;
  }

  // Player 2 scores
  if (Ball_pos[0] <= 0) {
    Score_P2++;
    Ball_pos[0] = 64;
    Ball_pos[1] = 32;
    Vx = abs(Vx);
    
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(30, 0);
    display.print("P1: " + String(Score_P1));
    display.setCursor(30, 10);
    display.print("P2: " + String(Score_P2));
    display.display();
    delay(3000);

    if (Score_P2 == 9) {
      Score_P2 = 0;
      Score_P1 = 0;
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      String message = "Player 2 Won";
      int textWidth = message.length() * 6;
      int x = (128 - textWidth) / 2;
      int y = (64 - 8) / 2;
      display.setCursor(x, y);
      display.print(message);
      display.display();
      delay(3000);
    }
  }

  // Player 1 scores
  if (Ball_pos[0] >= 127) {
    Score_P1++;
    Ball_pos[0] = 64;
    Ball_pos[1] = 32;
    Vx = -abs(Vx);
    
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(30, 0);
    display.print("P1: " + String(Score_P1));
    display.setCursor(30, 10);
    display.print("P2: " + String(Score_P2));
    display.display();
    delay(3000);

    if (Score_P1 == 9) {
      Score_P2 = 0;
      Score_P1 = 0;
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      String message = "Player 1 Won";
      int textWidth = message.length() * 6;
      int x = (128 - textWidth) / 2;
      int y = (64 - 8) / 2;
      display.setCursor(x, y);
      display.print(message);
      display.display();
      delay(3000);
    }
  }

  // Move ball
  Sx = Ball_pos[0] + Vx * 0.008;
  Sy = Ball_pos[1] + Vy * 0.008;
  Ball_pos[0] = Sx;
  Ball_pos[1] = Sy;

  display.display();
  display.clearDisplay();
  
}
