/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:20:41 by ciglesia          #+#    #+#             */
/*   Updated: 2020/11/21 23:37:48 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstswap(t_list **list, size_t a, size_t b)
{
	t_list	*tmp;

	tmp = list[a];
	list[a] = list[b];
	list[b] = tmp;
}

static int	partitioning(t_list **list, int low, int high, int f(t_list *, t_list *))
{
	t_list	*pivot;
	int		i;
	int		j;

	pivot = list[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (f(list[j], pivot))
		{
			ft_lstswap(list, i, j);
			i++;
		}
		j++;
	}
	ft_lstswap(list, i, high);
	return (i);
}

static void	quick(t_list **list, int low, int high, int f(t_list *, t_list *))
{
	int	part;

	if (low < high)
	{
		part = partitioning(list, low, high, f);
		quick(list, low, part - 1, f);
		quick(list, part + 1, high, f);
	}
}

void		ft_quicksort(t_list **list, size_t size, int f(t_list *, t_list *))
{
	quick(list, 0, size - 1, f);
}
