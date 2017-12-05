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
static const char *ng0 = "/home/l3/alder/Documents/AEO/Nexys3V6/IPwaitBT1.vhd";
extern char *IEEE_P_2592010699;



static void work_a_2043985290_2030911003_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(72, ng0);

LAB3:    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t1 = (t0 + 5416);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 5U);
    xsi_driver_first_trans_fast(t1);

LAB2:    t7 = (t0 + 5288);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_2043985290_2030911003_p_1(char *t0)
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
    unsigned char t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;

LAB0:    xsi_set_current_line(113, ng0);
    t2 = (t0 + 1312U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 5304);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(114, ng0);
    t4 = (t0 + 1512U);
    t8 = *((char **)t4);
    t9 = *((unsigned char *)t8);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(117, ng0);
    t2 = (t0 + 2792U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t2 = (t0 + 5480);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t11 = (t8 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = t1;
    xsi_driver_first_trans_fast(t2);

LAB9:    goto LAB3;

LAB5:    t4 = (t0 + 1352U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(115, ng0);
    t4 = (t0 + 5480);
    t11 = (t4 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = (unsigned char)0;
    xsi_driver_first_trans_fast(t4);
    goto LAB9;

}

static void work_a_2043985290_2030911003_p_2(char *t0)
{
    char t9[16];
    char t10[16];
    char t14[16];
    char t18[16];
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t11;
    int t12;
    unsigned int t13;
    char *t15;
    int t16;
    char *t17;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    static char *nl0[] = {&&LAB4, &&LAB4, &&LAB3};

LAB0:    xsi_set_current_line(128, ng0);
    t1 = (t0 + 2952U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (char *)((nl0) + t3);
    goto **((char **)t1);

LAB2:    t1 = (t0 + 5320);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(131, ng0);
    t4 = (t0 + 5544);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(132, ng0);
    t1 = (t0 + 9116);
    t4 = (t0 + 9140);
    t7 = ((IEEE_P_2592010699) + 4000);
    t8 = (t10 + 0U);
    t11 = (t8 + 0U);
    *((int *)t11) = 0;
    t11 = (t8 + 4U);
    *((int *)t11) = 23;
    t11 = (t8 + 8U);
    *((int *)t11) = 1;
    t12 = (23 - 0);
    t13 = (t12 * 1);
    t13 = (t13 + 1);
    t11 = (t8 + 12U);
    *((unsigned int *)t11) = t13;
    t11 = (t14 + 0U);
    t15 = (t11 + 0U);
    *((int *)t15) = 0;
    t15 = (t11 + 4U);
    *((int *)t15) = 2;
    t15 = (t11 + 8U);
    *((int *)t15) = 1;
    t16 = (2 - 0);
    t13 = (t16 * 1);
    t13 = (t13 + 1);
    t15 = (t11 + 12U);
    *((unsigned int *)t15) = t13;
    t6 = xsi_base_array_concat(t6, t9, t7, (char)97, t1, t10, (char)97, t4, t14, (char)101);
    t15 = (t0 + 2472U);
    t17 = *((char **)t15);
    t19 = ((IEEE_P_2592010699) + 4000);
    t20 = (t0 + 9040U);
    t15 = xsi_base_array_concat(t15, t18, t19, (char)97, t6, t9, (char)97, t17, t20, (char)101);
    t21 = (t0 + 5608);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    memcpy(t25, t15, 32U);
    xsi_driver_first_trans_fast_port(t21);
    goto LAB2;

LAB4:    xsi_set_current_line(134, ng0);
    t1 = (t0 + 5544);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(135, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)4, 32U);
    t4 = (t0 + 5608);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t1, 32U);
    xsi_driver_first_trans_fast_port(t4);
    goto LAB2;

}

static void work_a_2043985290_2030911003_p_3(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    unsigned char t7;
    unsigned int t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned char t16;
    unsigned char t17;
    unsigned char t18;
    int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned char t22;
    unsigned char t23;
    int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned char t28;
    unsigned char t29;
    unsigned char t30;
    int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned char t35;
    unsigned char t36;
    int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned char t41;
    unsigned char t42;
    unsigned char t43;
    int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned char t48;
    unsigned char t49;
    int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned char t54;
    unsigned char t55;
    unsigned char t56;
    char *t57;
    char *t58;
    int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned char t63;
    unsigned char t64;
    char *t65;
    char *t66;
    int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned char t71;
    unsigned char t72;
    unsigned char t73;
    char *t74;
    char *t75;
    int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned char t80;
    unsigned char t81;
    char *t82;
    char *t83;
    int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned char t88;
    unsigned char t89;
    char *t90;
    char *t91;
    char *t92;
    char *t93;
    char *t94;
    static char *nl0[] = {&&LAB3, &&LAB4, &&LAB5};

LAB0:    xsi_set_current_line(141, ng0);
    t1 = (t0 + 2952U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (char *)((nl0) + t3);
    goto **((char **)t1);

LAB2:    t1 = (t0 + 5336);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(143, ng0);
    t4 = (t0 + 1192U);
    t5 = *((char **)t4);
    t4 = (t0 + 9143);
    t7 = 1;
    if (11U == 11U)
        goto LAB10;

LAB11:    t7 = 0;

LAB12:    if (t7 != 0)
        goto LAB7;

LAB9:    xsi_set_current_line(146, ng0);
    t1 = (t0 + 5672);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB8:    goto LAB2;

LAB4:    xsi_set_current_line(149, ng0);
    t1 = (t0 + 2152U);
    t2 = *((char **)t1);
    t19 = (0 - 4);
    t8 = (t19 * -1);
    t20 = (1U * t8);
    t21 = (0 + t20);
    t1 = (t2 + t21);
    t22 = *((unsigned char *)t1);
    t23 = (t22 == (unsigned char)3);
    if (t23 == 1)
        goto LAB31;

LAB32:    t18 = (unsigned char)0;

LAB33:    if (t18 == 1)
        goto LAB28;

LAB29:    t6 = (t0 + 2152U);
    t9 = *((char **)t6);
    t31 = (1 - 4);
    t32 = (t31 * -1);
    t33 = (1U * t32);
    t34 = (0 + t33);
    t6 = (t9 + t34);
    t35 = *((unsigned char *)t6);
    t36 = (t35 == (unsigned char)3);
    if (t36 == 1)
        goto LAB34;

LAB35:    t30 = (unsigned char)0;

LAB36:    t17 = t30;

LAB30:    if (t17 == 1)
        goto LAB25;

LAB26:    t12 = (t0 + 2152U);
    t13 = *((char **)t12);
    t44 = (2 - 4);
    t45 = (t44 * -1);
    t46 = (1U * t45);
    t47 = (0 + t46);
    t12 = (t13 + t47);
    t48 = *((unsigned char *)t12);
    t49 = (t48 == (unsigned char)3);
    if (t49 == 1)
        goto LAB37;

LAB38:    t43 = (unsigned char)0;

LAB39:    t16 = t43;

LAB27:    if (t16 == 1)
        goto LAB22;

LAB23:    t57 = (t0 + 2152U);
    t58 = *((char **)t57);
    t59 = (3 - 4);
    t60 = (t59 * -1);
    t61 = (1U * t60);
    t62 = (0 + t61);
    t57 = (t58 + t62);
    t63 = *((unsigned char *)t57);
    t64 = (t63 == (unsigned char)3);
    if (t64 == 1)
        goto LAB40;

LAB41:    t56 = (unsigned char)0;

LAB42:    t7 = t56;

LAB24:    if (t7 == 1)
        goto LAB19;

LAB20:    t74 = (t0 + 2152U);
    t75 = *((char **)t74);
    t76 = (4 - 4);
    t77 = (t76 * -1);
    t78 = (1U * t77);
    t79 = (0 + t78);
    t74 = (t75 + t79);
    t80 = *((unsigned char *)t74);
    t81 = (t80 == (unsigned char)3);
    if (t81 == 1)
        goto LAB43;

LAB44:    t73 = (unsigned char)0;

LAB45:    t3 = t73;

LAB21:    if (t3 != 0)
        goto LAB16;

LAB18:    xsi_set_current_line(157, ng0);
    t1 = (t0 + 5672);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);

LAB17:    goto LAB2;

LAB5:    xsi_set_current_line(160, ng0);
    t1 = (t0 + 5672);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB6:    xsi_set_current_line(162, ng0);
    t1 = (t0 + 5672);
    t2 = (t1 + 56U);
    t4 = *((char **)t2);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB7:    xsi_set_current_line(144, ng0);
    t11 = (t0 + 5672);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = (unsigned char)1;
    xsi_driver_first_trans_fast(t11);
    goto LAB8;

LAB10:    t8 = 0;

LAB13:    if (t8 < 11U)
        goto LAB14;
    else
        goto LAB12;

LAB14:    t9 = (t5 + t8);
    t10 = (t4 + t8);
    if (*((unsigned char *)t9) != *((unsigned char *)t10))
        goto LAB11;

LAB15:    t8 = (t8 + 1);
    goto LAB13;

LAB16:    xsi_set_current_line(155, ng0);
    t90 = (t0 + 5672);
    t91 = (t90 + 56U);
    t92 = *((char **)t91);
    t93 = (t92 + 56U);
    t94 = *((char **)t93);
    *((unsigned char *)t94) = (unsigned char)2;
    xsi_driver_first_trans_fast(t90);
    goto LAB17;

LAB19:    t3 = (unsigned char)1;
    goto LAB21;

LAB22:    t7 = (unsigned char)1;
    goto LAB24;

LAB25:    t16 = (unsigned char)1;
    goto LAB27;

LAB28:    t17 = (unsigned char)1;
    goto LAB30;

LAB31:    t4 = (t0 + 2312U);
    t5 = *((char **)t4);
    t24 = (0 - 4);
    t25 = (t24 * -1);
    t26 = (1U * t25);
    t27 = (0 + t26);
    t4 = (t5 + t27);
    t28 = *((unsigned char *)t4);
    t29 = (t28 == (unsigned char)3);
    t18 = t29;
    goto LAB33;

LAB34:    t10 = (t0 + 2312U);
    t11 = *((char **)t10);
    t37 = (1 - 4);
    t38 = (t37 * -1);
    t39 = (1U * t38);
    t40 = (0 + t39);
    t10 = (t11 + t40);
    t41 = *((unsigned char *)t10);
    t42 = (t41 == (unsigned char)3);
    t30 = t42;
    goto LAB36;

LAB37:    t14 = (t0 + 2312U);
    t15 = *((char **)t14);
    t50 = (2 - 4);
    t51 = (t50 * -1);
    t52 = (1U * t51);
    t53 = (0 + t52);
    t14 = (t15 + t53);
    t54 = *((unsigned char *)t14);
    t55 = (t54 == (unsigned char)3);
    t43 = t55;
    goto LAB39;

LAB40:    t65 = (t0 + 2312U);
    t66 = *((char **)t65);
    t67 = (3 - 4);
    t68 = (t67 * -1);
    t69 = (1U * t68);
    t70 = (0 + t69);
    t65 = (t66 + t70);
    t71 = *((unsigned char *)t65);
    t72 = (t71 == (unsigned char)3);
    t56 = t72;
    goto LAB42;

LAB43:    t82 = (t0 + 2312U);
    t83 = *((char **)t82);
    t84 = (4 - 4);
    t85 = (t84 * -1);
    t86 = (1U * t85);
    t87 = (0 + t86);
    t82 = (t83 + t87);
    t88 = *((unsigned char *)t82);
    t89 = (t88 == (unsigned char)3);
    t73 = t89;
    goto LAB45;

}


extern void work_a_2043985290_2030911003_init()
{
	static char *pe[] = {(void *)work_a_2043985290_2030911003_p_0,(void *)work_a_2043985290_2030911003_p_1,(void *)work_a_2043985290_2030911003_p_2,(void *)work_a_2043985290_2030911003_p_3};
	xsi_register_didat("work_a_2043985290_2030911003", "isim/masterbench_isim_beh.exe.sim/work/a_2043985290_2030911003.didat");
	xsi_register_executes(pe);
}
