#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
    for(int i = 0; i<num; i++) {
        string A, B;
        int answer = 0;
        cin >> A >> B;
        int LCS[101][101] = {0};

        for (int i = 1; i <= A.size(); i++) {
            for (int j = 1; j <= B.size(); j++) {

                if (A[i-1] == B[j-1]) { 
                    LCS[i][j] = LCS[i-1][j-1] + 1; 
                }
                else {
                    LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]); 
                }
            }
        }
        answer = LCS[A.size()][B.size()];
        cout << answer << endl;
    }
    return 0;
}