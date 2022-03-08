#include <stdio.h>
#include <stdlib.h>
#include "NameCard/NameCard.h"
#include "NameCard/ArrayList.h"

/**
 * 리스트 활용
 * NameCard.h가 주어짐 -> 기능에 맞게 NameCard.c 구현
 * 요구 사항
 * 1. 총 3명의 전화번호 정보를 리스트에 저장한다.
 *    특정 이름으로 대상을 탐색 할 수 있다.
 *    탐색한 대상에 대하여
 * 2. 정보 출력
 * 3. 전화번호 변경
 * 4. 정보 삭제
 * 5. 리스트의 정보를 출력한다.
*/

int main() {
    List nameCards;
    NameCard *nameCard;

    ListInit(&nameCards);

    //1.
    nameCard = MakeNameCard("Royce", "010-1244-6390");
    LInsert(&nameCards, nameCard);

    nameCard = MakeNameCard("Kongstar", "010-1993-2259");
    LInsert(&nameCards, nameCard);

    nameCard = MakeNameCard("Noah", "010-7466-3906");
    LInsert(&nameCards, nameCard);

    //2.
    char *findName;
    findName = "Kongstar";

    if (LFirst(&nameCards, &nameCard)) {
        if (!NameCompare(nameCard, findName)) {
            ShowNameCardInfo(nameCard);
        } else {
            while (LNext(&nameCards, &nameCard)) {
                if (!NameCompare(nameCard, findName)) {
                    ShowNameCardInfo(nameCard);
                    break;
                }
            }
        }
    }

    //3. change "Kongstar" Phone number
    char *changePhone;
    changePhone = "010-0000-0000";

    if (LFirst(&nameCards, &nameCard)) {
        if (!NameCompare(nameCard, findName)) {
            ChangePhoneNum(nameCard, changePhone);
        } else {
            while (LNext(&nameCards, &nameCard)) {
                if (!NameCompare(nameCard, findName)) {
                    ChangePhoneNum(nameCard, changePhone);
                    break;
                }
            }
        }
    }

    printf("\n");

    //4.
    char *removeName;
    removeName = "Noah";
    if (LFirst(&nameCards, &nameCard)) {
        if (!NameCompare(nameCard, removeName)) {
            nameCard = LRemove(&nameCards);
            free(nameCard);
        } else {
            while (LNext(&nameCards, &nameCard)) {
                if (!NameCompare(nameCard, removeName)) {
                    nameCard = LRemove(&nameCards);
                    free(nameCard);
                    break;
                }
            }
        }
    }

    //5.
    if (LFirst(&nameCards, &nameCard)) {
        ShowNameCardInfo(nameCard);

        while (LNext(&nameCards, &nameCard)) {
            ShowNameCardInfo(nameCard);
        }
    }
    return 0;

}

