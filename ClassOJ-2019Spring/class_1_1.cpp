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
//给定一个整型数组，按出现频率进行排序，若频率相同则按大小递增排序

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
        //处理
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
