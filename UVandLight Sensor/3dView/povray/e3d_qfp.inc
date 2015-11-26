//Eagle3D 20110101 INC-File e3d_qfp.inc
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
 
#ifndef(__qfp_inc)
#declare __qfp_inc = true;

#ifndef(inc_testmode)
#declare inc_testmode=true;
#include "e3d_tools.inc"
#undef inc_testmode
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_QFP_PIN.inc.src
// QFP-Pin
// Makro für Pins von QFP-Gehäusen
// H = Höhe des Pins
// B = Breite des Pins
// T = Tiefe des Pins
// S = Materialstärke des Pins
// //////////
#macro QFP_PIN(H,B,T,S)
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
texture{col_silver}}
#end

/********************************************************************************************************************************************
//L     = Länge über alles (x-Achse)
//B     = Breite über alles (z-Achse)
//H     = Höhe des Kunststoff (Y-Achse)
//pin_l = Anzahl Pins links
//pin_r = Anzahl Pins rechts
//pin_o = Anzahl Pins "oben"
//pin_u = Anzahl Pins "unten"
//pitch = Abstand der einzelnen Pins
//pin_br= Breite eines Pins
//pin_h = Stärke des Pinmaterials
//LK    = Länge des Kunststoff (x-Achse)
//BK    = Breite des Kunststoff (z-Achse)
//HKoP  = Höhe des Kunststoffs über der Platine (Y-Achse)
//KORW  = Korrekturwinkel
//kp1ab = Wenn nicht 0 wird keine Abschrägung an Pin1 erzeugt
//logo  = Name of the logo
********************************************************************************************************************************************/
#macro QFP_GRND(L,B,H,pin_l,pin_r,pin_o,pin_u,pitch,pin_br,pin_h,LK,BK,HKoP,KORW,kp1ab,logo)
union{
	difference{
		box{<-LK/2,HKoP,-BK/2><LK/2,HKoP+H,BK/2>}
		box{<-LK/2-0.01,0,0><LK/2+0.01,-2,-1> rotate<-10,0,0> translate<0,HKoP+H/2-pin_h/2,-BK/2>}
		box{<-LK/2-0.01,0,0><LK/2+0.01,-2,1> rotate<10,0,0> translate<0,HKoP+H/2-pin_h/2,BK/2>}
		box{<-LK/2-0.01,0,0><LK/2+0.01,2,1> rotate<-10,0,0> translate<0,HKoP+H/2+pin_h/2,BK/2>}
		box{<-LK/2-0.01,0,0><LK/2+0.01,2,-1> rotate<10,0,0> translate<0,HKoP+H/2+pin_h/2,-BK/2>}
		box{<0,0,-BK/2-0.01><1,2,BK/2+0.01> rotate<0,0,10> translate<LK/2,HKoP+H/2+pin_h/2,0>}
		box{<0,0,-BK/2-0.01><-1,2,BK/2+0.01> rotate<0,0,-10> translate<-LK/2,HKoP+H/2+pin_h/2,0>}
		box{<0,0,-BK/2-0.01><1,-2,BK/2+0.01> rotate<0,0,-10> translate<LK/2,HKoP+H/2-pin_h/2,0>}
		box{<0,0,-BK/2-0.01><-1,-2,BK/2+0.01> rotate<0,0,10> translate<-LK/2,HKoP+H/2-pin_h/2,0>}
		#if(kp1ab=0)
			box{<0,0,-3><-2,5,3> rotate<0,-45,0> translate<-LK/2+LK/40,0,-BK/2+BK/40>}
		#end
		cylinder{<0,H+HKoP-0.1,0><0,H+HKoP+1,0>0.4 translate<-LK/2+LK/10,0,-BK/2+BK/10>}
		pigment{Gray20}
        finish {ambient (0.1 * global_ambient_mul)}
	}
	
	#local i=0;
	#while(i<(pin_l/2))
		#if((pin_l/2)=div(pin_l,2))
			object{QFP_PIN((H+HKoP)/2+pin_h/2,(L-LK)/2,pin_br,pin_h) rotate<0,0,0> translate<LK/2,0,pitch*i+pitch/2>}
			object{QFP_PIN((H+HKoP)/2+pin_h/2,(L-LK)/2,pin_br,pin_h) rotate<0,0,0> translate<LK/2,0,-pitch*i-pitch/2>}
		#else
			object{QFP_PIN((H+HKoP)/2+pin_h/2,(L-LK)/2,pin_br,pin_h) rotate<0,0,0> translate<LK/2,0,pitch*i>}
			object{QFP_PIN((H+HKoP)/2+pin_h/2,(L-LK)/2,pin_br,pin_h) rotate<0,0,0> translate<LK/2,0,-pitch*i>}
		#end
		#local i=i+1;
	#end
	
	#local i=0;
	#while(i<(pin_r/2))
		#if((pin_l/2)=div(pin_l,2))
			object{QFP_PIN((H+HKoP)/2+pin_h/2,(L-LK)/2,pin_br,pin_h) rotate<0,180,0> translate<-LK/2,0,pitch*i+pitch/2>}
			object{QFP_PIN((H+HKoP)/2+pin_h/2,(L-LK)/2,pin_br,pin_h) rotate<0,180,0> translate<-LK/2,0,-pitch*i-pitch/2>}
		#else
			object{QFP_PIN((H+HKoP)/2+pin_h/2,(L-LK)/2,pin_br,pin_h) rotate<0,180,0> translate<-LK/2,0,pitch*i>}
			object{QFP_PIN((H+HKoP)/2+pin_h/2,(L-LK)/2,pin_br,pin_h) rotate<0,180,0> translate<-LK/2,0,-pitch*i>}
		#end
		#local i=i+1;
	#end

	#local i=0;
	#while(i<(pin_u/2))
		#if((pin_l/2)=div(pin_l,2))
			object{QFP_PIN((H+HKoP)/2+pin_h/2,(B-BK)/2,pin_br,pin_h) rotate<0,90,0> translate<pitch*i+pitch/2,0,-BK/2>}
			object{QFP_PIN((H+HKoP)/2+pin_h/2,(B-BK)/2,pin_br,pin_h) rotate<0,90,0> translate<-pitch*i-pitch/2,0,-BK/2>}
		#else
			object{QFP_PIN((H+HKoP)/2+pin_h/2,(B-BK)/2,pin_br,pin_h) rotate<0,90,0> translate<pitch*i,0,-BK/2>}
			object{QFP_PIN((H+HKoP)/2+pin_h/2,(B-BK)/2,pin_br,pin_h) rotate<0,90,0> translate<-pitch*i,0,-BK/2>}
		#end
		#local i=i+1;
	#end

	#local i=0;
	#while(i<(pin_o/2))
		#if((pin_l/2)=div(pin_l,2))
			object{QFP_PIN((H+HKoP)/2+pin_h/2,(B-BK)/2,pin_br,pin_h) rotate<0,-90,0> translate<pitch*i+pitch/2,0,BK/2>}
			object{QFP_PIN((H+HKoP)/2+pin_h/2,(B-BK)/2,pin_br,pin_h) rotate<0,-90,0> translate<-pitch*i-pitch/2,0,BK/2>}
		#else
			object{QFP_PIN((H+HKoP)/2+pin_h/2,(B-BK)/2,pin_br,pin_h) rotate<0,-90,0> translate<pitch*i,0,BK/2>}
			object{QFP_PIN((H+HKoP)/2+pin_h/2,(B-BK)/2,pin_br,pin_h) rotate<0,-90,0> translate<-pitch*i,0,BK/2>}
		#end
		#local i=i+1;
	#end
	
	#local scl_fa = BK/10;
	#local value_arial_size_min = 0.0;
	#local value_arial_size_max = 0.0;
	#local value_arial_size = 0.0;
	#local value_courier_size_min = 0.0;
	#local value_courier_size_max = 0.0;
	#local value_courier_size = 0.0;
	#local value_arial_bold =  text{ttf global_fontfile_arial_bold value 0.2,0 rotate<90,-90,0> pigment{White}}
	#local value_courier_bold = text{ttf global_fontfile_courier_bold value 0.2,0 rotate<90,-90,0> pigment{White}}
	Extents(value_arial_bold, value_arial_size_min, value_arial_size_max)
	Extents(value_courier_bold, value_courier_size_min, value_courier_size_max)
	#local value_arial_size = value_arial_size_max - value_arial_size_min; 
	#local value_courier_size = value_courier_size_max - value_courier_size_min;	
	#local value_scale_factor_arial = BK/value_arial_size.z * 0.7;
	#local value_scale_factor_courier = BK/value_courier_size.z * 0.7;	
	
	#if(value_arial_size.x*value_scale_factor_arial > LK/6.0) 
                #local value_scale_factor_arial = LK/6.0 / value_arial_size.x;	
	#end
	#if(value_courier_size.x*value_scale_factor_courier > LK/6.0) 
                #local value_scale_factor_courier = LK/6.0 / value_courier_size.x;	
	#end
		
	#local value_arial_size = value_arial_size * value_scale_factor_arial; 
	#local value_courier_size = value_courier_size * value_scale_factor_courier;
	//a random datecode string
	#local value_datecode_arial_size_min = 0.0;
	#local value_datecode_arial_size_max = 0.0;
	#local value_datecode_arial_size = 0.0;
	#local value_datecode_courier_size_min = 0.0;
	#local value_datecode_courier_size_max = 0.0;
	#local value_datecode_courier_size = 0.0;
	#local value_datecode_string = concat(str(rand(global_seed)*52.9, -2, 0),str(rand(global_seed)*3.9+2, -2, 0));	
	#local value_datecode_arial_bold = text{ttf global_fontfile_arial_bold value_datecode_string 0.2,0 rotate<90,-90,0> pigment{White}}
	#local value_datecode_courier_bold = text{ttf global_fontfile_arial_bold value_datecode_string 0.2,0 rotate<90,-90,0> pigment{White}}
	Extents(value_datecode_arial_bold, value_datecode_arial_size_min, value_datecode_arial_size_max)
	Extents(value_datecode_courier_bold, value_courier_size_min, value_courier_size_max)
	#local value_datecode_arial_size = value_datecode_arial_size_max - value_datecode_arial_size_min; 
	#local value_datecode_courier_size = value_courier_size_max - value_courier_size_min;	
	#local value_datecode_scale_factor_arial = value_scale_factor_arial;
	#local value_datecode_scale_factor_courier = value_scale_factor_courier;
	#local value_datecode_arial_size = value_datecode_arial_size * value_scale_factor_arial; 
	#local value_datecode_courier_size = value_datecode_courier_size * value_scale_factor_courier;
	
    // added logos Freescale and Microchip
    // by xocas

	#local logo_assigned = 0;
		
	#if(strcmp(logo,"FTDI")=0.0)
	        #local logo_assigned = 1;
		text{ttf global_fontfile_eagle3d "f" 0.2,0 scale<scl_fa*2,scl_fa*2,1> rotate<90,-90,0> translate<-LK/2+LK/3,H+HKoP+0.001,-BK/2+BK/6> pigment{Gray60} }		
		object{value_arial_bold scale<value_scale_factor_arial,1,value_scale_factor_arial> translate<value_arial_size.x/2,H+HKoP+0.001,-value_arial_size.z/2>}
		object{value_datecode_arial_bold scale<value_datecode_scale_factor_arial,1,value_datecode_scale_factor_arial> translate<value_datecode_arial_size.x/2,H+HKoP+0.001,-value_datecode_arial_size.z/2> translate<LK/2-LK/4,0,0>}
	#end
	
	#if(strcmp(logo,"ATMEL")=0.0)
	        #local logo_assigned = 1;
		text{ttf global_fontfile_eagle3d "a" 0.2,0 scale<scl_fa*2,scl_fa*2,1> rotate<90,-90,0> translate<-LK/2+LK/3,H+HKoP+0.001,-BK/7> pigment{Gray60} }		
		object{value_arial_bold pigment{Gray60} scale<value_scale_factor_arial,1,value_scale_factor_arial> translate<value_arial_size.x/2,H+HKoP+0.001,-value_arial_size.z/2>}
		object{value_datecode_arial_bold pigment{Gray60} scale<value_datecode_scale_factor_arial,1,value_datecode_scale_factor_arial> translate<value_datecode_arial_size.x/2,H+HKoP+0.001,-value_datecode_arial_size.z/2> translate<LK/2-LK/4,0,0>}
	#end
	#if(strcmp(logo,"MICROCHIP")=0.0)
	        #local logo_assigned = 1;
		text{ttf global_fontfile_eagle3d "m" 0.2,0 scale<scl_fa*2,scl_fa*2,1> rotate<90,-90,0> translate<-LK/2+LK/3,H+HKoP+0.001,-BK/10> pigment{Gray60} }		
		object{value_arial_bold pigment{Gray60} scale<value_scale_factor_arial,1,value_scale_factor_arial> translate<value_arial_size.x/2,H+HKoP+0.001,-value_arial_size.z/2>}
		object{value_datecode_arial_bold pigment{Gray60} scale<value_datecode_scale_factor_arial,1,value_datecode_scale_factor_arial> translate<value_datecode_arial_size.x/2,H+HKoP+0.001,-value_datecode_arial_size.z/2> translate<LK/2-LK/4,0,0>}
	#end
	#if(strcmp(logo,"FREESCALE")=0.0)
	        #local logo_assigned = 1;
		text{ttf global_fontfile_eagle3d "/" 0.2,0 scale<scl_fa*2,scl_fa*2,1> rotate<90,-90,0> translate<-LK/2+LK/2.8,H+HKoP+0.001,-BK/9> pigment{Gray60} }		
		object{value_arial_bold pigment{Gray60} scale<value_scale_factor_arial,1,value_scale_factor_arial> translate<value_arial_size.x/1.6,H+HKoP+0.001,-value_arial_size.z/2>}
		object{value_datecode_arial_bold pigment{Gray60} scale<value_datecode_scale_factor_arial,1,value_datecode_scale_factor_arial> translate<value_datecode_arial_size.x/2,H+HKoP+0.001,-value_datecode_arial_size.z/2> translate<LK/2-LK/4,0,0>}
	#end
	
	#if(logo_assigned < 0.5)
		text{ttf besch_font value 0.2,0 scale<scl_fa,scl_fa,1> rotate<90,-90,0> translate<-LK/2+LK/4,H+HKoP+0.001,-BK/2+BK/6> pigment{White} }
	#end
	
	rotate<0,KORW,0>
}
#end
//LQFP-64 aus DS80C390 Datasheet
#macro QFP_LQFP_64_050MM(value,logo)
QFP_GRND(12,12,1.4,16,16,16,16,0.5,0.22,0.15,10,10,0.1,0,0,logo)
#end
//TQFP-32 Maße von www.altera.com
#macro QFP_TQFP_32_080MM(value,logo)
QFP_GRND(9,9,1.17,8,8,8,8,0.8,0.37,0.15,7,7,0.1,90,0,logo)
#end
//TQFP-44 Maße von www.altera.com
#macro QFP_TQFP_44_080MM(value,logo)
QFP_GRND(12,12,1.17,11,11,11,11,0.8,0.37,0.15,10,10,0.1,90,0,logo)
#end
//PQFP-48
#macro QFP_PQFP_48_050MM(value,logo)
QFP_GRND(9,9,3.4,12,12,12,12,0.5,0.22,0.1,7,7,0.22,90,0,logo)
#end
//LQFP-48 aus FT2232 Datasheet                                       
#macro QFP_LQFP_48_050MM(value,logo)
QFP_GRND(9,9,1.1,12,12,12,12,0.5,0.22,0.1,7,7,0.22,90,0,logo)
#end
#macro QFP_TQFP_64_080MM(value,logo)
QFP_GRND(16,16,1.2,16,16,16,16,0.8,0.35,0.15,14,14,0.1,90,0,logo)
#end
//TQFP-100 Maße von www.altera.com
#macro QFP_TQFP_100_050MM(value,logo)
QFP_GRND(16,16,1.17,25,25,25,25,0.5,0.22,0.15,14,14,0.1,90,0,logo)
#end
//TQFP-144 Maße von www.altera.com
#macro QFP_TQFP_144_050MM(value,logo)
QFP_GRND(22,22,1.17,36,36,36,36,0.5,0.22,0.15,20,20,0.1,90,0,logo)
#end
//PQFP-44 Maße von www.altera.com
#macro QFP_PQFP_44_080MM(value,logo)
QFP_GRND(13.2,13.2,2,11,11,11,11,0.8,0.37,0.1,10,10,0.2,90,0,logo)
#end
//PQFP-100 Maße von www.altera.com
#macro QFP_PQFP_100_065MM(value,logo)
QFP_GRND(24.3,18.3,1.95,20,20,30,30,0.65,0.3,0.1,21,15,0.15,90,0,logo)
#end
//PQFP-160 Maße von www.altera.com
#macro QFP_PQFP_160_065MM(value,logo)
QFP_GRND(31.2,31.1,3.4,40,40,40,40,0.65,0.3,0.1,28,28,0.32,90,0,logo)
#end
//PQFP-208 Maße von www.altera.com
#macro QFP_PQFP_208_050MM(value,logo)
QFP_GRND(30.8,30.8,3.4,52,52,52,52,0.5,0.22,0.1,28,28,0.32,90,0,logo)
#end
//PQFP-240 Maße von www.altera.com
#macro QFP_PQFP_240_050MM(value,logo)
QFP_GRND(34.5,34.5,3.4,60,60,60,60,0.5,0.22,0.1,32,32,0.32,90,0,logo)
#end
//SQFP-R-14X20-100 Maße von M16C/62 Gehäuse QFP100-P-1420-0.65
#macro QFP_SQFP_R_14X20_100_065MM(value,logo)
QFP_GRND(22.8,16.8,2.8,20,20,30,30,0.65,0.3,0.15,20,14,0.1,0,1,logo)
#end
// Philips LPC2148 SQFP-S-10X10-64
#macro QFP_SQFP_S_10X10_64_050MM(value,logo)
QFP_GRND(12.0,12.0,2.8,16,16,16,16,0.5,0.22,0.15,10,10,0.1,0,1,logo)
#end
//PQFP-128 Maße von www.micrel.com
#macro QFP_PQFP_128_050MM(value,logo)
QFP_GRND(23.2,17.2,3.4,26,26,38,38,0.50,0.22,0.1,20,14,0.1,0,1,logo)
#end
//TQFP-112
#macro QFP_TQFP_112_065MM(value,logo)
QFP_GRND(22,22,1.6,28,28,28,28,0.65,0.37,0.15,20,20,0.15,90,0,logo)
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
