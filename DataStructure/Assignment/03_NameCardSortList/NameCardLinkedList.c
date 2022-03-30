#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"
#include "DLinkedList.h"

/*
 * 리스트 활용의 이해와 수정
 * 요구 사항
 * 1. 저장할 명함 항목 입력
 * 2. 저장된 리스트에서 특정인 정보 출력
 * 3. 저장된 리스트에서 특정인 전화번호 변경
 * 4. 저장된 리스트에서 특정인 정보 삭제
 * 5. 저장된 명함 정보 출력
 * 6. 프로그램 종료
*/

int sortWay(LData name1, LData name2) {
    //명함의 이름 오름차순
    //ex)   strcmp(Royce, Kongstar)
    //      return 0
    return strcmp(name1->name, name2->name);
}

int main() {
    List nameCards;
    NameCard *nameCard;

    ListInit(&nameCards);

    int status;
    char *nameCardName;
    char *phoneNum;

    SetSortRule(&nameCards, sortWay);

    //입력 받지 않는 3, 4번의 요구사항을 충족하기 위한 기본 데이터 추가
    //3번(전화번호 변경) 데이터
    nameCard = MakeNameCard("Kongstar", "010-8999-1234");
    LInsert(&nameCards, nameCard);
    //4번(특정인 정보 삭제) 데이터
    nameCard = MakeNameCard("Royce", "010-2241-4348");
    LInsert(&nameCards, nameCard);

    //1.저장할 명함 항목 입력
    //0을 입력 하면 종료
    while (1) {
        printf("명함의 이름을 입력해 주세요 : ");
        scanf("%s", &nameCardName);
        getchar();
        printf("전화번호를 입력해 주세요 : ");
        scanf("%s", &phoneNum);
        getchar();

        nameCard = MakeNameCard(&nameCardName, &phoneNum);
        LInsert(&nameCards, nameCard);

        printf("저장 완료!\n");
        printf("추가로 입력 하시려면 1, 모두 입력 하셨다면 0을 입력 해주세요 : ");


        scanf("%d", &status);
        if (status != 1) {
            printf("===================== 입력 종료 ======================\n\n\n");
            break;
        }
    }

    //2. 특정인 정보 출력
    char *findName;
    findName = "Royce";
    printf("이름이 %s인 사람의 NameCard 정보\n", findName);

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
    printf("\n\n");

    //3. 특정인 전화번호 변경
    //"Kongstar"의 전화번호를 changePhone으로 변경
    char *changeName;
    char *changePhone;
    changeName = "Kongstar";
    changePhone = "010-0000-0000";

    if (LFirst(&nameCards, &nameCard)) {
        if (!NameCompare(nameCard, changeName)) {
            printf("%s의 전화번호를 변경하였습니다\n", changeName);
            printf("[%s] -> [%s]\n\n\n", nameCard->phone, changePhone);
            ChangePhoneNum(nameCard, changePhone);
        } else {
            while (LNext(&nameCards, &nameCard)) {
                if (!NameCompare(nameCard, changeName)) {
                    printf("%s의 전화번호를 변경하였습니다\n", changeName);
                    printf("[%s] -> [%s]\n\n", nameCard->phone, changePhone);
                    ChangePhoneNum(nameCard, changePhone);
                    break;
                }
            }
        }
    }
    printf("\n");

    //4. "Royce"의 정보 삭제
    char *removeName;
    removeName = "Royce";
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

    printf("%s의 정보가 삭제되었습니다\n\n\n", removeName);

    //5. 저장되어 있는 명함 정보 출력
    printf("=================== 명함 목록 출력 ====================\n");
    if (LFirst(&nameCards, &nameCard)) {
        ShowNameCardInfo(nameCard);

        while (LNext(&nameCards, &nameCard)) {
            ShowNameCardInfo(nameCard);
        }
    }

    return 0;

}

