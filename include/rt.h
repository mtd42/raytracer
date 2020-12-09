/* ************************************************************************** */
/*                                                                            */
/*                                                            #               */
/*   Filename: rt.h                                          ###              */
/*                                                          #####             */
/*   By: mtd42 <https://github.com/mtd42>                  #     #            */
/*                                                        ###   ###           */
/*   Created: 2018/05/27 21:30:00 by mtd42               ##### #####          */
/*   Updated: 2018/05/27 21:30:04 by mtd42        May the force be with you   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H_
# define RT_H_

# include <mlx.h>
# include <math.h>
# include <stdlib.h>

# define WINX			1920
# define WINY			1080
# define DISTANCE		500
# define SPHERE			1
# define CYLINDER		2
# define CONE			3
# define PLAN			4
# define NEGSCALE		0
# define GRAYSCALE		0
# define REDSCALE		0
# define GREENSCALE		0
# define BLUESCALE		0
# define NOREDSCALE		0
# define NOGREENSCALE		0
# define NOBLUESCALE		0
# define ESC			65307
# define SPHEREX		0
# define SPHEREY		450
# define SPHEREZ		100
# define SPHEREANGLEX		0
# define SPHEREANGLEY		0
# define SPHEREANGLEZ		0
# define SPHERERADIUS		75
# define SPHEREBRIGHT		0.4
# define SPHERECOLOR		0xC30A55;
# define CYLINDERX		0
# define CYLINDERY		150
# define CYLINDERZ		0
# define CYLINDERANGLEX		0
# define CYLINDERANGLEY		0
# define CYLINDERANGLEZ		0
# define CYLINDERRADIUS		75
# define CYLINDERBRIGHT		0.5
# define CYLINDERCOLOR		0x89B4FD
# define CONEX			0
# define CONEY			-250
# define CONEZ			0
# define CONEANGLEX		0
# define CONEANGLEY		0
# define CONEANGLEZ		0
# define CONEANGLE		3
# define CONEBRIGHT		0.3
# define CONECOLOR		0xF0E68C
# define PLANX			0
# define PLANY			0
# define PLANZ			-50
# define PLANANGLEX		0
# define PLANANGLEY		0
# define PLANANGLEZ		0
# define PLANBRIGHT		0.7
# define PLANCOLOR		0x2FBF78
# define EYEX			-300
# define EYEY			100
# define EYEZ			100
# define EYEANGLEX		0
# define EYEANGLEY		0
# define EYEANGLEZ		0
# define VECTX			DISTANCE
# define VECTY			(WINX / 2.0) - x
# define VECTZ			(WINY / 2.0) - y
# define SPOTX			-300
# define SPOTY			200
# define SPOTZ			200
# define SPOTCOLOR		0xFFFFFF

typedef struct		s_image
{
  void			*img;
  char			*data;
  int			bpp;
  int			sizeline;
  int			endian;
}			t_image;

typedef struct		s_system
{
  void			*mlx;
  void			*win;
  t_image		image;
}			t_system;

typedef struct		s_values
{
  double		eye_x;
  double		eye_y;
  double		eye_z;
  double		eye_angle_x;
  double		eye_angle_y;
  double		eye_angle_z;
  double		vect_x;
  double		vect_y;
  double		vect_z;
  double		sphere_x;
  double		sphere_y;
  double		sphere_z;
  double		sphere_angle_x;
  double		sphere_angle_y;
  double		sphere_angle_z;
  double		sphere_radius;
  double		sphere_bright;
  unsigned int		sphere_color;
  double		cylinder_x;
  double		cylinder_y;
  double		cylinder_z;
  double		cylinder_angle_x;
  double		cylinder_angle_y;
  double		cylinder_angle_z;
  double		cylinder_radius;
  double		cylinder_bright;
  unsigned int		cylinder_color;
  double		cone_x;
  double		cone_y;
  double		cone_z;
  double		cone_angle_x;
  double		cone_angle_y;
  double		cone_angle_z;
  double		cone_angle;
  double		cone_bright;
  unsigned int		cone_color;
  double		plan_x;
  double		plan_y;
  double		plan_z;
  double		plan_angle_x;
  double		plan_angle_y;
  double		plan_angle_z;
  double		plan_bright;
  unsigned int		plan_color;
}			t_values;

typedef struct		s_spot
{
  double		spot_x;
  double		spot_y;
  double		spot_z;
  double		vect_x;
  double		vect_y;
  double		vect_z;
  double		norme_light;
  double		norme_obj;
  double		scalar;
  unsigned int		color;
}			t_spot;

typedef struct		s_eye
{
  double		eye_x;
  double		eye_y;
  double		eye_z;
  double		eye_angle_x;
  double		eye_angle_y;
  double		eye_angle_z;
  double		vect_x;
  double		vect_y;
  double		vect_z;
}			t_eye;

typedef struct		s_inter
{
  double		sphere_one;
  double		sphere_two;
  double		sphere_coord_x;
  double		sphere_coord_y;
  double		sphere_coord_z;
  double		sphere_normal_x;
  double		sphere_normal_y;
  double		sphere_normal_z;
  double		cylinder_one;
  double		cylinder_two;
  double		cylinder_coord_x;
  double		cylinder_coord_y;
  double		cylinder_coord_z;
  double		cylinder_normal_x;
  double		cylinder_normal_y;
  double		cylinder_normal_z;
  double		cone_one;
  double		cone_two;
  double		cone_coord_x;
  double		cone_coord_y;
  double		cone_coord_z;
  double		cone_normal_x;
  double		cone_normal_y;
  double		cone_normal_z;
  double		plan;
  double		plan_coord_x;
  double		plan_coord_y;
  double		plan_coord_z;
  double		plan_normal_x;
  double		plan_normal_y;
  double		plan_normal_z;
}			t_inter;

void		get_sphere_eye(t_values *val, t_eye *eye);
void		get_sphere_inter(t_inter *inter, double delta, double b, double a);
void		calc_sphere(t_inter *inter, t_values *val, double *sphere);
double		sphere(t_values *val, t_eye *eye, t_inter *inter, double delta);
int		sphere_shadow(t_values *val, t_inter *inter,t_spot *spot);
int		cylinder_shadow(t_values *val, t_inter *inter, t_spot *spot);
int		cone_shadow(t_values *val, t_inter *inter, t_spot *spot);
int		plan_shadow(t_values *val, t_inter *inter, t_spot *spot);
int		shadow(t_values *val, t_inter *inter, t_spot *spot, int object);
void		rotate_x(double *y, double *z, double angle);
void		rotate_y(double *x, double *z, double angle);
void		rotate_z(double *x, double *y, double angle);
t_system	*init_mlx();
int		expose_handling(t_system *sys);
int		key_handling(int keycode, t_system *sys);
unsigned int	calc_image(t_values *val, t_spot *spot);
void		init_sphere(t_values *val);
void		init_sphere2(t_values *val);
void		init_cylinder(t_values *val);
void		init_cone(t_values *val);
void		init_plan(t_values *val);
void		init(int x, int y, t_values *val, t_spot *spot);
double		get_sphere_cos(t_spot *spot, t_inter *inter);
double		get_cylinder_cos(t_spot *spot, t_inter *inter);
double		get_cone_cos(t_spot *spot, t_inter *inter);
double		get_plan_cos(t_spot *spot, t_inter *inter);
double		get_cos(t_spot *spot, t_inter *inter, int object);
void		get_cylinder_eye(t_values *val, t_eye *eye);
void		get_cylinder_inter(t_inter *inter, double delta, double a, double b);
int		calc_cylinder(t_inter *inter, t_values *val, double *cylinder);
double		cylinder(t_values *val, t_eye *eye, t_inter *inter);
void		get_cone_eye(t_values *val, t_eye *eye);
void		get_cone_inter(t_inter *inter, double delta, double a, double b);
void		calc_cone(t_inter *inter, t_values *val, double *cone);
double		cone(t_values *val, t_eye *eye, t_inter *inter);
unsigned int	get_pixel_color(t_values *val, t_spot *spot, t_inter *inter);
unsigned int	get_object_color(t_values *val, int object);
void		init_objects(t_values *val);
int		pixel_put_to_image(t_system *sys, int x, int y, int color);
int		filling(t_system *sys, t_values *val, t_spot *spot);
unsigned int	brightness(unsigned int color, unsigned int spot, double bright);
void		grayscale(unsigned int *tmp, unsigned int *r,
			  unsigned int *g, unsigned int *b);
unsigned int	scales (unsigned int color, unsigned int r,
			unsigned int g, unsigned int b);
unsigned int	light(t_values *val, t_inter *inter, t_spot *spot,
			   int object);
void		get_plan_eye(t_values *val, t_eye *eye);
double		get_abscisse(double n);
double		plan(t_values *val, t_eye *eye, t_inter *inter);
int		sphere_shadow2(t_values *val, t_values *shadow_val);
int		cylinder_shadow2(t_values *val, t_values *shadow_val);
int		cone_shadow2(t_values *val, t_values *shadow_val);
void		my_pixel_put_to_image(t_system *sys, int x, int y, int color);

#endif /* !RT_H_ */
