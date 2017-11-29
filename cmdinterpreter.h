#ifndef CMDINTERPRETER_H
#define CMDINTERPRETER_H

class CmdInterpreter : public Game {
public:
  void init();
  void input();
  void rename();
  void createMacro();
  void execute();
};

#endif
