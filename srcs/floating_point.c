/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floating_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:39:57 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/21 17:28:08 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <stdlib.h>
#include "ft_bigfloat.h"
#include "ft_printf.h"
#include "ft_types.h"
#include "libft.h"

void					print_double_binary(long double d)
{
	int					i;
	int					exp_ln;
	int					man_ln;
	int					exponent_max;
	t_float_conv		conv;

	exp_ln = 0;
	ft_bzero(&conv, sizeof(conv));
	conv.value = d;
	man_ln = LDBL_MANT_DIG - (sizeof(d) == sizeof(double));
	exponent_max = LDBL_MAX_EXP;
	while (exponent_max != 0 && (++exp_ln || 1))
		exponent_max /= 2;
	printf("d            = %Lf\n", (long double)d);
	printf("sizeof(d)    = %lu\n", sizeof(d));
	printf("bits in d    = %lu\n\n", sizeof(d) * 8);
	printf("FLT_RADIX    = %d\n", FLT_RADIX);
	printf("DBL_MAX_EXP  = %d\n", LDBL_MAX_EXP);
	printf("DBL_MANT_DIG = %d\n", LDBL_MANT_DIG);
	printf("exponent len = %d\n", exp_ln);
	printf("total used   = %d\n", exp_ln + man_ln + 1);
	exponent_max = sizeof(d) * 8;
	printf("requiered bits : %d\n", exponent_max);
	exponent_max -= (exp_ln + man_ln + 1);
	i = 0;
	while (i < (int)sizeof(d) && !conv.bytes[sizeof(d) - (i + 1)])
		i++;
	while (++i <= (int)sizeof(d))
		ft_printf("%.8b ", conv.bytes[sizeof(d) - i]);
	ft_printf("\n");
	printf("\n");
	printf("S ");
	i = -1;
	while (++i < exp_ln)
		printf("E");
	printf(" ");
	i = -1;
	while (++i < man_ln)
		printf("M");
	printf("\n");
}
/*
**	1111111111111111111111111
**	1000101101000100101100110010101101010111100000001011100000000000
*/
static const char				*g_man_vals[] =
{
	"1.0",
	"0.5",
	"0.25",
	"0.125",
	"0.0625",
	"0.03125",
	"0.015625",
	"0.0078125",
	"0.00390625",
	"0.001953125",
	"0.0009765625",
	"0.00048828125",
	"0.000244140625",
	"0.0001220703125",
	"0.00006103515625",
	"0.000030517578125",
	"0.0000152587890625",
	"0.00000762939453125",
	"0.000003814697265625",
	"0.0000019073486328125",
	"0.00000095367431640625",
	"0.000000476837158203125",
	"0.0000002384185791015625",
	"0.00000011920928955078125",
	"0.000000059604644775390625",
	"0.0000000298023223876953125",
	"0.00000001490116119384765625",
	"0.000000007450580596923828125",
	"0.0000000037252902984619140625",
	"0.00000000186264514923095703125",
	"0.000000000931322574615478515625",
	"0.0000000004656612873077392578125",
	"0.00000000023283064365386962890625",
	"0.000000000116415321826934814453125",
	"0.0000000000582076609134674072265625",
	"0.00000000002910383045673370361328125",
	"0.000000000014551915228366851806640625",
	"0.0000000000072759576141834259033203125",
	"0.00000000000363797880709171295166015625",
	"0.000000000001818989403545856475830078125",
	"0.0000000000009094947017729282379150390625",
	"0.00000000000045474735088646411895751953125",
	"0.000000000000227373675443232059478759765625",
	"0.0000000000001136868377216160297393798828125",
	"0.00000000000005684341886080801486968994140625",
	"0.000000000000028421709430404007434844970703125",
	"0.0000000000000142108547152020037174224853515625",
	"0.00000000000000710542735760100185871124267578125",
	"0.000000000000003552713678800500929355621337890625",
	"0.0000000000000017763568394002504646778106689453125",
	"0.00000000000000088817841970012523233890533447265625",
	"0.000000000000000444089209850062616169452667236328125",
	"0.0000000000000002220446049250313080847263336181640625",
	"0.00000000000000011102230246251565404236316680908203125",
	"0.000000000000000055511151231257827021181583404541015625",
	"0.0000000000000000277555756156289135105907917022705078125",
	"0.00000000000000001387778780781445675529539585113525390625",
	"0.000000000000000006938893903907228377647697925567626953125",
	"0.0000000000000000034694469519536141888238489627838134765625",
	"0.00000000000000000173472347597680709441192448139190673828125",
	"0.000000000000000000867361737988403547205962240695953369140625",
	"0.0000000000000000004336808689942017736029811203479766845703125",
	"0.00000000000000000021684043449710088680149056017398834228515625",
	"0.000000000000000000108420217248550443400745280086994171142578125",
	NULL
};

t_float					get_float_components(t_ft_dbl d)
{
	t_float				ret;
	t_float_conv		conv;
	int					exp_ln;
	int					man_ln;

	exp_ln = 0;
	ft_bzero(&conv, sizeof(conv));
	conv.value = d;
	man_ln = LDBL_MAX_EXP;
	while (man_ln != 0 && ++exp_ln)
		man_ln >>= 1;
	man_ln = LDBL_MANT_DIG - (sizeof(d) == sizeof(double));
	ft_memcpy(&ret.mantissa, conv.bytes, man_ln / 8);
	ret.exponent = *((unsigned short *)(conv.bytes + (man_ln / 8)));
	ret.sign = ret.exponent >> exp_ln;
	ret.exponent &= ~(1 << exp_ln);
	ft_printf("%.1b %.15b %.*lb\n", ret.sign, ret.exponent,
									man_ln, ret.mantissa);
	ret.exponent -= (LDBL_MAX_EXP - 1);
	return (ret);
}

void					print_float(t_ft_dbl d)
{
	int					i;
	t_float				fl;
	t_bflt				*tmp;
	t_bflt				*exp;
	t_bflt				*mantissa;

	i = 0;
	fl = get_float_components(d);
	exp = new_bflt("1.1");
	mantissa = new_bflt("0");
	while (i < LDBL_MANT_DIG)
	{
		if (!((fl.mantissa >> (LDBL_MANT_DIG - ++i)) & 0b1))
			continue ;
		tmp = mantissa;
		unset_bflt(exp);
		set_bflt(exp, g_man_vals[i - 1]);
		mantissa = add_bflt(exp, mantissa);
		del_bflt(tmp);
	}
	del_bflt(exp);
	/*ft_putstr("2^");
	ft_putnbr(fl.exponent);
	ft_putstr(" * ");*/
	/*print_bflt(mantissa);*/
	printf("%s * %d^%d\n", bflt_tostr(mantissa), FLT_RADIX, fl.exponent);
	if (!(exp = two_pow(fl.exponent)))
		return ;
	/*print_bflt(exp);*/
	tmp = exp;
	exp = mul_bflt(exp, mantissa);
	del_bflt(tmp);
	print_bflt(exp);
	del_bflt(exp);
}
