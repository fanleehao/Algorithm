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

