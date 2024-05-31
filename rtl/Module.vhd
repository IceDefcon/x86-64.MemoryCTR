library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity Module is
port
(    
    CLOCK : in std_logic; -- 50MHz Clock
    RESET : in std_logic;
    
    INTERRUPT : in std_logic;
    OUT : out std_logic
);
end Module;

architecture rtl of Module is

    constant test_constant_1 : integer := 1000;
    
    signal test_signal : std_logic := '0';
    signal test_interrupt : std_logic := '0';

    signal test_timer : std_logic_vector(25 downto 0) := (others => '0');

    type TEST is 
    (
        IDLE,
        INIT,
        CONFIG,
        COMPUTE,
        DONE
    );
    signal test_state: TEST := IDLE;

    begin

    state_machine_process:
    process(CLOCK, RESET, test_interrupt, test_timer, test_state)
    begin
        if rising_edge(CLOCK) then

            test_interrupt <= INTERRUPT;

            if(RESET = '1') then
                test_signal <= '0';
                test_timer <= (others => '0');
                test_state <= IDLE;
            else
                case test_state is
                    when IDLE =>
                        if test_interrupt = '1' then
                            test_state <= INIT;
                        else
                            test_state <= IDLE;
                        end if;

                    when INIT =>
                        if test_timer = "10111110101111000010000000" then
                            test_state <= CONFIG;
                            test_timer <= (others => '0');
                        else
                            test_state <= INIT;
                            test_timer <= test_timer + '1';
                        end if;

                    when CONFIG =>
                        test_state <= PRODUCE;

                    when COMPUTE =>
                        ------------------
                        -- Compute output 
                        -- test signal
                        ------------------
                        test_state <= DONE;

                    when DONE =>
                        test_state <= IDLE;

                    when others =>
                        test_state <= IDLE;

                end case;

                OUT_SIGNAL <= test_signal;

            end if;
        end if;
    end process;

end rtl;