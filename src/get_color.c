/* ************************************************************************** */
/*                                                                            */
/*                                                            #               */
/*   Filename: get_color.c                                   ###              */
/*                                                          #####             */
/*   By: mtd42 <https://github.com/mtd42>                  #     #            */
/*                                                        ###   ###           */
/*   Created: 2018/05/27 21:31:07 by mtd42               ##### #####          */
/*   Updated: 2018/05/27 21:31:09 by mtd42        May the force be with you   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

unsigned int	get_pixel_color(t_values *val, t_spot *spot, t_inter *inter)
{
  if (inter->sphere_one > 0 &&
      (inter->sphere_one < inter->plan || inter->plan == -1) &&
      (inter->sphere_one < inter->cone_one || inter->cone_one == -1) &&
      (inter->sphere_one < inter->cylinder_one || inter->cylinder_one == -1))
    return (light(val, inter, spot, SPHERE));
  if (inter->cylinder_one > 0 &&
      (inter->cylinder_one < inter->sphere_one || inter->sphere_one == -1) &&
      (inter->cylinder_one < inter->cone_one || inter->cone_one == -1) &&
      (inter->cylinder_one < inter->plan || inter->plan == -1))
    return (light(val, inter, spot, CYLINDER));
  if (inter->cone_one > 0 &&
      (inter->cone_one < inter->plan || inter->plan == -1) &&
      (inter->cone_one < inter->sphere_one || inter->sphere_one == -1) &&
      (inter->cone_one < inter->cylinder_one || inter->cylinder_one == -1))
    return (light(val, inter, spot, CONE));
  if (inter->plan > 0 &&
      (inter->plan < inter->sphere_one || inter->sphere_one < 0) &&
      (inter->plan < inter->cone_one || inter->cone_one < 0) &&
      (inter->plan < inter->cylinder_one || inter->cylinder_one < 0))
    return (light(val, inter, spot, PLAN));
  return (EXIT_SUCCESS);
}

unsigned int	get_object_color(t_values *val, int object)
{
  unsigned int	color;

  if (object == SPHERE)
    color = val->sphere_color;
  else if (object == CYLINDER)
    color = val->cylinder_color;
  else if (object == CONE)
    color = val->cone_color;
  else if (object == PLAN)
    color = val->plan_color;
  return (color);
}
