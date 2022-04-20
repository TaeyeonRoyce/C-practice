#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "../LinkedListStack/LinkedListStack.h"

int main() {
    int N;
    scanf("%d", &N);

    Stack userInputNumStack;
    StackInit(&userInputNumStack);
    int num;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &num);
        SPush(&userInputNumStack, num);
    }

    Stack cmpStack;
    Stack ansStack;
    Stack tempStack;
    StackInit(&tempStack);
    StackInit(&cmpStack);
    StackInit(&ansStack);
    Data initNum = SPop(&userInputNumStack);
    SPush(&cmpStack, initNum);
    SPush(&ansStack, -1);

    int max = initNum;
    while (!IsEmpty(&userInputNumStack)) {
        Data num = SPop(&userInputNumStack);
        if (num > max) {
            SPush(&ansStack, -1);
            max = num;
        } else {
            while(1) {
                Data cmpNum = SPop(&cmpStack);
                SPush(&tempStack, cmpNum);
                if (cmpNum > num) {
                    SPush(&ansStack, cmpNum);
                    break;
                }
            }
            while (!IsEmpty(&tempStack)) {
                SPush(&cmpStack, SPop(&tempStack));
            }
        }

        SPush(&cmpStack, num);
    }

    while(!IsEmpty(&ansStack)) {
        printf("%d ", SPop(&ansStack));
    }


}
