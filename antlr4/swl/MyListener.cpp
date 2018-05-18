// Generated from swl.g4 by ANTLR 4.7

/* ------------------------------
 *
 *	SWL PARSER PROJECT - UNIPD
 *	swl.debug.ovh (V-1.0)
 *
 * ------------------------------
 */


#include <iostream>
#include "MyListener.h"

using namespace std;

/*
 *
 *	PROGRAM HEADER / FOOTER
 *
 */


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
 *
 *	 WHILE-DO
 *
 */

void MyListener::enterWhiledo(swlParser::WhiledoContext *ctx){
  	cout << string(indent, ' ') << "while (";
  	string cond = ctx->boolean()->getText();
  	cout << cond;
}

void MyListener::exitWdo(swlParser::WdoContext *ctx){
  	cout << ") {" << endl;
  	indent += 4;
}

void MyListener::exitWhiledo(swlParser::WhiledoContext *ctx){
    indent -= 4;
    cout << string(indent, ' ') << "}" << endl;
}

/*
 *
 *	 IF-THEN-ELSE
 *
 */

void MyListener::enterIfthenelse(swlParser::IfthenelseContext *ctx){
  	cout << string(indent, ' ') << "if (";
  	string cond = ctx->boolean()->getText();
  	cout << cond;
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


/*
 *
 *	 ASSIGNMENT AND PRINT
 *
 */


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

/*
 *
 *	 BASE MATH OPERATIONS
 *
 */


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