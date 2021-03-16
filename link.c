/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:31:53 by abelarif          #+#    #+#             */
/*   Updated: 2021/02/18 16:17:18 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"
#include "cub3d.h"

t_list		*insertion(t_list *list, char *str)
{
	t_list	*tmp;

	tmp = my_malloc(sizeof(t_list));
	tmp->str = str;
	tmp->next = list;
	return (tmp);
}
