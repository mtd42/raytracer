/* ************************************************************************** */
/*                                                                            */
/*                                                            #               */
/*   Filename: shadow.c                                      ###              */
/*                                                          #####             */
/*   By: mtd42 <https://github.com/mtd42>                  #     #            */
/*                                                        ###   ###           */
/*   Created: 2018/05/27 21:34:29 by mtd42               ##### #####          */
/*   Updated: 2018/05/27 21:34:31 by mtd42        May the force be with you   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		sphere_shadow(t_values *val, t_inter *inter,t_spot *spot)
{
  t_values	shadow;

  shadow.eye_x = inter->sphere_coord_x;
  shadow.eye_y = inter->sphere_coord_y;
  shadow.eye_z = inter->sphere_coord_z;
  shadow.eye_angle_x = val->eye_angle_x;
  shadow.eye_angle_y = val->eye_angle_y;
  shadow.eye_angle_z = val->eye_angle_z;
  shadow.vect_x = spot->vect_x;
  shadow.vect_y = spot->vect_y;
  shadow.vect_z = spot->vect_z;
  if (cone_shadow2(val, &shadow) == 1 || cylinder_shadow2(val, &shadow) == 1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		cylinder_shadow(t_values *val, t_inter *inter, t_spot *spot)
{
  t_values	shadow;

  shadow.eye_x = inter->cylinder_coord_x;
  shadow.eye_y = inter->cylinder_coord_y;
  shadow.eye_z = inter->cylinder_coord_z;
  shadow.eye_angle_x = val->eye_angle_x;
  shadow.eye_angle_y = val->eye_angle_y;
  shadow.eye_angle_z = val->eye_angle_z;
  shadow.vect_x = spot->vect_x;
  shadow.vect_y = spot->vect_y;
  shadow.vect_z = spot->vect_z;
  if (sphere_shadow2(val, &shadow) == 1 || cone_shadow2(val, &shadow) == 1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		cone_shadow(t_values *val, t_inter *inter, t_spot *spot)
{
  t_values	shadow;

  shadow.eye_x = inter->cone_coord_x;
  shadow.eye_y = inter->cone_coord_y;
  shadow.eye_z = inter->cone_coord_z;
  shadow.eye_angle_x = val->eye_angle_x;
  shadow.eye_angle_y = val->eye_angle_y;
  shadow.eye_angle_z = val->eye_angle_z;
  shadow.vect_x = spot->vect_x;
  shadow.vect_y = spot->vect_y;
  shadow.vect_z = spot->vect_z;
  if (sphere_shadow2(val, &shadow) == 1 || cylinder_shadow2(val, &shadow) == 1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		plan_shadow(t_values *val, t_inter *inter, t_spot *spot)
{
  t_values	shadow;

  shadow.eye_x = inter->plan_coord_x;
  shadow.eye_y = inter->plan_coord_y;
  shadow.eye_z = inter->plan_coord_z;
  shadow.eye_angle_x = val->eye_angle_x;
  shadow.eye_angle_y = val->eye_angle_y;
  shadow.eye_angle_z = val->eye_angle_z;
  shadow.vect_x = spot->vect_x;
  shadow.vect_y = spot->vect_y;
  shadow.vect_z = spot->vect_z;
  if (sphere_shadow2(val, &shadow) == 1 || cone_shadow2(val, &shadow) == 1 ||
      cylinder_shadow2(val, &shadow) == 1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		shadow(t_values *val, t_inter *inter, t_spot *spot, int object)
{
  int		current_object;

  current_object = 0;
  if (object == SPHERE)
    current_object = sphere_shadow(val, inter, spot);
  else if (object == CYLINDER)
    current_object = cylinder_shadow(val, inter, spot);
  else if (object == CONE)
    current_object = cone_shadow(val, inter, spot);
  else if (object == PLAN)
    current_object = plan_shadow(val, inter, spot);
  return (current_object);
}
