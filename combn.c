/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:42:44 by nhanafi           #+#    #+#             */
/*   Updated: 2022/06/21 20:42:45 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void    write_f(int nb, char *num)
{
    write(1, num, nb);
    if (num[nb - 1] != '9' || num[0] != '9' - nb + 1)
        write(1, ", ", 2);
    num[nb - 1]++;
}

void    make_nbr_list(int nb, char *num, int i)
{
    while (num[0] <= '9' - nb)
    {
        i = nb - 1;
        while (i > 0)
        {
            if (num[i] != num[i - 1] + 1)
            {
                num[i - 1] = num[i - 1] + 1;
                while (nb > i++)
                    num[i - 1] = num[i - 2] + 1;
                break ;
            }
            i--;
        }
        while (num[nb - 1] <= '9')
        {
            write_f(nb, num);
        }
        num[nb - 1]--;
    }
}

void    ft_print_combn(int nb)
{
    char    num[9];
    int        i;

    i = 0;
    if (nb > 0 && nb < 10)
    {
        while (i < nb)
        {
            num[i] = i + '0';
            i++;
        }
        make_nbr_list(nb, num, i);
    }
}