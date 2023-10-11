// 直接插入排序   

// 数据基本有序的待排序序列（逆序对少，降低了时间复杂度，排序速度快）

// 数据结构：静态顺序表的实现

/*
核心思想：
    1、从只包含一个数据元素的有序序列开始，
        不断地将待排序数据元素有序的插入到这个有序序列中。
    2、直到待排序序列中只剩下一个待排序数据元素。退出条件

举例说明：
        
        有序序列：24
第一趟： 待排序列：   29 45 |24| 11
        排序结果：24 29 45 |24| 11
        
        有序序列：24 29
第二趟： 待排序列：      45 |24| 11
        排序结果：24 29 45 |24| 11

        有序序列：24 29 45
第三趟： 待排序列：         |24| 11
        排序结果：24 29 45 |24| 11

        有序序列：24 |24| 29 45
第四趟： 待排序列：              11
        排序结果：11  24 |24| 29 45 

 
    结束
*/

/*
    稳定性：稳定
    排序趟数：n - 1
    时间复杂度：
        - 最好时间复杂度：O(n)
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




// 直接插入排序
void InsertSort(struct List *list){
    int i, j; // i为待插入元素的下标
    struct entry insertitem;
    for(i = 1; i < list->n; i++){
        insertitem = list->arry[i];
        for(j = i - 1; j >= 0; j--){
            // 如果有小于有序序列的元素插入，将不断的把有序序列元素后移
            if(insertitem.key < list->arry[j].key)
            {
                list->arry[j + 1] = list->arry[j];
            }else {
                break;
            }
        }
        list->arry[j + 1] = insertitem; // 插入元素
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

    InsertSort(&list);

    for(int i = 0; i < list.n; i++){
        printf("%d ", list.arry[i].key);
    }
    printf("\n");
    
    return 0;
}
