#include<iostream>
using namespace std;



int binary_search(int arr[],int low,int high,int item){
    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid] == item){
            return 1;
        }
        else if(arr[mid] < item){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    }
    return 0;
}
int main(){
    int item,size;
    int arr[] = { 2, 3, 4, 7, 10, 30};
    cout<<"Enter the element to be searched : ";
    cin>>item;
    size = sizeof(arr)/sizeof(arr[0]);
    int result = binary_search(arr,0,size-1,item);
    if(result == 1){
        cout<<endl<<"element is present in the array";
    }
    else{
        cout<<endl<<"element is not present in the array"<<endl;
    }
}