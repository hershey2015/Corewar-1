/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleksii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:01:24 by coleksii          #+#    #+#             */
/*   Updated: 2017/09/12 16:02:06 by coleksii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/create.h"

int main()
{
	t_header	*header;
	t_label		*label1;
	t_function	*function1;

	header = (t_header *)malloc(sizeof(t_header));
	header->magic = 0xea83f3;
	header->prog_comment = "some comment";
	header->prog_name = "some prog namea";
	header->prog_size = 7;
	header->error = 0;
	header->file_name = "some_file.cor";

	label1 = (t_label *)malloc(sizeof(t_label));
	header->labels = label1;
	label1->label_size = 12;
	label1->label_name = "some label";
	label1->next = NULL;
	label1->prev = NULL;

	function1 = (t_function *)malloc(sizeof(t_function));
	label1->functions = function1;
	function1->name = "live";
	function1->func_in_hex = 0x01;

	ft_printf("%s", "hello main\n");

	create_file(header);
	return (0);
}
