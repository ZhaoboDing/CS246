# include <iostream>
# include <string>
# include <fstream>
using namespace std;

int width = 25;
string dictFile = "";

bool isNumber(char *str)
{
  for (char *p = str; *p; p++)
    if (*p > '9' || *p < '0')
      return false;

  return true;
}

int atoi(char *str)
{
  int ans = 0;

  for (char *p = str; *p; p++)
    if (*p >= '0' && *p <= '9')
      ans = ans * 10 + *p - '0';
    else
      return -1;

  return ans;
}

int separablePos(string str)
{
  ifstream fin;
  string word;
  int pos;

  fin.open(dictFile);
  while (fin >> word >> pos)
    if (word == str) return pos;

  fin.close();
  return str.length();
}

int main(int argc, char *argv[])
{
  if (argc >= 3)
  {
    width = atoi(argv[1]);
    dictFile = argv[2];
  }
  else if (argc == 2)
    if (isNumber(argv[1]))
      width = atoi(argv[1]);
    else
      dictFile = argv[1];

  string word, newLine = "";
  int wordLen, newLineLen = 0;

  while (cin >> word)
  {
    wordLen = word.length();
    if (newLineLen)
      if (newLineLen + 1 + wordLen <= width)
      {
        newLineLen += wordLen + 1;
        newLine += " " + word;
        continue;
      }
      else
      {
        int partialLen = separablePos(word);
        if (newLineLen + 1 + partialLen + 1 <= width)
        {
          newLine += " " + word.substr(0, partialLen) + "-";
          word = word.substr(partialLen);
          wordLen -= partialLen;
        }

        cout << newLine << endl;
        newLine = "";
        newLineLen = 0;
      }

    if (wordLen <= width)
    {
      newLine = word;
      newLineLen = wordLen;
    }
    else
    {
      while (wordLen > width)
      {
        cout << word.substr(0, width) << endl;
        word = word.substr(width);
        wordLen -= width;
      }

      newLine = word;
      newLineLen = wordLen;
    }
  }

  if (newLineLen)
    cout << newLine << endl;

  return 0;
}
