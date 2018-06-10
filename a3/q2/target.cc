#include <string>
#include "target.h"

Target::Target(const std::string &name, std::ostream &out) {
  filename = name;
  this->out = &out;
  lastModified = 0;
  childNum = 0;
}

bool Target::isLeaf() const {
  return childNum == 0;
}

void Target::addDepend(Target *d) {
  for (int i = 0; i < childNum; i++)
    if (childList[i] == d)
      return;

  if (childNum == 10)
    *out << "Max dependencies exceeded\n";
  else
    childList[childNum++] = d;
}

void Target::update(int time) {
  if (isLeaf()) {
    lastModified = time;
    *out << filename << " updated at time " << time << std::endl;
  }
  else
    *out << "Cannot update non-leaf object\n";
}

int Target::lastUpdated() const {
  return lastModified;
}

void Target::build() {
  int latest = lastModified;

  for (int i = 0; i < childNum; i++) {
    childList[i]->build();
    if (latest < childList[i]->lastModified)
      latest = childList[i]->lastModified;
  }

  if (latest > lastModified) {
    *out << "Building " << filename << std::endl;
    lastModified = latest;
  }
}
