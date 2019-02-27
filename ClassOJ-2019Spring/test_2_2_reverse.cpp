#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<sstream>
#include<iomanip>
#include<stack>
#include<map>
#define LL long long         //9223372036854775807(19位) 2的63次方
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff
#define MAX 101000
using namespace std;

//回文
//程序运行流程：
//　　1、利用快慢指针找到中间的位置（起初均指向头结点，然后pSlow一次走一步，pFast一次走两步。
       //注意不需要区分链表结点个数是奇数还是偶数）；
//　　2、将后半部分指针翻转；
//　　3、最后再进行一次遍历，一个从前向后，一个从后向前。

typedef struct Node{
    char value;
    Node* next;
}Link;

bool Reverse(Link * root, int n){
    //判断回文
    Link *p = root->next;
    if(p == NULL){
        return false;
    }
    else if(p->next == NULL){
        return true;
    }
//    //使用快慢指针操作，找到中间的节点
//    Link *slow = p, *fast = p;
//    while(fast != NULL && fast->next != NULL){
//        fast = fast->next->next;
//        slow = slow->next;
//    }
    Link *mid, *temp = p;
    for(int i = 1; i <= n/2; i++){
        temp = temp->next;
    }
    mid = temp;
    cout<<"####:"<<mid->value<<endl;

    Link *n = mid->next;
    mid->next = NULL;
    while(n != NULL){    //指针反转
        Link *q = n->next;
        n->next = temp;
        temp = n;
        n = q;
    }
    while(p != mid){
        if(p->value != slow->value)
            return false;
        if(p->next == slow){
            return true;
        }
        p = p->next;
        slow = slow->next;
    }

    return true;
}
void printLink(Link *root){
    Link *cur;
    cur = root->next;
    while(cur != NULL){
        cout<<cur->value<<" ";
        cur = cur->next;
    }
    cout<<endl;
    cout<<"*******\n";
}
//创建长度为n的链表
Link* createLink(int n){
    Node *cur, *head, *s;
    cur = head = (Link *)malloc(sizeof(Link));
    for(int i = 1; i <= n; i++){
        s = (Link *)malloc(sizeof(Link));
        //scanf("%c", &s->value);
        cin>>s->value;
        cur->next = s;
        cur = s;
    }
    cur->next = NULL;
    return head;
}

int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        //char arr[N];
        Link *root;
        root = createLink(N);
        printLink(root);
        bool flag = Reverse(root, N);
        //cout<<flag<<endl;
//        int flag = Reverse(arr, N);
//        if(flag == 0)
//            printf("true\n");
//        else printf("false\n");
    }
    return 0;
}
