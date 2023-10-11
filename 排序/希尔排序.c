// 希尔排序

// 数据结构：静态顺序表的实现

/*
核心思想：
    1、改进的直接插入排序，给直接插入排序分组。
*/

/*
    稳定性：不稳定
    排序趟数：n - 1
    时间复杂度：
        - 最好时间复杂度：O(n^1.3) 
        - 最坏时间复杂度：O(n^2) 
        - 平均时间复杂度：O(nlogn) 
        - 空间复杂度：O(1)

*/

#include <stdio.h>
#include <stdbool.h>

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

// 希尔排序
void ShellSort(struct List * list){
    int i, j, gap; // gap分组大小
    struct entry temp;
    for(gap = list->n >> 1; gap > 0; gap >>= 1){
        for(i = gap; i < list->n; i++){
            temp = list->arry[i];
            for(j = i - gap; j >= 0 && list->arry[j].key > temp.key; j -= gap){
                list->arry[j + gap] = list->arry[j];
            }
            list->arry[j + gap] = temp;
        }
    }
}

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

    ShellSort(&list);

    for(int i = 0; i < list.n; i++){
        printf("%d ", list.arry[i].key);
    }
    printf("\n");
    
    return 0;
}
