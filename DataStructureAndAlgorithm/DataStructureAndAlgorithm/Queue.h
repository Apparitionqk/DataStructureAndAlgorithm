//
//  Queue.h
//  DataStructureAndAlgorithm
//
//  Created by 123 on 2020/5/18.
//  Copyright © 2020 齐科. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

//队列相关操作
#include <stdio.h>
#include "Macros.h"

typedef int QElemType; /* QElemType 类型根据实际情况而定， 这里假设为int */

typedef struct {
    QElemType data[MAXSIZE_NodeList];
    int front; //!< 头指针
    int rear;   //!< 尾指针
}SqQueue; //!< 顺序队列


/// 队列初始化
/// @param q 需要初始化的队列
Status initQueue(SqQueue *q);


/// 清空队列
/// @param q 队列指针
Status clearQueue(SqQueue *q);


/// 是否为空队列
/// @param q 队列指针
Status isQueueEmpty(SqQueue q);


/// 队列长度
/// @param q 队列指针
int lengthOfQueue(SqQueue q);


/// 获取队列头结点
/// @param q 队列
/// @param e 头结点
Status getHead(SqQueue q, QElemType *e);


/// 将新元素插入队列队尾
/// @param q 队列指针
/// @param e 新元素
Status insertQueue(SqQueue *q, QElemType e);


/// 删除队列头结点
/// @param q 队列指针
/// @param e 头结点
Status deleteHeadOfQueue(SqQueue *q, QElemType *e);


/// 遍历打印队列
/// @param q 队列指针
Status queueTraverse(SqQueue q);
void testQueue();

/********  链式队列  ******/
typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
    QueuePtr front, rear; //!< 队头、队尾指针
}LinkQueue;

Status initLinkQueue(LinkQueue *Q);

Status destoryLinkQueue(LinkQueue *Q);

Status clearLinkQueue(LinkQueue *Q);

Status isLinkQueueEmpty(LinkQueue Q);

int lengthOfLinkQueue(LinkQueue Q);

Status insertLinkQueue(LinkQueue *Q, ElemType e);

Status deLinkQueue(LinkQueue *Q, QElemType *e);

Status getLinkQueueHead(LinkQueue Q, QElemType *e);

Status linkQueueTraverse(LinkQueue Q);

#endif /* Queue_h */
