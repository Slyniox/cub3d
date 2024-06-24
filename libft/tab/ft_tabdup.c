/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:17:33 by soelalou          #+#    #+#             */
/*   Updated: 2024/02/08 11:29:39 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_tabdup(char **tab)
{
	int		i;
	char	**ret;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
		i++;
	ret = (char **)malloc(sizeof(char *) * (i + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		ret[i] = ft_strdup(tab[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
