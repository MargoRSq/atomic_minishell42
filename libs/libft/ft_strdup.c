/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:17:33 by avoltorb          #+#    #+#             */
/*   Updated: 2022/09/21 19:36:00 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*memory;
	char	*start;

	memory = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!memory)
		return (NULL);
	start = memory;
	while (*s1)
	{
		*memory = *s1;
		memory++;
		s1++;
	}
	*memory = '\0';
	return (start);
}
