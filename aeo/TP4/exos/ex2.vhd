----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:42:22 10/04/2017 
-- Design Name: 
-- Module Name:    ex2 - Behavioral 
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all; 

entity C16b is 
port (  clk,raz :in std_logic;
			qs : out std_logic_vector(15 downto 0) );
end C16b; 

architecture aC16b of C16b is 
	signal q : std_logic_vector(15 downto 0);  
	begin 

	qs <= q; 

	process(clk) 
	begin 
		if clk'event and clk='1' then
			if raz='1' then
				q<=(others=>'0');
			else
				q<=q+1;
			end if;
		end if;
	end process; 
end aC16b;

