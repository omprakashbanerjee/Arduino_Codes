/************************************************************************************************************************************************************************                                              
 * - Author               : BELKHIR Mohamed                        *                                               
 * - Profession           : (Electrical Ingineer) MEGA DAS owner   *                                                                                              
 * - Main purpose         : Industrial Application                 *                                                                                 
 * - Copyright (c) holder : All rights reserved                    *
 * - License              : BSD 2-Clause License                   * 
 * - Date                 : 20/04/2017                             *
 * ***********************************************************************************************************************************************************************/
 
 /*********************************** NOTE **************************************/
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:

// * Redistributions of source code must retain the above copyright notice, this
//  list of conditions and the following disclaimer.

// * Redistributions in binary form must reproduce the above copyright notice,
//  this list of conditions and the following disclaimer in the documentation
//  and/or other materials provided with the distribution.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED

/*

                                                         ─▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄
                                                         █░░░█░░░░░░░░░░▄▄░██░█
                                                         █░▀▀█▀▀░▄▀░▄▀░░▀▀░▄▄░█
                                                         █░░░▀░░░▄▄▄▄▄░░██░▀▀░█
                                                         ─▀▄▄▄▄▄▀─────▀▄▄▄▄▄▄▀

*/
#include <Stepper.h>      // Include the stepper Motor librarie 
const int stepPerRotation = 20;          // Number of steps by turn. Standard value for CD/DVD
 
// Indicate X axis stepper motor Pins 
Stepper myStepperX(stepPerRotation, 8,9,10,11); 
 
void setup() 
{
 myStepperX.setSpeed(100);    // Stepper motor speed
 
}
 
void loop() {
  
  myStepperX.step(100);
 delay(1000);
 myStepperX.step(-100);              
 delay(1000);
 }
