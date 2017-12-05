----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:57:22 10/04/2017 
-- Design Name: 
-- Module Name:    pingpong - Behavioral 
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

entity pingpong is
	port(
		btn: in std_logic_vector(4 downto 0);
		switches: in std_logic_vector(7 downto 0);
		clk: in std_logic;
		led: out std_logic_vector(7 downto 0)
	);
end pingpong;

architecture Behavioral of pingpong is
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
		variable left : std_logic := '1';
		variable temp : std_logic_vector (7 downto 0) := "00000001";
	begin
		if (longer_clk'event and longer_clk='1') then
			if (left = '1') then
				temp := temp(6 downto 0) & temp(7);
				led <= temp;
			else
				temp := temp(0) & temp(7 downto 1);
				led <= temp;
			end if;
		
			if (temp(7) = '1') then
				left := '0';
			elsif (temp(0) = '1') then
				left := '1';
			else
				for i in 0 to 7 loop
					if (switches(i) = '1' and temp(i) = '1') then
						left := not left;
					end if;
				end loop;
			end if;
		end if;
	end process;
end Behavioral;
