## 模板

### 1. 字符串

#### 1.1 KMP

```c++
#include<bits/stdc++.h>
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
//KMP算法
//next[j]
void makeNext(const char P[],int next[])
{
    int q,k;//q:模版字符串下标；k:最大前后缀公有长度
    int m = strlen(P);//模版字符串长度
    next[0] = 0;//模版字符串的第一个字符的最大前后缀长度为0
    for (q = 1,k = 0; q < m; ++q)//for循环，从第二个字符开始，依次计算每一个字符对应的next值
    {
        while(k > 0 && P[q] != P[k])//递归的求出P[0]···P[q]的最大的相同的前后缀长度k
            k = next[k-1];          //不理解没关系看下面的分析，这个while循环是整段代码的精髓所在，确实不好理解
        if (P[q] == P[k])//如果相等，那么最大相同前后缀长度加1
        {
            k++;
        }
        next[q] = k;
    }
}
//index
void KMP(const char T[], const char P[], int next[]){
    int n,m;
    int i,q;
    n = strlen(T);
    m = strlen(P);
    makeNext(P, next);
    for(i=0,q=0;i<n;i++){
        while(q > 0 && P[q] != T[i])
            q = next[q-1];
        if(P[q] == T[i])
            q++;
        if(q==m){
            printf("Pattern occurs with shift:%d\n",(i-m+1));
        }
    }
}
int main()
{
    int i;
    int next[20]={0};
    char T[] = "ababxbababcadfdsss";
    char P[] = "abc";
    printf("%s\n",T);
    printf("%s\n",P );
    // makeNext(P,next);
    KMP(T,P,next);
    for (i = 0; i < strlen(P); ++i)
    {
        printf("%d ",next[i]);
    }
    printf("\n");
    return 0;
}
```

#### 1.2 



&nbsp;

### 2 树

#### 2.1 构建树

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size() - 1;
        return buildTree(preorder, 0, len, inorder, 0, len);
    }
    TreeNode *buildTree(vector<int>& preorder, int preL, int preR, vector<int>& inorder, int inL, int inR){
        if(preL > preR) //遍历到头
            return NULL;
        int index = inL;
        while(preorder[preL] != inorder[index])
            index++;
        int numL = index - inL;
        TreeNode* root = new TreeNode(preorder[preL]);
        root->left = buildTree(preorder, preL+1, preL+numL, inorder, inL, index-1);
        root->right = buildTree(preorder, preL+numL+1, preR, inorder, index+1, inR);
        return root;
    }
};
```

 

### 3 递归

#### 3.1 棋盘覆盖

```c++
//棋盘覆盖问题
int Pan[1024][1024];
int T=1;
//子棋盘的起点（Prow,Pcol）
//大小为Size=2^n;
//特殊点在(x,y)
void chessPan(int Prow, int Pcol, int x, int y, int Size)
{
    if(Size==1) //递归结束
        return;
    int t = T++;    //每一个标记自增，来标记“L”
    int s = Size / 2;    //棋盘中间的行、列号(相等的)
    //检查特殊方块是否在左上角子棋盘中
    if ( x<Prow+s && y<Pcol+s )              //在
        chessPan( Prow, Pcol, x, y, s);
    else         //不在，将该子棋盘右下角的方块视为特殊方块
    {
        Pan[Prow+s-1][Pcol+s-1]=t;
        chessPan( Prow, Pcol, Prow+s-1, Pcol+s-1, s );
    }
    //检查特殊方块是否在右上角子棋盘中
    if ( x<Prow+s && y>=Pcol+s )               //在
        chessPan(Prow, Pcol+s, x, y, s );
    else          //不在，将该子棋盘左下角的方块视为特殊方块
    {
        Pan[Prow+s-1][Pcol+s]=t;
        chessPan( Prow, Pcol+s, Prow+s-1, Pcol+s, s );
    }
    //检查特殊方块是否在左下角子棋盘中
    if ( x>=Prow+s && y<Pcol+s )              //在
        chessPan( Prow+s, Pcol, x, y, s );
    else            //不在，将该子棋盘右上角的方块视为特殊方块
    {
        Pan[Prow+s][Pcol+s-1]=t;
        chessPan( Prow+s, Pcol, Prow+s, Pcol+s-1, s );
    }
    //检查特殊方块是否在右下角子棋盘中
    if ( x>=Prow+s && y>=Pcol+s )                //在
        chessPan( Prow+s, Pcol+s, x, y, s );
    else         //不在，将该子棋盘左上角的方块视为特殊方块
    {
        Pan[Prow+s][Pcol+s]=t;
        chessPan( Prow+s, Pcol+s, Prow+s, Pcol+s, s );
    }
}
```



### 4 排序

#### 4.1 基数排序

```c++
int main()
{
    int ages[] = {20,45,56,44,44,26,28,24,33,22,46};
    int num = 11;
    //给若干个区间的数排序---年龄
    int timesOfAges[99];
    memset(timesOfAges, 0, 99*sizeof(int));
    for(int i = 0; i < num; i++){
        timesOfAges[ages[i]]++;
    }
    int index = 0;
    for(int i = 0; i < 99; i++){
        for(int j = 0 ; j < timesOfAges[i]; j++){
            ages[index++] = i;
        }
    }

    for(auto x:ages)
        cout<<x<<" ";
    return 0;
}
```



### 5 查找

#### 5.1 顺序查找(无序)

- 普通的，使用循环遍历即可

  ```c++
  int Sequential_Search(int *num, int n, int key){
      for(int i = 0; i < n; i++){
          if(num[i] == key)
          	return i;
      }
      return -1;
  }
  ```

- 优化：设立一个**哨兵**，可以减少判断次数，提高效率

  ```c++
  int Sequential_Search2(int *num, int n, int key){
      a[0] = key;			//哨兵
      int index = n;
      while(num[index] != key)
      	index--;
      return index;        //返回0则查找失败
  }
  ```

  &nbsp;

#### 5.2 二分查找

- 折半查找。

- 非递归：

  ```c++
  int Binary_Search(int *num, int n, int key){
      int left, right, mid;
      left = 1;  //数组为1-n下标
      right = n;
      while(left <= right){
          mid = (left + right) / 2;
          if(num[mid] < key)
              left = mid + 1;
          else if(num[mid] > key)
              right = mid - 1;
          else
              return mid;
      }
      return 0;
  }
  ```

- 递归：

  ```c++
  int Binary_Search2(int *num, int key, int left, int right){
      if(left <= right){
          int mid = (left + right) / 2;
          if(num[mid] < key)
              return Binary_Search2(num, key, mid+1, right);
          else if(num[mid] > key)
              return Binary_Search2(num, key, left, mid-1);
          else
              return mid;
      }
      return 0;
  }
  ```

- 二分查找边界问题

  ```c++
  //第一个大于或等于key的数
  int Binary_Search1(int * arr, int len, int key){
      int left = 0;
      int right = len - 1;
      while(left <= right){
          int mid = (left + right) / 2;
          if(arr[mid] >= key)
              right = mid - 1;
          else
              left = mid + 1;
      }
      return left;     //左边界
  }
  
  //找到第一个等于target的index，也就是下边界
  int Binary_Search2(int* arr, int len, int key){
      int left = 0;
      int right = len - 1;
      while(left <= right){
          int mid = (left + right) / 2;
          if(arr[mid] >= key)
              right = mid - 1;
          else
              left = mid + 1;
          if(left < len && arr[left] == key)
              return left;
      }
      return -1;
  }
  
  //最后一个小于或等于key的数
  int Binary_Search3(int * arr, int len, int key){
      int left = 0;
      int right = len - 1;
      while(left <= right){
          int mid = (left + right) / 2;
          if(arr[mid] <= key)
              left = mid + 1;
          else
              right = mid - 1;
      }
      return right;   //右边界
  }
  
  //二分查找-----找到最后一个等于target的index，也就是上边界
  int Binary_Search4(int* arr, int len, int key){
      int left = 0;
      int right = len - 1;
      while(left <= right){
          int mid = (left + right) / 2;
          if(arr[mid] <= key)
              left = mid + 1;
          else
              right = mid - 1;
          /**这里和上面一个相比，如果这个条件成立时，继续执行这个逻辑按Binary_Search3中的话，right不会动，一直到跳出循环为止；*/
          if(right >= 0 && arr[right] == key)   
              return right;
      }
      return -1;
  }
  ```

&nbsp;

#### 5.3 插值查找

- 插值查找是折半查找的，也可以按数的规律，每次折取一定比例；如1/4,3/4等；

- 公式为：`mid = left + (right - left) (key - num[left])/(num[right] - num[left]) `

- 适合在关键字分布比较均匀的情况下使用

- 细微差别在海量数据处理中有影响

  &nbsp;

#### 5.4 斐波那契查找

- 斐波那契查找：先找到数组个数在F(k-1),F(k)之间的`k`值，然后，补齐到F(k)之间的数据；
- `mid = left + F(k-1) + 1`
- 目标值在左边时，除right = mid - 1外，k = k-1;
- 目标值在右边时，除left = mid + 1外，k=k-2;

&nbsp;

#### 5.5 二叉查找树（动态）

- 二叉排序树，使用中序遍历可得到排序结果
- 二叉查找树的构建，是提高插入、查找和删除的效率；并未为了排序

&nbsp;

