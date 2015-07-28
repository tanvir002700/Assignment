%{
	int sum=0;
%}

%%	

I {
	sum += 1;
}
IV {
	sum += 4;
}
V {
	sum += 5;
}
IX {
	sum += 9;
}
X {
	sum += 10;
}
XL {
	sum += 40;
}
L {
	sum += 50;
}
XC {
	sum += 90;
}
C {
	sum += 100;
}
CD {
	sum += 400;
}
D {
	sum += 500;
}
CM {
	sum += 900;
}
M {
	sum += 1000;
}

[\n] {
	return sum;
}

%%
int main (void) {
   
	yylex ();

	printf ("Decimal value  = %d\n", sum);
	return 0;
}

int yywrap(void){
	return 0;
}

int yyerror(void){
	printf("Error\n");
	exit(1);
}