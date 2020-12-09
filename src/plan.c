/* ************************************************************************** */
/*                                                                            */
/*                                                            #               */
/*   Filename: plan.c                                        ###              */
/*                                                          #####             */
/*   By: mtd42 <https://github.com/mtd42>                  #     #            */
/*                                                        ###   ###           */
/*   Created: 2018/05/27 21:34:00 by mtd42               ##### #####          */
/*   Updated: 2018/05/27 21:34:03 by mtd42        May the force be with you   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_plan_eye(t_values *val, t_eye *eye)
{
  eye->eye_x = val->eye_x - val->plan_x;
  eye->eye_y = val->eye_y - val->plan_y;
  eye->eye_z = val->eye_z - val->plan_z;
  rotate_x(&eye->eye_y, &eye->eye_z, -val->plan_angle_x);
  rotate_y(&eye->eye_x, &eye->eye_z, -val->plan_angle_y);
  rotate_z(&eye->eye_x, &eye->eye_y, -val->plan_angle_z);
  eye->vect_x = val->vect_x;
  eye->vect_y = val->vect_y;
  eye->vect_z = val->vect_z;
  rotate_x(&eye->vect_y, &eye->vect_z, -val->plan_angle_x);
  rotate_y(&eye->vect_x, &eye->vect_z, -val->plan_angle_y);
  rotate_z(&eye->vect_x, &eye->vect_y, -val->plan_angle_z);
}

double	get_abscisse(double vect)
{
  if (vect < 0)
    return (-vect);
  return (vect);
}

double		plan(t_values *val, t_eye *eye, t_inter *inter)
{
  double	k;

  get_plan_eye(val, eye);
  inter->plan = -1;
  if (get_abscisse(eye->vect_z) < 0.0001)
    return (0);
  k = eye->eye_z / eye->vect_z;
  k = -k;
  if (k < 0)
    return (0);
  inter->plan = k;
  inter->plan_coord_x = val->eye_x + k * val->vect_x;
  inter->plan_coord_y = val->eye_y + k * val->vect_y;
  inter->plan_coord_z = val->eye_z + k * val->vect_z;
  inter->plan_normal_x = 0;
  inter->plan_normal_y = 0;
  inter->plan_normal_z = 100;
  rotate_x(&inter->plan_normal_y, &inter->plan_normal_z, val->plan_angle_x);
  rotate_y(&inter->plan_normal_x, &inter->plan_normal_z, val->plan_angle_y);
  rotate_z(&inter->plan_normal_x, &inter->plan_normal_y, val->plan_angle_z);
  return (k);
}
