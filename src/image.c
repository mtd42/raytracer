/* ************************************************************************** */
/*                                                                            */
/*                                                            #               */
/*   Filename: image.c                                       ###              */
/*                                                          #####             */
/*   By: mtd42 <https://github.com/mtd42>                  #     #            */
/*                                                        ###   ###           */
/*   Created: 2018/05/27 21:31:47 by mtd42               ##### #####          */
/*   Updated: 2018/05/27 21:31:48 by mtd42        May the force be with you   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_objects(t_values *val)
{
  init_sphere(val);
  init_cylinder(val);
  init_cone(val);
  init_plan(val);
}

unsigned int	calc_image(t_values *val, t_spot *spot)
{
  t_eye		eye;
  t_inter	inter;

  sphere(val, &eye, &inter, 0);
  cylinder(val, &eye, &inter);
  cone(val, &eye, &inter);
  plan(val, &eye, &inter);
  return (get_pixel_color(val, spot, &inter));
}

int		filling(t_system *sys, t_values *val, t_spot *spot)
{
  int		x;
  int		y;
  double	color;

  y = 0;
  while (y != WINY)
    {
      x = 0;
      while (x != WINX)
	{
	  init(x, y, val, spot);
	  color = calc_image(val, spot);
	  if (NEGSCALE == 0)
	    pixel_put_to_image(sys, x, y, color);
	  else
	    pixel_put_to_image(sys, x, y, 256 - color);
	  x++;
	}
      mlx_put_image_to_window(sys->mlx, sys->win, sys->image.img, 0, 0);
      y++;
    }
  return (EXIT_SUCCESS);
}
