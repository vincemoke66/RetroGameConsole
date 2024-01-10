#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI 9
#define OLED_CLK 10
#define OLED_DC 11
#define OLED_CS 12
#define OLED_RESET 13
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
                         OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;

// bitmap graphic
const unsigned char PROGMEM dioda16[] = {
    0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x3F, 0xF0, 0x3C, 0x00, 0x3C, 0x00, 0xFF, 0x00, 0x7F, 0xFF,
    0x7F, 0xFF, 0xFF, 0x00, 0x3C, 0x00, 0x3C, 0x00, 0x1F, 0xF0, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00};

const unsigned char PROGMEM storm[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7F, 0xFE, 0x00, 0x00, 0x00, 0x07, 0x80, 0x01, 0xE0, 0x00, 0x00, 0x0C,
    0x00, 0x00, 0x20, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x30, 0x00, 0x00, 0x04, 0x00,
    0x00, 0x20, 0x00, 0x00, 0x04, 0x00, 0x00, 0x20, 0x00, 0x00, 0x04, 0x00, 0x00, 0x60, 0x00, 0x00,
    0x02, 0x00, 0x00, 0x40, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x00, 0x00, 0x01, 0x00, 0x00, 0x40,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x40, 0x00, 0x00, 0x01, 0x00, 0x00, 0x7F, 0xE0, 0x00, 0x01, 0x00,
    0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xD7, 0xFF, 0xFF,
    0xE1, 0x00, 0x01, 0xBF, 0xFC, 0x1F, 0xFA, 0x80, 0x01, 0xBF, 0xF1, 0xCF, 0xFA, 0x80, 0x01, 0x3F,
    0xC2, 0x37, 0xF7, 0x80, 0x01, 0xEF, 0x9C, 0x01, 0xE7, 0xC0, 0x01, 0xE0, 0x70, 0x06, 0x06, 0x80,
    0x01, 0xE0, 0xC0, 0x03, 0x06, 0x80, 0x01, 0xFF, 0x80, 0x01, 0xFF, 0x80, 0x01, 0xF8, 0x00, 0x00,
    0x1D, 0xC0, 0x03, 0x70, 0x00, 0x80, 0x0C, 0x60, 0x05, 0xB0, 0x07, 0xF0, 0x08, 0x90, 0x09, 0x10,
    0x1F, 0xF8, 0x09, 0xD0, 0x0B, 0x90, 0x1F, 0x7C, 0x03, 0xF0, 0x0F, 0xC0, 0xFC, 0x0F, 0x07, 0x90,
    0x0D, 0x43, 0xC0, 0x03, 0x07, 0x90, 0x05, 0x64, 0x00, 0x00, 0xCF, 0x10, 0x07, 0xFC, 0x00, 0x00,
    0x26, 0x10, 0x01, 0x80, 0x00, 0x00, 0x10, 0x20, 0x01, 0x00, 0x00, 0x00, 0x0E, 0x40, 0x01, 0x80,
    0x07, 0xF0, 0x01, 0x80, 0x00, 0x80, 0x07, 0xC8, 0x00, 0x80, 0x00, 0x80, 0x0B, 0xE8, 0x00, 0x80,
    0x00, 0x87, 0x97, 0xE9, 0xE0, 0x80, 0x00, 0x87, 0xDF, 0xEF, 0xA0, 0x80, 0x00, 0x4B, 0xFF, 0xFF,
    0xA0, 0x80, 0x00, 0x6B, 0xDF, 0xFB, 0xA3, 0x00, 0x00, 0x24, 0x97, 0xE8, 0x24, 0x00, 0x00, 0x1E,
    0x1F, 0xC0, 0x2C, 0x00, 0x00, 0x07, 0xF8, 0x1F, 0xF0, 0x00, 0x00, 0x00, 0x0F, 0xF8, 0x00, 0x00};

// game initial states
int bulletX = 0;
int bulletY = 0;
int bulletExists = 0;
int enemyY = 8;
int direction = 0;
int gameOver = 0;
int enemy1X = 95;
int enemy1Y = 0;
int enemy2X = 95;
int enemy2Y = 0;
int enemy3X = 95;
int enemy3Y = 0;
int score = 0;

// game mechanics variables
int bulletSpeed = 3;     // speed of bullet
int bulletCount = 1;     // number of bullets
int bulletDiameter = 10; // bullet diameter
int minDelay = 600;      // minimum delay
int maxDelay = 1200;     // maximum delay

int enemy4X = 95;
int enemy4Y = 0;
int playerLife = 5; // player life
int initializationFlag = 0;
int bulletsFired = 0;
int currentLevel = 1;
int displayCenterValue = 95; // center of the display
unsigned long initialTime = 0;
unsigned long chosenTime = 0;
unsigned long currentTime = 0;
unsigned long levelTimer = 0;
int playerPosition = 30;

// pin assignments
int goUpPin = 7;
int goDownPin = 6;
int firePin = 5;
int buzzerPin = 4;

void setup()
{
  // buttons pin configuration
  pinMode(firePin, INPUT_PULLUP);   // for firing
  pinMode(goUpPin, INPUT_PULLUP);   // for going up
  pinMode(goDownPin, INPUT_PULLUP); // for going down

  // initializing OLED display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  display.clearDisplay();
  display.setTextSize(0);
  display.drawBitmap(6, 11, storm, 48, 48, 1);
  display.setFont(&FreeSans9pt7b);
  display.setTextColor(WHITE);
  display.setCursor(65, 14);
  display.println("PaCAO");
  display.setFont();
  display.setCursor(65, 17);
  display.setTextSize(0);
  display.println("vs");
  display.setCursor(0, 0);
  display.setFont(&FreeSans9pt7b);
  display.setCursor(65, 39);
  display.println("Death");
  display.setFont();
  display.setCursor(65, 42);
  display.println("star ");
  display.setTextSize(0);

  display.setCursor(65, 55);

  display.println("by CpE_4N");

  display.setCursor(65, 20);

  display.display();

  display.setFont();
  beep(a, 500);
  beep(a, 500);
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

  delay(500);

  delay(500);
}

void loop()
{

  if (gameOver == 0)
  {
    display.clearDisplay();

    display.drawPixel(50, 30, 1);
    display.drawPixel(30, 17, 1);
    display.drawPixel(60, 18, 1);
    display.drawPixel(55, 16, 1);
    display.drawPixel(25, 43, 1);
    display.drawPixel(100, 43, 1);
    display.drawPixel(117, 52, 1);
    display.drawPixel(14, 49, 1);
    display.drawPixel(24, 24, 1);
    display.drawPixel(78, 36, 1);
    display.drawPixel(80, 57, 1);
    display.drawPixel(107, 11, 1);
    display.drawPixel(150, 11, 1);
    display.drawPixel(5, 5, 1);
    display.drawPixel(8, 7, 1);
    display.drawPixel(70, 12, 1);
    display.drawPixel(10, 56, 1);
    display.drawPixel(70, 25, 1);

    if (initializationFlag == 0)
    {
      initialTime = millis();
      chosenTime = random(400, 1200);
      initializationFlag = 1;
    }
    currentTime = millis();

    if ((currentTime - levelTimer) > 50000)
    {
      levelTimer = currentTime;
      currentLevel = currentLevel + 1;

      bulletSpeed = bulletSpeed + 1;
      if (currentLevel % 2 == 0)
      {
        bulletCount = bulletCount + 1;
        bulletDiameter = bulletDiameter - 1;
      }
      minDelay = minDelay - 50;
      maxDelay = maxDelay - 50;
    }

    if ((chosenTime + initialTime) < currentTime)
    {
      initializationFlag = 0;
      bulletsFired = bulletsFired + 1;
      if (bulletsFired == 1)
      {
        enemy1X = 95;
        enemy1Y = enemyY;
      }
      if (bulletsFired == 2)
      {
        enemy2X = 95;
        enemy2Y = enemyY;
      }
      if (bulletsFired == 3)
      {
        enemy3X = 95;
        enemy3Y = enemyY;
      }

      if (bulletsFired == 4)
      {
        enemy4X = 95;
        enemy4Y = enemyY;
      }
    }

    if (bulletsFired > 0)
    {
      display.drawCircle(enemy1X, enemy1Y, 2, 1);
      enemy1X = enemy1X - bulletSpeed;
    }

    if (bulletsFired > 1)
    {
      display.drawCircle(enemy2X, enemy2Y, 1, 1);
      enemy2X = enemy2X - bulletSpeed;
    }

    if (bulletsFired > 2)
    {
      display.drawCircle(enemy3X, enemy3Y, 4, 1);
      enemy3X = enemy3X - bulletSpeed;
    }

    if (bulletsFired > 3)
    {
      display.drawCircle(enemy4X, enemy4Y, 2, 1);
      enemy4X = enemy4X - bulletSpeed;
    }

    // go up
    if (digitalRead(goUpPin) == 0 && playerPosition >= 2)
    {
      playerPosition = playerPosition - 2;
    }

    // go down
    if (digitalRead(goDownPin) == 0 && playerPosition <= 46)
    {
      playerPosition = playerPosition + 2;
    }

    if (digitalRead(firePin) == 0 && bulletExists == 0)
    {
      bulletExists = 1;
      bulletX = 6;
      bulletY = playerPosition + 8;
      tone(buzzerPin, 1200, 20);
    }
    if (bulletExists == 1)

    {
      bulletX = bulletX + 8;

      display.drawLine(bulletX, bulletY, bulletX + 4, bulletY, 1);
    }

    display.drawBitmap(4, playerPosition, dioda16, 16, 16, 1);
    display.fillCircle(displayCenterValue, enemyY, bulletDiameter, 1);
    display.fillCircle(displayCenterValue + 2, enemyY + 3, bulletDiameter / 3, 0);

    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(33, 57);
    display.println("score:");
    display.setCursor(68, 57);
    display.println(score);

    display.setCursor(33, 0);
    display.println("lives:");
    display.setCursor(68, 0);
    display.println(playerLife);

    display.setCursor(110, 0);
    display.println("L:");

    display.setCursor(122, 0);
    display.println(currentLevel);

    display.setCursor(108, 57);
    display.println(currentTime / 1000);
    display.display();

    if (bulletX > 128)
      bulletExists = 0;

    if (direction == 0)
    {
      enemyY = enemyY + bulletCount;
    }
    else
    {
      enemyY = enemyY - bulletCount;
    }

    if (enemyY >= (64 - bulletDiameter))
      direction = 1;
    if (enemyY <= bulletDiameter)
      direction = 0;

    if (bulletY >= enemyY - bulletDiameter && bulletY <= enemyY + bulletDiameter)
      if (bulletX > (displayCenterValue - bulletDiameter) && bulletX < (displayCenterValue + bulletDiameter))
      {
        bulletX = -20;
        tone(buzzerPin, 500, 20);
        score = score + 1;
        bulletExists = 0;
      }

    int pozicija = playerPosition + 8;
    if (enemy1Y >= pozicija - 8 && enemy1Y <= pozicija + 8)
      if (enemy1X < 12 && enemy1X > 4)
      {
        enemy1X = 95;
        enemy1Y = -50;
        tone(buzzerPin, 100, 100);
        playerLife = playerLife - 1;
      }

    if (enemy2Y >= pozicija - 8 && enemy2Y <= pozicija + 8)
      if (enemy2X < 12 && enemy2X > 4)
      {
        enemy2X = -50;
        enemy2Y = -50;
        tone(buzzerPin, 100, 100);
        playerLife = playerLife - 1;
      }

    if (enemy3Y >= pozicija - 8 && enemy3Y <= pozicija + 8)
      if (enemy3X < 12 && enemy3X > 4)
      {
        enemy3X = -50;
        enemy3Y = -50;
        tone(buzzerPin, 100, 100);
        playerLife = playerLife - 1;
      }

    if (enemy4Y >= pozicija - 8 && enemy4Y <= pozicija + 8)
      if (enemy4X < 12 && enemy4X > 4)
      {
        enemy4X = 200;
        enemy4Y = -50;
        bulletsFired = 0;
        tone(buzzerPin, 100, 100);
        playerLife = playerLife - 1;
      }

    if (enemy4X < 1)
    {
      bulletsFired = 0;
      enemy4X = 200;
    }

    if (playerLife == 0)
      gameOver = 1;
  }

  if (gameOver == 1)
  {
    if (playerLife == 0)
    {
      tone(buzzerPin, 200, 300);
      delay(300);
      tone(buzzerPin, 250, 200);
      delay(200);
      tone(buzzerPin, 300, 300);
      delay(300);
      playerLife = 5;
    }
    display.clearDisplay();
    display.setFont();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(7, 10);
    display.println("GAME OVER!");
    display.setTextSize(1);
    display.setCursor(7, 30);
    display.println("score:");
    display.setCursor(44, 30);
    display.println(score);
    display.setCursor(7, 40);
    display.println("level:");
    display.setCursor(44, 40);
    display.println(currentLevel);
    display.setCursor(7, 50);
    display.println("time(s):");
    display.setCursor(60, 50);

    display.println(currentTime / 1000);
    display.display();

    if (digitalRead(3) == 0)
    {
      tone(buzzerPin, 280, 300);
      delay(300);
      tone(buzzerPin, 250, 200);
      delay(200);
      tone(buzzerPin, 370, 300);
      delay(300);
      ponovo();
    }
  }
}

void ponovo()
{
  bulletX = 0;
  bulletY = 0;
  bulletExists = 0;
  enemyY = 8;
  direction = 0;
  gameOver = 0;
  enemy1X = 95;
  enemy1Y = 0;
  enemy2X = 95;
  enemy2Y = 0;
  enemy3X = 95;
  enemy3Y = 0;
  score = 0;

  bulletSpeed = 3;
  bulletCount = 1;
  minDelay = 600;
  maxDelay = 1200;
  bulletDiameter = 12;

  enemy4X = 95;
  enemy4Y = 0;
  playerLife = 5;
  initializationFlag = 0;
  bulletsFired = 0;
  currentLevel = 1;
  initialTime = 0;
  chosenTime = 0;
  currentTime = 0;
  levelTimer = 0;
}

// play a note
void beep(int note, int duration)
{
  // Play tone on buzzerPin
  tone(buzzerPin, note, duration);

  delay(duration);

  noTone(buzzerPin);

  delay(50);
}
