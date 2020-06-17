 #include <iostream>

using namespace std;

long long int m, Num[20];
int n, used[20];

void sum(int, long long int);

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> Num[i];
	sum(0, 0);
	
	return 0;
}

void sum(int d, long long int s)
{
	if (s== m)
	{
		for (int i=0; i<d; i++)
			if (used[i]) cout << Num[i] << " ";
		cout << endl;
		return;
	}
	if (d==n || s> m) return;
	used[d]= 1;
	sum(d+1, s+Num[d]);
	used[d]= 0;
	sum(d+1, s);	
}