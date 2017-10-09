/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		execute_live_cmd(t_map *all_info, t_player *player, t_ps *ps,
	int value);
//	проверки на валидность нет и пропус команды
void			live(t_map *all_info, t_player *player, t_ps *ps)
{
	int			i;
	int			pc;

	if (ps->cycles_to_cmd < g_tab[0].cycle)
	{
		ps->cycles_to_cmd++;
		return ;
	}

	printf("%sLIVE HAS BEEN USED BY:%s\n", GREEN, RESET);
	// printf("%splayer:\t\t\t%d%s\n", GREEN, ps->player, RESET);
	// printf("%sps->cycles_to_cmd:\t%d%s\n", GREEN, ps->cycles_to_cmd, RESET);
	// print_process(ps);

	pc = fill_commands(all_info, ps);
	execute_live_cmd(all_info, player, ps, ps->arg[0]);
	ps->pc = pc;

	// print_process(ps);
	null_commands_variables(ps);
}

static void		execute_live_cmd(t_map *all_info, t_player *player, t_ps *ps,
	int value)
{
	t_player	*copy_players;

	ps->check_live = 1;
	copy_players = player;
	while (copy_players)
	{
		if (value == copy_players->player_num)
		{
			copy_players->total_lives++;
			copy_players->last_live = all_info->cycle;
			return ;
		}
		copy_players = copy_players->next;
	}
}
