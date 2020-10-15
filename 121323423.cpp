#include<bits/stdc++.h>
using namespace std;



typedef long long int ll;

int main()
{
	
	int T;
	cin >> T;

	int n , m;

	while(T--)
	{
		cin >> n >> m;
		int a[n][m];	
		
		
		for(int i = 0 ;i  < n ; i++)
			for(int j = 0 ; j  < m ; j++)
				cin >> a[i][j];


		ll ans = 0;
		
		for(int i  = 0 ; i < n ; i++)
		{
			
			int b[3] = {0};
			for(int j = 0 ; j <  m ; j++)
			{
				b[0] = a[i][j];
				b[1] = a[i][m - j- 1];
				b[2] = a[n - i - 1][j];

				sort(b , b + 3);
				
				ans += (b[2] - b[1]) + (b[1] - b[0]);	
				
				a[i][j] = b[1];
				a[i][m - j - 1] = b[1];
				a[n - i -1 ][j] = b[1];
		
				
			}

		}
		
		cout << ans << endl;
	
	}
	
	return 0;
}
