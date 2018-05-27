# include <iostream>
# include <algorithm>
# include <cstdlib>
using namespace std;

int ans[11] = {0}, money[11] = {0};
int moneyNum = 0;
int aimMoney = 0;

int main(int argc, char *args[])
{
  aimMoney = atoi(args[argc - 1]);
  moneyNum = argc - 2;
  for (int i = 1; i < argc - 1; i++)
    money[i - 1] = atoi(args[i]);
  
  sort(money, money + moneyNum, greater<>());
  for (int i = 0; i < moneyNum; i++)
  {
    ans[i] = aimMoney / money[i];
    aimMoney %= money[i];
  }

  if (aimMoney)
    cout << "Impossible" << endl;
  else
    for (int i = 0; i < moneyNum; i++)
      if (ans[i])
        cout << ans[i] << " x " << money[i] << endl;

  return 0;
}
