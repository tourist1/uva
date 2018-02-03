#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> input, int len) {
	int *dp = new int[len];

	for(int i = 0; i < len; ++i) {
		dp[i] = 1;
	}
	
	int maxlen = 0;

	for(int i = 0; i < len; ++i) {
		for(int j = i+1; j <len; ++j) {
			if(input[i] < input[j]) {
				dp[j] = max(dp[i]+1, dp[j]);
				maxlen = max(maxlen, dp[j]);
			}
		}
	}
	delete []dp;
	return maxlen;
}

int main() {
	int test, lines;
	scanf("%d", &test);
	while(test-- > 0) {
		vector<int> in;
		scanf("%d", &lines);
		
		for(int i = 0; i < lines; ++i) {
			int a;
			scanf("%d", &a);
			in.emplace_back(a);
		}
		
		if(lines == 1) {
			printf("1\n");
			continue;
		}

		// make palindrome
		vector<int> rev(in.rbegin(), in.rend());
		rev.insert(rev.end(), in.begin(), in.end());
		
		printf("%d\n", lis(rev, 2*lines));
	}
	return 0;
}