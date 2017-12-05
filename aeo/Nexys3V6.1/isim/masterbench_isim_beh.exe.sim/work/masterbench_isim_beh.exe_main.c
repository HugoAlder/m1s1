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

#include "xsi.h"

struct XSI_INFO xsi_info;

char *XILINXCORELIB_P_1837083571;
char *IEEE_P_2592010699;
char *STD_STANDARD;
char *IEEE_P_3620187407;
char *UNISIM_P_0947159679;
char *IEEE_P_3499444699;
char *IEEE_P_1242562249;
char *XILINXCORELIB_P_1705937335;
char *STD_TEXTIO;
char *IEEE_P_0774719531;
char *XILINXCORELIB_P_0718376120;
char *XILINXCORELIB_P_3155556343;
char *XILINXCORELIB_P_3381355550;
char *XILINXCORELIB_P_1433929353;
char *WORK_P_4079225897;
char *WORK_P_2431924499;
char *XILINXCORELIB_P_0624651749;


int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    std_textio_init();
    ieee_p_2592010699_init();
    ieee_p_3499444699_init();
    ieee_p_3620187407_init();
    ieee_p_0774719531_init();
    ieee_p_1242562249_init();
    work_p_4079225897_init();
    unisim_p_0947159679_init();
    work_p_2431924499_init();
    work_a_2958612305_3212880686_init();
    work_a_4234865043_3212880686_init();
    work_a_2452422755_3212880686_init();
    unisim_a_0350208134_1521797606_init();
    unisim_a_3055263662_1392679692_init();
    unisim_a_2661327437_0605893366_init();
    work_a_3138163414_3212880686_init();
    work_a_1136051149_3212880686_init();
    work_a_1492497583_3212880686_init();
    work_a_0737135909_3212880686_init();
    work_a_1279054538_3212880686_init();
    work_a_0535152851_1516540902_init();
    work_a_1556331924_1799128906_init();
    work_a_3743478949_3212880686_init();
    work_a_0673290681_3212880686_init();
    work_a_4124023227_3212880686_init();
    unisim_a_4147737283_2967259552_init();
    unisim_a_3762448000_2971575191_init();
    work_a_3555047783_3212880686_init();
    work_a_1734369168_3212880686_init();
    work_a_3152475931_3212880686_init();
    work_a_0124003922_0204290887_init();
    work_a_3532375871_0204290887_init();
    work_a_0264796693_0024109146_init();
    work_a_3326775529_3212880686_init();
    work_a_2790152726_3212880686_init();
    work_a_0690313384_3212880686_init();
    unisim_a_2312877582_0635394241_init();
    work_a_3795921498_3212880686_init();
    work_a_3427547875_0410308891_init();
    work_a_2043985290_2030911003_init();
    work_a_0886648295_2030911003_init();
    xilinxcorelib_p_0718376120_init();
    xilinxcorelib_p_1837083571_init();
    xilinxcorelib_p_3381355550_init();
    xilinxcorelib_p_1433929353_init();
    xilinxcorelib_p_3155556343_init();
    xilinxcorelib_p_0624651749_init();
    xilinxcorelib_a_1176612285_3212880686_init();
    xilinxcorelib_a_2518525174_3212880686_init();
    xilinxcorelib_a_0791441494_3212880686_init();
    work_a_0047244507_1692752377_init();
    xilinxcorelib_a_4268275752_3212880686_init();
    xilinxcorelib_a_3696541233_3212880686_init();
    work_a_3361092007_2372819840_init();
    work_a_0066810598_3899006464_init();
    work_a_0736105500_3212880686_init();
    work_a_2086890402_3212880686_init();
    work_a_4258046745_0410308891_init();
    work_a_3189010558_3212880686_init();
    work_a_3219098319_3212880686_init();
    work_a_4205237495_3212880686_init();
    xilinxcorelib_p_1705937335_init();
    xilinxcorelib_a_1231764273_3212880686_init();
    work_a_0295974560_3976424755_init();
    work_a_3734584229_3212880686_init();
    work_a_0939384457_3212880686_init();
    work_a_1492027647_2372691052_init();


    xsi_register_tops("work_a_1492027647_2372691052");

    XILINXCORELIB_P_1837083571 = xsi_get_engine_memory("xilinxcorelib_p_1837083571");
    IEEE_P_2592010699 = xsi_get_engine_memory("ieee_p_2592010699");
    xsi_register_ieee_std_logic_1164(IEEE_P_2592010699);
    STD_STANDARD = xsi_get_engine_memory("std_standard");
    IEEE_P_3620187407 = xsi_get_engine_memory("ieee_p_3620187407");
    UNISIM_P_0947159679 = xsi_get_engine_memory("unisim_p_0947159679");
    IEEE_P_3499444699 = xsi_get_engine_memory("ieee_p_3499444699");
    IEEE_P_1242562249 = xsi_get_engine_memory("ieee_p_1242562249");
    XILINXCORELIB_P_1705937335 = xsi_get_engine_memory("xilinxcorelib_p_1705937335");
    STD_TEXTIO = xsi_get_engine_memory("std_textio");
    IEEE_P_0774719531 = xsi_get_engine_memory("ieee_p_0774719531");
    XILINXCORELIB_P_0718376120 = xsi_get_engine_memory("xilinxcorelib_p_0718376120");
    XILINXCORELIB_P_3155556343 = xsi_get_engine_memory("xilinxcorelib_p_3155556343");
    XILINXCORELIB_P_3381355550 = xsi_get_engine_memory("xilinxcorelib_p_3381355550");
    XILINXCORELIB_P_1433929353 = xsi_get_engine_memory("xilinxcorelib_p_1433929353");
    WORK_P_4079225897 = xsi_get_engine_memory("work_p_4079225897");
    WORK_P_2431924499 = xsi_get_engine_memory("work_p_2431924499");
    XILINXCORELIB_P_0624651749 = xsi_get_engine_memory("xilinxcorelib_p_0624651749");

    return xsi_run_simulation(argc, argv);

}
