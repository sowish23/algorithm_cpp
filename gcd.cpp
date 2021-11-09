#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    else 
        return gcd(b, a%b);
}

int main() {
    int answer = gcd(1071, 1029);
    cout << answer << endl;
    return answer;
}