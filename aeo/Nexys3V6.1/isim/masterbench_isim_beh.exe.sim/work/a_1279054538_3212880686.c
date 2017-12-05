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
static const char *ng0 = "/home/l3/alder/Documents/AEO/Nexys3V6/predicat.vhd";



static void work_a_1279054538_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    unsigned int t4;
    int t5;
    unsigned int t6;
    unsigned int t7;
    char *t8;
    int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned char t12;
    unsigned int t13;
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
    char *t25;
    char *t26;

LAB0:    xsi_set_current_line(42, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t3 = t1;
    if (-1 == -1)
        goto LAB5;

LAB6:    t4 = 0;

LAB7:    t5 = (t4 - 31);
    t6 = (t5 * -1);
    t7 = (1U * t6);
    t8 = (t3 + t7);
    t9 = (0 - 31);
    t10 = (t9 * -1);
    t10 = (t10 + 1);
    t11 = (1U * t10);
    memset(t8, (unsigned char)2, t11);
    t12 = 1;
    if (32U == 32U)
        goto LAB8;

LAB9:    t12 = 0;

LAB10:    if (t12 != 0)
        goto LAB3;

LAB4:
LAB14:    t21 = (t0 + 2744);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    *((unsigned char *)t25) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t21);

LAB2:    t26 = (t0 + 2664);
    *((int *)t26) = 1;

LAB1:    return;
LAB3:    t16 = (t0 + 2744);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    *((unsigned char *)t20) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t16);
    goto LAB2;

LAB5:    t4 = 31;
    goto LAB7;

LAB8:    t13 = 0;

LAB11:    if (t13 < 32U)
        goto LAB12;
    else
        goto LAB10;

LAB12:    t14 = (t2 + t13);
    t15 = (t1 + t13);
    if (*((unsigned char *)t14) != *((unsigned char *)t15))
        goto LAB9;

LAB13:    t13 = (t13 + 1);
    goto LAB11;

LAB15:    goto LAB2;

}


extern void work_a_1279054538_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1279054538_3212880686_p_0};
	xsi_register_didat("work_a_1279054538_3212880686", "isim/masterbench_isim_beh.exe.sim/work/a_1279054538_3212880686.didat");
	xsi_register_executes(pe);
}
