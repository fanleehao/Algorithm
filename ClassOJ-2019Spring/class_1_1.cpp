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
#define LL long long         //9223372036854775807(19λ) 2��63�η�
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff
#define MAX 101000
using namespace std;
//����һ���������飬������Ƶ�ʽ���������Ƶ����ͬ�򰴴�С��������

void printVec(int *vec, int n){
    for(int i = 0; i < n; i++){
        printf("%d ",vec[i]);
    }
    printf("\n");
}

typedef struct Node{
    int key;
    int value;
};
bool cmp(Node a, Node b){
    if(a.value == b.value)
        return a.key < b.key;
    else
        return a.value > b.value;
}

int main(){
    int T;
    scanf("%d", &T);
    Node node[61];
    int arr[61] = {0};
    while(T--){
        int N;
        scanf("%d", &N);
        for(int i = 0; i < N; i++){
            int temp;
            scanf("%d", &temp);
            arr[temp]++;

        }
        int k = 0;
        for(int i = 0; i < 61; i++){
            if(arr[i] != 0){
                node[k].key = i;
                node[k].value = arr[i];
                k++;
            }
        }
        //����
        sort(node, node + k, cmp);
        for(int i = 0; i < k; i++){
            //printf("%d -> %d\n", node[i].key, node[i].value);
            int len = node[i].value;
            for(int j = 0; j < len; j++){
                //printf("%d ", node[i].key);
                cout<<node[i].key<<" ";
            }
        }
        cout<<"\n";
    }
}
