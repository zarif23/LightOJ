#include<bits/stdc++.h>

using namespace std;

int p[100000];

int leftsearch(int lo, int hi, int x)
{
	int mid = lo + ((hi - lo) >> 1);
	while(p[lo]<x)
	{
		lo = lo + 1;
		hi = mid;
		mid = (hi+lo)/2;
	}
	return lo;
}

int rightsearch(int lo, int hi, int x)
{
	int mid = (lo+hi)/2;
	while(p[hi]>x)
	{
		hi = hi - 1;
		lo = mid;
		mid = (hi+lo)/2;
	}
	return hi;
}

int main()
{
	int T,t=0;
	scanf("%d",&T);
	while(t<T)
	{
		int n,q,i=0,j;
		scanf("%d %d",&n,&q);
		while(i<n) 
		{
			scanf("%d",p+i);
			i++;
		}
		for(i=0;i<q;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			int x,y;
			x = leftsearch(0,n,a);
			y = rightsearch(0,n,b);
			printf("%d\n",y-x);
		}
		t++;
	}
}
