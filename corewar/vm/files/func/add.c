/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"
//	CARRY GOOD!!!!!!!!!!!!!!!!!!!!!!!
static void		execute_add_cmd(t_map *all_info, t_ps *ps);

//	проверки на валидность нет и пропус команды CARRY НЕ МЕНЯЕТ
void			add(t_map *all_info, t_player *player, t_ps *ps)
{
	int			i;
	int			pc;

	if (ps->cycles_to_cmd < g_tab[3].cycle)
	{
		ps->cycles_to_cmd++;
		return ;
	}
	
	printf("%sADD HAS BEEN USED BY:%s\n", GREEN, RESET);
	// printf("%splayer:\t\t\t%d%s\n", GREEN, ps->player, RESET);
	// printf("%sps->cycles_to_cmd:\t%d%s\n", GREEN, ps->cycles_to_cmd, RESET);
	// print_process(ps);

	pc = fill_commands(all_info, ps);
	execute_add_cmd(all_info, ps);
	ps->pc = pc;

	// print_process(ps);
	null_commands_variables(ps);
}

static void		execute_add_cmd(t_map *all_info, t_ps *ps)
{
	int			first_arg;
	int			second_arg;

	//	проверка на валидность регистра
	if (ps->arg[FIRST_ARG] < 1
		|| ps->arg[FIRST_ARG] > 16)
		return ;
	if (ps->arg[SECOND_ARG] < 1
		|| ps->arg[SECOND_ARG] > 16)
		return ;
	if (ps->arg[THIRD_ARG] < 1
		|| ps->arg[THIRD_ARG] > 16)
		return ;
	//	запись аргументов
	first_arg = ps->reg[ps->arg[FIRST_ARG] - 1];
	second_arg = ps->reg[ps->arg[SECOND_ARG] - 1];
	if (!first_arg && !second_arg)
		ps->carry = 1;
	else
		ps->carry = 0;
	ps->reg[ps->arg[THIRD_ARG] - 1] = first_arg + second_arg;
}

