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
//4--插入排序
void printfVec(int *vec, int len){
    for(int i = 0; i < len - 1; i++){
        printf("%d ", vec[i]);
    }
    printf("%d", vec[len - 1]);
}
void insertSort(int *arr, int len){
    int i,j;
    int temp;
    for(i = 1; i < len; i++){
        int temp = arr[i];
        for(j = i - 1; j >= 0; j--){
            if(arr[j] > temp){
                arr[j + 1] = arr[j];
            }
            else break;
        }
        arr[j + 1] = temp;
    }
    printfVec(arr, len);
}
int main(){
    int num, len = 0;
    int arr[MAX];
    while(scanf("%d", &arr[len++])!= EOF);
//    int arr[14] = {13, 24, 3, 56, 34, 3, 78, 12, 29, 49, 84, 51, 9, 100};
    insertSort(arr, len - 1);
    return 0;
}






