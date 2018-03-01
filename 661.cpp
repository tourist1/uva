#include <bits/stdc++.h>
using namespace std;

int main() {
	int seq = 1;
	for(int n, m, c; scanf("%d%d%d", &n, &m, &c) && (n || m || c); ) {
		vector<int> in, im;
		int a;
		while(n-- > 0) {
			scanf("%d", &a);
			in.emplace_back(a);
		}
		while(m-- > 0) {
			scanf("%d", &a);
			im.emplace_back(a);
		}
		vector<bool> toggle(in.size(), false);
		int on = 0, tmp = 0, maxn = 0;
		bool blown = false;
		for(int i : im) {
			if(!toggle[i-1]) {
				tmp += in[i-1];
				toggle[i-1] = true;
			} else {
				tmp -= in[i-1];
				toggle[i-1] = false;
			}
			if(tmp > c) {
				blown = true;
				break;
			}
			maxn = max(tmp, maxn);
		}
		printf("Sequence %d\nFuse was ", seq++);
		if(blown) printf("blown.\n\n");
		else {
			printf("not blown.\n");
			printf("Maximal power consumption was %d amperes.\n\n", maxn);
		}
	}
	return 0;
}