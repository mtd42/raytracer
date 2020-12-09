/* ************************************************************************** */
/*                                                                            */
/*                                                            #               */
/*   Filename: cone.c                                        ###              */
/*                                                          #####             */
/*   By: mtd42 <https://github.com/mtd42>                  #     #            */
/*                                                        ###   ###           */
/*   Created: 2018/05/27 21:30:28 by mtd42               ##### #####          */
/*   Updated: 2018/05/27 21:30:44 by mtd42        May the force be with you   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_cone_eye(t_values *val, t_eye *eye)
{
  eye->eye_x = val->eye_x - val->cone_x;
  eye->eye_y = val->eye_y - val->cone_y;
  eye->eye_z = val->eye_z - val->cone_z;
  rotate_x(&eye->eye_y, &eye->eye_z, -val->cone_angle_x);
  rotate_y(&eye->eye_x, &eye->eye_z, -val->cone_angle_y);
  rotate_z(&eye->eye_x, &eye->eye_y, -val->cone_angle_z);
  eye->vect_x = val->vect_x;
  eye->vect_y = val->vect_y;
  eye->vect_z = val->vect_z;
  rotate_x(&eye->vect_y, &eye->vect_z, -val->cone_angle_x);
  rotate_y(&eye->vect_x, &eye->vect_z, -val->cone_angle_y);
  rotate_z(&eye->vect_x, &eye->vect_y, -val->cone_angle_z);
}

void	get_cone_inter(t_inter *inter, double delta, double a, double b)
{
  if (delta >= 0)
  {
    inter->cone_one = (-b - sqrt(delta)) / (2.0 * a);
    inter->cone_two = inter->cone_one;
  }
  if (delta > 0)
    inter->cone_two = (-b + sqrt(delta)) / (2.0 * a);
  if (inter->cone_two > 0 && inter->cone_two < inter->cone_one)
    inter->cone_one = inter->cone_two;
}

void	calc_cone(t_inter *inter, t_values *val, double *cone)
{
  inter->cone_coord_x = val->eye_x + *cone * val->vect_x;
  inter->cone_coord_y = val->eye_y + *cone * val->vect_y;
  inter->cone_coord_z = val->eye_z + *cone * val->vect_z;
  inter->cone_normal_x = inter->cone_coord_x - val->cone_x;
  inter->cone_normal_y = inter->cone_coord_y - val->cone_y;
  inter->cone_normal_z = -tan(val->cone_angle * M_PI / 180) *
    inter->cone_coord_z - val->cone_z;
}

double		cone(t_values *val, t_eye *eye, t_inter *inter)
{
  double	a;
  double	b;
  double	c;
  double	tmp;
  double	delta;

  get_cone_eye(val, eye);
  inter->cone_one = -1;
  inter->cone_two = -1;
  tmp = tan(val->cone_angle * (M_PI / 180));
  a = pow(eye->vect_x, 2) + pow(eye->vect_y, 2) - pow(eye->vect_z, 2) * tmp;
  b = (2.0 * eye->eye_x * eye->vect_x) + (2.0 * eye->eye_y *eye->vect_y) -
    (2.0 * eye->eye_z * eye->vect_z) * tmp;
  c = pow(eye->eye_x, 2) + pow(eye->eye_y, 2) - pow(eye->eye_z, 2) * tmp;
  if ((delta = pow(b, 2) - (4.0 * a * c)) < 0)
    return (-1);
  get_cone_inter(inter, delta, a, b);
  calc_cone(inter, val, &inter->cone_one);
  if (eye->eye_z + inter->cone_one * eye->vect_z < 0)
    inter->cone_one = -1;
  return (inter->cone_one);
}
