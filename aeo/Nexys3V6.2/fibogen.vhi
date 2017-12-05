
-- VHDL Instantiation Created from source file fibogen.vhd -- 10:39:52 11/22/2017
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT fibogen
	PORT(
		clk : IN std_logic;
		init : IN std_logic;          
		fiboout : OUT std_logic_vector(31 downto 0)
		);
	END COMPONENT;

	Inst_fibogen: fibogen PORT MAP(
		clk => ,
		init => ,
		fiboout => 
	);


