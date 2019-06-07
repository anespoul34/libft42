/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 15:20:33 by anespoul          #+#    #+#             */
/*   Updated: 2015/12/23 15:22:23 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_size_list(t_list *begin_list)
{
	int i;

	i = 0;
	if (begin_list == NULL)
		return (0);
	while (begin_list->next)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}
