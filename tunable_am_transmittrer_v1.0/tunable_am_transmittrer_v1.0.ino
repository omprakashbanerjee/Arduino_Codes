/*
 Name:    transmitter.ino
 Created: 6/08/2020
 Author:  Nate Stone
 
 Original transmitter code came from Dr. Volt.
*/
#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <Adafruit_GFX.h>
#include "Adafruit_MonoOLED.h"
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define ANTENNA_PIN PB3 //Arduino Nano/Uno D11

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

uint32_t fTransmit = 600; //KHz



bool transmitting = false;


void writeScreen(void) {
  
  display.clearDisplay();

  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.println(F("AM Radio Transmitter"));

  if(transmitting){
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
  display.println("TRANSMITTING");
  }
  else{
    display.println("NOT TRANSMITTING");
  }

  display.setTextSize(1);             // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.print("Frequency: "); 
  display.print(fTransmit);
  display.println(" kHz");
  display.display();
}


void transmitCall(){

  //Carrier Frequency generation
  uint32_t fTransmitCall;
  if(transmitting){
    fTransmitCall = fTransmit;
  }
  else{
    fTransmitCall = 0;
  }
  DDRB |= (1 << ANTENNA_PIN);
  TCCR2A = (0 << COM2A1) + (1 << COM2A0); //Toggle OC0A on Compare Match
  TCCR2A |= (1 << WGM21) + (0 << WGM20); //CTC
  TCCR2B = (0 << CS22) + (0 << CS21) + (1 << CS20); //No Prescaling
  OCR2A = F_CPU / (2000 * fTransmitCall) - 1;
  
  char strbuf[255];
  sprintf(strbuf, "Will broadcast at %d KHz", (F_CPU / (2 * (1 + OCR2A)) / 1000));
  Serial.println(strbuf);

  //PWM Signal generation
  //TCCR1A |= (0 << WGM11) + (1 << WGM10);  //Fast PWM 8 Bit
  //TCCR1A |= (1 << WGM11) + (0 << WGM10);  //Fast PWM 9 Bit
  TCCR1A |= (1 << WGM11) + (1 << WGM10); //Fast PWM 10 Bit
  TCCR1B = (1 << WGM12);          
  TCCR1B |= (0 << CS12) + (0 << CS11) + (1 << CS10); //No Prescaling
  TIMSK1 = (1 << OCIE1A) + (1 << TOIE1);

  //ADC Settings
  ADMUX = (1 << REFS1) + (1 << REFS0); //Reference internal 1.1V
  ADCSRA = (1 << ADEN) + (1 << ADSC) + (1 << ADATE); //Auto Trigger enable, free running
  ADCSRA |= (1 << ADPS2) + (1 << ADPS1) + (0 << ADPS0); //Divide by 64 -> 18.5k Sample rate
  DIDR0 = (1 << ADC0D);
  
  
}

// the setup function runs once when you press reset or power the board
void setup() {
  //Serial.begin(115200);
  Serial.begin(9600);
  pinMode(7,INPUT);//down
  pinMode(8,INPUT);//up
  pinMode(9,INPUT); //Transmit Pin

  transmitCall();

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  
  writeScreen();    // Draw 'stylized' characters
}

ISR(TIMER1_OVF_vect) {
  uint8_t adcl = ADCL;
  uint8_t adch = ADCH;
  OCR1A = (adch << 8) + adcl;
  DDRB |= (1 << ANTENNA_PIN);
}

ISR(TIMER1_COMPA_vect) {
  DDRB &= ~(1 << ANTENNA_PIN);
}

void loop() {
  if(digitalRead(7)==HIGH){
    if(fTransmit >400){
      fTransmit= fTransmit-10;
    }
    if(transmitting){
      transmitCall();
    }
    transmitting=false;
    writeScreen();
    delay(500);
  }
  if(digitalRead(8)==HIGH){
    if(fTransmit <3000){
      fTransmit= fTransmit+10;
    }
    if(transmitting){
      transmitCall();
    }
    transmitting=false;
    writeScreen();
    delay(500);
  }
  if(digitalRead(9)==HIGH){
    if(!transmitting){
      transmitting=true;
    }
    else{
      transmitting = false;
    }
    transmitCall();
    writeScreen();
    delay(1000);
  }
}
