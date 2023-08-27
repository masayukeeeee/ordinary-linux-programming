#include <stdio.h>

void readInputWithScanf() {
    char x[2048];
    printf("Enter text: ");
    fgets(x, sizeof(x), stdin);
    printf("You entered: %s", x);
}

int main(){
    readInputWithScanf();
    return 0;
}
