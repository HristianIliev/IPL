using namespace std;

#include <iostream>
#include <set>
#include "parser.hpp"
#include "ast.hpp"

extern int yylex();

extern Node* root;

int main() {
    yylex();

    AST tree(root);
    tree.ToString();
}
