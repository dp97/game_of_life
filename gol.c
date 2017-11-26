#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define CHECK(a) ((a > -1) ? 1 : 0)
#define LIVE	1
#define	DIE		0

int		check_neighbours(int **life, int width, int height, int x, int y)
{
	int	alive;

	alive = 0;
	if (CHECK(y - 1) && CHECK(x - 1))
		if (life[y - 1][x - 1])
			alive++;
	if (CHECK(y - 1) && CHECK(x))
		if (life[y - 1][x])
			alive++;
	if (CHECK(y - 1) && x + 1 < width)
		if (life[y - 1][x + 1])
			alive++;
	if (CHECK(y) && CHECK(x - 1))
		if (life[y][x - 1])
			alive++;
	if (CHECK(y) && x + 1 < width)
		if (life[y][x + 1])
			alive++;
	if (y + 1 < height && CHECK(x - 1))
		if (life[y + 1][x - 1])
			alive++;
	if (y + 1 < height && CHECK(x))
		if (life[y + 1][x])
			alive++;
	if (y + 1 < height && x + 1 < width)
		if (life[y + 1][x + 1])
			alive++;
	return (alive);
}

int		decide_fate_by(int	facts, int cell)
{
	if (cell)
	{
		if (facts < 2)
			return (DIE);
		else if (facts == 2 || facts == 3)
			return (LIVE);
		else if (facts > 3)
			return (DIE);
	}
	else
	{
		if (facts == 3)
			return (LIVE);
	}
	return (cell);
}

int		**tick(int **life_at, int width, int height)
{
	int	cell;
	int	facts;
	int	**new_life;
	int	x;
	int	y;

	if ((new_life = (int **)malloc(height * sizeof(int *))) == NULL)
		exit(write(2, "Error.\n", 7));
	y = 0;
	while (y < height)
	{
		x = 0;
		new_life[y] = (int *)malloc(width * sizeof(int));
		while (x < width)
		{
			cell = life_at[y][x];
			facts = check_neighbours(life_at, width, height, x, y);
			new_life[y][x] = decide_fate_by(facts, cell);
			x++;
		}
		y++;
	}

	y = 0;
	while (y < height)
		free(life_at[y++]);
	free(life_at);
	return (new_life);
}

void	print(int **life, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (life[y][x])
				printf("\e[31m0 \e[0m");
			else
				printf("0 ");
			x++;
		}
		putchar('\n');
		y++;
	}
}

void	generate()
{
	int	**life;
	int i;

	i = 0;
	if ((life = (int **)malloc(20 * sizeof(int *))) == NULL)
		exit(write(2, "Error.\n", 7));
	while (i < 20)
	{
		if ((life[i++] = (int *)malloc(36 * sizeof(int))) == NULL)
			exit(write(2, "Error.\n", 7));
	}
/*Game of life glider gun */
	life[5][1] = 1;
	life[5][2] = 1;
	life[6][1] = 1;
	life[6][2] = 1;

	life[5][11] = 1;
	life[6][11] = 1;
	life[7][11] = 1;
	life[4][12] = 1;
	life[8][12] = 1;
	life[3][13] = 1;
	life[9][13] = 1;
	life[3][14] = 1;
	life[9][14] = 1;
	life[6][15] = 1;
	life[4][16] = 1;
	life[8][16] = 1;
	life[5][17] = 1;
	life[6][17] = 1;
	life[7][17] = 1;
	life[6][18] = 1;
	
	life[3][21] = 1;
	life[4][21] = 1;
	life[5][21] = 1;
	life[3][22] = 1;
	life[4][22] = 1;
	life[5][22] = 1;
	life[2][23] = 1;
	life[6][23] = 1;
	life[1][25] = 1;
	life[2][25] = 1;
	life[6][25] = 1;
	life[7][25] = 1;
	life[3][35] = 1;
	life[3][36] = 1;
	life[4][35] = 1;
	life[4][36] = 1;
	
	while (1)
	{
		system("clear");
		print(life, 37, 20);
		life = tick(life, 37, 20);
		sleep(1);
	}
}

int	main(void)
{
	generate();
	return (0);
}
