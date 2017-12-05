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
static const char *ng0 = "/home/l3/alder/Documents/AEO/Nexys3V6/Hmaster.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_3488546069778340532_503743352(char *, unsigned char , unsigned char );


static void work_a_0939384457_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    unsigned char t8;
    unsigned char t9;
    char *t10;
    unsigned char t11;
    unsigned char t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;

LAB0:    xsi_set_current_line(921, ng0);

LAB3:    t1 = (t0 + 10976U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 10816U);
    t4 = *((char **)t1);
    t5 = *((unsigned char *)t4);
    t6 = ieee_p_2592010699_sub_3488546069778340532_503743352(IEEE_P_2592010699, t3, t5);
    t1 = (t0 + 11136U);
    t7 = *((char **)t1);
    t8 = *((unsigned char *)t7);
    t9 = ieee_p_2592010699_sub_3488546069778340532_503743352(IEEE_P_2592010699, t6, t8);
    t1 = (t0 + 11296U);
    t10 = *((char **)t1);
    t11 = *((unsigned char *)t10);
    t12 = ieee_p_2592010699_sub_3488546069778340532_503743352(IEEE_P_2592010699, t9, t11);
    t1 = (t0 + 19072);
    t13 = (t1 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    *((unsigned char *)t16) = t12;
    xsi_driver_first_trans_fast(t1);

LAB2:    t17 = (t0 + 18976);
    *((int *)t17) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_0939384457_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;

LAB0:    xsi_set_current_line(595, ng0);

LAB3:    t1 = (t0 + 4096U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 16416U);
    t4 = *((char **)t1);
    t5 = *((unsigned char *)t4);
    t6 = ieee_p_2592010699_sub_3488546069778340532_503743352(IEEE_P_2592010699, t3, t5);
    t1 = (t0 + 19136);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = t6;
    xsi_driver_first_trans_fast(t1);

LAB2:    t11 = (t0 + 18992);
    *((int *)t11) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_0939384457_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0939384457_3212880686_p_0,(void *)work_a_0939384457_3212880686_p_1};
	xsi_register_didat("work_a_0939384457_3212880686", "isim/masterbench_isim_beh.exe.sim/work/a_0939384457_3212880686.didat");
	xsi_register_executes(pe);
}
