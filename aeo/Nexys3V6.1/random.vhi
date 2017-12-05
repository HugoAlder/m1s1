
-- VHDL Instantiation Created from source file random.vhd -- 11:05:31 11/08/2017
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT random
	PORT(
		clk : IN std_logic;
		reset : IN std_logic;
		enable : IN std_logic;          
		random_num : OUT std_logic_vector(31 downto 0)
		);
	END COMPONENT;

	Inst_random: random PORT MAP(
		clk => ,
		reset => ,
		enable => ,
		random_num => 
	);


