#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void fun1(char* str) {
	int i;
    for ( i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}
void fun2(const char* word) {
     const int L = strlen(word);
    char y[L + 1]; 
    int a = 3;
    
    while (a > 0) {
        printf("\nAttempts: %d left\n",a);
        printf("your guess: ",L);
        scanf("%s", y);

        fun1(y);

        if (strcmp(y, word) == 0) {
            printf("\nYou win!\n the word was:%s\n",word);
            return;
        } else {
            printf("RESULT:\n");
           int i;
            char result[L + 1];
            for ( i = 0; i < L; i++) {
                if (y[i] == word[i]) {
                    result[i] = toupper(word[i]);
                } else if (strchr(word, y[i]) != NULL) {
                    result[i] = tolower(y[i]);
                } else {
                    result[i] = '_';
                }
            }
            result[L] = '\0';
            printf("%s\n", result);
            a--;
        }
    }
    printf("\n out of attempts. You lose!\n the word was:%s\n",word);
} int main() {
    const char* str[] = {"GROUP", "CHAIR", "TABLE", "STORE", "HANDS"};
    const int num = sizeof(str) / sizeof(str[0]);
    srand(time(NULL));
    int x = rand() % num;
    const char* word = str[x];
    int m;

    do {
        printf("Welcome to Comple \n");
        int c;
        printf("Choose a word 1-5:");
        scanf("%d", &c);
        if (c >= 1 && c <= num) {
            printf("\nword has been selected\n");
            fun2(word);
        } else {
            printf("\nInvalid choice  try again\n");
        }
        printf("would you lyk to play again? 1- YES : 0-NO: ");
        scanf("%d", &m);
        printf("\n");
    } while (m == 1 );
    printf("Thanks for playing \n");

    return 0;
}
