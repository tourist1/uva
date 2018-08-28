#include <bits/stdc++.h>
using namespace std;

int edit_distance(string a, string b) {
	int lena = a.length(), lenb = b.length();
	int dp[11][11] = {0};

	for (int i = 0; i <= lena; ++i)
        dp[i][0] = i;
    for (int j = 0; j <= lenb; ++j)
        dp[0][j] = j;

	for(int i = 1; i <= lena; ++i) {
		for(int j = 1; j <= lenb; ++j) {
			if(a[i-1] == b[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			} else {
				dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
			}
		}
	}
	return dp[lena][lenb]; 
}

int main(int argv, char *args[]) {
	int n;
	scanf("%d", &n);

	while(n--) {
		vector<string> dic;
		string str;

		// read input
		cin >> str;
		while(str.compare("*")) {
			dic.emplace_back(str);
			cin >> str;
		}

		map<string, vector<string>> adjacency;

		// find each word that is one char different from s using edit distance algorithm
		for(string s : dic) {
			adjacency[s] = vector<string>();
			for(string sp : dic) {
				if(edit_distance(s, sp) == 1) {
					adjacency[s].emplace_back(sp);
				}
			}
		}

		// clear buffer
		cin.get();

		// calculate result
		while(getline(cin, str) && str.length()) {
			string start, ending;
			
			map<string, bool> used;
			map<string, string> pre;

			// read two string separated with space
			istringstream iss(str);
			iss >> start >> ending;

			// find shortest path between 2 words
			queue<string> q;
			string e = ending;
			q.push(e);
			used[ending] = true;

			while(!q.empty()) {
				ending = q.front();
				q.pop();
				for(string s : adjacency[ending]) {
					if(!used[s]) {
						used[s] = true;
						pre[s] = ending;
						q.push(s);
					}
				}
			}

			// output result
			int path = 0;
			cout << start << ' ' << e << ' ';
			while(start != e) {
				path++;
				start = pre[start];
			}
			cout << path << "\n";
		}
		if(n) puts("");
	}
	return 0;
}