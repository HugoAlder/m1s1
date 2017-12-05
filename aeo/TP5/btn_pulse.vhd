----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16:41:41 10/11/2016 
-- Design Name: 
-- Module Name:    btn_pulse - Behavioral 
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

entity btn_pulse is
	port ( inp : in std_logic;
			 enable : in std_logic;
			 clk : in std_logic;
			 outp : out std_logic
			);
end btn_pulse;

architecture Behavioral of btn_pulse is
	signal q0 : std_logic := '0';
	signal q1 : std_logic := '0';
	signal q2 : std_logic := '0';
	signal q3 : std_logic := '0';
	signal q4 : std_logic := '0';
	signal q5 : std_logic := '0';
	signal o1 : std_logic := '0';
begin
	o1 <= q0 and q1 and q2 ;
	outp <= q3 and q4 and not q5;

	process (clk)
	begin
		if clk'event and clk ='1' then
			if enable = '1' then
				q2 <= q1;
				q1 <= q0;
				q0 <= inp;
			end if;
			q5 <= q4;
			q4 <= q3;
			q3 <= o1;
		end if;
		
	end process;
end Behavioral;