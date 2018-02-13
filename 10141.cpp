#include <bits/stdc++.h>
using namespace std;
#define MAXLEN 256

struct prop {
    char name[MAXLEN];
    double price;
    int met_req;
};

// comparator function
bool cmp(const prop &a, const prop &b) {
	return a.price < b.price;
}

int main() {
    char line[MAXLEN];
    int n, p, cases = 1;
    while(true) {

    	// scanf is buffered input
    	// so one needs to deal with buffer after using it
	    scanf("%d%d", &n, &p);
	    if(n == 0 && p == 0) break;


	    map<int, vector<prop>> props;
	    int _n = n, _p = p;

	    // clear buffer of scanf above
	    char t;
	    scanf("%c", &t);
	    
	    // read line with spaces
	    
	    // Note that fgets will place '\n' at the end of line
	    // rather than ignore it while input
	    while(_n-- > 0) {
	        fgets(line, MAXLEN, stdin);
	    }

	    
	    int max_req = 0;
	    while(_p-- > 0) {
	        prop p1;

	        // read line with spaces
	        
	        // Note that fgets will place '\n' at the end of line
	        // rather than ignore it while input
	        fgets(p1.name, MAXLEN, stdin);
	        
	        // scanf is buffered input
    		// so one needs to deal with buffer after using it
	        scanf("%lf %d", &p1.price, &p1.met_req);

	        // clear buffer of scanf above
	        scanf("%c", &t);

	        // keep record of the max # of request match
	        max_req = max(max_req, p1.met_req);

	        // read line with spaces
	        
	        // Note that fgets will place '\n' at the end of line
	        // rather than ignore it while input
	        for(int i = 0; i < p1.met_req; ++i) {
	            char tmp[MAXLEN];
	            fgets(tmp, MAXLEN, stdin);
	        }
	        props[p1.met_req].emplace_back(p1);
	        
	    }

	    // sort those proposal that match most request
	    sort(props[max_req].begin(), props[max_req].end(), cmp);

	    if(cases != 1) puts("");
	    printf("RFP #%d\n", cases++);
		printf("%s", props[max_req][0].name);

    }
   	return 0;
}