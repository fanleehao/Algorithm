#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>
#define LL long long         //9223372036854775807(19位) 2的63次方
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff
#define MAX 101000
using namespace std;

int main(){
    LL a, b;
    while(1){
        cin>>a>>b;
        if(a==0&&b==0) break;
        else cout<<a+b<<endl;
    }
    return 0;
}
