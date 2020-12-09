/* ************************************************************************** */
/*                                                                            */
/*                                                            #               */
/*   Filename: sphere.c                                      ###              */
/*                                                          #####             */
/*   By: mtd42 <https://github.com/mtd42>                  #     #            */
/*                                                        ###   ###           */
/*   Created: 2018/05/27 21:34:37 by mtd42               ##### #####          */
/*   Updated: 2018/05/27 21:34:39 by mtd42        May the force be with you   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_sphere_eye(t_values *val, t_eye *eye)
{
  eye->eye_x = val->eye_x - val->sphere_x;
  eye->eye_y = val->eye_y - val->sphere_y;
  eye->eye_z = val->eye_z - val->sphere_z;
  rotate_x(&eye->eye_y, &eye->eye_z, -val->sphere_angle_x);
  rotate_y(&eye->eye_x, &eye->eye_z, -val->sphere_angle_y);
  rotate_z(&eye->eye_x, &eye->eye_y, -val->sphere_angle_z);
  eye->vect_x = val->vect_x;
  eye->vect_y = val->vect_y;
  eye->vect_z = val->vect_z;
  rotate_x(&eye->vect_y, &eye->vect_z, -val->sphere_angle_x);
  rotate_y(&eye->vect_x, &eye->vect_z, -val->sphere_angle_y);
  rotate_z(&eye->vect_x, &eye->vect_y, -val->sphere_angle_z);
}

void	get_sphere_inter(t_inter *inter, double delta, double a, double b)
{
  if (delta >= 0)
  {
    inter->sphere_one = (-b - sqrt(delta)) / (2.0 * a);
    inter->sphere_two = inter->sphere_one;
  }
  if (delta > 0)
    inter->sphere_two = (-b + sqrt(delta)) / (2.0 * a);
  if (inter->sphere_two > 0 && inter->sphere_two < inter->sphere_one)
    inter->sphere_one = inter->sphere_two;
}

void	calc_sphere(t_inter *inter, t_values *val, double *sphere)
{
  inter->sphere_coord_x = val->eye_x + *sphere * val->vect_x;
  inter->sphere_coord_y = val->eye_y + *sphere * val->vect_y;
  inter->sphere_coord_z = val->eye_z + *sphere * val->vect_z;
  inter->sphere_normal_x = inter->sphere_coord_x - val->sphere_x;
  inter->sphere_normal_y = inter->sphere_coord_y - val->sphere_y;
  inter->sphere_normal_z = inter->sphere_coord_z - val->sphere_z;
  rotate_x(&inter->sphere_normal_y, &inter->sphere_normal_z,
	   val->sphere_angle_x);
  rotate_y(&inter->sphere_normal_x, &inter->sphere_normal_z,
	   val->sphere_angle_y);
  rotate_z(&inter->sphere_normal_x, &inter->sphere_normal_y,
	   val->sphere_angle_z);
}

double		sphere(t_values *val, t_eye *eye, t_inter *inter, double delta)
{
  double	a;
  double	b;
  double	c;

  get_sphere_eye(val, eye);
  a = pow(eye->vect_x, 2) + pow(eye->vect_y, 2) + pow(eye->vect_z, 2);
  b = ((eye->eye_x * eye->vect_x) + (eye->eye_y * eye->vect_y) +
       (eye->eye_z * eye->vect_z)) * 2.0;
  c = (pow(eye->eye_x, 2) + pow(eye->eye_y, 2) + pow(eye->eye_z, 2)) -
    pow(val->sphere_radius, 2);
  inter->sphere_one = -1;
  inter->sphere_two = -1;
  if ((delta = pow(b, 2) - (4.0 * a * c)) < 0)
    return (-1);
  get_sphere_inter(inter, delta, a, b);
  calc_sphere(inter, val, &inter->sphere_one);
  return (inter->sphere_one);
}
