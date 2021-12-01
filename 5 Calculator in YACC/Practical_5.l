%{
   /* Definition section */
  #include<stdio.h>
  #include "Practical_5.tab.h"
  extern int yylval;
%}
  
/* Rule Section */
%%
[0-9]+ {
          yylval=atoi(yytext);
          return NUMBER;
  
       }
[\t] ;
  
[\n] return 0;
  
. return yytext[0];
  
%%
  
int yywrap()
{
 return 1;
}

/*
flex Practical_5.l
bison -d Practical_5.y
gcc lex.yy.c Practical_5.tab.c -w
a.exe

5+9-3
*/
