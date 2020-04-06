//
//  Table.c
//  DataStructureAndAlgorithm
//
//  Created by 齐科 on 2020/4/4.
//  Copyright © 2020 齐科. All rights reserved.
//

#include "LinearTable.h"

//初始化
Status initLinearTable(LinearTable *L) {
    //为顺序表分配一个大小为MAXSIZE_LINEARTABLE的数组空间
    L->data = malloc(sizeof(ElemType ) * MAXSIZE_LINEARTABLE);
    //存储分配失败
    if (!L->data) {printf("初始化失败");return ERROR;}
    
    //空包长度为0
    L->length = 0;
    printf("初始化成功\n");
    return OK;
}

//插入
/*
  初始条件： 顺序线性表L已存在且可再插入新元素，并且插入位置合法 1 ≥ i ≤ L->length+1
  操作结果：在L中第i个位置之前插入新的元素e，L的长度+1
 */
Status linearTableInsert(LinearTable *L, int i, ElemType e) {
    //检查表是否存在
    if (!L->data)   {printf("插入失败：表不存在\n"); return ERROR;}
    //检查位置是否合法
    if (i<0 || i > L->length+1) {printf("插入失败：位置不合法\n"); return ERROR;}
    //存储空间已满
    if (L->length == MAXSIZE_LINEARTABLE)  {printf("插入失败：存储空间满"); return ERROR;}
    
    if (i != L->length) {// 插入的位置不在末尾
        for (int j = L->length; j >= i; j--) {
            L->data[j+1] = L->data[j];
        }
    }
    L->data[i] = e;
    L->length ++;
    return OK;
}

//查询
ElemType getElem(LinearTable L, int i) {
    if (!L.data) {
        printf("查询失败：表不存在\n");
        return ERROR;
    }
    if (i > L.length-1) {
        printf("查询失败：超出表长度\n");
        return ERROR;
    }
    return L.data[i];
}
//获取元素位置
int getIndex(LinearTable L, ElemType e) {
    if (!L.data) {
           printf("查询失败：表不存在\n");
           return ERROR;
    }
    int index = -1;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            index = i;
            break;
        }
    }
    if (L.length < index || index < 0) {
        printf("表中不存在该元素");
        return ERROR;
    }
    return index;
}
//删除
Status deleteElem(LinearTable *L, ElemType e) {
    if (!L->data) {
        printf("删除失败：表不存在\n");
        return ERROR;
    }
    int contains = containsElem(*L, e);
    if (contains == FALSE) {
        printf("删除失败：链表中没有该元素");
        return ERROR;
    }
    int index = getIndex(*L, e);
    for (int i = index; i<L->length-1; i++) {
        L->data[i] = L->data[i+1];
    }
    L->length--;
    return OK;
}
int containsElem(LinearTable L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return TRUE;
        }
    }
    return FALSE;
}

Status deleteElemAtIndex(LinearTable *L, int i) {
    if (!L->data) {
           printf("删除失败：表不存在\n");
           return ERROR;
       }
    for (int j = i; j < L->length-1; j++) {
        L->data[j] = L->data[j+1];
    }
    L->length -- ;
    return OK;
}
//清空
Status clearTable(LinearTable *L) {
    for (int i = 0; i < L->length; i++) {
        L->length = 0;
    }
    return OK;
}

//判断表是否为空
Status isEmpty(LinearTable L) {
    if (L.length == 0) {
        return TRUE;
    }
    return FALSE;
}

//顺序输出
/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status TraverseList(LinearTable L) {
    if (L.length == 0) {
        printf("这是张空表\n");
        return ERROR;
    }
    for(int i=0;i<L.length;i++)
        printf("%d--%d  ", i, L.data[i]);
    printf("\n");
    return OK;
}
