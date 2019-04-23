#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
	int i = 0, med = 0;
	vector<long long> tmp;
	for(long long a; ~scanf("%lld", &a); ) {
		tmp.emplace_back(a);
		i++;
		//sort(tmp.begin(), tmp.end());
		if(i > 1) {
			for(int j = i-1; j > 0 && tmp[j] > tmp[j-1]; --j) {
				swap(tmp[j], tmp[j-1]);
			}
		}
		med = i >> 1;
		if(i % 2) {
			printf("%lld\n", tmp[med]);
		} else {
			printf("%lld\n", (tmp[med-1]+tmp[med])/2);
		}
	}
	
	return 0;
}