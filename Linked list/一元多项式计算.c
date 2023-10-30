// 使用带表头结点的单循环链表表示多项式，
// 完成一元整系数多项式的算数运算

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define OK 1

typedef int Element;

struct PNode{
    Element coef; // 系数域
    Element exp; // 指数域
    struct PNode *link; // 节点的指针域
};
struct headlist{
    struct PNode * head; // 单链表头指针
    // int n; // 单链表中数据个数
};

// 多项式的创建
void CreatePoly(struct headlist * list){
    // 创建一个带表头结点的空单循环链表
    list->head = (struct PNode *)malloc(sizeof(struct PNode));
    list->head->exp = -1; // 指针域初始化为-1
    list->head->link = list->head;

    // 循环执行数据插入，退出条件设置为输入的指数域为负数
    // 找到第一个指数域小于新结点指数域的结点，将新结点插入到该结点之前
    struct PNode * temp; // 存储新的数据的结点
    struct PNode * p, * pre; // 遍历结点的指针
    for(;;){
        temp = (struct PNode *)malloc(sizeof(struct PNode));
        printf("coef:\n");
        scanf("%d", &temp->coef);
        printf("exp:\n");
        scanf("%d", &temp->exp);
        if(temp->exp < 0){
            break;
        }
        pre = list->head;
        p = list->head->link;
        while(p && p->exp > temp->exp){
            pre = p;
            p = p->link;
        }
        pre->link = temp;
        temp->link = p;
    }

}

// 多项式加法
int Add(struct headlist * list_a, struct headlist * list_b){
    struct PNode * pa, * pb;
    struct PNode * temp;
    struct PNode * pb1 = list_b->head;
    struct PNode * pa1;
    if(list_a->head == NULL) return ERROR;
    pa = list_a->head->link; // pa指向多项式list_a的第一个结点
    pb = pb1->link; // pb指向多项式list_b的第一个结点
    while(pa->exp >= 0){
        while(pa->exp < pb->exp){
            pb1 = pb;
            pb = pb->link;
        }
        if(pa->exp == pb->exp){
            pb->coef = pa->coef + pb->coef;
            if(pb->coef == 0){
                pb1->link = pb->link;
                free(pb);
                pb = pb1->link;
                pa = pa->link;
            }else{
                pb1 = pb;
                pb = pb->link;
                pa = pa->link;
            }
        }
        else{
            temp = (struct PNode *)malloc(sizeof(struct PNode));
            temp->coef = pa->coef;
            temp->exp = pa->exp;
            temp->link = pb1->link;
            pb1->link = temp;
            pb1 = pb1->link;
            pa = pa->link;
        }
    }
    return OK;
}

// 输出
int Output(struct headlist * list){
    struct PNode * temp;
    temp = list->head->link;
    while(temp->exp >= 0){
        printf("(%d)x^(%d) + ", temp->coef, temp->exp);
        temp = temp->link;
    }
    printf("\n");
    return OK;
}


int main()
{
    struct headlist list_a, list_b;
    printf("创建list_a.....\n");
    CreatePoly(&list_a);
    Output(&list_a);
    printf("创建list_b.....\n");
    CreatePoly(&list_b);
    Output(&list_b);

    Add(&list_a, &list_b);
    Output(&list_b);

    
    return 0;
}
