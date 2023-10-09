// 简单选择排序

// 数据结构：静态顺序表的实现

/*
核心思想：
    1、每一趟排序，找到待排序序列中关键字最小的数据元素，
    2、将其与待排序序列中第一个数据元素交换位置，并将其从下一趟待排序序列中移出。
    3、直到某趟排序待排序序列中仅剩下两个数据元素。 退出条件

举例说明：
        待排序列：24 29 45 |24| 11
第一趟： 
        排序结果：11 29 45 |24| 24

        待排序列：    29  45 |24| 24
第二趟：
        排序结果：11 |24| 45  29  24

        待排序列：        45  29  24
第三趟：
        排序结果：11 |24| 24  29  45

        待排序列：            29  45
第四趟：
        排序结果：11 |24| 24  29  45 

    结束
*/

/*
    稳定性：不稳定
    排序趟数：n - 1
    时间复杂度：
        - 最好时间复杂度：O(n^2)
        - 最坏时间复杂度：O(n^2)
        - 平均时间复杂度：O(n^2)
        - 空间复杂度：O(1)

*/

#include <stdio.h>

#define MaxSize 10

typedef int KeyType;  // 定义关键字类型
typedef char DataType; // 定义数据类型

struct entry{ // 定义数据元素结构体
    KeyType key;  // 排序关键字
    DataType data; // 存储的数据
};

struct List{ // 定义静态顺序表
    int n; // 待排序序列的元素数量
    struct entry arry[MaxSize]; 
};


// 从startindex到表尾范围内找到最小的关键字元素的下标
int FindMinIndex(struct List list, int startindex){
    int minindex = startindex;
    for(int i = startindex + 1; i < list.n; i++){
        if(list.arry[i].key < list.arry[minindex].key){
            minindex = i;
        }
    }
    return minindex;
}

// 交换两个元素的位置
void Swap(struct entry * arry, int i, int j){
    struct entry temp;
    if(i ==j){
        return;
    }
    temp = *(arry + i);
    *(arry + i) = *(arry + j);
    *(arry + j) = temp;
}

// 简单选择排序
void SelectSort(struct List *list){
    int minindex, startindex = 0;
    while(startindex < (list->n - 1)){
        minindex = FindMinIndex(*list, startindex);
        Swap(list->arry, startindex, minindex);
        startindex++;
    }
}


// 交换数组中两个元素的位置
int main()
{
    struct List list;
    list.n = 5;

    list.arry[0].key = 24;
    list.arry[0].data = 'a';
    list.arry[1].key = 29;
    list.arry[1].data = 'b';
    list.arry[2].key = 45;
    list.arry[2].data = 'c';
    list.arry[3].key = 24;
    list.arry[3].data = 'd';
    list.arry[4].key = 11;
    list.arry[4].data = 'e';

    for(int i = 0; i < list.n; i++){
        printf("%d ", list.arry[i].key);
    }
    printf("\n");

    SelectSort(&list);

    for(int i = 0; i < list.n; i++){
        printf("%d ", list.arry[i].key);
    }
    printf("\n");
    
    return 0;
}
