/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:32:29 by msukri            #+#    #+#             */
/*   Updated: 2022/07/05 12:36:37 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	ft_vector(int x, int y)
{
	t_vec	position;
	
	position.x = x;
	position.y = y;
	return (position);
}
