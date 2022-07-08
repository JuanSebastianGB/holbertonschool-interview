#include "menger.h"

/**
 * draw_blank_in_pow3 - It checks if the current cell is in the
 * middle of a 3x3 square, and if it is, it prints a space,
 * otherwise it prints a hash
 *
 * @x: the x coordinate of the current cell
 * @y: the y coordinate of the point
 */
void draw_blank_in_pow3(int x, int y)
{
	int is_space = 0, tmpx, tmpy;

	for (tmpx = x, tmpy = y, is_space = 0; tmpx || tmpy; tmpx /= 3, tmpy /= 3)
		if (tmpx % 3 == 1 && tmpy % 3 == 1)
			is_space = 1;
	printf("%c", !is_space ? '#' : ' ');
}

/**
 * It prints a blank space if the sum of the coordinates is divisible by 3,
 * otherwise it prints a hash
 *
 * @param level the level of the sponge to draw
 */
void menger(int level)
{
	int x = 0, y = 0, s_sponge = pow(3, level);

	for (x = 0; x < s_sponge; x++)
	{
		for (y = 0; y < s_sponge; y++)
			draw_blank_in_pow3(x, y);
		printf("\n");
	}
}
