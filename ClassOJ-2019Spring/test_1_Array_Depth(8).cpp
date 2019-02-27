#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<sstream>
#include<iomanip>
#define LL long long         //9223372036854775807(19位) 2的63次方
#define debug cout<<"******"<<endl;
#define INF 0x3fffffff
#define MAX 101000
using namespace std;

int sum(vector<int> vec)
{
    int res = 0;
    for(int i = 0; i < vec.size(); i++)
    {
        res += vec[i];
    }
    return res;
}
void printArr(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void adjust(vector<int> arr, vector<int> arr2)
{
    vector<int> temp;
    if (sum(arr) < sum(arr2))
    {
        temp = arr;
        arr = arr2;
        arr2 = temp;
    }
    bool ifCycle = true;
    int length = arr.size();
    while (ifCycle)
    {
        ifCycle = false;
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
            {
                int itemValue = arr[i] - arr2[j];
                int sumValue = sum(arr) - sum(arr2);
                if (itemValue <= sumValue && itemValue > 0)
                {
                    ifCycle = true;
                    int item = arr[i];
                    arr[i] = arr2[j];
                    arr2[j] = item;
                }
            }
        }
    }
    cout<<abs(sum(arr) - sum(arr2))<<endl;
}

void adjust2(vector<int> &arr, vector<int> &arr2)
{
    int len = arr.size();
    int sumA = 0, sumB = 0;
    sumA = sum(arr);
    sumB = sum(arr2);
    int dis = sumA - sumB;
    while(dis != 0){
        int mini = 0, minj = 0;
        int best = 0;
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                if(abs(dis - 2*(arr[i] - arr2[j])) < abs(dis - 2 * best)){
                    best = arr[i] - arr2[j];
                    mini = i;
                    minj = j;
                }
            }
        }
        if(best == 0)
            return;
        swap(arr[mini], arr2[minj]);
        sumA -= best;
        sumB += best;
        dis = sumA - sumB;
    }
}


int main()
{
    string line;
    stringstream ss, ss2;
    getline(cin, line);
    ss<<line;

    vector<int> arr, arr2;
    int i =0;
    while(ss>>i)
    {
        arr.push_back(i);
    }

    getline(cin, line);
    ss2<<line;
    i = 0;
    while(ss2>>i)
    {
        arr2.push_back(i);
    }
    adjust2(arr, arr2);
    //printArr(arr);
    //printArr(arr2);
    cout<<abs(sum(arr) - sum(arr2))<<endl;
    return 0;
}
