----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    08:57:57 10/11/2017 
-- Design Name: 
-- Module Name:    ex1 - Behavioral 
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

entity ex1 is 
	port (clk, reset :in std_logic);
end ex1;

architecture Behavioral of ex1 is

--Insert the following in the architecture before the begin keyword
   --Use descriptive names for the states, like st1_reset, st2_search
   type state_type is (s1, s2, s3); 
   signal state, next_state : state_type; 
   --Declare internal signals for all outputs of the state-machine
   signal output_1 : std_logic;
	signal output_2 : std_logic;

begin

--Insert the following in the architecture after the begin keyword
   SYNC_PROC: process (clk)
   begin
      if (clk'event and clk = '1') then
         if (reset = '1') then
            state <= s1;
            output_1 <= '1';
			elsif (s2 = '1') then
				state <= s2;
				output_2 <= '0';
         else
            state <= next_state;
         -- assign other outputs to internal signals
         end if;        
      end if;
   end process;
 
   --MOORE State-Machine - Outputs based on state only
   OUTPUT_DECODE: process (state)
   begin
      --insert statements to decode internal output signals
      --below is simple example
      if state = s1 then
         output_1 <= '1';
			output_2 <= '1';
		else
			output_1 <= '0';
         output_2 <= '0';
      end if;
   end process;
 
   NEXT_STATE_DECODE: process (state, s1, s2, s3)
   begin
      --declare default state for next_state to avoid latches
      next_state <= state;  --default is to stay in current state
      --insert statements to decode next_state
      --below is a simple example
      case (state) is
         when s1 =>
            if s1 = '1' then
               next_state <= s2;
            end if;
         when s2 =>
            if s2 = '0' then
               next_state <= s3;
            end if;
         when s3 =>
            next_state <= s1;
         when others =>
            next_state <= s1;
      end case;      
   end process;
end Behavioral;

