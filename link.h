/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:30:05 by abelarif          #+#    #+#             */
/*   Updated: 2021/02/18 16:44:43 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINK_H
# define LINK_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_list	t_list;

struct					s_list
{
	char				*str;
	t_list				*next;
};

t_list					*insertion(t_list *list, char *str);

#endif
