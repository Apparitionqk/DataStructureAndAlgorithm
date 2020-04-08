//
//  DoubleLinkedList.c
//  DataStructureAndAlgorithm
//
//  Created by 123 on 2020/4/8.
//  Copyright © 2020 齐科. All rights reserved.
//

#include "DoubleLinkedList.h"


Status createDLinkedList(DLinkedList *L) {
    printf("请输入要插入的值，用空格隔开, 输入0结束\n");
    int value = -1;
    DLinkedList tail = NULL;//记录尾指针
    while (1) {
        scanf("%d", &value);
        if (value == 0) break;
        printf("开始插入值： %d\n", value);
        if (*L == NULL) {
            *L = (DLinkedList)malloc(sizeof(DNode));
            if (*L == NULL) return ERROR;
            (*L)->data = value;
            (*L)->next = NULL;
            (*L)->prior = NULL;
            tail = *L;
        }else {
            DLinkedList temp = (DLinkedList)malloc(sizeof(DNode));
            if (!temp) return ERROR;
            temp->data = value;
            tail->next = temp;
            temp->prior = tail;
            temp->next = NULL;
            tail = tail->next;
        }
    }
    return OK;
}

Status insertDlinkedList(DLinkedList *L, int index, ElemType data) {
    if (*L == NULL || index < 1)  return ERROR;
    
    //新建结点
    DLinkedList temp = (DLinkedList)malloc(sizeof(DNode));
    temp->data = data;
    temp->prior = NULL;
    temp->next = NULL;
    
    DLinkedList head = *L;//头结点
    
    //找到插入位置的结点
    for (int j = 1; j<= index && head; j++) {
        head = head->next;
    }
    //如果插入位置超过链表本身的长度
    if (head == NULL) {
        printf("插入位置超过链表本身的长度");
        return ERROR;
    }
    printf("请选择插入方式，1.前插 2.后插\n");
    int insert;
    scanf("%d",&insert);
    
    if (insert == 1) {
        if (head->prior == NULL) {//表头
            temp->next = head;
            head->prior = temp;
            *L = temp;
        }else if (head->next == NULL){
            head->next = temp;
            temp->prior = head;
        }else{
            temp->prior = head->prior;
            head->prior->next = temp;
            temp->next = head;
            head->prior = temp;
            
        }
    }else{
        if (head->next == NULL) {//表尾
            head->next = temp;
            temp->prior = head;
        }else {
            head->next->prior = temp;
            temp->next = head->next;
            head->next = temp;
            temp->prior = head;
        }
    }

    return OK;
}
//删除双向链表指定位置的结点
Status deleteDNode(DLinkedList *L, int index, ElemType *e) {
    if (*L == NULL) return ERROR;
    
    int k = 1;
    DLinkedList p = (*L);
    
    //移动p指针到index的前一个结点
    while (k < index-1 && p != NULL) {
        p = p->next;
        k++;
    }
    
    //如果k > i 或者 p==NULL 则返回ERROR
    if (k > index || p == NULL) return ERROR;

    //创建临时指针指向要删除的结点， 并将要删除的结点的data赋值给*e，带出函数
    DLinkedList delTemp = p->next;
    *e = delTemp->data;
    
    //p->next 等于要删除的结点的下一个结点
    p->next = delTemp->next;
    
    //如果删除结点的下一个结点不为空， 则将要删除的下一个结点的前驱指针赋值p
    if (delTemp->next != NULL) {
        delTemp->next->prior = p;
    }
    free(delTemp);
    free(p);
    return OK;
}

Status deleteDNodeElem(DLinkedList *L, ElemType e) {
    if (*L == NULL) {
        printf("链表为空\n");
        return ERROR;
    }
    
    DLinkedList p = *L;
    while (p) {
        if (p->data == e) {
            //修改p结点的前驱结点的后继指针，指向p的后继
            p->prior->next = p->next;
            if (p->next != NULL) {
                //修改p结点的后继指针的前驱指针，指向p结点的前驱
                p->next->prior = p->prior;
            }
            free(p);
            break;
        }
        p = p->next;
    }
    
    return OK;
}

//在双向链表中查找元素的位置
int selectElem(DLinkedList L,ElemType elem) {
    int index = 1;
    DLinkedList p = L->next;
    while (p) {
        if (p->data == elem) {
            return index;
        }
        p = p->next;
        index ++;
    }
    printf("为找到该元素\n");
    return -1;
}

// 在双向链表中更新/修改结点
Status replaceElem(DLinkedList *L,int index,ElemType newElem) {
    if (*L == NULL) {
        printf("链表为空");
        return ERROR;
    }
    
    int i = 1;
    DLinkedList p = (*L);
    while (p) {
        if (i == index) {
            p->data = newElem;
            return OK;
        }
        p = p->next;
        i++;
    }
    printf("未找到该位置的结点\n");
    return ERROR;
}

//遍历打印双向链表
void showList(DLinkedList *L) {
    if (*L == NULL) return;
    DLinkedList temp = *L;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != NULL);
    printf("\n");
}

void doubleLinkedTest(void) {
    DLinkedList head;
       int place, num;
       int iStatus;
       
       int stop = -1;
       
       //初始化
       iStatus = createDLinkedList(&head);
       printf("原始的链表:\n");
       showList(&head);
       while (stop != 0) {
           printf("请输入要测试的功能：\n0. 退出\n1. 手动插入数据\n2.  查询元素位置\n3. 删除第n个元素\n4.删除指定值的元素\n5.修改指定位置元素\n");
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
                   iStatus = insertDlinkedList(&head,place,num);
               }
                   break;
               case 2:
               {
                   //查询
                   printf("输入想要查找的值：");
                   scanf("%d", &num);
                   place = selectElem(head, num);
                   if (place == -1) {
                       printf("没找到值\n");
                   }else {
                       printf("该值的位置是：%d\n", place);
                   }
               }
                   break;;
               case 3:
               {
                   //删除
                   printf("输入要删除的位置：");
                   scanf("%d", &place);
                   ElemType e;
                   deleteDNode(&head, place, &e);
                   printf("删除的结点值是：%d\n", e);
               }
                   break;
                case 4:
                {
                    //删除
                    printf("输入要删除的元素：");
                    ElemType e;
                    scanf("%d", &e);
                    deleteDNodeElem(&head, e);
                }
                    break;
                case 5:
               {
                   //修改指定位置元素
                   printf("输入要修改元素的位置和值，用空格分开：\n");
                   ElemType e;
                   scanf("%d %d", &place, &e);
                   replaceElem(&head, place, e);
               }
                   break;
               default:
                   break;
           }
           showList(&head);
       }
}
