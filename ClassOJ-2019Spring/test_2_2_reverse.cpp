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
#define LL long long         //9223372036854775807(19λ) 2��63�η�
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff
#define MAX 101000
using namespace std;

//����
//�����������̣�
//����1�����ÿ���ָ���ҵ��м��λ�ã������ָ��ͷ��㣬Ȼ��pSlowһ����һ����pFastһ����������
       //ע�ⲻ��Ҫ�����������������������ż������
//����2������벿��ָ�뷭ת��
//����3������ٽ���һ�α�����һ����ǰ���һ���Ӻ���ǰ��

typedef struct Node{
    char value;
    Node* next;
}Link;

bool Reverse(Link * root, int n){
    //�жϻ���
    Link *p = root->next;
    if(p == NULL){
        return false;
    }
    else if(p->next == NULL){
        return true;
    }
//    //ʹ�ÿ���ָ��������ҵ��м�Ľڵ�
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
    while(n != NULL){    //ָ�뷴ת
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
//��������Ϊn������
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
