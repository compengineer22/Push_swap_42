/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:41:07 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/17 17:47:20 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *s)
{
	t_stack	*tmp;
	t_stack	*cur;

	cur = s;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
}
