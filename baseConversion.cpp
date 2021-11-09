#include <iostream>
using namespace std;

void baseConversion(int num, int base) {
    static baseTable[] = "0123456789abcdef";
    if(num>=base) baseConversion(num/base, base);
    printf("%c\n", baseTable[num%base]);

}

int main() {
    int num = 1234567;
    baseConversion(num, 16);
    return 0;
}