/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowercase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:40:48 by ciglesia          #+#    #+#             */
/*   Updated: 2020/11/13 14:51:01 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lowercase(char *str)
{
	char	*lower;
	int		i;

	lower = ft_strnew(ft_strlen(str));
	i = 0;
	while (str[i])
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			lower[i] = (str[i] + 32);
		else
			lower[i] = str[i];
		i++;
	}
	return (lower);
}
