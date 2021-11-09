#include <iostream>
using namespace std;
#define MAX 2147000000

int main() {
    int num;
    cin >> num;
    for(int i = 0; i<num; i++) {
        int answer = 0;
        int matrix_num;
        cin >> matrix_num;
        int matrix[101] = {0};
        for(int j = 0; j<matrix_num+1; j++){
            int n;
            cin >> n;
            matrix[j] = n;
        }
        int CMM[101][101] = {0};
        for(int j = 1; j<=matrix_num; j++)
            CMM[j][j] = 0;
        for(int k = 1; k<=matrix_num-1; k++) {
            for(int l = 1; l<=matrix_num-k; l++) {
                int t = l + k;
                CMM[l][t] = MAX;
                for(int m = l; m<t; m++) {
                    int temp = CMM[l][m] + CMM[m+1][t] + matrix[l-1]*matrix[m]*matrix[t];
                    if (temp < CMM[l][t])
                        CMM[l][t] = temp;
                }
            }
        }
        answer = CMM[1][matrix_num];
        cout << answer << endl;
    }
    return 0;
}