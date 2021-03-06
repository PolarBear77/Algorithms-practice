#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <Windows.h>

using namespace std;

/*
* Time complexity: TODO
* Space complexity: TODO
*/

char *runLenEncode( char *src ) {
	
	int rLen;
	char count[MAX_RLEN];
	int len = strlen(src);

	char *answer = (char *)malloc(sizeof( char ) *( len * 2 + 1 ));

	int i, j = 0, k;

	for (i = 0; i < len; i++) {

		answer[j++] = src[i];
		rLen = 1;
		while (( i + 1 < len ) && ( src[i] == src[i + 1])) {
			rLen++;
			i++;
		}

		sprintf(count, "%d", rLen);

		for (k = 0; *(count + k); k++, j++) {
			answer[j] = count[k];
		}
	}

	return answer;
}




int main(int argc, const char *argv[]) {
	int T;
	scanf("%d\n", &T);

	for (int i = 0; i < T; ++i) {
		char buf[BUFSIZ];
		scanf("%s\n", buf);
	}

	return 0;
}
