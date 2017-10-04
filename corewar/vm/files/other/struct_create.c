/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

t_cmd			*create_cmd(int args)
{
	t_cmd		*cmd;
	int			i;

	i = 0;
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->cmd_name = NULL;
	cmd->cmd_size = 0;
	cmd->cmd_in_hex = 0;
	cmd->codage_byte = 0;
	cmd->arg_types = (char *)malloc(sizeof(char) * args);
	cmd->arg = (int *)malloc(sizeof(int) * args);
	cmd->next = NULL;
	return (cmd);
}

t_info			*create_info(void)
{
	t_info		*info;

	info = malloc(sizeof(t_info));
	info->file_name = NULL;
	info->magic = 0;
	info->prog_name = NULL;
	info->prog_size = 0;
	info->prog_comment = NULL;
	info->player_num = 0;
	info->read = NULL;
	info->commands = NULL;
	info->next = NULL;
	return (info);
}

t_map			*create_map(void)
{
	t_map		*map;

	map = (t_map *)malloc(sizeof(t_map));
	ft_bzero(map->map, MEM_SIZE + 1);
	map->cycle = 0;
	map->cycle_to_die = CYCLE_TO_DIE;
	map->cycle_delta = CYCLE_DELTA;
	map->processes = 0;
	map->players = NULL;
	map->ps = NULL;
	return (map);
}

t_player		*create_player(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	player->name = NULL;
	player->player_num = 0;
	player->lives = 0;
	player->last_live = 0;
	return (player);
}
