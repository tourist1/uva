#include <bits/stdc++.h>
using namespace std;

int main() {
	for(int a; ~scanf("%d", &a) && a; ) {
		map<int, vector<int>> graph;

		for(int start; ~scanf("%d", &start) && start; ) {
			for(int vertex; ~scanf("%d", &vertex) && vertex; ) {
				graph[start].emplace_back(vertex);
			}
		}

		int test_case = 0, test_v = 0, len;
		scanf("%d", &test_case);

		while(test_case-- > 0) {
			len = a;
			scanf("%d", &test_v);
			stack<int> dfs;
			dfs.push(test_v);
			vector<bool> visited(a+1, false);

			while(!dfs.empty()) {
				int i = dfs.top();
				dfs.pop();
				for(int j : graph[i]) {
					if(!visited[j]) {
						dfs.push(j);
						visited[j] = true;
						len--;
					}
				}
			}

			printf("%d", len);
			for(int i = 1; i <= a; ++i) {
				if(!visited[i])
					printf(" %d", i);
			}
			puts("");
		}
	}
	return 0;
}
