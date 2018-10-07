#include <unistd.h>

#include "sudocu.h"

extern char    g_array[9][9];
extern int        g_solution;

void    determine(int x, int y, int print);


int        place(int y, int x, char a)
{
    int    i;
    int    j;
    
    i = 0;
    while (i < 9)
    {
        if (g_array[y][i] == a || g_array[i][x] == a)
            return (0);
        i++;
    }
    i = (y / 3) * 3;
    while (i < ((y / 3) * 3 + 3))
    {
        j = (x / 3) * 3;
        while (j < ((x / 3) * 3 + 3))
        {
            if (g_array[i][j] == a)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

void    check(int y, int x, int print)
{
    if (x == 8 && y == 8)
    {
        g_solution++;
        if (print)
            print_s();
    }
    else if (x != 8)
        determine(y, x + 1, print);
    else
        determine(y + 1, 0, print);
}

void    determine(int y, int x, int print)
{
    char    a;
    
    if (g_solution > 1)
        return ;
    if (g_array[y][x] != '0')
    {
        check(y, x, print);
    }
    else
    {
        a = '0';
        while (a <= '9')
        {
            if (place(y, x, a))
            {
                g_array[y][x] = a;
                check(y, x, print);
                g_array[y][x] = '0';
            }
            a++;
        }
    }
}


int	check_er(int argc, char **argv)
{
	int i;
	int	j;	
   
	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (((argv[i][j] > '0' && argv[i][j] <= '9') || argv[i][j] == '.') && ft_strlen(argv[i]) == 9)
				{
                if (argv[i][j] == '.')
					g_array[i - 1][j] = '0';
                else
					g_array[i - 1][j] = argv[i][j];
				}
			else
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int        main(int argc, char **argv)
{
	int	res;
	res = check_er(argc, argv);
	g_solution = 0;
	determine(0, 0, 0);
    if (g_solution != 1 || argc != 10 || res)
    {
		write(1, "Error\n", 6);
        return (0);
    }
	determine(0, 0, 1);
    return (0);
}
