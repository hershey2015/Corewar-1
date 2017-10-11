/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"
//	CARRY GOOD!!!!!!!!!!!!!!!!!!!!!!!
static void		execute_ld_cmd(t_map *all_info, t_ps *ps);

//	проверки на валидность нет и пропус команды
void			ld(t_map *all_info, t_player *player, t_ps *ps)
{
	int			i;
	int			pc;

	if (ps->cycles_to_cmd < g_tab[1].cycle)
	{
		ps->cycles_to_cmd++;
		return ;
	}
	
	printf("%sLD HAS BEEN USED BY:%s\n", GREEN, RESET);
	// printf("%splayer:\t\t\t%d%s\n", GREEN, ps->player, RESET);
	// printf("%sps->cycles_to_cmd:\t%d%s\n", GREEN, ps->cycles_to_cmd, RESET);
	// print_process(ps);

	pc = fill_commands(all_info, ps);
	// IDX_MOD check
	execute_ld_cmd(all_info, ps);
	ps->pc = pc;

	// print_process(ps);
	null_commands_variables(ps);
}

static void		execute_ld_cmd(t_map *all_info, t_ps *ps)
{
	int			pc;
	int			distance;
	int			first_arg;

	//	проверка на валидный регистр(если регистр выходит за пределы,
	//	функция ждет свои циклы, но не исполняется)
	if (ps->arg[SECOND_ARG] < 1
		|| ps->arg[SECOND_ARG] > 16)
		return ;
	//	проверка тип(T_DIR T_IND) первого аргумента и взятие значения
	if (ps->arg_types[FIRST_ARG] == DIR_CODE)
		first_arg = ps->arg[FIRST_ARG];
	else
	{
		pc = ps->pc;
		distance = ps->arg[FIRST_ARG] % IDX_MOD;
		move_map_counter(&pc, distance);
		first_arg = get_value_from_map(all_info, &pc, 4);
	}
	if (first_arg == 0)
		ps->carry = 1;
	else
		ps->carry = 0;
	ps->reg[ps->arg[1] - 1] = first_arg;
}
