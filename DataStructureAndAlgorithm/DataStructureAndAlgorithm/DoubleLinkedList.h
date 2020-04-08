//
//  DoubleLinkedList.h
//  DataStructureAndAlgorithm
//
//  Created by 123 on 2020/4/8.
//  Copyright © 2020 齐科. All rights reserved.
//

#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h

#include <stdio.h>
#include "Macros.h"
typedef struct DNode{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DNode;
typedef struct DNode *DLinkedList;

//创建双向链表
Status createDLinkedList(DLinkedList *L);

//删除双向链表指定位置元素
Status deleteDNode(DLinkedList *L, int index, ElemType *e);

//删除双向链表指定元素
Status deleteDNodeElem(DLinkedList *L, ElemType e);

//在双向链表中查找元素的位置
int selectElem(DLinkedList L,ElemType elem);

// 在双向链表中更新/修改结点
Status replaceElem(DLinkedList *L,int index,ElemType newElem);

void doubleLinkedTest(void);
#endif /* DoubleLinkedList_h */
