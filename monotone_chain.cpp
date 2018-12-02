#include <bits/stdc++.h>
using namespace std;

struct pt{
	int x, y;
	pt(){ x = y = 0;}
	pt(int _x, int _y):x(_x), y(_y){}
	bool operator<(pt a){
		return x < a.x || (x == a.x) && y < a.y;
	}
};

long long cross(pt o, pt a, pt b){
	return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.y - o.y);
}

vector<pt> convex_hull(vector<pt> p){
	int n = (int)p.size(), k=0;
	if(n<=3) return p;
	vector<pt> h(2*n);
	sort(p.begin(), p.end());
	for(int i=0; i<n; i++){
		while(k>=2 && cross(h[k-2], h[k-1], p[i]) <= 0LL) k--;
		h[k++] = p[i];
	}
	for(int i=n-1, t=k+1; i>0; i--){
		while(k>=t && cross(h[k-2], h[k-1], p[i-1]) <= 0LL) k--;
		h[k++] = p[i-1];
	}
	h.resize(k-1);
	return h;
}

int main(){
	int n;
	scanf("%d", &n);
	vector<pt> t, p;
	for(int i=0; i<n; i++){
		int x, y; scanf("%d%d", &x, &y);
		t.push_back(pt(x, y));
	}
	p = convex_hull(t);
	for(auto a:p){
		printf("x = %d - y = %d\n", a.x, a.y);v
	}
}
