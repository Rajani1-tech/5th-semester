//Lab 6: Write a C program to that tests random numbers for frequency using Kolmogorov S test
#include<conio.h>
#include<stdio.h>
#define N 5
#define Dalpha 0.665
int main()
{
	float R[N] = {0.05,0.14,0.44,0.81,0.93};
	float X[N],Y[N],Z[N];
	float D1,D2,D;
	int i;
	for(i=1;i<=N;i++)
	{
		X[i-1] = (double)i/N;		
	}
	for(i=1;i<=N;i++)
	{
		Y[i-1] = (double)i/N-R[i-1];		
	}
	for(i=1;i<=N;i++)
	{
		Z[i-1] = R[i-1]-(double)(i-1)/N;		
	}
	D1 = Y[0];
	for(i=1;i<N;i++)
	{
		if(D1<Y[i])
		D1 = Y[i];
	}
	D2 = Z[0];
    for(i=1;i<N;i++)
	{
		if(D1<Z[i])
		D1 = Z[i];
	}
	D = (D1>D2)?D1:D2;
	printf("D =  %0.2f",D);
	if(D<Dalpha)
	printf("Random numbers are uniformally distributed\n");
	else
	printf("Random numbers are not uniformally distributed\n");
printf("\nRajani Lamichhane, Rollno:25796");
}
