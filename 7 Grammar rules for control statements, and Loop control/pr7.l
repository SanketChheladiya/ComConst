%{
#include <stdio.h>
#include <stdlib.h>
#include "pr7.tab.h"
%}

alpha [A-Za-z]
digit [0-9]

%%

[\t \n]
for             return FOR;
if              return IF;
while           return WHILE;
{digit}+    return NUM;
{alpha}({alpha}|{digit})* return ID;
"<="         return LE;
">="         return GE;
"=="         return EQ;
"!="          return NE;
"||"            return OR;
"&&"         return AND;
.                return yytext[0];

%%


/*
flex pr7.l
bison -d pr7.y
gcc lex.yy.c pr7.tab.c -w


while{a=b;}

if(a<9){a++;}

while(a<9){a=a+5;}

while(a<9){{a=a++5;}

*/