#include<bits/stdc++.h>
#define Quick std :: ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pb emplace_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define MOD 1000000007
#define tf(ok) cout<<(ok ? "YES" : "NO")<<'\n';
using namespace std;
string s;
int i=0,l = 0;
int E();
int Ee();
int F()
{
	if(s[i] == '(')
	{
		i++;
		if(E())
		if(s[i] == ')')
		{
			i++;
			return 1;
		}
		else 
			return 0;
		else 
			return 0;
	}
	else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
	{
		i++;
		return 1;
	}
	return 0;
}
int Tt()
{
	if(s[i] == '*')
	{
		i++;
		if(F())
		if(Tt()) 
			return 1;
		else 
			return 0;
		else 
			return 0;
	}
	return 1;
}
	
int T()
{
	if(F())
	if(Tt()) 
		return 1;
	else 
		return 0;
	return 0;
}
int E()
{
	if(T())
	if(Ee()) 
		return 1;
	else 
		return 0;
	return 0;
}
int Ee()
{
	if(s[i] == '+')
	{
		i++;
		if(T())
		if(Ee()) 
			return 1;
		else 
			return 0;
		else 
			return 0;
	}
	return 1;
}
signed main()
{
	cout<<"\nE->TE'\nE'->+TE'/@\nT->FT'\nT'->*FT'/@\nF->(E)/ID\n\nEnter the string to be checked:";
	cin>>s;
	if(E())
	{
		if(s[i+1] == '\0') 
			cout<<"\nString is Accepted\n";
		else 
			cout<<"\nString is not accepted\n";
	}
	return 0;
}

/*
a+b
*/
