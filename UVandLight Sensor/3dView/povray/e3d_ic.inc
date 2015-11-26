//Eagle3D 20110101 INC-File e3d_ic.inc
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
 
#ifndef(__ic_inc)
#declare __ic_inc = true;

#ifndef(inc_testmode)
#declare inc_testmode=true;
#include "e3d_tools.inc"
#undef inc_testmode
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_IC_DIS_PIN.inc.src
// Pin Diskretes IC
// DIP Pin
// //////////
#macro IC_DIS_PIN()
union{
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
    difference{
        box{<0,0,0><1.43,1.7,0.3> translate<-0.4875,3.4,0>}
        box{<0,0,0><1,2.2,0.5> rotate<0,0,-20> translate<0.55,3.4,-0.1>}
        box{<0,0,0><-1,2.2,0.5> rotate<0,0,20> translate<-0.095,3.40,-0.1>}
    }
    difference{
        cylinder{<0,0,0><1.43,0,0>0.5 translate<-0.4875,5.1,0.5> }
        box{<0,0,0><2,2.2,2> translate<-0.8,3.1,0.3>}
        box{<0,0,0><2,2.2,2> translate<-0.7,4,0.5>}
    }
    translate<-0.455/2,0,0>
}
#end



// ////////////////////////////////////////////////////////////
// Original file: ./1_IC_SMD_PIN.inc.src
// SO Pin
// Makro für Pin von SO und ähnlichem (Kopie von QFP-Pin)
// H = Höhe des Pins
// B = Breite des Pins
// T = Tiefe des Pins
// S = Materialstärke des Pins
// //////////
#macro IC_SMD_PIN(H,B,T,S)
union{
    box{<0,H,T/2> <B/4,H-S,-T/2>}
    difference{
        cylinder{<B/4,H-S,-T/2> <B/4,H-S,T/2> S}
        box{<-1,H-S,-T/2-0.01> <B/2,H-S-3,T/2+0.01>}
    }
    box{<B/4,H-S,-T/2> <B/4+S,S,T/2>}
    difference{
        cylinder{<B/4+S,S,-T/2> <B/4+S,S,T/2> S}
        box{<0,S,-T/2-0.01> <B,S+3,T/2+0.01>}
    }
    box{<B/4+S,0,-T/2> <B,S,T/2>}
    difference{
        box{<B/4+S,S,-T/2> <B/4+S+S/2,1.5*S, T/2>}
        cylinder{<B/4+S+S/2,S+S/2,T/2+0.01> <B/4+S+S/2,S+S/2,-T/2-0.01>, S/2}
    }
}
#end



// ////////////////////////////////////////////////////////////
// Original file: ./1_IC_SMD_PLCC_PIN.inc.src
// PLCC Pin
// //////////
#macro IC_SMD_PLCC_PIN()
union{
    intersection{
        difference{
            box{<0,0,0><1.8,0.9,0.45>}
            cylinder{<0.9,0.9,-0.1><0.9,0.9,0.5>0.7}
        }
        cylinder{<0.9,0.9,-0.1><0.9,0.9,0.5>0.9}
    }
    box{<1.6,0.8,0><1.8,1.2,0.45>}
    difference{
        box{<1.6,1.2,-0.125><1.8,2.5,0.45+0.125>}
        box{<-0.1,0,0><0.3,0.5,-0.5> rotate<-20,0,0> translate<1.55,1.2,0>}
        box{<-0.1,0,0><0.3,0.5,0.5> rotate<20,0,0> translate<1.55,1.2,0.45>}
    }
    difference{
        cylinder{<1.5,2.5,-0.125><1.5,2.5,0.45+0.125>0.3}
        box{<1.6,2.9,-1><1,2,1>}
    }
    difference{
        box{<1.6,2.5,-0.125><1.4,2.8,0.45+0.125>}
        cylinder{<1.45,2.45,-1><1.45,2.45,1>0.15}
    }
    translate<-1.4,0,0>
    rotate<0,90,0>
    translate<-0.225,0,0>
}
#end

/********************************************************************************************************************************************
//Macros for Beck SC12
//Designed by Stefan Seegel <dahamm(replace with at)gmx.net>
********************************************************************************************************************************************/
#macro IC_BECK_SC12_GRND()
union
{
    //plastic package
    difference
    {
        union
        {
            difference
            {
                box{<-22,0,-11>,<22,9.5,11>}
                box{<-23,8.5,-7.5>,<9.5,10,7.5>}
            }            
    
            box{<0,0,-8>,<-5,-5,8> rotate<0,0,18.43> translate<9.5,9.5,0>} //Schraege innen rechts
            box{<0,0,-7.5>,<20,-5,7.5> rotate<0,0,-3.81> translate<-21.5,9.5,0>} //Schraege innen links
                    
            box{<-22,0,0>,<22,-1,-5> rotate<-26.57,0,0> translate<0,9.5,7.5>} //Schraege innen oben
            box{<-22,0,0>,<22,-1,5> rotate<26.57,0,0> translate<0,9.5,-7.5>} //Schraege innen unten
        }
    
        box{<-23,-1,-10>,<23,0.5,10>} //Bodennocken
        box{<-21,-1,-12>,<21,0.5,12>} //Bodennocken
            
        box{<-5,-1,-12>,<0,10,12> rotate<0,0,-3> translate<-22,0,0>} //Schraege kurze Seite
        box{<5,-1,-12>,<0,10,12> rotate<0,0,3> translate<22,0,0>} //Schraege kurze Seite

        box{<-23,-1,0><23,10,-5> rotate<3,0,0> translate<0,0,-11>} //Schraege lange Seite
        box{<-23,-1,0><23,10,5> rotate<-3,0,0> translate<0,0,11>} //Schraege lange Seite
            
        box{<-6,8.3,-5>,<6,10,5>} //Aufkleberfläche*/
        
        cylinder{<-20.5,9.0,-9.5>,<-20.5,10.0,-9.5> 0.25}        
        
        texture{e3d_tex_ic_body_1}
    }
    
    //Holo-Aufkleber
    #local w=0.1;
    union
    {
        cylinder{<5.25,8.3,4.25>,<5.25,8.3+w,4.25>0.5}
        cylinder{<5.25,8.3,-4.25>,<5.25,8.3+w,-4.25>0.5}
        cylinder{<-5.25,8.3,4.25>,<-5.25,8.3+w,4.25>0.5}
        cylinder{<-5.25,8.3,-4.25>,<-5.25,8.3+w,-4.25>0.5}
        box{<-5.25,8.3,-4.75>,<5.25,8.3+w,4.75>}
        box{<-5.75,8.3,-4.25>,<5.75,8.3+w,4.25>}
        
        texture{T_Chrome_5C}
    }
    
    text{ttf global_fontfile_arial_bold "@CHIP" 1, 0 scale<3.3,3.3,0> rotate<90,0,0> translate<-5.5,8.3+w,1.5> texture{e3d_tex_ic_marking_black}}
    text{ttf global_fontfile_arial_bold "License SL01" 1, 0 scale<1.2,1.2,0> rotate<90,0,0> translate<-3.5,8.3+w,-2.0> texture{e3d_tex_ic_marking_black}}
    text{ttf global_fontfile_arial_bold "2001 BECK IPC" 1, 0 scale<1.2,1.2,0> rotate<90,0,0> translate<-4.0,8.3+w,-3.5> texture{e3d_tex_ic_marking_black}}
        
    //Pins    
    union
    {
        #local i=-8;
        #while (i<8)
            cylinder{<i*2.54+1.27,0.5,7.62>,<i*2.54+1.27,-4.5,7.62> 0.25}
            cylinder{<i*2.54+1.27,0.5,-7.62>,<i*2.54+1.27,-4.5,-7.62> 0.25}
            #local i=i+1;
        #end
        texture{e3d_tex_silver}
    }
    
}
#end

#macro IC_BECK_SC12()
IC_BECK_SC12_GRND()
#end


/********************************************************************************************************************************************
//Designed by Friedrich Bleikamp, fbleikamp@web.de>
//Macro fuer B-DIL rectifier aus rectifier.lib
//benutzt Macro DIC_PIN() aus ic.inc
********************************************************************************************************************************************/
#macro IC_DIS_DIP4S_RECTIFIER_GRND(value)
union{
    difference{
        box{<0,0,0><9.4,3.2,6.0>}
        box{<-0.1,0,0><12,2,-2> rotate<5,0,0> translate<0,2,0>}
        box{<-0.1,0,0><12.2,2,2> rotate<-5,0,0> translate<0,2,6.6>}
        box{<0,0,6.7><-2,2,0> rotate<0,0,-35> translate<0,2,0>}
        translate<-4.7,0,-3.0>
    }
    union{
        object{IC_DIS_PIN() rotate<0,180,0> translate<2.54,-3.75,3.81>}
        object{IC_DIS_PIN() rotate<0,180,0> translate<-2.54,-3.75,3.81>}
        object{IC_DIS_PIN() translate<-2.54,-3.75,-3.81>}
        object{IC_DIS_PIN() translate<2.54,-3.75,-3.81>}
        texture{e3d_tex_silver}
    }
    union{    
        text {ttf besch_font value 0.2, 0     rotate <90,0,0> scale<1.5,1,1.5> translate<-3.1,3.21,-0.3>}
        text {ttf besch_font "~     ~" 0.2, 0 rotate <90,0,0> scale<1.5,1,1.5> translate<-3.0,3.21,1.8>}
        text {ttf besch_font "+     -" 0.2, 0 rotate <90,0,0> scale<1.5,1,1.5> translate<-3.0,3.21,-2.5>}
        texture{e3d_tex_ic_marking_bright}
    }
    translate<0,0.25,0>
    texture{e3d_tex_ic_body_1}
}
#end

#macro IC_DIS_DIP4S_RECTIFIER(value)
IC_DIS_DIP4S_RECTIFIER_GRND(value)
#end


/********************************************************************************************************************************************
// The following is a modified module section by Joseph Zeglinski   Aug. 20, 2003

// This macro now produces either a fully pin populated DIL,  or a DIL with fewer "quads" of pins.
// Example: Some IC's, FET's, Optoisolators and Crystal Oscillators - (8, 14, 16, or 24) pin body, with only 4, 8 or 12 outer pins.
// The " a= Available Pins" parameter is how many pins (modulo 4), are present on the intended DIP.

//Grundmakro für DIP's
//p=Pincount of a full DIL
//a=Count of available pins, ( less than or equal to "p" )
//b=breite (in Raster)
//h=höhe
//n=Beschriftung
********************************************************************************************************************************************/
#macro IC_DIS_DIP_GRND(p,a,b,h,n,logo)
union{
    //Body
    difference{
        box{<0,0,0><(p/2)*2.54-0.2,h,b*2.54-1>}
        box{<-0.1,0,0><(p/2)*2.54+2,-2,-2> rotate<-15,0,0> translate<0,h/2-0.3,0>}
        box{<-0.1,0,0><(p/2)*2.54+2,2,-2> rotate<15,0,0> translate<0,h/2+0.3,0>}
        box{<-0.1,0,0><(p/2)*2.54+2,-2,2> rotate<15,0,0> translate<0,h/2-0.3,b*2.54-1>}
        box{<-0.1,0,0><(p/2)*2.54+2,2,2> rotate<-15,0,0> translate<0,h/2+0.3,b*2.54-1>}
        box{<0,0,b*2.54><-2,-2,-b*2> rotate<0,0,15> translate<0,h/2-0.3,0>}
        box{<0,0,b*2.54><-2,2,-b*2> rotate<0,0,-15> translate<0,h/2+0.3,0>}
        box{<0,0,b*2.54><2,-2,-b*2> rotate<0,0,-15> translate<p/2*2.54-0.2,h/2-0.3,0>}
        box{<0,0,b*2.54><2,2,-b*2> rotate<0,0,15> translate<p/2*2.54-0.2,h/2+0.3,0>}
        cylinder{<0,h-0.3,(b*2.54-1)/2><0,h+0.3,(b*2.54-1)/2>1}
        translate<-(p/2*2.54-0.2)/2,0,-(b*2.54-1)/2>
    }
    
    //Pins
    union{
        
        #local i=0;
        #while(i<(p/2))

            // Check for special  "Partial Pin Population" DIL condition
            #if( (p>a) & (i=a/4) ) 
                #local i=i+(p-a)/2; 
            #end  

            object{IC_DIS_PIN() rotate<0,180,0> translate<i*2.54,-3.75,b*2.54/2>}
            object{IC_DIS_PIN() translate<i*2.54,-3.75,-b*2.54/2>}
            #local i=i+1;
        #end
        translate<-p/2*1.27+1.27,0,0>
        texture{e3d_tex_silver}
    }

    // ADAPTIVE print scaling for small IC's 
    // Check if printing will fall off the end of the DIP surface
    // Automatically size the X-scaling factor for the value (n) to fit the DIP IC surface:
    // DIP4 - because it is so short, printing will be "rotated to fit" the width (b) of this IC

    //Marking
    union{
        // create a TrueType text shape
        #local astring = text {ttf besch_font,n,0.2,0}
        #local L=(max_extent(astring).x); // MM width of text string (n)
        #local astrscale = ( (p=4) ? (b*2-1.0)/L : ((p/2)*2.54-0.2 -2.5 )/L );  //scale to width for tiny DIP4
        #if(p=4)
            #local astrscale = (astrscale<1.5 ? astrscale : 1.5);    // Leave normal scaling, if a short label will fit
            object{astring rotate<90,-90,0,>  scale <1.5,1,astrscale>  translate<0.3,h+0.01,-L*astrscale/2>  }
        #else 
            #if(astrscale < 1.5) // For DP6 & DIP8 check if a normal scale label will still fit
                object{astring rotate<90,0,0,>  scale <astrscale,1,1.5>  translate<-(p/4)*2.54+1.5,h+0.01,-0.3> } //No - shrink in X-direction      
            #else
                text{ttf global_fontfile_arial_bold n 0.2, 0 rotate <90,0,0> scale<b/2,1,b/2> translate<-b,h+0.01,0.6>}
            #end
        #end
        
        #if(p>12)
            #if(strcmp(logo,"MICROCHIP")=0.0)
                text{ttf global_fontfile_eagle3d "m" 0.2,0 scale<b+1,b+1,b+1> rotate<90,0,0> translate<-(p/5)*2.54+0.5,h+0.01,-b/1.8>}                        
                text{ttf besch_font "Microchip" 0.2,0 rotate<90,0,0> scale<b/1.5,b/1.5,b/1.5> translate<-b,h+0.01,-b/2> }
                #if(p>14)
                    text{ttf besch_font "Microchip" 0.2,0 rotate<90,0,0> scale<b/1.5,b/1.5,b/1.5> translate<-b,h+0.01,-b/2> }
                #end
            #end
                    
            #if(strcmp(logo,"PHILIPS")=0.0)
                text{ttf global_fontfile_eagle3d "p" 0.2,0 scale<b*1.5,b*1.5,b*1.5> rotate<90,0,0> translate<-(p/5)*2.54+1.5,h+0.01,-b/1.5>}                        
            #end

            #if(strcmp(logo,"MAXIM")=0.0)
                text{ttf global_fontfile_eagle3d "-" 0.2,0 scale<b/2.5,b/2.5,b/2.5> rotate<90,0,0> translate<-(p/5)*2.54,h+0.01,-b/2.2>}                        
            #end

            #if(strcmp(logo,"ST")=0.0)
                text{ttf global_fontfile_eagle3d "s" 0.2,0 scale<b,b,b> rotate<90,0,0> translate<-(p/5)*2.54+0.5,h+0.01,-b/2.2>}                        
            #end

            #if(strcmp(logo,"TEXAS")=0.0)
                text{ttf global_fontfile_eagle3d "t" 0.2,0 scale<b*0.9,b*0.9,b*0.9> rotate<90,0,0> translate<-(p/5)*2.54,h+0.01,-b/2.2>}                        
            #end    
        #end                            
        texture{e3d_tex_ic_marking_bright}
    }
    
    translate<0,0.25,0>
    
    texture{e3d_tex_ic_body_1}
}
#end













//DIP8 with 4 corner pins
#macro IC_DIS_DIP8A4(name,logo)
IC_DIS_DIP_GRND(8,4,3,3.2,name,logo)
#end
//DIP14 with 4 corner pins
#macro IC_DIS_DIP14A4(name,logo)
IC_DIS_DIP_GRND(14,4,3,3.2,name,logo)
#end
//DIP14 with 8 corner pins
#macro IC_DIS_DIP14A8(name,logo)
IC_DIS_DIP_GRND(14,8,3,3.2,name,logo)
#end
//DIP16 with 4 corner pins
#macro IC_DIS_DIP16A4(name,logo)
IC_DIS_DIP_GRND(16,4,3,3.2,name,logo)
#end
//DIP16 with 8 corner pins
#macro IC_DIS_DIP16A8(name,logo)
IC_DIS_DIP_GRND(16,8,3,3.2,name,logo)
#end
//DIP24 with 12 corner pins
#macro IC_DIS_DIP24A12(name,logo) 
IC_DIS_DIP_GRND(24,12,3,3.2,name,logo)
#end
//DIP2
#macro IC_DIS_DIP2(name,logo)
IC_DIS_DIP_GRND(2,2,3,3.2,name,logo)
#end
//DIP4
#macro IC_DIS_DIP4(name,logo)    
IC_DIS_DIP_GRND(4,4,3,3.2,name,logo)
#end
//DIP6
#macro IC_DIS_DIP6(name,logo)    
IC_DIS_DIP_GRND(6,6,3,3.2,name,logo)
#end
//DIP6-4
#macro IC_DIS_DIP6_4(name,logo)
IC_DIS_DIP_GRND(6,6,4,3.2,name,logo)
#end
//DIP8
#macro IC_DIS_DIP8(name,logo)
IC_DIS_DIP_GRND(8,8,3,3.2,name,logo)
#end
//DIP14
#macro IC_DIS_DIP14(name,logo)    
IC_DIS_DIP_GRND(14,14,3,3.2,name,logo)
#end
//DIP16
#macro IC_DIS_DIP16(name,logo)    
IC_DIS_DIP_GRND(16,16,3,3.2,name,logo)
#end
//DIP18
#macro IC_DIS_DIP18(name,logo)    
IC_DIS_DIP_GRND(18,18,3,3.2,name,logo)
#end
//DIP20
#macro IC_DIS_DIP20(name,logo)    
IC_DIS_DIP_GRND(20,20,3,3.2,name,logo)
#end
//DIP22
#macro IC_DIS_DIP22(name,logo)    
IC_DIS_DIP_GRND(22,22,3,3.2,name,logo)
#end
//DIP22-4
#macro IC_DIS_DIP22_4(name,logo)    
IC_DIS_DIP_GRND(22,22,4,3.2,name,logo)
#end
//DIP24
#macro IC_DIS_DIP24(name,logo)    
IC_DIS_DIP_GRND(24,24,3,3.2,name,logo)
#end
//DIP24-4
#macro IC_DIS_DIP24_4(name,logo)    
IC_DIS_DIP_GRND(24,24,4,3.2,name,logo)
#end
#macro IC_DIS_DIP24_9(name,logo)    
IC_DIS_DIP_GRND(24,24,9,3.2,name,logo)
#end
//DIP28
#macro IC_DIS_DIP28(name,logo)    
IC_DIS_DIP_GRND(28,28,3,3.2,name,logo)
#end
//DIP24 600mil
#macro IC_DIS_DIP24_W(name,logo)    
IC_DIS_DIP_GRND(24,24,6,3.2,name,logo)
#end
//DIP28 400mil
#macro IC_DIS_DIP28_4(name,logo)    
IC_DIS_DIP_GRND(28,28,4,3.2,name,logo)
#end
//DIP28 600mil
#macro IC_DIS_DIP28_W(name,logo)    
IC_DIS_DIP_GRND(28,28,6,3.2,name,logo)
#end
//DIP32 300mil
#macro IC_DIS_DIP32_3(name,logo)    
IC_DIS_DIP_GRND(32,32,3,3.2,name,logo)
#end
//DIP32 600mil
#macro IC_DIS_DIP32_W(name,logo)    
IC_DIS_DIP_GRND(32,32,6,3.2,name,logo)
#end
//DIP36 600mil
#macro IC_DIS_DIP36_W(name,logo)
IC_DIS_DIP_GRND(36,36,6,3.2,name,logo)
#end
//DIP40 600mil
#macro IC_DIS_DIP40_W(name,logo)    
IC_DIS_DIP_GRND(40,40,6,3.2,name,logo)
#end
//DIP42 600mil
#macro IC_DIS_DIP42_W(name,logo)    
IC_DIS_DIP_GRND(42,42,6,3.2,name,logo)
#end
//DIP48 600mil
#macro IC_DIS_DIP48_W(name,logo)    
IC_DIS_DIP_GRND(48,48,6,3.2,name,logo)
#end
//DIP52 600mil
#macro IC_DIS_DIP52_W(name,logo)    
IC_DIS_DIP_GRND(52,52,6,3.2,name,logo)
#end
//DIP64 900mil
#macro IC_DIS_DIP64_9(name,logo)    
IC_DIS_DIP_GRND(64,64,9,3.2,name,logo)
#end
//DIP68 900mil
#macro IC_DIS_DIP68_9(name,logo)    
IC_DIS_DIP_GRND(68,68,9,3.2,name,logo)
#end


/********************************************************************************************************************************************
// Sharp SIL-type solid-state-relay (SSR)   (relay.lib)
// s2xxEx      S202SE1, S202SE2, (S202S12, S216S02), S216SE1, S216SE2, S102S11, S102S12
//
// Joerg Bredendiek <sprut(replace with at)sprut.de> 
//
// Mittelpunkt: geometrische Mitte zwischen den Aussenpins 
********************************************************************************************************************************************/
#macro IC_DIS_S2XXEX_GRND(value)
// macro for one pin
#macro S2XXEX_PIN()
        difference{
                union{
                        box{<-0.4,  S2xxEx_s_pin, -0.3><0.4  , 4.2, 0.3>} 
                        box{<-0.625, 0.5, -0.3><0.625, 3  , 0.3>} 
                        box{<-0.55,  2.2, -0.3><0.55 , 4.2, 0.3>}   
                }                                                
                box{<-0.5,-0.5,-0.5>< 0.5,0.5,0.5> rotate<  0, 0,-25> translate< 0.65,S2xxEx_s_pin, -0.0>}
                box{<-0.5,-0.5,-0.5>< 0.5,0.5,0.5> rotate<  0, 0, 25> translate<-0.65,S2xxEx_s_pin, -0.0>}
                box{<-0.5,-0.5,-0.5>< 0.5,0.5,0.5> rotate< 25, 0,  0> translate< 0   ,S2xxEx_s_pin, -0.6>}
                box{<-0.5,-0.5,-0.5>< 0.5,0.5,0.5> rotate<-25, 0,  0> translate< 0   ,S2xxEx_s_pin,  0.6>}                              
        }
#end

#if(pin_short=off)
    #local S2xxEx_s_pin = -7;
#else
    #local S2xxEx_s_pin = -(pcb_height+pin_length);
#end
union{    
    union{
        union{
            //pins
            object{S2XXEX_PIN() translate<-7.62,0,0>}
            object{S2XXEX_PIN() translate<-2.54,0,0>}
            object{S2XXEX_PIN() translate< 5.08,0,0>}
            object{S2XXEX_PIN() translate< 7.62,0,0>}
        }           
        //metal plate inside the plastic body
        difference{
            box{<-8.2, 4.5, 0.3><8.2, 28.8, -0.3>}
            cylinder{<0,0,-2><0,0,2>2 translate<0,28.8-3.2,0>}
        }
        texture{e3d_tex_silver}
    }           
    //plastic body   
    //front part   
    #local front = 0.3+1.4-5.5;
    #local top   = 28.8;
    difference{
        box{<-9.25, 4.2, front+5.5><9.25, top, front>} 
        
        box{<-5,-3,-5><5,3,5> rotate<0,-60,0> translate< 10,top-2.5, -4> }
        box{<-5,-3,-5><5,3,5> rotate<0, 60,0> translate<-10,top-2.5, -4> }
        cylinder{<0,0,-7><0,0,2>1.6 translate<0, top-3.2, 0>}      
        cylinder{<0,0,front-0.1><0,0,front+0.1>1 translate< 0,  6, 0>}
        cylinder{<0,0,front-0.1><0,0,front+0.1>1 translate<-7.5, 21, 0>}
        cylinder{<0,0,front-0.1><0,0,front+0.1>1 translate< 7.5, 21, 0>}
        texture{e3d_tex_ic_body_2}
    }                
    //plastic at the back of the metal plate
    difference{                   
        box{<-8.2, 4.2, -0.4><8.2, top, front+5.5>} 
        cylinder{<0,0,-7><0,0,2>1.6 translate<0, top-3.2, 0>}         
        cylinder{<-9, top-3.2, 0><9, top-3.2, 0>0.5 translate<0, 0, -0.5>}           
        texture{e3d_tex_ic_body_2}
    }    

    // labels
    union{    
        text{ttf besch_font value            0.5,0 scale<3,3,1.7>   translate<-6, 15,   front-0.01>}
        text{ttf besch_font "SHARP"          0.5,0 scale<3,2.5,1.7> translate<-4.5, 12, front-0.01>}
        text{ttf besch_font "~         + -"  0.5,0 scale<1.7,2,1.7> translate<-5.7, 5,  front-0.01>}
        texture{e3d_tex_ic_marking_bright}
    }
}
#end


#macro IC_DIS_S2XXEX(value)
IC_DIS_S2XXEX_GRND(value)
#end


/********************************************************************************************************************************************
//Multiwatt15 H & V package.
//Author: Christian Hostelet c.hostelet@wanadoo.fr
//Reference: ST-Microelectronics web site (www.st.com)
//
//Depends on "discrete-ttols.inc" include file
//
//The two macros defined are:
//
//Multiwatt15V (value)  - for vertical MW15 package
//Multiwatt15H (value)  - for horizontal MW15 package
********************************************************************************************************************************************/
#macro IC_MULTIWATT_GRND(value,H_V)
    // *  Discrete Utilities
    // *
    // *  Author: Christian Hostelet c.hostelet@wanadoo.fr
    // *
    // *  Defines some macros used in other include files
    // *
    // *  Essentially, macros to define and build discrete components leads
    //////////////////////////////////////////
    //
    // Returns the lenght of a text
    //
    #macro TextWidth( Text, Font, Size )
       #local T1 = text { ttf Font concat("|",Text,"|") 1 0 scale <Size, Size, 1> }
       #local T2 = text { ttf Font "||" 1 0 scale <Size, Size, 1> }
       
       ((max_extent(T1).x - min_extent(T1).x) - (max_extent(T2).x - min_extent(T2).x))
    #end
    
    
    //////////////////////////////////////////
    //
    // Some textures for components' leads
    //
    #local DiscLead_Silver = texture{e3d_tex_silver};
    #local DiscLead_Gold   = texture{e3d_tex_gold};
    
    //////////////////////////////////////////
    // Resistor/Diode/Condensator leads
    //////////////////////////////////////////
    //
    // Axial leads for horizontal component
    //
    // Entraxe : distance between the two pass-thru holes
    // Height  : distance from PCB to horizontal axle of the lead 
    // LeadDiam: lead diameter
    // LeadTxtr: lead texture
    //
    #macro DiscreteAxialLeadHoriz (Entraxe, Height, LeadDiam, LeadTxtr)
       #local LeadRadius = LeadDiam/2;
       #local BendRadius = LeadDiam;
       #local BoxSize    = 2*LeadDiam+1;
       #local HorizLeadHLen = (Entraxe-LeadDiam)/2;
       #if (Entraxe > 1.0)
       #if (LeadDiam < 1.0)
       #local BendRadius=1.0;
       #end
       #end
       #if (HorizLeadHLen < 0)
       #local HorizLeadHLen= 0;
       #local BendRadius = Entraxe/2;
       #end
                         
       union {
          cylinder {<0,-2,0>, <0,Height-BendRadius,0>, LeadRadius translate -(HorizLeadHLen+BendRadius)*x }
          difference {
             torus {BendRadius LeadRadius}
             box {<-BoxSize,-BoxSize,-BoxSize> <0,BoxSize,BoxSize>}
             box {<-BoxSize,-BoxSize,-BoxSize> <BoxSize,BoxSize,0>}
             rotate <-90,0,0> translate <HorizLeadHLen,Height-BendRadius,0> }
          #if (HorizLeadHLen>0)
             cylinder { <-HorizLeadHLen,Height,0>, <HorizLeadHLen,Height,0>, LeadRadius }
          #end
          difference {
             torus {BendRadius LeadRadius}
             box {<-BoxSize,-BoxSize,-BoxSize> <0,BoxSize,BoxSize>}
             box {<-BoxSize,-BoxSize,-BoxSize> <BoxSize,BoxSize,0>}
             rotate <-90,180,0> translate <-HorizLeadHLen,Height-BendRadius,0> }
          cylinder {<0,-2,0>, <0,Height-BendRadius,0>, LeadRadius translate (HorizLeadHLen+BendRadius)*x }
          texture {LeadTxtr} 
       }
    #end
    
    //////////////////////////////////////////
    //
    // Axial leads vertical component
    //
    // Entraxe : distance between the two pass-thru holes
    // Height  : distance from PCB to horizontal axle of the lead 
    // LeadDiam: lead diameter
    // LeadTxtr: lead texture
    //
    #macro DiscreteAxialLeadVerti (Entraxe, Height, LeadDiam, LeadTxtr)
       #local LeadRadius = LeadDiam/2;
       #local BendRadius = LeadDiam;
       #local BoxSize    = 2*LeadDiam+1;
       #if (BendRadius <= 1.28)
       #local BendRadius = ((Entraxe/2) < 1.28 ? Entraxe/2 : 1.28);
       #end
       #local HorizLeadLen = (Entraxe-2*BendRadius);
       #local HorizLeadHei = (Height/*+BendRadius*/);
       
       union {
          cylinder {<0,-2,0>, <0,HorizLeadHei,0>, LeadRadius }
          difference {
             torus {BendRadius LeadRadius}
             box {<-BoxSize,-BoxSize,-BoxSize> <0,BoxSize,BoxSize>}
             box {<-BoxSize,-BoxSize,-BoxSize> <BoxSize,BoxSize,0>}
             rotate <-90,180,0> translate <BendRadius,HorizLeadHei,0> }
          #if (HorizLeadLen>0)
             cylinder { <0,HorizLeadHei,0>, <HorizLeadLen,HorizLeadHei,0>, LeadRadius translate <BendRadius,BendRadius,0> }
          #end   
          difference {
             torus {BendRadius LeadRadius}
             box {<-BoxSize,-BoxSize,-BoxSize> <0,BoxSize,BoxSize>}
             box {<-BoxSize,-BoxSize,-BoxSize> <BoxSize,BoxSize,0>}
             rotate <-90,0,0> translate <HorizLeadLen+BendRadius,HorizLeadHei,0> }
          cylinder {<0,-2,0>, <0,HorizLeadHei,0>, LeadRadius translate Entraxe*x }
          texture {LeadTxtr} 
       }
    #end
    
    //////////////////////////////////////////
    //
    // Strap
    //
    // Entraxe : distance between the two pass-thru holes
    // LeadDiam: lead diameter
    // LeadTxtr: lead texture
    //
    #macro DiscreteStrap (Entraxe, LeadDiam, LeadTxtr)
       DiscreteAxialLeadVerti (Entraxe, 0.1, LeadDiam, LeadTxtr)
    #end
    
    //////////////////////////////////////////
    //
    // Radial leads for horizontal component (bended leads)
    //
    // Entraxe : distance between the two pass-thru holes
    // Height  : distance from PCB to horizontal part of the leads
    // Depth   : length of the horizontal section of the leads
    // LeadDiam: lead diameter
    // LeadTxtr: lead texture
    //
    #macro DiscreteRadialLeadHoriz (Entraxe, Height, Depth, LeadDiam, LeadTxtr)
       #local LeadRadius = LeadDiam/2;
       #local BendRadius = LeadDiam;
       #local BoxSize    = 2*LeadDiam+1;
       
       union {
          cylinder {<-(Entraxe/2),-2,0>, <-(Entraxe/2),Height-BendRadius,0>, LeadRadius }
          cylinder {<+(Entraxe/2),-2,0>, <+(Entraxe/2),Height-BendRadius,0>, LeadRadius }
          difference {
             torus {BendRadius LeadRadius}
             box {<-BoxSize,-BoxSize,-BoxSize> <0,BoxSize,BoxSize>}
             box {<-BoxSize,-BoxSize,-BoxSize> <BoxSize,BoxSize,0>}
             rotate <-90,90,0> translate <-Entraxe/2, Height-BendRadius,BendRadius> }
          difference {
             torus {BendRadius LeadRadius}
             box {<-BoxSize,-BoxSize,-BoxSize> <0,BoxSize,BoxSize>}
             box {<-BoxSize,-BoxSize,-BoxSize> <BoxSize,BoxSize,0>}
             rotate <-90,90,0> translate <+Entraxe/2, Height-BendRadius,BendRadius> }
          cylinder {<-(Entraxe/2),Height,BendRadius>, <-(Entraxe/2),Height,BendRadius+Depth>, LeadRadius }
          cylinder {<+(Entraxe/2),Height,BendRadius>, <+(Entraxe/2),Height,BendRadius+Depth>, LeadRadius }
          texture {LeadTxtr} 
       }
    #end
    
    
    //////////////////////////////////////////
    //
    // Axial leads vertical component
    //
    // Entraxe : distance between the two pass-thru holes
    // Height  : distance from PCB to top of the leads
    // LeadDiam: lead diameter
    // LeadTxtr: lead texture
    //
    #macro DiscreteRadialLeadVerti (Entraxe, Height, LeadDiam, LeadTxtr)
       #local LeadRadius = LeadDiam/2;
       
       union {
          cylinder {<-(Entraxe/2),-2,0>, <-(Entraxe/2),Height,0>, LeadRadius }
          cylinder {<+(Entraxe/2),-2,0>, <+(Entraxe/2),Height,0>, LeadRadius }
          texture {LeadTxtr} 
       }
    #end


    // Heatsink
    #macro MWHeatSink ()
    object {
       difference {
          box { <-9.8,0,0> <9.8,1.5,17.5> }
          cylinder { <0,-1,14.7> <0,2,14.7> 3.75/2 }
          
          box { <0,-1,0> <2,2,4> rotate -45*y translate <9.8,0,15> } 
          box { <7.8,-1,-1> <10.8,2,2> } 
          cylinder { <5,-1,10> <5,2,10> 0.8 }
          box { <10, -1, 9.2> <5,2,10.8> }
          box { <8.5,-1,9.5> <11,2,7> }
          box { <8.8,-1,0> <10,2,10> }
          
          box { <0,-1,0> <-2,2,4> rotate 45*y translate <-9.8,0,15> }
          box { <-7.8,-1,-1> <-10.8,2,2> } 
          cylinder { <-5,-1,10> <-5,2,10> 0.8 }
          box { <-10, -1, 9.2> <-5,2,10.8> }
          box { <-8.5,-1,9.5> <-11,2,7> }
          box { <-8.8,-1,0> <-10,2,10> }
          
          box { <-0.5,-1,0> <0.5,2,2> }
          box { <-10,-1,-1> <10,2,1> }
          }
       texture{e3d_tex_heatsink_silver}
    }
    #end
    
    // Plastic package with value engraved
    #macro MWPlastic(value)
    object {
       difference {
          box { <-9.8,0,0> <9.8,5,10.7> }
          
          box { <-10,0,-2> <10,6,0> rotate 7*x translate <0,1.5,0>}
          box { <0,0,0> <3,6,11> rotate 7*z translate <9.8,1.5,0> }
          cone { <9.8,5.01,5> 1.5 <9.8,1.4,5> 1.3 }
          cylinder { <6,4.9,5> <6,5.5,5> 1 }
          
          box { <-10,0,0> <10,6,2> rotate -7*x translate <0,1.5,10.7>}
          box { <0,0,0> <-2,6,11> rotate -7*z translate <-9.8,1.5,0> }
          cone { <-9.8,5.01,5> 1.5 <-9.8,1.4,5> 1.3 }
          cylinder { <-6,4.9,5> <-6,5.5,5> 1 }
          
          #local Twidth = TextWidth( value, besch_font, 2 );
          text { ttf besch_font value 1, 0 scale <2,2,1> rotate 90*x translate <-Twidth/2,5.95,6> texture{e3d_tex_ic_marking_bright}}          
       }
       texture{e3d_tex_ic_body_2}
    }
    #end
    
    // Body = Heatsink + Plastic Box
    #macro MWBody (value)
    union {
       object { MWHeatSink () translate -0.001*y }
       object { MWPlastic (value) }
       translate -1.5*y
    }
    #end
    
    // Bend of a pin
    #macro MWBend(BWidth, BRadius, BSlope)
    object {
       difference {
          cylinder { -BWidth/2*x BWidth/2*x BRadius }
          cylinder { -BWidth*x   BWidth*x   BRadius/2 }
          box { <-BWidth,-2*BRadius,0>,          <BWidth, 2*BRadius,2*BRadius> }
          box { <-BWidth,         0,-2*BRadius>, <BWidth,-2*BRadius,2*BRadius> rotate BSlope*x }
          }
       }
    #end
                     
    // Pins for MW15 H
    #macro MWPinH(NpinF, NpinB)
    #local B = 2.5;
    #local D = 4;
    #local E = 0.52;
    #local F = 0.72;
    #local G = 1.27;
    #local R = 2*E;
    #local L2 = 2.54;
    #local L5 = 5.28;
    #local L6 = 2.38;
    #local Ls = 3.592;
    #local IFx = 1.498;
    #local IFy = 2.862;
    
    union {
    
    #local iF = 0;
       union {
    #while (iF < NpinF)
          union {
             box { <-F/2, -L5, -E/2>, <F/2, 1.04, E/2> }
             box { <-F/2, -E/2, 0>, <F/2, E/2, D> translate <0, 4.36, 3.32> }
             union {
                box { <-F/2, -E/2, -Ls/2>, <F/2, E/2, Ls/2>  }
                object { MWBend(F, R, 45) translate <0, -R+E/2, -Ls/2> }
                object { MWBend(F, R, 45) translate <0, -R+E/2, -Ls/2> rotate 180*y }
                rotate -45*x translate <0, IFy, IFx>
                }
             translate iF*2*G*x
             }
    #local iF = iF + 1;
    #end
          translate -(NpinF-1)*G*x
          }
       
    #local iB = 0;
       union {
    #while (iB < NpinB)
          union {
             box { <-F/2, -(L6+B), -E/2>, <F/2, 0, E/2> }
             object { MWBend(F, R, 0) translate (R-E/2)*z }
             box { <-F/2, -E/2, 0>, <F/2, E/2, D> translate <0, R-E/2, R-E/2> }
             translate <iB*2*G, 4.36-(R-E/2), L2>
             }
    #local iB = iB + 1;
    #end
          translate -(NpinB-1)*G*x
          }
    
          
       translate -1.27*z
       texture{e3d_tex_silver}
       }
    #end
    
    // Pins for MW15 V
    #macro MWPinV(NpinF,NpinB)
    #local B  = 2.5;
    #local M1 = 5.08;
    #local M  = 4.55;
    #local G  = 1.27;
    #local E  = 0.52;
    #local R  = 2*E;
    #local F  = 0.72;
    #local L8 = 3.4;
    
    #local AlphaDF = 18.307;
    #local Len4F = 6.109;
    #local IFx = 0.895;
    #local IFy = 1.700;
    #local AlphaDB = 58.886;
    #local Len4B = 3.030;
    #local IBx = 3.435;
    #local IBy = 1.700;
    
    union {
    #local iF = 0;
       union {
    #while (iF < NpinF)
          union {
             box { <-F/2, 0.0, -E/2>, <F/2, 2.0, E/2> translate <0, L8, M1/2+M-(B+E/2)> }
             box { <-F/2, 0.0, -E/2>, <F/2,-5.0, E/2> translate <0,  0, -M1/2> }
             union {
                box { <-F/2, -E/2, -Len4F/2>, <F/2, E/2, Len4F/2>  }
                object { MWBend(F, R, AlphaDF) translate <0, -R+E/2, -Len4F/2> }
                object { MWBend(F, R, AlphaDF) translate <0, -R+E/2, -Len4F/2> rotate 180*x  }
                rotate -AlphaDF*x translate <0, IFy, IFx>
                }
             translate <iF*2*G,0,>
             }
    #local iF = iF + 1;
    #end
          translate -(NpinF-1)*G*x
          }
       
    #local iB = 0;
       union {
    #while (iB < NpinB)
          union {
             box { <-F/2, 0.0, -E/2> <F/2,  2.0, E/2> translate <0, L8, M1/2+M-(B+E/2)> }
             box { <-F/2, 0.0, -E/2> <F/2, -5.5, E/2> translate <0,  0, M1/2> }
             union {
                box { <-F/2, -E/2, -Len4B/2>, <F/2, E/2, Len4B/2>  }
                object { MWBend(F, R, AlphaDB) translate <0, -R+E/2, -Len4B/2> }
                object { MWBend(F, R, AlphaDB) translate <0, -R+E/2, -Len4B/2> rotate 180*x  }
                rotate -AlphaDB*x translate <0, IBy, IBx>
                }
             translate iB*2*G*x
             }
    #local iB = iB + 1;
    #end
          translate -(NpinB-1)*G*x
          }
          
          texture{e3d_tex_silver}
       }
    #end


    #if(H_V=1)
        union { object { MWBody (value) rotate -90*x translate <0,3.5,6> } object { MWPinV(8, 7) } }
    #else
        union { object { MWBody (value)              translate <0,3.5,4.6> } object { MWPinH(8, 7) } }
    #end

#end

#macro IC_MULTIWATT15V(value)
IC_MULTIWATT_GRND(value,1)
#end
#macro IC_MULTIWATT15H(value) 
IC_MULTIWATT_GRND(value,0)
#end


/********************************************************************************************************************************************
//Macros for SMD bridge DF...S from Int. Rectifier
//Designed by Philippe Boucheny <philippe.boucheny(at)free.fr>
//Rev. 1.0  26/03/06
********************************************************************************************************************************************/
#macro IC_SMD_DFS_GRND()
union{
    
    //Body
    difference{
        box{<-4.1,0.3,-3.1><+4.1,1.9,+3.1>}
        cylinder{<3,1.8,0><3,2,0> 0.4}    
        texture{e3d_tex_ic_body_1}
    }

    // Marking
    union{
        text {ttf global_fontfile_eagle3d "j" 0.02, 0    scale 2 rotate<90,0,0> translate<-2.8,1.91,-0.8>}
        text {ttf global_fontfile_arial_bold "+" 0.02, 0 scale 1 rotate<90,0,0> translate<+2.3,1.91,+2>}
        text {ttf global_fontfile_arial_bold "-" 0.02, 0 scale 1 rotate<90,0,0> translate<-2.7,1.91,+2>}
        text {ttf global_fontfile_arial_bold "~" 0.02, 0 scale 1 rotate<90,0,0> translate<+2.3,1.91,-3>}
        text {ttf global_fontfile_arial_bold "~" 0.02, 0 scale 1 rotate<90,0,0> translate<-2.7,1.91,-3>}
        texture{e3d_tex_ic_marking_bright}
    }
    
    //Pins
    union{
        object {IC_SMD_PIN(1.5,1.5,1.2,0.3) rotate -90*y translate<-2.5,0,3>}
        object {IC_SMD_PIN(1.5,1.5,1.2,0.3) rotate -90*y translate<+2.5,0,3>}
        object {IC_SMD_PIN(1.5,1.5,1.2,0.3) rotate +90*y translate<-2.5,0,-3>}
        object {IC_SMD_PIN(1.5,1.5,1.2,0.3) rotate +90*y translate<+2.5,0,-3>}
        texture{e3d_tex_silver}
    }
}
#end

#macro IC_SMD_DFS()
IC_SMD_DFS_GRND()
#end


/********************************************************************************************************************************************
//Makro fuer SMD-IC's die Pins nur auf 2-Seiten haben(SO, TSOP, TSSOP usw.)
//ueberarbeitet von Tilmann Reh <tilmann.reh(replace with at)autometer.de>
//erweitert fuer DPAK Friedrich Bleikamp <fbleikamp(replace with at)web.de>
//LK      = Laenge des Kunststoff(Seite der Pins)
//BK      = Breite des Kunststoff(Seite ohne Pins)
//HK      = Hoehe des Kunststoff
//B       = Laenge der Seite ohne Pins ueber alles
//pin_u   = Pins auf der "unteren" Seite
//pin_o   = Pins auf der "oberen" Seite
//ptch_u  = Pitch der Pins auf der "unteren" Seite
//ptch_o  = Pitch der Pins auf der "oberen" Seite
//pinb_u  = Breite der Pins auf der "unteren" Seite
//pinb_o  = Breite der Pins auf der  "oberen" Seite
//pin_s   = Staerke des Pinmaterials
//di_pcb  = Abstand des Kunststoff zur Platine
//kor_w   = Korrekturwinkel
//pin0_m  = Pin-1-Markierung: 0 = keine, 1 = Farbklecks, 2 = Kerbe wie bei DIP, 3 = PowerSO, 4 = DPAK
//pin0_45 = Wenn != 0 wird an der unteren Seite ein Winkel am Koerper von 45° statt 10° verwendet (SO)
//pin0_a  = Abstand des Pin0-Kennzeichners vom Rand
//besch_s = Scalefaktor der Beschriftung
//besch_w = Wenn != 0 wird Beschriftung gedreht
//logo  = Name of the logo
********************************************************************************************************************************************/
#macro IC_SMD_GRND(LK,BK,HK,B,pin_u,pin_o,ptch_u,ptch_o,pinb_u,pinb_o,pin_s,di_pcb,kor_w,pin0_m,pin0_45,pin0_a,besch_s,besch_w,logo)
union{
    difference{
        box{<LK/2,di_pcb,BK/2><-LK/2,di_pcb+HK,-BK/2>}
        box{<LK/2+0.01,0,0><-LK/2-0.1,-HK,1>  rotate<10,0,0> translate<0,(di_pcb+HK)/2-pin_s/2,BK/2>}
        box{<LK/2+0.01,0,0><-LK/2-0.1,-HK,-1>  rotate<-10,0,0> translate<0,(di_pcb+HK)/2-pin_s/2,-BK/2>}
        box{<LK/2+0.01,0,0><-LK/2-0.1,HK,1>  rotate<-10,0,0> translate<0,(di_pcb+HK)/2+pin_s/2,BK/2>}
        box{<LK/2+0.01,0,0><-LK/2-0.1,HK,-1>  rotate<10,0,0> translate<0,(di_pcb+HK)/2+pin_s/2,-BK/2>}
        #if(pin0_45!=0)
            box{<LK/2+0.01,0,0><-LK/2-0.1,HK,-1>  rotate<45,0,0> translate<0,(di_pcb+HK)/2+pin_s/2+pin_s*1.5,-BK/2>}
        #end
        box{<0,0,-BK/2-0.1><1,HK,BK/2+0.1>  rotate<0,0,10> translate<LK/2,(di_pcb+HK)/2+pin_s/2,0>}
        box{<0,0,-BK/2-0.1><-1,HK,BK/2+0.1>  rotate<0,0,-10> translate<-LK/2,(di_pcb+HK)/2+pin_s/2,0>}
        box{<0,0,-BK/2-0.1><1,-HK,BK/2+0.1>  rotate<0,0,-10> translate<LK/2,(di_pcb+HK)/2-pin_s/2,0>}
        box{<0,0,-BK/2-0.1><-1,-HK,BK/2+0.1>  rotate<0,0,10> translate<-LK/2,(di_pcb+HK)/2-pin_s/2,0>}
        #if(pin0_m = 0)
            #local TextX = -LK/2+0.1*LK;
        #end // ohne Pin-1-Markierung
        #if(pin0_m = 1)  // SO-Farbmarkierung
            #local TextX = -LK/2+0.1*LK;
            #if((((pin_u-1)/2*ptch_u)+0.3)>LK/2)
                #local i = -(pin_u-1)/2*ptch_u+0.3;
            #else
                #local i = -(pin_u-1)/2*ptch_u;
            #end
            sphere{<i,HK+di_pcb+0.1,-BK/2+pin0_a>0.15 texture{e3d_tex_ic_marking_bright}}
        #end
        #if(pin0_m = 2)  // VSO-Kerbe
            #local TextX = -LK/2+0.15*LK;
            cylinder{<-LK/2,di_pcb+0.7*HK,0><-LK/2,di_pcb+HK+0.1,0> 1}
        #end
        #if(pin0_m = 3)  // PSO-Kerben und Fase (vereinfacht rechteckig)
            #local TextX = -LK/2+0.25*LK;
            box{<3,di_pcb-0.1,-3> <-3,HK+di_pcb+0.1,0> rotate<0,45,0> translate<1-LK/2,0,1-BK/2>}
            box{<0,di_pcb-0.1,-1.45> <-2,HK+di_pcb+0.1,1.45> translate<1.45-LK/2,0,0>}
            box{<0,di_pcb-0.1,-1.45> <2,HK+di_pcb+0.1,1.45> translate<-1.45+LK/2,0,0>}
        #end

        #if(pin0_m = 4) // fuer DPAK ohne Pin-1-Markierung
            #local TextX = -LK/2+0.15*LK;
        #end
    }
    #if(pin0_m = 3)  // PSO-Metallboden (vereinfacht, da der Rest sowieso unsichtbar bleibt)
        box{<-LK/2,0,-1.5> <LK/2,1,1.5> texture{e3d_tex_silver}}
    #end

    #if(pin0_m = 4)  // DPAK-SEATING PLANE & BLIND PIN
            box{<-pinb_u/2,(HK+di_pcb)/2+pin_s/2,-(BK/2+1)> <pinb_u/2,(HK+di_pcb)/2-pin_s/2,-(BK/2-0.1)> texture{e3d_tex_silver}}
            box{<-0.57,0,-5.25> <0.57,0.5,-4.5> translate<ptch_u/2,0,0> texture{e3d_tex_silver}}
            box{<-0.57,0,-5.25> <0.57,0.5,-4.5> translate<-ptch_u/2,0,0> texture{e3d_tex_silver}}
            difference{
                box{<-2.5,0,-0.85> <2.5,0.55,4.5>}
                box{<-0.5,-0.1,-0.5> <0.5,1.1,0.5> rotate <0,45,0> translate<-2.5,0,4.5>}
                box{<-0.5,-0.1,-0.5> <0.5,0.6,0.5> rotate <0,45,0> translate<2.5,0,4.5>}
                texture{e3d_tex_silver}
            }
    #end

    union{
        #local i=0;
        #while(i<(pin_u/2))
            #if((pin_u/2)=div(pin_u,2))
                object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_u,pin_s) rotate<0,90,0> translate<ptch_u*i+ptch_u/2,0,-BK/2>}
                object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_u,pin_s) rotate<0,90,0> translate<-ptch_u*i-ptch_u/2,0,-BK/2>}
            #else
                object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_u,pin_s) rotate<0,90,0> translate<ptch_u*i,0,-BK/2>}
                object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_u,pin_s) rotate<0,90,0> translate<-ptch_u*i,0,-BK/2>}
            #end
            #local i=i+1;
        #end

        #local i=0;
        #while(i<(pin_o/2))
            #if((pin_o/2)=div(pin_o,2))
                object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_o,pin_s) rotate<0,-90,0> translate<ptch_o*i+ptch_o/2,0,BK/2>}
                object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_o,pin_s) rotate<0,-90,0> translate<-ptch_o*i-ptch_o/2,0,BK/2>}
            #else
                object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_o,pin_s) rotate<0,-90,0> translate<ptch_o*i,0,BK/2>}
                object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_o,pin_s) rotate<0,-90,0> translate<-ptch_o*i,0,BK/2>}
            #end
        #local i=i+1;
        #end
        texture{e3d_tex_silver}
    }

    #local value_arial_size_min = 0.0;
    #local value_arial_size_max = 0.0;
    #local value_arial_size = 0.0;
    #local value_courier_size_min = 0.0;
    #local value_courier_size_max = 0.0;
    #local value_courier_size = 0.0;
    #local value_arial_bold =  text{ttf global_fontfile_arial_bold value 0.2,0 rotate<90,-90,0>}
    #local value_courier_bold = text{ttf global_fontfile_courier_bold value 0.2,0 rotate<90,-90,0>}
    Extents(value_arial_bold, value_arial_size_min, value_arial_size_max)
    Extents(value_courier_bold, value_courier_size_min, value_courier_size_max)
    #local value_arial_size = value_arial_size_max - value_arial_size_min;
    #local value_courier_size = value_courier_size_max - value_courier_size_min;
    #local value_scale_factor_arial = LK/value_arial_size.z * 0.5;
    #local value_scale_factor_courier = LK/value_courier_size.z * 0.5;

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
    #local value_datecode_arial_bold = text{ttf global_fontfile_arial_bold value_datecode_string 0.2,0 rotate<90,-90,0>}
    #local value_datecode_courier_bold = text{ttf global_fontfile_arial_bold value_datecode_string 0.2,0 rotate<90,-90,0>}
    Extents(value_datecode_arial_bold, value_datecode_arial_size_min, value_datecode_arial_size_max)
    Extents(value_datecode_courier_bold, value_courier_size_min, value_courier_size_max)
    #local value_datecode_arial_size = value_datecode_arial_size_max - value_datecode_arial_size_min;
    #local value_datecode_courier_size = value_courier_size_max - value_courier_size_min;
    #local value_datecode_scale_factor_arial = value_scale_factor_arial;
    #local value_datecode_scale_factor_courier = value_scale_factor_courier;
    #local value_datecode_arial_size = value_datecode_arial_size * value_scale_factor_arial;
    #local value_datecode_courier_size = value_datecode_courier_size * value_scale_factor_courier;

    // added logos. now with Atmel, FTDI, Microchip, Philips, and ST
    // by xocas

    #local logo_assigned = 0;

    union{
        #if(strcmp(logo,"PHILIPS")=0.0)
                #local logo_assigned = 1;
                #local label = union{
                    text{ttf global_fontfile_eagle3d "p" 0.2,0 scale<besch_s*2,besch_s*2,1> rotate<90,0,0> translate<-LK/3,0,0>}
                    text{ttf global_fontfile_arial value 0.2,0 rotate<90,0,0> scale<value_scale_factor_arial,1,value_scale_factor_arial> translate<-value_arial_size.z/2,0,-value_arial_size.x/2-BK/6>}
                    translate<0,HK+di_pcb+0.001,0>
                }
        #end

        #if(strcmp(logo,"MICROCHIP")=0.0)
            #local logo_assigned = 1;
            #local label = union{
                text{ttf global_fontfile_eagle3d "m" 0.2,0 scale<besch_s*2,besch_s*2,1> rotate<90,0,0> translate<-LK/3,0,0>}
                text{ttf global_fontfile_arial value 0.2,0 rotate<90,0,0> scale<value_scale_factor_arial,1,value_scale_factor_arial> translate<-value_arial_size.z/2,0,-value_arial_size.x/2-BK/6>}
                translate<0,HK+di_pcb+0.001,0>
            }
         #end
         #if(strcmp(logo,"ST")=0.0)
            #local logo_assigned = 1;
            #local label = union{
                text{ttf global_fontfile_eagle3d "s" 0.2,0 scale<besch_s*2,besch_s*2,1> rotate<90,0,0> translate<-LK/2.5,0,-BK/3>}
                text{ttf global_fontfile_arial value 0.2,0 rotate<90,0,0> scale<value_scale_factor_arial,1,value_scale_factor_arial> translate<-value_arial_size.z/2,0,value_arial_size.x/2>}
                translate<0,HK+di_pcb+0.001,0>
            }
        #end

        #if(strcmp(logo,"ATMEL")=0.0)
            #local logo_assigned = 1;
            #local label = union{
                text{ttf global_fontfile_eagle3d "a" 0.2,0 scale<besch_s*2,besch_s*2,1> rotate<90,0,0> translate<-LK/3,0,0>}
                text{ttf global_fontfile_arial value 0.2,0 rotate<90,0,0> scale<value_scale_factor_arial,1,value_scale_factor_arial> translate<-value_arial_size.z/2,0,-value_arial_size.x/2-BK/6>}
                translate<0,HK+di_pcb+0.001,0>
            }
        #end

        #if(strcmp(logo,"FTDI")=0.0)
            #local logo_assigned = 1;
            #local label = union{
                text{ttf global_fontfile_eagle3d "f" 0.2,0 scale<besch_s*2,besch_s*2,1> rotate<90,0,0> translate<-LK/3,0,0>}
                text{ttf global_fontfile_arial value 0.2,0 rotate<90,0,0> scale<value_scale_factor_arial,1,value_scale_factor_arial> translate<-value_arial_size.z/2,0,-value_arial_size.x/2-BK/6>}
                translate<0,HK+di_pcb+0.001,0>
            }
        #end

        #if(strcmp(logo,"TEXAS")=0.0)
            #local logo_assigned = 1;
            #local label = union{
                text{ttf global_fontfile_eagle3d "t" 0.2,0 scale<besch_s*2,besch_s*2,1> rotate<90,0,0> translate<-LK/3,0,0>}
                text{ttf global_fontfile_arial value 0.2,0 rotate<90,0,0> scale<value_scale_factor_arial,1,value_scale_factor_arial> translate<-value_arial_size.z/2,0,-value_arial_size.x/2-BK/6>}
                translate<0,HK+di_pcb+0.001,0>
            }
        #end

        #if(logo_assigned < 0.5)
            #local label = text{ttf besch_font value 0.2,0 rotate<90,0,0> scale<besch_s,1,besch_s> translate<TextX,HK+di_pcb+0.01,-besch_s/2> }
        #end

        #if(besch_w=0)
            object{label}
        #else
            object{label rotate<0,270,0>}
        #end
        texture{e3d_tex_ic_marking_bright}
    }
    rotate<0,kor_w,0>
    texture{e3d_tex_ic_body_1}
}
#end

// JEDEC MO-193AA
#macro IC_SMD_TSOP6(value,logo)
IC_SMD_GRND(2.9,1.6,0.9, 2.8, 3,3, 0.95,0.95, 0.4,0.4,0.2, 0.1,0, 1,0,0.3,0.6,0,logo)
#end
#macro IC_SMD_SO8(value,logo)
IC_SMD_GRND(4.9,3.9,1.35,6,4,4,1.27,1.27,0.4,0.4,0.22,0.18,0,1,1,3.9/5,3.9/5,0,logo)
#end
#macro IC_SMD_SO14(value,logo)
IC_SMD_GRND(8.65,3.9,1.35,6,7,7,1.27,1.27,0.4,0.4,0.22,0.18,0,1,1,3.9/5,3.9/4,0,logo)
#end
#macro IC_SMD_SO16(value,logo)
IC_SMD_GRND(9.9,3.9,1.35,6,8,8,1.27,1.27,0.4,0.4,0.22,0.18,0,1,1,3.9/5,3.9/4,0,logo)
#end
#macro IC_SMD_SO16W(value,logo)
IC_SMD_GRND(10.3,7.5,2.35,10.3,8,8,1.27,1.27,0.4,0.4,0.27,0.2,0,1,1,7.5/6,7.5/5,0,logo)
#end
#macro IC_SMD_UMAX10(value,logo)
IC_SMD_GRND(3,3,0.8,4.9,5,5,0.5,0.5,0.22,0.22,0.13,0.1,0,1,0,0.4,0.7,0,logo)
#end
#macro IC_SMD_UMAX8(value,logo)
IC_SMD_GRND(3,3,0.8,4.9,4,4,0.65,0.65,0.3,0.3,0.13,0.1,0,1,0,0.4,0.7,0,logo)
#end
//Rudi Hofer <rudi.hofer@t-online.de>
#macro IC_SMD_SO18W(value,logo)
IC_SMD_GRND(11.6,7.5,2.35,10.3,9,9,1.27,1.27,0.4,0.4,0.27,0.2,0,1,1,7.5/6,7.5/5,0,logo)
#end
#macro IC_SMD_SO20W(value,logo)
IC_SMD_GRND(12.8,7.5,2.35,10.3,10,10,1.27,1.27,0.4,0.4,0.27,0.2,0,1,1,7.5/6,7.5/5,0,logo)
#end
#macro IC_SMD_SO24W(value,logo)
IC_SMD_GRND(15.4,7.5,2.35,10.3,12,12,1.27,1.27,0.4,0.4,0.27,0.2,0,1,1,7.5/6,7.5/5,0,logo)
#end
#macro IC_SMD_SO28W(value,logo)
IC_SMD_GRND(17.9,7.5,2.35,10.3,14,14,1.27,1.27,0.4,0.4,0.27,0.2,0,1,1,7.5/6,7.5/5,0,logo)
#end
#macro IC_SMD_SO32_400(value,logo)
IC_SMD_GRND(20.5,7.5,2.35,10.3,16,16,1.27,1.27,0.4,0.4,0.27,0.2,0,1,1,7.5/6,7.5/5,0,logo)
#end
#macro IC_SMD_SO32_525(value,logo)
IC_SMD_GRND(20.5,11.43,2.74,14.12,16,16,1.27,1.27,0.4,0.4,0.2,0.05,0,1,1,7.5/5,7.5/5,0,logo)
#end
#macro IC_SMD_TSSOP8(value,logo)
IC_SMD_GRND(2.9,4.4,1,6.4,4,4,0.65,0.65,0.22,0.22,0.15,0.1,0,1,0,0.5,0.6,1,logo)
#end
#macro IC_SMD_TSSOP14(value,logo)
IC_SMD_GRND(5,4.4,1.1,6.375,7,7,0.65,0.65,0.22,0.22,0.15,0.1,0,1,0,0.5,0.8,0,logo)
#end
#macro IC_SMD_TSSOP16(value,logo)
IC_SMD_GRND(5.2,4.4,1.1,6.375,8,8,0.65,0.65,0.22,0.22,0.15,0.1,0,1,0,0.5,0.8,0,logo)
#end
#macro IC_SMD_TSSOP20(value,logo)
IC_SMD_GRND(6.5,4.4,1.1,6.375,10,10,0.65,0.65,0.22,0.22,0.15,0.1,0,1,0,0.5,1.0,0,logo)
#end
#macro IC_SMD_TSSOP24(value,logo)
IC_SMD_GRND(7.8,4.4,1.1,6.375,12,12,0.65,0.65,0.22,0.22,0.15,0.1,0,1,0,0.5,1.1,0,logo)
#end
#macro IC_SMD_TSSOP28(value,logo)
IC_SMD_GRND(9.7,4.4,1.1,6.375,14,14,0.65,0.65,0.22,0.22,0.15,0.1,0,1,0,0.5,1.1,0,logo)
#end
#macro IC_SMD_TSSOP38(value,logo)
IC_SMD_GRND(9.7,4.4,1.1,6.4,19,19,0.5,0.5,0.22,0.22,0.15,0.1,0,1,0,0.5,1.1,0,logo)
#end
#macro IC_SMD_TSSOP48(value,logo)
IC_SMD_GRND(12.5,6.1,0.95,8.1,24,24,0.5,0.5,0.22,0.22,0.15,0.1,0,1,0,0.5,1.1,0,logo)
#end
#macro IC_SMD_TSSOP56(value,logo)
IC_SMD_GRND(14,6.1,0.95,8.1,28,28,0.5,0.5,0.22,0.22,0.15,0.1,0,1,0,0.5,1.1,0,logo)
#end
#macro IC_SMD_TSSOP64(value,logo)
IC_SMD_GRND(17,6.1,0.95,8.1,32,32,0.5,0.5,0.22,0.22,0.15,0.1,0,1,0,0.5,1.1,0,logo)
#end
#macro IC_SMD_QSOP16(value,logo)
IC_SMD_GRND(4.9,3.9,1.45,6,8,8,0.635,0.635,0.25,0.25,0.225,0.15,0,1,1,0.7,0.7,0,logo)
#end
#macro IC_SMD_QSOP20(value,logo)
IC_SMD_GRND(8.65,3.9,1.45,6,10,10,0.635,0.635,0.25,0.25,0.225,0.15,0,1,1,0.7,1.1,0,logo)
#end
#macro IC_SMD_QSOP24(value,logo)
IC_SMD_GRND(8.65,3.9,1.45,6,12,12,0.635,0.635,0.25,0.25,0.225,0.15,0,1,1,0.7,1.1,0,logo)
#end
#macro IC_SMD_QSOP28(value,logo)
IC_SMD_GRND(9.9,3.9,1.45,6,14,14,0.635,0.635,0.25,0.25,0.225,0.15,0,1,1,0.7,1.1,0,logo)
#end
#macro IC_SMD_SSOP14(value,logo)
IC_SMD_GRND(6.2,5.3,1.7,7.7,7,7,0.65,0.65,0.32,0.32,0.15,0.15,0,1,0,0.5,0.85,0,logo)
#end
#macro IC_SMD_SSOP16(value,logo)
IC_SMD_GRND(6.2,5.3,1.7,7.7,8,8,0.65,0.65,0.32,0.32,0.15,0.15,0,1,0,0.5,0.85,0,logo)
#end
#macro IC_SMD_SSOP20(value,logo)
IC_SMD_GRND(7.2,5.3,1.7,7.7,10,10,0.65,0.65,0.32,0.32,0.15,0.15,0,1,0,0.5,0.95,0,logo)
#end
#macro IC_SMD_SSOP24(value,logo)
IC_SMD_GRND(8.2,5.3,1.7,7.7,12,12,0.65,0.65,0.32,0.32,0.15,0.15,0,1,0,0.5,0.95,0,logo)
#end
#macro IC_SMD_SSOP28(value,logo)
IC_SMD_GRND(10.2,5.3,1.7,7.7,14,14,0.65,0.65,0.32,0.32,0.15,0.15,0,1,0,0.5,0.95,0,logo)
#end
#macro IC_SMD_SSOP30(value,logo)
IC_SMD_GRND(10.2,6.1,1.2,8.1,15,15,0.65,0.65,0.24,0.24,0.15,0.1,0,1,0,0.5,0.95,0,logo)
#end
#macro IC_SMD_SSOP48(value,logo)
IC_SMD_GRND(15.8,7.5,2.25,10.2,24,24,0.635,0.635,0.25,0.25,0.15,0.3,0,1,0,0.5,1.1,0,logo)
#end
//Joseph Zeglinski
#macro IC_SMD_SSOP56DL(value,logo)
IC_SMD_GRND(18.4,7.5,2.25,10.2,28,28,0.635,0.635,0.25,0.25,0.15,0.3,0,1,0,0.5,1.1,0,logo)
#end
#macro IC_SMD_SSOP56(value,logo)
IC_SMD_GRND(23.7,13.3,2.25,10.2,28,28,0.635,0.635,0.25,0.25,0.15,0.3,0,1,0,0.5,1.1,0,logo)
#end
#macro IC_SMD_TSOPII28(value,logo)
IC_SMD_GRND(18.4,10.1,1,11.7,14,14,1.27,1.27,0.4,0.4,0.15,0.1,0,1,0,0.5,1.5,0,logo)
#end
#macro IC_SMD_TSOPII32(value,logo)
IC_SMD_GRND(20.95,10.1,1,11.7,16,16,1.27,1.27,0.4,0.4,0.15,0.1,0,1,0,0.5,1.5,0,logo)
#end
#macro IC_SMD_TSOPII44(value,logo)
IC_SMD_GRND(18.3,10.1,1,11.7,22,22,0.8,0.8,0.375,0.375,0.15,0.1,0,1,0,0.5,1.5,0,logo)
#end
#macro IC_SMD_TSOPII50(value,logo)
IC_SMD_GRND(20.95,10.1,1,11.7,25,25,0.8,0.8,0.375,0.375,0.15,0.1,0,1,0,0.5,1.5,0,logo)
#end
#macro IC_SMD_TSOPII54(value,logo)
IC_SMD_GRND(22.22,10.1,1,11.7,27,27,0.8,0.8,0.375,0.375,0.15,0.1,0,1,0,0.5,1.5,0,logo)
#end
#macro IC_SMD_TSOPII86(value,logo)
IC_SMD_GRND(22.22,10.1,1,11.7,43,43,0.5,0.5,0.22,0.22,0.15,0.1,0,1,0,0.5,1.5,0,logo)
#end
#macro IC_SMD_TSOP28_13MM(value,logo)
IC_SMD_GRND(8,11.8,1,13.4,14,14,0.55,0.55,0.22,0.22,0.13,0.1,90,1,0,0.5,1.1,1,logo)
#end
#macro IC_SMD_TSOP32_13MM(value,logo)
IC_SMD_GRND(8,11.8,1,13.4,16,16,0.5,0.5,0.22,0.22,0.13,0.1,90,1,0,0.5,1.1,1,logo)
#end
#macro IC_SMD_TSOP32(value,logo)
IC_SMD_GRND(8,18.4,1.1,20,16,16,0.5,0.5,0.22,0.22,0.13,0.1,90,1,0,0.5,1.1,1,logo)
#end
#macro IC_SMD_TSOP48(value,logo)
IC_SMD_GRND(12,18.4,1.1,20,24,24,0.5,0.5,0.22,0.22,0.13,0.1,90,1,0,0.5,1.1,1,logo)
#end
#macro IC_SMD_TSOP56(value,logo)
IC_SMD_GRND(14,18.4,1.1,20,28,28,0.5,0.5,0.22,0.22,0.13,0.1,90,1,0,0.5,1.1,1,logo)
#end
//Tilmann Reh <tilmann.reh@autometer.de>
#macro IC_SMD_VSO40(value,logo)
IC_SMD_GRND(15.4,7.55,2.35,12.05,20,20,0.762,0.762,0.36,0.36,0.18,0.2,0,2,0,7.5/6,7.5/5,0,logo)
#end
#macro IC_SMD_VSO56(value,logo)
IC_SMD_GRND(21.7,11.05,2.9,15.5,28,28,0.75,0.75,0.36,0.36,0.18,0.2,0,2,0,11/6,11/5,0,logo)
#end
#macro IC_SMD_PSO20(value,logo)
IC_SMD_GRND(15.9,11,3.3,14.2,10,10,1.27,1.27,0.47,0.47,0.28,0.2,0,3,0,7.5/6,7.5/5,0,logo)
#end
#macro IC_SMD_PSO36(value,logo)
IC_SMD_GRND(15.9,11,3.3,14.2,18,18,0.65,0.65,0.3,0.3,0.28,0.2,0,3,0,7.5/6,7.5/5,0,logo)
#end
#macro IC_SMD_MSOP10(value,logo)
IC_SMD_GRND(3,3,0.85,4.9,5,5,0.5,0.5,0.25,0.25,0.15,0.1,0,1,0,0.5,0.65,0,logo)
#end
#macro IC_SMD_SOT23(value,logo)
IC_SMD_GRND(2.9,1.3,1,2.8,2,1,1.9,1.9,0.45,0.45,0.13,0.1,0,0,0,1.5,0.7,0,logo)
#end
#macro IC_SMD_SOT23_5(value,logo)
IC_SMD_GRND(2.9,1.6,1,2.8,3,2,0.95,1.90,0.35,0.35,0.13,0.1,0,0,0,1.5,0.7,0,logo)
#end
#macro IC_SMD_SOT23_6(value,logo)
IC_SMD_GRND(2.9,1.6,1,2.8,3,3,0.95,0.95,0.35,0.35,0.13,0.1,0,1,0,0.3,0.7,0,logo)
#end
#macro IC_SMD_SOT223(value,logo)
IC_SMD_GRND(6.5,3.5,1.6,7,3,1,2.3,2.3,0.75,3,0.2,0.2,0,0,0,0,1.0,0,logo)
#end
#macro IC_SMD_SOT363(value,logo)
IC_SMD_GRND(2.0,1.25,1.0,2.1,3,3,0.65,0.65,0.25,0.25,0.15,0.1,0,1,0,0,0.5,0,logo)
#end
//SMD-Transistoren aus SIC_GRND abgeleitet
#macro IC_TR_SOT23(value,logo)
IC_SMD_GRND(2.9,1.3,1,2.8,2,1,1.9,1.9,0.45,0.45,0.13,0.1,0,0,0,1.5,0.7,0,logo)
#end
#macro IC_TR_TO252(value,logo)
IC_SMD_GRND(6.1,6.5,2.2,10,2,1,4.5,1.9,0.9,5.3,0.5,0.1,0,0,0,1.5,1.0,0,logo)
#end
#macro IC_TR_TO263(value,logo)
IC_SMD_GRND(10.2,8.7,4.2,15.2,2,1,5.1,1.9,1.4,10.2,0.5,0.1,0,0,0,1.5,1.0,0,logo)
#end
// Friedrich Bleikamp
#macro IC_SMD_DPAK_369C(value,logo)
IC_SMD_GRND(6.1,6.5,2.2,11,2,0,4.5,0,0.8,0,0.5,0.1,0,4,0,1.5,1.0,0,logo)
#end
#macro IC_SMD_TSOP86(value,logo)
IC_SMD_GRND(22.22,10.16,1.2,11.76,43,43,0.5,0.5,0.2,0.2,0.12,0.1,0,2,0,3.9/5,3.9/5,0,logo)
#end


/********************************************************************************************************************************************
//Macros for SMD bridge MB2S from Vishay TO
//Designed by Philippe Boucheny <philippe.boucheny(at)free.fr>
//Rev. 1.0  16/12/06
********************************************************************************************************************************************/
#macro IC_SMD_MB2S_GRND(code)
union{
    
    //Body
    difference{
        box{<-2.35,0.3,-1.95><+2.35,2.65,+1.95>}
        box{<-2.36,-0.5,0.5><+2.36,0.5,-0.5> rotate +45*x translate<0,2.65+0.1,-1.95-0.1>}
        box{<-2.36,-0.5,0.8><+2.36,0.5,-0.8> rotate +80*x translate<0,2.65-0.5,+1.95+0.4>}
        box{<-2.36,-0.5,0.8><+2.36,0.5,-0.8> rotate -80*x translate<0,2.65-0.5,-1.95-0.4>}
        box{<-2.36,-0.5,0.8><+2.36,0.5,-0.8> rotate -80*x translate<0,1.325-0.5,+1.95+0.4>}
        box{<-2.36,-0.5,0.8><+2.36,0.5,-0.8> rotate +80*x translate<0,1.325-0.5,-1.95-0.4>}
        box{<-1,-0.5,2><+1,0.5,-2> rotate +80*z translate<-2.5-0.2,2.65-0.5,0>}
        box{<-1,-0.5,2><+1,0.5,-2> rotate -80*z translate<-2.5-0.2,1.325-0.5,0>}
        box{<-1,-0.5,2><+1,0.5,-2> rotate -80*z translate<+2.5+0.2,2.65-0.5,0>}
        box{<-1,-0.5,2><+1,0.5,-2> rotate +80*z translate<+2.5+0.2,1.325-0.5,0>}
        texture{e3d_tex_ic_body_1}
    }
    
    // Marking
    union{
        text {ttf global_fontfile_arial_bold code 0.02, 0  scale 1.2 rotate<90,180,0> translate<+0.45,2.66,-0.2>}  
        text {ttf global_fontfile_arial_bold "2N3" 0.02, 0 scale 1.2 rotate<90,180,0> translate<+1.2,2.66,+1.3>}
        text {ttf global_fontfile_arial_bold "-" 0.02, 0   scale 1 rotate<90,0,0> translate<+1.07,2.66,-1.35>}
        text {ttf global_fontfile_arial_bold "+" 0.02, 0   scale 1 rotate<90,0,0> translate<-1.27,2.66,-1.4>}
        texture{e3d_tex_ic_marking_bright}
    }
    
    //Pins
    union
    {
        object {IC_SMD_PIN(1.5,1.5,0.6,0.3) rotate -90*y translate<-1.27,0,1.9>}
        object {IC_SMD_PIN(1.5,1.5,0.6,0.3) rotate -90*y translate<+1.27,0,1.9>}
        object {IC_SMD_PIN(1.5,1.5,0.6,0.3) rotate +90*y translate<-1.27,0,-1.9>}
        object {IC_SMD_PIN(1.5,1.5,0.6,0.3) rotate +90*y translate<+1.27,0,-1.9>}
        texture{e3d_tex_silver}
    }
}
#end

#macro IC_SMD_MB2S()
IC_SMD_MB2S_GRND("2")
#end
#macro IC_SMD_MB4S()
IC_SMD_MB2S_GRND("4")
#end
#macro IC_SMD_MB6S()
IC_SMD_MB2S_GRND("6")
#end


/********************************************************************************************************************************************
//LK    = Laenge des Kunststoff (x-Achse)
//BK    = Breite des Kunststoff (z-Achse)
//H     = Hoehe des Kunststoff (Y-Achse)
//pin_l = Anzahl Pins links
//pin_r = Anzahl Pins rechts
//pin_o = Anzahl Pins "oben"
//pin_u = Anzahl Pins "unten"
//pitch = Abstand der einzelnen Pins
//pin_br= Breite eines Pins
//pin_h = Höhe eines Pins
//pin_t = Tiefe eines Pins
//HKoP  = Hoehe des Kunststoffs ueber der Platine (Y-Achse)
//KORW  = Korrekturwinkel
//kp1ab = Wenn 0, wird Abschraegung an Pin1 erzeugt
//cool_x= Kühlfläche unter dem Chip (X-Achse)
//cool_z= Kühlfläche unter dem Chip (Z-Achse)
********************************************************************************************************************************************/
#macro IC_SMD_MLF_GRND(LK,BK,H,pin_l,pin_r,pin_o,pin_u,pitch,pin_br,pin_h,pin_t,HKoP,KORW,kp1ab,cool_x,cool_z)
/********************************************************************************************************************************************
//Makro fuer Pins von MLF-Gehaeusen
//H = Hoehe des Pins
//B = Breite des Pins
//T = Tiefe des Pins
********************************************************************************************************************************************/
union{

    #macro MLF_PIN(H,B,T)
        union{
            box{<-B/2,0,0><+B/2,H,T-B/2>}
            cylinder{<0,0,T-B/2><0,H,T-B/2>,B/2}
            texture{e3d_tex_silver}
        }
    #end
    
    union{
        difference{
            box{<-LK/2,HKoP,-BK/2><LK/2,HKoP+H,BK/2>}
            #if(kp1ab=0)
                box{<0,0,-3><-2,5,3> rotate<0,-45,0> translate<-LK/2+LK/40,0,-BK/2+BK/40>}
            #end
            cylinder{<0,H+HKoP-0.1,0><0,H+HKoP+1,0>0.4 translate<-LK/2+LK/10,0,-BK/2+BK/10>}
            texture{e3d_tex_ic_body_1}
            }
        }
    
    #local scl_fa = BK/10;
    text{ttf besch_font value 0.2,0 scale<scl_fa,scl_fa,1> rotate<90,-90,0> translate<-LK/2+LK/4,H+HKoP+0.001,-BK/2+BK/6> texture{e3d_tex_ic_marking_bright} }

    // Kühlfläche des Dies unter dem Chip
    #if((cool_x!=0) & (cool_z!=0))
        object{TOOLS_PCB_SMD(cool_x,cool_z,H/2,15) texture{e3d_tex_silver}}
    #end

    // Pins auf linker Seite
    #local i=0;
    #while(i<(pin_l/2))
        object{MLF_PIN(pin_h,pin_br,pin_t) translate<-(div(pin_l,2)-i)*pitch,0,-BK/2-0.01> rotate<0,90,0> }
        object{MLF_PIN(pin_h,pin_br,pin_t) translate<+(div(pin_l,2)-i)*pitch,0,-BK/2-0.01> rotate<0,90,0> }
        #local i=i+1;
    #end
    // Pins auf rechter Seite
    #local i=0;
    #while(i<(pin_r/2))
        object{MLF_PIN(pin_h,pin_br,pin_t) translate<-(div(pin_r,2)-i)*pitch,0,-BK/2-0.01> rotate<0,-90,0> }
        object{MLF_PIN(pin_h,pin_br,pin_t) translate<+(div(pin_r,2)-i)*pitch,0,-BK/2-0.01> rotate<0,-90,0> }
        #local i=i+1;
    #end
    // Pins auf vorderen/"unteren" Seite
    #local i=0;
    #while(i<pin_u)
        object{MLF_PIN(pin_h,pin_br,pin_t) translate<-(div(pin_u,2)-i)*pitch,0,-LK/2-0.01>}
        object{MLF_PIN(pin_h,pin_br,pin_t) translate<+(div(pin_u,2)-i)*pitch,0,-LK/2-0.01>}
        #local i=i+1;
    #end
    // Pins auf hinteren/"oberen" Seite
    #local i=0;
    #while(i<pin_o)
        object{MLF_PIN(pin_h,pin_br,pin_t) translate<-(div(pin_o,2)-i)*pitch,0,-LK/2-0.01> rotate<0,180,0> }
        object{MLF_PIN(pin_h,pin_br,pin_t) translate<+(div(pin_o,2)-i)*pitch,0,-LK/2-0.01> rotate<0,180,0> }
        #local i=i+1;
    #end
    rotate<0,KORW,0>
}
#end

//MLP-28 aus CP2102-GM Datasheet
#macro IC_SMD_MLF_28_050MM(value)
IC_SMD_MLF_GRND(5,5,0.9,7,7,7,7,0.5,0.23,0.25,0.55,0.02,0,1,3.15,3.15)
#end
//MLF-32 aus ATmega8 Datasheet
#macro IC_SMD_MLF_32_050MM(value)
IC_SMD_MLF_GRND(5,5,0.9,8,8,8,8,0.5,0.23,0.25,0.60,0.02,0,1,3.1,3.1)
#end
//MLF-44 aus ATmega16 Datasheet
#macro IC_SMD_MLF_44_050MM(value)
IC_SMD_MLF_GRND(7,7,0.9,11,11,11,11,0.5,0.23,0.25,0.64,0.02,0,1,5,5)
#end
//MLF-32 aus ATmega128 Datasheet
#macro IC_SMD_MLF_64_050MM(value)
IC_SMD_MLF_GRND(9,9,0.9,16,16,16,16,0.5,0.23,0.25,0.60,0.02,0,1,5.4,5.4)
#end


/********************************************************************************************************************************************
//PLCC
********************************************************************************************************************************************/
#macro IC_SMD_PLCC_GRND(xsize,ysize,oupin,lrpin,valsize)
union{
    
    //Body
    union{
        difference{
            box{<0,0,0><xsize,4.05,ysize>}
            box{<-0.1,0,0><xsize+0.1,3,-1> rotate<10,0,0> translate<0,2.15,0>}
            box{<-0.1,0,0><xsize+0.1,3,1> rotate<-10,0,0> translate<0,2.15,ysize>}
            box{<-1,-3,-0.1><0,0,ysize+0.1> rotate<0,0,10> translate<0,1.85,0>}
            box{<1,-3,-0.1><0,0,ysize+0.1> rotate<0,0,-10> translate<xsize,1.85,0>}
            box{<-1,3,-0.1><0,0,ysize+0.1> rotate<0,0,-10> translate<0,2.15,0>}
            box{<1,3,-0.1><0,0,ysize+0.1> rotate<0,0,10> translate<xsize,2.15,0>}
            box{<-0.1,0,0><xsize+0.1,-3,-1> rotate<-10,0,0> translate<0,1.85,0>}
            box{<-0.1,0,0><xsize+0.1,-3,1> rotate<10,0,0> translate<0,1.85,ysize>}
            box{<-0.1,0,0><xsize+0.1,3,1> rotate<-45,0,0> translate<0,3,ysize>}
            box{<0,-0.1,-3><-2,4.5,3> rotate<0,45,0> translate<0.8,0,ysize-0.8>}
            sphere{<xsize/2,4.05,ysize-2>0.5 texture{e3d_tex_ic_marking_bright}}
        }
        
        //Marking
        text{ttf besch_font value 0.2,0 scale<valsize,valsize,valsize> rotate<90,0,0> translate<1.5,4.051,ysize/2> texture{e3d_tex_ic_marking_bright} }
        
        translate<-xsize/2,0,-ysize/2>
        texture{e3d_tex_ic_body_1}
    }
    
    //Pins
    union{
        #local i=0;
        #while(i<(oupin)/2)
            object{IC_SMD_PLCC_PIN() translate<i*1.27,-0.7,-ysize/2>}
            object{IC_SMD_PLCC_PIN() translate<-i*1.27,-0.7,-ysize/2>}
            object{IC_SMD_PLCC_PIN() rotate<0,180,0> translate<i*1.27,-0.7,ysize/2>}
            object{IC_SMD_PLCC_PIN() rotate<0,180,0> translate<-i*1.27,-0.7,ysize/2>}
        #local i=i+1;
        #end
        #local i=0;
        #while(i<(lrpin)/2)
            object{IC_SMD_PLCC_PIN() rotate<0,90,0> translate<-xsize/2,-0.7,i*1.27>}
            object{IC_SMD_PLCC_PIN() rotate<0,90,0> translate<-xsize/2,-0.7,-i*1.27>}
            object{IC_SMD_PLCC_PIN() rotate<0,-90,0> translate<xsize/2,-0.7,i*1.27>}
            object{IC_SMD_PLCC_PIN() rotate<0,-90,0> translate<xsize/2,-0.7,-i*1.27>}
        #local i=i+1;
        #end
        texture{e3d_tex_silver}
    }
}
#end

#macro IC_SMD_PLCC20(value)
IC_SMD_PLCC_GRND(9,9,5,5,1.2)
#end
#macro IC_SMD_PLCC28(value)
IC_SMD_PLCC_GRND(11.45,11.45,7,7,1.5)
#end
#macro IC_SMD_PLCC32(value)
IC_SMD_PLCC_GRND(11.45,14,7,9,1.5)
#end
#macro IC_SMD_PLCC44(value)
IC_SMD_PLCC_GRND(16.5,16.5,11,11,2)
#end
#macro IC_SMD_PLCC52(value)
IC_SMD_PLCC_GRND(19.1,19.1,13,13,2.5)
#end
#macro IC_SMD_PLCC68(value)
IC_SMD_PLCC_GRND(24.1,24.1,17,17,3)
#end
#macro IC_SMD_PLCC84(value)
IC_SMD_PLCC_GRND(29.25,29.25,21,21,3)
#end


/********************************************************************************************************************************************
//Makro fuer 4-pin SMD-IC's mit Pins nur auf 2-Seiten (SO, TSOP, TSSOP usw.)
//Bas Laarhoven <aesmail@xs4all.nl>
//LK      = Laenge des Kunststoff(Seite der Pins)
//BK      = Breite des Kunststoff(Seite ohne Pins)
//HK      = Hoehe des Kunststoff
//B       = Laenge der Seite ohne Pins ueber alles
//pinb_1  = Breite der Pin 1
//pinb_x  = Breite der anderen Pins
//pin_s   = Staerke des Pinmaterials
//di_pcb  = Abstand des Kunststoff zur Platine
//kor_w   = Korrekturwinkel
//pin0_m  = Pin-1-Markierung: 0 = keine, 1 = Farbklecks, 2 = Kerbe wie bei DIP, 3 = PowerSO, 4 = DPAK
//pin0_45 = Wenn != 0 wird an der unteren Seite ein Winkel am Koerper von 45° statt 10° verwendet (SO)
//pin0_a  = Abstand des Pin0-Kennzeichners vom Rand
//besch_s = Scalefaktor der Beschriftung
********************************************************************************************************************************************/
#macro IC_SMD_SOT143_GRND(LK,BK,HK,B,pinb_1,pinb_x,pin_s,di_pcb,kor_w,pin0_m,pin0_45,pin0_a,besch_s)
union{
    difference{
        box{<LK/2,di_pcb,BK/2><-LK/2,di_pcb+HK,-BK/2>}
        box{<LK/2+0.01,0,0><-LK/2-0.1,-HK,1>  rotate<10,0,0> translate<0,(di_pcb+HK)/2-pin_s/2,BK/2>}
        box{<LK/2+0.01,0,0><-LK/2-0.1,-HK,-1>  rotate<-10,0,0> translate<0,(di_pcb+HK)/2-pin_s/2,-BK/2>}
        box{<LK/2+0.01,0,0><-LK/2-0.1,HK,1>  rotate<-10,0,0> translate<0,(di_pcb+HK)/2+pin_s/2,BK/2>}
        box{<LK/2+0.01,0,0><-LK/2-0.1,HK,-1>  rotate<10,0,0> translate<0,(di_pcb+HK)/2+pin_s/2,-BK/2>}
        #if(pin0_45!=0)
            box{<LK/2+0.01,0,0><-LK/2-0.1,HK,-1>  rotate<45,0,0> translate<0,(di_pcb+HK)/2+pin_s/2+pin_s*1.5,-BK/2>}
        #end
        box{<0,0,-BK/2-0.1><1,HK,BK/2+0.1>  rotate<0,0,10> translate<LK/2,(di_pcb+HK)/2+pin_s/2,0>}
        box{<0,0,-BK/2-0.1><-1,HK,BK/2+0.1>  rotate<0,0,-10> translate<-LK/2,(di_pcb+HK)/2+pin_s/2,0>}
        box{<0,0,-BK/2-0.1><1,-HK,BK/2+0.1>  rotate<0,0,-10> translate<LK/2,(di_pcb+HK)/2-pin_s/2,0>}
        box{<0,0,-BK/2-0.1><-1,-HK,BK/2+0.1>  rotate<0,0,10> translate<-LK/2,(di_pcb+HK)/2-pin_s/2,0>}
        #if(pin0_m = 0)
            #local TextX = -LK/2+0.1*LK;
        #end // ohne Pin-1-Markierung
    }
    
    union{       
        object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_x,pin_s) rotate<0,90,0> translate<0.95,0,-BK/2>}
        object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_1,pin_s) rotate<0,90,0> translate<-0.75,0,-BK/2>}
        object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_x,pin_s) rotate<0,-90,0> translate<0.95,0,BK/2>}
        object{IC_SMD_PIN((HK+di_pcb)/2+pin_s/2,(B-BK)/2,pinb_x,pin_s) rotate<0,-90,0> translate<-0.95,0,BK/2>}
        texture{e3d_tex_silver}
    }
      
    text{ttf besch_font value 0.2,0 rotate<90,0,0> scale<besch_s,1,besch_s> translate<TextX,HK+di_pcb+0.01,-besch_s/2> texture{e3d_tex_ic_marking_bright} }
    
    rotate<0,kor_w,0>
    
    texture{e3d_tex_ic_body_1}
}
#end

#macro IC_SMD_SOT143(value)
IC_SMD_SOT143_GRND(3.0,1.4,1.1,2.9,0.88,0.48,0.12,0.1,0,0,30,0,0.7)
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
