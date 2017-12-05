----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:57:22 10/04/2017 
-- Design Name: 
-- Module Name:    shift2 - Behavioral 
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
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity shift2 is
	port(
		btn: in std_logic_vector(4 downto 0);
		sw: in std_logic_vector(7 downto 0);
		clk: in std_logic;
		led: out std_logic_vector(7 downto 0)
	);
end shift2;

architecture Behavioral of shift2 is
	COMPONENT clk_div
	PORT(
		clk : IN std_logic;          
		clk_4hz : OUT std_logic
		);
	END COMPONENT;
	
	SIGNAL longer_clk : std_logic;
begin
	Inst_clk_div: clk_div PORT MAP(
		clk => clk,
		clk_4hz => longer_clk
	);
	
	process (longer_clk)
		variable temp : std_logic_vector (7 downto 0) := "00000001";
	begin
		if (longer_clk'event and longer_clk='1') then
			temp := temp(6 downto 0) & temp(7);
			led <= temp;
		end if;
	end process;
end Behavioral;

