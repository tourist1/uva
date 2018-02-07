#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cfloat>
#include <iomanip>
using namespace std;
struct point {
    double x, y;
    int index;
};
 
struct pairs { point a, b; };
vector<pairs> sol;
 
double distant(point a, point b) {
    return sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2));
}
bool cmp(point a, point b) { return a.x < b.x; }
bool cmp_pair(pairs a, pairs b) { return a.a.index < b.a.index; }
double min(double a, double b) { return (a < b)? a: b; }
 
double divideAndConquer(point *data, int l, int r, double &tmp) {
    if(r-l <= 3) {
        for(int i = l; i <= r-1; ++i) {
            for(int j = i+1; j <= r; ++j) {
                pairs p;
                if(tmp > distant(data[i], data[j])) {
                    sol.clear();
                    p.a = data[i];
                    p.b = data[j];
                    sol.push_back(p);
                    tmp = distant(data[i], data[j]);
                }
                else if(tmp == distant(data[i], data[j])) {
                    p.a = data[i];
                    p.b = data[j];
                    sol.push_back(p);
                }
            }
        }
        return tmp;
    }
    int mid = (l+r) >> 1, sl, sr;
 
    double l_min = divideAndConquer(data, l, mid-1, tmp);
    double r_min = divideAndConquer(data, mid, r, tmp);
    tmp = min(l_min, r_min);
    for(sl = l; data[sl].x < data[mid].x-tmp; ++sl);
    for(sr = r; data[sr].x > data[mid].x+tmp; --sr);
    for(int i = sl; i < mid; ++i) {
        for(int j = mid; j <= sr; ++j) {
            pairs p;
            if(tmp > distant(data[i], data[j])) {
                sol.clear();
                p.a = data[i];
                p.b = data[j];
                sol.push_back(p);
                tmp = distant(data[i], data[j]);
            }
            else if(tmp == distant(data[i], data[j])) {
                p.a = data[i];
                p.b = data[j];
                sol.push_back(p);
            }
        }
    }
    return tmp;
}
 
void swap(point &a, point &b) {
    point temp = a;
    a = b;
    b = temp;
}
 
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
 
int main() {
    for(int n; scanf("%d", &n) && n; ) {
      point *ps = (point *)malloc(sizeof(point)*n);
      for(int i = 0; i < n; ++i) {
          double x, y;
          scanf("%lf%lf", &x, &y);
          ps[i].x = x;
          ps[i].y = y;
          ps[i].index = i+1;
      }
      sort(ps, ps+n, cmp);
      double distance = DBL_MAX;
      double result = divideAndConquer(ps, 0, n-1, distance);
      for(pairs &i : sol) {
          if(i.a.index - i.b.index > 0) {
              swap(i.a.index, i.b.index);
          }
      }
      sort(sol.begin(), sol.end(), cmp_pair);
      if(result >= 10000) {
        printf("INFINITY\n");
      } else 
        printf("%.4lf\n", result);
      free(ps);
    }
    return 0;
}