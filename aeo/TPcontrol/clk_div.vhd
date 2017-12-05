----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:29:28 10/04/2017 
-- Design Name: 
-- Module Name:    clk_div - Behavioral 
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

entity clk_div is
	port(
		clk: in std_logic;
		clk_100hz: out std_logic
	);
end clk_div;

architecture Behavioral of clk_div is
	signal tmp : std_logic := '1';
begin
	process(clk)
		variable counter : unsigned(23 downto 0) := (others => '0');
		
	begin
		if (clk'event and clk='1') then
			counter := counter + 1;
			if (counter = 500000) then
				tmp <= not tmp;
				counter := (others => '0');
			end if;
		end if;
	end process;
	clk_100hz <= tmp;
end Behavioral;
