<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="6.5.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="50" name="dxf" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="53" name="tGND_GNDA" color="7" fill="9" visible="no" active="no"/>
<layer number="54" name="bGND_GNDA" color="1" fill="9" visible="no" active="no"/>
<layer number="56" name="wert" color="7" fill="1" visible="no" active="no"/>
<layer number="57" name="tCAD" color="7" fill="1" visible="no" active="no"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="100" name="Muster" color="7" fill="1" visible="yes" active="yes"/>
<layer number="101" name="Patch_Top" color="12" fill="4" visible="yes" active="yes"/>
<layer number="102" name="Mittellin" color="7" fill="1" visible="yes" active="yes"/>
<layer number="103" name="Stiffner" color="7" fill="1" visible="yes" active="yes"/>
<layer number="104" name="Name" color="7" fill="1" visible="yes" active="yes"/>
<layer number="105" name="Beschreib" color="7" fill="1" visible="yes" active="yes"/>
<layer number="106" name="BGA-Top" color="7" fill="1" visible="yes" active="yes"/>
<layer number="107" name="BD-Top" color="7" fill="1" visible="yes" active="yes"/>
<layer number="108" name="tBridges" color="7" fill="1" visible="yes" active="yes"/>
<layer number="109" name="tBPL" color="7" fill="1" visible="yes" active="yes"/>
<layer number="110" name="bBPL" color="7" fill="1" visible="yes" active="yes"/>
<layer number="111" name="MPL" color="7" fill="1" visible="yes" active="yes"/>
<layer number="112" name="tSilk" color="7" fill="1" visible="yes" active="yes"/>
<layer number="116" name="Patch_BOT" color="9" fill="4" visible="no" active="yes"/>
<layer number="121" name="sName" color="7" fill="1" visible="yes" active="yes"/>
<layer number="122" name="_bPlace" color="7" fill="1" visible="yes" active="yes"/>
<layer number="123" name="tTestmark" color="7" fill="1" visible="yes" active="yes"/>
<layer number="124" name="bTestmark" color="7" fill="1" visible="yes" active="yes"/>
<layer number="125" name="_tNames" color="7" fill="1" visible="yes" active="yes"/>
<layer number="126" name="_bNames" color="7" fill="1" visible="yes" active="yes"/>
<layer number="127" name="_tValues" color="7" fill="1" visible="yes" active="yes"/>
<layer number="128" name="_bValues" color="7" fill="1" visible="yes" active="yes"/>
<layer number="131" name="tAdjust" color="7" fill="1" visible="yes" active="yes"/>
<layer number="132" name="bAdjust" color="7" fill="1" visible="yes" active="yes"/>
<layer number="144" name="Drill_legend" color="7" fill="1" visible="yes" active="yes"/>
<layer number="150" name="Notes" color="7" fill="1" visible="no" active="yes"/>
<layer number="151" name="HeatSink" color="7" fill="1" visible="yes" active="yes"/>
<layer number="152" name="_bDocu" color="7" fill="1" visible="yes" active="yes"/>
<layer number="153" name="FabDoc1" color="6" fill="1" visible="no" active="no"/>
<layer number="154" name="FabDoc2" color="2" fill="1" visible="no" active="no"/>
<layer number="155" name="FabDoc3" color="7" fill="15" visible="no" active="no"/>
<layer number="199" name="Contour" color="7" fill="1" visible="yes" active="yes"/>
<layer number="200" name="200bmp" color="1" fill="10" visible="yes" active="yes"/>
<layer number="201" name="201bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="202" name="202bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="203" name="203bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="204" name="204bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="205" name="205bmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="206" name="206bmp" color="7" fill="10" visible="no" active="yes"/>
<layer number="207" name="207bmp" color="8" fill="10" visible="no" active="yes"/>
<layer number="208" name="208bmp" color="9" fill="10" visible="no" active="yes"/>
<layer number="209" name="209bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="210" name="210bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="211" name="211bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="212" name="212bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="213" name="213bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="214" name="214bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="215" name="215bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="216" name="216bmp" color="7" fill="1" visible="no" active="yes"/>
<layer number="217" name="217bmp" color="18" fill="1" visible="no" active="no"/>
<layer number="218" name="218bmp" color="19" fill="1" visible="no" active="no"/>
<layer number="219" name="219bmp" color="20" fill="1" visible="no" active="no"/>
<layer number="220" name="220bmp" color="21" fill="1" visible="no" active="no"/>
<layer number="221" name="221bmp" color="22" fill="1" visible="no" active="no"/>
<layer number="222" name="222bmp" color="23" fill="1" visible="no" active="no"/>
<layer number="223" name="223bmp" color="24" fill="1" visible="no" active="no"/>
<layer number="224" name="224bmp" color="25" fill="1" visible="no" active="no"/>
<layer number="248" name="Housing" color="7" fill="1" visible="yes" active="yes"/>
<layer number="249" name="Edge" color="7" fill="1" visible="yes" active="yes"/>
<layer number="250" name="Descript" color="7" fill="1" visible="yes" active="yes"/>
<layer number="251" name="SMDround" color="7" fill="1" visible="yes" active="yes"/>
<layer number="254" name="cooling" color="7" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="UniqueInteractionsLib">
<packages>
<package name="EZ-I2CHEADERV1">
<wire x1="-0.935" y1="-2.54" x2="-1.07" y2="-1.905" width="0.2032" layer="21"/>
<wire x1="-1.07" y1="-1.905" x2="-1.07" y2="-0.635" width="0.2032" layer="21"/>
<wire x1="-1.07" y1="-0.635" x2="-0.635" y2="0.3" width="0.2032" layer="21"/>
<wire x1="0.635" y1="0.3" x2="1.07" y2="-0.635" width="0.2032" layer="21"/>
<wire x1="1.07" y1="-0.635" x2="1.07" y2="-1.905" width="0.2032" layer="21"/>
<wire x1="1.07" y1="-1.905" x2="0.935" y2="-2.54" width="0.2032" layer="21"/>
<wire x1="-1.07" y1="-6.985" x2="-1.07" y2="-5.715" width="0.2032" layer="21"/>
<wire x1="-1.07" y1="-5.715" x2="-0.935" y2="-5.08" width="0.2032" layer="21"/>
<wire x1="0.935" y1="-5.08" x2="1.07" y2="-5.715" width="0.2032" layer="21"/>
<wire x1="-0.935" y1="-5.08" x2="-1.07" y2="-4.445" width="0.2032" layer="21"/>
<wire x1="-1.07" y1="-4.445" x2="-1.07" y2="-3.175" width="0.2032" layer="21"/>
<wire x1="-1.07" y1="-3.175" x2="-0.935" y2="-2.54" width="0.2032" layer="21"/>
<wire x1="0.935" y1="-2.54" x2="1.07" y2="-3.175" width="0.2032" layer="21"/>
<wire x1="1.07" y1="-3.175" x2="1.07" y2="-4.445" width="0.2032" layer="21"/>
<wire x1="1.07" y1="-4.445" x2="0.935" y2="-5.08" width="0.2032" layer="21"/>
<wire x1="-0.935" y1="-10.16" x2="-1.07" y2="-9.525" width="0.2032" layer="21"/>
<wire x1="-1.07" y1="-9.525" x2="-1.07" y2="-8.255" width="0.2032" layer="21"/>
<wire x1="-1.07" y1="-8.255" x2="-0.935" y2="-7.62" width="0.2032" layer="21"/>
<wire x1="0.935" y1="-7.62" x2="1.07" y2="-8.255" width="0.2032" layer="21"/>
<wire x1="1.07" y1="-8.255" x2="1.07" y2="-9.525" width="0.2032" layer="21"/>
<wire x1="1.07" y1="-9.525" x2="0.935" y2="-10.16" width="0.2032" layer="21"/>
<wire x1="-1.07" y1="-6.985" x2="-0.935" y2="-7.62" width="0.2032" layer="21"/>
<wire x1="0.935" y1="-7.62" x2="1.07" y2="-6.985" width="0.2032" layer="21"/>
<wire x1="1.07" y1="-5.715" x2="1.07" y2="-6.985" width="0.2032" layer="21"/>
<wire x1="-1.07" y1="-14.605" x2="-1.07" y2="-13.335" width="0.2032" layer="21"/>
<wire x1="-1.07" y1="-13.335" x2="-0.935" y2="-12.7" width="0.2032" layer="21"/>
<wire x1="0.935" y1="-12.7" x2="1.07" y2="-13.335" width="0.2032" layer="21"/>
<wire x1="-0.935" y1="-12.7" x2="-1.07" y2="-12.065" width="0.2032" layer="21"/>
<wire x1="-1.07" y1="-12.065" x2="-1.07" y2="-10.795" width="0.2032" layer="21"/>
<wire x1="-1.07" y1="-10.795" x2="-0.935" y2="-10.16" width="0.2032" layer="21"/>
<wire x1="0.935" y1="-10.16" x2="1.07" y2="-10.795" width="0.2032" layer="21"/>
<wire x1="1.07" y1="-10.795" x2="1.07" y2="-12.065" width="0.2032" layer="21"/>
<wire x1="1.07" y1="-12.065" x2="0.935" y2="-12.7" width="0.2032" layer="21"/>
<wire x1="-0.635" y1="-15.04" x2="0.635" y2="-15.04" width="0.2032" layer="21"/>
<wire x1="-1.07" y1="-14.605" x2="-0.635" y2="-15.04" width="0.2032" layer="21"/>
<wire x1="0.635" y1="-15.04" x2="1.07" y2="-14.605" width="0.2032" layer="21"/>
<wire x1="1.07" y1="-13.335" x2="1.07" y2="-14.605" width="0.2032" layer="21"/>
<wire x1="-0.635" y1="0.3" x2="0.635" y2="0.3" width="0.2032" layer="21"/>
<pad name="LPOW" x="0" y="-13.97" drill="1.016" diameter="1.8796" rot="R180"/>
<pad name="SCL" x="0" y="-11.43" drill="1.016" diameter="1.8796" rot="R180"/>
<pad name="SDA" x="0" y="-8.89" drill="1.016" diameter="1.8796" rot="R180"/>
<pad name="GND" x="0" y="-6.35" drill="1.016" diameter="1.8796" rot="R180"/>
<pad name="VCC" x="0" y="-3.81" drill="1.016" diameter="1.8796" rot="R180"/>
<pad name="BAT" x="0" y="-1.27" drill="1.016" diameter="1.8796" rot="R180"/>
<rectangle x1="-0.254" y1="-1.524" x2="0.254" y2="-1.016" layer="51" rot="R90"/>
<rectangle x1="-0.254" y1="-4.064" x2="0.254" y2="-3.556" layer="51" rot="R90"/>
<rectangle x1="-0.254" y1="-6.604" x2="0.254" y2="-6.096" layer="51" rot="R90"/>
<rectangle x1="-0.254" y1="-9.144" x2="0.254" y2="-8.636" layer="51" rot="R90"/>
<rectangle x1="-0.254" y1="-11.684" x2="0.254" y2="-11.176" layer="51" rot="R90"/>
<rectangle x1="-0.254" y1="-14.224" x2="0.254" y2="-13.716" layer="51" rot="R90"/>
<text x="0.075" y="-0.07" size="0.4064" layer="25" font="vector" ratio="30" align="center">BAT</text>
<text x="0" y="-2.57" size="0.4064" layer="25" font="vector" ratio="30" align="center">VCC</text>
<text x="0.05" y="-5.12" size="0.4064" layer="25" font="vector" ratio="30" align="center">GND</text>
<text x="0.02" y="-7.65" size="0.4064" layer="25" font="vector" ratio="30" align="center">SDA</text>
<text x="0.06" y="-10.18" size="0.4064" layer="25" font="vector" ratio="30" align="center">SCL</text>
<text x="0.03" y="-12.74" size="0.4064" layer="25" font="vector" ratio="30" align="center">LPW</text>
<wire x1="16.845" y1="-2.54" x2="16.71" y2="-1.905" width="0.2032" layer="21"/>
<wire x1="16.71" y1="-1.905" x2="16.71" y2="-0.635" width="0.2032" layer="21"/>
<wire x1="16.71" y1="-0.635" x2="17.145" y2="0.3" width="0.2032" layer="21"/>
<wire x1="18.415" y1="0.3" x2="18.85" y2="-0.635" width="0.2032" layer="21"/>
<wire x1="18.85" y1="-0.635" x2="18.85" y2="-1.905" width="0.2032" layer="21"/>
<wire x1="18.85" y1="-1.905" x2="18.715" y2="-2.54" width="0.2032" layer="21"/>
<wire x1="16.71" y1="-6.985" x2="16.71" y2="-5.715" width="0.2032" layer="21"/>
<wire x1="16.71" y1="-5.715" x2="16.845" y2="-5.08" width="0.2032" layer="21"/>
<wire x1="18.715" y1="-5.08" x2="18.85" y2="-5.715" width="0.2032" layer="21"/>
<wire x1="16.845" y1="-5.08" x2="16.71" y2="-4.445" width="0.2032" layer="21"/>
<wire x1="16.71" y1="-4.445" x2="16.71" y2="-3.175" width="0.2032" layer="21"/>
<wire x1="16.71" y1="-3.175" x2="16.845" y2="-2.54" width="0.2032" layer="21"/>
<wire x1="18.715" y1="-2.54" x2="18.85" y2="-3.175" width="0.2032" layer="21"/>
<wire x1="18.85" y1="-3.175" x2="18.85" y2="-4.445" width="0.2032" layer="21"/>
<wire x1="18.85" y1="-4.445" x2="18.715" y2="-5.08" width="0.2032" layer="21"/>
<wire x1="16.845" y1="-10.16" x2="16.71" y2="-9.525" width="0.2032" layer="21"/>
<wire x1="16.71" y1="-9.525" x2="16.71" y2="-8.255" width="0.2032" layer="21"/>
<wire x1="16.71" y1="-8.255" x2="16.845" y2="-7.62" width="0.2032" layer="21"/>
<wire x1="18.715" y1="-7.62" x2="18.85" y2="-8.255" width="0.2032" layer="21"/>
<wire x1="18.85" y1="-8.255" x2="18.85" y2="-9.525" width="0.2032" layer="21"/>
<wire x1="18.85" y1="-9.525" x2="18.715" y2="-10.16" width="0.2032" layer="21"/>
<wire x1="16.71" y1="-6.985" x2="16.845" y2="-7.62" width="0.2032" layer="21"/>
<wire x1="18.715" y1="-7.62" x2="18.85" y2="-6.985" width="0.2032" layer="21"/>
<wire x1="18.85" y1="-5.715" x2="18.85" y2="-6.985" width="0.2032" layer="21"/>
<wire x1="16.71" y1="-14.605" x2="16.71" y2="-13.335" width="0.2032" layer="21"/>
<wire x1="16.71" y1="-13.335" x2="16.845" y2="-12.7" width="0.2032" layer="21"/>
<wire x1="18.715" y1="-12.7" x2="18.85" y2="-13.335" width="0.2032" layer="21"/>
<wire x1="16.845" y1="-12.7" x2="16.71" y2="-12.065" width="0.2032" layer="21"/>
<wire x1="16.71" y1="-12.065" x2="16.71" y2="-10.795" width="0.2032" layer="21"/>
<wire x1="16.71" y1="-10.795" x2="16.845" y2="-10.16" width="0.2032" layer="21"/>
<wire x1="18.715" y1="-10.16" x2="18.85" y2="-10.795" width="0.2032" layer="21"/>
<wire x1="18.85" y1="-10.795" x2="18.85" y2="-12.065" width="0.2032" layer="21"/>
<wire x1="18.85" y1="-12.065" x2="18.715" y2="-12.7" width="0.2032" layer="21"/>
<wire x1="17.145" y1="-15.04" x2="18.415" y2="-15.04" width="0.2032" layer="21"/>
<wire x1="16.71" y1="-14.605" x2="17.145" y2="-15.04" width="0.2032" layer="21"/>
<wire x1="18.415" y1="-15.04" x2="18.85" y2="-14.605" width="0.2032" layer="21"/>
<wire x1="18.85" y1="-13.335" x2="18.85" y2="-14.605" width="0.2032" layer="21"/>
<wire x1="17.145" y1="0.3" x2="18.415" y2="0.3" width="0.2032" layer="21"/>
<pad name="LPOW1" x="17.78" y="-13.97" drill="1.016" diameter="1.8796" rot="R180"/>
<pad name="SCL1" x="17.78" y="-11.43" drill="1.016" diameter="1.8796" rot="R180"/>
<pad name="SDA1" x="17.78" y="-8.89" drill="1.016" diameter="1.8796" rot="R180"/>
<pad name="GND1" x="17.78" y="-6.35" drill="1.016" diameter="1.8796" rot="R180"/>
<pad name="VCC1" x="17.78" y="-3.81" drill="1.016" diameter="1.8796" rot="R180"/>
<pad name="BAT1" x="17.78" y="-1.27" drill="1.016" diameter="1.8796" rot="R180"/>
<rectangle x1="17.526" y1="-1.524" x2="18.034" y2="-1.016" layer="51" rot="R90"/>
<rectangle x1="17.526" y1="-4.064" x2="18.034" y2="-3.556" layer="51" rot="R90"/>
<rectangle x1="17.526" y1="-6.604" x2="18.034" y2="-6.096" layer="51" rot="R90"/>
<rectangle x1="17.526" y1="-9.144" x2="18.034" y2="-8.636" layer="51" rot="R90"/>
<rectangle x1="17.526" y1="-11.684" x2="18.034" y2="-11.176" layer="51" rot="R90"/>
<rectangle x1="17.526" y1="-14.224" x2="18.034" y2="-13.716" layer="51" rot="R90"/>
<text x="17.84" y="-0.07" size="0.4064" layer="25" font="vector" ratio="30" align="center">BAT</text>
<text x="17.77" y="-2.57" size="0.4064" layer="25" font="vector" ratio="30" align="center">VCC</text>
<text x="17.79" y="-5.1" size="0.4064" layer="25" font="vector" ratio="30" align="center">GND</text>
<text x="17.78" y="-7.65" size="0.4064" layer="25" font="vector" ratio="30" align="center">SDA</text>
<text x="17.84" y="-10.2" size="0.4064" layer="25" font="vector" ratio="30" align="center">SCL</text>
<text x="17.81" y="-12.73" size="0.4064" layer="25" font="vector" ratio="30" align="center">LPW</text>
<text x="1.56" y="-1.185" size="0.6096" layer="25" font="vector" ratio="15" rot="R270" align="center">BAT</text>
<text x="1.55" y="-3.9" size="0.6096" layer="25" font="vector" ratio="15" rot="R270" align="center">VCC</text>
<text x="1.52" y="-8.93" size="0.6096" layer="25" font="vector" ratio="15" rot="R90" align="center">SDA</text>
<text x="1.5" y="-11.42" size="0.6096" layer="25" font="vector" ratio="15" rot="R90" align="center">SCL</text>
<text x="1.51" y="-14.1" size="0.6096" layer="25" font="vector" ratio="15" rot="R90" align="center">LPW</text>
<text x="16.26" y="-1.17" size="0.6096" layer="25" font="vector" ratio="15" rot="R90" align="center">BAT</text>
<text x="16.2" y="-3.76" size="0.6096" layer="25" font="vector" ratio="15" rot="R90" align="center">VCC</text>
<text x="16.24" y="-6.3" size="0.6096" layer="25" font="vector" ratio="15" rot="R90" align="center">GND</text>
<text x="16.19" y="-8.91" size="0.6096" layer="25" font="vector" ratio="15" rot="R90" align="center">SDA</text>
<text x="16.23" y="-11.32" size="0.6096" layer="25" font="vector" ratio="15" rot="R90" align="center">SCL</text>
<text x="16.24" y="-13.96" size="0.6096" layer="25" font="vector" ratio="15" rot="R90" align="center">LPW</text>
<text x="1.59" y="-1.155" size="0.6096" layer="26" font="vector" ratio="15" rot="MR270" align="center">BAT</text>
<text x="1.54" y="-3.87" size="0.6096" layer="26" font="vector" ratio="15" rot="MR270" align="center">VCC</text>
<text x="1.54" y="-6.42" size="0.6096" layer="25" font="vector" ratio="15" rot="R90" align="center">GND</text>
<text x="1.54" y="-6.46" size="0.6096" layer="26" font="vector" ratio="15" rot="MR90" align="center">GND</text>
<text x="1.53" y="-8.94" size="0.6096" layer="26" font="vector" ratio="15" rot="MR90" align="center">SDA</text>
<text x="1.52" y="-11.43" size="0.6096" layer="26" font="vector" ratio="15" rot="MR90" align="center">SCL</text>
<text x="1.54" y="-14.1" size="0.6096" layer="26" font="vector" ratio="15" rot="MR90" align="center">LPW</text>
<text x="16.22" y="-13.99" size="0.6096" layer="26" font="vector" ratio="15" rot="MR90" align="center">LPW</text>
<text x="16.22" y="-11.38" size="0.6096" layer="26" font="vector" ratio="15" rot="MR90" align="center">SCL</text>
<text x="16.21" y="-8.92" size="0.6096" layer="26" font="vector" ratio="15" rot="MR90" align="center">SDA</text>
<text x="16.24" y="-6.3" size="0.6096" layer="26" font="vector" ratio="15" rot="MR90" align="center">GND</text>
<text x="16.22" y="-3.75" size="0.6096" layer="26" font="vector" ratio="15" rot="MR90" align="center">VCC</text>
<text x="16.22" y="-1.22" size="0.6096" layer="26" font="vector" ratio="15" rot="MR90" align="center">BAT</text>
</package>
<package name="BATTERY_1.25MM_PINHOLES">
<wire x1="-0.95" y1="1.29" x2="-0.95" y2="-1.56" width="0.2032" layer="21"/>
<wire x1="-0.95" y1="-1.56" x2="-1.7" y2="-1.56" width="0.2032" layer="21"/>
<wire x1="-1.7" y1="-1.56" x2="-1.7" y2="4.79" width="0.2032" layer="21"/>
<wire x1="-1.7" y1="4.79" x2="2.95" y2="4.79" width="0.2032" layer="21"/>
<wire x1="2.95" y1="4.79" x2="2.95" y2="-1.56" width="0.2032" layer="21"/>
<wire x1="2.95" y1="-1.56" x2="2.3" y2="-1.56" width="0.2032" layer="21"/>
<wire x1="2.3" y1="-1.56" x2="2.3" y2="1.29" width="0.2032" layer="21"/>
<pad name="-" x="0" y="0" drill="0.7" diameter="1.016"/>
<pad name="+" x="1.25" y="0" drill="0.7" diameter="1.016"/>
<text x="-1.27" y="2.81" size="0.4064" layer="25">&gt;Name</text>
<text x="-1.27" y="4.04" size="0.4064" layer="27">&gt;Value</text>
<text x="0.6" y="0.74" size="1.27" layer="51">+</text>
<text x="-0.15" y="0.74" size="1.27" layer="51">-</text>
</package>
<package name="JUMPER-3PAD">
<wire x1="-0.381" y1="0" x2="0.381" y2="0" width="0.2032" layer="1"/>
<smd name="1" x="-0.508" y="0" dx="0.635" dy="1.016" layer="1" cream="no"/>
<smd name="2" x="0.508" y="0" dx="0.635" dy="1.016" layer="1" cream="no"/>
<smd name="3" x="1.578" y="0" dx="0.635" dy="1.016" layer="1" cream="no"/>
</package>
</packages>
<symbols>
<symbol name="EZ-I2CHEADERV1">
<rectangle x1="-20.32" y1="-5.08" x2="-15.24" y2="7.62" layer="94"/>
<rectangle x1="17.78" y1="-5.08" x2="22.86" y2="7.62" layer="94"/>
<pin name="BAT" x="-15.24" y="7.62" length="middle"/>
<pin name="VCC" x="-15.24" y="5.08" length="middle"/>
<pin name="GND" x="-15.24" y="2.54" length="middle"/>
<pin name="SDA" x="-15.24" y="0" length="middle"/>
<pin name="SCL" x="-15.24" y="-2.54" length="middle"/>
<pin name="LPW" x="-15.24" y="-5.08" length="middle"/>
<pin name="BAT1" x="17.78" y="7.62" length="middle" rot="R180"/>
<pin name="VCC1" x="17.78" y="5.08" length="middle" rot="R180"/>
<pin name="GND1" x="17.78" y="2.54" length="middle" rot="R180"/>
<pin name="SDA1" x="17.78" y="0" length="middle" rot="R180"/>
<pin name="SCL1" x="17.78" y="-2.54" length="middle" rot="R180"/>
<pin name="LPW1" x="17.78" y="-5.08" length="middle" rot="R180"/>
</symbol>
<symbol name="BATTERY_1.25MM_PINHOLES">
<wire x1="-2.54" y1="-2.54" x2="-2.54" y2="1.778" width="0.254" layer="94"/>
<wire x1="-2.54" y1="1.778" x2="-2.54" y2="3.302" width="0.254" layer="94"/>
<wire x1="-2.54" y1="3.302" x2="-2.54" y2="5.08" width="0.254" layer="94"/>
<wire x1="-2.54" y1="5.08" x2="5.08" y2="5.08" width="0.254" layer="94"/>
<wire x1="5.08" y1="5.08" x2="5.08" y2="3.302" width="0.254" layer="94"/>
<wire x1="5.08" y1="3.302" x2="5.08" y2="1.778" width="0.254" layer="94"/>
<wire x1="5.08" y1="1.778" x2="5.08" y2="-2.54" width="0.254" layer="94"/>
<wire x1="5.08" y1="-2.54" x2="4.064" y2="-2.54" width="0.254" layer="94"/>
<wire x1="4.064" y1="-2.54" x2="4.064" y2="0" width="0.254" layer="94"/>
<wire x1="4.064" y1="0" x2="-1.524" y2="0" width="0.254" layer="94"/>
<wire x1="-1.524" y1="0" x2="-1.524" y2="-2.54" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-2.54" x2="-1.524" y2="-2.54" width="0.254" layer="94"/>
<pin name="-" x="0" y="-5.08" visible="off" length="middle" rot="R90"/>
<pin name="+" x="2.54" y="-5.08" visible="off" length="middle" rot="R90"/>
<wire x1="2.032" y1="1.016" x2="3.048" y2="1.016" width="0.254" layer="94"/>
<wire x1="2.54" y1="0.508" x2="2.54" y2="1.524" width="0.254" layer="94"/>
<wire x1="0" y1="0.508" x2="0" y2="1.524" width="0.254" layer="94"/>
<text x="-2.54" y="5.842" size="1.778" layer="95">&gt;NAME</text>
</symbol>
<symbol name="JUMPER-3PAD">
<wire x1="-2.54" y1="-2.54" x2="-2.54" y2="-1.27" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="0" x2="-2.54" y2="-1.27" width="0.4064" layer="94"/>
<wire x1="0" y1="-2.54" x2="0" y2="-1.27" width="0.1524" layer="94"/>
<wire x1="0" y1="0" x2="0" y2="-1.27" width="0.4064" layer="94"/>
<wire x1="-3.175" y1="-2.54" x2="0" y2="-2.54" width="0.4064" layer="94"/>
<wire x1="0" y1="-2.54" x2="2.54" y2="-2.54" width="0.4064" layer="94"/>
<wire x1="2.54" y1="-2.54" x2="3.175" y2="-2.54" width="0.4064" layer="94"/>
<wire x1="3.175" y1="-2.54" x2="3.175" y2="-1.905" width="0.4064" layer="94"/>
<wire x1="3.175" y1="-1.905" x2="-3.175" y2="-1.905" width="0.4064" layer="94"/>
<wire x1="-3.175" y1="-1.905" x2="-3.175" y2="-2.54" width="0.4064" layer="94"/>
<wire x1="2.54" y1="0" x2="2.54" y2="-1.27" width="0.4064" layer="94"/>
<wire x1="2.54" y1="-2.54" x2="2.54" y2="-1.27" width="0.1524" layer="94"/>
<text x="-3.81" y="-2.54" size="1.778" layer="95" rot="R90">&gt;NAME</text>
<text x="5.715" y="-2.54" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="1" x="-2.54" y="-5.08" visible="off" length="short" direction="pas" rot="R90"/>
<pin name="2" x="0" y="-5.08" visible="off" length="short" direction="pas" rot="R90"/>
<pin name="3" x="2.54" y="-5.08" visible="off" length="short" direction="pas" rot="R90"/>
<wire x1="-2.54" y1="0" x2="0" y2="0" width="0.254" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="EZ-I2CHEADERV1">
<gates>
<gate name="G$1" symbol="EZ-I2CHEADERV1" x="0" y="0"/>
</gates>
<devices>
<device name="" package="EZ-I2CHEADERV1">
<connects>
<connect gate="G$1" pin="BAT" pad="BAT"/>
<connect gate="G$1" pin="BAT1" pad="BAT1"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="GND1" pad="GND1"/>
<connect gate="G$1" pin="LPW" pad="LPOW"/>
<connect gate="G$1" pin="LPW1" pad="LPOW1"/>
<connect gate="G$1" pin="SCL" pad="SCL"/>
<connect gate="G$1" pin="SCL1" pad="SCL1"/>
<connect gate="G$1" pin="SDA" pad="SDA"/>
<connect gate="G$1" pin="SDA1" pad="SDA1"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
<connect gate="G$1" pin="VCC1" pad="VCC1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="BATTERY_1.25MM_PINHOLES">
<gates>
<gate name="G$1" symbol="BATTERY_1.25MM_PINHOLES" x="-2.54" y="-2.54"/>
</gates>
<devices>
<device name="" package="BATTERY_1.25MM_PINHOLES">
<connects>
<connect gate="G$1" pin="+" pad="+"/>
<connect gate="G$1" pin="-" pad="-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="JUMPER-3PAD">
<gates>
<gate name="G$1" symbol="JUMPER-3PAD" x="0" y="2.54"/>
</gates>
<devices>
<device name="" package="JUMPER-3PAD">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="microbuilder">
<description>&lt;h2&gt;&lt;b&gt;microBuilder.eu&lt;/b&gt; Eagle Footprint Library&lt;/h2&gt;

&lt;p&gt;Footprints for common components used in our projects and products.  This is the same library that we use internally, and it is regularly updated.  The newest version can always be found at &lt;b&gt;www.microBuilder.eu&lt;/b&gt;.  If you find this library useful, please feel free to purchase something from our online store. Please also note that all holes are optimised for metric drill bits!&lt;/p&gt;

&lt;h3&gt;Obligatory Warning&lt;/h3&gt;
&lt;p&gt;While it probably goes without saying, there are no guarantees that the footprints or schematic symbols in this library are flawless, and we make no promises of fitness for production, prototyping or any other purpose. These libraries are provided for information puposes only, and are used at your own discretion.  While we make every effort to produce accurate footprints, and many of the items found in this library have be proven in production, we can't make any promises of suitability for a specific purpose. If you do find any errors, though, please feel free to contact us at www.microbuilder.eu to let us know about it so that we can update the library accordingly!&lt;/p&gt;

&lt;h3&gt;License&lt;/h3&gt;
&lt;p&gt;This work is placed in the public domain, and may be freely used for commercial and non-commercial work with the following conditions:&lt;/p&gt;
&lt;p&gt;THIS SOFTWARE IS PROVIDED ''AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
&lt;/p&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="AGND">
<wire x1="-1.27" y1="0" x2="1.27" y2="0" width="0.254" layer="94"/>
<text x="-1.524" y="-2.54" size="1.27" layer="96">&gt;VALUE</text>
<pin name="AGND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="AGND">
<description>&lt;b&gt;Analog GND&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="AGND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$5" library="microbuilder" deviceset="AGND" device=""/>
<part name="U$1" library="UniqueInteractionsLib" deviceset="EZ-I2CHEADERV1" device=""/>
<part name="U$3" library="UniqueInteractionsLib" deviceset="BATTERY_1.25MM_PINHOLES" device=""/>
<part name="U$4" library="UniqueInteractionsLib" deviceset="BATTERY_1.25MM_PINHOLES" device=""/>
<part name="U$7" library="UniqueInteractionsLib" deviceset="BATTERY_1.25MM_PINHOLES" device=""/>
<part name="U$8" library="UniqueInteractionsLib" deviceset="JUMPER-3PAD" device=""/>
<part name="U$9" library="UniqueInteractionsLib" deviceset="BATTERY_1.25MM_PINHOLES" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$5" gate="G$1" x="38.1" y="58.42" rot="R90"/>
<instance part="U$1" gate="G$1" x="-21.336" y="55.88"/>
<instance part="U$3" gate="G$1" x="12.7" y="7.62" rot="R180"/>
<instance part="U$4" gate="G$1" x="25.4" y="7.62" rot="R180"/>
<instance part="U$7" gate="G$1" x="38.1" y="7.62" rot="R180"/>
<instance part="U$8" gate="G$1" x="68.58" y="38.1" rot="R270"/>
<instance part="U$9" gate="G$1" x="50.8" y="7.62" rot="R180"/>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<junction x="15.24" y="58.42"/>
<wire x1="10.16" y1="58.42" x2="15.24" y2="58.42" width="0.1524" layer="91"/>
<wire x1="15.24" y1="58.42" x2="35.56" y2="58.42" width="0.1524" layer="91"/>
<label x="27.94" y="58.42" size="1.778" layer="95" xref="yes"/>
<pinref part="U$5" gate="G$1" pin="AGND"/>
<wire x1="35.56" y1="58.42" x2="38.1" y2="58.42" width="0.1524" layer="91"/>
<junction x="35.56" y="58.42"/>
<wire x1="0" y1="58.42" x2="2.54" y2="58.42" width="0.1524" layer="91"/>
<junction x="2.54" y="58.42"/>
<wire x1="2.54" y1="58.42" x2="15.24" y2="58.42" width="0.1524" layer="91"/>
<junction x="2.54" y="58.42"/>
<wire x1="2.54" y1="58.42" x2="-3.556" y2="58.42" width="0.1524" layer="91"/>
<wire x1="-3.556" y1="58.42" x2="-36.576" y2="58.42" width="0.1524" layer="91"/>
<wire x1="-41.148" y1="58.42" x2="-36.576" y2="58.42" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="GND"/>
<wire x1="-36.576" y1="58.42" x2="-15.24" y2="58.42" width="0.1524" layer="91"/>
<junction x="-36.576" y="58.42"/>
<pinref part="U$1" gate="G$1" pin="GND1"/>
<junction x="-3.556" y="58.42"/>
<wire x1="50.8" y1="58.42" x2="35.56" y2="58.42" width="0.1524" layer="91"/>
<wire x1="50.8" y1="58.42" x2="50.8" y2="20.32" width="0.1524" layer="91"/>
<wire x1="12.7" y1="20.32" x2="25.4" y2="20.32" width="0.1524" layer="91"/>
<wire x1="25.4" y1="20.32" x2="38.1" y2="20.32" width="0.1524" layer="91"/>
<wire x1="38.1" y1="20.32" x2="50.8" y2="20.32" width="0.1524" layer="91"/>
<wire x1="12.7" y1="20.32" x2="12.7" y2="12.7" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="-"/>
<wire x1="12.7" y1="12.7" x2="12.7" y2="7.62" width="0.1524" layer="91"/>
<junction x="12.7" y="12.7"/>
<wire x1="25.4" y1="7.62" x2="25.4" y2="12.7" width="0.1524" layer="91"/>
<wire x1="25.4" y1="12.7" x2="25.4" y2="20.32" width="0.1524" layer="91"/>
<wire x1="38.1" y1="7.62" x2="38.1" y2="12.7" width="0.1524" layer="91"/>
<junction x="25.4" y="20.32"/>
<junction x="38.1" y="20.32"/>
<pinref part="U$4" gate="G$1" pin="-"/>
<junction x="25.4" y="12.7"/>
<pinref part="U$7" gate="G$1" pin="-"/>
<wire x1="38.1" y1="12.7" x2="38.1" y2="20.32" width="0.1524" layer="91"/>
<junction x="38.1" y="12.7"/>
<wire x1="50.8" y1="7.62" x2="50.8" y2="12.7" width="0.1524" layer="91"/>
<pinref part="U$9" gate="G$1" pin="-"/>
<wire x1="50.8" y1="12.7" x2="50.8" y2="20.32" width="0.1524" layer="91"/>
<junction x="50.8" y="12.7"/>
</segment>
</net>
<net name="SDA" class="0">
<segment>
<junction x="15.24" y="53.34"/>
<wire x1="15.24" y1="53.34" x2="27.94" y2="53.34" width="0.1524" layer="91"/>
<label x="27.94" y="53.34" size="1.778" layer="95" xref="yes"/>
<wire x1="0" y1="55.88" x2="2.54" y2="55.88" width="0.1524" layer="91"/>
<wire x1="2.54" y1="55.88" x2="10.16" y2="55.88" width="0.1524" layer="91"/>
<wire x1="10.16" y1="55.88" x2="10.16" y2="53.34" width="0.1524" layer="91"/>
<wire x1="10.16" y1="53.34" x2="15.24" y2="53.34" width="0.1524" layer="91"/>
<junction x="2.54" y="55.88"/>
<junction x="2.54" y="55.88"/>
<wire x1="2.54" y1="55.88" x2="-3.556" y2="55.88" width="0.1524" layer="91"/>
<wire x1="-3.556" y1="55.88" x2="-36.576" y2="55.88" width="0.1524" layer="91"/>
<wire x1="-41.148" y1="55.88" x2="-36.576" y2="55.88" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="SDA"/>
<wire x1="-36.576" y1="55.88" x2="-15.24" y2="55.88" width="0.1524" layer="91"/>
<junction x="-36.576" y="55.88"/>
<pinref part="U$1" gate="G$1" pin="SDA1"/>
<junction x="-3.556" y="55.88"/>
</segment>
</net>
<net name="SCL" class="0">
<segment>
<junction x="15.24" y="48.26"/>
<wire x1="10.16" y1="48.26" x2="15.24" y2="48.26" width="0.1524" layer="91"/>
<wire x1="15.24" y1="48.26" x2="27.94" y2="48.26" width="0.1524" layer="91"/>
<label x="27.94" y="48.26" size="1.778" layer="95" xref="yes"/>
<wire x1="0" y1="53.34" x2="2.54" y2="53.34" width="0.1524" layer="91"/>
<wire x1="2.54" y1="53.34" x2="7.62" y2="53.34" width="0.1524" layer="91"/>
<wire x1="7.62" y1="53.34" x2="7.62" y2="48.26" width="0.1524" layer="91"/>
<wire x1="7.62" y1="48.26" x2="15.24" y2="48.26" width="0.1524" layer="91"/>
<junction x="2.54" y="53.34"/>
<junction x="2.54" y="53.34"/>
<wire x1="2.54" y1="53.34" x2="-3.556" y2="53.34" width="0.1524" layer="91"/>
<wire x1="-3.556" y1="53.34" x2="-36.576" y2="53.34" width="0.1524" layer="91"/>
<wire x1="-41.148" y1="53.34" x2="-36.576" y2="53.34" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="SCL"/>
<wire x1="-36.576" y1="53.34" x2="-15.24" y2="53.34" width="0.1524" layer="91"/>
<junction x="-36.576" y="53.34"/>
<pinref part="U$1" gate="G$1" pin="SCL1"/>
<junction x="-3.556" y="53.34"/>
</segment>
</net>
<net name="VCC" class="0">
<segment>
<junction x="15.24" y="63.5"/>
<wire x1="11.684" y1="63.5" x2="15.24" y2="63.5" width="0.1524" layer="91"/>
<wire x1="15.24" y1="63.5" x2="25.4" y2="63.5" width="0.1524" layer="91"/>
<label x="27.94" y="63.5" size="1.778" layer="95" xref="yes"/>
<wire x1="25.4" y1="63.5" x2="27.94" y2="63.5" width="0.1524" layer="91"/>
<wire x1="7.62" y1="60.96" x2="7.62" y2="63.5" width="0.1524" layer="91"/>
<wire x1="7.62" y1="63.5" x2="15.24" y2="63.5" width="0.1524" layer="91"/>
<wire x1="7.62" y1="60.96" x2="-3.556" y2="60.96" width="0.1524" layer="91"/>
<wire x1="-3.556" y1="60.96" x2="-36.576" y2="60.96" width="0.1524" layer="91"/>
<wire x1="-41.148" y1="60.96" x2="-36.576" y2="60.96" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="VCC"/>
<wire x1="-36.576" y1="60.96" x2="-15.24" y2="60.96" width="0.1524" layer="91"/>
<junction x="-36.576" y="60.96"/>
<pinref part="U$1" gate="G$1" pin="VCC1"/>
<junction x="-3.556" y="60.96"/>
<wire x1="58.42" y1="66.04" x2="25.4" y2="66.04" width="0.1524" layer="91"/>
<wire x1="25.4" y1="66.04" x2="25.4" y2="63.5" width="0.1524" layer="91"/>
<junction x="25.4" y="63.5"/>
<wire x1="58.42" y1="66.04" x2="58.42" y2="35.56" width="0.1524" layer="91"/>
<wire x1="58.42" y1="35.56" x2="63.5" y2="35.56" width="0.1524" layer="91"/>
<pinref part="U$8" gate="G$1" pin="3"/>
<wire x1="63.5" y1="35.56" x2="68.58" y2="35.56" width="0.1524" layer="91"/>
<junction x="63.5" y="35.56"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<wire x1="0" y1="50.8" x2="2.54" y2="50.8" width="0.1524" layer="91"/>
<wire x1="0" y1="50.8" x2="-3.556" y2="50.8" width="0.1524" layer="91"/>
<wire x1="-3.556" y1="50.8" x2="-36.576" y2="50.8" width="0.1524" layer="91"/>
<wire x1="-41.148" y1="50.8" x2="-36.576" y2="50.8" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="LPW"/>
<wire x1="-36.576" y1="50.8" x2="-15.24" y2="50.8" width="0.1524" layer="91"/>
<junction x="-36.576" y="50.8"/>
<pinref part="U$1" gate="G$1" pin="LPW1"/>
<junction x="-3.556" y="50.8"/>
</segment>
</net>
<net name="BAT" class="0">
<segment>
<wire x1="-17.78" y1="63.5" x2="-36.576" y2="63.5" width="0.1524" layer="91"/>
<wire x1="-41.148" y1="63.5" x2="-36.576" y2="63.5" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="BAT"/>
<wire x1="-36.576" y1="63.5" x2="-7.62" y2="63.5" width="0.1524" layer="91"/>
<junction x="-36.576" y="63.5"/>
<pinref part="U$1" gate="G$1" pin="BAT1"/>
<wire x1="-7.62" y1="63.5" x2="-3.556" y2="63.5" width="0.1524" layer="91"/>
<wire x1="-3.556" y1="63.5" x2="2.54" y2="63.5" width="0.1524" layer="91"/>
<junction x="-3.556" y="63.5"/>
<wire x1="63.5" y1="68.58" x2="-7.62" y2="68.58" width="0.1524" layer="91"/>
<wire x1="-7.62" y1="68.58" x2="-7.62" y2="63.5" width="0.1524" layer="91"/>
<junction x="-7.62" y="63.5"/>
<pinref part="U$8" gate="G$1" pin="1"/>
<wire x1="63.5" y1="68.58" x2="63.5" y2="40.64" width="0.1524" layer="91"/>
<wire x1="63.5" y1="40.64" x2="68.58" y2="40.64" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<wire x1="53.34" y1="17.78" x2="53.34" y2="38.1" width="0.1524" layer="91"/>
<wire x1="10.16" y1="17.78" x2="22.86" y2="17.78" width="0.1524" layer="91"/>
<wire x1="22.86" y1="17.78" x2="35.56" y2="17.78" width="0.1524" layer="91"/>
<wire x1="35.56" y1="17.78" x2="48.26" y2="17.78" width="0.1524" layer="91"/>
<wire x1="48.26" y1="17.78" x2="53.34" y2="17.78" width="0.1524" layer="91"/>
<wire x1="10.16" y1="17.78" x2="10.16" y2="12.7" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="+"/>
<wire x1="10.16" y1="12.7" x2="10.16" y2="7.62" width="0.1524" layer="91"/>
<junction x="10.16" y="12.7"/>
<wire x1="22.86" y1="7.62" x2="22.86" y2="12.7" width="0.1524" layer="91"/>
<wire x1="22.86" y1="12.7" x2="22.86" y2="17.78" width="0.1524" layer="91"/>
<wire x1="35.56" y1="7.62" x2="35.56" y2="12.7" width="0.1524" layer="91"/>
<junction x="22.86" y="17.78"/>
<junction x="35.56" y="17.78"/>
<pinref part="U$4" gate="G$1" pin="+"/>
<junction x="22.86" y="12.7"/>
<pinref part="U$7" gate="G$1" pin="+"/>
<wire x1="35.56" y1="12.7" x2="35.56" y2="17.78" width="0.1524" layer="91"/>
<junction x="35.56" y="12.7"/>
<wire x1="53.34" y1="38.1" x2="63.5" y2="38.1" width="0.1524" layer="91"/>
<pinref part="U$8" gate="G$1" pin="2"/>
<wire x1="63.5" y1="38.1" x2="68.58" y2="38.1" width="0.1524" layer="91"/>
<junction x="63.5" y="38.1"/>
<wire x1="48.26" y1="5.08" x2="48.26" y2="12.7" width="0.1524" layer="91"/>
<pinref part="U$9" gate="G$1" pin="+"/>
<wire x1="48.26" y1="12.7" x2="48.26" y2="17.78" width="0.1524" layer="91"/>
<junction x="48.26" y="12.7"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
