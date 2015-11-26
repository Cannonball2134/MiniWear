//Eagle3D 20110101 INC-File e3d_socket.inc
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
 
#ifndef(__socket_inc)
#declare __socket_inc = true;

#ifndef(inc_testmode)
#declare inc_testmode=true;
#include "e3d_tools.inc" 
#undef inc_testmode
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_SOCKET_DIP_PIN.inc.src
// Sockel Pin
// //////////
#macro SOCKET_DIP_PIN()
difference{
union{
cylinder{<0,0,0><0,2.95,0>0.25}
sphere{<0,0,0>0.25}
cone{<0,2.95,0>0.25<0,3.45,0>0.6}
cylinder{<0,3.45,0><0,7.15,0>0.6}
cylinder{<0,6.4,0><0,7.15,0>0.85}}
cylinder{<0,4,0><0,7.16,0>0.5}
texture{col_silver}}
#end

/********************************************************************************************************************************************
// The following is a modified module section by Joseph Zeglinski   Aug. 20, 2003

// This macro now produces either a fully pin populated DIL SOCKET,  or a DIL SOCKET with fewer "quads" of pins.
// Example: Some IC's, FET's, Optoisolators and Crystal Oscillators - (8, 14, 16, or 24) pin body, with only 4, 6 or 12 outer pins.
// The " a= Available Pins" parameter is how many pins (modulo 4), are present on the intended DIL SOCKET.


//Grundmakro für DIL SOCKETS
//pin=Pincount of a full DIL
//a=Count of available pin positions, ( less than or equal to "pin" )
//breite=breite (in Raster)
********************************************************************************************************************************************/
#macro SOCKET_DIP_GRND(pin,a,breite)
union{
	difference{
		union{
			box{<-pin/4*2.54,0,breite/2+1.2><pin/4*2.54,2.8,breite/2-1.2>}
			box{<-pin/4*2.54,0,-breite/2-1.2><pin/4*2.54,2.8,-breite/2+1.2>}
		}
		#local i=0;
		#while(i<(a/4))
			#if((pin/4)=div(pin,4))
    			#local k = div(pin,4)-i-1;
				cylinder{<0,-0.1,0><0,8,0>0.51 translate<k*2.54+1.27,-7.15+2.9,breite/2>}
				cylinder{<0,-0.1,0><0,8,0>0.51 translate<-k*2.54-1.27,-7.15+2.9,breite/2>}
				cylinder{<0,-0.1,0><0,8,0>0.51 translate<k*2.54+1.27,-7.15+2.9,-breite/2>}
				cylinder{<0,-0.1,0><0,8,0>0.51 translate<-k*2.54-1.27,-7.15+2.9,-breite/2>}
			#else
				#local k = div(pin,4)-i;
				cylinder{<0,-0.1,0><0,8,0>0.51 translate<k*2.54,-7.15+2.9,breite/2>}
				cylinder{<0,-0.1,0><0,8,0>0.51 translate<-k*2.54,-7.15+2.9,breite/2>}
				cylinder{<0,-0.1,0><0,8,0>0.51 translate<k*2.54,-7.15+2.9,-breite/2>}
				cylinder{<0,-0.1,0><0,8,0>0.51 translate<-k*2.54,-7.15+2.9,-breite/2>}
			#end
			#local i=i+1;
		#end
	}
	#local i=0;
	#while(i<(a/4))
		#if((pin/4)=div(pin,4))
			#local k = div(pin,4)-i-1;
			object{SOCKET_DIP_PIN() translate<k*2.54+1.27,-7.15+2.9,breite/2>}
			object{SOCKET_DIP_PIN() translate<-k*2.54-1.27,-7.15+2.9,breite/2>}
			object{SOCKET_DIP_PIN() translate<k*2.54+1.27,-7.15+2.9,-breite/2>}
			object{SOCKET_DIP_PIN() translate<-k*2.54-1.27,-7.15+2.9,-breite/2>}
		#else
			#local k = div(pin,4)-i;
			object{SOCKET_DIP_PIN() translate<k*2.54,-7.15+2.9,breite/2>}
			object{SOCKET_DIP_PIN() translate<-k*2.54,-7.15+2.9,breite/2>}
			object{SOCKET_DIP_PIN() translate<k*2.54,-7.15+2.9,-breite/2>}
			object{SOCKET_DIP_PIN() translate<-k*2.54,-7.15+2.9,-breite/2>}
		#end
		#local i=i+1;
	#end
	difference{
		box{<-pin/4*2.54,0,breite/2-1.2><-pin/4*2.54+2,2,-breite/2+1.2>}
		cylinder{<0,-0.1,0><0,3,0>1 translate<-pin/4*2.54-0.4,0,0>}
	}
	box{<pin/4*2.54,0,breite/2-1.2><pin/4*2.54-2,2,-breite/2+1.2>}
	#if((pin>19)&(pin<33))
		box{<-1,0,breite/2-1.2><1,2,-breite/2+1.2>}
	#end
	#if(pin>32)
		box{<-pin/12*2.54+1,0,breite/2-1.2><-pin/12*2.54-1,2,-breite/2+1.2>}
		box{<pin/12*2.54+1,0,breite/2-1.2><pin/12*2.54-1,2,-breite/2+1.2>}
	#end
	translate<0,0.1,0> 
	pigment{Gray10}
}
#end

//DIP8 with 4 corner pin sockets
#macro SOCKET_DIP8A4()
SOCKET_DIP_GRND(8,4,7.62)
#end
//DIP14 with 4 corner pin sockets
#macro SOCKET_DIP14A4()
SOCKET_DIP_GRND(14,4,7.62)
#end
//DIP14 with 8 corner pin sockets
#macro SOCKET_DIP14A8()
SOCKET_DIP_GRND(14,8,7.62)
#end
//DIP16 with 4 corner pin sockets
#macro SOCKET_DIP16A4()
SOCKET_DIP_GRND(16,4,7.62)
#end
//DIP16 with 8 corner pin sockets
#macro SOCKET_DIP16A8()
SOCKET_DIP_GRND(16,8,7.62)
#end
//DIP24 with 12 corner pin sockets
#macro SOCKET_DIP24A12()
SOCKET_DIP_GRND(24,12,7.62)
#end
#macro SOCKET_DIP2()
SOCKET_DIP_GRND(2,2,7.62)
#end
#macro SOCKET_DIP4()
SOCKET_DIP_GRND(4,4,7.62)
#end
#macro SOCKET_DIP6()
SOCKET_DIP_GRND(6,6,7.62)
#end
#macro SOCKET_DIP6_4()
SOCKET_DIP_GRND(6,6,10.16)
#end
#macro SOCKET_DIP8()
SOCKET_DIP_GRND(8,8,7.62)
#end
#macro SOCKET_DIP14()
SOCKET_DIP_GRND(14,14,7.62)
#end
#macro SOCKET_DIP16()
SOCKET_DIP_GRND(16,16,7.62)
#end
#macro SOCKET_DIP18()
SOCKET_DIP_GRND(18,18,7.62)
#end
#macro SOCKET_DIP20()
SOCKET_DIP_GRND(20,20,7.62)
#end
#macro SOCKET_DIP22()
SOCKET_DIP_GRND(22,22,7.62)
#end
#macro SOCKET_DIP22_4()
SOCKET_DIP_GRND(22,22,10.16)
#end
#macro SOCKET_DIP24()
SOCKET_DIP_GRND(24,24,7.62)
#end
#macro SOCKET_DIP24_4()
SOCKET_DIP_GRND(24,24,10.16)
#end
#macro SOCKET_DIP24W()
SOCKET_DIP_GRND(24,24,15.24)
#end
#macro SOCKET_DIP24_9()
SOCKET_DIP_GRND(24,24,22.86)
#end
#macro SOCKET_DIP28()
SOCKET_DIP_GRND(28,28,7.62)
#end
#macro SOCKET_DIP28_4()
SOCKET_DIP_GRND(28,28,10.16)
#end
#macro SOCKET_DIP28W()
SOCKET_DIP_GRND(28,28,15.24)
#end
#macro SOCKET_DIP32_3()
SOCKET_DIP_GRND(32,32,7.62)
#end
#macro SOCKET_DIP32W()
SOCKET_DIP_GRND(32,32,15.24)
#end
#macro SOCKET_DIP36W()
SOCKET_DIP_GRND(36,36,15.24)
#end
#macro SOCKET_DIP40W()
SOCKET_DIP_GRND(40,40,15.24)
#end
#macro SOCKET_DIP42W()
SOCKET_DIP_GRND(42,42,15.24)
#end
#macro SOCKET_DIP48W()
SOCKET_DIP_GRND(48,48,15.24)
#end
#macro SOCKET_DIP52W()
SOCKET_DIP_GRND(52,52,15.24)
#end
#macro SOCKET_DIP64_9()
SOCKET_DIP_GRND(64,64,22.86)
#end
#macro SOCKET_DIP68_9()
SOCKET_DIP_GRND(68,68,22.86)
#end


/********************************************************************************************************************************************
//B    = Breite (Z-Achse)
//pin_l= Pins auf einer L-Seite
//pin_b= Pins auf einer B-Seite
//Li   = Länge innen
//Bi   = Breite innen
//totalPins= Anzahl der Pins komplett
//pincL= Korrektur für Pinausrichtung auf L-Seite
//pincB= Korrektur für Pinausrichtung auf L-Seite
//chip = Der Chip für den Sockel
********************************************************************************************************************************************/
#macro SOCKET_PLCC_GRND(L,B,pin_l,pin_b,Li,Bi,totalPins,pincL,pincB,chip)

#local plcc20_pina = array[13][13]
{
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,2,1,1,1,2,0,0,0,0}
        {0,0,0,0,1,1,1,1,1,0,0,0,0}
        {0,0,0,0,1,1,0,1,1,0,0,0,0}
        {0,0,0,0,1,1,1,1,1,0,0,0,0}
        {0,0,0,0,2,1,1,1,2,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
}

#local plcc28_pina = array[13][13]
{
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,2,1,1,1,1,2,0,0,0}
        {0,0,0,0,1,1,1,1,1,1,0,0,0}
        {0,0,0,0,1,1,0,0,1,1,0,0,0}
        {0,0,0,0,1,1,0,0,1,1,0,0,0}
        {0,0,0,0,1,1,1,1,1,1,0,0,0}
        {0,0,0,0,2,1,1,1,1,2,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
}//Korrektur -1.27,-1.27

#local plcc32_pina = array[13][13]
{
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,2,1,1,1,1,2,0,0,0}
        {0,0,0,0,1,1,1,1,1,1,0,0,0}
        {0,0,0,0,1,1,0,0,1,1,0,0,0}
        {0,0,0,0,1,1,0,0,1,1,0,0,0}
        {0,0,0,0,1,1,0,0,1,1,0,0,0}
        {0,0,0,0,1,1,1,1,1,1,0,0,0}
        {0,0,0,0,2,1,1,1,1,2,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
}//Korrektur -1.27,0

#local plcc44_pina = array[13][13]
{
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,2,1,1,1,1,1,1,2,0,0}
        {0,0,0,1,1,1,1,1,1,1,1,0,0}
        {0,0,0,1,1,0,0,0,0,1,1,0,0}
        {0,0,0,1,1,0,0,0,0,1,1,0,0}
        {0,0,0,1,1,0,0,0,0,1,1,0,0}
        {0,0,0,1,1,0,0,0,0,1,1,0,0}
        {0,0,0,1,1,1,1,1,1,1,1,0,0}
        {0,0,0,2,1,1,1,1,1,1,2,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
}//Korrektur -1.27,-1.27

#local plcc52_pina = array[13][13]
{
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,2,1,1,1,1,1,1,1,2,0,0}
        {0,0,1,1,1,1,1,1,1,1,1,0,0}
        {0,0,1,1,0,0,0,0,0,1,1,0,0}
        {0,0,1,1,0,0,0,0,0,1,1,0,0}
        {0,0,1,1,0,0,0,0,0,1,1,0,0}
        {0,0,1,1,0,0,0,0,0,1,1,0,0}
        {0,0,1,1,0,0,0,0,0,1,1,0,0}
        {0,0,1,1,1,1,1,1,1,1,1,0,0}
        {0,0,2,1,1,1,1,1,1,1,2,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
}

#local plcc68_pina = array[13][13]
{
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
        {0,2,1,1,1,1,1,1,1,1,1,2,0}
        {0,1,1,1,1,1,1,1,1,1,1,1,0}
        {0,1,1,0,0,0,0,0,0,0,1,1,0}
        {0,1,1,0,0,0,0,0,0,0,1,1,0}
        {0,1,1,0,0,0,0,0,0,0,1,1,0}
        {0,1,1,0,0,0,0,0,0,0,1,1,0}
        {0,1,1,0,0,0,0,0,0,0,1,1,0}
        {0,1,1,0,0,0,0,0,0,0,1,1,0}
        {0,1,1,0,0,0,0,0,0,0,1,1,0}
        {0,1,1,1,1,1,1,1,1,1,1,1,0}
        {0,2,1,1,1,1,1,1,1,1,1,2,0}
        {0,0,0,0,0,0,0,0,0,0,0,0,0}
}

#local plcc84_pina = array[13][13]
{
        {2,1,1,1,1,1,1,1,1,1,1,1,2}
        {1,1,1,1,1,1,1,1,1,1,1,1,1}
        {1,1,0,0,0,0,0,0,0,0,0,1,1}
        {1,1,0,0,0,0,0,0,0,0,0,1,1}
        {1,1,0,0,0,0,0,0,0,0,0,1,1}
        {1,1,0,0,0,0,0,0,0,0,0,1,1}
        {1,1,0,0,0,0,0,0,0,0,0,1,1}
        {1,1,0,0,0,0,0,0,0,0,0,1,1}
        {1,1,0,0,0,0,0,0,0,0,0,1,1}
        {1,1,0,0,0,0,0,0,0,0,0,1,1}
        {1,1,0,0,0,0,0,0,0,0,0,1,1}
        {1,1,1,1,1,1,1,1,1,1,1,1,1}
        {2,1,1,1,1,1,1,1,1,1,1,1,2}
}

#switch(totalPins)
  #case (20)
    #local pinar = plcc20_pina;
  #break
  #case (28)
    #local pinar = plcc28_pina;
  #break
  #case (32)
    #local pinar = plcc32_pina;
  #break
  #case (44)
    #local pinar = plcc44_pina;
  #break
  #case (52)
    #local pinar = plcc52_pina;
  #break
  #case (68)
    #local pinar = plcc68_pina;
  #break
  #case (84)
    #local pinar = plcc84_pina;
  #break  
  #else
    #local pinar = plcc20_pina;
#end

union{
	difference{
		union{
			box{<-L/2,0.6,-B/2+2><L/2,7.5,B/2-2>}
			box{<-L/2+2,0.6,-B/2><L/2-2,7.5,B/2>}
			cylinder{<-L/2+2,0.6,-B/2+2><-L/2+2,7.5,-B/2+2>,2}
			cylinder{<L/2-2,0.6,-B/2+2><L/2-2,7.5,-B/2+2>,2}
			cylinder{<-L/2+2,0.6,B/2-2><-L/2+2,7.5,B/2-2>,2}
			cylinder{<L/2-2,0.6,B/2-2><L/2-2,7.5,B/2-2>,2}
		}
		box{<-Li/2,2.6,-Bi/2><Li/2,7.6,Bi/2>}
		box{<sqrt(pow(L,2)+pow(B,2))/2-2.5,2.61,-0.8><-sqrt(pow(L,2)+pow(B,2))/2+2.5,7.6,0.8> rotate<0,-45,0>}
		
		#local i=0;
		#while (i<pin_l)
			box{<-0.3,2.61,0><0.3,7.6,-3> translate<1.27*i/2,0,Bi/2+2>}
			#if(i!=0) 
				box{<-0.3,2.61,0><0.3,7.6,-3> translate<-1.27*i/2,0,Bi/2+2>} 
			#end
			box{<-0.3,2.61,0><0.3,7.6,3> translate<1.27*i/2,0,-Bi/2-2>}
			#if(i!=0) 
				box{<-0.3,2.61,0><0.3,7.6,3> translate<-1.27*i/2,0,-Bi/2-2>} 
			#end
			#local i=i+2;
		#end
		
		#local i=0;
		#while (i<pin_b)
			box{<-3,2.61,0.3><0,7.6,-0.3> translate<Li/2+2,0,1.27*i/2>}
			#if(i!=0)
				box{<-3,2.61,0.3><0,7.6,-0.3> translate<Li/2+2,0,-1.27*i/2>} 
			#end
			box{<3,2.61,0.3><0,7.6,-0.3> translate<-Li/2-2,0,1.27*i/2>}
			#if(i!=0) 
				box{<3,2.61,0.3><0,7.6,-0.3> translate<-Li/2-2,0,-1.27*i/2>} 
			#end
			#local i=i+2;
		#end
		cylinder{<0,0,0><0,4,0>1.5}
		box{<-3,0,0><3,7.6,3> rotate<0,-45,0> translate<-L/2+1,0,B/2-1>}
		box{<-1,2.61,-1><1,7.6,1> rotate<0,-45,0> translate<-L/2+2.5,0,B/2-2.5>}
		box{<-1,2.61,-1><1,7.6,1> rotate<0,-45,0> translate<L/2-2,0,-B/2+2>}
	}
	box{<-1,1.5,0><1,7.5,1> rotate<0,-45,0> translate<-Li/2+0.5,0,Bi/2-0.5>}
	//Innere Kontaktfedern
	#local i=0;
	#while (i<pin_l)
		cylinder{<-0.25,5.5,Bi/2+1><0.25,5.5,Bi/2+1>0.8 texture{col_silver} translate<1.27*i/2,0,0>}
		#if(i!=0) 
			cylinder{<-0.25,5.5,Bi/2+1><0.25,5.5,Bi/2+1>0.8 texture{col_silver} translate<-1.27*i/2,0,0>} 
		#end
		cylinder{<-0.25,5.5,-Bi/2-1><0.25,5.5,-Bi/2-1>0.8 texture{col_silver} translate<1.27*i/2,0,0>}
		#if(i!=0) 
			cylinder{<-0.25,5.5,-Bi/2-1><0.25,5.5,-Bi/2-1>0.8 texture{col_silver} translate<-1.27*i/2,0,0>} 
		#end
		#local i=i+2;
	#end
	#local i=0;
	#while (i<pin_b)
		cylinder{<Li/2+1,5.5,-0.25><Li/2+1,5.5,0.25>0.8 texture{col_silver} translate<0,0,1.27*i/2>}
		#if(i!=0)
			cylinder{<Li/2+1,5.5,-0.25><Li/2+1,5.5,0.25>0.8 texture{col_silver} translate<0,0,-1.27*i/2>} 
		#end
		cylinder{<-Li/2-1,5.5,-0.25><-Li/2-1,5.5,0.25>0.8 texture{col_silver} translate<0,0,1.27*i/2>}
		#if(i!=0) 
			cylinder{<-Li/2-1,5.5,-0.25><-Li/2-1,5.5,0.25>0.8 texture{col_silver} translate<0,0,-1.27*i/2>} 
		#end
	#local i=i+2;
	#end
	//Pinplatzierung per Arrays
	union{
		#local i=-6;
		#while(i<7)
        	#local j=-6;
        	#while(j<7)
        		#if (pinar[i+6][j+6]=1)
        			box{<-0.25,0.6,-0.1><0.25,-3,0.1> texture{col_silver} translate<j*2.54,0,i*2.54>}
        		#end
        		#if (pinar[i+6][j+6]=2)
        			cylinder{<0,0.05,0><0,0.6,0>1 translate<j*2.54,0,i*2.54>}
        		#end
        	#local j=j+1;
        	#end
		#local i=i+1;
		#end
	object{chip translate<0,3.5,0> translate<-pincL,0,-pincB>}
	translate<pincL,0,pincB>}
	pigment{Gray40}
}
#end


#macro SOCKET_PLCC20(value)
SOCKET_PLCC_GRND(15.5,15.5,5,5,9,9,20,0,0,IC_SMD_PLCC20(value))
#end
#macro SOCKET_PLCC28(value)
SOCKET_PLCC_GRND(18,18,7,7,11.5,11.5,28,-1.27,-1.27,IC_SMD_PLCC28(value))
#end
#macro SOCKET_PLCC32(value)
SOCKET_PLCC_GRND(18,22.34,7,9,11.5,14,32,-1.27,0,IC_SMD_PLCC32(value))
#end
#macro SOCKET_PLCC44(value)
SOCKET_PLCC_GRND(23.6,23.6,11,11,16.5,16.4,44,-1.27,-1.27,IC_SMD_PLCC44(value))
#end
#macro SOCKET_PLCC52(value)
SOCKET_PLCC_GRND(25.9,25.9,13,13,19.2,19.2,52,0,0,IC_SMD_PLCC52(value))
#end
#macro SOCKET_PLCC68(value)
SOCKET_PLCC_GRND(31.8,31.8,16,16,24.1,24.1,68,0,0,IC_SMD_PLCC68(value))
#end
#macro SOCKET_PLCC84(value)
SOCKET_PLCC_GRND(36.7,36.7,21,21,29.3,29.3,84,0,0,IC_SMD_PLCC84(value))
#end


/********************************************************************************************************************************************
// Eagle3D-Makro for TEXTOOL-Socket,   keine eagle-library,         Joerg Bredendiek <sprut(replace with at)sprut.de>   
// lever actuated zero insertion force mechanism,  con-3m.lbr

// based of SOCKET_DIP_GRND from Joseph Zeglinski
// TEXTOOL-Sockel mit 15.24mm Reihenabstand erhalten automatisch breite Kontaktfedern

//Basemakro for TEXTOOL SOCKETS
//pin    = number of pins
//breite = interspace between the lines of pins in mm
********************************************************************************************************************************************/
#macro SOCKET_TEX_GRND(pin,breite)
/********************************************************************************************************************************************
//Philips screw for Textool-Socket
//Kreuzschraube fuer Textool-Sockel
********************************************************************************************************************************************/
#macro TEXSOCKET_SCREWHEAD_CROSS()
#local w = RRand(0,89,1);
difference{
	superellipsoid{<1,0.1> rotate<90,0,0> scale<1.4,0.5,1.4> translate<0,0,0>}
	box{<0.25,0,-1><-0.25,1,1>rotate<0, w,   0> translate<0,0,0>}
	box{<0.25,0,-1><-0.25,1,1>rotate<0, w+90,0> translate<0,0,0>}
	texture{col_silver}
}
#end
/********************************************************************************************************************************************
//Textool-Socket Pin
********************************************************************************************************************************************/
#macro TEXSOCKET_DIP_PIN()
box{<-0.2,0,-0.45><0.2,7,0.45> texture{col_silver}}
#end
/********************************************************************************************************************************************
//Textool-Socket Contakt
********************************************************************************************************************************************/
#macro TEXSOCKET_CONT()
union{
	box{<-0.0,5,-breite/4.4><0.1,10,breite/4.4>}
	box{< 0.2,5,-breite/4.4><0.3,10,breite/4.4>}
	texture{col_silver}
}
#end
/********************************************************************************************************************************************

********************************************************************************************************************************************/

#local texcolor = color red 0.15 green 0.5 blue 0.4;	//typical green color of the plastic body
union{
	#local links=-pin/4*2.54-8.73;	//linker gehaeuserand (mit hebel)  10.5mm vom pin  10-1.27=8.73
	#local rechts=pin/4*2.54+5.73;	//rechter gehaeuserand 7 mm vom pin 7-1.27=5.73
	#local a=pin;
        #local srand = 3.8;		//seitenrand , Abstand vom Pin zum Gehauserand
        #if(breite>20) 
                #local srand = (33-breite) / 2;
                #local links =-pin/4*2.54-11.36;
                #local rechts= pin/4*2.54+7.36;
                // beim 40WW (240-3639-00-0602J) ist das Gehäuse etwas kürzer
                #if(pin=40) 
                        #local links  = -35.5;
                        #local rechts = 31;
                #end
        #end
	// beim 48W (248-1282-00-0602J) ist das Gehäuse um ca 2,5 mm in Richtung zum Hebel verschoben
        #if(pin=48) 
                #local links  = links - 2.5;
                #local rechts = rechts - 2.5;
        #end

	difference{
		union{
			// der gruene grundkoerper
			// Länge: 2.54*pin/2 + 14.63
			// Breite:  15.00=7.62+2x3.7   22.75=15.24+2x3.7
			// Hoehe:   11.50

			box{<links+1, 0, -breite/2-srand>  <rechts-1, 11.8  ,breite/2+srand>}
			box{<links,   0, -breite/2-srand+1>  <rechts, 11.8  ,breite/2+srand-1>}
			cylinder{<0,0,0><0,11.8,0>1 translate<links+1 , 0,  breite/2+srand-1>}
			cylinder{<0,0,0><0,   7,0>1 translate<links+1 , 0, -breite/2-srand+1>}
			cylinder{<0,0,0><0,11.8,0>1 translate<rechts-1, 0,  breite/2+srand-1>}
			cylinder{<0,0,0><0,11.8,0>1 translate<rechts-1, 0, -breite/2-srand+1>}

                        // Beschriftung      
                        text{ttf besch_font "3M" 0.5,0.1*x scale<3,4,1>  rotate<90,0,0> rotate<0,-90,0> translate<links+8,12,-2>}
		}
                // diferent width of the contacts (slots)
		#local ii=0;
		#if(breite>10) 
			#local ii=2;
		#end
		#if(breite>20) 
			#local ii=4.5;
		#end
		// die Ausspartung fuer den Hebel
		box{<links-1, 5, -breite/2-srand+2><links+6, 12 ,-breite/2-srand-2>}
		// Vertiefungen
		box{<-pin/4*2.54, 2, -breite/4><pin/4*2.54, 3, breite/4> translate<0, 9,  breite/2-ii>} 
		box{<-pin/4*2.54, 2, -breite/4><pin/4*2.54, 3, breite/4> translate<0, 9, -breite/2+ii>} 
		//loecher fuer die schrauben
		cylinder{<0,0,0><0,13,0>1.6 translate<links +2,0,0>}
		cylinder{<0,0,0><0,13,0>1.6 translate<rechts-2,0,0>}
		// fuer jedes Pin ein schlitz im Grundkoerper
		// Breite 1.4mm, Laenge 7mm=15,24/2.2 oder 3.5mm=7,62/2,2
		// Verschiebung breiter schlitze ist 2mm geringer
		#local i=0;
		#while(i<(a/4))
			#if((pin/4)=div(pin,4))	// pinzahl durch 4 teilbar
    			#local k = div(pin,4)-i-1;
				box{<-0.7,-0,-breite/4.4><0.7,15,breite/4.4> translate< k*2.54+1.27,-7.15+2.9+9, breite/2-ii>}
				box{<-0.7,-0,-breite/4.4><0.7,15,breite/4.4> translate<-k*2.54-1.27,-7.15+2.9+9, breite/2-ii>}
				box{<-0.7,-0,-breite/4.4><0.7,15,breite/4.4> translate< k*2.54+1.27,-7.15+2.9+9,-breite/2+ii>}
				box{<-0.7,-0,-breite/4.4><0.7,15,breite/4.4> translate<-k*2.54-1.27,-7.15+2.9+9,-breite/2+ii>}
			#else			// pinzahl nicht durch 4 teilbar
				#local k = div(pin,4)-i;
				box{<-0.7,-0,-breite/4.4><0.7,15,breite/4.4> translate< k*2.54,-7.15+2.9+9, breite/2-ii>}
				box{<-0.7,-0,-breite/4.4><0.7,15,breite/4.4> translate<-k*2.54,-7.15+2.9+9, breite/2-ii>}
				box{<-0.7,-0,-breite/4.4><0.7,15,breite/4.4> translate< k*2.54,-7.15+2.9+9,-breite/2+ii>}
				box{<-0.7,-0,-breite/4.4><0.7,15,breite/4.4> translate<-k*2.54,-7.15+2.9+9,-breite/2+ii>}
			#end
			#local i=i+1;
		#end
		pigment{texcolor}
	} //difference fuer den gruenen plastik-koerper endet hier

	// der Hebel
	union{
		cylinder{<  0,0,0><  0,0,3>0.8 texture{col_silver}} 
		sphere{<    0,0,0>0.8 texture{col_silver}} 
		cylinder{<  0,0,0><-14,0,0>0.8 texture{col_silver}} 
		cylinder{<-14,0,0><-16.5,0,0>2.4 pigment{texcolor}}
		sphere{<-14,0,0>2.4 pigment{texcolor}} 
		sphere{<-16.5,0,0>2.4 pigment{texcolor}} 
		translate<links+5, 7, -breite/2-srand+1>
	}

	//schrauben  Durchmesser 3mm, kreuz mit 2mm
	object{TEXSOCKET_SCREWHEAD_CROSS() translate<links+2 , 11,0>}
	object{TEXSOCKET_SCREWHEAD_CROSS() translate<rechts-2, 11,0>}

	//kontaktfedern
	#local i=0;
	#while(i<(a/4))
		#if((pin/4)=div(pin,4))	// pinzahl durch 4 teilbar
   			#local k = div(pin,4)-i-1;
			object{TEXSOCKET_CONT() translate< k*2.54+1.27, 0 ,breite/2-ii>}
			object{TEXSOCKET_CONT() translate<-k*2.54-1.27, 0, breite/2-ii>}
			object{TEXSOCKET_CONT() translate< k*2.54+1.27, 0,-breite/2+ii>}
			object{TEXSOCKET_CONT() translate<-k*2.54-1.27, 0,-breite/2+ii>}
		#else			// pinzahl nicht durch 4 teilbar
			#local k = div(pin,4)-i;
			object{TEXSOCKET_CONT() translate< k*2.54, 0 ,breite/2-ii>}
			object{TEXSOCKET_CONT() translate<-k*2.54, 0, breite/2-ii>}
			object{TEXSOCKET_CONT() translate< k*2.54, 0,-breite/2+ii>}
			object{TEXSOCKET_CONT() translate<-k*2.54, 0,-breite/2+ii>}
		#end
		#local i=i+1;
	#end

	// nun die pins, in Form flacher Blechstreifen
	#local i=0;
	#while(i<(a/4))
		#if((pin/4)=div(pin,4))
			#local k = div(pin,4)-i-1;
			object{TEXSOCKET_DIP_PIN() translate<k*2.54+1.27,-7.15+2.9,breite/2>}
			object{TEXSOCKET_DIP_PIN() translate<-k*2.54-1.27,-7.15+2.9,breite/2>}
			object{TEXSOCKET_DIP_PIN() translate<k*2.54+1.27,-7.15+2.9,-breite/2>}
			object{TEXSOCKET_DIP_PIN() translate<-k*2.54-1.27,-7.15+2.9,-breite/2>}
		#else
			#local k = div(pin,4)-i;
			object{TEXSOCKET_DIP_PIN() translate<k*2.54,-7.15+2.9,breite/2>}
			object{TEXSOCKET_DIP_PIN() translate<-k*2.54,-7.15+2.9,breite/2>}
			object{TEXSOCKET_DIP_PIN() translate<k*2.54,-7.15+2.9,-breite/2>}
			object{TEXSOCKET_DIP_PIN() translate<-k*2.54,-7.15+2.9,-breite/2>}
		#end
		#local i=i+1;
	#end
	translate<0,0.1,0> 
}
#end


#macro SOCKET_TEX14()
SOCKET_TEX_GRND(14,7.62)
#end
#macro SOCKET_TEX16()
SOCKET_TEX_GRND(16,7.62)
#end
#macro SOCKET_TEX18()
SOCKET_TEX_GRND(18,7.62)
#end
#macro SOCKET_TEX20()
SOCKET_TEX_GRND(20,7.62)
#end
#macro SOCKET_TEX22()
SOCKET_TEX_GRND(22,10.16)
#end
#macro SOCKET_TEX24()
SOCKET_TEX_GRND(24,7.62)
#end
#macro SOCKET_TEX24W()
SOCKET_TEX_GRND(24,15.24)
#end
#macro SOCKET_TEX28()
SOCKET_TEX_GRND(28,10.16)
#end
#macro SOCKET_TEX28W()
SOCKET_TEX_GRND(28,15.24)
#end
#macro SOCKET_TEX32W()
SOCKET_TEX_GRND(32,15.24)
#end
#macro SOCKET_TEX40W()
SOCKET_TEX_GRND(40,15.24)
#end
#macro SOCKET_TEX40WW()
SOCKET_TEX_GRND(40,25.4)
#end
#macro SOCKET_TEX42W()
SOCKET_TEX_GRND(42,15.24)
#end
#macro SOCKET_TEX48W()
SOCKET_TEX_GRND(48,15.24)
#end
#macro SOCKET_TEX64WW()
SOCKET_TEX_GRND(64,22.86)
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
