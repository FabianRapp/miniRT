#ifndef FT_TUPLE_H
# define FT_TUPLE_H

# include <stdbool.h>

//keep x,y,z as the first elements to allow casting t_tuple* to double*
typedef union u_tuple
{
	struct
	{
		double	x;
		double	y;
		double	z;
		double	w;
	}__attribute__((aligned(16)));
	double		arr[4];
}	t_tuple;

typedef t_tuple	t_vec;
typedef t_tuple	t_point;

# ifndef IS_VEC
#  define IS_VEC(tuple) (EQ_F(tuple.w, 0.0))
# endif//IS_VEC

# ifndef IS_POINT
#  define IS_POINT(tuple) (EQ_F(tuple.w, 0.0))
# endif //IS_POINT

// for vecs w == 0
bool	is_vec(t_tuple tuple);
// for points w == 1
bool	is_point(t_tuple tuple);

t_point	new_point(double x, double y, double z);
t_vec	new_vec(double x, double y, double z);

//equal tuple
bool	eq_t(t_tuple a, t_tuple b);

t_tuple	add_t(t_tuple a, t_tuple b);

t_tuple	sub_t(t_tuple a, t_tuple b);
// tests to verify add_t adn sub_t with special focus on w

t_vec	negate_v(t_vec v);
//negate_t test

t_vec	mult_v(t_vec v, double scalar);
t_vec	div_v(t_vec v, double scalar);

//len/magnitude
double	len_v(t_vec v);

//creates uint vector (len == 1)
t_vec	norm(t_vec v);

double	dot_prod(t_vec a, t_vec b);
t_vec	cross_prod(t_vec a, t_vec b);

//******tests**********

void	print_t(int fd, t_tuple t);

t_tuple	get_rdm_tuple(void);
bool	is_point_test(void);
bool	is_vec_test(void);

//Comapare Points
int		p_compareifequal(t_point a, t_point b);

//Comapare Tubles including the w
int		t_check_ifequal(t_tuple a, t_tuple b);

#endif
