#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int width=20,length=20,gameover;
int x,y,fruitx,fruity,score,flag,life;
int tailX[100],tailY[100];
int CountTail=0;

void game();

void setup1()
 {
    gameover=0;
    x=width/2;
    y=length/2;
 } 

void setup2()
 {
   label1:
   fruitx=rand()%10;
   if(fruitx==0)
   goto label1;
   label2:
   fruity=rand()%10;
   if(fruity==0)
   goto label2;
   CountTail++;
 }

void newgame();

void life0()
 {
   game();
   life=0;
 }

void life1()
 {

	life=3;
	if("gameover>=1")
	{
		life--;
			printf("\n\t\t\t\t\tYOU HAVE ONLY 2 LIFE IN THIS GAME\n");
		system("pause");
        game();
   }
}

void life2()
{
	life=2;
	printf("\n\t\t\t\t\tYOU HAVE ONLY 1 LIFE IN THIS GAME\n");
    if("gameover>=1")
	{
		life--;
		system("pause");
	    game();	
   }
}

void life3()
{
  life=1;
  printf("\n\t\t\t\t\tYOU HAVE NO LIFE IN THIS GAME\n");
  if("gameover>=1")
	{
		life--;
		system("pause");
	   game();	
   }
}
  

void draw()
{
  int i,j,k;
  system("cls");
  for(i=0;i<width;i++)
    {
      for(j=0;j<width;j++)
      {
        if(i==0||i==length-1||j==0||j==width-1)
         {
            printf("*");
         }
        else
         {
           if(i==x&&j==y)
            printf("*");
           else if(i==fruitx&&j==fruity)
            printf("\af\a");
           else
           {
           	int ch=0;
		   for(k=0;k<CountTail;k++)
		   {
		   	if(i==tailX[k]&&j==tailY[k])
		   	{
		   		printf("*");
		   		ch=1;
			   }
		   }
		   if(ch==0)
		   {
            printf(" ");
           }
		   }
		 }
      }
     printf("\n");
    }
 if(x==fruitx&&y==fruity)
  {
    setup2();
    score++;
  }
}


void input()
{
 if(kbhit())
  {
    switch(getch())
     {
       case'a':
         flag=1;
         break;
       case's':
         flag=2;
         break;
       case'w':
         flag=3;
         break;
       case'z':
         flag=4;
         break;
       case'e':
         flag=5;
         break;
       case'd':
         flag=6;
         break;	
       default:
         printf("\nFINAL SCORE=%d",score);
         gameover=1;
         break;
     }
  }
}


void MakeLogic()
{
	int i;
	int prevX=tailX[0];
	int prevY=tailY[0];
	int prev2X,prev2Y;
	tailX[0]=x;
	tailY[0]=y;
	for(i=1;i<CountTail;i++)
	{
		prev2X=tailX[i];
		prev2Y=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
		
	}
  switch(flag)
    {
       case 1:
         y--;
         break; 
       case 2:
         y++;
         break;
       case 3:
         x--;
         break;
       case 4:
         x++;
         break;
       case 5:
         {
           system("pause");
           printf("\nLONG PRESS ANY KEY");
           break;
         }
       case 6:
         {
           system("cls");
           system("pause");
           printf("GAME OVER");
           break;
         }
       default:
         break;
    }
  if(x<0||x>width||y<0||y>length)
   {
     printf("SCORE=%d",score);
     gameover=1;               
   }
   if(x==tailX[i]&&y==tailY[i])
   {
   gameover=1;
   }
 }


int main()
{
    int m,n,z,x,y;
    life=3;
	printf("CLICK 1 TO START THE GAME\n ");
	scanf("%d",&z);
	if(z==1)
	{
	system("cls");
	printf("~Choose the level of the game :\n\t\t*Enter 1 to play easy level\n\t\t*Enter 2 to play medium level game\n\t\t*Enter 3 to play hard level game ");
	scanf("%d",&x);
	if(x==1)
	 {
	  printf("\t\t\t\t\t>>>>>RULES<<<<<");
	  printf("\n\n=>The snake starts at the centre of the board ,and can moves only north, south,east and west(ignore the version of game in which snake can moves in curves)\n\n=>You will be given 3 life (chance) \n\n=>There is always exactly one fruit(f) appear in the game at a time\n=>When the snake eats (run into) a fruit , it gets longer\n\n=>A snake dies either by running into the edge of the board , or by running into it's own tail\n\n=>The score is based on the number of fruit eaten by the snake.\n\n\t\t~USE 'w' TO MOVE SNAKE IN UPWARD DIRECTION.\n\n\t\t~USE 'z' TO MOVE THE SNAKE IN DOWNWARD DIRECTION.\n\n\t\t~USE 's' TO MOVE THE SNAKE IN YOUR RIGHT DIRECTION.\n\n\t\t~USE 'a' TO MOVE THE SNAKE IN YOUR LEFT DIRECTION\n\n\t\t\tALL THE BEST\n\n=>click 2 to start the game");
	  scanf("%d",&y);
      if(y==2)
	     {
	     life0();
         life1();
         life2();
         life3();
         life=3;
         
         }
       else
         {
    	   printf("\nCLOSING THE GAME");
	     }
     }
     else if(x==2)
     {
      printf("\t\t\t\t\t>>>>>RULES<<<<<");
	  printf("\n\n=>The snake starts at the centre of the board ,and can moves only north, south,east and west(ignore the version of game in which snake can moves in curves)\n\n=>You will be given 2 life (chance) \n\n=>There is always exactly one fruit(f) appear in the game at a time\n=>When the snake eats (run into) a fruit , it gets longer\n\n=>A snake dies either by running into the edge of the board , or by running into it's own tail\n\n=>The score is based on the number of fruit eaten by the snake.\n\n\t\t~USE 'w' TO MOVE SNAKE IN UPWARD DIRECTION.\n\n\t\t~USE 'z' TO MOVE THE SNAKE IN DOWNWARD DIRECTION.\n\n\t\t~USE 's' TO MOVE THE SNAKE IN YOUR RIGHT DIRECTION.\n\n\t\t~USE 'a' TO MOVE THE SNAKE IN YOUR LEFT DIRECTION\n\n\t\t\tALL THE BEST\n\n=>click 2 to start the game");
	  scanf("%d",&y);
      if(y==2)
	     {
		 life=2;
	     
         life2();
         life3();
         
         life=2;
         
         }
       else
         {
    	   printf("\nCLOSING THE GAME");
	     }	
	 }
	 else if(x==3)
	 {
	 	  printf("\t\t\t\t\t>>>>>RULES<<<<<");
	  printf("\n\n=>The snake starts at the centre of the board ,and can moves only north, south,east and west(ignore the version of game in which snake can moves in curves)\n\n=>You will be given 1 life (chance) \n\n=>There is always exactly one fruit(f) appear in the game at a time\n=>When the snake eats (run into) a fruit , it gets longer\n\n=>A snake dies either by running into the edge of the board , or by running into it's own tail\n\n=>The score is based on the number of fruit eaten by the snake.\n\n\t\t~USE 'w' TO MOVE SNAKE IN UPWARD DIRECTION.\n\n\t\t~USE 'z' TO MOVE THE SNAKE IN DOWNWARD DIRECTION.\n\n\t\t~USE 's' TO MOVE THE SNAKE IN YOUR RIGHT DIRECTION.\n\n\t\t~USE 'a' TO MOVE THE SNAKE IN YOUR LEFT DIRECTION\n\n\t\t\tALL THE BEST\n\n=>click 2 to start the game");
	  scanf("%d",&y);
      if(y==2)
	     {
		 life=1;
	     
         life3();
         
         
         life=1;
         
         }
       else
         {
    	   printf("\nCLOSING THE GAME");
	     }	
	 }
	 
}
newgame();

}   



void game()
{
  int n,m;

  setup1();
  setup2();
  while(!gameover)
   {
     draw();
      input();
     MakeLogic();
     printf("\nSCORE=%d\t\t\tLIFE=%d\n\n\nENTER e TO EXIT THE GAME\n\nLONG PRESS ANY PLAYING KEY TO CONTINUE",score,life);
   }
}


void newgame()
{
	int d,life;
	CountTail=0;
	system("cls");
	printf("\n\t\t\t!!!GAME OVER!!!\n\n\n\t\t\tENTER 1 TO START A NEW GAME\n");
	scanf("%d",&d);
	score=0;
		if(d==1)
	{
	system("cls");
	printf("~Choose the level of the game :\n\t\t*Enter 1 to play easy level\n\t\t*Enter 2 to play medium level game\n\t\t*Enter 3 to play hard level game ");
	scanf("%d",&x);
	if(x==1)
	 {
	  printf("\t\t\t\t\t>>>>>RULES<<<<<");
	  printf("\n\n=>The snake starts at the centre of the board ,and can moves only north, south,east and west(ignore the version of game in which snake can moves in curves)\n\n=>You will be given 3 life (chance) \n\n=>There is always exactly one fruit(f) appear in the game at a time\n=>When the snake eats (run into) a fruit , it gets longer\n\n=>A snake dies either by running into the edge of the board , or by running into it's own tail\n\n=>The score is based on the number of fruit eaten by the snake.\n\n\t\t~USE 'w' TO MOVE SNAKE IN UPWARD DIRECTION.\n\n\t\t~USE 'z' TO MOVE THE SNAKE IN DOWNWARD DIRECTION.\n\n\t\t~USE 's' TO MOVE THE SNAKE IN YOUR RIGHT DIRECTION.\n\n\t\t~USE 'a' TO MOVE THE SNAKE IN YOUR LEFT DIRECTION\n\n\t\t\tALL THE BEST\n\n=>click 2 to start the game");
	  scanf("%d",&y);
      if(y==2)
	     {
	     life0();
         life1();
         life2();
         life3();
         life=3;
         
         }
       else
         {
    	   printf("\nCLOSING THE GAME");
	     }
     }
     else if(x==2)
     {
      printf("\t\t\t\t\t>>>>>RULES<<<<<");
	  printf("\n\n=>The snake starts at the centre of the board ,and can moves only north, south,east and west(ignore the version of game in which snake can moves in curves)\n\n=>You will be given 2 life (chance) \n\n=>There is always exactly one fruit(f) appear in the game at a time\n=>When the snake eats (run into) a fruit , it gets longer\n\n=>A snake dies either by running into the edge of the board , or by running into it's own tail\n\n=>The score is based on the number of fruit eaten by the snake.\n\n\t\t~USE 'w' TO MOVE SNAKE IN UPWARD DIRECTION.\n\n\t\t~USE 'z' TO MOVE THE SNAKE IN DOWNWARD DIRECTION.\n\n\t\t~USE 's' TO MOVE THE SNAKE IN YOUR RIGHT DIRECTION.\n\n\t\t~USE 'a' TO MOVE THE SNAKE IN YOUR LEFT DIRECTION\n\n\t\t\tALL THE BEST\n\n=>click 2 to start the game");
	  scanf("%d",&y);
      if(y==2)
	     {
		 life=2;
	     
         life2();
         life3();
         
         life=2;
         
         }
       else
         {
    	   printf("\nCLOSING THE GAME");
	     }	
	 }
	 else if(x==3)
	 {
	 	  printf("\t\t\t\t\t>>>>>RULES<<<<<");
	      printf("\n\n=>The snake starts at the centre of the board ,and can moves only north, south,east and west(ignore the version of game in which snake can moves in curves)\n\n=>You will be given 1 life (chance) \n\n=>There is always exactly one fruit(f) appear in the game at a time\n=>When the snake eats (run into) a fruit , it gets longer\n\n=>A snake dies either by running into the edge of the board , or by running into it's own tail\n\n=>The score is based on the number of fruit eaten by the snake.\n\n\t\t~USE 'w' TO MOVE SNAKE IN UPWARD DIRECTION.\n\n\t\t~USE 'z' TO MOVE THE SNAKE IN DOWNWARD DIRECTION.\n\n\t\t~USE 's' TO MOVE THE SNAKE IN YOUR RIGHT DIRECTION.\n\n\t\t~USE 'a' TO MOVE THE SNAKE IN YOUR LEFT DIRECTION\n\n\t\t\tALL THE BEST\n\n=>click 2 to start the game");
	      scanf("%d",&y);
          if(y==2)
	     {
		 life=1;
	     
         life3();
         
         
         life=1;
         
         }
       else
         {
    	   printf("\nCLOSING THE GAME");
	     }	
	 }
	 
}
	
}

