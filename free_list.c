/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:19:16 by abelarif          #+#    #+#             */
/*   Updated: 2021/02/18 16:42:17 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		free_list(t_mem *list)
{
	if (list == NULL)
		return ;
	free_list(list->next);
	if (list->mem != NULL)
	{
		free(list->mem);
		list->mem = NULL;
	}
	free(list);
	list = NULL;
}

void		list_push_back(t_mem **list, void *ptr)
{
	if ((*list))
		list_push_back(&(*list)->next, ptr);
	else
	{
		(*list) = (t_mem*)malloc(sizeof(t_mem));
		(*list)->mem = ptr;
		(*list)->next = NULL;
	}
}

void		*my_malloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	list_push_back(&g_memory, ptr);
	return (ptr);
}
