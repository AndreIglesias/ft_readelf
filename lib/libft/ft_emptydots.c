/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_emptydots.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:19:04 by ciglesia          #+#    #+#             */
/*   Updated: 2020/11/20 12:04:06 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_emptydots(char *str)
{
	char	*new;
	size_t	dots;
	int		i;
	int		j;

	dots = ft_countchr(str, '.');
	if (dots == ft_strlen(str))
		return (ft_strdup(str));
	new = ft_strnew(ft_strlen(str) - dots);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '.')
			new[j++] = str[i];
		i++;
	}
	new[j] = '\0';
	free(str);
	return (new);
}
