#pragma once

#include <vector>
#include <iostream>

using namespace std;

class Solution1 {
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
	// 所有可能的组合
	vector<int> combinations;
public:
	Solution1();

	// 读取数据
	void read_data();

	// 贪心算法，计算最多能买多少
	// 贪心策略：先计算所有可能的排列组合，即价格减去优惠的所有可能；
	// 再按照从小到大排序，然后从小开始累加
	void greedy();

	// 计算当前的price和coupons能产生多少种组合
	void cal_combinations();

	// 打印类信息
	void print_Information();

	// 打印最多购买商品数量和最多剩余钱
	void result();


	friend class Solution2;
};