%{
	#include<stdio.h>
	#include<stdlib.h>
	int tabNum = 0;
%}
Rightb	[{]
Leftb	[}]
%%
^{Rightb}	{tabNum++; for(int i=0;i<tabNum;i++) printf("\t"); ECHO;}
^{Leftb}	{tabNum--; for(int i=0;i<tabNum;i++) printf("\t"); ECHO;}
^.			{for(int i=0;i<tabNum;i++) printf("\t"); ECHO;}
{Rightb}	{tabNum++; ECHO;}
{Leftb}		{tabNum--; ECHO;}
.			ECHO;
%%
int main(int argc, char* argv[]){
	yylex();
	return 0;
}