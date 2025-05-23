#include <ft_matrix.h>
#include <libft.h>
#include <libft_macros.h>
#include <ft_floats.h>

void	mtx_print(t_fd fd, t_matrix m)
{
	int	row;
	int	col;

	printf("%dx%dMatrix:\n", (int)m.type, (int)m.type);
	row = 0;
	FT_ASSERT(m.type >= MAT2X2 && m.type <= MAT4X4);
	while (row < (int)m.type)
	{
		col = 0;
		printf("[ ");
		while (col < (int)m.type)
		{
			printf("%10f", m.m[row][col]);
			col++;
			if (col < (int)m.type)
				fprintf(stderr, "\t");
		}
		printf("]\n");
		row++;
	}
	(void)fd;
}

bool	mtx_eq(t_matrix ma, t_matrix mb)
{
	uint8_t	row;
	uint8_t	col;

	if (ma.type != mb.type)
		return (false);
	row = 0;
	while (row < ma.type)
	{
		col = 0;
		while (col < ma.type)
		{
			if (!eq_f(ma.m[row][col], mb.m[row][col]))
				return (false);
			col++;
		}
		row++;
	}
	return (true);
}

bool	mtx_eq_roughly(t_matrix ma, t_matrix mb)
{
	uint8_t	row;
	uint8_t	col;

	if (ma.type != mb.type)
		return (false);
	row = 0;
	while (row < ma.type)
	{
		col = 0;
		while (col < ma.type)
		{
			if (fabs(ma.m[row][col] - mb.m[row][col]) > (EPSILON) * 1000)
				return (false);
			col++;
		}
		row++;
	}
	return (true);
}
