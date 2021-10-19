#include <iostream>
using namespace std;

int check(char line[], int first, int last) {
    if(line[first] != line[last]) return 0;
    else if(first >= last) return 1;
    else return check(line, first+1, last-1);
}

int main() {
    char line[256] = "malayalam";
    printf("%d \n", check(line, 0, strlen(line) -1));
    return 0;
}