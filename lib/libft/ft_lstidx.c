/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstidx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 00:03:51 by ciglesia          #+#    #+#             */
/*   Updated: 2020/11/18 00:08:25 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstidx(t_list *head, int idx)
{
	int	i;
	if (idx < 0 || idx >= ft_lstlen(head))
		return (NULL);
	i = 0;
	while (head && idx != i)
	{
		i++;
		head = head->next;
	}
	return (head);
}
