--                                                   
-- Description :  FF QD
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

library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity QD is
	 generic(N : integer := 32);
	 port(
		 d : in STD_LOGIC_VECTOR(N-1 downto 0);
		 clk : in STD_LOGIC;
		 q : out STD_LOGIC_VECTOR(N-1 downto 0)
	     );

		attribute clock_signal : string;
	attribute clock_signal of clk : signal is "yes";
end QD;
architecture QD of QD is
begin
	process(clk)
	begin
	if clk'event   and clk = '1' then
			q <= d;
	end if;						 
	end process;
end QD;