#ifndef AST_H
#define AST_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    string name = "undefined";
    string label = "undefined";

    virtual ~Node() {}

    virtual void ToStringLabel() {
        cout << "\t" << name << " [label=\"" << label << "\"]" << endl;
    }

    virtual void ToStringChilds() {}

    virtual void ToString() {
        ToStringLabel();
        ToStringChilds();
    }
};

struct LiteralNode: public Node {
    string value = "undefined";
    vector<LiteralNode*> siblings;

    LiteralNode(string name, string label, string value) {
        this->name = name;
        this->label = label;
        this->value = value; 
    }

    virtual void ToStringLabel() {
        cout << "\t" << name << " [shape=box,label=\"" << label << ": " << value << "\"]" << endl;
    }

    virtual void ToStringChilds() {
    }
};

struct LiteralNodes: public Node {
    vector<LiteralNode*> literals;

    LiteralNodes(string name, string label) {
        this->name = name;
        this->label = label;
    }

    virtual void ToStringChilds() {
        vector<LiteralNode*>::reverse_iterator iterator;
        for (iterator = literals.rbegin(); iterator != literals.rend(); iterator++) {
            cout << "\t" << name << " -> " << (*iterator)->name << ";" << endl;

            (*iterator)->ToString();
        }
    }

};

struct UnaryNode: public Node {
    Node* child = nullptr;

    UnaryNode(string name, string label) {
        this->name = name;
        this->label = label;
    }

    ~UnaryNode() {
        if (child != nullptr)
            delete child;

        child = nullptr;
    }

    virtual void ToStringChilds() {
        if (child != nullptr) {
            cout << "\t" << name << " -> " << child->name << ";" << endl;

            child->ToString();
        }
    }
};

struct BinaryNode: public Node {
    Node* left = nullptr;
    Node* right = nullptr;

    BinaryNode(string name, string label) {
        this->name = name;
        this->label = label;
    }

    ~BinaryNode() {
        if (left != nullptr)
            delete left;

        left = nullptr;

        if (right != nullptr)
            delete right;

        right = nullptr;
    }

    virtual void ToStringChilds() {
        if (left != nullptr) {
            cout << "\t" << name << " -> " << left->name << ";" << endl;

            left->ToString();
        }

        if (right != nullptr) {
            cout << "\t" << name << " -> " << right->name << ";" << endl;

            right->ToString();
        }
    }
};

struct BlockNode: public Node {
    vector<Node*> childs;

    BlockNode(string name) {
        this->name = name;
        this->label = "Block";
    }

    virtual void ToStringChilds() {
        vector<Node*>::iterator iterator;
        for (iterator = childs.begin(); iterator != childs.end(); iterator++) {
            cout << "\t" << name << " -> " << (*iterator)->name << ";" << endl;

            (*iterator)->ToString();
        }
    }
};

struct ElifNode: public Node { 
    Node* condition; 
    Node* block;
    vector<ElifNode*> siblings;

    ElifNode(string name) {
        this->name = name;
        this->label = "ElseIf";
    }

    ~ElifNode() {
        if (condition != nullptr)
            delete condition;
        condition = nullptr;
        if (block != nullptr)
            delete block;
        block = nullptr;
    }

    virtual void ToStringChilds() { 
        cout << "\t" << name << " -> " << condition->name << ";" << endl; 

        condition->ToString(); 

        cout << "\t" << name << " -> " << block->name << ";" << endl; 

        block->ToString(); 
    } 
};

struct IfNode: public Node {
    Node* condition = nullptr;
    BlockNode* ifBlock = nullptr;
    vector<ElifNode*> elifs;
    BlockNode* elseBlock = nullptr;

    IfNode(string name) {
        this->name = name;
        this->label = "If";
    }

    ~IfNode() {
        if (condition != nullptr)
            delete condition;
        condition = nullptr;
        if (ifBlock != nullptr)
            delete ifBlock;
        ifBlock = nullptr;

        if (elseBlock != nullptr)
            delete elseBlock;
        elseBlock = nullptr;
    }

    virtual void ToStringChilds() {
        cout << "\t" << name << " -> " << condition->name << ";" << endl;

        condition->ToString();

        cout << "\t" << name << " -> " << ifBlock->name << ";" << endl;

        ifBlock->ToString();

        vector<ElifNode*>::iterator iterator;
        for (iterator = elifs.begin(); iterator != elifs.end(); iterator++) {
            cout << "\t" << name << " -> " << (*iterator)->name << ";" << endl;

            (*iterator)->ToString();
        }

        if (elseBlock != nullptr) {
            cout << "\t" << name << " -> " << elseBlock->name << ";" << endl;

            elseBlock->ToString();
        }
    }
};

struct ClassNode : public Node {
    string className;
    BlockNode* classBlock = nullptr;

    ClassNode(string name, string className, BlockNode* classBlock) {
        this->name = name;
        this->className = className;
        this->classBlock = classBlock;
        this->label = "Class";
    }

    ~ClassNode() {
        if (classBlock != nullptr) {
            delete classBlock;
        }

        classBlock = nullptr;
    }

    virtual void ToStringLabel() {
        cout << "\t" << name << " [shape=box,label=\"" << label << ": " << className << "\"]" << endl;
    }

    virtual void ToStringChilds() {
        if (classBlock != nullptr) {
            cout << "\t" << name << " -> " << classBlock->name << ";" << endl;

            classBlock->ToString();
        }
    }
};

struct FunctionNode : public Node {
    string functionName;
    LiteralNodes* parameters = nullptr;
    BlockNode* functionBlock = nullptr;

    FunctionNode(string name, string label, string functionName, LiteralNodes* parameters) {
        this->functionName = functionName;
        this->name = name;
        this->label = label;
        this->parameters = parameters;
    }

    ~FunctionNode() {
        if (parameters != nullptr)
            delete parameters;
        parameters = nullptr;
        if (functionBlock != nullptr)
            delete functionBlock;
        functionBlock = nullptr;
    }

    virtual void ToStringLabel() {
        cout << "\t" << name << " [shape=box,label=\"" << label << ": " << functionName << "\"]" << endl;
    }

    virtual void ToStringChilds() {
        cout << "\t" << name << " -> " << parameters->name << ";" << endl;

        parameters->ToString();

        if (functionBlock != nullptr) {
            cout << "\t" << name << " -> " << functionBlock->name << ";" << endl;

            functionBlock->ToString();
        }
    }

};

struct ForNode: public Node {
    LiteralNode* iterationVar;
    LiteralNode* array = nullptr;
    FunctionNode* functionCallNodeArray = nullptr;
    Node* block = nullptr;

    ForNode(string name, LiteralNode* iterationVar, LiteralNode* array) {
        this->name = name;
        this->iterationVar = iterationVar;
        this->array = array;
        this->label = "For";
    }

    ~ForNode() {
        if (functionCallNodeArray != nullptr)
            delete functionCallNodeArray;
        functionCallNodeArray = nullptr;
        if (block != nullptr)
            delete block;
        block = nullptr;
    }

    virtual void ToStringChilds() {
        cout << "\t" << name << " -> " << iterationVar->name << ";" << endl;
        iterationVar->ToString();

        if (array != nullptr) {
            cout << "\t" << name << " -> " << array->name << ";" << endl;

            array->ToString();
        }
        
        if (functionCallNodeArray != nullptr) {
            cout << "\t" << name << " -> " << functionCallNodeArray->name << ";" << endl;

            functionCallNodeArray->ToString();
        }

        cout << "\t" << name << " -> " << block->name << ";" << endl;

        block->ToString();
    }
};

struct WhileNode: public Node {
    Node* condition;
    Node* block;

    WhileNode(string name) {
        this->name = name;
        this->label = "While";
    }

    virtual void ToStringChilds() {
        cout << "\t" << name << " -> " << condition->name << ";" << endl;

        condition->ToString();

        cout << "\t" << name << " -> " << block->name << ";" << endl;

        block->ToString();
    }
};


struct AST {
    Node* root = nullptr;

    AST(Node* root) {
        this->root = root;
    }

    AST(){}

    ~AST() {
        if (root != nullptr) {
            delete root;

            root = nullptr;
        }
    }

    void ToString() {
        cout << "digraph G {" << endl;

        root->ToString();

        cout << "}" << endl;
    }
};



#endif
