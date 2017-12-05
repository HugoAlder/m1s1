<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_2(7:0)" />
        <signal name="XLXN_3(7:0)" />
        <signal name="switches(7:0)" />
        <signal name="leds(7:0)" />
        <port polarity="Input" name="switches(7:0)" />
        <port polarity="Output" name="leds(7:0)" />
        <blockdef name="obuf8">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
            <rect width="64" x="0" y="-44" height="24" />
            <rect width="96" x="128" y="-44" height="24" />
        </blockdef>
        <blockdef name="ibuf8">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <rect width="96" x="128" y="-44" height="24" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
        </blockdef>
        <block symbolname="ibuf8" name="XLXI_9">
            <blockpin signalname="switches(7:0)" name="I(7:0)" />
            <blockpin signalname="XLXN_3(7:0)" name="O(7:0)" />
        </block>
        <block symbolname="obuf8" name="XLXI_10">
            <blockpin signalname="XLXN_3(7:0)" name="I(7:0)" />
            <blockpin signalname="leds(7:0)" name="O(7:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1376" y="2384" name="XLXI_10" orien="R0" />
        <instance x="512" y="1296" name="XLXI_9" orien="R0" />
        <branch name="XLXN_3(7:0)">
            <wire x2="1128" y1="1264" y2="1264" x1="736" />
            <wire x2="1136" y1="1264" y2="1264" x1="1128" />
            <wire x2="1136" y1="1264" y2="2352" x1="1136" />
            <wire x2="1376" y1="2352" y2="2352" x1="1136" />
            <wire x2="1296" y1="1264" y2="1264" x1="1136" />
            <wire x2="1520" y1="1264" y2="1264" x1="1296" />
            <wire x2="1136" y1="2352" y2="2352" x1="848" />
        </branch>
        <branch name="switches(7:0)">
            <wire x2="512" y1="1264" y2="1264" x1="480" />
        </branch>
        <iomarker fontsize="28" x="480" y="1264" name="switches(7:0)" orien="R180" />
        <branch name="leds(7:0)">
            <wire x2="1632" y1="2352" y2="2352" x1="1600" />
        </branch>
        <iomarker fontsize="28" x="1632" y="2352" name="leds(7:0)" orien="R0" />
    </sheet>
</drawing>