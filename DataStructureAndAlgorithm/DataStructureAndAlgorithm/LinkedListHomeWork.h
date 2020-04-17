//
//  LinkedListHomeWork.h
//  DataStructureAndAlgorithm
//
//  Created by 123 on 2020/4/8.
//  Copyright © 2020 齐科. All rights reserved.
//

#ifndef LinkedListHomeWork_h
#define LinkedListHomeWork_h

#include <stdio.h>
#include "SingleLinkedList.h"

/*
    将2个递增的有序链表合并为⼀一个链表的有序链表; 要求结果链表仍然使⽤用两个链表的存储空间,
    不不另外占⽤用其他的存储空间. 表中不不允许有重复的数据
*/
Status mergeTwoList(LinkList *La, LinkList *Lb, LinkList *Lc);

/*
    已知两个链表A和B分别表示两个集合.其元素递增排列列. 设计⼀一个算法,⽤用于求出A与B的交集,并
    存储在A链表中; 例例如 : La = {2,4,6,8}; Lb = {4,6,8,10}; Lc = {4,6,8}
 */
Status findSameElemList(LinkList *La, LinkList *Lb, LinkList *Lc);

/*
    将链表中所有结点的链接方向“原地旋转”，即要求仅仅利用原表的存储空间，换句话说，要求算法空间复杂度位O(1)
    例如:L={0,2,4,6,8,10}, 逆转后: L = {10,8,6,4,2,0};
    关键词：不能开辟新空间， 头插法
    思路：1. *L 作为新的旋转后链表的首结点，用临时变量p指向首元结点
              2. 从前向后遍历链表
              3. 临时变量p指向待插入结点的后继结点
 */
Status reverseList(LinkList *L);

/*
    设计一个算法,删除递增有序链表中值⼤大于等于mink且⼩小于等于maxk(mink,maxk是给定的两个参 数,其值可以和表中的元素相同,也可以不不同)的所有元素
    1. 遍历链表，第一个大于min的结点，保存前驱pre
    2. 遍历链表，第一个大于max的结点， p指向
    3. pre->next = p;
    4. 介于pre和p之间的内存释放
 */
Status removeList(LinkList *L, int min, int max);

/*
    设将n(n>1)个整数存放到一维数组R中, 试设计一个在时间和空间两⽅方⾯面都尽可能⾼高效的算法;将R
    中保存的序列列循环左移p个位置(0<p<n)个位置, 即将R中的数据由(x0,x1,......,xn-1)变换为 (xp,xp+1,...,xn-1,x0,x1,...,xp-1).
    例如: pre[10] = {0,1,2,3,4,5,6,7,8,9},
            n = 10,p = 3;
            pre[10] = {3,4,5,6,7,8,9,0,1,2}
    思路：
        a. n个数据原地逆置
        b. 拆解
        c. 将n-p个数据/p个数据再一次逆置
 */

//倒叙数组
Status revers(int *pre, int *left, int right);


/*
    已知⼀一个整数序列列A = (a0,a1,a2,...an-1),其中(0<= ai <=n),(0<= i<=n). 若存在ap1= ap2 = ...=
    apm = x,且m>n/2(0<=pk<n,1<=k<=m),则称x 为 A的主元素. 例例如,A = (0,5,5,3,5,7,5,5),则5是主 元素; 若B = (0,5,5,3,5,1,5,7),则A 中没有主元素,假设A中的n个元素保存在⼀一个⼀一维数组中,请设 计⼀一个尽可能⾼高效的算法,找出数组元素中的主元素,若存在主元素则输出该元素,否则输出-1.
 */


/*
    ⽤用单链表保存m个整数, 结点的结构为(data,link),且|data|<=n(n为正整数). 现在要去设计⼀一个时
    间复杂度尽可能⾼高效的算法. 对于链表中的data 绝对值相等的结点, 仅保留留第⼀一次出现的结点,⽽而 删除其余绝对值相等的结点.例例如,链表A = {21,-15,15,-7,15}, 删除后的链表A={21,-15,-7};
 */
#endif /* LinkedListHomeWork_h */
