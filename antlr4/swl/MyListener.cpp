// Generated from swl.g4 by ANTLR 4.7
#include <iostream>
#include "MyListener.h"

using namespace std;

/*
string MyListener::conditionCheck(swlParser::ProgramContext *ctx){

}*/

void MyListener::enterProgram(swlParser::ProgramContext *ctx) {
    cout << "#include <iostream>" << endl << endl
         << "using namespace std;" << endl << endl
         << "int main() {" << endl;
    indent += 4;
}

void MyListener::exitProgram(swlParser::ProgramContext *ctx) {
    cout << "}" << endl;
}

void MyListener::enterWhiledo(swlParser::WhiledoContext *ctx){
  cout << string(indent, ' ') << "while (";
  /*if(ctx->boolean() != NULL)
    cout << ctx->boolean()->getText();
  cout << "){" << endl;
    indent += 4;*/
}

void MyListener::exitWdo(swlParser::WdoContext *ctx){
  cout <<"){"<<endl;
  indent += 4;
}

void MyListener::exitWhiledo(swlParser::WhiledoContext *ctx){
    cout << endl << string(indent, ' ') << "}";
    indent -= 4;
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

void MyListener::exitBoolean(swlParser::BooleanContext *ctx) {

  if(ctx->LOGIC()!=NULL)
  {
    string logic;
    if(ctx->LOGIC()->getText() == " and ") logic = "&&";
    else if(ctx->LOGIC()->getText() == " or ") logic = "||";
    else if(ctx->LOGIC()->getText() == " not ") logic = "!";

    ctx->LOGIC()->getText() = logic;
  }
}

void MyListener::exitCondition(swlParser::ConditionContext *ctx) {
  if(ctx->ID().size() > 1)
  {
    cout << ' ' << ctx->ID(0)->getText();
  }
  if(ctx->CARATTERI() != NULL)
  {
    cout << ' ' << ctx->CARATTERI()->getText() << ' ';
  }
  if(ctx->LOGIC() != NULL)
  {
    string logic;
    if(ctx->LOGIC()->getText() == " and ") logic = "&&";
    else if(ctx->LOGIC()->getText() == " or ") logic = "||";
    else if(ctx->LOGIC()->getText() == " not ") logic = "!";
    cout << logic;
  }
  if(ctx->ID().size() > 1)
  {
    cout << ' ' << ctx->ID(1)->getText();
  }
  /*if(ctx->NUMBER() > 1)
  {
    cout << ' ' << ctx->NUMBER().getText();
  }*/
}
