// 堆排序

// 空间复杂度有限

// 数据结构：静态顺序表的实现

/*
核心思想：
    1、借助堆，不断输出堆顶元素，然后将剩余调整为堆。

将待排序构建成最大堆：arry[0],array[1],...,array[n-1]
第一趟排序：将堆顶元素array[0]与堆底元素array[n-1]交换；
            调整arry[0],array[1],...,array[n-2]为最大堆
第二趟排序：将堆顶元素array[0]与堆底元素array[n-2]交换；
            调整arry[0],array[1],...,array[n-3]为最大堆
第 n-1 趟排序：将堆顶元素array[0]与堆底元素array[1]交换；
            排序结束。
*/

/*
    稳定性：不稳定
    排序趟数：n - 1
    时间复杂度：
        - 最好时间复杂度：O(nlogn) 
        - 最坏时间复杂度：O(nlogn) 
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

void Swap(struct entry *arry, int i, int j){
    struct entry temp;
    if(i ==j){
        return;
    }
    temp = *(arry + i);
    *(arry + i) = *(arry + j);
    *(arry + j) = temp;
}

// 调整为最大堆
void max_heapify(struct entry * array, int start, int end){
    int parent = start; // 父节点下标
    int son = parent * 2 + 1;// 标记子节点下标
    while(son <= end){
        // 比较两个子节点的大小，获取较大子节点的下标
        if(son + 1 <= end && array[son].key < array[son + 1].key){
            son++;
        }
        // 比较较大子节点和父节点的大小，如果子节点大于父节点则交换，否则退出
        if(array[son].key > array[parent].key){
            Swap(array, son, parent);
            parent = son;
            son = parent * 2 +1;
        }else{
            return;
        }
    }
}
// 最大堆排序
void MaxHeapSort(struct List * list){
    //从二叉树的底部向上调整，即从最后一个父节点开始
    int i;
    for(i = list->n / 2 - 1; i >= 0; i--){
        max_heapify(list->arry, i, list->n - 1); // 初始化为最大堆
    }

    for(i = list->n - 1; i > 0; i--){
       Swap(list->arry, 0, i); // 交换堆顶元素和堆低元素
       max_heapify(list->arry, 0, i - 1);
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

    MaxHeapSort(&list);

    for(int i = 0; i < list.n; i++){
        printf("%d ", list.arry[i].key);
    }
    printf("\n");
    
    return 0;
}
