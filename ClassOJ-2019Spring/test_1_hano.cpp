//#include<iostream>
//#include<math.h>
//#include<algorithm>
//#include<string.h>
//#include<stdlib.h>
//#include<stdio.h>
//#include<vector>
//#include<sstream>
//#include<iomanip>
//#define LL long long         //9223372036854775807(19位) 2的63次方
//#define debug cout<<"******"<<endl;
//#define INF 0x3fffffff
//#define MAX 101000
//using namespace std;
////refer:https://blog.csdn.net/qq_27161673/article/details/52735095
///*变量含义
//* n：圆盘数量
//*left：左柱子
//*mid：中间柱子
//*right:右柱子
//*from：起点柱子
//*to：目标柱子
//*/
////将N个盘子从左移到右边，必须经过中间 ,
//void Hanoi(int n,string left, string mid, string right, string from, string to, int * step)
//{
//    if (n==1)
//    {
//        //只有一个盘子，判断起始点-----1.起始点中有中间，则直接移动    2.否则通过中间移动两次
//        if(from == mid || to == mid)
//        {
//            //printf("%s -> %s\n", from, to);
//            //cout<<from<<" -> "<<to<<endl;
//            (*step) += 1;
//        }
//        else
//        {
//            //printf("%s -> %s\n", from, mid);
//            //printf("%s -> %s\n", mid, to);
//            //cout<<from<<" -> "<<mid<<endl;
//            //cout<<mid<<" -> "<<to<<endl;
//            (*step) += 2;
//        }
//    }
//    else
//    {
//        Hanoi(n-1, left, mid, right, from, to, step);  //A借助C，将n-1个盘子移到B;
//        //printf("%s -> %s\n", from, mid);   //A上剩余的一个盘通过中间移到C;
//        //cout<<from<<" -> "<<mid<<endl;
//        (*step)++;
//        Hanoi(n-1, left, mid, right, to, from, step);
//        //printf("%s -> %s\n", mid, to);
//        //cout<<mid<<" -> "<<to<<endl;
//        (*step)++;
//        Hanoi(n-1, left, mid, right, from, to, step);  //将B上的n-1个盘子移到C。
//    }
//    //cout<<*step<<endl;
//}
//int main()
//{
//    int step = 0;
//    string from = "left";
//    string depend = "mid";
//    string to = "right";
//    int n;
//    //cin>>n;
//    scanf("%d", &n);
//    if(n>1)
//    {
//        Hanoi(n, from, depend, to, from, to, &step);
//    }
//    //cout<<step;
//    printf("%d\n", step);
//    return 0;
//}
//
//









//hanbuota II 非递归
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<stack>

using namespace std;

enum Action{
    NO,LTOM,MTOL,RTOM,MTOR
};

int fstackTotstack(Action &a,Action preAction,Action nowAction,stack<int>&fstack,stack<int >&tstack,string from,string to)
{
    if(preAction != a&&fstack.size()!=0&&(tstack.size()==0||fstack.top()<tstack.top()))
    {
        tstack.push(fstack.top());
        fstack.pop();
        a = nowAction;
        return 1;
    }
    return 0;
}


int hannuota(int n,string left,string mid,string right)
{
    stack<int>fstack;
    stack<int>mstack;
    stack<int>tstack;
    for(int i = n;i>=1;i--)
        fstack.push(i);
    int step = 0;
    Action a = NO;
    while(tstack.size()!=n)
    {
        step += fstackTotstack(a,MTOL,LTOM,fstack,mstack,left,mid);
        step += fstackTotstack(a,LTOM,MTOL,mstack,fstack,mid,left);
        step += fstackTotstack(a,RTOM,MTOR,mstack,tstack,mid,right);
        step += fstackTotstack(a,MTOR,RTOM,tstack,mstack,right,mid);

    }
    return step;
}


int main()
{
    int n;
    string left = "left";
    string mid = "mid";
    string right = "right";
    scanf("%d", &n);
    if(n>=1){
        cout<<hannuota(n,left,mid,right)<<endl;
    }
    return 0;
}
