// Generated from swl.g4 by ANTLR 4.7
#include <iostream>
#include "MyListener.h"

using namespace std;

string MyListener::conditionCheck(swlParser::ProgramContext *ctx){

}

void MyListener::enterProgram(swlParser::ProgramContext *ctx) {
    cout << "#include <iostream>" << endl << endl
         << "using namespace std;" << endl << endl
         << "int main() {" << endl;
    indent += 4;
}

void MyListener::enterWhile(swlParser::WhileContext *ctx) {

    string logic;
    if(ctx->OPTCONF() == "and") logic = "&&";
    elseif(ctx->OPTCONF() == "or") logic = "||";
    elseif(ctx->OPTCONF() == "not") logic = "!";


    cout << "while (" << Foo << ") {" << endl
         << Bar << endl
         << "}" << endl;

    indent += 4;
}
void MyListener::enterIf(swlParser::IfContext *ctx) {
    cout << "#include <iostream>" << endl << endl
         << "using namespace std;" << endl << endl
         << "int main() {" << endl;
    indent += 4;
}

void MyListener::exitProgram(swlParser::ProgramContext *ctx) {
    cout << "}" << endl;
}

void MyListener::exitWhile(swlParser::WhileContext *ctx) {
    cout << "}" << endl;
}

void MyListener::exitIf(swlParser::IfContext *ctx) {
    cout << "}" << endl;
}

void MyListener::exitAssign(swlParser::AssignContext *ctx) {
    string name = ctx->ID(0)->getText();
    string val;
    if(ctx->ID().size() > 1) {
        val = ctx->ID(1)->getText();
    } else {
        val = ctx->NUMBER()->getText();
    }
    cout << string(indent, ' ') << "int " << name << " = " << val << ";" << endl;
}


void MyListener::exitPrint(swlParser::PrintContext *ctx) {
    string val;
    if(ctx->ID() != NULL) {
        val = ctx->ID()->getText();
    } else {
        val = ctx->NUMBER()->getText();
    }
    cout << string(indent, ' ') << "cout << " << val << " << endl;" << endl;
}

void MyListener::exitAdd(swlParser::AddContext *ctx) {
    string name;
    string val;
    if(ctx->ID().size() > 1) {
        name = ctx->ID(1)->getText();
        val = ctx->ID(0)->getText();
    } else {
        name = ctx->ID(0)->getText();
        val = ctx->NUMBER()->getText();
    }
    cout << string(indent, ' ') << name << " += " << val << ";" << endl;
}

void MyListener::exitSub(swlParser::SubContext *ctx) {
    string name;
    string val;
    if(ctx->ID().size() > 1) {
        name = ctx->ID(1)->getText();
        val = ctx->ID(0)->getText();
    } else {
        name = ctx->ID(0)->getText();
        val = ctx->NUMBER()->getText();
    }
    cout << string(indent, ' ') << name << " -= " << val << ";" << endl;
}

void MyListener::exitMult(swlParser::MultContext *ctx) {
    string name;
    string val;
    if(ctx->ID().size() > 1) {
        name = ctx->ID(1)->getText();
        val = ctx->ID(0)->getText();
    } else {
        name = ctx->ID(0)->getText();
        val = ctx->NUMBER()->getText();
    }
    cout << string(indent, ' ') << name << " = " << name << "*" << val << ";" << endl;
}

void MyListener::exitDiv(swlParser::DivContext *ctx) {
    string name;
    string val;
    if(ctx->ID().size() > 1) {
        name = ctx->ID(1)->getText();
        val = ctx->ID(0)->getText();
    } else {
        name = ctx->ID(0)->getText();
        val = ctx->NUMBER()->getText();
    }
    cout << string(indent, ' ') << name << " = " << name << "/" << val << ";" << endl;
}
void MyListener::exitVar(swlParser::VarContext *ctx) {
  cout << ctx->ID()->getText()<<endl;
}
