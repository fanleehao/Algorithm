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
    int i,k;//i:模版字符串下标；k:最大前后缀公有长度
    int m = strlen(P);//模版字符串长度
    next[0] = 0;//模版字符串的第一个字符的最大前后缀长度为0
    for (i = 1,k = 0; i < m; ++i)//for循环，从第二个字符开始，依次计算每一个字符对应的next值
    {
        while(k > 0 && P[i] != P[k])//递归的求出P[0]···P[i]的最大的相同的前后缀长度k
            k = next[k-1];          //不理解没关系看下面的分析，这个while循环是整段代码的精髓所在，确实不好理解
        if (P[i] == P[k])//如果相等，那么最大相同前后缀长度加1
        {
            k++;
        }
        next[i] = k;
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



&nbsp;

### 6 排列组合

#### 6. 1 计算组合数C(n,m)

计算C(n,m)的方式，常见的几种；分别能够满足一定的需要；

- 方法1：暴力。一般而言，暴力最多只能得到n<15以内的值。10!=3628800,14!=87,178,291,200，一般如果4字节的int型为2,147,483,648.  通常n一般到12就会溢出了。用Long Long或者高精度，可以再适当提高，不过都是较小的两位数（20左右）。

  ```c++
  int Combination(int n, int m) 
  { 
      const int M = 10007;     //结果取模
      int ans = 1; 
      for(int i=n; i>=(n-m+1); --i) 
          ans *= i; 
      while(m) 
          ans /= m--; 
      return ans % M; 
  }
  ```

- 方法2：递推+打表。根据公式C(n,m) = C(n-1,m) + C(n-1, m-1); 可以构建一个二维表。一般可以达到n=10000左右。查询时间短，构建时间为O(n^2^).

  ```c++
  const int M = 10007; 
  const int MAXN = 1000; 
  int C[MAXN+1][MAXN+1]; 
  void Initial() 
  { 
      int i,j; 
      for(i=0; i<=MAXN; ++i) 
      { 
          C[0][i] = 0; 
          C[i][0] = 1; 
      } 
      for(i=1; i<=MAXN; ++i) 
      { 
          for(j=1; j<=MAXN; ++j) 
          C[i][j] = (C[i-1][j] + C[i-1][j-1]) % M; 
      } 
  } 
  int Combination(int n, int m) 
  { 
      return C[n][m]; 
  } 
  ```

- 方法3：**质因数**分解法，C(n,m)=n!/m!*(n-m)!，假设某一个质因数p在n!中出现次数为a，在m!中出现b次，在(n-m)!中出现c次，则最终结果为（a-b-c）次。C(n,m)=p~1~^a1-b1-c1^p~2~^a2-b2-c2^…p~k~^ak-bk-ck^.   n!分解后p的次数为：**n/p+n/p^2^+…+n/p^k^ **。这种方法一般能达到n=10000000左右，但是数很大的时候，内存消耗也大。

  其中的生成某个区间的质数方法：

  ```c++
  vector<int> produce_prim_number(){   //生产质数 
      vector<int> prim; 
      prim.push_back(2); 
      int i,j; 
      for(i=3;i*i<=maxn;i+=2){ 
          if(!arr[i]) { 
              prim.push_back(i); 
              for(j=i*i;j<=maxn;j+=i) 
                  arr[j]=true; 
          } 
      } 
      while(i<maxn){ 
          if(!arr[i]) 
              prim.push_back(i); 
          i+=2; 
      } 
      return prim; 
  } 
  ```

  ```c++
  const int maxn=1000000; 
  bool arr[maxn+1]={false}; 
  vector<int> produce_prim_number(){   //生产质数 
      vector<int> prim; 
      prim.push_back(2); 
      int i,j; 
      for(i=3;i*i<=maxn;i+=2){ 
          if(!arr[i]) { 
              prim.push_back(i); 
              for(j=i*i;j<=maxn;j+=i) 
                  arr[j]=true; 
          } 
      } 
      while(i<maxn){ 
          if(!arr[i]) 
              prim.push_back(i); 
          i+=2; 
      } 
      return prim; 
  } 
  //计算n!中素数因子p的指数  
  int cal(int n,int p) { 
      int ans=0; 
      long long rec=p; 
      while(n>=rec)   { 
              ans+=n/rec; 
              rec*=p; 
      } 
      return ans; 
  } 
  //计算n的k次方对m取模，二分法  
  int pow(long long n,int k,int M) 
  { 
      long long ans=1; 
      while(k) { 
          if(k&1)  //k为奇数
              ans=(ans*n)%M;
          n=(n*n)%M; 
          k>>=1;   //除2
      } 
      return ans; 
  } 
  //计算C（n，m）  
  int combination(int n,int m) { 
      const int M=10007; 
      vector<int> prim=produce_prim_number(); 
      long long ans=1; 
      int num; 
      for(int i=0;i<prim.size()&&prim[i]<=n;++i) 
      { 
          num=cal(n,prim[i])-cal(m,prim[i])-cal(n-m,prim[i]); 
          ans=(ans*pow(prim[i],num,M)) % M; 
      } 
      return ans; 
  } 
  ```

- 方法4：*拓展的欧几里得算法*

  ```c++
  #include <stdio.h>
  const int M = 2013;
  int ff[M+5];  //打表，记录n!，避免重复计算
   
  //求最大公因数   ——辗转相除法
  int gcd(int a,int b){
      if(b==0)
          return a;
      else
          return gcd(b,a%b);
  }
   
  //解线性同余方程，扩展欧几里德定理
  int x,y;
  void Extended_gcd(int a,int b)
  {
      if(b==0)
      {
          x=1;
          y=0;
      }
      else
      {
          Extended_gcd(b,a%b);
          long t=x;
          x=y;
          y=t-(a/b)*y;
      }
  }
   
  //计算不大的C(n,m)
  int C(int a,int b)
  {
      if(b>a)
          return 0;
      b=(ff[a-b]*ff[b])%M;
      a=ff[a];
      int c=gcd(a,b);
      a/=c;
      b/=c;
      Extended_gcd(b,M);
      x=(x+M)%M;
      x=(x*a)%M;
      return x;
  }
   
  //Lucas定理
  int Combination(int n, int m)
  {
      int ans=1;
      int a,b;
      while(m||n)
      {
          a=n%M;
          b=m%M;
          n/=M;
          m/=M;
          ans=(ans*C(a,b))%M;
      }
      return ans;
  }
   
  int main()
  {
      int i,m,n;
      ff[0]=1;
      for(i=1; i<=M; i++) //预计算n!
          ff[i]=(ff[i-1]*i)%M;
      while(~scanf("%d%d",&n, &m))
      {
          printf("%d\n",Combination(n,m));
      }
      return 0;
  }
  ```

&nbsp;

#### 6.2 下一个排列

- 递归的方法：求下一个子数组的全排列。

  - 将每个元素都与子数组的第一个元素交换，
  - 再求剩余部分的全排列，
  - 求完后再交换会来，复原原数组。

  ```c++
  void swap(int &a,int &b){
      int temp=a;
      a=b;
      b=temp;
  }
  void perm(int list[],int low,int high){
      if(low==high){   //当low==high时,此时list就是其中一个排列,输出list
          for(int i=0;i<=low;i++)
              cout<<list[i];
          cout<<endl;
      }else{
          for(int i=low;i<=high;i++){//每个元素与第一个元素交换
              swap(list[i],list[low]); 
              perm(list,low+1,high); //交换后,得到子序列,用函数perm得到子序列的全排列
              swap(list[i],list[low]);//最后,将元素交换回来,复原,然后交换另一个元素
          }
      }
  }
   
  int main()
  {
      int list[]={1,2,3};
      perm(list,0,2);   //必须有序
      return 0;
  }
  ```
