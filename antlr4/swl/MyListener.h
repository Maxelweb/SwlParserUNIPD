#pragma once

/* ------------------------------
 *
 *  SWL PARSER PROJECT - UNIPD
 *  swl.debug.ovh (V-1.0)
 *
 * ------------------------------
 */


#include "antlr4-runtime.h"
#include "swlParser.h"
#include "swlBaseListener.h"
using namespace std;

/**
 * This class defines a concrete listener for a parse tree produced by swlParser.
 */


class  MyListener : public swlBaseListener {
private:
  int indent = 0;

public:

  void enterProgram(swlParser::ProgramContext *ctx);
  void exitProgram(swlParser::ProgramContext *ctx);

  void exitAssign(swlParser::AssignContext *ctx);

  void exitPrint(swlParser::PrintContext *ctx);
  void exitAsk(swlParser::AskContext *ctx);

  void enterWhiledo(swlParser::WhiledoContext *ctx);
  void exitWdo(swlParser::WdoContext *ctx);
  void exitWhiledo(swlParser::WhiledoContext *ctx);

  void enterIfthenelse(swlParser::IfthenelseContext *ctx);
  void enterIthen(swlParser::IthenContext *ctx);
  void exitIelse(swlParser::IelseContext *ctx);
  void exitIfthenelse(swlParser::IfthenelseContext *ctx);

  void exitAdd(swlParser::AddContext *ctx);
  void exitMult(swlParser::MultContext *ctx);
  void exitSub(swlParser::SubContext *ctx);
  void exitDiv(swlParser::DivContext *ctx);

};
