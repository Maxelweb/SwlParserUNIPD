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
 /*

 */
void MyListener::exitAsk(swlParser::AskContext *ctx) {
    string val;
    if(ctx->ID() != NULL) {
        val = ctx->ID()->getText();
    }
    cout << string(indent, ' ') << "cin >> " << val << "; " << endl;
}

void MyListener::enterWhiledo(swlParser::WhiledoContext *ctx){
    cout << string(indent, ' ') << "while (";
}

void MyListener::exitWdo(swlParser::WdoContext *ctx){
    cout<<"){"<<endl;
    indent += 4;
}

void MyListener::exitWhiledo(swlParser::WhiledoContext *ctx){
    indent -= 4;
    cout << endl << string(indent, ' ') << "}"<<endl;
}

void MyListener::enterIfthenelse(swlParser::IfthenelseContext *ctx){
  	cout << string(indent, ' ') << "if (";
}

void MyListener::enterIthen(swlParser::IthenContext *ctx){
  	cout << ") {" << endl;
  	indent += 4;
}

void MyListener::exitIelse(swlParser::IelseContext *ctx){
		indent -= 4;
  	cout << string(indent, ' ') << "} else {" << endl;
  	indent += 4;
}

void MyListener::exitIfthenelse(swlParser::IfthenelseContext *ctx){
    indent -= 4;
    cout << string(indent, ' ') << "}" << endl;
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
        val = ctx->NUMBER()->getText();void exitBoolean(swlParser::BooleanContext *ctx);
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
    }void exitBoolean(swlParser::BooleanContext *ctx);
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
    int siznot = ctx->lnot().size();
    if(siznot >= 1)
    {
      for (int i=0; i < siznot;  i++)
        cout << '!';

    }
}

void MyListener::enterLogic(swlParser::LogicContext *ctx) {
    if(ctx->getText() == "and")
      cout << " && ";
    else
      cout << " || ";
}

void MyListener::enterOpconf(swlParser::OpconfContext *ctx){
    cout << " " << ctx->getText() << " ";
}

void MyListener::enterVar(swlParser::VarContext *ctx){
    int siznot = ctx->lnot().size();
    if(siznot >= 1)
    {
      for (int i=0; i < siznot;  i++)
        cout << '!';

    }
    else
    {
      if(ctx->ID() != NULL)
      {
        cout << ctx->ID()->getText();
      }
      else
      {
        cout << ctx->NUMBER()->getText();
      }
    }

}
void MyListener::enterLb(swlParser::LbContext *ctx)
{
    cout<< '(';
}
void MyListener::enterRb(swlParser::RbContext *ctx){
    cout<< ')';
}
