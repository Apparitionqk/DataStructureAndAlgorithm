//
//  RecursionProject.h
//  DataStructureAndAlgorithm
//
//  Created by 123 on 2020/4/23.
//  Copyright © 2020 齐科. All rights reserved.
//

#ifndef RecursionProject_h
#define RecursionProject_h

/*
    递归问题
    下面3中情况下，我们会用递归来解决问题
    1. 定义是递归的
    2. 数据结构是递归的
    3. 问题的解法是递归的
 */
#include <stdio.h>

/*
    Hanoi塔问题 （汉诺塔）
    古代有一个梵塔，塔内有三个座A、B、C，A座上有64个盘子，盘子大小不等，大的在下，小的在上。有一个和尚想把这64个盘子从A座移到B座，但每次只能允许移动一个盘子，并且在移动过程中，3个座上的盘子始终保持大盘在下，小盘在上。
 */


/// 移动盘子
/// @param x 塔盘
/// @param n 盘子编号
/// @param y 塔盘
void moves(char x, int n, char y);


/// 将n个盘子从A按规则移动到C
/// @param n 盘子数量
/// @param A A塔
/// @param B 辅助塔
/// @param C C塔
void hanoi(int n, char A, char B, char C);

void testHanoi(void);



/// Fibonacci 斐波那契数列
/// @param i 数字个数
int Fibonacci(int i);

void testFibonacci();
#endif /* RecursionProject_h */
