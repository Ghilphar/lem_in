/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:21:43 by fgaribot          #+#    #+#             */
/*   Updated: 2020/01/12 22:36:39 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	add_number_ants(char *line, t_data *data)
{
	if (ft_isanint(line))
		data->ants = ft_atoi(line);
	if (data->ants == 0)
	{
		// FREE (pas de fourmis)
		exit(EXIT_FAILURE);
	}
	else
	{
		//FREE CE QU'IL Y A A FREE
		exit(EXIT_FAILURE);
	}	
}

int		detect_orders(char *line, t_data *data)
{
	int order;

	data->order = 0;
	if (ft_strcmp(line, "##start\n") == 0)
		data->order = 1;
	else if (ft_strcmp(line, "##end\n") == 0)
		data->order = 2;
	return (data->order);
}

void	initialise(t_data *data)
{
	if(!(data = malloc(sizeof(data))))
		return (0);
	data->ants = 0;
	data->form = 0;
	data->order = 0;
	data->start_map = NULL;
	data->end_map = NULL;
}

void	add_start_map(char *line, t_data *data)
{
	t_maps	*new_start;
	char	*tab;

	if (data->start_map != NULL)
		//exit(EXIT_FAILURE); // fonction sorted'erreur
	(!(new_start = malloc(sizeof(new_start))))
		//return (Malloc fail sortie en free tout);
	ft_strsplit(line, ' ');
	new_start->map_name = tab[0];
	new_start->map_x = ft_atoi(tab[1]);
	new_start->map_y = ft_atoi(tab[2]);
}

void	add_end_map(char *line, t_data *data)
{
	t_maps	*new_start;
	char	*tab;

	if (data->start_map != NULL)
		exit(ERROR); // fonction sortie d'erreur
	(!(new_start = malloc(sizeof(new_start))))
		return (FONCTION SORTIE ERREUR);
	ft_strsplit(line, ' ');
	new_start->map_name = tab[0];
	new_start->map_x = ft_atoi(tab[1]);
	new_start->map_y = ft_atoi(tab[2]);
}

void	add_order(char *line, t_data *data)
{
	if (room_or_pipe(line, data) == 1)//correct_map_form(line);
	if (data->order == 1)
		add_start_map(line, data);
	else if (data->order == 2)
		add_end_map(line, data);
	data->order = 0;
}

void	hash_function(char *line, t_data *line)
{
	
}

void	add_room(char *line, t_data *data)
{
}

int 	room_or_pipe(char *line, t_data *data)
{

}

void parsing(t_data *data)
{
	char	**line;

	if (!(line = malloc(sizeof(line))))
		return (NULL);
	while (get_next_line(0, line) == 1)
	{
		if (data->ants == 0)
		{
			add_number_ants(*line, data);
			continue;
		}
		else if (data->order == 1 || data->order == 2)
			add_order(*line, data);
		else if (detect_orders(*line, data) >= 1) // || si premier caracthere de line est un #;
			continue;
		else
			data->form = room_or_pipe(*line, data); // (1 room | 2 pipe)
			//data->form = check_form(*line, data);
	}
}

int		is_a_room(char *line)
{
	char	**room;
	int		i;

	i = 0;
	room = ft_strsplit(line, ' ');
	while (i < 4 || room[i] != '\0')
		i++;
	if (!(ft_isanint(room[1]) && ft_isanint(room[2])))
		// Probleme de coordonnees| exit(EXIT_FAILURE)
}

int main(int ac, char **av)
{
	t_data	*data;

	initialise(data);
	parsing(data);
}
