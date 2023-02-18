#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 101
#define MAXSUM 100000
int A[MAXN];
bool dp[MAXN][MAXSUM];

// 题目可转换为从2n个数中选出n个数，其和尽量接近于给定值sum/2
int main()
{
	int n, i, k1, k2, s, u;
	cin >> n;
	for (i=1; i<=2*n; i++)
		cin >> A[i];
	int sum = 0;
	for (i=1; i<=2*n; i++)
		sum += A[i];
	memset(dp,0,sizeof(dp));
	dp[0][0]=true;
	// 对于dp[k][s]要进行u次决策，由于阶段k的选择受到决策的限制，
	// 这里决策选择不允许重复，但阶段可以重复，比较特别
	for (k1=1; k1<=2*n; k1++)//				// 外阶段k1
		for (k2=min(k1,n); k2>=1; k2--)		// 内阶段k2
			for (s=1; s<=sum/2; s++)	// 状态s
				// 有两个决策包含或不包含元素k1
				if (s>=A[k1] && dp[k2-1][s-A[k1]])//判断总和为s的数是否能够等于k2个提取的数之和
					dp[k2][s] = true;
	// 确定最接近的给定值sum/2的和
	for (s=sum/2; s>=1 && !dp[n][s]; s--);
	printf("the differece between two sub array is %d\n", sum-2*s);
}
