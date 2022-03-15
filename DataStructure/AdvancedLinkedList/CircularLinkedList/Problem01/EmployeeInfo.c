#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircularLinkedList.h"
#include "EmployeeInfo.h"

/**
 * 문제 요구 사항
 * 1. 사번과 이름을 저장할 수 있는 직원정보 구조체 정의
 * 2. 직원의 이름과 숫자를 이용하여 당직자 알아내기
 *    ex) 직원 A, B, C가 있다면, 당직은 A B C A B C ...으로 돌아감
 * 직원의 정보나 숫자는 임의로 생성할 것.
 */

/**
 * To Run this Source,
 * copy following texts and paste to CMakeLists.txt

   add_executable(
        DataStructure
        AdvancedLinkedList/CircularLinkedList/Problem01/EmployeeInfo.c
        AdvancedLinkedList/CircularLinkedList/Problem01/EmployeeInfo.h
        AdvancedLinkedList/CircularLinkedList/Problem01/CircularLinkedList.c
        AdvancedLinkedList/CircularLinkedList/Problem01/CircularLinkedList.h
    )

 */

//name인 사람이 당직을 선 뒤, day가 지난 뒤 누가 당직을 서는가?
char *getTurnAfterDay(List *plist, char *name, int day) {
    Employee *ret;
    int num;

    //시작점 찾기
    num = LCount(plist);
    LFirst(plist, &ret);
    //맨 처음 사람이 아니면
    if (strcmp(ret->name, name) != 0) {
        for (int i = 0; i < num - 1; i++) {
            //다음 사람 조회
            LNext(plist, &ret);
            if (strcmp(ret->name, name) == 0) {
                break;
            }

            //조회 실패!
            if (i >= num - 1) {
                return NULL;
            }
        }
    }

    for (int i = 0; i < day; i++) {
        LNext(plist, &ret);
    }

    return ret->name;

}


int main() {
    Employee *empl;

    CList list;
    ListInit(&list);

    empl = (Employee *) malloc(sizeof(Employee));
    empl->num = 1111;
    strcpy(empl->name, "Royce");
    LInsert(&list, empl);

    empl = (Employee *) malloc(sizeof(Employee));
    empl->num = 2222;
    strcpy(empl->name, "Tae");
    LInsert(&list, empl);


    empl = (Employee *) malloc(sizeof(Employee));
    empl->num = 3333;
    strcpy(empl->name, "Noah");
    LInsert(&list, empl);


    empl = (Employee *) malloc(sizeof(Employee));
    empl->num = 4444;
    strcpy(empl->name, "Kongstar");
    LInsert(&list, empl);

    //Royce뒤로 8일뒤 당직은 누구?
    char *afterRoyceName = getTurnAfterDay(&list, "Royce", 8);

    //Kongstar 11일뒤 당직은 누구?
    char *afterKongstarName = getTurnAfterDay(&list, "Kongstar", 11);

    printf("Employee name: %s\n", afterRoyceName); //Royce (8 % 4 == 0)
    printf("Employee name: %s", afterKongstarName); //Noah (11 & 4 == 3)
    return 0;
}