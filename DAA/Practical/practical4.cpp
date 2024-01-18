#include <stdio.h>
#include <conio.h>
int main()
{
	int arr[]={17,32,77,12,45,15,45,79,65,9},key,i,flag=0;
	  printf("Rajani Lamichhane, Roll no:25796\n");
	printf("ENTER A NUMBER: ");
	scanf("%d",&key);
	printf("The numbers existed in array are:\n");
	for (i=0;i<10;i++)
	{
		printf("%d,",arr[i]);
	}
	for(i=0;i<10;i++)
	{
		if(key==arr[i])
			flag=1;
	}
	if(flag==1)
		printf("\nTHE NUMBER %d EXISTS IN THE ARRAY",key);
	else
printf("\nTHE NUMBER %d DOES NOT EXIST IN THE ARRAY",key);
	getch();
}
