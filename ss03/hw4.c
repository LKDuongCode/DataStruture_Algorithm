#include <stdio.h>
#include <stdlib.h>

void revert(char *str, int start, int end) {
    if (start >= end) {
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    revert(str, start + 1, end - 1);
}

int main() {
 	char *str = (char *)malloc(100 * sizeof(char)); 	
    if (str == NULL) {
        printf("cap phat that bai.\n");
        return 1;
    }

    printf("nhap chuoi can dao: ");
    fgets(str, 100, stdin); 
    
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    length--; 

 	revert(str, 0, length - 1);

    printf("%s", str);
    free(str);

    return 0;
}
