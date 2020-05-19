//
//  Queue.c
//  DataStructureAndAlgorithm
//
//  Created by 123 on 2020/5/18.
//  Copyright © 2020 齐科. All rights reserved.
//

#include "Queue.h"

Status initQueue(SqQueue *q) {
    q->front = 0;
    q->rear = 0;
    return OK;
}

Status clearQueue(SqQueue *q) {
    q->front = q->rear = 0;
    return OK;
}

Status isQueueEmpty(SqQueue q) {
    if (q.front == q.rear) {
        return FALSE;
    }
    return TRUE;
}

int lengthOfQueue(SqQueue q) {
    return (q.rear - q.front + MAXSIZE_NodeList) % MAXSIZE_NodeList;
}

Status getHead(SqQueue q, QElemType *e) {
    if (q.front == q.rear) {
        return ERROR;
    }
    *e = q.data[q.front];
    return OK;
}

Status insertQueue(SqQueue *q, QElemType e) {
    
    if ((q->rear + 1)%MAXSIZE_NodeList == q->front) {
        //队列已满
        return ERROR;
    }
    
    //将元素e赋值给队尾
    q->data[q->rear] = e;
    
    //rear指针向后移动一位，若到最后则转到头结点
    q->rear = (q->rear + 1)%MAXSIZE_NodeList;
    return OK;
}

Status deleteHeadOfQueue(SqQueue *q, QElemType *e) {
    if (q->front == q->rear) {
        //如果队列为空，则返回错误
        return ERROR;
    }
    *e = q->data[q->front];
    
    //front指针向后移动一位，若到最后则转到数组头部
    q->front = (q->front + 1)%MAXSIZE_NodeList;
    return OK;
}

Status queueTraverse(SqQueue q) {
    int i;
    while ((i + q.front) != q.rear) {
        printf("%d ", q.data[i]);
        i = (i+1)%MAXSIZE_NodeList;
    }
    printf("\n");
    return OK;
}

void testQueue() {
    
    Status j;
    int i = 0, l;
    QElemType d;
    SqQueue q;
    
    initQueue(&q);
    printf("初始化队列后，队列是否为空：%s\n", isQueueEmpty(q) ? "是" : "否");
    
    while (i < 10) {
        insertQueue(&q, i);
        i ++;
    }
    queueTraverse(q);
    printf("队列长度为: %d\n", lengthOfQueue(q));
    printf("出队\n");
    
    deleteHeadOfQueue(&q, &d);
    queueTraverse(q);
    
    j = getHead(q, &d);
    if (j) {
        printf("现在队列头元素为: %d\n", d);
    }
    
    clearQueue(&q);
    printf("清空队列之后，队列是否为空： %s\n", isQueueEmpty(q) ? "是" : "否");
}
