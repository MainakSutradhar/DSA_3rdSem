#include<iostream>
using namespace std;

void selection_sort(int arr[],int size){
    for(int i=0; i<size-1;i++){
        int min_index = i;
        for(int j=i+1;j<=size;j++){
            if(arr[min_index] > arr[j]){
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

void printArr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {1,4,2,3,66,2,4,8,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"The original array is : ";
    printArr(arr,size);
    selection_sort(arr,size);
    cout<<endl<<"The sorted array is : ";
    printArr(arr,size);
}