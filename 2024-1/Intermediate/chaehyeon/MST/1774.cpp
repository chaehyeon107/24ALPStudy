#include <bits/stdc++.h>
using namespace std;

int v, e;
int n, m;
vector<tuple<int,int,double>> edge;
pair<int,int> node[1005];
vector<int> p(10005, -1);

int find(int x) {
	if(p[x] < 0) return x;
	return p[x] = find(p[x]);	
}

bool is_diff_group(int u, int v) {
	u = find(u); v = find(v);
	if(u == v) return 0;
	if(p[u] == p[v]) p[u]--;
	if(p[u] < p[v]) p[v] = u;
	else p[u] = v;
	return 1;
}

bool cmp(const tuple<int,int,int>& a, const tuple<int,int,int>& b) {
	return get<2>(a) < get<2>(b);
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int x, y, a, b;
	for(int i = 1; i <= n; i++) {
		cin >> x >> y;
		node[i] = {x, y};
	}
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		if(a > b) p[b] = a;
		else p[a] = b;
	}
	for(int i = 1; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			double cost = sqrt(pow((node[i].first - node[j].first),0) + pow((node[i].second - node[j].second),2));
			tuple<int,int,double> tup = make_tuple(i, j, cost);
			edge.push_back(tup);
		}
	}
	sort(edge.begin(), edge.end(), cmp);
	
	
	int cnt = 0;
	double ans = 0;
	for(int i = 0; i < edge.size(); i++) {
		int a, b;
		double cost;
		tie(a, b, cost) = edge[i];
		if(!is_diff_group(a, b)) continue;
		ans += cost;
		cnt++;
		if(cnt == v-1) break;
	}
	cout << fixed;
	cout.precision(2);
	cout << ans;
}
