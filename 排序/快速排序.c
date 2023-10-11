// 快速排序

// 随机分布的数据

// 数据结构：静态顺序表的实现

/*
核心思想：
    1、待排序序列中元素数量小于等于1，退出
    2、选择分割元素，进行序列划分，移动序列数据
        - 左子序列非空，所有数据元素小于等于分割元素
        - 右子序列非空，所有数据元素大于等于分割元素
    3、快速排序（左子序列）
    4、快速排序（右子序列）

序列划分：
    存在序列：array[low], array[low+1],...,array[high].
    选择array[low]作为分割元素，设置两个游动下标 i,j
    i = low; j = high + 1。只能进行 i++ , j--。
    
    1、下标 i 前进，每前进一步，将当前 array[i] 与 array[low]
        进行比较，如果 array[i] <= array[low]，则 i 继续前进；否则停止
    2、下标 j 前进，每前进一步，将当前 array[j] 与 array[low]
        进行比较，如果 array[j] >= array[low]，则 j 继续前进；否则停止
    3、如果 i >= j，交换 array[low]和array[j]，退出；否则，交换 array[i]和array[j]，回到 1。
*/

/*
    稳定性：不稳定
    排序趟数：n - 1
    时间复杂度：
        - 最好时间复杂度：O(nlogn) - 空间复杂度：O(logn)
        - 最坏时间复杂度：O(n^2) - 空间复杂度：O(n)
        - 平均时间复杂度：O(nlogn) - 空间复杂度：O(logn)
        

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

int Partition(struct List * list, int low, int high){
    // 序列划分
    int i = low, j = high + 1;
    struct entry pivot = list->arry[low];
    do{
        do{
            i++;
        }while(i <= high && list->arry[i].key < pivot.key);// i 前进
        do{
            j--;
        }while(list->arry[j].key > pivot.key);// j 前进
        if(i < j){
            Swap(list->arry, i, j);
        }

    }while(i < j);
    Swap(list->arry, low, j); // 一趟排序结束
    return j; // 分割元素下标
}

void mQuickSort(struct List *list, int low, int high){
    // 快速排序的递归函数
    int k;
    if(low < high){
        k = Partition(list, low, high);
        mQuickSort(list, low, k - 1);
        mQuickSort(list, k + 1, high);
    }
}

void QuickSort(struct List *list){
    // 主调函数
    mQuickSort(list, 0, list->n - 1);
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

    QuickSort(&list);

    for(int i = 0; i < list.n; i++){
        printf("%d ", list.arry[i].key);
    }
    printf("\n");
    
    return 0;
}
