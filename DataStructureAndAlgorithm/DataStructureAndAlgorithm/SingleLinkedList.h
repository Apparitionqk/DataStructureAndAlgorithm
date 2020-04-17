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

Status initList(LinkList *L);
/// 单向循环链表创建
/// @param L 链表指针
Status createList(LinkList *L);

/// 单向循环链表创建
/// @param L 链表指针
Status createList2(LinkList *L);

//遍历循环链表，循环链表的遍历最好用do while语句，因为头节点就有值
void displayList(LinkList L);

// 循环链表插入数据
Status listInsert(LinkList *L, int index, int num);

// 循环链表删除元素
Status linkListDelete(LinkList *L, int index);

//循环链表查询值
int findNodeIndex(LinkList L, int value);

//测试单向循环链表
void singleLinkedTest(void);
#endif /* SingleLinkedList_h */
