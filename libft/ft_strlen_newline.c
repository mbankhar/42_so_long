/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_newline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 12:42:26 by mbankhar          #+#    #+#             */
/*   Updated: 2024/05/12 12:46:28 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_newline(const char *c)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (c[i] != '\0')
	{
		if (c[i] == '\n')
			y--;
		y++;
		i++;
	}
	return (y);
}
