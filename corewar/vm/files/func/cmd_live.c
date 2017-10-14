/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_live.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		execute_live_cmd(t_map *all_info, t_ps *ps);

void			cmd_live(t_map *all_info, t_ps *ps)
{
	int			pc;

	if (ps->cycles_to_cmd < g_tab[0].cycle)
	{
		ps->cycles_to_cmd++;
		return ;
	}

	printf("%sLIVE HAS BEEN USED BY:%s\n", GREEN, RESET);
	// printf("%sps->cycles_to_cmd:\t%d%s\n", GREEN, ps->cycles_to_cmd, RESET);
	// print_process(ps);

	pc = fill_commands(all_info, ps);
	execute_live_cmd(all_info, ps);
	ps->pc = pc;

	// print_process(ps);
	null_commands_variables(ps);
}

static void		execute_live_cmd(t_map *all_info, t_ps *ps)
{
	t_player	*copy_players;

	ps->check_live = 1;
	copy_players = all_info->players;
	while (copy_players)
	{
		if (ps->arg[0] == copy_players->player_num)
		{
			copy_players->total_lives++;
			copy_players->last_live = all_info->cycle;
			return ;
		}
		copy_players = copy_players->next;
	}
}