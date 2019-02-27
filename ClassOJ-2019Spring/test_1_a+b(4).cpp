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

int main()
{
    int n;
    LL a;
    while(1){
        cin>>n;
        if(n == 0)break;
        a = 0;
        LL sum = 0;
        for(int i =0; i < n; i++){
            cin>>a;
            sum += a;
        }
        cout<<sum<<endl;
    }
    return 0;
}
