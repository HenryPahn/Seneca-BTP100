#include <stdio.h>

int main() {
    
    char des1[] = {"CELL3048005191"};
    char des2[] = {"CELL3048005191"};
    char des3[] = ("HOME3048005191");
    char des4[] = ("TBA");
    char des5[] = ("WORK7934346809");
    
    char description[30];
    int dec; 
    for(int i = 0; ; i++) {
        dec = (int) des5[i];
        if (dec < 65 || dec > 90) {
            description[i] = '\0';
            break;
        }
        description[i] = des5[i];
    }
    printf("%s\n", description);
    return 0;
}