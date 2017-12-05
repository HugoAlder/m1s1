----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:56:52 10/04/2017 
-- Design Name: 
-- Module Name:    fpd - Behavioral 
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


entity fpd is
GENERIC (init_value: STD_Logic := '0');
    Port ( d : in  STD_LOGIC;
           q : out  STD_LOGIC := init_value;
           clk : in  STD_LOGIC);
end fpd;

architecture Behavioral of fpd is

begin


end Behavioral;

