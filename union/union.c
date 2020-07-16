
#include <unistd.h>

int main (int argc, char **argv)
{
	int flag[255] = {0};
	int x;
	int y;

	if (argc == 3)
	{
		x = 1;
		while (x < 3)
		{
			y = 0;
			while (argv[x][y])
			{
				if (!flag[(unsigned char)argv[x][y]])
				{
					flag[(unsigned char)argv[x][y]] = 1;
					write(1, &argv[x][y], 1);
				}
				y++;
			}
			x++;
		}
	}
	write(1, "\n", 1);
	return(0);
}