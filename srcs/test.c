/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:17:56 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/27 18:41:14 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int main(int ac, char **av)
{
	int i;
	int	j;
	char	**tab;

	i = 0;
	tab = ft_strsplit(av[1], ' ');
	printf("tab[0] = %s\ntab[1] = %s\n", tab[0], tab[1]);

	while (tab[i] != '\0')
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	printf("%s", tab[4]);
}