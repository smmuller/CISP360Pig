#include <stdio.h>
#include <stdlib.h>

void clearInput(void);
int main(void)

{
	int roll;
	char hold;
	int turnTotal = 0;
	int player1Total = 0;
	int player2Total = 0;
	int turn =0; // 1 is computer, 0 is player
	FILE *fp;

	// turn = rand() % 2 +1;

	while(1)
	{
		if (player1Total >= 100)
		{
			printf("Player 1 wins!\n");
			fp = fopen("Scores", "a+");
			fprintf(fp, "%d\n", player1Total);
			break;
		}
		if (player2Total >= 100)
		{
			printf("Player 2 wins!\n");
			fp = fopen("Scores", "a+");
			fprintf(fp, "%d\n", player2Total);
			break;
		}
		if (turn == 1)
			printf("Computer turn:\n");
		else
			printf("Your turn:\n");
		roll = rand() % 6 + 1;
		while (roll == 1)
			roll = rand() % 6 + 1;
		while(roll != 1) //?
		{
			printf("Dice roll: %d\n", roll);
			turnTotal += roll;
			printf("Current turn total: %d\n", turnTotal);
			printf("Continue? y/n: ");
			if (turn == 1) // computer
			{
				hold = 'n';
				printf("n\n");
			}
			else	
			{
				scanf("%c", &hold);
				clearInput();
			}
			if (hold == 'n' && turn == 0)
			{
				player1Total += turnTotal;
				printf("Total score: %d\n\n", player1Total);
				turn = 1;
				break;
			}
			if (hold == 'n' && turn == 1)
			{
				player2Total += turnTotal;
				printf("Total score: %d\n\n", player2Total);
				turn = 0;
				break;
			}
			roll = rand() % 6 + 1;
			if (roll == 1)
			{
				turn = !turn;
				printf("Dice roll: 1\n\n");
			}

		}
		turnTotal = 0;	
	}
	return 0;
}

void clearInput(void)
{
	while(getchar() != '\n');
}
