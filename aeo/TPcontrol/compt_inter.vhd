----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:59:18 10/18/2017 
-- Design Name: 
-- Module Name:    compt_inter - Behavioral 
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
use IEEE.NUMERIC_std.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity compt_inter is

Port ( clk : IN STD_LOGIC;
		 outp : OUT STD_LOGIC_VECTOR (3 downto 0));
			  
end compt_inter;

architecture Behavioral of compt_inter is

begin

	process(clk)
		VARIABLE counter : unsigned(3 downto 0) := (others => '0');
		begin
		if (clk'event and clk = '1') then
			counter := counter + 1;
			outp <= counter;
		end if;
	end process;

end Behavioral;

