--------------------------------------------------------------------------------
-- Copyright (c) 1995-2010 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 12.4
--  \   \         Application : sch2hdl
--  /   /         Filename : regfile.vhf
-- /___/   /\     Timestamp : 11/22/2017 09:49:11
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -sympath /home/l3/alder/Documents/AEO/Nexys3V6/ipcore_dir -intstyle ise -family spartan6 -flat -suppress -vhdl /home/l3/alder/Documents/AEO/Nexys3V6/regfile.vhf -w /home/l3/alder/Documents/AEO/Nexys3V6/regfile.sch
--Design Name: regfile
--Device: spartan6
--Purpose:
--    This vhdl netlist is translated from an ECS schematic. It can be 
--    synthesized and simulated, but it should not be modified. 
--
----- CELL D4_16E_HXILINX_regfile -----
  
library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity D4_16E_HXILINX_regfile is
  
port(
    D0  : out std_logic;
    D1  : out std_logic;
    D2  : out std_logic;
    D3  : out std_logic;
    D4  : out std_logic;
    D5  : out std_logic;
    D6  : out std_logic;
    D7  : out std_logic;
    D8  : out std_logic;
    D9  : out std_logic;
    D10  : out std_logic;
    D11  : out std_logic;
    D12  : out std_logic;
    D13  : out std_logic;
    D14  : out std_logic;
    D15  : out std_logic;

    A0  : in std_logic;
    A1  : in std_logic;
    A2  : in std_logic;
    A3  : in std_logic;
    E   : in std_logic
  );
end D4_16E_HXILINX_regfile;

architecture D4_16E_HXILINX_regfile_V of D4_16E_HXILINX_regfile is
  signal d_tmp : std_logic_vector(15 downto 0);
begin
  process (A0, A1, A2, A3, E)
  variable sel   : std_logic_vector(3 downto 0);
  begin
    sel := A3&A2&A1&A0;
    if( E = '0') then
    d_tmp <= "0000000000000000";
    else
      case sel is
      when "0000" => d_tmp <= "0000000000000001";
      when "0001" => d_tmp <= "0000000000000010";
      when "0010" => d_tmp <= "0000000000000100";
      when "0011" => d_tmp <= "0000000000001000";
      when "0100" => d_tmp <= "0000000000010000";
      when "0101" => d_tmp <= "0000000000100000";
      when "0110" => d_tmp <= "0000000001000000";
      when "0111" => d_tmp <= "0000000010000000";
      when "1000" => d_tmp <= "0000000100000000";
      when "1001" => d_tmp <= "0000001000000000";
      when "1010" => d_tmp <= "0000010000000000";
      when "1011" => d_tmp <= "0000100000000000";
      when "1100" => d_tmp <= "0001000000000000";
      when "1101" => d_tmp <= "0010000000000000";
      when "1110" => d_tmp <= "0100000000000000";
      when "1111" => d_tmp <= "1000000000000000";
      when others => NULL;
      end case;
    end if;
  end process; 

    D15 <= d_tmp(15);
    D14 <= d_tmp(14);
    D13 <= d_tmp(13);
    D12 <= d_tmp(12);
    D11 <= d_tmp(11);
    D10 <= d_tmp(10);
    D9  <= d_tmp(9);
    D8  <= d_tmp(8);
    D7  <= d_tmp(7);
    D6  <= d_tmp(6);
    D5  <= d_tmp(5);
    D4  <= d_tmp(4);
    D3  <= d_tmp(3);
    D2  <= d_tmp(2);
    D1  <= d_tmp(1);
    D0  <= d_tmp(0);

end D4_16E_HXILINX_regfile_V;

library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity regfile is
   port ( clk    : in    std_logic; 
          Nreg   : in    std_logic_vector (2 downto 0); 
          Rstore : in    std_logic_vector (31 downto 0); 
          store  : in    std_logic; 
          Rload  : out   std_logic_vector (31 downto 0));
end regfile;

architecture BEHAVIORAL of regfile is
   attribute HU_SET     : string ;
   attribute BOX_TYPE   : string ;
   signal XLXN_7  : std_logic_vector (31 downto 0);
   signal XLXN_8  : std_logic_vector (31 downto 0);
   signal XLXN_9  : std_logic_vector (31 downto 0);
   signal XLXN_10 : std_logic_vector (31 downto 0);
   signal XLXN_11 : std_logic_vector (31 downto 0);
   signal XLXN_12 : std_logic_vector (31 downto 0);
   signal XLXN_13 : std_logic_vector (31 downto 0);
   signal XLXN_14 : std_logic_vector (31 downto 0);
   signal XLXN_15 : std_logic_vector (31 downto 0);
   signal XLXN_16 : std_logic_vector (31 downto 0);
   signal XLXN_44 : std_logic;
   signal XLXN_49 : std_logic;
   signal XLXN_50 : std_logic;
   signal XLXN_51 : std_logic;
   signal XLXN_52 : std_logic;
   signal XLXN_53 : std_logic;
   signal XLXN_54 : std_logic;
   signal XLXN_55 : std_logic;
   signal XLXN_56 : std_logic;
   component mux2x32
      port ( sel : in    std_logic; 
             X0  : in    std_logic_vector (31 downto 0); 
             X1  : in    std_logic_vector (31 downto 0); 
             Y   : out   std_logic_vector (31 downto 0));
   end component;
   
   component Mux4
      port ( X0  : in    std_logic_vector (31 downto 0); 
             X1  : in    std_logic_vector (31 downto 0); 
             X2  : in    std_logic_vector (31 downto 0); 
             X3  : in    std_logic_vector (31 downto 0); 
             sel : in    std_logic_vector (1 downto 0); 
             Y   : out   std_logic_vector (31 downto 0));
   end component;
   
   component QDE_1
      port ( E   : in    std_logic; 
             clk : in    std_logic; 
             d   : in    std_logic_vector (31 downto 0); 
             q   : out   std_logic_vector (31 downto 0));
   end component;
   
   component D4_16E_HXILINX_regfile
      port ( A0  : in    std_logic; 
             A1  : in    std_logic; 
             A2  : in    std_logic; 
             A3  : in    std_logic; 
             E   : in    std_logic; 
             D0  : out   std_logic; 
             D1  : out   std_logic; 
             D10 : out   std_logic; 
             D11 : out   std_logic; 
             D12 : out   std_logic; 
             D13 : out   std_logic; 
             D14 : out   std_logic; 
             D15 : out   std_logic; 
             D2  : out   std_logic; 
             D3  : out   std_logic; 
             D4  : out   std_logic; 
             D5  : out   std_logic; 
             D6  : out   std_logic; 
             D7  : out   std_logic; 
             D8  : out   std_logic; 
             D9  : out   std_logic);
   end component;
   
   component VCC
      port ( P : out   std_logic);
   end component;
   attribute BOX_TYPE of VCC : component is "BLACK_BOX";
   
   attribute HU_SET of XLXI_27 : label is "XLXI_27_4";
begin
   mux2 : mux2x32
      port map (sel=>Nreg(2),
                X0(31 downto 0)=>XLXN_15(31 downto 0),
                X1(31 downto 0)=>XLXN_16(31 downto 0),
                Y(31 downto 0)=>Rload(31 downto 0));
   
   mux40 : Mux4
      port map (sel(1 downto 0)=>Nreg(1 downto 0),
                X0(31 downto 0)=>XLXN_7(31 downto 0),
                X1(31 downto 0)=>XLXN_8(31 downto 0),
                X2(31 downto 0)=>XLXN_9(31 downto 0),
                X3(31 downto 0)=>XLXN_10(31 downto 0),
                Y(31 downto 0)=>XLXN_15(31 downto 0));
   
   mux41 : Mux4
      port map (sel(1 downto 0)=>Nreg(1 downto 0),
                X0(31 downto 0)=>XLXN_11(31 downto 0),
                X1(31 downto 0)=>XLXN_12(31 downto 0),
                X2(31 downto 0)=>XLXN_13(31 downto 0),
                X3(31 downto 0)=>XLXN_14(31 downto 0),
                Y(31 downto 0)=>XLXN_16(31 downto 0));
   
   R0 : QDE_1
      port map (clk=>clk,
                d(31 downto 0)=>Rstore(31 downto 0),
                E=>XLXN_49,
                q(31 downto 0)=>XLXN_7(31 downto 0));
   
   R1 : QDE_1
      port map (clk=>clk,
                d(31 downto 0)=>Rstore(31 downto 0),
                E=>XLXN_50,
                q(31 downto 0)=>XLXN_8(31 downto 0));
   
   R2 : QDE_1
      port map (clk=>clk,
                d(31 downto 0)=>Rstore(31 downto 0),
                E=>XLXN_51,
                q(31 downto 0)=>XLXN_9(31 downto 0));
   
   R3 : QDE_1
      port map (clk=>clk,
                d(31 downto 0)=>Rstore(31 downto 0),
                E=>XLXN_52,
                q(31 downto 0)=>XLXN_10(31 downto 0));
   
   R4 : QDE_1
      port map (clk=>clk,
                d(31 downto 0)=>Rstore(31 downto 0),
                E=>XLXN_53,
                q(31 downto 0)=>XLXN_11(31 downto 0));
   
   R5 : QDE_1
      port map (clk=>clk,
                d(31 downto 0)=>Rstore(31 downto 0),
                E=>XLXN_54,
                q(31 downto 0)=>XLXN_12(31 downto 0));
   
   R6 : QDE_1
      port map (clk=>clk,
                d(31 downto 0)=>Rstore(31 downto 0),
                E=>XLXN_55,
                q(31 downto 0)=>XLXN_13(31 downto 0));
   
   R7 : QDE_1
      port map (clk=>clk,
                d(31 downto 0)=>Rstore(31 downto 0),
                E=>XLXN_56,
                q(31 downto 0)=>XLXN_14(31 downto 0));
   
   XLXI_27 : D4_16E_HXILINX_regfile
      port map (A0=>store,
                A1=>Nreg(0),
                A2=>Nreg(1),
                A3=>Nreg(2),
                E=>XLXN_44,
                D0=>open,
                D1=>XLXN_49,
                D2=>open,
                D3=>XLXN_50,
                D4=>open,
                D5=>XLXN_51,
                D6=>open,
                D7=>XLXN_52,
                D8=>open,
                D9=>XLXN_53,
                D10=>open,
                D11=>XLXN_54,
                D12=>open,
                D13=>XLXN_55,
                D14=>open,
                D15=>XLXN_56);
   
   XLXI_28 : VCC
      port map (P=>XLXN_44);
   
end BEHAVIORAL;


