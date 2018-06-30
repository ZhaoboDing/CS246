#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>

class Expression {
public:
  virtual ~Expression();
  virtual std::string prettyprint();
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
  ~Unary();

  std::string prettyprint();
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
  ~Binary();

  std::string prettyprint();
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
  Variable(std::string name, int val, bool def);
  ~Variable();

  std::string prettyprint();
  void set(std::string name, int val);
  void unset(std::string name);
  int  evaluate();
};

class Loneint : public Expression {
private:
  int val;

public:
  Loneint(int val);
  ~Loneint();

  std::string prettyprint();
  void set(std::string name, int val);
  void unset(std::string name);
  int  evaluate();
};

#endif
