/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:08:59 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/27 04:42:45 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
			ft_error();
		i++;
	}
	if (str[i] != ' ' && str[i] != '\0' && str[i] != '.')
		ft_error();
	if ((r * s) < -2147483648 || (r * s) > 2147483647)
		ft_error();
	return (r * s);
}

int	sign(char *c)
{
	int	s;

	s = 1;
	if (*c == '+' || *c == '-')
	{
		if (*c == '-')
			s = s * (-1);
	}
	return (s);
}

double	ft_atof(const char *str)
{
	double	res;
	double	res2;
	char	*c;
	int		len;
	int		s;

	c = (char *)str;
	s = 1;
	res = (double)ft_atoi(c);
	printf("res : %f\n", res);
	s = sign(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	res2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		res2 /= 10;
	if (res >= 0)
		return ((res + res2) * s);
	else
		return ((res + -res2));
}
