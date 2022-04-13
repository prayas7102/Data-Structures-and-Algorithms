#include <iostream>

using namespace std;
bool isSorted (int a[],int sizeA){
    if(sizeA<=1){return 1;}
    if(a[sizeA-1]<a[sizeA-2]){
        return 0;
    }
    isSorted(a,sizeA-1);
}
int main()
{
    int a[5]={1,2,3,5,7};
    cout<<isSorted(a,sizeof(a)/sizeof(a[0]));
    return 0;
}
