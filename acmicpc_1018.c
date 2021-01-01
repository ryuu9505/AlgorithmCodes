#define _CRT_SECURE_NO_WARNINGS
#define WHITE -1
#define BLACK 1
#include <stdio.h>
#include <limits.h>

// Brute-Force
int ColorChessboard(int N, int M, int board_src[50][50], int start_row, int start_column, int first_block)
{
	int r, c;
	int end_row = start_row + 7;
	int end_column = start_column + 7;
	int changes = 0;

	int board[50][50];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			board[i][j] = board_src[i][j];

	if (board[start_row][start_column] != first_block)
	{
		board[start_row][start_column] = first_block;
		changes++;
	}
		
	for (r = start_row; r <= end_row; r++)
	{
		for (c = start_column ; c < end_column; c++)
		{					
			if (board[r][c] == board[r][c + 1])
			{
				board[r][c + 1] *= -1;
				changes++;
			}
		}
		if (r != end_row)
		{
			if (board[r][start_column] == board[r + 1][start_column])
			{
				board[r + 1][start_column] *= -1;
				changes++;
			}
		}
	}
	return changes;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	char board[50][50];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf(" %c", &board[i][j]);

	int board_src[50][50];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 'B')
				board_src[i][j] = BLACK; 
			else if (board[i][j] == 'W')
				board_src[i][j] = WHITE;
			else
				board_src[i][j] = 0;
		}
	}

	int changes, min = INT_MAX;
	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			changes = ColorChessboard(N, M, board_src, i, j, BLACK);
			if (min > changes)
				min = changes;
			changes = ColorChessboard(N, M, board_src, i, j, WHITE);
			if (min > changes)
				min = changes;
		}
	}
	printf("%d", min);

	return 0;
 }
