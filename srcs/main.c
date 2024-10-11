#include <main.h>

int	main(int ac, char *av[])
{
	t_main	*m_data;

	m_data = get_m_data();
	main_init(m_data, ac, av);
	FT_ASSERT(0);
	return (0);
}
