// 冒泡排序

// 数据结构：静态顺序表的实现

/*
核心思想：
    1、从前向后不断地交换相邻逆序数据元素
    2、直到所有相邻数据元素不再逆序。退出条件

举例说明：
    从小到大排序
        
第一趟： 待排序列：24 29 45 |24| 11
        排序结果：24 29 |24| 11 45
        
        
第二趟： 待排序列：24 29 |24| 11 45
        排序结果：24 |24| 11 29 45

        
第三趟： 待排序列：24 |24| 11 29 45
        排序结果：24  11 |24| 29 45

        
第四趟： 待排序列：24  11 |24| 29 45
        排序结果：11  24 |24| 29 45 

 
    结束
*/

/*
    稳定性：稳定
    排序趟数：最好 1 / 最坏 n - 1
    时间复杂度：
        - 最好时间复杂度：O(n)
        - 最坏时间复杂度：O(n^2)
        - 平均时间复杂度：O(n^2)
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

// 冒泡排序
void BubbleSort(struct List *list){
    int i, j;
    for(i = list->n - 1; i > 0; i--){ // i不能等于n，因为j+1
    // i 从 1 还是 n-1 开始不影响，建议从 n-1 开始
        bool isSwap = false;//
        for(j = 0; j < i; j++){
            if(list->arry[j].key > list->arry[j+1].key){
                Swap(list->arry, j, j + 1);
                isSwap = true;
            }
        }
        if(!isSwap){
            break;
        }
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

    BubbleSort(&list);

    for(int i = 0; i < list.n; i++){
        printf("%d ", list.arry[i].key);
    }
    printf("\n");
    
    return 0;
}
