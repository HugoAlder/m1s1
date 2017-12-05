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
static const char *ng0 = "/home/l3/alder/Documents/AEO/TP5/clk_div.vhd";
extern char *IEEE_P_3620187407;

char *ieee_p_3620187407_sub_2255506239096166994_3965413181(char *, char *, char *, char *, int );


static void work_a_1255938629_2858095548_p_0(char *t0)
{
    char t10[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned char t8;
    unsigned char t9;
    char *t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    int t16;
    unsigned int t17;
    unsigned char t18;

LAB0:    xsi_set_current_line(36, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 992U);
    t4 = xsi_signal_has_event(t1);
    if (t4 == 1)
        goto LAB7;

LAB8:    t3 = (unsigned char)0;

LAB9:    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    xsi_set_current_line(47, ng0);
    t1 = (t0 + 1968U);
    t2 = *((char **)t1);
    t16 = (18 - 23);
    t14 = (t16 * -1);
    t15 = (1U * t14);
    t17 = (0 + t15);
    t1 = (t2 + t17);
    t3 = *((unsigned char *)t1);
    t5 = (t0 + 3608);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t11 = (t7 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = t3;
    xsi_driver_first_trans_fast(t5);
    t1 = (t0 + 3512);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(37, ng0);
    t1 = (t0 + 5555);
    t6 = (t0 + 1968U);
    t7 = *((char **)t6);
    t6 = (t7 + 0);
    memcpy(t6, t1, 24U);
    xsi_set_current_line(38, ng0);
    t1 = (t0 + 3608);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB3;

LAB5:    xsi_set_current_line(40, ng0);
    t2 = (t0 + 1968U);
    t6 = *((char **)t2);
    t2 = (t0 + 5504U);
    t7 = ieee_p_3620187407_sub_2255506239096166994_3965413181(IEEE_P_3620187407, t10, t6, t2, 1);
    t11 = (t0 + 1968U);
    t12 = *((char **)t11);
    t11 = (t12 + 0);
    t13 = (t10 + 12U);
    t14 = *((unsigned int *)t13);
    t15 = (1U * t14);
    memcpy(t11, t7, t15);
    xsi_set_current_line(41, ng0);
    t1 = (t0 + 1968U);
    t2 = *((char **)t1);
    t16 = (18 - 23);
    t14 = (t16 * -1);
    t15 = (1U * t14);
    t17 = (0 + t15);
    t1 = (t2 + t17);
    t4 = *((unsigned char *)t1);
    t8 = (t4 == (unsigned char)3);
    if (t8 == 1)
        goto LAB13;

LAB14:    t3 = (unsigned char)0;

LAB15:    if (t3 != 0)
        goto LAB10;

LAB12:    xsi_set_current_line(44, ng0);
    t1 = (t0 + 3672);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB11:    goto LAB3;

LAB7:    t2 = (t0 + 1032U);
    t5 = *((char **)t2);
    t8 = *((unsigned char *)t5);
    t9 = (t8 == (unsigned char)3);
    t3 = t9;
    goto LAB9;

LAB10:    xsi_set_current_line(42, ng0);
    t5 = (t0 + 3672);
    t7 = (t5 + 56U);
    t11 = *((char **)t7);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t5);
    goto LAB11;

LAB13:    t5 = (t0 + 1672U);
    t6 = *((char **)t5);
    t9 = *((unsigned char *)t6);
    t18 = (t9 == (unsigned char)2);
    t3 = t18;
    goto LAB15;

}

static void work_a_1255938629_2858095548_p_1(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(49, ng0);

LAB3:    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 3736);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 3528);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_1255938629_2858095548_init()
{
	static char *pe[] = {(void *)work_a_1255938629_2858095548_p_0,(void *)work_a_1255938629_2858095548_p_1};
	xsi_register_didat("work_a_1255938629_2858095548", "isim/code_isim_beh.exe.sim/work/a_1255938629_2858095548.didat");
	xsi_register_executes(pe);
}
