/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:32:44 by lannur-s          #+#    #+#             */
/*   Updated: 2024/02/18 18:25:14 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_skip_zeros(char *str, int len, int i)
{
	while (str[i] == '0' && str[i + 1] != '\0')
	{
		ft_memcpy(&str[i], &str[i + 1], ft_strlen(&str[i + 1]));
		str[len - 1] = 0;
		len--;
	}
	return (str);
}

int	ft_is_int(char *str)
{
	int	i;
	int	len;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[++i] == '\0')
			return (0);
	len = ft_strlen(str);
	str = ft_skip_zeros(str, len, i);
	len = ft_strlen(str);
	while (str[i])
		if (ft_isdigit(str[i++]) == 0)
			return (0);
	if (len < 10)
		return (1);
	if (len > 11)
		return (0);
	if (len == 10)
		if (ft_strcmp("2147483647", str) < 0)
			return (0);
	if (len == 11)
		if ((ft_strcmp("-2147483648", str) < 0)
			|| (str[0] == '+' && ft_strcmp("+2147483647", str) < 0))
			return (0);
	return (1);
}
