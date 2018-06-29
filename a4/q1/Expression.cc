#include <iostream>
#include <string>
#include "Expression.h"

int absoluteValue(int x) {
  if (x > 0) return x; else return -x;
}
// Calculate the absolute value

Expression::~Expression() {}

void Expression::prettyprint() {}

void Expression::set(std::string, int) {}

void Expression::unset(std::string) {}

int Expression::evaluate() {
  return 0;
}

Unary::Unary(std::string opt, Expression *exp): opt{opt}, exp{exp} {}

void Unary::prettyprint() {
  if (opt == "ABS") {
    std::cout << "|";
    exp->prettyprint();
    std::cout << "|";
  }
  else if (opt == "NEG") {
    std::cout << "-";
    exp->prettyprint();
  }
  else
    throw std::runtime_error("Unknown operateor: " + opt);
}

void Unary::set(std::string name, int val) {
  this->exp->set(name, val);
}

void Unary::unset(std::string name) {
  this->exp->unset(name);
}

int Unary::evaluate() {
  if (opt == "ABS")
    return absoluteValue(exp->evaluate());
  else if (opt == "NEG")
    return -exp->evaluate();
  else
    throw std::runtime_error("Unknown operateor: " + opt);
}

Binary::Binary(std::string opt, Expression *Lexp, Expression *Rexp):
  opt{opt}, Lexp{Lexp}, Rexp{Rexp} {}

void Binary::prettyprint() {
  std::cout << "(";
  Lexp->prettyprint();
  std::cout << " " << opt << " ";
  Rexp->prettyprint();
  std::cout << ")";
}

void Binary::set(std::string name, int val) {
  Lexp->set(name, val);
  Rexp->set(name, val);
}

void Binary::unset(std::string name) {
  Lexp->unset(name);
  Rexp->unset(name);
}

int Binary::evaluate() {
  int l = Lexp->evaluate();
  int r = Rexp->evaluate();

  if (opt == "+")
    return l + r;
  else if (opt == "-")
    return l - r;
  else if (opt == "*")
    return l * r;
  else if (opt == "/")
    if (r != 0)
      return l / r;
    else
      throw std::runtime_error("Divided by zero");
  else
    throw std::runtime_error("Unknown operator: " + opt);
}

Variable::Variable(std::string name): name{name}, val{0}, def{false} {}

Variable::Variable(std::string name, int val): name{name}, val{val}, def{true} {}

void Variable::prettyprint() {
  if (def)
    std::cout << val;
  else
    std::cout << name;
}

void Variable::set(std::string name, int val) {
  if (this->name == name) {
    def = true;
    this->val = val;
  }
}

void Variable::unset(std::string name) {
  if (this->name == name)
    def = false;
}

int Variable::evaluate() {
  if (def)
    return val;
  else {
    std::cout << name << " has no value." << std::endl;
    throw std::runtime_error("Variable not defined");
    return 0;
  }
}

Loneint::Loneint(int val) {
  this->val = val;
}

void Loneint::prettyprint() {
  std::cout << val;
}

void Loneint::set(std::string, int) {}

void Loneint::unset(std::string) {}

int Loneint::evaluate() {
  return val;
}

