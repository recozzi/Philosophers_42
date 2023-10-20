/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <recozzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:33:06 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/19 11:34:38 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_strerror(char *str, int err)
{
	printf("%s\n", str);
	return (err);
}

int	ft_atoi(const char *nptr)
{
	char	*ptr;
	int		sign;
	int		res;

	ptr = (char *)nptr;
	sign = 1;
	res = 0;
	while (*ptr == 32 || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign *= -1;
		ptr++;
	}
	while (*ptr >= 48 && *ptr <= 57)
	{
		res = (res * 10) + (*ptr - 48);
		ptr++;
	}
	return (res * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (0);
	memset(ptr, 0, nmemb * size);
	return (ptr);
}
