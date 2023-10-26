// 单链表——没有头结点

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
    struct node *link; // 节点的指针域
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

// 查找表中第 i 个元素的值，通过 x 返回
int Find(struct singlist * list, int i, Element *x){
    if(i < 0 || i > list->n - 1){
        // 越界检查
        return ERROR;
    }

    struct Node *tmp; // 遍历单链表的指针
    tmp = list->frist;
    for(int j = 0; j < i; j++){
        tmp = tmp->link; // 从头指针开始遍历
    }
    *x = tmp->element; 
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

// 删除表中第 i 个元素，i = 0表示删除头结点
int Delete(struct singlist * list, int i){
    struct Node *p, *q; // 指向第i个元素和他的前向结点
    int j;
    if(!list->n){
        return ERROR;
    }
    if(i > list->n - 1 || i < 0){
        return ERROR;
    }
    q = list->frist;
    p = list->frist;
    for(j = 0; j < i - 1; j++){
        q = q->link; // 找到第 i - 1 个元素
    }
    if(i == 0){
        list->frist = list->frist->link; // 删除头结点
    }else{
        p = q->link;
        q->link = p->link; // 删除第i个元素
    }
    free(p);
    list->n--;
    return OK;
}

// 输出
int Output(struct singlist * list){
    struct Node * temp;
    if(!list->n){
        return ERROR;
    }
    temp = list->frist;
    while(p){
        printf("%d", temp->element);
        temp = temp->link;
    }
    return OK;
}

// 销毁
void Destroy(struct singlist * list){
    struct Node * p;
    while(list->frist){
        p = list->frist->link;
        free(list->frist);
        list->frist = p;
    }
}

int main()
{
    struct singlist list;
    init(&list);
    return 0;
}
