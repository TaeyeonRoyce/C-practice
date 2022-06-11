#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100
typedef int Data;

typedef struct _cQueue {
    int front;
    int rear;
    Data queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;

typedef int LData;

typedef struct _node {
    LData data;
    struct _node *next;
} Node;

typedef struct _linkedList {
    Node *head;
    Node *before;
    Node *cur;
    int numOfCount;
    int (*comp)(LData data1, LData data2);
} LinkedList;

typedef LinkedList List;


typedef struct _ual {
    int numV;
    int numE;
    List *adjList;
    int *visitInfo;
} ALGraph;

//LinkedList Section
void ListInit(List *plist) {
    plist->head = (Node *)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfCount = 0;
}

void FInsert(List *plist, LData data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head->next;
    plist->head->next = newNode;

    (plist->numOfCount)++;
}

void SInsert(List *plist, LData data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *pred = plist->head;

    newNode->data = data;

    while(pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
        pred = pred->next;
    }

    newNode->next = pred->next;
    pred->next = newNode;

    (plist->numOfCount)++;
}

void LInsert(List *plist, LData data) {
    if(plist->comp == NULL)
        FInsert(plist, data);
    else
        SInsert(plist, data);
}

int LFirst(List *plist, LData *pdata) {
    if(plist->head->next == NULL)
        return FALSE;
    plist->before = plist->head;
    plist->cur = plist->head->next;

    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List *plist, LData *pdata) {
    if(plist->cur->next == NULL)
        return FALSE;
    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}

LData LRemove(List *plist) {
    Node *rpos = plist->cur;
    LData rdata = rpos->data;

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    free(rpos);
    (plist->numOfCount)--;
    return rdata;
}

int LCount(List *plist) {
    return plist->numOfCount;
}

void SetSortRule(List *plist, int (*comp)(LData data1, LData data2)) {
    plist->comp = comp;
}

//Queue Section
void QueueInit(Queue *pq) {
    pq->front = 0;
    pq->rear = 0;
}

int	QIsEmpty(Queue *pq) {
    if(pq->front == pq->rear)
        return TRUE;
    else
        return FALSE;
}

int NextPosIdx(int pos) {
    if(pos == QUE_LEN - 1)
        return 0;
    else
        return pos + 1;
}

void Enqueue(Queue *pq, Data data) {
    if(NextPosIdx(pq->rear) == pq->front) {
        printf("Queue Memory Error!\n");
        exit(-1);
    }

    pq->rear = NextPosIdx(pq->rear);
    pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue *pq) {
    if(QIsEmpty(pq)) {
        printf("Queue Memory Error!\n");
        exit(-1);
    }

    pq->front = NextPosIdx(pq->front);

    return pq->queArr[pq->front];
}

Data QPeek(Queue *pq) {
    if(QIsEmpty(pq)) {
        printf("Queue Memory Error!\n");
        exit(-1);
    }

    return pq->queArr[NextPosIdx(pq->front)];
}


int WhoIsPrecede(int data1, int data2) {
    if(data1 > data2)
        return 1;
    else
        return 0;
}

void GraphInit(ALGraph *pg, int nv) {
    int i;

    pg->adjList = (List *)malloc(sizeof(List) * nv); //LinkedList 배열 생성
    pg->numV = nv;
    pg->numE = 0;

    for(i = 0; i < nv; i++) {
        ListInit(&(pg->adjList[i])); //LinkedList 배열 초기화
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
    }

    pg->visitInfo = (int *)malloc(sizeof(int) * pg->numV);
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV); //방문하지 않은 노드에 대해선 0으로 저장
}


//Deprecate
void GraphDestroy(ALGraph *pg) {
    if(pg->adjList != NULL)
        free(pg->adjList);

    if(pg->visitInfo != NULL)
        free(pg->visitInfo);
}

void AddEdge(ALGraph *pg, int fromV, int toV) {
    LInsert(&(pg->adjList[fromV - 1]), toV - 1);
    LInsert(&(pg->adjList[toV - 1]), fromV - 1);
    pg->numE += 1;
}


void ShowGraphEdgeInfo(ALGraph *pg) {
    int i;
    int vx;

    for(i = 0; i < pg->numV; i++) {
        printf("%d와 연결된 정점: ", i + 1);

        if(LFirst(&(pg->adjList[i]), &vx)) {
            printf("%d ", vx);

            while(LNext(&(pg->adjList[i]), &vx)) {
                printf("%d ", vx);
            }
            printf("\n");
        }
    }
}

int VisitVertex(ALGraph *pg, int visitV) {
    if(pg->visitInfo[visitV] == 0) {
        pg->visitInfo[visitV] = 1;
        return TRUE;
    }
    return FALSE;
}

void BFShowGraphVertex(ALGraph *pg, int startV) {
    Queue queue; //DFS랑 다르게 Stack이 아닌 Queue를 활용하여 진행 순서 보장
    //Queue의 FIFO 특징을 통해 BFS순서 구현
    int visitV = startV;
    int nextV;
    int cnt;
    cnt = 0;

    QueueInit(&queue); //진행 순서 담을 Queue init
    VisitVertex(pg, visitV);

    while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
        if(VisitVertex(pg, nextV) == TRUE) {
            Enqueue(&queue, nextV);
            cnt++;
        }

        while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
            if(VisitVertex(pg, nextV) == TRUE) {
                Enqueue(&queue, nextV);
                cnt++;
            }
        }

        if(QIsEmpty(&queue) == TRUE)
            break;
        else
            visitV = Dequeue(&queue);
    }
    printf("%d", cnt);
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

int main() {
    int computers;
    scanf("%d", &computers);

    int edges;
    scanf("%d", &edges);

    ALGraph graph;

    GraphInit(&graph, computers);
    for (int i = 0; i < edges; ++i) {
        int from, to;
        scanf("%d %d", &from, &to);
        AddEdge(&graph, from, to);
    }
    BFShowGraphVertex(&graph, 0);

    return 0;
}