----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:19:00 10/13/2017 
-- Design Name: 
-- Module Name:    display - Behavioral 
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

entity display_fsm is
    Port ( data : in  STD_LOGIC_VECTOR (15 downto 0);
			  reset, clk190 : in STD_LOGIC;
           anode, outp : out STD_LOGIC_VECTOR (3 downto 0));
end display_fsm;

architecture Behavioral of display_fsm is

   type state_type is (digit_1, digit_2, digit_3, digit_4); 
   signal state, next_state : state_type; 
   signal out_i, anode_i : std_logic_vector (3 downto 0) := "0000";  
 
begin

   SYNC_PROC: process (clk190)
   begin
      if (clk190'event and clk190 = '1') then
         if (reset = '1') then
            state <= digit_1;
            anode <= "0000";
				outp <= "0000";
         else
            state <= next_state;
            anode <= anode_i;
				outp <= out_i;
         end if;        
      end if;
   end process;

   OUTPUT_DECODE: process (state, data)
   begin
		case state is
			when digit_1 =>
				out_i <= data(3 downto 0);
				anode_i <= "1110";
			when digit_2 =>
				out_i <= data(7 downto 4);
				anode_i <= "1101";
			when digit_3 =>
				out_i <= data(11 downto 8);
				anode_i <= "1011";
			when digit_4 =>
				out_i <= data(15 downto 12);
				anode_i <= "0111";
			when others =>
				out_i <= "0000";
				anode_i <= "0000";
		end case;
		
   end process;
 
   NEXT_STATE_DECODE: process (state)
   begin
      next_state <= state;
      case (state) is
         when digit_1 =>
				next_state <= digit_2;
         when digit_2 =>
            next_state <= digit_3;
         when digit_3 =>
            next_state <= digit_4;
			when digit_4 =>
				next_state <= digit_1;
         when others =>
            next_state <= digit_1;
      end case;      
   end process;

end Behavioral;
