/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 23:42:39 by ciglesia          #+#    #+#             */
/*   Updated: 2020/11/18 00:18:04 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **list)
{
	void	*tmp;
	size_t	tmp_size;
	int		size;
	int		i;

	if (!*list || !(*list)->next)
		return ;
	i = 0;
	size = ft_lstlen(*list);
	while (size && i < (int)(size / 2))
	{
		tmp = ft_lstidx(*list, i)->obj;
		tmp_size = ft_lstidx(*list, i)->dim;
		ft_lstidx(*list, i)->obj = ft_lstidx(*list, size - 1 - i)->obj;
		ft_lstidx(*list, i)->dim = ft_lstidx(*list, size - 1 - i)->dim;
		ft_lstidx(*list, size - 1 - i)->obj = tmp;
		ft_lstidx(*list, size - 1 - i)->dim = tmp_size;
		i++;
	}
}
