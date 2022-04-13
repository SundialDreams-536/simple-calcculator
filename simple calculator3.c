/*#include<stdio.h>
int main()
{	
	char str[]="2+2*3+2/2-1";
	int a=str[0]-'0';
	int b=str[2]-'0';
	int c=str[4]-'0';
	int d=str[6]-'0';
	int e=str[8]-'0';        （修改前的代码，简单但是麻烦）
	int f=str[10]-'0';
	int s;
	s=a+b*c+d/e-f;
	printf("%d\n",s);
	return 0;
}*/

//修改后的代码：
#include<stdio.h>
#include<string.h>
int main()
{
	char strExp[]="2+2*3+2/2-1";
	char strTmp[1000]="3";//strlen(strExp)，临时存放数组
	int strTmpIndex=-1;
	int i;
	int res;
	for(i=0;i<strlen(strExp);i++)
	{
		if(strExp[i]=='*')    //先执行‘*’与‘/’
		{
			int leftOperand=strTmp[strTmpIndex]-'0';  //左操作数从临时数组中取  
			int rightOperand=strExp[i+1]-'0'; //右操作数从原数组中取
			strTmp[strTmpIndex]=leftOperand*rightOperand+'0';   
			i++;
		}
		
		else if(strExp[i]=='/')
		{
			int leftOperand=strTmp[strTmpIndex]-'0';
			int rightOperand=strExp[i+1]-'0';
			strTmp[strTmpIndex]=leftOperand/rightOperand+'0';
			i++;
		}
		else strTmp[++strTmpIndex]=strExp[i];
	}

	//printf("%s\n",strTmp); 查看临时数组
	res=strTmp[0]-'0';
	for(i=1;i<strlen(strTmp);i++)
	{
		if(strTmp[i]=='+') res+=strTmp[++i]-'0';
		else if(strTmp[i]=='-') res-=strTmp[++i]-'0';
	}
	printf("%d\n",res);
	return 0;
}













