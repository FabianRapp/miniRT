#include <ft_engine.h>
#include <libft.h>
#include <main.h>
#include <ft_bump_map.h>

t_bump	*bump_new_bump(void)
{
	t_bump		*bump;

	bump = ft_malloc(sizeof(t_bump));
	if (!bump)
		ft_error("Malloc failed", __FILE__, __LINE__, 1);
	bump->base_obj = eng_new_obj();
	bump->base_obj.type = OBJ_BUMP;
	bump->type = BUMP_DEFAULT;
	return (bump);
}

t_vec	bump_normal_at(t_obj obj, t_bump bump_map, \
		t_point world_point, t_vec normal_base)
{
	t_point	obj_point;
	t_point	bump_point;

	obj_point = mtx_mult_mt(obj.inverse, world_point);
	bump_point = mtx_mult_mt(bump_map.base_obj.inverse, obj_point);
	FT_ASSERT(bump_map.type != BUMP_DEFAULT);
	if (bump_map.type == BUMP_WAVE)
		return (bump_wave_normal_at(bump_map, bump_point, normal_base));
	FT_ASSERT(0);
}
