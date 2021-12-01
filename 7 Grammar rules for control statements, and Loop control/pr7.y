
%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char *msg);
void yywrap();

%}
%token ID NUM FOR LE GE EQ NE OR AND IF WHILE
%right "="
%left OR AND
%left '>' '<' LE GE EQ NE
%left '+' '-'
%left '*' '/'
%right UMINUS
%left '!'

%%
   
S         : ST {printf("Input accepted\n"); exit(0);}
ST       : FOR '(' E ';' E2 ';' E ')' DEF
          | IF '(' E2 ')' DEF
          | WHILE '(' E2 ')' DEF 
           ;
DEF    : '{' BODY '}'
           | E';'
           | ST
           |
           ;
BODY  : BODY BODY
           | E ';'       
           | ST
           |            
           ;
       
E        : ID '=' E
          | E '+' E
          | E '-' E
          | E '*' E
          | E '/' E
          | E '<' E
          | E '>' E
          | E LE E
          | E GE E
          | E EQ E
          | E NE E
          | E OR E
          | E AND E
          | E '+' '+'
          | E '-' '-'
          | ID 
          | NUM
          ;

   
E2     : E'<'E
         | E'>'E
         | E LE E
         | E GE E
         | E EQ E
         | E NE E
         | E OR E
         | E AND E
         ;   
%%


void main() {
    printf("Enter the expression:\n");
    yyparse();
} 



void yyerror(char *msg)
{printf("Error=%s\n",msg);}
void yywrap()
{
  return 0;
}