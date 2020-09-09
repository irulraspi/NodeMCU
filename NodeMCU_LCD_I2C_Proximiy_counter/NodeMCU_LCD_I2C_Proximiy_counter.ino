#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int ir_pin = D5;  // pin
int counter = 0;
int hitObject = false;

//coklat = VCC 5V
//biru = GND
//hitam = OUT

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
	// initialize the LCD
	lcd.begin();
  pinMode(ir_pin, INPUT);

	// Turn on the blacklight and print a message.
	lcd.backlight();
	//lcd.print("Hello, world!");
}

void loop()
{
	// Do nothing here...
 int val = digitalRead(ir_pin);

  if ( (val == 0) && (hitObject == false) ) {
    counter++;
    hitObject = true;
    lcd.setCursor(0,0);
    lcd.print("Status saat ini ");
    lcd.setCursor(0,1);
    lcd.print("Counter = ");
    lcd.print( counter);
  }
  else if ( (val == 1) && (hitObject == true) ) {
    hitObject = false;
  }
}
