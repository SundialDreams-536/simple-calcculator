#include<stdio.h>
#include<string.h>
int main()
{
	char str[]="2*2/4*1/1*2*3/2";
	int a=str[0]-'0';
	int i;
	for(i=1;i<strlen(str);i++)
	{
		if(str[i]=='*')
		{
			int b=str[i+1]-'0';
			a=a*b;
			i++;
		}
		else if(str[i]=='/')
		{
			int b=str[i+1]-'0';
			a=a/b;
			i++;
		}
	}
	printf("%d\n",a);
	return 0;
}