#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char *str, int start, int end) {
    if (start >= end) {
        return 1;
    }
    if (str[start] != str[end]) {
        return 0; 
    }
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char *str = (char *)malloc(100 * sizeof(char)); 
    if (str == NULL) {
        printf("cap phat  bai.\n");
        return 1; 
    }

    printf("nhap chuoi: ");
    fgets(str, 100, stdin); 

    int length = strlen(str);

    if (isPalindrome(str, 0, length - 1)) {
        printf(" Palindrome valid.\n");
    } else {
        printf(" Palindrome invalid.\n");
    }

    free(str);
    return 0;
}
