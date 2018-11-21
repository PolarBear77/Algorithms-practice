#include <iostream>
#include <stdio.h>
#include "stdafx.h"
#include <iostream>

int main(){
	int **array_of_arrays;

	int num_arrays, num_queries;
	num_arrays = num_queries = 0;
	std::cin >> num_arrays >> num_queries;
	//std::cout << num_arrays << " " << num_queries;

	//Process the Arrays
	array_of_arrays = new int*[num_arrays];
	int size_current_array = 0;

	for (int i = 0; i < num_arrays; i++)
	{
		std::cin >> size_current_array;
		int *tmp_array = new int[size_current_array];
		for (int j = 0; j < size_current_array; j++)
		{
			int tmp = 0;
			std::cin >> tmp;
			tmp_array[j] = tmp;
		}
		array_of_arrays[i] = tmp_array;
	}


	//Process the Queries
	int x, y;
	x = y = 0;
	for (int q = 0; q < num_queries; q++)
	{
		std::cin >> x >> y;
		//std::cout << "Current x & y: " << x << ", " << y << "\n";
		std::cout << array_of_arrays[x][y] << "\n";
	}

	return 0;
}

//int min = 1000000;
//
//int bfs(int y, int x, int *maze) {
//	if(*maze[y][x])
//
//}
//
//
//void main() {
//	int n, m;
//
//	std::cin >> n;
//	std::cin >> m;
//	
//	int maze[n][m];
//	for (int i = 0; i < n; i++) {
//		for (int k = 0; k < m; k++) {
//			std::cin >> maze[i][k];
//		}
//	}
//
//	return bfs(maze)
//}