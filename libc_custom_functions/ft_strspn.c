/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:54:13 by alambert          #+#    #+#             */
/*   Updated: 2022/01/21 18:54:16 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int ft_strspn(const char *str, const char *set)
{
    const char  *p;
    const char  *s;

    p = str;
    while (*p)
    {
        s = set;
        s = ft_strchr(s, *p);
        if (s == 0)
            break;
        else
            p++;
    }
    return (p - str);
}
