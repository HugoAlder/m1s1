----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:48:46 10/13/2017 
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

entity display is
	PORT( clk : IN STD_LOGIC;
			btns : IN STD_LOGIC;
			sw : IN STD_LOGIC_VECTOR (7 downto 0);
			an : OUT STD_LOGIC_VECTOR (3 downto 0);
			seg : OUT STD_LOGIC_VECTOR (6 downto 0));
end display;

architecture Behavioral of display is
	COMPONENT clkdiv
	PORT(
		clk : IN std_logic;
		reset : IN std_logic;          
		E190 : OUT std_logic;
		clk190 : OUT std_logic
		);
	END COMPONENT;
	
	COMPONENT display_fsm
	PORT(
		data : IN std_logic_vector(15 downto 0);
		reset : IN std_logic;
		clk190 : IN std_logic;          
		anode : OUT std_logic_vector(3 downto 0);
		outp : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;
	
	COMPONENT x7seg
	PORT(
		sw : IN std_logic_vector(3 downto 0);          
		seg : OUT std_logic_vector(6 downto 0)
		);
	END COMPONENT;
	
	signal E190_s, clk190_s : STD_LOGIC;
	signal anode_s, data_s : STD_LOGIC_VECTOR (3 downto 0) := "0000";
begin
	
	Inst_clkdiv: clkdiv PORT MAP(
		clk => clk,
		reset => '0',
		E190 => E190_s,
		clk190 => clk190_s
	);
	
	Inst_display_fsm: display_fsm PORT MAP(
		data => sw,
		reset => btns,
		clk190 => clk190_s,
		anode => anode_s,
		outp => data_s
	);
	
	Inst_x7seg: x7seg PORT MAP(
		sw => data_s,
		seg => seg
	);
	
	an <= anode_s;

end Behavioral;
