//
//  StackAndStackStorage.c
//  DataStructureAndAlgorithm
//
//  Created by 123 on 2020/4/21.
//  Copyright © 2020 齐科. All rights reserved.
//

#include "StackAndStackStorage.h"

#pragma mark ------- 栈 Stack
/// 初始化空栈
/// @param S 栈
Status initStack(SqStack *S) {
    S->top = -1;
    return OK;
}


/// 置空栈
/// @param S 栈
Status clearStack(SqStack *S) {
    //置空只需要将栈顶指针赋值为-1即可
    S->top = -1;
    return OK;
}


/// 判断顺序栈是否为空
/// @param S 栈
Status isStackEmpty(SqStack S) {
    if (S.top == -1) {
        return TRUE;
    }
    return FALSE;
}


/// 获取栈的长度
/// @param S 栈
int lengthOfStack(SqStack S) {
    return S.top + 1;
}


/// 获取栈顶
/// @param S 栈
/// @param e 栈顶元素
Status getStackTop(SqStack S, SElemType *e) {
    if (S.top == -1) {
        printf("栈为空栈");
        return ERROR;
    }
    *e = S.data[S.top];
    printf("栈顶元素为：%d", *e);
    return OK;
}


/// 插入新元素为栈顶元素
/// @param S 栈
/// @param e 栈顶元素
Status pushData(SqStack *S, SElemType e) {
    //栈已满
    if (S->top == MAXSIZE_NodeList - 1) {
        printf("栈满");
        return ERROR;
    }
    
    //栈顶指针+1
    S->top ++;
    //将新插入的元赋值给栈顶空间
    S->data[S->top] = e;
    return OK;
}


/// 删除栈顶元素赋值给e
/// @param S 栈
/// @param e 栈顶元素
Status popData(SqStack *S, SElemType *e) {
    //空栈
    if (S->top == -1) {
        printf("空栈");
        return ERROR;
    }
    
    //将栈顶元素赋值给e
    *e = S->data[S->top];
    
    // 栈顶指针-1
    S->top --;
    return OK;
}


/// 遍历输出栈元素
/// @param S 栈
/// @param order 顺序 1 顺序 0 逆序
Status stackTraverse(SqStack *S, int order) {
    
    //空栈
    if (S->top == -1) {
        printf("空栈");
        return ERROR;
    }
    
    if (order == TRUE) {//顺序
        int index = 0;
        while (index <= S->top) {
            printf("%d ", S->data[index]);
            index++;
        }
        printf("\n");
    }else {
        int index = S->top;
        while (index != -1) {
            printf("%d  ", S->data[index]);
            index --;
        }
        printf("\n");
    }
    
    return OK;
}

void testStack(void) {
    SqStack S;
    int e;
    if (initStack(&S) == OK) {
        for (int j = 1; j < 10; j++) {
            pushData(&S, j);
        }
    }
    
    printf("顺序栈中元素为:\n");
    printf("顺序\n");
    stackTraverse(&S, TRUE);
    printf("倒序\n");
    stackTraverse(&S, FALSE);
     printf("\n");
    popData(&S, &e);
    printf("弹出栈顶元素为: %d\n",e);
    stackTraverse(&S, TRUE);
    printf("是否为空栈:%d\n",isStackEmpty(S));
    getStackTop(S, &e);
    printf("栈顶元素:%d \n栈长度:%d\n",e,lengthOfStack(S));
    clearStack(&S);
    printf("是否已经清空栈 %d, 栈长度为:%d\n",isStackEmpty(S),lengthOfStack(S));
}

#pragma mark ----- 链栈 LinkStack
/// 初始化空栈
/// @param S 栈
Status initLinkStack(LinkStack *S) {
    S->top = NULL;
    S->count = 0;
    return OK;
}


/// 清空链栈
/// @param S S description
Status clearLinkStack(LinkStack *S) {
    LinkStackPtr p, q;
    p = S->top;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    S->count = 0;
    return OK;
}


/// 判断链栈是否为空栈
/// @param S S description
Status isLinkStackEmpty(LinkStack S) {
    if (S.count == 0) {
        return TRUE;
    }
    return FALSE;
}


/// 获取栈长度
/// @param S S description
int lengthOfLinkStack(LinkStack S) {
    return S.count;
}


/// 获取栈顶
/// @param S S description
/// @param e e description
Status getLinkStackTop(LinkStack S, SElemType *e) {
    if (S.top == NULL) {
        printf("栈顶为空");
        return ERROR;
    }
    *e = S.top->data;
    return OK;
}


/// 插入元素到链栈
/// @param S S description
/// @param e 新栈顶元素
Status pushLinkStack(LinkStack *S, SElemType e) {
    //创建新的结点temp
    LinkStackPtr temp =  (LinkStackPtr)malloc(sizeof(StackNode));
    //赋值
    temp->data = e;
    //把当前栈顶元素赋值给新结点的后继
    temp->next = S->top;
    //将新结点temp赋值给栈顶指针
    S->top = temp;
    S->count ++;
    return OK;
}


/// 删除栈顶元素，用e返回值
/// @param S S description
/// @param e e description
Status popLinkStack(LinkStack *S, SElemType *e) {
    LinkStackPtr p;
    if (isLinkStackEmpty(*S)) {
        printf("链表为空");
        return ERROR;
    }
    //将栈顶元素赋值给*e
    *e = S->top->data;
    //将栈顶结点赋值给p
    p = S->top;
    //是栈顶指针下移一位，指向后一结点
    S->top = S->top->next;
    //释放p
    free(p);
    //个数--
    S->count -- ;
    return OK;
}


/// 遍历输出链栈
/// @param S S description
Status linkStackTraverse(LinkStack S) {
    if (isLinkStackEmpty(S)) {
        printf("链表为空");
        return ERROR;
    }
    printf("栈中元素依次为：\n");
    LinkStackPtr p;
    p = S.top;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}
void testLinkStack(void) {
    int j;
    LinkStack s;
    int e;
    if (initLinkStack(&s) == OK) {
        for (j = 1; j <= 10; j++) {
            pushLinkStack(&s, j);
        }
    }
    linkStackTraverse(s);
    popLinkStack(&s, &e);
    printf("弹出的栈顶元素 e=%d\n",e);
    linkStackTraverse(s);
    printf("栈空否：%d(1:空 0:否)\n",isLinkStackEmpty(s));
    getLinkStackTop(s,&e);
    printf("栈顶元素 e=%d 栈的长度为%d\n", e, lengthOfLinkStack(s));
    clearLinkStack(&s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",isLinkStackEmpty(s));
}
