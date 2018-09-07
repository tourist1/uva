#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *args[]) {
	int a;
	scanf("%d", &a);
	vector<vector<int>> net(a, vector<int> ());

	for(int i = 0; i < a; ++i) {
		int fnum = 0;
		scanf("%d", &fnum);
		while(fnum--) {
			int findex = 0;
			scanf("%d", &findex);
			net[i].emplace_back(findex);
		}
	}

	int emp = a;
	scanf("%d", &a);
	while(a-- > 0) {
		int findex = 0;
		scanf("%d", &findex);
		if(!net[findex].size()) {
			printf("0\n");
			continue;
		}
		vector<bool> visited(emp, false);
		queue<int> q;
		q.push(findex);

		int day = 1, maxday = 1;
		int maxnum = 1;
		vector<vector<int>> each_day;
		vector<int> first_day({findex});
		each_day.emplace_back(first_day);
		vector<int> current;
		visited[findex] = true;
		while(!q.empty()) {
			int index = q.front();
			q.pop();
			each_day[day-1].pop_back();

			for(int i : net[index]) {
				if(!visited[i]) {
					q.push(i);
					visited[i] = true;
					current.emplace_back(i);
				}
			}
			if(!each_day[day-1].size()) {
				each_day.emplace_back(current);
				if(maxnum < current.size()) {
					maxnum = current.size();
					maxday = day;
				}
				current.clear();
				day++;
			}
		}
		printf("%d %d\n", maxnum, maxday);
	}
	return 0;
}