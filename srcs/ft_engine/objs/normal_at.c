#include <ft_matrix.h>
#include <ft_engine.h>
#include <libft.h>
#include <libft_macros.h>
#include <ft_floats.h>
#include <ft_bump_map.h>

static t_vec	normal_at_iterate_types(t_obj_ptr object, \
		t_point point_obj_space)
{
	if (object->type == OBJ_SPHERE)
		return (compute_normal_sphere(point_obj_space));
	else if (object->type == OBJ_PLANE)
		return (compute_normal_plane(point_obj_space));
	else if (object->type == OBJ_CYLINDER)
		return (compute_normal_cylinder((t_cylinder *)object, point_obj_space));
	else if (object->type == OBJ_CONE)
		return (compute_normal_cone((t_cone *)object, point_obj_space));
	else
		FT_ASSERT(0);
}

t_vec	eng_normal_at(t_obj_ptr object, t_point intersec_point)
{
	t_point		point_obj_space;
	t_vec		normal_obj_space;
	t_vec		normal_world_space;

	point_obj_space = mtx_mult_mt(object->inverse, intersec_point);
	normal_obj_space = normal_at_iterate_types(object, point_obj_space);
	normal_world_space = mtx_mult_mt(mtx_transpose(object->inverse), \
		normal_obj_space);
	normal_world_space.w = 0;
	if (object->material.bump)
		normal_world_space = bump_normal_at(*object, *object->material.bump, \
			intersec_point, normal_world_space);
	return (norm(normal_world_space));
}
