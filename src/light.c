/* ************************************************************************** */
/*                                                                            */
/*                                                            #               */
/*   Filename: light.c                                       ###              */
/*                                                          #####             */
/*   By: mtd42 <https://github.com/mtd42>                  #     #            */
/*                                                        ###   ###           */
/*   Created: 2018/05/27 21:32:13 by mtd42               ##### #####          */
/*   Updated: 2018/05/27 21:32:15 by mtd42        May the force be with you   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

unsigned int	brightness(unsigned int color, unsigned int spot, double bright)
{
  unsigned int	r;
  unsigned int	g;
  unsigned int	b;

  r = ((color >> 16) % 256 * (1 - bright) + (spot >> 16) % 256 * bright);
  g = ((color >> 8) % 256 * (1 - bright) + (spot >> 8) % 256 * bright);
  b = (color % 256 * (1 - bright) + spot % 256 * bright);
  return (color = (r * 0x10000) + (g * 0x100) + b);
}

void	grayscale(unsigned int *tmp, unsigned int *r,
			unsigned int *g, unsigned int *b)
{
  *tmp = (*r + *g + *b) / 3;
  *r = *tmp;
  *g = *tmp;
  *b = *tmp;
}

unsigned int	scales (unsigned int color, unsigned int r,
			unsigned int g, unsigned int b)
{
  unsigned int	tmp;

  tmp = (r + g + b) / 3;
  if (GRAYSCALE == 1)
    {
      grayscale(&tmp, &r, &g, &b);
      color = tmp;
      color = (r * 0x10000) + (g * 0x100) + b;
    }
  else if (REDSCALE == 1)
    color = (tmp * 0x10000);
  else if (GREENSCALE == 1)
    color = (tmp * 0x100);
  else if (BLUESCALE == 1)
    color = tmp;
  else if (NOREDSCALE == 1)
    color = (0 * 0x10000) + (g * 0x100) + b;
  else if (NOGREENSCALE == 1)
    color = (r * 0x10000) + (0 * 0x100) + b;
  else if (NOBLUESCALE == 1)
    color = (r * 0x10000) + (g * 0x100) + 0;
  else
    color = (r * 0x10000) + (g * 0x100) + b;
  return (color);
}

unsigned int	light(t_values *val, t_inter *inter, t_spot *spot, int object)
{
  double	cos;
  unsigned int	color;
  unsigned int	r;
  unsigned int	g;
  unsigned int	b;

  if ((cos = get_cos(spot, inter, object)) < 0)
    return (0);
  color = get_object_color(val, object);
  if (object == SPHERE)
    color = brightness(color, spot->color, val->sphere_bright);
  else if (object == CYLINDER)
    color = brightness(color, spot->color, val->cylinder_bright);
  else if (object == CONE)
    color = brightness(color, spot->color, val->cone_bright);
  else if (object == PLAN)
    color = brightness(color, spot->color, val->plan_bright);
  r = (color >> 16) % 256 * cos;
  g = (color >> 8) % 256 * cos;
  b = color % 256 * cos;
  color = scales(color, r, g, b);
  if (shadow(val, inter, spot, object) == 1)
    return (0);
  return (color);
}
