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
static const char *ng0 = "/home/l3/alder/Documents/AEO/Nexys3V6/IPmul16.vhd";
extern char *IEEE_P_3620187407;



static void work_a_3734584229_3212880686_p_0(char *t0)
{
    char *t1;
    char *t3;
    char *t4;
    char *t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;

LAB0:    xsi_set_current_line(63, ng0);
    t1 = (t0 + 5406);
    t3 = (t0 + 5184U);
    t4 = (t0 + 1352U);
    t5 = *((char **)t4);
    t4 = (t0 + 5232U);
    t6 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t1, t3, t5, t4);
    if (t6 != 0)
        goto LAB3;

LAB4:
LAB5:    t13 = xsi_get_transient_memory(32U);
    memset(t13, 0, 32U);
    t14 = t13;
    memset(t14, (unsigned char)4, 32U);
    t15 = (t0 + 3344);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    memcpy(t19, t13, 32U);
    xsi_driver_first_trans_fast_port(t15);

LAB2:    t20 = (t0 + 3264);
    *((int *)t20) = 1;

LAB1:    return;
LAB3:    t7 = (t0 + 1672U);
    t8 = *((char **)t7);
    t7 = (t0 + 3344);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t8, 32U);
    xsi_driver_first_trans_fast_port(t7);
    goto LAB2;

LAB6:    goto LAB2;

}


extern void work_a_3734584229_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3734584229_3212880686_p_0};
	xsi_register_didat("work_a_3734584229_3212880686", "isim/masterbench_isim_beh.exe.sim/work/a_3734584229_3212880686.didat");
	xsi_register_executes(pe);
}
