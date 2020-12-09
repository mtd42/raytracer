/* ************************************************************************** */
/*                                                                            */
/*                                                            #               */
/*   Filename: cylinder.c                                    ###              */
/*                                                          #####             */
/*   By: mtd42 <https://github.com/mtd42>                  #     #            */
/*                                                        ###   ###           */
/*   Created: 2018/05/27 21:31:10 by mtd42               ##### #####          */
/*   Updated: 2018/05/27 21:31:12 by mtd42        May the force be with you   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_cylinder_eye(t_values *val, t_eye *eye)
{
  eye->eye_x = val->eye_x - val->cylinder_x;
  eye->eye_y = val->eye_y - val->cylinder_y;
  eye->eye_z = val->eye_z - val->cylinder_z;
  rotate_x(&eye->eye_y, &eye->eye_z, -val->cylinder_angle_x);
  rotate_y(&eye->eye_x, &eye->eye_z, -val->cylinder_angle_y);
  rotate_z(&eye->eye_x, &eye->eye_y, -val->cylinder_angle_z);
  eye->vect_x = val->vect_x;
  eye->vect_y = val->vect_y;
  eye->vect_z = val->vect_z;
  rotate_x(&eye->vect_y, &eye->vect_z, -val->cylinder_angle_x);
  rotate_y(&eye->vect_x, &eye->vect_z, -val->cylinder_angle_y);
  rotate_z(&eye->vect_x, &eye->vect_y, -val->cylinder_angle_z);
}

void	get_cylinder_inter(t_inter *inter, double delta, double a, double b)
{
  if (delta >= 0)
  {
    inter->cylinder_one = (-b - sqrt(delta)) / (2.0 * a);
    inter->cylinder_two = inter->cylinder_one;
  }
  if (delta > 0)
    inter->cylinder_two = (-b + sqrt(delta)) / (2.0 * a);
  if (inter->cylinder_two > 0 && inter->cylinder_two < inter->cylinder_one)
    inter->cylinder_one = inter->cylinder_two;
}

int	calc_cylinder(t_inter *inter, t_values *val, double *cylinder)
{
  inter->cylinder_coord_x = val->eye_x + *cylinder * val->vect_x;
  inter->cylinder_coord_y = val->eye_y + *cylinder * val->vect_y;
  inter->cylinder_coord_z = val->eye_z + *cylinder * val->vect_z;
  inter->cylinder_normal_x = inter->cylinder_coord_x - val->cylinder_x;
  inter->cylinder_normal_y = inter->cylinder_coord_y - val->cylinder_y;
  inter->cylinder_normal_z = 0;
  return (EXIT_SUCCESS);
}

double		cylinder(t_values *val, t_eye *eye, t_inter *inter)
{
  double	delta;
  double	a;
  double	b;
  double	c;

  get_cylinder_eye(val, eye);
  a = pow(eye->vect_x, 2) + pow(eye->vect_y, 2);
  b = (2.0 * eye->eye_x * eye->vect_x) + (2.0 * eye->eye_y * eye->vect_y);
  c = pow(eye->eye_x, 2) + pow(eye->eye_y, 2) - pow(val->cylinder_radius, 2);
  inter->cylinder_one = -1;
  inter->cylinder_two = -1;
  if ((delta = pow(b, 2) - (4.0 * a * c)) < 0)
    return (-1);
  get_cylinder_inter(inter, delta, a, b);
  calc_cylinder(inter, val, &inter->cylinder_one);
  return (inter->cylinder_one);
}
