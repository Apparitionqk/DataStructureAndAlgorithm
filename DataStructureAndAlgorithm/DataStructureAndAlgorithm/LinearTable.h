//
//  Table.h
//  DataStructureAndAlgorithm
//
//  Created by 齐科 on 2020/4/4.
//  Copyright © 2020 齐科. All rights reserved.
//

#ifndef LinearTable_h
#define LinearTable_h

#include <stdio.h>
#include "Macros.h"
/* 线性结构使用顺序表的方式存储 */

//顺序表结构设计
typedef struct {
    ElemType *data;
    int length; //!< 顺序表的长度
}LinearTable;


/// 线性表初始化
/// @param L 线性表指针
Status initLinearTable(LinearTable *L);


/// 线性表插入
/// @param L 线性表指针
/// @param i 插入位置
/// @param e 插入元素
Status linearTableInsert(LinearTable *L, int i, ElemType e);

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status TraverseList(LinearTable L);

/// 线性表查询
/// @param L 线性表指针
/// @param i 查询位置
ElemType getElem(LinearTable L, int i);


/// 获取元素的位置
/// @param L 线性表
/// @param e 需要查询的元素
int getIndex(LinearTable L, ElemType e);


/// 删除元素
/// @param L 线性表
/// @param e 元素
Status deleteElem(LinearTable *L, ElemType e);

/// 删除元素
/// @param L 线性表
/// @param e 元素
Status deleteElemAtIndex(LinearTable *L, int i);


/// 链表中是否包含元素
/// @param L 链表
/// @param e 元素
int containsElem(LinearTable L, ElemType e);


/// 清空表
/// @param L 线性表指针
Status clearTable(LinearTable *L);


/// 判断表是否为空
/// @param L 线性表
Status isEmpty(LinearTable L);
#endif /* LinearTable_h */
