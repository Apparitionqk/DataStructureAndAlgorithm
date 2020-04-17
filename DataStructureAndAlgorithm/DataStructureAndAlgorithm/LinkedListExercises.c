//
//  LinkedListHomeWork.c
//  DataStructureAndAlgorithm
//
//  Created by 123 on 2020/4/8.
//  Copyright © 2020 齐科. All rights reserved.
//

#include "LinkedListExercises.h"
#include "SingleLinkedList.h"

Status mergeTwoList(LinkList *La, LinkList *Lb, LinkList *Lc) {
    LinkList pa, pb, pc, temp;
    //pa 是链表La的工作指针,pb 是链表Lb的工作指针, 初始化为首元结点
    pa = (*La)->next;
    pb = (*Lb)->next;
    
    *Lc = pc = *La;
    while (pa && pb) {
        if (pa->data < pb->data) {
            //取较小者La中的元素,将pa链接在pc的后面,pa指针后移
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }else if (pa->data > pb->data) {
            //取较小者Lb的元素,将pb链接在pc后面, pb指针后移
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }else {
            //相等时，取La中的元素，删除Lb中的元素
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            temp = pb->next;
            free(pb);
            pb = temp;
        }
    }
    pc->next = pa ? pa : pb;
    return OK;
}


Status findSameElemList(LinkList *La, LinkList *Lb, LinkList *Lc) {
    LinkList pa, pb, pc, temp;
    //pa 是链表La的工作指针,pb 是链表Lb的工作指针, 初始化为首元结点;La的头结点作为Lc的头结点
    pa = (*La)->next;
    pb = (*Lb)->next;
    
    *Lc = pc = *La;
    while (pa && pb) {
        if (pa->data == pb->data) {
            //相等,交集并入结果链表中;
            //(1).取La中的元素,将pa链接到pc的后面,pa指针后移;
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            
            //释放pb
            temp = pb;
            pb = pb->next;
            free(temp);
        }else if (pa->data < pb->data) {
            //删除较小值La的元素;
            temp = pa;
            pa = pa->next;
            free(temp);
        }else {
            //删除较小值La的元素;
            temp = pb;
            pb = pb->next;
            free(temp);
        }
    }
    while (pa) {
        temp = pa;
        pa = pa->next;
        free(temp);
    }
    while (pb) {
        temp = pb;
        pb = pb->next;
        free(pb);
    }
    pc->next = NULL;
    return OK;
}

Status reverseList(LinkList *L) {
    LinkList p, q;
    //p指向首元结点
    p = (*L)->next;
    //头结点的指针域置空
    (*L)->next = NULL;
    
    while (p != NULL) {
        //q执行p的后继，不丢失对结点的控制
        q = p->next;
        p->next = (*L)->next;
        (*L)->next = p;
        p = q;
    }
    return OK;
}


Status removeList(LinkList *L, int min, int max) {
    LinkList p, q, pre, temp;
    pre = *L;
    p = (*L)->next;
    
    while (p && p->data < min) {
        pre = p;
        p = p->next;
    }
    while (p && p->data > max) {
        p = p->next;
    }
    q = pre->next;
    pre->next = p;
    while (q != p) {
        temp = q->next;
        free(q);
        q = temp;
    }
    return OK;
}
Status removeListInterval(LinkList *L, int min, int max) {
    LinkList p, q, pre;
    pre = *L;
    LinkList temp;
    
    //p指向首元结点
    p = (*L)->next;
    
    //1 查找第一个值大于min的结点
    while (p && p->data < min) {
        //指向前驱结点
        pre = p;
        p = p->next;
    }
    
    //2 查找第一个值大于等于max的结点
    while (p && p->data <= max) {
        p = p->next;
    }
    
    //3 修改待删除的结点指针
    q = pre->next;
    pre->next = p;
    
    while (q != p) {
        temp = q->next;
        free(q);
        q = temp;
    }
    return OK;
}

Status revers(int *pre, int left, int right) {
    //i等于左边界left，j等于右边界
    int i = left , j = right;
    int temp;
    
    //交换pre[i] 和pre[j]的值
    while (i < j) {
        //交换
        temp = pre[i];
        pre[i] = pre[j];
        pre[j] = temp;
        // i右移，j左移
        i++;
        j--;
    }
    return OK;
}
void leftShift(int *pre, int n, int p) {
    //将长度为n的数组pre中的数据循环左移p个位置
    if (p > 0 && p < n) {
        //1 将数组中所有元素倒置
        revers(pre, 0, n-1);
        //2 将n-p个数据倒置
        revers(pre, 0, n-p-1);
        //3 将后p个数据倒置
        revers(pre, n-p, n-1);
    }
}
int mainElement(int *A, int n) {
    //count用来计数
    int count = 1;
    //key用来保存候选主元素，初始A[0]
    int key = A[0];
    // 扫描数组，选取候选主元素
    for (int i = 1; i < n; i++) {
        // 如果A[i]元素值 == key， 则count +1
        if (A[i] == key) {
            count ++;
        }else {
            if (count > 0) {
                count -- ;
            }else {
                key = A[i];
                count = 1;
            }
        }
    }
    if (count > 0) {
        //统计候选元素的实际出现最大次数
        for (int i = count = 0; i < n; i++) {
            if (A[i] == key) count++;
        }
    }
    if (count > n/2) {
        return key;
    }
    return -1;
}

void deleteEqualNode(LinkList *L, int n) {
    // 开辟辅助数组p
    int *p = alloca(sizeof(int ) * n);
    LinkList r = *L;
    
    //数组元素初始值置空
    for (int i = 0 ; i < n; i++) {
        *(p+i) = 0;
    }
    
    //指针temp指向首元结点
    LinkList temp = (*L)->next;
    
    //遍历链表， 直到temp = null
    while (temp != NULL) {
        //如果该绝对值已经在节点上出现过，则删除该结点
        if (p[abs(temp->data)] == 1) {
            //临时指针指向temp->next
            r->next = temp->next;
            //删除temp指向的结点
            free(temp);
            //temp指向删除结点下一个结点
            temp = r->next;
        }else {
            //未出现过的结点， 则将数组中对应位置置为1
            p[abs(temp->data)] = 1;
            r = temp;
            //继续向后遍历结点
            temp = temp->next;
        }
    }
}

//2.2 单链表插入
/*
 初始条件:顺序线性表L已存在,1≤i≤ListLength(L);
 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1;
 */
Status ListInsert(LinkList *L,int i,ElemType e){
    
    int j;
    LinkList p,s;
    p = *L;
    j = 1;
    
    //寻找第i个结点
    while (p && j<i) {
        p = p->next;
        ++j;
    }
    
    //第i个元素不存在
    if(!p || j>i) {
        printf("第%d个元素不存在\n", i);
        return ERROR;
    }
    
    //生成新结点s
    s = (LinkList)malloc(sizeof(Node));
    //将e赋值给s的数值域
    s->data = e;
    //将p的后继结点赋值给s的后继
    s->next = p->next;
    //将s赋值给p的后继
    p->next = s;
    
    return OK;
}
/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(LinkList L)
{
    LinkList p=L->next;
    while(p)
    {
        printf("%d  ",p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}
void testLinkedList() {
    int num;
    char *decs[] = {"将2个递增的有序链表合并为一个有序链表; 要求结果链表仍然使⽤用两个链表的存储空间, 不另外占⽤用其他的存储空间. 表中不允许有重复的数据", "已知两个链表A和B分别表示两个集合.其元素递增排列列. 设计⼀一个算法,⽤用于求出A与B的交集,并存储在A链表中", "将链表中所有节点的链接方向\"原地旋转\",即要求仅仅利用原表的存储空间. 换句话说,要求算法空间复杂度为O(1)", "删除递增有序链表中值⼤于等于mink且⼩于等于maxk的所有元素", "将R中保存的序列循环左移p个位置(0<p<n)个位置", "找出数组元素中的主元素",
        "删除链表中绝对值相等的结点"
    };
    printf("请选择测试题目：\n1.%s\n2.%s\n3.%s\n4.%s\n5.%s\n6.%s\n7.%s\n",decs[0], decs[1], decs[2], decs[3], decs[4], decs[5], decs[6]);
    scanf("%d",&num);
    //    //设计2个递增链表La,Lb
    LinkList La, Lb, Lc;
    initList(&La);
    initList(&Lb);
    initList(&Lc);
    initTwoLists(La, Lb);
    
    switch (num) {
        case 1:
            testMergeList(La, Lb, Lc);
            break;
        case 2:
            testGetSameElemList(La, Lb, Lc);
            break;
        case 3:
        {
            printf("L逆转前:\n");
            ListTraverse(La);
        
            reverseList(&La);
            printf("L逆转后:\n");
            ListTraverse(La);
        }
            break;
        case 4:
        {
            int a, b;
            printf("请输入要删除的范围，用空格隔开\n");
            scanf("%d %d", &a, &b);
            removeListInterval(&La, a, b);
            ListTraverse(La);
        }
            break;
        case 5:
        {
            int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
            int a;
            printf("请输入要移动位置的次数:\n");
            scanf("%d", &a);
            leftShift(num, 10, a);
            for (int i = 0; i< 10; i++) {
                printf("%d ", num[i]);
            }
            printf("\n");
        }
            break;
        case 6:
        {
            int  A[] = {0,5,5,3,5,7,5,5};
            int  B[] = {0,5,5,3,5,1,5,7};
            int  C[] = {0,1,2,3,4,5,6,7};
            
            int value = mainElement(A, 8);
            printf("数组A 主元素为: %d\n",value);
            value = mainElement(B, 8);
            printf("数组B 主元素为(-1表示数组没有主元素): %d\n",value);
            value = mainElement(C, 8);
            printf("数组C 主元素为(-1表示数组没有主元素): %d\n",value);
        }
            break;
        case 7:
        {
            LinkList L;
            initList(&L);
            ListInsert(&L, 1, 21);
            ListInsert(&L, 1, -15);
            ListInsert(&L, 1, 15);
            ListInsert(&L, 1, -7);
            ListInsert(&L, 1, 15);
        
            deleteEqualNode(&L, 21);
            ListTraverse(L);
        }
            break;
        default:
            break;
    }
}
void initTwoLists (LinkList La, LinkList Lb) {
    for(int j = 10;j>=0;j-=2)
       {
           ListInsert(&La, 1, j);
       }
       printf("La:\n");
       ListTraverse(La);

       for(int j = 11;j>0;j-=2)
       {
           ListInsert(&Lb, 1, j);
       }
       printf("Lb:\n");
       ListTraverse(Lb);
}
void testMergeList(LinkList La, LinkList Lb, LinkList Lc) {
    for(int j = 10;j>=0;j-=2)
    {
        ListInsert(&La, 1, j);
    }
    printf("La:\n");
    ListTraverse(La);

    for(int j = 11;j>0;j-=2)
    {
        ListInsert(&Lb, 1, j);
    }
    printf("Lb:\n");
    ListTraverse(Lb);

    mergeTwoList(&La, &Lb, &Lc);
    printf("Lc:\n");
    ListTraverse(Lc);
}
void testGetSameElemList(LinkList La, LinkList Lb, LinkList Lc) {
   ListInsert(&La, 1, 8);
   ListInsert(&La, 1, 6);
   ListInsert(&La, 1, 4);
   ListInsert(&La, 1, 2);
   printf("La:\n");
   ListTraverse(La);

    ListInsert(&Lb, 1, 10);
    ListInsert(&Lb, 1, 8);
    ListInsert(&Lb, 1, 6);
    ListInsert(&Lb, 1, 4);
    printf("Lb:\n");
    ListTraverse(Lb);
    
    findSameElemList(&La, &Lb, &Lc);
    printf("Lc:\n");
    ListTraverse(Lc);
}
