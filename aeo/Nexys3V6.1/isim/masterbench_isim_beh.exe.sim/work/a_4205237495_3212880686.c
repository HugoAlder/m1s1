/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x9ca8bed6 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/l3/alder/Documents/AEO/Nexys3V6/IP_rdm.vhd";
extern char *IEEE_P_3620187407;
extern char *IEEE_P_2592010699;



static void work_a_4205237495_3212880686_p_0(char *t0)
{
    char t6[16];
    char *t1;
    char *t2;
    unsigned int t3;
    unsigned int t4;
    unsigned int t5;
    char *t7;
    char *t8;
    int t9;
    unsigned int t10;
    char *t12;
    unsigned char t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;

LAB0:    xsi_set_current_line(67, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = (10 - 10);
    t4 = (t3 * 1U);
    t5 = (0 + t4);
    t1 = (t2 + t5);
    t7 = (t6 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 10;
    t8 = (t7 + 4U);
    *((int *)t8) = 0;
    t8 = (t7 + 8U);
    *((int *)t8) = -1;
    t9 = (0 - 10);
    t10 = (t9 * -1);
    t10 = (t10 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t10;
    t8 = (t0 + 6545);
    t12 = (t0 + 6400U);
    t13 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t1, t6, t8, t12);
    if (t13 != 0)
        goto LAB3;

LAB4:
LAB5:    t19 = (t0 + 4192);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    *((unsigned char *)t23) = (unsigned char)2;
    xsi_driver_first_trans_fast(t19);

LAB2:    t24 = (t0 + 4080);
    *((int *)t24) = 1;

LAB1:    return;
LAB3:    t14 = (t0 + 4192);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    *((unsigned char *)t18) = (unsigned char)3;
    xsi_driver_first_trans_fast(t14);
    goto LAB2;

LAB6:    goto LAB2;

}

static void work_a_4205237495_3212880686_p_1(char *t0)
{
    char t6[16];
    char t21[16];
    char t23[16];
    char t28[16];
    char *t1;
    char *t2;
    unsigned int t3;
    unsigned int t4;
    unsigned int t5;
    char *t7;
    char *t8;
    int t9;
    unsigned int t10;
    char *t12;
    unsigned char t13;
    char *t14;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t22;
    char *t24;
    char *t25;
    int t26;
    unsigned int t27;
    char *t29;
    int t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;

LAB0:    xsi_set_current_line(68, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = (10 - 10);
    t4 = (t3 * 1U);
    t5 = (0 + t4);
    t1 = (t2 + t5);
    t7 = (t6 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 10;
    t8 = (t7 + 4U);
    *((int *)t8) = 0;
    t8 = (t7 + 8U);
    *((int *)t8) = -1;
    t9 = (0 - 10);
    t10 = (t9 * -1);
    t10 = (t10 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t10;
    t8 = (t0 + 6556);
    t12 = (t0 + 6400U);
    t13 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t1, t6, t8, t12);
    if (t13 != 0)
        goto LAB3;

LAB4:
LAB5:    t35 = xsi_get_transient_memory(32U);
    memset(t35, 0, 32U);
    t36 = t35;
    memset(t36, (unsigned char)4, 32U);
    t37 = (t0 + 4256);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    t40 = (t39 + 56U);
    t41 = *((char **)t40);
    memcpy(t41, t35, 32U);
    xsi_driver_first_trans_fast_port(t37);

LAB2:    t42 = (t0 + 4096);
    *((int *)t42) = 1;

LAB1:    return;
LAB3:    t14 = (t0 + 6567);
    t16 = (t0 + 1832U);
    t17 = *((char **)t16);
    t10 = (31 - 11);
    t18 = (t10 * 1U);
    t19 = (0 + t18);
    t16 = (t17 + t19);
    t22 = ((IEEE_P_2592010699) + 4000);
    t24 = (t23 + 0U);
    t25 = (t24 + 0U);
    *((int *)t25) = 0;
    t25 = (t24 + 4U);
    *((int *)t25) = 19;
    t25 = (t24 + 8U);
    *((int *)t25) = 1;
    t26 = (19 - 0);
    t27 = (t26 * 1);
    t27 = (t27 + 1);
    t25 = (t24 + 12U);
    *((unsigned int *)t25) = t27;
    t25 = (t28 + 0U);
    t29 = (t25 + 0U);
    *((int *)t29) = 11;
    t29 = (t25 + 4U);
    *((int *)t29) = 0;
    t29 = (t25 + 8U);
    *((int *)t29) = -1;
    t30 = (0 - 11);
    t27 = (t30 * -1);
    t27 = (t27 + 1);
    t29 = (t25 + 12U);
    *((unsigned int *)t29) = t27;
    t20 = xsi_base_array_concat(t20, t21, t22, (char)97, t14, t23, (char)97, t16, t28, (char)101);
    t29 = (t0 + 4256);
    t31 = (t29 + 56U);
    t32 = *((char **)t31);
    t33 = (t32 + 56U);
    t34 = *((char **)t33);
    memcpy(t34, t20, 32U);
    xsi_driver_first_trans_fast_port(t29);
    goto LAB2;

LAB6:    goto LAB2;

}

static void work_a_4205237495_3212880686_p_2(char *t0)
{
    char t6[16];
    char t21[16];
    char t23[16];
    char t28[16];
    char *t1;
    char *t2;
    unsigned int t3;
    unsigned int t4;
    unsigned int t5;
    char *t7;
    char *t8;
    int t9;
    unsigned int t10;
    char *t12;
    unsigned char t13;
    char *t14;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t22;
    char *t24;
    char *t25;
    int t26;
    unsigned int t27;
    char *t29;
    int t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;

LAB0:    xsi_set_current_line(69, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = (10 - 10);
    t4 = (t3 * 1U);
    t5 = (0 + t4);
    t1 = (t2 + t5);
    t7 = (t6 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 10;
    t8 = (t7 + 4U);
    *((int *)t8) = 0;
    t8 = (t7 + 8U);
    *((int *)t8) = -1;
    t9 = (0 - 10);
    t10 = (t9 * -1);
    t10 = (t10 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t10;
    t8 = (t0 + 6587);
    t12 = (t0 + 6400U);
    t13 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t1, t6, t8, t12);
    if (t13 != 0)
        goto LAB3;

LAB4:
LAB5:    t35 = xsi_get_transient_memory(32U);
    memset(t35, 0, 32U);
    t36 = t35;
    memset(t36, (unsigned char)4, 32U);
    t37 = (t0 + 4320);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    t40 = (t39 + 56U);
    t41 = *((char **)t40);
    memcpy(t41, t35, 32U);
    xsi_driver_first_trans_fast_port(t37);

LAB2:    t42 = (t0 + 4112);
    *((int *)t42) = 1;

LAB1:    return;
LAB3:    t14 = (t0 + 6598);
    t16 = (t0 + 1832U);
    t17 = *((char **)t16);
    t10 = (31 - 23);
    t18 = (t10 * 1U);
    t19 = (0 + t18);
    t16 = (t17 + t19);
    t22 = ((IEEE_P_2592010699) + 4000);
    t24 = (t23 + 0U);
    t25 = (t24 + 0U);
    *((int *)t25) = 0;
    t25 = (t24 + 4U);
    *((int *)t25) = 19;
    t25 = (t24 + 8U);
    *((int *)t25) = 1;
    t26 = (19 - 0);
    t27 = (t26 * 1);
    t27 = (t27 + 1);
    t25 = (t24 + 12U);
    *((unsigned int *)t25) = t27;
    t25 = (t28 + 0U);
    t29 = (t25 + 0U);
    *((int *)t29) = 23;
    t29 = (t25 + 4U);
    *((int *)t29) = 12;
    t29 = (t25 + 8U);
    *((int *)t29) = -1;
    t30 = (12 - 23);
    t27 = (t30 * -1);
    t27 = (t27 + 1);
    t29 = (t25 + 12U);
    *((unsigned int *)t29) = t27;
    t20 = xsi_base_array_concat(t20, t21, t22, (char)97, t14, t23, (char)97, t16, t28, (char)101);
    t29 = (t0 + 4320);
    t31 = (t29 + 56U);
    t32 = *((char **)t31);
    t33 = (t32 + 56U);
    t34 = *((char **)t33);
    memcpy(t34, t20, 32U);
    xsi_driver_first_trans_fast_port(t29);
    goto LAB2;

LAB6:    goto LAB2;

}


extern void work_a_4205237495_3212880686_init()
{
	static char *pe[] = {(void *)work_a_4205237495_3212880686_p_0,(void *)work_a_4205237495_3212880686_p_1,(void *)work_a_4205237495_3212880686_p_2};
	xsi_register_didat("work_a_4205237495_3212880686", "isim/masterbench_isim_beh.exe.sim/work/a_4205237495_3212880686.didat");
	xsi_register_executes(pe);
}
