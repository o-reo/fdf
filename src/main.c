/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/25 16:15:47 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 19:13:27 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** Exits the program cleanly
*/

void     exit_program(s_mlx_params *mlx) 
{
    mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
    mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
    free(mlx);
    exit(0);
}

/*
** Links key press to the matching functions
*/

int    key_loop(int keycode, s_mlx_params *mlx)
{
    keycode == 53 ? exit_program(mlx) : NULL;
    return (0);
}

/*
** Creates the new image
*/

void    display_img(s_mlx_params *mlx)
{
    void    *img_ptr;
    int     bpp;
    int     endian;
    int     size_line;
    char    *img;

    size_line =  WINDOW_WIDTH;
    img_ptr = mlx_new_image(mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    img = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img_ptr, 0, 0);
}

/*
** Appends a pointer void* to an array void** and returns an new array
*/

void     **append(void **array, void *new_item)
{
    int     len;
    void    **new_array;

    len = ft_arraylen(array);
    if (!(new_array = ft_memalloc(sizeof(void*) * (len + 1))))
        return (NULL);
    new_array[len] = new_item;
    while (--len)
        new_array[len] = array[len];
    free(array);
    return (new_array);
}

/*
** Parses input file descriptor
*/

int     **parse_fdf(int fd)
{
    char    *line;
    char    **split;
    int     **img_matrix;

    while (ft_readline(fd, &line) == 1)
    {
        ft_printf("%s\n", line);
        split = ft_strsplit(line, ' ');
        img_matrix = (int**)append((void**)img_matrix, (void*)split);
    }
    return (img_matrix);
}

/*
** Initialize mlx window and distributes to files
*/

int     main(int ac, char **av)
{
    s_mlx_params    *mlx;

    if (ac != 2)
        return (0);
    parse_fdf(open(av[1], O_RDONLY));
    if (!(mlx = ft_memalloc(sizeof(mlx))))
        return (0);
    mlx->mlx_ptr = mlx_init();
    mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
    mlx_key_hook(mlx->win_ptr, key_loop, mlx);
    display_img(mlx);
    mlx_loop(mlx->mlx_ptr);
}