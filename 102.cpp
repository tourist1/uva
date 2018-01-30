#include <bits/stdc++.h>
using namespace std;

int main() {
	auto cstr_compare = [](const char* s1, const char* s2) {
        return strcmp(s1,s2) < 0;
    };

	char* str[6] = {"BGC","BCG","GBC","GCB","CBG","CGB"};
	for(int a,b,c,d,e,f,g,h,i; ~scanf("%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h, &i); ) {
		int max = INT_MAX;
		int mnum[6] = {b+c+d+f+g+h, b+c+d+e+g+i, a+c+e+f+g+h, a+c+d+e+h+i, a+b+e+f+g+i, a+b+d+f+h+i};
		vector<char *> min;
		for(int j = 0; j < 6; ++j) {
			if(mnum[j] <= max) {
				if (mnum[j] < max && !min.empty())
					min.clear();
				min.emplace_back(str[j]);
				max = mnum[j];
			}
		}
		sort(min.begin(), min.end(), cstr_compare);
		
		printf("%s %d\n", min[0], max);
	}
	return 0;
}