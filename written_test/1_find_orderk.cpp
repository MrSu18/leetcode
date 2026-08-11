//2026-8-8：芯动科技笔试
//题目：给定长度为 `n` 的整数数组，求第 `k` 大元素；不能使用 `O(n²)` 的排序方法。数组中可存在重复元素。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int*a,int*b)
{
    int temp=*b;
    *b=*a;
    *a=temp;
}

//partition 最重要的两个指针:j：负责检查当前元素,i：记录“小元素区”的下一个位置
int partition(int *a,int left,int right)
{
    int pivot=a[right];//需要比较的随机选一个数组最右边
    int i = left,j=left;
    while(j<right)
    {
        if (a[j]<=pivot)
        {
            swap(&a[i],&a[j]);
            i++;
        }
        j++;
    }
    swap(&a[i],&a[right]);
    return i;
}

int find_orderk(int *a,int n,int k)
{
    int target=n-k;
    int left=0,right=n-1;
    int ops=0;
    while(left<=right)
    {
        ops=partition(a,left,right);
        if (ops<target)//根据 pos 缩小范围
        {
            left=ops+1; //目标在右边
        }
        else if(ops>target)
        {
            right=ops-1;//目标在左边
        }
        else
        {
            return a[ops];
        }
    }
    return -1;
}

int main()
{
    int a[] = {3, 1, 2};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 2;
    int result = find_orderk(a, n, k);
    printf("The %d-th largest element is: %d\n", k, result);
    return 0;
}