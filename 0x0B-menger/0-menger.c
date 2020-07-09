#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 *
 *@level: level of the Menger Sponge to draw
 **/

void menger(int level)
{
	int i, j, row, col, side;
	char sponge;

	if (level < 0)
		return;

	side = pow(3, level);

	for (i = 0; i < side; i++)
	{
		for (j = 0; j < side; j++)
		{
			row = i;
			col = j;
			sponge = '#';
			while (row > 0 && col > 0)
			{
				if (row % 3 == 1 && col % 3 == 1)
					sponge = ' ';
				row /= 3;
				col /= 3;
			}
			printf("%c", sponge);
		}
		printf("\n");
	}
}
