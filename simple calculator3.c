/*#include<stdio.h>
int main()
{	
	char str[]="2+2*3+2/2-1";
	int a=str[0]-'0';
	int b=str[2]-'0';
	int c=str[4]-'0';
	int d=str[6]-'0';
	int e=str[8]-'0';        ���޸�ǰ�Ĵ��룬�򵥵����鷳��
	int f=str[10]-'0';
	int s;
	s=a+b*c+d/e-f;
	printf("%d\n",s);
	return 0;
}*/

//�޸ĺ�Ĵ��룺
#include<stdio.h>
#include<string.h>
int main()
{
	char strExp[]="2+2*3+2/2-1";
	char strTmp[1000]="3";//strlen(strExp)����ʱ�������
	int strTmpIndex=-1;
	int i;
	int res;
	for(i=0;i<strlen(strExp);i++)
	{
		if(strExp[i]=='*')    //��ִ�С�*���롮/��
		{
			int leftOperand=strTmp[strTmpIndex]-'0';  //�����������ʱ������ȡ  
			int rightOperand=strExp[i+1]-'0'; //�Ҳ�������ԭ������ȡ
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

	//printf("%s\n",strTmp); �鿴��ʱ����
	res=strTmp[0]-'0';
	for(i=1;i<strlen(strTmp);i++)
	{
		if(strTmp[i]=='+') res+=strTmp[++i]-'0';
		else if(strTmp[i]=='-') res-=strTmp[++i]-'0';
	}
	printf("%d\n",res);
	return 0;
}













