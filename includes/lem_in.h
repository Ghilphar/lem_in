/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:33:56 by fgaribot          #+#    #+#             */
/*   Updated: 2020/01/12 22:29:38 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/*
** LIBRAIRIES
*/

# include "../srcs/libft/libft.h"

/*
** STRUCTURES
*/

typedef struct	s_links
{
	char		*map_linked;
	int			flux;
	int			hash_link;
	t_links		*next_link;
}				t_links;

typedef struct	s_maps
{
	char		*map_name;
	int			hash;
	int			map_x;
	int			map_y;
	t_links		*links;
	t_maps		*next;
}				t_maps;

typedef struct	s_data
{
	t_maps		*start_map;
	t_maps		*end_map;
	int			ants;
	int			form;
	int			order;
}				t_data;

#endif
