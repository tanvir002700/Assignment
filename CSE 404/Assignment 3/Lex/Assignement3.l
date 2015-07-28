%{
	#include<stdio.h>
	#include<stdlib.h>
	int pos  = 0;
	int result[100];
	char Ans[][30]={" ","ODD","DIV4","Singed","Decimal","Scientefic","HEX","Overflow","String","Identifier","Unknown"};
%}

digit [0-9]{4,}
decimal [0-9]+\.[0-9]+
singed (-|\+)[0-9]+
hex [0-9A-F]+
string [0-9][0-9a-zA-Z]*
scientefic ({singed}(e|E){singed})
identifier [a-zA-Z][0-9a-zA-Z]*
unknown [^(-\+0-9a-zA-Z \n)]

%%
[ ] {}
{digit} {
	int number=atoi(yytext);
	int len=yyleng;
	if(number%2){
		result[pos]=1;
	}else if(number%4==0){
		result[pos]=2;
	}else if(len>4){
		result[pos]=7;
	}else{
		result[pos]=10;
	}
	pos++;
}
{singed} {
	result[pos]=3;
	pos++;
}
{decimal} {
	result[pos]=4;
	pos++;
}
{scientefic} {
	result[pos]=5; pos++;
}
{hex} {
	int len=yyleng;
	if(len>4){
		result[pos]=7;
	}else{
		result[pos]=6;
	}
	pos++;
}
{string} {
	result[pos]=8; pos++;
}
{identifier} {
	result[pos]=9; pos++;
}
{unknown} {
	result[pos]=10; pos++;
}
[\n] {
	return 0;
}
%%


int main(int argc, char **argv){
	yyin = stdin;
	yylex();
	int i=0;
	for(i=0;i<pos;i++){
		printf("%s\n",Ans[result[i]]);
	}
	return 0;
}

int yywrap(void){
	return 0;
}
