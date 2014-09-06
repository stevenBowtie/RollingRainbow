byte dataPin=3;
byte clock=2;

byte green=255;
byte red=0;
byte blue=0;
byte leds=15;
int state=0;
byte color_step=20;
byte rate=10;
byte brightness=255;
byte mode=4;

byte value=0;

void setup(){
  pinMode(0,OUTPUT);
  digitalWrite(0,1);
  pinMode(0,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  for(int i=0;i<leds;i++){
    shiftOut(dataPin, clock, MSBFIRST, red);
    shiftOut(dataPin, clock, MSBFIRST, green);
    shiftOut(dataPin, clock, MSBFIRST, blue);
  }
  delay(200);
}

void loop(){
  for(int i=leds;i>0;i--){
    mode_switch();
    switch(mode){
      case 0:
        get_colors(i*color_step+state);
        rate=10;
        break;
      case 1:
        get_colors(random(765));
        rate=10;
        break;
    }
    shiftOut(dataPin, clock, MSBFIRST, red);
    shiftOut(dataPin, clock, MSBFIRST, green);
    shiftOut(dataPin, clock, MSBFIRST, blue);
  }
  if(mode==2){get_colors(random(765));rate=50;}
  if(mode==3){red=255;green=255;blue=255;}
  if(mode==4){red=0;green=0;blue=0;}
  state+=1; //Add delay here if necesarry.
  state=state%765;
  delay(rate);
  
}

void get_colors(int current_state){
  current_state=current_state%765;
  if(current_state<255){
    green=min(brightness,max(0,255-current_state));
    blue=min(brightness,max(0,current_state));
    red=0;
  }
  if(current_state>255 && current_state<512){
    blue=min(brightness,max(0,512-current_state));
    red=min(brightness,max(0,current_state-255));
    green=0;
  }
  if(current_state>512){
    red=min(brightness,max(0,764-current_state));
    green=min(brightness,max(0,current_state-512));
    blue=0;
  }
}

void mode_switch(){
  if(!digitalRead(0)){
    mode=(mode+1)%5;
    delay(500);
  }
}
  

