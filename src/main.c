/* ************************************************************************** */
/*                                                                            */
/*                                                            #               */
/*   Filename: main.c                                        ###              */
/*                                                          #####             */
/*   By: mtd42 <https://github.com/mtd42>                  #     #            */
/*                                                        ###   ###           */
/*   Created: 2018/05/27 21:32:26 by mtd42               ##### #####          */
/*   Updated: 2018/05/27 21:32:29 by mtd42        May the force be with you   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_system	*init_mlx()
{
  t_system	*sys;

  if ((sys = malloc(sizeof(*sys))) == NULL)
    return (NULL);
  if ((sys->mlx = mlx_init()) == NULL)
    return (NULL);
  sys->win = mlx_new_window(sys->mlx, WINX, WINY, "RT");
  sys->image.img = mlx_new_image(sys->mlx, WINX, WINY);
  sys->image.data = mlx_get_data_addr
    (sys->image.img, &sys->image.bpp, &sys->image.sizeline, &sys->image.endian);
  return (sys);
}

int		main()
{
  t_system	*sys;
  t_values	val;
  t_spot	spot;

  if ((sys = init_mlx()) == NULL)
    return (EXIT_FAILURE);
  init_objects(&val);
  filling(sys, &val, &spot);
  mlx_key_hook(sys->win, key_handling, sys);
  mlx_expose_hook(sys->win, expose_handling, sys);
  mlx_loop(sys->mlx);
  return (EXIT_SUCCESS);
}
