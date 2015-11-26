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
<layer number="119" name="subcmp" color="7" fill="1" visible="yes" active="yes"/>
<layer number="120" name="Descript" color="7" fill="1" visible="yes" active="yes"/>
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
<text x="-0.74" y="-0.34" size="0.6096" layer="25" ratio="15">BAT</text>
<text x="-0.84" y="-2.94" size="0.6096" layer="25" ratio="15">VCC</text>
<text x="-0.94" y="-5.44" size="0.6096" layer="25" ratio="15">GND</text>
<text x="-0.84" y="-7.94" size="0.6096" layer="25" ratio="15">SDA</text>
<text x="-0.74" y="-10.54" size="0.6096" layer="25" ratio="15">SCL</text>
<text x="-0.94" y="-13.04" size="0.6096" layer="25" ratio="15">LPW</text>
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
<text x="17.04" y="-0.34" size="0.6096" layer="25" ratio="15">BAT</text>
<text x="16.94" y="-2.94" size="0.6096" layer="25" ratio="15">VCC</text>
<text x="16.84" y="-5.44" size="0.6096" layer="25" ratio="15">GND</text>
<text x="16.94" y="-7.94" size="0.6096" layer="25" ratio="15">SDA</text>
<text x="17.04" y="-10.54" size="0.6096" layer="25" ratio="15">SCL</text>
<text x="16.84" y="-13.04" size="0.6096" layer="25" ratio="15">LPW</text>
<text x="1.22" y="-0.635" size="0.6096" layer="25" ratio="15" rot="R270">BAT</text>
<text x="1.26" y="-3.04" size="0.6096" layer="25" ratio="15" rot="R270">VCC</text>
<text x="1.86" y="-7.44" size="0.6096" layer="25" ratio="15" rot="R90">GND</text>
<text x="1.86" y="-9.84" size="0.6096" layer="25" ratio="15" rot="R90">SDA</text>
<text x="1.84" y="-12.28" size="0.6096" layer="25" ratio="15" rot="R90">SCL</text>
<text x="1.86" y="-14.94" size="0.6096" layer="25" ratio="15" rot="R90">LPW</text>
<text x="16.47" y="-1.81" size="0.6096" layer="25" ratio="15" rot="R90">BAT</text>
<text x="16.53" y="-4.73" size="0.6096" layer="25" ratio="15" rot="R90">VCC</text>
<text x="16.53" y="-7.23" size="0.6096" layer="25" ratio="15" rot="R90">GND</text>
<text x="16.53" y="-9.73" size="0.6096" layer="25" ratio="15" rot="R90">SDA</text>
<text x="16.53" y="-12.13" size="0.6096" layer="25" ratio="15" rot="R90">SCL</text>
<text x="16.53" y="-14.83" size="0.6096" layer="25" ratio="15" rot="R90">LPW</text>
<text x="1.89" y="-0.635" size="0.6096" layer="26" ratio="15" rot="MR270">BAT</text>
<text x="1.83" y="-3.04" size="0.6096" layer="26" ratio="15" rot="MR270">VCC</text>
<text x="1.86" y="-7.44" size="0.6096" layer="25" ratio="15" rot="R90">GND</text>
<text x="1.23" y="-7.44" size="0.6096" layer="26" ratio="15" rot="MR90">GND</text>
<text x="1.23" y="-9.84" size="0.6096" layer="26" ratio="15" rot="MR90">SDA</text>
<text x="1.21" y="-12.28" size="0.6096" layer="26" ratio="15" rot="MR90">SCL</text>
<text x="1.23" y="-14.94" size="0.6096" layer="26" ratio="15" rot="MR90">LPW</text>
<text x="15.86" y="-14.83" size="0.6096" layer="26" ratio="15" rot="MR90">LPW</text>
<text x="15.86" y="-12.13" size="0.6096" layer="26" ratio="15" rot="MR90">SCL</text>
<text x="15.96" y="-9.73" size="0.6096" layer="26" ratio="15" rot="MR90">SDA</text>
<text x="15.86" y="-7.23" size="0.6096" layer="26" ratio="15" rot="MR90">GND</text>
<text x="15.96" y="-4.73" size="0.6096" layer="26" ratio="15" rot="MR90">VCC</text>
<text x="15.8" y="-1.81" size="0.6096" layer="26" ratio="15" rot="MR90">BAT</text>
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
</devicesets>
</library>
<library name="SparkFun">
<packages>
<package name="1X06-SMD">
<wire x1="7.62" y1="1.25" x2="-7.62" y2="1.25" width="0.127" layer="51"/>
<wire x1="-7.62" y1="1.25" x2="-7.62" y2="-1.25" width="0.127" layer="51"/>
<wire x1="-7.62" y1="-1.25" x2="-6.35" y2="-1.25" width="0.127" layer="51"/>
<wire x1="-6.35" y1="-1.25" x2="-3.81" y2="-1.25" width="0.127" layer="51"/>
<wire x1="-3.81" y1="-1.25" x2="-1.27" y2="-1.25" width="0.127" layer="51"/>
<wire x1="-1.27" y1="-1.25" x2="1.27" y2="-1.25" width="0.127" layer="51"/>
<wire x1="1.27" y1="-1.25" x2="3.81" y2="-1.25" width="0.127" layer="51"/>
<wire x1="3.81" y1="-1.25" x2="6.35" y2="-1.25" width="0.127" layer="51"/>
<wire x1="6.35" y1="-1.25" x2="7.62" y2="-1.25" width="0.127" layer="51"/>
<wire x1="7.62" y1="-1.25" x2="7.62" y2="1.25" width="0.127" layer="51"/>
<wire x1="6.35" y1="-1.25" x2="6.35" y2="-7.25" width="0.127" layer="51"/>
<wire x1="3.81" y1="-1.25" x2="3.81" y2="-7.25" width="0.127" layer="51"/>
<wire x1="1.27" y1="-1.25" x2="1.27" y2="-7.25" width="0.127" layer="51"/>
<wire x1="-1.27" y1="-1.25" x2="-1.27" y2="-7.25" width="0.127" layer="51"/>
<wire x1="-3.81" y1="-1.25" x2="-3.81" y2="-7.25" width="0.127" layer="51"/>
<wire x1="-6.35" y1="-1.25" x2="-6.35" y2="-7.25" width="0.127" layer="51"/>
<smd name="4" x="1.27" y="5" dx="3" dy="1" layer="1" rot="R90"/>
<smd name="5" x="3.81" y="5" dx="3" dy="1" layer="1" rot="R90"/>
<smd name="6" x="6.35" y="5" dx="3" dy="1" layer="1" rot="R90"/>
<smd name="3" x="-1.27" y="5" dx="3" dy="1" layer="1" rot="R90"/>
<smd name="2" x="-3.81" y="5" dx="3" dy="1" layer="1" rot="R90"/>
<smd name="1" x="-6.35" y="5" dx="3" dy="1" layer="1" rot="R90"/>
<hole x="-5.08" y="0" drill="1.4"/>
<hole x="5.08" y="0" drill="1.4"/>
</package>
<package name="1X06">
<wire x1="11.43" y1="0.635" x2="12.065" y2="1.27" width="0.2032" layer="21"/>
<wire x1="12.065" y1="1.27" x2="13.335" y2="1.27" width="0.2032" layer="21"/>
<wire x1="13.335" y1="1.27" x2="13.97" y2="0.635" width="0.2032" layer="21"/>
<wire x1="13.97" y1="-0.635" x2="13.335" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="13.335" y1="-1.27" x2="12.065" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="12.065" y1="-1.27" x2="11.43" y2="-0.635" width="0.2032" layer="21"/>
<wire x1="6.985" y1="1.27" x2="8.255" y2="1.27" width="0.2032" layer="21"/>
<wire x1="8.255" y1="1.27" x2="8.89" y2="0.635" width="0.2032" layer="21"/>
<wire x1="8.89" y1="-0.635" x2="8.255" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="8.89" y1="0.635" x2="9.525" y2="1.27" width="0.2032" layer="21"/>
<wire x1="9.525" y1="1.27" x2="10.795" y2="1.27" width="0.2032" layer="21"/>
<wire x1="10.795" y1="1.27" x2="11.43" y2="0.635" width="0.2032" layer="21"/>
<wire x1="11.43" y1="-0.635" x2="10.795" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="10.795" y1="-1.27" x2="9.525" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="9.525" y1="-1.27" x2="8.89" y2="-0.635" width="0.2032" layer="21"/>
<wire x1="3.81" y1="0.635" x2="4.445" y2="1.27" width="0.2032" layer="21"/>
<wire x1="4.445" y1="1.27" x2="5.715" y2="1.27" width="0.2032" layer="21"/>
<wire x1="5.715" y1="1.27" x2="6.35" y2="0.635" width="0.2032" layer="21"/>
<wire x1="6.35" y1="-0.635" x2="5.715" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="5.715" y1="-1.27" x2="4.445" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="4.445" y1="-1.27" x2="3.81" y2="-0.635" width="0.2032" layer="21"/>
<wire x1="6.985" y1="1.27" x2="6.35" y2="0.635" width="0.2032" layer="21"/>
<wire x1="6.35" y1="-0.635" x2="6.985" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="8.255" y1="-1.27" x2="6.985" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="0.635" y2="1.27" width="0.2032" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.27" y2="0.635" width="0.2032" layer="21"/>
<wire x1="1.27" y1="-0.635" x2="0.635" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="1.27" y1="0.635" x2="1.905" y2="1.27" width="0.2032" layer="21"/>
<wire x1="1.905" y1="1.27" x2="3.175" y2="1.27" width="0.2032" layer="21"/>
<wire x1="3.175" y1="1.27" x2="3.81" y2="0.635" width="0.2032" layer="21"/>
<wire x1="3.81" y1="-0.635" x2="3.175" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="3.175" y1="-1.27" x2="1.905" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="1.905" y1="-1.27" x2="1.27" y2="-0.635" width="0.2032" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-1.27" y2="-0.635" width="0.2032" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="-1.27" y2="0.635" width="0.2032" layer="21"/>
<wire x1="-1.27" y1="-0.635" x2="-0.635" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="-0.635" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="13.97" y1="0.635" x2="13.97" y2="-0.635" width="0.2032" layer="21"/>
<pad name="1" x="0" y="0" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="2" x="2.54" y="0" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="3" x="5.08" y="0" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="4" x="7.62" y="0" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="5" x="10.16" y="0" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="6" x="12.7" y="0" drill="1.016" diameter="1.8796" rot="R90"/>
<text x="-1.3462" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-1.27" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="12.446" y1="-0.254" x2="12.954" y2="0.254" layer="51"/>
<rectangle x1="9.906" y1="-0.254" x2="10.414" y2="0.254" layer="51"/>
<rectangle x1="7.366" y1="-0.254" x2="7.874" y2="0.254" layer="51"/>
<rectangle x1="4.826" y1="-0.254" x2="5.334" y2="0.254" layer="51"/>
<rectangle x1="2.286" y1="-0.254" x2="2.794" y2="0.254" layer="51"/>
<rectangle x1="-0.254" y1="-0.254" x2="0.254" y2="0.254" layer="51"/>
</package>
<package name="MOLEX-1X6-RA_LOCK">
<wire x1="-1.27" y1="0.635" x2="-1.27" y2="3.175" width="0.127" layer="21"/>
<wire x1="13.97" y1="0.635" x2="13.97" y2="3.175" width="0.127" layer="21"/>
<wire x1="13.97" y1="0.635" x2="-1.27" y2="0.635" width="0.127" layer="21"/>
<wire x1="13.97" y1="3.175" x2="12.7" y2="3.175" width="0.127" layer="21"/>
<wire x1="12.7" y1="3.175" x2="0" y2="3.175" width="0.127" layer="21"/>
<wire x1="0" y1="3.175" x2="-1.27" y2="3.175" width="0.127" layer="21"/>
<wire x1="0" y1="3.175" x2="0" y2="7.62" width="0.127" layer="21"/>
<wire x1="0" y1="7.62" x2="12.7" y2="7.62" width="0.127" layer="21"/>
<wire x1="12.7" y1="7.62" x2="12.7" y2="3.175" width="0.127" layer="21"/>
<pad name="1" x="0" y="0.127" drill="1.016" diameter="1.8796" shape="square"/>
<pad name="2" x="2.54" y="-0.127" drill="1.016" diameter="1.8796"/>
<pad name="3" x="5.08" y="0.127" drill="1.016" diameter="1.8796"/>
<pad name="4" x="7.62" y="-0.127" drill="1.016" diameter="1.8796"/>
<pad name="5" x="10.16" y="0.127" drill="1.016" diameter="1.8796"/>
<pad name="6" x="12.7" y="-0.127" drill="1.016" diameter="1.8796"/>
<text x="-0.889" y="-2.794" size="1.27" layer="25">&gt;NAME</text>
<text x="8.001" y="-2.794" size="1.27" layer="25">&gt;VALUE</text>
</package>
<package name="1X06_LONGPADS">
<wire x1="-1.27" y1="0.635" x2="-1.27" y2="-0.635" width="0.2032" layer="21"/>
<wire x1="13.97" y1="0.635" x2="13.97" y2="-0.635" width="0.2032" layer="21"/>
<pad name="1" x="0" y="0" drill="1.016" diameter="1.8796" shape="long" rot="R90"/>
<pad name="2" x="2.54" y="0" drill="1.016" diameter="1.8796" shape="long" rot="R90"/>
<pad name="3" x="5.08" y="0" drill="1.016" diameter="1.8796" shape="long" rot="R90"/>
<pad name="4" x="7.62" y="0" drill="1.016" diameter="1.8796" shape="long" rot="R90"/>
<pad name="5" x="10.16" y="0" drill="1.016" diameter="1.8796" shape="long" rot="R90"/>
<pad name="6" x="12.7" y="0" drill="1.016" diameter="1.8796" shape="long" rot="R90"/>
<text x="-1.3462" y="2.4638" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-1.27" y="-3.81" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="12.446" y1="-0.254" x2="12.954" y2="0.254" layer="51"/>
<rectangle x1="9.906" y1="-0.254" x2="10.414" y2="0.254" layer="51"/>
<rectangle x1="7.366" y1="-0.254" x2="7.874" y2="0.254" layer="51"/>
<rectangle x1="4.826" y1="-0.254" x2="5.334" y2="0.254" layer="51"/>
<rectangle x1="2.286" y1="-0.254" x2="2.794" y2="0.254" layer="51"/>
<rectangle x1="-0.254" y1="-0.254" x2="0.254" y2="0.254" layer="51"/>
</package>
<package name="1X06_LOCK">
<description>This footprint was designed to help hold the alignment of a through-hole component (i.e.  6-pin header) while soldering it into place.  
You may notice that each hole has been shifted either up or down by 0.005 of an inch from it's more standard position (which is a perfectly straight line).  
This slight alteration caused the pins (the squares in the middle) to touch the edges of the holes.  Because they are alternating, it causes a "brace" 
to hold the component in place.  0.005 has proven to be the perfect amount of "off-center" position when using our standard breakaway headers.
Although looks a little odd when you look at the bare footprint, once you have a header in there, the alteration is very hard to notice.  Also,
if you push a header all the way into place, it is covered up entirely on the bottom side.  This idea of altering the position of holes to aid alignment 
will be further integrated into the Sparkfun Library for other footprints.  It can help hold any component with 3 or more connection pins.</description>
<wire x1="-1.27" y1="0.508" x2="-0.635" y2="1.143" width="0.2032" layer="21"/>
<wire x1="-0.635" y1="1.143" x2="0.635" y2="1.143" width="0.2032" layer="21"/>
<wire x1="0.635" y1="1.143" x2="1.27" y2="0.508" width="0.2032" layer="21"/>
<wire x1="1.27" y1="0.508" x2="1.905" y2="1.143" width="0.2032" layer="21"/>
<wire x1="1.905" y1="1.143" x2="3.175" y2="1.143" width="0.2032" layer="21"/>
<wire x1="3.175" y1="1.143" x2="3.81" y2="0.508" width="0.2032" layer="21"/>
<wire x1="3.81" y1="0.508" x2="4.445" y2="1.143" width="0.2032" layer="21"/>
<wire x1="4.445" y1="1.143" x2="5.715" y2="1.143" width="0.2032" layer="21"/>
<wire x1="5.715" y1="1.143" x2="6.35" y2="0.508" width="0.2032" layer="21"/>
<wire x1="6.35" y1="0.508" x2="6.985" y2="1.143" width="0.2032" layer="21"/>
<wire x1="6.985" y1="1.143" x2="8.255" y2="1.143" width="0.2032" layer="21"/>
<wire x1="8.255" y1="1.143" x2="8.89" y2="0.508" width="0.2032" layer="21"/>
<wire x1="8.89" y1="0.508" x2="9.525" y2="1.143" width="0.2032" layer="21"/>
<wire x1="9.525" y1="1.143" x2="10.795" y2="1.143" width="0.2032" layer="21"/>
<wire x1="10.795" y1="1.143" x2="11.43" y2="0.508" width="0.2032" layer="21"/>
<wire x1="11.43" y1="0.508" x2="12.065" y2="1.143" width="0.2032" layer="21"/>
<wire x1="12.065" y1="1.143" x2="13.335" y2="1.143" width="0.2032" layer="21"/>
<wire x1="13.335" y1="1.143" x2="13.97" y2="0.508" width="0.2032" layer="21"/>
<wire x1="13.97" y1="0.508" x2="13.97" y2="-0.762" width="0.2032" layer="21"/>
<wire x1="13.97" y1="-0.762" x2="13.335" y2="-1.397" width="0.2032" layer="21"/>
<wire x1="13.335" y1="-1.397" x2="12.065" y2="-1.397" width="0.2032" layer="21"/>
<wire x1="12.065" y1="-1.397" x2="11.43" y2="-0.762" width="0.2032" layer="21"/>
<wire x1="11.43" y1="-0.762" x2="10.795" y2="-1.397" width="0.2032" layer="21"/>
<wire x1="10.795" y1="-1.397" x2="9.525" y2="-1.397" width="0.2032" layer="21"/>
<wire x1="9.525" y1="-1.397" x2="8.89" y2="-0.762" width="0.2032" layer="21"/>
<wire x1="8.89" y1="-0.762" x2="8.255" y2="-1.397" width="0.2032" layer="21"/>
<wire x1="8.255" y1="-1.397" x2="6.985" y2="-1.397" width="0.2032" layer="21"/>
<wire x1="6.985" y1="-1.397" x2="6.35" y2="-0.762" width="0.2032" layer="21"/>
<wire x1="6.35" y1="-0.762" x2="5.715" y2="-1.397" width="0.2032" layer="21"/>
<wire x1="5.715" y1="-1.397" x2="4.445" y2="-1.397" width="0.2032" layer="21"/>
<wire x1="4.445" y1="-1.397" x2="3.81" y2="-0.762" width="0.2032" layer="21"/>
<wire x1="3.81" y1="-0.762" x2="3.175" y2="-1.397" width="0.2032" layer="21"/>
<wire x1="3.175" y1="-1.397" x2="1.905" y2="-1.397" width="0.2032" layer="21"/>
<wire x1="1.905" y1="-1.397" x2="1.27" y2="-0.762" width="0.2032" layer="21"/>
<wire x1="1.27" y1="-0.762" x2="0.635" y2="-1.397" width="0.2032" layer="21"/>
<wire x1="0.635" y1="-1.397" x2="-0.635" y2="-1.397" width="0.2032" layer="21"/>
<wire x1="-0.635" y1="-1.397" x2="-1.27" y2="-0.762" width="0.2032" layer="21"/>
<wire x1="-1.27" y1="-0.762" x2="-1.27" y2="0.508" width="0.2032" layer="21"/>
<wire x1="1.27" y1="0.508" x2="1.27" y2="-0.762" width="0.2032" layer="21"/>
<wire x1="3.81" y1="0.508" x2="3.81" y2="-0.762" width="0.2032" layer="21"/>
<wire x1="6.35" y1="0.508" x2="6.35" y2="-0.762" width="0.2032" layer="21"/>
<wire x1="8.89" y1="0.508" x2="8.89" y2="-0.762" width="0.2032" layer="21"/>
<wire x1="11.43" y1="0.508" x2="11.43" y2="-0.762" width="0.2032" layer="21"/>
<pad name="1" x="0" y="0" drill="1.016" diameter="1.8796"/>
<pad name="2" x="2.54" y="-0.254" drill="1.016" diameter="1.8796"/>
<pad name="3" x="5.08" y="0" drill="1.016" diameter="1.8796"/>
<pad name="4" x="7.62" y="-0.254" drill="1.016" diameter="1.8796"/>
<pad name="5" x="10.16" y="0" drill="1.016" diameter="1.8796"/>
<pad name="6" x="12.7" y="-0.254" drill="1.016" diameter="1.8796"/>
<text x="-1.27" y="1.778" size="1.27" layer="25" font="vector">&gt;NAME</text>
<text x="-1.27" y="-3.302" size="1.27" layer="27" font="vector">&gt;VALUE</text>
<rectangle x1="-0.2921" y1="-0.4191" x2="0.2921" y2="0.1651" layer="51"/>
<rectangle x1="2.2479" y1="-0.4191" x2="2.8321" y2="0.1651" layer="51"/>
<rectangle x1="4.7879" y1="-0.4191" x2="5.3721" y2="0.1651" layer="51"/>
<rectangle x1="7.3279" y1="-0.4191" x2="7.9121" y2="0.1651" layer="51"/>
<rectangle x1="9.8679" y1="-0.4191" x2="10.4521" y2="0.1651" layer="51"/>
<rectangle x1="12.4079" y1="-0.4191" x2="12.9921" y2="0.1651" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="GND">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
<symbol name="ARDUINO_SERIAL_PROGRAM">
<wire x1="1.27" y1="-7.62" x2="-7.62" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<wire x1="-1.27" y1="-2.54" x2="0" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="-1.27" y1="-5.08" x2="0" y2="-5.08" width="0.6096" layer="94"/>
<wire x1="-7.62" y1="10.16" x2="-7.62" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-7.62" x2="1.27" y2="10.16" width="0.4064" layer="94"/>
<wire x1="-7.62" y1="10.16" x2="1.27" y2="10.16" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="5.08" x2="0" y2="5.08" width="0.6096" layer="94"/>
<wire x1="-1.27" y1="2.54" x2="0" y2="2.54" width="0.6096" layer="94"/>
<wire x1="-1.27" y1="7.62" x2="0" y2="7.62" width="0.6096" layer="94"/>
<text x="-5.08" y="-10.16" size="1.778" layer="96">&gt;VALUE</text>
<text x="-5.08" y="10.922" size="1.778" layer="95">&gt;NAME</text>
<pin name="DTR" x="5.08" y="-5.08" visible="pin" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="RXI" x="5.08" y="-2.54" visible="pin" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="TXO" x="5.08" y="0" visible="pin" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="VCC" x="5.08" y="2.54" visible="pin" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="CTS" x="5.08" y="5.08" visible="pin" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="GND" x="5.08" y="7.62" visible="pin" length="middle" direction="pas" swaplevel="1" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" prefix="GND">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="ARDUINO_SERIAL_PROGRAM" prefix="JP" uservalue="yes">
<gates>
<gate name="G$1" symbol="ARDUINO_SERIAL_PROGRAM" x="0" y="-2.54"/>
</gates>
<devices>
<device name="SMD" package="1X06-SMD">
<connects>
<connect gate="G$1" pin="CTS" pad="5"/>
<connect gate="G$1" pin="DTR" pad="1"/>
<connect gate="G$1" pin="GND" pad="6"/>
<connect gate="G$1" pin="RXI" pad="2"/>
<connect gate="G$1" pin="TXO" pad="3"/>
<connect gate="G$1" pin="VCC" pad="4"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="PTH" package="1X06">
<connects>
<connect gate="G$1" pin="CTS" pad="5"/>
<connect gate="G$1" pin="DTR" pad="1"/>
<connect gate="G$1" pin="GND" pad="6"/>
<connect gate="G$1" pin="RXI" pad="2"/>
<connect gate="G$1" pin="TXO" pad="3"/>
<connect gate="G$1" pin="VCC" pad="4"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="RA_LOCK" package="MOLEX-1X6-RA_LOCK">
<connects>
<connect gate="G$1" pin="CTS" pad="2"/>
<connect gate="G$1" pin="DTR" pad="6"/>
<connect gate="G$1" pin="GND" pad="1"/>
<connect gate="G$1" pin="RXI" pad="5"/>
<connect gate="G$1" pin="TXO" pad="4"/>
<connect gate="G$1" pin="VCC" pad="3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="LONGPADS" package="1X06_LONGPADS">
<connects>
<connect gate="G$1" pin="CTS" pad="5"/>
<connect gate="G$1" pin="DTR" pad="1"/>
<connect gate="G$1" pin="GND" pad="6"/>
<connect gate="G$1" pin="RXI" pad="2"/>
<connect gate="G$1" pin="TXO" pad="3"/>
<connect gate="G$1" pin="VCC" pad="4"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="LOCK" package="1X06_LOCK">
<connects>
<connect gate="G$1" pin="CTS" pad="5"/>
<connect gate="G$1" pin="DTR" pad="1"/>
<connect gate="G$1" pin="GND" pad="6"/>
<connect gate="G$1" pin="RXI" pad="2"/>
<connect gate="G$1" pin="TXO" pad="3"/>
<connect gate="G$1" pin="VCC" pad="4"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="akafugu">
<packages>
<package name="LED5MM">
<description>&lt;B&gt;LED&lt;/B&gt;&lt;p&gt;
5 mm, round</description>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="1.905" width="0.2032" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="1.905" width="0.254" layer="21" curve="-286.260205" cap="flat"/>
<wire x1="-1.143" y1="0" x2="0" y2="1.143" width="0.1524" layer="51" curve="-90" cap="flat"/>
<wire x1="0" y1="-1.143" x2="1.143" y2="0" width="0.1524" layer="51" curve="90" cap="flat"/>
<wire x1="-1.651" y1="0" x2="0" y2="1.651" width="0.1524" layer="51" curve="-90" cap="flat"/>
<wire x1="0" y1="-1.651" x2="1.651" y2="0" width="0.1524" layer="51" curve="90" cap="flat"/>
<wire x1="-2.159" y1="0" x2="0" y2="2.159" width="0.1524" layer="51" curve="-90" cap="flat"/>
<wire x1="0" y1="-2.159" x2="2.159" y2="0" width="0.1524" layer="51" curve="90" cap="flat"/>
<circle x="0" y="0" radius="2.54" width="0.1524" layer="21"/>
<pad name="A" x="-1.27" y="0" drill="0.8128" diameter="1.8796"/>
<pad name="K" x="1.27" y="0" drill="0.8128" diameter="1.8796"/>
<text x="3.175" y="0.5334" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="3.2004" y="-1.8034" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="LED3MM">
<description>&lt;B&gt;LED&lt;/B&gt;&lt;p&gt;
3 mm, round</description>
<wire x1="1.5748" y1="-1.27" x2="1.5748" y2="1.27" width="0.254" layer="51"/>
<wire x1="0" y1="2.032" x2="1.561" y2="1.3009" width="0.254" layer="21" curve="-50.193108" cap="flat"/>
<wire x1="-1.7929" y1="0.9562" x2="0" y2="2.032" width="0.254" layer="21" curve="-61.926949" cap="flat"/>
<wire x1="0" y1="-2.032" x2="1.5512" y2="-1.3126" width="0.254" layer="21" curve="49.763022" cap="flat"/>
<wire x1="-1.7643" y1="-1.0082" x2="0" y2="-2.032" width="0.254" layer="21" curve="60.255215" cap="flat"/>
<wire x1="-2.032" y1="0" x2="-1.7891" y2="0.9634" width="0.254" layer="51" curve="-28.301701" cap="flat"/>
<wire x1="-2.032" y1="0" x2="-1.7306" y2="-1.065" width="0.254" layer="51" curve="31.60822" cap="flat"/>
<wire x1="1.5748" y1="1.2954" x2="1.5748" y2="0.7874" width="0.254" layer="21"/>
<wire x1="1.5748" y1="-1.2954" x2="1.5748" y2="-0.8382" width="0.254" layer="21"/>
<pad name="A" x="-1.27" y="0" drill="0.8128" diameter="1.8796"/>
<pad name="K" x="1.27" y="0" drill="0.8128" diameter="1.8796"/>
<text x="1.905" y="0.381" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="1.905" y="-1.651" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="LED-1206">
<wire x1="-1" y1="1" x2="-2.4" y2="1" width="0.2032" layer="21"/>
<wire x1="-2.4" y1="1" x2="-2.4" y2="-1" width="0.2032" layer="21"/>
<wire x1="-2.4" y1="-1" x2="-1" y2="-1" width="0.2032" layer="21"/>
<wire x1="1" y1="1" x2="2.4" y2="1" width="0.2032" layer="21"/>
<wire x1="2.4" y1="1" x2="2.4" y2="-1" width="0.2032" layer="21"/>
<wire x1="2.4" y1="-1" x2="1" y2="-1" width="0.2032" layer="21"/>
<wire x1="0.3" y1="0.7" x2="0.3" y2="0" width="0.2032" layer="21"/>
<wire x1="0.3" y1="0" x2="0.3" y2="-0.7" width="0.2032" layer="21"/>
<wire x1="0.3" y1="0" x2="-0.3" y2="0.6" width="0.2032" layer="21"/>
<wire x1="-0.3" y1="0.6" x2="-0.3" y2="-0.6" width="0.2032" layer="21"/>
<wire x1="-0.3" y1="-0.6" x2="0.3" y2="0" width="0.2032" layer="21"/>
<smd name="A" x="-1.5" y="0" dx="1.2" dy="1.4" layer="1"/>
<smd name="C" x="1.5" y="0" dx="1.2" dy="1.4" layer="1"/>
<text x="-0.889" y="1.397" size="0.4064" layer="25">&gt;NAME</text>
<text x="-1.016" y="-1.778" size="0.4064" layer="27">&gt;VALUE</text>
</package>
<package name="LED-0603">
<wire x1="0.17" y1="-0.46" x2="0.17" y2="0" width="0.0762" layer="21"/>
<wire x1="0.17" y1="0.46" x2="0.17" y2="0" width="0.0762" layer="21"/>
<wire x1="0.17" y1="0" x2="-0.14" y2="-0.2338" width="0.0762" layer="21"/>
<wire x1="0.1546" y1="0.0254" x2="-0.14" y2="0.2184" width="0.0762" layer="21"/>
<wire x1="-0.1524" y1="-0.2286" x2="-0.1524" y2="0.2032" width="0.0762" layer="21"/>
<smd name="C" x="0.75" y="0" dx="0.8" dy="0.8" layer="1" rot="R270"/>
<smd name="A" x="-0.75" y="0" dx="0.8" dy="0.8" layer="1" rot="R270"/>
<text x="-0.889" y="0.6985" size="0.4064" layer="25">&gt;NAME</text>
<text x="-1.016" y="-1.0795" size="0.4064" layer="27">&gt;VALUE</text>
</package>
<package name="LED10MM">
<wire x1="-5" y1="-2" x2="-5" y2="2" width="0.2032" layer="21" curve="316.862624"/>
<wire x1="-5" y1="2" x2="-5" y2="-2" width="0.2032" layer="21"/>
<pad name="A" x="2.54" y="0" drill="2.4" diameter="3.7"/>
<pad name="C" x="-2.54" y="0" drill="2.4" diameter="3.7" shape="square"/>
<text x="2.159" y="2.54" size="1.016" layer="51" ratio="15">L</text>
<text x="-2.921" y="2.54" size="1.016" layer="51" ratio="15">S</text>
</package>
<package name="LED3MM-NS">
<description>&lt;h3&gt;LED 3MM - No Silk&lt;/h3&gt;
3 mm, round</description>
<wire x1="1.5748" y1="-1.27" x2="1.5748" y2="1.27" width="0.254" layer="51"/>
<wire x1="0" y1="2.032" x2="1.561" y2="1.3009" width="0.254" layer="51" curve="-50.193108" cap="flat"/>
<wire x1="-1.7929" y1="0.9562" x2="0" y2="2.032" width="0.254" layer="51" curve="-61.926949" cap="flat"/>
<wire x1="0" y1="-2.032" x2="1.5512" y2="-1.3126" width="0.254" layer="51" curve="49.763022" cap="flat"/>
<wire x1="-1.7643" y1="-1.0082" x2="0" y2="-2.032" width="0.254" layer="51" curve="60.255215" cap="flat"/>
<wire x1="-2.032" y1="0" x2="-1.7891" y2="0.9634" width="0.254" layer="51" curve="-28.301701" cap="flat"/>
<wire x1="-2.032" y1="0" x2="-1.7306" y2="-1.065" width="0.254" layer="51" curve="31.60822" cap="flat"/>
<wire x1="1.5748" y1="1.2954" x2="1.5748" y2="0.7874" width="0.254" layer="51"/>
<wire x1="1.5748" y1="-1.2954" x2="1.5748" y2="-0.8382" width="0.254" layer="51"/>
<pad name="A" x="-1.27" y="0" drill="0.8128"/>
<pad name="K" x="1.27" y="0" drill="0.8128"/>
<text x="1.905" y="0.381" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="1.905" y="-1.651" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="LED-0805">
<wire x1="-1" y1="0.873" x2="-2.019" y2="0.873" width="0.127" layer="21"/>
<wire x1="-2.019" y1="0.873" x2="-2.019" y2="-0.873" width="0.127" layer="21"/>
<wire x1="-2.019" y1="-0.873" x2="-1" y2="-0.873" width="0.127" layer="21"/>
<wire x1="1" y1="0.873" x2="2.019" y2="0.873" width="0.127" layer="21"/>
<wire x1="2.019" y1="0.873" x2="2.019" y2="-0.873" width="0.127" layer="21"/>
<wire x1="2.019" y1="-0.873" x2="1" y2="-0.873" width="0.127" layer="21"/>
<wire x1="0.173" y1="0.446" x2="0.173" y2="0" width="0.127" layer="21"/>
<wire x1="0.173" y1="0" x2="0.173" y2="-0.446" width="0.127" layer="21"/>
<wire x1="0.173" y1="0" x2="-0.173" y2="0.346" width="0.127" layer="21"/>
<wire x1="-0.173" y1="0.346" x2="-0.173" y2="-0.346" width="0.127" layer="21"/>
<wire x1="-0.173" y1="-0.346" x2="0.173" y2="0" width="0.127" layer="21"/>
<smd name="A" x="-1.05" y="0" dx="1.2" dy="1.2" layer="1" rot="R90"/>
<smd name="C" x="1.05" y="0" dx="1.2" dy="1.2" layer="1" rot="R90"/>
<text x="-1.778" y="1.27" size="0.4064" layer="25">&gt;NAME</text>
<text x="-1.778" y="-1.524" size="0.4064" layer="27">&gt;VALUE</text>
</package>
<package name="QFN32">
<description>&lt;b&gt;QFN 32&lt;/b&gt;&lt;p&gt;
Source: http://www.ftdichip.com/Documents/DataSheets/DS_FT232R_v104.pdf</description>
<wire x1="-2.45" y1="2.45" x2="2.45" y2="2.45" width="0.1016" layer="51"/>
<wire x1="2.45" y1="2.45" x2="2.45" y2="-2.45" width="0.1016" layer="51"/>
<wire x1="2.45" y1="-2.45" x2="-2.45" y2="-2.45" width="0.1016" layer="51"/>
<wire x1="-2.45" y1="-2.45" x2="-2.45" y2="2.45" width="0.1016" layer="51"/>
<wire x1="-2.45" y1="2.05" x2="-2.45" y2="2.45" width="0.1016" layer="21"/>
<wire x1="-2.45" y1="2.45" x2="-2.05" y2="2.45" width="0.1016" layer="21"/>
<wire x1="2.05" y1="2.45" x2="2.45" y2="2.45" width="0.1016" layer="21"/>
<wire x1="2.45" y1="2.45" x2="2.45" y2="2.05" width="0.1016" layer="21"/>
<wire x1="2.45" y1="-2.05" x2="2.45" y2="-2.45" width="0.1016" layer="21"/>
<wire x1="2.45" y1="-2.45" x2="2.05" y2="-2.45" width="0.1016" layer="21"/>
<wire x1="-2.05" y1="-2.45" x2="-2.45" y2="-2.45" width="0.1016" layer="21"/>
<wire x1="-2.45" y1="-2.45" x2="-2.45" y2="-2.05" width="0.1016" layer="21"/>
<circle x="-2.175" y="2.175" radius="0.15" width="0" layer="21"/>
<smd name="EXP" x="0" y="0" dx="3.2" dy="3.2" layer="1" roundness="20" stop="no" cream="no"/>
<smd name="1" x="-2.3" y="1.75" dx="0.6" dy="0.3" layer="1" roundness="30" stop="no" cream="no"/>
<smd name="2" x="-2.3" y="1.25" dx="0.6" dy="0.3" layer="1" roundness="30" stop="no" cream="no"/>
<smd name="3" x="-2.3" y="0.75" dx="0.6" dy="0.3" layer="1" roundness="30" stop="no" cream="no"/>
<smd name="4" x="-2.3" y="0.25" dx="0.6" dy="0.3" layer="1" roundness="30" stop="no" cream="no"/>
<smd name="5" x="-2.3" y="-0.25" dx="0.6" dy="0.3" layer="1" roundness="30" stop="no" cream="no"/>
<smd name="6" x="-2.3" y="-0.75" dx="0.6" dy="0.3" layer="1" roundness="30" stop="no" cream="no"/>
<smd name="7" x="-2.3" y="-1.25" dx="0.6" dy="0.3" layer="1" roundness="30" stop="no" cream="no"/>
<smd name="8" x="-2.3" y="-1.75" dx="0.6" dy="0.3" layer="1" roundness="30" stop="no" cream="no"/>
<smd name="9" x="-1.75" y="-2.3" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R90" stop="no" cream="no"/>
<smd name="10" x="-1.25" y="-2.3" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R90" stop="no" cream="no"/>
<smd name="11" x="-0.75" y="-2.3" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R90" stop="no" cream="no"/>
<smd name="12" x="-0.25" y="-2.3" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R90" stop="no" cream="no"/>
<smd name="13" x="0.25" y="-2.3" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R90" stop="no" cream="no"/>
<smd name="14" x="0.75" y="-2.3" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R90" stop="no" cream="no"/>
<smd name="15" x="1.25" y="-2.3" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R90" stop="no" cream="no"/>
<smd name="16" x="1.75" y="-2.3" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R90" stop="no" cream="no"/>
<smd name="17" x="2.3" y="-1.75" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R180" stop="no" cream="no"/>
<smd name="18" x="2.3" y="-1.25" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R180" stop="no" cream="no"/>
<smd name="19" x="2.3" y="-0.75" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R180" stop="no" cream="no"/>
<smd name="20" x="2.3" y="-0.25" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R180" stop="no" cream="no"/>
<smd name="21" x="2.3" y="0.25" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R180" stop="no" cream="no"/>
<smd name="22" x="2.3" y="0.75" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R180" stop="no" cream="no"/>
<smd name="23" x="2.3" y="1.25" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R180" stop="no" cream="no"/>
<smd name="24" x="2.3" y="1.75" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R180" stop="no" cream="no"/>
<smd name="25" x="1.75" y="2.3" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R270" stop="no" cream="no"/>
<smd name="26" x="1.25" y="2.3" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R270" stop="no" cream="no"/>
<smd name="27" x="0.75" y="2.3" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R270" stop="no" cream="no"/>
<smd name="28" x="0.25" y="2.3" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R270" stop="no" cream="no"/>
<smd name="29" x="-0.25" y="2.3" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R270" stop="no" cream="no"/>
<smd name="30" x="-0.75" y="2.3" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R270" stop="no" cream="no"/>
<smd name="31" x="-1.25" y="2.3" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R270" stop="no" cream="no"/>
<smd name="32" x="-1.75" y="2.3" dx="0.6" dy="0.3" layer="1" roundness="30" rot="R270" stop="no" cream="no"/>
<text x="-4.05" y="-4.35" size="1.27" layer="27">&gt;VALUE</text>
<text x="-3.8" y="3.25" size="1.27" layer="25">&gt;NAME</text>
<rectangle x1="-0.3" y1="1.1" x2="0.3" y2="1.4" layer="31"/>
<rectangle x1="-0.3" y1="0.6" x2="0.3" y2="0.9" layer="31"/>
<rectangle x1="-0.3" y1="0.1" x2="0.3" y2="0.4" layer="31"/>
<rectangle x1="-0.3" y1="-0.4" x2="0.3" y2="-0.1" layer="31"/>
<rectangle x1="-0.3" y1="-0.9" x2="0.3" y2="-0.6" layer="31"/>
<rectangle x1="-0.3" y1="-1.4" x2="0.3" y2="-1.1" layer="31"/>
<rectangle x1="-1.3" y1="1.1" x2="-0.7" y2="1.4" layer="31"/>
<rectangle x1="-1.3" y1="0.6" x2="-0.7" y2="0.9" layer="31"/>
<rectangle x1="-1.3" y1="0.1" x2="-0.7" y2="0.4" layer="31"/>
<rectangle x1="-1.3" y1="-0.4" x2="-0.7" y2="-0.1" layer="31"/>
<rectangle x1="-1.3" y1="-0.9" x2="-0.7" y2="-0.6" layer="31"/>
<rectangle x1="-1.3" y1="-1.4" x2="-0.7" y2="-1.1" layer="31"/>
<rectangle x1="0.7" y1="1.1" x2="1.3" y2="1.4" layer="31"/>
<rectangle x1="0.7" y1="0.6" x2="1.3" y2="0.9" layer="31"/>
<rectangle x1="0.7" y1="0.1" x2="1.3" y2="0.4" layer="31"/>
<rectangle x1="0.7" y1="-0.4" x2="1.3" y2="-0.1" layer="31"/>
<rectangle x1="0.7" y1="-0.9" x2="1.3" y2="-0.6" layer="31"/>
<rectangle x1="0.7" y1="-1.4" x2="1.3" y2="-1.1" layer="31"/>
<polygon width="0.5" layer="29">
<vertex x="-1.325" y="1.325"/>
<vertex x="1.325" y="1.325"/>
<vertex x="1.325" y="-1.325"/>
<vertex x="-1.325" y="-1.325"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="-2.55" y="1.85"/>
<vertex x="-2.1" y="1.85"/>
<vertex x="-2.05" y="1.8"/>
<vertex x="-2.05" y="1.65"/>
<vertex x="-2.55" y="1.65"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-2.525" y="1.825"/>
<vertex x="-2.125" y="1.825"/>
<vertex x="-2.075" y="1.775"/>
<vertex x="-2.075" y="1.675"/>
<vertex x="-2.525" y="1.675"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="-2.55" y="1.35"/>
<vertex x="-2.05" y="1.35"/>
<vertex x="-2.05" y="1.15"/>
<vertex x="-2.55" y="1.15"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-2.525" y="1.325"/>
<vertex x="-2.075" y="1.325"/>
<vertex x="-2.075" y="1.175"/>
<vertex x="-2.525" y="1.175"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="-2.55" y="0.85"/>
<vertex x="-2.05" y="0.85"/>
<vertex x="-2.05" y="0.65"/>
<vertex x="-2.55" y="0.65"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-2.525" y="0.825"/>
<vertex x="-2.075" y="0.825"/>
<vertex x="-2.075" y="0.675"/>
<vertex x="-2.525" y="0.675"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="-2.55" y="0.35"/>
<vertex x="-2.05" y="0.35"/>
<vertex x="-2.05" y="0.15"/>
<vertex x="-2.55" y="0.15"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-2.525" y="0.325"/>
<vertex x="-2.075" y="0.325"/>
<vertex x="-2.075" y="0.175"/>
<vertex x="-2.525" y="0.175"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="-2.55" y="-0.15"/>
<vertex x="-2.05" y="-0.15"/>
<vertex x="-2.05" y="-0.35"/>
<vertex x="-2.55" y="-0.35"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-2.525" y="-0.175"/>
<vertex x="-2.075" y="-0.175"/>
<vertex x="-2.075" y="-0.325"/>
<vertex x="-2.525" y="-0.325"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="-2.55" y="-0.65"/>
<vertex x="-2.05" y="-0.65"/>
<vertex x="-2.05" y="-0.85"/>
<vertex x="-2.55" y="-0.85"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-2.525" y="-0.675"/>
<vertex x="-2.075" y="-0.675"/>
<vertex x="-2.075" y="-0.825"/>
<vertex x="-2.525" y="-0.825"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="-2.55" y="-1.15"/>
<vertex x="-2.05" y="-1.15"/>
<vertex x="-2.05" y="-1.35"/>
<vertex x="-2.55" y="-1.35"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-2.525" y="-1.175"/>
<vertex x="-2.075" y="-1.175"/>
<vertex x="-2.075" y="-1.325"/>
<vertex x="-2.525" y="-1.325"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="-2.55" y="-1.85"/>
<vertex x="-2.1" y="-1.85"/>
<vertex x="-2.05" y="-1.8"/>
<vertex x="-2.05" y="-1.65"/>
<vertex x="-2.55" y="-1.65"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-2.525" y="-1.825"/>
<vertex x="-2.125" y="-1.825"/>
<vertex x="-2.075" y="-1.775"/>
<vertex x="-2.075" y="-1.675"/>
<vertex x="-2.525" y="-1.675"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="-1.85" y="-2.55"/>
<vertex x="-1.85" y="-2.1"/>
<vertex x="-1.8" y="-2.05"/>
<vertex x="-1.65" y="-2.05"/>
<vertex x="-1.65" y="-2.55"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-1.825" y="-2.525"/>
<vertex x="-1.825" y="-2.125"/>
<vertex x="-1.775" y="-2.075"/>
<vertex x="-1.675" y="-2.075"/>
<vertex x="-1.675" y="-2.525"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="-1.35" y="-2.55"/>
<vertex x="-1.35" y="-2.05"/>
<vertex x="-1.15" y="-2.05"/>
<vertex x="-1.15" y="-2.55"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-1.325" y="-2.525"/>
<vertex x="-1.325" y="-2.075"/>
<vertex x="-1.175" y="-2.075"/>
<vertex x="-1.175" y="-2.525"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="-0.85" y="-2.55"/>
<vertex x="-0.85" y="-2.05"/>
<vertex x="-0.65" y="-2.05"/>
<vertex x="-0.65" y="-2.55"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-0.825" y="-2.525"/>
<vertex x="-0.825" y="-2.075"/>
<vertex x="-0.675" y="-2.075"/>
<vertex x="-0.675" y="-2.525"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="-0.35" y="-2.55"/>
<vertex x="-0.35" y="-2.05"/>
<vertex x="-0.15" y="-2.05"/>
<vertex x="-0.15" y="-2.55"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-0.325" y="-2.525"/>
<vertex x="-0.325" y="-2.075"/>
<vertex x="-0.175" y="-2.075"/>
<vertex x="-0.175" y="-2.525"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="0.15" y="-2.55"/>
<vertex x="0.15" y="-2.05"/>
<vertex x="0.35" y="-2.05"/>
<vertex x="0.35" y="-2.55"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="0.175" y="-2.525"/>
<vertex x="0.175" y="-2.075"/>
<vertex x="0.325" y="-2.075"/>
<vertex x="0.325" y="-2.525"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="0.65" y="-2.55"/>
<vertex x="0.65" y="-2.05"/>
<vertex x="0.85" y="-2.05"/>
<vertex x="0.85" y="-2.55"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="0.675" y="-2.525"/>
<vertex x="0.675" y="-2.075"/>
<vertex x="0.825" y="-2.075"/>
<vertex x="0.825" y="-2.525"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="1.15" y="-2.55"/>
<vertex x="1.15" y="-2.05"/>
<vertex x="1.35" y="-2.05"/>
<vertex x="1.35" y="-2.55"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="1.175" y="-2.525"/>
<vertex x="1.175" y="-2.075"/>
<vertex x="1.325" y="-2.075"/>
<vertex x="1.325" y="-2.525"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="1.85" y="-2.55"/>
<vertex x="1.85" y="-2.1"/>
<vertex x="1.8" y="-2.05"/>
<vertex x="1.65" y="-2.05"/>
<vertex x="1.65" y="-2.55"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="1.825" y="-2.525"/>
<vertex x="1.825" y="-2.125"/>
<vertex x="1.775" y="-2.075"/>
<vertex x="1.675" y="-2.075"/>
<vertex x="1.675" y="-2.525"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="2.55" y="-1.85"/>
<vertex x="2.1" y="-1.85"/>
<vertex x="2.05" y="-1.8"/>
<vertex x="2.05" y="-1.65"/>
<vertex x="2.55" y="-1.65"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="2.525" y="-1.825"/>
<vertex x="2.125" y="-1.825"/>
<vertex x="2.075" y="-1.775"/>
<vertex x="2.075" y="-1.675"/>
<vertex x="2.525" y="-1.675"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="2.55" y="-1.35"/>
<vertex x="2.05" y="-1.35"/>
<vertex x="2.05" y="-1.15"/>
<vertex x="2.55" y="-1.15"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="2.525" y="-1.325"/>
<vertex x="2.075" y="-1.325"/>
<vertex x="2.075" y="-1.175"/>
<vertex x="2.525" y="-1.175"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="2.55" y="-0.85"/>
<vertex x="2.05" y="-0.85"/>
<vertex x="2.05" y="-0.65"/>
<vertex x="2.55" y="-0.65"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="2.525" y="-0.825"/>
<vertex x="2.075" y="-0.825"/>
<vertex x="2.075" y="-0.675"/>
<vertex x="2.525" y="-0.675"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="2.55" y="-0.35"/>
<vertex x="2.05" y="-0.35"/>
<vertex x="2.05" y="-0.15"/>
<vertex x="2.55" y="-0.15"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="2.525" y="-0.325"/>
<vertex x="2.075" y="-0.325"/>
<vertex x="2.075" y="-0.175"/>
<vertex x="2.525" y="-0.175"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="2.55" y="0.15"/>
<vertex x="2.05" y="0.15"/>
<vertex x="2.05" y="0.35"/>
<vertex x="2.55" y="0.35"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="2.525" y="0.175"/>
<vertex x="2.075" y="0.175"/>
<vertex x="2.075" y="0.325"/>
<vertex x="2.525" y="0.325"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="2.55" y="0.65"/>
<vertex x="2.05" y="0.65"/>
<vertex x="2.05" y="0.85"/>
<vertex x="2.55" y="0.85"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="2.525" y="0.675"/>
<vertex x="2.075" y="0.675"/>
<vertex x="2.075" y="0.825"/>
<vertex x="2.525" y="0.825"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="2.55" y="1.15"/>
<vertex x="2.05" y="1.15"/>
<vertex x="2.05" y="1.35"/>
<vertex x="2.55" y="1.35"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="2.525" y="1.175"/>
<vertex x="2.075" y="1.175"/>
<vertex x="2.075" y="1.325"/>
<vertex x="2.525" y="1.325"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="2.55" y="1.85"/>
<vertex x="2.1" y="1.85"/>
<vertex x="2.05" y="1.8"/>
<vertex x="2.05" y="1.65"/>
<vertex x="2.55" y="1.65"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="2.525" y="1.825"/>
<vertex x="2.125" y="1.825"/>
<vertex x="2.075" y="1.775"/>
<vertex x="2.075" y="1.675"/>
<vertex x="2.525" y="1.675"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="1.85" y="2.55"/>
<vertex x="1.85" y="2.1"/>
<vertex x="1.8" y="2.05"/>
<vertex x="1.65" y="2.05"/>
<vertex x="1.65" y="2.55"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="1.825" y="2.525"/>
<vertex x="1.825" y="2.125"/>
<vertex x="1.775" y="2.075"/>
<vertex x="1.675" y="2.075"/>
<vertex x="1.675" y="2.525"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="1.35" y="2.55"/>
<vertex x="1.35" y="2.05"/>
<vertex x="1.15" y="2.05"/>
<vertex x="1.15" y="2.55"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="1.325" y="2.525"/>
<vertex x="1.325" y="2.075"/>
<vertex x="1.175" y="2.075"/>
<vertex x="1.175" y="2.525"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="0.85" y="2.55"/>
<vertex x="0.85" y="2.05"/>
<vertex x="0.65" y="2.05"/>
<vertex x="0.65" y="2.55"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="0.825" y="2.525"/>
<vertex x="0.825" y="2.075"/>
<vertex x="0.675" y="2.075"/>
<vertex x="0.675" y="2.525"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="0.35" y="2.55"/>
<vertex x="0.35" y="2.05"/>
<vertex x="0.15" y="2.05"/>
<vertex x="0.15" y="2.55"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="0.325" y="2.525"/>
<vertex x="0.325" y="2.075"/>
<vertex x="0.175" y="2.075"/>
<vertex x="0.175" y="2.525"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="-0.15" y="2.55"/>
<vertex x="-0.15" y="2.05"/>
<vertex x="-0.35" y="2.05"/>
<vertex x="-0.35" y="2.55"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-0.175" y="2.525"/>
<vertex x="-0.175" y="2.075"/>
<vertex x="-0.325" y="2.075"/>
<vertex x="-0.325" y="2.525"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="-0.65" y="2.55"/>
<vertex x="-0.65" y="2.05"/>
<vertex x="-0.85" y="2.05"/>
<vertex x="-0.85" y="2.55"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-0.675" y="2.525"/>
<vertex x="-0.675" y="2.075"/>
<vertex x="-0.825" y="2.075"/>
<vertex x="-0.825" y="2.525"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="-1.15" y="2.55"/>
<vertex x="-1.15" y="2.05"/>
<vertex x="-1.35" y="2.05"/>
<vertex x="-1.35" y="2.55"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-1.175" y="2.525"/>
<vertex x="-1.175" y="2.075"/>
<vertex x="-1.325" y="2.075"/>
<vertex x="-1.325" y="2.525"/>
</polygon>
<polygon width="0.1016" layer="29">
<vertex x="-1.85" y="2.55"/>
<vertex x="-1.85" y="2.1"/>
<vertex x="-1.8" y="2.05"/>
<vertex x="-1.65" y="2.05"/>
<vertex x="-1.65" y="2.55"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-1.825" y="2.525"/>
<vertex x="-1.825" y="2.125"/>
<vertex x="-1.775" y="2.075"/>
<vertex x="-1.675" y="2.075"/>
<vertex x="-1.675" y="2.525"/>
</polygon>
</package>
<package name="QFN32-LONG">
<wire x1="-2.45" y1="2.45" x2="2.45" y2="2.45" width="0.1016" layer="51"/>
<wire x1="2.45" y1="2.45" x2="2.45" y2="-2.45" width="0.1016" layer="51"/>
<wire x1="2.45" y1="-2.45" x2="-2.45" y2="-2.45" width="0.1016" layer="51"/>
<wire x1="-2.45" y1="-2.45" x2="-2.45" y2="2.45" width="0.1016" layer="51"/>
<wire x1="-2.45" y1="2.05" x2="-2.45" y2="2.45" width="0.1016" layer="21"/>
<wire x1="-2.45" y1="2.45" x2="-2.05" y2="2.45" width="0.1016" layer="21"/>
<wire x1="2.05" y1="2.45" x2="2.45" y2="2.45" width="0.1016" layer="21"/>
<wire x1="2.45" y1="2.45" x2="2.45" y2="2.05" width="0.1016" layer="21"/>
<wire x1="2.45" y1="-2.05" x2="2.45" y2="-2.45" width="0.1016" layer="21"/>
<wire x1="2.45" y1="-2.45" x2="2.05" y2="-2.45" width="0.1016" layer="21"/>
<wire x1="-2.05" y1="-2.45" x2="-2.45" y2="-2.45" width="0.1016" layer="21"/>
<wire x1="-2.45" y1="-2.45" x2="-2.45" y2="-2.05" width="0.1016" layer="21"/>
<circle x="-2.175" y="2.175" radius="0.15" width="0" layer="21"/>
<smd name="EXP" x="0" y="0" dx="3.2" dy="3.2" layer="1" roundness="20" cream="no"/>
<smd name="1" x="-2.45" y="1.75" dx="0.9" dy="0.3" layer="1" roundness="30" cream="no"/>
<smd name="2" x="-2.45" y="1.25" dx="0.9" dy="0.3" layer="1" roundness="30" cream="no"/>
<smd name="3" x="-2.45" y="0.75" dx="0.9" dy="0.3" layer="1" roundness="30" cream="no"/>
<smd name="4" x="-2.45" y="0.25" dx="0.9" dy="0.3" layer="1" roundness="30" cream="no"/>
<smd name="5" x="-2.45" y="-0.25" dx="0.9" dy="0.3" layer="1" roundness="30" cream="no"/>
<smd name="6" x="-2.45" y="-0.75" dx="0.9" dy="0.3" layer="1" roundness="30" cream="no"/>
<smd name="7" x="-2.45" y="-1.25" dx="0.9" dy="0.3" layer="1" roundness="30" cream="no"/>
<smd name="8" x="-2.45" y="-1.75" dx="0.9" dy="0.3" layer="1" roundness="30" cream="no"/>
<smd name="9" x="-1.75" y="-2.45" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R90" cream="no"/>
<smd name="10" x="-1.25" y="-2.45" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R90" cream="no"/>
<smd name="11" x="-0.75" y="-2.45" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R90" cream="no"/>
<smd name="12" x="-0.25" y="-2.45" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R90" cream="no"/>
<smd name="13" x="0.25" y="-2.45" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R90" cream="no"/>
<smd name="14" x="0.75" y="-2.45" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R90" cream="no"/>
<smd name="15" x="1.25" y="-2.45" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R90" cream="no"/>
<smd name="16" x="1.75" y="-2.45" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R90" cream="no"/>
<smd name="17" x="2.45" y="-1.75" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R180" cream="no"/>
<smd name="18" x="2.45" y="-1.25" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R180" cream="no"/>
<smd name="19" x="2.45" y="-0.75" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R180" cream="no"/>
<smd name="20" x="2.45" y="-0.25" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R180" cream="no"/>
<smd name="21" x="2.45" y="0.25" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R180" cream="no"/>
<smd name="22" x="2.45" y="0.75" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R180" cream="no"/>
<smd name="23" x="2.45" y="1.25" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R180" cream="no"/>
<smd name="24" x="2.45" y="1.75" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R180" cream="no"/>
<smd name="25" x="1.75" y="2.45" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R270" cream="no"/>
<smd name="26" x="1.25" y="2.45" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R270" cream="no"/>
<smd name="27" x="0.75" y="2.45" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R270" cream="no"/>
<smd name="28" x="0.25" y="2.45" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R270" cream="no"/>
<smd name="29" x="-0.25" y="2.45" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R270" cream="no"/>
<smd name="30" x="-0.75" y="2.45" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R270" cream="no"/>
<smd name="31" x="-1.25" y="2.45" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R270" cream="no"/>
<smd name="32" x="-1.75" y="2.45" dx="0.9" dy="0.3" layer="1" roundness="30" rot="R270" cream="no"/>
<text x="-4.05" y="-4.35" size="1.27" layer="27">&gt;VALUE</text>
<text x="-3.8" y="3.25" size="1.27" layer="25">&gt;NAME</text>
<rectangle x1="-1.2" y1="0.4" x2="-0.4" y2="1.2" layer="31"/>
<rectangle x1="-1.2" y1="-1.2" x2="-0.4" y2="-0.4" layer="31"/>
<rectangle x1="0.4" y1="0.4" x2="1.2" y2="1.2" layer="31"/>
<rectangle x1="0.4" y1="-1.2" x2="1.2" y2="-0.4" layer="31"/>
<polygon width="0.1016" layer="31">
<vertex x="-2.525" y="1.825"/>
<vertex x="-2.125" y="1.825"/>
<vertex x="-2.075" y="1.775"/>
<vertex x="-2.075" y="1.675"/>
<vertex x="-2.525" y="1.675"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-2.525" y="1.325"/>
<vertex x="-2.075" y="1.325"/>
<vertex x="-2.075" y="1.175"/>
<vertex x="-2.525" y="1.175"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-2.525" y="0.825"/>
<vertex x="-2.075" y="0.825"/>
<vertex x="-2.075" y="0.675"/>
<vertex x="-2.525" y="0.675"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-2.525" y="0.325"/>
<vertex x="-2.075" y="0.325"/>
<vertex x="-2.075" y="0.175"/>
<vertex x="-2.525" y="0.175"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-2.525" y="-0.175"/>
<vertex x="-2.075" y="-0.175"/>
<vertex x="-2.075" y="-0.325"/>
<vertex x="-2.525" y="-0.325"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-2.525" y="-0.675"/>
<vertex x="-2.075" y="-0.675"/>
<vertex x="-2.075" y="-0.825"/>
<vertex x="-2.525" y="-0.825"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-2.525" y="-1.175"/>
<vertex x="-2.075" y="-1.175"/>
<vertex x="-2.075" y="-1.325"/>
<vertex x="-2.525" y="-1.325"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-2.525" y="-1.825"/>
<vertex x="-2.125" y="-1.825"/>
<vertex x="-2.075" y="-1.775"/>
<vertex x="-2.075" y="-1.675"/>
<vertex x="-2.525" y="-1.675"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-1.825" y="-2.525"/>
<vertex x="-1.825" y="-2.125"/>
<vertex x="-1.775" y="-2.075"/>
<vertex x="-1.675" y="-2.075"/>
<vertex x="-1.675" y="-2.525"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-1.325" y="-2.525"/>
<vertex x="-1.325" y="-2.075"/>
<vertex x="-1.175" y="-2.075"/>
<vertex x="-1.175" y="-2.525"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-0.825" y="-2.525"/>
<vertex x="-0.825" y="-2.075"/>
<vertex x="-0.675" y="-2.075"/>
<vertex x="-0.675" y="-2.525"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-0.325" y="-2.525"/>
<vertex x="-0.325" y="-2.075"/>
<vertex x="-0.175" y="-2.075"/>
<vertex x="-0.175" y="-2.525"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="0.175" y="-2.525"/>
<vertex x="0.175" y="-2.075"/>
<vertex x="0.325" y="-2.075"/>
<vertex x="0.325" y="-2.525"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="0.675" y="-2.525"/>
<vertex x="0.675" y="-2.075"/>
<vertex x="0.825" y="-2.075"/>
<vertex x="0.825" y="-2.525"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="1.175" y="-2.525"/>
<vertex x="1.175" y="-2.075"/>
<vertex x="1.325" y="-2.075"/>
<vertex x="1.325" y="-2.525"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="1.825" y="-2.525"/>
<vertex x="1.825" y="-2.125"/>
<vertex x="1.775" y="-2.075"/>
<vertex x="1.675" y="-2.075"/>
<vertex x="1.675" y="-2.525"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="2.525" y="-1.825"/>
<vertex x="2.125" y="-1.825"/>
<vertex x="2.075" y="-1.775"/>
<vertex x="2.075" y="-1.675"/>
<vertex x="2.525" y="-1.675"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="2.525" y="-1.325"/>
<vertex x="2.075" y="-1.325"/>
<vertex x="2.075" y="-1.175"/>
<vertex x="2.525" y="-1.175"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="2.525" y="-0.825"/>
<vertex x="2.075" y="-0.825"/>
<vertex x="2.075" y="-0.675"/>
<vertex x="2.525" y="-0.675"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="2.525" y="-0.325"/>
<vertex x="2.075" y="-0.325"/>
<vertex x="2.075" y="-0.175"/>
<vertex x="2.525" y="-0.175"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="2.525" y="0.175"/>
<vertex x="2.075" y="0.175"/>
<vertex x="2.075" y="0.325"/>
<vertex x="2.525" y="0.325"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="2.525" y="0.675"/>
<vertex x="2.075" y="0.675"/>
<vertex x="2.075" y="0.825"/>
<vertex x="2.525" y="0.825"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="2.525" y="1.175"/>
<vertex x="2.075" y="1.175"/>
<vertex x="2.075" y="1.325"/>
<vertex x="2.525" y="1.325"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="2.525" y="1.825"/>
<vertex x="2.125" y="1.825"/>
<vertex x="2.075" y="1.775"/>
<vertex x="2.075" y="1.675"/>
<vertex x="2.525" y="1.675"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="1.825" y="2.525"/>
<vertex x="1.825" y="2.125"/>
<vertex x="1.775" y="2.075"/>
<vertex x="1.675" y="2.075"/>
<vertex x="1.675" y="2.525"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="1.325" y="2.525"/>
<vertex x="1.325" y="2.075"/>
<vertex x="1.175" y="2.075"/>
<vertex x="1.175" y="2.525"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="0.825" y="2.525"/>
<vertex x="0.825" y="2.075"/>
<vertex x="0.675" y="2.075"/>
<vertex x="0.675" y="2.525"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="0.325" y="2.525"/>
<vertex x="0.325" y="2.075"/>
<vertex x="0.175" y="2.075"/>
<vertex x="0.175" y="2.525"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-0.175" y="2.525"/>
<vertex x="-0.175" y="2.075"/>
<vertex x="-0.325" y="2.075"/>
<vertex x="-0.325" y="2.525"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-0.675" y="2.525"/>
<vertex x="-0.675" y="2.075"/>
<vertex x="-0.825" y="2.075"/>
<vertex x="-0.825" y="2.525"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-1.175" y="2.525"/>
<vertex x="-1.175" y="2.075"/>
<vertex x="-1.325" y="2.075"/>
<vertex x="-1.325" y="2.525"/>
</polygon>
<polygon width="0.1016" layer="31">
<vertex x="-1.825" y="2.525"/>
<vertex x="-1.825" y="2.125"/>
<vertex x="-1.775" y="2.075"/>
<vertex x="-1.675" y="2.075"/>
<vertex x="-1.675" y="2.525"/>
</polygon>
</package>
<package name="PTC">
<wire x1="-1.27" y1="0.635" x2="1.27" y2="0.635" width="0.127" layer="21"/>
<wire x1="1.27" y1="0.635" x2="1.27" y2="0" width="0.127" layer="21"/>
<wire x1="1.27" y1="0" x2="1.27" y2="-0.635" width="0.127" layer="21"/>
<wire x1="1.27" y1="-0.635" x2="-1.27" y2="-0.635" width="0.127" layer="21"/>
<wire x1="-1.27" y1="-0.635" x2="-1.27" y2="0" width="0.127" layer="21"/>
<wire x1="-1.27" y1="0" x2="-1.27" y2="0.635" width="0.127" layer="21"/>
<wire x1="-1.27" y1="0" x2="-1.905" y2="0" width="0.127" layer="21"/>
<wire x1="1.27" y1="0" x2="1.905" y2="0" width="0.127" layer="21"/>
<wire x1="-1.016" y1="-1.27" x2="0.762" y2="1.016" width="0.127" layer="21"/>
<wire x1="0.762" y1="1.016" x2="1.905" y2="1.016" width="0.127" layer="21"/>
<pad name="P$1" x="-2.54" y="0" drill="0.8"/>
<pad name="P$2" x="2.54" y="0" drill="0.8"/>
</package>
<package name="PTC-1206">
<wire x1="-1.5" y1="0.75" x2="1.5" y2="0.75" width="0.127" layer="51"/>
<wire x1="1.5" y1="0.75" x2="1.5" y2="-0.75" width="0.127" layer="51"/>
<wire x1="1.5" y1="-0.75" x2="-1.5" y2="-0.75" width="0.127" layer="51"/>
<wire x1="-1.5" y1="-0.75" x2="-1.5" y2="0.75" width="0.127" layer="51"/>
<wire x1="0.635" y1="-0.762" x2="-0.635" y2="-0.762" width="0.2032" layer="21"/>
<wire x1="-0.635" y1="0.762" x2="0.635" y2="0.762" width="0.2032" layer="21"/>
<wire x1="-1.143" y1="-1.016" x2="0.254" y2="1.016" width="0.127" layer="51"/>
<wire x1="0.254" y1="1.016" x2="1.143" y2="1.016" width="0.127" layer="51"/>
<smd name="1" x="-1.4" y="0" dx="1" dy="1.8" layer="1"/>
<smd name="2" x="1.4" y="0" dx="1" dy="1.8" layer="1"/>
<text x="-1.524" y="1.27" size="0.4064" layer="25">&gt;Name</text>
<text x="-1.524" y="-1.651" size="0.4064" layer="27">&gt;Value</text>
</package>
<package name="0603">
<wire x1="-1.473" y1="0.983" x2="1.473" y2="0.983" width="0.0508" layer="39"/>
<wire x1="1.473" y1="0.983" x2="1.473" y2="-0.983" width="0.0508" layer="39"/>
<wire x1="1.473" y1="-0.983" x2="-1.473" y2="-0.983" width="0.0508" layer="39"/>
<wire x1="-1.473" y1="-0.983" x2="-1.473" y2="0.983" width="0.0508" layer="39"/>
<wire x1="-0.356" y1="0.432" x2="0.356" y2="0.432" width="0.1016" layer="51"/>
<wire x1="-0.356" y1="-0.419" x2="0.356" y2="-0.419" width="0.1016" layer="51"/>
<smd name="1" x="-0.85" y="0" dx="1.1" dy="1" layer="1"/>
<smd name="2" x="0.85" y="0" dx="1.1" dy="1" layer="1"/>
<text x="-0.889" y="0.762" size="0.4064" layer="25" font="vector">&gt;NAME</text>
<text x="-1.016" y="-1.143" size="0.4064" layer="27" font="vector">&gt;VALUE</text>
<rectangle x1="-0.8382" y1="-0.4699" x2="-0.3381" y2="0.4801" layer="51"/>
<rectangle x1="0.3302" y1="-0.4699" x2="0.8303" y2="0.4801" layer="51"/>
<rectangle x1="-0.1999" y1="-0.3" x2="0.1999" y2="0.3" layer="35"/>
</package>
<package name="1206">
<wire x1="-2.473" y1="0.983" x2="2.473" y2="0.983" width="0.0508" layer="39"/>
<wire x1="2.473" y1="-0.983" x2="-2.473" y2="-0.983" width="0.0508" layer="39"/>
<wire x1="-2.473" y1="-0.983" x2="-2.473" y2="0.983" width="0.0508" layer="39"/>
<wire x1="2.473" y1="0.983" x2="2.473" y2="-0.983" width="0.0508" layer="39"/>
<wire x1="-0.965" y1="0.787" x2="0.965" y2="0.787" width="0.1016" layer="51"/>
<wire x1="-0.965" y1="-0.787" x2="0.965" y2="-0.787" width="0.1016" layer="51"/>
<smd name="1" x="-1.4" y="0" dx="1.6" dy="1.8" layer="1"/>
<smd name="2" x="1.4" y="0" dx="1.6" dy="1.8" layer="1"/>
<text x="-1.27" y="1.143" size="0.4064" layer="25">&gt;NAME</text>
<text x="-1.397" y="-1.524" size="0.4064" layer="27">&gt;VALUE</text>
<rectangle x1="-1.7018" y1="-0.8509" x2="-0.9517" y2="0.8491" layer="51"/>
<rectangle x1="0.9517" y1="-0.8491" x2="1.7018" y2="0.8509" layer="51"/>
<rectangle x1="-0.1999" y1="-0.4001" x2="0.1999" y2="0.4001" layer="35"/>
</package>
<package name="2010">
<description>&lt;b&gt;RESISTOR&lt;/b&gt;&lt;p&gt;
chip</description>
<wire x1="-1.662" y1="1.245" x2="1.662" y2="1.245" width="0.1524" layer="51"/>
<wire x1="-1.637" y1="-1.245" x2="1.687" y2="-1.245" width="0.1524" layer="51"/>
<wire x1="-3.473" y1="1.483" x2="3.473" y2="1.483" width="0.0508" layer="39"/>
<wire x1="3.473" y1="1.483" x2="3.473" y2="-1.483" width="0.0508" layer="39"/>
<wire x1="3.473" y1="-1.483" x2="-3.473" y2="-1.483" width="0.0508" layer="39"/>
<wire x1="-3.473" y1="-1.483" x2="-3.473" y2="1.483" width="0.0508" layer="39"/>
<wire x1="-1.027" y1="1.245" x2="1.027" y2="1.245" width="0.1524" layer="21"/>
<wire x1="-1.002" y1="-1.245" x2="1.016" y2="-1.245" width="0.1524" layer="21"/>
<smd name="1" x="-2.2" y="0" dx="1.8" dy="2.7" layer="1"/>
<smd name="2" x="2.2" y="0" dx="1.8" dy="2.7" layer="1"/>
<text x="-2.54" y="1.5875" size="0.4064" layer="25">&gt;NAME</text>
<text x="-2.54" y="-2.032" size="0.4064" layer="27">&gt;VALUE</text>
<rectangle x1="-2.4892" y1="-1.3208" x2="-1.6393" y2="1.3292" layer="51"/>
<rectangle x1="1.651" y1="-1.3208" x2="2.5009" y2="1.3292" layer="51"/>
</package>
<package name="R0805">
<wire x1="-0.3" y1="0.6" x2="0.3" y2="0.6" width="0.1524" layer="21"/>
<wire x1="-0.3" y1="-0.6" x2="0.3" y2="-0.6" width="0.1524" layer="21"/>
<smd name="1" x="-0.9" y="0" dx="0.8" dy="1.2" layer="1"/>
<smd name="2" x="0.9" y="0" dx="0.8" dy="1.2" layer="1"/>
<text x="-0.762" y="0.8255" size="0.4064" layer="25">&gt;NAME</text>
<text x="-1.016" y="-1.397" size="0.4064" layer="27">&gt;VALUE</text>
</package>
<package name="R0402">
<description>&lt;b&gt;CAPACITOR&lt;/b&gt;&lt;p&gt;
chip</description>
<wire x1="-0.245" y1="0.224" x2="0.245" y2="0.224" width="0.1524" layer="51"/>
<wire x1="0.245" y1="-0.224" x2="-0.245" y2="-0.224" width="0.1524" layer="51"/>
<wire x1="-1.473" y1="0.483" x2="1.473" y2="0.483" width="0.0508" layer="39"/>
<wire x1="1.473" y1="0.483" x2="1.473" y2="-0.483" width="0.0508" layer="39"/>
<wire x1="1.473" y1="-0.483" x2="-1.473" y2="-0.483" width="0.0508" layer="39"/>
<wire x1="-1.473" y1="-0.483" x2="-1.473" y2="0.483" width="0.0508" layer="39"/>
<smd name="1" x="-0.65" y="0" dx="0.7" dy="0.9" layer="1"/>
<smd name="2" x="0.65" y="0" dx="0.7" dy="0.9" layer="1"/>
<text x="-0.889" y="0.6985" size="0.4064" layer="25">&gt;NAME</text>
<text x="-1.0795" y="-1.143" size="0.4064" layer="27">&gt;VALUE</text>
<rectangle x1="-0.554" y1="-0.3048" x2="-0.254" y2="0.2951" layer="51"/>
<rectangle x1="0.2588" y1="-0.3048" x2="0.5588" y2="0.2951" layer="51"/>
<rectangle x1="-0.1999" y1="-0.3" x2="0.1999" y2="0.3" layer="35"/>
<rectangle x1="-0.2032" y1="-0.3556" x2="0.2032" y2="0.3556" layer="21"/>
</package>
<package name="1/6W-RES">
<description>1/6W Thru-hole Resistor</description>
<wire x1="-1.55" y1="0.85" x2="-1.55" y2="-0.85" width="0.2032" layer="21"/>
<wire x1="-1.55" y1="-0.85" x2="1.55" y2="-0.85" width="0.2032" layer="21"/>
<wire x1="1.55" y1="-0.85" x2="1.55" y2="0.85" width="0.2032" layer="21"/>
<wire x1="1.55" y1="0.85" x2="-1.55" y2="0.85" width="0.2032" layer="21"/>
<pad name="1" x="-2.5" y="0" drill="0.762"/>
<pad name="2" x="2.5" y="0" drill="0.762"/>
<text x="-1.2662" y="0.9552" size="0.6096" layer="25">&gt;NAME</text>
</package>
<package name="2512">
<wire x1="-2.362" y1="1.473" x2="2.387" y2="1.473" width="0.1524" layer="51"/>
<wire x1="-2.362" y1="-1.473" x2="2.387" y2="-1.473" width="0.1524" layer="51"/>
<smd name="1" x="-2.8" y="0" dx="1.8" dy="3.2" layer="1"/>
<smd name="2" x="2.8" y="0" dx="1.8" dy="3.2" layer="1"/>
<text x="-2.54" y="1.905" size="1.27" layer="25">&gt;NAME</text>
<text x="-2.54" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-3.2004" y1="-1.5494" x2="-2.3505" y2="1.5507" layer="51"/>
<rectangle x1="2.3622" y1="-1.5494" x2="3.2121" y2="1.5507" layer="51"/>
</package>
<package name="1/4W-RES">
<description>1/4W Resistor, 0.4" wide&lt;p&gt;

Yageo CFR series &lt;a href="http://www.yageo.com/pdf/yageo/Leaded-R_CFR_2008.pdf"&gt;http://www.yageo.com/pdf/yageo/Leaded-R_CFR_2008.pdf&lt;/a&gt;</description>
<wire x1="-3.15" y1="-1.2" x2="-3.15" y2="1.2" width="0.2032" layer="21"/>
<wire x1="-3.15" y1="1.2" x2="3.15" y2="1.2" width="0.2032" layer="21"/>
<wire x1="3.15" y1="1.2" x2="3.15" y2="-1.2" width="0.2032" layer="21"/>
<wire x1="3.15" y1="-1.2" x2="-3.15" y2="-1.2" width="0.2032" layer="21"/>
<pad name="P$1" x="-5.08" y="0" drill="0.9" diameter="1.8796"/>
<pad name="P$2" x="5.08" y="0" drill="0.9" diameter="1.8796"/>
<text x="-3.175" y="1.905" size="0.8128" layer="25" font="vector" ratio="15">&gt;Name</text>
</package>
<package name="1/2W-RES">
<description>1/2W Resistor, 0.5" wide&lt;p&gt;

Yageo CFR series &lt;a href="http://www.yageo.com/pdf/yageo/Leaded-R_CFR_2008.pdf"&gt;http://www.yageo.com/pdf/yageo/Leaded-R_CFR_2008.pdf&lt;/a&gt;</description>
<wire x1="-4.5" y1="-1.65" x2="-4.5" y2="1.65" width="0.2032" layer="21"/>
<wire x1="-4.5" y1="1.65" x2="4.5" y2="1.65" width="0.2032" layer="21"/>
<wire x1="4.5" y1="1.65" x2="4.5" y2="-1.65" width="0.2032" layer="21"/>
<wire x1="4.5" y1="-1.65" x2="-4.5" y2="-1.65" width="0.2032" layer="21"/>
<pad name="P$1" x="-6.35" y="0" drill="0.9" diameter="1.8796"/>
<pad name="P$2" x="6.35" y="0" drill="0.9" diameter="1.8796"/>
<text x="-4.445" y="2.54" size="0.8128" layer="25" font="vector" ratio="15">&gt;Name</text>
<text x="0.635" y="2.54" size="0.8128" layer="27" font="vector" ratio="15">&gt;Value</text>
</package>
<package name="1/4W-RES-OUTLINE">
<wire x1="5.08" y1="0" x2="4.064" y2="0" width="0.6096" layer="51"/>
<wire x1="-5.08" y1="0" x2="-4.064" y2="0" width="0.6096" layer="51"/>
<wire x1="-3.175" y1="0.889" x2="-2.921" y2="1.143" width="0.1524" layer="21" curve="-90"/>
<wire x1="-3.175" y1="-0.889" x2="-2.921" y2="-1.143" width="0.1524" layer="21" curve="90"/>
<wire x1="2.921" y1="-1.143" x2="3.175" y2="-0.889" width="0.1524" layer="21" curve="90"/>
<wire x1="2.921" y1="1.143" x2="3.175" y2="0.889" width="0.1524" layer="21" curve="-90"/>
<wire x1="-3.175" y1="-0.889" x2="-3.175" y2="0.889" width="0.1524" layer="21"/>
<wire x1="-2.921" y1="1.143" x2="-2.54" y2="1.143" width="0.1524" layer="21"/>
<wire x1="-2.413" y1="1.016" x2="-2.54" y2="1.143" width="0.1524" layer="21"/>
<wire x1="-2.921" y1="-1.143" x2="-2.54" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="-2.413" y1="-1.016" x2="-2.54" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="2.413" y1="1.016" x2="2.54" y2="1.143" width="0.1524" layer="21"/>
<wire x1="2.413" y1="1.016" x2="-2.413" y2="1.016" width="0.1524" layer="21"/>
<wire x1="2.413" y1="-1.016" x2="2.54" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="2.413" y1="-1.016" x2="-2.413" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="2.921" y1="1.143" x2="2.54" y2="1.143" width="0.1524" layer="21"/>
<wire x1="2.921" y1="-1.143" x2="2.54" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-0.889" x2="3.175" y2="0.889" width="0.1524" layer="21"/>
<wire x1="-1.973" y1="0.983" x2="1.973" y2="0.983" width="0.0508" layer="39"/>
<wire x1="1.973" y1="-0.983" x2="-1.973" y2="-0.983" width="0.0508" layer="39"/>
<pad name="P$1" x="-5.08" y="0" drill="0.9" diameter="1.8796"/>
<pad name="P$2" x="5.08" y="0" drill="0.9" diameter="1.8796"/>
<text x="-3.048" y="1.524" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-3.1306" y="-2.775" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<rectangle x1="3.175" y1="-0.3048" x2="4.0386" y2="0.3048" layer="21"/>
<rectangle x1="-4.0386" y1="-0.3048" x2="-3.175" y2="0.3048" layer="21"/>
</package>
<package name="1/6W-RES-OUTLINE">
<wire x1="2.5401" y1="0" x2="1.778" y2="0" width="0.4572" layer="51"/>
<wire x1="-1.27" y1="0.5715" x2="-1.016" y2="0.8255" width="0.1524" layer="21" curve="-90"/>
<wire x1="-1.27" y1="-0.5715" x2="-1.016" y2="-0.8255" width="0.1524" layer="21" curve="90"/>
<wire x1="1.016" y1="-0.8255" x2="1.2699" y2="-0.5715" width="0.1524" layer="21" curve="90.067712"/>
<wire x1="1.016" y1="0.8255" x2="1.2699" y2="0.5715" width="0.1524" layer="21" curve="-90.067712"/>
<wire x1="-1.27" y1="-0.5715" x2="-1.27" y2="0.5715" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="0.8255" x2="-0.635" y2="0.8255" width="0.1524" layer="21"/>
<wire x1="-0.5081" y1="0.6985" x2="-0.635" y2="0.8255" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="-0.8255" x2="-0.635" y2="-0.8255" width="0.1524" layer="21"/>
<wire x1="-0.5081" y1="-0.6985" x2="-0.635" y2="-0.8255" width="0.1524" layer="21"/>
<wire x1="0.508" y1="0.6985" x2="0.6349" y2="0.8255" width="0.1524" layer="21"/>
<wire x1="0.508" y1="0.6985" x2="-0.5081" y2="0.6985" width="0.1524" layer="21"/>
<wire x1="0.508" y1="-0.6985" x2="0.6349" y2="-0.8255" width="0.1524" layer="21"/>
<wire x1="0.508" y1="-0.6985" x2="-0.5081" y2="-0.6985" width="0.1524" layer="21"/>
<wire x1="1.016" y1="0.8255" x2="0.6349" y2="0.8255" width="0.1524" layer="21"/>
<wire x1="1.016" y1="-0.8255" x2="0.6349" y2="-0.8255" width="0.1524" layer="21"/>
<wire x1="1.2699" y1="-0.5715" x2="1.2699" y2="0.5715" width="0.1524" layer="21"/>
<pad name="1" x="-2.5" y="0" drill="0.762"/>
<pad name="2" x="2.5" y="0" drill="0.762"/>
<rectangle x1="-1.8161" y1="-0.2032" x2="-1.27" y2="0.2032" layer="21"/>
<rectangle x1="1.27" y1="-0.2032" x2="1.816" y2="0.2032" layer="21" rot="R180"/>
</package>
<package name="1/2W-RES-OUTLINE">
<wire x1="6.35" y1="0" x2="5.334" y2="0" width="0.6096" layer="51"/>
<wire x1="-6.35" y1="0" x2="-5.334" y2="0" width="0.6096" layer="51"/>
<wire x1="-4.572" y1="1.397" x2="-4.318" y2="1.651" width="0.1524" layer="21" curve="-90"/>
<wire x1="-4.572" y1="-1.397" x2="-4.318" y2="-1.651" width="0.1524" layer="21" curve="90"/>
<wire x1="4.318" y1="-1.651" x2="4.572" y2="-1.397" width="0.1524" layer="21" curve="90"/>
<wire x1="4.318" y1="1.651" x2="4.572" y2="1.397" width="0.1524" layer="21" curve="-90"/>
<wire x1="-4.572" y1="-1.397" x2="-4.572" y2="1.397" width="0.1524" layer="21"/>
<wire x1="-4.318" y1="1.651" x2="-3.937" y2="1.651" width="0.1524" layer="21"/>
<wire x1="-3.683" y1="1.397" x2="-3.937" y2="1.651" width="0.1524" layer="21"/>
<wire x1="-4.318" y1="-1.651" x2="-3.937" y2="-1.651" width="0.1524" layer="21"/>
<wire x1="-3.683" y1="-1.397" x2="-3.937" y2="-1.651" width="0.1524" layer="21"/>
<wire x1="3.683" y1="1.397" x2="3.937" y2="1.651" width="0.1524" layer="21"/>
<wire x1="3.683" y1="1.397" x2="-3.683" y2="1.397" width="0.1524" layer="21"/>
<wire x1="3.683" y1="-1.397" x2="3.937" y2="-1.651" width="0.1524" layer="21"/>
<wire x1="3.683" y1="-1.397" x2="-3.683" y2="-1.397" width="0.1524" layer="21"/>
<wire x1="4.318" y1="1.651" x2="3.937" y2="1.651" width="0.1524" layer="21"/>
<wire x1="4.318" y1="-1.651" x2="3.937" y2="-1.651" width="0.1524" layer="21"/>
<wire x1="4.572" y1="-1.397" x2="4.572" y2="1.397" width="0.1524" layer="21"/>
<pad name="P$1" x="-6.35" y="0" drill="0.9" diameter="1.8796"/>
<pad name="P$2" x="6.35" y="0" drill="0.9" diameter="1.8796"/>
<text x="-4.445" y="2.54" size="0.8128" layer="25" font="vector" ratio="15">&gt;Name</text>
<text x="0.635" y="2.54" size="0.8128" layer="27" font="vector" ratio="15">&gt;Value</text>
<rectangle x1="4.572" y1="-0.3048" x2="5.4356" y2="0.3048" layer="21"/>
<rectangle x1="-5.4356" y1="-0.3048" x2="-4.572" y2="0.3048" layer="21"/>
</package>
<package name="CAP-PTH-2.54MM">
<wire x1="1.27" y1="0.635" x2="1.27" y2="-0.635" width="0.2032" layer="21"/>
<pad name="1" x="0" y="0" drill="0.7" diameter="1.651"/>
<pad name="2" x="2.54" y="0" drill="0.7" diameter="1.651"/>
<text x="0.508" y="1.27" size="0.4064" layer="25">&gt;Name</text>
<text x="0.254" y="-1.524" size="0.4064" layer="27">&gt;Value</text>
</package>
<package name="CAP-PTH-5MM">
<wire x1="0" y1="0.635" x2="0" y2="-0.635" width="0.2032" layer="21"/>
<pad name="1" x="-2.5" y="0" drill="0.7" diameter="1.651"/>
<pad name="2" x="2.5" y="0" drill="0.7" diameter="1.651"/>
<text x="-0.762" y="1.27" size="0.4064" layer="25">&gt;Name</text>
<text x="-1.016" y="-1.524" size="0.4064" layer="27">&gt;Value</text>
</package>
<package name="1210">
<wire x1="-1.6" y1="1.3" x2="1.6" y2="1.3" width="0.127" layer="51"/>
<wire x1="1.6" y1="1.3" x2="1.6" y2="-1.3" width="0.127" layer="51"/>
<wire x1="1.6" y1="-1.3" x2="-1.6" y2="-1.3" width="0.127" layer="51"/>
<wire x1="-1.6" y1="-1.3" x2="-1.6" y2="1.3" width="0.127" layer="51"/>
<wire x1="-1.6" y1="1.3" x2="1.6" y2="1.3" width="0.2032" layer="21"/>
<wire x1="-1.6" y1="-1.3" x2="1.6" y2="-1.3" width="0.2032" layer="21"/>
<smd name="1" x="-1.6" y="0" dx="1.2" dy="2" layer="1"/>
<smd name="2" x="1.6" y="0" dx="1.2" dy="2" layer="1"/>
<text x="-0.8" y="0.5" size="0.4064" layer="25">&gt;NAME</text>
<text x="-0.9" y="-0.7" size="0.4064" layer="27">&gt;VALUE</text>
</package>
<package name="0805-CAP">
<wire x1="-0.3" y1="0.6" x2="0.3" y2="0.6" width="0.1524" layer="21"/>
<wire x1="-0.3" y1="-0.6" x2="0.3" y2="-0.6" width="0.1524" layer="21"/>
<smd name="1" x="-0.9" y="0" dx="0.8" dy="1.2" layer="1"/>
<smd name="2" x="0.9" y="0" dx="0.8" dy="1.2" layer="1"/>
<text x="-0.762" y="0.8255" size="0.4064" layer="25">&gt;NAME</text>
<text x="-1.016" y="-1.397" size="0.4064" layer="27">&gt;VALUE</text>
</package>
<package name="0402-CAP">
<wire x1="-0.245" y1="0.224" x2="0.245" y2="0.224" width="0.1524" layer="51"/>
<wire x1="0.245" y1="-0.224" x2="-0.245" y2="-0.224" width="0.1524" layer="51"/>
<wire x1="-1.473" y1="0.483" x2="1.473" y2="0.483" width="0.0508" layer="39"/>
<wire x1="1.473" y1="0.483" x2="1.473" y2="-0.483" width="0.0508" layer="39"/>
<wire x1="1.473" y1="-0.483" x2="-1.473" y2="-0.483" width="0.0508" layer="39"/>
<wire x1="-1.473" y1="-0.483" x2="-1.473" y2="0.483" width="0.0508" layer="39"/>
<smd name="1" x="-0.65" y="0" dx="0.7" dy="0.9" layer="1"/>
<smd name="2" x="0.65" y="0" dx="0.7" dy="0.9" layer="1"/>
<text x="-0.889" y="0.6985" size="0.4064" layer="25">&gt;NAME</text>
<text x="-1.0795" y="-1.143" size="0.4064" layer="27">&gt;VALUE</text>
<rectangle x1="-0.554" y1="-0.3048" x2="-0.254" y2="0.2951" layer="51"/>
<rectangle x1="0.2588" y1="-0.3048" x2="0.5588" y2="0.2951" layer="51"/>
<rectangle x1="-0.1999" y1="-0.3" x2="0.1999" y2="0.3" layer="35"/>
<rectangle x1="-0.2032" y1="-0.3556" x2="0.2032" y2="0.3556" layer="21"/>
</package>
<package name="SJ-3">
<wire x1="1.2065" y1="-1.016" x2="-1.2065" y2="-1.016" width="0.2032" layer="21"/>
<wire x1="1.2065" y1="1.016" x2="1.4605" y2="0.762" width="0.2032" layer="21" curve="-90"/>
<wire x1="-1.4605" y1="0.762" x2="-1.2065" y2="1.016" width="0.2032" layer="21" curve="-90"/>
<wire x1="-1.4605" y1="-0.762" x2="-1.2065" y2="-1.016" width="0.2032" layer="21" curve="90"/>
<wire x1="1.2065" y1="-1.016" x2="1.4605" y2="-0.762" width="0.2032" layer="21" curve="90"/>
<wire x1="-1.2065" y1="1.016" x2="1.2065" y2="1.016" width="0.2032" layer="21"/>
<smd name="1" x="-0.889" y="0" dx="0.635" dy="1.27" layer="1" cream="no"/>
<smd name="2" x="0" y="0" dx="0.635" dy="1.27" layer="1" cream="no"/>
<smd name="3" x="0.889" y="0" dx="0.635" dy="1.27" layer="1" cream="no"/>
<text x="-1.27" y="1.27" size="0.4064" layer="25">&gt;NAME</text>
<text x="-1.27" y="-1.905" size="0.4064" layer="27">&gt;VALUE</text>
</package>
<package name="SJ-3-LEFT">
<wire x1="1.2065" y1="-1.016" x2="-1.2065" y2="-1.016" width="0.2032" layer="21"/>
<wire x1="1.2065" y1="1.016" x2="1.4605" y2="0.762" width="0.2032" layer="21" curve="-90"/>
<wire x1="-1.4605" y1="0.762" x2="-1.2065" y2="1.016" width="0.2032" layer="21" curve="-90"/>
<wire x1="-1.4605" y1="-0.762" x2="-1.2065" y2="-1.016" width="0.2032" layer="21" curve="90"/>
<wire x1="1.2065" y1="-1.016" x2="1.4605" y2="-0.762" width="0.2032" layer="21" curve="90"/>
<wire x1="-1.2065" y1="1.016" x2="1.2065" y2="1.016" width="0.2032" layer="21"/>
<wire x1="-0.889" y1="0" x2="0" y2="0" width="0.2032" layer="1"/>
<smd name="1" x="-0.889" y="0" dx="0.635" dy="1.27" layer="1" cream="no"/>
<smd name="2" x="0" y="0" dx="0.635" dy="1.27" layer="1" cream="no"/>
<smd name="3" x="0.889" y="0" dx="0.635" dy="1.27" layer="1" cream="no"/>
<text x="-1.27" y="1.27" size="0.4064" layer="25">&gt;NAME</text>
<text x="-1.27" y="-1.905" size="0.4064" layer="27">&gt;VALUE</text>
</package>
<package name="SJ-3-RIGHT">
<wire x1="1.2065" y1="-1.016" x2="-1.2065" y2="-1.016" width="0.2032" layer="21"/>
<wire x1="1.2065" y1="1.016" x2="1.4605" y2="0.762" width="0.2032" layer="21" curve="-90"/>
<wire x1="-1.4605" y1="0.762" x2="-1.2065" y2="1.016" width="0.2032" layer="21" curve="-90"/>
<wire x1="-1.4605" y1="-0.762" x2="-1.2065" y2="-1.016" width="0.2032" layer="21" curve="90"/>
<wire x1="1.2065" y1="-1.016" x2="1.4605" y2="-0.762" width="0.2032" layer="21" curve="90"/>
<wire x1="-1.2065" y1="1.016" x2="1.2065" y2="1.016" width="0.2032" layer="21"/>
<wire x1="0" y1="0" x2="0.889" y2="0" width="0.2032" layer="1"/>
<smd name="1" x="-0.889" y="0" dx="0.635" dy="1.27" layer="1" cream="no"/>
<smd name="2" x="0" y="0" dx="0.635" dy="1.27" layer="1" cream="no"/>
<smd name="3" x="0.889" y="0" dx="0.635" dy="1.27" layer="1" cream="no"/>
<text x="-1.27" y="1.27" size="0.4064" layer="25">&gt;NAME</text>
<text x="-1.27" y="-1.905" size="0.4064" layer="27">&gt;VALUE</text>
</package>
<package name="1X03">
<wire x1="3.81" y1="0.635" x2="4.445" y2="1.27" width="0.2032" layer="21"/>
<wire x1="4.445" y1="1.27" x2="5.715" y2="1.27" width="0.2032" layer="21"/>
<wire x1="5.715" y1="1.27" x2="6.35" y2="0.635" width="0.2032" layer="21"/>
<wire x1="6.35" y1="-0.635" x2="5.715" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="5.715" y1="-1.27" x2="4.445" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="4.445" y1="-1.27" x2="3.81" y2="-0.635" width="0.2032" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="0.635" y2="1.27" width="0.2032" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.27" y2="0.635" width="0.2032" layer="21"/>
<wire x1="1.27" y1="-0.635" x2="0.635" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="1.27" y1="0.635" x2="1.905" y2="1.27" width="0.2032" layer="21"/>
<wire x1="1.905" y1="1.27" x2="3.175" y2="1.27" width="0.2032" layer="21"/>
<wire x1="3.175" y1="1.27" x2="3.81" y2="0.635" width="0.2032" layer="21"/>
<wire x1="3.81" y1="-0.635" x2="3.175" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="3.175" y1="-1.27" x2="1.905" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="1.905" y1="-1.27" x2="1.27" y2="-0.635" width="0.2032" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-1.27" y2="-0.635" width="0.2032" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="-1.27" y2="0.635" width="0.2032" layer="21"/>
<wire x1="-1.27" y1="-0.635" x2="-0.635" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="-0.635" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="6.35" y1="0.635" x2="6.35" y2="-0.635" width="0.2032" layer="21"/>
<pad name="1" x="0" y="0" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="2" x="2.54" y="0" drill="1.016" diameter="1.8796" rot="R90"/>
<pad name="3" x="5.08" y="0" drill="1.016" diameter="1.8796" rot="R90"/>
<text x="-1.3462" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-1.27" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="4.826" y1="-0.254" x2="5.334" y2="0.254" layer="51"/>
<rectangle x1="2.286" y1="-0.254" x2="2.794" y2="0.254" layer="51"/>
<rectangle x1="-0.254" y1="-0.254" x2="0.254" y2="0.254" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="LED">
<wire x1="1.27" y1="0" x2="0" y2="-2.54" width="0.254" layer="94"/>
<wire x1="0" y1="-2.54" x2="-1.27" y2="0" width="0.254" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="0" y2="-2.54" width="0.254" layer="94"/>
<wire x1="0" y1="-2.54" x2="-1.27" y2="-2.54" width="0.254" layer="94"/>
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="0" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="-2.032" y1="-0.762" x2="-3.429" y2="-2.159" width="0.1524" layer="94"/>
<wire x1="-1.905" y1="-1.905" x2="-3.302" y2="-3.302" width="0.1524" layer="94"/>
<text x="3.556" y="-4.572" size="1.778" layer="95" rot="R90">&gt;NAME</text>
<text x="5.715" y="-4.572" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="C" x="0" y="-5.08" visible="off" length="short" direction="pas" rot="R90"/>
<pin name="A" x="0" y="2.54" visible="off" length="short" direction="pas" rot="R270"/>
<polygon width="0.1524" layer="94">
<vertex x="-3.429" y="-2.159"/>
<vertex x="-3.048" y="-1.27"/>
<vertex x="-2.54" y="-1.778"/>
</polygon>
<polygon width="0.1524" layer="94">
<vertex x="-3.302" y="-3.302"/>
<vertex x="-2.921" y="-2.413"/>
<vertex x="-2.413" y="-2.921"/>
</polygon>
</symbol>
<symbol name="FT232R-BASIC-PAD">
<wire x1="-10.16" y1="15.24" x2="10.16" y2="15.24" width="0.254" layer="94"/>
<wire x1="10.16" y1="15.24" x2="10.16" y2="-17.78" width="0.254" layer="94"/>
<wire x1="10.16" y1="-17.78" x2="-10.16" y2="-17.78" width="0.254" layer="94"/>
<wire x1="-10.16" y1="-17.78" x2="-10.16" y2="15.24" width="0.254" layer="94"/>
<text x="-7.62" y="15.748" size="1.778" layer="95">&gt;NAME</text>
<text x="-7.62" y="-20.32" size="1.778" layer="96">&gt;VALUE</text>
<pin name="3V3OUT" x="-15.24" y="2.54" length="middle" direction="out"/>
<pin name="USBDM" x="-15.24" y="12.7" length="middle"/>
<pin name="USBDP" x="-15.24" y="10.16" length="middle"/>
<pin name="GND1" x="-15.24" y="-10.16" length="middle" direction="pwr"/>
<pin name="GND2" x="-15.24" y="-12.7" length="middle" direction="pwr"/>
<pin name="GND3" x="-15.24" y="-15.24" length="middle" direction="pwr"/>
<pin name="TXD" x="15.24" y="12.7" length="middle" direction="out" rot="R180"/>
<pin name="RXD" x="15.24" y="10.16" length="middle" direction="in" rot="R180"/>
<pin name="VCCIO" x="-15.24" y="0" length="middle" direction="pwr"/>
<pin name="AGND" x="-15.24" y="-7.62" length="middle" direction="pwr"/>
<pin name="TEST" x="-15.24" y="-5.08" length="middle" direction="in"/>
<pin name="VCC" x="-15.24" y="5.08" length="middle" direction="pwr"/>
<pin name="TXLED" x="15.24" y="-12.7" length="middle" function="dot" rot="R180"/>
<pin name="RXLED" x="15.24" y="-15.24" length="middle" function="dot" rot="R180"/>
<pin name="RTS" x="15.24" y="2.54" length="middle" function="dot" rot="R180"/>
<pin name="CTS" x="15.24" y="5.08" length="middle" function="dot" rot="R180"/>
<pin name="DTR" x="15.24" y="0" length="middle" function="dot" rot="R180"/>
<pin name="PAD" x="15.24" y="-5.08" length="middle" rot="R180"/>
</symbol>
<symbol name="PTC">
<wire x1="5.08" y1="1.27" x2="5.08" y2="-1.27" width="0.254" layer="94"/>
<wire x1="5.08" y1="-1.27" x2="-2.54" y2="-1.27" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-1.27" x2="-2.54" y2="1.27" width="0.254" layer="94"/>
<wire x1="-2.54" y1="1.27" x2="5.08" y2="1.27" width="0.254" layer="94"/>
<wire x1="-1.524" y1="-2.54" x2="3.81" y2="2.54" width="0.254" layer="94"/>
<wire x1="3.81" y1="2.54" x2="5.08" y2="2.54" width="0.254" layer="94"/>
<text x="-2.54" y="3.048" size="1.778" layer="95">&gt;NAME</text>
<text x="-3.302" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-5.08" y="0" visible="off" length="short"/>
<pin name="2" x="7.62" y="0" visible="off" length="short" rot="R180"/>
</symbol>
<symbol name="RESISTOR">
<wire x1="-2.54" y1="0" x2="-2.159" y2="1.016" width="0.1524" layer="94"/>
<wire x1="-2.159" y1="1.016" x2="-1.524" y2="-1.016" width="0.1524" layer="94"/>
<wire x1="-1.524" y1="-1.016" x2="-0.889" y2="1.016" width="0.1524" layer="94"/>
<wire x1="-0.889" y1="1.016" x2="-0.254" y2="-1.016" width="0.1524" layer="94"/>
<wire x1="-0.254" y1="-1.016" x2="0.381" y2="1.016" width="0.1524" layer="94"/>
<wire x1="0.381" y1="1.016" x2="1.016" y2="-1.016" width="0.1524" layer="94"/>
<wire x1="1.016" y1="-1.016" x2="1.651" y2="1.016" width="0.1524" layer="94"/>
<wire x1="1.651" y1="1.016" x2="2.286" y2="-1.016" width="0.1524" layer="94"/>
<wire x1="2.286" y1="-1.016" x2="2.54" y2="0" width="0.1524" layer="94"/>
<text x="-3.81" y="1.4986" size="1.778" layer="95">&gt;NAME</text>
<text x="-3.81" y="-3.302" size="1.778" layer="96">&gt;VALUE</text>
<pin name="2" x="5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1" rot="R180"/>
<pin name="1" x="-5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1"/>
</symbol>
<symbol name="CAP">
<wire x1="0" y1="2.54" x2="0" y2="2.032" width="0.1524" layer="94"/>
<wire x1="0" y1="0" x2="0" y2="0.508" width="0.1524" layer="94"/>
<text x="1.524" y="2.921" size="1.778" layer="95">&gt;NAME</text>
<text x="1.524" y="-2.159" size="1.778" layer="96">&gt;VALUE</text>
<rectangle x1="-2.032" y1="0.508" x2="2.032" y2="1.016" layer="94"/>
<rectangle x1="-2.032" y1="1.524" x2="2.032" y2="2.032" layer="94"/>
<pin name="1" x="0" y="5.08" visible="off" length="short" direction="pas" swaplevel="1" rot="R270"/>
<pin name="2" x="0" y="-2.54" visible="off" length="short" direction="pas" swaplevel="1" rot="R90"/>
</symbol>
<symbol name="SJ_2">
<wire x1="-0.635" y1="-1.397" x2="0.635" y2="-1.397" width="1.27" layer="94" curve="180" cap="flat"/>
<wire x1="-0.635" y1="1.397" x2="0.635" y2="1.397" width="1.27" layer="94" curve="-180" cap="flat"/>
<wire x1="1.27" y1="-0.635" x2="-1.27" y2="-0.635" width="0.1524" layer="94"/>
<wire x1="-1.27" y1="-0.635" x2="-1.27" y2="0" width="0.1524" layer="94"/>
<wire x1="-1.27" y1="0" x2="-1.27" y2="0.635" width="0.1524" layer="94"/>
<wire x1="-1.27" y1="0.635" x2="1.27" y2="0.635" width="0.1524" layer="94"/>
<wire x1="1.27" y1="0.635" x2="1.27" y2="-0.635" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="0" x2="-1.27" y2="0" width="0.1524" layer="94"/>
<text x="2.54" y="0.381" size="1.778" layer="95">&gt;NAME</text>
<text x="2.54" y="-1.905" size="1.778" layer="96">&gt;VALUE</text>
<rectangle x1="-1.27" y1="-0.635" x2="1.27" y2="0.635" layer="94"/>
<pin name="3" x="0" y="-5.08" visible="off" length="short" direction="pas" rot="R90"/>
<pin name="1" x="0" y="5.08" visible="off" length="short" direction="pas" rot="R270"/>
<pin name="2" x="-5.08" y="0" visible="off" length="short" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="LED" prefix="LED" uservalue="yes">
<description>&lt;b&gt;LEDs&lt;/b&gt;
Standard schematic elements and footprints for 5mm, 3mm, 1206, and 0603 sized LEDs. 5mm - Spark Fun Electronics SKU : COM-00529 (and others)</description>
<gates>
<gate name="G$1" symbol="LED" x="0" y="0"/>
</gates>
<devices>
<device name="5MM" package="LED5MM">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="C" pad="K"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="3MM" package="LED3MM">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="C" pad="K"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="1206" package="LED-1206">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="C" pad="C"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="0603" package="LED-0603">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="C" pad="C"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="10MM" package="LED10MM">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="C" pad="C"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-3MM-NO_SILK" package="LED3MM-NS">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="C" pad="K"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="0805" package="LED-0805">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="C" pad="C"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="FT232R-BASIC-PAD">
<gates>
<gate name="G$1" symbol="FT232R-BASIC-PAD" x="0" y="0"/>
</gates>
<devices>
<device name="-Q" package="QFN32">
<connects>
<connect gate="G$1" pin="3V3OUT" pad="16"/>
<connect gate="G$1" pin="AGND" pad="24"/>
<connect gate="G$1" pin="CTS" pad="8"/>
<connect gate="G$1" pin="DTR" pad="31"/>
<connect gate="G$1" pin="GND1" pad="4"/>
<connect gate="G$1" pin="GND2" pad="17"/>
<connect gate="G$1" pin="GND3" pad="20"/>
<connect gate="G$1" pin="PAD" pad="EXP"/>
<connect gate="G$1" pin="RTS" pad="32"/>
<connect gate="G$1" pin="RXD" pad="2"/>
<connect gate="G$1" pin="RXLED" pad="21"/>
<connect gate="G$1" pin="TEST" pad="26"/>
<connect gate="G$1" pin="TXD" pad="30"/>
<connect gate="G$1" pin="TXLED" pad="22"/>
<connect gate="G$1" pin="USBDM" pad="15"/>
<connect gate="G$1" pin="USBDP" pad="14"/>
<connect gate="G$1" pin="VCC" pad="19"/>
<connect gate="G$1" pin="VCCIO" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-Q-LONGPADS" package="QFN32-LONG">
<connects>
<connect gate="G$1" pin="3V3OUT" pad="16"/>
<connect gate="G$1" pin="AGND" pad="24"/>
<connect gate="G$1" pin="CTS" pad="8"/>
<connect gate="G$1" pin="DTR" pad="31"/>
<connect gate="G$1" pin="GND1" pad="4"/>
<connect gate="G$1" pin="GND2" pad="17"/>
<connect gate="G$1" pin="GND3" pad="20"/>
<connect gate="G$1" pin="PAD" pad="EXP"/>
<connect gate="G$1" pin="RTS" pad="32"/>
<connect gate="G$1" pin="RXD" pad="2"/>
<connect gate="G$1" pin="RXLED" pad="21"/>
<connect gate="G$1" pin="TEST" pad="26"/>
<connect gate="G$1" pin="TXD" pad="30"/>
<connect gate="G$1" pin="TXLED" pad="22"/>
<connect gate="G$1" pin="USBDM" pad="15"/>
<connect gate="G$1" pin="USBDP" pad="14"/>
<connect gate="G$1" pin="VCC" pad="19"/>
<connect gate="G$1" pin="VCCIO" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="PTC" prefix="F">
<description>&lt;b&gt;Resettable Fuse PTC&lt;/b&gt;
Resettable Fuse. Spark Fun Electronics SKU : COM-08357</description>
<gates>
<gate name="G$1" symbol="PTC" x="0" y="0"/>
</gates>
<devices>
<device name="PTH" package="PTC">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
<connect gate="G$1" pin="2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="SMD" package="PTC-1206">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="0603" package="0603">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="RESISTOR" prefix="R" uservalue="yes">
<description>&lt;b&gt;Resistor&lt;/b&gt;
Basic schematic elements and footprints for 0603, 1206, and PTH resistors.</description>
<gates>
<gate name="G$1" symbol="RESISTOR" x="0" y="0"/>
</gates>
<devices>
<device name="-1206" package="1206">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-2010" package="2010">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-0805" package="R0805">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-0603" package="0603">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-0402" package="R0402">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-PTH-1/6W" package="1/6W-RES">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-2512" package="2512">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-PTH-1/4W" package="1/4W-RES">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
<connect gate="G$1" pin="2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-PTH-1/2W" package="1/2W-RES">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
<connect gate="G$1" pin="2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-PTH-1/4W-OUTLINE" package="1/4W-RES-OUTLINE">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
<connect gate="G$1" pin="2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-PTH-1/6W-OUTLINE" package="1/6W-RES-OUTLINE">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-PTH-1/2W-OUTLINE" package="1/2W-RES-OUTLINE">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
<connect gate="G$1" pin="2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="CAP" prefix="C" uservalue="yes">
<description>&lt;b&gt;Capacitor&lt;/b&gt;
Standard 0603 ceramic capacitor, and 0.1" leaded capacitor.</description>
<gates>
<gate name="G$1" symbol="CAP" x="0" y="0"/>
</gates>
<devices>
<device name="-PTH-2.54MM" package="CAP-PTH-2.54MM">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-PTH-5MM" package="CAP-PTH-5MM">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-1210" package="1210">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-1206" package="1206">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-0603" package="0603">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-0805" package="0805-CAP">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-0402" package="0402-CAP">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="SOLDERJUMPER_2WAY" prefix="SJ" uservalue="yes">
<description>&lt;b&gt;Solder Jumper&lt;/b&gt;
2 way solder jumper</description>
<gates>
<gate name="G$1" symbol="SJ_2" x="0" y="0"/>
</gates>
<devices>
<device name="-OPEN" package="SJ-3">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-LEFT-BRIDGED" package="SJ-3-LEFT">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-RIGHT-BRIDGED" package="SJ-3-RIGHT">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-PTH" package="1X03">
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
<library name="serial">
<packages>
<package name="MOLEX-47346-0001">
<wire x1="0" y1="-4.15" x2="0" y2="4.15" width="0" layer="20"/>
<wire x1="5" y1="3.8" x2="5" y2="-3.75" width="0.4064" layer="51"/>
<wire x1="5" y1="-3.75" x2="0.1" y2="-3.75" width="0.4064" layer="51"/>
<wire x1="0.1" y1="-3.75" x2="-0.7" y2="-4.5" width="0.4064" layer="51"/>
<wire x1="5" y1="3.8" x2="0.05" y2="3.8" width="0.4064" layer="51"/>
<wire x1="0.05" y1="3.8" x2="-0.7" y2="4.45" width="0.4064" layer="51"/>
<wire x1="-0.7" y1="4.45" x2="-0.7" y2="-4.5" width="0.4064" layer="51"/>
<wire x1="-0.7" y1="-4.5" x2="-0.7" y2="-4.55" width="0.4064" layer="51"/>
<smd name="3" x="4.25" y="0" dx="0.45" dy="1.7" layer="1" rot="R90"/>
<smd name="2" x="4.25" y="0.65" dx="0.45" dy="1.7" layer="1" rot="R90"/>
<smd name="4" x="4.25" y="-0.65" dx="0.45" dy="1.7" layer="1" rot="R90"/>
<smd name="5" x="4.25" y="-1.3" dx="0.45" dy="1.7" layer="1" rot="R90"/>
<smd name="1" x="4.25" y="1.3" dx="0.45" dy="1.7" layer="1" rot="R90"/>
<smd name="GND2" x="3.75" y="2.5" dx="2.1" dy="1.475" layer="1"/>
<smd name="GND3" x="3.75" y="-2.5" dx="2.1" dy="1.475" layer="1"/>
<smd name="GND1" x="1.45" y="2.95" dx="2.375" dy="1.9" layer="1" rot="R90"/>
<smd name="GND4" x="1.45" y="-2.95" dx="2.375" dy="1.9" layer="1" rot="R90"/>
<smd name="GND5" x="1.45" y="0.8375" dx="1.175" dy="1.9" layer="1" rot="R90"/>
<smd name="GND6" x="1.45" y="-0.8375" dx="1.175" dy="1.9" layer="1" rot="R90"/>
<text x="0.2" y="4.6" size="1.27" layer="21">&gt;NAME</text>
<rectangle x1="2.65" y1="-1.6" x2="3.3" y2="1.6" layer="41"/>
</package>
<package name="FCI-10118193-0001LF">
<wire x1="-4.125" y1="0" x2="4.125" y2="0" width="0.1" layer="21"/>
<pad name="G6" x="3.3" y="1.45" drill="1.2" diameter="1.6"/>
<pad name="G5" x="-3.3" y="1.45" drill="1.2" diameter="1.6"/>
<smd name="3" x="0" y="4.125" dx="0.4" dy="1.35" layer="1"/>
<smd name="4" x="0.65" y="4.125" dx="0.4" dy="1.35" layer="1"/>
<smd name="2" x="-0.65" y="4.125" dx="0.4" dy="1.35" layer="1"/>
<smd name="1" x="-1.3" y="4.125" dx="0.4" dy="1.35" layer="1"/>
<smd name="5" x="1.3" y="4.125" dx="0.4" dy="1.35" layer="1"/>
<smd name="G2" x="3.2" y="3.86" dx="1.6" dy="1.4" layer="1"/>
<smd name="G1" x="-3.2" y="3.86" dx="1.6" dy="1.4" layer="1"/>
<smd name="G4" x="1.2" y="1.45" dx="1.9" dy="1.9" layer="1"/>
<smd name="G3" x="-1.2" y="1.45" dx="1.9" dy="1.9" layer="1"/>
</package>
<package name="ZX62-B-5PA">
<description>&lt;b&gt;Hirose ZX62-B-5PA(11)&lt;/b&gt;&lt;br&gt;
Micro B - Standard (Bottom Mount), Shell SMT</description>
<wire x1="-5" y1="-1.45" x2="5" y2="-1.45" width="0" layer="21"/>
<wire x1="3.75" y1="-2.15" x2="-3.75" y2="-2.15" width="0.1" layer="48"/>
<wire x1="-3.75" y1="-2.15" x2="-3.75" y2="2.85" width="0.1" layer="48"/>
<wire x1="-3.75" y1="2.85" x2="3.75" y2="2.85" width="0.1" layer="48"/>
<wire x1="3.75" y1="2.85" x2="3.75" y2="-2.15" width="0.1" layer="48"/>
<wire x1="-3.75" y1="-2.15" x2="-4.05" y2="-2.75" width="0.1" layer="48"/>
<wire x1="-4.05" y1="-2.75" x2="4.05" y2="-2.75" width="0.1" layer="48"/>
<wire x1="4.05" y1="-2.75" x2="3.75" y2="-2.15" width="0.1" layer="48"/>
<smd name="GND@1" x="-3.1" y="2.55" dx="2.1" dy="1.6" layer="1"/>
<smd name="GND@2" x="3.1" y="2.55" dx="2.1" dy="1.6" layer="1"/>
<smd name="3" x="0" y="2.675" dx="0.4" dy="1.35" layer="1"/>
<smd name="4" x="0.65" y="2.675" dx="0.4" dy="1.35" layer="1"/>
<smd name="5" x="1.3" y="2.675" dx="0.4" dy="1.35" layer="1"/>
<smd name="2" x="-0.65" y="2.675" dx="0.4" dy="1.35" layer="1"/>
<smd name="1" x="-1.3" y="2.675" dx="0.4" dy="1.35" layer="1"/>
<smd name="GND@5" x="-1.2" y="0" dx="1.9" dy="1.9" layer="1"/>
<smd name="GND@4" x="1.2" y="0" dx="1.9" dy="1.9" layer="1"/>
<smd name="GND@6" x="-3.9" y="0" dx="1.9" dy="1.6" layer="1" rot="R90"/>
<smd name="GND@3" x="3.9" y="0" dx="1.9" dy="1.6" layer="1" rot="R90"/>
</package>
</packages>
<symbols>
<symbol name="MOLEX-47346-0001">
<wire x1="2.54" y1="6.35" x2="2.54" y2="-6.35" width="0.254" layer="94"/>
<wire x1="2.54" y1="-6.35" x2="1.27" y2="-7.62" width="0.254" layer="94" curve="-90"/>
<wire x1="1.27" y1="-7.62" x2="0" y2="-7.62" width="0.254" layer="94"/>
<wire x1="0" y1="-7.62" x2="-1.016" y2="-8.128" width="0.254" layer="94" curve="53.130102"/>
<wire x1="-1.016" y1="-8.128" x2="-2.54" y2="-8.89" width="0.254" layer="94" curve="-53.130102"/>
<wire x1="-2.54" y1="-8.89" x2="-5.08" y2="-8.89" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-8.89" x2="-6.35" y2="-7.62" width="0.254" layer="94" curve="-90"/>
<wire x1="-6.35" y1="-7.62" x2="-6.35" y2="7.62" width="0.254" layer="94"/>
<wire x1="2.54" y1="6.35" x2="1.27" y2="7.62" width="0.254" layer="94" curve="90"/>
<wire x1="1.27" y1="7.62" x2="0" y2="7.62" width="0.254" layer="94"/>
<wire x1="0" y1="7.62" x2="-1.016" y2="8.128" width="0.254" layer="94" curve="-53.130102"/>
<wire x1="-1.016" y1="8.128" x2="-2.54" y2="8.89" width="0.254" layer="94" curve="53.130102"/>
<wire x1="-2.54" y1="8.89" x2="-5.08" y2="8.89" width="0.254" layer="94"/>
<wire x1="-5.08" y1="8.89" x2="-6.35" y2="7.62" width="0.254" layer="94" curve="90"/>
<wire x1="0" y1="5.08" x2="0" y2="-5.08" width="0.254" layer="94"/>
<wire x1="0" y1="-5.08" x2="-1.27" y2="-6.35" width="0.254" layer="94"/>
<wire x1="-1.27" y1="-6.35" x2="-3.81" y2="-6.35" width="0.254" layer="94"/>
<wire x1="-3.81" y1="6.35" x2="-1.27" y2="6.35" width="0.254" layer="94"/>
<wire x1="-1.27" y1="6.35" x2="0" y2="5.08" width="0.254" layer="94"/>
<wire x1="5.08" y1="10.16" x2="-7.62" y2="10.16" width="0.254" layer="94" style="shortdash"/>
<wire x1="-7.62" y1="10.16" x2="-7.62" y2="-10.16" width="0.254" layer="94" style="shortdash"/>
<wire x1="-7.62" y1="-10.16" x2="5.08" y2="-10.16" width="0.254" layer="94" style="shortdash"/>
<text x="2.54" y="11.43" size="1.778" layer="95" font="vector" rot="MR0">&gt;NAME</text>
<text x="-12.7" y="-7.62" size="1.778" layer="96" font="vector" rot="MR90">&gt;VALUE</text>
<pin name="V" x="5.08" y="5.08" visible="pin" length="middle" direction="in" rot="R180"/>
<pin name="D-" x="5.08" y="2.54" visible="pin" length="middle" direction="in" rot="R180"/>
<pin name="D+" x="5.08" y="0" visible="pin" length="middle" direction="in" rot="R180"/>
<pin name="ID" x="5.08" y="-2.54" visible="pin" length="middle" direction="in" rot="R180"/>
<pin name="G" x="5.08" y="-5.08" visible="pin" length="middle" direction="in" rot="R180"/>
<pin name="GND1" x="2.54" y="-12.7" visible="off" length="short" direction="pwr" rot="R90"/>
<pin name="GND2" x="0" y="-12.7" visible="off" length="short" direction="pwr" rot="R90"/>
<pin name="GND3" x="-2.54" y="-12.7" visible="off" length="short" direction="pwr" rot="R90"/>
<pin name="GND4" x="-5.08" y="-12.7" visible="off" length="short" direction="pwr" rot="R90"/>
<pin name="GND5" x="-7.62" y="-12.7" visible="off" length="short" direction="pwr" rot="R90"/>
<pin name="GND6" x="5.08" y="-12.7" visible="off" length="short" direction="pwr" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="MICRO-USB" prefix="USB">
<description>MICRO USB B, BOTTOM MOUNT</description>
<gates>
<gate name="G$1" symbol="MOLEX-47346-0001" x="0" y="0"/>
</gates>
<devices>
<device name="-MOLEX-47346" package="MOLEX-47346-0001">
<connects>
<connect gate="G$1" pin="D+" pad="3"/>
<connect gate="G$1" pin="D-" pad="2"/>
<connect gate="G$1" pin="G" pad="5"/>
<connect gate="G$1" pin="GND1" pad="GND1"/>
<connect gate="G$1" pin="GND2" pad="GND2"/>
<connect gate="G$1" pin="GND3" pad="GND3"/>
<connect gate="G$1" pin="GND4" pad="GND4"/>
<connect gate="G$1" pin="GND5" pad="GND5"/>
<connect gate="G$1" pin="GND6" pad="GND6"/>
<connect gate="G$1" pin="ID" pad="4"/>
<connect gate="G$1" pin="V" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-FCI-10118193" package="FCI-10118193-0001LF">
<connects>
<connect gate="G$1" pin="D+" pad="3"/>
<connect gate="G$1" pin="D-" pad="2"/>
<connect gate="G$1" pin="G" pad="5"/>
<connect gate="G$1" pin="GND1" pad="G1"/>
<connect gate="G$1" pin="GND2" pad="G2"/>
<connect gate="G$1" pin="GND3" pad="G3"/>
<connect gate="G$1" pin="GND4" pad="G4"/>
<connect gate="G$1" pin="GND5" pad="G5"/>
<connect gate="G$1" pin="GND6" pad="G6"/>
<connect gate="G$1" pin="ID" pad="4"/>
<connect gate="G$1" pin="V" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-ZX62-B-5PA" package="ZX62-B-5PA">
<connects>
<connect gate="G$1" pin="D+" pad="3"/>
<connect gate="G$1" pin="D-" pad="2"/>
<connect gate="G$1" pin="G" pad="5"/>
<connect gate="G$1" pin="GND1" pad="GND@1"/>
<connect gate="G$1" pin="GND2" pad="GND@2"/>
<connect gate="G$1" pin="GND3" pad="GND@3"/>
<connect gate="G$1" pin="GND4" pad="GND@4"/>
<connect gate="G$1" pin="GND5" pad="GND@5"/>
<connect gate="G$1" pin="GND6" pad="GND@6"/>
<connect gate="G$1" pin="ID" pad="4"/>
<connect gate="G$1" pin="V" pad="1"/>
</connects>
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
<class number="1" name="power" width="0.3048" drill="0">
</class>
</classes>
<parts>
<part name="U$1" library="UniqueInteractionsLib" deviceset="EZ-I2CHEADERV1" device=""/>
<part name="U1" library="akafugu" deviceset="FT232R-BASIC-PAD" device="-Q-LONGPADS"/>
<part name="GND1" library="SparkFun" deviceset="GND" device=""/>
<part name="C2" library="akafugu" deviceset="CAP" device="-0402" value="0.1uF"/>
<part name="GND6" library="SparkFun" deviceset="GND" device=""/>
<part name="GND7" library="SparkFun" deviceset="GND" device=""/>
<part name="R1" library="akafugu" deviceset="RESISTOR" device="-0402" value="1K"/>
<part name="R2" library="akafugu" deviceset="RESISTOR" device="-0402" value="1K"/>
<part name="LED1" library="akafugu" deviceset="LED" device="0603" value="Red"/>
<part name="LED2" library="akafugu" deviceset="LED" device="0603" value="Green"/>
<part name="F1" library="akafugu" deviceset="PTC" device="SMD"/>
<part name="GND4" library="SparkFun" deviceset="GND" device=""/>
<part name="USB1" library="serial" deviceset="MICRO-USB" device="-ZX62-B-5PA"/>
<part name="JP3" library="SparkFun" deviceset="ARDUINO_SERIAL_PROGRAM" device="PTH"/>
<part name="GND8" library="SparkFun" deviceset="GND" device=""/>
<part name="C1" library="akafugu" deviceset="CAP" device="-0402" value="10uF"/>
<part name="C3" library="akafugu" deviceset="CAP" device="-0402" value="0.1uF"/>
<part name="GND2" library="SparkFun" deviceset="GND" device=""/>
<part name="GND3" library="SparkFun" deviceset="GND" device=""/>
<part name="SJ5" library="akafugu" deviceset="SOLDERJUMPER_2WAY" device="-LEFT-BRIDGED"/>
</parts>
<sheets>
<sheet>
<plain>
<text x="10.16" y="-38.1" size="5.08" layer="91">Based on Sparksfun FTDIBReakout-master</text>
<text x="-8.89" y="59.436" size="1.778" layer="91">5V</text>
<text x="93.98" y="-5.08" size="1.524" layer="97">Default 5V</text>
<text x="51.562" y="54.61" size="1.778" layer="95">VCCIO</text>
<text x="61.976" y="54.61" size="1.778" layer="95">VCCIO</text>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="-10.16" y="76.2"/>
<instance part="U1" gate="G$1" x="30.48" y="33.02"/>
<instance part="GND1" gate="1" x="-40.64" y="25.4"/>
<instance part="C2" gate="G$1" x="-10.16" y="30.48"/>
<instance part="GND6" gate="1" x="-10.16" y="22.86"/>
<instance part="GND7" gate="1" x="0" y="10.16"/>
<instance part="R1" gate="G$1" x="55.88" y="27.94" rot="R90"/>
<instance part="R2" gate="G$1" x="66.04" y="27.94" rot="R90"/>
<instance part="LED1" gate="G$1" x="55.88" y="40.64"/>
<instance part="LED2" gate="G$1" x="66.04" y="40.64"/>
<instance part="F1" gate="G$1" x="-35.56" y="53.34"/>
<instance part="GND4" gate="1" x="50.8" y="25.4"/>
<instance part="USB1" gate="G$1" x="-45.72" y="48.26"/>
<instance part="JP3" gate="G$1" x="53.34" y="78.74"/>
<instance part="GND8" gate="1" x="78.74" y="83.82"/>
<instance part="C1" gate="G$1" x="-17.78" y="30.48"/>
<instance part="C3" gate="G$1" x="-25.4" y="30.48"/>
<instance part="GND2" gate="1" x="-25.4" y="22.86"/>
<instance part="GND3" gate="1" x="-17.78" y="22.86"/>
<instance part="SJ5" gate="G$1" x="73.66" y="0" rot="R90"/>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<wire x1="-15.24" y1="78.74" x2="-25.4" y2="78.74" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="GND"/>
<wire x1="-25.4" y1="78.74" x2="7.62" y2="78.74" width="0.1524" layer="91"/>
<junction x="-25.4" y="78.74"/>
<pinref part="U$1" gate="G$1" pin="GND1"/>
</segment>
<segment>
<pinref part="GND1" gate="1" pin="GND"/>
<pinref part="USB1" gate="G$1" pin="G"/>
<wire x1="-40.64" y1="27.94" x2="-40.64" y2="35.56" width="0.1524" layer="91"/>
<wire x1="-40.64" y1="35.56" x2="-40.64" y2="43.18" width="0.1524" layer="91"/>
<wire x1="-40.64" y1="43.18" x2="-45.72" y2="43.18" width="0.1524" layer="91"/>
<pinref part="USB1" gate="G$1" pin="GND6"/>
<junction x="-40.64" y="35.56"/>
<junction x="-40.64" y="43.18"/>
</segment>
<segment>
<wire x1="-10.16" y1="25.4" x2="-10.16" y2="27.94" width="0.1524" layer="91"/>
<pinref part="C2" gate="G$1" pin="2"/>
<pinref part="GND6" gate="1" pin="GND"/>
</segment>
<segment>
<wire x1="15.24" y1="27.94" x2="0" y2="27.94" width="0.1524" layer="91"/>
<wire x1="0" y1="27.94" x2="0" y2="25.4" width="0.1524" layer="91"/>
<wire x1="0" y1="25.4" x2="0" y2="22.86" width="0.1524" layer="91"/>
<wire x1="0" y1="22.86" x2="0" y2="20.32" width="0.1524" layer="91"/>
<wire x1="0" y1="20.32" x2="0" y2="17.78" width="0.1524" layer="91"/>
<wire x1="0" y1="17.78" x2="0" y2="12.7" width="0.1524" layer="91"/>
<wire x1="15.24" y1="25.4" x2="0" y2="25.4" width="0.1524" layer="91"/>
<wire x1="15.24" y1="22.86" x2="0" y2="22.86" width="0.1524" layer="91"/>
<wire x1="15.24" y1="20.32" x2="0" y2="20.32" width="0.1524" layer="91"/>
<wire x1="0" y1="17.78" x2="15.24" y2="17.78" width="0.1524" layer="91"/>
<junction x="0" y="25.4"/>
<junction x="0" y="22.86"/>
<junction x="0" y="20.32"/>
<junction x="0" y="17.78"/>
<pinref part="U1" gate="G$1" pin="TEST"/>
<pinref part="U1" gate="G$1" pin="AGND"/>
<pinref part="U1" gate="G$1" pin="GND1"/>
<pinref part="U1" gate="G$1" pin="GND2"/>
<pinref part="U1" gate="G$1" pin="GND3"/>
<pinref part="GND7" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="PAD"/>
<pinref part="GND4" gate="1" pin="GND"/>
<wire x1="50.8" y1="27.94" x2="45.72" y2="27.94" width="0.1524" layer="91"/>
</segment>
<segment>
<wire x1="58.42" y1="86.36" x2="78.74" y2="86.36" width="0.1524" layer="91"/>
<pinref part="JP3" gate="G$1" pin="GND"/>
<pinref part="GND8" gate="1" pin="GND"/>
</segment>
<segment>
<wire x1="-25.4" y1="22.86" x2="-25.4" y2="25.4" width="0.1524" layer="91"/>
<pinref part="C3" gate="G$1" pin="2"/>
<wire x1="-25.4" y1="25.4" x2="-25.4" y2="27.94" width="0.1524" layer="91"/>
<wire x1="-25.4" y1="27.94" x2="-25.4" y2="30.48" width="0.1524" layer="91"/>
<junction x="-25.4" y="27.94"/>
<pinref part="GND2" gate="1" pin="GND"/>
<junction x="-25.4" y="25.4"/>
</segment>
<segment>
<wire x1="-17.78" y1="22.86" x2="-17.78" y2="25.4" width="0.1524" layer="91"/>
<pinref part="C1" gate="G$1" pin="2"/>
<wire x1="-17.78" y1="25.4" x2="-17.78" y2="27.94" width="0.1524" layer="91"/>
<wire x1="-17.78" y1="27.94" x2="-17.78" y2="30.48" width="0.1524" layer="91"/>
<junction x="-17.78" y="27.94"/>
<pinref part="GND3" gate="1" pin="GND"/>
<junction x="-17.78" y="25.4"/>
</segment>
</net>
<net name="VCC" class="0">
<segment>
<wire x1="15.24" y1="35.56" x2="-10.16" y2="35.56" width="0.1524" layer="91"/>
<junction x="-10.16" y="35.56"/>
<pinref part="U1" gate="G$1" pin="3V3OUT"/>
<pinref part="C2" gate="G$1" pin="1"/>
<wire x1="-15.24" y1="81.28" x2="-25.4" y2="81.28" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="VCC"/>
<wire x1="-25.4" y1="81.28" x2="-10.16" y2="81.28" width="0.1524" layer="91"/>
<junction x="-25.4" y="81.28"/>
<pinref part="U$1" gate="G$1" pin="VCC1"/>
<wire x1="-10.16" y1="81.28" x2="7.62" y2="81.28" width="0.1524" layer="91"/>
<wire x1="-10.16" y1="35.56" x2="-10.16" y2="81.28" width="0.1524" layer="91"/>
<junction x="-10.16" y="81.28"/>
</segment>
<segment>
<wire x1="58.42" y1="0" x2="58.42" y2="2.54" width="0.1524" layer="91"/>
<wire x1="68.58" y1="0" x2="58.42" y2="0" width="0.1524" layer="91"/>
<label x="58.42" y="2.54" size="1.778" layer="95"/>
<pinref part="SJ5" gate="G$1" pin="1"/>
</segment>
</net>
<net name="SDA" class="0">
<segment>
<wire x1="-15.24" y1="76.2" x2="-25.4" y2="76.2" width="0.1524" layer="91"/>
<wire x1="-25.4" y1="76.2" x2="7.62" y2="76.2" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="SDA"/>
<junction x="-25.4" y="76.2"/>
<pinref part="U$1" gate="G$1" pin="SDA1"/>
</segment>
</net>
<net name="SCL" class="0">
<segment>
<wire x1="-15.24" y1="73.66" x2="-25.4" y2="73.66" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="SCL"/>
<wire x1="-25.4" y1="73.66" x2="7.62" y2="73.66" width="0.1524" layer="91"/>
<junction x="-25.4" y="73.66"/>
<pinref part="U$1" gate="G$1" pin="SCL1"/>
</segment>
</net>
<net name="LPW" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="LPW"/>
<wire x1="-25.4" y1="71.12" x2="-15.24" y2="71.12" width="0.1524" layer="91"/>
<junction x="-25.4" y="71.12"/>
<pinref part="U$1" gate="G$1" pin="LPW1"/>
<wire x1="-15.24" y1="71.12" x2="7.62" y2="71.12" width="0.1524" layer="91"/>
<wire x1="7.62" y1="71.12" x2="10.16" y2="71.12" width="0.1524" layer="91"/>
<junction x="7.62" y="71.12"/>
</segment>
</net>
<net name="BAT" class="0">
<segment>
<wire x1="-17.78" y1="83.82" x2="-25.4" y2="83.82" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="BAT"/>
<wire x1="-25.4" y1="83.82" x2="7.62" y2="83.82" width="0.1524" layer="91"/>
<junction x="-25.4" y="83.82"/>
<pinref part="U$1" gate="G$1" pin="BAT1"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<wire x1="-7.62" y1="48.26" x2="-7.62" y2="43.18" width="0.1524" layer="91"/>
<wire x1="-7.62" y1="43.18" x2="15.24" y2="43.18" width="0.1524" layer="91"/>
<pinref part="U1" gate="G$1" pin="USBDP"/>
<wire x1="-7.62" y1="48.26" x2="-40.64" y2="48.26" width="0.1524" layer="91"/>
<pinref part="USB1" gate="G$1" pin="D+"/>
<wire x1="-40.64" y1="48.26" x2="-45.72" y2="48.26" width="0.1524" layer="91"/>
<junction x="-40.64" y="48.26"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<wire x1="-2.54" y1="50.8" x2="-2.54" y2="45.72" width="0.1524" layer="91"/>
<wire x1="-2.54" y1="45.72" x2="15.24" y2="45.72" width="0.1524" layer="91"/>
<pinref part="U1" gate="G$1" pin="USBDM"/>
<wire x1="-2.54" y1="50.8" x2="-40.64" y2="50.8" width="0.1524" layer="91"/>
<pinref part="USB1" gate="G$1" pin="D-"/>
<wire x1="-40.64" y1="50.8" x2="-45.72" y2="50.8" width="0.1524" layer="91"/>
<junction x="-40.64" y="50.8"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<wire x1="55.88" y1="20.32" x2="45.72" y2="20.32" width="0.1524" layer="91"/>
<wire x1="55.88" y1="20.32" x2="55.88" y2="22.86" width="0.1524" layer="91"/>
<pinref part="U1" gate="G$1" pin="TXLED"/>
<pinref part="R1" gate="G$1" pin="1"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<wire x1="66.04" y1="17.78" x2="45.72" y2="17.78" width="0.1524" layer="91"/>
<wire x1="66.04" y1="17.78" x2="66.04" y2="22.86" width="0.1524" layer="91"/>
<pinref part="U1" gate="G$1" pin="RXLED"/>
<pinref part="R2" gate="G$1" pin="1"/>
</segment>
</net>
<net name="CTS" class="0">
<segment>
<wire x1="45.72" y1="38.1" x2="50.8" y2="38.1" width="0.1524" layer="91"/>
<label x="48.26" y="38.1" size="1.778" layer="95"/>
<pinref part="U1" gate="G$1" pin="CTS"/>
</segment>
<segment>
<wire x1="58.42" y1="83.82" x2="68.58" y2="83.82" width="0.1524" layer="91"/>
<label x="68.58" y="83.82" size="1.778" layer="95"/>
<pinref part="JP3" gate="G$1" pin="CTS"/>
</segment>
</net>
<net name="DTR" class="0">
<segment>
<wire x1="45.72" y1="33.02" x2="50.8" y2="33.02" width="0.1524" layer="91"/>
<label x="48.26" y="33.02" size="1.778" layer="95"/>
<pinref part="U1" gate="G$1" pin="DTR"/>
</segment>
<segment>
<wire x1="58.42" y1="73.66" x2="68.58" y2="73.66" width="0.1524" layer="91"/>
<label x="66.04" y="73.66" size="1.778" layer="95"/>
<pinref part="JP3" gate="G$1" pin="DTR"/>
</segment>
</net>
<net name="RX-I" class="0">
<segment>
<wire x1="45.72" y1="43.18" x2="50.8" y2="43.18" width="0.1524" layer="91"/>
<label x="48.26" y="43.18" size="1.778" layer="95"/>
<pinref part="U1" gate="G$1" pin="RXD"/>
</segment>
<segment>
<wire x1="58.42" y1="76.2" x2="68.58" y2="76.2" width="0.1524" layer="91"/>
<label x="66.04" y="76.2" size="1.778" layer="95"/>
<pinref part="JP3" gate="G$1" pin="RXI"/>
</segment>
</net>
<net name="TX-O" class="0">
<segment>
<wire x1="45.72" y1="45.72" x2="50.8" y2="45.72" width="0.1524" layer="91"/>
<label x="48.26" y="45.72" size="1.778" layer="95"/>
<pinref part="U1" gate="G$1" pin="TXD"/>
</segment>
<segment>
<wire x1="58.42" y1="78.74" x2="68.58" y2="78.74" width="0.1524" layer="91"/>
<label x="66.04" y="78.74" size="1.778" layer="95"/>
<pinref part="JP3" gate="G$1" pin="TXO"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<wire x1="-38.1" y1="53.34" x2="-40.64" y2="53.34" width="0.1524" layer="91"/>
<pinref part="F1" gate="G$1" pin="1"/>
<wire x1="-40.64" y1="53.34" x2="-45.72" y2="53.34" width="0.1524" layer="91"/>
<pinref part="USB1" gate="G$1" pin="V"/>
<junction x="-40.64" y="53.34"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<wire x1="55.88" y1="33.02" x2="55.88" y2="35.56" width="0.1524" layer="91"/>
<pinref part="R1" gate="G$1" pin="2"/>
<pinref part="LED1" gate="G$1" pin="C"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<wire x1="66.04" y1="35.56" x2="66.04" y2="33.02" width="0.1524" layer="91"/>
<pinref part="LED2" gate="G$1" pin="C"/>
<pinref part="R2" gate="G$1" pin="2"/>
</segment>
</net>
<net name="5V" class="0">
<segment>
<wire x1="0" y1="38.1" x2="15.24" y2="38.1" width="0.1524" layer="91"/>
<wire x1="0" y1="53.34" x2="0" y2="38.1" width="0.1524" layer="91"/>
<wire x1="0" y1="53.34" x2="-7.62" y2="53.34" width="0.1524" layer="91"/>
<wire x1="-7.62" y1="53.34" x2="-17.78" y2="53.34" width="0.1524" layer="91"/>
<wire x1="-17.78" y1="53.34" x2="-25.4" y2="53.34" width="0.1524" layer="91"/>
<wire x1="-27.94" y1="53.34" x2="-25.4" y2="53.34" width="0.1524" layer="91"/>
<pinref part="U1" gate="G$1" pin="VCC"/>
<pinref part="F1" gate="G$1" pin="2"/>
<wire x1="-25.4" y1="33.02" x2="-25.4" y2="35.56" width="0.1524" layer="91"/>
<wire x1="-25.4" y1="35.56" x2="-25.4" y2="53.34" width="0.1524" layer="91"/>
<wire x1="-17.78" y1="33.02" x2="-17.78" y2="35.56" width="0.1524" layer="91"/>
<pinref part="C3" gate="G$1" pin="1"/>
<junction x="-25.4" y="35.56"/>
<pinref part="C1" gate="G$1" pin="1"/>
<wire x1="-17.78" y1="35.56" x2="-17.78" y2="53.34" width="0.1524" layer="91"/>
<junction x="-17.78" y="35.56"/>
<junction x="-25.4" y="53.34"/>
<junction x="-17.78" y="53.34"/>
<wire x1="-7.62" y1="53.34" x2="-7.62" y2="58.42" width="0.1524" layer="91"/>
<junction x="-7.62" y="53.34"/>
</segment>
<segment>
<wire x1="88.9" y1="2.54" x2="88.9" y2="0" width="0.1524" layer="91"/>
<wire x1="78.74" y1="0" x2="88.9" y2="0" width="0.1524" layer="91"/>
<label x="88.9" y="2.54" size="1.778" layer="95"/>
<pinref part="SJ5" gate="G$1" pin="3"/>
</segment>
</net>
<net name="VCCIO" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="VCCIO"/>
<wire x1="-5.08" y1="33.02" x2="15.24" y2="33.02" width="0.1524" layer="91"/>
<label x="-5.08" y="33.02" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="LED1" gate="G$1" pin="A"/>
<wire x1="55.88" y1="43.18" x2="55.88" y2="53.34" width="0.1524" layer="91"/>
<junction x="55.88" y="53.34"/>
</segment>
<segment>
<pinref part="LED2" gate="G$1" pin="A"/>
<wire x1="66.04" y1="43.18" x2="66.04" y2="53.34" width="0.1524" layer="91"/>
<junction x="66.04" y="53.34"/>
</segment>
<segment>
<label x="83.82" y="-20.32" size="1.778" layer="95"/>
<wire x1="83.82" y1="-20.32" x2="73.66" y2="-20.32" width="0.1524" layer="91"/>
<wire x1="73.66" y1="-7.62" x2="81.28" y2="-7.62" width="0.1524" layer="91"/>
<wire x1="73.66" y1="-5.08" x2="73.66" y2="-7.62" width="0.1524" layer="91"/>
<label x="81.28" y="-7.62" size="1.778" layer="95"/>
<pinref part="SJ5" gate="G$1" pin="2"/>
<wire x1="73.66" y1="-20.32" x2="73.66" y2="-7.62" width="0.1524" layer="91"/>
<junction x="73.66" y="-7.62"/>
</segment>
<segment>
<wire x1="58.42" y1="81.28" x2="86.36" y2="81.28" width="0.1524" layer="91"/>
<label x="86.36" y="81.28" size="1.778" layer="95"/>
<pinref part="JP3" gate="G$1" pin="VCC"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
<errors>
<approved hash="204,1,-43.18,35.56,USB1,GND1,,,,"/>
<approved hash="204,1,-45.72,35.56,USB1,GND2,,,,"/>
<approved hash="204,1,-48.26,35.56,USB1,GND3,,,,"/>
<approved hash="204,1,-50.8,35.56,USB1,GND4,,,,"/>
<approved hash="204,1,-53.34,35.56,USB1,GND5,,,,"/>
</errors>
</schematic>
</drawing>
</eagle>
