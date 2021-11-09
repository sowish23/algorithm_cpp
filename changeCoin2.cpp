#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
 
int main(void)
{
    int num;
    cin >> num;
    for(int i = 0; i < num; i++) {
        int n, money, cost;
        int d[11][1001] = { 0 };
        cin >> money >> n;
        d[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> cost;
            for (int j = 0; j <= money; j++)
            {
                if (j < cost)
                    d[i][j] = d[i - 1][j];
                else
                    d[i][j] = d[i][j - cost] + d[i - 1][j];
            }
        }
        cout << d[n][money] << endl;
    }
 
    return 0;
}
