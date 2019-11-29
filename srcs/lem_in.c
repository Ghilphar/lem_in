/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:21:43 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/27 18:41:15 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	add_number_ants(char *line, t_data *data)
{
	if (ft_isanint(line))
		ft_atoi(line);
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
	data->start_map = NULL;
	data->end_map = NULL;
}

void	add_start_map(char *line, t_data *data)
{
	t_maps	*new_start;
	char	*tab;

	if (data->start_map != NULL)
		exit(ERROR); // fonction sorted'erreur
	(!(new_start = malloc(sizeof(new_start))))
		return (FONCTION SORTIE ERREUR);
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
	correct_map_form(line);
	if (data->order == 1)
		add_start_map(line, data);
	else if (data->order == 2)
		add_end_map(line, data);
	data->order = 0;
}

void	hash_function(char *line, t_data *line)
{
	
}

int		check_form(char *line, t_data *data)
{
	char	**tab;

	if (!line)
		// fonction exit error;
	tab = ft_strsplit(line, ' ');
	if (tab[0] == NULL || tab[1] == NULL || tab[2] == NULL || tab[3] != NULL)
		EXIT ERROR;
	else if (ft_isanint(tab[1]) != 1 || ft_isanint(tab[2]) != 1)
		EXIT ERROR;
	else
		hash_function(tab[0], data);
}

void	add_map(char *line, t_data *data)
{
}

void	add_correct_form(char *line, t_data *data)
{
	if ()
		add_map();
	else if ()
		add_pipe();
	else
	{
		//Error;
	}
	
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
			data->form = check_form(*line, data);
		add_correct_form(*line, data);
	}
}


int main(int ac, char **av)
{
	t_data	*data;

	initialise(data);
	parsing(data);
}
