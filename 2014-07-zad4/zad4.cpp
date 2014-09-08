#include <iostream>
#include <string.h>
using namespace std;

bool isPolindrom(char* a) {
	int n = strlen(a);

	for(int i=0; i<n/2; i++)
		if(a[i] != a[n-i-1])
			return false;

	return true;
}

void solve(char* a) {
	int n = strlen(a);
	int i,j;

	for(i=0; i<n; i++) {
		if(isPolindrom(a)) {
			cout<<i<<" ("<<a<<")\n";
			return; 
		}

		char x = a[0];
		for(j=0; j<n-1;j++)
			a[j] = a[j+1];
		a[j] = x;
	}

	cout<<"NO\n";
}

int main() {

	string str;
	cin>>str;
	solve((char*)str.c_str());
}