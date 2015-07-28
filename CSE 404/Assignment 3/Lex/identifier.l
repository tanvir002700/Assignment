identifier [a-zA-Z][a-zA-Z0-9]*
%%
{identifier} {printf("identifier found\n");}

. {yyerror();}
%%

int main(int argc, char **argv){
	FILE *fp=fopen(argv[0],"r");
	yyin = fp;
	yylex();
}

int yywrap(void){
	return 0;
}

int yyerror(void){
	printf("Error\n");
	exit(1);
}
