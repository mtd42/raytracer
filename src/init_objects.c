/* ************************************************************************** */
/*                                                                            */
/*                                                            #               */
/*   Filename: init_objects.c                                ###              */
/*                                                          #####             */
/*   By: mtd42 <https://github.com/mtd42>                  #     #            */
/*                                                        ###   ###           */
/*   Created: 2018/05/27 21:31:55 by mtd42               ##### #####          */
/*   Updated: 2018/05/27 21:31:57 by mtd42        May the force be with you   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init_sphere(t_values *val)
{
  val->sphere_x = SPHEREX;
  val->sphere_y = SPHEREY;
  val->sphere_z = SPHEREZ;
  val->sphere_angle_x = SPHEREANGLEX;
  val->sphere_angle_y = SPHEREANGLEY;
  val->sphere_angle_z = SPHEREANGLEZ;
  val->sphere_radius = SPHERERADIUS;
  val->sphere_bright = SPHEREBRIGHT;
  val->sphere_color = SPHERECOLOR;
}

void		init_cylinder(t_values *val)
{
  val->cylinder_x = CYLINDERX;
  val->cylinder_y = CYLINDERY;
  val->cylinder_z = CYLINDERZ;
  val->cylinder_angle_x = CYLINDERANGLEX;
  val->cylinder_angle_y = CYLINDERANGLEY;
  val->cylinder_angle_z = CYLINDERANGLEZ;
  val->cylinder_radius = CYLINDERRADIUS;
  val->cylinder_bright = CYLINDERBRIGHT;
  val->cylinder_color = CYLINDERCOLOR;
}

void		init_cone(t_values *val)
{
  val->cone_x = CONEX;
  val->cone_y = CONEY;
  val->cone_z = CONEZ;
  val->cone_angle_x = CONEANGLEX;
  val->cone_angle_y = CONEANGLEY;
  val->cone_angle_z = CONEANGLEZ;
  val->cone_angle = CONEANGLE;
  val->cone_bright = CONEBRIGHT;
  val->cone_color = CONECOLOR;
}

void		init_plan(t_values *val)
{
  val->plan_x = PLANX;
  val->plan_y = PLANY;
  val->plan_z = PLANZ;
  val->plan_angle_x = PLANANGLEX;
  val->plan_angle_y = PLANANGLEY;
  val->plan_angle_z = PLANANGLEZ;
  val->plan_bright = PLANBRIGHT;
  val->plan_color = PLANCOLOR;
}

void		init(int x, int y, t_values *val, t_spot *spot)
{
  val->eye_x = EYEX;
  val->eye_y = EYEY;
  val->eye_z = EYEZ;
  val->eye_angle_x = EYEANGLEX;
  val->eye_angle_y = EYEANGLEY;
  val->eye_angle_z = EYEANGLEZ;
  val->vect_x = VECTX;
  val->vect_y = VECTY;
  val->vect_z = VECTZ;
  rotate_x(&val->vect_y, &val->vect_z, val->eye_angle_x);
  rotate_y(&val->vect_x, &val->vect_z, val->eye_angle_y);
  rotate_z(&val->vect_x, &val->vect_y, val->eye_angle_z);
  spot->spot_x = SPOTX;
  spot->spot_y = SPOTY;
  spot->spot_z = SPOTZ;
  spot->color = SPOTCOLOR;
}
