#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 2147000000
 
int main(void)
{
    int num;
    cin >> num;
    for(int i = 0; i < num; i++) {
        int length, coin_num;
        cin >> length;
        cin >> coin_num;
        int coin[coin_num];
        for(int j = 0; j< coin_num; j++) {
            int n;
            cin >> n;
            coin[j] = n;
        }

        int dp[length+1];
        fill_n(dp, length+1, MAX);
        dp[0] = 0;
 
        for (int i = 0; i < coin_num; i++) {
            for (int j = coin[i]; j <= length; j++) {
                dp[j] = min(dp[j], dp[j - coin[i]] + 1);
            }
        }

        cout << dp[length] << endl;
    }
 
    return 0;
}
