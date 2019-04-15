#include<bits\stdc++.h>
#include<string>

using namespace std;

int K,k;

int permute(string s, string taken)
{
	if(k==K) return 0;
	if(s.empty()) 
	{
		cout<<taken<<endl;
		k++;
	}
	else
	{
		for(int i=0;i<s.length();i++)
		{
			char c = s[i];
			taken += c;
			s.erase(i,1);
			permute(s,taken);
			s.insert(i,1,c);
			taken.erase(taken.length()-1,1);
		}
	}
}

int main()
{
	int n,T,t=0;
	string al = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	scanf("%d",&T);
	while(t<T)
	{
		scanf("%d %d",&n,&K);
		string inp;
		inp = al.substr(0,n);
		k = 0;
//		cout<<inp<<endl;
		printf("Case %d:\n",t+1);
		permute(inp,"");
		t++;
	} 
	
}
