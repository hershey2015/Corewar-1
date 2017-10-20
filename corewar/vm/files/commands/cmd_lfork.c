/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lfork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		print_flags_lfork(t_map *map, t_ps *ps, t_ps *ps_new, int pc)
{
	if (check_flags(map->flags, 'v', 4))
	{
		ft_printf("P    %-d | %s", ps->ps_num, "lfork");
		ft_printf(" %d (%d)\n", ps->arg[FIRST_ARG], pc);
	}
	if (map->flags->java_flag)
		ft_printf(";%d:%d:%d", ps_new->player_num, ps_new->pc, 1);
}

static void		execute_lfork(t_map *map, t_ps *ps)
{
	t_ps		*ps_new;
	int			distance;
	int			pc;

	ps_new = create_ps(0, 0, map->ps_counter++);
	ps_new->next = map->ps;
	map->ps = ps_new;
	copy_process(ps, ps_new);
	pc = ps->pc;
	distance = ps->arg[FIRST_ARG];
	move_map_counter(&pc, distance);
	ps_new->pc = pc;
	if (map->map[ps_new->pc] >= 1 && map->map[ps_new->pc] <= 16)
	{
		ps_new->cmd_in_hex = map->map[ps_new->pc];
		ps_new->cycles_to_cmd = g_tab[ps_new->cmd_in_hex - 1].cycle - 1;
	}
	map->processes++;
	print_flags_lfork(map, ps, ps_new, pc);
}

void			cmd_lfork(t_map *map, t_ps *ps)
{
	int			pc;
	int			temp_pc;

	temp_pc = ps->pc;
	pc = fill_commands(map, ps);
	if (ps->skip_cmd == 0)
		execute_lfork(map, ps);
	if (check_flags(map->flags, 'v', 16))
	{
		if (ps->pc == 0)
			ft_printf("ADV %d (0x0000 -> %#06x) ", pc - ps->pc, pc);
		else
			ft_printf("ADV %d (%#06x -> %#06x) ", pc - ps->pc, ps->pc, pc);
		while (temp_pc != pc)
		{
			ft_printf("%02x ", map->map[temp_pc] & 255);
			move_map_counter(&temp_pc, 1);
		}
		ft_printf("\n");
	}
	ps->pc = pc;
	null_commands_variables(ps);
}