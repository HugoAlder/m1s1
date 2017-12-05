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
static const char *ng0 = "/home/l3/alder/Documents/AEO/TP5/code.vhd";
extern char *IEEE_P_2592010699;



static void work_a_3644029139_3212880686_p_0(char *t0)
{
    char t6[16];
    char t8[16];
    char t14[16];
    char *t1;
    char *t3;
    char *t4;
    unsigned char t5;
    char *t7;
    char *t9;
    char *t10;
    int t11;
    unsigned int t12;
    char *t13;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;

LAB0:    xsi_set_current_line(110, ng0);

LAB3:    t1 = (t0 + 8425);
    t3 = (t0 + 1832U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t7 = ((IEEE_P_2592010699) + 4000);
    t9 = (t8 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 0;
    t10 = (t9 + 4U);
    *((int *)t10) = 2;
    t10 = (t9 + 8U);
    *((int *)t10) = 1;
    t11 = (2 - 0);
    t12 = (t11 * 1);
    t12 = (t12 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t12;
    t3 = xsi_base_array_concat(t3, t6, t7, (char)97, t1, t8, (char)99, t5, (char)101);
    t10 = (t0 + 1672U);
    t13 = *((char **)t10);
    t15 = ((IEEE_P_2592010699) + 4000);
    t16 = (t0 + 8360U);
    t10 = xsi_base_array_concat(t10, t14, t15, (char)97, t3, t6, (char)97, t13, t16, (char)101);
    t17 = (t0 + 5080);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t10, 6U);
    xsi_driver_first_trans_delta(t17, 2U, 6U, 0LL);

LAB2:    t22 = (t0 + 4936);
    *((int *)t22) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3644029139_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    unsigned int t4;
    unsigned int t5;
    char *t6;
    char *t7;
    int t8;
    char *t9;
    char *t10;
    int t11;
    char *t12;
    int t14;
    char *t15;
    int t17;
    char *t18;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;

LAB0:    xsi_set_current_line(114, ng0);
    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t3 = (4 - 3);
    t4 = (t3 * 1U);
    t5 = (0 + t4);
    t1 = (t2 + t5);
    t6 = (t0 + 8428);
    t8 = xsi_mem_cmp(t6, t1, 4U);
    if (t8 == 1)
        goto LAB3;

LAB8:    t9 = (t0 + 8432);
    t11 = xsi_mem_cmp(t9, t1, 4U);
    if (t11 == 1)
        goto LAB4;

LAB9:    t12 = (t0 + 8436);
    t14 = xsi_mem_cmp(t12, t1, 4U);
    if (t14 == 1)
        goto LAB5;

LAB10:    t15 = (t0 + 8440);
    t17 = xsi_mem_cmp(t15, t1, 4U);
    if (t17 == 1)
        goto LAB6;

LAB11:
LAB7:    xsi_set_current_line(123, ng0);
    t1 = (t0 + 5208);
    t2 = (t1 + 56U);
    t6 = *((char **)t2);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB2:    t1 = (t0 + 4952);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(115, ng0);
    t18 = (t0 + 8444);
    t20 = (t0 + 5144);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    memcpy(t24, t18, 2U);
    xsi_driver_first_trans_fast(t20);
    xsi_set_current_line(116, ng0);
    t1 = (t0 + 5208);
    t2 = (t1 + 56U);
    t6 = *((char **)t2);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB4:    xsi_set_current_line(117, ng0);
    t1 = (t0 + 8446);
    t6 = (t0 + 5144);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    t10 = (t9 + 56U);
    t12 = *((char **)t10);
    memcpy(t12, t1, 2U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(118, ng0);
    t1 = (t0 + 5208);
    t2 = (t1 + 56U);
    t6 = *((char **)t2);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB5:    xsi_set_current_line(119, ng0);
    t1 = (t0 + 8448);
    t6 = (t0 + 5144);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    t10 = (t9 + 56U);
    t12 = *((char **)t10);
    memcpy(t12, t1, 2U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(120, ng0);
    t1 = (t0 + 5208);
    t2 = (t1 + 56U);
    t6 = *((char **)t2);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB6:    xsi_set_current_line(121, ng0);
    t1 = (t0 + 8450);
    t6 = (t0 + 5144);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    t10 = (t9 + 56U);
    t12 = *((char **)t10);
    memcpy(t12, t1, 2U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(122, ng0);
    t1 = (t0 + 5208);
    t2 = (t1 + 56U);
    t6 = *((char **)t2);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB12:;
}

static void work_a_3644029139_3212880686_p_2(char *t0)
{
    unsigned char t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned char t13;
    unsigned char t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;

LAB0:    xsi_set_current_line(129, ng0);
    t2 = (t0 + 1312U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 4968);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(130, ng0);
    t4 = (t0 + 1192U);
    t8 = *((char **)t4);
    t9 = (4 - 4);
    t10 = (t9 * -1);
    t11 = (1U * t10);
    t12 = (0 + t11);
    t4 = (t8 + t12);
    t13 = *((unsigned char *)t4);
    t14 = (t13 == (unsigned char)3);
    if (t14 != 0)
        goto LAB8;

LAB10:    t2 = (t0 + 1832U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t3 = (t1 == (unsigned char)2);
    if (t3 != 0)
        goto LAB11;

LAB12:
LAB9:    goto LAB3;

LAB5:    t4 = (t0 + 1352U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(131, ng0);
    t15 = (t0 + 5272);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = (unsigned char)0;
    xsi_driver_first_trans_fast(t15);
    goto LAB9;

LAB11:    xsi_set_current_line(133, ng0);
    t2 = (t0 + 2152U);
    t5 = *((char **)t2);
    t6 = *((unsigned char *)t5);
    t2 = (t0 + 5272);
    t8 = (t2 + 56U);
    t15 = *((char **)t8);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    *((unsigned char *)t17) = t6;
    xsi_driver_first_trans_fast(t2);
    goto LAB9;

}

static void work_a_3644029139_3212880686_p_3(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    xsi_set_current_line(143, ng0);
    t1 = (t0 + 1992U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)4);
    if (t4 != 0)
        goto LAB2;

LAB4:    xsi_set_current_line(146, ng0);
    t1 = (t0 + 8454);
    t5 = (t0 + 5336);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 2U);
    xsi_driver_first_trans_delta(t5, 0U, 2U, 0LL);

LAB3:    t1 = (t0 + 4984);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(144, ng0);
    t1 = (t0 + 8452);
    t6 = (t0 + 5336);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 2U);
    xsi_driver_first_trans_delta(t6, 0U, 2U, 0LL);
    goto LAB3;

}

static void work_a_3644029139_3212880686_p_4(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned char t8;
    unsigned char t9;
    unsigned char t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    static char *nl0[] = {&&LAB6, &&LAB7, &&LAB8, &&LAB9, &&LAB9};

LAB0:    xsi_set_current_line(153, ng0);
    t1 = (t0 + 1992U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 5400);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(156, ng0);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t8 = (t3 == (unsigned char)3);
    if (t8 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5000);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(157, ng0);
    t1 = (t0 + 1992U);
    t4 = *((char **)t1);
    t9 = *((unsigned char *)t4);
    t1 = (char *)((nl0) + t9);
    goto **((char **)t1);

LAB5:    goto LAB3;

LAB6:    xsi_set_current_line(159, ng0);
    t5 = (t0 + 1672U);
    t6 = *((char **)t5);
    t5 = (t0 + 8456);
    t10 = 1;
    if (2U == 2U)
        goto LAB13;

LAB14:    t10 = 0;

LAB15:    if (t10 != 0)
        goto LAB10;

LAB12:    xsi_set_current_line(162, ng0);
    t1 = (t0 + 5400);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB11:    goto LAB5;

LAB7:    xsi_set_current_line(165, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t1 = (t0 + 8458);
    t3 = 1;
    if (2U == 2U)
        goto LAB22;

LAB23:    t3 = 0;

LAB24:    if (t3 != 0)
        goto LAB19;

LAB21:    xsi_set_current_line(168, ng0);
    t1 = (t0 + 5400);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB20:    goto LAB5;

LAB8:    xsi_set_current_line(171, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t1 = (t0 + 8460);
    t3 = 1;
    if (2U == 2U)
        goto LAB31;

LAB32:    t3 = 0;

LAB33:    if (t3 != 0)
        goto LAB28;

LAB30:    xsi_set_current_line(174, ng0);
    t1 = (t0 + 5400);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB29:    goto LAB5;

LAB9:    xsi_set_current_line(177, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t1 = (t0 + 8462);
    t3 = 1;
    if (2U == 2U)
        goto LAB40;

LAB41:    t3 = 0;

LAB42:    if (t3 != 0)
        goto LAB37;

LAB39:    xsi_set_current_line(180, ng0);
    t1 = (t0 + 5400);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB38:    goto LAB5;

LAB10:    xsi_set_current_line(160, ng0);
    t14 = (t0 + 5400);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    *((unsigned char *)t18) = (unsigned char)1;
    xsi_driver_first_trans_fast(t14);
    goto LAB11;

LAB13:    t11 = 0;

LAB16:    if (t11 < 2U)
        goto LAB17;
    else
        goto LAB15;

LAB17:    t12 = (t6 + t11);
    t13 = (t5 + t11);
    if (*((unsigned char *)t12) != *((unsigned char *)t13))
        goto LAB14;

LAB18:    t11 = (t11 + 1);
    goto LAB16;

LAB19:    xsi_set_current_line(166, ng0);
    t7 = (t0 + 5400);
    t12 = (t7 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = (unsigned char)2;
    xsi_driver_first_trans_fast(t7);
    goto LAB20;

LAB22:    t11 = 0;

LAB25:    if (t11 < 2U)
        goto LAB26;
    else
        goto LAB24;

LAB26:    t5 = (t2 + t11);
    t6 = (t1 + t11);
    if (*((unsigned char *)t5) != *((unsigned char *)t6))
        goto LAB23;

LAB27:    t11 = (t11 + 1);
    goto LAB25;

LAB28:    xsi_set_current_line(172, ng0);
    t7 = (t0 + 5400);
    t12 = (t7 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = (unsigned char)3;
    xsi_driver_first_trans_fast(t7);
    goto LAB29;

LAB31:    t11 = 0;

LAB34:    if (t11 < 2U)
        goto LAB35;
    else
        goto LAB33;

LAB35:    t5 = (t2 + t11);
    t6 = (t1 + t11);
    if (*((unsigned char *)t5) != *((unsigned char *)t6))
        goto LAB32;

LAB36:    t11 = (t11 + 1);
    goto LAB34;

LAB37:    xsi_set_current_line(178, ng0);
    t7 = (t0 + 5400);
    t12 = (t7 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = (unsigned char)4;
    xsi_driver_first_trans_fast(t7);
    goto LAB38;

LAB40:    t11 = 0;

LAB43:    if (t11 < 2U)
        goto LAB44;
    else
        goto LAB42;

LAB44:    t5 = (t2 + t11);
    t6 = (t1 + t11);
    if (*((unsigned char *)t5) != *((unsigned char *)t6))
        goto LAB41;

LAB45:    t11 = (t11 + 1);
    goto LAB43;

}


extern void work_a_3644029139_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3644029139_3212880686_p_0,(void *)work_a_3644029139_3212880686_p_1,(void *)work_a_3644029139_3212880686_p_2,(void *)work_a_3644029139_3212880686_p_3,(void *)work_a_3644029139_3212880686_p_4};
	xsi_register_didat("work_a_3644029139_3212880686", "isim/code_isim_beh.exe.sim/work/a_3644029139_3212880686.didat");
	xsi_register_executes(pe);
}
