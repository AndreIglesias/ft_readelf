/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:54:58 by ciglesia          #+#    #+#             */
/*   Updated: 2020/11/20 19:55:21 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sorting(t_list *list, void f(t_list *))
{
	t_list	*iter;
	t_list	*aux;

	iter = list;
	while (iter && iter->next)
	{
		aux = list;
		while (aux && aux->next)
		{
			f(aux);
			aux = aux->next;
		}
		iter = iter->next;
	}
}
