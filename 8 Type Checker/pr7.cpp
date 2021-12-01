#include<bits/stdc++.h> 
using namespace std;
int main()
{
	cout<<"Enter Number of Variables : "; 
	int n; 
	cin>>n; 
	cout<<'\n'; 
	map<string,char>m1; 
	cout<<"Integer : i \n"; 
	cout<<"Float : f \n"; 
	int cntInt = 0,cntFloat = 0; 
	for(int i=0;i<n;i++)
	{ 
		cout<<"Enter name of variable : "; 
		string s; 
		cin>>s; 
		cout<<'\n'; 
		cout<<"Enter Type of Variable : ";
		char c; 
		cin>>c; 
		if(c == 'f') 
			cntFloat++; 
		if(c == 'i') 
			cntInt++; 
			m1[s] = c; 
	}
	cout<<"Enter Expression : "; 
	string s; 
	cin>>s; 
	string var = ""; 
	for(int i=0;i<s.size();i++)
	{ 
		if(s[i] == '=')
		{ 
			break; 
		} 
		else var += s[i]; 
	} 
	if((cntFloat && cntInt == 0) || (cntInt && cntFloat==0))
	{ 
		cout<<"The datatype is correct\n"; 
	} 
	else
	{ 
		if(m1[var] == 'i' && cntFloat)
		{ 
			cout<<var<<" must be type float\n"; 
		}
	} 
	return 0;
}
/*

4

a 
i
b 
i
c 
f
d 
i

a=b+c/d

*/
