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
uint8_t state=0;
NexButton bt0 = NexButton(0, 3, "bt0");
NexText t0 = NexText(0, 2, "t0");

NexTouch *nex_listen_list[] = 
{
    &bt0,
    NULL
};

void bt0PopCallback(void *ptr)
{
   if(state==0)
   {
    state=1;
    t0.setText("State ON");
   digitalWrite(led,state);
   }
    else
    {
    state=0;
    t0.setText("State OFF");
   digitalWrite(led,state);
   }
}


void setup(void)
{    Serial.begin(9600);
    nexInit();
    bt0.attachPop(bt0PopCallback, &bt0);
   pinMode(led,OUTPUT);
   digitalWrite(led,0);
}

void loop(void)
{   
    nexLoop(nex_listen_list);
}
