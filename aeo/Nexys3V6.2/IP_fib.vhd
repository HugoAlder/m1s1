----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:27:11 11/22/2017 
-- Design Name: 
-- Module Name:    IP_fib - Behavioral 
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


entity IP_fibo is
generic ( mycode : STD_LOGIC_VECTOR (10 downto 0):= "10000000011");
   port ( 
		clk : in  STD_LOGIC;
		reset : in  STD_LOGIC:='0';
		Tin : in  STD_LOGIC_VECTOR (31 downto 0);
		Tout : out  STD_LOGIC_VECTOR (31 downto 0);
		Ipcode : in  STD_LOGIC_VECTOR (10 downto 0); 
		IPdone : out STD_LOGIC
	);
end IP_fibo;

architecture fibo of IP_fibo is
	type state_type is (idle, starting, finished); 
   signal state, next_state : state_type; 
	
   signal IPdone_i, init_i : std_logic := 'Z';
	signal Tout_i, fibobus : std_logic_vector (31 downto 0) := (others => 'Z');
	signal compt, compt_i : std_logic_vector (7 downto 0) := (others => 'Z');

	COMPONENT fibogen
	PORT(
		clk : IN std_logic;
		init : IN std_logic;          
		fiboout : OUT std_logic_vector(31 downto 0)
		);
	END COMPONENT;
begin

	Inst_fibogen: fibogen PORT MAP(
		clk => clk,
		init => init_i,
		fiboout => fibobus
	);

	--Insert the following in the architecture after the begin keyword
   SYNC_PROC: process (clk)
   begin
      if (clk'event and clk = '1') then
         if (reset = '1') then
            state <= idle;
         else
            state <= next_state;
				compt <= compt_i;
         end if;
      end if;
   end process;
 
   --MOORE State-Machine - Outputs based on state only
   OUTPUT_DECODE: process (state)
   begin
      if state = finished then
			IPdone_i <= '1';
         Tout_i <= fibobus;
		elsif state = idle then
			init_i <= '1';
			IPdone_i <= '0';
			Tout_i <= (others => '0');
      else
			IPdone_i <= '0';
			init_i <= '0';
         Tout_i <= (others => '0');
      end if;
   end process;
 
   NEXT_STATE_DECODE: process (state, Ipcode, compt)
   begin
      next_state <= state;
      case (state) is
         when idle =>
            if mycode = Ipcode then
               next_state <= starting;
					compt_i <= Tin(7 downto 0) - 2;
            end if;
         when starting =>
            if compt = x"00" then
               next_state <= finished;
				else
					compt_i <= compt - 1;
            end if;
         when finished =>
            next_state <= idle;
			when others =>
            next_state <= idle;
      end case;      
   end process;

   IPdone <= '1' when IPdone_i = '1' else '0';
   Tout <= Tout_i when IPdone_i = '1' else ( others=>'Z');
end fibo;

