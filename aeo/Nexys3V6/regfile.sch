<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="virtex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="Rstore(31:0)" />
        <signal name="clk" />
        <signal name="XLXN_7(31:0)" />
        <signal name="XLXN_8(31:0)" />
        <signal name="XLXN_9(31:0)" />
        <signal name="XLXN_10(31:0)" />
        <signal name="XLXN_11(31:0)" />
        <signal name="XLXN_12(31:0)" />
        <signal name="XLXN_13(31:0)" />
        <signal name="XLXN_14(31:0)" />
        <signal name="XLXN_15(31:0)" />
        <signal name="XLXN_16(31:0)" />
        <signal name="Rload(31:0)" />
        <signal name="Nreg(2:0)" />
        <signal name="store" />
        <signal name="Nreg(2)" />
        <signal name="Nreg(1:0)" />
        <signal name="Nreg(1)" />
        <signal name="Nreg(0)" />
        <signal name="XLXN_44" />
        <signal name="XLXN_49" />
        <signal name="XLXN_50" />
        <signal name="XLXN_51" />
        <signal name="XLXN_52" />
        <signal name="XLXN_53" />
        <signal name="XLXN_54" />
        <signal name="XLXN_55" />
        <signal name="XLXN_56" />
        <port polarity="Input" name="Rstore(31:0)" />
        <port polarity="Input" name="clk" />
        <port polarity="Output" name="Rload(31:0)" />
        <port polarity="Input" name="Nreg(2:0)" />
        <port polarity="Input" name="store" />
        <blockdef name="Mux4">
            <timestamp>2013-9-26T9:27:57</timestamp>
            <rect width="256" x="64" y="-320" height="320" />
            <rect width="64" x="0" y="-300" height="24" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <rect width="64" x="0" y="-236" height="24" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <rect width="64" x="0" y="-172" height="24" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-300" height="24" />
            <line x2="384" y1="-288" y2="-288" x1="320" />
        </blockdef>
        <blockdef name="d4_16e">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <rect width="256" x="64" y="-1152" height="1088" />
            <line x2="320" y1="-1088" y2="-1088" x1="384" />
            <line x2="320" y1="-1024" y2="-1024" x1="384" />
            <line x2="320" y1="-960" y2="-960" x1="384" />
            <line x2="320" y1="-896" y2="-896" x1="384" />
            <line x2="320" y1="-832" y2="-832" x1="384" />
            <line x2="320" y1="-768" y2="-768" x1="384" />
            <line x2="320" y1="-704" y2="-704" x1="384" />
            <line x2="320" y1="-640" y2="-640" x1="384" />
            <line x2="320" y1="-576" y2="-576" x1="384" />
            <line x2="320" y1="-512" y2="-512" x1="384" />
            <line x2="320" y1="-448" y2="-448" x1="384" />
            <line x2="320" y1="-384" y2="-384" x1="384" />
            <line x2="320" y1="-320" y2="-320" x1="384" />
            <line x2="320" y1="-256" y2="-256" x1="384" />
            <line x2="320" y1="-192" y2="-192" x1="384" />
            <line x2="320" y1="-128" y2="-128" x1="384" />
            <line x2="64" y1="-896" y2="-896" x1="0" />
            <line x2="64" y1="-960" y2="-960" x1="0" />
            <line x2="64" y1="-1024" y2="-1024" x1="0" />
            <line x2="64" y1="-1088" y2="-1088" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
        </blockdef>
        <blockdef name="vcc">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-64" x1="64" />
            <line x2="64" y1="0" y2="-32" x1="64" />
            <line x2="32" y1="-64" y2="-64" x1="96" />
        </blockdef>
        <blockdef name="QDE_1">
            <timestamp>2014-4-18T8:36:27</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-172" height="24" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
        </blockdef>
        <blockdef name="mux2x32">
            <timestamp>2014-4-18T9:52:21</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-172" height="24" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
        </blockdef>
        <block symbolname="Mux4" name="mux40">
            <blockpin signalname="XLXN_7(31:0)" name="X0(31:0)" />
            <blockpin signalname="XLXN_8(31:0)" name="X1(31:0)" />
            <blockpin signalname="XLXN_9(31:0)" name="X2(31:0)" />
            <blockpin signalname="XLXN_10(31:0)" name="X3(31:0)" />
            <blockpin signalname="Nreg(1:0)" name="sel(1:0)" />
            <blockpin signalname="XLXN_15(31:0)" name="Y(31:0)" />
        </block>
        <block symbolname="Mux4" name="mux41">
            <blockpin signalname="XLXN_11(31:0)" name="X0(31:0)" />
            <blockpin signalname="XLXN_12(31:0)" name="X1(31:0)" />
            <blockpin signalname="XLXN_13(31:0)" name="X2(31:0)" />
            <blockpin signalname="XLXN_14(31:0)" name="X3(31:0)" />
            <blockpin signalname="Nreg(1:0)" name="sel(1:0)" />
            <blockpin signalname="XLXN_16(31:0)" name="Y(31:0)" />
        </block>
        <block symbolname="d4_16e" name="XLXI_27">
            <blockpin signalname="store" name="A0" />
            <blockpin signalname="Nreg(0)" name="A1" />
            <blockpin signalname="Nreg(1)" name="A2" />
            <blockpin signalname="Nreg(2)" name="A3" />
            <blockpin signalname="XLXN_44" name="E" />
            <blockpin name="D0" />
            <blockpin signalname="XLXN_49" name="D1" />
            <blockpin name="D10" />
            <blockpin signalname="XLXN_54" name="D11" />
            <blockpin name="D12" />
            <blockpin signalname="XLXN_55" name="D13" />
            <blockpin name="D14" />
            <blockpin signalname="XLXN_56" name="D15" />
            <blockpin name="D2" />
            <blockpin signalname="XLXN_50" name="D3" />
            <blockpin name="D4" />
            <blockpin signalname="XLXN_51" name="D5" />
            <blockpin name="D6" />
            <blockpin signalname="XLXN_52" name="D7" />
            <blockpin name="D8" />
            <blockpin signalname="XLXN_53" name="D9" />
        </block>
        <block symbolname="vcc" name="XLXI_28">
            <blockpin signalname="XLXN_44" name="P" />
        </block>
        <block symbolname="QDE_1" name="R0">
            <blockpin signalname="XLXN_49" name="E" />
            <blockpin signalname="clk" name="clk" />
            <blockpin signalname="Rstore(31:0)" name="d(31:0)" />
            <blockpin signalname="XLXN_7(31:0)" name="q(31:0)" />
        </block>
        <block symbolname="QDE_1" name="R1">
            <blockpin signalname="XLXN_50" name="E" />
            <blockpin signalname="clk" name="clk" />
            <blockpin signalname="Rstore(31:0)" name="d(31:0)" />
            <blockpin signalname="XLXN_8(31:0)" name="q(31:0)" />
        </block>
        <block symbolname="QDE_1" name="R2">
            <blockpin signalname="XLXN_51" name="E" />
            <blockpin signalname="clk" name="clk" />
            <blockpin signalname="Rstore(31:0)" name="d(31:0)" />
            <blockpin signalname="XLXN_9(31:0)" name="q(31:0)" />
        </block>
        <block symbolname="QDE_1" name="R3">
            <blockpin signalname="XLXN_52" name="E" />
            <blockpin signalname="clk" name="clk" />
            <blockpin signalname="Rstore(31:0)" name="d(31:0)" />
            <blockpin signalname="XLXN_10(31:0)" name="q(31:0)" />
        </block>
        <block symbolname="QDE_1" name="R4">
            <blockpin signalname="XLXN_53" name="E" />
            <blockpin signalname="clk" name="clk" />
            <blockpin signalname="Rstore(31:0)" name="d(31:0)" />
            <blockpin signalname="XLXN_11(31:0)" name="q(31:0)" />
        </block>
        <block symbolname="QDE_1" name="R5">
            <blockpin signalname="XLXN_54" name="E" />
            <blockpin signalname="clk" name="clk" />
            <blockpin signalname="Rstore(31:0)" name="d(31:0)" />
            <blockpin signalname="XLXN_12(31:0)" name="q(31:0)" />
        </block>
        <block symbolname="QDE_1" name="R6">
            <blockpin signalname="XLXN_55" name="E" />
            <blockpin signalname="clk" name="clk" />
            <blockpin signalname="Rstore(31:0)" name="d(31:0)" />
            <blockpin signalname="XLXN_13(31:0)" name="q(31:0)" />
        </block>
        <block symbolname="QDE_1" name="R7">
            <blockpin signalname="XLXN_56" name="E" />
            <blockpin signalname="clk" name="clk" />
            <blockpin signalname="Rstore(31:0)" name="d(31:0)" />
            <blockpin signalname="XLXN_14(31:0)" name="q(31:0)" />
        </block>
        <block symbolname="mux2x32" name="mux2">
            <blockpin signalname="Nreg(2)" name="sel" />
            <blockpin signalname="XLXN_15(31:0)" name="X0(31:0)" />
            <blockpin signalname="XLXN_16(31:0)" name="X1(31:0)" />
            <blockpin signalname="Rload(31:0)" name="Y(31:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="Rstore(31:0)">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="816" y="464" type="branch" />
            <wire x2="816" y1="224" y2="352" x1="816" />
            <wire x2="1456" y1="352" y2="352" x1="816" />
            <wire x2="816" y1="352" y2="464" x1="816" />
            <wire x2="816" y1="464" y2="624" x1="816" />
            <wire x2="1456" y1="624" y2="624" x1="816" />
            <wire x2="816" y1="624" y2="896" x1="816" />
            <wire x2="1456" y1="896" y2="896" x1="816" />
            <wire x2="816" y1="896" y2="1168" x1="816" />
            <wire x2="816" y1="1168" y2="1440" x1="816" />
            <wire x2="1456" y1="1440" y2="1440" x1="816" />
            <wire x2="816" y1="1440" y2="1712" x1="816" />
            <wire x2="1456" y1="1712" y2="1712" x1="816" />
            <wire x2="816" y1="1712" y2="1984" x1="816" />
            <wire x2="816" y1="1984" y2="2256" x1="816" />
            <wire x2="1456" y1="2256" y2="2256" x1="816" />
            <wire x2="1456" y1="1984" y2="1984" x1="816" />
            <wire x2="1456" y1="1168" y2="1168" x1="816" />
        </branch>
        <branch name="clk">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="752" y="176" type="branch" />
            <wire x2="752" y1="96" y2="176" x1="752" />
            <wire x2="752" y1="176" y2="288" x1="752" />
            <wire x2="752" y1="288" y2="560" x1="752" />
            <wire x2="752" y1="560" y2="832" x1="752" />
            <wire x2="752" y1="832" y2="1104" x1="752" />
            <wire x2="752" y1="1104" y2="1376" x1="752" />
            <wire x2="752" y1="1376" y2="1648" x1="752" />
            <wire x2="752" y1="1648" y2="1920" x1="752" />
            <wire x2="752" y1="1920" y2="2192" x1="752" />
            <wire x2="1456" y1="2192" y2="2192" x1="752" />
            <wire x2="1456" y1="1920" y2="1920" x1="752" />
            <wire x2="1456" y1="1648" y2="1648" x1="752" />
            <wire x2="1456" y1="1376" y2="1376" x1="752" />
            <wire x2="1456" y1="1104" y2="1104" x1="752" />
            <wire x2="1456" y1="832" y2="832" x1="752" />
            <wire x2="1456" y1="560" y2="560" x1="752" />
            <wire x2="1456" y1="288" y2="288" x1="752" />
        </branch>
        <instance x="2208" y="864" name="mux40" orien="R0">
        </instance>
        <instance x="2224" y="1952" name="mux41" orien="R0">
        </instance>
        <branch name="XLXN_7(31:0)">
            <wire x2="2016" y1="224" y2="224" x1="1840" />
            <wire x2="2016" y1="224" y2="576" x1="2016" />
            <wire x2="2208" y1="576" y2="576" x1="2016" />
        </branch>
        <branch name="XLXN_8(31:0)">
            <wire x2="2000" y1="496" y2="496" x1="1840" />
            <wire x2="2000" y1="496" y2="640" x1="2000" />
            <wire x2="2208" y1="640" y2="640" x1="2000" />
        </branch>
        <branch name="XLXN_9(31:0)">
            <wire x2="2016" y1="768" y2="768" x1="1840" />
            <wire x2="2016" y1="704" y2="768" x1="2016" />
            <wire x2="2208" y1="704" y2="704" x1="2016" />
        </branch>
        <branch name="XLXN_10(31:0)">
            <wire x2="2032" y1="1040" y2="1040" x1="1840" />
            <wire x2="2032" y1="768" y2="1040" x1="2032" />
            <wire x2="2208" y1="768" y2="768" x1="2032" />
        </branch>
        <branch name="XLXN_11(31:0)">
            <wire x2="2032" y1="1312" y2="1312" x1="1840" />
            <wire x2="2032" y1="1312" y2="1664" x1="2032" />
            <wire x2="2224" y1="1664" y2="1664" x1="2032" />
        </branch>
        <branch name="XLXN_12(31:0)">
            <wire x2="2016" y1="1584" y2="1584" x1="1840" />
            <wire x2="2016" y1="1584" y2="1728" x1="2016" />
            <wire x2="2224" y1="1728" y2="1728" x1="2016" />
        </branch>
        <branch name="XLXN_13(31:0)">
            <wire x2="2016" y1="1856" y2="1856" x1="1840" />
            <wire x2="2016" y1="1792" y2="1856" x1="2016" />
            <wire x2="2224" y1="1792" y2="1792" x1="2016" />
        </branch>
        <branch name="XLXN_14(31:0)">
            <wire x2="2048" y1="2128" y2="2128" x1="1840" />
            <wire x2="2048" y1="1856" y2="2128" x1="2048" />
            <wire x2="2224" y1="1856" y2="1856" x1="2048" />
        </branch>
        <branch name="XLXN_15(31:0)">
            <wire x2="2608" y1="576" y2="576" x1="2592" />
            <wire x2="2608" y1="576" y2="1152" x1="2608" />
            <wire x2="2816" y1="1152" y2="1152" x1="2608" />
        </branch>
        <branch name="XLXN_16(31:0)">
            <wire x2="2624" y1="1664" y2="1664" x1="2608" />
            <wire x2="2816" y1="1216" y2="1216" x1="2624" />
            <wire x2="2624" y1="1216" y2="1664" x1="2624" />
        </branch>
        <branch name="Rload(31:0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="3296" y="1088" type="branch" />
            <wire x2="3296" y1="1088" y2="1088" x1="3200" />
            <wire x2="3312" y1="1088" y2="1088" x1="3296" />
        </branch>
        <branch name="Nreg(2:0)">
            <wire x2="16" y1="240" y2="624" x1="16" />
            <wire x2="16" y1="624" y2="688" x1="16" />
            <wire x2="16" y1="688" y2="752" x1="16" />
            <wire x2="16" y1="752" y2="800" x1="16" />
        </branch>
        <branch name="store">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="144" y="368" type="branch" />
            <wire x2="144" y1="192" y2="368" x1="144" />
            <wire x2="144" y1="368" y2="560" x1="144" />
            <wire x2="224" y1="560" y2="560" x1="144" />
        </branch>
        <instance x="224" y="1648" name="XLXI_27" orien="R0" />
        <branch name="Nreg(2:0)">
            <attrtext style="alignment:SOFT-RIGHT;fontsize:28;fontname:Arial" attrname="Name" x="2000" y="96" type="branch" />
            <wire x2="2112" y1="96" y2="96" x1="2000" />
            <wire x2="2800" y1="96" y2="96" x1="2112" />
            <wire x2="2960" y1="96" y2="96" x1="2800" />
        </branch>
        <bustap x2="2112" y1="96" y2="192" x1="2112" />
        <branch name="Nreg(1:0)">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2112" y="336" type="branch" />
            <wire x2="2112" y1="192" y2="336" x1="2112" />
            <wire x2="2112" y1="336" y2="832" x1="2112" />
            <wire x2="2208" y1="832" y2="832" x1="2112" />
            <wire x2="2112" y1="832" y2="1920" x1="2112" />
            <wire x2="2224" y1="1920" y2="1920" x1="2112" />
        </branch>
        <bustap x2="2800" y1="96" y2="192" x1="2800" />
        <branch name="Nreg(2)">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2800" y="624" type="branch" />
            <wire x2="2800" y1="192" y2="624" x1="2800" />
            <wire x2="2800" y1="624" y2="1088" x1="2800" />
            <wire x2="2816" y1="1088" y2="1088" x1="2800" />
        </branch>
        <iomarker fontsize="28" x="16" y="240" name="Nreg(2:0)" orien="R270" />
        <iomarker fontsize="28" x="752" y="96" name="clk" orien="R270" />
        <iomarker fontsize="28" x="144" y="192" name="store" orien="R270" />
        <bustap x2="112" y1="752" y2="752" x1="16" />
        <branch name="Nreg(2)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="168" y="752" type="branch" />
            <wire x2="176" y1="752" y2="752" x1="112" />
            <wire x2="224" y1="752" y2="752" x1="176" />
        </branch>
        <bustap x2="112" y1="688" y2="688" x1="16" />
        <branch name="Nreg(1)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="168" y="688" type="branch" />
            <wire x2="176" y1="688" y2="688" x1="112" />
            <wire x2="224" y1="688" y2="688" x1="176" />
        </branch>
        <bustap x2="112" y1="624" y2="624" x1="16" />
        <branch name="Nreg(0)">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="168" y="624" type="branch" />
            <wire x2="176" y1="624" y2="624" x1="112" />
            <wire x2="224" y1="624" y2="624" x1="176" />
        </branch>
        <branch name="XLXN_44">
            <wire x2="224" y1="1520" y2="1520" x1="192" />
        </branch>
        <instance x="192" y="1584" name="XLXI_28" orien="R270" />
        <instance x="1456" y="384" name="R0" orien="R0">
        </instance>
        <instance x="1456" y="656" name="R1" orien="R0">
        </instance>
        <instance x="1456" y="928" name="R2" orien="R0">
        </instance>
        <instance x="1456" y="1200" name="R3" orien="R0">
        </instance>
        <instance x="1456" y="1472" name="R4" orien="R0">
        </instance>
        <instance x="1456" y="1744" name="R5" orien="R0">
        </instance>
        <instance x="1456" y="2288" name="R7" orien="R0">
        </instance>
        <instance x="1456" y="2016" name="R6" orien="R0">
        </instance>
        <iomarker fontsize="28" x="816" y="224" name="Rstore(31:0)" orien="R270" />
        <branch name="XLXN_49">
            <wire x2="672" y1="624" y2="624" x1="608" />
            <wire x2="672" y1="624" y2="688" x1="672" />
            <wire x2="912" y1="688" y2="688" x1="672" />
            <wire x2="912" y1="224" y2="688" x1="912" />
            <wire x2="1456" y1="224" y2="224" x1="912" />
        </branch>
        <branch name="XLXN_50">
            <wire x2="1024" y1="752" y2="752" x1="608" />
            <wire x2="1024" y1="496" y2="752" x1="1024" />
            <wire x2="1456" y1="496" y2="496" x1="1024" />
        </branch>
        <branch name="XLXN_51">
            <wire x2="1024" y1="880" y2="880" x1="608" />
            <wire x2="1024" y1="768" y2="880" x1="1024" />
            <wire x2="1456" y1="768" y2="768" x1="1024" />
        </branch>
        <branch name="XLXN_52">
            <wire x2="1024" y1="1008" y2="1008" x1="608" />
            <wire x2="1024" y1="1008" y2="1040" x1="1024" />
            <wire x2="1456" y1="1040" y2="1040" x1="1024" />
        </branch>
        <branch name="XLXN_53">
            <wire x2="1024" y1="1136" y2="1136" x1="608" />
            <wire x2="1024" y1="1136" y2="1312" x1="1024" />
            <wire x2="1456" y1="1312" y2="1312" x1="1024" />
        </branch>
        <branch name="XLXN_54">
            <wire x2="1008" y1="1264" y2="1264" x1="608" />
            <wire x2="1008" y1="1264" y2="1584" x1="1008" />
            <wire x2="1456" y1="1584" y2="1584" x1="1008" />
        </branch>
        <branch name="XLXN_55">
            <wire x2="1024" y1="1392" y2="1392" x1="608" />
            <wire x2="1024" y1="1392" y2="1856" x1="1024" />
            <wire x2="1456" y1="1856" y2="1856" x1="1024" />
        </branch>
        <branch name="XLXN_56">
            <wire x2="992" y1="1520" y2="1520" x1="608" />
            <wire x2="992" y1="1520" y2="2128" x1="992" />
            <wire x2="1456" y1="2128" y2="2128" x1="992" />
        </branch>
        <instance x="2816" y="1248" name="mux2" orien="R0">
        </instance>
        <iomarker fontsize="28" x="3312" y="1088" name="Rload(31:0)" orien="R0" />
    </sheet>
</drawing>