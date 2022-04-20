#include<iostream>
using namespace std;
string reverse(string s, int i, int j){
	if(i>=j){
		return s;
	}
	swap(s[i],s[j]);
	return reverse(s,i+1,j-1);
}
int main(){
	string s = "prayas";
	string s1 =reverse(s,0,s.length()-1);
	cout<<s<<endl<<s1;
	return 0;
}