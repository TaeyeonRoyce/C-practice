#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "LinkedListStack.h"
#include "InfixToPostfix.h"

#define TRUE 1
#define FALSE 0

int IsInputValid(char userInput[]) {
    Stack bracketStack;
    StackInit(&bracketStack);
    int i;
    i = 0;
    while (userInput[i] != '\0') {
        char letter = userInput[i];
        if (letter == '\0') {
            break;
        }
        if (letter == '(' || letter ==')') {
            if (letter == '(') {
                SPush(&bracketStack, letter);
            } else {
                if (IsEmpty(&bracketStack)) {
                    return FALSE;
                }
                SPop(&bracketStack);
            }
        }
        i++;
    }

    if (IsEmpty(&bracketStack)) {
        return TRUE;
    }

    return 0;

}

int main() {
    char userInput[50];
    scanf("%s", userInput);

    if (IsInputValid(userInput) == 0) {
        printf("INVALID");
        return 0;
    }

    ConvToRPNExp(userInput);
    printf("%s", userInput);
    return 0;
}