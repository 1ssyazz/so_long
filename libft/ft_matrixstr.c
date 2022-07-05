/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:17:32 by msukri            #+#    #+#             */
/*   Updated: 2022/06/30 16:19:02 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_matrixstr(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	char	*s3;

	if (s2 == NULL)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = (char *)malloc(s1_len + s2_len + 1);
	if (s3 == NULL)
		return (NULL);
	while (i < s1_len || i < s2_len)
	{
		if (i < s1_len)
			s3[i] = s1[i];
		if (i < s2_len)
			s3[i + s1_len] = s2[i];
		i++;
	}
	s3[s1_len + s2_len] = '\0';
	free(s1);
	return (s3);
}
