# include <iostream>
# include <string>
# include <cstdlib>
using namespace std;

int width = 25;

int main(int argc, char *argv[])
{
  if (argc >= 2)
    width = atoi(argv[1]);

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
