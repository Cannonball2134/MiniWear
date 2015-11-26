//Eagle3D 20110101 INC-File e3d_switch.inc
//created by: INC SRC Compiler v2.02
//created on: 01.01.2011 17:33:58
//(c) 2011 by M. Weisser
//or the author of the macro

/*
 * Copyright 2005-2010 Matthias Weisser <matthias@matwei.de>
 *
 * This file is part of Eagle3D
 *
 * Eagle3D is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * Eagle3D is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#ifndef(__switch_inc)
#declare __switch_inc = true;

#ifndef(inc_testmode)
#declare inc_testmode=true;
#include "e3d_tools.inc"
#undef inc_testmode
#end

/********************************************************************************************************************************************
//B3F-10XX
//Tobias Mueller <Tobias_Mueller(replace with at)twam.info>
//erweitert und umbenannt von M. Weisser <mattias@matwei.de>
//
//dia:    diameter of button
//height: height of button over case of button
//color:  color of actual button
********************************************************************************************************************************************/
#macro SWITCH_ALPS_SKHH_V_GRND(dia, height, c)
union{
	box{<-3,0,-3><3,2.9,3> pigment{Black}}
	box{<-3,2.9,-3><3,3,3> pigment{Gray50}}
		
	object{
		Round_Cylinder_Union(<0,3,0>, <0,3+height,0>, dia/2, (dia/2)/10)
		texture
		{
			pigment{c}
			finish{phong 0.4 reflection{0.2}  ambient (0.1 * global_ambient_mul)}
		}
	}
	
	
	cylinder { <0,3,0> <0,3.2,0> 0.4 pigment {Black} translate<-2.5,0,-2.5>}
	cylinder { <0,3,0> <0,3.2,0> 0.4 pigment {Black} translate <-2.5,0,2.5>}
	cylinder { <0,3,0> <0,3.2,0> 0.4 pigment {Black} translate <2.5,0,-2.5>}
	cylinder { <0,3,0> <0,3.2,0> 0.4 pigment {Black} translate <2.5,0,2.5>}
	union{
		box{<-0.2,-1,-0.4> <0.2,1,0.4>}
		cylinder { <-0,1,-0.4> <0,1,0.4> 0.2}
		translate <3,0,2.2>
	}
	union{
		box { <-0.2,-1,-0.4> <0.2,1,0.4>}
		cylinder { <-0,1,-0.4>  <0,1,0.4> 0.2}
		translate <3,0,-2.2>
	}
	union {
		box { <-0.2,-1,-0.4> <0.2,1,0.4>}
		cylinder { <-0,1,-0.4>  <0,1,0.4> 0.2}
		translate <-3,0,2.2>
	}
	union {
		box { <-0.2,-1,-0.4> <0.2,1,0.4>}
		cylinder { <-0,1,-0.4>  <0,1,0.4> 0.2}
		translate <-3,0,-2.2>
	}
	texture{pigment{Gray70} finish{F_MetalA ambient (0.1 * global_ambient_mul)}}
}
#end


#macro SWITCH_B3F_10XX1()
SWITCH_ALPS_SKHH_V_GRND(4,1,Black)
#end
#macro SWITCH_SKHH_V_4_3MM_YELL()
SWITCH_ALPS_SKHH_V_GRND(4,1.3,Yellow)
#end
#macro SWITCH_SKHH_V_5MM_YELL()
SWITCH_ALPS_SKHH_V_GRND(4,2,Yellow)
#end
#macro SWITCH_SKHH_V_7MM_YELL()
SWITCH_ALPS_SKHH_V_GRND(4,4,Yellow)
#end
#macro SWITCH_SKHH_V_9_5MM_YELL()
SWITCH_ALPS_SKHH_V_GRND(4,6.5,Yellow)
#end


/********************************************************************************************************************************************
//Nigel Eke <nigel@eke.name>
//Dipswitch
********************************************************************************************************************************************/
#macro SWITCH_DIP_GRND(nrSwitches)
  #local pin   = cylinder { <0,-3,0> <0,0,0> .25 texture {T_Gold_5E} }
  #local well  = box { <0,3.7,2> <1,3.91,6> pigment { MediumWood } }
  #local housing = difference { box { <0,0,0> <2*nrSwitches+1,3.9,7.8> }
                                box { <0,3.7,2> <.3,3.91,6> }
                                pigment { color red 0.7 green 0.15 blue 0.15 } } //SteelBlue
  #local offSwitch = union { box { <0.1,3.71,2.01> <.9,3.71,5.9> }
                             box { <0.1,3.71,2.01> <.9,4.5,3> }
                             pigment { NewTan }}
  #local onSwitch = union { box { <0.1,3.71,2.01> <.9,3.71,5.9> }
                            box { <0.1,3.71,5> <.9,4.5,5.9> }
                            pigment { NewTan }}
  union {
    difference {
      object { housing }

      #local wellNr = 0;
      #while (wellNr < nrSwitches)
        object { well translate<wellNr*2+1,0,0> }
        #local wellNr = wellNr + 1;
      #end
    }
    #local switchNr = 0;
    #while (switchNr < nrSwitches)
      #local xShift = (switchNr*2)+1;
      object { pin translate<xShift+0.5,0,1> }
      object { pin translate<xShift+0.5,0,7> }
      #local onOff = SRand(1);
      #if (onOff < 0)
        object { offSwitch translate<xShift,0,0> }
      #else
        object { onSwitch translate<xShift,0,0> }
      #end
      text {
        ttf besch_font str(switchNr+1,2,0) .01, 0
        pigment { NewTan }
        scale 1.5
        rotate<90,0,0>
        translate<xShift-.2,3.91,.5>
      }
      #local switchNr = switchNr + 1;
    #end
    text {
      ttf besch_font "ON" .01, 0
      pigment { NewTan }
      scale 1.5
      rotate<90,0,0>
      translate<0.5,3.91,6.3>}
    translate<-nrSwitches-.5,0,-3.9>
    scale 2.54/2}
#end

#macro SWITCH_DIP01()
SWITCH_DIP_GRND(1)
#end
#macro SWITCH_DIP02()
SWITCH_DIP_GRND(2)
#end
#macro SWITCH_DIP03()
SWITCH_DIP_GRND(3)
#end
#macro SWITCH_DIP04()
SWITCH_DIP_GRND(4)
#end
#macro SWITCH_DIP05()
SWITCH_DIP_GRND(5)
#end
#macro SWITCH_DIP06()
SWITCH_DIP_GRND(6)
#end
#macro SWITCH_DIP07()
SWITCH_DIP_GRND(7)
#end
#macro SWITCH_DIP08()
SWITCH_DIP_GRND(8)
#end
#macro SWITCH_DIP09()
SWITCH_DIP_GRND(9)
#end
#macro SWITCH_DIP10()
SWITCH_DIP_GRND(10)
#end
#macro SWITCH_DIP12()
SWITCH_DIP_GRND(12)
#end


/********************************************************************************************************************************************
// Joerg Bredendiek <sprut(replace with at)sprut.de>  
// based on Nigel Eke <nigel@eke.name> ans some Pin-macros
//Dipswitch  small and smd
// pintyp=0  smd nach außen gewinkelt
// pintyp=1  smd nach innen gewinkelt
// pintyp=2  normal
********************************************************************************************************************************************/
#macro SWITCH_DIP_SM_GRND(nrSwitches, pintyp, abmasse)
/********************************************************************************************************************************************
// Pin Typ 0,  smd nach außen gewinkelt
********************************************************************************************************************************************/
#macro SWITCH_DIP_SM_PIN0(H,B,T,S)
//H = Höhe des Pins
//B = Breite des Pins
//T = Tiefe des Pins
//S = Materialstärke des Pins
union{
	box{<0,H,T/2><B/4,H-S,-T/2>}
	difference{
		cylinder{<B/4,H-S,-T/2><B/4,H-S,T/2>S}
		box{<-1,H-S,-T/2-0.01><B/2,H-S-3,T/2+0.01>}}
	box{<B/4,H-S,-T/2><B/4+S,S,T/2>}
	difference{
		cylinder{<B/4+S,S,-T/2><B/4+S,S,T/2>S}
		box{<0,S,-T/2-0.01><B,S+3,T/2+0.01>}}
	box{<B/4+S,0,-T/2><B,S,T/2>}
	difference{
		box{<B/4+S,S,-T/2><B/4+S+S/2,1.5*S,T/2>}
		cylinder{<B/4+S+S/2,S+S/2,T/2+0.01><B/4+S+S/2,S+S/2,-T/2-0.01>,S/2}}
	//box{<0,0,-T/2><B,H,T/2> pigment{White filter 0.9}}
	rotate<0,90,0>
	texture{col_silver}
}
#end
/********************************************************************************************************************************************
// Pin Typ 1,  smd nach innen gewinkelt
********************************************************************************************************************************************/
#macro SWITCH_DIP_SM_PIN1()

union{
	intersection{
		difference{
			box{<0,0,0><1.8,0.9,0.45>}
			cylinder{<0.9,0.9,-0.1><0.9,0.9,0.5>0.7}}
		cylinder{<0.9,0.9,-0.1><0.9,0.9,0.5>0.9}}
	box{<1.6,0.8,0><1.8,1.2,0.45>}
	difference{
		box{<1.6,1.2,-0.125><1.8,2.5,0.45+0.125>}
		box{<-0.1,0,0><0.3,0.5,-0.5> rotate<-20,0,0> translate<1.55,1.2,0>}
		box{<-0.1,0,0><0.3,0.5,0.5> rotate<20,0,0> translate<1.55,1.2,0.45>}}
	difference{
		cylinder{<1.5,2.5,-0.125><1.5,2.5,0.45+0.125>0.3}
		box{<1.6,2.9,-1><1,2,1>}}
	difference{
		box{<1.6,2.5,-0.125><1.4,2.8,0.45+0.125>}
		cylinder{<1.45,2.45,-1><1.45,2.45,1>0.15}}
	texture{col_silver}
	translate<-1.4,0,0>
	rotate<0,90,0>
	translate<-0.225,0,0>
}
#end
/********************************************************************************************************************************************
// Pin Typ 2, normal
********************************************************************************************************************************************/
#macro SWITCH_DIP_SM_PIN2()
union{
	//unterstes Ende durch das Loch der Platine
	difference{
		box{<0,0,0><0.455,3.4,0.3>}
		box{<0,0,0><0.5,0.5,0.5> rotate<0,0,-20> translate<0.305,0,-0.1>}
		box{<0,0,0><-0.5,0.5,0.5> rotate<0,0,20> translate<0.15,0,-0.1>}
	}
	box{<0,0,0><1.43,0.3,0.33> translate<-0.4875,5.3,0.5>}
	difference{
		box{<0,0,0><1.43,0.25,0.25> translate<-0.4875,5.05,0.3>}
		cylinder{<0,0,0><2,0,0>0.25 translate<-0.6,5.05,0.55>}
	}
	// breiter senkrechter Streifen mit Verjuengung
	difference{
		box{<0,0,0><1.43,1.7,0.3> translate<-0.4875,3.4,0>}
		box{<0,0,0><1,2.2,0.5> rotate<0,0,-20> translate<0.55,3.4,-0.1>}
		box{<0,0,0><-1,2.2,0.5> rotate<0,0,20> translate<-0.095,3.40,-0.1>}
	}
	// obere Biegung des breiten Streifens
	difference{
		cylinder{<0,0,0><1.43,0,0>0.5 translate<-0.4875,5.1,0.5> }
		box{<0,0,0><2,2.2,2> translate<-0.8,3.1,0.3>}
		box{<0,0,0><2,2.2,2> translate<-0.7,4,0.5>}
	}
	texture{col_silver}
	translate<-0.455/2,-3,-0.15>
}
#end
/********************************************************************************************************************************************
// Pin 
********************************************************************************************************************************************/
#macro SWITCH_DIP_SM_PIN(pintyp)
#if (pintyp=0)
	SWITCH_DIP_SM_PIN0(2.5, 1.5, 0.75, 0.3)
#end

#if (pintyp=1)
	SWITCH_DIP_SM_PIN1()
#end

#if (pintyp=2)
	SWITCH_DIP_SM_PIN2()
#end

#end

/********************************************************************************************************************************************
// body
********************************************************************************************************************************************/
#macro SWITCH_DIP_SM_HOUSING(seitenrand, tiefe)
difference { 
	box { <0,1,-tiefe> <2.54*(nrSwitches-1)+2*seitenrand, 4, tiefe> }
	box { <0,3.7,-2> <.2,4.2,2> }
	translate <-seitenrand,0,0> 
} 
#end


#local well  = union{
	box { <-0.5, 3.9, -2>  <0.5, 4.1, 2>  }
	box { <-0.5, 2,   -1> <0.5,  4.1, 1>  }
	}



	//Grundkoerper
	#local seitenrand = 2.2;	//CTS
	#local tiefe = 3.5;
	#if (abmasse=1)
		#local seitenrand = 1.5;
		#local tiefe = 3.5;
	#end
	#if (abmasse=2)			// DIPxxYL
		#local seitenrand = 2.5;
//		#local tiefe = 4.4;
	#end
	#if (abmasse=3)			// DIPxxS
		#local seitenrand = 1.5;
		#local tiefe = 3.5;
	#end
	#if (abmasse=4)			// SD-xx	
		#local seitenrand = 2.1;
		#local tiefe = 3.5;
	#end
	union {
	difference {
		object { SWITCH_DIP_SM_HOUSING(seitenrand, tiefe) }
		#local wellNr = 0;
		#while (wellNr < nrSwitches)
			object { well translate<wellNr*2.54,0,0> }
			#local wellNr = wellNr + 1;
		#end
	pigment { color red 0.15 green 0.1 blue 0.1 } 
	}


	text {
		ttf besch_font "ON" .01, 0
		pigment { NewTan }
		rotate<90,0,0>
		translate<-0.5, 4.01, 2.5>}


	#local switchNr = 0;
	#while (switchNr < nrSwitches)
		#local xShift = switchNr*2.54;
		//pins
		object { SWITCH_DIP_SM_PIN(pintyp) rotate <0,180,0>  translate<xShift, 0, 3.81> }
		object { SWITCH_DIP_SM_PIN(pintyp)                   translate<xShift, 0, -3.81> }
		// schalter
		box { <-0.6, 2, -2>  <0.6, 3, 2> texture {T_Gold_5E} translate<xShift,0,0>}
		#local onOff = SRand(1);
		#if (onOff < 0)
			box { <-0.5, 3,-1> <0.5, 4.1, 0> pigment {Red} translate<xShift,0,0>}
		#else
			box { <-0.5, 3, 1> <0.5, 4.1, 0> pigment {Red} translate<xShift,0,0>}
		#end
		//beschriftung
		text {
			ttf besch_font str(switchNr+1,2,0) .01, 0
			pigment { NewTan }
			rotate<90,0,0>
			translate<xShift-1, 4.01,-3>
			#if (switchNr>8)
				translate<0.5, 0, 0>
			#end
		}
		#if (switchNr < (nrSwitches-1))
			cylinder{<0,4,0><0,4.01,0> 0.25 translate<xShift+1.27, 0, -0.5> pigment { NewTan }}
		#end
		#local switchNr = switchNr + 1;
	#end

    translate<(-nrSwitches+1)*2.54/2,0,0>
}
#end

#macro SWITCH_DIP01_SM()
SWITCH_DIP_SM_GRND(1,0, 0)
#end
#macro SWITCH_DIP02_SM()
SWITCH_DIP_SM_GRND(2,0, 0)
#end
#macro SWITCH_DIP03_SM()
SWITCH_DIP_SM_GRND(3,0, 0)
#end
#macro SWITCH_DIP04_SM()
SWITCH_DIP_SM_GRND(4,0, 0)
#end
#macro SWITCH_DIP05_SM()
SWITCH_DIP_SM_GRND(5,0, 0)
#end
#macro SWITCH_DIP06_SM()
SWITCH_DIP_SM_GRND(6,0, 0)
#end
#macro SWITCH_DIP07_SM()
SWITCH_DIP_SM_GRND(7,0, 0)
#end
#macro SWITCH_DIP08_SM()
SWITCH_DIP_SM_GRND(8,0, 0)
#end
#macro SWITCH_DIP09_SM()
SWITCH_DIP_SM_GRND(9,0, 0)
#end
#macro SWITCH_DIP10_SM()
SWITCH_DIP_SM_GRND(10,0, 0)
#end
#macro SWITCH_DIP12_SM()
SWITCH_DIP_SM_GRND(12,0, 0)
#end
#macro SWITCH_DIP01_SMJ()
SWITCH_DIP_SM_GRND(1,1, 1)
#end
#macro SWITCH_DIP02_SMJ()
SWITCH_DIP_SM_GRND(2,1, 1)
#end
#macro SWITCH_DIP03_SMJ()
SWITCH_DIP_SM_GRND(3,1, 1)
#end
#macro SWITCH_DIP04_SMJ()
SWITCH_DIP_SM_GRND(4,1, 1)
#end
#macro SWITCH_DIP05_SMJ()
SWITCH_DIP_SM_GRND(5,1, 1)
#end
#macro SWITCH_DIP06_SMJ()
SWITCH_DIP_SM_GRND(6,1, 1)
#end
#macro SWITCH_DIP07_SMJ()
SWITCH_DIP_SM_GRND(7,1, 1)
#end
#macro SWITCH_DIP08_SMJ()
SWITCH_DIP_SM_GRND(8,1, 1)
#end
#macro SWITCH_DIP09_SMJ()
SWITCH_DIP_SM_GRND(9,1, 1)
#end
#macro SWITCH_DIP10_SMJ()
SWITCH_DIP_SM_GRND(10,1, 1)
#end
#macro SWITCH_DIP12_SMJ()
SWITCH_DIP_SM_GRND(12,1, 1)
#end
#macro SWITCH_DIP01_SMV()
SWITCH_DIP_SM_GRND(1,2, 2)
#end
#macro SWITCH_DIP02_SMV()
SWITCH_DIP_SM_GRND(2,2, 2)
#end
#macro SWITCH_DIP03_SMV()
SWITCH_DIP_SM_GRND(3,2, 2)
#end
#macro SWITCH_DIP04_SMV()
SWITCH_DIP_SM_GRND(4,2, 2)
#end
#macro SWITCH_DIP05_SMV()
SWITCH_DIP_SM_GRND(5,2, 2)
#end
#macro SWITCH_DIP06_SMV()
SWITCH_DIP_SM_GRND(6,2, 2)
#end
#macro SWITCH_DIP07_SMV()
SWITCH_DIP_SM_GRND(7,2, 2)
#end
#macro SWITCH_DIP08_SMV()
SWITCH_DIP_SM_GRND(8,2, 2)
#end
#macro SWITCH_DIP09_SMV()
SWITCH_DIP_SM_GRND(9,2, 2)
#end
#macro SWITCH_DIP10_SMV()
SWITCH_DIP_SM_GRND(10,2, 2)
#end
#macro SWITCH_DIP12_SMV()
SWITCH_DIP_SM_GRND(12,2, 2)
#end
#macro SWITCH_DIP04_SMV1()
SWITCH_DIP_SM_GRND(4,2, 3)
#end
#macro SWITCH_DIP08_SMV1()
SWITCH_DIP_SM_GRND(8,2, 3)
#end
#macro SWITCH_DIP01_SMV2()
SWITCH_DIP_SM_GRND(1,2, 4)
#end
#macro SWITCH_DIP02_SMV2()
SWITCH_DIP_SM_GRND(2,2, 4)
#end
#macro SWITCH_DIP03_SMV2()
SWITCH_DIP_SM_GRND(3,2, 4)
#end
#macro SWITCH_DIP04_SMV2()
SWITCH_DIP_SM_GRND(4,2, 4)
#end
#macro SWITCH_DIP05_SMV2()
SWITCH_DIP_SM_GRND(5,2, 4)
#end
#macro SWITCH_DIP06_SMV2()
SWITCH_DIP_SM_GRND(6,2, 4)
#end
#macro SWITCH_DIP07_SMV2()
SWITCH_DIP_SM_GRND(7,2, 4)
#end
#macro SWITCH_DIP08_SMV2()
SWITCH_DIP_SM_GRND(8,2, 4)
#end
#macro SWITCH_DIP09_SMV2()
SWITCH_DIP_SM_GRND(9,2, 4)
#end
#macro SWITCH_DIP10_SMV2()
SWITCH_DIP_SM_GRND(10,2, 4)
#end


/********************************************************************************************************************************************
//Macros for Sealed miniature toggle switch Serie E from ITT-industries
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1 du 09/01/06
//
// Version supported:
// Function     : 10x 20x 30x for 1,2,3 circuits
//              : x01(actuator pos 1) x05(actuator pos 2)
// Actuator     : M, S, L3 (L3 red by default, other color can be created)
// Bushing      : D1, D9, Y only for termin. C (take D1 for F1) (D9 doesn't exist for 3 circuits)
// Termination  : A, AV2, C, (V3, V2, V4, V6, V7, V8, V9)
// Contact mat. : Gold by default (silver can be created)
// Plastic Actuator Color : Red by default (White and Black can be created)
//
// Circuit=1-3 ActuatorType=1-3 ActuatorPos=1-3 Bushing=1-3 T=1..20 Material=1-2 PAC=1-3
// parameters are took in the same order than datasheet
********************************************************************************************************************************************/
#macro SWITCH_ITTE_GRND(Circuit,ActuatorType,ActuatorPos,Bushing,T,Material,PAC)
// Case
#macro ITT_CASE(Circuit,Pos) // Pos=1 actuator on top Pos=2 actuator H  Pos=3 actuator V
    #if(Circuit=1)
        #local W=6.6;
        #local L=8.89;
    #end
    #if(Circuit=2)
        #local W=11.43;
        #local L=8.89;
    #end
    #if(Circuit=3)
        #local W=16.31;
        #local L=10.77;
    #end
    #local H=12.7;
        union{
            superellipsoid {<0.04,0.04> scale <L/2-0.5,H/2,W/2> translate (+0.5-t1/2)*x  pigment{Redbody}} // large part
            superellipsoid {<0.04,0.04> scale <1/2,H/2,W/2>     translate (-L/2+0.5-t1/2)*x pigment{Redbody}} // thin part
            #if(Pos=2 | Pos=3)
                superellipsoid {<0.04,0.04> scale <t1/2,H/2,W/2>    translate (-L/2-t1)*x   texture{Silver2}} // front plate
            #end
            #if(Circuit=2)
                superellipsoid {<0.05,0.5> scale <1.52/2,H/2,1.2/2> translate (L/2)*x  pigment{Redbody}} // large part
            #end
            #if(Circuit=3)
                superellipsoid {<0.05,0.5> scale <1.52/2,H/2,1.2/2> translate <(L/2),0,-4.83/2>  pigment{Redbody}} // large part
                superellipsoid {<0.05,0.5> scale <1.52/2,H/2,1.2/2> translate <(L/2),0,+4.83/2>  pigment{Redbody}} // large part
            #end
            //marking
            #local OffsetX=3.7;
            #local Oy=-6.5;
            #local Oz=0;
            text {ttf global_fontfile_eagle3d "&" 0.05, 0 pigment{Black} scale 2.2 rotate<0,0,90> translate<OffsetX-5.2,Oy+3.9,-W/2-.05>}  
            #if(Circuit=1)   
                text {ttf global_fontfile_arial "C&K  CR  E 101" 0.05, 0 pigment{Black} scale 1.5 rotate<0,0,90> translate<OffsetX-3.5,Oy+1,-W/2-.05>}     
            #end
            #if(Circuit=2)   
                text {ttf global_fontfile_arial "C&K  CR  E 201" 0.05, 0 pigment{Black} scale 1.5 rotate<0,0,90> translate<OffsetX-3.5,Oy+1,-W/2-.05>}     
            #end
            #if(Circuit=3)   
                text {ttf global_fontfile_arial "C&K  CR  E 301" 0.05, 0 pigment{Black} scale 1.5 rotate<0,0,90> translate<OffsetX-3.5,Oy+1,-W/2-.05>}     
            #end
            text {ttf global_fontfile_arial "0.4 VA MAX" 0.05, 0 pigment{Black} scale 1.5 rotate<0,0,90> translate<OffsetX-1.75,Oy+2.5,-W/2-.05>}     
            text {ttf global_fontfile_arial "0214" 0.05, 0 pigment{Black} scale 1.5 rotate<0,0,90> translate<OffsetX-0,Oy+4.7,-W/2-.05>}     

            #if(Pos=1)
                rotate <0,0,-90>
                translate <0,L/2,0>
            #end
            #if(Pos=2)
                rotate <90,0,0>
                translate <L/2+0.25,W/2,0>
            #end
            #if(Pos=3)
                translate <L/2+0.25,H/2,0>
            #end
            
        }
#end

// Bushing
#macro ITT_BUSHING(B,Pos,OffsetX,OffsetY) // Pos=1 actuator on top Pos=2 actuator H  Pos=3 actuator V
#local r=0.2;
#local e=0.1; // Epsilon
    #if(B=1 | B=2 | B=3)
        #local D=6.48;
    #end
    #if(B=1 | B=2)
        #local LB=6.35;
    #end
    #if(B=3)
        #local LB=7.11;
    #end
    #if(B=4)
        #local LB=8.89;
        #local D=6.2;
    #end
    
    difference{
        union{
            cylinder{<-LB+r,0,0><0,0,0> D/2}
            torus{D/2-r, r rotate 90*z translate <-LB+r,0,0>}
            cylinder{<-LB,0,0><0,0,0> D/2-r}
        }
        union{        
            cylinder{<-LB-e,0,0><0,0,0> 1.8}
            #if(B=1 | B=2 | B=3)
                box{<-LB-e,-D/2,-2.78><0,+D/2,-D/2-e>}
                box{<-LB-e,-D/2,+2.78><0,+D/2,+D/2+e>}
            #end
            #if(B=4)
                #ifdef (global_fine_drawing)
                    #local Alpha=0;
                    #local Pitch=0.47;
                    #local xs=0;
                    #local N=0;
                    #while(xs>(-LB-1)) 
                        #local xs=-Alpha/360*Pitch;
                        sphere{<xs,sin(Alpha*3.14/360)*D/2,cos(Alpha*3.14/360)*D/2> 0.66*Pitch}
                        #local Alpha=Alpha+10;
                    #end      
                #else
                    #local N=0;
                    #while((N*0.635)<LB)   
                        torus{D/2,0.2 rotate 93*z translate <-N*0.635,0,0>}
                        #local N=N+1;
                    #end      
                #end
                box{<0,-D/2+.56,-0.42><-LB-1,-D/2-0.1,+0.42>}
            #end
        }
        #if(Pos=1)
            rotate -90*z
            translate OffsetY*y
        #end
        #if(Pos=2)
            rotate -90*x
            translate <-OffsetX,OffsetY,0>
        #end
        #if(Pos=3)
            translate <-OffsetX,OffsetY,0>
        #end
        
        #if(B=1 | B=2 | B=3)
            pigment {Redbody}
        #else
            texture {col_silver}
            //pigment {Silver}
        #end
    }
#end

#macro ITT_ACTUATOR(Pos,ActuatorType,ActuatorPos,OffsetX,OffsetY,PAC,B) // Pos=1 actuator on top Pos=2 actuator H  Pos=3 actuator V
    #local k=3;
    #local col=Gray20;
    
    #if(B=1 | B=2)
        #local ofs=6.35-k;
    #end
    #if(B=3)
        #local ofs=7.11-k;
    #end
    #if(B=4)
        #local ofs=8.89-k;
    #end

    #if(ActuatorPos=1)
        #local Alpha = -25/360*3.14;
    #end
    #if(ActuatorPos=2)
        #local Alpha = 0;
    #end
    #if(ActuatorPos=3)
        #local Alpha = +25/360*3.14;
    #end
    union{
        #if(ActuatorType=1)
            #local L1=7.62+k;
            #local D=2.67;
            sphere{<-L1+D/2,-tan(Alpha)*(L1-D/2),0>, D/2 texture{Chrome_Texture}}
            cone{<-L1+D/2,-tan(Alpha)*(L1-D/2), 0>, D/2, <0,0,0>, 1.2 texture { Chrome_Texture }}
        #end    
        #if(ActuatorType=2)
            #local L1=12.70+k;
            #local D=2.92;
            sphere{<-L1+D/2,-tan(Alpha)*(L1-D/2),0>, D/2 texture{Chrome_Texture}}
            cone{<-L1+D/2,-tan(Alpha)*(L1-D/2), 0>, D/2, <0,0,0>, 1.2 texture { Chrome_Texture }}
        #end    
        #if(ActuatorType=3)
            #local L1=7.5+k;
            #local L2=23.30+k;
            #local L3=23.88+k;
            #local D1=2.92;
            #local D2=3.28;
            #local D3=2.78;
            #if(PAC=1)
                #local col=Gray20;
            #end
            #if(PAC=2)
                #local col=White;
            #end
            #if(PAC=3)
                #local col=Red;
            #end
            cone{<-L1,-tan(Alpha)*(L1), 0>, D1/2, <0,0,0>, 1.2 texture{Chrome_Texture}}
            cone{<-L2,-tan(Alpha)*(L2), 0>, D2/2, <-L1,-tan(Alpha)*(L1), 0>, D1/2 pigment { col }}
            cone{<-L3,-tan(Alpha)*(L3), 0>, D3/2, <-L2,-tan(Alpha)*(L2), 0>, D2/2 pigment { col }}
        #end  
        translate -ofs*x
        #if(Pos=1)
            rotate -90*z
            translate <0,OffsetY,0>
        #end
        #if(Pos=2)
            rotate -90*x
            translate <-OffsetX,OffsetY,0>
        #end
        #if(Pos=3)
            rotate 180*x
            translate <-OffsetX,OffsetY,0>
        #end
    }  
#end

#macro ITT_SPRING(Pos,OffsetX,OffsetY)
union{
    difference{
        intersection{
            box{<-2-9.636,-6.15,+3.25><-9.043,6.15,-3.25> texture { Silver2 }}
            cylinder{<0,0,-5><0,0,+5> 30 translate +20.0*x texture { Silver2 }}
        }
        union{
            box{<-2-9.7,-4.85,+2.85><-9.3,4.85,-2.85> texture { Silver2 }}
            cylinder{<0,0,-5><0,0,+5> 30 translate +20.2*x texture { Silver2 }}
        }
    }
    box{<-0.1,-1.3,-2.5><+0.1,+1.3,+2.5> rotate -20*z translate<-9.95,3.58,0> texture { Silver2 }}
    box{<-0.1,-1.3,-2.5><+0.1,+1.3,+2.5> rotate +20*z translate<-10,-3.58,0> texture { Silver2 }}
    #if(Pos=1)
        rotate -90*z
        translate OffsetY*y
    #end
    #if(Pos=2)
        rotate -90*x
        translate <OffsetX,OffsetY,0>
    #end
    #if(Pos=3)
        translate <OffsetX,OffsetY,0>
    #end
}
#end

    //front plate
#macro ITT_PLATE_PIN(Pos,OffsetX,OffsetY)
    #local t1 = 0.41;   // front plate thickness
    #if(Circuit=1)
        #local W=6.6;
        #local L=8.89;
    #end
    #if(Circuit=2)
        #local W=11.43;
        #local L=8.89;
    #end
    #if(Circuit=3)
        #local W=16.31;
        #local L=10.77;
    #end
    #local H  = 12.7;   // case height
    union{
        box{<-t1/2,0,+2.54-0.635><+t1/2,-2.24,+2.54+0.635>}
        box{<-t1/2,0,-2.54-0.635><+t1/2,-2.24,-2.54+0.635>}
        cylinder{<-t1/2,-2.24,+2.54><+t1/2,-2.24,+2.54> .635}
        cylinder{<-t1/2,-2.24,-2.54><+t1/2,-2.24,-2.54> .635}
        texture { Silver2 }
    }
#end 

//Bended E pin   L=lenght H=height R=ray h=pin height w=pin width
#macro ITT_PIN(L,H,R,h,w,Offset,Material)
    #local e=0.1; // Epsilon

    union{   
        box{<-L,H-h/2,-w/2><0-R,H+h/2,+w/2>}    // horizontal pin part
        box{<-h/2,-3.18,-w/2><+h/2,H-R,+w/2>}   // vertical pin part
        difference{
            cylinder{<-R,H-R,-w/2><-R,H-R,+w/2> R+h/2}   // bended pin part
            union{
                cylinder{<-R,H-R,-w/2-e><-R,H-R,+w/2+e> R-h/2}   // delete central part of cylinder
                box{<-2*R-h/2-e,H+h/2+e,-w/2-e><-R,H-2*R-h/2-e,+w/2+e>} // delete half of disc
                box{<-R-e,H-R,-w/2-e><+h/2+e,H-2*R-h/2-e,+w/2+e>} // delete half of remaining half of disc
            }
        }                 
        translate Offset*x
        #if(Material=1 | Material=2)
            texture {col_gold}
        #else
            texture {col_silver}
        #end
    }
#end

#macro ITT_PIN_SET(Circuit,L,H,T,Material)
    #local h=0.76;
    #local w=1.27;
    #local MH=H/2;
    #local ST=3.81;
    #local Start=0;
    #local L1=12.70;
    
    #if(T=1) //A
        #if(Circuit=1)
            #local DH=3.81;
            #local DW=4.7;
            #local Start=0;
        #end
        #if(Circuit=2)
            #local DH=3.81;
            #local DW=4.7;
            #local Start=-DH/2;
        #end
        #if(Circuit=3)
            #local DH=3.81;
            #local DW=4.7;
            #local Start=-DH;
            #local L1=14.35;
        #end
    #else       //AV2
        #if(Circuit=1)
            #local DH=4.7;
            #local DW=4.83;
            #local Start=0;
        #end
        #if(Circuit=2)
            #local DH=4.7;
            #local DW=4.83;
            #local Start=-DW/2;
        #end
        #if(Circuit=3)
            #local DH=4.7;
            #local DW=4.83;
            #local Start=-DW;
            #local L1=14.35;
        #end
    #end

    
    union{
        #local N=1;  
        #if(T=1)
            #while(N<(Circuit+1))
                union{
                    object{ITT_PIN(4+ST*(N-1),MH+Start+(N-1)*DH,1.1+(N-1),w,h,L1+ST*(N-1),Material) translate -DW*z}
                    object{ITT_PIN(4+ST*(N-1),MH+Start+(N-1)*DH,1.1+(N-1),w,h,L1+ST*(N-1),Material) }
                    object{ITT_PIN(4+ST*(N-1),MH+Start+(N-1)*DH,1.1+(N-1),w,h,L1+ST*(N-1),Material) translate +DW*z}
                    sphere{ <0,0,0>, 1.52 scale <1,1,0.6> translate <L, MH+Start+(N-1)*DH, -DW>pigment{Redbody}}
                    sphere{ <0,0,0>, 1.52 scale <1,1,0.6> translate <L, MH+Start+(N-1)*DH, 0>pigment{Redbody}}
                    sphere{ <0,0,0>, 1.52 scale <1,1,0.6> translate <L, MH+Start+(N-1)*DH, +DW>pigment{Redbody}}

                    //sphere{ <0,0,0>, 1.52 scale <0,0,0.6> translate <L, MH+Start+(N-1)*DH, -DW>pigment{Redbody}}

                }
                #local N=N+1;
            #end
        #end 
        #if(T=2)
            #while(N<(Circuit+1))
                union{
                    object{ITT_PIN(4,MH-DH,1.1,h,w,L1,Material) }
                    object{ITT_PIN(4+ST,MH,2.0,h,w,L1+ST,Material) }
                    object{ITT_PIN(4+2*ST,MH+DH,3.0,h,w,L1+2*ST,Material) }
                    sphere{ <0,0,0>, 1.52 scale <1,0.6,1> translate <L, MH-DH, 0> pigment{Redbody}}
                    sphere{ <0,0,0>, 1.52 scale <1,0.6,1> translate <L, MH, 0> pigment{Redbody}}
                    sphere{ <0,0,0>, 1.52 scale <1,0.6,1> translate <L, MH+DH, 0> pigment{Redbody}}
                    translate z*(Start+(N-1)*DW)
                }
                #local N=N+1;
            #end 
        #end
        #if(T=3)
            #while(N<(Circuit+1))
                union{
                    box{<-h/2,1.52,-w/2><+h/2,1.52-6.35,+w/2> translate<-4.70,0,0>}
                    box{<-h/2,1.52,-w/2><+h/2,1.52-6.35,+w/2>}
                    box{<-h/2,1.52,-w/2><+h/2,1.52-6.35,+w/2> translate<+4.70,0,0>}
                    #if(Material=1 | Material=2)
                        texture {col_gold}
                    #else
                        texture {col_silver}
                    #end
                    translate z*(Start+(N-1)*DW)
                }
                union{
                    sphere{ <0,0,0>, 1.52 scale <1,0.6,1> translate <-DH,1.52,0>}
                    sphere{ <0,0,0>, 1.52 scale <1,0.6,1> translate <0,1.52,0>}
                    sphere{ <0,0,0>, 1.52 scale <1,0.6,1> translate <+DH,1.52,0>}
                    translate z*(Start+(N-1)*DW)
                    pigment{Redbody}
                }
                #local N=N+1;
            #end 
        #end
    }

#end

#local Redbody = rgb <0.62, 0.32, 0.29>;
#local t1 = 0.41;   // front plate thickness
#local t2 = 0.51;   // V type plate thickness
#local sh = 1.52;   // Epoxy seal height
#local H  = 12.7;   // case height
#if(Circuit=1)
    #local W=6.6;
    #local L=8.89;
#end
#if(Circuit=2)
    #local W=11.43;
    #local L=8.89;
#end
#if(Circuit=3)
    #local W=16.31;
    #local L=10.77;
#end    
    
    #if(T=1)  // A
        union{
            object{ITT_CASE(Circuit,2) translate (t1/2)*x}
            object{ITT_BUSHING(Bushing,2,t1/2,W/2)}
            object{ITT_ACTUATOR(2,ActuatorType,ActuatorPos,2.86,W/2,PAC,Bushing)}
            object{ITT_SPRING(2,9,W/2)}
            object{ITT_PLATE_PIN(2,0,H/2)}
            object{ITT_PIN_SET(Circuit,L,W,T,Material)}
        }
    #end
    
    #if(T=2)  // AV2
        union{
            object{ITT_CASE(Circuit,3) translate<t1/2,0,0>}
            object{ITT_BUSHING(Bushing,3,t1/2,H/2)}
            object{ITT_ACTUATOR(3,ActuatorType,ActuatorPos,2.86,H/2,PAC,Bushing)}
            object{ITT_SPRING(3,9,H/2)}
            object{ITT_PLATE_PIN(3,0,H/2)}
            object{ITT_PIN_SET(Circuit,L,H,T,Material)}
       }
    #end
    
    #if(T=3) // C
        union{
            object{ITT_CASE(Circuit,1) translate sh*y}
            object{ITT_BUSHING(Bushing,1,0,L+sh)}
            object{ITT_ACTUATOR(1,ActuatorType,ActuatorPos,0,L+2.86,PAC,Bushing)}
            object{ITT_PIN_SET(Circuit,L,W,T,Material)}
        }
    #end

#end
// Fonction 1 circuit pos 1, Actuator M, Bushing D1
#macro SWITCH_ITTE_E101MD1ABE()           
SWITCH_ITTE_GRND(1,1,1,1,1,1,0)
#end
#macro SWITCH_ITTE_E101MD1AV2BE()
SWITCH_ITTE_GRND(1,1,1,1,2,1,0)
#end
#macro SWITCH_ITTE_E101MD1CBE()
SWITCH_ITTE_GRND(1,1,1,1,3,1,0)
#end
// Fonction 2 circuits pos 1, Actuator M, Bushing D1
#macro SWITCH_ITTE_E201MD1ABE()           
SWITCH_ITTE_GRND(2,1,1,1,1,1,0)
#end
#macro SWITCH_ITTE_E201MD1AV2BE()
SWITCH_ITTE_GRND(2,1,1,1,2,1,0)
#end
#macro SWITCH_ITTE_E201MD1CBE()
SWITCH_ITTE_GRND(2,1,1,1,3,1,0)
#end
// Fonction 3 circuits pos 1, Actuator M, Bushing D1
#macro SWITCH_ITTE_E301MD1ABE()           
SWITCH_ITTE_GRND(3,1,1,1,1,1,0)
#end
#macro SWITCH_ITTE_E301MD1AV2BE()
SWITCH_ITTE_GRND(3,1,1,1,2,1,0)
#end
#macro SWITCH_ITTE_E301MD1CBE()
SWITCH_ITTE_GRND(3,1,1,1,3,1,0)
#end
// Fonction 1 circuit pos 1, Actuator M, Bushing D9
#macro SWITCH_ITTE_E101MD9ABE()           
SWITCH_ITTE_GRND(1,1,1,3,1,1,0)
#end
#macro SWITCH_ITTE_E101MD9AV2BE()
SWITCH_ITTE_GRND(1,1,1,3,2,1,0)
#end
#macro SWITCH_ITTE_E101MD9CBE()
SWITCH_ITTE_GRND(1,1,1,3,3,1,0)
#end
// Fonction 2 circuits pos 1, Actuator M, Bushing D9
#macro SWITCH_ITTE_E201MD9ABE()           
SWITCH_ITTE_GRND(2,1,1,3,1,1,0)
#end
#macro SWITCH_ITTE_E201MD9AV2BE()
SWITCH_ITTE_GRND(2,1,1,3,2,1,0)
#end
#macro SWITCH_ITTE_E201MD9CBE()
SWITCH_ITTE_GRND(2,1,1,3,3,1,0)
#end
// Fonction 1 circuit pos 1, Actuator M, Bushing Y
#macro SWITCH_ITTE_E101MYCBE()           
SWITCH_ITTE_GRND(1,1,1,4,3,1,0)
#end
// Fonction 2 circuits pos 1, Actuator M, Bushing Y
#macro SWITCH_ITTE_E201MYCBE()
SWITCH_ITTE_GRND(2,1,1,4,3,1,0)
#end
// Fonction 3 circuits pos 1, Actuator M, Bushing Y
#macro SWITCH_ITTE_E301MYCBE()
SWITCH_ITTE_GRND(3,1,1,4,3,1,0)
#end
// Fonction 1 circuit pos 1, Actuator S, Bushing D1
#macro SWITCH_ITTE_E101SD1ABE()           
SWITCH_ITTE_GRND(1,2,1,1,1,1,0)
#end
#macro SWITCH_ITTE_E101SD1AV2BE()
SWITCH_ITTE_GRND(1,2,1,1,2,1,0)
#end
#macro SWITCH_ITTE_E101SD1CBE()
SWITCH_ITTE_GRND(1,2,1,1,3,1,0)
#end
// Fonction 2 circuits pos 1, Actuator S, Bushing D1
#macro SWITCH_ITTE_E201SD1ABE()           
SWITCH_ITTE_GRND(2,2,1,1,1,1,0)
#end
#macro SWITCH_ITTE_E201SD1AV2BE()
SWITCH_ITTE_GRND(2,2,1,1,2,1,0)
#end
#macro SWITCH_ITTE_E201SD1CBE()
SWITCH_ITTE_GRND(2,2,1,1,3,1,0)
#end
// Fonction 3 circuits pos 1, Actuator S, Bushing D1
#macro SWITCH_ITTE_E301SD1ABE()           
SWITCH_ITTE_GRND(3,2,1,1,1,1,0)
#end
#macro SWITCH_ITTE_E301SD1AV2BE()
SWITCH_ITTE_GRND(3,2,1,1,2,1,0)
#end
#macro SWITCH_ITTE_E301SD1CBE()
SWITCH_ITTE_GRND(3,2,1,1,3,1,0)
#end
// Fonction 1 circuit pos 1, Actuator S, Bushing D9
#macro SWITCH_ITTE_E101SD9ABE()           
SWITCH_ITTE_GRND(1,2,1,3,1,1,0)
#end
#macro SWITCH_ITTE_E101SD9AV2BE()
SWITCH_ITTE_GRND(1,2,1,3,2,1,0)
#end
#macro SWITCH_ITTE_E101SD9CBE()
SWITCH_ITTE_GRND(1,2,1,3,3,1,0)
#end
// Fonction 2 circuits pos 1, Actuator S, Bushing D9
#macro SWITCH_ITTE_E201SD9ABE()           
SWITCH_ITTE_GRND(2,2,1,3,1,1,0)
#end
#macro SWITCH_ITTE_E201SD9AV2BE()
SWITCH_ITTE_GRND(2,2,1,3,2,1,0)
#end
#macro SWITCH_ITTE_E201SD9CBE()
SWITCH_ITTE_GRND(2,2,1,3,3,1,0)
#end
// Fonction 1 circuit pos 1, Actuator S, Bushing Y
#macro SWITCH_ITTE_E101SYCBE()
SWITCH_ITTE_GRND(1,2,1,4,3,1,0)
#end
// Fonction 2 circuits pos 1, Actuator S, Bushing Y
#macro SWITCH_ITTE_E201SYCBE()
SWITCH_ITTE_GRND(2,2,1,4,3,1,0)
#end
// Fonction 3 circuits pos 1, Actuator S, Bushing Y
#macro SWITCH_ITTE_E301SYCBE()
SWITCH_ITTE_GRND(3,2,1,4,3,1,3)
#end
// Fonction 1 circuit pos 1, Actuator L3, Bushing D1
#macro SWITCH_ITTE_E101L3D1ABE()           
SWITCH_ITTE_GRND(1,3,1,1,1,1,3)
#end
#macro SWITCH_ITTE_E101L3D1AV2BE()
SWITCH_ITTE_GRND(1,3,1,1,2,1,3)
#end
#macro SWITCH_ITTE_E101L3D1CBE()
SWITCH_ITTE_GRND(1,3,1,1,3,1,3)
#end
// Fonction 2 circuits pos 1, Actuator L3, Bushing D1
#macro SWITCH_ITTE_E201L3D1ABE()           
SWITCH_ITTE_GRND(2,3,1,1,1,1,3)
#end
#macro SWITCH_ITTE_E201L3D1AV2BE()
SWITCH_ITTE_GRND(2,3,1,1,2,1,3)
#end
#macro SWITCH_ITTE_E201L3D1CBE()
SWITCH_ITTE_GRND(2,3,1,1,3,1,3)
#end
// Fonction 3 circuits pos 1, Actuator L3, Bushing D1
#macro SWITCH_ITTE_E301L3D1ABE()           
SWITCH_ITTE_GRND(3,3,1,1,1,1,3)
#end
#macro SWITCH_ITTE_E301L3D1AV2BE()
SWITCH_ITTE_GRND(3,3,1,1,2,1,3)
#end
#macro SWITCH_ITTE_E301L3D1CBE()
SWITCH_ITTE_GRND(3,3,1,1,3,1,3)
#end
// Fonction 1 circuit pos 1, Actuator L3, Bushing D9
#macro SWITCH_ITTE_E101L3D9ABE()           
SWITCH_ITTE_GRND(1,3,1,3,1,1,3)
#end
#macro SWITCH_ITTE_E101L3D9AV2BE()
SWITCH_ITTE_GRND(1,3,1,3,2,1,3)
#end
#macro SWITCH_ITTE_E101L3D9CBE()
SWITCH_ITTE_GRND(1,3,1,3,3,1,3)
#end
// Fonction 2 circuits pos 1, Actuator L3, Bushing D9
#macro SWITCH_ITTE_E201L3D9ABE()           
SWITCH_ITTE_GRND(2,3,1,3,1,1,3)
#end
#macro SWITCH_ITTE_E201L3D9AV2BE()
SWITCH_ITTE_GRND(2,3,1,3,2,1,3)
#end
#macro SWITCH_ITTE_E201L3D9CBE()
SWITCH_ITTE_GRND(2,3,1,3,3,1,3)
#end
// Fonction 1 circuit pos 1, Actuator L3, Bushing Y
#macro SWITCH_ITTE_E101L3YCBE()
SWITCH_ITTE_GRND(1,3,1,4,3,1,3)
#end
// Fonction 2 circuits pos 1, Actuator L3, Bushing Y
#macro SWITCH_ITTE_E201L3YCBE()
SWITCH_ITTE_GRND(2,3,1,4,3,1,3)
#end
// Fonction 3 circuits pos 1, Actuator L3, Bushing Y
#macro SWITCH_ITTE_E301L3YCBE()
SWITCH_ITTE_GRND(3,3,1,4,3,1,3)
#end
// Fonction 1 circuit pos 2, Actuator M, Bushing D1
#macro SWITCH_ITTE_E105MD1ABE()           
SWITCH_ITTE_GRND(1,1,2,1,1,1,0)
#end
#macro SWITCH_ITTE_E105MD1AV2BE()
SWITCH_ITTE_GRND(1,1,2,1,2,1,0)
#end
#macro SWITCH_ITTE_E105MD1CBE()
SWITCH_ITTE_GRND(1,1,2,1,3,1,0)
#end
// Fonction 2 circuits pos 2, Actuator M, Bushing D1
#macro SWITCH_ITTE_E205MD1ABE()           
SWITCH_ITTE_GRND(2,1,2,1,1,1,0)
#end
#macro SWITCH_ITTE_E205MD1AV2BE()
SWITCH_ITTE_GRND(2,1,2,1,2,1,0)
#end
#macro SWITCH_ITTE_E205MD1CBE()
SWITCH_ITTE_GRND(2,1,2,1,3,1,0)
#end
// Fonction 3 circuits pos 2, Actuator M, Bushing D1
#macro SWITCH_ITTE_E305MD1ABE()           
SWITCH_ITTE_GRND(3,1,2,1,1,1,3)
#end
#macro SWITCH_ITTE_E305MD1AV2BE()
SWITCH_ITTE_GRND(3,1,2,1,2,1,3)
#end
#macro SWITCH_ITTE_E305MD1CBE()
SWITCH_ITTE_GRND(3,1,2,1,3,1,3)
#end
// Fonction 1 circuit pos 2, Actuator M, Bushing D9
#macro SWITCH_ITTE_E105MD9ABE()           
SWITCH_ITTE_GRND(1,1,2,3,1,1,3)
#end
#macro SWITCH_ITTE_E105MD9AV2BE()
SWITCH_ITTE_GRND(1,1,2,3,2,1,3)
#end
#macro SWITCH_ITTE_E105MD9CBE()
SWITCH_ITTE_GRND(1,1,2,3,3,1,3)
#end
// Fonction 2 circuits pos 2, Actuator M, Bushing D9
#macro SWITCH_ITTE_E205MD9ABE()           
SWITCH_ITTE_GRND(2,1,2,3,1,1,3)
#end
#macro SWITCH_ITTE_E205MD9AV2BE()
SWITCH_ITTE_GRND(2,1,2,3,2,1,3)
#end
#macro SWITCH_ITTE_E205MD9CBE()
SWITCH_ITTE_GRND(2,1,2,3,3,1,3)
#end
// Fonction 1 circuit pos 2, Actuator M, Bushing Y
#macro SWITCH_ITTE_E105MYCBE()
SWITCH_ITTE_GRND(1,1,2,4,3,1,0)
#end
// Fonction 2 circuits pos 2, Actuator M, Bushing Y
#macro SWITCH_ITTE_E205MYCBE()
SWITCH_ITTE_GRND(2,1,2,4,3,1,0)
#end
// Fonction 3 circuits pos 2, Actuator M, Bushing Y
#macro SWITCH_ITTE_E305MYCBE()
SWITCH_ITTE_GRND(3,1,2,4,3,1,3)
#end
// Fonction 1 circuit pos 2, Actuator S, Bushing D1
#macro SWITCH_ITTE_E105SD1ABE()           
SWITCH_ITTE_GRND(1,2,2,1,1,1,0)
#end
#macro SWITCH_ITTE_E105SD1AV2BE()
SWITCH_ITTE_GRND(1,2,2,1,2,1,0)
#end
#macro SWITCH_ITTE_E105SD1CBE()
SWITCH_ITTE_GRND(1,2,2,1,3,1,0)
#end
// Fonction 2 circuits pos 2, Actuator S, Bushing D1
#macro SWITCH_ITTE_E205SD1ABE()           
SWITCH_ITTE_GRND(2,2,2,1,1,1,0)
#end
#macro SWITCH_ITTE_E205SD1AV2BE()
SWITCH_ITTE_GRND(2,2,2,1,2,1,0)
#end
#macro SWITCH_ITTE_E205SD1CBE()
SWITCH_ITTE_GRND(2,2,2,1,3,1,0)
#end
// Fonction 3 circuits pos 2, Actuator S, Bushing D1
#macro SWITCH_ITTE_E305SD1ABE()           
SWITCH_ITTE_GRND(3,2,2,1,1,1,0)
#end
#macro SWITCH_ITTE_E305SD1AV2BE()
SWITCH_ITTE_GRND(3,2,2,1,2,1,0)
#end
#macro SWITCH_ITTE_E305SD1CBE()
SWITCH_ITTE_GRND(3,2,2,1,3,1,0)
#end
// Fonction 1 circuit pos 2, Actuator S, Bushing D9
#macro SWITCH_ITTE_E105SD9ABE()           
SWITCH_ITTE_GRND(1,2,2,3,1,1,0)
#end
#macro SWITCH_ITTE_E105SD9AV2BE()
SWITCH_ITTE_GRND(1,2,2,3,2,1,0)
#end
#macro SWITCH_ITTE_E105SD9CBE()
SWITCH_ITTE_GRND(1,2,2,3,3,1,0)
#end
// Fonction 2 circuits pos 2, Actuator S, Bushing D9
#macro SWITCH_ITTE_E205SD9ABE()           
SWITCH_ITTE_GRND(2,2,2,3,1,1,0)
#end
#macro SWITCH_ITTE_E205SD9AV2BE()
SWITCH_ITTE_GRND(2,2,2,3,2,1,0)
#end
#macro SWITCH_ITTE_E205SD9CBE()
SWITCH_ITTE_GRND(2,2,2,3,3,1,0)
#end
// Fonction 1 circuit pos 2, Actuator S, Bushing Y
#macro SWITCH_ITTE_E105SYCBE()
SWITCH_ITTE_GRND(1,2,2,4,3,1,0)
#end
// Fonction 2 circuits pos 2, Actuator S, Bushing Y
#macro SWITCH_ITTE_E205SYCBE()
SWITCH_ITTE_GRND(2,2,2,4,3,1,0)
#end
// Fonction 3 circuits pos 2, Actuator S, Bushing Y
#macro SWITCH_ITTE_E305SYCBE()
SWITCH_ITTE_GRND(3,2,2,4,3,1,3)
#end
// Fonction 1 circuit pos 2, Actuator L3, Bushing D1
#macro SWITCH_ITTE_E105L3D1ABE()           
SWITCH_ITTE_GRND(1,3,2,1,1,1,3)
#end
#macro SWITCH_ITTE_E105L3D1AV2BE()
SWITCH_ITTE_GRND(1,3,2,1,2,1,3)
#end
#macro SWITCH_ITTE_E105L3D1CBE()
SWITCH_ITTE_GRND(1,3,2,1,3,1,3)
#end
// Fonction 2 circuits pos 2, Actuator L3, Bushing D1
#macro SWITCH_ITTE_E205L3D1ABE()           
SWITCH_ITTE_GRND(2,3,2,1,1,1,3)
#end
#macro SWITCH_ITTE_E205L3D1AV2BE()
SWITCH_ITTE_GRND(2,3,2,1,2,1,3)
#end
#macro SWITCH_ITTE_E205L3D1CBE()
SWITCH_ITTE_GRND(2,3,2,1,3,1,3)
#end
// Fonction 3 circuits pos 2, Actuator L3, Bushing D1
#macro SWITCH_ITTE_E305L3D1ABE()           
SWITCH_ITTE_GRND(3,3,2,1,1,1,3)
#end
#macro SWITCH_ITTE_E305L3D1AV2BE()
SWITCH_ITTE_GRND(3,3,2,1,2,1,3)
#end
#macro SWITCH_ITTE_E305L3D1CBE()
SWITCH_ITTE_GRND(3,3,2,1,3,1,3)
#end
// Fonction 1 circuit pos 2, Actuator L3, Bushing D9
#macro SWITCH_ITTE_E105L3D9ABE()           
SWITCH_ITTE_GRND(1,3,2,3,1,1,3)
#end
#macro SWITCH_ITTE_E105L3D9AV2BE()
SWITCH_ITTE_GRND(1,3,2,3,2,1,3)
#end
#macro SWITCH_ITTE_E105L3D9CBE()
SWITCH_ITTE_GRND(1,3,2,3,3,1,3)
#end
// Fonction 2 circuits pos 2, Actuator L3, Bushing D9
#macro SWITCH_ITTE_E205L3D9ABE()           
SWITCH_ITTE_GRND(2,3,2,3,1,1,3)
#end
#macro SWITCH_ITTE_E205L3D9AV2BE()
SWITCH_ITTE_GRND(2,3,2,3,2,1,3)
#end
#macro SWITCH_ITTE_E205L3D9CBE()
SWITCH_ITTE_GRND(2,3,2,3,3,1,3)
#end
// Fonction 1 circuit pos 2, Actuator L3, Bushing Y
#macro SWITCH_ITTE_E105L3YCBE()
SWITCH_ITTE_GRND(1,3,2,4,3,1,3)
#end
// Fonction 2 circuits pos 2, Actuator L3, Bushing Y
#macro SWITCH_ITTE_E205L3YCBE()
SWITCH_ITTE_GRND(2,3,2,4,3,1,3)
#end
// Fonction 3 circuits pos 2, Actuator L3, Bushing Y
#macro SWITCH_ITTE_E305L3YCBE()
SWITCH_ITTE_GRND(3,3,2,4,3,1,3)
#end


/********************************************************************************************************************************************
//Macro für Taster 6x6
//franz.riedmueller@web.de
********************************************************************************************************************************************/
#macro SWITCH_PUSH_BUTTON_6X6_GRND(col)
union{
 box {<-3,   0, -3>
      < 3, 3.4,  3>
      pigment{
        color rgb <0, 0, 0>
      }
 } 
 box {<-3, 3.4, -3>
      < 3, 3.5,  3>
      pigment{
        color rgb <2, 2, 2>}
      finish { ambient (0.15 * global_ambient_mul) diffuse 0.85 reflection 0.35 phong 1.0 phong_size 70 brilliance 10}
 }
 cone {<0, 3.4, 0>,  1.65,
       <0, 9.5, 0>, 1.45  
       pigment{col}
       finish { ambient (0.15 * global_ambient_mul) diffuse 0.85 reflection 0.05 phong 1.0 phong_size 40}
 }
 cylinder {<-2.3, 3.4, 2.3>,
           <-2.3, 3.7, 2.3>,  0.5 
           pigment{color rgb <0, 0, 0>}
           finish { ambient (0.15 * global_ambient_mul) diffuse 0.85}
 }
 cylinder {<-2.3, 3.4, -2.3>,
           <-2.3, 3.7, -2.3>,  0.5 
           pigment{color rgb <0, 0, 0>}
           finish { ambient (0.15 * global_ambient_mul) diffuse 0.85}
 }
 cylinder {<2.3, 3.4, 2.3>,
           <2.3, 3.7, 2.3>,  0.5 
           pigment{color rgb <0, 0, 0>}
           finish { ambient (0.15 * global_ambient_mul) diffuse 0.85}
 }
 cylinder {<2.3, 3.4, -2.3>,
           <2.3, 3.7, -2.3>,  0.5 
           pigment{color rgb <0, 0, 0>}
           finish { ambient (0.15 * global_ambient_mul) diffuse 0.85}
 }
 box {<-3.01, -2.5, -0.1>
      < -2.5,  1.0,  0.1>
      pigment{
        color rgb <2, 2, 2>}
      finish { ambient (0.15 * global_ambient_mul) diffuse 0.85 reflection 0.35 phong 1.0 phong_size 70 brilliance 10}
 }
 box {<3.01, -2.5, -0.1>
      < 2.5,  1.0,  0.1>
      pigment{color rgb <2, 2, 2>}
      finish { ambient (0.15 * global_ambient_mul) diffuse 0.85 reflection 0.35 phong 1.0 phong_size 70 brilliance 10}
 }
}
#end

#macro SWITCH_PUSH_BUTTON_6X6_RED()
SWITCH_PUSH_BUTTON_6X6_GRND(Red)
#end
#macro SWITCH_PUSH_BUTTON_6X6_GREEN()
SWITCH_PUSH_BUTTON_6X6_GRND(Green)
#end
#macro SWITCH_PUSH_BUTTON_6X6_BLUE()
SWITCH_PUSH_BUTTON_6X6_GRND(Blue)
#end
#macro SWITCH_PUSH_BUTTON_6X6_BLACK()
SWITCH_PUSH_BUTTON_6X6_GRND(Black)
#end
#macro SWITCH_PUSH_BUTTON_6X6_WHITE()
SWITCH_PUSH_BUTTON_6X6_GRND(White)
#end


/********************************************************************************************************************************************
// Makro für LSH-Taster von Schurter (http://www.schurter.de/)
// Erstellt von Oliver Saal (osaal@gmx.de) 22.09.2003
// height  = Höhe des Tasters (von der Platine aus gemessen)
// dia_top = Durchmesser des Tasters am oberen Ende
// Benutzt Makro "IC_SMD_PIN" aus "ic.inc"
********************************************************************************************************************************************/
#macro SWITCH_PUSH_BUTTON_LSH_GRND(height,dia_top)
// Makro für LSH-Grundkörper (Quader mit abgerundeten senkrechten Kanten)
// Erstellt von Oliver Saal (osaal@gmx.de) 22.09.2003
// size_x = Länge
// size_z = Breite
// height = Höhe
// r      = Radius der Rundung
#macro SWITCH_PUSH_BUTTON_LSH_BOX(size_x,size_z,height,r)
union
{
	cylinder {<0,0,0><0,height,0> 0.2 translate<size_x/2-r,0,size_z/2-r>}
	cylinder {<0,0,0><0,height,0> 0.2 translate<size_x/2-r,0,-(size_z/2-r)>}
	cylinder {<0,0,0><0,height,0> 0.2 translate<-(size_x/2-r),0,size_z/2-r>}
	cylinder {<0,0,0><0,height,0> 0.2 translate<-(size_x/2-r),0,-(size_z/2-r)>}
	box {<-size_x/2,0,-size_z/2+r><size_x/2,height,size_z/2-r>}
	box {<-size_x/2+r,0,-size_z/2><size_z/2-r,height,size_z/2>}
}
#end

union
{
	object {SWITCH_PUSH_BUTTON_LSH_BOX(6,6,3,0.2)}
	object {SWITCH_PUSH_BUTTON_LSH_BOX(6,6,0.6,0.2) translate<0,3,0> texture{col_silver}}
	cylinder {<0,0,0><0,0.2,0>0.3 translate<-2,3.6,-2>}
	cylinder {<0,0,0><0,0.2,0>0.3 translate<-2,3.6,2>}
	cylinder {<0,0,0><0,0.2,0>0.3 translate<2,3.6,-2>}
	cylinder {<0,0,0><0,0.2,0>0.3 translate<2,3.6,2>}

	cone {<0,3.6,0> 1.7 <0,height-0.2,0> dia_top/2 }
	torus {dia_top/2-0.2, 0.2 translate<0,height-0.2,0>}
	cylinder {<0, height-0.2,0><0, height,0>,dia_top/2-0.2}
	object {IC_SMD_PIN(1.5,2.0,0.7,0.3) translate<3,0,2.25>}
	object {IC_SMD_PIN(1.5,2.0,0.7,0.3) translate<3,0,-2.25>}
	object {IC_SMD_PIN(1.5,2.0,0.7,0.3) rotate<0,180,0> translate<-3,0,-2.25>}
	object {IC_SMD_PIN(1.5,2.0,0.7,0.3) rotate<0,180,0> translate<-3,0,2.25>}
	pigment{Gray30}
}
#end

// Schurter-Best-Nr. LSH 1301.9314, Reichelt-Best.Nr.: Taster 9314 Höhe 4,3mm
#macro SWITCH_PUSH_BUTTON_LSH43()
SWITCH_PUSH_BUTTON_LSH_GRND(4.3, 3.4)
#end
// Schurter-Best-Nr. LSH 1301.9315, Reichelt-Best.Nr.: Taster 9315 Höhe 5,0mm
#macro SWITCH_PUSH_BUTTON_LSH50()
SWITCH_PUSH_BUTTON_LSH_GRND(5.0, 3.4)
#end
// Schurter-Best-Nr. LSH 1301.9316, Reichelt-Best.Nr.: Taster 9316 Höhe 7,0mm
#macro SWITCH_PUSH_BUTTON_LSH70()
SWITCH_PUSH_BUTTON_LSH_GRND(7.0, 3.2)
#end
// Schurter-Best-Nr. LSH 1301.9318, Reichelt-Best.Nr.: Taster 9318 Höhe 8,0mm
#macro SWITCH_PUSH_BUTTON_LSH80()
SWITCH_PUSH_BUTTON_LSH_GRND(8.0, 3.2)
#end
// Schurter-Best-Nr. LSH 1301.9319, Reichelt-Best.Nr.: Taster 9319 Höhe 9,5mm
#macro SWITCH_PUSH_BUTTON_LSH95()
SWITCH_PUSH_BUTTON_LSH_GRND(9.5, 3.0)
#end
// Schurter-Best-Nr. LSH 1301.9320, Reichelt-Best.Nr.: Taster 9320 Höhe 12,5mm
#macro SWITCH_PUSH_BUTTON_LSH125()
SWITCH_PUSH_BUTTON_LSH_GRND(12.5, 3.0)
#end


/********************************************************************************************************************************************
//Nigel Eke <nigel@eke.name>
//Rotary-DIP
********************************************************************************************************************************************/
#macro SWITCH_ROTARYDIP_GRND(nrPositions, V)
  #local pin   = cylinder { <0,-3,0> <0,0,0> .25 texture{col_gold} }
  #local dial  = cylinder { <0,3.75,0> <0,3.91,0> 1.5 pigment { NewTan } }
  #local arrow = union { box { <-.25,3.76,-1> <.25,4,.75> }
                         box { <-.35,3.76,-.35> <.35,4,.35> rotate<0,45,0> translate<0,0,.75> }
                         pigment { MediumWood } }
  #local housing = difference { box { <-3.9,0,-3.9> <3.9,3.9,3.9> }
				#if (V=0)
                                box { <-3.91,-.01,3.65> <-3.65,3.91,3.91> }
				#else
                                box { < 3.91,-.01,3.65> < 3.65,3.91,3.91> }
				#end
                                pigment { SteelBlue } }
  #local notch = cylinder { <0,0,0> <0,3.91,0> .2 pigment { NewTan } }



union {
	difference {
		object { housing }
		object { dial }
	}
	difference {
		object { dial }
		object { arrow }
	}
	#if (V=0)
		object { notch translate<-3.4,0,3.4> }
	#else
		object { notch translate< 3.4,0,3.4> }
	#end

	// pins
	#if (V=0)		
		#local pinNr = 0;
		#while (pinNr < 3)
			object { pin translate<-3,0,(pinNr-1)*2>}
			#if (pinNr != 1)
				object { pin translate<3,0,(pinNr-1)*2>}
			#end
			#local pinNr = pinNr + 1;
		#end
	#else
		object { pin translate<-3,0,3>}
		object { pin translate<-1,0,3>}
		object { pin translate< 1,0,3>}
		object { pin translate< 3,0,3>}
		object { pin translate<-1,0,-3>}
	#end


    #local chars = "0123456789ABCDEF";
    #local charNr = 0;
    #while (charNr < nrPositions)
      text {
        ttf besch_font substr(chars, charNr+1, 1) .01, 0
        pigment { NewTan }
        scale 1.5
        rotate<90,0,0>
        translate<-.5,0,0>
        translate<0,0,2.2>
        rotate<0,charNr*360/nrPositions,0>
        translate<0,3.91,0>
      }
      #local charNr = charNr + 1;
    #end

    rotate<0,180,0>
    scale 2.54/2
  }
#end

#macro SWITCH_ROTARYDIP10()
SWITCH_ROTARYDIP_GRND(10, 0)
#end
#macro SWITCH_ROTARYDIP16()
SWITCH_ROTARYDIP_GRND(16, 0)
#end
#macro SWITCH_ROTARYDIP10_1()
SWITCH_ROTARYDIP_GRND(10, 1)
#end
#macro SWITCH_ROTARYDIP16_1()
SWITCH_ROTARYDIP_GRND(16, 1)
#end


/********************************************************************************************************************************************
//Rotary encoder EVQVX from Panasonic
********************************************************************************************************************************************/
#macro SWITCH_ROTENC_PANASONIC_EVQVX_GRND(height)
union{
	//Anschlusspins
	union{                                      
		box{<-0.4,-3.5,-0.15><0.4,0,0.15>}
		box{<-0.4,-3.5,-0.15><0.4,0,0.15> translate<-2.5,0,0>}
		box{<-0.4,-3.5,-0.15><0.4,0,0.15> translate< 2.5,0,0>}
		
		box{<-0.6,0,-0.15><0.6,height-5,0.15>}
		box{<-0.6,0,-0.15><0.6,height-5,0.15> translate<-2.5,0,0>}
		box{<-0.6,0,-0.15><0.6,height-5,0.15> translate< 2.5,0,0>}
		
		box{<-0.7,height-4,-0.15><0.7,height-5,0.15>}
		box{<-0.7,height-4,-0.15><0.7,height-5,0.15> translate<-2.5,0,0>}
		box{<-0.7,height-4,-0.15><0.7,height-5,0.15> translate< 2.5,0,0>}
		
		//Vorderseite		
		difference{
			box{<-0.15,-3.5,-1.0><0.15,height-1,1.0> translate<-10/2,0,2>}
			box{<-0.16,height-5,0.7><0.16,height,1.1> translate<-10/2,0,2>}
		}
		
		difference{
			box{<-0.15,-3.5,-1.0><0.15,height-1,1.0> translate< 10/2,0,2>}
			box{<-0.16,height-5,0.7><0.16,height,1.1> translate< 10/2,0,2>}
		}
		
		difference{
			union{
				box{<-3,0,2.5><3,height+2,2.8>}
				difference{
					cylinder{<0,height-2,2.5><0,height-2,2.8>10.0/2}
					box{<-9.5,height+2,2.4><9.5,-5,2.9>}	
				}
			}
			
			box{<-2,0,2.4><0,6,2.9> translate<-2.3,-1,0> rotate<0,0,10>}
			box{<0,0,2.4><2,6,2.9> translate<2.3,-1,0> rotate<0,0,-10>}
			cylinder{<0,height,2.4><0,height,2.9>1.5}
		}
		
		box{<-5.15,height-4,2.5><5.15,height-2,2.8>}
				
		box{<-2,height-1,2.5><-5.15,height+1,2.8>}
		box{<2,height-1,2.5><5.15,height+1,2.8>}
		
		//Seitenteile
		box{<-0.15,height-1,-1.0><0.15,height+1,0.1> translate< 10/2,0,2>}
		box{<-0.15,height-1,-1.0><0.15,height+1,0.1> translate<-10/2,0,2>}
		
		box{<-0.15,height,-1.0><0.15,height+1,0.7> translate< 10/2,0,2>}
		box{<-0.15,height,-1.0><0.15,height+1,0.7> translate<-10/2,0,2>}
		
		
		box{<-0.15,2,2.0><0.15,4,6> translate< 10/2,0,0> }
		box{<-0.15,2,2.0><0.15,4,6> translate<-10/2,0,0>}
				
		box{<-0.15,0,4.0><0.15,2,6> translate< 10/2,0,0>}
		box{<-0.15,0,4.0><0.15,2,6> translate<-10/2,0,0>}
		
		box{<-0.15,height-2,1><0.15,height-4,-0.5> translate< 10/2,0,0> }
		box{<-0.15,height-2,1><0.15,height-4,-0.5> translate<-10/2,0,0> }
		                                                              								
		//Rueckseite
		box{<-5.15,height-2,-0.2><5.15,height-4,-0.5>}		
		
		difference{
			union{
				box{<-3,0,-0.2><3,height+2,-0.5>}
				difference{
					cylinder{<0,height-2,-0.1><0,height-2,-0.6>10.0/2}
					box{<-9.5,height+2,0><9.5,-5,-0.7>}	
				}
			}
						
			cylinder{<0,height,0><0,height,-0.7>1.5}
		}
		
		
		//pigment{Red}
		texture{col_silver}
	}
	                                   
	difference{	                                   
		union{
			box{<-9.8/2,height-5,-0.2><9.8/2,height+2,2.5>}
			difference{
				cylinder{<0,height-2,-0.2><0,height-2,2.5>12.8/2}
				box{<-9.5,height+2,-0.3><9.5,-5,2.6>}	
			}
		}	
		cylinder{<0,height,-0.3><0,height,2.6>1.5}		
	}

	pigment{Gray30}
	
	//rotate<0,180-45,0>

}
#end
#macro SWITCH_ROTENC_PANASONIC_EVQVX_9MM()
SWITCH_ROTENC_PANASONIC_EVQVX_GRND(9.0)
#end
#macro SWITCH_ROTENC_PANASONIC_EVQVX_11MM()
SWITCH_ROTENC_PANASONIC_EVQVX_GRND(11.0)
#end


/********************************************************************************************************************************************
//Macros for 1K2 serie, change over slide switch from SECME
//Designed by Philippe Boucheny <philippe.boucheny(at)free.fr>
//Rev. 1.0  26/03/06
********************************************************************************************************************************************/
#macro SWITCH_SECME_1K2_GRND(Cnx,Act,Au)
union{
    union{
        difference{
            union{
                superellipsoid { <0.05, 0.05> scale <5, 2.25,1.25> translate <0, 0.5+2.25, 0>}
                cylinder{<-4,0,0><-4,0.5,0> 0.5}
                cylinder{<+4,0,0><+4,0.5,0> 0.5}
            }
            cylinder{<+4,4.9,0><+4,5.1,0> 0.5}
            box{<-1.5,3.5,-1.3><+1.5,4,+1.3>}
            box{<-4.9,3.4,-1.3><-5.1,4.1,+1.3>}
            box{<-3.7,2,-1.2><+3.7,3.3,-1.3>}
        }
        text {ttf global_fontfile_arial_bold "SECME" 0.1, 0 scale 1.3 rotate<0,0,0> translate<-2.3,2.2,-1.25>}  // Marking
        #if(Au=0)
            pigment { Gray80 }
        #else
            pigment { Gray15 }
        #end
        finish {
           diffuse 0.5 
           specular 0.5
           ambient (0.1 * global_ambient_mul)
        }
    }
    #if(Act=0) // High actuator
    union{
        superellipsoid { <0.05, 0.05> scale <4, 0.3,1.25> translate <-0.8, 0.5+4.5+0.3, 0>}
        box{<-3.9,0,-1.25><1,0.4,+1.25> rotate +4*z translate <-0.8, 0.5+4.5+0.5, 0>}
        box{<+3.9,0,-1.25><1,0.4,+1.25> rotate -4*z translate <-0.8, 0.5+4.5+0.5, 0>}
        difference{
            superellipsoid { <0.05, 0.05> scale <1.2, 0.4,1.25>}
            cylinder{<0,0.2,0><0,0.5,0> 0.5}
            translate <-0.8, 0.5+4.5+0.6+0.2+0.2, 0>
        }
        box{<-1.5,3.5,-1.2><+1.5,4,+1.2>}
        pigment { Red }
        finish {
           diffuse 0.5 
           specular 0.5
           ambient (0.1 * global_ambient_mul)
        }
    }
    #else // low actuator
    union{
        superellipsoid { <0.05, 0.05> scale <4, 0.4,1.25> translate <-0.8, 0.5+4.5+0.4, 0>}
        difference{
            superellipsoid { <0.05, 0.05> scale <1.2, 1.05,1.25>}
            cylinder{<0,0.9,0><0,1.1,0> 0.5}
            translate <-0.8, 0.5+4.5+1.05, 0>
        }
        box{<-1.5,3.5,-1.2><+1.5,4,+1.2>}
        pigment { Gray15 }
        finish {
           diffuse 0.5 
           specular 0.5
           ambient (0.1 * global_ambient_mul)
        }
    }
    #end
        
    #if(Cnx=0) // Straight connection
        #local pin =
        union{
            cylinder {<0, -5, 0> <0, 1, 0> 0.3}
            sphere {<0,-5,0> 0.3}
            texture{col_gold}
        }  
    #else
        #local pin =
        union{
            cylinder {<0, -0.4, 0> <0, 1, 0> 0.3}
            cylinder {<0, -0.7, 0.4> <0, -0.7, 4.45> 0.3}
            sphere {<0,-0.7,4.45> 0.3}
            intersection {
              torus { 0.4 0.3 rotate < 0, 0, 90> }
              box { < -0.3, -0, 0> <+0.3, -2, -2> }
              translate < 0, -0.3, +0.4>
            }
            texture{col_gold}
        }  
    #end
    
    #local i = 0;
    #while(i<3)
        object{pin translate< -(3-1)*2.54/2+i*2.54, 0, 0>}
    #local i = i + 1;
    #end
    
    rotate 180*y
    
    #if(Cnx=1)
    rotate -90*x
    translate <0,1.25,-1.2>
    #end
    

   
}
#end

// Straight connection - Low actuator
#macro SWITCH_SECME_1K2_SL()
SWITCH_SECME_1K2_GRND(0,0,0)
#end
// Straight connection - High actuator
#macro SWITCH_SECME_1K2_SH()
SWITCH_SECME_1K2_GRND(0,1,0)
#end
// Right-angled connection - Low actuator
#macro SWITCH_SECME_1K2_RL()
SWITCH_SECME_1K2_GRND(1,0,0)
#end
// Right-angled connection - High actuator
#macro SWITCH_SECME_1K2_RH()
SWITCH_SECME_1K2_GRND(1,1,0)
#end
// Straight connection - Low actuator
#macro SWITCH_SECME_1K2_SLB()
SWITCH_SECME_1K2_GRND(0,0,1)
#end


/**********************************************************************
Testing
**********************************************************************/
#ifndef(inc_testmode)
          
//Size of the Grid Plane (+/- span)
#local XYZ_span=20;

//Orientation axes
cylinder{<-XYZ_span,0,0><XYZ_span,0,0>0.1 pigment{Blue}}	//X
cylinder{<0,-XYZ_span,0><0,XYZ_span,0>0.1 pigment{Red}}		//Y
cylinder{<0,0,-XYZ_span><0,0,XYZ_span>0.1 pigment{Yellow}}	//Z

// Useful GRIDS:
#local XYZ_step= 1 ;          // axis increment
#local XYZ_cnt = 0;           //  loop counter
#local xyz_thick = 0.05;     // grid line thickness

// GRID PLANES: Remove comment begin/end to activate & select PLANES:
#while (XYZ_cnt <= XYZ_span)

	cylinder{<-XYZ_span,0,XYZ_cnt><XYZ_span,0,XYZ_cnt>xyz_thick pigment{Blue}}		// Positive Z-Lines
	cylinder{<-XYZ_span,0,-XYZ_cnt><XYZ_span,0,-XYZ_cnt>xyz_thick pigment{Blue}}	// Negative Z-Lines
	
	//cylinder{<0,XYZ_cnt,-XYZ_span><0,XYZ_cnt,XYZ_span>xyz_thick pigment{Red}}		// Positive Y-Z Plane Lines
	//cylinder{<0,-XYZ_cnt,-XYZ_span><0,-XYZ_cnt,XYZ_span>xyz_thick pigment{Red}}	// Negative Y-Z Plane Lines
	
	//cylinder{<-XYZ_span,XYZ_cnt,0><XYZ_span,XYZ_cnt,0>xyz_thick pigment{Red}}		// Positive Y-X Plane Lines
	//cylinder{<-XYZ_span,-XYZ_cnt,0><XYZ_span,-XYZ_cnt,0>xyz_thick pigment{Red}}	// Negative Y-X Plane Lines
	
	cylinder{<XYZ_cnt,0,-XYZ_span><XYZ_cnt,0,XYZ_span>xyz_thick pigment{Yellow}}	// Positive X-Lines
	cylinder{<-XYZ_cnt,0,-XYZ_span><-XYZ_cnt,0,XYZ_span>xyz_thick pigment{Yellow}}	// Negative X-Lines

	#local XYZ_cnt = XYZ_cnt+XYZ_step;
#end

camera
{       
	#local tt = 40;				//let's you change the distance easily
	location <-tt,tt,-tt>
	//location<0,5,-50>			//alternate location
	look_at <0,0,0>				//best to select the approximate centre of the object
	angle 30
}

light_source { <100, 100, -100> White}
light_source { <-100, 100, -100> White }
light_source { <-100, 100, 100> White }
light_source { <100, 100, 100> White }
//light_source { <-tt,tt,-tt> White }
//light_source { <-tt,tt,-tt> White }
//light_source { <-tt,tt,-tt> White }
background{Grey}

#end

#end
//End of Macros
