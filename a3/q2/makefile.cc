#include <string>
#include <iostream>
#include "makefile.h"

Makefile::Makefile(std::ostream &out) {
  this->out = &out;
  fileNum = 0;
  sysClock = 0;
}

Makefile::~Makefile() {
  for (int i = 0; i < fileNum; i++)
    delete fileList[i];

  return;
}

Target *Makefile::getFileByName(const std::string &f, bool add) {
  for (int i = 0; i < fileNum; i++)
    if (fileList[i]->filename == f)
      return fileList[i];

  if (!add) return NULL;

  if (fileNum == 20) {
    *out << "Max targets exceeded\n";
    return NULL;
  }
  else {
    fileList[fileNum++] = new Target(f, *out);
    return fileList[fileNum - 1];
  }
}

void Makefile::addDepend(const std::string &t, const std::string &d) {
  Target *T = getFileByName(t, true);
  Target *D = getFileByName(d, true);

  if (T != NULL && D != NULL)
    T->addDepend(D);
}

void Makefile::changeTarget(const std::string &t) {
  Target *T = getFileByName(t);

  if (T) T->update(++sysClock);
}

void Makefile::rebuild(const std::string &t) {
  Target *T = getFileByName(t);

  if (T) T->build();
}
