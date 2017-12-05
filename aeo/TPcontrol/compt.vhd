----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:51:26 10/18/2017 
-- Design Name: 
-- Module Name:    compt - Behavioral 
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

entity compt is
    Port ( clk : IN STD_LOGIC;
			  an : OUT STD_LOGIC_VECTOR (3 downto 0);
			  seg : OUT STD_LOGIC_VECTOR (6 downto 0));
end compt;

architecture Behavioral of compt is
	
	COMPONENT clk_div
	PORT(
		clk : IN std_logic;          
		clk_100hz : OUT std_logic
		);
	END COMPONENT;
	
	COMPONENT compt_inter
	PORT(
		clk : IN std_logic;          
		outp : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;
	
	COMPONENT x7seg
	PORT(
		sw : IN std_logic_vector(3 downto 0);          
		seg : OUT std_logic_vector(6 downto 0)
		);
	END COMPONENT;
	
	SIGNAL longer_clk : std_logic;
	SIGNAL data : std_logic_vector(3 downto 0);
	
begin

	Inst_clk_div: clk_div PORT MAP(
		clk => clk,
		clk_100hz => longer_clk
	);
	
	Inst_compt_inter: compt_inter PORT MAP(
		clk => longer_clk,
		outp => data
	);
	
	Inst_x7seg: x7seg PORT MAP(
		sw => data,
		seg => seg
	);
	
	an <= "0001";
	
end Behavioral;

