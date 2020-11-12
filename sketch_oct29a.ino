#include <TouchScreen.h>
#include <Elegoo_TFTLCD.h>
#include <Elegoo_GFX.h>

//プリプロセッサ部
#define BLACK   0x0000
#define BLUE    0x001F
#define WHITE   0xFFFF
#define ORANGE  0xE3C0

double num1=0;
double num2=0;
double result=0;

int phase=0;

int number=0;

int errortype=0;
int calctype=0;

#define YP A3 
#define XM A2
#define YM 9
#define XP 8

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0

#define LCD_RESET A4

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
Elegoo_GFX_Button button[16];

void dispresult(){

if(phase==3){
        tft.setCursor(12,40);
        tft.setTextColor(WHITE,BLACK);
        tft.setTextSize(2);
        tft.print(result);
}
else if(phase==2){
        tft.setCursor(12,40);
        tft.setTextColor(WHITE,BLACK);
        tft.setTextSize(2);
        tft.print(num2);
}
else if(phase==1){
        tft.setCursor(12,40);
        tft.setTextColor(WHITE,BLACK);
        tft.setTextSize(3);
        tft.print(num1);
}
else if(phase==0){
        tft.setCursor(12,40);
        tft.setTextColor(WHITE,BLACK);
        tft.setTextSize(2);
        tft.print("Press a button");
}
}

void disperror(){
   if(errortype==0){
   tft.setCursor(12,40);
   tft.setTextColor(WHITE,BLACK);
   tft.setTextSize(2);
   tft.print("E:Divide by 0");
   } 
   if(errortype==1){
   tft.setCursor(12,40);
   tft.setTextColor(WHITE,BLACK);
   tft.setTextSize(2);
   tft.print("E:Select operator");
   }
}

void calc(){

  if(number>=0&&number<=9){

    if(phase==0){
      num1=number;
      phase=1;
    }
    else if(phase==1){
      num1=num1*10;
      num1=num1+number;
    }
    else if(phase==2){
      num2=number;
      phase=3;
    }
    else if(phase==3){
      num2=num2*10;
      num2=num2+number;
    } 
  }
  else if(number=10){ 
    if(phase==0){
    }
    if(phase==1){
      phase=2;
      calctype=0;
    }
    if(phase==2){
      
      if(calctype==0){
        num1=num1+num2;
        num2=0;
      }
      if(calctype==1){
        num1=num1-num2;
        num2=0;
      }
      if(calctype==2){
        num1=num1*num2;
        num2=0;
      }
      if(calctype==3){
        if(num2==0){
        errortype=0;
        disperror();
        num2=0;
       }
       else{
        num1=num1/num2;
        num2=0;
       }
      }
    }
    
  }
  else if(number==11){ 
    if(phase=0){
    }
    if(phase=1){
      phase=2;
      calctype=1;
    }
    if(phase=2){
      
      if(calctype==0){
        num1=num1+num2;
        num2=0;
      }
      if(calctype==1){
        num1=num1-num2;
        num2=0;
       }
      if(calctype==2){
        num1=num1*num2;
        num2=0;
      }
      if(calctype==3){
        if(num2==0){
        errortype=0;
        disperror();
        num2=0;
       }
       else{
        num1=num1/num2;
        num2=0;
       }
      }
    }
  }
  else if(number==12){ 
    if(phase==0){
    }
    if(phase==1){
      phase=2;
      calctype=2;
    }
    if(phase==2){
      
      if(calctype==0){
        num1=num1+num2;
        num2=0;
      }
      if(calctype==1){
        num1=num1-num2;
        num2=0;
      }
      if(calctype==2){
        num1=num1*num2;
        num2=0;
      }
      if(calctype==3){
       if(num2==0){
        errortype=0;
        disperror();
        num2=0;
       }
       else{
        num1=num1/num2;
        num2=0;
       }
      }
    }
  }
  else if(number==13){
    if(phase==0){
    }
    if(phase==1){
      phase=2;
      calctype=3;
    }
    if(phase==2){
      
      if(calctype==0){
        num1=num1+num2;
        num2=0;
      }
      if(calctype==1){
        num1=num1-num2;
        num2=0;
      }
      if(calctype==2){
        num1=num1*num2;
        num2=0;
      }
      if(calctype==3){
        if(num2==0){
        errortype=0;
        disperror();
        num2=0;
       }
       else{
        num1=num1/num2;
        num2=0;
       }
      }
    }
  }
  else if(number==14){
    if(phase==0){
      
    }
    if(phase==1){
      if(calctype==0){
        result=num1*2;
        phase=3;
      }
      if(calctype==1){
        result=0;
        phase=3;
      }
      if(calctype==2){
        result=num1*num1;
        phase=3;
      }
      if(calctype==3){
        result=1;
        phase=3;
      }
      else{
        errortype=1;
        disperror();
      }
    }
    if(phase==2){
      if(calctype==0){
        result=num1+num2;
        phase=3;
      }
      else if(calctype==1){
        result=num1-num2;
        phase=3;
      }
      else if(calctype==2){
        result=num1*num2;
        phase=3;
      }
      else if(calctype==3){
       if(num2==0){
        errortype=0;
        disperror();
        num2=0;
        phase=1;
       }
       else{
        result=num1/num2;
        num2=0;
        phase=3;
       }
      }
      else{
        errortype=1;
        disperror();
      }
     }
    }
  else if(number==15){

    if(phase==3){
      num1=num2=result=0;
      phase=0;
    }
    else if(phase==2){
      num2=0;
      phase=1;
    }
    else if(phase==1){
      num1=0;
      phase=0;
    }
    else if(phase==0){}
}
}

//プリプロセッサ部ここまで

//セットアップ部
void setup(){
tft.fillScreen(BLACK);

button[0].initButton(&tft,120,220,60,30,WHITE,BLUE,WHITE,"0",2);
button[1].initButton(&tft,40,100,60,30,WHITE,BLUE,WHITE,"1",2);
button[2].initButton(&tft,120,100,60,30,WHITE,BLUE,WHITE,"2",2);
button[3].initButton(&tft,200,100,60,30,WHITE,BLUE,WHITE,"3",2);
button[4].initButton(&tft,40,140,60,30,WHITE,BLUE,WHITE,"4",2);
button[5].initButton(&tft,120,140,60,30,WHITE,BLUE,WHITE,"5",2);
button[6].initButton(&tft,200,140,60,30,WHITE,BLUE,WHITE,"6",2);
button[7].initButton(&tft,40,180,60,30,WHITE,BLUE,WHITE,"7",2);
button[8].initButton(&tft,120,180,60,30,WHITE,BLUE,WHITE,"8",2);
button[9].initButton(&tft,200,180,60,30,WHITE,BLUE,WHITE,"9",2);
button[10].initButton(&tft,40,260,60,30,WHITE,ORANGE,WHITE,"+",2);
button[11].initButton(&tft,40,300,60,30,WHITE,ORANGE,WHITE,"-",2);
button[12].initButton(&tft,120,260,60,30,WHITE,ORANGE,WHITE,"*",2); 
button[13].initButton(&tft,120,300,60,30,WHITE,ORANGE,WHITE,"/",2);
button[14].initButton(&tft,200,260,60,30,WHITE,ORANGE,WHITE,"=",2);
button[15].initButton(&tft,200,300,60,30,WHITE,ORANGE,WHITE,"C",2);
 
for(int i=0;i<16;i++){
    button[i].drawButton();
}
}
//セットアップ部ここまで

//ループ部
void loop(){
TSPoint p = ts.getPoint();

for(int i=0; i<16; i++){

  if(button[i].contains(p.x, p.y)){
    button[i].press(true);
  }
  else{
    button[i].press(false);
  }
  if(button[i].justReleased()) {
    button[i].drawButton();
  }
  if(button[i].justPressed()) {
    button[i].drawButton(true);
    calc();
  }
  dispresult();
}
}
//ループ部ここまで
