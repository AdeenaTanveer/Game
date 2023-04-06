#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int checkWin(char array[][3]);
void display();
int main()
{
	printf("           \t \t Tic Tac Toe\n                    ----------------------\n              \t      By Adeena Tanveer");
	printf("\n\n\n");
	char array[3][3] = { {' ',' ',' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
	char player1[20];// Use for entering the name of first player
	char player2[20];// Use for entering the name of second player
	char sign;
	char sign2;
	int count = 1;
	int i; // Index at rows
	int j; // Index at columns
	int status;
	display();
	//status = checkWin();

	printf("                    ****++ There are two players in this game ++****                    \n\n");
	printf("Please enter the name of first player:");
	scanf("%s", player1);
	getchar();

	printf("Please enter the name of second player:");
	scanf("%s", player2);
	getchar();

	printf("\n                    ****** Choose the desired sign ****** \n\n");
	printf("Please %s enter the sign you want to use (x or o):", player1);
	scanf("%c", &sign);
	getchar();
	while (sign != 'x' && sign != 'o')
	{
		printf("Invalid Sign! \nPlease enter the valid sign:");
		scanf("%c", &sign);
		getchar();
	}
	if (sign == 'x')
	{
		sign2 = 'o';
	}
	else if (sign == 'o')
	{
		sign2 = 'x';
	}

	printf("\n                     ****++ Now the game begins ++****                  \n\n");


	do
	{
		if (count % 2 != 0)
		{
			printf("Please %s enter the index of row where you want to enter the sign:", player1);
			scanf("%d", &i);
			while (i >= 3 || i < 0)
			{
				printf("Invalid index! \nPlease enter the valid index:");
				scanf("%d", &i);
				getchar();
			}

			printf("Please %s enter the index of column where you want to enter the sign:", player1);
			scanf("%d", &j);
			while (j >= 3 || j < 0)
			{
				printf("Invalid index! \nPlease enter the valid index:");
				scanf("%d", &j);
				getchar();
			}
			while (array[i][j] != ' ')
			{
				printf("already Occupied\nEnter valid row and column index\n");
				printf("Please %s enter the index of row where you want to enter the sign Again:", player1);
				scanf("%d", &i);
				while (i >= 3 || i < 0)
				{
					printf("Invalid index! \nPlease enter the valid index:");
					scanf("%d", &i);
					getchar();
				}

				printf("Please %s enter the index of column where you want to enter the sign Again: ", player1);
				scanf("%d", &j);
				while (j >= 3 || j < 0)
				{
					printf("Invalid index! \nPlease enter the valid index:");
					scanf("%d", &j);
					getchar();
				}
			}
			array[i][j] = sign;
			for (int r = 0; r < 3; r++)
			{
				printf(" \n");
				for (int c = 0; c < 3; c++)
				{
					printf("  %c   ", array[r][c]);
				}

				printf(" \n");
				printf(" ----| ---- | ----  \n");
				printf("\n");
			}
			status = checkWin(array);
			if (status == 1)
			{
				printf("%s has won the game", player1);
				break;
			}
			else if (status == 0)
			{
				printf("Oops Match Drawn");
			}
			count++;
		}
		else if (count % 2 == 0)
		{
			printf("Please %s enter the index of row where you want to enter the sign:", player2);
			scanf("%d", &i);
			while (i >= 3 || i < 0)
			{
				printf("Invalid index! \nPlease enter the valid index:");
				scanf("%d", &i);
				getchar();
			}
			printf("Please %s enter the index of column where you want to enter the sign:", player2);
			scanf("%d", &j);
			while (j >= 3 || j < 0)
			{
				printf("Invalid index! \nPlease enter the valid index:");
				scanf("%d", &j);
				getchar();
			}
			while (array[i][j] != ' ')
			{
				printf("already Occupied\nEnter valid row and column index\n");
				printf("Please %s enter the index of row where you want to enter the sign:", player2);
				scanf("%d", &i);
				while (i >= 3 || i < 0)
				{
					printf("Invalid index! \nPlease enter the valid index:");
					scanf("%d", &i);
					getchar();
				}
				printf("Please %s enter the index of column where you want to enter the sign:", player2);
				scanf("%d", &j);
				while (j >= 3 || j < 0)
				{
					printf("Invalid index! \nPlease enter the valid index:");
					scanf("%d", &j);
					getchar();
				}
			}

			array[i][j] = sign2;
			for (int r = 0; r < 3; r++)
			{
				printf(" \n");
				for (int c = 0; c < 3; c++)
				{
					printf("  %c   ", array[r][c]);
				}

				printf(" \n");
				printf(" ----| ---- | ----  \n");
				printf("\n");
			}

			status = checkWin(array);
			if (status == 1)
			{
				printf("%s has won the game", player2);
				break;
			}
			else if (status == 0)
			{
				printf("Oops Match Drawn");
			}
			count++;
		}

	} while (count < 10);

	return 0;

}
int checkWin(char array[][3])
{
	if (array[0][0] == 'x' && array[0][1] == 'x' && array[0][2] == 'x')
	{
		return 1;
	}
	else if (array[0][0] == 'o' && array[0][1] == 'o' && array[0][2] == 'o')
	{
		return 1;
	}

	if (array[1][0] == 'x' && array[1][1] == 'x' && array[1][2] == 'x')
	{
		return 1;
	}
	else if (array[1][0] == 'o' && array[1][1] == 'o' && array[1][2] == 'o')
	{
		return 1;
	}

	if (array[2][0] == 'x' && array[2][1] == 'x' && array[2][2] == 'x')
	{
		return 1;
	}
	else if (array[2][0] == 'o' && array[2][1] == 'o' && array[2][2] == 'o')
	{
		return 1;
	}

	// **************** FOR COLS ************************* //
	if (array[0][0] == 'x' && array[1][0] == 'x' && array[2][0] == 'x')
	{
		return 1;
	}
	else if (array[0][0] == 'o' && array[1][0] == 'o' && array[2][0] == 'o')
	{
		return 1;
	}

	if (array[0][1] == 'x' && array[1][1] == 'x' && array[2][1] == 'x')
	{
		return 1;
	}
	else if (array[0][1] == 'o' && array[1][1] == 'o' && array[2][1] == 'o')
	{
		return 1;
	}

	if (array[0][2] == 'x' && array[1][2] == 'x' && array[2][2] == 'x')
	{
		return 1;
	}
	else if (array[0][2] == 'o' && array[1][2] == 'o' && array[2][2] == 'o')
	{
		return 1;
	}

	// **************** FOR DIAGNOLS ************************* //

	if (array[0][0] == 'x' && array[1][1] == 'x' && array[2][2] == 'x')
	{
		return 1;
	}
	else if (array[0][0] == 'o' && array[1][1] == 'o' && array[2][2] == 'o')
	{
		return 1;
	}

	else if (array[0][2] == 'x' && array[1][1] == 'x' && array[2][0] == 'x')
	{
		return 1;
	}
	else if (array[0][2] == 'o' && array[1][1] == 'o' && array[2][0] == 'o')
	{
		return 1;
	}
	else if (array[0][0] != ' ' && array[0][1] != ' ' && array[0][2] != ' ' && array[1][0] != ' ' && array[1][1] != ' ' && array[1][2] != ' ' && array[2][0] != ' ' && array[2][1] != ' ' && array[2][2] != ' ' && array[1][0] != ' ' && array[2][0] != ' ' && array[0][1] != ' ' && array[1][1] != ' ' && array[2][1] != ' ' && array[0][2] != ' ' && array[1][2] != ' ' && array[2][2] != ' ')
	{
		return 0;
	}
	else
	{
		return -1;
	}
}


void display()
{
	char array[3][3] = { {' ',' ',' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
	for (int r = 0; r < 3; r++)
	{
		printf(" \n");
		for (int c = 0; c < 3; c++)
		{
			printf("  %c   ", array[r][c]);

		}
		printf(" \n");
		printf(" ----| ---- | ----  \n");
		printf("\n");
	}
}