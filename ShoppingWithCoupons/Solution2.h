#pragma once

#include <vector>
#include <iostream>
#include "Solution1.h"

class Solution2 {
private:
	// n:商品和优惠券的种类和数量
	int n;
	// D:总金钱数量
	int D;
	// cnt:购买数量
	int cnt;
	// price:价格
	vector<int> price;
	// coupons:优惠券
	vector<int> coupons;
public:
	Solution2();

	Solution2(const Solution1& s1);

	// 动态规划，从底到顶
	void dynamic_programming();

	// 打印类信息
	void print_Information();

	// 打印最多购买商品数量和最多剩余钱
	void result();
};