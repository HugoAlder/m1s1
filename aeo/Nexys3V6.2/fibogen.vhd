----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:12:12 11/22/2017 
-- Design Name: 
-- Module Name:    fibogen - Behavioral 
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
use ieee.std_logic_unsigned.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity fibogen is
    Port ( clk      : in  STD_LOGIC;
           init     : in  STD_LOGIC;
           fiboout  : out STD_LOGIC_VECTOR (31 downto 0));
 
 attribute clock_signal : string;
 attribute clock_signal of clk : signal is "yes";
end fibogen;

architecture Behavioral of fibogen is
	signal fib, fib2 : std_logic_vector (31 downto 0);
begin

	process(clk)
		variable tmp : std_logic_vector (31 downto 0);
	begin
		if (clk'event and clk = '1') then
			if (init = '1') then
				fib <= x"00000001";
				fib2 <= x"00000001";
			else
				tmp := fib2;
				fib2 <= fib + fib2;
				fib <= tmp;
			end if;
		end if;
	end process;

	fiboout <= fib2;

end Behavioral;

