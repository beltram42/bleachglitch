/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:09:50 by alambert          #+#    #+#             */
/*   Updated: 2022/05/08 20:05:46 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

typedef enum e_var
{
	SIGN,
	BASE,
	DGT,
	ANY,
	RES,
	CUT,
	MOD,
    MOVE,
	ENUM_MAX
}					t_var;

static long ft_basecheck(const char *s, long base, long val[8])
{
    long c;
    
    c = val[DGT];
    if (((base == 0 || base == 2) && c == 48 && (*s == 'b'|| *s == 'B'))
        || ((base == 0 || base == 16) && c == 48 && (*s == 'x' || *s == 'X')))
    {
        if ((base == 0 || base == 2) && c == 48 && (*s == 'b'|| *s == 'B'))
            base = 2;
        else
            base = 16;
    }
    else if (base == 0)
    {
        base = 10;
        if (c == 48)
            base = 8;
    }
    return (base);
}

static long *ft_cvbase(const char *s, long val[8])
{
    while (*s++)
    {
        val[MOVE] += 1;
        if (ft_isdigit(val[DGT]) || ft_isalpha(val[DGT]))
        {
            if (ft_islower(val[DGT]))
                val[DGT] -= 'a' - 10;
            else if (ft_isupper(val[DGT]))
                val[DGT] -= 'A' - 10;
            else
                val[DGT] -= '0';
        }
        else
            break;
        if (val[DGT] >= val[BASE])
            break;
        if (val[ANY] < 0 || ((unsigned long)val[RES] > (unsigned long)val[CUT]) || (val[RES] == val[CUT] && val[DGT] > val[MOD]))
            val[ANY] = -1;
        else
        {
            val[ANY] = 1;
            val[RES] = (val[RES] * val[BASE]) + val[DGT];
        }
        val[DGT] = *s;
    }
    return (val);
}

static long ft_ltobase(const char *s, long val[8])
{
    val[MOVE] = 0;
    val[ANY] = 0;
    val[RES] = 0;
    if (val[SIGN] == -1)
        val[CUT] = -(unsigned long)LONG_MIN;
    if (val[BASE] == 2 || val[BASE] == 16)
    {
        s += 2;
        val[MOVE] = 2;
    }
    if (val[BASE] == 8)
    {
        s += 1;
        val[MOVE] = 1;
    }
    val[DGT] = *s;
    val = ft_cvbase(s, val);
    if (val[ANY] < 0)
    {
        val[RES] = LONG_MAX;
        if (val[SIGN] == -1)
            val[RES] = LONG_MIN;
    }
    else if (val[SIGN] == -1)
        val[RES] *= val[SIGN];
    return (val[RES]);
}

long ft_strtol(const char *str, char **endptr, int base)
{
    const char *s;
    long val[8];

    s = str;
    val[SIGN] = 1;
    while (*s == '\t' || *s == '\n' || *s == '\v' || *s == '\f' || *s == '\r' || *s == ' ')
        s++;
    val[DGT] = *s++;
    if (!(isdigit((int)val[DGT]) || isalpha((int)val[DGT]) || val[DGT] == '-' || val[DGT] == '+'))
        return (0);
    if (val[DGT] == '-' || val[DGT] == '+')
    {
        if (val[DGT] == '-')
            val[SIGN] = -1;
        val[DGT] = *s++;
    }
    val[BASE] = ft_basecheck(s, base, val);
    val[CUT] = LONG_MAX;
    val[MOD] = val[CUT] % (unsigned long)val[BASE];
    s--;
    val[RES] = ft_ltobase(s, val);
    if ((endptr != 0) && val[ANY] != 0)
        *endptr = (char*)(s + val[MOVE] - 1);
    return ((long)val[RES]);
}
