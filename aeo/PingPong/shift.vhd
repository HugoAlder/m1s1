----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:21:34 10/04/2017 
-- Design Name: 
-- Module Name:    shift - Behavioral 
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

entity shift is
	port(
		btn: in std_logic_vector(4 downto 0);
		sw: in std_logic_vector(7 downto 0);
		clk: in std_logic;
		led: out std_logic_vector(7 downto 0)
	);
end shift;

architecture Behavioral of shift is
	COMPONENT fpd
	GENERIC (init_value: STD_Logic  := '0');
	PORT(
		d : IN std_logic;
		clk : IN std_logic;          
		q : OUT std_logic := init_value
		);
	END COMPONENT;
	
	COMPONENT clk_div
	PORT(
		clk : IN std_logic;          
		clk_4hz : OUT std_logic
		);
	END COMPONENT;
	
	SIGNAL q0, q1, q2, q3, q4, q5, q6, q7 : std_logic;
	SIGNAL longer_clk : std_logic;
begin
	Inst_clk_div: clk_div PORT MAP(
		clk => clk,
		clk_4hz => longer_clk
	);

	Inst_fpd0: fpd 
	GENERIC MAP(init_value => '1')
	PORT MAP(
		d => q7,
		q => q0,
		clk => longer_clk
	);
	
	Inst_fpd1: fpd 
	PORT MAP(
		d => q0,
		q => q1,
		clk => longer_clk
	);
	
	Inst_fpd2: fpd
	PORT MAP(
		d => q1,
		q => q2,
		clk => longer_clk
	);
	
	Inst_fpd3: fpd
	PORT MAP(
		d => q2,
		q => q3,
		clk => longer_clk
	);
	
	Inst_fpd4: fpd
	PORT MAP(
		d => q3,
		q => q4,
		clk => longer_clk
	);
	
	Inst_fpd5: fpd
	PORT MAP(
		d => q4,
		q => q5,
		clk => longer_clk
	);
	
	Inst_fpd6: fpd
	PORT MAP(
		d => q5,
		q => q6,
		clk => longer_clk
	);
	
	Inst_fpd7: fpd
	PORT MAP(
		d => q6,
		q => q7,
		clk => longer_clk
	);

	led <= q7 & q6 & q5 & q4 & q3 & q2 & q1 & q0;
end Behavioral;

