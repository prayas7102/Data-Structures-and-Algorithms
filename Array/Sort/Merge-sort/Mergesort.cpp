#include<iostream>
using namespace std;
void Merge(int *arr,int lb, int ub){
	int mid=(lb+ub)/2;
	int len1=mid-lb+1;
	int len2=ub-mid;
	int a[len1],b[len2],i=0,j=0,c=lb;

	for (int i = 0; i < len1; ++i)
	{
		a[i]=arr[c++];
	}
	c=mid+1;
	for (int i = 0; i < len2; ++i)
	{
		b[i]=arr[c++];
	}
	c=lb;
	while(i<len1 && j<len2){
		if(a[i]<=b[j]){
			arr[c++]=a[i++];
		}
		else{
			arr[c++]=b[j++];
		}
	}

	while(i<len1){
		arr[c++]=a[i++];
	}
	while(j<len2){
		arr[c++]=b[j++];
	}
}

void MergeSort(int *arr,int lb, int ub){
	if(lb>=ub){return;}
	int mid=(lb+ub)/2;
	MergeSort(arr,lb,mid);
	MergeSort(arr,mid+1,ub);
	Merge(arr,lb,ub);
}

int main()
{
	int arr[8]={1,2,6,3,4,55,6,7};
	MergeSort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}