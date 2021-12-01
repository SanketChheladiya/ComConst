/* Lex code to count total no of tokens */
%{
int n=0;
%}

%%

"while"|"if"|"else"|"int"|"float" {n++; printf(" ::::: Keywords");}

[a-zA-Z_][a-zA-Z0-9_]* {n++; printf(":::::  Indentifier");}

"<="|">="|"<"|">"|"=="|"="|"++"|"-"|"+"|"*"|"/" {n++; printf("::::::: Operator");}

[(){}|, ;]  {n++; printf("::::: Seperator");}

[0-9]*"."[0-9] {n++; printf(":::::: Float");}

[0-9]+  {n++; printf(":::::::: Integer");}

%%

int main()
{
	yylex();
	printf("Total No. of tokens = %d", n);
}
int yywrap()
{
	return 1;
}

/*

flex pr1.l
gcc lex.yy.c
a.exe

int 
float 
5 
6.5 
abc

*/






