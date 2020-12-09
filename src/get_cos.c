/* ************************************************************************** */
/*                                                                            */
/*                                                            #               */
/*   Filename: get_cos.c                                     ###              */
/*                                                          #####             */
/*   By: mtd42 <https://github.com/mtd42>                  #     #            */
/*                                                        ###   ###           */
/*   Created: 2018/05/27 21:31:33 by mtd42               ##### #####          */
/*   Updated: 2018/05/27 21:31:35 by mtd42        May the force be with you   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		get_sphere_cos(t_spot *spot, t_inter *inter)
{
  double	cos;

  spot->vect_x = spot->spot_x - inter->sphere_coord_x;
  spot->vect_y = spot->spot_y - inter->sphere_coord_y;
  spot->vect_z = spot->spot_z - inter->sphere_coord_z;
  spot->scalar = spot->vect_x * inter->sphere_normal_x;
  spot->scalar += spot->vect_y * inter->sphere_normal_y;
  spot->scalar += spot->vect_z * inter->sphere_normal_z;
  spot->norme_light = sqrt((spot->vect_x * spot->vect_x)
		       + (spot->vect_y * spot->vect_y)
		       + (spot->vect_z * spot->vect_z));
  spot->norme_obj = sqrt((inter->sphere_normal_x * inter->sphere_normal_x)
			 + (inter->sphere_normal_y * inter->sphere_normal_y)
			 + (inter->sphere_normal_z * inter->sphere_normal_z));
  cos = -1;
  if (spot->norme_light * spot->norme_obj != 0)
    cos = (spot->scalar / (spot->norme_light * spot->norme_obj));
  return (cos);
}

double		get_cylinder_cos(t_spot *spot, t_inter *inter)
{
  double	cos;

  spot->vect_x = spot->spot_x - inter->cylinder_coord_x;
  spot->vect_y = spot->spot_y - inter->cylinder_coord_y;
  spot->vect_z = spot->spot_z - inter->cylinder_coord_z;
  spot->scalar = spot->vect_x * inter->cylinder_normal_x;
  spot->scalar += spot->vect_y * inter->cylinder_normal_y;
  spot->scalar += spot->vect_z * inter->cylinder_normal_z;
  spot->norme_light = sqrt((spot->vect_x * spot->vect_x) +
		       (spot->vect_y * spot->vect_y) +
		       (spot->vect_z * spot->vect_z));
  spot->norme_obj = sqrt((inter->cylinder_normal_x * inter->cylinder_normal_x) +
			 (inter->cylinder_normal_y * inter->cylinder_normal_y) +
			 (inter->cylinder_normal_z * inter->cylinder_normal_z));
  cos = -1;
  if (spot->norme_light * spot->norme_obj != 0)
    cos = (spot->scalar / (spot->norme_light * spot->norme_obj));
  return (cos);
}

double		get_cone_cos(t_spot *spot, t_inter *inter)
{
  double	cos;

  spot->vect_x = spot->spot_x - inter->cone_coord_x;
  spot->vect_y = spot->spot_y - inter->cone_coord_y;
  spot->vect_z = spot->spot_z - inter->cone_coord_z;
  spot->scalar = spot->vect_x * inter->cone_normal_x;
  spot->scalar += spot->vect_y * inter->cone_normal_y;
  spot->scalar += spot->vect_z * inter->cone_normal_z;
  spot->norme_light = sqrt((spot->vect_x * spot->vect_x)
		       + (spot->vect_y * spot->vect_y)
		       + (spot->vect_z * spot->vect_z));
  spot->norme_obj = sqrt((inter->cone_normal_x * inter->cone_normal_x)
			 + (inter->cone_normal_y * inter->cone_normal_y)
			 + (inter->cone_normal_z * inter->cone_normal_z));
  cos = -1;
  if (spot->norme_light * spot->norme_obj != 0)
    cos = (spot->scalar / (spot->norme_light * spot->norme_obj));
  return (cos);
}

double		get_plan_cos(t_spot *spot, t_inter *inter)
{
  double	cos;

  spot->vect_x = spot->spot_x - inter->plan_coord_x;
  spot->vect_y = spot->spot_y - inter->plan_coord_y;
  spot->vect_z = spot->spot_z - inter->plan_coord_z;
  spot->scalar = spot->vect_x * inter->plan_normal_x;
  spot->scalar += spot->vect_y * inter->plan_normal_y;
  spot->scalar += spot->vect_z * inter->plan_normal_z;
  spot->norme_light = sqrt((spot->vect_x * spot->vect_x)
		       + (spot->vect_y * spot->vect_y)
		       + (spot->vect_z * spot->vect_z));
  spot->norme_obj = sqrt((inter->plan_normal_x * inter->plan_normal_x)
			 + (inter->plan_normal_y * inter->plan_normal_y)
			 + (inter->plan_normal_z * inter->plan_normal_z));
  cos = -1;
  if (spot->norme_light * spot->norme_obj != 0)
    cos = (spot->scalar / (spot->norme_light * spot->norme_obj));
  return (cos);
}

double		get_cos(t_spot *spot, t_inter *inter, int object)
{
  double	cos;

  cos = -1;
  if (object == SPHERE)
    cos = get_sphere_cos(spot, inter);
  else if (object == CYLINDER)
    cos = get_cylinder_cos(spot, inter);
  else if (object == CONE)
    cos = get_cone_cos(spot, inter);
  else if (object == PLAN)
    cos = get_plan_cos(spot, inter);
  return (cos);
}
