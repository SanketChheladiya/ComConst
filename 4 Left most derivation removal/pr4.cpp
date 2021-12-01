#include <bits/stdc++.h>
using namespace std;
vector<char> vars;
vector<string> newVars;
vector<vector<string>> rules, newRules;
int main() 
{
	int no_nonTerm;
	cin >> no_nonTerm;
	rules = vector<vector<string>> (no_nonTerm);
	
	for (int i = 0; i < no_nonTerm; i++) 
	{
		char leftVar; cin >> leftVar;
		vars.push_back(leftVar);
		int noRules; cin >> noRules;
		for (int j = 0; j < noRules; j++) 
		{
			string rule; cin >> rule;
			rules[i].push_back(rule);
		}
	}
	auto subsitute = [&] (vector<pair<int, string>> v, int j) 
	{
		vector<pair<int, string>> result;
		for (auto &it : v) 
		{
			string rule = it.second;
			int startIdx = it.first, len = rule.size();
			for (int i = startIdx; i < len; i++) 
			{
				if (rule[i] == vars[j]) 
				{
					for (auto prvRule : rules[j]) 
					{
						if (prvRule == "#")
						prvRule = "";
						result.push_back({i + prvRule.size(), rule.substr(0, i) + prvRule + rule.substr(i + 1)});
					}
					break;
				}
			}
		}
		return result;
	};
	
	for (int i = 0; i < vars.size(); i++) 
	{
		char leftVar = vars[i];
		for (int j = 0; j < i; j++) 
		{
			vector<string> newRules;
			for (auto &rule : rules[i]) 
			{
				vector<pair<int, string>> v = {{0, rule}}, result;
				while ((result = subsitute(v, j)).size() > 0) 
				{
					v = result;
				}
				for (auto &it : v) 
				{
					newRules.push_back(it.second);
				}
			}
			rules[i] = newRules;
		}
	}
	
	for (int i = 0; i < vars.size(); i++) 
	{
		cout << vars[i] << " : ";
		for (auto &it : rules[i]) 
		{
			cout << it << ' ';
		}
		cout << endl;
	}
	cout << "\n\n" << endl;
	for (int i = 0; i < vars.size(); i++) 
	{
		bool flg = 0;
		for (auto &rule : rules[i]) 
		{
			if (rule[0] == vars[i]) 
			{
				flg = 1;
				break;
			}
		}
		string var = string(1, vars[i]), var_ = var + "'";
		newVars.push_back(var);
		if (flg) 
		{
			newVars.push_back(var_);
			vector<string> r, r_;
			for (auto &rule : rules[i]) 
			{
				if (rule[0] == vars[i]) {
				rule = rule.substr(1);
				r_.push_back(rule + var_);
				} else {
				if (rule == "#") rule = "";
				r.push_back(rule + var_);
				}
			}
			r_.push_back("#");
			newRules.push_back(r);
			newRules.push_back(r_);
		} 
		else 
		{
			newRules.push_back(rules[i]);
		}
	}
	for (int i = 0; i < newVars.size(); i++) 
	{
		cout << newVars[i] << " : ";
		for (auto &rule : newRules[i]) 
		{
			cout << rule << ' ';
		}
		cout << endl;
	}
}

/*
	2
	A 3 ABd Aa a
	B 2 Bx b
*/
