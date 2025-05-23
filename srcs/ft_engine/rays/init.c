#include <ft_engine.h>
#include <main.h>
#include <libft.h>

t_ray	eng_new_ray(t_point origin, t_vec direct)
{
	t_ray	ray;

	FT_ASSERT(IS_POINT(direct));
	FT_ASSERT(IS_POINT(direct));
	ray.base_obj = eng_new_obj();
	ray.base_obj.type = OBJ_RAY;
	ray.origin = origin;
	ray.direct = direct;
	return (ray);
}

t_obj	eng_new_obj(void)
{
	t_obj	obj;

	obj.transform = mtx_new_ident(MAT4X4);
	obj.inverse = obj.transform;
	obj.type = OBJ_DEFAULT;
	obj.material = eng_new_material();
	return (obj);
}

t_sphere	eng_new_glass_sphere(void)
{
	t_sphere	sph;

	sph = eng_new_sphere();
	sph.base_obj.material.transparency = 1.0;
	sph.base_obj.material.refractive_index = 1.5;
	return (sph);
}

//sph.origin = new_point(0, 0, 0);
//sph.rad = 1;
t_sphere	eng_new_sphere(void)
{
	t_sphere	sph;

	sph.base_obj = eng_new_obj();
	sph.base_obj.type = OBJ_SPHERE;
	return (sph);
}

t_plane	eng_new_plane(void)
{
	t_plane	plane;

	plane.base_obj = eng_new_obj();
	plane.base_obj.type = OBJ_PLANE;
	return (plane);
}
