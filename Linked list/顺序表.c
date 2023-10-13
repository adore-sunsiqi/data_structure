// 顺序表

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define OVERFLOW 2 // 上溢
#define UNDERFLOW 3 // 下溢
#define NOTPRESENT 4 // 元素不存在
#define DUPLICATE 5 // 有重复元素

typedef int ElemType;

struct SeqList{
    int n;//顺序表的长度
    int maxLength; //顺序表的最大允许长度
    ElemType * element;
};

// 初始化
int Init(struct SeqList *list, int mSize){
    list->maxLength = mSize;
    list->n = 0;
    list->element = (ElemType*)malloc(sizeof(ElemType)*mSize);
    if(!list->element){
        return ERROR;
    }
    return OK;
}

// 查找表中元素i的值
int Find(struct SeqList *list, int i, ElemType * x){
    // 通过 x 返回查找结果
    if(i > list->n - 1 || i < 0){
        return ERROR;
    }
    *x = list->element[i];
    return OK;
}

// 在元素list->element[i]之前插入新元素x，i = -1表示插入在最前面
int Insert(struct SeqList * list, int i, ElemType x){
    if(i < -1 || i >= list->n - 1){
        // 判断 i 是否越界
        return ERROR;
    }
    if(list->n == list->maxLength){
        // 表内空间已满
        return ERROR;
    }
    for(int j = list->n - 1; j > i; j--){
        // 从后往前后移元素
        list->element[j + 1] = list->element[j];
    }
    list->element[i + 1] = x; // 插入新元素
    list->n += 1;
    return OK;  // O(n)
}

// 删除元素list->element[i]
int Delete(struct SeqList * list, int i){
    if(i < -1 || i >= list->n - 1){
        // 判断 i 是否越界
        return ERROR;
    }
    if(!list->n){
        // 判空
        return ERROR;
    }
    for(int j = i + 1; j < list->n; j++){
        list->element[j] = list->element[j + 1];
    }
    list->n--;
    return OK;
}

// 销毁
void Destroy(struct SeqList * list){
    list->n = 0;
    list->maxLength = 0;
    free(list->element);
}

int main()
{
    return 0;
}
