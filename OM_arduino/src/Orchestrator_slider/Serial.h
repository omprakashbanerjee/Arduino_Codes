#ifndef SERIAL_H
#define SERIAL_H

#include "Utils.h"

void setup_serial(){ Serial.begin(115200); Serial.println(); }

unsigned int commandIndex = 0;

void show_splash_screen(){
  Serial.println("\n=============================== DEBUG MODE ==============================");
  Serial.println("=========================================================================");

  Serial.println("Initial Mode: Move slider OUTWARDS [Code: 1]");

  Serial.println("Change Current Mode: by Sending the Corresponding Number.\n");
  Serial.println("\tMove Slider OUTWARDS ===> 1");
  Serial.println("\tMove Slider INWARDS  ===> 2");
  Serial.println("\tSTOP Slider          ===> 3");
  Serial.println("\tIDLE mode            ===> 4");

  Serial.println("=========================================================================");
}

void print_state(){
  commandIndex++;
  Serial.println("\t"); Serial.print(commandIndex); Serial.print(". ");
  switch(motor_state){
    case MOVE:
    Serial.print("MOVING => ");
    if(motor_direction == OUTWARDS) { Serial.print("OUTWARDS"); }
    else if(motor_direction == INWARDS) { Serial.print("INWARDS"); }
    break;
    case STOP:
    Serial.print("STOPPED.");
    break;
    case IDLE:
    Serial.print("IDLE");
    break;
  }
}

char find_state(){
  #ifdef DEBUG
  Serial.println("L1, L2: ");Serial.print(digitalRead(LIMITSWITCH1_PIN));Serial.print(" -> ");
  Serial.print(digitalRead(LIMITSWITCH2_PIN));Serial.println();
  #endif
  
  if(digitalRead(LIMITSWITCH1_PIN) && digitalRead(LIMITSWITCH2_PIN))  { return 'm'; } // MIDDLE
  if(!digitalRead(LIMITSWITCH1_PIN)){ return 'b'; } // BACKWARD
  else if(!digitalRead(LIMITSWITCH2_PIN)){ return 'f'; } // FORWARD
}

void process_command(const short input){
  if(input == 0){ return; }

  switch(input){
    case COMMAND_MOVE_OUT: 
      if(find_state() == 'f') { 
        #ifdef DEBUG
        Serial.println("Already in the Outward most Position. Collision case avoided.");
        #endif
        break; 
      }
      else { motor_direction = OUTWARDS; motor_state = MOVE;  break; }
    case COMMAND_MOVE_IN: 
      if(find_state() == 'b') { 
        #ifdef DEBUG
        Serial.println("Already in the Inward most Position. Collision case avoided.");
        #endif
        break; 
      }
      else { motor_direction = INWARDS;  motor_state = MOVE;  break; }
    case 3: 
    Serial.println(find_state());
    motor_state = STOP;  break;
    case 4: motor_state = IDLE;  break;
    case 5: Serial.println(find_state()); break;
    default: break;
  }
  
  #ifdef DEBUG
  print_state();
  #endif
}

#endif
