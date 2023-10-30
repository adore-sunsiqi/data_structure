// 反转链表

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

// 迭代反转 3个指针
int Iteration_reverse(struct singlist * list){
    // 从头结点遍历，每次改变结点的指针域
    if(list->frist == NULL || list->frist->link == NULL){
        return ERROR;
    }else{
        struct Node * beg = NULL;
        struct Node * mid = list->frist;
        struct Node * end = list->frist->link;

        while(1){
            mid->link = beg;
            if(end == NULL){
                break;
            }
            beg = mid;
            mid = end;
            end = end->link;
        }
        list->frist = mid;
    }
}

// 就地反转 2个指针
int local_reverse(struct singlist * list){
    if(list->frist == NULL || list->frist->link == NULL)
    {
        return ERROR;
    }
    struct Node * beg = NULL;
    struct Node * end = NULL;

    beg = list->frist;
    end = beg->link;
    while(end != NULL){
        beg->link = end->link; // 将end从链表删除
        end->link = list->frist; // 将end移动到链表头
        list->frist = end; // 头指针指向end
        end = beg->link; // 指针遍历
    }
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
    struct singlist list;
    Init(&list);
    for(int i = 0; i < 9; i++){
        Insert(&list, i - 1, i);
    }
    Output(&list);
    Iteration_reverse(&list);
    Output(&list);
    local_reverse(&list);
    Output(&list);
    return 0;
}
