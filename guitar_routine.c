#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int KEY = 0;
int MODE = 0;
int ARPE = 0;

const int Ionian[] = {0, 2, 4, 5, 7, 9, 11};
const int Dorian[] = {0, 2, 3, 5, 7, 9, 10};
const int Phrygian[] = {0, 1, 3, 5, 7, 8, 10};
const int Lydian[] = {0, 2, 4, 6, 7, 9, 11};
const int Mixolydian[] = {0, 2, 4, 5, 7, 9, 10};
const int Aeolian[] = {0, 2, 3, 5, 7, 8, 10};
const int Locrian[] = {0, 1, 3, 5, 6, 8, 10};

int CheckDistance(int notea, int howa, int noteb, int howb) {
//    int level[] = {0, 2, 4, 5, 7, 9, 11};
    //
    int oria = notea + howa;
    int orib = noteb + howb;
    int distance = abs(oria - orib);
    return distance;
}

int FindHow(char a, char b) {
    int result = 0;
    if (a == ' ') {
        if (b == '#')
            result = -1;
        else if (b == 'b')
            result = 1;
    } else if (a == 'b')
        result = 2;
    else
        result = -2;
    return result;
}

char *GetNote(int num, int how) {
    //how
    //0 原;1 b;-1 #;
    num = num + 1;
    //记得free()
    char notes[] = "C D EF G A B";
    if (abs(how) < 2 && (num == 1 || num == 3 || num == 5 || num == 6 || num == 8 || num == 10 || num == 12)) {
        char a[3] = {' ', ' ', notes[num - 1], '\0'};

        char *b = malloc((strlen(a) + 1) * sizeof(char));
        strcpy(b, a);
        return b;
    } else {
        //用b表达
        char a[3] = {' ', 'b', notes[num], '\0'};
        //用#表达
        if (how == -1) {
            a[1] = '#';
            a[2] = notes[(num - 2 + 12) % 12];
        } else if (how == -2) {
            a[0] = '#';
            a[1] = '#';
            a[2] = notes[(num - 1 + 12) % 12];
        } else if (how == 2) {
            a[0] = 'b';
            a[1] = 'b';
            a[2] = notes[(num + 1 + 12) % 12];
        }

        char *b = malloc((strlen(a) + 1) * sizeof(char));
        strcpy(b, a);
        return b;
    }
}

void ShowNote(char *notes) {
    printf("%s", notes);
}

void ShowKey() {
    int key = rand() % 12;
    key = 6;
    KEY = key;
    char *charKey = GetNote(key, 1);
    ShowNote(charKey);
    free(charKey);
}

void ShowMode() {
    char a[7][15] = {"Ionian", "Dorian", "Phrygian", "Lydian", "Mixolydian", "Aeolian", "Locrian"};
    int num = rand() % 7;
    num = 1;
    MODE = num;
    char *x = a[num];
    printf("%s", x);
}

void ShowScaleDetail() {
    int s[7];
//    printf(" %d ", MODE);
    switch (MODE) {
        case 0:
            memcpy(s, Ionian, sizeof(Ionian));
            break;
        case 1:
            memcpy(s, Dorian, sizeof(Dorian));
            break;
        case 2:
            memcpy(s, Phrygian, sizeof(Phrygian));
            break;
        case 3:
            memcpy(s, Lydian, sizeof(Lydian));
            break;
        case 4:
            memcpy(s, Mixolydian, sizeof(Mixolydian));
            break;
        case 5:
            memcpy(s, Aeolian, sizeof(Aeolian));
            break;
        case 6:
            memcpy(s, Locrian, sizeof(Locrian));
            break;
    }

    int last[2];
    char *name = GetNote(KEY, 1);
    ShowNote(name);
    printf(" ");
    last[0] = FindHow(name[0], name[1]);
    last[1] = KEY;
    free(name);

    for (int i = 1; i < sizeof(s) / sizeof(int); i++) {
        int num = (KEY + s[i]) % 12;
        char *note;

        note = GetNote(num, 1);
        int h = FindHow(note[0], note[1]);
        int distance = CheckDistance(last[1], last[0], num, h);
        if (distance != 1 && distance != 2) {
            free(note);
            if (distance == 0) {
                note = GetNote(num, 2);
                h = 2;
            } else {
                note = GetNote(num, -1);
                h = -1;
            }
        }
        last[0] = h;
        last[1] = num;

        ShowNote(note);
        free(note);
        printf(" ");
    }
}


void ShowChord() {
    char a[4][15] = {"大七和弦", "小七和弦", "属七和弦", "半减七和弦"};
    int num = rand() % 4;
    char *x = a[num];
    printf("%s", x);
}

void ShowArpeggio() {
    char a[4][15] = {"大七和弦", "小七和弦", "属七和弦", "半减七和弦"};
    int num = rand() % 4;
    ARPE = num;
    char *x = a[num];
    printf("%s", x);
}

int main() {
    srand((unsigned int) time(NULL));

    printf("音阶练习: ");
    ShowKey();
    printf(" ");
    ShowMode();
    printf(" ");
    ShowScaleDetail();
    printf("\n");


    printf("和弦练习: ");
    ShowChord();
    printf("\n");
    printf("琶音练习: ");
    ShowArpeggio();
    printf("\n");

    //getchar();
    return 0;
}
