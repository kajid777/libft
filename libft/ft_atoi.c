/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:51:20 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/06 18:11:01 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isspace(char x)
{
	if (x == '\t')
		return (1);
	if (x == '\n')
		return (1);
	if (x == '\v')
		return (1);
	if (x == '\f')
		return (1);
	if (x == '\r')
		return (1);
	if (x == ' ')
		return (1);
	return (0);
}

static int	overflowl(int sign, long l, char next)
{
	if (sign == 1)
		if (LONG_MAX / 10 < l
			|| (LONG_MAX / 10 == l && LONG_MAX % 10 <= next - '0'))
			return (1);
	if (sign == -1)
		if (LONG_MIN / -10 < l
			|| (LONG_MIN / -10 == l && LONG_MIN % -10 * -1 <= next - '0'))
			return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	ret;
	int		sign;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
		{
			if (overflowl(sign, ret, *str) == 1)
				return ((int)LONG_MAX);
			if (overflowl(sign, ret, *str) == -1)
				return ((int)LONG_MIN);
			ret = ret * 10 + (long)(*str - '0');
			str++;
		}
		else
			break ;
	}
	return ((int)(ret * sign));
}

