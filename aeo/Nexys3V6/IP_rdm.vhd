----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:03:07 11/08/2017 
-- Design Name: 
-- Module Name:    IP_rdm - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_unsigned.all;
use IEEE.std_logic_arith.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity IP_Rdm is
GENERIC (Mycode : std_logic_vector(10 downto 0) := "00000010000"); 
	port (
		clk , reset : in std_logic; 
		ipcode : in std_logic_vector (10 downto 0);
		Tout : out std_logic_vector (31 downto 0);
		Nout : out std_logic_vector (31 downto 0)
	);
end IP_Rdm;

architecture Behavioral of IP_rdm is

signal qbus : std_logic_vector(31 downto 0) ;
signal en : std_logic;

	COMPONENT random
	PORT(
		clk : IN std_logic;
		reset : IN std_logic;
		enable : IN std_logic;          
		random_num : OUT std_logic_vector(31 downto 0)
		);
	END COMPONENT;

begin

	Inst_random: random PORT MAP(
		clk => clk,
		reset => reset,
		enable => en,
		random_num => qbus
	);
	
	en <= '1' when ipcode(10 downto 0)= Mycode else '0';
	Tout <= ("00000000000000000000" & qbus(11 downto 0)) when ipcode(10 downto 0)= Mycode else (others =>'Z');
	Nout <= ("00000000000000000000" & qbus(23 downto 12)) when ipcode(10 downto 0)= Mycode else (others =>'Z');
end Behavioral;
