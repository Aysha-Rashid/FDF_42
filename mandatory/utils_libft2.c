/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:59:59 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/23 16:12:19 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_strncmp(const char	*s1, const char	*s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if ((unsigned char)s1[i] != (unsigned char) s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		else if ((unsigned char)s1[i] < (unsigned char)s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

void	*ft_memset(void	*b, int c, size_t	len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (len > i)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	nb;
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	nb = 0;
	while ((str[i] >= '0' && str[i] <= '9' && str_base <= 16)
		|| (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F'))
	{
		nb = nb * str_base;
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb + str[i] - '0';
		if (str[i] >= 'a' && str[i] <= 'f')
			nb = nb + str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			nb = nb + str[i] - 'A' + 10;
		i++;
	}
	if (str[i] > 'f' && str[i] > 'F')
		exit(0);
	return (nb * sign);
}
