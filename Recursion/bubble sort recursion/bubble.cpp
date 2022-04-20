#include <iostream>
using namespace std;
void sortArray (int a[], int n){
	if(n<=1){
		return;
	}
	bool swapped=false;
	for(int i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			swap(a[i],a[i+1]);
			swapped=true;
		}
	}
	if(!swapped){return;}
	sortArray(a,n-1);
}
int main()
{
	int a[8]={2,3,1,34,7,5,6,44};
	int n=sizeof(a)/sizeof(a[0]);
	sortArray(a,n);
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}