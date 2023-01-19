/*
 * This lexer along with the parser.y implements a Push parser which means that on every matched token
 * the parser is called, which pushes new node in the tree.  
 */
%{
#include <iostream>
#include <stack>
#include <cstdlib>

#include "./parser.hpp"

/*
 * Since in Python indentation makes difference for the logic of the program the lexer needs to keep track of it
 * and be able to determine on which identation level is it on on every given token. I am doing with a stack on which we push token 
 * for identation every time a tab or whitespaces is encountered and poppint indentation tokens every time a tab is reduced.
 */
std::stack<int> indents;
%}

%option noyywrap
%option yylineno

%%

%{
  if (indents.empty()) {
    indents.push(0);
  }

  /*
   * We also want to initialize a parser state to be sent to the parser on
   * each push parse call.
   */
  yypstate* pstate = yypstate_new();

  YYSTYPE yylval;
  YYLTYPE location;

  /*
   * Definition of a macro that pushes a token to the parser along with its value
   */
  #define PARSE(token, text) do { \
    yylval.str = text ? new std::string(text) : NULL; \
    location.first_line = location.last_line = yylineno; \
    int status = yypush_parse(pstate, token, &yylval, &location); \
    if (status != YYPUSH_MORE) { \
      yypstate_delete(pstate); \
      return status; \
    } \
  } while (0) \
%}

"+"         { PARSE(PLUS, NULL); }
"-"         { PARSE(MINUS, NULL); }
"*"         { PARSE(MULTIPLICATION, NULL); }
"/"         { PARSE(DIVISION, NULL); }
"%"         { PARSE(MODULUS, NULL); }
"="         { PARSE(ASSIGN, NULL); }
"=="        { PARSE(EQUALS, NULL); }
"!="        { PARSE(NOTEQUALS, NULL); }
">"         { PARSE(GREATERTHAN, NULL); }
"<"         { PARSE(LESSTHAN, NULL); }
">="        { PARSE(GREATERTHANEQUALS, NULL); }
"<="        { PARSE(LESSTHANEQUALS, NULL); }

"["         { PARSE(LEFTBRACKET, NULL); }
"]"         { PARSE(RIGHTBRACKET, NULL); }
"("         { PARSE(LEFTPAREN, NULL); }
")"         { PARSE(RIGHTPAREN, NULL); }
","         { PARSE(COMMA, NULL); }
":"         { PARSE(COLON, NULL); }

"if"        { PARSE(IF, NULL); }
"elif"      { PARSE(ELIF, NULL); }
"else"      { PARSE(ELSE, NULL); }
"and"       { PARSE(AND, NULL); }
"for"       { PARSE(FOR, NULL); }
"in"        { PARSE(IN, NULL); }
"break"     { PARSE(BREAK, NULL); }
"def"       { PARSE(DEF, NULL); }
"not"       { PARSE(NOT, NULL); }
"or"        { PARSE(OR, NULL); }
"return"    { PARSE(RETURN, NULL); }
"while"     { PARSE(WHILE, NULL); }
"class"     { PARSE(CLASS, NULL); }

"True"      { PARSE(BOOLEAN, yytext); }
"False"     { PARSE(BOOLEAN, yytext); }

[a-zA-Z_][a-zA-Z0-9_]*  { PARSE(IDENTIFIER, yytext); }
[a-zA-Z_][a-zA-Z0-9_]*\.?[a-zA-Z_][a-zA-Z0-9_]*  { PARSE(FIELDINVOCATION, yytext); }

-?[0-9]+    { PARSE(INTEGER, yytext); }

-?[0-9]+"."[0-9]+       { PARSE(FLOAT, yytext); }

^[ \t]*\r?\n   {}

^[ \t]*#.*\r?\n    {}

^[ \t]+     {
              if (indents.top() < (int)yyleng) {
                /*
                 * We have encountered more indents than the previous indent on top of the stack.
                 */
                indents.push(yyleng);

                PARSE(INDENT, NULL);
              } else {
                /*
                 * If the current indentation level is less than or equal to the top indentation then pop from the stack
                 * of indentations until the current top is the same as the current token and emit a deindent.
                 */
                while (indents.empty() == false && indents.top() != (int) yyleng) {
                  indents.pop();

                  PARSE(DEINDENT, NULL);
                }

                /*
                 * If we popped everything off the stack, that means the current indentation level didn't match any on the stack,
                 * which is an indentation error.
                 */
                if (indents.empty()) {
                  std::cerr << "Error: Incorrect indentation on line " << yylineno << std::endl;
                  return 1;
                }
              }
            }

^[^ \t]+  {
              /*
               * Not indented line. Pop all indentations and push a DEINDENT token. After that REJECT so that the next token is also called.
               */
              while(indents.top() != 0) {
                indents.pop();

                PARSE(DEINDENT, NULL);
              }

              REJECT;
            }

\r?\n       {
              PARSE(NEWLINE, NULL);
            }

<<EOF>>     {
              /*
               * We have reached the end of the file so pop all indentations and push DEINDENT for every one
               */
              while(indents.top() != 0) {
                indents.pop();

                PARSE(DEINDENT, NULL);
              }

              // Terminate the parsing
              int status = yypush_parse(pstate, 0, NULL, NULL);

              yypstate_delete(pstate);

              return status;
            }

[ \t]       {  }

\"(\\.|[^"\\])*\" { PARSE(STRING, yytext); }

.           {
              std::cerr << "Token on line " << yylineno << " was not recognized. Token: " << yytext << std::endl;

              PARSE(yytext[0], NULL);
            }


%%
