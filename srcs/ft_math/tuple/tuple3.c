#include <ft_floats.h>
#include <ft_tuple.h>
#include <libft.h>

double	len_v(t_vec v)
{
	return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w));
}

t_vec	norm(t_vec v)
{
	double	len;

	len = len_v(v);
	return (div_v(v, len));
}

double	dot_prod(t_vec a, t_vec b)
{
	return (a.x * b.x
		+ a.y * b.y
		+ a.z * b.z
		+ a.w * b.w
	);
}

t_vec	cross_prod(t_vec a, t_vec b)
{
	return (new_vec(a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x));
}
