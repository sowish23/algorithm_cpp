#include <iostream>
#include <vector>
using namespace std;
#define MAX 2147000000

int main() {
    int n;
    cin >> n;
    while(n--) {
        int length, cut_num;
        cin >> length;
        cin >> cut_num;

        int cut_array[1001] = { 0 };
        for(int i=2; i<=cut_num+1; i++) {
            int input;
            cin >> input;
            cut_array[i] = input;
        }
        cut_array[cut_num + 2] = length;

        int dp[102][1002] = { 0 };
        for (int i = 1; i <= cut_num+2; i++){
            dp[i][i] = 0;
        }
        for (int i = 2; i < cut_num+2; i++){
            for (int j = 1; j <= cut_num+2 - i; j++){
                dp[j][i + j] = MAX;
                for (int k = j; k < i + j; k++){
                    dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k][i + j] + cut_array[i+j] - cut_array[j]);
                }
            }
        }
        int answer = dp[1][cut_num+2];
        cout << answer << endl;

    }
    return 0;
}