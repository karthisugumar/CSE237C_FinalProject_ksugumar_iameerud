-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2019.1
-- Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity flatten is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    in_r_address0 : OUT STD_LOGIC_VECTOR (8 downto 0);
    in_r_ce0 : OUT STD_LOGIC;
    in_r_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
    out_r_address0 : OUT STD_LOGIC_VECTOR (8 downto 0);
    out_r_ce0 : OUT STD_LOGIC;
    out_r_we0 : OUT STD_LOGIC;
    out_r_d0 : OUT STD_LOGIC_VECTOR (31 downto 0) );
end;


architecture behav of flatten is 
    attribute CORE_GENERATION_INFO : STRING;
    attribute CORE_GENERATION_INFO of behav : architecture is
    "flatten,hls_ip_2019_1,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=1,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7z020-clg400-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=6.508000,HLS_SYN_LAT=993,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=90,HLS_SYN_LUT=258,HLS_VERSION=2019_1}";
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (4 downto 0) := "00001";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (4 downto 0) := "00010";
    constant ap_ST_fsm_state3 : STD_LOGIC_VECTOR (4 downto 0) := "00100";
    constant ap_ST_fsm_state4 : STD_LOGIC_VECTOR (4 downto 0) := "01000";
    constant ap_ST_fsm_state5 : STD_LOGIC_VECTOR (4 downto 0) := "10000";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv32_2 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000010";
    constant ap_const_lv32_3 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000011";
    constant ap_const_lv32_4 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000100";
    constant ap_const_lv5_0 : STD_LOGIC_VECTOR (4 downto 0) := "00000";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv9_0 : STD_LOGIC_VECTOR (8 downto 0) := "000000000";
    constant ap_const_lv3_0 : STD_LOGIC_VECTOR (2 downto 0) := "000";
    constant ap_const_lv5_10 : STD_LOGIC_VECTOR (4 downto 0) := "10000";
    constant ap_const_lv5_1 : STD_LOGIC_VECTOR (4 downto 0) := "00001";
    constant ap_const_lv9_19 : STD_LOGIC_VECTOR (8 downto 0) := "000011001";
    constant ap_const_lv2_0 : STD_LOGIC_VECTOR (1 downto 0) := "00";
    constant ap_const_lv3_5 : STD_LOGIC_VECTOR (2 downto 0) := "101";
    constant ap_const_lv3_1 : STD_LOGIC_VECTOR (2 downto 0) := "001";
    constant ap_const_lv9_5 : STD_LOGIC_VECTOR (8 downto 0) := "000000101";
    constant ap_const_lv9_1 : STD_LOGIC_VECTOR (8 downto 0) := "000000001";
    constant ap_const_boolean_1 : BOOLEAN := true;

    signal ap_CS_fsm : STD_LOGIC_VECTOR (4 downto 0) := "00001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal ifm_fu_156_p2 : STD_LOGIC_VECTOR (4 downto 0);
    signal ifm_reg_275 : STD_LOGIC_VECTOR (4 downto 0);
    signal ap_CS_fsm_state2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state2 : signal is "none";
    signal idx_fu_162_p2 : STD_LOGIC_VECTOR (8 downto 0);
    signal idx_reg_280 : STD_LOGIC_VECTOR (8 downto 0);
    signal icmp_ln9_fu_150_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal add_ln12_3_fu_184_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal add_ln12_3_reg_285 : STD_LOGIC_VECTOR (7 downto 0);
    signal r_fu_196_p2 : STD_LOGIC_VECTOR (2 downto 0);
    signal r_reg_293 : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_CS_fsm_state3 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state3 : signal is "none";
    signal add_ln12_fu_202_p2 : STD_LOGIC_VECTOR (8 downto 0);
    signal add_ln12_reg_298 : STD_LOGIC_VECTOR (8 downto 0);
    signal icmp_ln10_fu_190_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal add_ln12_5_fu_229_p2 : STD_LOGIC_VECTOR (9 downto 0);
    signal add_ln12_5_reg_303 : STD_LOGIC_VECTOR (9 downto 0);
    signal c_fu_241_p2 : STD_LOGIC_VECTOR (2 downto 0);
    signal c_reg_311 : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_CS_fsm_state4 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state4 : signal is "none";
    signal icmp_ln11_fu_235_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal add_ln12_1_fu_261_p2 : STD_LOGIC_VECTOR (8 downto 0);
    signal ap_CS_fsm_state5 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state5 : signal is "none";
    signal ifm_0_reg_83 : STD_LOGIC_VECTOR (4 downto 0);
    signal idx_0_reg_94 : STD_LOGIC_VECTOR (8 downto 0);
    signal idx_1_reg_106 : STD_LOGIC_VECTOR (8 downto 0);
    signal r_0_reg_117 : STD_LOGIC_VECTOR (2 downto 0);
    signal idx_2_reg_128 : STD_LOGIC_VECTOR (8 downto 0);
    signal c_0_reg_139 : STD_LOGIC_VECTOR (2 downto 0);
    signal zext_ln12_6_fu_256_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln12_3_fu_267_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal tmp_2_fu_172_p3 : STD_LOGIC_VECTOR (6 downto 0);
    signal zext_ln12_fu_168_p1 : STD_LOGIC_VECTOR (7 downto 0);
    signal zext_ln12_1_fu_180_p1 : STD_LOGIC_VECTOR (7 downto 0);
    signal zext_ln12_2_fu_208_p1 : STD_LOGIC_VECTOR (7 downto 0);
    signal add_ln12_4_fu_212_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal zext_ln12_4_fu_217_p1 : STD_LOGIC_VECTOR (9 downto 0);
    signal p_shl1_cast_fu_221_p3 : STD_LOGIC_VECTOR (9 downto 0);
    signal zext_ln12_5_fu_247_p1 : STD_LOGIC_VECTOR (9 downto 0);
    signal add_ln12_6_fu_251_p2 : STD_LOGIC_VECTOR (9 downto 0);
    signal ap_NS_fsm : STD_LOGIC_VECTOR (4 downto 0);


begin




    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_CS_fsm <= ap_ST_fsm_state1;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;


    c_0_reg_139_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
                c_0_reg_139 <= c_reg_311;
            elsif (((icmp_ln10_fu_190_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
                c_0_reg_139 <= ap_const_lv3_0;
            end if; 
        end if;
    end process;

    idx_0_reg_94_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln10_fu_190_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
                idx_0_reg_94 <= idx_reg_280;
            elsif (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then 
                idx_0_reg_94 <= ap_const_lv9_0;
            end if; 
        end if;
    end process;

    idx_1_reg_106_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln11_fu_235_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state4))) then 
                idx_1_reg_106 <= add_ln12_reg_298;
            elsif (((icmp_ln9_fu_150_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
                idx_1_reg_106 <= idx_0_reg_94;
            end if; 
        end if;
    end process;

    idx_2_reg_128_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
                idx_2_reg_128 <= add_ln12_1_fu_261_p2;
            elsif (((icmp_ln10_fu_190_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
                idx_2_reg_128 <= idx_1_reg_106;
            end if; 
        end if;
    end process;

    ifm_0_reg_83_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln10_fu_190_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
                ifm_0_reg_83 <= ifm_reg_275;
            elsif (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then 
                ifm_0_reg_83 <= ap_const_lv5_0;
            end if; 
        end if;
    end process;

    r_0_reg_117_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln11_fu_235_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state4))) then 
                r_0_reg_117 <= r_reg_293;
            elsif (((icmp_ln9_fu_150_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
                r_0_reg_117 <= ap_const_lv3_0;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln9_fu_150_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                add_ln12_3_reg_285 <= add_ln12_3_fu_184_p2;
                idx_reg_280 <= idx_fu_162_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln10_fu_190_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state3))) then
                add_ln12_5_reg_303 <= add_ln12_5_fu_229_p2;
                add_ln12_reg_298 <= add_ln12_fu_202_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state4)) then
                c_reg_311 <= c_fu_241_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state2)) then
                ifm_reg_275 <= ifm_fu_156_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state3)) then
                r_reg_293 <= r_fu_196_p2;
            end if;
        end if;
    end process;

    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, ap_CS_fsm_state1, ap_CS_fsm_state2, icmp_ln9_fu_150_p2, ap_CS_fsm_state3, icmp_ln10_fu_190_p2, ap_CS_fsm_state4, icmp_ln11_fu_235_p2)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                if (((icmp_ln9_fu_150_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                    ap_NS_fsm <= ap_ST_fsm_state1;
                else
                    ap_NS_fsm <= ap_ST_fsm_state3;
                end if;
            when ap_ST_fsm_state3 => 
                if (((icmp_ln10_fu_190_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state4;
                end if;
            when ap_ST_fsm_state4 => 
                if (((icmp_ln11_fu_235_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state4))) then
                    ap_NS_fsm <= ap_ST_fsm_state3;
                else
                    ap_NS_fsm <= ap_ST_fsm_state5;
                end if;
            when ap_ST_fsm_state5 => 
                ap_NS_fsm <= ap_ST_fsm_state4;
            when others =>  
                ap_NS_fsm <= "XXXXX";
        end case;
    end process;
    add_ln12_1_fu_261_p2 <= std_logic_vector(unsigned(idx_2_reg_128) + unsigned(ap_const_lv9_1));
    add_ln12_3_fu_184_p2 <= std_logic_vector(unsigned(zext_ln12_fu_168_p1) + unsigned(zext_ln12_1_fu_180_p1));
    add_ln12_4_fu_212_p2 <= std_logic_vector(unsigned(add_ln12_3_reg_285) + unsigned(zext_ln12_2_fu_208_p1));
    add_ln12_5_fu_229_p2 <= std_logic_vector(unsigned(zext_ln12_4_fu_217_p1) + unsigned(p_shl1_cast_fu_221_p3));
    add_ln12_6_fu_251_p2 <= std_logic_vector(unsigned(add_ln12_5_reg_303) + unsigned(zext_ln12_5_fu_247_p1));
    add_ln12_fu_202_p2 <= std_logic_vector(unsigned(idx_1_reg_106) + unsigned(ap_const_lv9_5));
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state2 <= ap_CS_fsm(1);
    ap_CS_fsm_state3 <= ap_CS_fsm(2);
    ap_CS_fsm_state4 <= ap_CS_fsm(3);
    ap_CS_fsm_state5 <= ap_CS_fsm(4);

    ap_done_assign_proc : process(ap_CS_fsm_state2, icmp_ln9_fu_150_p2)
    begin
        if (((icmp_ln9_fu_150_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_assign_proc : process(ap_start, ap_CS_fsm_state1)
    begin
        if (((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    ap_ready_assign_proc : process(ap_CS_fsm_state2, icmp_ln9_fu_150_p2)
    begin
        if (((icmp_ln9_fu_150_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

    c_fu_241_p2 <= std_logic_vector(unsigned(c_0_reg_139) + unsigned(ap_const_lv3_1));
    icmp_ln10_fu_190_p2 <= "1" when (r_0_reg_117 = ap_const_lv3_5) else "0";
    icmp_ln11_fu_235_p2 <= "1" when (c_0_reg_139 = ap_const_lv3_5) else "0";
    icmp_ln9_fu_150_p2 <= "1" when (ifm_0_reg_83 = ap_const_lv5_10) else "0";
    idx_fu_162_p2 <= std_logic_vector(unsigned(idx_0_reg_94) + unsigned(ap_const_lv9_19));
    ifm_fu_156_p2 <= std_logic_vector(unsigned(ifm_0_reg_83) + unsigned(ap_const_lv5_1));
    in_r_address0 <= zext_ln12_6_fu_256_p1(9 - 1 downto 0);

    in_r_ce0_assign_proc : process(ap_CS_fsm_state4)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state4)) then 
            in_r_ce0 <= ap_const_logic_1;
        else 
            in_r_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    out_r_address0 <= zext_ln12_3_fu_267_p1(9 - 1 downto 0);

    out_r_ce0_assign_proc : process(ap_CS_fsm_state5)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
            out_r_ce0 <= ap_const_logic_1;
        else 
            out_r_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    out_r_d0 <= in_r_q0;

    out_r_we0_assign_proc : process(ap_CS_fsm_state5)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
            out_r_we0 <= ap_const_logic_1;
        else 
            out_r_we0 <= ap_const_logic_0;
        end if; 
    end process;

    p_shl1_cast_fu_221_p3 <= (add_ln12_4_fu_212_p2 & ap_const_lv2_0);
    r_fu_196_p2 <= std_logic_vector(unsigned(r_0_reg_117) + unsigned(ap_const_lv3_1));
    tmp_2_fu_172_p3 <= (ifm_0_reg_83 & ap_const_lv2_0);
    zext_ln12_1_fu_180_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tmp_2_fu_172_p3),8));
    zext_ln12_2_fu_208_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(r_0_reg_117),8));
    zext_ln12_3_fu_267_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(idx_2_reg_128),64));
    zext_ln12_4_fu_217_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln12_4_fu_212_p2),10));
    zext_ln12_5_fu_247_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(c_0_reg_139),10));
    zext_ln12_6_fu_256_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln12_6_fu_251_p2),64));
    zext_ln12_fu_168_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(ifm_0_reg_83),8));
end behav;
