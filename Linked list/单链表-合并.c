// 将两个有序递增的单链表合并成一个单链表

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define OVERFLOW 2 // 上溢
#define UNDERFLOW 3 // 下溢
#define NOTPRESENT 4 // 元素不存在
#define DUPLICATE 5 // 有重复元素

typedef int Element;

struct Node{
    Element element; // 数据域
    struct Node *link; // 节点的指针域
};
struct singlist{
    struct Node * frist; // 单链表头指针
    int n; // 单链表中数据个数
};

// 初始化
int Init(struct singlist *list){
    list->frist = NULL;
    list->n = 0;
    return OK;
}

// 在单链表的第 i 个元素之后插入新元素 x。
int Insert(struct singlist * list, int i, Element x){
    if(i < -1 || i > list->n - 1){
        // 越界检查
        return ERROR;
    }

    struct Node * p; // 为 x 创建一个新结点
    p = (struct Node *)malloc(sizeof(struct Node));
    p->element = x;
    
    if(i > -1){
        // 遍历单链表找第i个位置
        struct Node * temp;
        temp = list->frist;
        for(int j = 0; j < i; j++){
            temp = temp->link;
        }
        p->link = temp->link;
        temp->link = p;
    } else{
        // i = -1 插入在头结点前
        p->link = list->frist;
        list->frist = p;
    }
    list->n++;
    return OK;
}

// 合并
int MergeList(struct singlist * list_a, struct singlist * list_b){
    // 用链表list_b保存最后结果
    struct Node * pa = list_a->frist;
    struct Node * pb = list_b->frist;
    struct Node * tp = NULL;
    struct Node * temp = NULL;

    if(list_a->frist == NULL){
        printf("list_a是空链表\n");
    }
    if(list_b->frist == NULL){
        printf("list_b是空链表\n");
    }

    while(pa != NULL && pb != NULL){
      
        if(pa->element >= pb->element){
            tp = pb;
            pb = pb->link;
        }
        else{
            temp = pa;
            pa = pa->link;
            temp->link = pb;
            if(tp == NULL){
                tp = temp;
                list_b->frist = tp;
            }else{
                tp->link = temp;
            }
                tp = tp->link;
        }
    }
    if(pa != NULL){
        tp->link = pa;
    }

    list_b->n = list_a->n + list_b->n;

    return OK;

}

// 输出
int Output(struct singlist * list){
    struct Node * temp;
    if(!list->n){
        return ERROR;
    }
    temp = list->frist;
    while(temp){
        printf("%d", temp->element);
        temp = temp->link;
    }
    printf("\n");
    return OK;
}

int main()
{
    struct singlist list_a, list_b;

    Init(&list_a);
    for(int i = 0; i < 9; i++){
        Insert(&list_a, i - 1, 2*i + 1);
    }
    printf("list_a:");
    Output(&list_a);

    Init(&list_b);
    for(int i = 0; i < 9; i++){
        Insert(&list_b, i - 1, 2*i + 2);
    }
    printf("list_b:");
    Output(&list_b);


    MergeList(&list_a, &list_b);
    Output(&list_b);
    return 0;
}
