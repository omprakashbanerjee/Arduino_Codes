/**
 * @example CompButton.ino
 * 
 * @par How to Use
 * Show how to use API of class NexButton.  
 *
 * @author  Wu Pengfei (email:<pengfei.wu@itead.cc>)
 * @date    2015/7/10
 * @copyright 
 * Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */

#include "Nextion.h"
const int led=10;
NexButton b0 = NexButton(0, 4, "b0");
NexButton b1 = NexButton(0, 5, "b1");
//NexText t0 = NexText(0, 4, "t0");
//char buffer[100] = {0};

NexTouch *nex_listen_list[] = 
{
    &b0,&b1,
    NULL
};

void b0PopCallback(void *ptr)
{
  // t0.setText("State ON");
   digitalWrite(led,1);
}
void b1PopCallback(void *ptr)
{
   //t0.setText("State OFF");
   digitalWrite(led,0);
}

void setup(void)
{    Serial.begin(9600);
    nexInit();
    b0.attachPop(b0PopCallback, &b0);
     b1.attachPop(b1PopCallback, &b1);
   // dbSerialPrintln("setup done"); 
   pinMode(led,OUTPUT);
   digitalWrite(led,0);
}

void loop(void)
{   
    nexLoop(nex_listen_list);
}
