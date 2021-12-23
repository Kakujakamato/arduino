//#define ROW_1 9 //pin4 {9,12,7,13,A2,6,3,A0}
//#define ROW_2 12 //pin7
//#define ROW_3 7 //pin2
//#define ROW_4 13 //pin8
//#define ROW_5 A2 //pin13
//#define ROW_6 6 //pin1
//#define ROW_7 3 //pin11
//#define ROW_8 A0 //pin16
//
//#define COL_1 5 //pin9 {5,4,A3,8,A1,10,11,2}
//#define COL_2 4 //pin10
//#define COL_3 A3//pin14
//#define COL_4 8//pin3
//#define COL_5 A1//pin15
//#define COL_6 10//pin5
//#define COL_7 11//pin6
//#define COL_8 2//pin12
char Row[8]={9,12,7,13,A2,6,3,A0}; // Arduino gate numbers control rows of matrix
char Col[8]={5,4,A3,8,A1,10,11,2};   // Arduino gate numbers control cols of matrix 

int i=0; // row 
int j=0; // columne

int carry=0, eat=0, random_num1=0,random_num2=0;
int direct=0; 
int head_x=0,head_y=2;
int tail_x=0,tail_y=0;
void directions();
void game(char mat[8][8]);
void clear();

const int X_pin = A4; // analog pin connected to X output
const int Y_pin = A5; // analog pin connected to Y output



char start[8][8]=
{
  5,0,0,0,0,0,0,0,
  4,0,0,0,0,0,0,0,
  3,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  1,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
};

char over[8][8]=
{
  0,0,0,0,0,0,0,0,
  0,1,0,0,0,0,1,0,
  0,0,1,1,1,1,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,1,1,0,0,1,1,0,
  0,1,1,0,0,1,1,0,
  0,0,0,0,0,0,0,0,
};

void setup() {
  for(int i=0; i<8; i++)
   {
    pinMode(Row[i],OUTPUT);
    pinMode(Col[i],OUTPUT);
    digitalWrite(Row[i],LOW);
    digitalWrite(Col[i],HIGH);
   }
  Serial.begin(110000);

  
}

void loop()
{

  for(int i=0; i<13; i++)
    {
      Display(start);
    }

      directions();
     
      if(direct==2) 
    {
      Turn_down(start);
      if(eat==0)
      {
        tail(start);
      }
       else
       {
        random_food(start);
         eat--;
       }

    }

    else if(direct==1) 
    {
     Turn_up(start);
      if(eat==0)
      {
        tail(start);
      }
       else
       {
        random_food(start);
         eat--;
       }

    }

   else if(direct==4) 
 {
    Turn_left(start);
      if(eat==0)
      {
        tail(start);
      }
       else
       {
        random_food(start);
         eat--;
       }

 }

   else if(direct==3) 
 {
    Turn_right(start);
      if(eat==0)
      {
        tail(start);
      }
       else
       {
        random_food(start);
         eat--;
       }

 }
    
}

void Display(char mat[8][8])
{
  for(int i=0; i<8; i++)
  {
    digitalWrite(Col[i],LOW);
    for(int j=0; j<8; j++)
    {
      digitalWrite(Row[j],mat[j][i]);
       Serial.println(mat[j][i]);
    }
    delay(1);
    clear();
  }
}



void tail(char mat[8][8])
{
 
  if(mat[tail_y+1][tail_x]== (mat[tail_y][tail_x]-1)) // down
  {
    mat[tail_y][tail_x]=0;
    tail_y++;
    return;
  }
  
  else if (mat[tail_y-1][tail_x]==(mat[tail_y][tail_x]-1)) // up
  {
    mat[tail_y][tail_x]=0;
    tail_y--;
     return;
  }

    else if (mat[tail_y][tail_x-1]==(mat[tail_y][tail_x]-1)) // left
  {
    mat[tail_y][tail_x]=0;
    tail_x--;
     return;
  }
    else if (mat[tail_y][tail_x+1]==(mat[tail_y][tail_x]-1))  // right
  {
    mat[tail_y][tail_x]=0;
    tail_x++;
     return;
  }

   if(tail_y==7 && carry==1)  // wall down
  {
    mat[tail_y][tail_x]=0;
    tail_y=0;
    carry=0;
  }
    else if(tail_x==7 && carry==1) // wall right
  {
    mat[tail_y][tail_x]=0;
    tail_x=0;
    carry=0;
  }

  else if(tail_x==0 && carry==1)  //wall left
  {
    mat[tail_y][tail_x]=0;
    tail_x=7;
    carry=0;
  }
  
  else if(tail_y==0 && carry==1) // wall up
  {
    mat[tail_y][tail_x]=0;
    tail_y=7;
    carry=0;
  }

}


void Turn_down(char mat[8][8])
{
  if( mat[head_y+1][head_x]==1)
  eat++;
  
   else if( mat[head_y+1][head_x]>2)
   game(over);
  
  head_y++;
  
  if(head_y>7)
  {
      head_y=0;
      carry=1;
        if( mat[head_y][head_x]==1)
          eat++;
  }

  mat[head_y][head_x]=2;
  add_one(start);
}


void Turn_up(char mat[8][8])
{
    if( mat[head_y-1][head_x]==1)
        eat++; 

   else if( mat[head_y-1][head_x]>2)
   game(over);
  
  head_y--;
  
  if(head_y<0)
    {
       head_y=7;
       carry=1;
        if( mat[head_y][head_x]==1)
          eat++;
    }
    
  mat[head_y][head_x]=2;
  add_one(start);
}

void Turn_left(char mat[8][8])
{
    if( mat[head_y][head_x-1]==1)
        eat++;

    else if( mat[head_y][head_x-1]>2)
        game(over);
  
  head_x--;
  
  if(head_x<0)
    {
       head_x=7;
       carry=1;
        if( mat[head_y][head_x]==1)
          eat++;
    }

  mat[head_y][head_x]=2;
  add_one(start);
}

void Turn_right(char mat[8][8])
{
  if( mat[head_y][head_x+1]==1)
      eat++;

   else if( mat[head_y][head_x+1]>2)
   game(over);
  
  head_x++;
  
  if(head_x>7)
    {
       head_x=0;
       carry=1;
        if( mat[head_y][head_x]==1)
          eat++;
    }

  mat[head_y][head_x]=2;
  add_one(start);
}


void directions()
{
       if(analogRead(X_pin)>615 && direct!=2)
   {
     direct=1;
     return;
   }
 
    else if(analogRead(X_pin)<400 && direct!=1 )
    {
      direct=2;
      return;
    }
     else if(analogRead(Y_pin)<415 && direct!=4)
    {
      direct=3;
      return;
    }
     
   else if(analogRead(Y_pin)>630 && direct!=3)
    {
      direct=4;
      return;
    }
}




void random_food(char mat[8][8])
{
  while(1)
  {
    random_num1=random(0,7);
    random_num2=random(0,7);
     if(mat[random_num1][random_num2]!=2)
    {
       mat[random_num1][random_num2]=1;
       break;
    }
  }

   
}   

 void game(char mat[8][8])    // display game over :(

 {
    while(1) // display the matrix
    {
      Display(over);
    }
 }


 void add_one(char mat[8][8])  // increase by one every digit larger than one
 {
    for(int k=0; k<8; k++)
  {
       for(int s=0; s<8; s++)
     {
        int x=mat[s][k];
        if (x>1)
         mat[s][k]+=1;
     }
  }
 }


 
void clear()
{

  for(int i=0; i<8; i++)
   {
    digitalWrite(Row[i],LOW);
    digitalWrite(Col[i],HIGH);
   }
}
