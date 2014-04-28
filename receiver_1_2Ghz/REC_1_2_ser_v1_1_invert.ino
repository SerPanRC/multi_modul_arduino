/*
  20.07.2013
  SerPanRC@yandex.ru
  http://forum.rcdesign.ru/f90/thread327590.html
  
  */

#include <Wire.h>
#include <EEPROM.h>
static const byte FREGLOW[]= {91,98,101,104,106,108,110,112,114,116,118,120,124,128,132,136};
static const byte ASCII[][5] ={
{0x00, 0x00, 0x00, 0x00, 0x00} // 20
,{0x00, 0x00, 0x5f, 0x00, 0x00} // 21 !
,{0x00, 0x07, 0x00, 0x07, 0x00} // 22 "
,{0x14, 0x7f, 0x14, 0x7f, 0x14} // 23 #
,{0x24, 0x2a, 0x7f, 0x2a, 0x12} // 24 $
,{0x23, 0x13, 0x08, 0x64, 0x62} // 25 %
,{0x36, 0x49, 0x55, 0x22, 0x50} // 26 &
,{0x00, 0x05, 0x03, 0x00, 0x00} // 27 '
,{0x00, 0x1c, 0x22, 0x41, 0x00} // 28 (
,{0x00, 0x41, 0x22, 0x1c, 0x00} // 29 )
,{0x14, 0x08, 0x3e, 0x08, 0x14} // 2a *
,{0x08, 0x08, 0x3e, 0x08, 0x08} // 2b +
,{0x00, 0x50, 0x30, 0x00, 0x00} // 2c ,
,{0x08, 0x08, 0x08, 0x08, 0x08} // 2d -
,{0x00, 0x60, 0x60, 0x00, 0x00} // 2e .
,{0x20, 0x10, 0x08, 0x04, 0x02} // 2f /
,{0x3e, 0x51, 0x49, 0x45, 0x3e} // 30 0
,{0x00, 0x42, 0x7f, 0x40, 0x00} // 31 1
,{0x42, 0x61, 0x51, 0x49, 0x46} // 32 2
,{0x21, 0x41, 0x45, 0x4b, 0x31} // 33 3
,{0x18, 0x14, 0x12, 0x7f, 0x10} // 34 4
,{0x27, 0x45, 0x45, 0x45, 0x39} // 35 5
,{0x3c, 0x4a, 0x49, 0x49, 0x30} // 36 6
,{0x01, 0x71, 0x09, 0x05, 0x03} // 37 7
,{0x36, 0x49, 0x49, 0x49, 0x36} // 38 8
,{0x06, 0x49, 0x49, 0x29, 0x1e} // 39 9
,{0x00, 0x36, 0x36, 0x00, 0x00} // 3a :
,{0x00, 0x56, 0x36, 0x00, 0x00} // 3b ;
,{0x08, 0x14, 0x22, 0x41, 0x00} // 3c <
,{0x14, 0x14, 0x14, 0x14, 0x14} // 3d =
,{0x00, 0x41, 0x22, 0x14, 0x08} // 3e >
,{0x02, 0x01, 0x51, 0x09, 0x06} // 3f ?
,{0x32, 0x49, 0x79, 0x41, 0x3e} // 40 @
,{0x7e, 0x11, 0x11, 0x11, 0x7e} // 41 A
,{0x7f, 0x49, 0x49, 0x49, 0x36} // 42 B
,{0x3e, 0x41, 0x41, 0x41, 0x22} // 43 C
,{0x7f, 0x41, 0x41, 0x22, 0x1c} // 44 D
,{0x7f, 0x49, 0x49, 0x49, 0x41} // 45 E
,{0x7f, 0x09, 0x09, 0x09, 0x01} // 46 F
,{0x3e, 0x41, 0x49, 0x49, 0x7a} // 47 G
,{0x7f, 0x08, 0x08, 0x08, 0x7f} // 48 H
,{0x00, 0x41, 0x7f, 0x41, 0x00} // 49 I
,{0x20, 0x40, 0x41, 0x3f, 0x01} // 4a J
,{0x7f, 0x08, 0x14, 0x22, 0x41} // 4b K
,{0x7f, 0x40, 0x40, 0x40, 0x40} // 4c L
,{0x7f, 0x02, 0x0c, 0x02, 0x7f} // 4d M
,{0x7f, 0x04, 0x08, 0x10, 0x7f} // 4e N
,{0x3e, 0x41, 0x41, 0x41, 0x3e} // 4f O
,{0x7f, 0x09, 0x09, 0x09, 0x06} // 50 P
,{0x3e, 0x41, 0x51, 0x21, 0x5e} // 51 Q
,{0x7f, 0x09, 0x19, 0x29, 0x46} // 52 R
,{0x46, 0x49, 0x49, 0x49, 0x31} // 53 S
,{0x01, 0x01, 0x7f, 0x01, 0x01} // 54 T
,{0x3f, 0x40, 0x40, 0x40, 0x3f} // 55 U
,{0x1f, 0x20, 0x40, 0x20, 0x1f} // 56 V
,{0x3f, 0x40, 0x38, 0x40, 0x3f} // 57 W
,{0x63, 0x14, 0x08, 0x14, 0x63} // 58 X
,{0x07, 0x08, 0x70, 0x08, 0x07} // 59 Y
,{0x61, 0x51, 0x49, 0x45, 0x43} // 5a Z
,{0x00, 0x7f, 0x41, 0x41, 0x00} // 5b [
,{0x02, 0x04, 0x08, 0x10, 0x20} // 5c ¥
,{0x00, 0x41, 0x41, 0x7f, 0x00} // 5d ]
,{0x04, 0x02, 0x01, 0x02, 0x04} // 5e ^
,{0x40, 0x40, 0x40, 0x40, 0x40} // 5f _
,{0x00, 0x01, 0x02, 0x04, 0x00} // 60 `
,{0x20, 0x54, 0x54, 0x54, 0x78} // 61 a
,{0x7f, 0x48, 0x44, 0x44, 0x38} // 62 b
,{0x38, 0x44, 0x44, 0x44, 0x20} // 63 c
,{0x38, 0x44, 0x44, 0x48, 0x7f} // 64 d
,{0x38, 0x54, 0x54, 0x54, 0x18} // 65 e
,{0x08, 0x7e, 0x09, 0x01, 0x02} // 66 f
,{0x0c, 0x52, 0x52, 0x52, 0x3e} // 67 g
,{0x7f, 0x08, 0x04, 0x04, 0x78} // 68 h
,{0x00, 0x44, 0x7d, 0x40, 0x00} // 69 i
,{0x20, 0x40, 0x44, 0x3d, 0x00} // 6a j
,{0x7f, 0x10, 0x28, 0x44, 0x00} // 6b k
,{0x00, 0x41, 0x7f, 0x40, 0x00} // 6c l
,{0x7c, 0x04, 0x18, 0x04, 0x78} // 6d m
,{0x7c, 0x08, 0x04, 0x04, 0x78} // 6e n
,{0x38, 0x44, 0x44, 0x44, 0x38} // 6f o
,{0x7c, 0x14, 0x14, 0x14, 0x08} // 70 p
,{0x08, 0x14, 0x14, 0x18, 0x7c} // 71 q
,{0x7c, 0x08, 0x04, 0x04, 0x08} // 72 r
,{0x48, 0x54, 0x54, 0x54, 0x20} // 73 s
,{0x04, 0x3f, 0x44, 0x40, 0x20} // 74 t
,{0x3c, 0x40, 0x40, 0x20, 0x7c} // 75 u
,{0x1c, 0x20, 0x40, 0x20, 0x1c} // 76 v
,{0x3c, 0x40, 0x30, 0x40, 0x3c} // 77 w
,{0x44, 0x28, 0x10, 0x28, 0x44} // 78 x
,{0x0c, 0x50, 0x50, 0x50, 0x3c} // 79 y
,{0x44, 0x64, 0x54, 0x4c, 0x44} // 7a z
,{0x00, 0x08, 0x36, 0x41, 0x00} // 7b {
,{0x00, 0x00, 0x7f, 0x00, 0x00} // 7c |
,{0x00, 0x41, 0x36, 0x08, 0x00} // 7d }
,{0x10, 0x08, 0x08, 0x10, 0x08} // 7e ←
,{0x78, 0x46, 0x41, 0x46, 0x78} // 7f →
};

#define PIN_SCE 5 //  XCS
#define PIN_SDIN 4 // SDA
#define PIN_RESET 6 // XRES
#define PIN_SCLK 3 // SCLK
#define Rssiin A6 // вход RSSI
#define Bolche A3
#define Regim A2
#define Menche A0
#define Vvod A1


#define LCD_C LOW // Command
#define LCD_D HIGH // Data
unsigned char lcd_x = 0, lcd_y = 0;
byte column=0; // cтолбец
byte line=0; // строка
byte contrast=10;


unsigned int n=0;// определяет не пора ли менять шаг изменения частоты
byte data0=0; 
byte data1=0;
byte data2=0;
byte data3=0;
unsigned int Freguency=0;
unsigned int Delitel;
byte DelitelH ;
byte DelitelL ;
byte var =0; // режим, 0- прием, 1- спектр, 2- скан
unsigned int sval=0;//  накопительный замер рсси 
unsigned int RSSI = 0;// максимум АРУ
unsigned int RSSImin = 0;
unsigned int spec =0; // что будет отображаться в спектре
unsigned int MAXi = 0;// i при макс АРУ

byte RSSI_por;
byte RSSI_dev;
byte can;



void setup()  
{ 
 Wire.begin(); //включить i2c
 
  pinMode(PIN_SCE, OUTPUT);
  pinMode(PIN_RESET, OUTPUT);
  pinMode(PIN_SDIN, OUTPUT);
  pinMode(PIN_SCLK, OUTPUT);
  digitalWrite(PIN_RESET, LOW);
  digitalWrite(PIN_SCE, HIGH);
  digitalWrite(PIN_SCLK, LOW);
  digitalWrite(PIN_SDIN, LOW);

  pinMode(Bolche, INPUT);
  digitalWrite(Bolche, HIGH);
  pinMode(Menche, INPUT);
  digitalWrite(Menche, HIGH);
  pinMode(Vvod, INPUT);
  digitalWrite(Vvod, HIGH);
  pinMode(Regim, INPUT);
  digitalWrite(Regim, HIGH);
  
 DelitelL= EEPROM.read(0);
 DelitelH= EEPROM.read(1);
 
 RSSI_por=EEPROM.read(2);
 RSSI_dev=EEPROM.read(3);
 can= EEPROM.read(4);

 Freguency= (DelitelH *32 + DelitelL/8) -479;
 if (Freguency>1350 || Freguency<840) Freguency=1160;
 
  prog_freg();
  
  LcdInitialise();
  LcdClear();
  //LcdWrite(LCD_C, 0xA7); // Inverted display
  LcdWrite(LCD_C, 0xA6); // Normal display
  lcd_contrast(contrast);
  
  for ( byte i = 0; i < 8; i++){
  lcd_set_pos_pix(6*i, i);
  LcdString("SerPanRC");
  delay (200);}
  delay (500);
  LcdClear();
  
 }
 
  
 void loop()
 {  
  lcd_set_pos_pix(66, 0);
   if (var==0)  LcdString("RCV");
   if (var==1)  LcdString("SPC");
   if (var==2)  LcdString("SCN");
   if (var==3)  LcdString("CLB");
   if (var==4)  LcdString("CNL");
   
   while (digitalRead(Regim)==LOW)
     {
       var=var+1;
      if (var>4) var=0 ;
      lcd_set_pos_pix(66, 0);
      if (var==0)  LcdString("RCV");
      if (var==1)  LcdString("SPC");
      if (var==2) LcdString("SCN");
      if (var==3)  LcdString("CLB");
      if (var==4)  LcdString("CNL");
      delay (800);
     };

 
    
    switch (var) {
    case 0:
    sval=0; 
    for ( byte i = 0; i < 10; i++){
      sval = sval + (1023-analogRead(Rssiin));
      delay(2);}
  
  if (Freguency <840) Freguency=1350;
  if (Freguency >1350) Freguency=840;  
  if (digitalRead(Bolche)==LOW or digitalRead(Menche)==LOW)
     { n=n+1;
  
  if (digitalRead(Bolche)==LOW and n<15) Freguency=Freguency+1;
  if (digitalRead(Bolche)==LOW and n>=15) Freguency=Freguency+10;
     
  if (digitalRead(Menche)==LOW and n<15 )  Freguency=Freguency-1;
  if (digitalRead(Menche)==LOW and n>=15 )  Freguency=Freguency-10;
  prog_freg();
} 
  
  else { n=0;}
  
  lcd_set_pos_pix(0, 0);
  LcdString("FREG: ");
  LcdString_f(Freguency);
  LcdString(" ");
  lcd_set_pos_pix(0, 1);
  LcdString("RSSI:       ");
  lcd_set_pos_pix(35, 1);
  
  if (sval>(RSSI_por*39)){ 
  LcdString_f(((sval-(RSSI_por*39))/4));
  
  byte L=5*(sval-(RSSI_por*39))/(2*RSSI_dev);
   if (L>95) L=95;
   for (byte x = 0; x < L; x ++) { 
        lcd_set_pos_pix(x , 4);
        LcdWrite(LCD_D, 0xff);}
   for (byte x = L; x < 96; x ++) { 
        lcd_set_pos_pix(x , 4);
        LcdWrite(LCD_D, 0x00);}
   
    }
   else {LcdString("   0");
   for (byte x = 0; x < 96; x ++) { 
        lcd_set_pos_pix(x , 4);
        LcdWrite(LCD_D, 0x00);}};
   
 
  
  if (digitalRead(Vvod)==LOW)  
   {EEPROM.write(0, DelitelL);
    EEPROM.write(1, DelitelH);
    delay(3000);};
  
  
  delay(200);
      break;
      
      
    case 1:
    for ( byte i = 0; i < 96; i++){
      Freguency = 870+5*i;
      prog_freg();
      
      lcd_set_pos_pix(0, 0);
      LcdString("FREG: ");
      LcdString_f(Freguency);
      LcdString(" ");
      if (digitalRead(Bolche)==LOW) delay (500);
      sval=0;
      for ( byte u = 0; u < 10; u++){
      sval = sval + (1023-analogRead(Rssiin));
      delay (2);};
     
      if (sval>(RSSI_por*39)) spec = 4+7*(sval-(RSSI_por*39))/(5*RSSI_dev);
      else spec = 4;
       
       column=i;
       Lcd_drawColumn(1,spec);
       column=i+1;
       Lcd_drawColumn(1, 0);
     
       if (digitalRead(Regim)==LOW ){ 
    var=0;
    DelitelL= EEPROM.read(0);
    DelitelH= EEPROM.read(1);
    Freguency= (DelitelH *32 + DelitelL/8) -479;
    prog_freg();
 
     for ( byte m = 0; m < 96; m++)
    {
      column=m;
      Lcd_drawColumn(1, 0);};
       goto prer ;  };};  
  
      prer:
      break;
      
      
      case 2:
      sval=0;
      RSSI=0; 
      for ( unsigned int i = 0; i < 459; i++){
      if (i == 24) i = 90;
      Freguency = 890+i;
      prog_freg();
      
  
  lcd_set_pos_pix(0, 0);
  LcdString("FREG: ");
  LcdString_f(Freguency);
  LcdString(" ");
  
  lcd_set_pos_pix(0, 1);
  delay (20) ;
  LcdString("RSSI:       ");
  sval =(1023-analogRead(Rssiin));
  lcd_set_pos_pix(35, 1);
  LcdString_f(sval);
  
  if (sval > RSSI )
           { RSSI=sval;
             MAXi=i ; };
             
 }
   Freguency = 890+MAXi;
   prog_freg();
   var=0;
   break;
  
      
        case 3:
     RSSI=0;
     RSSImin=10230; 
      for ( unsigned int i = 0; i < 509; i++){
      Freguency = 840+i;
      prog_freg();
      
  
  lcd_set_pos_pix(0, 0);
  LcdString("FREG: ");
  LcdString_f(Freguency);
  LcdString(" ");
  
  lcd_set_pos_pix(0, 1);
  LcdString("RSSI:       ");
  sval=0;
  for ( byte u = 0; u < 10; u++){
      sval = sval + (1023-analogRead(Rssiin));
      delay (2) ;};
  lcd_set_pos_pix(35, 1);
  LcdString("    ");
  lcd_set_pos_pix(35, 1);
  LcdString_f(sval);
  
  if (sval > RSSI )RSSI=sval;
  if (sval < RSSImin ) RSSImin=sval; 
             
 }
   RSSI_por=RSSImin/40; // масштабируем до байта 
   RSSI_dev= (RSSI-RSSImin)/40;
   EEPROM.write(2, RSSI_por);
   EEPROM.write(3, RSSI_dev);
   
   lcd_set_pos_pix(0, 3);
   LcdString("POR :     ");
   lcd_set_pos_pix(35, 3);
   LcdString_f(RSSI_por);
  
   lcd_set_pos_pix(0, 4);
   LcdString("DEV :       ");
   lcd_set_pos_pix(35, 4);
   LcdString_f(RSSI_dev);
   delay (2000) ;
   
  
 DelitelL= EEPROM.read(0);
 DelitelH= EEPROM.read(1);
 Freguency= (DelitelH *32 + DelitelL/8) -479;
 if (Freguency>1350 || Freguency<840) Freguency=1160;
 
  prog_freg();
  var=0;
 
      
   break;
   
    case 4:
    sval=0; 
    for ( byte i = 0; i < 10; i++){
      sval = sval + (1023-analogRead(Rssiin));
      delay(2);}
  
  if (digitalRead(Bolche)==LOW ) can=can+1;
  if (can==16) can=0; 
  if (digitalRead(Menche)==LOW  ) can=can-1;
  if (can>16) can=15;
  Freguency=10*FREGLOW[can];
  prog_freg();
  
  lcd_set_pos_pix(0, 0);
  LcdString("FREG: ");
  LcdString_f(Freguency);
  LcdString(" ");
  lcd_set_pos_pix(0, 1);
  LcdString("RSSI:       ");
  lcd_set_pos_pix(35, 1);
  
  if (sval>(RSSI_por*39)){ 
  LcdString_f(((sval-(RSSI_por*39))/4));
  
  byte L=5*(sval-(RSSI_por*39))/(2*RSSI_dev);
   if (L>95) L=95;
   for (byte x = 0; x < L; x ++) { 
        lcd_set_pos_pix(x , 4);
        LcdWrite(LCD_D, 0xff);}
   for (byte x = L; x < 96; x ++) { 
        lcd_set_pos_pix(x , 4);
        LcdWrite(LCD_D, 0x00);}
   
    }
   else {LcdString("   0");
   for (byte x = 0; x < 96; x ++) { 
        lcd_set_pos_pix(x , 4);
        LcdWrite(LCD_D, 0x00);}};
   
 
  
  if (digitalRead(Vvod)==LOW)  
   {EEPROM.write(4, can);
    delay(3000);};
    
     if (digitalRead(Regim)==LOW ){ 
    var=0;
    DelitelL= EEPROM.read(0);
    DelitelH= EEPROM.read(1);
    Freguency= (DelitelH *32 + DelitelL/8) -479;
    prog_freg();};
  
  
  delay(200);
      break;
  }
 }


 void prog_freg (void) {
  
  Delitel=Freguency*8+3836; //считаем делитель
  DelitelH=Delitel>>8;
  DelitelL=Delitel&0XFF;

  delay(100);
  Wire.beginTransmission(0x61);   // стучимся к синтезатору и передаем байты параметров
  Wire.write(DelitelH);
  Wire.write(DelitelL);
  Wire.write(0xCE);
  Wire.write(0x00);
  Wire.endTransmission();
 }
 



void LcdCharacter(char character){
  LcdWrite(LCD_D, 0x00);
  for (int index = 0; index < 5; index++)
  {LcdWrite(LCD_D, ASCII[character - 0x20][index]);
  }}
  
void LcdClear(void){
for (int index = 0; index < 864 ; index++)
LcdWrite(LCD_D, 0x00);
}

void lcd_set_pos(unsigned char c, unsigned char r){
  c = c*6;
  r = r*1;
  lcd_set_pos_pix(c,r);
}

void lcd_set_pos_pix(unsigned char c, unsigned char r){
  lcd_x = c;
  lcd_y = r;
  LcdWrite(LCD_C,0xB0 | (r & 0x0F));
  LcdWrite(LCD_C,0x10 | ((c >> 4) & 0x07));
  LcdWrite(LCD_C,0x00 | (c & 0x0F));
}

void lcd_crlf(void){
  lcd_x = 0;
  lcd_y = lcd_y+1;
  if(lcd_y>=8) lcd_y = 0;
  lcd_set_pos_pix(lcd_x,lcd_y);}
  
  void lcd_contrast(byte contrast)
{
    contrast = contrast & 0x1F;
    LcdWrite(LCD_C,0x80 + contrast);
  }
    
void Lcd_drawColumn(unsigned char sline, unsigned char value){

    unsigned char lines=9-sline;
    if (value > lines*8) value = lines*8;
    unsigned char mark = (lines*8 - 1 - value)/8;
    for (unsigned char line = 0; line < mark; line++) { 
        lcd_set_pos_pix(column, sline + line);
        LcdWrite(LCD_D, 0x00);}
        
    unsigned char b = 0xff;
    for (unsigned char i = 0; i < lines*8 - mark*8 - value; i++) {
        b <<= 1;
    }
    lcd_set_pos_pix(column, sline + mark);
    LcdWrite(LCD_D, b);
    for (unsigned char line = mark + 1; line < lines; line++) {
        lcd_set_pos_pix(column, sline + line);
        LcdWrite(LCD_D, 0xff);
    } 
  }

void LcdInitialise(void){
digitalWrite(PIN_RESET, HIGH);
LcdWrite(LCD_C, 0xE2);
LcdWrite(LCD_C, 0x3D);
LcdWrite(LCD_C, 0x01);
LcdWrite(LCD_C, 0xA4); 
LcdWrite(LCD_C, 0x2F); 
LcdWrite(LCD_C, 0xC0); 
LcdWrite(LCD_C, 0xC0); 
LcdWrite(LCD_C, 0xAF); 
}

void LcdString(char *characters){
while (*characters){
LcdCharacter(*characters++);
}
}

void LcdString_f(unsigned int func){
byte k = 0;
if (func>9999) func=9999;
unsigned int n=10000;
for ( byte i = 0; i < 4; i++){
 n=n/10; 
 byte tetra= func/n;
 if (tetra>0)  k = 1;
 byte bukva=tetra+0x30;
 if (k>0|| i==3) LcdCharacter(bukva);
 else LcdCharacter(0x20);
 func=func-tetra*n;}
}

void LcdWrite(byte dc, byte data){
 if (dc==1) PORTD |= 0b00010000;
 else PORTD &= ~0b00010000;
 PORTD &= ~0b00100000;
 PORTD |= 0b00001000;
 PORTD &= ~0b00001000;
   for (char i=0; i<8; i++) {
     if(data &(0b10000000>>i)) PORTD |= 0b00010000;
     else PORTD &= ~0b00010000;
  PORTD |= 0b00001000;
  PORTD &= ~0b00001000;}
  PORTD |= 0b00100000;      
}
