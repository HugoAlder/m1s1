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
static const char *ng0 = "/home/l3/alder/Documents/AEO/Nexys3V6/returnstack.vhd";
extern char *IEEE_P_3620187407;

unsigned char ieee_p_3620187407_sub_1306455576380142462_3965413181(char *, char *, char *, char *, char *);
char *ieee_p_3620187407_sub_2255506239096166994_3965413181(char *, char *, char *, char *, int );
char *ieee_p_3620187407_sub_2255506239096238868_3965413181(char *, char *, char *, char *, int );
int ieee_p_3620187407_sub_5109402382352621412_3965413181(char *, char *, char *);


static void work_a_1734369168_3212880686_p_0(char *t0)
{
    char t22[16];
    char t23[16];
    unsigned char t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    unsigned char t9;
    unsigned char t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    int t17;
    int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t24;
    char *t25;
    char *t26;
    char *t27;

LAB0:    xsi_set_current_line(54, ng0);
    t2 = (t0 + 992U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 4032);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(56, ng0);
    t4 = (t0 + 1832U);
    t8 = *((char **)t4);
    t9 = *((unsigned char *)t8);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB8;

LAB10:    t2 = (t0 + 1192U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t3 = (t1 == (unsigned char)3);
    if (t3 != 0)
        goto LAB11;

LAB12:
LAB9:    xsi_set_current_line(66, ng0);
    t2 = (t0 + 1352U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t3 = (t1 == (unsigned char)3);
    if (t3 != 0)
        goto LAB16;

LAB18:
LAB17:    goto LAB3;

LAB5:    t4 = (t0 + 1032U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)2);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(57, ng0);
    t4 = (t0 + 7352);
    t12 = (t0 + 4128);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t4, 4U);
    xsi_driver_first_trans_fast(t12);
    goto LAB9;

LAB11:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 1512U);
    t5 = *((char **)t2);
    t2 = (t0 + 2312U);
    t8 = *((char **)t2);
    t2 = (t0 + 6744U);
    t17 = ieee_p_3620187407_sub_5109402382352621412_3965413181(IEEE_P_3620187407, t8, t2);
    t18 = (t17 - 15);
    t19 = (t18 * -1);
    t20 = (32U * t19);
    t21 = (0U + t20);
    t11 = (t0 + 4192);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t5, 32U);
    xsi_driver_first_trans_delta(t11, t21, 32U, 0LL);
    xsi_set_current_line(62, ng0);
    t2 = (t0 + 2312U);
    t4 = *((char **)t2);
    t2 = (t0 + 6744U);
    t5 = (t0 + 7356);
    t11 = (t22 + 0U);
    t12 = (t11 + 0U);
    *((int *)t12) = 0;
    t12 = (t11 + 4U);
    *((int *)t12) = 3;
    t12 = (t11 + 8U);
    *((int *)t12) = 1;
    t17 = (3 - 0);
    t19 = (t17 * 1);
    t19 = (t19 + 1);
    t12 = (t11 + 12U);
    *((unsigned int *)t12) = t19;
    t1 = ieee_p_3620187407_sub_1306455576380142462_3965413181(IEEE_P_3620187407, t4, t2, t5, t22);
    if (t1 != 0)
        goto LAB13;

LAB15:
LAB14:    goto LAB9;

LAB13:    xsi_set_current_line(63, ng0);
    t12 = (t0 + 2312U);
    t13 = *((char **)t12);
    t12 = (t0 + 6744U);
    t14 = ieee_p_3620187407_sub_2255506239096238868_3965413181(IEEE_P_3620187407, t23, t13, t12, 1);
    t15 = (t0 + 4128);
    t16 = (t15 + 56U);
    t24 = *((char **)t16);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    memcpy(t26, t14, 4U);
    xsi_driver_first_trans_fast(t15);
    goto LAB14;

LAB16:    xsi_set_current_line(67, ng0);
    t2 = (t0 + 2312U);
    t5 = *((char **)t2);
    t2 = (t0 + 6744U);
    t8 = (t0 + 7360);
    t12 = (t22 + 0U);
    t13 = (t12 + 0U);
    *((int *)t13) = 0;
    t13 = (t12 + 4U);
    *((int *)t13) = 3;
    t13 = (t12 + 8U);
    *((int *)t13) = 1;
    t17 = (3 - 0);
    t19 = (t17 * 1);
    t19 = (t19 + 1);
    t13 = (t12 + 12U);
    *((unsigned int *)t13) = t19;
    t6 = ieee_p_3620187407_sub_1306455576380142462_3965413181(IEEE_P_3620187407, t5, t2, t8, t22);
    if (t6 != 0)
        goto LAB19;

LAB21:
LAB20:    goto LAB17;

LAB19:    xsi_set_current_line(68, ng0);
    t13 = (t0 + 2312U);
    t14 = *((char **)t13);
    t13 = (t0 + 6744U);
    t15 = ieee_p_3620187407_sub_2255506239096166994_3965413181(IEEE_P_3620187407, t23, t14, t13, 1);
    t16 = (t0 + 4128);
    t24 = (t16 + 56U);
    t25 = *((char **)t24);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    memcpy(t27, t15, 4U);
    xsi_driver_first_trans_fast(t16);
    goto LAB20;

}

static void work_a_1734369168_3212880686_p_1(char *t0)
{
    char t5[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    int t8;
    unsigned int t9;
    unsigned char t10;
    char *t11;
    char *t12;
    int t13;
    int t14;
    int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;

LAB0:    xsi_set_current_line(80, ng0);
    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t1 = (t0 + 6744U);
    t3 = (t0 + 7364);
    t6 = (t5 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 0;
    t7 = (t6 + 4U);
    *((int *)t7) = 3;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t8 = (3 - 0);
    t9 = (t8 * 1);
    t9 = (t9 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t9;
    t10 = ieee_p_3620187407_sub_1306455576380142462_3965413181(IEEE_P_3620187407, t2, t1, t3, t5);
    if (t10 != 0)
        goto LAB2;

LAB4:    xsi_set_current_line(83, ng0);
    t1 = (t0 + 1992U);
    t2 = *((char **)t1);
    t1 = (t0 + 2312U);
    t3 = *((char **)t1);
    t1 = (t0 + 6744U);
    t8 = ieee_p_3620187407_sub_5109402382352621412_3965413181(IEEE_P_3620187407, t3, t1);
    t13 = (t8 - 15);
    t9 = (t13 * -1);
    xsi_vhdl_check_range_of_index(15, 0, -1, t8);
    t16 = (32U * t9);
    t17 = (0 + t16);
    t4 = (t2 + t17);
    t6 = (t0 + 4256);
    t7 = (t6 + 56U);
    t11 = *((char **)t7);
    t12 = (t11 + 56U);
    t18 = *((char **)t12);
    memcpy(t18, t4, 32U);
    xsi_driver_first_trans_fast_port(t6);

LAB3:    t1 = (t0 + 4048);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(81, ng0);
    t7 = (t0 + 1992U);
    t11 = *((char **)t7);
    t7 = (t0 + 2312U);
    t12 = *((char **)t7);
    t7 = (t0 + 6744U);
    t13 = ieee_p_3620187407_sub_5109402382352621412_3965413181(IEEE_P_3620187407, t12, t7);
    t14 = (t13 + 1);
    t15 = (t14 - 15);
    t9 = (t15 * -1);
    xsi_vhdl_check_range_of_index(15, 0, -1, t14);
    t16 = (32U * t9);
    t17 = (0 + t16);
    t18 = (t11 + t17);
    t19 = (t0 + 4256);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    memcpy(t23, t18, 32U);
    xsi_driver_first_trans_fast_port(t19);
    goto LAB3;

}


extern void work_a_1734369168_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1734369168_3212880686_p_0,(void *)work_a_1734369168_3212880686_p_1};
	xsi_register_didat("work_a_1734369168_3212880686", "isim/masterbench_isim_beh.exe.sim/work/a_1734369168_3212880686.didat");
	xsi_register_executes(pe);
}
