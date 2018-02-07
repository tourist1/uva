#include <bits/stdc++.h>
using namespace std;

int main() {
	for(int k; ~scanf("%d", &k); ) {
		vector<int> in;
		bool jolly = true;
		for(int i = 0; i < k; ++i) {
			int a;
			scanf("%d", &a);
			in.emplace_back(a);
		}
		if(k < 2) {
			printf("Jolly\n");
			continue;
		} else if(k == 2) {
			printf((abs(in[0]-in[1]) == 1) ? "Jolly\n" : "Not jolly\n");
			continue;
		}

		
		vector<int> diff;
		for(int i = 0; i < k-1; ++i)
			diff.emplace_back(abs(in[i]-in[i+1]));

		sort(diff.begin(), diff.end());

		for(int i = 0; i < k-1; ++i) {
			if(diff[i] != i+1) {
				jolly = false;
				break;
			}
		}
		printf((jolly)?"Jolly\n" : "Not jolly\n");
	}
	return 0;
}