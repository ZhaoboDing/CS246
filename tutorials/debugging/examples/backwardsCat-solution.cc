#include <iostream>
#include <string>
#include <fstream>
#include <vector>

//Reverses s in range [start,finish)
//If std::string::npos is supplied to finish, use s.size() (i.e. reverse the entire string).
std::string reverse(std::string s, size_t start = 0, size_t finish = std::string::npos) {
  if (finish == std::string::npos) finish = s.size();
  std::string answer;
  //for (auto posn = finish - 1; posn >= start; --posn) {
  for (int posn = finish - 1; posn >= start && posn >= 0; --posn) {
  //In case the user gives us too big of a finish position
    if (posn < s.size()) {
      answer += s[posn];
    }
  }
  return answer;
}

void backwards_cat(std::istream &in) {
  std::vector<std::string> lines;
  std::string line;

  while (getline(in, line)) {
    lines.push_back(line);
  }

  while (!lines.empty()) {
    std::cout << reverse(lines.back()) << std::endl;
    lines.pop_back();
  }
}

int main(int argc, char **argv) {
  //A vector is just a dynamic array, similar
  //to IntArray from assignment 2.
  std::vector<std::string> files;

  for (int i=1; i<argc; ++i) {
    files.push_back(argv[i]);
  }

//Run "backwards cat" on each file,
//or on stdin if no files are supplied
  if (files.empty()) {
    std::cout << "Enter some text:" << std::endl;
    backwards_cat(std::cin);
  } else {
    for (const std::string &file : files) {
      std::ifstream ifs(file);

      backwards_cat(ifs);
    }
  }

  return 0;
}
