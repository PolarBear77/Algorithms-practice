#include "stdafx.h"
#include <stdio.h>
#include <iostream>

__int64 MIN = 0;
__int64 MAX = 0;
int numbers[11] = { 0, };
int n = 0;


void calculate(int num, int depth, int plus, int minus, int multiply, int divide) {

	if (depth == n) {
		if (num > MAX) { printf("Max\n:%d", MAX); MAX = num; }
		if (num < MIN) { printf("Min\n:%d", MIN); MIN = num; }
		return;
	}


	printf("Number %d, Depth %d, + %d, - %d, * %d, / %d\n", num, depth, plus, minus, multiply, divide);
	int dep = depth;

	depth += 1;

	if (plus > 0) { calculate(int(*(numbers + 1)) + numbers[depth], depth, plus - 1, minus, multiply, divide); }
	if (minus > 0) { calculate(int(*(numbers + 1)) - numbers[depth], depth, plus, minus - 1, multiply, divide); }
	if (multiply > 0) { calculate(int(*(numbers + 1)) * numbers[depth], depth, plus, minus, multiply - 1, divide); }
	if (divide > 0) { calculate(int(*(numbers + 1)) / numbers[depth], depth, plus, minus, multiply, divide - 1); }

}


int main() {
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> numbers[i];
	}

	int plus = 0, minus = 0, multiply = 0, divide = 0;
	std::cin >> plus;
	std::cin >> minus;
	std::cin >> multiply;
	std::cin >> divide;

	printf("Numbers:%d, ", n);
	for (int i = 0; i < n; i++) {
		std::cout << numbers[i];
	}
	printf("\n");

	calculate(numbers[0], 0, plus, minus, multiply, divide);
	printf("%d, %d\n", MIN, MAX);

	return 0;
}