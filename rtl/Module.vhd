library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity Module is
port
(    
    IN_1 : in std_logic;
    IN_2 : in std_logic;
    OUT_1 : out std_logic
);
end Module;

architecture rtl of Module is

    constant delay : integer := 25000000; -- Generate 1s after 25M risign edges
    signal count : integer := 0;
    signal button_temp : std_logic := '0';

    begin

    process(clock)
    begin
        if rising_edge(clock) then
            if (button_in /= button_temp) then -- if not equal
                button_temp <= button_in;
                count <= 0;
            elsif (count = delay) then
                button_out <= button_temp;
            else
                count <= count + 1;
					 button_out <= '0'; -- To avoid high debouncing signals output must be keept as low on idle
            end if;
        end if;
    end process;

end rtl;