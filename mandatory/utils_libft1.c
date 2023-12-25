/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:58:48 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/23 16:12:15 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strdup(char	*s1)
{
	int		len;
	int		i;
	char	*ptr;

	len = ft_strlen(s1);
	i = 0;
	ptr = (char *) malloc(sizeof(*ptr) * (len + 1));
	if (!ptr)
		return (NULL);
	if (ptr)
	{
		while (s1[i])
		{
			ptr[i] = s1[i];
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*s3;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(len1 + len2 + 1);
	if (!s3)
		return (NULL);
	i = 0;
	while (i < len1 + len2)
	{
		if (i < len1)
			s3[i] = s1[i];
		else
			s3[i] = s2[i - len1];
		i++;
	}
	s3[len1 + len2] = '\0';
	free(s1);
	return (s3);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	while (*s != (char )c)
	{
		if (*s == '\0')
		{
			return (NULL);
		}
		s++;
	}
	return ((char *)s);
}

int	ft_atoi(const char	*str)
{
	unsigned long long	r;
	unsigned long long	max;
	int					sign;
	int					i;

	i = 0;
	sign = 1;
	r = 0;
	max = 9223372036854775807;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		r = (r * 10) + str[i++] - '0';
	if (sign == 1 && r > max)
		return (-1);
	if (sign == -1 && r > max)
		return (0);
	return ((int)r * sign);
}
