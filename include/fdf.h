/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/25 16:16:22 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 19:05:22 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../minilibx_macos/mlx.h"
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500

typedef struct  t_mlx_params {
    void        *mlx_ptr;
    void        *win_ptr;
}               s_mlx_params;

size_t	        ft_arraylen(void **array);

#endif