#include <TeensyView.h>  // Include the SFE_TeensyView library
#include <Bounce.h>

///////////////////////////////////
// TeensyView Object Declaration //
///////////////////////////////////
//Standard
#define PIN_RESET 15
#define PIN_DC    5
#define PIN_CS    10
#define PIN_SCK   13
#define PIN_MOSI  11


TeensyView oled(PIN_RESET, PIN_DC, PIN_CS, PIN_SCK, PIN_MOSI);

void setup()
{
  oled.begin();    // Initialize the OLED
  oled.clear(ALL); // Clear the display's internal memory
  oled.display();  // Display what's in the buffer (splashscreen)
  delay(1000);     // Delay 1000 ms
  oled.clear(PAGE); // Clear the buffer.

  randomSeed(analogRead(A0) + analogRead(A1));

  printTitle("Cat n Mouse", 1);
  pinMode(4, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
}

void lineExample()
{
  int middleX = oled.getLCDWidth() / 2;
  int middleY = oled.getLCDHeight() / 2;
  int xEnd, yEnd;
  int lineWidth = min(middleX, middleY);

  for (int deg = 0; deg < 360; deg += 10)
  {
    xEnd = lineWidth * cos(deg * PI / 180.0);
    yEnd = lineWidth * sin(deg * PI / 180.0);

    oled.line(middleX, middleY, middleX + xEnd, middleY + yEnd);
    oled.display();
    delay(1000);
  }
  for (int deg = 0; deg < 360; deg += 10)
  {
    xEnd = lineWidth * cos(deg * PI / 180.0);
    yEnd = lineWidth * sin(deg * PI / 180.0);

    oled.line(middleX, middleY, middleX + xEnd, middleY + yEnd, BLACK, NORM);
    oled.display();
    delay(10);
  }
}

void loop()
{
  Mouse.move(36, 0); //Start mouse moving
  delay(36);
  Mouse.move(-36, 0); //Move it back
  lineExample();   // Then the line example function
}

// Center and print a small title
// This function is quick and dirty. Only works for titles one
// line long.
void printTitle(String title, int font)
{
  int middleX = oled.getLCDWidth() / 2;
  int middleY = oled.getLCDHeight() / 2;

  oled.clear(PAGE);
  oled.setFontType(font);
  // Try to set the cursor in the middle of the screen
  oled.setCursor(middleX - (oled.getFontWidth() * (title.length() / 2)),
                 middleY - (oled.getFontWidth() / 2));
  // Print the title:
  oled.print(title);
  oled.display();
  delay(3000);
  oled.clear(PAGE);
}
