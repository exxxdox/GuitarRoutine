#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *FindKey() {
    int key = rand() % 12 + 1;
//    printf("key is %d\n", key);
    char keys[] = "C D EF G A B";
    if (key == 1 || key == 3 || key == 5 || key == 6 || key == 8 || key == 10 || key == 12) {
        char a[2] = {' ', keys[key - 1]};
        char *b = a;
        return b;
    } else {
        char a[2] = {'b', keys[key]};
        char *b = a;
        return b;
    }
};

void ShowKey() {
    srand((unsigned int) time(NULL));
    char *key = FindKey();
    for (int i = 0; i < 2; i++) {
        if (key[i] != ' ') {
            printf("%c", key[i]);
        }
    }
    printf("\n");
}

int main() {
    ShowKey();
    getchar();
    return 0;
}
