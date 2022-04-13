#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int isOperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/') return 1;
	else return 0;
}

void moveOperator(char *p)
{
	while(*p!='\0')//移动操作符
	{
		*p=*(p+1);
		p++;
	}
}

void moveOperand(float *p,float *end)//移动操作数
{
	while(p!=end)
	{
		*p=*(p+1);
		p++;
	}
}


int main()
{
	char strExp[]="1-2.5*4+10.2/5.1";
	char operators[100]={'\0'};//操作符
	float operands[100];//操作数
	int operatorsIndex=0;//操作符下标
	for(int i=0;i<strlen(strExp);i++)//提取操作符
	{
		if(isOperator(strExp[i])) 
			operators[operatorsIndex++]=strExp[i];
	}
	int operandsIndex=0;//操作数下标
	for(int i=0;i<strlen(strExp);i++)//提取操作数
	{
		char temp[100]={'\0'};
		int tempIndex=0;
		while(!isOperator(strExp[i]))
		{
			temp[tempIndex]=strExp[i];
			i++;
			tempIndex++;
		}
		float floatV=atof(temp);
		operands[operandsIndex++]=floatV;
	}

	char *poperator=operators; //处理* /
	char *poperand=operands;
	while(*poperator!='\0')
	{
		if(*poperator=='*')
		{
			float leftOperand=*poperand;
			float rightOperand=*(poperand+1);
			float res=leftOperand*rightOperand;
			*poperand=res;
			moveOperator(poperator);
			moveOperand(poperand+1,&operands[operandsIndex--]);
		}else if(*poperator=='/')
		{
			float leftOperand=*poperand;
			float rightOperand=*(poperand+1);
			float res=leftOperand/rightOperand;
			*poperand=res;
			moveOperator(poperator);
			moveOperand(poperand+1,&operands[operandsIndex--]);
		}else
		{
			poperator++;
			poperand++;
		}
	}
	poperator=operators;  //处理+-
	poperand=operands;
	while(*poperator!='\0')
	{
		if(*poperator=='+')
		{
			float leftOperand=*poperand;
			float rightOperand=*(poperand+1);
			float res=leftOperand+rightOperand;
			*poperand=res;
			moveOperator(poperator);
			moveOperand(poperand+1,&operands[operandsIndex--]);
		}else if(*poperator=='-')
		{
			float leftOperand=*poperand;
			float rightOperand=*(poperand+1);
			float res=leftOperand-rightOperand;
			*poperand=res;
			moveOperator(poperator);
			moveOperand(poperand+1,&operands[operandsIndex--]);
		}
	}
	printf("%0.2f",operands[0]);
	return 0;
}