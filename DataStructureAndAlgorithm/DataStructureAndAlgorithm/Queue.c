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

/********* 链式队列  ***********/

Status initLinkQueue(LinkQueue *Q) {
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    
    //判断是否创建新结点成功与否
    if (!Q->front) {
        return ERROR;
    }
    
    //头结点指针域置空
    Q->front->next = NULL;
    return OK;
}

Status destoryLinkQueue(LinkQueue *Q) {
    while (Q->front) {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}

Status clearLinkQueue(LinkQueue *Q) {
    QueuePtr p, q;
    Q->front = Q->rear;
    p = Q->front->next;
    Q->front->next = NULL;
    
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    return OK;
}

Status isLinkQueueEmpty(LinkQueue Q) {
    if (Q.front == Q.rear) {
        return TRUE;
    }
    return FALSE;
}

int lengthOfLinkQueue(LinkQueue Q) {
    int i = 0;
    QueuePtr p;
    p = Q.front;
    while (Q.rear != p) {
        i++;
        p = p->next;
    }
    return i;
}

Status insertLinkQueue(LinkQueue *Q, ElemType e) {
    //为入队元素分配结点空间,用指针s指向;
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    
    //判断是否分配成功
    if (!s) {
        return ERROR;
    }
    
    s->data = e;
    s->next = NULL;
    
    Q->rear->next = s;
    
    Q->rear = s;
    return OK;
}

Status deLinkQueue(LinkQueue *Q, QElemType *e) {
    QueuePtr p;
      
      //判断队列是否为空;
      if (Q->front == Q->rear) {
          return ERROR;
      }
      
      //将要删除的队头结点暂时存储在p
      p = Q->front->next;
      
      //将要删除的队头结点的值赋值给e
      *e = p->data;
      
      //将原队列头结点的后继p->next 赋值给头结点后继
      Q->front->next = p ->next;
      
      //若队头就是队尾,则删除后将rear指向头结点.
      if(Q->rear == p) Q->rear = Q->front;
      
      free(p);
      
      return OK;
}

Status getLinkQueueHead(LinkQueue Q, QElemType *e) {
    //队列非空
       if (Q.front != Q.rear) {
           //返回队头元素的值,队头指针不变
           *e =  Q.front->next->data;
           return TRUE;
       }
       
       return  FALSE;
}

Status linkQueueTraverse(LinkQueue Q) {
    
    QueuePtr p;
    p = Q.front->next;
    while (p) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}


void testLinkQueue() {
    // insert code here...
    printf("链队列的表示与操作!\n");
    
    Status iStatus;
    QElemType d;
    LinkQueue q;
    
    //1.初始化队列q
    iStatus = initLinkQueue(&q);
    
    //2. 判断是否创建成
    if (iStatus) {
        printf("成功地构造了一个空队列\n");
    }
    
    //3.判断队列是否为空
    printf("是否为空队列?%d (1:是 0:否)\n",isLinkQueueEmpty(q));
    
    //4.获取队列的长度
    printf("队列的长度为%d\n",isLinkQueueEmpty(q));
    
    //5.插入元素到队列中
    insertLinkQueue(&q, -3);
    insertLinkQueue(&q, 6);
    insertLinkQueue(&q, 12);
    
    printf("队列的长度为%d\n",lengthOfLinkQueue(q));
    printf("是否为空队列?%d (1:是 0:否)\n",lengthOfLinkQueue(q));
    
    //6.遍历队列
    printf("队列中的元素如下:\n");
    linkQueueTraverse(q);

    //7.获取队列头元素
    iStatus = getLinkQueueHead(q, &d);
    if (iStatus == OK) {
        printf("队头元素是:%d\n",d);
    }
    
    //8.删除队头元素
    iStatus =deLinkQueue(&q, &d);
    if (iStatus == OK) {
        printf("删除了的队头元素为:%d\n",d);
    }
    
    //9.获取队头元素
    iStatus = getLinkQueueHead(q, &d);
    if (iStatus == OK) {
        printf("新的队头元素为:%d\n",d);
    }
    
    //10.清空队列
    clearLinkQueue(&q);
    
    //11.销毁队列
    destoryLinkQueue(&q);
}

