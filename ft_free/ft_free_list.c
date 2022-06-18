/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:39:02 by hjrifi            #+#    #+#             */
/*   Updated: 2022/06/18 22:39:05 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../shell.h"
#include "../header/minishell.h"

void	ft_free_list(t_list *lst)
{
	int i;

	while (lst)
    {
        i = 0;
        while (lst->val[i])
            free(lst->val[i++]);
        free(lst->val);
        free(lst->v_type);
        if (lst->prev)
            free(lst->prev);
        if (!lst->next)
        free(lst);
            lst = lst->next;
    }
}
