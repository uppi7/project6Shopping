#include <iostream>
#include <vector>

#include "Solution1.h"
#include "Solution2.h"

using namespace std;

int main()
{
	Solution1 solution1;

	solution1.read_data();

	Solution2 solution2(solution1);

	solution2.dynamic_programming();

	solution2.result();

	solution1.greedy();

	solution1.result();
}