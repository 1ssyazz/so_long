/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:09:50 by msukri            #+#    #+#             */
/*   Updated: 2022/06/30 12:36:11 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_dup_matrix(char **m)
{
	char	**ret;
	int		rows;
	int		i;

	i = 0;
	rows = ft_matrixlen(m);
	ret = malloc(sizeof(char *) * (rows + 1));
	if (!ret)
		return (NULL);
	while (m[i])
	{
		ret[i] = ft_strdup(m[i]);
		if (!ret[i])
		{
			ft_free_matrix(&ret);
			return (NULL);
		}
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
