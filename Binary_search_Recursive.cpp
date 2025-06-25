#include<iostream>
using namespace std;

int binary_search(int arr[],int low,int high,int item){
    if(high >= low){
        int mid = low + (high - low)/2;
        if(arr[mid] == item){
            return 1;
        }
        else if(arr[mid] < item){
            return binary_search(arr,mid+1,high,item);
        }
        return binary_search(arr,low,mid-1,item);
    }
    return 0;
}


int main() {
    int item, size;
    int arr[] = {2, 3, 4, 7, 10, 30};

    cout << "Enter the element to be searched: ";
    cin >> item;

    size = sizeof(arr) / sizeof(arr[0]);
    int result = binary_search(arr, 0, size - 1, item);

    if (result == 1) {
        cout << "\nElement is present in the array" << endl;
    } else {
        cout << "\nElement is not present in the array" << endl;
    }

    return 0;
}