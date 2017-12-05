----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:13:27 10/18/2017 
-- Design Name: 
-- Module Name:    question1 - Behavioral 
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

entity question1 is
	PORT(	sw : IN STD_LOGIC_VECTOR (7 downto 0);
			an : OUT STD_LOGIC_VECTOR (3 downto 0);
			seg : OUT STD_LOGIC_VECTOR (6 downto 0));
end question1;

architecture Behavioral of question1 is

begin


end Behavioral;

