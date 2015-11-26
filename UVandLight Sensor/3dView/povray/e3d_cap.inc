//Eagle3D 20110101 INC-File e3d_cap.inc
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
 
#ifndef(__cap_inc)
#declare __cap_inc = true;

#ifndef(inc_testmode)
#declare inc_testmode=true;
#include "e3d_tools.inc"
#undef inc_testmode
#end

/********************************************************************************************************************************************
//Joerg Bredendiek <sprut(replace with at)sprut.de>  
//based on WIMA-Cap-macro by Andreas Rebmann <A.Rebmann-Elektrotechnik@t-online.de>
//Grundmacro - Breite=B , Tiefe = T, Hoehe = H, Raster = Ra
********************************************************************************************************************************************/
#macro CAP_DIS_BLOCK_GRND(B,T,H,Ra)
union{

    box{<-B/2+0.2, 0,     T/2>     <B/2-0.2,H-0.2,-T/2>      rotate<0,0,0> translate<0,0,0>} //Grundkörper
    box{<-B/2,     0,    -T/2+0.2> <B/2,    H-0.2, T/2-0.2>  rotate<0,0,0> translate<0,0,0>} //Kleine Box innen
    box{<-B/2+0.2, H-0.2,-T/2+0.2> <B/2-0.2,H    , T/2-0.2>  rotate<0,0,0> translate<0,0,0>} //Kleine Box oben

    cylinder{<-B/2+0.2,0,0> <-B/2+0.2, H-0.2> 0.20  rotate<0,0,0> translate <0, 0,  T/2-0.2>} //Rundungen rechts
    cylinder{<-B/2+0.2,0,0> <-B/2+0.2, H-0.2> 0.20  rotate<0,0,0> translate <0, 0,-T/2+0.2>} //Rundungen rechts
    cylinder{< B/2-0.2,0,0> < B/2-0.2, H-0.2> 0.20  rotate<0,0,0> translate <0, 0,  T/2-0.2>} //Rundungen links
    cylinder{< B/2-0.2,0,0> < B/2-0.2, H-0.2> 0.20  rotate<0,0,0> translate <0, 0, -T/2+0.2>} //Rundungen links

    sphere{< B/2-0.2, H-0.2, T/2-0.2> 0.2 scale <1,1,1>  translate<0,0,0>}  //Rundungen oben
    sphere{< B/2-0.2, H-0.2,-T/2+0.2> 0.2 scale <1,1,1>  translate<0,0,0>}  //Rundungen oben
    sphere{<-B/2+0.2, H-0.2, T/2-0.2> 0.2 scale <1,1,1>  translate<0,0,0>}  //Rundungen oben
    sphere{<-B/2+0.2, H-0.2,-T/2+0.2> 0.2 scale <1,1,1>  translate<0,0,0>}  //Rundungen oben

    cylinder{<-B/2+0.2,  H-0.2> < B/2-0.2, H-0.2> 0.20 rotate<0,0,0> translate <0, 0, T/2-0.2>}   //Rundungen vorne
    cylinder{<-B/2+0.2,  H-0.2> < B/2-0.2, H-0.2> 0.20 rotate<0,0,0> translate <0, 0,-T/2+0.2>}   //Rundungen hinten
    cylinder{<-T/2+0.2,  H-0.2> < 0, H-0.2> 0.20 rotate<0, 90,0> translate <-B/2+0.2, 0, 0>}  //Rundungen rechts kurz
    cylinder{<-T/2+0.2,  H-0.2> < 0, H-0.2> 0.20 rotate<0,-90,0> translate <-B/2+0.2, 0, 0>}  //Rundungen rechts kurz
    cylinder{<-T/2+0.2,  H-0.2> < 0, H-0.2> 0.20 rotate<0, 90,0> translate < B/2-0.2, 0, 0>}  //Rundungen links kurz
    cylinder{<-T/2+0.2,  H-0.2> < 0, H-0.2> 0.20 rotate<0,-90,0> translate < B/2-0.2, 0, 0>}  //Rundungen links kurz

    //Drahtdurchmesser und Beschriftung an die Kondensatorgröße anpassen

    #if(pin_short=on)
        #local block_pin_length = -1*(pin_length+pcb_height);
    #else
        #local block_pin_length = -5;
    #end

    #if (Ra=10.16)    //d=0.7mm
        cylinder{<-Ra/2 ,0> <-Ra/2,block_pin_length,0> 0.35 texture{e3d_tex_silver}}   // Draht rechts senkrecht
        cylinder{< Ra/2 ,0> < Ra/2,block_pin_length,0> 0.35 texture{e3d_tex_silver}}   // Draht links senkrecht
        text {ttf besch_font  value   0.1, 0 scale<2.4,2.4,2.4> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-2.5, H-6.0, T/2+0.1> rotate<0,0,0>} //Beschriftung Value
    #end

    #if (Ra=15.24)    //d=0.8mm
        cylinder{<-Ra/2 ,0> <-Ra/2,block_pin_length,0> 0.40 texture{e3d_tex_silver}}   // Draht rechts senkrecht
        cylinder{< Ra/2 ,0> < Ra/2,block_pin_length,0> 0.40 texture{e3d_tex_silver}}   // Draht links senkrecht
        text {ttf besch_font  value   0.1, 0 scale<3.0,3.0,3.0> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-4.0, H-7.0, T/2+0.1> rotate<0,0,0>} //Beschriftung Value
    #end

    #if (Ra=22.5)    //d=0.8mm
        cylinder{<-Ra/2 ,0> <-Ra/2,block_pin_length,0> 0.40 texture{e3d_tex_silver}}   // Draht rechts senkrecht
        cylinder{< Ra/2 ,0> < Ra/2,block_pin_length,0> 0.40 texture{e3d_tex_silver}}   // Draht links senkrecht
        text {ttf besch_font  value   0.1, 0 scale<3.5,3.5,3.5> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-6.5, H-9.0, T/2+0.1> rotate<0,0,0>} //Beschriftung Value
    #end

    #if (Ra=27.5)    //d=1.0mm
        cylinder{<-Ra/2 ,0> <-Ra/2,block_pin_length,0> 0.50 texture{e3d_tex_silver}}   // Draht rechts senkrecht
        cylinder{< Ra/2 ,0> < Ra/2,block_pin_length,0> 0.50 texture{e3d_tex_silver}}   // Draht links senkrecht
        text {ttf besch_font  value   0.1, 0 scale<4.0,4.0,4.0> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-10.0, H-12.0, T/2+0.1> rotate<0,0,0>} //Beschriftung Value
    #end

    #if (Ra=32.5)    //d=1.0mm
        cylinder{<-Ra/2 ,0> <-Ra/2,block_pin_length,0> 0.50 texture{e3d_tex_silver}}   // Draht rechts senkrecht
        cylinder{< Ra/2 ,0> < Ra/2,block_pin_length,0> 0.50 texture{e3d_tex_silver}}   // Draht links senkrecht
        text {ttf besch_font  value   0.1, 0 scale<4.0,4.0,4.0> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-10.0, H-12.0, T/2+0.1> rotate<0,0,0>} //Beschriftung Value
    #end

    #if (Ra=37.5)    //d=1.0mm
        cylinder{<-Ra/2 ,0> <-Ra/2,block_pin_length,0> 0.50 texture{e3d_tex_silver}}   // Draht rechts senkrecht
        cylinder{< Ra/2 ,0> < Ra/2,block_pin_length,0> 0.50 texture{e3d_tex_silver}}   // Draht links senkrecht
        text {ttf besch_font  value   0.1, 0 scale<4.5,4.5,4.5> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-15.0, H-15.0, T/2+0.1> rotate<0,0,0>} //Beschriftung Value
    #end

    // hellblau
    texture{e3d_tex_cap_block_blue}
}   
#end

//C102-043X133:  rcl.lbr:   CAPACITOR, ,  grid 10.2 mm, outline 4.3 x 13.3 mm
//C102-054X133:  rcl.lbr:   CAPACITOR, ,  grid 10.2 mm, outline 5.4 x 13.3 mm
//C102-064X133:  rcl.lbr:   CAPACITOR, ,  grid 10.2 mm, outline 6.4 x 13.3 mm
//Raster 10
#macro CAP_DIS_BLOCK_100_040_130_095(value)
CAP_DIS_BLOCK_GRND(13.2, 4.2, 9.5, 10.16)
#end
#macro CAP_DIS_BLOCK_100_050_130_110(value)
CAP_DIS_BLOCK_GRND(13.2, 5.3, 11.0, 10.16)
#end
#macro CAP_DIS_BLOCK_100_060_130_120(value)
CAP_DIS_BLOCK_GRND(13.2, 6.3, 12.0, 10.16)
#end
//
//C150-054X183:  rcl.lbr:   CAPACITOR, ,  grid 15 mm, outline 5.4 x 18.3 mm
//C150-064X183:  rcl.lbr:   CAPACITOR, ,  grid 15 mm, outline 6.4 x 18.3 mm
//C150-072X183:  rcl.lbr:   CAPACITOR, ,  grid 15 mm, outline 7.2 x 18.3 mm
//C150-084X183:  rcl.lbr:   CAPACITOR, ,  grid 15 mm, outline 8.4 x 18.3 mm
//C150-091X182:  rcl.lbr:   CAPACITOR, ,  grid 15 mm, outline 9.1 x 18.2 mm
//Raster 15
#macro CAP_DIS_BLOCK_150_050_180_110(value)
CAP_DIS_BLOCK_GRND(18.2,5.3,11.0,15.24)
#end
#macro CAP_DIS_BLOCK_150_060_180_125(value)
CAP_DIS_BLOCK_GRND(18.2,6.3,12.5,15.24)
#end
#macro CAP_DIS_BLOCK_150_070_180_140(value)
CAP_DIS_BLOCK_GRND(18.2,7.1,14.0,15.24)
#end
#macro CAP_DIS_BLOCK_150_080_180_150(value)
CAP_DIS_BLOCK_GRND(18.2,8.3,15.0,15.24)
#end
#macro CAP_DIS_BLOCK_150_090_180_160(value)
CAP_DIS_BLOCK_GRND(18.1,9.0,16.0,15.24)
#end
//
//C225-062X268:  rcl.lbr:   CAPACITOR, ,  grid 22.5 mm, outline 6.2 x 26.8 mm
//C225-074X268:  rcl.lbr:   CAPACITOR, ,  grid 22.5 mm, outline 7.4 x 26.8 mm
//C225-087X268:  rcl.lbr:   CAPACITOR, ,  grid 22.5 mm, outline 8.7 x 26.8 mm
//C225-108X268:  rcl.lbr:   CAPACITOR, ,  grid 22.5 mm, outline 10.8 x 26.8 mm
//C225-113X268:  rcl.lbr:   CAPACITOR, ,  grid 22.5 mm, outline 11.3 x 26.8 mm
//Raster 22.5
#macro CAP_DIS_BLOCK_225_060_265_150(value)
CAP_DIS_BLOCK_GRND(26.7,6.1,15.0,22.5)
#end
#macro CAP_DIS_BLOCK_225_070_265_165(value)
CAP_DIS_BLOCK_GRND(26.7,7.3,16.5,22.5)
#end
#macro CAP_DIS_BLOCK_225_085_265_185(value)
CAP_DIS_BLOCK_GRND(26.7,8.6,18.5,22.5)
#end
#macro CAP_DIS_BLOCK_225_105_265_190(value)
CAP_DIS_BLOCK_GRND(26.7,10.7,19.0,22.5)
#end
#macro CAP_DIS_BLOCK_225_110_265_210(value)
CAP_DIS_BLOCK_GRND(26.7,11.2,21.0,22.5)
#end
//
//C275-093X316:  rcl.lbr:   CAPACITOR, ,  grid 27.5 mm, outline 9.3 x 31.6 mm
//C275-113X316:  rcl.lbr:   CAPACITOR, ,  grid 27.5 mm, outline 11.3 x 31.6 mm
//C275-134X316:  rcl.lbr:   CAPACITOR, ,  grid 27.5 mm, outline 13.4 x 31.6 mm
//C275-154X316:  rcl.lbr:   CAPACITOR, ,  grid 27.5 mm, outline 15.4 x 31.6 mm
//C275-173X316:  rcl.lbr:   CAPACITOR, ,  grid 27.5 mm, outline 17.3 x 31.6 mm
//C275-205X316:  rcl.lbr:   CAPACITOR, ,  grid 27.5 mm, outline 20.5 x 31.6 mm
//Raster 27.5
#macro CAP_DIS_BLOCK_275_090_315_210(value)
CAP_DIS_BLOCK_GRND(31.5,9.2,21.0,27.5)
#end
#macro CAP_DIS_BLOCK_275_110_315_210(value)
CAP_DIS_BLOCK_GRND(31.5,11.2,21.0,27.5)
#end
#macro CAP_DIS_BLOCK_275_130_315_240(value)
CAP_DIS_BLOCK_GRND(31.5,13.3,24.0,27.5)
#end
#macro CAP_DIS_BLOCK_275_150_315_260(value)
CAP_DIS_BLOCK_GRND(31.5,15.1,26.0,27.5)
#end
#macro CAP_DIS_BLOCK_275_170_315_345(value)
CAP_DIS_BLOCK_GRND(31.5,17.2,34.5,27.5)
#end
#macro CAP_DIS_BLOCK_275_200_315_395(value)
CAP_DIS_BLOCK_GRND(31.5,20.4,39.5,27.5)
#end
//
//C325-137X374:  rcl.lbr:   CAPACITOR, ,  grid 32.5 mm, outline 13.7 x 37.4 mm
//C325-162X374:  rcl.lbr:   CAPACITOR, ,  grid 32.5 mm, outline 16.2 x 37.4 mm
//C325-182X374:  rcl.lbr:   CAPACITOR, ,  grid 32.5 mm, outline 18.2 x 37.4 mm
//Raster 32.5
#macro CAP_DIS_BLOCK_325_140_415_260(value)
CAP_DIS_BLOCK_GRND(41.5,15.0,26.0,32.5)
#end
#macro CAP_DIS_BLOCK_325_160_415_320(value)
CAP_DIS_BLOCK_GRND(41.5,19.0,32.0,32.5)
#end
#macro CAP_DIS_BLOCK_325_180_415_395(value)
CAP_DIS_BLOCK_GRND(41.5,20.0,39.5,32.5)
#end
//
//C375-155X418:  rcl.lbr:   CAPACITOR, ,  grid 37.5 mm, outline 15.5 x 41.8 mm
//C375-192X418:  rcl.lbr:   CAPACITOR, ,  grid 37.5 mm, outline 19.2 x 41.8 mm
//C375-203X418:  rcl.lbr:   CAPACITOR, ,  grid 37.5 mm, outline 20.3 x 41.8 mm
//Raster 37.5
#macro CAP_DIS_BLOCK_375_150_415_260(value)
CAP_DIS_BLOCK_GRND(41.7,15.4,26.0,37.5)
#end
#macro CAP_DIS_BLOCK_375_190_415_320(value)
CAP_DIS_BLOCK_GRND(41.7,19.1,32.0,37.5)
#end
#macro CAP_DIS_BLOCK_375_200_415_395(value)
CAP_DIS_BLOCK_GRND(41.7,20.2,39.5,37.5)
#end


/********************************************************************************************************************************************
// Auth: David Harris
//
// Disk syle capacitors
// Macro Calling Arguments:  
//   diam1      = diameter of the main circumference
//   value      = Eagle "value" (capacitance etc.) - this is printed on the capacitors
//   leadspc    = lead spacing
//   bcolour    = body colour
//   tcolour    = text colour
********************************************************************************************************************************************/
#macro CAP_DIS_CERAMIC_DISK_GRND(diam1, value, leadspc, bcolour, tcolour)
    #local diam = diam1/2;
    #local cap = object {superellipsoid{<1, 1>scale<diam,diam*0.25,diam>rotate <-90,-7.5,0>translate<0,diam*1.1,0>} } 
    #local txt = text{ ttf besch_font ,value,40,0 scale<diam/3,diam/3,diam/3> translate<-diam/1.5,diam,-20>} 
    #local leg = object{ cylinder {  <0,diam*0.2,0>,<0,-10.0>,0.25 texture{col_silver}}}  
    #local ls2 = leadspc/2 ;
    union{ 
        object{ intersection{ object{txt} object{cap} } translate <0,0,-0.05> pigment{tcolour} }
        object {cap pigment{bcolour}}
        difference{
            torus { leadspc/2, 0.25 rotate -90*x  pigment{bcolour} }
            box { <-leadspc,0,0.5>, <leadspc,-leadspc,-0.5> }
            translate <0,diam*0.2,0>  
        } 
        object{ leg translate<-ls2,0,0> }
        object{ leg translate< ls2,0,0> }
        translate <0,0,0> 
        pigment{bcolour}
    } 
#end

//6,4mm leadpsacing 5mm diameter
#macro CAP_DIS_CERAMIC_DISK_64MM_50MM(value)
CAP_DIS_CERAMIC_DISK_GRND(5.0, value, 6.35, Brown, Black)
#end
//6, 4mm leadpsacing 6, 5mm diameter
#macro CAP_DIS_CERAMIC_DISK_64MM_65MM(value)
CAP_DIS_CERAMIC_DISK_GRND(6.5, value, 6.35, Red, Black)
#end
//6, 4mm leadpsacing 7, 4mm diameter
#macro CAP_DIS_CERAMIC_DISK_64MM_74MM(value)
CAP_DIS_CERAMIC_DISK_GRND(7.37, value, 6.35, Orange, Black)
#end
//6, 4mm leadpsacing 10mm diameter
#macro CAP_DIS_CERAMIC_DISK_64MM_100MM(value)
CAP_DIS_CERAMIC_DISK_GRND(10.01, value, 6.35, Yellow, Black)
#end
//6, 4mm leadpsacing 12mm diameter
#macro CAP_DIS_CERAMIC_DISK_64MM_120MM(value)
CAP_DIS_CERAMIC_DISK_GRND(11.99, value, 6.35, Green, Black)
#end
//5mm leadpsacing 6mm diameter
#macro CAP_DIS_CERAMIC_DISK_05MM_06MM(value)
CAP_DIS_CERAMIC_DISK_GRND(6, value, 5.08, Brown, Black)
#end
//5mm leadpsacing 8mm diameter
#macro CAP_DIS_CERAMIC_DISK_05MM_08MM(value)
CAP_DIS_CERAMIC_DISK_GRND(8, value, 5.08, Red, Black)
#end
//5mm leadpsacing 10mm diameter
#macro CAP_DIS_CERAMIC_DISK_05MM_10MM(value)
CAP_DIS_CERAMIC_DISK_GRND(10, value, 5.08, Orange, Black)
#end
//5mm leadpsacing 13mm diameter
#macro CAP_DIS_CERAMIC_DISK_05MM_13MM(value)
CAP_DIS_CERAMIC_DISK_GRND(13, value, 5.08, Yellow, Black)
#end
//10mm leadpsacing 13mm diameter
#macro CAP_DIS_CERAMIC_DISK_10MM_13MM(value)
CAP_DIS_CERAMIC_DISK_GRND(13.5, value, 10.16, Green, Black)
#end
//10mm leadpsacing 18mm diameter
#macro CAP_DIS_CERAMIC_DISK_10MM_18MM(value)
CAP_DIS_CERAMIC_DISK_GRND(18, value, 10.16, Blue, Black)
#end
//10mm leadpsacing 25mm diameter
#macro CAP_DIS_CERAMIC_DISK_10MM_25MM(value)
CAP_DIS_CERAMIC_DISK_GRND(25, value, 10.16, Gray, Blue)
#end


/********************************************************************************************************************************************
// Auth: David Harris
//
// Ceramic capacitors
// Macro Calling Arguments:  
//   diam1      = diameter of the main circumference
//   value      = Eagle "value" (capacitance etc.) - this is printed on the capacitors
//   leadspc    = lead spacing
//   bcolour    = body colour
//   tcolour    = text colour
********************************************************************************************************************************************/
#macro CAP_DIS_CERAMIC_GRND(diam1,value,leadspc,bcolour,tcolour)
 #local diam = diam1/2;
 #local cap = object {superellipsoid{<1, 1>scale<diam,diam*0.25,diam>rotate <-90,-7.5,0>translate<0,diam*1.1,0>} } 
 #local txt = text{ ttf besch_font,value,40,0 scale<diam/3,diam/3,diam/3> translate<-diam/1.5,diam,-20>} 
 #local leg = object{ cylinder {  <0,diam*0.2,0>,<0,-10.0>,0.25 texture{col_silver}}}  
 #local ls2 = leadspc/2 ;
 union{ 
  object{ intersection{ object{txt} object{cap} } translate <0,0,-0.05> pigment{tcolour} }
  object {cap pigment{bcolour}}
  difference{
   torus { leadspc/2, 0.25 rotate -90*x  pigment{bcolour} }
   box { <-leadspc,0,0.5>, <leadspc,-leadspc,-0.5> }
   translate <0,diam*0.2,0>  
  } 
  object{ leg translate<-ls2,0,0> }
  object{ leg translate< ls2,0,0> }
 pigment{bcolour}
 translate <0,0,0> 
 } 
 #end    
#macro CAP_DIS_CERAMIC_25MM_38MM(value)
CAP_DIS_CERAMIC_GRND(3.81,value,2.54,Red,Black)
#end
#macro CAP_DIS_CERAMIC_25MM_44MM(value)
CAP_DIS_CERAMIC_GRND(4.4,value,2.54,Red,Black)
#end
#macro CAP_DIS_CERAMIC_25MM_50MM(value)
CAP_DIS_CERAMIC_GRND(5.08,value,2.54,Yellow,Black)
#end
#macro CAP_DIS_CERAMIC_50MM_38MM(value)
CAP_DIS_CERAMIC_GRND(3.81,value,5.08,Orange,Black)
#end
#macro CAP_DIS_CERAMIC_50MM_44MM(value)
CAP_DIS_CERAMIC_GRND(4.40,value,5.08,Red,Black)
#end
#macro CAP_DIS_CERAMIC_50MM_50MM(value)
CAP_DIS_CERAMIC_GRND(5.08,value,5.08,Blue,Black)
#end
#macro CAP_DIS_CERAMIC_50MM_76MM(value)
CAP_DIS_CERAMIC_GRND(7.62,value,5.08,Yellow,Black)
#end
#macro CAP_DIS_CERAMIC_50MM_100MM(value)
CAP_DIS_CERAMIC_GRND(10.16,value,5.08,Gray,Black) 
#end
#macro CAP_DIS_CERAMIC_75MM_100MM(value)
CAP_DIS_CERAMIC_GRND(10.16,value,7.62,Gray,Black)
#end


/********************************************************************************************************************************************
//Macros for axial CTS tantale capacitor
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.0 du 06/01/06
// Macro Calling Arguments:  
//   diam       = diameter of the main circumference
//   Lg         = length
//   value      = Eagle "value" (capacitance etc.) - this is printed on the capacitors
//   r          = Pitch / Pas
//   lw         = pins length / Longeur des pattes
//   dw         = pins width / Largeur des pattes
********************************************************************************************************************************************/
#macro CAP_DIS_CTS_GRND(diam,Lg,Lt,r,lw,dw,value)
union{

#local rr=diam/2*0.7;
#local rrr=0.8;

    difference{
        //Body
        cylinder {<-Lg/2,0,0><+Lg/2,0,0> diam/2-0.1 }
        //Plus side
        union{
            torus{ rr rrr rotate <90,90,0> translate<-Lg/2,0,0> }
            cylinder{<-Lg/2-rrr,0,0><-Lg/2+rrr,0,0> rr}
        }
        texture{e3d_tex_silver}
    }
    //Plus pin
    cylinder {<-Lg/2-Lt+rrr,0,0><-Lg/2+1,0,0> dw*1.5 texture{Aluminum}}
    //pins
    object{TOOLS_WIRE_LEADS(Lg,diam,lw*2,dw,r,global_res_bend_radius,0,"H")}
    //Text value
    intersection{
        cylinder {<-Lg/2,0,0><+Lg/2,0,0> diam/2-0.1 }
        union{
                text {ttf global_fontfile_arial "+" 2,0 scale(Lg/20.8)*3  rotate<-90,180,180> translate<-Lg/2.5,diam/2,-(diam/9.1)*1.5 > }
                text {ttf global_fontfile_arial value 2,0  scale diam/9.1*3 rotate<-90,180,180> translate<-Lg/3.5,diam/2,-(diam/9.1)*1.5> }
        }
        texture{e3d_tex_cap_marking_black}
        translate +0.01*y
    }
    
    translate diam/2*y
}
#end

//CTS13 case A 15mm
#macro CAP_DIS_CTS_A_15MM(value)
CAP_DIS_CTS_GRND(3.6,8.1,2.1,6*2.54,30,0.5,value)
#end
//CTS13 case B 20mm
#macro CAP_DIS_CTS_B_20MM(value)
CAP_DIS_CTS_GRND(4.9,12.8,2.2,8*2.54,30,0.5,value)
#end
//CTS13 case C 25mm
#macro CAP_DIS_CTS_C_25MM(value)
CAP_DIS_CTS_GRND(7.5,18.2,2.3,10*2.54,30,0.6,value)
#end
//CTS13 case D 30mm
#macro CAP_DIS_CTS_D_30MM(value)
CAP_DIS_CTS_GRND(9.1,20.8,3.2,12*2.54,30,0.6,value)
#end


/********************************************************************************************************************************************
//Axial-Elko Grundmakro   
********************************************************************************************************************************************/
#macro CAP_DIS_ELKO_AXIAL_GRND(val_size,dis,dia,dia_b,value)
union{
    union{
        
        //Elko Koerper
        difference{
            union{
                cylinder{<0,dis/2-3.5,0><0,-(dis/2-3.5),0>dia}                            
                //Elko Rundung oben
                torus{dia-0.5,0.5 translate<0,-(dis/2-3.5),0>}                            
                difference{
                    cylinder{<0,-(dis/2-3.5),0><0,-(dis/2-3.0),0>dia-0.5}
                    cylinder{<0,-(dis/2-3.5),0><0,-(dis/2-2.9),0>dia*0.8*pow(dia/16,0.11)}
                }
                //Elko Rundung unten
                torus{dia-0.5,0.5 translate<0,dis/2-3.5,0>}
                difference{
                    cylinder{<0,dis/2-3.5,0><0,dis/2-3.0,0>dia-0.5}
                    cylinder{<0,dis/2-3.5,0><0,dis/2-2.9,0>dia*0.8*pow(dia/16,0.11)}
                }
            }
            
            //Aussparung unten
            torus{dia+0.85,1 translate<0,dis/2-5,0>}                                    
            
            //Textur fuer Minusmarkierung
            pigment{                                                                    
                    image_map{png "tex_elko_axial.png" map_type 2 interpolate 4}
                    scale <dia*2*pi*1.35,dia*2*pi,dia*2*pi*1.35>                
            }
            finish{reflection { 0.03, 0.1}  phong 0.4 crand 0.05 ambient (0.1 * global_ambient_mul) }        
        }
        
        //Abdeckung oben
        cylinder{<0,-(dis/2-3.6),0><0,-(dis/2-3.1),0>dia*0.8*pow(dia/16,0.11)           
            texture{e3d_tex_silver}
        }

        //Abdeckung unten
        cylinder{<0,dis/2-3.2,0><0,dis/2-3.5,0>dia-0.5 pigment{Black}}                  
        
        //Kontakt
        cylinder{<0,-(dis/2-3.2),0><0,-(dis/2-2),0> 1.5 texture{e3d_tex_silver}}            
        intersection{
            cylinder{<0,dis/2,0><0,-dis/2 + val_size + 3.5,0>dia}
            text {ttf besch_font value 0.2, 0 scale val_size rotate<0,0,-90> translate<0, dis/4,-dia>}
            rotate<0,10,0>
            translate<0,-val_size,-0.001>
            pigment {rgb<0.4,0.6,1>}
        }
        intersection{
            cylinder{<0,dis/2,0><0,-dis/2 + val_size + 3.5,0>dia}
            text {ttf besch_font value 0.2, 0 scale val_size rotate<0,0,-90> translate<0, dis/4,-dia>}
            rotate<0,100,0>
            translate<-0.001,-val_size,0>
            pigment {rgb<0.4,0.6,1>}
        }
        intersection{
            cylinder{<0,dis/2,0><0,-dis/2 + val_size + 3.5,0>dia}
            text {ttf besch_font value 0.2, 0 scale val_size rotate<0,0,-90> translate<0, dis/4,-dia>}
            rotate<0,190,0>
            translate<0,-val_size,0.001>
            pigment {rgb<0.4,0.6,1>}
        }
        rotate<0,180,>
        rotate<0,0,90>
    }
    object{TOOLS_WIRE_LEADS (dis-7, dia, 35, dia_b,  dis,  global_res_bend_radius, 0, "H")}

    pigment{Red}
    finish{F_MetalE ambient (0.1 * global_ambient_mul)}
    translate<0,dia,0>
}
#end

#macro CAP_DIS_ELKO_AXIAL_15MM_5MM(value)
CAP_DIS_ELKO_AXIAL_GRND(2,15.24,5/2,0.8/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_15MM_6MM(value)
CAP_DIS_ELKO_AXIAL_GRND(2,15.24,6/2,0.8/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_15MM_9MM(value)
CAP_DIS_ELKO_AXIAL_GRND(2,15.24,9/2,0.8/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_22MM_6MM(value)
CAP_DIS_ELKO_AXIAL_GRND(2,22.86,6/2,0.8/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_22MM_9MM(value)
CAP_DIS_ELKO_AXIAL_GRND(2,22.86,9/2,0.8/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_22MM_10MM(value)
CAP_DIS_ELKO_AXIAL_GRND(2,22.86,10/2,0.8/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_25MM_9MM(value)
CAP_DIS_ELKO_AXIAL_GRND(3,25.4,9/2,0.8/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_25MM_10MM(value)
CAP_DIS_ELKO_AXIAL_GRND(3,25.4,10/2,0.8/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_30MM_10MM(value)
CAP_DIS_ELKO_AXIAL_GRND(3,30.48,10/2,0.8/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_30MM_12MM(value)
CAP_DIS_ELKO_AXIAL_GRND(3,30.48,12/2,0.8/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_30MM_16MM(value)
CAP_DIS_ELKO_AXIAL_GRND(3,30.48,16/2,0.8/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_35MM_12MM(value)
CAP_DIS_ELKO_AXIAL_GRND(4,35.56,12/2,0.8/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_35MM_14MM(value)
CAP_DIS_ELKO_AXIAL_GRND(4,35.56,14/2,0.8/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_35MM_16MM(value)
CAP_DIS_ELKO_AXIAL_GRND(4,35.56,16/2,0.8/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_35MM_18MM(value)
CAP_DIS_ELKO_AXIAL_GRND(4,35.56,18/2,0.8/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_45MM_16MM(value)
CAP_DIS_ELKO_AXIAL_GRND(5,45.72,16/2,0.8/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_45MM_18MM(value)
CAP_DIS_ELKO_AXIAL_GRND(5,45.72,18/2,0.8/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_45MM_21MM(value)
CAP_DIS_ELKO_AXIAL_GRND(5,45.72,21/2,0.8/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_45MM_22MM(value)
CAP_DIS_ELKO_AXIAL_GRND(5,45.72,22/2,0.8/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_45MM_25MM(value)
CAP_DIS_ELKO_AXIAL_GRND(5,45.72,25/2,1/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_50MM_25MM(value)
CAP_DIS_ELKO_AXIAL_GRND(5,50,25/2,1/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_50MM_30MM(value)
CAP_DIS_ELKO_AXIAL_GRND(5,50,30/2,1/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_55MM_25MM(value)
CAP_DIS_ELKO_AXIAL_GRND(5,55.88,25/2,1/2,value)
#end
#macro CAP_DIS_ELKO_AXIAL_55MM_30MM(value)
CAP_DIS_ELKO_AXIAL_GRND(5,55.88,30/2,1/2,value)
#end


/********************************************************************************************************************************************
//Elko Grundmakro   
//bearbeitet von Walter Mücke
//tex_scale     vector um die Textur zu strecken/stauchen
//val_size      Größe der Beschriftung
//dis           Abstand der Pins      
//dia           Radius des Elkos 
//hig           Höhe des Kondensator 
//dia_b         Radius des Anschlußdrahtes
//value         Beschriftungstext            
********************************************************************************************************************************************/
#macro CAP_DIS_ELKO_GRND(tex_scale,val_size,dis,dia,hig,dia_b,value)
union{
    //Elko Körper
    difference{
        union{            
            cylinder{<0,0.5,0><0,hig-0.5,0>dia}                                  
            //Elko Rundung oben
            torus{dia-0.5,0.5 translate<0,hig-0.5,0>}                            
            difference{
                cylinder{<0,hig-0.5,0><0,hig,0>dia-0.5}
                cylinder{<0,hig-0.5,0><0,hig+0.1,0>dia*0.8*pow(dia/16,0.11)}
            }
            //Elko Rundung unten
            torus{dia-0.5,0.5 translate<0,0.5,0>}                                
        }
        //Aussparung unten
        torus{dia+0.85,1 translate<0,2.5,0>}                                     

        //Textur für Minusmarkierung
        pigment{image_map{png "tex_elko.png"}scale tex_scale}                    
        finish{reflection { 0.03, 0.1}  phong 0.4 crand 0.05 ambient (0.1 * global_ambient_mul)}
    }

    //Abdeckung oben
    difference{
        cylinder{<0,hig-0.5,0><0,hig-0.1,0>dia*0.8*pow(dia/16,0.11)}            
        box{<0,hig-0.35,-0.1><dia,hig,0.1>} 
        box{<0,hig-0.35,-0.1><dia,hig,0.1> rotate<0,120,0>}
        box{<0,hig-0.35,-0.1><dia,hig,0.1> rotate<0,240,0>} 
        texture{col_silver}
    }
    
    //Abdeckung unten
    cylinder{<0,0.2,0><0,0.5,0>dia-0.5 pigment{Black}}                            
    union{
        #if(pin_short=off)
            cylinder{<0,0,0><0,-14.5,0>dia_b translate<dis/2,0,0>}    //Beinchen rechts
            cylinder{<0,0,0><0,-17.5,0>dia_b translate<-dis/2,0,0>}   //Beinchen links
        #else
            cylinder{<0,0,0><0,-1*(pcb_height+pin_length)-0.2,0>dia_b translate<dis/2,0,0>}    //Beinchen rechts
            cylinder{<0,0,0><0,-1*(pcb_height+pin_length)-0.2,0>dia_b translate<-dis/2,0,0>}   //Beinchen links
        #end
        texture{e3d_tex_silver}
    }
    
    //Beschriftung
    intersection{
        cylinder{<0,0,0><0,hig,0>dia}
        text {ttf besch_font value 0.2, 0 scale val_size rotate<0,0,90> translate<0,0,-dia>}
        rotate<0,0,180>
        rotate<0,10,0>
        translate<0,hig-val_size,-0.001>
        pigment {rgb<0.4,0.6,1>}
    }
    intersection{
        cylinder{<0,0,0><0,hig,0>dia }
        text {ttf besch_font value 0.2, 0 scale val_size rotate<0,0,90> translate<0,0,-dia>}
        rotate<0,0,180>
        rotate<0,100,0>
        translate<-0.001,hig-val_size,0>
        pigment {rgb<0.4,0.6,1>}
    }
    intersection{
        cylinder{<0,0,0><0,hig,0>dia }
        text {ttf besch_font value 0.2, 0 scale val_size rotate<0,0,90> translate<0,0,-dia>}
        rotate<0,0,180>
        rotate<0,190,0>
        translate<0,hig-val_size,0.001>
        pigment {rgb<0.4,0.6,1>}
    }
    finish{F_MetalE ambient (0.1 * global_ambient_mul)}
    translate<0,0.2,0>
}
#end

#macro CAP_DIS_ELKO_2MM_5MM(value)
CAP_DIS_ELKO_GRND(<6.39,20,6.39>,1,2,5/2,11,0.5/2,value)
#end
#macro CAP_DIS_ELKO_2MM5_5MM(value)
CAP_DIS_ELKO_GRND(<6.39,20,6.39>,1,2.5,5/2,11.2,0.5/2,value)
#end
#macro CAP_DIS_ELKO_2MM5_6MM3(value)
CAP_DIS_ELKO_GRND(<8.04,22,8.04>,1,2.5,6.3/2,11.2,0.5/2,value)
#end
#macro CAP_DIS_ELKO_3MM5_8MM(value)
CAP_DIS_ELKO_GRND(<10.225,22,10.225>,1.1,3.5,8/2,11.5,0.6/2,value)
#end
#macro CAP_DIS_ELKO_5MM_10MM(value)
CAP_DIS_ELKO_GRND(<12.77,25,12.77>,1.8,5,10/2,13,0.6/2,value)
#end
#macro CAP_DIS_ELKO_5MM_10MM(value)
CAP_DIS_ELKO_GRND(<12.77,25,12.77>,1.8,5,10/2,16,0.6/2,value)
#end
#macro CAP_DIS_ELKO_5MM_10MM_2(value)
CAP_DIS_ELKO_GRND(<12.77,25,12.77>,1.8,5,10/2,25.5,0.6/2,value)
#end
#macro CAP_DIS_ELKO_5MM_12MM5_2(value)
CAP_DIS_ELKO_GRND(<15.95,30,15.95>,2.8,5,12.5/2,16.5,0.6/2,value)
#end
#macro CAP_DIS_ELKO_5MM_12MM5(value)
CAP_DIS_ELKO_GRND(<15.95,30,15.95>,2.8,5,12.5/2,22.5,0.6/2,value)
#end
#macro CAP_DIS_ELKO_5MM_12MM5_3(value)
CAP_DIS_ELKO_GRND(<15.95,30,15.95>,2.8,5,12.5/2,25.5,0.6/2,value)
#end
#macro CAP_DIS_ELKO_7MM5_16MM_2(value)
CAP_DIS_ELKO_GRND(<20.45,38,20.45>,3,7.5,16/2,16.5,0.8/2,value)
#end
#macro CAP_DIS_ELKO_7MM5_16MM_3(value)
CAP_DIS_ELKO_GRND(<20.45,38,20.45>,3,7.5,16/2,25.5,0.8/2,value)
#end
#macro CAP_DIS_ELKO_7MM5_16MM(value)
CAP_DIS_ELKO_GRND(<20.45,38,20.45>,3,7.5,16/2,28,0.8/2,value)
#end
#macro CAP_DIS_ELKO_7MM5_18MM(value)
CAP_DIS_ELKO_GRND(<23,40,23>,4,7.5,18/2,35.5,0.8/2,value)
#end


/********************************************************************************************************************************************
//Tantalkondensator Grundmakro 2,5mm Pitch
********************************************************************************************************************************************/
#macro CAP_DIS_TT_2MM5_GRND(obj_dia,obj_hgt,sca_txt)
union{
    //Body
    sphere{<0,0,0>obj_dia/2 scale<1,obj_hgt/obj_dia,1> pigment{CoolCopper}}
    
    //Leads
    union{
        #if(pin_short=off)
            cylinder{<0,1,0><0,-16,0>0.25 translate<-1.25,-((obj_hgt/obj_dia)*obj_dia)/2+1,0>}
            cylinder{<0,1,0><0,-14,0>0.25 translate<1.25,-((obj_hgt/obj_dia)*obj_dia)/2+1,0>}
        #else
            cylinder{<0,1,0><0,-1*(pcb_height+pin_length)-1.2,0>0.25 translate<-1.25,-((obj_hgt/obj_dia)*obj_dia)/2+1,0>}
            cylinder{<0,1,0><0,-1*(pcb_height+pin_length)-1.2,0>0.25 translate<1.25,-((obj_hgt/obj_dia)*obj_dia)/2+1,0>}
        #end
        texture{e3d_tex_silver}
    }
    
    //Marking
    union{
        intersection{
            sphere{<0,0,0>obj_dia/2 scale<1,obj_hgt/obj_dia,1.001> translate<0,0,0>}
            text {ttf besch_font "+" obj_dia+0.4, 0 rotate<0,0,00> translate<-1.25,-((obj_hgt/obj_dia)*obj_dia)/2+1,-(obj_dia+0.4)/2>}
        }
        intersection{
            sphere{<0,0,0>obj_dia/2 scale<1,obj_hgt/obj_dia,1.001> translate<0,0,0>}
            text {ttf besch_font value obj_dia+0.4,0  scale<sca_txt,1,1> rotate<0,0,90> translate<0.25,-((obj_hgt/obj_dia)*obj_dia)/2+1.5,-(obj_dia+0.4)/2>}
        }
        texture{e3d_tex_cap_marking_black}
    }
    translate<0,((obj_hgt/obj_dia)*obj_dia)/2+0.2,0>
}
#end

#macro CAP_DIS_TT_2MM5_4MM(value)
CAP_DIS_TT_2MM5_GRND(4,8.5,1)
#end
#macro CAP_DIS_TT_2MM5_4MM5(value)
CAP_DIS_TT_2MM5_GRND(4.5,8.5,1)
#end
#macro CAP_DIS_TT_2MM5_5MM(value)
CAP_DIS_TT_2MM5_GRND(5,10,1.2)
#end
#macro CAP_DIS_TT_2MM5_5MM5(value)
CAP_DIS_TT_2MM5_GRND(5.5,10.5,1.3)
#end
#macro CAP_DIS_TT_2MM5_6MM(value)
CAP_DIS_TT_2MM5_GRND(6,11.5,1.4)
#end
#macro CAP_DIS_TT_2MM5_6MM5(value)
CAP_DIS_TT_2MM5_GRND(6.5,11.5,1.5)
#end
#macro CAP_DIS_TT_2MM5_7MM(value)
CAP_DIS_TT_2MM5_GRND(7,12,1.6)
#end
#macro CAP_DIS_TT_2MM5_8MM(value)
CAP_DIS_TT_2MM5_GRND(8,13,1.8)
#end
#macro CAP_DIS_TT_2MM5_8MM5(value)
CAP_DIS_TT_2MM5_GRND(8.5,14,1.8)
#end
#macro CAP_DIS_TT_2MM5_9MM(value)
CAP_DIS_TT_2MM5_GRND(9,15,2)
#end
#macro CAP_DIS_TT_2MM5_10MM(value)
CAP_DIS_TT_2MM5_GRND(10,18,2)
#end


/********************************************************************************************************************************************
//Tantalkondensator Grundmakro 5mm Pitch
********************************************************************************************************************************************/
#macro CAP_DIS_TT_5MM_GRND(obj_dia,obj_hgt,sca_txt)
union{
    //Body
    sphere{<0,0,0>obj_dia/2 scale<1,obj_hgt/obj_dia,1> pigment{CoolCopper}}
    
    //Leads
    union{
        cylinder{<0,1,0><0,-1,0>0.25 translate<-1.25,-((obj_hgt/obj_dia)*obj_dia)/2+1,0>}
        cylinder{<0,1,0><0,-1,0>0.25 translate<1.25,-((obj_hgt/obj_dia)*obj_dia)/2+1,0>}
        cylinder{<0,0,0><-1.25,-1,0>0.25 translate<-1.25,-((obj_hgt/obj_dia)*obj_dia)/2,0>}
        cylinder{<0,0,0><1.25,-1,0>0.25 translate<1.25,-((obj_hgt/obj_dia)*obj_dia)/2,0>}
        #if(pin_short=off)
            cylinder{<0,-14,0><0,-2,0>0.25 translate<-2.5,-((obj_hgt/obj_dia)*obj_dia)/2+1,0>}
            cylinder{<0,-12,0><0,-2,0>0.25 translate<2.5,-((obj_hgt/obj_dia)*obj_dia)/2+1,0>}
        #else
            cylinder{<0,-1*(pcb_height+pin_length)-2.5,0><0,-2,0>0.25 translate<-2.5,-((obj_hgt/obj_dia)*obj_dia)/2+1,0>}
            cylinder{<0,-1*(pcb_height+pin_length)-2.5,0><0,-2,0>0.25 translate<2.5,-((obj_hgt/obj_dia)*obj_dia)/2+1,0>}
        #end
        sphere{<0,0,0>0.25 translate<-2.5,-((obj_hgt/obj_dia)*obj_dia)/2-1,0>}
        sphere{<0,0,0>0.25 translate<2.5,-((obj_hgt/obj_dia)*obj_dia)/2-1,0>}
        sphere{<0,0,0>0.25 translate<-1.25,-((obj_hgt/obj_dia)*obj_dia)/2,0>}
        sphere{<0,0,0>0.25 translate<1.25,-((obj_hgt/obj_dia)*obj_dia)/2,0>}
        texture{e3d_tex_silver}
    }
    //Marking
    union{
        intersection{
            sphere{<0,0,0>obj_dia/2 scale<1,obj_hgt/obj_dia,1.001> translate<0,0,0>}
            text {ttf besch_font "+" obj_dia+0.4, 0 rotate<0,0,00> translate<-1.25,-((obj_hgt/obj_dia)*obj_dia)/2+1,-(obj_dia+0.4)/2>}
        }
        intersection{
            sphere{<0,0,0>obj_dia/2 scale<1,obj_hgt/obj_dia,1.001> translate<0,0,0>}
            text {ttf besch_font value obj_dia+0.4,0  scale<sca_txt,1,1> rotate<0,0,90> translate<0.25,-((obj_hgt/obj_dia)*obj_dia)/2+1.5,-(obj_dia+0.4)/2>}
        }
        texture{e3d_tex_cap_marking_black}
    }
    translate<0,((obj_hgt/obj_dia)*obj_dia)/2+1.5,0>
}
#end


#macro CAP_DIS_TT_5MM_4MM5(value)
CAP_DIS_TT_5MM_GRND(4.5,8.5,1)
#end
#macro CAP_DIS_TT_5MM_5MM(value)
CAP_DIS_TT_5MM_GRND(5,10,1.2)
#end
#macro CAP_DIS_TT_5MM_5MM5(value)
CAP_DIS_TT_5MM_GRND(5.5,10.5,1.3)
#end
#macro CAP_DIS_TT_5MM_6MM(value)
CAP_DIS_TT_5MM_GRND(6,11.5,1.4)
#end
#macro CAP_DIS_TT_5MM_6MM5(value)
CAP_DIS_TT_5MM_GRND(6.5,11.5,1.5)
#end
#macro CAP_DIS_TT_5MM_7MM(value)
CAP_DIS_TT_5MM_GRND(7,12,1.6)
#end
#macro CAP_DIS_TT_5MM_8MM(value)
CAP_DIS_TT_5MM_GRND(8,13,1.8)
#end
#macro CAP_DIS_TT_5MM_8MM5(value)
CAP_DIS_TT_5MM_GRND(8.5,14,1.8)
#end
#macro CAP_DIS_TT_5MM_9MM(value)
CAP_DIS_TT_5MM_GRND(9,15,2)
#end
#macro CAP_DIS_TT_5MM_10MM(value)
CAP_DIS_TT_5MM_GRND(10,18,2)
#end
#macro CAP_DIS_TT_5MM_11MM(value)
CAP_DIS_TT_5MM_GRND(11,18,2)
#end


/********************************************************************************************************************************************
//Wimakondenstor Grundmakro
//by Andreas Rebmann <A.Rebmann-Elektrotechnik@t-online.de>
//Grundmacro - Breite=B , Tiefe = T, Hoehe = H, Raster = Ra
********************************************************************************************************************************************/
#macro CAP_DIS_WIMA_GRND(B,T,H,Ra)
union{

    box{<-B/2+0.2, 0,     T/2>     <B/2-0.2,H-0.2,-T/2>      rotate<0,0,0> translate<0,0,0>} //Grundkörper
    box{<-B/2,     0,    -T/2+0.2> <B/2,    H-0.2, T/2-0.2>  rotate<0,0,0> translate<0,0,0>} //Kleine Box innen
    box{<-B/2+0.2, H-0.2,-T/2+0.2> <B/2-0.2,H    , T/2-0.2>  rotate<0,0,0> translate<0,0,0>} //Kleine Box oben

    cylinder{<-B/2+0.2,0,0> <-B/2+0.2, H-0.2> 0.20  rotate<0,0,0> translate <0, 0,  T/2-0.2>} //Rundungen rechts
    cylinder{<-B/2+0.2,0,0> <-B/2+0.2, H-0.2> 0.20  rotate<0,0,0> translate <0, 0,-T/2+0.2>} //Rundungen rechts
    cylinder{< B/2-0.2,0,0> < B/2-0.2, H-0.2> 0.20  rotate<0,0,0> translate <0, 0,  T/2-0.2>} //Rundungen links
    cylinder{< B/2-0.2,0,0> < B/2-0.2, H-0.2> 0.20  rotate<0,0,0> translate <0, 0, -T/2+0.2>} //Rundungen links

    sphere{< B/2-0.2, H-0.2, T/2-0.2> 0.2 scale <1,1,1>  translate<0,0,0>}  //Rundungen oben
    sphere{< B/2-0.2, H-0.2,-T/2+0.2> 0.2 scale <1,1,1>  translate<0,0,0>}  //Rundungen oben
    sphere{<-B/2+0.2, H-0.2, T/2-0.2> 0.2 scale <1,1,1>  translate<0,0,0>}  //Rundungen oben
    sphere{<-B/2+0.2, H-0.2,-T/2+0.2> 0.2 scale <1,1,1>  translate<0,0,0>}  //Rundungen oben

    cylinder{<-B/2+0.2,  H-0.2> < B/2-0.2, H-0.2> 0.20 rotate<0,0,0> translate <0, 0, T/2-0.2>}   //Rundungen vorne
    cylinder{<-B/2+0.2,  H-0.2> < B/2-0.2, H-0.2> 0.20 rotate<0,0,0> translate <0, 0,-T/2+0.2>}   //Rundungen hinten
    cylinder{<-T/2+0.2,  H-0.2> < 0, H-0.2> 0.20 rotate<0, 90,0> translate <-B/2+0.2, 0, 0>}  //Rundungen rechts kurz
    cylinder{<-T/2+0.2,  H-0.2> < 0, H-0.2> 0.20 rotate<0,-90,0> translate <-B/2+0.2, 0, 0>}  //Rundungen rechts kurz
    cylinder{<-T/2+0.2,  H-0.2> < 0, H-0.2> 0.20 rotate<0, 90,0> translate < B/2-0.2, 0, 0>}  //Rundungen links kurz
    cylinder{<-T/2+0.2,  H-0.2> < 0, H-0.2> 0.20 rotate<0,-90,0> translate < B/2-0.2, 0, 0>}  //Rundungen links kurz

    //Drahtdurchmesser und Beschriftung an die Kondensatorgröße anpassen

    #if(pin_short=on)
        #local wima_pin_length = -1*(pin_length+pcb_height);
    #else
        #local wima_pin_length = -5;
    #end

    #if (Ra=2.54)    //d=0.4mm
        cylinder{<-Ra/2 ,0> <-Ra/2,wima_pin_length,0> 0.20 texture{e3d_tex_silver}}   // Draht rechts senkrecht
        cylinder{< Ra/2 ,0> < Ra/2,wima_pin_length,0> 0.20 texture{e3d_tex_silver}}   // Draht links senkrecht
        text {ttf besch_font  value   0.1, 0 scale<1.0,1.0,1.0> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-0.6, H-4.3, T/2+0.1> rotate<0,0,0>} //Beschriftung Value
        text {ttf besch_font "WIMA"   0.1, 0 scale<1.4,1.4,1.4> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-0.6, H-2.8, T/2+0.1> rotate<0,0,0>} //Beschriftung WIMA
    #end

    #if (Ra=5.08)    //d=0.5mm
        cylinder{<-Ra/2 ,0> <-Ra/2,wima_pin_length,0> 0.25 texture{e3d_tex_silver}}   // Draht rechts senkrecht
        cylinder{< Ra/2 ,0> < Ra/2,wima_pin_length,0> 0.25 texture{e3d_tex_silver}}   // Draht links senkrecht
        text {ttf besch_font  value   0.1, 0 scale<1.4,1.4,1.4> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-1.2, H-4.3, T/2+0.1> rotate<0,0,0>} //Beschriftung Value
        text {ttf besch_font "WIMA"   0.1, 0 scale<2.0,2.0,2.0> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-1.2, H-2.8, T/2+0.1> rotate<0,0,0>} //Beschriftung WIMA
    #end

    #if (Ra=7.50)    //d=0.7mm
        cylinder{<-Ra/2 ,0> <-Ra/2,wima_pin_length,0> 0.35 texture{e3d_tex_silver}}   // Draht rechts senkrecht
        cylinder{< Ra/2 ,0> < Ra/2,wima_pin_length,0> 0.35 texture{e3d_tex_silver}}   // Draht links senkrecht
        text {ttf besch_font  value   0.1, 0 scale<2.0,2.0,2.0> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-1.8, H-5.5, T/2+0.1> rotate<0,0,0>} //Beschriftung Value
        text {ttf besch_font "WIMA"   0.1, 0 scale<2.7,2.7,2.7> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-1.8, H-3.3, T/2+0.1> rotate<0,0,0>} //Beschriftung WIMA
    #end

    #if (Ra=10.0)    //d=0.7mm
        cylinder{<-Ra/2 ,0> <-Ra/2,wima_pin_length,0> 0.35 texture{e3d_tex_silver}}   // Draht rechts senkrecht
        cylinder{< Ra/2 ,0> < Ra/2,wima_pin_length,0> 0.35 texture{e3d_tex_silver}}   // Draht links senkrecht
        text {ttf besch_font  value   0.1, 0 scale<2.4,2.4,2.4> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-2.5, H-6.0, T/2+0.1> rotate<0,0,0>} //Beschriftung Value
        text {ttf besch_font "WIMA"   0.1, 0 scale<3.1,3.1,3.1> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-2.5, H-3.5, T/2+0.1> rotate<0,0,0>} //Beschriftung WIMA
    #end

    #if (Ra=15.0)    //d=0.8mm
        cylinder{<-Ra/2 ,0> <-Ra/2,wima_pin_length,0> 0.40 texture{e3d_tex_silver}}   // Draht rechts senkrecht
        cylinder{< Ra/2 ,0> < Ra/2,wima_pin_length,0> 0.40 texture{e3d_tex_silver}}   // Draht links senkrecht
        text {ttf besch_font  value   0.1, 0 scale<3.0,3.0,3.0> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-4.0, H-7.0, T/2+0.1> rotate<0,0,0>} //Beschriftung Value
        text {ttf besch_font "WIMA"   0.1, 0 scale<3.7,3.7,3.7> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-4.0, H-4.0, T/2+0.1> rotate<0,0,0>} //Beschriftung WIMA
    #end

    #if (Ra=22.5)    //d=0.8mm
        cylinder{<-Ra/2 ,0> <-Ra/2,wima_pin_length,0> 0.40 texture{e3d_tex_silver}}   // Draht rechts senkrecht
        cylinder{< Ra/2 ,0> < Ra/2,wima_pin_length,0> 0.40 texture{e3d_tex_silver}}   // Draht links senkrecht
        text {ttf besch_font  value   0.1, 0 scale<3.5,3.5,3.5> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-6.5, H-9.0, T/2+0.1> rotate<0,0,0>} //Beschriftung Value
        text {ttf besch_font "WIMA"   0.1, 0 scale<4.2,4.2,4.2> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-6.5, H-6.0, T/2+0.1> rotate<0,0,0>} //Beschriftung WIMA
    #end

    #if (Ra=27.5)    //d=1.0mm
        cylinder{<-Ra/2 ,0> <-Ra/2,wima_pin_length,0> 0.50 texture{e3d_tex_silver}}   // Draht rechts senkrecht
        cylinder{< Ra/2 ,0> < Ra/2,wima_pin_length,0> 0.50 texture{e3d_tex_silver}}   // Draht links senkrecht
        text {ttf besch_font  value   0.1, 0 scale<4.0,4.0,4.0> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-10.0, H-12.0, T/2+0.1> rotate<0,0,0>} //Beschriftung Value
        text {ttf besch_font "WIMA"   0.1, 0 scale<4.7,4.7,4.7> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-10.0, H- 8.0, T/2+0.1> rotate<0,0,0>} //Beschriftung WIMA
    #end

    #if (Ra=37.5)    //d=1.0mm
        cylinder{<-Ra/2 ,0> <-Ra/2,wima_pin_length,0> 0.50 texture{e3d_tex_silver}}   // Draht rechts senkrecht
        cylinder{< Ra/2 ,0> < Ra/2,wima_pin_length,0> 0.50 texture{e3d_tex_silver}}   // Draht links senkrecht
        text {ttf besch_font  value   0.1, 0 scale<4.5,4.5,4.5> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-15.0, H-15.0, T/2+0.1> rotate<0,0,0>} //Beschriftung Value
        text {ttf besch_font "WIMA"   0.1, 0 scale<5.2,5.2,5.2> texture{e3d_tex_cap_marking_black} rotate<0,180,0> translate<B/2-15.0, H-10.0, T/2+0.1> rotate<0,0,0>} //Beschriftung WIMA
    #end

    rotate<0,180,0>
    texture{e3d_tex_cap_wima}    
}
#end

// Raster 2.54
#macro CAP_DIS_WIMA_25_025_046_075(value)
CAP_DIS_WIMA_GRND(4.6,2.5,7.5,2.54,)
#end
#macro CAP_DIS_WIMA_25_030_046_075(value)
CAP_DIS_WIMA_GRND(4.6,3.0,7.5,2.54,)
#end
#macro CAP_DIS_WIMA_25_040_046_090(value)
CAP_DIS_WIMA_GRND(4.6,4.6,9.0,2.54,)
#end
#macro CAP_DIS_WIMA_25_050_046_100(value)
CAP_DIS_WIMA_GRND(4.6,5.5,10.0,2.54,)
#end
#macro CAP_DIS_WIMA_25_060_046_100(value)
CAP_DIS_WIMA_GRND(4.6,6.5,10.0,2.54,)
#end
//Raster 5.08
#macro CAP_DIS_WIMA_5_025_072_065(value)
CAP_DIS_WIMA_GRND(7.2,2.5,6.5,5.08,)
#end
#macro CAP_DIS_WIMA_5_030_072_075(value)
CAP_DIS_WIMA_GRND(7.2,3.0,7.5,5.08,)
#end
#macro CAP_DIS_WIMA_5_035_072_085(value)
CAP_DIS_WIMA_GRND(7.2,3.5,8.5,5.08,)
#end
#macro CAP_DIS_WIMA_5_045_072_095(value)
CAP_DIS_WIMA_GRND(7.2,4.5,9.5,5.08)
#end
#macro CAP_DIS_WIMA_5_050_072_100(value)
CAP_DIS_WIMA_GRND(7.2,5.0,10.0,5.08)
#end
#macro CAP_DIS_WIMA_5_055_072_115(value)
CAP_DIS_WIMA_GRND(7.2,5.5,11.5,5.08)
#end
#macro CAP_DIS_WIMA_5_072_072_130(value)
CAP_DIS_WIMA_GRND(7.2,7.2,13.0,5.08)
#end
#macro CAP_DIS_WIMA_5_085_072_140(value)
CAP_DIS_WIMA_GRND(7.2,8.5,14.0,5.08)
#end
//Raster 7.5
#macro CAP_DIS_WIMA_75_030_100_085(value)
CAP_DIS_WIMA_GRND(10.0,3.0,8.5,7.5)
#end
#macro CAP_DIS_WIMA_75_040_100_090(value)
CAP_DIS_WIMA_GRND(10.0,4.0,9.0,7.5)
#end
#macro CAP_DIS_WIMA_75_050_103_105(value)
CAP_DIS_WIMA_GRND(10.3,5.0,10.5,7.5)
#end
#macro CAP_DIS_WIMA_75_057_100_125(value)
CAP_DIS_WIMA_GRND(10.3,5.7,12.5,7.5)
#end
//Raster 10
#macro CAP_DIS_WIMA_100_040_130_095(value)
CAP_DIS_WIMA_GRND(13.0,4.0,9.5,10.0)
#end
#macro CAP_DIS_WIMA_100_050_130_110(value)
CAP_DIS_WIMA_GRND(13.0,5.0,11.0,10.0)
#end
#macro CAP_DIS_WIMA_100_060_130_120(value)
CAP_DIS_WIMA_GRND(13.0,6.0,12.0,10.0)
#end
//Raster 15
#macro CAP_DIS_WIMA_150_050_180_110(value)
CAP_DIS_WIMA_GRND(18.0,5.0,11.0,15.0)
#end
#macro CAP_DIS_WIMA_150_060_180_125(value)
CAP_DIS_WIMA_GRND(18.0,6.0,12.5,15.0)
#end
#macro CAP_DIS_WIMA_150_070_180_140(value)
CAP_DIS_WIMA_GRND(18.0,7.0,14.0,15.0)
#end
#macro CAP_DIS_WIMA_150_080_180_150(value)
CAP_DIS_WIMA_GRND(18.0,8.0,15.0,15.0)
#end
#macro CAP_DIS_WIMA_150_090_180_160(value)
CAP_DIS_WIMA_GRND(18.0,9.0,16.0,15.0)
#end
//Raster 22.5
#macro CAP_DIS_WIMA_225_060_265_150(value)
CAP_DIS_WIMA_GRND(26.5,6.0,15.0,22.5)
#end
#macro CAP_DIS_WIMA_225_070_265_165(value)
CAP_DIS_WIMA_GRND(26.5,7.0,16.5,22.5)
#end
#macro CAP_DIS_WIMA_225_085_265_185(value)
CAP_DIS_WIMA_GRND(26.5,8.5,18.5,22.5)
#end
#macro CAP_DIS_WIMA_225_105_265_190(value)
CAP_DIS_WIMA_GRND(26.5,10.5,19.0,22.5)
#end
#macro CAP_DIS_WIMA_225_110_265_210(value)
CAP_DIS_WIMA_GRND(26.5,11.0,21.0,22.5)
#end
//Raster 27.5
#macro CAP_DIS_WIMA_275_090_315_210(value)
CAP_DIS_WIMA_GRND(31.5,9.0,21.0,27.5)
#end
#macro CAP_DIS_WIMA_275_110_315_210(value)
CAP_DIS_WIMA_GRND(31.5,11.0,21.0,27.5)
#end
#macro CAP_DIS_WIMA_275_130_315_240(value)
CAP_DIS_WIMA_GRND(31.5,13.0,24.0,27.5)
#end
#macro CAP_DIS_WIMA_275_150_315_260(value)
CAP_DIS_WIMA_GRND(31.5,15.0,26.0,27.5)
#end
#macro CAP_DIS_WIMA_275_170_315_345(value)
CAP_DIS_WIMA_GRND(31.5,17.0,34.5,27.5)
#end
#macro CAP_DIS_WIMA_275_200_315_395(value)
CAP_DIS_WIMA_GRND(31.5,20.0,39.5,27.5)
#end
//Raster 37.5
#macro CAP_DIS_WIMA_375_150_415_260(value)
CAP_DIS_WIMA_GRND(41.5,15.0,26.0,37.5)
#end
#macro CAP_DIS_WIMA_375_190_415_320(value)
CAP_DIS_WIMA_GRND(41.5,19.0,32.0,37.5)
#end
#macro CAP_DIS_WIMA_375_200_415_395(value)
CAP_DIS_WIMA_GRND(41.5,20.0,39.5,37.5)
#end


/********************************************************************************************************************************************
//(Tiefe, Breite, Hoehe, Breite Loetflaechen, Abstand Pin zu Pin, Anzahl Kondensatoren,Farbe des Körpers)
********************************************************************************************************************************************/
#macro CAP_SMD_CHIP_ARRAY_GRND(b,l,h,blf,pitch,n)
union{    
    //Body
    object{
        Round_Box_Union(<0,0.05,0>, <l,h,b>, min(b,l,h)/6)
        translate<-l/2,0,-b/2>
        texture{e3d_tex_cap_smd_ceramic_1}
    }
        
    //Pins
    #local i = 0;
    #local x_pos = -(n-1)/2*pitch;        
    union{    
        #while(i<n)
        
            box{<-blf/2,0,b/2+0.01><blf/2,h,b/2-b/10> translate<x_pos,0,0>}
            box{<-blf/2,0,-b/2-0.01><blf/2,h,-b/2+b/10> translate<x_pos,0,0>}
            
            #local i = i+1;
            #local x_pos = x_pos + pitch;
        
        #end
        texture{e3d_tex_silver}
    }    
}
#end

#macro CAP_SMD_CHIP_ARRAY_4X0603_0612()
CAP_SMD_CHIP_ARRAY_GRND(1.60,3.20,0.8,0.4,0.8,4)
#end


/********************************************************************************************************************************************
//Grundmakro für SMD-Keramik-Chip-Kondensator (neu Parameter K = Anschlussbreite)
//basiert auf Makro von Walter Mücke
********************************************************************************************************************************************/
#macro CAP_SMD_CHIP_GRND(L,W,T,K)
union{
    //Body
    superellipsoid{<0.25-(L+W)/150, 0.25-(L+W)/150> texture{e3d_tex_cap_smd_ceramic_1} scale<L/2,W/2,T/2> }     //Grundkörper braun
    
    //Contacts
    union{
        superellipsoid{<0.25-(L+W)/200, 0.25-(L+W)/200> scale<(K+L/100)/2,W/2,T/2> translate <(L-K)/2,0,0>}
        superellipsoid{<0.25-(L+W)/200, 0.25-(L+W)/200> scale<(K+L/100)/2,W/2,T/2> translate <-(L-K)/2,0,0>}
        texture{e3d_tex_silver}
    }
    rotate<90,0,0>
    translate<0,T/2,0>
}
#end

//2220
#macro CAP_SMD_CHIP_2220()
CAP_SMD_CHIP_GRND(5.7,5.0,2.7,0.5)
#end
//1825
#macro CAP_SMD_CHIP_1825()
CAP_SMD_CHIP_GRND(4.5,6.4,1.7,0.5)
#end
//1812
#macro CAP_SMD_CHIP_1812()
CAP_SMD_CHIP_GRND(4.5,3.2,1.7,0.5)
#end
//1210
#macro CAP_SMD_CHIP_1210()
CAP_SMD_CHIP_GRND(3.2,2.5,1.7,0.5)
#end
#macro CAP_SMD_CHIP_1206()
CAP_SMD_CHIP_GRND(3.2,1.6,1.5,0.5)
#end
#macro CAP_SMD_CHIP_0805()
CAP_SMD_CHIP_GRND(2.0,1.25,1.3,0.5)
#end
#macro CAP_SMD_CHIP_0603()
CAP_SMD_CHIP_GRND(1.6,0.8,0.9,0.3)
#end
#macro CAP_SMD_CHIP_0402()
CAP_SMD_CHIP_GRND(1.0,0.5,0.6,0.2)
#end


/********************************************************************************************************************************************
//Grundmakro für SMD-Tantal-Chip-Kondensator
//basiert auf Makro von Walter Mücke
********************************************************************************************************************************************/
#macro CAP_SMD_CHIP_TT_GRND(L,W,H,LT,WT,HT,P,value)
union{
    
    //Body
    box{<0,0,0><LT,H,W> pigment{rgb(<0.400, 0.320, 0.220>)*1.2} translate<-LT/2,(L-LT)/2,-W/2>}            //Grundkörper braun
    
    //Marking
    text{ttf besch_font value 0.1,0 scale L/8 rotate<90,0,0> translate<-LT/4,H+(L-LT)/2+0.01,0> pigment{DarkWood*0.7}}
    
    //
    box{<0,0,0><(L-2*P)-0.3,(L-LT)/2,W> pigment{rgb(<0.400, 0.320, 0.220>)*1.2} translate<-((L-2*P)-0.3)/2,0,-W/2>}
    box{<0,0,0><0.4/exp(-LT/10),0.002,W> pigment{DarkWood*0.7} translate<-LT/2.1,H+(L-LT)/2,-W/2>}        //Markierung
    
    union{
        //rechter Anschluss
        difference{
            box{<0,0,0><-P,HT,WT>}
            box{<0,(L-LT)/2,-0.002><-P-0.002,HT-(L-LT)/2,WT+0.002> translate<-(L-LT)/2,0,0>}
            cylinder{<0,HT,-0.002><0,HT,WT+0.002>(L-LT)/2}
            cylinder{<0,0,-0.002><0,0,WT+0.002>(L-LT)/2}
            translate<LT/2+(L-LT)/2+0.02,0,-WT/2>
        }
        //rechter Anschlus
        difference{
            cylinder{<-(L-LT)/2,HT-(L-LT)/2,><-(L-LT)/2,HT-(L-LT)/2,WT>(L-LT)/2}
            cylinder{<-3*(L-LT)/4,HT-3*(L-LT)/4,-0.04><-3*(L-LT)/4,HT-3*(L-LT)/4,WT+0.002>(L-LT)/4}
            box{<-(L-LT)/2,HT-3*(L-LT)/4,-0.04><-(L-LT),HT-5,WT+0.002>}
            box{<-3*(L-LT)/4,HT-(L-LT)/2,-0.04><-(L-LT),HT-5,WT+0.002>}
            translate<LT/2+(L-LT)/2+0.02,0,-WT/2>
        }
        //rechter Anschlus
        difference{
            cylinder{<-(L-LT)/2,(L-LT)/2,0><-(L-LT)/2,(L-LT)/2,WT>(L-LT)/2}
            cylinder{<-3*(L-LT)/4,3*(L-LT)/4,-0.04><-3*(L-LT)/4,3*(L-LT)/4,WT+0.002>(L-LT)/4}
            box{<(-L-LT)/2,3*(L-LT)/4,-0.04><-(L-LT),5,WT+0.002>}
            box{<0,0,-0.04><(L-LT)/2,(L-LT)/2,WT+0.002> translate<-(L-LT),0.75*(L-LT),0>}
            box{<(L-LT)/2,(L-LT)/2,-0.04><(L-LT),L-LT,WT+0.002> translate<-1.75*(L-LT),0,0>}
            translate<LT/2+(L-LT)/2+0.02,0,-WT/2>
        }
        //linker (positiver) Anschlus
        difference{
            box{<0,0,0><P,HT,WT>}
            box{<(L-LT)/2,(L-LT)/2,-0.002><P+0.002,HT-(L-LT)/2,WT+0.002>}
            cylinder{<0,HT,-0.002><0,HT,WT+0.002>(L-LT)/2}
            cylinder{<0,0,-0.002><0,0,WT+0.002>(L-LT)/2}
            box{<-0.002,HT/2,0><P+0.002,HT+0.002,WT*0.3> translate<0,0,WT*0.35>}
            translate<-L/2-0.02,0,-WT/2>
        }
        //linker (positiver) Anschlus
        difference{
            cylinder{<(L-LT)/2,HT-(L-LT)/2,-0.002><(L-LT)/2,HT-(L-LT)/2,WT+0.002>(L-LT)/2}
            cylinder{<3*(L-LT)/4,HT-3*(L-LT)/4,-0.04><3*(L-LT)/4,HT-3*(L-LT)/4,WT+0.002>(L-LT)/4}
            box{<(L-LT)/2,HT-3*(L-LT)/4,-0.04><L-LT,HT-5,WT+0.002>}
            box{<3*(L-LT)/4,HT-(L-LT)/2,-0.04><L-LT,HT-5,WT+0.002>}
            box{<-0.002,HT/2,0><P+0.002,HT+0.002,WT*0.3> translate<0,0,WT*0.35>}
            translate<-L/2-0.02,0,-WT/2>
        }
        //linker (positiver) Anschlus
        difference{
            cylinder{<(L-LT)/2,(L-LT)/2,-0.002><(L-LT)/2,(L-LT)/2,WT+0.002>(L-LT)/2}
            cylinder{<3*(L-LT)/4,3*(L-LT)/4,-0.04><3*(L-LT)/4,HT-3*(L-LT)/4,WT+0.002>(L-LT)/4}
            box{<(L-LT)/2,3*(L-LT)/4,-0.04><L-LT,5,WT+0.002>}
            box{<3*(L-LT)/4,(L-LT)/2,-0.04><L-LT,L-LT,WT+0.002>}
            translate<-L/2-0.02,0,-WT/2>
        }
        texture{e3d_tex_silver}
    }
    
    rotate<0,180,0>
}
#end                                                                                                                 

#macro CAP_SMD_CHIP_TT_SCT_A(value)
CAP_SMD_CHIP_TT_GRND(3.2,1.6,1.6,3.0,1.2,1.0,0.8,value)
#end
#macro CAP_SMD_CHIP_TT_SCT_B(value)
CAP_SMD_CHIP_TT_GRND(3.5,2.8,1.9,3.3,2.2,1.2,0.8,value)
#end
#macro CAP_SMD_CHIP_TT_SCT_C(value)
CAP_SMD_CHIP_TT_GRND(6.0,3.2,2.5,5.8,2.2,1.5,1.3,value)
#end
#macro CAP_SMD_CHIP_TT_SCT_D(value)
CAP_SMD_CHIP_TT_GRND(7.3,4.3,2.8,7.1,2.4,1.6,1.3,value)
#end
#macro CAP_SMD_CHIP_TT_SCT_E(value)
CAP_SMD_CHIP_TT_GRND(7.3,4.3,4.1,7.1,2.4,1.6,1.3,value)
#end
#macro CAP_SMD_CHIP_TT_SCT_R(value)
CAP_SMD_CHIP_TT_GRND(2.0,1.6,1.0,1.9,1.2,0.6,0.5,value)
#end


/********************************************************************************************************************************************
//Grundmakro SMD-Elko
//L = Länge
//W = Breite
//H = Höhe
//D = Durchmesser Elkokörper
//B = Breite Anschlußpin
//S = Abstand Anschlußpins unten
//C = Länge Anschlußpins
********************************************************************************************************************************************/
#macro CAP_SMD_ELKO_GRND(L,W,H,D,B,S,C)
union{
    //Contacts
    box{<-S/2,0,-B/2><-S/2-C,0.3,B/2>}
    box{<S/2,0,-B/2><S/2+C,0.3,B/2>}
    //The base plastic
    difference{
        box{<-L/2,0.3,-W/2><L/2,2,W/2>}
        box{<0,0,0><6,3,-5> rotate<0,-45,0> translate<L/2-L/4,0,-W/2>}
        box{<0,0,0><6,3,5> rotate<0,45,0> translate<L/2-L/4,0,W/2>}
        texture{e3d_tex_cap_smd_electrolytic_base}
    }
    //Body
    difference{
        cylinder{<0,2,0><0,H-0.4,0>D/2}
        torus{D/2+0.2,0.4 translate<0,3,0>}
    }
    torus{D/2-0.4,0.4 translate<0,H-0.4,0>}
    cylinder{<0,H-0.4,0><0,H,0>D/2-0.4}

    //Top marking
    union{        
        difference{
            cylinder{<0,H-0.4,0><0,H+0.01,0>D/2-0.4}
            box{<-D/6,H-0.5,-D/2><D/2,H+0.1,D/2>}            
        }
        text {ttf besch_font value 0.5,0 scale D/7 rotate<90,-90,0> translate<D/16,H+0.01,-D/2+D/8>}
        texture{e3d_tex_cap_marking_black}
    }
    rotate<0,180,0>
    texture{e3d_tex_silver}
}
#end

#macro CAP_SMD_ELKO_0405(value)
CAP_SMD_ELKO_GRND(4.5,4.5,5.5,4.0,0.8,1.0,2.0)
#end
#macro CAP_SMD_ELKO_0505(value)
CAP_SMD_ELKO_GRND(5.5,5.5,5.5,5.0,0.8,1.4,2.3)
#end
#macro CAP_SMD_ELKO_0605(value)
CAP_SMD_ELKO_GRND(6.8,6.8,5.5,6.3,0.8,2.0,2.7)
#end
#macro CAP_SMD_ELKO_0807(value)
CAP_SMD_ELKO_GRND(8.6,8.6,6.8,8.0,0.8,2.3,3.4)
#end
#macro CAP_SMD_ELKO_0808(value)
CAP_SMD_ELKO_GRND(8.4,8.4,8.7,8,1,4.7,2.2)
#end
#macro CAP_SMD_ELKO_0810(value)
CAP_SMD_ELKO_GRND(8.6,8.6,10.5,8.0,1.1,3.1,3.0)
#end
#macro CAP_SMD_ELKO_1010(value)
CAP_SMD_ELKO_GRND(10.6,10.6,10.5,10.0,1.1,4.7,3.3)
#end
#macro CAP_SMD_ELKO_1012(value)
CAP_SMD_ELKO_GRND(10.6,10.6,12.3,10.0,1.2,4.5,3.9)
#end
#macro CAP_SMD_ELKO_1014(value)
CAP_SMD_ELKO_GRND(10.6,10.6,14.3,10.0,1.2,4.5,3.9)
#end
#macro CAP_SMD_ELKO_1212(value)
CAP_SMD_ELKO_GRND(12.8,12.8,12.5,12.5,1.2,4.7,4)
#end
#macro CAP_SMD_ELKO_1214(value)
CAP_SMD_ELKO_GRND(12.8,12.8,14.5,12.5,1.2,4.7,4)
#end
#macro CAP_SMD_ELKO_PANASONIC_B(value)
CAP_SMD_ELKO_GRND(4.3,4.3,5.8,4.0,0.65,1.0,1.8)
#end
#macro CAP_SMD_ELKO_PANASONIC_C(value)
CAP_SMD_ELKO_GRND(5.3,5.3,5.8,5.0,0.65,1.5,2.2)
#end
#macro CAP_SMD_ELKO_PANASONIC_D(value)
CAP_SMD_ELKO_GRND(6.6,6.6,5.8,6.3,0.65,1.8,2.6)
#end
#macro CAP_SMD_ELKO_PANASONIC_E(value)
CAP_SMD_ELKO_GRND(8.3,8.3,6.2,8.0,0.65,2.2,3.4)
#end
#macro CAP_SMD_ELKO_PANASONIC_F(value)
CAP_SMD_ELKO_GRND(8.3,8.3,10.2,8.0,0.9,3.1,3.4)
#end
#macro CAP_SMD_ELKO_PANASONIC_G(value)
CAP_SMD_ELKO_GRND(10.3,10.3,10.2,10.0,0.9,4.6,3.5)
#end


/********************************************************************************************************************************************
//Macros for murata TZ03 type F capacitor trimmer
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.0 du 23/12/05
********************************************************************************************************************************************/
#macro CAP_TRIM_TZ03F_GRND(col,dot)
union{
    difference{
        union{ 
            difference{          
                union{
                    torus { 2.5, 0.5 translate 4.3*y}           //top round
                    cylinder{<0,0,0><0,4.3,0> 3}                //main case   
                    cylinder{<0,0,0><0,4.8,0> 2.5}              //top cover 
                } 
                union{    
                    box{<0,-0.2,-3.2><+3.2,5.0,3.2>}            //delete back side (flat side)
                }
            } 
            
            cylinder{<2.5,0,+1.75><2.5,4.3,+1.75> 0.5}          //back bottom to top edges
            cylinder{<2.5,0,-1.75><2.5,4.3,-1.75> 0.5}
            sphere {<2.5,4.3,-1.75>, 0.5}                       //back top corners
            sphere {<2.5,4.3,+1.75>, 0.5}           
            cylinder{<2.5,4.3,+1.75><2.5,4.3,-1.75> 0.5}        //back top corner to corner edge
            box{<-1.3,0,-0.25><+1.3,4.3,+0.25> rotate -16.7*y translate<1.3,0,-2.3709>}     //flanks
            box{<-1.3,0,-0.25><+1.3,4.3,+0.25> rotate +16.7*y translate<1.3,0,+2.3709>}     //flanks
                            
            prism {0 4.8 4 <0, 2.5>, <2.5, 1.75>, <2.5, -1.75>, <0,-2.5>}  //top cover             

            box{<0,0,+1.75><3,4.3,-1.75>}               //back
            cylinder{<-1.35,4.3,0><+1.3,4.3,0> 0.5 rotate -16.7*y translate<1.3,0,-2.11>}   //back top corner to main case edges
            cylinder{<-1.35,4.3,0><+1.3,4.3,0> 0.5 rotate +16.7*y translate<1.3,0,+2.11>}
            
            cylinder{<0,0,+2.5><0,4.3,+2.5> 0.5}        //back bottom to top edges
            cylinder{<0,0,-2.5><0,4.3,-2.5> 0.5}
            sphere {<0,4.3,-2.5>, 0.5}                  //main case junctions
            sphere {<0,4.3,+2.5>, 0.5}
            
        }
        union{
            cylinder{<0,4,0><0,5,0> 1.25}                           //central hole
            box{<+0.1,-1,-0.55><-0.1,6,+0.55> translate -2.9*x }    //front pin groove on round side
            box{<+0.1,-1,-0.6><-0.1,1.1,0.6> translate +2.91*x}     //back pin groove on flat side
        }
         pigment{col}   
    }
    
    union{        
        difference{
            cylinder{<0,4,0><0,4.5,0> 1.1}                  //metalic axe
            union{
                box{<+1.1,4.1,-0.25><-1.1,4.51,+0.25>}      //axe cross grooves
                box{<-0.25,4.11,-1.1><+0.25,4.51,+1.1>}
            }
        }
        
        box{<+0.1,0,-0.5><-0.1,4.2,+0.5> translate -2.9*x}          //visible front pin allong the case
        difference{
            cylinder{<+0.1,0,0><-0.1,0,0> 0.5 rotate -15*z translate <-2.9,4.2,0>} //top front pin
            box{<+0.1,0,-0.5><-0.1,4.2,+0.5> translate -3.1*x }    
        }
        box{<+0.1,0,-0.5><-0.1,1,+0.5> translate +2.91*x }          //visible back pin allong the case
        
        box{<+0.1,-3,-0.5><-0.1,4.3,+0.5> translate 2.54*x}        //flat side pin
        box{<+0.125,-3,-0.5><-0.125,3.0,+0.5> translate -2.54*x}   //round side pin

        box{<+0.1,-0.35355,-0.35355><-0.1,0.35355,+0.35355> rotate 45*x translate <2.54,-3,0>}         //flat side pin
        box{<+0.125,-0.35355,-0.35355><-0.125,0.35355,+0.35355> rotate 45*x translate <-2.54,-3,0>}    //round side pin
        texture{e3d_tex_silver}
    }
    
    #if(dot=1)
        cylinder{<2.2,0,0><2.2,4.81,0> 0.4 pigment{White}} //White dot on the top
    #end
    
    rotate 90*y
}
#end


#macro CAP_TRIM_TZ03F_BLUE()
CAP_TRIM_TZ03F_GRND(Blue,0)
#end
#macro CAP_TRIM_TZ03F_PINK()
CAP_TRIM_TZ03F_GRND(Pink,0)
#end
#macro CAP_TRIM_TZ03F_WHITE()
CAP_TRIM_TZ03F_GRND(White,0)
#end
#macro CAP_TRIM_TZ03F_GREEN()
CAP_TRIM_TZ03F_GRND(Green,0)
#end
#macro CAP_TRIM_TZ03F_ORANGE()
CAP_TRIM_TZ03F_GRND(Orange,0)
#end
#macro CAP_TRIM_TZ03F_RED()
CAP_TRIM_TZ03F_GRND(Red,0)
#end
#macro CAP_TRIM_TZ03F_BROWN()
CAP_TRIM_TZ03F_GRND(Brown,0)
#end
#macro CAP_TRIM_TZ03F_YELLOW()
CAP_TRIM_TZ03F_GRND(Yellow,0)
#end
#macro CAP_TRIM_TZ03F_BLACK()
CAP_TRIM_TZ03F_GRND(Gray15,0)
#end
#macro CAP_TRIM_TZ03F_BLACKDOT()
CAP_TRIM_TZ03F_GRND(Gray15,1)
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
