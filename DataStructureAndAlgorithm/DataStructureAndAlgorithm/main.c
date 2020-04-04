//
//  main.c
//  DataStructureAndAlgorithm
//
//  Created by 齐科 on 2020/4/4.
//  Copyright © 2020 齐科. All rights reserved.
//

#include <stdio.h>
#include "LinearTable.h"

void linearTableTest() {
    LinearTable lTable;
    
    //初始化
    initLinearTable(&lTable);
    
    //插入数据
    for (int i = 0; i < 5; i++) {
        ElemType e = rand()%100;
        printf("插入 %d\n",e);
        linearTableInsert(&lTable, i, e);
    }
    TraverseList(lTable);
    int operation = 1;
    while (1) {
        if (operation == 0) {
            break;
        }
        Status stop = OK;
        while (stop) {
            if (stop == 2) {
                if (operation != 0) {
                    stop = 1;
                }
                break;
            }else {
                printf("请输入要测试的功能：\n0. 退出\n1. 手动插入数据\n2. 根据位置查询元素\n3. 查询元素位置\n4. 删除元素\n5. 删除第n个元素\n6. 清空表\n");
                scanf("%d", &operation);
                switch (operation) {
                    case 0:
                    {
                        stop = 2;
                    }
                        break;
                    case 1://手动插入数据
                    {
                        printf("手动插入数据：位置 元素\n");
                        ElemType a, b;
                        scanf("%d %d", &a, &b);
                        linearTableInsert(&lTable, a, b);
                        printf("停止插入？2：停止， 1：继续\n");
                        scanf("%d", &stop);
                        TraverseList(lTable);
                    }
                        break;
                    case 2: //-----根据位置查询元素
                    {
                        printf("输入查询位置：");
                        ElemType a;
                        scanf("%d", &a);
                        printf("查询到该元素是：%d\n", getElem(lTable, a));
                        printf("停止查询？2：停止， 1：继续\n");
                        scanf("%d", &stop);
                        TraverseList(lTable);
                    }
                        break;
                    case 3: //-----根据位置查询元素
                   {
                       printf("输入查询元素：");
                       ElemType a;
                       scanf("%d", &a);
                       int index = getIndex(lTable, a);
                       for (int i = 0; i < sizeof(index)/sizeof(int); i++) {
                           printf("查询到该元素的位置是：%d\n", index);
                       }
                       printf("停止c ? 2：停止， 1：继续\n");
                       scanf("%d", &stop);
                       TraverseList(lTable);
                   }
                        break;
                    case 4:
                    {
                        printf("输入删除元素：");
                        ElemType a;
                        scanf("%d", &a);
                        deleteElem(&lTable, a);
                        printf("停止c ? 2：停止， 1：继续\n");
                        scanf("%d", &stop);
                        TraverseList(lTable);
                    }
                        break;
                    case 5:
                    {
                        printf("输入删除位置：");
                        ElemType a;
                        scanf("%d", &a);
                        deleteElemAtIndex(&lTable, a);
                        printf("停止c ? 2：停止， 1：继续\n");
                        scanf("%d", &stop);
                        TraverseList(lTable);
                    }
                        break;
                    case 6:
                    {
                        printf("清空表....\n");
                        clearTable(&lTable);
                        TraverseList(lTable);
                        Status empty = isEmpty(lTable);
                        printf("%s空表\n", empty == OK ? "是" : "不是");
                    }
                        break;
                    default:
                        break;
                }
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    printf("数据结构与算法\n");
    printf("选择测试项目\n1. 线性表\n2.单向链表\n3.双向链表\n");
    
    int selectItem;
   
    scanf("%d", &selectItem);
    switch (selectItem) {
        case 1:
             linearTableTest();
            break;
            
        default:
            break;
    }
    return 0;
}
