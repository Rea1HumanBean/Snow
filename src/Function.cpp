#define _CRT_SECURE_NO_WARNINGS

#include "../inc/Function.hpp"
#include <fstream>
#include <iostream>
#include <cmath>

namespace boba
{
	bool isPos35(int x)
	{
		if (x <= 0)
		{
			return false;
		}

		int dig;
		while (x > 0)
		{
			dig = x % 10;
			if (dig == 3)
			{
				return true;
			}
			else if (dig == 5)
			{
				return true;
			}
			x = x / 10;
		}
	}

	void sumOfSquares(int str, int Matrix[100][100]) {
		int min = INT_MAX, sum = 0, y1, x1;

		for (int y = 0; y < str; y++)
		{
			for (int x = 0; x < str; x++)
			{
				sum += pow(Matrix[x][y], 2);
				if (Matrix[x][y] < min)
				{
					min = Matrix[x][y];
					x1 = x;
					y1 = y;
				}
			}
			Matrix[x1][y1] = sum;
		}
	}

	int inp(int Matrix[100][100]) {
		char N[100], * divide;
		int x = 0, y;
		std::ifstream in("Matrix.txt");

		while (in.getline(N, 100))
		{
			divide = strtok(N, " ");
			y = 0;
			while (divide != NULL) {
				Matrix[x][y] = atoi(divide);
				divide = strtok(NULL, " ");
				y++;
			}
			x++;
		}
		return x;
	}

	bool check(int Matrix[100][100], int N) {
		for (int i = 0; i < N; i++)
		{
			if (isPos35(Matrix[i][i]) == false)
			{
				return false;
			}
		}
		return true;
	}

	void out(int Matrix[100][100], int N) {
		std::ofstream of("Bebra.txt");
		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < N; y++)
			{
				of << "[" << Matrix[x][y] << "]" << "  ";
			}
			of << std::endl;
		}
	}
}