#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>

class Expression {
public:
  virtual ~Expression() = 0;
  virtual void prettyprint();
  virtual void set(std::string, int);
  virtual void unset(std::string);
  virtual int  evaluate();
};

class Unary : public Expression {
private:
  std::string opt;
  Expression *exp;

public:
  Unary(std::string opt, Expression *exp);

  void prettyprint();
  void set(std::string name, int val);
  void unset(std::string name);
  int  evaluate();
};

class Binary : public Expression {
private:
  std::string opt;
  Expression *Lexp, *Rexp;

public:
  Binary(std::string opt, Expression *Lexp, Expression *Rexp);

  void prettyprint();
  void set(std::string name, int val);
  void unset(std::string name);
  int  evaluate();
};

class Variable : public Expression {
private:
  std::string name;
  int val;
  bool def;

public:
  Variable(std::string name);
  Variable(std::string name, int val);

  void prettyprint();
  void set(std::string name, int val);
  void unset(std::string name);
  int  evaluate();
};

class Loneint : public Expression {
private:
  int val;

public:
  Loneint(int val);

  void prettyprint();
  void set(std::string name, int val);
  void unset(std::string name);
  int  evaluate();
};

#endif
