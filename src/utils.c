/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 18:17:18 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 19:13:24 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** Check if a string is only digits
*/

int		ft_strisdigit(char *str)
{
	int		is_digit;

	is_digit = 1;
	while (*str && is_digit)
	{
		is_digit = ft_isdigit(*str) ? 1 : 0;
		str++;
	}
	return (is_digit);
}

/*
** Calculate the length of an array
*/

size_t	ft_arraylen(void **array)
{
	size_t	len;

	if (!array)
		return (0);
	len = 0;
	while (*array)
	{
		array++;
		len++;
	}
	return (len);
}

/*
** Returns error
*/

int		error(int is_error)
{
	if (is_error)
		return (-1);
	else
		return (0);
}
