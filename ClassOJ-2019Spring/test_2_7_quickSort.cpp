#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<sstream>
#include<iomanip>
#include<map>
#define LL long long         //9223372036854775807(19位) 2的63次方
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff
#define MAX 101000
using namespace std;
//参考：https://blog.csdn.net/adusts/article/details/80882649
//一趟分布的过程，返回的结果是，基准数左边的都小，右边的都大
int part(vector<int> &arr, int left, int right){
    //一趟比较
    int temp = arr[left];
    int i = left + 1, j = right;
    while(i <= j){
        //从右往左
        while(arr[j] > temp)
            j--;
        //从右往左
        while(arr[i] < temp)
            i++;
        if(i < j)
            swap(arr[i++], arr[j--]);
        else i++;
    }
    swap(arr[j], arr[left]);
    return j;
}

void quickSort(vector<int> &arr, int left, int right){
    //排序入口
    if(left > right)
        return;
    int p = part(arr, left, right);
    //左边继续排序
    quickSort(arr, left, p - 1);
    //右边
    quickSort(arr, p + 1, right);
}


int main(){
    int n, num;
    while(scanf("%d", &n)!=EOF){
        vector<int> vec;
        for(int i = 0; i < n; i++){
            scanf("%d", &num);
            vec.push_back(num);
        }
        //printf("---%d----\n", vec.size());
        quickSort(vec, 0, n - 1);
        for(int i = 0; i < vec.size() - 1; i++)
            printf("%d ", vec[i]);
        printf("%d\n", vec[vec.size() - 1]);
    }
    return 0;

}



//
//
//
//#include <stdio.h>
//int a[101],n;//定义全局变量，这两个变量需要在子函数中使用
//void quicksort(int left, int right) {
//	int i, j, t, temp;
//	if(left > right)
//		return;
//    temp = a[left]; //temp中存的就是基准数
//    i = left;
//    j = right;
//    while(i != j) { //顺序很重要，要先从右边开始找
//    	while(a[j] >= temp && i < j)
//    		j--;
//    	while(a[i] <= temp && i < j)//再找右边的
//    		i++;
//    	if(i < j)//交换两个数在数组中的位置
//    	{
//    		t = a[i];
//    		a[i] = a[j];
//    		a[j] = t;
//    	}
//    }
//    //最终将基准数归位
//    a[left] = a[i];
//    a[i] = temp;
//    quicksort(left, i-1);//继续处理左边的，这里是一个递归的过程
//    quicksort(i+1, right);//继续处理右边的 ，这里是一个递归的过程
//}
//int main() {
//	int i;
//    //读入数据
//	scanf("%d", &n);
//	for(i = 1; i <= n; i++)
//		scanf("%d", &a[i]);
//    quicksort(1, n); //快速排序调用
//    //输出排序后的结果
//    for(i = 1; i < n; i++)
//    	printf("%d ", a[i]);
//    printf("%d\n", a[n]);
//    return 0;
//}
