%{
#include <stdio.h>
%}

%%
if|else|printf  { printf("%s is a keyword\n", yytext); }
[0-9]+          { printf("%s is a number\n", yytext); }
[a-zA-Z]+       { printf("%s is a word\n", yytext); }
[ \t\n]         ;  // Skip whitespace (spaces, tabs, newlines)
.               { printf("Unknown character: %s\n", yytext); }
%%

int main() {
    printf("\nEnter the string here:\n");
    yylex();  // Call the lexical analyzer to start scanning input
    return 0;
}

int yywrap() {
    return 1;
}
