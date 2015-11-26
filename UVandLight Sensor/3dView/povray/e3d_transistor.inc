//Eagle3D 20110101 INC-File e3d_transistor.inc
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
 
#ifndef(__transistor_inc)
#declare __transistor_inc = true;

#ifndef(inc_testmode)
#declare inc_testmode=true;
#include "e3d_tools.inc"
#undef inc_testmode
#end

/********************************************************************************************************************************************
//SOT82 Housing horizontal
********************************************************************************************************************************************/
#macro TR_SOT82_L_GRND(value)
/********************************************************************************************************************************************
//pin horizontal SOT82
********************************************************************************************************************************************/
#macro SOT82_PIN_H()
union{
union{
	// senkrechter spitzer teil
	difference{
		box{<-0.375,tr_SOT82_s_pin ,0><0.375,8.5,0.6>}
		box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45-0.375,tr_SOT82_s_pin ,-0.2>}
		box{<0,0,0><-1,1,1> rotate<0,0,25> translate< 0.3-0.375,tr_SOT82_s_pin ,-0.2>}}
	// biegung
	difference{
		cylinder{<-0.375,8.5,0.6><0.375,8.5,0.6>0.6}
		cylinder{<-0.38,8.0,1.1><0.38,8.0,1.1>0.5}}
	// horizontal zum koerper
	box{<-0.375,8.5,0.6><0.375,9.1,5.0>}
	translate<0, -7, -5.08>
}
	//verdickung
	box{<-0.75, 8.5, 0><0.75, 9.1, 2> translate<0, -7, -4>}
}
#end
/********************************************************************************************************************************************

********************************************************************************************************************************************/

union{
	#if(pin_short=off)
		#local tr_SOT82_s_pin = 0;
	#else
		#local tr_SOT82_s_pin = 7-(pcb_height+pin_length);
	#end

	//Pins
	union{
		object{SOT82_PIN_H() translate<-2.54,0,0>}
		object{SOT82_PIN_H() translate< 2.54,0,0>}
		object{SOT82_PIN_H()}
		texture{col_silver}
	}

	//body
	union{
		//metal Body ground
		box{<-2.8,4.5,1.8><2.8,12,2.551> texture{col_silver}}              
		
		difference{
			//plastic Body
			box{<-3.6,2.5,0><3.6,13.15,2.55>}
			cylinder{<0,0,0.1><0,0,-0.4>1.55 translate<0,9.35,0>}

			cylinder{<0,0,1.25><0,0,-0.4>2 translate<-4.5,9.35,0>}
			cylinder{<0,0,1.25><0,0,-0.4>2 translate< 4.5,9.35,0>}

			cylinder{<0,0,0.1><0,0,-0.4>0.7 translate<-2.5,3.5,0>}
			cylinder{<0,0,0.1><0,0,-0.4>0.7 translate< 2.5,3.5,0>}

			pigment{Gray30}}	
		
		text{ttf besch_font value 0.5,0 pigment{White} scale<1.7,2,1.7> translate<-3, 5, -0.01>}

		rotate<90,0,0>
		translate<0,2.55,-3.81>
	}
}
#end


#macro TR_SOT82_L(value)
TR_SOT82_L_GRND(value)
#end


/********************************************************************************************************************************************
//SOT82 Housing standing
********************************************************************************************************************************************/
#macro TR_SOT82_S_GRND(value)
union{
	union{
		union{
			#if(pin_short=off)
				#local tr_SOT82_s_pin = -14;
			#else
				#local tr_SOT82_s_pin = 0-(pcb_height+pin_length);
			#end

			difference{    
				//PIN Middle
				box{<0,tr_SOT82_s_pin,0><0.8,2.5,0.62>}
				box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45,tr_SOT82_s_pin,-0.2>}
				box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3,tr_SOT82_s_pin,-0.2>}}
			difference{ 
				//PIN Left
				box{<0,tr_SOT82_s_pin,0><0.8,2.5,0.62>}
				box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45,tr_SOT82_s_pin,-0.2>}
				box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3,tr_SOT82_s_pin,-0.2>}
				translate<-2.54,0,0>}
			difference{     
				//PIN Right
				box{<0,tr_SOT82_s_pin,0><0.8,2.5,0.62>}
				box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45,tr_SOT82_s_pin,-0.2>}
				box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3,tr_SOT82_s_pin,-0.2>}
				translate<2.54,0,0>}
			//PIN add-on
			box{<0,0,0><1.5,1,0.6> translate<-0.375,0.8,0>}
			box{<0,0,0><1.5,1,0.6> translate<-0.375,0,0> translate<2.54,0.8,0>}
			box{<0,0,0><1.5,1,0.6> translate<-0.375,0,0> translate<-2.54,0.8,0>}

			translate<-0.8/2,0,0.84>
		}//END union3

		//metal plate / Body ground
		box{<-2.8,4.5,1.8><2.8,12,2.551>}              
		texture{col_silver}
	}//END union2

	difference{
		//plastic Body
		box{<-3.6,2.5,0><3.6,13.15,2.55>}
		cylinder{<0,0,0.1><0,0,-0.4>1.55 translate<0,9.35,0>}

		cylinder{<0,0,1.25><0,0,-0.4>2 translate<-4.5,9.35,0>}
		cylinder{<0,0,1.25><0,0,-0.4>2 translate< 4.5,9.35,0>}

		cylinder{<0,0,0.1><0,0,-0.4>0.7 translate<-2.5,3.5,0>}
		cylinder{<0,0,0.1><0,0,-0.4>0.7 translate< 2.5,3.5,0>}

		pigment{Gray30}}

	// lable
	text{ttf besch_font value 0.5,0 pigment{White} scale<1.7,2,1.7> translate<-3,5,-0.01>}

	translate<0,0,-2.55>
}//END union1

#end


#macro TR_SOT82_S(value)
TR_SOT82_S_GRND(value)
#end


/********************************************************************************************************************************************
// Author      : Sven-Mortem Resch (sven-mortem.resch(replace with at)gmx.de
// Name        : Macro TR_SOT93_GRND - SOT93 Transistor package
// Created     : 18.03.2006
// Modified    : 18.03.2006 by Sven-Mortem Resch
// Version     : 1.0
// Arguments   : M = Montagelage (mounting position) => H = horizontal, V = vertikal
//               O = Offset des Bauteils bezueglich 0 auf der Z-Achse (Z-Offset)
//               S = Offset des Bauteils bezueglich = auf der Y-Achse (Y-Separation)
//               B = Position des Knicks der Pins auf der Z-Achse (Bend position)
//               V = Beschriftung (Value)
// Description : Dieses Macro generiert ein SOT93 Package für horizontale und vertikale Montage.
//               This macro generates a SOT93 package for horizontal and vertical mounting.
********************************************************************************************************************************************/
#macro TR_SOT93_GRND(M, O, S, B, V, L)
#local Horizontal =! (strcmp(strupr(M), "H") );
#local ww = 1.3; 
#local wt = 0.78;

union {
 difference {
  union {
   box {<-7.5, 0, -2.45><7.5, 12.2, 2.45>} //Koerper
   pigment{Gray30}
  }
  union {
   cylinder{<0, 3, -2><0, 3, -2.5> 1.2} //Vertiefung in der Mitte
   cone {<-7, 3, 1.08>, 1, <-7, 3, -2.5>, 1.2} //Aussparung links
   cone {<7, 3, 1.08>, 1, <7, 3, -2.5>, 1.2} //Aussparung rechts
   box {<-8, 0, 0><8, 1, -4> rotate <-7,0,0> translate <0, 12.1, 1.08>} //Abschraegung Gehaeuse oben
   box {<-7.6, 0, 0><7.6, 1, -2.6> rotate <7,0,0> translate <0, -1, 0>} //Abschraegung Gehaeuse unten vorn
   box {<-7.6, 0, 0><7.6, 1, -2.6> rotate <-7,0,0> translate <0, -0.65, 2.6>} //Abschraegung Gehaeuse unten hinten
   box {<-0.5, 0, -2.6><0.5, 12.2, 2.5> rotate <0,-7,0> translate <-7.87, 0, 0>} //Abschraegung Gehaeuse links
   box {<-0.5, 0, -2.6><0.5, 12.2, 2.5> rotate <0,7,0> translate <7.87, 0, 0>} //Abschraegung Gehaeuse rechts
   pigment{Gray30}
  }
 } 
 difference {
  box {<-7.5, 12.2, 2.45><7.5, 20.35, 1.08>}  //Kuehlfahne
  cylinder {<0, 16.2, 2.5><0, 16.2, 0>, 2} //Bohrung Kuehlfahne
  box {<0, 0, 0><3, 3, 3> rotate <0,0,45> translate <-7.5,18.23,0>} //Abschraegung links Kuehlfahne
  box {<0, 0, 0><3, 3, 3> rotate <0,0,45> translate <7.5,18.23,0>} //Abschraegung rechts Kuehlfahne
  texture {col_silver}
 }
 //Pins
 #if(pin_short=off)
   #local p_height = 8.85;
  #else
   #local p_height = pcb_height+S;
  #end 
 //Pins vertikale Version
 #if (Horizontal = no)
  union {
   union {
    box{<0, 0, 0><1.8, -1.8, wt>}
    box{<0, -1.8, 0><1.3, -p_height, wt>}
    texture {col_silver}
   } 
   union {
    box{<0, 0, 0><1.8, -1.8, wt>}
    box{<0.25, -1.8, 0><1.55, -p_height, wt>}
    texture {col_silver}
    translate <5.55, 0, 0>
   }
   union {
    box{<0, 0, 0><1.8, -1.8, wt>}
    box{<0.5, -1.8, 0><1.8, -p_height, wt>}
    texture {col_silver}
    translate <11.1, 0, 0>
   }
   translate <-6.45,0,-wt/2>
  }
 #else
  //Pins horizontale Version
  union {
   difference {
    union {
     box{<0, 0, 0><1.8, -1.8, wt>}
     box{<0, -1.8, 0><ww, -B-wt, wt>}
     box{<0, -B-(wt/2),wt/2><ww, -B-(wt/2)-wt, 4+S>}
     box{<0, -B, wt/2><1.3, -B-0.9, (wt/2)+0.9>} 
     cylinder{<0, -B-wt, wt/2><1.3, -B-wt, wt/2>, wt/2}
    }
     cylinder{<-0.1, -B, wt+(wt/2)><1.4, -B, wt+(wt/2)>, wt/2}
   }
   difference {
    union {
     box{<0, 0, 0><1.8, -1.8, wt>}
     box{<0.25, -1.8, 0><ww+0.25, -B-wt, wt>}
     box{<0.25, -B-(wt/2),wt/2><ww+0.25, -B-(wt/2)-wt, 4+S>}
     box{<0.25, -B, wt/2><1.55, -B-0.9, (wt/2)+0.9>} 
     cylinder{<0.25, -B-wt, wt/2><1.55, -B-wt, wt/2>, wt/2}
    }
     cylinder{<0.24, -B, wt+(wt/2)><1.55, -B, wt+(wt/2)>, wt/2}
     translate <5.55, 0, 0>
   }  
   difference {
    union {
     box{<0, 0, 0><1.8, -1.8, wt>}
     box{<0.5, -1.8, 0><ww+0.5, -B-wt, wt>}
     box{<0.5, -B-(wt/2),wt/2><ww+0.5, -B-(wt/2)-wt, 4+S>}
     box{<0.5, -B, wt/2><1.8, -B-0.9, (wt/2)+0.9>} 
     cylinder{<0.5, -B-wt, wt/2><1.8, -B-wt, wt/2>, wt/2}
    }
     cylinder{<0.49, -B, wt+(wt/2)><1.81, -B, wt+(wt/2)>, wt/2}
     translate <11.1, 0, 0>
   }
   texture {col_silver}
   translate <-6.45,0,-wt/2>    
   translate <0,L,0>
  }
 #end 
 //Beschriftung
 text {ttf global_fontfile_arial V 1, 0 scale 2.5 translate <-4.5,6,-2.455> pigment{Gray70}}
 
 //In endgueltige Position bringen
 #if (Horizontal = yes)
  rotate <90,0,0>
  translate <0,2.45+S, O>
 #else
  translate <0,1.8+S, O>
 #end
}
#end



#macro TR_SOT93_H(value) 
TR_SOT93_GRND("H",-3.3,0,3.6,value, 0)  
#end
#macro TR_SOT93_H1(value) 
TR_SOT93_GRND("H",-3.3,0,3.6,value,2.54)
#end
#macro TR_SOT93_H2(value) 
TR_SOT93_GRND("H",-3.3-3.0,0,3.6,value,0)
#end
#macro TR_SOT93_V(value) 
TR_SOT93_GRND("V",-3.18,0,0,value, 0)
#end


/********************************************************************************************************************************************
//TO126 Housing horizontal
********************************************************************************************************************************************/
#macro TR_TO126_L_GRND(value)
/********************************************************************************************************************************************
//pin horizontal TO126
********************************************************************************************************************************************/
#macro TO126_PIN_H()
union{
union{
	// senkrechter spitzer teil
	difference{
		box{<-0.375,tr_to126_s_pin ,0><0.375,8.5,0.6>}
		box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45-0.375,tr_to126_s_pin ,-0.2>}
		box{<0,0,0><-1,1,1> rotate<0,0,25> translate< 0.3-0.375,tr_to126_s_pin ,-0.2>}}
	// biegung
	difference{
		cylinder{<-0.375,8.5,0.6><0.375,8.5,0.6>0.6}
		cylinder{<-0.38,8.0,1.1><0.38,8.0,1.1>0.5}}
	// horizontal zum koerper
	box{<-0.375,8.5,0.6><0.375,9.1,5.0>}
	translate<0, -7, -5.08>
}
	//verdickung
	box{<-0.75, 8.5, 0><0.75, 9.1, 2> translate<0, -7, -4>}
}
#end
/********************************************************************************************************************************************

********************************************************************************************************************************************/

union{
	#if(pin_short=off)
		#local tr_to126_s_pin = 0;
	#else
		#local tr_to126_s_pin = 7-(pcb_height+pin_length);
	#end

	//Pins
	union{
		object{TO126_PIN_H() translate<-2.54,0,0>}
		object{TO126_PIN_H() translate< 2.54,0,0>}
		object{TO126_PIN_H()}
		texture{col_silver}
	}

	//body
	union{
		difference{ 
			//Body ground
			box{<-2.8,4.5,1.8><2.8,12,2.551>}              
			cylinder{<0,0,0><0,0,1>1.549 translate<0,9.35,1.7>}
			texture{col_silver}
		}
		difference{
			//Body
			box{<-3.6,2.5,0><3.6,13.15,2.55>}
			cylinder{<0,0,0><0,0,3>1.55 translate<0,9.35,-0.1>}
			cylinder{<0,0,0.1><0,0,-0.4>0.7 translate<-2.5,11.5,0>}
			cylinder{<0,0,0.1><0,0,-0.4>0.7 translate< 2.5,11.5,0>}
			cylinder{<0,0,0.1><0,0,-0.4>0.7 translate<0,6.5,0>}
			box{<-0.5,-1,-1><0.5,1,1> translate<0,1.3,0> translate<0,9.35,0>}
			box{<-0.5,-1,-1><0.5,1,1> translate<0,1.3,0> rotate<0,0, 120> translate<0,9.35,0>}
			box{<-0.5,-1,-1><0.5,1,1> translate<0,1.3,0> rotate<0,0,-120> translate<0,9.35,0>}
			pigment{Gray30}
		}
		text{ttf besch_font value 0.5,0 pigment{White} scale<1.7,2,1.7> translate<-3, 5, -0.01>}

		rotate<90,0,0>
		translate<0,2.55,-3.81>
	}
}
#end


#macro TR_TO126_L(value)
TR_TO126_L_GRND(value)
#end


/********************************************************************************************************************************************
//TO126 Housing standing
********************************************************************************************************************************************/
#macro TR_TO126_S_GRND(value)
union{
	union{
		union{
			#if(pin_short=off)
				#local tr_to126_s_pin = -14;
			#else
				#local tr_to126_s_pin = 0-(pcb_height+pin_length);
			#end

			difference{    
				//PIN Middle
				box{<0,tr_to126_s_pin,0><0.8,2.5,0.62>}
				box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45,tr_to126_s_pin,-0.2>}
				box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3,tr_to126_s_pin,-0.2>}}
			difference{ 
				//PIN Left
				box{<0,tr_to126_s_pin,0><0.8,2.5,0.62>}
				box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45,tr_to126_s_pin,-0.2>}
				box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3,tr_to126_s_pin,-0.2>}
				translate<-2.54,0,0>}
			difference{     
				//PIN Right
				box{<0,tr_to126_s_pin,0><0.8,2.5,0.62>}
				box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45,tr_to126_s_pin,-0.2>}
				box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3,tr_to126_s_pin,-0.2>}
				translate<2.54,0,0>}
			//PIN add-on
			box{<0,0,0><1.5,1,0.6> translate<-0.375,0.8,0>}
			box{<0,0,0><1.5,1,0.6> translate<-0.375,0,0> translate<2.54,0.8,0>}
			box{<0,0,0><1.5,1,0.6> translate<-0.375,0,0> translate<-2.54,0.8,0>}

			translate<-0.8/2,0,0.84>
		}//END union3

		difference{ 
			//Body ground
			box{<-2.8,4.5,1.8><2.8,12,2.551>}              
			cylinder{<0,0,0><0,0,1>1.549 translate<0,9.35,1.7>}}
		texture{col_silver}
	}//END union2

	difference{
		//Body
		box{<-3.6,2.5,0><3.6,13.15,2.55>}
		cylinder{<0,0,0><0,0,3>1.55 translate<0,9.35,-0.1>}
		cylinder{<0,0,0.1><0,0,-0.4>0.7 translate<-2.5,11.5,0>}
		cylinder{<0,0,0.1><0,0,-0.4>0.7 translate< 2.5,11.5,0>}
		cylinder{<0,0,0.1><0,0,-0.4>0.7 translate<0,6.5,0>}

		box{<-0.5,-1,-1><0.5,1,1> translate<0,1.3,0> translate<0,9.35,0>}
		box{<-0.5,-1,-1><0.5,1,1> translate<0,1.3,0> rotate<0,0, 120> translate<0,9.35,0>}
		box{<-0.5,-1,-1><0.5,1,1> translate<0,1.3,0> rotate<0,0,-120> translate<0,9.35,0>}

		pigment{Gray30}}
	text{ttf besch_font value 0.5,0 pigment{White} scale<1.7,2,1.7> 
	translate<-3,5,-0.01>}
	translate<0,0,-2.55>
}//END union1

#end


#macro TR_TO126_S(value)
TR_TO126_S_GRND(value)
#end


/********************************************************************************************************************************************
//TO18D metal cup
//daniel cardona dancardona50@hotmail.com
********************************************************************************************************************************************/
#macro TR_TO18D_GRND(value)
union{
cylinder{<0,0,0><0,14,0>0.24 texture{col_silver} translate<-0.8,0,-0.8>}                                          //linker Pin
cylinder{<0,0,0><0,14,0>0.24 texture{col_silver} translate<1,0,1>}                                            //hinterer Pin Gehäuse
union{                                                                                                          //Transitorkörper
torus{1.6 0.8 pigment {Silver} translate <0.12,19.3,0>}

cylinder{<0,14,0><0,19.3,0>2.4 pigment{ Silver}translate<0.12,0,0>}
cylinder{<0,19.3,0><0,20.1,0>1.6 pigment{ Silver}translate<0.12,0,0>}
cylinder{<0,13.9,0><0,14,0>2.9 pigment{ Silver}translate<0.12,0,0>}}
box {<-0.56,0,2.6><0.56,0.1,4.2> pigment {Silver}  translate <0.12,13.9,0> rotate <0,-90,0> }
text {ttf besch_font value 1, 0 pigment { Black } scale <0.7,1,0.7> rotate <90,135,0> translate<1,20.101,0.5>}                                //Beschriftung
translate<0,-11,-0.22> rotate <0,-135,0> }
#end

#macro TR_TO18D(value)
TR_TO18D_GRND(value)
#end


/********************************************************************************************************************************************
//TO18 Gehäuse stehend        
// Joerg Bredendiek <sprut(replace with at)sprut.de>   
//based on Robert Eckelmann <dc6xs@dc6xs.de>
********************************************************************************************************************************************/
#macro TR_TO18_GRND(value)
union{       
        #if(pin_short=off)
                #local tr_to18_pin=0;
        #else
                #local tr_to18_pin=11-(pcb_height+pin_length);
        #end    

        cylinder{<0,tr_to18_pin,0><0,14,0>0.24 texture{col_silver} translate<-1.27,0,-1.27>}                 //linker Pin
        cylinder{<0,tr_to18_pin,0><0,14,0>0.24 texture{col_silver} translate<1.27,0,1.27>}                   //hinterer Pin Gehäuse
        cylinder{<0,tr_to18_pin,0><0,14,0>0.24 texture{col_silver} translate<1.27,0,-1.27>}                  //rechter Pin

union{                                                                                                       //Transitorkörper
        torus{1.6 0.8 pigment {Silver} translate <0.12,19.3,0>}
        cylinder{<0,14,0><0,19.3,0>2.4 pigment{ Silver}translate<0.12,0,0>}
        cylinder{<0,19.3,0><0,20.1,0>1.6 pigment{ Silver}translate<0.12,0,0>}
        cylinder{<0,13.9,0><0,14,0>2.9 pigment{ Silver}translate<0.12,0,0>}}

box {<-0.58,0,2.6><0.58,0.1,4.07> pigment {Silver}  translate <0,13.9,0> rotate <0,-90,0> }
text {ttf besch_font value 1, 0 pigment { Black } scale <0.7,1,0.7> rotate <90,0,0> translate<-1.5,20.101,-.5>} //Beschriftung
translate<0,-11,0>
}
#end


#macro TR_TO18(value)
TR_TO18_GRND(value)
#end


/********************************************************************************************************************************************
//
// Joerg Bredendiek <sprut(replace with at)sprut.de>   
********************************************************************************************************************************************/
#macro TR_TO202_GRND(value, pins, hor, inline, lang, shift)
/********************************************************************************************************************************************
//plastic body for TO202
********************************************************************************************************************************************/
#macro TR_TO202_BODY()
// plastik grundkoerper
difference{
	box{<-4.8, 10, -2.5><4.8, 18, 2>}
        box{<-2, 9, 4><0, 19, -4> rotate<0, 7, 0> translate<-4.8, 0, 0> }	                             
        box{<-2, 9, 4><0, 19, -4> rotate<0,-7, 0> translate<-4.8, 0, 0> }	                             
        box{< 2, 9, 4><0, 19, -4> rotate<0,45, 0> translate< 4.8, 0, 0> }	                             
        box{< 2, 9, 4><0, 19, -4> rotate<0,-7, 0> translate< 4.8, 0, 0> }	                                                         
//	cylinder{<0, 14, 2.4><0, 14, 2.6> 1.7}
	pigment{Gray30}
}
#end
/********************************************************************************************************************************************
//pin vertical TO202
********************************************************************************************************************************************/
#macro TR_TO202_PIN_V(shift)
#local lshift = shift+lang;
union{
 	difference{
		box{<0,tr_to202_s_pin,0><0.66, 10.5, 0.5>}
		box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45,tr_to202_s_pin,-0.2>}
		box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3,tr_to202_s_pin,-0.2>}  
	        translate<-0.66/2, 0, -0.25>		
	}
 	box{<-0.375, 8, -0.25><0.375, 10.5, 0.25>}
}
#end
/********************************************************************************************************************************************
//pin horizontal TO202
********************************************************************************************************************************************/
#macro TR_TO202_PIN_H(shift)
union{
	union{
		#local tr_to202_v_pin = tr_to202_s_pin -2;
		// senkrechter spitzer teil
		difference{
			box{<-0.375,tr_to202_v_pin ,0><0.375,8.5,0.6>}
			box{<0,0,0>< 1,1,1> rotate<0,0,-25> translate<0.45-0.375,tr_to202_v_pin ,-0.2>}
			box{<0,0,0><-1,1,1> rotate<0,0, 25> translate< 0.3-0.375,tr_to202_v_pin ,-0.2>}}
		// biegung
		difference{
			cylinder{<-0.375,8.5,0.6><0.375,8.5,0.6>0.6}
			cylinder{<-0.38,8.0,1.1><0.38,8.0,1.1>0.5}}
		// horizontal zum koerper
		box{<-0.375, 8.5, 0.6> <0.375, 9.1, 5>} 
	}
	box{<-0.75, 8.5, 3><0.75, 9.1, 5> translate<0,0,0> }
	translate<0, 0, -2.54-0.3> 
}
#end
/********************************************************************************************************************************************
//pin TO202
********************************************************************************************************************************************/
#macro TR_TO202_PIN(shift)
#if (hor=1)
        TR_TO202_PIN_H(shift)
#else
        TR_TO202_PIN_V(shift)
#end
#end
/********************************************************************************************************************************************
//metal plate
********************************************************************************************************************************************/
#macro TR_TO202_BACK()
union{
	// metallische Kuehlfahne
	difference{
		box{<-3.1, 17, -0.25> <3.1, 32, 0.25>}
		cylinder{<0,0,-1><0,0,1>1.65 translate<0,29,0>}
	}	
	box{<-3.0, 20, -0.25> <-4.6, 32, 0.25>}
        box{< 3.0, 20, -0.25> < 4.6, 32, 0.25>}
	texture{col_silver}
}
#end
/********************************************************************************************************************************************

********************************************************************************************************************************************/
// pin_length = 2.5;
// pcb_height = 1.5;

union{	
	#if(pin_short=off)
		#local tr_to202_s_pin = 0;
	#else
		#local tr_to202_s_pin = 9.5-(pcb_height+pin_length);
	#end

	//Pins
	union{
           	object{TR_TO202_PIN(0) translate<-2.54,0,0>}
		object{TR_TO202_PIN(0) translate< 2.54,0,0>}
		object{TR_TO202_PIN(0)}
     		texture{col_silver}
		translate<0,-7,-2.54>
	}

	// Koerper
	union{
		// metallische Rueckplatte
		object{TR_TO202_BACK()} 
		// plastik grundkoerper
		object{TR_TO202_BODY()}     
		// Beschriftung
		text{ttf besch_font value 0.5,0 pigment{White} scale<1,1.5,1> translate<-3.5,15,-0.01-2.5>}
		translate<0,-7,-2>      // rueckseite schliesst mit 0 ab    
		#if (hor=1)
			translate< 0, -3, 0>
			rotate<90,0,0>
			translate< 0, 0, -1>
		#end
	}
}
#end


#macro TR_TO202_3_H(value)
TR_TO202_GRND(value, 3, 1, 1, 5.08, 0)
#end
#macro TR_TO202_3_V(value)
TR_TO202_GRND(value, 3, 0, 1, 0, 0)
#end


/********************************************************************************************************************************************
//Macros for TO218AB with up or down bended pin
//Designed by Philippe Boucheny <philippe.boucheny(at)numericable.fr>
//Rev. 1.0  12/05/06
********************************************************************************************************************************************/
#macro TR_TO218_GRND(value,pindir,Lh,pinsnb,cutpins,pRot,pTra)
#macro TR_TO218_BENDED_PIN (pindir,Lt,Lh,xp,yp,cutpins)
//pin dirrection 0=up 1=down 3= straight; Lt pin length; Lh horizontal part length without rounded part
//xpin = pin Width; yp = thinckness
//Lt = Lh + (pi/2)r + Lv
//cutpins 1=enable short pins cutting 0=disable it
#if(cutpins=0)
#local cutpins = 0;
#else
#local cutpins = pin_short;
#end

#declare r=0.6;         
#declare Lv=Lt-Lh-1.57*r;
union{
    #if (pindir=3) //straight pin
        #if(cutpins=off)
            box{<-xp/2,+yp/2,-yp/2><+xp/2,-yp/2,-yp/2-Lh-1>} //horizontal part
        #else
            box{<-xp/2,+yp/2,-yp/2-Lh+(pcb_height+pin_length)+3><+xp/2,-yp/2,-yp/2-Lh-1>}//shorted horizontal part
        #end    
    #else
        difference{
            #if(cutpins=off)
                box{<-xp/2,-r+yp/2,-yp/2><xp/2,-r+yp/2-Lv,+yp/2>} //vertical part
                box{<0,0,-1><1,1,1> rotate<0,0,-25> translate<0.45-0.375,-r+yp/2-Lv,0>} //terminal V shape
                box{<0,0,-1><-1,1,1> rotate<0,0,25> translate<0.30-0.375,-r+yp/2-Lv,0> }
            #else
                box{<-xp/2,-r+yp/2,-yp/2><xp/2,-2.5-(pcb_height+pin_length),+yp/2>}//shorted vertical part
            #end
        }
        difference{ //curved part
            cylinder{<-xp/2,-r+yp/2,-r+yp/2><xp/2,-r+yp/2,-r+yp/2>r}
            box{<-xp/2-0.1,-yp/2,-yp/2><+xp/2+0.1,-yp/2-1,-yp/2-1>}
        }
        box{<-xp/2,+yp/2,-yp/2><+xp/2,-yp/2,-yp/2-Lh-1>}//short horizontal part next case
    #end
    box{<-0.75,+yp/2,-yp/2-Lh-1.0><+0.75,-yp/2,-yp/2-Lh+1.7>}//large horizontal part next case
    box{<-0.90,+yp/2,-yp/2-Lh+0.7><+0.90,-yp/2,-yp/2-Lh+1.7>}//extra large horizontal part next case
    rotate 180*y
    #if (pindir=0) // up/down pins
        rotate 180*z
    #end
    translate <0,2.75,-Lh-yp/2> // offset to mid thickness case and change zero to fixation hole
}
#end

union{
    
    union{
        
        difference{ //plastic case
            box{<-7.4,0,-3.8><7.4,4.9,-16.3>} //main part
            box{<-7.5,-3,-3.8><7.5,6,0> rotate<-1,0,0> } //heatsink side shaping
            box{<-7.4,-3,-3.7><-10,6,-16.4> rotate<0,0,-1> }//right side shaping
            box{<+7.4,-3,-3.7><+10,6,-16.4> rotate<0,0,+1> }//left side shaping
            box{<-7.5,-3,-16.3><7.5,6,-20> rotate<+2,0,0> translate 2.75*y }//pins side up shaping
            box{<-7.5,-3,-16.3><7.5,6,-20> rotate<-2,0,0> translate 2.75*y}//pins side down shaping
            cylinder{<0,4.8,-10.05><0,5,-10.05>2}//light printed round
            pigment{Gray30}
        }
        text{ttf besch_font value 0.5,0 pigment{White} scale<2.5,2.5,2> rotate 90*x translate<-4.5,4.95,-7>}//3 character code
        difference{ 
            box{<-7.4,-0.01,-3.8><7.4,2,4>}//heatsink base
            cylinder{<0,-0.1,0><0,2.1,0>2.02}//hole
            box{<-1,-0.1,-2><+1,2.1,+2> rotate<0,+45,0> translate<-7.4,0,4>}//right corner
            box{<-1,-0.1,-2><+1,2.1,+2> rotate<0,-45,0> translate<+7.4,0,4>}//left corner
        }
        box{<-7.5,-0.01,-3><+7.5,2,-2>}//extra side heatsink
        box{<-5.5,-0.01,-3.7><+5.5,0,-12>}//heatsink under case
    }
    union{
        object{TR_TO218_BENDED_PIN(pindir,14.5,Lh,1.1,0.5,cutpins) translate<-5.5,0,-16.3>} //left pin
        #if(pinsnb=3)
            object{TR_TO218_BENDED_PIN(pindir,14.5,Lh,1.1,0.5,cutpins) translate<0,0,-16.3>}//center pin
        #end
        object{TR_TO218_BENDED_PIN(pindir,14.5,Lh,1.1,0.5,cutpins) translate<+5.5,0,-16.3>} //right pin   
        
    }
    texture{col_silver}
    translate 10.05*z
    
    rotate pRot
    translate pTra
}
#end


#macro TR_TO218(value)
TR_TO218_GRND(value,1,3,3,on,0,0)
#end
#macro TR_TO218V(value)
TR_TO218_GRND(value,3,10,3,on,-90*x,9*y)
#end
#macro TR_TO218_2(value)
TR_TO218_GRND(value,1,3,2,on,0,0)
#end
#macro TR_TO218_2V(value)
TR_TO218_GRND(value,3,10,2,on,-90*x,9*y)
#end


/********************************************************************************************************************************************
//
// Joerg Bredendiek <sprut(replace with at)sprut.de>   
// pruefen:
//TO220H:0:1:0:0:0:0:0:0:0:0:0:0:0:0:0:0:-6.2:0:0:1:0:0:0:0:0:0:0:0:0:0:TR_TO220_L2(:TO220 liegend:TO220 Horizontal
********************************************************************************************************************************************/
#macro TR_TO220_GRND(value, pins, hor, inline, lang, shift)
/********************************************************************************************************************************************
//plastic body for TO220
********************************************************************************************************************************************/
#macro TR_TO220_BODY()
// plastik grundkoerper
difference{
	box{<-5.1, 13.5, 0><5.1, 22.6, 4.5>}
	box{<-5.5, 0, 0><5.5, 3.5, -2> rotate<80, 0, 0> translate<0, 22.6-0.6, 0> }
	box{<-5.5, 0, 0><5.5, -1, 2> rotate<-20, 0, 0> translate<0, 13.5, 3.7> }
	cone{<-5.4,16.5,-0.01>1.4<-5.4,16.5,3.23>1.2}
	cone{<5.4,16.5,-0.01>1.4<5.4,16.5,3.23>1.2}
	#if (pins>3)
	cylinder{<-3.5, 14.5, 0.1><-3.5, 14.5, -0.05>0.7}
	#else
	cylinder{<0, 14.5, 0.1><0, 14.5, -0.05>0.7}
	#end
	pigment{Gray30}
}
#end
/********************************************************************************************************************************************
//pin vertical TO220
********************************************************************************************************************************************/
#macro TR_TO220_PIN_V(shift)
#local lshift = shift+lang;
union{
	// die platinenoberflaeche liegt bei etwa 8.5
	// unterer teil
	union{
	 	difference{
			box{<0,tr_to220_s_pin,0><0.75, 9, 0.6>}
			box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45,tr_to220_s_pin,-0.2>}
			box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3,tr_to220_s_pin,-0.2>}
		}
		#if (inline=0)
		#if (lshift>0)
			// biegung
			difference{
				cylinder{< 0,  8.5, 0.6><0.75, 8.5, 0.6> 0.6}
				cylinder{<-0.1,8.0, 1.1><0.76, 8.0, 1.1> 0.5}
				translate<0, 0.5, 0>}
		translate<0,0,-shift*2.54-lang>
		#end
		#end
	}

	//oberer teil
	box{<0,9.6,0><0.75,13.5,0.6>}
	#if (inline=0)
	#if (lshift>0)
	difference{
		cylinder{< 0,   9.6,   0  ><0.75, 9.6,   0> 0.6}
		cylinder{<-0.1,10.1,  -0.5><0.76,10.1,-0.5> 0.5}
	}
	#end
	#end

	//mittlerer teil
	#if (lshift>0)
	#if (inline=1)
		box{<0,9,0><0.75,9.6,0.6>}
	#else
		box{<0,9.6,-shift*2.54-lang+0.6><0.75,9,0.6-0.6>}
	#end
	#else
		box{<0,9.6,-shift*2.54-lang+0.6><0.75,9,0.6-0.6>}
	#end

	#if (pins<5)
		box{<0,0,0><1.5, 3.7, 0.6> translate<-0.375, 9.8, 0>}
	#end
	translate<-0.75/2, -8.5  , -2.54-0.3>
}
#end
/********************************************************************************************************************************************
//pin horizontal TO220
********************************************************************************************************************************************/
#macro TR_TO220_PIN_H(shift)
union{
union{
	#local tr_to220_v_pin = tr_to220_s_pin -2;
	// senkrechter spitzer teil
	difference{
		box{<-0.375,tr_to220_v_pin ,0><0.375,8.5,0.6>}
		box{<0,0,0>< 1,1,1> rotate<0,0,-25> translate<0.45-0.375,tr_to220_v_pin ,-0.2>}
		box{<0,0,0><-1,1,1> rotate<0,0, 25> translate< 0.3-0.375,tr_to220_v_pin ,-0.2>}}
	// biegung
	difference{
		cylinder{<-0.375,8.5,0.6><0.375,8.5,0.6>0.6}
		cylinder{<-0.38,8.0,1.1><0.38,8.0,1.1>0.5}}
	// horizontal zum koerper
	box{<-0.375,8.5,0.6><0.375,9.1,4.0+2.54*shift>}
	translate<0, -5.98,-6.7>
	translate<0,     0, 5.08-lang>
	#if (inline=0)
		translate<0,0,-2.54*shift>
	#end
}
#if (pins<5)
#if (lang>1)
	box{<-0.75, 8.5, 2><0.75, 9.1, 6> translate<0, -5.98, -6.7>
	translate<0,0,(5.08-lang)/2>
	}
#end
#end
}
#end
/********************************************************************************************************************************************
//pin TO220
********************************************************************************************************************************************/
#macro TR_TO220_PIN(shift)
#if (hor=1)
TR_TO220_PIN_H(shift)
#else
TR_TO220_PIN_V(shift)
#end
#end
/********************************************************************************************************************************************
//metal back plate
********************************************************************************************************************************************/
#macro TR_TO220_BACK()
union{
	// metallische Rueckplatte
	difference{
		box{<-5.1,22.6,4.5><5.1,29,4.5-1.27>}
		cylinder{<0,0,0><0,0,2>1.9 translate<0,26.2,2.6>}
		box{<0,0,0><1,3,3> rotate<0,0,20> translate<5.1,26.5,2>}
		box{<0,0,0><-1,3,3> rotate<0,0,-20> translate<-5.1,26.5,2>}
	}
	box{<-4,22.6,4.5><4,16,4.501>}
	texture{col_silver}
}
#end
/********************************************************************************************************************************************

********************************************************************************************************************************************/
// pin_length = 2.5;
// pcb_height = 1.5;

union{	
	#if(pin_short=off)
		#local tr_to220_s_pin = -2;
	#else
		#local tr_to220_s_pin = 9.5-(pcb_height+pin_length)-2;
	#end

	//Pins
	union{
		#if (pins<5)
			object{TR_TO220_PIN(0) translate<-2.54,0,0>}
			object{TR_TO220_PIN(0) translate< 2.54,0,0>}
			#if (pins>2)
				object{TR_TO220_PIN(2)}
			#end
		#else
			object{TR_TO220_PIN(1.5)}
			object{TR_TO220_PIN(0)   translate<-1.778,0,0>}
			object{TR_TO220_PIN(0)   translate< 1.778,0,0>}
			object{TR_TO220_PIN(1.5) translate<-3.556,0,0>}
			object{TR_TO220_PIN(1.5) translate< 3.556,0,0>}
		#end			
		texture{col_silver}
	}

	// Koerper
	union{
		// metallische Rueckplatte
		object{TR_TO220_BACK()}
		// plastik grundkoerper
		object{TR_TO220_BODY()}
		// Beschriftung
		text{ttf besch_font value 0.5,0 pigment{White} scale<1.7,2,1.7> translate<-3.5,18,-0.01>}
		translate<0,-9.5,-4.5>
		#if (hor=1)
			translate< 0, -4, 4.5>
			rotate<90,0,0>
			translate< 0, 4.6, -1.4>
		#end
	}
}
#end


#macro TR_TO220_3_H(value)
TR_TO220_GRND(value, 3, 1, 1, 5.08, 0)
#end
#macro TR_TO220_2_H(value)
TR_TO220_GRND(value, 2, 1, 1, 5.08, 0)
#end
#macro TR_TO220_3_H1(value)
TR_TO220_GRND(value, 3, 1, 1, 2.54, 0)
#end
#macro TR_TO220_3_H2(value)
TR_TO220_GRND(value, 3, 1, 1, 2.54, 5.08)
#end
#macro TR_TO220_3_H3(value)
TR_TO220_GRND(value, 3, 1, 1, 0.5, 0)
#end
#macro TR_TO220_3_HX(value)
TR_TO220_GRND(value, 3, 1, 0, 2.54, 0)
#end
#macro TR_TO220_2_V(value)
TR_TO220_GRND(value, 2, 0, 1, 0, 0)
#end
#macro TR_TO220_3_V(value)
TR_TO220_GRND(value, 3, 0, 1, 0, 0)
#end
#macro TR_TO220_3_VX(value)
TR_TO220_GRND(value, 3, 0, 0, 0, 0)
#end
#macro TR_TO220_5_V(value)
TR_TO220_GRND(value, 5, 0, 0, 2, 0)
#end


/********************************************************************************************************************************************
//TO220 5-Pin Gehaeuse mit geraden Pins, stehend
//dahamm@gmx.net
********************************************************************************************************************************************/
#macro TR_TO220_T05A_S_GRND(value)
union{	
	union{
		union{
			#if(pin_short=off)
				#local tr_to220_s_pin = 9.5;
			#else
				#local tr_to220_s_pin = 9.5-(pcb_height+pin_length);
			#end
			difference{
				box{<0,tr_to220_s_pin,0><0.75,13.5,0.6>}
				box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45,tr_to220_s_pin,-0.2>}
				box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3,tr_to220_s_pin,-0.2>}
			}
			difference{
				box{<0,tr_to220_s_pin,0><0.75,13.5,0.6>}
				box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45,tr_to220_s_pin,-0.2>}
				box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3,tr_to220_s_pin,-0.2>}
				translate<-1.778,0,0>
			}
			difference{
				box{<0,tr_to220_s_pin,0><0.75,13.5,0.6>}
				box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45,tr_to220_s_pin,-0.2>}
				box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3,tr_to220_s_pin,-0.2>}
				translate<1.778,0,0>
			}
			difference{
				box{<0,tr_to220_s_pin,0><0.75,13.5,0.6>}
				box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45,tr_to220_s_pin,-0.2>}
				box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3,tr_to220_s_pin,-0.2>}
				translate<3.556,0,0>
			}
			difference{
				box{<0,tr_to220_s_pin,0><0.75,13.5,0.6>}
				box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45,tr_to220_s_pin,-0.2>}
				box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3,tr_to220_s_pin,-0.2>}
				translate<-3.556,0,0>
			}
			box{<0,0,0><1.5,3.7,0.6> translate<-0.375,9.8,0>}
			box{<0,0,0><1.5,3.7,0.6> translate<-0.375,0,0> translate<1.778,9.8,0>}
			box{<0,0,0><1.5,3.7,0.6> translate<-0.375,0,0> translate<-1.778,9.8,0>}
			box{<0,0,0><1.5,3.7,0.6> translate<-0.375,0,0> translate<3.556,9.8,0>}
			box{<0,0,0><1.5,3.7,0.6> translate<-0.375,0,0> translate<-3.556,9.8,0>}
			translate<-0.75/2,0,1.6>
		}
		difference{
			box{<-5.1,22.6,4.5><5.1,29,4.5-1.27>}
			cylinder{<0,0,0><0,0,2>1.9 translate<0,26.2,2.6>}
			box{<0,0,0><1,3,3> rotate<0,0,20> translate<5.1,26.5,2>}
			box{<0,0,0><-1,3,3> rotate<0,0,-20> translate<-5.1,26.5,2>}
		}
		box{<-4,22.6,4.5><4,16,4.501>}
		texture{col_silver}
	}
	difference{
		box{<-5.1,13.5,0><5.1,22.6,4.5>}
		box{<-5.5,0,0><5.5,3,-2> rotate<45,0,0> translate<0,22.6-1.8,0> }
		box{<-5.5,0,0><5.5,-1,2> rotate<-20,0,0> translate<0,13.5,3.7> }
		cone{<-5.4,16.5,-0.01>1.4<-5.4,16.5,3.23>1.2}
		cone{<5.4,16.5,-0.01>1.4<5.4,16.5,3.23>1.2}
		cylinder{<0,14.5,0.1><0,14.5,-0.05>0.7}
		pigment{Gray30}
	}
	text{ttf besch_font value 0.5,0 pigment{White} scale<1.7,2,1.7> translate<-3.5,18,-0.01>}
	translate<0,-9.5,-4.5>
}
#end
#macro TR_TO220_T05A_S(value)
TR_TO220_T05A_S_GRND(value)
#end


/********************************************************************************************************************************************
//Macros for TO247 
//Designed by Philippe Boucheny <philippe.boucheny(at)numericable.fr>
//Rev. 1.0  26/10/07
********************************************************************************************************************************************/
#macro TR_TO247_GRND(value,pindir,Lh,pinsnb,cutpins,pRot,pTra)
#macro TO247_BENDED_PIN (pindir,Lt,Lh,xp,yp,cutpins,xxp)
//pin dirrection 0=up 1=down 3= straight; Lt pin length; Lh horizontal part length without rounded part
//xpin = pin Width; yp = thinckness
//Lt = Lh + (pi/2)r + Lv
//cutpins 1=enable short pins cutting 0=disable it
#if(cutpins=0)
#local cutpins = 0;
#else
#local cutpins = pin_short;
#end

#local r=0.6;         
#local Lv=Lt-Lh-1.57*r;
union{
    #if (pindir=3) //straight pin
        #if(cutpins=off)
            box{<-xp/2,+yp/2,-yp/2><+xp/2,-yp/2,-yp/2-Lh-1>} //horizontal part
        #else
            box{<-xp/2,+yp/2,-yp/2-Lh+(pcb_height+pin_length)+3><+xp/2,-yp/2,-yp/2-Lh-1>}//shorted horizontal part
        #end    
    #else
        difference{
            #if(cutpins=off)
                box{<-xp/2,-r+yp/2,-yp/2><xp/2,-r+yp/2-Lv,+yp/2>} //vertical part
                box{<0,0,-1><1,1,1> rotate<0,0,-25> translate<0.45-0.375,-r+yp/2-Lv,0>} //terminal V shape
                box{<0,0,-1><-1,1,1> rotate<0,0,25> translate<0.30-0.375,-r+yp/2-Lv,0> }
            #else
                box{<-xp/2,-r+yp/2,-yp/2><xp/2,-2.5-(pcb_height+pin_length),+yp/2>}//shorted vertical part
            #end
        }
        difference{ //curved part
            cylinder{<-xp/2,-r+yp/2,-r+yp/2><xp/2,-r+yp/2,-r+yp/2>r}
            box{<-xp/2-0.1,-yp/2,-yp/2><+xp/2+0.1,-yp/2-1,-yp/2-1>}
        }
        box{<-xp/2,+yp/2,-yp/2><+xp/2,-yp/2,-yp/2-Lh-1>}//short horizontal part next case
    #end
        
    //box{<-xxp/2,+yp/2,-yp/2-Lh-1.0><+xxp/2,-yp/2,-yp/2-Lh+1.7>}//large horizontal part next case
    
    prism {linear_sweep linear_spline +yp/2, -yp/2,5,
    < -xxp/2, -yp/2-Lh-1.0>, < +xxp/2, -yp/2-Lh-1.0>, < +xxp/2, -yp/2-Lh+1.7>, < 0, -yp/2-Lh+1.7+1>,  < -xxp/2, -yp/2-Lh+1.7> 
    }


    //box{<-0.90,+yp/2,-yp/2-Lh+0.7><+0.90,-yp/2,-yp/2-Lh+1.7>}//extra large horizontal part next case
    rotate 180*y
    #if (pindir=0) // up/down pins
        rotate 180*z
    #end
    translate <0,2.75,-Lh-yp/2> // offset to mid thickness case and change zero to fixation hole
}
#end


union{
    difference{
        union{
            
            difference{ //plastic case
                box{<-7.75,0,-6.35><7.75,5,+13.65>} //main part
                box{<-7.8,-3,-5.5><7.8,6,-8> rotate<-6,0,0> translate<0,2,0>} //pins side bevel
                box{<-7.8,-3,-5.5><7.8,6,-8> rotate<+6,0,0> translate<0,2,0>} //pins side bevel
                box{<-7.8,-3,+14><7.8,6,+18> rotate<-6,0,0> translate<0,2,0>} //top side bevel
                box{<-7.8,-3,+14><7.8,6,+18> rotate<+6,0,0> translate<0,2,0>} //top side bevel
                box{<-7.5,-3,-7><-10,6,+15> rotate<0,0,+6> translate<0,2,0> } //right side bevel
                box{<-7.5,-3,-7><-10,6,+15> rotate<0,0,-6> translate<0,2,0> } //right side bevel
                box{<+7.5,-3,-7><+10,6,+15> rotate<0,0,+6> translate<0,2,0> } //left side bevel
                box{<+7.5,-3,-7><+10,6,+15> rotate<0,0,-6> translate<0,2,0> } //left side bevel
                cone{<+7.75,2,+8.15>,2.25,<+7.75,5.1,+8.15> 2.75}
                cone{<-7.75,2,+8.15>,2.25,<-7.75,5.1,+8.15> 2.75}

                pigment{Gray30}
            }
            text{ttf global_fontfile_arial value 0.5,0 pigment{White} scale<2,2.5,2> rotate 90*x translate<-5,5.05,0>}//3 character code
            box{<-6.75,-0.01,-4><+6.75,+0.5,+13.5>}//heatsink under case
        }
        cylinder{<0,-10,+8.15><0,+10,+8.15>3.6/2}//Hole

    }
    union{
        object{TO247_BENDED_PIN(pindir,14.5,Lh,1.2,0.5,cutpins,2.2) translate<-5.45,0,-6.3>} //left pin
        #if(pinsnb=3)
            object{TO247_BENDED_PIN(pindir,14.5,Lh,1.2,0.5,cutpins,3.2) translate<0,0,-6.3>}//center pin
        #end
        object{TO247_BENDED_PIN(pindir,14.5,Lh,1.2,0.5,cutpins,2.2) translate<+5.45,0,-6.3>} //right pin   
        
    }
    texture{col_silver}        
    
    #if (pindir=3) //straight pin
      rotate<-90,0,0>   
      translate<0,8,0>
    #end            
    translate pTra 
}
#end


#macro TR_TO247_H(value)
TR_TO247_GRND(value,1,3,3,on,0,0) 
#end
#macro TR_TO247_H1(value)
TR_TO247_GRND(value,1,13,3,on,0,<0,0,-8.0>)
#end
#macro TR_TO247_2H(value)
TR_TO247_GRND(value,1,3,2,on,0,0)
#end
#macro TR_TO247_V(value)
TR_TO247_GRND(value,3,10,3,on,-90*x,9*y)
#end
#macro TR_TO247_2V(value)
TR_TO247_GRND(value,3,10,2,on,-90*x,9*y)
#end


/********************************************************************************************************************************************
//TO39 metal cup
//daniel cardona<dancardona50@hotmail.com>
// mod by Joerg Bredendiek <sprut(replace with at)sprut.de>   
********************************************************************************************************************************************/
#macro TR_TO39_GRND(value, pins)
// pin_length = 2.5;
// pcb_height = 1.5;

union{	
	#if(pin_short=off)
		#local tr_to39_pin = 0;
	#else
		#local tr_to39_pin = 11-(pcb_height+pin_length);
	#end
	#if (pins=4)
		cylinder{<0,tr_to39_pin ,0><0,14,0>0.24 texture{col_silver} translate<0,0,-1.8>}      //linker Pin
		cylinder{<0,tr_to39_pin ,0><0,14,0>0.24 texture{col_silver} translate<0,0, 1.8>}      //hinterer Pin
		cylinder{<0,tr_to39_pin ,0><0,14,0>0.24 texture{col_silver} translate< 1.8,0,0>}      //rechter Pin
		cylinder{<0,tr_to39_pin ,0><0,14,0>0.24 texture{col_silver} translate<-1.8,0,0>}      //vorderer Pin
	#else
		cylinder{<0,tr_to39_pin ,0><0,14,0>0.24 texture{col_silver} translate<0,0,-2.54>}      //linker Pin
		cylinder{<0,tr_to39_pin ,0><0,14,0>0.24 texture{col_silver} translate<0,0, 2.54>}      //hinterer Pin Gehaeuse
		cylinder{<0,tr_to39_pin ,0><0,14,0>0.24 texture{col_silver} translate< 2.54,0,0>}      //rechter Pin
	#end

	union{                                                                                                       //Transistorkörper
		torus{4.2 0.8 pigment {P_Silver3} translate <0.12,19.3,0>}
		cylinder{<0,14,0><0,19.3,0>5 pigment{ P_Silver3}translate<0.12,0,0>}
		cylinder{<0,19.3,0><0,20.1,0>4.2 pigment{ P_Silver3}translate<0.12,0,0>}
		cylinder{<0,13.9,0><0,14,0>5.6  pigment{P_Silver3}translate<0.12,0,0>}}
	box {<-0.56,0,2.6><0.56,0.1,6.2> pigment{P_Silver3}  translate <0.12,13.9,0> rotate <0,-135,0> }
	text {ttf besch_font value 1, 0 pigment { Black } scale <1,1,1> rotate <90,0,0> translate<-1.5,20.2,-.5>}    //Beschriftung
	finish {
 	   ambient (0.25 * global_ambient_mul)
	    brilliance 4
	    diffuse 0.5
	    metallic
	    specular 0.80
 	   roughness 1/80
 	   reflection 0.5
	}
	pigment{ P_Silver3}
	translate<0,-11,0>
	
	#if (pins=4)
		rotate<0,45,0>
	#end
}
#end

#macro TR_TO39(value)
TR_TO39_GRND(value, 3)
#end
#macro TR_TO39_4(value)
TR_TO39_GRND(value, 4)
#end


/********************************************************************************************************************************************
//TO3 metal cup
//daniel cardona<dancardona50@hotmail.com>
********************************************************************************************************************************************/
#macro TR_TO3_GRND(value)
union{
union{
difference{
   cylinder { <0, 0, 0>, <0, 1, 0>, 5   }
    cylinder { <0, -0.5, 0>, <0, 1.1, 0>, 2.3   }
translate <15,0,0>
} 
difference{
   cylinder { <0, 0, 0>, <0, 1, 0>, 5   }
    cylinder { <0, -0.5, 0>, <0, 1.1, 0>, 2.3   } 
translate <-15,0,0> 
}    
translate<0,0,0>}
union{  
box {<0, 0, 0> < 13,  1,  3> translate <-11.8,0,9.5>rotate <0,-30,0>}
box {<0, 0, 0> < 13,  1,  3> translate <0.2,0,-12.7>rotate <0,-30,0>}
box {<0, 0, 0> < 13,  1,  3> translate <-2,0,9.4>rotate <0,30,0>}
box {<0, 0, 0> < 13,  1,  3> translate <-13.2,0,-12.7>rotate <0,30,0>}
 cylinder{<0,0,0><0,4,0>0.6 translate<-1.8,-3,-5.4>} 
 cylinder{<0,0,0><0,4,0>0.6 translate<-1.8,-3,5.4>} 
cylinder{<0,0,0><0,1,0>12.7}
  cylinder{<0,1,0><0,2,0>11.6}
   cylinder{<0,2,0><0,8,0>10} 
    torus{9.2 0.8  translate <0,8,0>}
     cylinder{<0,8,0><0,8.8,0>9.2} 
text {ttf besch_font value 0.5, 0 pigment { Black } scale <5,1,5> rotate <90,0,0> translate<-5,8.81,0>} 
translate<0,0,0>} 


pigment{P_Chrome5}

finish {
    ambient (0.25 * global_ambient_mul)
    brilliance 4
    diffuse 0.5
    metallic
    specular 0.80
    roughness 1/80
    reflection 0.5
}

}
#end

#macro TR_TO3(value)
TR_TO3_GRND(value)
#end


/********************************************************************************************************************************************
//TO52 metal case
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1  20/12/05
********************************************************************************************************************************************/
#macro TR_TO52_GRND(value,npin)
union{
    //case
    cylinder{<0,0,0><0,3.5-0.3,0>2.35 pigment{P_Silver3} }
    cylinder{<0,3.5-0.3,0><0,3.5,0>2.05 pigment{P_Silver3}}
    torus{2.05 0.3 pigment {P_Silver3} translate (3.5-0.3)*y}
    torus{2.45 0.3 pigment {P_Silver3} translate 0.3*y}
    cylinder{<0,0,0><0,0.6,0>2.45 pigment{P_Silver3}}
    box {<-0.5,0,0><0.5,0.6,3.3> pigment{P_Silver3}  translate <0,0,0> rotate <0,135,0> }
    text {ttf besch_font value 1, 0 pigment { Black } scale <1,1,1> rotate <90,0,0> translate<-1.5,3.52,-.4>}
    //pins
    #if(npin=2)
        #if(pin_short=off)
            cylinder{<+1.27,0,0><+1.27,-12.7,0>0.2 pigment{ P_Silver3}}
            cylinder{<-1.27,0,0><-1.27,-12.7,0>0.2 pigment{ P_Silver3}}
        #else
            cylinder{<+1.27,0,0><+1.27,-(pin_length+pcb_height),0>0.2 pigment{ P_Silver3}}
            cylinder{<-1.27,0,0><-1.27,-(pin_length+pcb_height),0>0.2 pigment{ P_Silver3}}
        #end
    #else
        #if(pin_short=off)
            cylinder{<+1.27,0,0><+1.27,-12.7,0>0.2 pigment{ P_Silver3}}
            cylinder{<-1.27,0,0><-1.27,-12.7,0>0.2 pigment{ P_Silver3}}
            cylinder{<0,0,+1.27><0,-12.7,+1.27>0.2 pigment{ P_Silver3}}
        #else
            cylinder{<+1.27,0,0><+1.27,-(pin_length+pcb_height),0>0.2 pigment{ P_Silver3}}
            cylinder{<-1.27,0,0><-1.27,-(pin_length+pcb_height),0>0.2 pigment{ P_Silver3}}
            cylinder{<0,0,+1.27><0,-(pin_length+pcb_height),+1.27>0.2 pigment{ P_Silver3}}
        #end
    #end
    }
    translate<0,1,0>
#end

#macro TR_TO51(value)
TR_TO52_GRND(value,2)
#end
#macro TR_TO52(value)
TR_TO52_GRND(value,3)
#end
#macro TR_TO52A(value)
TR_TO52_GRND(value,3)
#end


/********************************************************************************************************************************************
//TO66 metal cup
//daniel cardona<dancardona50@hotmail.com>
********************************************************************************************************************************************/
#macro TR_TO66_GRND(value)
union{
union{
difference{
   cylinder { <0, 0, 0>, <0, 1, 0>, 3.6   }
    cylinder { <0, -0.5, 0>, <0, 1.1, 0>, 1.8   }
translate <12,0,0>
} 
difference{
   cylinder { <0, 0, 0>, <0, 1, 0>, 3.6   }
    cylinder { <0, -0.5, 0>, <0, 1.1, 0>, 1.8   } 
translate <-12,0,0> 
}    
translate<0,0,0>}
union{  
box {<0, 0, 0> < 10,  1,  3.7> translate <-9,0,5.>rotate <0,-25,0>}
box {<0, 0, 0> < 10,  1,  3.7> translate <-1.4,0,-8.7>rotate <0,-25,0>}
box {<0, 0, 0> < 10,  1,  3.7> translate <-1,0,4.6>rotate <0,25,0>}
box {<0, 0, 0> < 10,  1,  3.7> translate <-9.4,0,-8.7>rotate <0,25,0>}
 cylinder{<0,0,0><0,4,0>0.6 translate<-2.6,-3,-2.8>} 
 cylinder{<0,0,0><0,4,0>0.6 translate<-2.6,-3,2.8>} 
cylinder{<0,0,0><0,1,0>8.6}
  cylinder{<0,1,0><0,2,0>7.6}
   cylinder{<0,2,0><0,8,0>6} 
    torus{5.2 0.8  translate <0,8,0>}
     cylinder{<0,8,0><0,8.8,0>5.2} 
text {ttf besch_font value 0.5, 0 pigment { Black } scale <2,1,2> rotate <90,0,0> translate<-4,8.81,0>} 
translate<0,0,0>} 


pigment{P_Chrome5}

finish {
    ambient (0.25 * global_ambient_mul)
    brilliance 4
    diffuse 0.5
    metallic
    specular 0.80
    roughness 1/80
    reflection 0.5
}

}
#end

#macro TR_TO66(value)
TR_TO66_GRND(value)
#end


/********************************************************************************************************************************************
//TO72 metal case
//Joerg Bredendiek <sprut(replace with at)sprut.de>   
//based on TO52 Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
********************************************************************************************************************************************/
#macro TR_TO72_GRND(value,npin)
union{
    //case
    cylinder{<0,0,0><0,3.5-0.3 +1.5 ,0>2.35 pigment{P_Silver3} }                                      
    cylinder{<0,3.5-0.3 +1.5 ,0><0,3.5 +1.5 ,0>2.05 pigment{P_Silver3}}   
    torus{2.05 0.3 pigment {P_Silver3} translate (3.5-0.3 +1.5 )*y}
    torus{2.45 0.3 pigment {P_Silver3} translate 0.3*y}
    cylinder{<0,0,0><0,0.6,0>2.45 pigment{P_Silver3}}   
    box {<-0.5,0,0><0.5,0.6,3.3> pigment{P_Silver3}  translate <0,0,0> rotate <0,-90,0> }
    text {ttf besch_font value 1, 0 pigment { Black } scale <1,1,1> rotate <90,0,0> translate<-1.5,3.52 +1.5 ,-.4>}

    //pins
    #if(npin>=3)
        #if(pin_short=off)
            cylinder{<+1.27, 0, -1.27> <+1.27,-12.7,-1.27> 0.2 pigment{ P_Silver3}}   
            cylinder{<-1.27, 0, -1.27> <-1.27,-12.7,-1.27> 0.2 pigment{ P_Silver3}}  
            cylinder{<-1.27, 0, +1.27> <-1.27,-12.7,+1.27> 0.2 pigment{ P_Silver3}}    
        #else
            cylinder{<+1.27, 0,-1.27> <+1.27,-(pin_length+pcb_height),-1.27> 0.2 pigment{ P_Silver3}}   
            cylinder{<-1.27, 0,-1.27> <-1.27,-(pin_length+pcb_height),-1.27> 0.2 pigment{ P_Silver3}}   
            cylinder{<-1.27, 0,+1.27> <-1.27,-(pin_length+pcb_height),+1.27> 0.2 pigment{ P_Silver3}}   
        #end
    #end

    #if(npin=4)
        #if(pin_short=off)
            cylinder{<+1.27, 0, +1.27> <+1.27,-12.7,+1.27> 0.2 pigment{ P_Silver3}}   
        #else
            cylinder{<+1.27, 0,+1.27> <+1.27,-(pin_length+pcb_height),+1.27> 0.2 pigment{ P_Silver3}}  
        #end
    #end

    }
    translate<0,1,0>
#end

#macro TR_TO72_3(value)
TR_TO72_GRND(value,3)
#end
#macro TR_TO72_4(value)
TR_TO72_GRND(value,4)
#end


/********************************************************************************************************************************************
// Joerg Bredendiek <sprut(replace with at)sprut.de>
// replacement for all TR_TO92 and DIODE_TO92 macros
//
//TO92 & SOT54 packages, vertical
// pin - number of pins (2 or 3)
// L - Pin 1 shift along X
// M - Pin 2 shift along Z
// R - Pin 3 shift along X
// D - Rotation of the whole package around Y
//
//
********************************************************************************************************************************************/
#macro TR_TO92_G_GRND(value, pin, L, M, R, D)
union{
	//lower part of pin
	#if(pin_short=off)
		box{<-0.24,0,-0.22><0.24,10,0.22> translate< L,0,0>}                                      //linker Pin
		#if (pin=3)
		box{<-0.24,0,-0.22><0.24,10,0.22> translate< 0,0,M>}                                      //mittlerer Pin
		#end
		box{<-0.24,0,-0.22><0.24,10,0.22> translate< R,0,0>}                                      //rechter Pin
	#else
		box{<-0.24,9.3-(pcb_height+pin_length),-0.22><0.24,10,0.22> translate< L,0,0>}            //linker Pin
		#if (pin=3)
		box{<-0.24,9.3-(pcb_height+pin_length),-0.22><0.24,10,0.22> translate< 0,0,M>}            //mittlerer Pin
		#end
		box{<-0.24,9.3-(pcb_height+pin_length),-0.22><0.24,10,0.22> translate< R,0,0>}            //rechter Pin
	#end

	// bended middle part of pin
	#local M1=sqrt( (1.5*1.5) + (L+1.27-0.48)*(L+1.27-0.48) );
	#local M2=sqrt( (1.5*1.5) + (M+0.44)*(M+0.44) );
	#local M3=sqrt( (1.5*1.5) + (R-1.27+0.48)*(R-1.27+0.48) );

	#local L1=sqrt((M1*M1) - (0.48*0.48) );
	#local L2=sqrt((M2*M2) - (0.44*0.44) );
	#local L3=sqrt((M3*M3) - (0.48*0.48) );

	#local A1= (asin( (L+1.27-0.48)/M1 ) + asin(0.48/M1) ) / 3.1415 * 180;
	#local A2= (asin( (M+0.44)/M2 )      - asin(0.44/M2) ) / 3.1415 * 180;
	#local A3= (asin( (R-1.27+0.48)/M3 ) - asin(0.48/M3) ) / 3.1415 * 180;

	box{<-0.24,-L1/2,-0.22><0.24,L1/2,0.22> rotate<0,0,A1> translate<(L+1.27)/2-1.27 ,10.75,0>}          //linker Pin Schraege
	#if (pin=3)
 	box{<-0.24,-L2/2,-0.22><0.24,L2/2,0.22> rotate<-A2,0,0> translate< 0,10.75,(M/2)>}                   //mittlerer Pin Schraege
	#end
	box{<-0.24,-L3/2,-0.22><0.24,L3/2,0.22> rotate<0,0, A3> translate<(R-1.27)/2+1.27,10.75,0>}          //rechter Pin Schraege


	// upper part of pin at the housing
	box{<-0.24,11.5,-0.22><0.24,14,0.22> translate<-1.27,0,0>}                                     //linker Pin
	#if (pin=3)
	box{<-0.24,11.5,-0.22><0.24,14,0.22> }                                                         //mittlerer Pin
	#end
	box{<-0.24,11.5,-0.22><0.24,14,0.22> translate< 1.27,0,0>}                                     //rechter Pin

	// wider part of pin close to the housing
	box{<-0.34,12,-0.22><0.34,13,0.22> translate<-1.27,0,0>}                                        //Abstandhalter links
	#if (pin=3)
	box{<-0.34,12,-0.22><0.34,13,0.22> }                                                            //Abstandhalter mitte
	#end
	box{<-0.34,12,-0.22><0.34,13,0.22> translate< 1.27,0,0>}                                        //Abstandhalter rechts

	// plastic body
	difference{                                                                                  //Transistorkoerper
		cylinder{<0,14,0><0,19.2,0>2.4 pigment{ Gray30}translate<0.12,0,0>}
            box{<-3,13.9,-1><3,20,-3> pigment{ Gray30}}}

	// label
	text {ttf besch_font value 1, 0 pigment { White } translate<-1.8,17,-1.01>}                  //Beschriftung

	texture{col_silver}
	translate<0, -9.3, 0>
	rotate<0,D,0>
}
#end

#macro TR_TO92_L(value)
TR_TO92_G_GRND(value, 3, -2.54, 0.00, 2.54, 0)
#end
#macro TR_TO92_G(value)
TR_TO92_G_GRND(value, 3, -1.27, 1.905,1.27, 0)
#end
#macro TR_TO92_G2(value)
TR_TO92_G_GRND(value, 3, -2.54, 2.54, 2.54, 90)
#end
#macro TR_TO92_G3(value)
TR_TO92_G_GRND(value, 3, -2.00, 2.00, 2.00, 0)
#end
#macro TR_TO92_G4(value)
TR_TO92_G_GRND(value, 3, -1.80, 1.80, 1.80, 0)
#end
#macro TR_TO92_G5(value)
TR_TO92_G_GRND(value, 3, -2.18, 2.55, 2.18, 0)
#end
#macro TR_TO92_2(value)
TR_TO92_G_GRND(value, 2, -1.27, 0.00, 1.27, 0)
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
