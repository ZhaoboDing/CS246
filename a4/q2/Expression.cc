#include <iostream>
#include <string>
#include "Expression.h"

int absoluteValue(int x) {
  if (x > 0) return x; else return -x;
}
// Calculate the absolute value


Expression::~Expression() {}

Expression *Expression::clone() {
  return this;
}

std::string Expression::prettyprint() {
  return "";
}

void Expression::set(std::string, int) {}

void Expression::unset(std::string) {}

int Expression::evaluate() {
  return 0;
} // We return 0 for an empty expression


Unary::Unary(std::string opt, Expression *exp): opt{opt}, exp{exp} {}

Unary::~Unary() {
  delete exp;
}

Unary *Unary::clone() {
  return new Unary{opt, exp->clone()};
}

std::string Unary::prettyprint() {
  if (opt == "ABS")
    return "|" + exp->prettyprint() + "|";
  else if (opt == "NEG")
    return "-" + exp->prettyprint();
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

Binary *Binary::clone() {
  return new Binary{opt, Lexp->clone(), Rexp->clone()};
}

Binary::~Binary() {
  delete Lexp;
  delete Rexp;
}

std::string Binary::prettyprint() {
  return "(" + Lexp->prettyprint() + " " + opt +
         " " + Rexp->prettyprint() + ")";
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

Variable::~Variable() {}

Variable::Variable(std::string name, int val, bool def):
  name{name}, val{val}, def{def} {}

Variable *Variable::clone() {
  return new Variable{name, val, def};
}

std::string Variable::prettyprint() {
  if (def)
    return std::to_string(val);
  else
    return name;
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


Loneint::Loneint(int val): val{val} {}

Loneint::~Loneint() {}

Loneint *Loneint::clone() {
  return new Loneint{val};
}

std::string Loneint::prettyprint() {
  return std::to_string(val);
}

void Loneint::set(std::string, int) {}

void Loneint::unset(std::string) {}

int Loneint::evaluate() {
  return val;
}

