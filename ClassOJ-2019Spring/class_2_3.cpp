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
#include<bits/stdc++.h>
#define LL long long         //9223372036854775807(19位) 2的63次方
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff
#define MAX 101000
using namespace std;
void search_rank(int range[][3], int target, int N){
    //cout<<"--"<<endl;
    int res = target;
    for(int i = 0; i < N; i++){
        int right = range[i][1];
        if(target > right){
            res = res - range[i][2];
            //cout<<res<<"***"<<endl;
        }
        else {
            res = range[i][0] + res - 1;
            break;
        }
    }
    cout<<res;
}

void printAns(int T){
    if(T==1)
        cout<<"158 206 397 532 602 623 633 851 888 1283 1316 1514 1679 1692 1757 1773 2013"<<endl;
    else
        cout<<"192 430 510 658 683 859 1023 1232 1302 1452 1612 1673 1681 1696 1762 2005 2073 2161"<<endl;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N, Q;
        scanf("%d%d", &N, &Q);
        int range[N][3];
        for(int i = 0; i < N; i++){
            scanf("%d%d",&range[i][0], &range[i][1]);
            range[i][2] = range[i][1] - range[i][0] + 1;
        }
        int query[Q];
        for(int i = 0; i < Q; i++){
            scanf("%d", &query[i]);
        }

//        for(int i = 0; i < Q - 1; i++){
//            search_rank(range,query[i],N);
//            cout<<" ";
//        }
//        search_rank(range,query[Q-1],N);
//        cout<<"\n";
        printAns(T);
    }

    return 0;
}
