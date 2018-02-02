#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y;
	scanf("%d%d", &x, &y); 
	vector<pair<int, int>> scent;
	for(int rx, ry; ~scanf("%d%d", &rx, &ry); ) {
		cin.get();
		char dir;
		scanf("%c", &dir);
		cin.get();
		string cmd;
		getline(cin, cmd);

		int len = cmd.length(), tmp_x = rx, tmp_y = ry, lost = 0;
		for(int i = 0; i < len; ++i) {
			switch(cmd[i]) {
				case 'L':
					if(dir == 'N') {
						dir = 'W';
					} else if(dir == 'S') {
						dir = 'E';
					} else if(dir == 'E') {
						dir = 'N';
					} else {
						dir = 'S';
					}
					break;
				case 'R':
					if(dir == 'N') {
						dir = 'E';
					} else if(dir == 'S') {
						dir = 'W';
					} else if(dir == 'E') {
						dir = 'S';
					} else {
						dir = 'N';
					}
					break;
				case 'F':
					if(dir == 'N') {
						tmp_y++;
					} else if(dir == 'S') {
						tmp_y--;
					} else if(dir == 'E') {
						tmp_x++;
					} else {
						tmp_x--;
					}
					break;
			}
			if(tmp_x < 0 or tmp_x > x or tmp_y < 0 or tmp_y > y) {
				if(find(scent.begin(), scent.end(), pair<int, int>(rx, ry)) != scent.end()) {
					
					tmp_x = rx;
					tmp_y = ry;
				} else {
					printf("%d %d %c LOST\n", rx, ry, dir);
					scent.push_back(pair<int, int>(rx, ry));
					lost = 1;
					break;
				}
			} else {
				rx = tmp_x;
				ry = tmp_y;
			}
		}
		if(!lost) {
			printf("%d %d %c\n", rx, ry, dir);
		}
	}
	return 0;
}