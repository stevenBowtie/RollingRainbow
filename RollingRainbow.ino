byte dataPin=3;
byte clock=2;

byte green=255;
byte red=0;
byte blue=0;
byte leds=14;
int state=0;
byte color_step=10;
byte rate=1;
byte brightness=255;

byte value=0;

void setup(){
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
}

void loop(){
  for(int i=0;i<leds;i++){
    shiftOut(dataPin, clock, MSBFIRST, red);
    shiftOut(dataPin, clock, MSBFIRST, green);
    shiftOut(dataPin, clock, MSBFIRST, blue);
    //get_colors(i*color_step+state);
    get_colors(random(765));
  }
  state+=rate; //Add delay here if necesarry.
  state=state%765;
  delay(10);
  
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


