//Lab 10:  Write a program to simulate the game called DiceToss
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int Arand()
{
	int r;
	r =  1+rand()%5;
	return r;
}
int Brand()
{
	int r;
	r =  1+rand()%5;
	return r;
}
int main()
{
	srand(time(0));
	int sa=0,sb,a,b,x,y;
	a = Arand();
	b = Arand();
	sa =  a+b;
	x =  Brand();
	y =  Brand();
	sb =  x+y;
	if(sa>sb)
	printf("A wins the game by %d points\n",sa);
	else
	printf("B wins the game by %d points\n",sb);
	printf("\nRajani Lamichhane, Rollno:25796");
	return 0;
}
