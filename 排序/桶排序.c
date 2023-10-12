// 桶排序

// 适用于重复数据很多；外部排序；多线程排序；分布均匀；

// 数据结构：静态顺序表的实现

/*
核心思想：
    桶排序法是一种基于计数的排序算法。
    它的基本思想是将要排序的数据分到几个有序的桶里，
    每个桶里的数据再单独进行排序。
    桶内排完序之后，再把每个桶里的数据按照顺序依次取出，
    组成的序列就是排好序的序列。

    1、确定要排序的元素的范围，并选择合适的桶的数量。
    2、创建对应数量的空桶，用于存放待排序的元素
    3、遍历待排序的元素列表，根据每个元素的值将其分配到相应的桶中
    4、对每个非空桶中的元素进行排序：插入、快速、归并、基数排序

*/

/*
    稳定性：取决于桶内排序算法
    排序趟数：取决于桶内排序算法
    时间复杂度：
        - 最好时间复杂度：O(n) 
        - 最坏时间复杂度：O(n) 
        - 平均时间复杂度：O(n) 
        - 空间复杂度：取决于桶内排序算法

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 10
#define BUCKET_COUNT 10

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

struct bucket{
    int count;
    struct entry * array;
};


// 直接插入排序
void InsertSort(struct bucket *bucket){
    int i, j; // i为待插入元素的下标
    struct entry insertitem;
    for(i = 1; i < bucket->count; i++){
        insertitem = bucket->array[i];
        for(j = i - 1; j >= 0; j--){
            // 如果有小于有序序列的元素插入，将不断的把有序序列元素后移
            if(insertitem.key < bucket->array[j].key)
            {
                bucket->array[j + 1] = bucket->array[j];
            }else {
                break;
            }
        }
        bucket->array[j + 1] = insertitem; // 插入元素
    }
}


void BucketSort(struct List * list){
    // 创建桶数组
    struct bucket buckets[BUCKET_COUNT];
    
    // 初始化
    for(int i = 0; i < BUCKET_COUNT; i++){
        buckets[i].array = NULL;
        buckets[i].count = 0;
    }

    // 将元素放入桶中
    for(int i = 0; i < list->n; i++){
        int bucketIndex = list->arry[i].key / BUCKET_COUNT;
        // 50 是待排序序列的最大值, 确定该元素应该被分到哪个桶内
        struct bucket * bucket1 = &buckets[bucketIndex];
        bucket1->array = realloc(bucket1->array, (bucket1->count + 1) * sizeof(struct entry));
        memcpy(&bucket1->array[bucket1->count], &list->arry[i], sizeof(struct entry));
        bucket1->count++;
    }

    // 对每个桶中的数据排序
    for(int i = 0; i < BUCKET_COUNT; i++){
        InsertSort(&buckets[i]);
    }

    // 合并
    int index = 0;
    for(int i = 0; i < BUCKET_COUNT; i++){
        struct bucket *bucket1 = &buckets[i];
        for(int j = 0; j < bucket1->count; j++){
            list->arry[index] = bucket1->array[j];
            index++;
        }
        bucket1->count = 0;
        free(bucket1->array);
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

    BucketSort(&list);

    for(int i = 0; i < list.n; i++){
        printf("%d ", list.arry[i].key);
    }
    printf("\n");
    
    return 0;
}
