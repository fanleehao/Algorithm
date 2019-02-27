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
//序号乘方
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        LL P;
        cin>>P;
        LL res = 0;
        LL up_bound = sqrt(P * 1.0);
        //cout<<up_bound<<endl;
        for(LL i = 1; i <= up_bound; i++){
            if(P >= i * i){
                res += 1;
                P -= i * i;
            }
            else break;
        }
        cout<<res<<endl;
    }
    return 0;
}
