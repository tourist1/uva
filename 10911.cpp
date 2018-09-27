#include <bits/stdc++.h>
using namespace std;

double dp[1<<20];
int N;

struct student {
	char name[22];
	double x, y;
};

// calculate the distance between 2 nodes
double distance(const student &a, const student &b) {
	return sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2));
}

// find the smallest index node i in a subset of all student
// dp along pairs between i and all other student j
// subset s
// dp[s] min distance for subset s

// transfer function:
// 		dp[s] = min{dp[s], distance[i][j]+dp[s-ij]}

// find which pair can result in smallest distance sum
double dps(vector<vector<double>> &dist, int set1) {
	if(dp[set1] || !set1) return dp[set1];
	int i;

	// find the smallest index node i in set1
	for(i = 0; i < N; ++i) {
		if(set1 & (1<<i)) break;
	}
	dp[set1] = 0x7FFFFFFF; // int max

	// find min cost with each part added in
	for(int j = i+1; j < N; ++j) {
		// if j is also in set1
		if(set1 & (1<<j))
			dp[set1] = min(dp[set1], dist[i][j]+dps(dist, set1 ^ (1<<i) ^ (1<<j)));
	}
	return dp[set1];
}

int main(int argc, char* args[]) {
	int index = 0;
	for(int a; ~scanf("%d", &a) && a; ) {
		
		// read input
		vector<student> list;
		for(int i = 0; i < 2*a; ++i) {
			student tmp;
			scanf("%s", tmp.name);
			scanf("%lf%lf", &tmp.x ,&tmp.y);
			list.emplace_back(tmp);
		}
		vector<vector<double>> table(2*a+1, vector<double>(2*a+1, 0));

		// calculate distances between all pairs
		for(int i = 0; i < 2*a; ++i) {
			for(int j = i; j < 2*a; ++j) {
				if(i == j) table[i][j] = 0;
				else table[i][j] = table[j][i] = distance(list[i], list[j]);
			}
		}

		a <<= 1;
		N = a;
		
		// initialize dp table for each case
		memset(dp, 0, sizeof(dp));

		// (1 << N) is the total subset number of N nodes set
		// dp go through all pairs of students
		printf("Case %d: %.2lf\n", ++index, dps(table, (1<<a)-1));
	}
	return 0;
}