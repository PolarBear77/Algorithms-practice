#include "stdafx.h"
#include <iostream>
#include <stdio.h>

#define MAX 101

int main() {
	int lineNum;
	std::cin >> lineNum;

	char pattern[MAX];
	fgets(pattern, MAX, stdin);
	int patternLength = strlen(pattern);

	int star_position = 0;
	star_position = strcspn(pattern, "*");

	for (int i = 0; i < lineNum; i++) {
		char input[MAX];
		fgets(input, MAX, stdin);
		int inputLength = strlen(input);

		if (strncmp(input, pattern, star_position) == 0) {
			if (inputLength < patternLength - 1) {
				std::cout << "NE\n";
			}
			else if ())

		}



	}

}