/* ************************************************************************** */
/*                                                                            */
/*                                                            #               */
/*   Filename: shadow2.c                                     ###              */
/*                                                          #####             */
/*   By: mtd42 <https://github.com/mtd42>                  #     #            */
/*                                                        ###   ###           */
/*   Created: 2018/05/27 21:34:20 by mtd42               ##### #####          */
/*   Updated: 2018/05/27 21:34:21 by mtd42        May the force be with you   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		sphere_shadow2(t_values *val, t_values *shadow)
{
  double	k;
  t_inter	inter;
  t_eye		eye;

  shadow->sphere_x = val->sphere_x;
  shadow->sphere_y = val->sphere_y;
  shadow->sphere_z = val->sphere_z;
  shadow->sphere_angle_x = val->sphere_angle_x;
  shadow->sphere_angle_y = val->sphere_angle_y;
  shadow->sphere_angle_z = val->sphere_angle_z;
  shadow->sphere_radius = val->sphere_radius;
  k = sphere(shadow, &eye, &inter, 0);
  if (k > 0 && k < 1.0001)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		cylinder_shadow2(t_values *val, t_values *shadow)
{
  double	k;
  t_inter	inter;
  t_eye		eye;

  shadow->cylinder_x = val->cylinder_x;
  shadow->cylinder_y = val->cylinder_y;
  shadow->cylinder_z = val->cylinder_z;
  shadow->cylinder_angle_x = val->cylinder_angle_x;
  shadow->cylinder_angle_y = val->cylinder_angle_y;
  shadow->cylinder_angle_z = val->cylinder_angle_z;
  shadow->cylinder_radius = val->cylinder_radius;
  k = cylinder(shadow, &eye, &inter);
  if (k > 0 && k < 1.0001)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		cone_shadow2(t_values *val, t_values *shadow)
{
  double	k;
  t_inter	inter;
  t_eye		eye;

  shadow->cone_x = val->cone_x;
  shadow->cone_y = val->cone_y;
  shadow->cone_z = val->cone_z;
  shadow->cone_angle_x = val->cone_angle_x;
  shadow->cone_angle_y = val->cone_angle_y;
  shadow->cone_angle_z = val->cone_angle_z;
  shadow->cone_angle = val->cone_angle;
  k = cone(shadow, &eye, &inter);
  if (k > 0 && k < 1.0001)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
