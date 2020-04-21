//
//  StackAndStackStorage.h
//  DataStructureAndAlgorithm
//
//  Created by 123 on 2020/4/21.
//  Copyright © 2020 齐科. All rights reserved.
//
/*
    栈与栈的链式存储
 */

#ifndef StackAndStackStorage_h
#define StackAndStackStorage_h

#include <stdio.h>
#include "Macros.h"

typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */
typedef struct {
    SElemType data[MAXSIZE_SingleLinkedList];
    int top; //!< 用于栈顶指针
}SqStack; //!< 栈结构

#pragma mark -------- 栈
/// 初始化空栈
/// @param S 栈
Status initStack(SqStack *S);


/// 置空栈
/// @param S 栈
Status clearStack(SqStack *S);


/// 判断顺序栈是否为空
/// @param S 栈
Status isStackEmpty(SqStack S);


/// 获取栈的长度
/// @param S 栈
int lengthOfStack(SqStack S);


/// 获取栈顶
/// @param S 栈
/// @param e 栈顶元素
Status getStackTop(SqStack S, SElemType *e);


/// 插入新元素为栈顶元素
/// @param S 栈
/// @param e 栈顶元素
Status pushData(SqStack *S, SElemType e);


/// 删除栈顶元素赋值给e
/// @param S 栈
/// @param e 栈顶元素
Status popData(SqStack *S, SElemType *e);


/// 遍历输出栈元素
/// @param S 栈
/// @param order 顺序 1 顺序 0 逆序
Status stackTraverse(SqStack *S, int order);

#pragma mark ------- 链式栈

typedef struct {
    SElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct {
    LinkStackPtr top;
    int count;
}LinkStack;


/// 初始化空栈
/// @param S 栈
Status initLinkStack(LinkStack *S);


/// 清空链栈
/// @param S S description
Status clearLinkStack(LinkStack *S);


/// 判断链栈是否为空栈
/// @param S S description
Status isLinkStackEmpty(LinkStack *S);


/// 获取栈长度
/// @param S S description
Status lengthOfLinkStack(LinkStack S);


/// 获取栈顶
/// @param S S description
/// @param e e description
Status getLinkStackTop(LinkStack S, SElemType *e);


/// 插入元素到链栈
/// @param S S description
/// @param e 新栈顶元素
Status pushLinkStack(LinkStack *S, SElemType *e);


/// 删除栈顶元素，用e返回值
/// @param S S description
/// @param e e description
Status popLinkStack(LinkStack *S, SElemType *e);


/// 遍历输出链栈
/// @param S S description
Status linkStackTraverse(LinkStack S);

void testStack(void);
void testLinkStack(void);
#endif /* StackAndStackStorage_h */
