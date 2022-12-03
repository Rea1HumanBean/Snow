#define _CRT_SECURE_NO_WARNINGS

#include "inc/Function.hpp"

using namespace std;


int main()
{
	int Matrix[100][100];
	int N = boba::inp(Matrix);

	if (boba::check(Matrix, N))
	{
		boba::sumOfSquares(N, Matrix);
	}

	boba::out(Matrix, N);

	return 0;
} 