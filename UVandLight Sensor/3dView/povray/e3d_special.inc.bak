//Eagle3D 20110101 INC-File e3d_special.inc
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
 
#ifndef(__special_inc)
#declare __special_inc = true;

#ifndef(inc_testmode)
	#declare inc_testmode=true;
	#include "e3d_tools.inc"
	#undef inc_testmode
#end

// Copyright 2010 Gary French <gary@chromiteblue.com>
// Simple wire jumpers
/********************************************************************************************************************************************
//Buzzer Grundmakro   
//bearbeitet von Ronny Schulz
//val_size      Groesse der Beschriftung
//dis           Abstand der Pins      
//dia           Radius des Buzzers 
//hig           Hoehe des Buzzers
//hole          Radius des sound emission hole
//dia_b         Radius des Anschlussdrahtes
********************************************************************************************************************************************/
#macro SPC_BUZZER_GRND(val_size,dis,dia,hig,hole,dia_b)
union{
	union{
		cylinder{<0,0,0><0,hig,0>dia pigment{Gray20}}                                                           //Buzzer Koerper
		cylinder{<0,hig-1,0><0,hig+0.1,0>hole pigment{Black}}                                                   //Oeffnung oben
       	}
	union{                                                                                                          //Plus Symbol
        	torus{(dia-hole)/3.5,0.15}
	        box{<-(dia-hole)/3.5,-0.15,-0.15><(dia-hole)/3.5,0.15,0.15>}
	        box{<-0.1,-0.15,-(dia-hole)/3.5><0.15,0.15,(dia-hole)/3.5>}
	        translate<(dia+hole)/2,hig,0>
		pigment{Gray20} 
	}
	#if(pin_short=off)
		cylinder{<0,0,0><0,-14.5,0>dia_b texture{col_silver} translate<dis/2,0,0>}                              //Beinchen rechts
		cylinder{<0,0,0><0,-17.5,0>dia_b texture{col_silver} translate<-dis/2,0,0>}                     	//Beinchen links
	#else
		cylinder{<0,0,0><0,-1*(pcb_height+pin_length)-0.2,0>dia_b texture{col_silver} translate<dis/2,0,0>}	//Beinchen rechts
		cylinder{<0,0,0><0,-1*(pcb_height+pin_length)-0.2,0>dia_b texture{col_silver} translate<-dis/2,0,0>}	//Beinchen links
	#end
}
#end

#macro SPC_BUZZER_TDB()
SPC_BUZZER_GRND(1,7.62,12/2,9.5,2.5/2,1/2)
#end


/********************************************************************************************************************************************
// Ceramic Resonator
// Producer: Abracon
// Web: www.abracon.com
// Part: ABM3B
// Carsten Koegler <koegler(replace with at)ftz-leipzig.de>
********************************************************************************************************************************************/
#macro SPC_CRES_ABRACON_ABM3B_GRND(value)
#local SPC_CRES_METAL_TEXTURE = texture { T_Chrome_5B } ;
#local SPC_CRES_TEXT_PIGMENT = pigment { White*0.5 } ;

union{
	//Grundkoerper
	union{
        Round_Box_Union(<-2.5,0.03,-1.6>,<2.5,0.9, 1.6>, 0.05 ) pigment{White*0.1}
        }
	
	//Anschlusspads
	box{<-0.5,0,-0.45><0.5,0.3,0.45> texture{col_gold} translate<-2.05,0, 1.1>}
	box{<-0.5,0,-0.45><0.5,0.3,0.45> texture{col_gold} translate<-2.05,0,-1.1>}
	box{<-0.5,0,-0.45><0.5,0.3,0.45> texture{col_gold} translate< 2.05,0, 1.1>}
	box{<-0.5,0,-0.45><0.5,0.3,0.45> texture{col_gold} translate< 2.05,0,-1.1>}

        Round_Box_Union(<-2.5,0.85,-1.6>, <2.5,1.0, 1.6>, 0.05 )
        Round_Box_Union(<-2.5+0.5,0.5,-1.6+0.5>,<2.5-0.5,1.1, 1.6-0.5>, 0.05 )
        text {ttf besch_font value 0.02, 0 pigment{SPC_CRES_TEXT_PIGMENT} rotate<90,0,0> scale 1.0 translate<-1.5, 1.11,-0.1>}

        texture {SPC_CRES_METAL_TEXTURE}	
}
#end

#macro SPC_CRES_ABRACON_ABM3B(value)
SPC_CRES_ABRACON_ABM3B_GRND(value)
#end


/********************************************************************************************************************************************
//Ceramic Resonator
********************************************************************************************************************************************/
#macro SPC_CRES_MURATA_CSTCE_G_A_GRND(value)
union{
	//Grundkörper
	box{<-1.6,0,-0.65><1.6,0.4,0.65> pigment{White}}
	//Anschlußflächen
	box{<-0.25,0,-0.6501><0.25,0.3,0.6501> texture{col_gold}}
	box{<-0.25,0,-0.6501><0.25,0.41,0.6501> texture{col_gold} translate<-1.2,0,0>}
	box{<-0.25,0,-0.6501><0.25,0.41,0.6501> texture{col_gold} translate<1.2,0,0>}
	
	difference{
		Round_Box_Union(<-1.5,0.1,-0.55>,<1.5,0.7,0.55>, 0.1)
  		text {ttf besch_font value 0.02, 0 rotate<90,0,0> scale 0.5 translate<-1,0.701,-0.1>}
		texture{col_silver}
	}
}
#end

#macro SPC_CRES_MURATA_CSTCE_G_A(value)
SPC_CRES_MURATA_CSTCE_G_A_GRND(value)
#end


/********************************************************************************************************************************************
// 32.768 Hz Crystal
// Producer: Abracon
// Web: www.abracon.com
// Part: ABM3B
// Carsten Koegler <koegler(replace with at)ftz-leipzig.de>
********************************************************************************************************************************************/
#macro SPC_CRYSTAL_ABRACON_ABS13_GRND(value)
#local SPC_CRYSTAL_METAL_TEXTURE = texture {col_silver};
#local SPC_CRYSTAL_PLASTIC_TEXTURE = texture { pigment{White*0.2}} ;

union{
	//Grundkoerper
	difference
	        {
                box{<-3.45,0.03,-0.7> <3.45,1.3,0.7>}
                box{<-3.45,0.03,-0.9> <3.45,1.3,0.9> rotate<0,0,45> translate<-4.2,0,0>}
                texture{SPC_CRYSTAL_PLASTIC_TEXTURE}
                }    
        text {ttf besch_font value 0.2, 0 pigment { Gray60 } rotate<90,0,0> scale 1.0 translate<-2.3, 1.31,-0.3>}
	
	//Anschlusspads
	box{<-0.3,0,-0.21><0.3,0.4,0.21> texture{col_silver} translate<-3.28,0, 0.50>}
	box{<-0.3,0,-0.21><0.3,0.4,0.21> texture{col_silver} translate<-3.28,0,-0.50>}
	box{<-0.3,0,-0.21><0.3,0.4,0.21> texture{col_silver} translate< 3.28,0, 0.50>}
	box{<-0.3,0,-0.21><0.3,0.4,0.21> texture{col_silver} translate< 3.28,0,-0.50>}

}
#end

#macro SPC_CRYSTAL_ABRACON_ABS13(value)
SPC_CRYSTAL_ABRACON_ABS13_GRND(value)
#end


/********************************************************************************************************************************************
// SMD-Crystal MA505
// everyone1@freenet.de
********************************************************************************************************************************************/
#macro SPC_CRYSTAL_SMD_MM505_GRND(value)
#macro SPC_CRYSTAL_SMD_MM505_PIN(H,B,T,S,H2,R,rx,ry,rz,tx,ty,tz)
        difference{
                union{
	                box{ < 0, 0 ,-T/2> < B-S, S,T/2>}

        	        difference{
		                cylinder{ < B-S-0.01, S+0.01, -T/2> <B-S-0.01, S+0.01 ,T/2> S+0.01 }
		                box { < B-2*S-0.1, S+0.01, -T/2-0.1> < B-S-0.01, S*2+0.1, T/2+0.1> }
	                }

                	box{ < B-S, S, -T/2> < B, H-S, T/2> }
	                difference{
		                cylinder{ < B-S-0.01, H-S-0.01, -T/2> <B-S-0.01, H-S-0.01 ,T/2> S+0.01 }
		                box { < B-2*S-0.1, H-S-0.01, -T/2-0.1> < B-S-0.01, H-S*2-0.1, T/2+0.1> }
	                }

	                box{ < 0, H-S, -T/2> < B-S, H, T/2> }
	                translate <-B, 0, 0>
                }

                prism{ -0.1, B+0.1, 5, 
                        <-T/2-0.1, H+0.1>, < 0, H+0.1>, < 0, H2+T/4>, <-T/2-0.1, H2-T/4>, <-T/2-0.1, H+0.1>
	                rotate<-90, 90, 0>
                        #if (R=1)
                                scale < 1, 1,-1>
                        #end
                }
	        texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)} }
	        rotate< rx, ry, rz> 
	        translate<tx,ty,tz>  
        }
        #end

union{
        SPC_CRYSTAL_SMD_MM505_PIN(2.2, 2.54, 1.09, 0.4, 0.8, 1, 0, 0, 0, 6.73, 0, -1.65)
        SPC_CRYSTAL_SMD_MM505_PIN(2.2, 2.54, 1.09, 0.4, 0.8, 0, 0, 0, 0, 6.73, 0,  1.65)
        SPC_CRYSTAL_SMD_MM505_PIN(2.2, 2.54, 1.09, 0.4, 0.8, 1, 0, 180, 0,-6.73, 0, 1.65)
        SPC_CRYSTAL_SMD_MM505_PIN(2.2, 2.54, 1.09, 0.4, 0.8, 0, 0, 180, 0,-6.73, 0, -1.65)

        difference{
                prism{-2.6, 2.6, 8, 
                        <-6.15, 0.3>, < 6.15, 0.3>, < 6.35, 2.0>, < 6.05, 4.7>, 
                        <-4.35, 4.7>, <-6.35, 2.6>, <-6.35, 2.0>, <-6.15, 0.3>
	                rotate<-90, 0, 0>
                } 
                prism{-7.5, 7.5, 9, 
                        <-3.0, 0>, < 3.0, 0>, < 3.0, 2.01>, < 2.54, 2.01>, < 2.44, 0.4>, 
                        <-2.44, 0.4>, <-2.54, 2.01>, <-3.0, 2.01>, <-3.0, 0>
	                rotate<-90, 90, 0>
                }
                prism{-7.5, 7.5, 9, 
                        <-3.0, 5.0>, < 3.0, 5.0>, < 3.0, 2.0>, < 2.54, 2.0>, < 2.34, 4.6>, 
                        <-2.34, 4.6>, <-2.54, 2.0>, <-3.0, 2.0>, <-3.0, 5.0>
	                rotate<-90, 90, 0>
                }
                texture{pigment { Gray20 }}
        } 
        text{ttf global_fontfile_arial value 0.1,0 rotate<90,0,0> scale<1.8,1,1.8> translate<-4, 4.61, 0> pigment{Gray60}}
}
#end

#macro SPC_CRYSTAL_SMD_MM505(value)
SPC_CRYSTAL_SMD_MM505_GRND(value)
#end


/********************************************************************************************************************************************
// DC-DC CONVERTERs BY J. ZEGLINSKI
// DC-DC CONVERTER "NMA" D-series 6-pin DIP14  Package 1 Watt  Dual output voltage (e.g. NMA1205D)
// <JAZeglinski@rogers.com>
// C & D Technologies (formerly Newport Components) Dc-DC Converters:
********************************************************************************************************************************************/
#macro SPC_DC_DC_NMA_D_GRND(value)
union{
box{<-9.75,0,-4.9><9.75,6.8,4.9>}     // Body
cylinder{<-7.62,6.85,-3.81><-7.62,6.80,-3.81> 0.5 pigment{White} }   // Pin #1 marking
//
box{<-0.25,0,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<-7.62,0,+3.81> } // six square leads
box{<-0.25,0,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<-7.62,0,-3.81> } 
box{<-0.25,0,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<0,0,+3.81> } 
box{<-0.25,0,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<5.08,0,+3.81>  }
box{<-0.25,0,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<7.62,0,-3.81>  }
box{<-0.25,0,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<7.62,0,+3.81>  }
//
text {ttf besch_font value 0.1, 0 pigment{White} scale 1.75 rotate<90,0,0> translate<-8.75,6.81,3>}  // Marking on top surface
text {ttf besch_font "DC-DC CONVERTER" 0.1, 0 pigment{White} scale 1 rotate<90,0,0> translate<-8.75,6.81,2>} // Markings front surface 
text {ttf besch_font "C&D"  0.1, 0 pigment{White} scale<3.5,1.25,1> rotate<90,0,0> translate<2.41,6.81,-3.31>} 
text {ttf besch_font "TECHNOLOGIES"  0.1, 0 pigment{White} scale<0.85,1,1> rotate<90,0,0> translate<2.41,6.81,-4.31>} 
}
pigment{Gray20} 
#end
#macro SPC_DC_DC_NMA_D(value)
SPC_DC_DC_NMA_D_GRND(value)
#end


/********************************************************************************************************************************************
// DC-DC CONVERTERs BY J. ZEGLINSKI
// DC-DC CONVERTER "NMA" S-series 5-pin SIP7   Package 1 Watt  Dual output voltage (e.g. NMA1205S)
// <JAZeglinski@rogers.com>
// C & D Technologies (formerly Newport Components) Dc-DC Converters:
********************************************************************************************************************************************/
#macro SPC_DC_DC_NMA_S_GRND(value)
union{
box{<-9.75,0,-3><-9.25,0.5,3>}    // Feet left and right side
box{<9.75,0,-3><9.25,0.5,3>}
box{<-9.75,0.5,-3><9.75,10,3>}     // Body
cylinder{<-7.75,2.0,-3.05><-7.75,2.0,-3.00> 0.5 pigment{White} }   // Pin #1 marking
//
box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<-7.75,0,1.75> } // five square leads
box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<-5.21,0,1.75> } // NB: Different from the NME_S
box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<-0.13,0,1.75> } //  NMA_S pins along "back" edge
box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<2.41,0,1.75>  }
box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<4.95,0,1.75>  }
//
text {ttf besch_font value 0.1, 0 pigment{White} scale 1.75 rotate<90,0,0> translate<-8.75,10.01,0>}  // Value on top surface
text {ttf besch_font value 0.1, 0 pigment{White} scale 1.75 translate<-8.75,8,-3.05>}                // Markings on vertical front face
text {ttf besch_font "DC-DC CONVERTER" 0.1, 0 pigment{White} scale 1 translate<-8.75,7,-3.05>} 
text {ttf besch_font "C&D"  0.1, 0 pigment{White} scale<3.5,1.25,1> translate<2.41,2.5,-3.05>} 
text {ttf besch_font "TECHNOLOGIES"  0.1, 0 pigment{White} scale<0.85,1,1> translate<2.41,1.5,-3.05>} 
}
pigment{Gray20}  translate<1.27,0,-1.75>  rotate<0,90,0>
#end
#macro SPC_DC_DC_NMA_S(value)
SPC_DC_DC_NMA_S_GRND(value)
#end


/********************************************************************************************************************************************
// DC-DC CONVERTERs BY J. ZEGLINSKI
// DC-DC CONVERTER "NME" S-series 4-pin SIP4   Package 2 Watts Single output voltage (e.g. NML0505S) 
// <JAZeglinski@rogers.com>
// C & D Technologies (formerly Newport Components) Dc-DC Converters:
********************************************************************************************************************************************/
#macro SPC_DC_DC_NME_S_GRND(value)
union{
box{<-7,0,-3.75><-6.5,0.5,3.75>}    // Feet left and right side
box{<7,0,-3.75><6.5,0.5,3.75>}
box{<-7,0.5,-3.75><7,10,3.75>}     // Body
cylinder{<-3.81,2.0,-3.80><-3.75,2.0,-3.0> 0.5 pigment{White} }   // Pin #1 marking
//
box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<-3.81,0,-2.5> } // four square leads
box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<-1.27,0,-2.5> } 
box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<3.81,0,-2.5> } 
box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<1.27,0,-2.5> }
//
text {ttf besch_font value 0.1, 0 pigment{White} scale 1.75 rotate<90,0,0> translate<-6,10.01,0>}
text {ttf besch_font value 0.1, 0 pigment{White} scale 1.75 translate<-6,8,-3.80>}
text {ttf besch_font "DC-DC CONVERTER" 0.1, 0 pigment{White} scale 1 translate<-6,7,-3.80>} 
text {ttf besch_font "C&D"  0.1, 0 pigment{White} scale<3.5,1.25,1> translate<-1.27,2.5,-3.80>} 
text {ttf besch_font "TECHNOLOGIES"  0.1, 0 pigment{White} scale<0.85,1,1> translate<-1.27,1.5,-3.80>} 
}
pigment{Gray20}  translate<0,0,2.5>  rotate<0,90,0>
#end
#macro SPC_DC_DC_NME_S(value)
SPC_DC_DC_NME_S_GRND(value)
#end


/********************************************************************************************************************************************
//Relais Uwe Lorenz <u.lorenz@er-dresden.net>
********************************************************************************************************************************************/
#macro SPC_DK1A_L2_5V_GRND()
union{
//***** Lötstift
cylinder{<-3.76,-3.5,-11.5><-3.76,1.1,-11.5>0.3 texture{col_silver}}
cylinder{<3.76,-3.5,-11.5><3.76,1.1,-11.5>0.3 texture{col_silver}}
cylinder{<-3.76,-3.5,-8.96><-3.76,1.1,-8.96>0.3 texture{col_silver}}
cylinder{<3.76,-3.5,-8.96><3.76,1.1,-8.96>0.3 texture{col_silver}}
//
cylinder{<-3.76,-3.5,11.5><-3.76,1.1,11.5>0.5 texture{col_silver}}
cylinder{<3.76,-3.5,11.5><3.76,1.1,11.5>0.5 texture{col_silver}}
cylinder{<-3.76,-3.5,3.88><-3.76,1.1,3.88>0.5 texture{col_silver}}
cylinder{<3.76,-3.5,3.88><3.76,1.1,3.88>0.5 texture{col_silver}}
//***** Ende Lötstifte
//
//***** Grundkörper
difference{
box{<-6.25,0.5,-12.5><6.25,12.0,12.5>}
box{<-2.0,10.8,8.5><2.0,12.1,12.6>}
}
//***** Ende Grundkörper
box{<-6.25,0.0,-6.5><-6.25,0.5,-5.0>}
box{<6.25,0.0,-6.5><6.25,0.5,-5.0>}
box{<-6.25,0.0,7.5><-6.25,0.5,6.0>}
box{<6.25,0.0,7.5><6.25,0.5,6.0>}
cylinder{<0.0,10.7,10.5><0.0,11.5,10.5>1.0}
//
text {ttf besch_font "NAIS" 0, 0 pigment{Gray80} scale<4,4,4> rotate<90,-90,0>
translate<-1.5,12.05,-10>}
text {ttf besch_font "DK1a-L2-5V" 0, 0 pigment{Gray80} scale<2,2,2> rotate<90,-90,0>
translate<1.5,12.05,-10>}
text {ttf besch_font "ADE129" 0, 0 pigment{Gray80} scale<1,1,1> rotate<90,-90,0>
translate<3.0,12.05,-10>}
text {ttf besch_font "10A250V~(COS°=1.0)" 0, 0 pigment{Gray80} scale<1,1,1> rotate<90,-90,0>
translate<4.0,12.05,-10>}
text {ttf besch_font "SPULE:5V=" 0, 0 pigment{Gray80} scale<1,1,1> rotate<90,-90,0>
translate<5.0,12.05,-10>}
text {ttf besch_font "JAPAN" 0, 0 pigment{Gray80} scale<2,2,2> rotate<90,-90,0>
translate<-3.4,12.05,5>}
pigment{Gray20} translate<0,0.2,0>}
#end
#macro SPC_DK1A_L2_5V()
SPC_DK1A_L2_5V_GRND()
#end


/********************************************************************************************************************************************
//Fuse Holder
//(c) 2003 Juraj Rojko  
********************************************************************************************************************************************/
#macro SPC_FUSE1_GRND(value)
union
{
   #macro SPC_FUSE1_HOLDER()
   union
   {
      // base plate
      box { <-.1,0,-2>,<4.3,.2,2>}     
      box { <4.6,0,-2>,<-.4,.2,-1.4> }
      box { <4.6,0,2>,<-.4,.2,1.4> }  
   
      // 1st pin
      box { <-.5,-5,-.4>,<-.3,-.2,.4> }
      
      intersection {
         difference {
            cylinder{<-.1,-.2,-.4><-.1,-.2,.4>.4}
            cylinder{<-.1,-.2,-.4><-.1,-.2,.4>.2 open}
         }
         box { <-.5,-.2,-.4>,<-0.1,.2,.4>}
      }
                   
      // 2nd pin
      box { <4.5,-5,-.4>,<4.7,-.2,.4> }
      
      intersection {
         difference {   
            cylinder{<4.3,-.2,-.4><4.3,-.2,.4>.4}
            cylinder{<4.3,-.2,-.4><4.3,-.2,.4>.2 open}
         }
         box { <4.3,-.2,-.4>,<4.7,.2,.4>}
      }
        
      // 1st holder arm
      box { <0,0,-2>,<4.25,4.4,-2.2> rotate<3,0,0>} 
     
      intersection {
         difference {
            cylinder{<0,6,.65><4.25,6,.65>3}
            cylinder{<0,6,.65><4.25,6,.65>2.8 open}
         }
         box { <-.1,4.4,-1.8>,<4.3,8,-3>}
      }      
                                      
                                      
      intersection {
         box { <0,7.3,-1.8>,<4.25,9.2,-2>}
         cylinder {<2.125,7,-5><2.125,7,5>2.5}
      }   
   
      // 2st holder arm
      box { <0,0,2>,<4.25,4.4,2.2> rotate<-3,0,0>}
             
      intersection {
         difference {
            cylinder{<0,6,-.65><4.25,6,-.65>3}
            cylinder{<0,6,-.65><4.25,6,-.65>2.8 open}
         }
         box { <-.1,4.4,1.8>,<4.3,8,3>}
      }       
   
      intersection {
         box { <0,7.3,1.8>,<4.25,9.2,2>}
         cylinder {<2.125,7,-5><2.125,7,5>2.5}
      }   
   
      texture{col_silver}                                    
   }
   #end

   #macro SPC_FUSE1_CUP()
   union
   {
      difference {
         cylinder{<0,6,0><3.5,6,0>2.15 } 
         cylinder{<0.2,6,0><3.5,6,0>2 open} 
      }
      torus{2.15-.3,.3 rotate<0,0,90> translate<0,6,0>} 
   
      // drop of solder
      difference {
         sphere{<.8,6,0>1.2}
         box {<0,4,-2><3,8,2>}
      }
      
      translate<.3,0,0>
      texture{col_silver}
      
   }
   #end
   
   
#if (on) // draw holder on/off
   object {
      SPC_FUSE1_HOLDER()
      
      rotate<0,0,0> translate<-10,0,0>
      texture{col_silver}                                    
   }

   object {
      SPC_FUSE1_HOLDER()
      
      rotate<0,180,0> translate<10,0,0>
      texture{col_silver}                                    
   }
#end      
      
#if (on) // draw fuse on/off
   object
   {
      SPC_FUSE1_CUP()
      
      rotate<0,0,0> translate<-10,0,0>
      texture{col_silver}
      
   }
  
   // glass tube
   difference { 
      cylinder{<-9,6,0><9,6,0>2}
      cylinder{<-9,6,0><9,6,0>1.8}
      texture {T_Green_Glass}
   }

   // fiber
   cylinder{<-9,6,0><9,6,0>.07 texture{col_silver} translate<0,0,0>} 

   object
   {
      SPC_FUSE1_CUP()
      
      rotate<0,180,0> translate<10,0,0>
      texture{col_silver}
      
   }
            
   // value   
   intersection{
     difference { 
        cylinder{<-9,6,0><9,6,0>2.01}
        cylinder{<-9,6,0><9,6,0>2}
     }
     text {ttf besch_font value 2, 0 scale 2 rotate<90,0,0> translate<-2,10,-.6> }
     pigment {White}
   }  

#end

}

#end
#macro SPC_FUSE1(value)
SPC_FUSE1_GRND(value)
#end


/********************************************************************************************************************************************
//--------------------------------------------------------------------------------------------------
// FUSE HOLDER SHK20Q FOR FUSES 5 x 20 mm, SH contact, E1207 Buerklin 46G6061
// fbleikamp(replace with at)web.de
//--------------------------------------------------------------------------------------------------
********************************************************************************************************************************************/
#macro SPC_FUSE2_GRND(value)
#macro SPC_FUSE2_PART()
union{
   object{TOOLS_RECT_BOGEN(0.25,167.5,0.3,4,3.0,2.8507) rotate<0,0,0>translate <0,0,0>}
   object{TOOLS_RECT_BOGEN(0.25,125.428,0.3,4,0,0) rotate<180,0,-12.5> translate <-2.85631,0.712,0>}
   object{TOOLS_RECT_BOGEN(2.5,84.144,0.3,4,0,0) rotate<0,0,42.072> translate <-4.785 ,-1.242, 0>}
   object{TOOLS_RECT_BOGEN(0.25,125.428,0.3,4,0.7,0) rotate<180,180,0> translate <-6.6585,1.10,0>}
   difference{
      box {<3.125,-0.15,-0.6><7,0.15,0.6>}
      box {<3.125,-0.16,-0.6><7,0.16,0.6> rotate <0,-10,0> translate <0.5,0,-2.0>}
      box {<3.125,-0.16,-0.6><7,0.16,0.6> rotate <0,10,0> translate <0.5,0,2.0>}
   } texture{col_silver} rotate<0,0,-90> translate <-2.50,3.4,0>
}
#end
  
#macro SPC_FUSE2_HOLDER()
union{      
   object {SPC_FUSE2_PART()}
   object {SPC_FUSE2_PART() rotate <0,180,0>}
   object{TOOLS_RECT_BOGEN(0.1,90,0.3,2,2.25,0) rotate<90,0,0>translate <-2.5,1.2,-2.25>}
   object{TOOLS_RECT_BOGEN(0.1,90,0.3,2,2.25,0) rotate<-90,180,0>translate <2.5,1.2,-2.25>}
   intersection {
      merge {
         cylinder {<-0.3,0,0><0.3,0,0>2.5 }
         torus {2.5,.3 rotate<0,0,90>}
         box {<-0.3,-2.5,0><0.3,2.5,-1>} 
      }
      box {<-0.31,-1,3><0,1,-0.5>}
      texture {col_silver} rotate <20,-90,0> translate <0,8,-2>}
   rotate <0,90,0>  texture{col_silver}
}
#end

#macro SPC_FUSE2_CUP()
union {
   difference {
      cylinder{<0.0,0,0><4.8,0,0>2.5 } 
      cylinder{<0.1,0,0><4.9,0,0>2.25 open} 
   }
   cylinder{<-0.2,0,0><0,0,0>2.3 }
   torus{2.3,.2 rotate<0,0,90>} 
   texture {col_silver}     
   translate<0,0,0>
}
#end

#macro SPC_FUSE_20X5(value)
union {
   object
   {
      SPC_FUSE2_CUP()      
      rotate<0,0,0> translate<-9.8,0,0>
      texture{col_silver}     
   }
  
// glass tube
   difference { 
      cylinder{<-9,0,0><9,0,0>2.2}
      cylinder{<-9,0,0><9,0,0>1.9}
      texture {T_Glass3}
   }

// fiber
   cylinder{<-9,-1.3,-1.5><9,1.3,1.5>.07 texture{col_silver}} 

   object
   {
      SPC_FUSE2_CUP()      
      rotate<0,180,0> translate<9.8,0,0>
      texture{col_silver}      
   }
   
// value
#if (strlen(value)>0)  
   intersection{
     difference { 
        cylinder{<-9,0,0><9,0,0>2.21}
        cylinder{<-9,0,0><9,0,0>2.2}
     }
     text {ttf besch_font value 2, 0 scale 2 rotate<90,0,0> translate<-4,4,-.6> }
     pigment{White}
   }
#end                 
}
#end

union{
   object {SPC_FUSE2_HOLDER() rotate <0,180,0> translate <8,0,0> }
   object {SPC_FUSE2_HOLDER() rotate <0,0,0> translate <-8,0,0> }
   object {SPC_FUSE_20X5(value) translate <0,8,0> }
}
#end
#macro SPC_FUSE2(value)
SPC_FUSE2_GRND(value)
#end


/********************************************************************************************************************************************
//Macros for TO220 heatsink type KL195 and KL195i SEIFERT
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1 - 04/01/06
********************************************************************************************************************************************/
#macro SPC_HEATSINK_KL195_GRND(Lg,Iso)
#macro half_KL195 (Lg, Iso)
union{
        difference {
                union{
                    //body with sharp edges
                    prism {0 Lg 38 <0,0>,<0,1.1>,<8.4,1.1>,<11.63,12.29>,<12.78,11.95>,<11.11,4.55>,<12.88,4.2>,<15.725,12.28>,
                    <16.88,11.94>,<14.44,4.68>,<16.15,4.1>,
                    <19.97,11.28>,<21.05,10.76>,<17.35,4.1>,<18.00,3.42>,<20.415,4.194>,<20.69,3.237>,<13.75,0.6>,<13.75,0>,
                    
                    <-13.75,0>,<-13.75,0.6>,<-20.69,3.237>,<-20.415,4.194>,<-18.00,3.42>,<-17.25,4.1>,<-21.05,10.76>,<-19.97,11.28>,
                    <-16.15,4.1>,<-14.44,4.68>,<-16.88,11.94>,<-15.725,12.28>,
                    <-12.88,4.2>,<-11.11,4.55>,<-12.78,11.95>,<-11.63,12.29>,<-8.4,1.1>,<-0,1.1>,<0,0>
                    }
                    //make external round edges      
                    cylinder{<12.2,0,12.1><12.2,Lg,12.1> .6}
                    cylinder{<16.3,0,12.1><16.3,Lg,12.1> .6}
                    cylinder{<20.5,0,11><20.5,Lg,11> .6}
                    cylinder{<20.5,0,3.7><20.5,Lg,3.7> .5} 
                    
                    cylinder{<-12.2,0,12.1><-12.2,Lg,12.1> .6}
                    cylinder{<-16.3,0,12.1><-16.3,Lg,12.1> .6}
                    cylinder{<-20.5,0,11><-20.5,Lg,11> .6}
                    cylinder{<-20.5,0,3.7><-20.5,Lg,3.7> .5}
                }
                
                union{
                
                    cylinder{<-14,-0.01,0><-14,Lg+0.01,0> 0.65 }
                    //make internal round edges
                    cylinder{<12,-0.01,4.4><12,Lg+0.01,4.4> 0.9}
                    cylinder{<15.3,-0.01,4.4><15.3,Lg+0.01,4.4> 0.9}
                    cylinder{<17.8,-0.01,3.88><17.8,Lg+0.01,3.88> 0.5}    
                    cylinder{<14,0,-0.01><14,Lg,0> 0.65}    
                
                    cylinder{<-12,-0.01,4.4><-12,Lg+0.01,4.4> 0.9}
                    cylinder{<-15.3,-0.01,4.4><-15.3,Lg+0.01,4.4> 0.9}
                    cylinder{<-17.8,-0.01,3.88><-17.8,Lg+0.01,3.88> 0.5}    
                    
                } 
                pigment{Gray30}
        
         }   
         
        //insulation rings and pins
        #if(Iso=1)
            cylinder{<12.7,-3,0><12.7,0,0> 3 pigment{Gray80}}    // ring
            cylinder{<12.7,-6,0><12.7,0,0> 1.25 pigment{Silver}} // pin          
        #else
            cylinder{<12.7,-4,0><12.7,0,0> 1.25 pigment{Silver}} // pin          
        #end
}
#end

union{
#local hole_height=18.3;
#local KL195_thickness=2.2;
#local TO220_thickness=1.27;
#local washer_thickness=0.8;

    #if(Iso=0) // Screws is used only with no insolated version (should to use clips instead)
        #if(global_show_screws=on)
            object { TOOLS_SCREW(3,8,0,Silver) rotate -90*x translate <0,hole_height,-KL195_thickness/2> }
        #end
        #if(global_show_washers=on)
            object { TOOLS_WASHER(3,1,Silver) rotate 90*x translate <0,hole_height,+KL195_thickness/2+TO220_thickness> }
        #end
        #if(global_show_nuts=on)
            object { TOOLS_NUT(3,0,Silver) rotate 90*x translate <0,hole_height,+KL195_thickness/2+TO220_thickness+washer_thickness> }
        #end
    #end
    difference{
            union{
                object{half_KL195(Lg, Iso)}
                object{half_KL195(Lg, Iso) rotate 180*y }
            }
            //holes
            union{
            cylinder{<0,18.3,-5><0,18.3,+5> 1.6}
            #if(Lg>25.4)
                 cylinder{<0,25.4,-5><0,25.4,+5> 1.6}
            #end
            }
        
        pigment{Gray20}
    }
    translate <0,Iso*3,-1.1> // shift 3 if insulation ring exist, shift 1.1 to set zero on heatsink surface
}
#end


#macro SPC_HEATSINK_KL195_25()
SPC_HEATSINK_KL195_GRND(25.4,0)
#end
#macro SPC_HEATSINK_KL195_38()
SPC_HEATSINK_KL195_GRND(38.4,0)
#end
#macro SPC_HEATSINK_KL195_50()
SPC_HEATSINK_KL195_GRND(50.8,0)
#end
#macro SPC_HEATSINK_KL195_63()
SPC_HEATSINK_KL195_GRND(63.5,0)
#end
#macro SPC_HEATSINK_KL195_25I()
SPC_HEATSINK_KL195_GRND(25.4,1)
#end
#macro SPC_HEATSINK_KL195_38I()
SPC_HEATSINK_KL195_GRND(38.4,1)
#end
#macro SPC_HEATSINK_KL195_50I()
SPC_HEATSINK_KL195_GRND(50.8,1)
#end
#macro SPC_HEATSINK_KL195_63I()
SPC_HEATSINK_KL195_GRND(63.5,1)
#end


/********************************************************************************************************************************************
//Macros for TO220 heatsink RA 37/3 from Seem
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1 - 01/01/06
********************************************************************************************************************************************/
#macro SPC_HEATSINK_RA37_GRND() 
difference{
    union{
    object{SPC_HEATSINK_RAWA400_9P() translate -17*x }
    object{SPC_HEATSINK_RAWA400_9P() translate +8*x }
    }
    box{<-8,-0.1,-5.5><+3,2.1,+5.5> pigment{Gray20}}
    translate +17*x
}
#end
#macro SPC_HEATSINK_RA37_3()
SPC_HEATSINK_RA37_GRND()
#end


/********************************************************************************************************************************************
//Macros for TO220 heatsink RAWA-400 from Seifert and RA 37/3 from Seem
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1 - 01/01/06
********************************************************************************************************************************************/
#macro SPC_HEATSINK_RAWA400_GRND (L1,D,Type)
union{
#local rawa_height=2;
#local TO220_height=1.27;
#local washer_height=0.8;
    #if(global_show_screws=on)
        object { TOOLS_SCREW(3,10,0,Silver) rotate 180*x translate <0,-pcb_height,0> }
    #end
    #if(global_show_washers=on)
        object { TOOLS_WASHER(3,1,Silver) translate <0,+rawa_height+TO220_height,0> }
    #end
    #if(global_show_nuts=on)
        object { TOOLS_NUT(3,0,Silver) translate <0,+rawa_height+TO220_height+washer_height,0> }
    #end
    difference{
        union{
            box{<-8,0,-6><17,02,+6> pigment{Gray20}} // base   
            box{<-8,0,-6><17,11,-8> pigment{Gray20}} // side   
            box{<-8,0,+6><17,11,+8> pigment{Gray20}} // side    
        }
        union{
            box{<L1,-0.1,-5.5><17.1,2.1,+5.5> pigment{Gray20}}    
            cylinder{<0,-.1,0><0,2.1,0> D/2 pigment{Gray20}}
            #if(Type=2)
                cylinder{<-2.5,-.1,0><-2.5,2.1,0> D/2 pigment{Gray20}}
                box{<-2.5,-0.1,-D/2><0,2.1,D/2> pigment{Gray20}}
            #end
        } 
    } 
}
#end
#macro SPC_HEATSINK_RAWA400_8P()
SPC_HEATSINK_RAWA400_GRND (13,3.8,0)
#end
#macro SPC_HEATSINK_RAWA400_9P()
SPC_HEATSINK_RAWA400_GRND (9,3.2,1)
#end
#macro SPC_HEATSINK_RAWA400_11P()
SPC_HEATSINK_RAWA400_GRND (9,3.2,2)
#end


/********************************************************************************************************************************************
//Macros for SK 104 heatsink for TO220, SOT32, TO3P
//Designed by Stefan Seegel <dahamm(replace with at)@gmx.net>
//17/10/06
//
//h:		height of heatsink
//typ:		0 = mounting clip, 1 = solder pins, 2 = solder pins and insulation washer, 3 = M3 threaded bolts, brass
//gap:	leave out gap on bottom if heatsink
//d:		make drills
********************************************************************************************************************************************/
#macro SPC_HEATSINK_SK104_GRND(h, typ, gap)

#macro SPC_HEATSINK_SK104_MOUNTINGCLIP_HALF()
union{
#local bw1 = 11;
#local bw2 = 95;
#local bw3 = 80;
#local bw4 = 160;
#local brm = 7;
#local br = 1;
#local d = 0.5;
#local rm = (2*br-d)/2;
#local rmm = (2*brm-d)/2;
#local s1 = 16.5;
#local s2 = 5.0;
#local s3 = 1.5;
#local s4 = 1.0;
#local hc = 6.4;

	difference{
		cylinder{<0,-hc/2,0><0,hc/2,0> brm}
		cylinder{<0,-hc,0><0,hc,0> brm-d}
		
		box{<0, -hc, -brm>,<-brm, hc, brm> rotate<0,0,0>}
		box{<0, -hc, -brm>,<brm, hc, brm> rotate<0,bw1,0>}
	}
	
	
	#local dx=sin(bw1/180*pi)*rmm;
	#local dy=cos(bw1/180*pi)*rmm;
	
	box{<-d/2, -hc/2, 0>,<d/2, hc/2, -s1> rotate<0,-90+bw1,0> translate<dx,0,dy>}
	
	#local dx=dx+s1*cos(bw1/180*pi);
	#local dy=dy-s1*sin(bw1/180*pi);
	
	union
	{
		difference{
			cylinder{<0,-hc/2,0><0,hc/2,0> br}
			cylinder{<0,-hc,0><0,hc,0> br-d}
			box{<0, -hc, -br>,<-br, hc, br> rotate<0,bw1,0>}
			#local bwx = bw1-bw2;
			box{<0, -hc, -br>,<br, hc, br> rotate<0,bwx,0>}
		}
			
	
		box{<-d/2, -hc/2, 0>,<d/2, hc/2, s2> rotate<0,bwx+90,0> translate<-sin(bwx/180*pi)*rm,0,-cos(bwx/180*pi)*rm>}
		
		
		#local dx=dx+sin(bw1/180*pi)*rm;
		#local dy=dy+cos(bw1/180*pi)*rm;
		translate<dx,0,dy>
	}
	
	#local dx = dx-rm*sin(bwx/180*pi) + s2*cos(bwx/180*pi);
	#local dy = dy-rm*cos(bwx/180*pi) - s2*sin(bwx/180*pi);
	
	//box{<-d/2, 0, 0>,<d/2, 6.5, s2> rotate<0,bw1-bw2+90,0> translate<dx,0,dy> texture{col_silver}}
	
	
	union
	{
		difference{
			cylinder{<0,-hc/2,0><0,hc/2,0> br}
			cylinder{<0,-hc,0><0,hc,0> br-d}
			box{<0, -hc, -br>,<-br, hc, br> rotate<0,bwx,0>}
			#local bwx = bwx-bw3;
			box{<0, -hc, -br>,<br, hc, br> rotate<0,bwx,0>}
		}
		
		box{<-d/2, -hc/2, 0>,<d/2, hc/2, s3> rotate<0,bwx+90,0> translate<-sin(bwx/180*pi)*rm,0,-cos(bwx/180*pi)*rm>}
		
		#local dx = dx - rm*cos(bw1/180*pi);
		#local dy = dy + rm*sin(bw1/180*pi);
		translate<dx,0,dy>
	}
	
	#local dx = dx -rm*sin(bwx/180*pi) + s3*cos(bwx/180*pi);
	#local dy = dy -rm*cos(bwx/180*pi) - s3*sin(bwx/180*pi);
	
	union
	{
		difference{
			cylinder{<0,-hc/2,0><0,hc/2,0> br}
			cylinder{<0,-hc><0,hc,0> br-d}
			box{<0, -hc, -br>,<-br, hc, br> rotate<0,bwx,0>}
			#local bwx = bwx+bw4;
			box{<0, -hc, -br>,<br, hc, br> rotate<0,bwx,0>}
		}
		
		box{<-d/2, -hc/2, 0>,<d/2, hc/2, s4> rotate<0,bwx+90,0> translate<sin(bwx/180*pi)*rm,0,cos(bwx/180*pi)*rm>}
		
		
		#local dx = dx - rm*sin((bwx-bw4)/180*pi);
		#local dy = dy - rm*cos((bwx-bw4)/180*pi);
		translate<dx,0,dy>
		
	}
	
	texture{col_gold}
	
}
#end

#macro SPC_HEATSINK_SK104_QUARTER(h)
union
{
	prism
	{
		0, h, 15,
		<-7.5,0.75>, 
		<-8,5.7>,<-9.2,5.6>,
		<-9.6,2.1>,
		<-12.5,6>,<-13.3,5.2>,
		<-12.3,3.4>,
		<-16.8,6>,<-17.6,5.1>,
		<-14.7,2.9>,
		<-17.0,3.6>,<-17.6,2.7>,
		<-12.7,0>,<0,0>,<0,0.75>
	}
	
	cylinder{<-8.6,0,5.65>,<-8.6,h,5.65> 0.6}
	cylinder{<-12.9,0,5.6>,<-12.9,h,5.6> 0.56}
	cylinder{<-17.2,0,5.55>,<-17.2,h,5.55> 0.6}
	cylinder{<-17.3,0,3.15>,<-17.3,h,3.15> 0.54}
	
}
#end

union
{
	difference
	{
		union
		{	                       
			object{SPC_HEATSINK_SK104_QUARTER(h)}
			object{SPC_HEATSINK_SK104_QUARTER(h) rotate<0,180,0>}
			object{SPC_HEATSINK_SK104_QUARTER(h) rotate<180,0,0> translate<0,h,0>}
			object{SPC_HEATSINK_SK104_QUARTER(h) rotate<180,180,0> translate<0,h,0>}
		}
		
		cylinder{<-12.7,-1,0>,<-12.7,h+1,0> 1.15}
		cylinder{<12.7,0,0>,<12.7,h+1,0> 1.15}
		
		#if (typ != 0)
		
			cylinder{<0,13.5,-1>,<0,13.5,1> 1.6}
			cylinder{<0,18.3,-1>,<0,18.3,1> 1.6}
			cylinder{<0,25.4,-1>,<0,25.4,1> 1.6}
		#end
		
		
		#if (gap=on)
			box{<-5.4,-1,-1>,<5.4,6.5,1>}
		#end
		
		pigment{Gray30}
	}
	
	#if (typ=3) //SK104 xx STSB (M3 threaded bolts, brass)
	
		cylinder{<-12.7,0,0>,<-12.7,-1.5,0> 3.5 texture{col_gold}}
		cylinder{<12.7,0,0>,<12.7,-1.5,0> 3.5 texture{col_gold}}
		object{TOOLS_SCREW(3,13.5,-1,Brass) translate<-12.7,7,0> texture{col_gold}}
		object{TOOLS_SCREW(3,13.5,-1,Brass) translate<12.7,7,0> texture{col_gold}}
		
		
		object{TOOLS_WASHER(3,1,Silver) translate<12.7,-pcb_height-2.3> }
		object{TOOLS_NUT(3,0,Silver) translate<12.7,-pcb_height-4.3,0> }
		
		object{TOOLS_WASHER(3,1,Silver) translate<-12.7,-pcb_height-2.3,0> }
		object{TOOLS_NUT(3,0,Silver) translate<-12.7,-pcb_height-4.3,0> }
		
		
		translate<0,1.5,0>
	#end
	
	#if (typ=2) //SK104 xx STIS (solder pins and insulation washer)
		//insulating washers
		cylinder{<-12.7,0,0>,<-12.7,-3,0> 3 pigment{White}}
		cylinder{<12.7,0,0>,<12.7,-3,0> 3 pigment{White}}

		//solder pins		
		cylinder{<-12.7,7,0>,<-12.7,-6,0> 1.15 texture{col_gold}} 
		cylinder{<12.7,7,0>,<12.7,-6,0> 1.15 texture{col_gold}}
		
		translate<0,3,0>
		
	#end
	
	#if (typ=1 | typ=0) //SK104 xx STS (solder pins)
		//solder pins
		cylinder{<-12.7,7,0>,<-12.7,-4.5,0> 1.15 texture{col_gold}}
		cylinder{<12.7,7,0>,<12.7,-4.5,0> 1.15 texture{col_gold}}
	#end
	
	#if (typ=0) //Mounting clip
		union
		{
			object{SPC_HEATSINK_SK104_MOUNTINGCLIP_HALF() rotate<0,180,0>} 
			object{SPC_HEATSINK_SK104_MOUNTINGCLIP_HALF() rotate<0,180,180>}
			translate<0,9,12>
		}
	#end
	
	
}

#end
#macro SPC_HEATSINK_SK104_254_STS()
SPC_HEATSINK_SK104_GRND(25.4, 1, on)
#end
#macro SPC_HEATSINK_SK104_381_STS()
SPC_HEATSINK_SK104_GRND(38.1, 1, on)
#end
#macro SPC_HEATSINK_SK104_508_STS()
SPC_HEATSINK_SK104_GRND(50.8, 1, on)
#end
#macro SPC_HEATSINK_SK104_635_STS()
SPC_HEATSINK_SK104_GRND(63.5, 1, on)
#end
#macro SPC_HEATSINK_SK104_254_STIS()
SPC_HEATSINK_SK104_GRND(25.4, 2, on)
#end
#macro SPC_HEATSINK_SK104_381_STIS()
SPC_HEATSINK_SK104_GRND(38.1, 2, on)
#end
#macro SPC_HEATSINK_SK104_508_STIS()
SPC_HEATSINK_SK104_GRND(50.8, 2, on)
#end
#macro SPC_HEATSINK_SK104_635_STIS()
SPC_HEATSINK_SK104_GRND(63.5, 2, on)        
#end
#macro SPC_HEATSINK_SK104_254_STSB()
SPC_HEATSINK_SK104_GRND(25.4, 3, on)
#end
#macro SPC_HEATSINK_SK104_381_STSB()
SPC_HEATSINK_SK104_GRND(38.1, 3, on)
#end
#macro SPC_HEATSINK_SK104_508_STSB()
SPC_HEATSINK_SK104_GRND(50.8, 3, on)
#end
#macro SPC_HEATSINK_SK104_635_STSB()
SPC_HEATSINK_SK104_GRND(63.5, 3, on)
#end
#macro SPC_HEATSINK_SK104_254_MC()
SPC_HEATSINK_SK104_GRND(25.4, 0, on)
#end
#macro SPC_HEATSINK_SK104_381_MC()
SPC_HEATSINK_SK104_GRND(38.1, 0, on)
#end
#macro SPC_HEATSINK_SK104_508_MC()
SPC_HEATSINK_SK104_GRND(50.8, 0, on)
#end
#macro SPC_HEATSINK_SK104_635_MC()
SPC_HEATSINK_SK104_GRND(63.5, 0, on)
#end


/********************************************************************************************************************************************
//Kuehlkoerper SK96/84
********************************************************************************************************************************************/
#macro SPC_HEATSINK_SK96_GRND(l)
union{
#local black_al = texture{  pigment{Black}
                            finish {
                                specular .7 
                                roughness .03 
                                reflection .05  
                                ambient (0.2 * global_ambient_mul) 
                                diffuse .5 
                                brilliance 4
                            } 
                         }
      difference{
        union{
              prism{0,l,9 <0,0>,<8,0>,<8,12.5>,<9.5,12.5>,<9.5,14>,<54,14>,<54,27>,<0,27>,<0,0>}   // Grundkörper
              cylinder{<54,0,15><54,l,15>1}                                                        // gerundete Ecken
              cylinder{<54,0,19><54,l,19>1}
              cylinder{<54,0,23><54,l,23>1}
              cylinder{<54,0,27><54,l,27>1}
                                                                                                   // Rundung der Kühlrippen
              cylinder{<1,0,27><1,l,27>1}
              cylinder{<6,0,27><6,l,27>1}
              cylinder{<11,0,27><11,l,27>1}
              cylinder{<16,0,27><16,l,27>1}
              cylinder{<21,0,27><21,l,27>1}
              cylinder{<26,0,27><26,l,27>1}
              cylinder{<31,0,27><31,l,27>1}
              cylinder{<36,0,27><36,l,27>1}
              cylinder{<41,0,27><41,l,27>1}
              cylinder{<46,0,27><46,l,27>1}                                                        // Flaeche ueber den horiz. Kuehlrippen
              box{<46,0,28><54,l,26.9>}
        }
        union{
                cylinder{<9.5,0-0.01,12.5><9.5,l+0.01,12.5>1.5}                                    // Innenecke unterhalb
                
                box{<2,-0.1,25><5,l+0.1,28.1>}                                                     // Erste 2 senkrechte Kuehlrippen
                cylinder{<3.5,-0.1,25><3.5,l+0.1,25>1.5}
                box{<7,-0.1,25><10,l+0.1,28.1>}
                cylinder{<8.5,-0.1,25><8.5,l+0.1,25>1.5}
                
                box{<12,-0.1,19><15,l+0.1,28.1>}                                                   // Die restlichen senkrechten Kuehlrippen
                cylinder{<13.5,-0.1,19><13.5,l+0.1,19>1.5}
                box{<17,-0.1,19><20,l+0.1,28.1>}
                cylinder{<18.5,-0.1,19><18.5,l+0.1,19>1.5}
                box{<22,-0.1,19><25,l+0.1,28.1>}
                cylinder{<23.5,-0.1,19><23.5,l+0.1,19>1.5}
                box{<27,-0.1,19><30,l+0.1,28.1>}
                cylinder{<28.5,-0.1,19><28.5,l+0.1,19>1.5}
                box{<32,-0.1,19><35,l+0.1,28.1>}
                cylinder{<33.5,-0.1,19><33.5,l+0.1,19>1.5}
                box{<37,-0.1,19><40,l+0.1,28.1>}
                cylinder{<38.5,-0.1,19><38.5,l+0.1,19>1.5}
                box{<42,-0.1,19><45,l+0.1,28.1>}
                cylinder{<43.5,-0.1,19><43.5,l+0.1,19>1.5}
                
                box{<55.1,-0.1,16><50,l+0.1,18>}                                                   // Die horizontalen Kuehlrippen
                cylinder{<50,-0.1,17><50,l+0.1,17>1}
                box{<55.1,-0.1,20><50,l+0.1,22>}
                cylinder{<50,-0.1,21><50,l+0.1,21>1}
                box{<55.1,-0.1,24><50,l+0.1,26>}
                cylinder{<50,-0.1,25><50,l+0.1,25>1}
                
                box{<-0.1,-0.1,17><6.5,l+0.1,19>}                                                  // Die Montageloecher
                box{<3,-0.1,-0.1><5,l+0.1,8>}

        }
        rotate<-90,-90,0>
        translate<-l/2,0,0>
      }
texture {black_al}}
#end

#macro SPC_HEATSINK_SK96_84()
SPC_HEATSINK_SK96_GRND(84)
#end


/********************************************************************************************************************************************
//Macros for TO220 heatsink type HS-1.25GY-50 from Viewcom
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1 30/12/05
********************************************************************************************************************************************/
#macro SPC_HEATSINK_VIEWCOM_HS_1_25GY_50_GRND()
union{
#local hole_height=19;
#local Heatsink_thickness=4.2;
#local TO220_thickness=1.27;
#local washer_thickness=0.8;

    #if(global_show_screws=on)
        object { TOOLS_SCREW(3,10,0,Silver) rotate -90*x translate <0,hole_height,-Heatsink_thickness> }
    #end
    #if(global_show_washers=on)
        object { TOOLS_WASHER(3,1,Silver) rotate 90*x translate <0,hole_height,+TO220_thickness> }
    #end
    #if(global_show_nuts=on)
        object { TOOLS_NUT(3,0,Silver) rotate 90*x translate <0,hole_height,+TO220_thickness+washer_thickness> }
    #end
    
    difference{
        union{
            // main shap with sharp edges
            prism {0 32 56 <0,0>,<5.55,0>,<5.55,0.5>,<16.8,0.5>,<16.8,10>,<18.2,10>,<18.4,3.4>,<21.4,5.8>,<21.6,11.1>,<23.4,11.1>,<23.5,7.6>,
            <25.3,9.2>,<25.4,12.2>,<26.9,12.2>,<27.1,10.5>,<29,12>,<30.1,11.2>,<27.7,8.1>,<29.3,8.1>,<29.3,6.6>,<26.1,6.4>,<23.5,3.1>,
            <28.9,2.5>,<28.9,0.8>,<21.1,0.4>,<19.3,-1.6>,<28.9,-2.5>,<28.9,-4.2>,
            
            <-28.9,-4.2>,<-28.9,-2.5>,<-19.3,-1.6> ,<-21.1,0.4>,<-28.9,0.8>,<-28.9,2.5>,<-23.5,3.1>,<-26.1,6.4>,<-29.3,6.6>,<-29.3,8.1>,<-27.7,8.1>,
            <-30.1,11.2>,<-29,12>,<-27.1,10.5>,<-26.9,12.2>,<-25.4,12.2>,<-25.3,9.2>,<-23.5,7.6>,<-23.4,11.1>,<-21.6,11.1>,<-21.4,5.8>,<-18.4,3.4>,
            <-18.2,10>,<-16.8,10>,<-16.8,0.5>,<-5.55,0.5>,<-5.55,0>,<0,0>
            }                
            // round edges           
            cylinder{<28.9,0,-3.4><28.9,32,-3.4> .85}
            cylinder{<28.9,0,1.6><28.9,32,1.6> .85}
            cylinder{<29.2,0,7.4><29.2,32,7.4> .75}
            cylinder{<29.5,0,11.5><29.5,32,11.5> .7}
            cylinder{<26.2,0,12.2><26.2,32,12.2> .75}
            cylinder{<22.5,0,11.1><22.5,32,11.1> .85}
            cylinder{<17.7,0,10.8><17.7,32,10.8> 1.7}
            
            cylinder{<-28.9,0,-3.4><-28.9,32,-3.4> .85}
            cylinder{<-28.9,0,1.6><-28.9,32,1.6> .85}
            cylinder{<-29.2,0,7.4><-29.2,32,7.4> .75}
            cylinder{<-29.5,0,11.5><-29.5,32,11.5> .7}
            cylinder{<-26.2,0,12.2><-26.2,32,12.2> .75}
            cylinder{<-22.5,0,11.1><-22.5,32,11.1> .85}
            cylinder{<-17.7,0,10.8><-17.7,32,10.8> 1.7}
            
            pigment{Gray20}
        }
        union{
            // to make half cylinder
            box{<15.5,-0.1,8.4><16.8,32.1,12.8> }    
            box{<-15.5,-0.1,8.4><-16.8,32.1,12.8> }
            //round groove    
            cylinder{<17.2,-0.1,10.6><17.2,32.1,10.6> .75}
            cylinder{<-17.2,-0.1,10.6><-17.2,32.1,10.6> .75}
            // hole
            cylinder{<0,19,-5><0,19,+5> 1.8}
            
            pigment{Gray20}
        }
    }      
}
#end
#macro SPC_HEATSINK_VIEWCOM_HS_1_25GY_50()
SPC_HEATSINK_VIEWCOM_HS_1_25GY_50_GRND()
#end


/********************************************************************************************************************************************
//Macros for jumper such simple wire
//Designed by Philippe Boucheny <philippe.boucheny(at)numericable.fr>
//Modified by Adriano Gandolfo <adrirobot(at)yahoo.it>
//Rev. 1.1  30/10/08
//If value is set in Eagle (1 to 9), colors can be passed to POV, by Emil Crisbaseanu
//<emilcrisba(at)gmail.com>
********************************************************************************************************************************************/
#macro SPC_JUMPER_WIRE_GRND(Lg,value)
              

#local h=0.9;


#if (strcmp (value,"1")=0)
#local gain=cylinder{<-(Lg-1)/2,h,0>,<(Lg-1)/2,h,0>,0.6 pigment { Brown } finish { Shiny }}
#else
        #if (strcmp (value,"2")=0)
        #local gain=cylinder{<-(Lg-1)/2,h,0>,<(Lg-1)/2,h,0>,0.6 pigment { Red } finish { Shiny }}
        #else
                #if (strcmp (value,"3")=0)
                #local gain=cylinder{<-(Lg-1)/2,h,0>,<(Lg-1)/2,h,0>,0.6 pigment { Orange } finish { Shiny }}
                #else
                        #if (strcmp (value,"4")=0)
                        #local gain=cylinder{<-(Lg-1)/2,h,0>,<(Lg-1)/2,h,0>,0.6 pigment { Yellow } finish { Shiny }}
                        #else
                                #if (strcmp (value,"5")=0)
                                #local gain=cylinder{<-(Lg-1)/2,h,0>,<(Lg-1)/2,h,0>,0.6 pigment { Blue } finish { Shiny }}
                                #else
                                        #if (strcmp (value,"6")=0)
                                        #local gain=cylinder{<-(Lg-1)/2,h,0>,<(Lg-1)/2,h,0>,0.6 pigment { Green } finish { Shiny }}
                                        #else
                                                #if (strcmp (value,"7")=0)
                                                #local gain=cylinder{<-(Lg-1)/2,h,0>,<(Lg-1)/2,h,0>,0.6 pigment { Pink } finish { Shiny }}
                                                #else
                                                        #if (strcmp (value,"8")=0)
                                                        #local gain=cylinder{<-(Lg-1)/2,h,0>,<(Lg-1)/2,h,0>,0.6 pigment { Gray60 } finish { Shiny }}
                                                        #else
                                                                #if (strcmp (value,"9")=0)
                                                                #local gain=cylinder{<-(Lg-1)/2,h,0>,<(Lg-1)/2,h,0>,0.6 pigment { White } finish { Shiny }}
                                                                #else
                                                                        #local gain=cylinder{<-(Lg-1)/2,h,0>,<(Lg-1)/2,h,0>,0.1 pigment { Brown } finish { Shiny }}
                                                                #end
                                                        #end
                                                #end
                                        #end
                                #end
                        #end
                  
                #end
         #end
#end     

union {        
      object{ TOOLS_WIRE_LEADS(0, 1, 1, 0.4,  Lg,  0.5, 0, "H") translate<0,h,0> }
      object{gain}
}
#end



#macro SPC_JUMPER_WIRE_5MM(value)
SPC_JUMPER_WIRE_GRND(5.08,value)
#end
#macro SPC_JUMPER_WIRE_7MM(value)
SPC_JUMPER_WIRE_GRND(7.62,value)
#end
#macro SPC_JUMPER_WIRE_10MM(value)
SPC_JUMPER_WIRE_GRND(10.16,value)
#end
#macro SPC_JUMPER_WIRE_12MM(value)
SPC_JUMPER_WIRE_GRND(12.7,value)
#end
#macro SPC_JUMPER_WIRE_15MM(value)
SPC_JUMPER_WIRE_GRND(15.24,value)
#end
#macro SPC_JUMPER_WIRE_17MM(value)
SPC_JUMPER_WIRE_GRND(17.78,value)
#end
#macro SPC_JUMPER_WIRE_20MM(value)
SPC_JUMPER_WIRE_GRND(20.32,value)
#end
#macro SPC_JUMPER_WIRE_22MM(value)
SPC_JUMPER_WIRE_GRND(22.86,value)
#end
#macro SPC_JUMPER_WIRE_25MM(value)
SPC_JUMPER_WIRE_GRND(25.40,value)
#end
#macro SPC_JUMPER_WIRE_27MM(value)
SPC_JUMPER_WIRE_GRND(27.94,value)
#end
#macro SPC_JUMPER_WIRE_30MM(value)
SPC_JUMPER_WIRE_GRND(30.48,value)
#end


/********************************************************************************************************************************************
//Macros for light pipe from dialight
//Designed by Philippe Boucheny <philippe.boucheny(at)numericable.fr>
//Rev. 1.0  24/12/06
********************************************************************************************************************************************/
#macro SPC_LIGHTPIPE_5151049F_GRND()
#macro LPIPEFOOT ()
#local l1=0.8;
intersection{                               
        merge{
                cylinder{<0,-2.1,0><0,0.5,0> 0.97}
                cone{<0,-2.4,0>, 0.7,<0,-2.1,0> 0.97}
        }
        box{<-l1,-2.5,-l1><+l1,0.51,+l1> rotate 45*y}
}
#end

#local Ray=9;
#local Ray1=8.9;
#local rr1=0.6;
#local ff=1.7;
#local x1=-1.5;
merge{
        intersection{
                cylinder{<-4.13,2.62,0><-21.2,2.62,0> 1.75}
                sphere { <0, 0, 0>, 5.3 translate<-6.28,2.62,0>}
        }
        difference{
                merge{
                        intersection{
                                cylinder{<0,5.14-Ray,-1.74><0,5.14-Ray,+1.74> Ray}
                                box{<-4.13,0,-1.73><0,5.14,1.73>}
                               
                        }
                        cylinder{<-4.13,2.62,0><-11.2,2.62,0> 1.75}
                        intersection{
                                cylinder{<x1,5.14-Ray1,-1.74><x1,5.14-Ray1,+1.74> Ray}
                                box{<-0.01,0,-1.73><4.89,5.14,1.73>}
                        }
                }
                merge{
                        cylinder{<ff,2.35-rr1,-1.74><ff,2.35-rr1,+1.74> rr1}
                        box{<ff,-0.1,-1.74><5,2.35,+1.74>}
                        box{<ff-rr1,-0.1,-1.74><2,2.35-rr1,+1.74>}
                }
                box{<-5.6,-1,-1><0,+1,+1> rotate<45,0,40> translate<-1,7.8,-1.73>}
                box{<-5.6,-1,-1><0,+1,+1> rotate<45,0,40> translate<-1,7.8,+1.73>}
                box{<-5,-0.1,-1.3><+5,0.2,+1.3>}
        }
        object {LPIPEFOOT()}
        object {LPIPEFOOT() translate -2.9*x}
        
        texture {
            pigment { rgbf<1.0, 1.0, 1.0, 0.7> }
            finish  {
                 ambient (0.6 * global_ambient_mul)
                diffuse 0.5
                reflection 0.7
                specular 0.8
                roughness 0.0003
                phong 0.3 
                phong_size 400
             }
        }
        rotate 180*y
        translate 3.76*x

}
#end
#macro SPC_LIGHTPIPE_5151049F()
SPC_LIGHTPIPE_5151049F_GRND()
#end


/********************************************************************************************************************************************
//Spule mit Kern: d=8mm,  h=10mm
//A. Zihlmann  - 12.2002 -  www.wueschomania.org
********************************************************************************************************************************************/
#macro SPC_L_5MM_S_GRND(value)
/*** Die Oberflaechenstruktur: **************************************/
#local OBERFLAECHE =
texture{
   pigment{White*.3}
}
/** Objekte des Spulenkoeropers ************************************/
#local L_PHASE=
torus{
   4,0.5
   texture { OBERFLAECHE }
}
#local L_KABELNUT=
cylinder{
   <0, -4, 0>,
   <0,4,0>,
   0.75
   texture { OBERFLAECHE }
}

#local L_BODEN=
difference{
   cylinder {
       <0, 0, 0>,
       <0, 2, 0>,
        4
       texture { OBERFLAECHE }
   }
   union{
       object{L_PHASE}
       object{L_KABELNUT translate -4*x}
       object{L_KABELNUT translate 4*x}
   }
}

#local L_DECKEL=
   object{L_BODEN rotate x*180 translate 2*y}
#local L_CORE=

    cylinder {
       <0, 0, 0>,
       <0, 6, 0>,
        2
       texture {OBERFLAECHE }
    }

#local L_KERN=
union{
   object{L_BODEN}
   object{L_CORE translate y*2}
   object{L_DECKEL translate y*8}
}

/***** Kupferlackkabelemente ****************************************/
#local Drahtstaerke = .5;

#local L_WINDUNG =
torus {
   3, Drahtstaerke/2
   texture {T_Gold_1A }
}

#local L_ANSCHLUSS=
torus{
  0.5,Drahtstaerke/2
   texture{T_Gold_1A }
}

#local L_BOGEN=
difference {
    torus {
      1, Drahtstaerke/2
      rotate -90*x
    }
    union{
        box { <5, 5, -1>, <-5, 0, 1> }
        box { <0, 5, -1>, <5, -5, 1> }
    }
    texture{T_Gold_1A }
}
#local L_VERBINDUNG=
cylinder{
    <0,0,0>
    <0,2,0>
    Drahtstaerke/2
    texture{T_Gold_1A }
}

#local L_SPULE=

union {
    #local i=0;
    #while(i<11)
      object{L_WINDUNG translate i*Drahtstaerke*y}
      #local i=i+1;
    #end
}
/******* Die Beinchen ***************************************************/

#local L_Beinchen=
cylinder{
      <0,0,0>
      <0,6,0>
      0.25
      texture { T_Silver_1A }
}

/*** Zusammenbau der Spule: ***************************************************************/
#local L_BAUTEIL =
union{
   object{L_KERN}
   object{L_SPULE translate (2+Drahtstaerke/2)*y}
   object{L_Beinchen translate <-2.5,-6,0>}
   object{L_Beinchen translate <2.5,-6,0>}
   object{L_ANSCHLUSS translate <-2.5,-1,0>}
   object{L_ANSCHLUSS translate <-2.5,-0.5,0>}
   object{L_BOGEN translate -3*x}
   object{L_VERBINDUNG translate -4*x}
   object{L_BOGEN rotate -90*z translate <-3,2,0>}
   object{L_ANSCHLUSS translate <2.5,-1,0>}
   object{L_ANSCHLUSS translate <2.5,-0.5,0>}
   object{L_BOGEN rotate 180*y translate 3*x }
   object{L_VERBINDUNG translate 4*x}
   object{L_BOGEN rotate 180*z translate <3,2,0>}
   text {ttf besch_font value 0.01, 0 pigment{White}
           scale 2
           rotate 90*x rotate 180*y
           translate <2,10+0.1,-0.5>}
           }
object{L_BAUTEIL translate 2*y}
#end
#macro SPC_L_5MM_S(value)
SPC_L_5MM_S_GRND(value)
#end


/********************************************************************************************************************************************
// EF12 Spulenkern stehend by Anderas Fecht
********************************************************************************************************************************************/
#macro SPC_L_EF12_GRND(value)

union
{
 //***** Loetstifte
 cylinder{<-3.81,-3.5,-3.81><-3.81,1.1,-3.81>0.3 texture{col_silver}}
 cylinder{< 3.81,-3.5, 3.81>< 3.81,1.1, 3.81>0.3 texture{col_silver}}
 cylinder{< 3.81,-3.5,-3.81>< 3.81,1.1,-3.81>0.3 texture{col_silver}}
 cylinder{<-3.81,-3.5, 3.81><-3.81,1.1, 3.81>0.3 texture{col_silver}}


 //***** Kern
 union
 {
  difference
  {
   box{<-6,-1.75,-6><6,1.75,6>}
   box{<-4.5,-1.76,-4.5><4.5,1.76,4.5>}

   cylinder{< 6,-1.76, 6> < 6,1.76, 6> 1 }
   cylinder{<-6,-1.76,-6> <-6,1.76,-6> 1 }
   cylinder{<-6,-1.76, 6> <-6,1.76, 6> 1 }
   cylinder{< 6,-1.76,-6> < 6,1.76,-6> 1 }

  }
  cylinder{< 5,-1.75, 5> < 5,1.75, 5> 1 }
  cylinder{<-5,-1.75,-5> <-5,1.75,-5> 1 }
  cylinder{<-5,-1.75, 5> <-5,1.75, 5> 1 }
  cylinder{< 5,-1.75,-5> < 5,1.75,-5> 1 }

  pigment{rgb <0.3, 0.3, 0.3>}
  rotate<90,0,0>
  translate<0,6,0>
  }


 box{<-3,3,3><3,10,-3> texture {T_Gold_1A } }

 union  // Spulenkörper
 {


  difference
  {
   box{<-6, 0.5, 1.75>< 6,4, 5>}
   box{< 3, 0.4, 3><  1,4.1, 5.1>}
   box{<-1, 0.4, 3>< -3,4.1, 5.1>}

   cylinder{<  6, 0.4,5> <  6,4.1,5> 1 }
   cylinder{< -6, 0.4,5> < -6,4.1,5> 1 }

  }

  cylinder{<  5, 0.5,4> <  5,4,4> 1 }
  cylinder{< -5, 0.5,4> < -5,4,4> 1 }


  difference
  {
   box{<-6, 0.5, -1.75>< 6,4, -5>}
   box{< 3, 0.4, -3>< 1,4.1, -5.1>}
   box{<-1, 0.4, -3>< -3,4.1, -5.1>}
   cylinder{< 6,-0.4,-5> < 6,4.1,-5> 1 }
   cylinder{< -6,-0.4,-5> < -6,4.1,-5> 1 }
  }

  cylinder{<  5, 0.5,-4> <  5,4,-4> 1 }
  cylinder{< -5, 0.5,-4> < -5,4,-4> 1 }

  difference
  {
   box{<-5, 10, 5>< 5,11, -5>}
   box{< 3, 9, -3>< 1, 12, -5.1>}
   box{<-1, 9, -3>< -3,12, -5.1>}

   box{< 3, 9,  3>< 1, 12,  5.1>}
   box{<-1, 9,  3>< -3,12,  5.1>}

   cylinder{<  5, 9, 5> <  5,12, 5> 1 }
   cylinder{< -5, 9,-5> < -5,12,-5> 1 }
   cylinder{< -5, 9, 5> < -5,12, 5> 1 }
   cylinder{<  5, 9,-5> <  5,12,-5> 1 }
  }

  cylinder{<  4, 10, 4> <  4,11, 4> 1 }
  cylinder{< -4, 10,-4> < -4,11,-4> 1 }
  cylinder{< -4, 10, 4> < -4,11, 4> 1 }
  cylinder{<  4, 10,-4> <  4,11,-4> 1 }

  difference
  {
   box{<-4, 6.5, 4>< 4,7, -4>}
   cylinder{<  4, 5, 4> <  4,8, 4> 1 }
   cylinder{< -4, 5,-4> < -4,8,-4> 1 }
   cylinder{< -4, 5, 5> < -4,8, 4> 1 }
   cylinder{<  4, 5,-4> <  4,8,-4> 1 }
  }

  cylinder{<  3, 6.5, 3> <  3,7, 3> 1 }
  cylinder{< -3, 6.5,-3> < -3,7,-3> 1 }
  cylinder{< -3, 6.5, 3> < -3,7, 3> 1 }
  cylinder{<  3, 6.5,-3> <  3,7,-3> 1 }

  pigment{rgb <0.1, 0.1, 0.1>}

 }
}
#end


#macro SPC_L_EF12(value)
SPC_L_EF12_GRND(value)
#end


/********************************************************************************************************************************************
// EF16 Spulenkern liegend by Anderas Fecht
********************************************************************************************************************************************/
#macro SPC_L_EF16_GRND(value)

union
{
 //***** Loetstifte
 cylinder{<-7.62,-3.5,-7.62><-7.62,1.1,-7.62>0.3 texture{col_silver}}
 cylinder{< 7.62,-3.5, 7.62>< 7.62,1.1, 7.62>0.3 texture{col_silver}}
 cylinder{< 7.62,-3.5,-7.62>< 7.62,1.1,-7.62>0.3 texture{col_silver}}
 cylinder{<-7.62,-3.5, 7.62><-7.62,1.1, 7.62>0.3 texture{col_silver}}

 cylinder{<-2.54,-3.5,-7.62><-2.54,1.1,-7.62>0.3 texture{col_silver}}
 cylinder{<-2.54,-3.5, 7.62><-2.54,1.1, 7.62>0.3 texture{col_silver}}


 //***** Kern
 union
 {
  difference
  {
   box{<-8,3.5,-8><8,8,8>}
   box{<-6.5,3.4,-6.5><6.5,8.1,6.5>}

   cylinder{< 8,3.4, 8> < 8,8.1, 8> 1 }
   cylinder{<-8,3.4,-8> <-8,8.1,-8> 1 }
   cylinder{<-8,3.4, 8> <-8,8.1, 8> 1 }
   cylinder{< 8,3.4,-8> < 8,8.1,-8> 1 }

  }
  cylinder{< 7,3.5, 7> < 7,8, 7> 1 }
  cylinder{<-7,3.5,-7> <-7,8,-7> 1 }
  cylinder{<-7,3.5, 7> <-7,8, 7> 1 }
  cylinder{< 7,3.5,-7> < 7,8,-7> 1 }

  pigment{rgb <0.3, 0.3, 0.3>}
 }

 union  // Spulenkörper
 {

  difference
  {
   box{<-8,0.5,  9>< 8,3.5, 5.5>}
   box{<-7,0.4, 10><-5,3.6, 8>}
   box{<-4,0.4, 10><-2,3.6, 8>}
   box{<-1,0.4, 10>< 1,3.6, 8>}
   box{< 2,0.4, 10>< 4,3.6, 8>}
   box{< 5,0.4, 10>< 7,3.6, 8>}


  }

  difference
  {
   box{<-8,0.5,-9><8,3.5,-5.5>}
   box{<-7,0.4,-10><-5,3.6,-8>}
   box{<-4,0.4,-10><-2,3.6,-8>}
   box{<-1,0.4,-10>< 1,3.6,-8>}
   box{< 2,0.4,-10>< 4,3.6,-8>}
   box{< 5,0.4,-10>< 7,3.6,-8>}

  }


  difference
  {
   box{<-6,8,8><6,11,6>}
   box{<-7,8.5,8.1><-4,11.5,6.5>}
   box{<-3,8.5,8.1>< 3,11.5,6.5>}
   box{< 4,8.5,8.1>< 7,11.5,6.5>}
  }

  difference
  {
   box{<-6,8,-8><6,11,-6>}
   box{<-7,8.5,-8.1><-4,11.5,-6.5>}
   box{<-3,8.5,-8.1>< 3,11.5,-6.5>}
   box{< 4,8.5,-8.1>< 7,11.5,-6.5>}
  }

  pigment{rgb <0.5, 0.3, 0.3>}
 }


 box{<-4,3,6><4,10,-6> texture {T_Gold_1A } }

 union  // Draht
 {

  torus { 5.2, 0.5 rotate<90,10,0> translate<0,6.5,0> }
  torus { 5.2, 0.5 rotate<90,10,0> translate<0,6.5,2> }
  torus { 5.2, 0.5 rotate<90,10,0> translate<0,6.5,4> }
  torus { 5.2, 0.5 rotate<90,10,0> translate<0,6.5,-2> }
  torus { 5.2, 0.5 rotate<90,10,0> translate<0,6.5,-4> }

  pigment{rgb <0.6, 0.5, 0.2>}

 }

}
#end

#macro SPC_L_EF16(value)
SPC_L_EF16_GRND(value)
#end


/********************************************************************************************************************************************
//Murata Chip Coil: 2012 LQH3C/N
//R. Klenner
********************************************************************************************************************************************/
#macro SPC_L_MURATA_2012_LQH3C_GRND(value)
/*** Die Oberflaechenstruktur: **************************************/
#local OBERFLAECHE =
texture{
   pigment{White*.3}
}
/** Objekte des Spulenkoerpers ************************************/
#local L_QUAD=
   box{<-1.3,0,-1.3><1.3,0.35,1.3> texture { OBERFLAECHE }
}

#local Drahtstaerke = .025;

#local L_Boden=
union{
   box{<-1.5,0,-1.45><1.5,0.275,1.45> texture { OBERFLAECHE }}
   box{<-2,0,-1.5><-1.5,0.3,1.5> texture{T_Silver_1A}}
   box{<2,0,-1.5><1.5,0.325,1.5> texture{T_Silver_1A}}
   union{
   difference{
        cylinder{<0,0,0><0,0.45,0>1.4 texture{ OBERFLAECHE }}
        cylinder{<-2,0.45,1><0,0.45,0.5> 0.2}
        cylinder{<2,0.45,-1><0,0.45,-0.5> 0.2}
   }
   cylinder{<-1.8,0.2,1><0,0.5,0.5> Drahtstaerke texture{T_Gold_1A }}
   cylinder{<1.8,0.2,-1><0,0.5,-0.5> Drahtstaerke texture{T_Gold_1A }}
   }
}

#local L_CORE=
    cylinder {<0, 0, 0><0, 1, 0>1 texture {OBERFLAECHE }
    }

#local L_KERN=
union{
   object{L_Boden}
   object{L_CORE translate y*0.25}
   object{L_QUAD translate y*1.25}
}

/***** Kupferlackkabelemente ****************************************/
#local L_WINDUNG =
torus {
   1.1, Drahtstaerke/2
   texture {T_Gold_1A }
}

#local L_SPULE=
union {
    #local i=0;
    #while(i<33)
      object{L_WINDUNG translate i*Drahtstaerke*y}
      #local i=i+1;
    #end
}
/*** Zusammenbau der Spule: ***************************************************************/
#local L_BAUTEIL =
union{
   object{L_KERN}
   object{L_SPULE translate (0.3+Drahtstaerke/2)*y}
   text {ttf besch_font value 0.01, 0 pigment{Red}
           scale 0.5
           rotate 90*x rotate 180*y
           translate <0.35,1.51,0>}
           }
object{L_BAUTEIL}
#end

#macro SPC_L_MURATA_2012_LQH3C(value)
SPC_L_MURATA_2012_LQH3C_GRND(value)
#end


/********************************************************************************************************************************************
//Macro fuer Spule, Kupferlackspule um Ringkern,     induktor.lib,      Joerg Bredendiek <sprut(replace with at)sprut.de>
//
// Nullpunkt:
//      stehende Spule: zwischen den Anschluessen
//      liegende Spule: in Ringkernmitte
//
// a = Abstand der Anschluesse
// b = Breite des Kerns
// d = Durchmesser des Kerns
// dd= Drahtdicke
// e = Abstand vom Ringkernmittelpunkt zum ersten Anschluss, nur bei liegender Spule
// o = 0 == liegend, sonst stehend
********************************************************************************************************************************************/
#macro SPC_L_TOROIDAL_GRND(a,b,d,dd,e,o)
// gelber Ringkern
#macro L_TOROIDAL_KERN(b,d)
union{
        object{
                torus{radmaj, radmin}
                translate<0, -delta/2, 0>
        }
        object{
                torus{radmaj, radmin}
                translate<0, delta/2, 0>
        }
        difference{
                cylinder{<0,-delta/2, 0><0,delta/2, 0>radmaj+radmin}
                cylinder{<0,-delta/2-0.1, 0><0,delta/2+0.1, 0>radmaj-radmin}
        }
        texture{pigment{color Yellow}}
}
#end

//eine einzelne Windung
#macro L_TOROIDAL_WINDUNG()
	torus { radmin+dd/2, dd/2 texture {T_Gold_1A }}
#end

//Windungen um den Kern
#macro L_TOROIDAL_SPULE()
	union {
		#local i=1;
	        #local ss = 0;
	        #local ss=int((radmaj-radmin-dd/2)*2*3.14/dd-0.5); //Anzahl der Windungen um den Kern zu fuellen
		#while(i<ss)
			union{
				difference{
					union{
				object{L_TOROIDAL_WINDUNG() translate <-delta/2, 0, 0>}
				object{L_TOROIDAL_WINDUNG() translate < delta/2, 0, 0>}
					}
					box{<-delta/2, -dd, radmin+dd><delta/2, dd, -radmin-dd>}
				}
				cylinder{<-delta/2, 0, radmin+dd/2>< delta/2, 0, radmin+dd/2> dd/2 texture {T_Gold_1A }}
				cylinder{<-delta/2, 0,-radmin-dd/2>< delta/2, 0,-radmin-dd/2> dd/2 texture {T_Gold_1A }}
				translate <0, 0, radmaj>
				rotate <90+i*360/ss, 0, 0>
				}
			#local i=i+1;
		#end
	}
#end

//Anschluesse fuer stehende Spule
#macro L_TOROIDAL_CONTV()
    #local ra=1;
    #local bends=array[5] {
    // <angle, radius, 0> or <0, distance, 0> for straight pipe,  negative angles bend left, positive bend right.
    <0, 3+1.5*dd-ra+2*radmin, 0>,  <-90, ra, 0>,  <0,a-2*ra,0>,  <-90,ra,0>,  <0, 3+1.5*dd-ra+2*radmin, 0> }

    // this pipe has a radius of dd/2, starts at the origin, and initially goes in the y direction
    TOOLS_BENTPIPE( dd/2, <0,0,0>, y, bends )
#end

//Anschluesse fuer liegende Spule
#macro L_TOROIDAL_CONTH()
    #local ra=a/2;
    #if (ra>b)
        #local ra=b;
    #end
    #local bends=array[5] {
    // <angle, radius, 0> or <0, distance, 0> for straight pipe, negative angles bend left, positive bend right.
    <0, 3+1.5*dd+b-ra, 0>,  <-90, ra, 0>,  <0,a-2*ra,0>,  <-90,ra,0>,  <0, 3+1.5*dd+b-ra, 0> }
    // this pipe has a radius of dd/2, starts at the origin, and initially goes in the y direction
    TOOLS_BENTPIPE( dd/2, <0,0,0>, y, bends )
#end

//Makro fuer stehende Spule
#macro L_TOROIDAL_SFT(a,b,d,dd)
	#local radmin = d/10;
	#local radmaj = d/2-radmin;
	#local delta  = b- 2*radmin;
	union {
		object {L_TOROIDAL_KERN(b,d) rotate<0,0,90> translate<0,radmaj+radmin+dd,0>}
	 	object {L_TOROIDAL_SPULE()                  translate<0,radmaj+radmin+dd,0>}
		object {L_TOROIDAL_CONTV()   translate<a/2, -3, 0> texture {T_Gold_1A }}
	}
#end

//Makro fuer liegende Spule
#macro L_TOROIDAL_ED(a,b,d,dd,e)
	#local radmin = d/10;
	#local radmaj = d/2-radmin;
	#local delta  = b- 2*radmin;
	union {
		object {L_TOROIDAL_KERN(b,d) rotate<0,0, 0>  translate<0,b/2+dd,0>}
	 	object {L_TOROIDAL_SPULE()   rotate<0,0,-90>  translate<0,b/2+dd,0>}
		object {L_TOROIDAL_CONTH()   translate<-e, -3, 0> texture {T_Gold_1A }}
	}
#end

#if(o=0)
    object{L_TOROIDAL_SFT(a,b,d,dd)}
#else
    object{L_TOROIDAL_ED(a,b,d,dd,e)}
#end

#end

#macro SPC_L_TOROIDAL_SFT830D()
SPC_L_TOROIDAL_GRND(10.16, 6.35, 15.875, 1,0,1)
#end
#macro SPC_L_TOROIDAL_SFT830S()
SPC_L_TOROIDAL_GRND(10.16, 8.255, 15.875, 1,0,1)
#end
#macro SPC_L_TOROIDAL_SFT840D()
SPC_L_TOROIDAL_GRND(12.7 , 8.89, 15.24, 1,0,1)
#end
#macro SPC_L_TOROIDAL_SFT1030()
SPC_L_TOROIDAL_GRND(12.7 , 8.255, 20.32, 1,0,1)
#end
#macro SPC_L_TOROIDAL_SFT1040()
SPC_L_TOROIDAL_GRND(15.24 , 10.8, 20.32, 1,0,1)
#end
#macro SPC_L_TOROIDAL_SFT1240()
SPC_L_TOROIDAL_GRND(15.24 , 10.8, 22.86, 1,0,1)
#end
#macro SPC_L_TOROIDAL_ED16()
SPC_L_TOROIDAL_GRND(3.5*1.27 , 10.8, 12*1.27, 0.6, 3*1.27,0)
#end
#macro SPC_L_TOROIDAL_ED22()
SPC_L_TOROIDAL_GRND(4*1.27 , 10.8, 16*1.27, 0.8, 4.5*1.27,0)
#end
#macro SPC_L_TOROIDAL_ED26()
SPC_L_TOROIDAL_GRND(5.5*1.27 , 10.8, 19*1.27, 1, 5*1.27,0)
#end
#macro SPC_L_TOROIDAL_ED38()
SPC_L_TOROIDAL_GRND(9*1.27 , 15, 26*1.27, 0.6, 6*1.27,0)
#end
#macro SPC_L_TOROIDAL_ED43()
SPC_L_TOROIDAL_GRND(10*1.27 , 15, 30*1.27, 1.4, 7*1.27,0)
#end


/********************************************************************************************************************************************
// TYCO H38 inductor
********************************************************************************************************************************************/
#macro SPC_L_TYCO_H38_GRND(value)
union{
difference{
        box{<0,0,0><12,6,12>}     // Body
        cylinder{<6,-0.01,6><6,6.01,6> 5.5 }

        cylinder{<2,-0.01,2><2,6.01,2> 1.25 }
        cylinder{<2,-0.01,10><2,6.01,10> 1.25 }
        cylinder{<10,-0.01,2><10,6.01,2> 1.25 }
        cylinder{<10,-0.01,10><10,6.01,10> 1.25 }
}
        cylinder{<6,0,6><6,5.9,6> 5 }

text {ttf besch_font value 0.1, 0 pigment{Black} scale 2  rotate<90,0,0> translate<4,6,4>}
text {ttf besch_font "H38" 0.1, 0 pigment{Black} scale 2  rotate<90,0,0> translate<4,6,6>}
}
pigment{Gray20}
translate<-6,0,-6>
#end
#macro SPC_L_TYCO_H38(value)
SPC_L_TYCO_H38_GRND(value)
#end


/********************************************************************************************************************************************
//Macros for LF type inductors from WE
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)numericable.fr>
//Rev. 1.1  17/01/08
//pin=pin diamenter ep=thickness
********************************************************************************************************************************************/
#macro SPC_L_WE_GI_LF_GRND(a,b,c,d1,ep,pin,value,lpin,dd,os)
#local dd=(b-ep)/2;//dd=(a-d1)/2; //pin holder diameter
#if(d1=0)
    #local d1=a-dd;
#end
#local d=1.5;//edge diameter
#local LA=c/4;//5; //bisel lenght
#local tc=7; //pin holder cylinders top
#local bc=1; //pin holder cylindres base
#local dm=0.2; //pin holder cylinder edge diameter
#local hb=4; //base height
#local lp=4.5; //wedge width
#local LT=a-d-(LA*sqrt(2));//top length
#local LH=c-d/2-(sqrt(2)*LA/2);//zero to bisel height
#local bends1=array[9] { <0,LH, 0>, <+45, 0.001, 0>, <0,LA,0>, <45,0.001,0>, <0, LT, 0>, <45, 0.001, 0>, <0,LA,0>, <45,0.001,0>,<0, LH, 0> }
#local bends2=array[9] { <0,LA/2, 0>, <+90, 0.001, 0>, <0,ep-d,0>, <90,0.001,0>, <0, LA, 0>, <90, 0.001, 0>, <0,ep-d,0>, <90,0.001,0>, <0,LA/2, 0> }

union{

    difference{
        union{
            object {
            TOOLS_BENTPIPE( d/2, <-a/2+d/2,0,0>, +y, bends1 )
            translate (-ep/2+d/2)*z
            }
            object {
            TOOLS_BENTPIPE( d/2, <-a/2+d/2,0,0>, +y, bends1 )
            translate (+ep/2-d/2)*z
            }
            object {
            TOOLS_BENTPIPE( d/2, <-ep/2+d/2,0,0>, +y, bends2 )
            rotate<45,90,0>
            translate<-a/2+d/2+(sqrt(2)/2*LA)/2,LH+(sqrt(2)/2*LA)/2,0>
            }
            object {
            TOOLS_BENTPIPE( d/2, <+ep/2-d/2,0,0>, +y, bends2 )
            rotate<45,-90,0>
            translate<+a/2-d/2-(sqrt(2)/2*LA)/2,LH+(sqrt(2)/2*LA)/2,-ep+d>
            }
            box{<-a/2+d/2,0,-ep/2><+a/2-d/2,LH,+ep/2>} //inside
            box{<-a/2,0,-ep/2+d/2><+a/2,LH,+ep/2-d/2>} //inside
            box{<-LT/2,0,-ep/2+d/2><+LT/2,c,+ep/2-d/2>}//top
            box{<-LT/2,0,-ep/2><+LT/2,c-d/2,+ep/2>}//top inside
            box{<-LA/2,LA/2,-ep/2><+LA/2,-LA/2,+ep/2> rotate 45*z translate<-a/2+(sqrt(2)/2*LA)+d/2,c-(sqrt(2)/2*LA)-d/2,0> }
            box{<-LA/2,LA/2,-ep/2><+LA/2,-LA/2,+ep/2> rotate 45*z translate<+a/2-(sqrt(2)/2*LA)-d/2,c-(sqrt(2)/2*LA)-d/2,0> }
            box{<-LA/2,-LA/2,-ep/2+d/2><+LA/2,LA/2,+ep/2-d/2> rotate 45*z translate<+a/2-(sqrt(2)/2*LA)-0.22,c-(sqrt(2)/2*LA)-0.22,0> }
            box{<-LA/2,-LA/2,-ep/2+d/2><+LA/2,LA/2,+ep/2-d/2> rotate 45*z translate<-a/2+(sqrt(2)/2*LA)+0.22,c-(sqrt(2)/2*LA)-0.22,0> }

            box{<-a/2+d/2,2,-ep/2-0.5><+a/2-d/2,hb,+ep/2-0.5>} //base

            box{<+a/2,0,-ep/2><+a/2-dd/2,tc-dm/2,+ep/2>}
            box{<-a/2,0,-ep/2><-a/2+dd/2,tc-dm/2,+ep/2>}
        }
        box{<-a/2-10,-0.1,-ep/2-10><+a/2+10,2,+ep/2+10>}
        text {ttf global_fontfile_arial_bold "WE" 0.07, 0  scale <3,5,4> rotate<45,90,0> translate<-a/2+0.7+os,c-(sqrt(2)/2*LA)-0.22+0.7+os,2.6>}
    }
    //wedges
    box{<-a/2+0.2,0,-lp/2><-a/2+1,3,+lp/2>}
    box{<+a/2+0.2,0,-lp/2><+a/2-1,3,+lp/2>}
    //pins
    cylinder{<-d1/2+dd/2+lpin,bc,-ep/2><-d1/2+dd/2+lpin,-4,-ep/2> pin/2 texture{col_silver}}
    cylinder{<+d1/2-dd/2-lpin,bc,-ep/2><+d1/2-dd/2-lpin,-4,-ep/2> pin/2 texture{col_silver}}
    cylinder{<-d1/2+dd/2+lpin,bc,+ep/2><-d1/2+dd/2+lpin,-4,+ep/2> pin/2 texture{col_silver}}
    cylinder{<+d1/2-dd/2-lpin,bc,+ep/2><+d1/2-dd/2-lpin,-4,+ep/2> pin/2 texture{col_silver}}
    #if(lpin=0)
    #local lpin=5.21;
    #end

    //pin holder cylinders
    cylinder{<-d1/2+dd/2,bc,-ep/2><-d1/2+dd/2,tc-dm/2,-ep/2>,dd}
    cylinder{<+d1/2-dd/2,bc,-ep/2><+d1/2-dd/2,tc-dm/2,-ep/2>,dd}
    cylinder{<-d1/2+dd/2,bc,+ep/2><-d1/2+dd/2,tc-dm/2,+ep/2>,dd}
    cylinder{<+d1/2-dd/2,bc,+ep/2><+d1/2-dd/2,tc-dm/2,+ep/2>,dd}

    cylinder{<-d1/2+dd/2+lpin,bc,-ep/2><-d1/2+dd/2+lpin,tc-dm/2,-ep/2>,dd}
    cylinder{<+d1/2-dd/2-lpin,bc,-ep/2><+d1/2-dd/2-lpin,tc-dm/2,-ep/2>,dd}
    cylinder{<-d1/2+dd/2+lpin,bc,+ep/2><-d1/2+dd/2+lpin,tc-dm/2,+ep/2>,dd}
    cylinder{<+d1/2-dd/2-lpin,bc,+ep/2><+d1/2-dd/2-lpin,tc-dm/2,+ep/2>,dd}
    //top of pin holder cylinders
    torus{dd-dm,dm translate<-d1/2+dd/2,tc-dm/2,-ep/2>}
    torus{dd-dm,dm translate<+d1/2-dd/2,tc-dm/2,-ep/2>}
    torus{dd-dm,dm translate<-d1/2+dd/2,tc-dm/2,+ep/2>}
    torus{dd-dm,dm translate<+d1/2-dd/2,tc-dm/2,+ep/2>}

    torus{dd-dm,dm translate<-d1/2+dd/2+lpin,tc-dm/2,-ep/2>}
    torus{dd-dm,dm translate<+d1/2-dd/2-lpin,tc-dm/2,-ep/2>}
    torus{dd-dm,dm translate<-d1/2+dd/2+lpin,tc-dm/2,+ep/2>}
    torus{dd-dm,dm translate<+d1/2-dd/2-lpin,tc-dm/2,+ep/2>}

    cylinder{<-d1/2+dd/2,bc,-ep/2><-d1/2+dd/2,tc+dm/2,-ep/2>,dd-dm}
    cylinder{<+d1/2-dd/2,bc,-ep/2><+d1/2-dd/2,tc+dm/2,-ep/2>,dd-dm}
    cylinder{<-d1/2+dd/2,bc,+ep/2><-d1/2+dd/2,tc+dm/2,+ep/2>,dd-dm}
    cylinder{<+d1/2-dd/2,bc,+ep/2><+d1/2-dd/2,tc+dm,+ep/2>,dd-dm}

    cylinder{<-d1/2+dd/2+lpin,bc,-ep/2><-d1/2+dd/2+lpin,tc+dm/2,-ep/2>,dd-dm}
    cylinder{<+d1/2-dd/2-lpin,bc,-ep/2><+d1/2-dd/2-lpin,tc+dm/2,-ep/2>,dd-dm}
    cylinder{<-d1/2+dd/2+lpin,bc,+ep/2><-d1/2+dd/2+lpin,tc+dm/2,+ep/2>,dd-dm}
    cylinder{<+d1/2-dd/2-lpin,bc,+ep/2><+d1/2-dd/2-lpin,tc+dm/2,+ep/2>,dd-dm}

    //marks
    text {ttf global_fontfile_alphalcd value 0.01, 0  pigment{Black} scale <2.3,2.3,2> rotate<0,0,0> translate<-a/2+1+(a-18.5)/2,tc+1+(c-20.5)/2,-ep/2-0.05>}
    text {ttf global_fontfile_alphalcd " WE  1OO7" 0.01, 0  pigment{Black} scale <2.3,2.3,2> rotate<0,0,0> translate<-a/2+1+(a-18.5)/2,tc+3.8+(c-20.5)/2,-ep/2-0.05>}
    text {ttf global_fontfile_alphalcd "2*39mHO,4A" 0.01, 0  pigment{Black} scale <2.3,2.3,2> rotate<0,0,0> translate<-a/2+1+(a-18.5)/2,tc+6.6+(c-20.5)/2,-ep/2-0.05>}
    //solded wire
    sphere { <-d1/2+lpin,bc/2,-ep/2>, pin  texture{col_silver}}
    sphere { <-d1/2+lpin,bc/2,+ep/2>, pin  texture{col_silver}}
    sphere { <+d1/2-lpin,bc/2,-ep/2>, pin  texture{col_silver}}
    sphere { <+d1/2-lpin,bc/2,+ep/2>, pin  texture{col_silver}}

    pigment {Brown}

}
#end

#macro SPC_L_WE_612SV(value)
SPC_L_WE_GI_LF_GRND(18.5,13.5,20.5,15.5+1.5,10,0.6,value,0,3,0)
#end
#macro SPC_L_WE_SV(value)
SPC_L_WE_GI_LF_GRND(18.5,13.5,20.5,0,10,0.6,value,5.21,3,0)
#end
#macro SPC_L_WE_622MV(value)
SPC_L_WE_GI_LF_GRND(23.5,16,25.5,0,12.5,0.6,value,5,3,0.45)
#end
#macro SPC_L_WE_632LV(value)
SPC_L_WE_GI_LF_GRND(26.5,18.5,30.5,0,15,0.6,value,5.25,3,0.9)
#end
#macro SPC_L_WE_642XV(value)
SPC_L_WE_GI_LF_GRND(32.5,21.5,35.5,0,17.5,0.8,value,8,3.5,1.4)
#end


/********************************************************************************************************************************************
//  by Anderas Fecht
********************************************************************************************************************************************/
#macro SPC_L_WE_PD4_GRND(value)

/*** Die Oberflaechenstruktur: **************************************/
#local OBERFLAECHE =
texture{
   pigment{White*.3}
}
/** Objekte des Spulenkoerpers ************************************/
#local L_QUAD=
union
{
 cylinder{<0,-0.175,0><0,0.175,0> 1.15 texture { OBERFLAECHE } }
 torus{ 1.15 0.175 texture { OBERFLAECHE } }
}

#local Drahtstaerke = .025;

#local L_Boden=

difference
{
 union
 {
   box{<-1.5,0,-1.45><1.5,0.275,1.45> texture { OBERFLAECHE }}
   box{<-2,0,-1.5><-1.5,0.3,1.5> texture{T_Silver_1A}}
   box{<2,0,-1.5><1.5,0.325,1.5> texture{T_Silver_1A}}
   union{
   difference{
        cylinder{<0,0,0><0,0.45,0>1.4 texture{ OBERFLAECHE }}
        cylinder{<-2,0.45,1><0,0.45,0.5> 0.2}
        cylinder{<2,0.45,-1><0,0.45,-0.5> 0.2}
   }
   cylinder{<-1.8,0.2,1><0,0.5,0.5> Drahtstaerke texture{T_Gold_1A }}
   cylinder{<1.8,0.2,-1><0,0.5,-0.5> Drahtstaerke texture{T_Gold_1A }}
   }
 }

 box{<3,-0.5,-1.5><1.5,0.5,1.5> rotate<0,60,0>  texture { OBERFLAECHE }}
 box{<3,-0.5,-1.5><1.5,0.5,1.5> rotate<0,-60,0> texture { OBERFLAECHE }}
 box{<-3,-0.5,-1.5><-1.5,0.5,1.5> rotate<0,60,0> texture { OBERFLAECHE }}
 box{<-3,-0.5,-1.5><-1.5,0.5,1.5> rotate<0,-60,0> texture { OBERFLAECHE }}

}

#local L_CORE=
    cylinder {<0, 0, 0><0, 1, 0>1 texture {OBERFLAECHE }
    }

#local L_KERN=
union{
   object{L_Boden}
   object{L_CORE translate y*0.25}
   object{L_QUAD translate y*1.25}
}

/***** Kupferlackkabelemente ****************************************/
#local L_WINDUNG =
torus {
   1.1, Drahtstaerke/2
   texture {T_Gold_1A }
}

#local L_SPULE=
union {
    #local i=0;
    #while(i<33)
      object{L_WINDUNG translate i*Drahtstaerke*y}
      #local i=i+1;
    #end
}
/*** Zusammenbau der Spule: ***************************************************************/
#local L_BAUTEIL =
union{
      object{L_KERN}
      object{L_SPULE translate (0.3+Drahtstaerke/2)*y}
      text {ttf besch_font value 0.1, 0 pigment{White} scale 0.5 rotate 90*x rotate 180*y translate <0.7,1.45,0.2>}
      scale 3
     }

object{L_BAUTEIL}
#end


#macro SPC_L_WE_PD4(value)
SPC_L_WE_PD4_GRND(value)
#end


/********************************************************************************************************************************************
//  by Anderas Fecht
********************************************************************************************************************************************/
#macro SPC_L_WE_PDM_GRND(value)

union
{
difference
{
 union
 {
   difference
   {
    box{<-3.65,0.5,-3.65><3.65,4,3.65> }
    cylinder{ < 3.65,0, 3.65> < 3.65,5, 3.65> 1 }
    cylinder{ <-3.65,0, 3.65> <-3.65,5, 3.65> 1 }
    cylinder{ < 3.65,0,-3.65> < 3.65,5,-3.65> 1 }
    cylinder{ <-3.65,0,-3.65> <-3.65,5,-3.65> 1 }
   }

   cylinder{ < 2.65,0.5, 2.65> < 2.65,4, 2.65> 1 }
   cylinder{ <-2.65,0.5, 2.65> <-2.65,4, 2.65> 1 }
   cylinder{ < 2.65,0.5,-2.65> < 2.65,4,-2.65> 1 }
   cylinder{ <-2.65,0.5,-2.65> <-2.65,4,-2.65> 1 }

   pigment{rgb <0.3, 0.3, 0.3>}
 }
 box{<-3.5,3.9,-0.7><3.5,4.5,0.7> rotate <0, 45, 0>}
 box{<-3.5,3.9,-0.7><3.5,4.5,0.7> rotate <0, -45, 0>}
 cylinder{ <0,3.9,0> <0,5,0> 2.7 }
 pigment{rgb <0.3, 0.3, 0.3>}
}
text {ttf besch_font value 0, 0 pigment{White} scale<1.5,2,2> rotate<90,-90,0> translate<1,3.95,-2>}
}

#end



#macro SPC_L_WE_PDM(value)
SPC_L_WE_PDM_GRND(value)
#end


/********************************************************************************************************************************************
//dahamm(at)gmx.net
********************************************************************************************************************************************/
#macro SPC_L_WE_PD_GRND(value, A, B, C, D)
#local r = 2; //Kantenradius
#local s = 0.5; //Gehäuseanhebung
#local ri = A / 2 - 1; //Kernradius
#local rx = A / 10;

	union
	{
		difference
		{
			union
			{
				cylinder{<A/2 - r, s, A/2 - r><A/2 - r, s + B, A/2 - r> r}
				cylinder{<-A/2 + r, s, A/2 - r><-A/2 + r, s + B, A/2 - r> r}
				cylinder{<A/2 - r, s, -A/2 + r><A/2 - r, s + B, -A/2 + r> r}
				cylinder{<-A/2 + r, s, -A/2 + r><-A/2 + r, s + B, -A/2 + r> r}
				box{<A/2, s, A/2 - r><-A/2, s + B, -A/2 + r>}
				box{<A/2 - r, s, A/2><-A/2 + r, s + B, -A/2>}
			}

			cylinder{<0.707 * ri, 0, 0.7 * ri><0.7 * ri, s + B + 1, 0.7 * ri> rx}
			cylinder{<-0.707 * ri, 0, 0.7 * ri><-0.7 * ri, s + B + 1, 0.7 * ri> rx}
			cylinder{<0.707 * ri, 0, -0.7 * ri><0.7 * ri, s + B + 1, -0.7 * ri> rx}
			cylinder{<-0.707 * ri, 0, -0.7 * ri><-0.7 * ri, s + B + 1, -0.7 * ri> rx}
		}

		torus{ri - 0.5, 0.5 translate<0, s + B, 0>}
		cylinder{<0, s + B, 0><0, s + B + 0.5, 0> ri - 0.5}

		box{<-D/2, 0, A/2><D/2, s, A/2 - C/2> texture{col_silver}}
		box{<-D/2, 0, -A/2><D/2, s, -A/2 + C/2> texture{col_silver}}

		text {ttf besch_font value 1, 0 pigment{Gray80} scale 2  rotate<90,0,0> translate<-2,s + B + 0.8, 0>}


		pigment{Gray20}
		rotate<0, 90, 0>
	}


#end


#macro SPC_L_WE_PD_S(value)
SPC_L_WE_PD_GRND(value, 7.3, 3.2, 1.5, 1.5)
#end
#macro SPC_L_WE_PD_M(value)
SPC_L_WE_PD_GRND(value, 7.3, 4.5, 2.0, 1.5)
#end
#macro SPC_L_WE_PD_L(value)
SPC_L_WE_PD_GRND(value, 12.0, 6.0, 8.0, 5.0)
#end
#macro SPC_L_WE_PD_XL(value)
SPC_L_WE_PD_GRND(value, 12.0, 8.0, 8.0, 5.0)
#end
#macro SPC_L_WE_PD_XXL(value)
SPC_L_WE_PD_GRND(value, 12.0, 10.0, 7.6, 5.0)
#end


/********************************************************************************************************************************************
//Macros for MURATA NFE61P EMI FILTERS
//Designed by Philippe Boucheny <philippe.boucheny(at)free.fr>
//Rev. 1.0  13/01/06
********************************************************************************************************************************************/
#macro SPC_MURATA_CSTCC_G_A_GRND(value)
union{
    difference{
        union{
            superellipsoid { <0.09, 0.09> scale <3.6,0.25,1.5> translate <0,0.25,0> }
            intersection{
                superellipsoid { <0.09, 0.09> scale <3.6,0.25,1.5> translate <0,0.25,0> }
                union{
                    box{<-4,-0.1,-1.6><-3.1,1,+1.6>}
                    box{<-1.9,-0.1,-1.6><-0.7,1,+1.6>}
                    box{<+0.7,-0.1,-1.6><+1.9,1,+1.6>}
                    box{<+4,-0.1,-1.6><+3.1,1,+1.6>}
                }
                pigment{color red 0.85 green 0.85 blue 0.71}
            }     
        }
        union{
            cylinder{<-2.5,0,-1.5><-2.5,0.6,-1.5> 0.23 }
            cylinder{<+2.5,0,-1.5><+2.5,0.6,-1.5> 0.23 }
            cylinder{<0,0,-1.5><0,0.6,-1.5> 0.23 }
            cylinder{<-2.5,0,+1.5><-2.5,0.6,+1.5> 0.23 }
            cylinder{<+2.5,0,+1.5><+2.5,0.6,+1.5> 0.23 }
            cylinder{<0,0,+1.5><0,0.6,+1.5> 0.23 }
        }
        texture{col_silver}
    }
    difference{
        superellipsoid { <0.2, 0.2> scale <3.3,1.55,1.05> translate <0,0,0>  }
        union{
            box{<-3.4,0,-1.6><+3.4,-2,+1.6> texture{col_silver}}
            text {ttf global_fontfile_arial value 0.08, 0 scale 1 rotate<90,0,0> translate<-2,1.6,-0.45>}     // Ref Marking
        }
        texture{col_silver}
    }
}
#end
#macro SPC_MURATA_CSTCC_G_A(value)
SPC_MURATA_CSTCC_G_A_GRND(value)
#end


/********************************************************************************************************************************************
//Macros for MURATA NFE61P EMI FILTERS
//Designed by Philippe Boucheny <philippe.boucheny(at)free.fr>
//Rev. 1.0  13/01/06
********************************************************************************************************************************************/
#macro SPC_MURATA_NFE61P_GRND()
union{
    difference{
        superellipsoid { <0.09, 0.09> scale <3.4,0.8,0.8> translate <0,0.8,0> texture{col_silver} }
        cylinder{<-2.7,0.8,0><+2.7,0.8,0> 1.2 texture{col_silver}}
    }
    superellipsoid { <0.09, 0.09> scale <1.3,0.8,0.8> translate <0,0.8,0> texture{col_silver} }
    cylinder{<-2.7,0.8,0><+2.7,0.8,0> 0.7 pigment{Gray30}}
}
#end
#macro SPC_MURATA_NFE61P()
SPC_MURATA_NFE61P_GRND()
#end


/********************************************************************************************************************************************
//A reed relay by Stefan Seegel (dahamm@gmx.net)
********************************************************************************************************************************************/
#macro SPC_REED_RELAY_SIL_GRND(value,L,W,H)
#local pin_l = 3.5;
union{
  union{
    difference{
      box{<0,2,0><0.6,-pin_l,0.25>}
      box{<0,0,-1><1,1,1> rotate<0,0,-45> translate<0.3,-pin_l,0>}
      box{<0,0,-1><-1,1,1> rotate<0,0,45> translate<0.3,-pin_l,0>}
      translate<L/2-7.92,0,W/2-0.125>
    }
  
    difference{
      box{<0,2,0><0.6,-pin_l,0.25>}
      box{<0,0,-1><1,1,1> rotate<0,0,-45> translate<0.3,-pin_l,0>}
      box{<0,0,-1><-1,1,1> rotate<0,0,45> translate<0.3,-pin_l,0>}
      translate<L/2-2.84,0,W/2-0.125>
    }
  
    difference{
      box{<0,2,0><0.6,-pin_l,0.25>}
      box{<0,0,-1><1,1,1> rotate<0,0,-45> translate<0.3,-pin_l,0>}
      box{<0,0,-1><-1,1,1> rotate<0,0,45> translate<0.3,-pin_l,0>}
      translate<L/2+2.24,0,W/2-0.125>
    }
  
    difference{
      box{<0,2,0><0.6,-pin_l,0.25>}
      box{<0,0,-1><1,1,1> rotate<0,0,-45> translate<0.3,-pin_l,0>}
      box{<0,0,-1><-1,1,1> rotate<0,0,45> translate<0.3,-pin_l,0>}
      translate<L/2+7.32,0,W/2-0.125>
    }
    
    texture{col_silver}
  }
  
  
  difference{
    box{<0,0,0><L,H,W>}
    
    box{<0,-1,0><-2,H+2,W> rotate<0,11,0> translate<0,0,W/2+0.3>}
    box{<0,-1,0><-2,H+2,-W> rotate<0,-11,0> translate<0,0,W/2-0.3>}
    
    box{<0,-1,0><2,H+2,-W> rotate<0,11,0> translate<L,0,W/2-0.3>}
    box{<0,-1,0><2,H+2,W> rotate<0,-11,0> translate<L,0,W/2+0.3>}
    
    box{<-1,0,0><L+2,2,-W> rotate<-15,0,0> translate<0,H,W/2-0.3>}
    box{<-1,0,0><L+2,2,W> rotate<15,0,0> translate<0,H,W/2+0.3>}
    box{<0,0,-1><-3,3,1> translate<1.4,H-2.6,0>}
    
    box{<0,0,0><L-3,-2,-W> rotate<11,0,0> translate<1.5,0.5,W/2-0.1>}
    box{<0,0,0><L-3,-2,W> rotate<-11,0,0> translate<1.5,0.5,W/2+0.1>}
    
    pigment{Gray20}
  }
  text{ttf besch_font "MEDER electronic" 0.5,0 pigment{White} scale<1.7,2,1.7> translate<2,5,0>}
  text{ttf besch_font value 0.5,0 pigment{White} scale<1.7,2,1.7> translate<2,2,0>}
  
  translate<-L/2, 0, -W/2>
  rotate<0,0,0>
}
#end
#macro SPC_REED_RELAY_SIL(value)
SPC_REED_RELAY_SIL_GRND(value,19.8,5.08,7.8)
#end


/********************************************************************************************************************************************
//Macros for Static Relay SK series from Celduc
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.0 30/12/05
********************************************************************************************************************************************/
#macro SPC_RELAY_CELDUC_SK_GRND(Value,L,W,H,L1,W1,Led,Type)
#local stp=1.27;
union{
    difference{     // case
        union{
            superellipsoid { <0.08, 0.08> scale <L/2, H/2+1, W/2> translate <0, H/2-1, -W/2+(W-W1)> pigment{Gray20}}            
            #if (Led=1)
                merge{cylinder{<0,0.75,0><0,5.48,0>1.5} sphere{<0,5.48,0>1.5} pigment{Red} translate <L/2-5,H-5.5,-W/2+(W-W1)>}  
            #end
        }
        union{
            box{<-L/2-1,0,-W1-1><+L/2+1,-3,-W1+W+1> }    // delete base
            box{<-L/2+1.6,-0.1,-W1-1><+L/2-1.6,0.8,-W1+W+1> }
            #if(Type=1)
                box{<-L/2-1,0,-5><+L/2+1,2,+5> rotate -45*x translate<0,H-0.2,-W/2> }
                box{<-L/2+4,1,-W/2-1><+L/2-4,H-1.7,-W/2-2> }
            #end
            pigment{Gray20}
        }
        translate (L/2-12.7-L1)*x
        
    }
    #if(Type=1)
        box{<-L/2+4,1,-W/2-1><+L/2-4,H-1.7,-W/2-1.45> translate (L/2-12.7-L1)*x pigment {Black}}
        box{<-L/2+3,2,+1.4><+L/2-3,H-2,+1.7> translate (L/2-12.7-L1)*x pigment {White}}
        box{<-L/2+6,5,+1.4><+L/2-6,H-5,+1.71> translate (L/2-12.7-L1)*x pigment {Gray25}}
    #end
    // pins
    cylinder{<-10*stp,2,0><-10*stp,-min(6.5,(pin_length+pcb_height)),0> .5 texture{col_silver} }        
    cylinder{<-6*stp,2,0><-6*stp,-min(6.5,(pin_length+pcb_height)),0> .5 texture{col_silver} }        
    cylinder{<+4*stp,2,0><+4*stp,-min(6.5,(pin_length+pcb_height)),0> .5 texture{col_silver} }        
    cylinder{<+12*stp,2,0><+12*stp,-min(6.5,(pin_length+pcb_height)),0> .5 texture{col_silver} } 
    #if(Type=1)
        #local H=H-1;
    #end
    // marking
    text {ttf global_fontfile_arial_bold "celduc" 0.1, 0 pigment{White} scale 5 rotate<0,0,0> translate<-L/2+8,H-6.1,-W1-0.01>}   
    text {ttf global_fontfile_arial "France" 0.1, 0 pigment{White} scale 4 rotate<0,0,0> translate<-L/2+25,H-6.1,-W1-0.01>}     
    text {ttf global_fontfile_arial "input" 0.1, 0 pigment{White} scale 3 rotate<0,0,0> translate<-12,H-16.5,-W1-0.01>}    
    text {ttf global_fontfile_arial "output" 0.1, 0 pigment{White} scale 3 rotate<0,0,0> translate<+5,H-16.5,-W1-0.01>}    
    text {ttf global_fontfile_arial_bold Value 0.1, 0 pigment{White} scale 4 rotate<0,0,0> translate<-10,H-11.5,-W1-0.01>} 
    #if(Type=0)    
        text {ttf global_fontfile_eagle3d "I" 0.1, 0 pigment{White} scale 3 rotate<0,0,0> translate<-18,H-10,-W1-0.01>}   // canada UL marking
        text {ttf global_fontfile_eagle3d "A" 0.1, 0 pigment{White} scale 3 rotate<0,0,0> translate<-17,H-14,-W1-0.01>}   // UL marking
        text {ttf global_fontfile_eagle3d "E" 0.1, 0 pigment{White} scale 5 rotate<0,0,0> translate<+12,H-12.5,-W1-0.01>} // CE marking 
        text {ttf global_fontfile_eagle3d "B" 0.1, 0 pigment{White} scale 5 rotate<0,0,0> translate<-3,H-18.5,-W1-0.01>}  // DVE marking 
    #end
    #local l1=3;
    cylinder{<-12.7,l1,-W1-0.01><-12.7,l1,-W1> 0.5 pigment{White}}
    cylinder{<-12.7+4*stp,l1,-W1-0.01><-12.7+4*stp,l1,-W1> 0.5 pigment{White}}
    cylinder{<-12.7+13*stp,l1,-W1-0.01><-12.7+13*stp,l1,-W1> 0.5 pigment{White}}
    cylinder{<-12.7+21*stp,l1,-W1-0.01><-12.7+21*stp,l1,-W1> 0.5 pigment{White}}
    text {ttf global_fontfile_arial "4-" 0.1, 0 pigment{White} scale 2.8 rotate<0,0,0> translate<-12,l1-1,-W1-0.01>}     
    text {ttf global_fontfile_arial "3+" 0.1, 0 pigment{White} scale 2.8 rotate<0,0,0> translate<-12+4*stp,l1-1,-W1-0.01>}  
    text {ttf global_fontfile_arial "2" 0.1, 0 pigment{White} scale 2.8 rotate<0,0,0> translate<-12+13*stp,l1-1,-W1-0.01>}    
    text {ttf global_fontfile_arial "1" 0.1, 0 pigment{White} scale 2.8 rotate<0,0,0> translate<-12+21*stp,l1-1,-W1-0.01>}     
}
#end
#macro SPC_RELAY_CELDUC_SK_ABD(value)
SPC_RELAY_CELDUC_SK_GRND(value,43.2,10.2,25.4,7.63,7.62,0,0)
#end
#macro SPC_RELAY_CELDUC_SK_AL(value)
SPC_RELAY_CELDUC_SK_GRND(value,43.2,10.2,25.4,7.63,7.62,1,0)
#end
#macro SPC_RELAY_CELDUC_SK_L(value)
SPC_RELAY_CELDUC_SK_GRND(value,43.6,6.0,24.5,7.83,4.60,0,1)
#end


/********************************************************************************************************************************************
//Macros for G2RL relas from OMRON
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)numericable.fr>
//Rev. 1.1  23/01/08
********************************************************************************************************************************************/
#macro SPC_RELAY_G2R_GRND(value,typ)
union{
    difference{
        #local L=29; // longueur
        #local W=12.7; // largeur
        #local H=16.7; // hauteur+1
        superellipsoid {<0.02, 0.02> scale <L/2, H/2, W/2>}
        box{<-1,-1,-W/2><1,1,+W/2> rotate -45*z translate<+L/2,H/2,0>}
        box{<-L/2-0.1,-H/2+1,-W/2-0.1><+L/2+0.1,-H/2-1,+W/2+0.1>}
        box{<-1.5,H/2+0.1,-3.5><+1.5,H/2-0.5,+3.5> translate -5*x}
        translate (H/2-1)*y 
        pigment {Gray20}
    }                
        //box{<-L/2-1,-H/2+1,-W/2-0.1><+L/2+0.1,-H/2-1,+W/2+1>translate (H/2-1)*y pigment {Red}} 
    cylinder{<-5,H-1,2.25><-5,H/2-1.5,2.25>0.5 pigment {Gray20}}
    cylinder{<-5,H-1,-2.25><-5,H/2-1.5,-2.25>0.5 pigment {Gray20}}

    union{
    text {ttf global_fontfile_eagle3d "A" 0.05, 0 scale <1.5,1.5,1> rotate<90,0,0> translate<-L/2+1,H-0.95,+W/2-4>}
    text {ttf global_fontfile_eagle3d "G" 0.05, 0 scale <3,3,1> rotate<90,0,0> translate<-L/2+4.5,H-0.95,+W/2-4.8>}
    text {ttf global_fontfile_eagle3d "B" 0.05, 0 scale <3,3,1> rotate<90,0,0> translate<-L/2+4.5,H-0.95,+W/2-8>}
    text {ttf global_fontfile_arial_bold "OMRON" 0.05, 0 scale <2,2,1> rotate<90,0,0> translate<-2,H-0.95,+W/2-2.4>}
    text {ttf global_fontfile_arial_bold "JAPAN" 0.05, 0 scale <1.5,1.5,1> rotate<90,0,0> translate<+7,H-0.95,+W/2-2.4>}
    text {ttf global_fontfile_arial value 0.05, 0  scale <3,3.5,1> rotate<90,0,0> translate<-2.5,H-0.95,+W/2-7.7>}
    text {ttf global_fontfile_arial_bold "2817Y1" 0.05, 0 scale <1.5,1.5,1> rotate<90,0,0> translate<-2.5,H-0.95,+W/2-9.3>}
    text {ttf global_fontfile_arial_bold "16A / 250V~ / AC1" 0.05, 0 scale <1.5,1.5,1> rotate<90,0,0> translate<-2.5,H-0.95,+W/2-11.1>}
    text {ttf global_fontfile_arial_bold "°" 0.05, 0 scale <3,3,1> rotate<90,0,0> translate<-L/2+1.5,H-0.95,+W/2-13>}

    box{<-L/2+1,H-0.95,-0.05><-7,H-1,+0.05> translate +1.3*z}
    box{<+7,H-0.95,-0.05><+L/2-2,H-1,+0.05> translate +0.8*z}
    box{<+7,H-0.95,-0.05><+8.5,H-1,+0.05> translate -0.3*z}
    box{<+9,H-0.95,-0.05><+10.5,H-1,+0.05> translate -0.3*z}
    box{<+11,H-0.95,-0.05><+12.5,H-1,+0.05> translate -0.3*z}
    union{
        box{<-1,H-0.95,-0.05><+1,H-1,+0.05> translate +0.5*z}
        box{<-1,H-0.95,-0.05><+1,H-1,+0.05> translate -0.5*z}
        box{<-0.05,H-0.95,-0.5><+0.05,H-1,+0.5> translate +1*x}
        box{<-0.05,H-0.95,-0.5><+0.05,H-1,+0.5> translate -1*x}
        box{<-0.05,H-0.95,-0.5><+0.05,H-1,-2.5> }
        box{<-0.05,H-0.95,+0.5><+0.05,H-1,+2.5> }
        translate <-L/2+3,0,-1.5>
    }
    pigment {Gray50}
    }


    box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5,0,-3.5> texture{col_silver}}        
    box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5,0,+3.5> texture{col_silver}}        


    #switch (typ)
      #case (0)
        text {ttf global_fontfile_arial "G2RL-1A" 0.05, 0  pigment {Gray50} scale <2,2,1> rotate<90,0,0> translate<-2.5,H-0.95,+W/2-4.5>}
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+23.5,0,-3.25> texture{col_silver}}        
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+20,0,+3.25> texture{col_silver}}        
      #break //First case ends
      #case (1)
        text {ttf global_fontfile_arial "G2RL-1" 0.05, 0  pigment {Gray50} scale <2,2,1> rotate<90,0,0> translate<-2.5,H-0.95,+W/2-4.5>}
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+23.5,0,-3.25> texture{col_silver}}        
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+20,0,+3.25> texture{col_silver}}        
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+16.5,0,-3.25> texture{col_silver}}        
      #break //Second case ends
      #case (2)
        text {ttf global_fontfile_arial "G2RL-1A-E" 0.05, 0  pigment {Gray50} scale <2,2,1> rotate<90,0,0> translate<-2.5,H-0.95,+W/2-4.5>}
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+20,0,+3.25> texture{col_silver}}        
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+20,0,-3.25> texture{col_silver}}        
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+25,0,+3.25> texture{col_silver}}        
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+25,0,-3.25> texture{col_silver}}        
      #break //Third case ends
      #case (3)
        text {ttf global_fontfile_arial "G2RL-1-E" 0.05, 0  pigment {Gray50} scale <2,2,1> rotate<90,0,0> translate<-2.5,H-0.95,+W/2-4.5>}
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+20,0,+3.25> texture{col_silver}}        
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+20,0,-3.25> texture{col_silver}}        
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+25,0,+3.25> texture{col_silver}}        
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+25,0,-3.25> texture{col_silver}}        
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+15,0,+3.25> texture{col_silver}}        
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+15,0,-3.25> texture{col_silver}}        
      #break //Fourth case ends
      #case (4)
        text {ttf global_fontfile_arial "G2RL-2A" 0.05, 0  pigment {Gray50} scale <2,2,1> rotate<90,0,0> translate<-2.5,H-0.95,+W/2-4.5>}
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+20,0,+3.25> texture{col_silver}}        
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+20,0,-3.25> texture{col_silver}}        
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+25,0,+3.25> texture{col_silver}}        
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+25,0,-3.25> texture{col_silver}}        
      #break //Fourth case ends
      #case (5)
        text {ttf global_fontfile_arial "G2RL-2" 0.05, 0  pigment {Gray50} scale <2,2,1> rotate<90,0,0> translate<-2.5,H-0.95,+W/2-4.5>}
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+20,0,+3.25> texture{col_silver}}        
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+20,0,-3.25> texture{col_silver}}        
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+25,0,+3.25> texture{col_silver}}        
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+25,0,-3.25> texture{col_silver}}        
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+15,0,+3.25> texture{col_silver}}        
        box{<+0.4,0,-0.25><-0.4,-4,+0.25> translate<-12.5+15,0,-3.25> texture{col_silver}}        
      #break //Fourth case ends
      #else
        text {ttf global_fontfile_arial "G2RL" 0.05, 0  pigment {Gray50} scale <2,2,1> rotate<90,0,0> translate<-2.5,H-0.95,+W/2-4.5>}
     #end // End of conditional part
    
    #if(typ=0)              //because origine offset in the footprint
    #local tl=10.16-1.27;
    #else
    #local tl=10.16;
    #end
    
    translate <tl,0,0>
}
#end
#macro SPC_RELAY_G2RL_1A(value)
SPC_RELAY_G2R_GRND(value,0)
#end
#macro SPC_RELAY_G2RL_1(value)
SPC_RELAY_G2R_GRND(value,1)
#end
#macro SPC_RELAY_G2RL_1A_E(value)
SPC_RELAY_G2R_GRND(value,2)
#end
#macro SPC_RELAY_G2RL_1_E(value)
SPC_RELAY_G2R_GRND(value,3)
#end
#macro SPC_RELAY_G2RL_2A(value)
SPC_RELAY_G2R_GRND(value,4)
#end
#macro SPC_RELAY_G2RL_2(value)
SPC_RELAY_G2R_GRND(value,5)
#end


/********************************************************************************************************************************************
//Omron Relais G6D by Anderas Fecht
********************************************************************************************************************************************/
#macro SPC_RELAY_G6D_GRND(value)

union
{
 difference
 {
  box{<-8.75,0.5,-3.25><8.75,12,3.25>}     // Body
  box{<-8,11.8,-2.5><-7,12.5,2.5>}         // Pin 1 Makierung
  cylinder{< 0,11.7,0>  < 0 12.5,0> 0.8}   //Angusszapfenloch
  
 }
 cylinder{< 0,11.5,0>  < 0 12.1,0> 0.3}   //Angusszapfen     
 
 difference { box{<-9.25,0.5,-1.5><-7,3,1.5>} box{<-9.3,1,-1.0><-7,3.1,1.0>} }        // Snapin
 difference { box{<9.25,0.5,-1.5><7,3,1.5>} box{<9.3,1,-1.0><7,3.1,1.0>} }        // Snapin
 
 box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<-7.62,0,-2.54> } //     
 box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate< 7.62,0,-2.54> } //     
 box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate< 2.54,0,-2.54> } //     
 box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<-5.08,0, 2.54> } //     
 
// box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<-5.21,0,1.75> } // 
// box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<-0.13,0,1.75> } // 
// box{<-0.25,0.5,-0.125><0.25,-min(4.1,(pin_length+pcb_height)),0.125 > texture{col_silver} translate<2.41,0,1.75>  }

 
 text {ttf besch_font "OMRON" 0.1, 0 pigment{White} scale 1.5 rotate<90,0,0> translate<-6,12.01,1.2>}  // Value on top surface
 text {ttf besch_font value 0.1, 0   pigment{White} scale 1.5 rotate<90,0,0> translate<-6,12.01,-2.2>}  // Value on top surface
 text {ttf besch_font "OMRON" 0.1, 0 pigment{White} scale 1.75 translate<-7,9,-3.26>}               // Markings on vertical front face
 text {ttf besch_font value 0.1, 0   pigment{White} scale 1.75 translate<-7,6,-3.26>}                 // Markings on vertical front face
 
 pigment{Gray20}  
 rotate<0,-90,0>
}
#end
#macro SPC_RELAY_G6D(value)
SPC_RELAY_G6D_GRND(value)
#end


/********************************************************************************************************************************************
//Macro JJM_REL_TYPE_1A, 1C, 2W  more structured
//By Emil Crisbaseanu <emilcrisba(at)gmail.com>
//for the free use and viewing pleasure
********************************************************************************************************************************************/
#macro SPC_RELAY_JJM_GRND(value,dual)
              

/********************************************************
for supports of the case
********************************************************/
#macro CUTS(xa,za)

prism {linear_sweep linear_spline
0
0.5
5
<-1,0>,<-0.6,0.4>,<0.6,0.4>,<1,0>,<-1,0>
rotate <90,0,0>
translate<xa,0.40,za>
}
#end
/********************************************************
For pins
********************************************************/
 
#macro PIN_REL(xp,zp,dx,dz)

union{
    box{<xp-(dx/2),-3.2,zp-(dz/2)><xp+(dx/2),1,zp+(dz/2)>}
    prism { linear_sweep linear_spline (-dz/2) (dz/2) 5 <(-dx/2),0>,<(dx/2),0>,<(dx/4),0.3>,<(-dx/4),0.3>,<(-dx/2),0> rotate <90,0,0> translate <xp,-3.2,zp>}
    texture{col_silver}
     }
#end
  union{                                                                   //of case and pins
        union{                                                           //case
                object{CUTS(-4.75,-6.00)}                                //legs of case, (botom side)
                object{CUTS(+5.75,-6.00)}
                object{CUTS(-4.75,+5.50)}
                object{CUTS(+5.75,+5.50)}
                difference{
                        #local L = 15;                                   //on x 
                        #local W = 12;                                   //on z
                        #local H = 27.8;                                 //on y
                        superellipsoid{<0.06,0.06> scale<L/2,H/2,W/2>}   //top box of case
                        box{<-7.8,-14,-6.1><7.8,0.4,6.1>}                //low cut
                        box{<-7.00,-0.1,-5.50><7.00,+0.60,5.50>}         //low inner cut
                        box{<4.4,13.8,-1.3><6,14,1.3>}                   //top box cut
                        sphere{<0,15,0> 1.5}                             //top central round cut
                        }
                pigment {color <1,0.6,0.2>} finish {phong 0.5}           //case pigment
             }
        
object{PIN_REL(-6,5,1,0.400) }
object{PIN_REL(4,5,1,0.300) }
object{PIN_REL(4,-5,1,0.300) }
object{PIN_REL(0,0,1.20,0.300) rotate<0,90,0> translate<6.5,0,0>}
#if(dual=1)
object{PIN_REL(-6,-5,1,0.400)}
#end
text{ttf besch_font value 0.1, 0 pigment{White} scale 1.5 rotate<90,180,0> translate<6,13.92,5>}
text{ttf global_fontfile_eagle3d "," 0.1, 0 pigment{White} scale 1.5 rotate<90,180,0> translate<6,13.92,-3.5>}   //NAiS LOGO     
}
#end 




#macro SPC_RELAY_JJM_1A(value)
SPC_RELAY_JJM_GRND(value, 0)
#end
#macro SPC_RELAY_JJM_1C(value)
SPC_RELAY_JJM_GRND(value, 1)
#end
#macro SPC_RELAY_JJM_2W(value)
SPC_RELAY_JJM_GRND(value, 1)
#end


/********************************************************************************************************************************************
//Macros for G90 type 30A relay
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1 du 05/01/06
//Form: 0=A 1=B 2=C
********************************************************************************************************************************************/
#macro SPC_RELAY_PB_G90_GRND(Value,Form,Com)
union{
#local H=20.4;
    difference{
        union{
            superellipsoid { <0.08, 0.08> scale <16.1,H/2+2,10>  translate <0.9, H/2-2, 0>  }
            superellipsoid { <0.08, 0.08> scale <8.8,H/2+2,10>  translate <-6.4, H/2-2, -3.7>  }
            superellipsoid { <0.08, 0.08> scale <6.4,H/2+2,10>  translate <-8.8, H/2-2, +3.7>  }
        }
        union{
            box{<50,-5,50> <-50,0.4,-50> }
            cylinder{<0,H-0.6,0><0,H+0.1,0> 1.5}
        }
        pigment{Gray30}
    }
    cylinder{<0,H-0.6,0><0,H-0.3,0> 0.6 pigment{Gray30}}
    cylinder{<+10.16,+1,+5.08><+10.16,-3.6,+5.08> .5 pigment{Silver} }      //pin1
    cylinder{<+10.16,+1,-5.08><+10.16,-3.6,-5.08> .5 pigment{Silver} }      //pin2    
    cylinder{<-2.54,+1,-8.9><-2.54,-2.8,-8.9> .9 pigment{Silver} }          //pin4
    cone {<-2.54,-2.8,-8.9>, 0.9, <-2.54,-3.3,-8.9>, 0.6 pigment{Silver}}
    
    #if(Form!=1)
        cylinder{<-5.08,+1,+8.9><-5.08,-2.8,+8.9> 0.9 pigment{Silver} }       //pin5
        cone {<-5.08,-2.8,+8.9>, 0.9, <-5.08,-3.3,+8.9>, 0.5 pigment{Silver}}
    #end
    #if(Form!=0)
        cylinder{<-12.7,+1,+8.9><-12.7,-2.8,+8.9> 0.9 pigment{Silver} }       //pin3  
        cone {<-12.7,-2.8,+8.9>, 0.9, <-12.7,-3.3,+8.9>, 0.5 pigment{Silver}}
    #end
    
    #if (Com=2)        
        cylinder{<+12.7,+1,0><+12.7,-2.8,0> 0.9 pigment{Silver} }        //pin6
        cone {<+12.7,-2.8,0>, 0.9, <+12.7,-3.3,0>, 0.5 pigment{Silver}}
    #end
    
    text {ttf global_fontfile_eagle3d "." 0.05, 0 pigment{White} scale 3.5 rotate<90,-90,0> translate<-11,H+0.05,-5>}     
    text {ttf global_fontfile_arial Value 0.05, 0 pigment{White} scale 2.2 rotate<90,-90,0> translate<-8.5,H+0.05,-7>}      
    text {ttf global_fontfile_arial "COIL-12VDC" 0.05, 0 pigment{White} scale 2.2 rotate<90,-90,0> translate<-6,H+0.05,-7>}     
    text {ttf global_fontfile_eagle3d "A" 0.05, 0 pigment{White} scale 3 rotate<90,-90,0> translate<-2,H+0.05,-7>}   
    text {ttf global_fontfile_eagle3d "G" 0.05, 0 pigment{White} scale 3 rotate<90,-90,0> translate<-2,H+0.05,+0>}     
    text {ttf global_fontfile_arial "20A 250VAC 30VDC" 0.05, 0 pigment{White} scale <1.5,2,2> rotate<90,-90,0> translate<+5,H+0.05,-7>}    
    text {ttf global_fontfile_arial "2HP 250VAC" 0.05, 0 pigment{White} scale <1.5,2,2> rotate<90,-90,0> translate<+7,H+0.05,-7>}     
    text {ttf global_fontfile_arial "1HP 125VAC" 0.05, 0 pigment{White} scale <1.5,2,2> rotate<90,-90,0> translate<+9,H+0.05,-7>}    

}
#end
// Form A, 1 common terminal
#macro SPC_RELAY_PB_G90_1A_1(value) 
SPC_RELAY_PB_G90_GRND(value,0,1)
#end
// Form B, 1 common terminal
#macro SPC_RELAY_PB_G90_1B_1(value) 
SPC_RELAY_PB_G90_GRND(value,1,1)
#end
// Form C, 1 common terminal
#macro SPC_RELAY_PB_G90_1C_1(value) 
SPC_RELAY_PB_G90_GRND(value,2,1)
#end
// Form A, 2 common terminals
#macro SPC_RELAY_PB_G90_1A_2(value)
SPC_RELAY_PB_G90_GRND(value,0,2)
#end
// Form B, 2 common terminals
#macro SPC_RELAY_PB_G90_1B_2(value)
SPC_RELAY_PB_G90_GRND(value,1,2)
#end
// Form C, 2 common terminals
#macro SPC_RELAY_PB_G90_1C_2(value) 
SPC_RELAY_PB_G90_GRND(value,2,2)
#end


/********************************************************************************************************************************************
//Schrack Relais RY2 by Anderas Fecht
********************************************************************************************************************************************/
#macro SPC_RELAY_RY2_GRND(value)

union{
//***** Loetstift
cylinder{<-3.76,-3.5,-12.5>  <-3.76,1.1,-12.5>0.3 texture{col_silver}}
cylinder{< 3.76,-3.5,-12.5>  < 3.76,1.1,-12.5>0.3 texture{col_silver}}
//
cylinder{<-3.76,-3.5,13>  <-3.76,1.1,13>0.5 texture{col_silver}}
cylinder{<-3.76,-3.5,7><-3.76,1.1,7>0.5 texture{col_silver}}
cylinder{ <3.76,-3.5,9.5> < 3.76,1.1,9.5>0.5 texture{col_silver}}


//***** Ende Loetstifte
//
//***** Grundkoerper
difference{
box{<-5,0.5,-14><5,12.0,14>}
box{<-2.0,10.8,11.5><3.0,12.1,14.1>}   

box{<-2.0 ,7,13.9><-1.0,12,14.1>}   
box{<-0.66,7,13.9><0.33,12,14.1>}   
box{<0.66,7,13.9> <1.66,12,14.1>}   
box{<2,7,13.9><3,12,14.1>}   

box{<0,10,16><6,12,20> rotate<45,0,0> translate <3,17,-6.5>}   
cylinder{<-3.5,10.7,12.5><-3.5,12.5,12.5>1}   
sphere{<0,14.5,0>3}
  
}

cylinder{<0,10,0><0,12,0>0.4}     
cylinder{<0.0,10.7,13><0.0,11.5,13>0.6}         
cylinder{<-3.5,10.7,12.5><-3.5,12,12.5>0.4}     

//***** Ende Grundkoerper

text {ttf besch_font "SCHRACK" 0, 0 pigment{Black} scale<2,3,3> rotate<90,-90,0>
translate<-1.5,12.05,-13>}
text {ttf besch_font value 0, 0 pigment{Black} scale<2,2,2> rotate<90,-90,0>
translate<1.5,12.05,-13>}
text {ttf besch_font "10A250V~" 0, 0 pigment{Black} scale<1.5,1.5,1.5> rotate<90,-90,0>
translate<4.0,12.05,-13>}
pigment{rgb <1, 0.25, 0.10>} translate<0,0.2,0>

}   
#end


#macro SPC_RELAY_RY2(value)
SPC_RELAY_RY2_GRND(value)
#end


/********************************************************************************************************************************************
// Auth: Gary French <gary@chromiteblue.com>
//
// Uses existing TOOLS_WIRE_LEADS macro to generate simple wire jumpers.
// SPC_SIMPLE_WIRE_JUMPER_GRND(l,d,r,lw,dw,op,w)
//   l:  length, passed to TOOLS_WIRE_LEADS:Length
//   d:  diameter, passed to TOOLS_WIRE_LEADS:Width
//   r:  raster, passed to TOOLS_WIRE_LEADS:Raster
//   lw: length of wire, 2 * value passed to TOOLS_WIRE_LEADS:Wirelength
//   dw:
//   op: offset?
//   w:
// Defined values:
//   jumper_diameter: wire diameter (currently defaults to the value of dim_mm_awg_24)
//   jumper_bend_radius: radius of jumper corners
//   jumper_seperation: distance of jumper from board surface
********************************************************************************************************************************************/
#macro SPC_SIMPLE_WIRE_JUMPER_GRND(l,d,r,lw,dw,op,w)
//general declarations
#local user_pcb_hole_pitch = 2.54;

//typical wire gauges scaled to Eagle3D
#local dim_mm_awg_16 = 1.290; //AWG-16
#local dim_mm_awg_18 = 1.024; //AWG-18 (standard)
#local dim_mm_awg_20 = 0.812; //AWG-20
#local dim_mm_awg_22 = 0.644; //AWG-22
#local dim_mm_awg_24 = 0.511; //AWG-24
#local dim_mm_awg_26 = 0.405; //AWG-26

#local jumper_diameter = dim_mm_awg_24;
#local jumper_bend_radius = 0.200;
#local jumper_seperation = 0.0;

object{
    TOOLS_WIRE_LEADS(l,d,lw*2,dim_mm_awg_24,r,jumper_bend_radius,jumper_seperation,"H")
    translate<0,dim_mm_awg_24/2+op,0>
}
#end

#macro SPC_SIMPLE_WIRE_JUMPER_05MM()
SPC_SIMPLE_WIRE_JUMPER_GRND(5.8, 2.2, 2.54*2, 20, 0.6, 0, 0.3)
#end
#macro SPC_SIMPLE_WIRE_JUMPER_07MM()
SPC_SIMPLE_WIRE_JUMPER_GRND(5.8, 2.2, 2.54*3, 20, 0.6, 0, 0.3)
#end
#macro SPC_SIMPLE_WIRE_JUMPER_10MM()
SPC_SIMPLE_WIRE_JUMPER_GRND(5.8, 2.2, 2.54*4, 20, 0.6, 0, 0.3)
#end
#macro SPC_SIMPLE_WIRE_JUMPER_12MM()
SPC_SIMPLE_WIRE_JUMPER_GRND(5.8, 2.2, 2.54*5, 20, 0.6, 0, 0.3)
#end
#macro SPC_SIMPLE_WIRE_JUMPER_15MM()
SPC_SIMPLE_WIRE_JUMPER_GRND(5.8, 2.2, 2.54*6, 20, 0.6, 0, 0.3)
#end
#macro SPC_SIMPLE_WIRE_JUMPER_20MM()
SPC_SIMPLE_WIRE_JUMPER_GRND(5.8, 2.2, 2.54*8, 20, 0.6, 0, 0.3)
#end
#macro SPC_SIMPLE_WIRE_JUMPER_25MM()
SPC_SIMPLE_WIRE_JUMPER_GRND(5.8, 2.2, 2.54*10, 20, 0.6, 0, 0.3)
#end
#macro SPC_SIMPLE_WIRE_JUMPER_30MM()
SPC_SIMPLE_WIRE_JUMPER_GRND(5.8, 2.2, 2.54*12, 20, 0.6, 0, 0.3)
#end


/********************************************************************************************************************************************
// SMD-Drossel von CTC
// http://www.ctccoils.com
// L - Gesamt Länge der Drossel
// B - Gesamt Breite der Drossel
// H - Gesamt Höhe der Drossel
// value - Aufschrift
// everyone1@freenet.de
********************************************************************************************************************************************/
#macro SPC_SMD_INDUCTOR_SMSL_GRND(L,B,H,value)

#local PX = 2.54;       // Pad-Größe

#local U = 0.1;         // Überlappung Differenzebildung
#local R = B*0.9/2;     // Radius Spulenkörper
#local R1 = 0.2;        // Radius Draht
#local H1 = 0.8;        // Höhe Grundplatte
#local H2 = 0.6;        // Dicke der Deckplatten der Spule
#local L1 = L*0.95/2;   // Halbe Länge der Grundplatte
#local X1 = L1*0.2;     // Halbe Länge der geraden Seite
#local Z1 = B*0.33/2;   // Halbe Breite der geraden Seite

#declare Draht =  torus{ R-R1-0.3, R1 
                        texture{Copper_Metal
                                pigment{color rgb<0.7,0.2,0>}
                                finish {metallic brilliance 4  ambient (0.1 * global_ambient_mul)}
                        }            
                  }
#local H3 = H-0.1-H1-2*H2;
#local A = int(H3 / (2*R1)) + 1;    // Anzahl der Windungen
#local C = H3 / A;
#local Y2 = H1+H2+R1;

union{
        box{ <-L/2+H1/4, 0, -B*0.30/2> <-L/2+PX, H1+0.2, B*0.30/2> texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}}
        cylinder{ < 0, 0,-B*0.30/2> < 0, 0, B*0.30/2> H1/2+0.1 
                scale< 0.5, 1, 1>
                translate<-L/2+H1/4, H1/2+0.1, 0>
                texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}
        }
        box{ < L/2-H1/4, 0, -B*0.30/2> < L/2-PX, H1+0.2, B*0.30/2> texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}}
        cylinder{ < 0, 0,-B*0.30/2> < 0, 0, B*0.30/2> H1/2+0.1 
                scale< 0.5, 1, 1>
                translate< L/2-H1/4, H1/2+0.1, 0>
                texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}
        }


        prism{ 0.1, H1, 9
                <-X1,-B/2>, < X1,-B/2>, < L1,-Z1>, < L1, Z1>, < X1, B/2>, 
                <-X1, B/2>, <-L1, Z1>, <-L1,-Z1>, <-X1,-B/2>
                texture{pigment{ Gray20 }}
        }
        
        cylinder{ < 0, 0.1+H1, 0> < 0, 0.1+H1+H2, 0> R-H2/2 
                texture{pigment{ Gray10 }}
        }
        torus{ R-H2/2, H2/2
                texture{pigment{ Gray10 }}
                translate< 0, 0.1+H1+H2/2, 0>
        }

        cylinder{ < 0, H, 0> < 0, H-H2, 0> R-H2/2 
                texture{pigment{ Gray10 }}
        }
        torus{ R-H2/2, H2/2
                texture{pigment{ Gray10 }}
                translate< 0, H-H2/2, 0>
        }
        
        #while ( A >= 0 )
                object{ Draht translate< 0, Y2, 0> }
                #declare Y2 = Y2 + C;
                #declare A = A -1;
        #end
        
        text{ttf global_fontfile_arial value 0.1,0 rotate<90,0,0> scale<1.8,1,1.8> translate<-R+1, H+0.01, 0.0> pigment{Gray60}}

}
#end

#macro SPC_SMD_INDUCTOR_SMSL_1305(value)
SPC_SMD_INDUCTOR_SMSL_GRND(12.95, 9.4, 5.21, value)
#end


/********************************************************************************************************************************************
//Macros for horizontal laser tranceiver/receiver TORX173/TOTX173 Toshiba
//Designed by Philippe Boucheny <philippe.boucheny(at)numericable.fr>
//Rev. 1.0  05/06/07
********************************************************************************************************************************************/
#macro SPC_TOXX173_GRND(value)
union{
    union{
        difference{
            box{<-6.5,0.5,+5.5><+6.5,8.5,-10>}
            box{<-6.1,-0.1,+3.3><-6.6,8.6,+4.5>}
            box{<+6.1,-0.1,+3.3><+6.6,8.6,+4.5>}
            box{<-6.6,+8.1,+3.3><+6.6,8.6,+4.5>}
            cylinder{<-5.2,1,-4.2><-5.1,8.6,-4.2>,0.3}
            cylinder{<+5.2,1,-4.2><+5.1,8.6,-4.2>,0.3}
            box{<-1.35,-0.1,-6.5><+1.35,8.6,-7.7>}
            box{<-5.1,+1.6,-5.4><-6.6,7.5,-10.1>}
            box{<+5.1,+1.6,-5.4><+6.6,7.5,-10.1>}
            box{<-4.3,-0.1,-5.4><-5.101,6.5,-8.4>}
            box{<+4.3,-0.1,-5.4><+5.101,6.5,-8.4>}
            box{<+3.1,+2.7,-4.2><-3.1,+7.5,-10.1>}
            box{<+1.7,+1.3,-4.2><-1.7,+7.5,-10.1>}
            box{<-1,-1,-4.2><+1,+1,-10.1> rotate 45*z translate<+1.7,2.7,0>} 
            box{<-1,-1,-4.2><+1,+1,-10.1> rotate 45*z translate<-1.7,2.7,0>} 
            cylinder{<-3,+4.5,-4.2><-3,+4.5,-10.1>,1}
            cylinder{<+3,+4.5,-4.2><+3,+4.5,-10.1>,1}
        }
        difference{
            box{<-2,6.5,-8.1><+2,2.5,0>}
            box{<-1,-0.5,-4.2><+1,+0.5,-10.1> rotate 45*z translate<+2,2.7,0>}
            box{<-1,-0.5,-4.2><+1,+0.5,-10.1> rotate -45*z translate<-2,2.7,0>}
            cylinder{<0,+4.3,-4.2><0,+4.3,-10.1>,1}
            pigment{Gray20}
        }
        box{<-3.81-0.6,0,+5.5,><-3.81+0.6,0.5,-10>}
        box{<+3.81-0.6,0,+5.5,><+3.81+0.6,0.5,-10>}
        pigment{Gray30}
    }
    #if (value = 0)
    text{ttf global_fontfile_arial_bold "TORX173" 0.5,0 pigment{Gray60} scale<2.5,4,0.1> rotate <90,180,0> translate<+5,8.51,-0>}
    #else
    text{ttf global_fontfile_arial_bold "TOTX173" 0.5,0 pigment{Gray60} scale<2.5,4,0.1> rotate <90,180,0> translate<+5,8.51,-0>}
    #end
    text{ttf global_fontfile_arial_bold "JAPAN" 0.5,0 pigment{Gray60} scale<1,2,0.1> rotate <90,180,0> translate<+1.5,8.51,2>}
    union{
        cylinder{<-5.2,-3.5,-4.2><-5.1,1,-4.2>,0.3}
        cylinder{<+5.2,-3.5,-4.2><+5.1,1,-4.2>,0.3}
        box{<-0.25,-3.5,-0.125><+0.25,1,+0.125> translate +1.27*x}
        box{<-0.25,-3.5,-0.125><+0.25,1,+0.125> translate +3.81*x}
        box{<-0.25,-3.5,-0.125><+0.25,1,+0.125> translate -1.27*x}
        box{<-0.25,-3.5,-0.125><+0.25,1,+0.125> translate -3.81*x}
        texture{col_silver}
    }
}
#end
#macro SPC_TOTX173()
SPC_TOXX173_GRND(1)
#end
#macro SPC_TORX173()
SPC_TOXX173_GRND(0)
#end


/********************************************************************************************************************************************
//Macros for DC-DC CONVERTERs DIP series from TRACO
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.0 - 24/12/05
********************************************************************************************************************************************/
#macro SPC_VCONV_DIP_GRND(value,M,Lb,Tp,L,W,H,p1,p2,p3,p9,p10,p11,p12,p13,p14,p15,p16,p22,p23,p24,offsetX,pw,hpin)
union{                               
    #if(M=0)  // Plastic
        #local inner = 1;          
        box{<-L/2,+0,-W/2><+L/2,H,+W/2> pigment{Gray20}}
    #else     // Metalic
        #if(L>33) 
            #local inner = 2.5; 
        #else
            #local inner = 1.5; 
        #end         
        difference{
            superellipsoid { <0.1, 0.1> scale <L/2, H/2+2,W/2> translate <0, H/2-2, 0> texture{Silver1}}
            box{<-L/2,0,-W/2><+L/2,-H,+W/2>}            
        }
    #end      
     
    #if(Lb=0)  // WHITE 
        #local col=White;
        box{<-L/2+inner,H,-W/2+inner><+L/2-inner,H+0.01,+W/2-inner> pigment{SpicyPink}} // Label
        text {ttf global_fontfile_arial "TRACO" 0.05, 0 pigment{col} scale 5 rotate<90,0,0> translate<-9,H+0.05,3.5>}  // Marking
        text {ttf global_fontfile_arial "POWER" 0.05, 0 pigment{col} scale 5 rotate<90,0,0> translate<-10,H+0.05,-1>}  // Marking
        text {ttf global_fontfile_arial "DC/DC CONVERTER" 0.05, 0 pigment{col} scale 2 rotate<90,0,0> translate<-13,H+0.05,-4.2>}  // Marking
        text {ttf global_fontfile_arial pw  0.05, 0 pigment{col} scale 2 rotate<90,0,0> translate<+8,H+0.05,-4.2>}  // Marking
        text {ttf global_fontfile_arial_bold value 0.05, 0 pigment{col} scale 2 rotate<90,0,0> translate<-5.5+offsetX,H+0.05,-7>}  // Marking
        text {ttf global_fontfile_arial "TM" 0.05, 0 pigment{col} scale 1.5 rotate<90,0,0> translate<+8.5,H+0.05,6.8>}  // Marking     
    #end
    #if(Lb=1) // BLACK
        #local col=Black;
        box{<-L/2+inner,H,-W/2+inner><+L/2-inner,H+0.01,+W/2-inner> pigment{SpicyPink}} // Label
        text {ttf global_fontfile_arial "TRACO" 0.05, 0 pigment{col} scale 5 rotate<90,0,0> translate<-9+offsetX,H+0.05,3>}  // Marking
        text {ttf global_fontfile_arial "DC/DC CONVERTER" 0.05, 0 pigment{col} scale 2 rotate<90,0,0> translate<-13+offsetX,H+0.05,-1.5>}  // Marking
        text {ttf global_fontfile_arial pw  0.05, 0 pigment{col} scale 2 rotate<90,0,0> translate<+8+offsetX,H+0.05,-1.5>}  // Marking
        text {ttf global_fontfile_arial_bold value 0.05, 0 pigment{col} scale 2 rotate<90,0,0> translate<-7+offsetX,H+0.05,-6>}  // Marking
        text {ttf global_fontfile_arial "R" 0.05, 0 pigment{col} scale 1.5 rotate<90,0,0> translate<+9,H+0.05,6.78>}  // Marking     
        disc {<9.45, H+0.05, 7.28> y,1.0,0.8 pigment{col}}
    #end
    #if(Lb=2) // DIL16
        #local col=White;
        text {ttf global_fontfile_arial "TRACO" 0.05, 0 pigment{col} scale 4 rotate<90,0,0> translate<-8+offsetX,H+0.05,3>}  // Marking
        text {ttf global_fontfile_arial "POWER" 0.05, 0 pigment{col} scale 4 rotate<90,0,0> translate<-8.5+offsetX,H+0.05,-0.5>}  // Marking
        text {ttf global_fontfile_arial_bold value 0.05, 0 pigment{col} scale 2 rotate<90,0,0> translate<-6+offsetX,H+0.05,-3.5>}  // Marking
        text {ttf global_fontfile_arial_bold "0341" 0.05, 0 pigment{col} scale 2 rotate<90,0,0> translate<-3+offsetX,H+0.05,-6>}  // Marking
        text {ttf global_fontfile_arial "R" 0.05, 0 pigment{col} scale 1 rotate<90,0,0> translate<+9.1-2.5,H+0.05,6.9-2>}  // Marking     
        disc {<9.45-2.5, H+0.05, 7.28-2> y,0.7,0.6.5 pigment{col}}
    #end
    #if(Lb=3)  // 5W 
        #local col=Black;
        box{<-L/2+inner,H,-W/2+inner><+L/2-inner,H+0.01,+W/2-inner> pigment{SpicyPink}} // Label
        text {ttf global_fontfile_arial "TRACO" 0.05, 0 pigment{col} scale 9 rotate<90,0,0> translate<-16,H+0.05,13>}  // Marking
        text {ttf global_fontfile_arial "POWER PRODUCTS" 0.05, 0 pigment{col} scale 3 rotate<90,0,0> translate<-15,H+0.05,8>}  // Marking
        text {ttf global_fontfile_arial "DC/DC CONVERTER" 0.05, 0 pigment{col} scale 3.2 rotate<90,0,0> translate<-20,H+0.05,-3>}  // Marking
        text {ttf global_fontfile_arial pw  0.05, 0 pigment{col} scale 3.2 rotate<90,0,0> translate<+14,H+0.05,-3>}  // Marking
        text {ttf global_fontfile_arial_bold value 0.05, 0 pigment{col} scale 3 rotate<90,0,0> translate<-8+offsetX,H+0.05,-15>}  // Marking
        text {ttf global_fontfile_arial "R" 0.05, 0 pigment{col} scale 2.5 rotate<90,0,0> translate<+16,H+0.05,19>}  // Marking     
        disc {<16.7, H+0.05, 19.8> y,1.5,1.2 pigment{col}}
    #end
    
    #if(Tp=0) // DIP24 pins  
        #if(p1=1)  
            cylinder{<-13.97,0,-7.62><-13.97,-min(hpin,(pin_length+pcb_height)),-7.62> 0.3 pigment{Silver}}
            cylinder{<-13.50,H,-7.62><-13.50,H+0.05,-7.62> 0.5 pigment{col}}
            text {ttf global_fontfile_arial_bold "1" 0.05, 0 pigment{col} scale 1.5 rotate<90,0,0> translate<-13.8,H+0.05,-6.8>}  // Marking
        #end        
        #if(p2=1)  
            cylinder{<-11.43,0,-7.62><-11.43,-min(hpin,(pin_length+pcb_height)),-7.62> 0.3 pigment{Silver}} 
            #if(p1=0)
                cylinder{<-11.43,H,-7.62><-11.43,H+0.05,-7.62> 0.5 pigment{col}}
                text {ttf global_fontfile_arial_bold "2" 0.05, 0 pigment{col} scale 1.5 rotate<90,0,0> translate<-11.8,H+0.05,-6.8>}  // Marking
            #end
        #end
        #if(p3=1)  
            cylinder{<-8.89,0,-7.62><-8.89,-min(hpin,(pin_length+pcb_height)),-7.62> 0.3 pigment{Silver}}
        #end
        #if(p9=1)  
            cylinder{<+6.35,0,-7.62><+6.35,-min(hpin,(pin_length+pcb_height)),-7.62> 0.3 pigment{Silver}}
        #end
        #if(p10=1)  
            cylinder{<+8.89,0,-7.62><+8.89,-min(hpin,(pin_length+pcb_height)),-7.62> 0.3 pigment{Silver}}
        #end
        #if(p11=1)  
            cylinder{<+11.43,0,-7.62><+11.43,-min(hpin,(pin_length+pcb_height)),-7.62> 0.3 pigment{Silver}}
        #end
        #if(p12=1)  
            cylinder{<+13.97,0,-7.62><+13.97,-min(hpin,(pin_length+pcb_height)),-7.62> 0.3 pigment{Silver}}
        #end
             
        #if(p24=1)  
            cylinder{<-13.97,0,+7.62><-13.97,-min(hpin,(pin_length+pcb_height)),+7.62> 0.3 pigment{Silver}}
        #end
        #if(p23=1)  
            cylinder{<-11.43,0,+7.62><-11.43,-min(hpin,(pin_length+pcb_height)),+7.62> 0.3 pigment{Silver}}
        #end
        #if(p22=1)  
            cylinder{<-8.89,0,+7.62><-8.89,-min(hpin,(pin_length+pcb_height)),+7.62> 0.3 pigment{Silver}}
        #end
        #if(p16=1)  
            cylinder{<+6.35,0,+7.62><+6.35,-min(hpin,(pin_length+pcb_height)),+7.62> 0.3 pigment{Silver}}
        #end       
        #if(p15=1)  
            cylinder{<+8.89,0,+7.62><+8.89,-min(hpin,(pin_length+pcb_height)),+7.62> 0.3 pigment{Silver}}
        #end       
        #if(p14=1)  
            cylinder{<+11.43,0,+7.62><+11.43,-min(hpin,(pin_length+pcb_height)),+7.62> 0.3 pigment{Silver}}
        #end       
        #if(p13=1)  
            cylinder{<+13.97,0,+7.62><+13.97,-min(hpin,(pin_length+pcb_height)),+7.62> 0.3 pigment{Silver}}
        #end
    #end
           
    #if(Tp=1) // DIL16 pins
        cylinder{<-8.89,H,-5.08><-8.89,H+0.05,-5.08> 0.75 pigment{col}}
        cylinder{<-8.89,0,-5.08><-8.89,-min(hpin,(pin_length+pcb_height)),-5.08> 0.25 pigment{Silver}} //pin1
        cylinder{<+6.35,0,-5.08><+6.35,-min(hpin,(pin_length+pcb_height)),-5.08> 0.25 pigment{Silver}} //pin7
        cylinder{<+8.89,0,-5.08><+8.89,-min(hpin,(pin_length+pcb_height)),-5.08> 0.25 pigment{Silver}} //pin8
        cylinder{<+8.89,0,+5.08><+8.89,-min(hpin,(pin_length+pcb_height)),+5.08> 0.25 pigment{Silver}} //pin9
        cylinder{<+6.35,0,+5.08><+6.35,-min(hpin,(pin_length+pcb_height)),+5.08> 0.25 pigment{Silver}} //pin10
        cylinder{<-8.89,0,+5.08><-8.89,-min(hpin,(pin_length+pcb_height)),+5.08> 0.25 pigment{Silver}} //pin16
    #end  

    #if(Tp=2) // TVL pins
        cylinder{<-10.16,0,-2.54><-10.16,-min(hpin,(pin_length+pcb_height)),-2.54> 0.25 pigment{Silver}} //pin2
        cylinder{<-10.16,0,+2.54><-10.16,-min(hpin,(pin_length+pcb_height)),+2.54> 0.25 pigment{Silver}} //pin1
        cylinder{<+10.16,0,-10.16><+10.16,-min(hpin,(pin_length+pcb_height)),-10.16> 0.25 pigment{Silver}} //pin3
        cylinder{<+10.16,0,0><+10.16,-min(hpin,(pin_length+pcb_height)),0> 0.25 pigment{Silver}}           //pin4
        cylinder{<+10.16,0,+10.16><+10.16,-min(hpin,(pin_length+pcb_height)),+10.16> 0.25 pigment{Silver}} //pin5
    #end  

}
#end

#macro SPC_VCONV_DIP_TYL(value)
SPC_VCONV_DIP_GRND(value,1,1,0,32.6,20.4,10.3,1,0,0,0,1,0,1,1,0,1,0,0,0,1,0,"1.5W",5)
#end
#macro SPC_VCONV_DIP_TEM2(value)
SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,"2W",3.8)
#end
#macro SPC_VCONV_DIP_TEL2(value)
SPC_VCONV_DIP_GRND(value,0,2,1,23.8,13.7,10,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"2W",4)
#end
#macro SPC_VCONV_DIP_THI_S(value)
SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,"2W",4)
#end
#macro SPC_VCONV_DIP_THI_D(value)
SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10,1,1,0,0,1,1,0,1,0,0,0,0,1,1,0,"2W",4)
#end
#macro SPC_VCONV_DIP_THP3_S(value)
SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10,1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,"2W",4)
#end
#macro SPC_VCONV_DIP_THP3_D(value)
SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10,1,0,0,0,0,1,0,1,0,1,0,0,1,1,0,"2W",4)
#end
#macro SPC_VCONV_DIP_TEM3(value)
SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,"3W",3.8)
#end
#macro SPC_VCONV_DIP_TEL3(value)
SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10.2,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,"3W",4.5)
#end
#macro SPC_VCONV_DIP_TEL3NP_S(value)
SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10.2,0,1,1,0,0,1,0,0,1,0,1,1,1,0,-1,"3W",4.5)
#end
#macro SPC_VCONV_DIP_TEL3NP_D(value)
SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10.2,0,1,1,1,0,1,0,0,1,0,1,1,1,0,-1,"3W",4.5)
#end
#macro SPC_VCONV_DIP_TEN3_S(value)
SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10.2,0,1,1,0,0,1,0,0,1,0,1,1,1,0,-1,"3W",5)
#end
#macro SPC_VCONV_DIP_TEN3_D(value)
SPC_VCONV_DIP_GRND(value,0,0,0,32,20,10.2,0,1,1,1,0,1,0,0,1,0,1,1,1,0,-1,"3W",5)
#end
#macro SPC_VCONV_DIP_TEN4_S(value)
SPC_VCONV_DIP_GRND(value,1,0,0,32,20,10.2,0,1,1,0,0,1,0,0,1,0,1,1,1,0,-1,"4W",5)
#end
#macro SPC_VCONV_DIP_TEN4_D(value)
SPC_VCONV_DIP_GRND(value,1,0,0,32,20,10.2,0,1,1,1,0,1,0,0,1,0,1,1,1,0,-1,"4W",5)
#end
#macro SPC_VCONV_DIP_TVL(value)
SPC_VCONV_DIP_GRND(value,1,3,2,51.3,51.3,8,0,1,1,1,0,1,0,0,1,0,1,1,1,0,-1,"5W",6)
#end
#macro SPC_VCONV_DIP_TEL5_S(value)
SPC_VCONV_DIP_GRND(value,0,0,0,32,20.3,10.2,0,1,1,0,0,1,0,0,1,0,1,1,1,0,-1,"5W",5)
#end
#macro SPC_VCONV_DIP_TEL5_D(value)
SPC_VCONV_DIP_GRND(value,0,0,0,32,20.3,10.2,0,1,1,1,0,1,0,0,1,0,1,1,1,0,-1,"5W",5)
#end
#macro SPC_VCONV_DIP_TEN5_S(value)
SPC_VCONV_DIP_GRND(value,1,0,0,32,20,10.2,0,1,1,0,0,1,0,0,1,0,1,1,1,0,-1,"5W",5)
#end
#macro SPC_VCONV_DIP_TEN5_D(value)
SPC_VCONV_DIP_GRND(value,1,0,0,32,20,10.2,0,1,1,1,0,1,0,0,1,0,1,1,1,0,-1,"5W",5)
#end
#macro SPC_VCONV_DIP_TEN5WI_S(value)
SPC_VCONV_DIP_GRND(value,1,0,0,32,20,10.2,0,1,1,0,0,1,0,0,1,0,1,1,1,0,-1,"5W",3.8)
#end
#macro SPC_VCONV_DIP_TEN5WI_D(value)
SPC_VCONV_DIP_GRND(value,1,0,0,32,20,10.2,0,1,1,1,0,1,0,0,1,0,1,1,1,0,-1,"5W",3.8)
#end
#macro SPC_VCONV_DIP_TEN6_S(value)
SPC_VCONV_DIP_GRND(value,1,0,0,32,20,10.2,0,1,1,0,0,1,0,0,1,0,1,1,1,0,-1,"5W",3.8)
#end
#macro SPC_VCONV_DIP_TEN6_D(value)
SPC_VCONV_DIP_GRND(value,1,0,0,32,20,10.2,0,1,1,1,0,1,0,0,1,0,1,1,1,0,-1,"5W",3.8)
#end
#macro SPC_VCONV_DIP_TEN8(value)
SPC_VCONV_DIP_GRND(value,1,0,0,32,20,10.2,1,1,1,1,0,1,0,0,1,0,1,1,1,0,-1,"8W",3.8)
#end


/********************************************************************************************************************************************
//Macros for DC-DC CONVERTERs SIP series from TRACO
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.0 - 21/12/05
********************************************************************************************************************************************/
#macro SPC_VCONV_SIP_GRND(value,s,Lg,lg1,lg,h,p1,p2,p3,p4,p5,p6,p7,p8,os,pl)
union{
    #local s = -((5*1.27)+s);
    #local lg1 = lg1+0.125;
    difference{
        box{<s,0,lg1-lg><s+Lg,+h,lg1>} 
        union{
            box{<s+0.5,-0.1,-lg><s+Lg-0.5,+0.5,lg1+0.5>}
            cylinder{<-6.35,2.5,lg1-lg-0.2><-6.35,2.5,lg1-lg+0.15> 0.6}
        }
    pigment{Gray20}
    }

    #if(p1=1)
    box{<-5*1.27-0.25,0.6,-0.125><-5*1.27+0.25,-min(pl,(pin_length+pcb_height)),+0.125> texture{col_silver}}
    #end
    #if(p2=1)
    box{<-3*1.27-0.25,0.6,-0.125><-3*1.27+0.25,-min(pl,(pin_length+pcb_height)),+0.125> texture{col_silver}}
    #end
    #if(p3=1)
    box{<-1*1.27-0.25,0.6,-0.125><-1*1.27+0.25,-min(pl,(pin_length+pcb_height)),+0.125> texture{col_silver}}
    #end
    #if(p4=1)
    box{<+1*1.27-0.25,0.6,-0.125><+1*1.27+0.25,-min(pl,(pin_length+pcb_height)),+0.125> texture{col_silver}}
    #end
    #if(p5=1)
    box{<+3*1.27-0.25,0.6,-0.125><+3*1.27+0.25,-min(pl,(pin_length+pcb_height)),+0.125> texture{col_silver}}
    #end
    #if(p6=1)
    box{<+5*1.27-0.25,0.6,-0.125><+5*1.27+0.25,-min(pl,(pin_length+pcb_height)),+0.125> texture{col_silver}}
    #end
    #if(p7=1)
    box{<+7*1.27-0.25,0.6,-0.125><+7*1.27+0.25,-min(pl,(pin_length+pcb_height)),+0.125> texture{col_silver}}
    #end
    #if(p8=1)
    box{<+9*1.27-0.25,0.6,-0.125><+9*1.27+0.25,-min(pl,(pin_length+pcb_height)),+0.125> texture{col_silver}}
    #end
    
    text {ttf besch_font value 0.1, 0 pigment{White} scale 1.75 rotate<90,0,0> translate<-3.0+os,h+0.01,lg1-(lg/2)-0.5>}  // Marking on top surface
    text {ttf besch_font "TRACO" 0.1, 0 pigment{White} scale 3 rotate<0,0,0> translate<-3.5+os,6.81,lg1-lg-0.01>}    // Markings front surface 
    text {ttf besch_font value 0.1, 0 pigment{White} scale 2 rotate<0,0,0> translate<-3.8+os,4.8,lg1-lg-0.01>}       // Markings front surface 
    text {ttf besch_font "9815" 0.1, 0 pigment{White} scale 1.75 rotate<0,0,0> translate<-1.3+os,2.8,lg1-lg-0.01>}   // Markings front surface 
    
    cylinder{<-6.35,2.5,lg1-lg+0.15><-6.35,2.5,lg1-lg+0.1> 0.6 pigment{White}}
    
    rotate<0,90,0>

}
#end



//TMA single/dual voltage, less or equal to 24V input voltage
#macro SPC_VCONV_SIP_TMA_S(value)
SPC_VCONV_SIP_GRND(value,2.3,+19.5,1.25,6,10.2,1,1,0,1,0,1,0,0,0,3.2)
#end
#macro SPC_VCONV_SIP_TMA_D(value)
SPC_VCONV_SIP_GRND(value,2.3,+19.5,1.25,6,10.2,1,1,0,1,0,1,0,0,0,3.2)
#end
#macro SPC_VCONV_SIP_TMA_S_24V(value)
SPC_VCONV_SIP_GRND(value,2.3,+19.5,1.25,7,10.2,1,1,0,1,0,1,0,0,0,3.2)
#end
#macro SPC_VCONV_SIP_TMA_D_24V(value)
SPC_VCONV_SIP_GRND(value,2.3,+19.5,1.25,7,10.2,1,1,0,1,0,1,0,0,0,3.2)
#end
//TME less or equal to 24V input voltage
#macro SPC_VCONV_SIP_TME(value)
SPC_VCONV_SIP_GRND(value,1.9,+11.5,4.2,6,10.2,1,1,1,1,0,0,0,0,-3.5,3.2)
#end
#macro SPC_VCONV_SIP_TME_24V(value)
SPC_VCONV_SIP_GRND(value,1.9,+11.5,5.2,7,10.2,1,1,1,1,0,0,0,0,-3.5,3.2)
#end
//TMV single/dual voltage, less or equal to 24V input voltage
#macro SPC_VCONV_SIP_TMV_S(value)
SPC_VCONV_SIP_GRND(value,2.3,+19.5,1.25,6,10.2,1,1,0,0,1,0,1,0,0.5,3.2)
#end
#macro SPC_VCONV_SIP_TMV_D(value)
SPC_VCONV_SIP_GRND(value,2.3,+19.5,1.25,6,10.2,1,1,0,0,1,1,1,0,0.5,3.2)
#end
#macro SPC_VCONV_SIP_TMV_S_24V(value)
SPC_VCONV_SIP_GRND(value,2.3,+19.5,1.25,7,10.2,1,1,0,0,1,0,1,0,0.5,3.2)
#end
#macro SPC_VCONV_SIP_TMV_D_24V(value)
SPC_VCONV_SIP_GRND(value,2.3,+19.5,1.25,7,10.2,1,1,0,0,1,1,1,0,0.5,3.2)
#end
// TMVEN  single/dual voltage
#macro SPC_VCONV_SIP_TMVEN_S(value)
SPC_VCONV_SIP_GRND(value,3.5,+22,1.75,7.5,12.5,1,1,0,0,1,0,1,0,0.5,4)
#end
#macro SPC_VCONV_SIP_TMVEN_D(value)
SPC_VCONV_SIP_GRND(value,3.5,+22,1.75,7.5,12.5,1,1,0,0,1,1,1,0,0.5,4)
#end
// TMH  single/dual voltage
#macro SPC_VCONV_SIP_TMH_S(value)
SPC_VCONV_SIP_GRND(value,2.3,+19.5,1.25,7.5,10.2,1,1,0,1,0,1,0,0,0,3.2)
#end
#macro SPC_VCONV_SIP_TMH_D(value)
SPC_VCONV_SIP_GRND(value,2.3,+19.5,1.25,7.5,10.2,1,1,0,1,1,1,0,0,0,3.2)
#end
// TMR  single/dual voltage
#macro SPC_VCONV_SIP_TMR(value)
SPC_VCONV_SIP_GRND(value,2,+21.8,3.2,9.2,11.1,1,1,0,0,0,1,1,1,1.5,4)
#end


/********************************************************************************************************************************************
//Quarz mit veränderbarer Höhe und 4,9mm Pitch
//basiert auf Modell von Andreas Fecht <info@aftec.de>
********************************************************************************************************************************************/
#macro SPC_XTAL_5MM_GRND(value,height)
union{
cylinder{<-3.35,0,0><-3.35,0.7,0>2.25}
cylinder{<3.35,0,0><3.35,0.7,0>2.25}
box{<-3.35,0,-2.25><3.35,0.7,2.25>}
cylinder{<-3.35,0.7,0><-3.35,height,0>2}
cylinder{<3.35,0,0><3.35,height,0>2}
box{<-3.35,0,-2><3.35,height,2>}
torus{1.6,0.4 translate<-3.35,height,0>}
torus{1.6,0.4 translate<3.35,height,0>}
cylinder{<-3.35,0,0><3.35,0,0>0.4 translate<0,height,-1.6>}
cylinder{<-3.35,0,0><3.35,0,0>0.4 translate<0,height,1.6>}
cylinder{<-3.35,height,0><-3.35,height+0.4,0>1.6}
cylinder{<3.35,height,0><3.35,height+0.4,0>1.6}
box{<-3.35,height,-1.6><3.35,height+0.4,1.6>}
#if(pin_short=off)
cylinder{<-2.45,0,0><-2.45,-12,0>0.25}
cylinder{<2.45,0,0><2.45,-12,0>0.25}
#else
cylinder{<-2.45,0,0><-2.45,-1*(pin_length+pcb_height),0>0.25}
cylinder{<2.45,0,0><2.45,-1*(pin_length+pcb_height),0>0.25}
#end
#if(height>5)
text {ttf besch_font value 0.1, 0 pigment{White*0.5} scale 1.5 translate<-3,height/2,-2.01>}
#else
text {ttf besch_font value 0.1, 0 pigment{White*0.5} scale 2 rotate<90,0,0> translate<-4,height+0.401,-0.5>}
#end
texture{col_silver}}
#end

#macro SPC_XTAL_5MM(value,height)
SPC_XTAL_5MM_GRND(value,height)
#end


/********************************************************************************************************************************************
//Quarz mit veränderbarer Höhe und 4,9mm Pitch SMD
//albi <azihlmann@gmx.net>
********************************************************************************************************************************************/
#macro SPC_XTAL_5MM_SMD_GRND(value,height)
union{
 union{
  cylinder{<-3.35,0,0><-3.35,0.7,0>2.25}
  cylinder{<3.35,0,0><3.35,0.7,0>2.25}
  box{<-3.35,0,-2.25><3.35,0.7,2.25>}
  cylinder{<-3.35,0.7,0><-3.35,height,0>2}
  cylinder{<3.35,0,0><3.35,height,0>2}
  box{<-3.35,0,-2><3.35,height,2>}
  torus{1.6,0.4 translate<-3.35,height,0>}
  torus{1.6,0.4 translate<3.35,height,0>}
  cylinder{<-3.35,0,0><3.35,0,0>0.4 translate<0,height,-1.6>}
  cylinder{<-3.35,0,0><3.35,0,0>0.4 translate<0,height,1.6>}
  cylinder{<-3.35,height,0><-3.35,height+0.4,0>1.6}
  cylinder{<3.35,height,0><3.35,height+0.4,0>1.6}
  box{<-3.35,height,-1.6><3.35,height+0.4,1.6>}
  #if(height>5)
  text {ttf besch_font value 0.1, 0 pigment{White*0.5} scale 1.5 translate<-3,height/2,-2.01>}
  #else
  text {ttf besch_font value 0.1, 0 pigment{White*0.5} scale 2 rotate<90,0,0> translate<-4,height+0.401,-0.5>}
  #end
  texture{col_silver}
  translate 0.7*y
 }
  box{<-5.5,0.01,-2.20><5.5,1,2.20> pigment{White*0.3}}
  difference{
     box{<-6.0,0,-0.35><6.0,0.3,0.35>}
     box{<-2.25,-0.1,-0.4><2.25,0.4,0.4>}
     texture{col_silver}
  }
}
#end
#macro SPC_XTAL_5MM_SMD(value,height)
SPC_XTAL_5MM_SMD_GRND(value,height)
#end


/********************************************************************************************************************************************
//Uhrenquarz mit 2,5mm Pitch
********************************************************************************************************************************************/
#macro SPC_XTAL_CLOCK_025MM_GRND(value)
#if(pin_short=off)
#local spc_pin_length = -5;
#else
#local spc_pin_length = -1*(pin_length+pcb_height);
#end
union{
superellipsoid{<1,0.12> rotate<90,0,0> scale<1,3,1> translate<0,5,0>}
sphere_sweep {
linear_spline 4
<-0.5,2,0>,0.18
<-0.5,1.5,0>,0.18
<-1.27,0.3,0>,0.18
<-1.27,-5,0>,0.18}
sphere_sweep {
linear_spline 4
<0.5,2,0>,0.18
<0.5,1.5,0>,0.18
<1.27,0.3,0>,0.18
<1.27,-5,0>,0.18}
intersection{
superellipsoid{<1,0.12> rotate<90,0,0> scale<1.001,3,1.001> translate<0,5,0> pigment{Black}}
union{
text {ttf besch_font value 0.5, 0 pigment{White*0.5} rotate<0,0,90> translate<0.5,2.8,-1.1>}
text {ttf besch_font value 0.5, 0 pigment{White*0.5} rotate<0,0,90> translate<0.5,2.8,-1.1> rotate<0,180,0>}}}
texture{col_silver}}
#end
#macro SPC_XTAL_CLOCK_025MM(value)
SPC_XTAL_CLOCK_025MM_GRND(value)
#end


/********************************************************************************************************************************************
// Joerg Bredendiek <sprut(replace with at)sprut.de>   
//Quarz HC49/18 liegend mit 4,9mm Pitch
//basiert auf Modell von Andreas Fecht <info@aftec.de>
********************************************************************************************************************************************/
#macro SPC_XTAL_L_GRND(value, buegel, pin3, smd, shift, pinshift)
union{
	#local height = 13.575;
	union{
		// bodenplatte
		cylinder{<-3.35,0,0><-3.35,0.7,0>2.25}
		cylinder{< 3.35,0,0>< 3.35,0.7,0>2.25}
		box{<-3.35,0,-2.25><3.35,0.7,2.25>}
		union{
			cylinder{<-2.45,-0.1,0><-2.45,0.1,0>1} 
			cylinder{< 2.45,-0.1,0>< 2.45,0.1,0>1} 
			pigment{Gray30}
		}

		// koerper
		cylinder{<-3.35,0.7,0><-3.35,height,0>2}
		cylinder{< 3.35,0  ,0>< 3.35,height,0>2}
		box{<-3.35,0,-2><3.35,height,2>}

		//kappe
		torus{1.6,0.4 translate<-3.35,height,0>}
		torus{1.6,0.4 translate< 3.35,height,0>}
		cylinder{<-3.35,0,0><3.35,0,0>0.4 translate<0,height,-1.6>}
		cylinder{<-3.35,0,0><3.35,0,0>0.4 translate<0,height, 1.6>}
		cylinder{<-3.35,height,0><-3.35,height+0.4,0>1.6}
		cylinder{< 3.35,height,0>< 3.35,height+0.4,0>1.6}
		box{<-3.35,height,-1.6><3.35,height+0.4,1.6>}
	
		// beschriftung auf der seite
		text {ttf besch_font value 0.1, 0 pigment{White*0.5} scale 1.5 translate<-3,height/3,-2.01>}
	
		rotate<90,0,0>
		translate<0, 2.25, shift>
	}	

	#if (smd=0)        
	        // pin unterteil
		#if  (pin_short=off)
			cylinder{<-2.45,0,0><-2.45,-12,0>0.2 translate<0, 0, pinshift> }
			cylinder{< 2.45,0,0>< 2.45,-12,0>0.2 translate<0, 0, pinshift> }
		#else
			cylinder{<-2.45,0,0><-2.45,-1*(pin_length+pcb_height),0>0.2 translate<0, 0, pinshift> }
			cylinder{< 2.45,0,0>< 2.45,-1*(pin_length+pcb_height),0>0.2 translate<0, 0, pinshift> }
		#end
                //pin oberteil                 
                #declare bends1=array[3] {<0, 0.8, 0>,  <90, 1.5, 0>,  <0,2,0> }  
                object { TOOLS_BENTPIPE( 0.2, <0,0,0>, y, bends1 ) rotate<0,-90,0> translate<-2.45,0,pinshift>}               
                object { TOOLS_BENTPIPE( 0.2, <0,0,0>, y, bends1 ) rotate<0,-90,0> translate< 2.45,0,pinshift>}               
                                 
		#if (pin3=1)
			cylinder{<0, 3, height+shift+0.575> <0, -1*(pin_length+pcb_height), height+shift+0.575> 0.2}
		#end  
	#else
                //pin 1 und 2                 
                #declare bends2=array[5] {<0,0.8,0>, <-90,0.5,0>, <0, 1, 0>,  <90, 0.5, 0>,  <0,2,0> }  
                object { TOOLS_BENTPIPE( 0.2, <0, 0, 0>, x, bends2 ) rotate<0,-90,0> translate<-2.45,0.2,pinshift>}               
                object { TOOLS_BENTPIPE( 0.2, <0, 0, 0>, x, bends2 ) rotate<0,-90,0> translate< 2.45,0.2,pinshift>}   
                //pin 3 
                #declare bends3=array[3] {<0, 3, 0>,  <90, 0.5, 0>,  <0,1,0> }  
                object { TOOLS_BENTPIPE( 0.2, <0,0,0>, y, bends3 ) rotate<0,-90,0> rotate<0,0,180> translate<0,3.7,height+shift+0.575>}    
		
	#end


	#if (buegel=1)
		//#declare bends=array[5] {<0, 5.5, 0>,  <90, 2.5, 0>,  <0,6.4,0>,  <90,2.5,0>,  <0, 5.5, 0> }
		#declare bends=array[5] {<0, 5.5, 0>,  <90, 2, 0>,  <0,7.4,0>,  <90,2,0>,  <0, 5.5, 0> }
		// <angle, radius, 0> or <0, distance, 0> for straight pipe
		// negative angles bend left, positive bend right.
		object { TOOLS_BENTPIPE( 0.25, <-2.25*2.54, -3, 1.5*2.54>, y, bends ) }
	#end

	texture{col_silver}
}
#end

#macro SPC_XTAL_L0(value)
SPC_XTAL_L_GRND(value, 0, 0, 0, -3.81, -5.08)
#end
#macro SPC_XTAL_L1(value)
SPC_XTAL_L_GRND(value, 0, 0, 1, -7, -9.1)
#end
#macro SPC_XTAL_L2(value)
SPC_XTAL_L_GRND(value, 1, 0, 0, -3.81, -5.08)
#end
#macro SPC_XTAL_L3(value)
SPC_XTAL_L_GRND(value, 0, 1, 0, -6.2, -7.62)
#end
#macro SPC_XTAL_L4(value)
SPC_XTAL_L_GRND(value, 0, 0, 0, -6.2, -7.62)
#end


/********************************************************************************************************************************************
//Macros for SMD TCVCXO CFPT-37 CFPT125 and CFPT126 from C-MAC
//Designed by Philippe Boucheny <philippe.boucheny(at)free.fr>
//Rev. 1.0  25/03/06
********************************************************************************************************************************************/
#macro SPC_XTAL_OSZ_CFPT_GRND(Type)

#macro SPC_XTAL_OSZ_CFPT_GRND_CAPSMDCHIP(color_sub,L,W,T,K)
union{
	superellipsoid{<0.25-(L+W)/150, 0.25-(L+W)/150> pigment{color_sub} scale<L/2,W/2,T/2> }     //Grundkoerper braun
	superellipsoid{<0.25-(L+W)/200, 0.25-(L+W)/200> scale<(K+L/100)/2,W/2,T/2> translate <(L-K)/2,0,0> texture{col_silver}}      //rechter Anschluss
	superellipsoid{<0.25-(L+W)/200, 0.25-(L+W)/200> scale<(K+L/100)/2,W/2,T/2> translate <-(L-K)/2,0,0> texture{col_silver}}      //linker Anschluss
	rotate<90,0,0>
	translate<0,T/2,0>
}
#end
 
union{
    difference{
        box{<-3.5,0,-2.5><+3.5,0.6,+2.5>}
        cylinder{<0,-0.2,0><0,0.8,0> 0.16 translate<+3.5,0,0> texture{T_Brass_3A}}    
        cylinder{<0,-0.2,0><0,0.8,0> 0.16 translate<-3.5,0,0> texture{T_Brass_3A}}    
        cylinder{<0,-0.2,0><0,0.8,0> 0.16 translate<0,0,+2.5> texture{T_Brass_3A}}    
        cylinder{<0,-0.2,0><0,0.8,0> 0.16 translate<0,0,-2.5> texture{T_Brass_3A}}    
        cylinder{<0,-0.2,0><0,0.8,0> 0.16 translate<+3.5,0,+2.5>}    
        cylinder{<0,-0.2,0><0,0.8,0> 0.16 translate<-3.5,0,+2.5>}    
        cylinder{<0,-0.2,0><0,0.8,0> 0.16 translate<+3.5,0,-2.5>}    
        cylinder{<0,-0.2,0><0,0.8,0> 0.16 translate<-3.5,0,-2.5>}    
        cylinder{<0,-0.2,0><0,0.8,0> 0.16 translate<-2.54,0,+2.5> texture{T_Brass_3A}}    
        cylinder{<0,-0.2,0><0,0.8,0> 0.16 translate<+2.54,0,+2.5> texture{T_Brass_3A}}    
        cylinder{<0,-0.2,0><0,0.8,0> 0.16 translate<-2.54,0,-2.5> texture{T_Brass_3A}}    
        cylinder{<0,-0.2,0><0,0.8,0> 0.16 translate<+2.54,0,-2.5> texture{T_Brass_3A}}    
        cylinder{<0,-0.2,0><0,0.8,0> 0.16 translate<-1.17,0,+2.5>}    
        cylinder{<0,-0.2,0><0,0.8,0> 0.16 translate<+1.17,0,+2.5>}    
        cylinder{<0,-0.2,0><0,0.8,0> 0.16 translate<-1.17,0,-2.5>}    
        cylinder{<0,-0.2,0><0,0.8,0> 0.16 translate<+1.17,0,-2.5>}    
        cylinder{<0,-0.2,0><0,0.8,0> 0.16 translate<+3.5,0,-1.12>}    
        cylinder{<0,-0.2,0><0,0.8,0> 0.16 translate<-3.5,0,-1.12>}    
        cylinder{<0,-0.2,0><0,0.8,0> 0.16 translate<+3.5,0,+1.12>}    
        cylinder{<0,-0.2,0><0,0.8,0> 0.16 translate<-3.5,0,+1.12>}    
    pigment{rgb <0.44, 0.37, 0.40>}
    }
    union{
        superellipsoid { <0.15, 0.15> scale <2.7, 0.455,1.7> translate <0, 0.6+0.455, 0> texture{T_Brass_5A} }
        superellipsoid { <0.15, 0.15> scale <2.55, 0.55,1.55> translate <0, 0.6+0.55, 0> texture{T_Brass_5A} }
        superellipsoid { <0.15, 0.15> scale <2.5, 0.61,1.5> translate <0, 0.6+0.61, 0> texture{T_Brass_5A} }
        
        superellipsoid { <0.05, 0.05> scale <0.05, 0.2,0.3> translate <-2.75, 0.2+0.55, -1.1> texture{col_silver} }
        superellipsoid { <0.05, 0.05> scale <0.05, 0.2,0.3> translate <-2.75, 0.2+0.55, +1.1> texture{col_silver} }
        superellipsoid { <0.05, 0.05> scale <0.05, 0.2,0.3> translate <+2.75, 0.2+0.55, -1.1> texture{col_silver} }
        superellipsoid { <0.05, 0.05> scale <0.05, 0.2,0.3> translate <+2.75, 0.2+0.55, +1.1> texture{col_silver} }
        
        box{<-2.3,1.8,-1><+2.3,1.83,+1> pigment{Gray50}}
        box{<-2,1.8,-1.3><+2,1.83,+1.3> pigment{Gray50}}
        cylinder{<0,1.8,0><0,1.83,0> 0.3 translate<-2,0,+1> pigment{Gray50}}    
        cylinder{<0,1.8,0><0,1.83,0> 0.3 translate<-2,0,-1> pigment{Gray50}}    
        cylinder{<0,1.8,0><0,1.83,0> 0.3 translate<+2,0,+1> pigment{Gray50}}    
        cylinder{<0,1.8,0><0,1.83,0> 0.3 translate<+2,0,-1> pigment{Gray50}}    
        text {ttf global_fontfile_arial_bold "CMAC" 0.05, 0 pigment{Gray30} scale <1,0,.8> rotate<90,0,0> translate<-2,1.84,+0.4>}  // Marking
        text {ttf global_fontfile_arial_bold Type 0.05, 0 pigment{Gray20} scale <0.8,1,1> rotate<90,0,0> translate<-1.5,1.84,-0.9>}  // Marking
        translate 0.3*z
    }
    object{SPC_XTAL_OSZ_CFPT_GRND_CAPSMDCHIP(DarkWood,1.0,0.5,0.6,0.2)translate<0,0.6,-1.9>}
    object{SPC_XTAL_OSZ_CFPT_GRND_CAPSMDCHIP(DarkWood,1.0,0.5,0.6,0.2)translate<-2.2,0.6,-1.9>}
    object{SPC_XTAL_OSZ_CFPT_GRND_CAPSMDCHIP(Gray30,1.0,0.5,0.6,0.2)translate<+2.2,0.6,-1.9>}
}
#end
#macro SPC_XTAL_OSZ_CFPT_37()
SPC_XTAL_OSZ_CFPT_GRND("CFPT-37")
#end
#macro SPC_XTAL_OSZ_CFPT_125()
SPC_XTAL_OSZ_CFPT_GRND("CFPT-125")
#end
#macro SPC_XTAL_OSZ_CFPT_126()
SPC_XTAL_OSZ_CFPT_GRND("CFPT-126")
#end


/********************************************************************************************************************************************
//Quarz Oszillator im DIP14
********************************************************************************************************************************************/
#macro SPC_XTAL_OSZ_DIP14_GRND(value)
union{
box{<-10.15,1,-5.6><10.15,2,5.6>}
box{<-9.15,1,-6.6><9.15,2,6.6>}
box{<-9.15,1,-5.6><-10.15,2,-6.6>}
cylinder{<9.15,1,-5.6><9.15,2,-5.6>1}
cylinder{<-9.15,1,5.6><-9.15,2,5.6>1}
cylinder{<9.15,1,5.6><9.15,2,5.6>1}
box{<-9.5,2,-4.95><9.5,5,4.95>}
box{<-8.5,2,-5.95><8.5,5,5.95>}
box{<-8.5,5,-4.95><8.5,6,4.95>}
sphere_sweep{
linear_spline
6
<-8.5,2,-4.95>1
<-8.5,5,-4.95>1
<8.5,5,-4.95>1
<8.5,5,4.95>1
<-8.5,5,4.95>1
<-8.5,5,-4.95>1}
cylinder{<8.5,5,-4.95><8.5,2,-4.95>1}
cylinder{<8.5,5,4.95><8.5,2,4.95>1}
cylinder{<-8.5,5,4.95><-8.5,2,4.95>1}
cylinder{<-3*2.54,5,-3.8><-3*2.54,6.01,-3.8>0.4 pigment{Black}}
text {ttf besch_font value 0.5, 0 pigment{White*0.5} scale<2,2,2> rotate<90,0,0> translate<-3*2.54,6.01,0>}
cylinder{<-3*2.54,1,-3.8><-3*2.54,-1*(pin_length+pcb_height)+0.2,-3.8>0.2}
cylinder{<3*2.54,1,-3.8><3*2.54,-1*(pin_length+pcb_height)+0.2,-3.8>0.2}
cylinder{<3*2.54,1,3.8><3*2.54,-1*(pin_length+pcb_height)+0.2,3.8>0.2}
cylinder{<-3*2.54,1,3.8><-3*2.54,-1*(pin_length+pcb_height)+0.2,3.8>0.2}
sphere{<3*2.54-1,1,3.8-1>0.8 pigment{Gray20}}
sphere{<3*2.54-1,1,-3.8+1>0.8 pigment{Gray20}}
sphere{<-3*2.54+1,1,-3.8+1>0.8 pigment{Gray20}}
sphere{<-3*2.54+1,1,3.8-1>0.8 pigment{Gray20}}
translate<0,-0.2,0>
texture{col_silver}}
#end
#macro SPC_XTAL_OSZ_DIP14(value)
SPC_XTAL_OSZ_DIP14_GRND(value)
#end


/********************************************************************************************************************************************
//Quarz Oszillator im DIP8
********************************************************************************************************************************************/
#macro SPC_XTAL_OSZ_DIP8_GRND(value)
union{
box{<-10.15+1.5*2.54,1,-5.6><10.15-1.5*2.54,2,5.6>}
box{<-9.15+1.5*2.54,1,-6.6><9.15-1.5*2.54,2,6.6>}
box{<-9.15+1.5*2.54,1,-5.6><-10.15+1.5*2.54,2,-6.6>}
cylinder{<9.15-1.5*2.54,1,-5.6><9.15-1.5*2.54,2,-5.6>1}
cylinder{<-9.15+1.5*2.54,1,5.6><-9.15+1.5*2.54,2,5.6>1}
cylinder{<9.15-1.5*2.54,1,5.6><9.15-1.5*2.54,2,5.6>1}
box{<-9.5+1.5*2.54,2,-4.95><9.5-1.5*2.54,5,4.95>}
box{<-8.5+1.5*2.54,2,-5.95><8.5-1.5*2.54,5,5.95>}
box{<-8.5+1.5*2.54,5,-4.95><8.5-1.5*2.54,6,4.95>}
sphere_sweep{
linear_spline
6
<-8.5+1.5*2.54,2,-4.95>1
<-8.5+1.5*2.54,5,-4.95>1
<8.5-1.5*2.54,5,-4.95>1
<8.5-1.5*2.54,5,4.95>1
<-8.5+1.5*2.54,5,4.95>1
<-8.5+1.5*2.54,5,-4.95>1}
cylinder{<8.5-1.5*2.54,5,-4.95><8.5-1.5*2.54,2,-4.95>1}
cylinder{<8.5-1.5*2.54,5,4.95><8.5-1.5*2.54,2,4.95>1}
cylinder{<-8.5+1.5*2.54,5,4.95><-8.5+1.5*2.54,2,4.95>1}
cylinder{<-3*2.54+1.5*2.54,5,-3.8><-3*2.54+1.5*2.54,6.01,-3.8>0.4 pigment{Black}}
text {ttf besch_font value 0.5, 0 pigment{Black} scale 1.3 rotate<90,0,0> translate<-3*2.54+1.5*2.54,6.01,0>}
cylinder{<-3*2.54+1.5*2.54,1,-3.8><-3*2.54+1.5*2.54,-1*(pin_length+pcb_height)+0.2,-3.8>0.2}
cylinder{<3*2.54-1.5*2.54,1,-3.8><3*2.54-1.5*2.54,-1*(pin_length+pcb_height)+0.2,-3.8>0.2}
cylinder{<3*2.54-1.5*2.54,1,3.8><3*2.54-1.5*2.54,-1*(pin_length+pcb_height)+0.2,3.8>0.2}
cylinder{<-3*2.54+1.5*2.54,1,3.8><-3*2.54+1.5*2.54,-1*(pin_length+pcb_height)+0.2,3.8>0.2}
sphere{<3*2.54-1-1.5*2.54,1,3.8-1>0.8 pigment{Gray20}}
sphere{<3*2.54-1-1.5*2.54,1,-3.8+1>0.8 pigment{Gray20}}
sphere{<-3*2.54+1+1.5*2.54,1,-3.8+1>0.8 pigment{Gray20}}
sphere{<-3*2.54+1+1.5*2.54,1,3.8-1>0.8 pigment{Gray20}}
translate<0,-0.2,0>
texture{col_silver}}
#end
#macro SPC_XTAL_OSZ_DIP8(value)
SPC_XTAL_OSZ_DIP8_GRND(value)
#end


/********************************************************************************************************************************************
//PLASTIC" DIP8 & DIP14 CRYSTAL OSCILLATORS   BY J. ZEGLINSKI
// <JAZeglinski@rogers.com>
********************************************************************************************************************************************/
#macro SPC_XTAL_OSZ_PDIP_GRND(p,value)
#macro OSZ_SYMBOL(Symbol_Color, Background_Color)
	// Create the "classic Oscillator symbol" at origin on X-Z Plane
	//    Basic symbol is (2.4mm wide x 1.2mm tall) - use "scale" on macro call to fit other size XTAL bodies
	
	#local T=0.15; // Symbol line thickness
	 union{          
	    box{ <(-0.1-T),0,(-0.6-T)><(0.1+T),0,(0.6+T)> } 
	    box{ <-0.1,0.01,-0.6><0.1,0.01,0.6>  pigment { Symbol_Color } } // set inside of box to IC body color to create a square "O"
	    box{ <(-0.5-T),0,-0.6-T><-0.5,0.01,0.6+T>   }
	    box{ <-0.5,0,-T/2><-1.2,0,T/2>   }
	    box{ <0.5+T,0,-0.6-T><0.5,0,0.6+T>   }
	    box{ <0.5,0,-T/2><1.2,0,T/2>  }
	      texture{ pigment { Background_Color }  }
	      }
#end

#if(p=8)
	union{
	  object{ IC_DIS_DIP8A4(value,"") } // use "IC.inc" macro to create PLASTIC DIP8 with 4 corner pins and "IC Name"
	
	  // Add the "Crystal Oscillator Symbol" to IC created by macro with Name already on it.
	    #local V=(3.2+0.01+0.25);   // vertical translation distance to final IC surface created in DIP08A4 macro
	    object{ OSZ_SYMBOL(Gray30,Gray60) scale<1.5,1,1> translate<0,V,2> }   // Plot & scale the symbol, and move up into DIP surface position 
	  }
#else
	union{
	  object{ IC_DIS_DIP14A4(value,"") } // use "IC.inc" macro to create PLASTIC DIP14 with 4 corner pins and "IC Name"
	
	  // Add the "Crystal Oscillator Symbol" to IC created by macro with Name already on it.
	    #local V=(3.2+0.01+0.25);   // vertical translation distance to final IC surface created in DIP14A4 macro
	    object{ OSZ_SYMBOL(Gray30,Gray60) scale<1.5,1,1> translate<0,V,2> }   // Plot & scale the symbol, and elevate into DIP surface position 
	  }
#end

#end

#macro SPC_XTAL_OSZ_PDIP8(value)
SPC_XTAL_OSZ_PDIP_GRND(8,value)
#end
#macro SPC_XTAL_OSZ_PDIP14(value)
SPC_XTAL_OSZ_PDIP_GRND(14,value)
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
