#include "Solution1.h"
#include <algorithm>

using namespace std;

Solution1::Solution1() : n(0), D(0), cnt(0) {}

void Solution1::read_data() {
	int tmp;
	cin >> n;
	cin >> D;
	
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		price.push_back(tmp);
	}

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		coupons.push_back(tmp);
	}
}

void Solution1::greedy() {
	cal_combinations();
	std::sort(combinations.begin(), combinations.end());

	for (auto p = combinations.begin(); p != combinations.end() && D >= (*p); p++) {
		cnt++;
		D -= (*p);
	}
}

void Solution1::cal_combinations() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			combinations.push_back(price[i] - coupons[j]);
		}
	}
}

void Solution1::print_Information() {
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

void Solution1::result() {
	cout << "-----Greedy-----" << endl;
	cout << "You can buy " << cnt << " items at most;" << endl;
	cout << "There is still " << D << " left;" << endl;
	cout << "----------------" << endl;
}