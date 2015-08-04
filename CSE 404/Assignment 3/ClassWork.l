%{
	#include<stdio.h>
    int characters=0;
	int words=0;
%}
%%

[\t | ' ' | \n] words++;
[A-Z|a-z] characters++;

%%

main(int argc, char *argv[])
{
    FILE *fp=fopen(argv[1],"r");
    yyin= fp;
    yylex();
    printf("words %d\n",words);
	printf("characters %d\n",characters);
}

int yywrap()
{
    return 1;
}