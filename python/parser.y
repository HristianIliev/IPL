%{
using namespace std;

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include "parser.hpp"

void yyerror(YYLTYPE* loc, const char* err);

Node* root = nullptr;

int nodesSize = 0;

set<string> symbols;
%}


%code requires {
    #include "ast.hpp"
}

%locations

%union {
    string* str;
    Node* node;
}

%define api.pure full
%define api.push-pull push
%define parse.error verbose
    
%token <str> IDENTIFIER FIELDINVOCATION FLOAT CLASS INTEGER STRING BOOLEAN INDENT DEINDENT NEWLINE AND BREAK DEF ELIF ELSE FOR IN IF NOT OR RETURN WHILE ASSIGN PLUS MINUS MULTIPLICATION DIVISION EQUALS NOTEQUALS GREATERTHAN GREATERTHANEQUALS LESSTHAN LESSTHANEQUALS MODULUS LEFTPAREN RIGHTPAREN LEFTBRACKET RIGHTBRACKET COMMA COLON

%type <node> program
%type <node> statements
%type <node> statement assign_statement if_statement for_statement while_statement break_statement parameters function_call function_definition return_statement class_definition
%type <node> expression primary_expression negated_expression
%type <node> block
%type <node> condition
%type <node> elif_blocks else_block

%left OR
%left AND
%left PLUS MINUS
%left MULTIPLICATION DIVISION
%left EQUALS NOTEQUALS GREATERTHAN GREATERTHANEQUALS LESSTHAN LESSTHANEQUALS
%right NOT

%start program

%%

program
  : statements { 
        string name = "root" + to_string(nodesSize);

        nodesSize++;

        BlockNode* result = new BlockNode(name);
        BlockNode* block = dynamic_cast<BlockNode*>($1);

        vector<Node*>::iterator it;
        for (it = block->childs.begin(); it != block->childs.end(); it++) {
            result->childs.push_back((*it));
        }

        root = result;
    }
  ;

statements
    : statement { 
        BlockNode* result = new BlockNode(string("temp"));

        result->childs.push_back($1);

        $$ = result;
    }
    | statements statement { 
        BlockNode* result = new BlockNode(string("temp"));
        BlockNode* originalBlockNode = dynamic_cast<BlockNode*>($1);

        vector<Node*>::iterator it;
        for (it = originalBlockNode->childs.begin(); it != originalBlockNode->childs.end(); ++it) {
            result->childs.push_back((*it));
        }

        result->childs.push_back($2);
        $$ = result;
    }
  ;

statement
  : assign_statement { 
        $$ = $1;
    }
  | if_statement { 
        $$ = $1;
    }
  | for_statement {
        $$ = $1;
    }
  | while_statement {  
        $$ = $1;
    }
  | break_statement { 
        $$ = $1;
  }
  | function_call {
      $$ = $1;
    }
  | function_definition {
      $$ = $1;
    }
  | class_definition {
      $$ = $1;
    }
  | return_statement {
      $$ = $1;
    }
  ;

primary_expression
  : IDENTIFIER { 
        string name = "iden" + to_string(nodesSize);

        nodesSize++;

        $$ = new LiteralNode(name, "Identifier", *$1);
    }
  | FIELDINVOCATION {
        string name = "fieldInvocation" + to_string(nodesSize);

        nodesSize++;

        $$ = new LiteralNode(name, "Identifier", *$1);
    }
  | FLOAT { 
        string name = "float" + to_string(nodesSize);

        nodesSize++;

        $$ = new LiteralNode(name, "Float", *$1);
    }
  | INTEGER { 
        string name = "integer" + to_string(nodesSize);

        nodesSize++;

        $$ = new LiteralNode(name, "Integer", *$1);
    }
  | BOOLEAN { 
        string name = "bool" + to_string(nodesSize);
        
        nodesSize++;
        
        $$ = new LiteralNode(name, "Boolean", *$1);
    }
  | STRING {
        string name = "string" + to_string(nodesSize);
        
        nodesSize++;
        
        string value = *$1;

        value.erase(0, 1);

        value = value.substr(0, value.size()-1);

        $$ = new LiteralNode(name, "String", value);
    }
  | LEFTPAREN expression RIGHTPAREN { 
        string name = "paren" + to_string(nodesSize);
        
        nodesSize++;

        UnaryNode* result = new UnaryNode(name, "Parenthesis");
        result->child = $2;
        $$ = result;
    }
  ;

negated_expression
  : NOT primary_expression { 
        string name = "not" + to_string(nodesSize);
        
        nodesSize++;

        UnaryNode* result = new UnaryNode(name, "NOT");
        result->child = $2;
        $$ = result;
    }
  ;

parameters
  : %empty { 
      $$ = nullptr;
    }
  | expression {
      $$ = $1;
    }
  | parameters COMMA primary_expression {
        LiteralNode* result = dynamic_cast<LiteralNode*>($3);
        
        LiteralNode* tmp1 = dynamic_cast<LiteralNode*>($1);
        
        result->siblings.push_back(tmp1);

        vector<LiteralNode*>::iterator it;
        for (it = tmp1->siblings.begin(); it != tmp1->siblings.end(); ++it) {
          result->siblings.push_back((*it));
        }

        $$ = result;
   }
 ;

expression
  : primary_expression { 
        $$ = $1; 
    }
  | negated_expression { 
        $$ = $1; 
    }
  | expression PLUS expression { 
        string name = "plus" + to_string(nodesSize);

        nodesSize++;

        BinaryNode* result = new BinaryNode(name, "Plus");
        result->left = $1;
        result->right = $3;
        $$ = result;
    }
  | expression MINUS expression { 
        string name = "minus" + to_string(nodesSize);
        
        nodesSize++;
        
        BinaryNode* result = new BinaryNode(name, "Minus");
        result->left = $1;
        result->right = $3;
        $$ = result;
    }
  | expression MULTIPLICATION expression { 
        string name = "multiplication" + to_string(nodesSize);

        nodesSize++;

        BinaryNode* result = new BinaryNode(name, "Multiplication");
        result->left = $1;
        result->right = $3;
        $$ = result;
    } 
  | expression MODULUS expression {
      string name = "modulus" + to_string(nodesSize);

      nodesSize++;

      BinaryNode* result = new BinaryNode(name, "Modulus");
      result->left = $1;
      result->right = $3;
      $$ = result;
    }
  | expression DIVISION expression { 
        string name = "division" + to_string(nodesSize);

        nodesSize++;

        BinaryNode* result = new BinaryNode(name, "Division");
        result->left = $1;
        result->right = $3;
        $$ = result;
    }
  | expression EQUALS expression { 
        string name = "equals" + to_string(nodesSize);

        nodesSize++;

        BinaryNode* result = new BinaryNode(name, "Equals");
        result->left = $1;
        result->right = $3;
        $$ = result;
    }
  | expression NOTEQUALS expression { 
        string name = "notequals" + to_string(nodesSize);

        nodesSize++;

        BinaryNode* result = new BinaryNode(name, "NotEquals");
        result->left = $1;
        result->right = $3;
        $$ = result;
    }
  | expression GREATERTHAN expression { 
        string name = "greaterthan" + to_string(nodesSize);
        
        nodesSize++;

        BinaryNode* result = new BinaryNode(name, "GreaterThan");
        result->left = $1;
        result->right = $3;
        $$ = result;
    }
  | expression GREATERTHANEQUALS expression { 
        string name = "greaterthanequals" + to_string(nodesSize);
        
        nodesSize++;

        BinaryNode* result = new BinaryNode(name, "GreaterThanEquals");
        result->left = $1;
        result->right = $3;
        $$ = result;
    }
  | expression LESSTHAN expression { 
        string name = "lessthan" + to_string(nodesSize);
        
        nodesSize++;

        BinaryNode* result = new BinaryNode(name, "LessThan");
        result->left = $1;
        result->right = $3;
        $$ = result;
    }
  | expression LESSTHANEQUALS expression { 
        string name = "lessthanequals" + to_string(nodesSize);
        
        nodesSize++;

        BinaryNode* result = new BinaryNode(name, "LessThanEquals");
        result->left = $1;
        result->right = $3;
        $$ = result;
    }
  | LEFTBRACKET parameters RIGHTBRACKET {
        string name = "arrayinitialization" + to_string(nodesSize);

        nodesSize++;

        LiteralNodes* result = new LiteralNodes(name, "Literals");

        if ($2 != nullptr) {
            LiteralNode* literal = dynamic_cast<LiteralNode*>($2);
            result->literals.push_back(literal);

            vector<LiteralNode*>::iterator it;
            for (it = literal->siblings.begin(); it != literal->siblings.end(); ++it) {
                result->literals.push_back((*it));
            }
        }

        $$ = result;
    }
  | IDENTIFIER LEFTPAREN parameters RIGHTPAREN {
      string name = "functioncall" + to_string(nodesSize);

      nodesSize++;

      LiteralNodes* parameters = new LiteralNodes("parameters" + nodesSize, "Parameters");

      if ($3 != nullptr) {
        LiteralNode* literal = dynamic_cast<LiteralNode*>($3);
        parameters->literals.push_back(literal);

        vector<LiteralNode*>::iterator it;
        for (it = literal->siblings.begin(); it != literal->siblings.end(); ++it) {
          parameters->literals.push_back((*it));
        }
      }

      FunctionNode* result = new FunctionNode(name, "FunctionCall", *$1, parameters);

      $$ = result;
    }
  ;

function_call
  : IDENTIFIER LEFTPAREN parameters RIGHTPAREN NEWLINE {
    string name = "functioncall" + to_string(nodesSize);

    nodesSize++;

    LiteralNodes* parameters = new LiteralNodes("parameters" + nodesSize, "Parameters");

    if ($3 != nullptr) {
      LiteralNode* literal = dynamic_cast<LiteralNode*>($3);
      parameters->literals.push_back(literal);

      vector<LiteralNode*>::iterator it;
      for (it = literal->siblings.begin(); it != literal->siblings.end(); ++it) {
        parameters->literals.push_back((*it));
      }
    }

    FunctionNode* result = new FunctionNode(name, "FunctionCall", *$1, parameters);

    $$ = result;
  }
  | FIELDINVOCATION LEFTPAREN parameters RIGHTPAREN NEWLINE {
    string name = "functioncall" + to_string(nodesSize);

    nodesSize++;

    LiteralNodes* parameters = new LiteralNodes("parameters" + nodesSize, "Parameters");

    if ($3 != nullptr) {
      LiteralNode* literal = dynamic_cast<LiteralNode*>($3);
      parameters->literals.push_back(literal);

      vector<LiteralNode*>::iterator it;
      for (it = literal->siblings.begin(); it != literal->siblings.end(); ++it) {
        parameters->literals.push_back((*it));
      }
    }

    FunctionNode* result = new FunctionNode(name, "FunctionCall", *$1, parameters);

    $$ = result;
  }
 ;

function_definition
  : DEF IDENTIFIER LEFTPAREN parameters RIGHTPAREN COLON NEWLINE block {
    string name = "functiondefinition" + to_string(nodesSize);

    nodesSize++;

    LiteralNodes* parameters = new LiteralNodes("parameters" + to_string(nodesSize), "Arguments");

    nodesSize++;
    if ($4 != nullptr) {
      LiteralNode* literal = dynamic_cast<LiteralNode*>($4);
      parameters->literals.push_back(literal);

      vector<LiteralNode*>::iterator it;
      for (it = literal->siblings.begin(); it != literal->siblings.end(); ++it) {
        parameters->literals.push_back((*it));
      }
    }

    FunctionNode* result = new FunctionNode(name, "FunctionDefinition", *$2, parameters);

    result->functionBlock = dynamic_cast<BlockNode*>($8);

    $$ = result;
  }
 ;

class_definition
  : CLASS IDENTIFIER COLON NEWLINE block {
    string name = "class" + to_string(nodesSize);

    nodesSize++;

    ClassNode* result = new ClassNode(name, *$2, dynamic_cast<BlockNode*>($5));

    $$ = result;
  }
 ;

return_statement
  : RETURN IDENTIFIER NEWLINE {
        string name = "return" + to_string(nodesSize);

        nodesSize++;

        UnaryNode* result = new UnaryNode(name, "Return");

        string nameLiteral = "returnvalue" + to_string(nodesSize);

        nodesSize++;

        result->child = new LiteralNode(nameLiteral, "Return identifier", *$2);

        $$ = result;
  }
 ;

assign_statement
  : IDENTIFIER ASSIGN expression NEWLINE { 
        string name = "assign" + to_string(nodesSize);
        
        nodesSize++;
        
        BinaryNode* result = new BinaryNode(name, "ASSIGNMENT");
        
        string name1 = "iden" + to_string(nodesSize);
        
        nodesSize++;
        
        LiteralNode* iden = new LiteralNode(name1, "Identifier", *$1);
        result->left = iden;

        result->right = $3;
        $$ = result;
    }
  | FIELDINVOCATION ASSIGN expression NEWLINE { 
        string name = "assign" + to_string(nodesSize);
        
        nodesSize++;
        
        BinaryNode* result = new BinaryNode(name, "ASSIGNMENT");
        
        string name1 = "iden" + to_string(nodesSize);
        
        nodesSize++;
        
        LiteralNode* iden = new LiteralNode(name1, "Identifier", *$1);
        result->left = iden;

        result->right = $3;
        $$ = result;
    }
  ;

block
  : INDENT statements DEINDENT { 
        string name = "block" + to_string(nodesSize);
        
        nodesSize++;
        
        BlockNode* result = new BlockNode(name);
        BlockNode* statements = dynamic_cast<BlockNode*>($2);

        vector<Node*>::iterator it;
        for (it = statements->childs.begin(); it != statements->childs.end(); ++it) {
            result->childs.push_back((*it));
        }

        $$ = result;
    }
  ;

condition
  : expression { 
        $$ = $1; 
    }
  | condition AND condition { 
        string name = "and" + to_string(nodesSize);
        
        nodesSize++;
        
        BinaryNode* result = new BinaryNode(name, "AND");
        result->left = $1;
        result->right = $3;
        $$ = result;
    }
  | condition OR condition { 
        string name = "or" + to_string(nodesSize);
        
        nodesSize++;
        
        BinaryNode* result = new BinaryNode(name, "OR");
        result->left = $1;
        result->right = $3;
        $$ = result;
    }
  ;

if_statement
  : IF condition COLON NEWLINE block elif_blocks else_block { 
        string name = "if" + to_string(nodesSize);
        
        nodesSize++;
        
        IfNode* result = new IfNode(name);
        result->condition = $2;
        result->ifBlock = dynamic_cast<BlockNode*>($5);

        if ($6 != nullptr) {
            ElifNode* elifnode = dynamic_cast<ElifNode*>($6);
            result->elifs.push_back(elifnode);

            vector<ElifNode*>::iterator it;
            for (it = elifnode->siblings.begin(); it != elifnode->siblings.end(); ++it) {
                result->elifs.push_back((*it));
            }
        }

        if ($7 != nullptr) {
          result->elseBlock = dynamic_cast<BlockNode*>($7);
        }

        $$ = result;
    }
  ;

elif_blocks
  : %empty { 
        $$ = nullptr;
    }
  | elif_blocks ELIF condition COLON NEWLINE block { 
        string name = "elif" + to_string(nodesSize);
        
        nodesSize++;

        ElifNode* result = new ElifNode(name);
        result->condition = $3;
        result->block = dynamic_cast<BlockNode*>($6);

        if ($1 != nullptr) {
            ElifNode* tmp1 = dynamic_cast<ElifNode*>($1);
            result->siblings.push_back(tmp1);

            vector<ElifNode*>::iterator it;
            for (it = tmp1->siblings.begin(); it != tmp1->siblings.end(); ++it) {
                result->siblings.push_back((*it));
            }
        }

        $$ = result;
    }
  ;

else_block
  : %empty { 
        $$ = nullptr;
    }
  | ELSE COLON NEWLINE block { 
        string name = "block" + to_string(nodesSize);
        
        nodesSize++;
        
        BlockNode* result = new BlockNode(name);
        /* ? */
        $$ = result;
        /* ? */
        $$ = $4;
    }
;

for_statement
  : FOR IDENTIFIER IN IDENTIFIER COLON NEWLINE block {
      string name = "for" + to_string(nodesSize);

      nodesSize++;

      string literalName = "iterationLiteral" + to_string(nodesSize);

      nodesSize++;

      LiteralNode* iterationLiteral = new LiteralNode(literalName, "IterationVar", *$2);

      string arrayName = "arrayLiteral" + to_string(nodesSize);

      nodesSize++;

      LiteralNode* arrayLiteral = new LiteralNode(arrayName, "ArrayVar", *$4);

      ForNode* result = new ForNode(name, iterationLiteral, arrayLiteral);
      result->block = $7;

      $$ = result;
    }
  | FOR IDENTIFIER IN IDENTIFIER LEFTPAREN parameters RIGHTPAREN COLON NEWLINE block {
      string name = "for" + to_string(nodesSize);

      nodesSize++;

      string literalName = "iterationLiteral" + to_string(nodesSize);

      nodesSize++;

      LiteralNode* iterationLiteral = new LiteralNode(literalName, "IterationVar", *$2);

      ForNode* result = new ForNode(name, iterationLiteral, nullptr);
  
      string functionCallName = "functioncall" + to_string(nodesSize);

      nodesSize++;

      LiteralNodes* parameters = new LiteralNodes("parameters" + nodesSize, "Parameters");

      if ($6 != nullptr) {
        LiteralNode* literal = dynamic_cast<LiteralNode*>($6);
        parameters->literals.push_back(literal);

        vector<LiteralNode*>::iterator it;
        for (it = literal->siblings.begin(); it != literal->siblings.end(); ++it) {
          parameters->literals.push_back((*it));
        }
      }

      FunctionNode* functioncall = new FunctionNode(functionCallName, "FunctionCall", *$4, parameters);

      result->functionCallNodeArray = functioncall;
      
      result->block = $10;

      $$ = result;
    }
  ;

while_statement
  : WHILE condition COLON NEWLINE block { 
        string name = "while" + to_string(nodesSize);
        
        nodesSize++;
        
        WhileNode* result = new WhileNode(name);
        result->condition = $2;
        result->block = $5;
        $$ = result;
    }
  ;

break_statement
  : BREAK NEWLINE { 
        string name = "break" + to_string(nodesSize);

        nodesSize;

        UnaryNode* result = new UnaryNode(name, "Break");

        $$ = result;
    }
  ;

%%

void yyerror(YYLTYPE* loc, const char* err) {
  cout << "Error (line " << loc->first_line << "): " << err << endl;
}
