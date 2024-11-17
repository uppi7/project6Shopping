#include "Solution2.h"
#include <algorithm>

using namespace std;

Solution2::Solution2() : n(0), D(0), cnt(0) {}

Solution2::Solution2(const Solution1& s1) : n(s1.n), D(s1.D), cnt(s1.cnt) {
	price = s1.price;
	coupons = s1.coupons;
}

void Solution2::dynamic_programming() {
	// 动态规划数组，dp[x]表示x元最多买多少东西
	vector<int> dp(D + 1, 0);

	sort(price.begin(), price.end());
	sort(coupons.begin(), coupons.end());

	for (int p : price) {
		for (int c : coupons) {
			int cost = p - c;
			// 如果剩余的钱不够
			if (cost > D) {
				break;
			}
			// 从后向前更新dp
			for (int x = D; x >= cost; x--) {
				dp[x] = max(dp[x], dp[x - cost] + 1);
			}
		}
	}

	// 找到最多能买的物品数目和剩余的钱
	int remainingMoney = D;
	for (int i = 0; i <= D; ++i) {
		if (dp[i] > cnt) {
			cnt = dp[i];
			remainingMoney = D - i;
		}
	}
	D = remainingMoney;
}

void Solution2::print_Information() {
	cout << "n: " << n << endl;

	cout << "D: " << D << endl;

	cout << "price: ";
	for (int i = 0; i < n - 1; i++) {
		cout << price[i] << ", ";
	}
	cout << price[n - 1] << endl;

	cout << "coupons: ";
	for (int i = 0; i < n - 1; i++) {
		cout << coupons[i] << ", ";
	}
	cout << coupons[n - 1] << endl;
}

void Solution2::result() {
	cout << "---Dynamic Programming---" << endl;
	cout << "You can buy " << cnt << " items at most;" << endl;
	cout << "There is still " << D << " left;" << endl;
	cout << "-------------------------" << endl;
}