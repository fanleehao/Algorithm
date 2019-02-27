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
//�ο���https://blog.csdn.net/adusts/article/details/80882649
//һ�˷ֲ��Ĺ��̣����صĽ���ǣ���׼����ߵĶ�С���ұߵĶ���
int part(vector<int> &arr, int left, int right){
    //һ�˱Ƚ�
    int temp = arr[left];
    int i = left + 1, j = right;
    while(i <= j){
        //��������
        while(arr[j] > temp)
            j--;
        //��������
        while(arr[i] < temp)
            i++;
        if(i < j)
            swap(arr[i++], arr[j--]);
        else i++;
    }
    swap(arr[j], arr[left]);
    return j;
}

void quickSort(vector<int> &arr, int left, int right){
    //�������
    if(left > right)
        return;
    int p = part(arr, left, right);
    //��߼�������
    quickSort(arr, left, p - 1);
    //�ұ�
    quickSort(arr, p + 1, right);
}


int main(){
    int n, num;
    while(scanf("%d", &n)!=EOF){
        vector<int> vec;
        for(int i = 0; i < n; i++){
            scanf("%d", &num);
            vec.push_back(num);
        }
        //printf("---%d----\n", vec.size());
        quickSort(vec, 0, n - 1);
        for(int i = 0; i < vec.size() - 1; i++)
            printf("%d ", vec[i]);
        printf("%d\n", vec[vec.size() - 1]);
    }
    return 0;

}



//
//
//
//#include <stdio.h>
//int a[101],n;//����ȫ�ֱ�����������������Ҫ���Ӻ�����ʹ��
//void quicksort(int left, int right) {
//	int i, j, t, temp;
//	if(left > right)
//		return;
//    temp = a[left]; //temp�д�ľ��ǻ�׼��
//    i = left;
//    j = right;
//    while(i != j) { //˳�����Ҫ��Ҫ�ȴ��ұ߿�ʼ��
//    	while(a[j] >= temp && i < j)
//    		j--;
//    	while(a[i] <= temp && i < j)//�����ұߵ�
//    		i++;
//    	if(i < j)//�����������������е�λ��
//    	{
//    		t = a[i];
//    		a[i] = a[j];
//    		a[j] = t;
//    	}
//    }
//    //���ս���׼����λ
//    a[left] = a[i];
//    a[i] = temp;
//    quicksort(left, i-1);//����������ߵģ�������һ���ݹ�Ĺ���
//    quicksort(i+1, right);//���������ұߵ� ��������һ���ݹ�Ĺ���
//}
//int main() {
//	int i;
//    //��������
//	scanf("%d", &n);
//	for(i = 1; i <= n; i++)
//		scanf("%d", &a[i]);
//    quicksort(1, n); //�����������
//    //��������Ľ��
//    for(i = 1; i < n; i++)
//    	printf("%d ", a[i]);
//    printf("%d\n", a[n]);
//    return 0;
//}
