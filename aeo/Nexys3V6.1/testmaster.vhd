--                                                   
-- Description :  tstbench for UART 
-- 
-- ----------------------------------------------------------------------------------
-- Copyright : UNIVERSITE DE LILLE 1 - INRIA Lille Nord de France
--  Villeneuve d'Accsq France
-- 
-- Module Name  : Nexys3v6
-- Project Name : Homade V6
-- Revision :     IPcore timer
--                                         
-- Target Device :     spartan 6 spartan 3 virtex 7
-- Tool Version : tested on ISE 12.4,/14.7

-- Contributor(s) :
-- Dekeyser Jean-Luc ( Creation  juin 2012) jean-luc.dekeyser@univ_lille1.fr
-- 
-- 
-- Cecil Licence:
--
----------------------------------------------------------------------------------

  LIBRARY ieee;
  USE ieee.std_logic_1164.ALL;
  USE ieee.numeric_std.ALL;
  use IEEE.std_Logic_ARITH.ALL;

  ENTITY testbench IS
  END testbench;

  ARCHITECTURE behavior OF testbench IS 

   -- Component Declaration
          COMPONENT HMaster is
			Port 	(	clock: in std_logic;
					reset : in std_logic;
					Out32 :out std_logic_vector(15 downto 0);
					Out8:out std_logic_vector(7 downto 0);
					In8:in std_logic_vector(7 downto 0);
					InBtn : in std_logic_vector (4 downto 0);
					IT8 : in std_logic_vector (2 downto 0);
					kernel : out std_logic;
  --   clock Wrapper ============
			--   Master ============
              
              enb      : in STD_LOGIC;
				  data_WR : in STD_LOGIC ;
			--   Slaves ============
              data_S             : in     STD_LOGIC;
              wphase_S           : in     STD_LOGIC
					);

          END COMPONENT;

          SIGNAL mclk :  std_logic := '0';
signal master : std_logic :='1';
			 
  signal      rx_out:  std_logic;
  type rom_array is array (natural range <>) of std_logic_vector ( 63 downto 0 ) ;
constant  rom : rom_array := ( 
 --  master code 
 x"0c00_0000_0024_1c00", -- 0x0000
 x"1000_0000_0020_1c00", -- 0x0004
 x"1c00_0000_0000_1c00", -- 0x0008
 x"1c00_0000_0000_1c00", -- 0x000c
 x"1c00_0000_0000_1c00", -- 0x0010
 x"1c00_0000_0000_1c00", -- 0x0014
 x"0000_0000_0000_0000", -- 0x0018
 x"0000_0000_0000_0000", -- 0x001c
 x"2088_a003_1400_ffff", -- 0x0020
 x"20ff_a003_2fff_2fff", -- 0x0024
 x"c82d_2000_a007_a007", -- 0x0028
 x"8000_8806_a823_8007", -- 0x002c
 x"a833_a000_07fa_8006", -- 0x0030
 x"8006_03ef_1c00_ffff", -- 0x0034
 x"ffff_ffff_ffff_ffff", -- 0x0038
 --  slave code 
 x"1c00_ffff_ffff_ffff", -- 0x0000
 x"ffff_ffff_ffff_ffff"  -- 0x0004
);




signal count :integer := 0;

signal nb_master : integer :=0; 
signal nb_slave : integer :=0; 
signal nbit : integer :=0;
signal rstfsm : std_logic:='1';

signal data_buff : std_logic_vector (63 downto 0);
          signal btn   : STD_LOGIC_VECTOR (4 downto 0):="00000";
			 signal sw     : STD_LOGIC_VECTOR (7 downto 0):="10101010";
signal  finish : std_logic :='0';          
signal en, ens: std_logic :='0';
signal last: std_logic :='0';
signal rst : std_logic:='0';


  BEGIN




  -- Component Instantiation
uut: HMaster PORT MAP(
					clock => mclk,
					reset =>rst,
					Out32 => open,
					Out8=> open,
					In8=>sw ,
					InBtn =>btn,
  --   clock Wrapper ============
			--   Master ============
					it8=> "000",
					kernel=> open,
              enb      =>en ,
				  data_WR =>rx_out,
			--   Slaves ============
              data_S      =>rx_out,
              wphase_S     =>ens
      );
--
-- proc frequency  100 Mhz
--
clkin_process :process
   begin
		mclk <= '1';
		wait for 5 ns;
		mclk <= '0';
		wait for 5 ns;
   end process;

--nb_master <= conv_integer( rom (0)(31 downto 0) ) / 4 ; 
--nb_slave <= conv_integer( rom (conv_integer(nb_master) + 1 )(31 downto 0) ) / 4 ; 

process 
begin

rstfsm<='1';
wait for 30 ns;
rstfsm<='0';
wait for 1 ms;
finish <= '0' ;

end process;


btn <= "11111" after 2.3 us;

	


process (mclk)
begin
if rstfsm ='0' then 

	if mclk' event and mclk='1' then

		if finish ='0' then 
			if nbit = 0 then 
				data_buff <= rom (conv_integer(count));
				if rom (conv_integer(count))(63 downto 48 ) /= x"FFFF" then 
					rx_out <= rom (conv_integer(count))(0);
					if master='1' then 
						en<='1' ;
						ens<='0';
					else 
						ens<='1';
						en<='0';
					end if;
					nbit <= 1;	
				else
					if master ='1' then
						master <='0';
						en<='0';
						count<=count+1;
					else
						finish <= '1' ;
						ens<='0';
						en<='0';
						rst <= '0';

					end if;
					
				end if;

			else 
				rx_out <= data_buff(nbit);	
				
				nbit <= nbit+1;
				if nbit = 63 then 
					count<=count +1;
					nbit<= 0;
				end if;

			end if;
			rst<='1';
		else
			  rst <= '0'; 
		end if ;
	end if;


end if;
end process;
end;