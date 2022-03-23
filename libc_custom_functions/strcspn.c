/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcspn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:53:48 by alambert          #+#    #+#             */
/*   Updated: 2022/01/21 18:53:52 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcspn(const char *str, const char *set)
{
    const char *p;
    const char *s;
    
    p = str;
    while (*p)
    {
        s = set;
        s = ft_strchr(s, *p);
        if (s != 0)
            break;
        else
            p++;
    }
    return (p - str);
}
