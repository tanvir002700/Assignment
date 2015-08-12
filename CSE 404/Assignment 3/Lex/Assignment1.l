%{
	#include <stdio.h>
	#include <string.h>
	
	int TotalKeyword=0;
	int TotalIdentifier=0;
	int TotalOperator=0;
	int TotalConstant=0; 
	int TotalPunctuation=0;
	int TotalParenthesis=0;

	char KeywordList[1000];
	char IdentifierList[1000];
	char OperatorList[1000];
	char ConstantList[1000]; 
	char PunctuationList[1000];
	char ParenthesisList[1000];
%}

token auto|break|c(har|co(nst|ntinue))|do(uble)?|e(lse|num|xtern)|f(loat|or)|i(f|nt)|long|re(gister|turn)|s(i(gned|zeof)|t(atic|ruct)|witch)|typedef|unsigned|vo(id|latile)|while|_Packed
identifier [a-zA-Z][a-zA-Z0-9]*
op [-|+|\*|/|^|=]
constant [0-9]+
paranthesis [{|}|\[|\]|\(|\)]
punctuation [;|:|,]

%%
{token} {
	TotalKeyword++;	
	strcat(KeywordList, yytext);
	strcat(KeywordList, ",");
}
{identifier} {
	TotalIdentifier++;
	strcat(IdentifierList, yytext);
	strcat(IdentifierList, ",");
}
{constant} {
	TotalConstant++; 
	strcat(ConstantList, yytext);
	strcat(ConstantList, ",");
}
{paranthesis} {
	TotalParenthesis++; 
	strcat(ParenthesisList, yytext);
	strcat(ParenthesisList, ",");
}
{op} {
	TotalOperator++; 
	strcat(OperatorList, yytext);
	strcat(OperatorList, ",");
}
{punctuation} {
	TotalPunctuation++; 
	strcat(PunctuationList, yytext);
	strcat(PunctuationList, ",");
}


%%

int main(int argc, char **argv){
	printf("%s",argv[1]);
	FILE *fp=fopen(argv[1],"r");
	yyin = fp;
	yylex();
	printf("\n\nKeywords (%d): %s \n", TotalKeyword, KeywordList);
	printf("Identifiers (%d): %s \n", TotalIdentifier, IdentifierList);
	printf("Constants (%d): %s \n", TotalConstant, ConstantList);
	printf("Operators (%d): %s \n", TotalOperator, OperatorList);
	printf("Paranthesis (%d): %s \n", TotalParenthesis, ParenthesisList);
	printf("Punctuation (%d): %s \n", TotalPunctuation, PunctuationList);
	return 0;
}

int yywrap(void){
	return 1;
}

int yyerror(void){
	printf("Error\n");
	exit(1);
}
