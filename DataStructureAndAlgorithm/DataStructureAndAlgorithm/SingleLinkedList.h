//
//  SingleLinkedList.h
//  DataStructureAndAlgorithm
//
//  Created by 齐科 on 2020/4/7.
//  Copyright © 2020 齐科. All rights reserved.
//

#ifndef SingleLinkedList_h
#define SingleLinkedList_h

#include <stdio.h>
#include "Macros.h"

/* 定义结点 */
typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;

typedef struct Node *LinkList;


/// 单向循环链表创建
/// @param L 链表指针
Status createList(LinkList *L);


#endif /* SingleLinkedList_h */
