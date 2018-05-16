#pragma once

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
  string logicTranslate(string raw);

public:

  void enterProgram(swlParser::ProgramContext *ctx);
  void exitProgram(swlParser::ProgramContext *ctx);

  void exitAssign(swlParser::AssignContext *ctx);

  void exitPrint(swlParser::PrintContext *ctx);

  void enterWhile(swlParser::WhileContext *ctx);
  void exitWhile(swlParser::WhileContext *ctx);

  void enterIf(swlParser::IfContext *ctx);
  void exitIf(swlParser::IfContext *ctx);

  void exitAdd(swlParser::AddContext *ctx);
  void exitMult(swlParser::MultContext *ctx);
  void exitSub(swlParser::SubContext *ctx);
  void exitDiv(swlParser::DivContext *ctx);
  void exitCondition(swlParser::ConditionContext *ctx);
  void exitVar(swlParser::VarContext *ctx);

};
