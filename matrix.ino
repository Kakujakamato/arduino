#define ROW_1 9 //pin4
#define ROW_2 12 //pin7
#define ROW_3 7 //pin2
#define ROW_4 13 //pin8
#define ROW_5 A2 //pin13
#define ROW_6 6 //pin1
#define ROW_7 3 //pin11
#define ROW_8 A0 //pin16

#define COL_1 5 //pin9
#define COL_2 4 //pin10
#define COL_3 A3//pin14
#define COL_4 8//pin3
#define COL_5 A1//pin15
#define COL_6 10//pin5
#define COL_7 11//pin6
#define COL_8 2//pin12
      
const byte rows[] = {
    ROW_1,ROW_2,ROW_3,ROW_4,ROW_5,ROW_6,ROW_7,ROW_8
};
const byte col[] = {
  COL_1,COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8
};

byte ALL[] = {B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111};
byte EX[] = {B00000000,B00010000,B00010000,B00010000,B00010000,B00000000,B00010000,B00000000};
byte A[] = {B00000000,B00111100,B01100110,B01100110,B01111110,B01100110,B01100110,B01100110};
byte B[] = {B01111000,B01001000,B01001000,B01110000,B01001000,B01000100,B01000100,B01111100};
byte C[] = {B00000000,B00011110,B00100000,B01000000,B01000000,B01000000,B00100000,B00011110};
byte D[] = {B00000000,B00111000,B00100100,B00100010,B00100010,B00100100,B00111000,B00000000};
byte E[] = {B11111111,B11000011,B11011111,B11000111,B11011111,B11011111,B11000011,B11111111};
byte F[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00100000,B00000000};
byte G[] = {B00000000,B00111110,B00100000,B00100000,B00101110,B00100010,B00111110,B00000000};
byte H[] = {B00000000,B00100100,B00100100,B00111100,B00100100,B00100100,B00100100,B00000000};
byte I[] = {B00000000,B00111000,B00010000,B00010000,B00010000,B00010000,B00111000,B00000000};
byte J[] = {B00000000,B00011100,B00001000,B00001000,B00001000,B00101000,B00111000,B00000000};
byte K[] = {B00000000,B00100100,B00101000,B00110000,B00101000,B00100100,B00100100,B00000000};
byte L[] = {B11111111,B11011111,B11011111,B11011111,B11011111,B11011111,B11000011,B11111111};
byte M[] = {B00000000,B00000000,B01000100,B10101010,B10010010,B10000010,B10000010,B00000000};
byte N[] = {B00000000,B00100010,B00110010,B00101010,B00100110,B00100010,B00000000,B00000000};
byte O[] = {B11111111,B11000011,B10111101,B10111101,B10111101,B10111101,B11000011,B11111111};
byte P[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100000,B00100000,B00000000};
byte Q[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000110,B00111110,B00000001};
byte R[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100100,B00100100,B00000000};
byte S[] = {B00000000,B00111100,B00100000,B00111100,B00000100,B00000100,B00111100,B00000000};
byte T[] = {B00000000,B01111100,B00010000,B00010000,B00010000,B00010000,B00010000,B00000000};
byte U[] = {B11111111,B10111101,B10111101,B10111101,B10111101,B11011011,B11100111,B11111111};
byte V[] = {B11011101,B11011101,B11011101,B11011101,B11101011,B11101011,B11110111,B11111111};
byte W[] = {B00000000,B10000010,B10010010,B01010100,B01010100,B00101000,B00000000,B00000000};
byte X[] = {B00000000,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B00000000};
byte Y[] = {B11111111,B10111011,B11010111,B11101111,B11101111,B11101111,B11101111,B11111111};
byte Z[] = {B00000000,B00111100,B00000100,B00001000,B00010000,B00100000,B00111100,B00000000};
byte Heart[] = {B11111111,B10011001,B00000000,B00000000,B10000001,B11000011,B11100111,B11111111};
float timeCount = 0;
void setup() 
{
    Serial.begin(9600);
    for (byte i = 2; i <= 13; i++)
        pinMode(i, OUTPUT);
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
}

void loop() {
  // This could be rewritten to not use a delay, which would make it appear brighter
delay(5);
timeCount += 1;

if(timeCount <  20) 
{
drawScreen(L);
} 
else if (timeCount <  40) 
{
drawScreen(O);
} 
else if (timeCount <  60) 
{
drawScreen(V);
} 
else if (timeCount <  80) 
{
drawScreen(E);
} 
else if (timeCount <  100) 
{
drawScreen(Y);
} 
else if (timeCount <  120) 
{
drawScreen(O);
} 
else if (timeCount <  140) {
  drawScreen(U);
} 
else if (timeCount <  160) 
{
drawScreen(Heart);
} 
else if (timeCount <  180) 
{
drawScreen(ALL);
} 
else {
// back to the start
timeCount = 0;
}
}
 void  drawScreen(byte buffer2[])
 { 
   // Turn on each row in series
    for (byte i = 0; i < 8; i++)       
     {
        digitalWrite(rows[i], HIGH);    
        for (byte a = 0; a < 8; a++)   
        {
          // if You set (~buffer2[i] >> a) 
          digitalWrite(col[a], (buffer2[i] >> a) & 0x01);        
          delayMicroseconds(500);
          //delay(10);
          //delay(100);
          
          digitalWrite(col[a], 1);     
        }
        digitalWrite(rows[i], LOW); 
    }
}
// 
  /* this is siplest resemplation how for loop is working with each row.
    digitalWrite(COL_1, (~b >> 0) & 0x01); // Get the 1st bit: 10000000
    digitalWrite(COL_2, (~b >> 1) & 0x01); // Get the 2nd bit: 01000000
    digitalWrite(COL_3, (~b >> 2) & 0x01); // Get the 3rd bit: 00100000
    digitalWrite(COL_4, (~b >> 3) & 0x01); // Get the 4th bit: 00010000
    digitalWrite(COL_5, (~b >> 4) & 0x01); // Get the 5th bit: 00001000
    digitalWrite(COL_6, (~b >> 5) & 0x01); // Get the 6th bit: 00000100
    digitalWrite(COL_7, (~b >> 6) & 0x01); // Get the 7th bit: 00000010
    digitalWrite(COL_8, (~b >> 7) & 0x01); // Get the 8th bit: 00000001
}*/
#define ROW_1 9
//#define ROW_2 12
//#define ROW_3 7
//#define ROW_4 13
//#define ROW_5 A2
//#define ROW_6 6
//#define ROW_7 3
//#define ROW_8 A0
////Columns
//#define COL_1 5
//#define COL_2 4
//#define COL_3 A3
//#define COL_4 8
//#define COL_5 A1
//#define COL_6 10
//#define COL_7 11
//#define COL_8 2
//const byte rows[] = {
//    ROW_1,ROW_2,ROW_3,ROW_4,ROW_5,ROW_6,ROW_7,ROW_8
//};
//const byte cols[] = {
//  COL_1,COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8
//};
//void setup() 
//{
//    Serial.begin(9600);
//    for (byte i = 2; i <= 13; i++)
//        pinMode(i, OUTPUT);
//    pinMode(A0, OUTPUT);
//    pinMode(A1, OUTPUT);
//    pinMode(A2, OUTPUT);
//    pinMode(A3, OUTPUT);
//}
//void loop() {
//  for(int i=0;i<8;i++){
//  digitalWrite(rows[i], HIGH);
//  digitalWrite(cols[i], LOW);
//  delay(1000);}  
//}
