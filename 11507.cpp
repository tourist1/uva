#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s) {
	vector<string> dir;
	size_t len = s.length();
	string token = "";
	for(int i = 0; i < len; ++i) {
	    if(s[i] == ' ') {
	    	if(token.length())
	    		dir.emplace_back(token);
	    	token.clear();
	    } else 
	    	token += s[i];
	}
	if(token.length())
		dir.emplace_back(token);
	return dir;
}


// 3d rotation matrix
void rotate(int vec[3], string dir) {
	int tmp[3];
	for(int i = 0; i < 3; ++i) {
		tmp[i] = vec[i];
	}
	if(!dir.compare("No")) return;
	int sign = (dir[0] == '+')? 1: -1;
	if(dir[1] == 'z') {
		vec[0] = sign * tmp[2];
		vec[1] = tmp[1];
		vec[2] = -1 * sign * tmp[0];
	} else {
		vec[0] = -1 * sign * tmp[1];
		vec[1] = sign * tmp[0];
		vec[2] = tmp[2];
	}
}

int main() {
	for(int l; scanf("%d", &l) && l; ) {
		cin.get();
		int vec[3] = {1, 0, 0};
		string dir;
		getline(cin, dir);
		vector<string> direction = split(dir);
		for(string i : direction) {
			rotate(vec, i);
		}

		if(vec[0]) {
			printf(vec[0] == 1 ? "+x" : "-x");
		} else if(vec[1]) {
			printf(vec[1] == 1 ? "+y" : "-y");
		} else {
			printf(vec[2] == 1 ? "-z" : "+z");
		}
		puts("");
	} 
	return 0;
}