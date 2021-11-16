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

void cat_n_mouse()
{
  for (unsigned int i = 0; i < random(oled.getLCDWidth()); i++)
  {
    /*
    // Cat
    int cat_x = random(oled.getLCDWidth());
    int cat_y = random(oled.getLCDHeight());
    int cat_head = 9;
    int cat_left_ear_rad = 3;
    int cat_right_ear_rad = 3;
    //int cat_left_eye_rad = 4;
    //int cat_right_eye_rad = 6;
    //int cat_pupil_rad = 2;

    // Head
    oled.circle(cat_x, cat_y, cat_head);

    // Left Ear
    oled.circle(cat_x + 9, cat_y - 9, cat_left_ear_rad);

    // Right Ear
    oled.circle(cat_x - 9, cat_y - 9, cat_right_ear_rad);
    
    // Left Eye
    //oled.circle(cat_x + 10, cat_y - 2, cat_left_eye_rad);
    //oled.circleFill(cat_x + 10, cat_y - 2, cat_pupil_rad);
    
    // Right Eye
    //oled.circle(cat_x, cat_y - 1, cat_right_eye_rad);
    //oled.circleFill(cat_x, cat_y - 1, cat_pupil_rad);
    */
   
    // Mouse
    int mouse_x = random(oled.getLCDWidth());
    int mouse_y = random(oled.getLCDHeight());
    int mouse_head = 6;
    int mouse_left_ear_rad = 4;
    int mouse_right_ear_rad = 4;

    // Head
    oled.circle(mouse_x, mouse_y, mouse_head);

    // Left Eye
    //oled.pixel(mouse_x + 2, mouse_y - 1);

    // Right Eye
    //oled.pixel(mouse_x - 2, mouse_y - 1);

    // Nose
    oled.pixel(mouse_x, mouse_y + 2);

    // Left Ear
    oled.circle(mouse_x + 7, mouse_y - 7, mouse_left_ear_rad);

    // Right Ear
    oled.circle(mouse_x - 7, mouse_y - 7, mouse_right_ear_rad);

    
    oled.display();
    delay(500);
    oled.clear(PAGE);
    delay(500);
  }
}


void loop()
{
  Mouse.move(9, 0); //Start mouse moving
  delay(36);
  Mouse.move(-9, 0); //Move it back
  //lineExample();   // Then the line example function
  cat_n_mouse();
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
