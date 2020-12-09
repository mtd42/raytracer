/* ************************************************************************** */
/*                                                                            */
/*                                                            #               */
/*   Filename: misc.c                                        ###              */
/*                                                          #####             */
/*   By: mtd42 <https://github.com/mtd42>                  #     #            */
/*                                                        ###   ###           */
/*   Created: 2018/05/27 21:33:38 by mtd42               ##### #####          */
/*   Updated: 2018/05/27 21:33:51 by mtd42        May the force be with you   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		expose_handling(t_system *sys)
{
  mlx_put_image_to_window(sys->mlx, sys->win, sys->image.img, 0, 0);
  return (EXIT_SUCCESS);
}

int		key_handling(int keycode, t_system *param)
{
  if (keycode == ESC)
    {
      mlx_destroy_window(param->mlx, param->win);
      exit (EXIT_SUCCESS);
    }
  return (EXIT_SUCCESS);
}

int		pixel_put_to_image(t_system *sys, int x, int y, int color)
{
  int		pos;

  pos = y * sys->image.sizeline + x * 4;
  sys->image.data[pos] = (color % 256);
  sys->image.data[pos + 1] = ((color >> 8) % 256);
  sys->image.data[pos + 2] = ((color >> 16) % 256);
  sys->image.data[pos + 3] = 0;
  return (EXIT_SUCCESS);
}
