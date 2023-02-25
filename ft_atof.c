/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:08:59 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/25 01:15:26 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_()
{
	// write(2, "Error \n", 7);
	exit(EXIT_FAILURE);
}

void	atoi_check(const char *str, int *i, int *s)
{
	while (str[*i] == ' ' || str[*i] == '\n' || str[*i] == '\t'
		|| str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			(*s) = (*s) * (-1);
		(*i)++;
	}
}

int	ft_atoi(const char *str)
{
	long	r;
	int		i;
	int		s;
	int		count;

	i = 0;
	r = 0;
	count = 0;
	s = 1;
	atoi_check(str, &i, &s);
	while (str[i] <= '9' && str[i] >= '0')
	{
		r = r * 10 + (str[i] - '0');
		count++;
		if (count > 10 && r != 0)
			error_();
		i++;
	}
	if (str[i] != ' ' && str[i] != '\0' && str[i] != '.')
		error_();
	if ((r * s) < -2147483648 || (r * s) > 2147483647)
		error_();
	return (r * s);
}
double	ft_atof(const char *str)
{
	double	res;
	double	res2;
	char	*c;
	int		len;

	c = (char *)str;
	res = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	res2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		res2 /= 10;
	if (res >= 0)
		return (res + res2);
	else
		return (res + -res2);
}