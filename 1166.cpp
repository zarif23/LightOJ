#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T,t=0,n,i;
	scanf("%d",&T);
	while(t<T)
	{
		scanf("%d",&n);
		int N[101],swap=0;
		for(i=1;i<=n;i++) scanf("%d",&N[i]);
		for(int j=1;j<n;j++){
			for(i=1;i<=n;i++)
			{
	//			printf("%d %d\n",i,N[i]);
				if(N[i]!=i)
				{
					int temp1,temp2;
					temp1 = N[i];
					temp2 = N[temp1];
					N[temp1] = temp1;
					N[i] = temp2;
		//			printf("%d %d\n",i,N[i]);
					swap++;
				}
			}
		}
//			for(i=1;i<=n;i++) printf("%d\n",N[i]);
		t++;
		printf("Case %d: %d\n",t,swap);
	}
}
