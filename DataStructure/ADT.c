#include <stdio.h>

/**
 * ADT(Abstract Data Type)
 * 추상 자료형은 구체적인 기능의 구현이 아닌,
 * 어떤 기능을 수행 하는 지 나열한 자료형
 */


typedef struct _wallet {
    int coin100Num;
    int bill5000Num;
} Wallet;

void PutMoney(Wallet* pw, int coinNum, int billNum);
int TakeOutMoney(Wallet* pw, int coinNum, int billNum);

//구체적인 PutMoney()와 TakeOutMoney()의 로직이 아닌
//이러한 기능 들이 있음을 열거.

int main() {

    Wallet wallet;

    PutMoney(&wallet, 5, 10);
    int outMoney = TakeOutMoney(&wallet, 2, 5);

    return 0;
}
