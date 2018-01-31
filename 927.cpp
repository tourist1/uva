#include <bits/stdc++.h>
using namespace std;

// calculate all a-n
long long cal(int ind, vector<int> coef) {
	int len = coef.size();
	long long an = 0, tmp = 1;
	for(int i = 0; i < len; ++i) {
		an += tmp*coef[i];
		tmp *= ind;
	}
	return an;
} 

int main() {
	// case num
	// a-n
	int c, a, tmp, d, k;

	scanf("%d", &c);
	while(c-- > 0) {
		vector<int> coef;
		scanf("%d", &a);
		while(a-- >= 0) {
			scanf("%d", &tmp);
			coef.emplace_back(tmp);
		}
		scanf("%d%d", &d, &k);
		int index = ceil((-1+sqrt(1+8*k/d))/2);

		//cout << "index = " << index << endl;

		printf("%lld\n", cal(index, coef));
	} 
	return 0;
}