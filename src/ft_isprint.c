/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:09:35 by agautier          #+#    #+#             */
/*   Updated: 2020/11/11 13:56:24 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	man isprint
*/

int	ft_isprint(int c)
{
	if (c < ' ' || c > '~')
		return (0);
	return (1);
}
