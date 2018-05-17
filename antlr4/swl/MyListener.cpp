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


void MyListener::enterBoolean(swlParser::BooleanContext *ctx) {


  int sizeNot = ctx->NOTNOT().size();
 

  if(sizeNot >= 1)
    for(int y=0; y<sizeNot; y++)
      cout << ctx->NOTNOT(y)->getText() << "(";

}



void MyListener::exitBoolean(swlParser::BooleanContext *ctx) {


  int sizeCond = ctx->condition().size();
  int sizeLog = ctx->LOGIC().size();

  int sizeNot = ctx->NOTNOT().size();


  //if(ctx->LEB() != NULL) // LE PARENTESI IN APERTURA SONO ERRATE
  //  cout << "(";

  if(sizeLog)
      cout << ctx->condition(0)->getText(); 
  
  if(sizeCond > 1)
  {

    for(int i=1; i < sizeCond; i++)
    { 

      string logic;
      if(ctx->LOGIC(i-1)->getText() == " and ") logic = " && ";
      else if(ctx->LOGIC(i-1)->getText() == " or ") logic = " || ";
      cout << logic;

      cout << ctx->condition(i)->getText(); 
    }

  }

  //if(ctx->RIB() != NULL) // LE PARENTESI IN CHIUSURA SONO ERRATE
  //  cout << ")";



  if(sizeNot >= 1)
      for(int y=0; y<sizeNot; y++)
            cout << ")";

}

/*

void MyListener::exitCondition(swlParser::ConditionContext *ctx) {
  
  if(ctx->LOGIC() != NULL)
    cout << ctx->LOGIC(0)->getText() << ' ';

  if(ctx->ID() != NULL)
      if(ctx->ID().size() > 1)
        cout << ' ' << ctx->ID(0)->getText();
      else
        cout << ' ' << ctx->ID()->getText();

  if(ctx->NUMBER() != NULL)
    if(ctx->NUMBER().size() > 1)
        cout << ' ' << ctx->NUMBER(0)->getText();

  if(ctx->CARATTERI() != NULL)
  {
    cout << ' ' << ctx->CARATTERI()->getText() << ' ';
  }

  if(ctx->ID() != NULL)
      if(ctx->ID().size() > 1)
        cout << ' ' << ctx->ID(1)->getText();

  if(ctx->NUMBER() != NULL)
    if(ctx->NUMBER().size() > 1)
        cout << ' ' << ctx->NUMBER(1)->getText();

}*/
