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
   // if(ctx->boolean() != NULL)
      //  cout << ctx->boolean()->getText();
    /*
  if(cty->LOGIC()!=NULL)
  {
    string logic;
    if(cty->LOGIC()->getText() == " and ") logic = "&&";
    else if(cty->LOGIC()->getText() == " or ") logic = "||";
    else if(cty->LOGIC()->getText() == " not ") logic = "!";
    else logic = cty->LOGIC()->getText();

    cout << " " << logic << " ";
  }
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


void MyListener::enterBoolean(swlParser::BooleanContext *ctx) {

  //int sizeCond = ctx->condition().size();
  //int sizeLog = ctx->LOGIC().size();
  //int sizeNot = ctx->NOTNOT() != NULL ? ctx->NOTNOT().size() : 0;
  //cout << "(SIZEA=" << ctx->condition().size() << ")";
  //cout << "(SIZEB=" << ctx->LOGIC().size() << ")";

  if(ctx->NOTNOT().size() > 0)
    if(ctx->NOTNOT(0)->getText() == " not " || ctx->NOTNOT(0)->getText() == "not ") 
      cout << "!(";

}



void MyListener::exitBoolean(swlParser::BooleanContext *ctx) {

// cout << ctx->condition().size() << " | " ; // DEBUG

    //if(ctx->condition() != NULL)

  //int x = 0;
  int sizeCond = ctx->condition().size();
  int sizeLog = ctx->LOGIC().size();
  //int sizeNot = ctx->NOTNOT() != NULL ? ctx->NOTNOT().size() : 0;
  //cout << "(SIZEA=" << ctx->condition().size() << ")";
  //cout << "(SIZEB=" << ctx->LOGIC().size() << ")";

  /*if(!sizeLog && !sizeCond && ctx->NOTNOT() != NULL)
    if(ctx->NOTNOT()->getText() == " not " || ctx->NOTNOT()->getText() == "not ") 
      cout << "!";*/

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


if(ctx->NOTNOT().size() > 0)
    if(ctx->NOTNOT(0)->getText() == " not " || ctx->NOTNOT(0)->getText() == "not ") 
      cout << ")";


   /*   if(ctx->condition().size() >= 1)
        {
         x++; 
         cout << "(X=" << x << ")";
         cout << ctx->condition(0)->getText();
        }
      /*else if(ctx->condition().size() == 1)
        cout << ctx->condition()->getText(); */
/*
    if(ctx->LOGIC()!=NULL)
    {
      x++;
      cout << "(X=" << x << ")";
      string logic;
      if(ctx->LOGIC()->getText() == " and ") logic = " && ";
      else if(ctx->LOGIC()->getText() == " or ") logic = " || ";
      else if(ctx->LOGIC()->getText() == " not ") logic = " ! ";
      cout << logic;
    }

   // if(ctx->condition() != NULL)
    /*  if(ctx->condition().size() > 1)
         cout << ctx->condition(1)->getText();*/

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
