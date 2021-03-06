/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:27:51 by agautier          #+#    #+#             */
/*   Updated: 2021/02/01 20:25:36 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Free un pointeur et le met a NULL.
*/

int	ft_free(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (0);
}
