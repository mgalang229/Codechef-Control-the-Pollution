#include <bits/stdc++.h>
using namespace std;

// this function calculates the minimum smoke value by iterating on
// every no. of person that will be placed on vehicle type 1 and the
// remaining will be placed on vehicle type 2 while comparing the values
// in each iteration of the loop
int get_min_smoke(int n, int x, int y, int capacity1, int capacity2) {
	int ans = INT_MAX;
	for(int person = 1; person <= n; person++) {
		int vehicle1 = ceil((double) person / capacity1);
		int remaining = n - person;
		int vehicle2 = ceil((double) remaining / capacity2);
		int res1 = vehicle1 * (capacity1 == 100 ? x : y);
		int res2 = vehicle2 * (capacity2 == 100 ? x : y);
		ans = min(ans, res1 + res2);
	}
	return ans;
}

void perform_test() {
	int n, x, y;
	cin >> n >> x >> y;
	int ans = get_min_smoke(n, x, y, 100, 4);
	ans = min(ans, get_min_smoke(n, x, y, 4, 100));
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc = 1;
	cin >> tc;
	for(int t = 0; t < tc; t++) {
		perform_test();
	}
	return 0;
}
