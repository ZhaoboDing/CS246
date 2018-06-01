# include <iostream>
using namespace std;

int ans[11] = {0}, money[11] = {0};
int moneyNum = 0;
int aimMoney = 0;

void swap(int &a, int &b)
{
  int t = a;
  a = b;
  b = t;
}

void sort(int l, int r)
{
  int i = l, j = r, x = money[l];

  while (i <= j)
  {
    while (money[i] > x) i++;
    while (money[j] < x) j--;
    if (i <= j)
    {
      swap(money[i], money[j]);
      i++;
      j--;
    }
  }

  if (i < r) sort(i, r);
  if (j > l) sort(l, j);
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

int main(int argc, char *args[])
{
  if (argc <= 2)
  {
    cout << "Usage: change [denominations] [amount]" << endl;
    return 0;
  }

  aimMoney = atoi(args[argc - 1]);
  moneyNum = argc - 2;
  for (int i = 1; i < argc - 1; i++)
    money[i - 1] = atoi(args[i]);
  
  sort(0, moneyNum - 1);
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
