#include <stdio.h>

//
// Created by tang on 2023/5/8.
//
void ShowNote(char *notes) {
    printf("%s", notes);
}
char *GetNote() {
    static char a[] = {'a', 'b', '\0'};
    char *b = a;
    return  b;
}

int main() {
    char *a = GetNote();
    ShowNote(a);
    return 0;
}