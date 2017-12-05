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
static const char *ng0 = "/home/l3/alder/Documents/AEO/Nexys3V6/IPWait.vhd";
extern char *IEEE_P_3620187407;

char *ieee_p_3620187407_sub_1496620905533721142_3965413181(char *, char *, char *, char *, char *, char *);
char *ieee_p_3620187407_sub_2255506239096238868_3965413181(char *, char *, char *, char *, int );


static void work_a_0886648295_2030911003_p_0(char *t0)
{
    unsigned char t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    unsigned char t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;

LAB0:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 1312U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 4152);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(60, ng0);
    t4 = (t0 + 2152U);
    t8 = *((char **)t4);
    t9 = *((unsigned char *)t8);
    t4 = (t0 + 4248);
    t10 = (t4 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t9;
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(61, ng0);
    t2 = (t0 + 1672U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t2 = (t0 + 4312);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t10 = (t8 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = t1;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(62, ng0);
    t2 = (t0 + 1992U);
    t4 = *((char **)t2);
    t2 = (t0 + 4376);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t10 = (t8 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t4, 32U);
    xsi_driver_first_trans_fast(t2);
    goto LAB3;

LAB5:    t4 = (t0 + 1352U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

}

static void work_a_0886648295_2030911003_p_1(char *t0)
{
    char t10[16];
    char t23[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    unsigned char t7;
    char *t8;
    unsigned char t9;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    static char *nl0[] = {&&LAB3, &&LAB4, &&LAB5};

LAB0:    xsi_set_current_line(72, ng0);
    t1 = (t0 + 4440);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(73, ng0);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t1 = (t0 + 4504);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 32U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(74, ng0);
    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t7 = *((unsigned char *)t2);
    t1 = (char *)((nl0) + t7);
    goto **((char **)t1);

LAB2:    t1 = (t0 + 4168);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(76, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t3 = (t0 + 6848U);
    t5 = (t0 + 7010);
    t8 = (t0 + 6816U);
    t9 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t4, t3, t5, t8);
    if (t9 != 0)
        goto LAB7;

LAB9:    xsi_set_current_line(80, ng0);
    t1 = (t0 + 4568);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB8:    goto LAB2;

LAB4:    xsi_set_current_line(83, ng0);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t19 = (31 - 31);
    t20 = (t19 * -1);
    t21 = (1U * t20);
    t22 = (0 + t21);
    t1 = (t2 + t22);
    t7 = *((unsigned char *)t1);
    t9 = (t7 == (unsigned char)3);
    if (t9 != 0)
        goto LAB10;

LAB12:    xsi_set_current_line(86, ng0);
    t1 = (t0 + 4568);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(87, ng0);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t1 = (t0 + 6864U);
    t3 = (t0 + 7021);
    t5 = (t23 + 0U);
    t6 = (t5 + 0U);
    *((int *)t6) = 0;
    t6 = (t5 + 4U);
    *((int *)t6) = 31;
    t6 = (t5 + 8U);
    *((int *)t6) = 1;
    t19 = (31 - 0);
    t20 = (t19 * 1);
    t20 = (t20 + 1);
    t6 = (t5 + 12U);
    *((unsigned int *)t6) = t20;
    t6 = ieee_p_3620187407_sub_1496620905533721142_3965413181(IEEE_P_3620187407, t10, t2, t1, t3, t23);
    t8 = (t0 + 4504);
    t11 = (t8 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t6, 32U);
    xsi_driver_first_trans_fast(t8);

LAB11:    goto LAB2;

LAB5:    xsi_set_current_line(90, ng0);
    t1 = (t0 + 4440);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(91, ng0);
    t1 = (t0 + 4568);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB6:    xsi_set_current_line(93, ng0);
    t1 = (t0 + 4568);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB7:    xsi_set_current_line(77, ng0);
    t11 = (t0 + 1032U);
    t12 = *((char **)t11);
    t11 = (t0 + 6832U);
    t13 = ieee_p_3620187407_sub_2255506239096238868_3965413181(IEEE_P_3620187407, t10, t12, t11, 5);
    t14 = (t0 + 4504);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t13, 32U);
    xsi_driver_first_trans_fast(t14);
    xsi_set_current_line(78, ng0);
    t1 = (t0 + 4568);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB8;

LAB10:    xsi_set_current_line(84, ng0);
    t3 = (t0 + 4568);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t8 = *((char **)t6);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t3);
    goto LAB11;

}


extern void work_a_0886648295_2030911003_init()
{
	static char *pe[] = {(void *)work_a_0886648295_2030911003_p_0,(void *)work_a_0886648295_2030911003_p_1};
	xsi_register_didat("work_a_0886648295_2030911003", "isim/masterbench_isim_beh.exe.sim/work/a_0886648295_2030911003.didat");
	xsi_register_executes(pe);
}
