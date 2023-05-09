#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int KEY = 0;
char KEYNAME[3];
int MODE = 0;
int ARPE = 0;

const char NAME[] = "ABCDEFG";

const int Ionian[] = {0, 2, 4, 5, 7, 9, 11};
const int Dorian[] = {0, 2, 3, 5, 7, 9, 10};
const int Phrygian[] = {0, 1, 3, 5, 7, 8, 10};
const int Lydian[] = {0, 2, 4, 6, 7, 9, 11};
const int Mixolydian[] = {0, 2, 4, 5, 7, 9, 10};
const int Aeolian[] = {0, 2, 3, 5, 7, 8, 10};
const int Locrian[] = {0, 1, 3, 5, 6, 8, 10};

int FindOff(char input) {
    return (int) (input - 'A');
}

int GetANote(char input) {
    char notes[] = "C D EF G A B";
    for (int i = 0; i < 12; i++) {
        if (input == notes[i])
            return i;
    }
}

int FindDistance(int a, int b) {
    if (abs(a - b) > 2)
        return a - b - 12;
    else
        return a - b;
}

char *GetNoteForKey(int num) {
    //º«µ√free()
    char notes[] = "C D EF G A B";
    if (num == 0 || num == 2 || num == 4 || num == 5 || num == 7 || num == 9 || num == 11) {
        char a[] = {' ', ' ', notes[num], '\0'};

        char *b = malloc((strlen(a) + 1) * sizeof(char));
        strcpy(b, a);
        return b;
    } else {
        //”√b±Ì¥Ô
        char a[] = {' ', 'b', notes[num + 1], '\0'};
        char *b = malloc((strlen(a) + 1) * sizeof(char));
        strcpy(b, a);
        return b;
    }
}

void ShowNote(char *notes) {
//    printf("%s", notes);
    for (char *i = notes; *i != '\0'; i++) {
        if (*i != ' ')
            printf("%c", *i);
    }
}

void ShowKey() {
    int key = rand() % 12;
//    key = 3;
    KEY = key;
//    printf("%d", key);

    char *charKey = GetNoteForKey(key);

    ShowNote(charKey);
    strcpy(KEYNAME, charKey);

    free(charKey);
}

void ShowMode() {
    char a[7][15] = {"Ionian", "Dorian", "Phrygian", "Lydian", "Mixolydian", "Aeolian", "Locrian"};
    int num = rand() % 7;
//    num = 1;
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


    int scaleSize = sizeof(s) / sizeof(int);
//    int scale[scaleSize];

    ShowNote(KEYNAME);
    printf(" ");

    int oldNum = KEY;
    int noteOff = FindOff(KEYNAME[2]);
    for (int i = 1; i < scaleSize; i++) {
        int num = (KEY + s[i]) % 12;

        noteOff = (noteOff + 1) % 7;
        char note[] = {' ', ' ', NAME[noteOff], '\0'};
        int adjust = FindDistance(num, GetANote(NAME[noteOff]));
        switch (adjust) {
            case -1:
                note[1] = 'b';
                break;
            case -2:
                note[0] = 'b';
                note[1] = 'b';
                break;
            case 1:
                note[1] = '#';
                break;
            case 2:
                note[0] = '#';
                note[1] = '#';
                break;
            default:
                break;
        }

        ShowNote(note);

        printf(" ");
    }
}


void ShowChord() {
    char a[4][15] = {"¥Û∆ﬂ∫Õœ“", "–°∆ﬂ∫Õœ“", " Ù∆ﬂ∫Õœ“", "∞Îºı∆ﬂ∫Õœ“"};
    int num = rand() % 4;
    char *x = a[num];
    printf("%s", x);
}

void ShowArpeggio() {
    char a[4][15] = {"¥Û∆ﬂ∫Õœ“", "–°∆ﬂ∫Õœ“", " Ù∆ﬂ∫Õœ“", "∞Îºı∆ﬂ∫Õœ“"};
    int num = rand() % 4;
    ARPE = num;
    char *x = a[num];
    printf("%s", x);
}

int main() {
    srand((unsigned int) time(NULL));

    printf("“ÙΩ◊¡∑œ∞: ");
    ShowKey();
    printf(" ");
    ShowMode();
    printf(" ");
    ShowScaleDetail();
    printf("\n");

    printf("∫Õœ“¡∑œ∞: ");
    ShowChord();
    printf("\n");
    printf("≈√“Ù¡∑œ∞: ");
    ShowArpeggio();
    printf("\n");

    getchar();
    return 0;
}
