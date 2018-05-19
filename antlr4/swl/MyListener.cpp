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
void MyListener::enterBoolean(swlParser::BooleanContext *ctx) {
  string name;
  string val;
  cout << string(indent, ' ') <<'{';
  indent++;
  cout<<endl<< "ENTER BOOL"<<endl;
  cout<<endl<< ctx->boolean().size()<<endl;
  cout<<endl<< ctx->ID().size()<<endl;
  cout<<endl<< ctx->NUMBER().size()<<endl;
  cout<<endl<< ctx->BR().size()<<endl;
  cout<<endl<< ctx->CARATTERI().size()<<endl;
  cout<<endl<< ctx->logic().size()<<endl;

}

void MyListener::exitBoolean(swlParser::BooleanContext *ctx) {
  cout<<endl<< "EXIT BOOL"<<endl;
  cout << string(indent, ' ') <<'}';
  indent--;
}

void MyListener::enterLogic(swlParser::LogicContext *ctx) {
  cout<<ctx->getText();
}


/*
void MyListener::enterBoolean(swlParser::BooleanContext *ctx) {
  //cout<<endl<<"Debug Enter boolean"<<endl;
  cout<<'(';
  if(ctx->NOTNOT() != NULL) {
      cout<<"(!";
  }

  if(ctx->CARATTERI().size() >= 1) {
      cout<< ctx->CARATTERI(0)->getText();
  }

  if(ctx->LOGIC().size() >= 1) {
      cout<< ctx->LOGIC(0)->getText();
  }

}

void MyListener::exitBoolean(swlParser::BooleanContext *ctx) {
  //cout<<endl<<"Debug exit boolean";
  if(ctx->CARATTERI().size() >= 1) {
      cout<< ctx->CARATTERI(0)->getText();
  }

  if(ctx->LOGIC().size() >= 1) {
      cout<< ctx->LOGIC(0)->getText();
  }
  cout<<')';
}

void MyListener::enterCondition(swlParser::ConditionContext *ctx) {
  cout<<endl<<"Debug Enter Condition"<<endl;
}

void MyListener::exitCondition(swlParser::ConditionContext *ctx) {
  cout<<endl<<"Debug exit Condition"<<endl;
}

void MyListener::enterVar(swlParser::VarContext *ctx) {
  //cout<<endl<<"Debug Enter Var" <<endl;
  string val;
  if(ctx->NOTNOT() != NULL) {
      cout<<"(!";
  }
  if(ctx->ID() != NULL) {
      val = ctx->ID()->getText();
  } else {
      val = ctx->NUMBER()->getText();
  }
  cout<< val;
}

void MyListener::exitVar(swlParser::VarContext *ctx) {
  //cout<<endl<<"Debug exit Var";
  if(ctx->NOTNOT() != NULL) {
      cout<<')';
  }
} */
