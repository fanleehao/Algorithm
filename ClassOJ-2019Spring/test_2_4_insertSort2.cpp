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

int main(){
    int n,num;
    while(scanf("%d", &n)!=EOF){
        vector<int> vec;
        for(int i = 0; i < n; i++){
            scanf("%d", &num);
            vec.push_back(num);
        }
        for(int i = 1; i < n; i++){
            for(int j = i; j > 0; j--){
                if(vec[j] < vec[j-1]){
                    swap(vec[j], vec[j-1]);
                }
            }
        }
        for(int i = 0; i < n - 1; i++){
            printf("%d ", vec[i]);
        }
        printf("%d\n", vec[n - 1]);
    }
    return 0;
}
