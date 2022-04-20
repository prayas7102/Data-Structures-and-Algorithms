#include<iostream>
using namespace std;
int power(int a,int b){
	// cout<<a<<b<<endl;
	if(b==0){
		return 1;
	}
	if(b==1){
		return a;
	}

	int ans=power(a,b/2);
	// cout<<ans<<a<<b<<endl;
	if(b%2==0){
		return ans*ans;
	}
	else{
		return a*ans*ans;
	}
}
int main()
{
	int a=2,b=5;
	cout<<power(a,b);
	return 0;
}