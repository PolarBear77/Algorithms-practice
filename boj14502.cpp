#include <iostream>
#include <stdio.h>
#include "stdafx.h"

int n, m, safe_squares, lab[][], visited[][];


int dfs(int x, int y){
	if (lab[x][y] != 2){}

		return;
}

int main(){
    std::cin >> n;
    std::cin >> m;
    lab[n][m] = {0};
    visited[n][m] = {0};
    safe_squares = n * m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> lab[i][j];
        }
    }
    
    return 0;
}