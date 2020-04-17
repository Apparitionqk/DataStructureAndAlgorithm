//
//  SingleLinkedList.c
//  DataStructureAndAlgorithm
//
//  Created by 齐科 on 2020/4/7.
//  Copyright © 2020 齐科. All rights reserved.
//

#include "SingleLinkedList.h"

Status initList(LinkList *L) {
    *L = (LinkList)malloc(sizeof(Node));
    if (!*L){
        printf("初始化失败");
        return ERROR;
    }
    (*L)->next = NULL;
    return OK;
}
/*
循环链表创建!
2种情况:① 第一次开始创建; ②已经创建,往里面新增数据

1. 判断是否第一次创建链表
   YES->创建一个新结点,并使得新结点的next 指向自身; (*L)->next = (*L);
   NO-> 找链表尾结点,将尾结点的next = 新结点. 新结点的next = (*L);
*/
Status createList(LinkList *L) {
    int item;
    LinkList temp = NULL;
    LinkList target = NULL;
    printf("输入结点的值，输入0结束\n");
    while (1) {
        scanf("%d", &item);
        if (item == 0) break;
        
        //如果输入的链表是空，则创建一个新的结点，使其next指针指向自己
        if (*L == NULL) {
            *L = (LinkList)malloc(sizeof(Node));
            if (!L) exit(0);
            (*L)->data = item;
            (*L)->next = *L; //(*head)->next = *head
        }else {
            //输入的链表不是空的，寻找链表的尾结点，使尾结点的next=新结点。新结点的next指针指向头结点
            for (target = *L; target->next != *L; target = target->next);
            temp = (LinkList)malloc(sizeof(Node));
            if (!temp)return ERROR;
            temp->data = item;
            temp->next = *L;//新结点指向头结点
            target->next = temp;//尾结点指向新结点
        }
    }
    return OK;
}

//添加临时变量(指针)，用来保存尾结点，可以避免循环遍历查找尾结点
Status createList2(LinkList *L) {
    int item;
    LinkList temp = NULL;
    LinkList r = NULL;
    printf("输入新的结点，输入0时结束\n");
    while (1) {
        scanf("%d", &item);
        if (item == 0) break;
        //第一次创建
        if (*L == NULL) {
            *L = (LinkList)malloc(sizeof(Node));
            if (! *L) return ERROR;
            (*L)->data = item;
            (*L)->next = *L;
            r = *L;//插入第一个元素，用r指针记录位置
        }else {
            temp = (LinkList)malloc(sizeof(Node));
            if (!temp) return ERROR;
            temp->data = item;
            temp->next = *L;
            //每插入一个新的元素，使r指针指向尾结点
            r->next = temp;
            r = temp;
        }
    }
    return OK;
}
//遍历循环链表，循环链表的遍历最好用do while语句，因为头节点就有值
void displayList(LinkList L) {
    //如果链表是空
    if (L == NULL) {
        printf("打印的链表为空!\n");
        return;
    }
    LinkList temp;
    temp = L;
    do {
        printf("%5d", temp->data);
        temp = temp->next;
    } while (temp != L);
    printf("\n");
}
// 循环链表插入数据
Status listInsert(LinkList *L, int index, int num) {
    LinkList temp, target;
    int i;
    //创建新结点temp，并判断是否创建成功，成功则赋值，否则返回ERROR
    temp = (LinkList)malloc(sizeof(Node));
    if (temp == NULL) return ERROR;
    temp->data = num;
    if (index == 1) {
        /*
          如果插入的位置位1，则属于插入首元结点， 所以需要特殊处理
          1. 找到链表最后的结点--尾结点
         2. 让新结点的next指向头结点
         3. 尾结点的next指向新结点
         4. 头指针指向temp
         */
        
        for (target = *L; target->next != *L; target = target->next);
        temp->next = *L;
        target->next = temp;
        *L = temp;
    }else {
        /*
          如果插入的位置在其他位置
         1. 先找到插入位置，如果超过链表长度，则自动插入队尾
         2. 通过target找到要插入位置的前一个结点， 让target->next = temp
         3. 插入结点的前驱指向新结点，新结点的next指向target原来的next位置
         */
        for (i = 1, target = *L; target->next != *L && i != index-1; target = target->next, i++);
        temp->next = target->next;
        target->next = temp;
    }
    return OK;
}
// 循环链表删除元素
Status linkListDelete(LinkList *L, int index) {
    LinkList temp, target;
    int i;
    //temp指向链表首元结点
    temp = *L;
    if (temp == NULL) return ERROR;
    if (index == 1) {
        //①如果删除到只剩下首元结点了，则直接将*L置空
        if ((*L)->next == (*L)) {
            (*L) = NULL;
            return OK;
        }
        //② 链表还有很多数据，但是删除的是首结点
        //找到尾结点，使得尾结点的next指向头结点的下一个结点 target->next = (*L)->next
        //新结点作为头结点，则释放原来的头结点
        for (target = *L; target->next != *L; target = target->next);
        temp = *L;
        *L = (*L)->next;
        target->next = *L;
    }else {
        //其他结点
        /*
            找到删除结点前一个结点target
            使target->next指向下一个结点
            释放需要删除结点的temp
         */
        for (i = 1, target = *L; target->next != *L && i != index-1; target = target->next, i++);
        temp = target->next;
        target->next = temp->next;
    }
    free(temp);
    return OK;
}
//循环链表查询值
int findNodeIndex(LinkList L, int value) {
    int i = 1;
    LinkList p;
    p = L;
    //寻找链表中的结点 data == value
    while (p->data != value && p->next != L) {
        i++;
        p = p->next;
    }
    //当尾结点指向头结点就会直接跳出循环，所以要额外增加一次判断尾结点的data == value
    if (p->next == L && p->data != value) {
        return -1;
    }
    return i;
}

void singleLinkedTest(void) {
    LinkList head;
    int place, num;
    int iStatus;
    
    int stop = 1;
    
    //初始化
    iStatus = createList(&head);
    printf("原始的链表:\n");
    displayList(head);
    while (stop != 0) {
        printf("请输入要测试的功能：\n0. 退出\n1. 手动插入数据\n2.  查询元素位置\n3. 删除第n个元素\n");
        int operation;
        scanf("%d", &operation);
        switch (operation) {
            case 0:
                stop = 0;
                break;
            case 1:
            {
                //插入
                printf("输入要插入的位置和数据用空格隔开：");
                scanf("%d %d",&place,&num);
                iStatus = listInsert(&head,place,num);
            }
                break;
            case 2:
            {
                //查询
                printf("输入想要查找的值：");
                scanf("%d", &num);
                place = findNodeIndex(head, num);
                if (place == -1) {
                    printf("没找到值\n");
                }else {
                    printf("改值的位置是：%d\n", place);
                }
            }
                break;;
            case 3:
            {
                //删除
                printf("输入要删除的位置：");
                scanf("%d", &place);
                linkListDelete(&head, place);
            }
                break;
            default:
                break;
        }
        displayList(head);
    }
}
