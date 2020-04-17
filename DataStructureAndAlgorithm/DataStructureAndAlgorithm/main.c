//
//  main.c
//  DataStructureAndAlgorithm
//
//  Created by 齐科 on 2020/4/4.
//  Copyright © 2020 齐科. All rights reserved.
//

#include <stdio.h>
#include "LinearTable.h"
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"
#include "LinkedListExercises.h"




int main(int argc, const char * argv[]) {
    // insert code here...
    
    printf("数据结构与算法\n");
    printf("选择测试项目\n1. 线性表\n2.单向链表\n3.双向链表\n4.链表习题\n");
    
    int selectItem;
   
    scanf("%d", &selectItem);
    switch (selectItem) {
        case 1:
             linearTableTest();
            break;
        case 2:
             singleLinkedTest();
            break;
        case 3:
            doubleLinkedTest();
            break;
        case 4:
            testLinkedList();
            break;
        default:
            break;
    }
    return 0;
}
