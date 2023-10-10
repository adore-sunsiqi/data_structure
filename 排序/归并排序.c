// 归并排序

// 数据结构：静态顺序表的实现

/*
核心思想：// 合并两个链表思路相似
    1、初始时，将待排序的 n 个数据看作 n 个待合并的有序序列，
        每个序列只包含一个数据元素

    2、将每 m 个待合并的有序序列合并成一个大的有序序列
    3、重复合并过程；直到所有数据都属于同一个有序序列

    m = 2 时， 称为两路合并排序算法

原有序列：a,b,c,d,e,f,g
第一趟排序：(a,b),(c,d),(e,f),g
第二趟排序：((a,b),(c,d)),((e,f),g)
第三趟排序：(((a,b),(c,d)),((e,f),g))
*/

/*
    稳定性：稳定
    排序趟数：logn，向下取整
    时间复杂度：
        - 最好时间复杂度：O(nlogn) 
        - 最坏时间复杂度：O(nlogn) 
        - 平均时间复杂度：O(nlogn) 
        - 空间复杂度：O(n)

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

// 序列两路合并方法
void Merge(struct List *list, struct entry * temp, int low, int num1, int num2){
    // temp用于存储合并后的数据的临时数组，
    // num1, num2是两个序列的长度
    // low是第一个序列的第一个元素的下标
    int i = low, j = low + num1;// i,j分别指向两个序列的首元素
    while(i <= low + num1 - 1 && j <= low + num1 + num2 -1){
        // 两个序列都没读完时
        if(list->arry[i].key <= list->arry[j].key){
            *temp++ = list->arry[i++]; // 把较小的数存入数组
        }else{
            *temp++ = list->arry[j++];
        }
    }
    while(j <= low + num1 + num2 -1){
        // 第一个序列读完，把第二个剩余数据写入
         *temp++ = list->arry[j++];
    }
    while(i <= low + num1 - 1){
        // 第二个序列读完，把第一个剩余数据写入
         *temp++ = list->arry[i++];
    }
}

// 归并排序
void MergeSort(struct List *list){
    struct entry temp[MaxSize];
    int low, num1, num2, i, size = 1; // size 标记子序列的长度
    while(size < list->n){
        low = 0; // 待合并序列中第一个序列的首元素下标
        while(low + size < list->n){// 至少存在两个子序列需要合并
            num1 = size;
            if(low + size * 2 < list->n){
                num2 = size;
            }else{
                num2 = list->n - low - size;
            }
            Merge(list, temp + low, low, num1, num2);
            low += num1 + num2; // 下一对待合并序列中第一个序列的首元素下标
        }
        for(i = 0; i < low; i++){// 复制一趟合并排序结果
            list->arry[i] = temp[i];
        }
        size *= 2; // 子序列长度翻倍
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

    MergeSort(&list);

    for(int i = 0; i < list.n; i++){
        printf("%d ", list.arry[i].key);
    }
    printf("\n");
    
    return 0;
}
