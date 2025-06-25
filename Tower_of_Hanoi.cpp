#include<iostream>
using namespace std;

void TowerOfHanoi(int n,char source,char destination,char auxiliary){
    if(n==0)return;
    TowerOfHanoi(n-1,source,auxiliary,destination);
    cout<<"Move disc "<<n<<" from "<< source <<" to " <<destination<<endl;
    TowerOfHanoi(n-1,auxiliary,source,destination);
}

int main(){
    int number;
    char A='A',B='B',C='C';
    cout<<"Enter the number of discs : ";
    cin>>number;
    TowerOfHanoi(number,A,C,B);
}