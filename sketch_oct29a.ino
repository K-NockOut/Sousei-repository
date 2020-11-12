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
   if(errortype=0){
   tft.setCursor(12,40);
   tft.setTextColor(WHITE,BLACK);
   tft.setTextSize(2);
   tft.print("Divide by 0");
   } 
}
//プリプロセッサ部ここまで

//セットアップ部
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
//セットアップ部ここまで

//ループ部
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
  }
  dispresult();
}
//ループ部ここまで
