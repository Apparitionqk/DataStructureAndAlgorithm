//
//  LinkedListHomeWork.h
//  DataStructureAndAlgorithm
//
//  Created by 123 on 2020/4/8.
//  Copyright © 2020 齐科. All rights reserved.
//

#ifndef LinkedListExercises_h
#define LinkedListExercises_h

#include <stdio.h>
#include "SingleLinkedList.h"

/*
    将2个递增的有序链表合并为一个有序链表; 要求结果链表仍然使⽤用两个链表的存储空间,
    不另外占⽤用其他的存储空间. 表中不允许有重复的数据
*/
Status mergeTwoList(LinkList *La, LinkList *Lb, LinkList *Lc);

/*
    已知两个链表A和B分别表示两个集合.其元素递增排列列. 设计⼀一个算法,⽤用于求出A与B的交集,并
    存储在A链表中; 例例如 : La = {2,4,6,8}; Lb = {4,6,8,10}; Lc = {4,6,8}
 
    算法思想：
    (1)假设待合并的链表为La和Lb,合并后的新表使用头指针Lc(Lc的表头结点设为La的表头结点)指向. Pa 和 Pb 分别是La,Lb的工作指针.初始化为相应链表的首元结点
    (2)从首元结点开始比较, 当两个链表La 和Lb 均未到达表尾结点时.
    (3)如果两个表中的元素相等,只摘取La表中的元素,删除Lb表中的元素;
    (4)如果其中一个表中的元素较小,删除此表中较小的元素. 此表的工作指针后移;
    (5)当链表La和Lb有一个先到达表尾结点为空时,依次删除另一个非空表中的所有元素,最后释放链表lb;
 */
Status findSameElemList(LinkList *La, LinkList *Lb, LinkList *Lc);

/*
    将链表中所有结点的链接方向“原地旋转”，即要求仅仅利用原表的存储空间，换句话说，要求算法空间复杂度位O(1)
    例如:L={0,2,4,6,8,10}, 逆转后: L = {10,8,6,4,2,0};
    关键词：不能开辟新空间， 头插法
    思路：
    (1) 利用原有的头结点*L,p为工作指针, 初始时p指向首元结点. 因为摘取的结点依次向前插入,为确保链表尾部为空,初始时将头结点的指针域置空;
    (2) 从前向后遍历链表,依次摘取结点,在摘取结点前需要用指针q记录后继结点,以防止链接后丢失后继结点;
    (3) 将摘取的结点插入到头结点之后,最后p指向新的待处理节点q(p=q);
 */
Status reverseList(LinkList *L);

/*
    设计一个算法,删除递增有序链表中值⼤于等于mink且⼩于等于maxk(mink,maxk是给定的两个参 数,其值可以和表中的元素相同,也可以不同)的所有元素
    1. 遍历链表，第一个大于min的结点，保存前驱pre
    2. 遍历链表，第一个小于max的结点， p指向
    3. pre->next = p;
    4. 介于pre和p之间的内存释放
 */
Status removeListInterval(LinkList *L, int min, int max);

/*
    设将n(n>1)个整数存放到一维数组R中, 试设计一个在时间和空间两⽅⾯都尽可能高效的算法;将R
    中保存的序列循环左移p个位置(0<p<n)个位置, 即将R中的数据由(x0,x1,......,xn-1)变换为 (xp,xp+1,...,xn-1,x0,x1,...,xp-1).
    例如: pre[10] = {0,1,2,3,4,5,6,7,8,9},
            n = 10,p = 3;
            pre[10] = {3,4,5,6,7,8,9,0,1,2}
    思路：
        a. n个数据原地逆置
        b. 拆解
        c. 将n-p个数据/p个数据再一次逆置
 */

//倒叙数组
Status revers(int *pre, int left, int right);
void leftShift(int *pre, int n, int p);

/*
    已知一个整数序列A = (a0,a1,a2,...an-1),其中(0<= ai <=n),(0 <= i <= n). 若存在ap1= ap2 = ...=
    apm = x,且m>n/2(0<=pk<n,1<=k<=m),则称x 为 A的主元素. 例如,A = (0,5,5,3,5,7,5,5),则5是主 元素; 若B = (0,5,5,3,5,1,5,7),则A 中没有主元素,假设A中的n个元素保存在一个一维数组中,请设 计⼀个尽可能⾼效的算法,找出数组元素中的主元素,若存在主元素则输出该元素,否则输出-1.
    主元素：数组中的出现次数哦超过一半的元素。当数组中存在主元素时，所有非主元素的个数和必须少于一半。如果让一个主元素和一个非主元素配对，则最后多出来的元素就是住元素
    算法思路:
    1. 选取候选主元素, 从前向后依次扫描数组中的每个整数, 假定第一个整数为主元素,将其保存在Key中,计数为1. 若遇到下一个整数仍然等于key,则计数加1. 否则计数减1. 当计数减到0时, 将遇到的下一个整数保存到key中, 计数重新记为1. 开始新一轮计数. 即可从当前位置开始重上述过程,直到将全部数组元素扫描一遍;
    2. 判断key中的元素是否是真正的主元素, 再次扫描数组, 统计key中元素出现的次数,若大于n/2,则为主元素,否则,序列中不存在主元素;
 */
int mainElement(int *A, int n);

/*
    ⽤单链表保存m个整数, 结点的结构为(data,link),且|data|<=n(n为正整数). 现在要去设计⼀个时
    间复杂度尽可能⾼效的算法. 对于链表中的data 绝对值相等的结点, 仅保留第⼀次出现的结点,⽽ 删除其余绝对值相等的结点.例如,链表A = {21,-15,15,-7,15}, 删除后的链表A={21,-15,-7};
 
    算法思路:
    1. 申请大小为n+1的辅助数组t并赋值初值为0;
    2. 从首元结点开始遍历链表,依次检查t[|data|]的值, 若[|data|]为0,即结点首次出现,则保留该结点,并置t[|data|] = 1,若t[|data|]不为0,则将该结点从链表中删除.
 */
void deleteEqualNode(LinkList *L, int n);

void testLinkedList(void);
void initTwoLists(LinkList La, LinkList Lb);
void testMergeList(LinkList La, LinkList Lb, LinkList Lc);
void testGetSameElemList(LinkList La, LinkList Lb, LinkList Lc);
#endif /* LinkedListExercises_h */
