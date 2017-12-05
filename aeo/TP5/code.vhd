----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:48:00 10/11/2017 
-- Design Name: 
-- Module Name:    code - Behavioral 
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

entity code is
    Port ( switches : in  STD_LOGIC_VECTOR (7 downto 0);
           btn : in STD_LOGIC_VECTOR (4 downto 0);
			  clk : in std_logic;
           led : out STD_LOGIC_VECTOR (7 downto 0)
	 );
end code;

architecture Behavioral of code is
	signal val_btn: std_logic_vector(1 downto 0);
	signal btn_pressed: std_logic;
	
	--Insert the following in the architecture before the begin keyword
   --Use descriptive names for the states, like st1_reset, st2_search
   type state_type is (s1, s2, s3, s4, succ); 
   signal state, next_state : state_type; 
   --Declare internal signals for all outputs of the state-machine
   --signal output1 : std_logic;
	
	COMPONENT clkdiv
	PORT(
		clk : IN std_logic;
		reset : IN std_logic;          
		E190 : OUT std_logic;
		clk190 : OUT std_logic
		);
	END COMPONENT;
	
	
	COMPONENT btn_pulse
	PORT(
		inp : IN std_logic;
		enable : IN std_logic;
		clk : IN std_logic;          
		outp : OUT std_logic
		);
	END COMPONENT;
	
	signal enable : std_logic;
	signal btn_out : std_logic_vector (4 downto 0) := "00000";
	
begin

	Inst_clkdiv: clkdiv PORT MAP(
		clk => clk,
		reset => btn(4),
		E190 => enable,
		clk190 => open
	);
	
	btn_pulse_1: btn_pulse PORT MAP(
		inp => btn(0),
		enable => enable,
		clk => clk,
		outp => btn_out(0)
	);
	
	btn_pulse_2: btn_pulse PORT MAP(
		inp => btn(1),
		enable => enable,
		clk => clk,
		outp => btn_out(1)
	);
	
	btn_pulse_3: btn_pulse PORT MAP(
		inp => btn(2),
		enable => enable,
		clk => clk,
		outp => btn_out(2)
	);
	
	btn_pulse_4: btn_pulse PORT MAP(
		inp => btn(3),
		enable => enable,
		clk => clk,
		outp => btn_out(3)
	);

	led(2 downto 0) <= btn_pressed & val_btn;

	process (btn_out)
	begin
		case btn_out(3 downto 0) is
			when "0001" => val_btn <= "00";
								btn_pressed <= '1';
			when "0010" => val_btn <= "01";
								btn_pressed <= '1';
			when "0100" => val_btn <= "10";
								btn_pressed <= '1';
			when "1000" => val_btn <= "11";
								btn_pressed <= '1';
			when others => btn_pressed <= '0';
		end case;
	end process;

   SYNC_PROC: process (clk)
   begin
      if (clk'event and clk = '1') then
         if (btn(4) = '1') then
            state <= s1;
         elsif (btn_pressed = '0') then
            state <= next_state;
         end if;        
      end if;
   end process;
 
   --MOORE State-Machine - Outputs based on state only
   OUTPUT_DECODE: process (state)
   begin
      --insert statements to decode internal output signals
      --below is simple example
      if state = s1 then
			led(7 downto 3) <= "10000";
		elsif state = s2 then
			led(7 downto 3) <= "01000";
		elsif state = s3 then
			led(7 downto 3) <= "00100";
		elsif state = s4 then
			led(7 downto 3) <= "00010";
      else
         led(7 downto 3) <= "00001";
      end if;
   end process;
 
   NEXT_STATE_DECODE: process (state)
   begin
      --declare default state for next_state to avoid latches
      next_state <= state;  --default is to stay in current state
      --insert statements to decode next_state
      --below is a simple example		
		--if btn_pressed = '1' then
			case (state) is
				when s1 =>
					if val_btn = "00" then
						next_state <= s2;
					else
						next_state <= s1;
					end if;
				when s2 =>
					if val_btn = "01" then
						next_state <= s3;
					else
						next_state <= s1;					
					end if;
				when s3 =>
					if val_btn = "10" then
						next_state <= s4;
					else
						next_state <= s1;					
					end if;
				when others =>
					if val_btn = "11" then
						next_state <= succ;
					else
						next_state <= s1;					
					end if;
			end case;
		--end if;
   end process;

end Behavioral;
