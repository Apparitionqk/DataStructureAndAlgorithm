//
//  RecursionProject.c
//  DataStructureAndAlgorithm
//
//  Created by 123 on 2020/4/23.
//  Copyright © 2020 齐科. All rights reserved.
//

#include "RecursionProject.h"

int m = 0;

void moves(char x, int n, char y) {
    m++;
    printf("%d frome %c ---> %c \n", n, x, y);
}
void hanoi(int n, char A, char B, char C) {
    //将塔盘A上的圆盘按规则移动到塔盘C上，B作为辅助盘
    
    //将编号为1的圆盘从A移动到C上
    if (n == 1) {
        moves(A, n, C);
    }else {
        //将塔盘A上的编号为1至n-1的圆盘移动到塔盘B上C作为辅助塔
        hanoi(n-1, A, C, B);
        //将编号为n的圆盘从A移动到C上
        moves(A, n, C);
        //将塔盘B上的编号为1至n-1的圆盘移动到塔盘C上A作为辅助塔
        hanoi(n-1, B, A, C);
    }
}

void testHanoi(void) {
    hanoi(3, 'A', 'B', 'C');
    printf("盘子数量为3:一共实现搬到次数:%d\n",m);
      
    
      hanoi(4, 'A', 'B', 'C');
      printf("盘子数量为3:一共实现搬到次数:%d\n",m);
}

int Fibonacci(int i) {
    if (i<2) {
        return i == 0 ? : 1;
    }
    return Fibonacci(i-1) + Fibonacci(i-2);
}

void testFibonacci() {
    printf("请输入数列个数\n");
    int n = 0;
    scanf("%d", &n);
    
    for (int i = 0; i<n; i++) {
        printf("%d ", Fibonacci(i));
    }
    printf("\n");
}
