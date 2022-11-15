/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:47:08 by okoponen          #+#    #+#             */
/*   Updated: 2019/10/29 18:39:30 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	ft_check_forbidden_characters(char str)
{
	if ((str == ' ') || (str == '\t') || (str == '\n') ||
		(str == '\v') || (str == '\r') || (str == '\f'))
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	int i;
	int sign;
	int res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_check_forbidden_characters(str[i]) == 1)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (res * sign);
		else
		{
			res = res * 10 + str[i] - '0';
			i++;
		}
	}
	return (sign * res);
}
