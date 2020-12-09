/* ************************************************************************** */
/*                                                                            */
/*                                                            #               */
/*   Filename: rotate.c                                      ###              */
/*                                                          #####             */
/*   By: mtd42 <https://github.com/mtd42>                  #     #            */
/*                                                        ###   ###           */
/*   Created: 2018/05/27 21:34:10 by mtd42               ##### #####          */
/*   Updated: 2018/05/27 21:34:12 by mtd42        May the force be with you   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		rotate_x(double *y, double *z, double angle)
{
  double	tmp_y;
  double	tmp_z;

  angle = angle * (M_PI / 180);
  tmp_y = *y;
  tmp_z = *z;
  *y = tmp_y * cos(angle) - tmp_z * sin(angle);
  *z = tmp_y * sin(angle) + tmp_z * cos(angle);
}

void		rotate_y(double *x, double *z, double angle)
{
  double	tmp_x;
  double	tmp_z;

  angle = angle * (M_PI / 180);
  tmp_x = *x;
  tmp_z = *z;
  *z = tmp_z * cos(angle) - tmp_x * sin(angle);
  *x = tmp_z * sin(angle) + tmp_x * cos(angle);
}

void		rotate_z(double *x, double *y, double angle)
{
  double	tmp_x;
  double	tmp_y;

  angle = angle * (M_PI / 180);
  tmp_x = *x;
  tmp_y = *y;
  *x = tmp_x * cos(angle) - tmp_y * sin(angle);
  *y = tmp_x * sin(angle) + tmp_y * cos(angle);
}
