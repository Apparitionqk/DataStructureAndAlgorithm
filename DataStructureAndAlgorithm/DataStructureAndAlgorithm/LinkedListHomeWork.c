//
//  LinkedListHomeWork.c
//  DataStructureAndAlgorithm
//
//  Created by 123 on 2020/4/8.
//  Copyright © 2020 齐科. All rights reserved.
//

#include "LinkedListHomeWork.h"

Status mergeTwoList(LinkList *La, LinkList *Lb, LinkList *Lc) {
    LinkList pa, pb, pc, temp;
    pa = (*La)->next;
    pb = (*Lb)->next;
    *Lc = *La;
    pc = *La;
    while (pa && pb) {
        if (pa->data < pb->data) {
            pc->next = pb;
            pc = pa;
            pa = pa->next;
        }else if (pa->data > pb->data) {
            pc->next = pa;
            pc = pb;
            pb = pb->next;
        }else {
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
    pa = (*La)->next;
    pb = (*Lb)->next;
    *Lc = *La;
    pc = *La;
    while (pa && pb) {
        if (pa->data == pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            
            //释放pb
            temp = pb;
            pb = pb->next;
            free(temp);
        }else if (pa->data < pb->data) {
            temp = pa;
            pa = pa->next;
            free(temp);
        }else {
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
    p = (*L)->next;
    (*L)->next = NULL;
    
    while (p != NULL) {
        q = p->next;//不丢失对结点的控制
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


Status revers(int *pre, int *left, int right) {
    return OK;
}
