#include <bits/stdc++.h>
using namespace std;

vector<int> table[1001];

void mul(int a) {
	vector<int> &_t = table[a-1];
	vector<int> &_t1 = table[a];
 	int len = _t.size(), carry = 0, rem = 0;
	for(int i = 0; i < len; ++i) {
		rem = (_t[i]*a + carry) % 10;
		carry = (_t[i]*a + carry) / 10;
		table[a].emplace_back(rem);
	}
	while(carry) {
		table[a].emplace_back(carry%10);
		carry /= 10;
	}
}

int main() {
	table[0].emplace_back(1);
	table[1].emplace_back(1);

	for(int i = 2; i <= 1000; ++i) {
		mul(i);
	}

	for(int a; ~scanf("%d", &a); ) {
		int len = table[a].size();
		printf("%d!\n", a);
		for(int i = len-1; i >= 0; --i) {
			printf("%d", table[a][i]);
		}
		puts("");
	}
	return 0;
}