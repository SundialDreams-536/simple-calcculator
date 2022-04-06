#include<stdio.h>
int main()
{	
	char str[]="2+2*3+2/2-1";
	int a=str[0]-'0';
	int b=str[2]-'0';
	int c=str[4]-'0';
	int d=str[6]-'0';
	int e=str[8]-'0';
	int f=str[10]-'0';
	int s;
	s=a+b*c+d/e-f;
	printf("%d\n",s);
	return 0;
}