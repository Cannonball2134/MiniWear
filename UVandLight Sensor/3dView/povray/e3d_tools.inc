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

#ifndef(__e3d_tools_inc)
#declare __e3d_tools_inc = true;

global_settings{charset utf8}

//POVRay include files
#include "arrays.inc"
#include "chars.inc"
#include "colors.inc"
#include "finish.inc"
#include "functions.inc"
#include "glass.inc"
#include "golds.inc"
#include "math.inc"
#include "metals.inc"
#include "rand.inc"
#include "shapes.inc"
#include "shapes2.inc"
#include "shapesq.inc"
#include "skies.inc"
#include "stoneold.inc"
#include "stones.inc"
#include "stones1.inc"
#include "stones2.inc"
#include "strings.inc"
#include "textures.inc"
#include "transforms.inc"

//Library files
#include "e3d_tex.inc"
#include "e3d_ic.inc"
#include "e3d_resistor.inc"
#include "e3d_trafo.inc"
#include "e3d_transistor.inc"
#include "e3d_connector.inc"
#include "e3d_cap.inc"
#include "e3d_diode.inc"
#include "e3d_special.inc"
#include "e3d_socket.inc"
#include "e3d_qfp.inc"
#include "e3d_switch.inc"

//******************************************************************************************************
#if(inc_testmode=true)
    #declare pin_short = on;
    #declare pcb_height = 1.500000;
    #declare pin_length = 2.5;

    #declare global_res_colselect=1;
    #declare global_res_col=1;
    #declare global_res_shape=1;
    #declare global_res_bend_radius=1;

    #declare global_diode_bend_radius=1;

    #declare global_seed=seed(1234);

    #declare global_show_screws = on;
    #declare global_show_washers = on;
    #declare global_show_nuts = on;
    #declare global_ambient_mul = 1.0;
#end

#declare besch_font = "DejaVuLGCSansMono-Bold.ttf"

//******************************************************************************************************
//Font symbols
//Here we declare fonts and fallbacks if the font could not be found
//The fallback font for all fonts is courbd.ttf as we used this font in earlier versions of Eagle3D

#declare global_fontfile_fallback = besch_font;

//Check the availability of the fall back font. If not available throw an error.
#if(file_exists(global_fontfile_fallback)=0)

    #warning "Fallback font not found. Please specify the path to courbd.ttf in the ini-file"
    #declare global_fontfile_fallback = "cyrvetic.ttf"

    #if(file_exists(global_fontfile_fallback) = 0)
        #error "Even the font installed with POVRay could not be found. Giving up."
    #end

#end

#declare global_fontfile_eagle3d        = "eagle3d.ttf"
#declare global_fontfile_courier        = "DejaVuLGCSansMono.ttf";
#declare global_fontfile_courier_bold   = "DejaVuLGCSansMono-Bold.ttf";
#declare global_fontfile_arial          = "DejaVuLGCSans.ttf";
#declare global_fontfile_arial_bold     = "DejaVuLGCSans-Bold.ttf";
#declare global_fontfile_alphalcd       = "alphalcd.ttf"

//The Eagle3D font has to exist
#if(file_exists(global_fontfile_eagle3d) = 0)
    #error "Eagle3D font not found. Please specify the path to eagle3d.ttf in the ini-file"
#end

//Check the availability of font files and set fallback font if not available
#if(file_exists(global_fontfile_courier) = 0)
    #warning "Font Courier not found. Fallback font used"
    #declare global_fontfile_courier = global_fontfile_fallback;
#end

#if(file_exists(global_fontfile_courier_bold) = 0)
    #warning "Font Courier Bold not found. Fallback font used"
    #declare global_fontfile_courier_bold = global_fontfile_fallback;
#end

#if(file_exists(global_fontfile_arial) = 0)
    #warning "Font Arial not found. Fallback font used"
    #declare global_fontfile_arial = global_fontfile_fallback;
#end

#if(file_exists(global_fontfile_arial_bold) = 0)
    #warning "Font Arial Bold not found. Fallback font used"
    #declare global_fontfile_arial_bold = global_fontfile_fallback;
#end

#if(file_exists(global_fontfile_alphalcd)=0)
    #warning "Font AlphaLCD not found. Fallback font arial used"
    #declare global_fontfile_alphalcd = global_fontfile_arial;
#end

//******************************************************************************************************
#macro COL_GOLD()
    #warning "Please use direct texture{} or better the texture{col_gold} identifier instead of COL_GOLD()"
    texture {col_gold}
#end

#macro COL_SILVER()
    #warning "Please use direct texture{} or better the texture{col_silver} identifier instead of COL_SILVER()"
    texture{col_silver}
#end



#ifdef(col_preset)
    //Verschieden Farb-Presets
    #switch(col_preset)
        #case(1)//Standard PCB LĂśtstop
            #declare col_brd = texture{pigment{DarkGreen}}                                  //Farbe der Platine
            #declare col_wrs = texture{pigment{ForestGreen}}                                //Farbe der Leiterbahnen
            #declare col_pds = texture{T_Silver_5A}                                         //Farbe der Pad's und SMD's
            #declare col_hls = texture{pigment{Black}}                                      //Farbe der Pseudobohrungen
            #declare col_bgr = White;                                                          //Hintergrundfarbe wenn keine Umgebung aktiviert
            #declare col_slk = texture{pigment{White}}                                      //Farbe des Bestďż˝ckungsdruck
            #declare col_thl = texture{T_Silver_5A}                                         //Farbe der Durchkontaktierungen
            #declare col_pol = col_wrs                                                      //Farbe der Polygone
        #break
        #case(2)//PCB LĂśtstop MĂźcke
            //PCB material
            #declare col_brd =  texture{
                                    pigment{rgb<0.117647,0.243137,0.015686>}
                                    finish{ambient (0.1 * global_ambient_mul)}
                                }
            //Wires
            #declare col_wrs =  texture{
                                    pigment{rgb<0.368627,0.352941,0.054902>}
                                    finish{ambient (0.1 * global_ambient_mul)}
                                }
            //Pads and SMDs
            #declare col_pds =  texture{
                                    pigment{Gray70}
                                    finish{F_MetalB ambient (0.3 * global_ambient_mul)}
                                }
            //Simulated holes
            #declare col_hls =  texture{
                                    pigment{Black}
                                    finish{ambient (0.1 * global_ambient_mul)}
                                }
            //Background color
            #declare col_bgr =  White;
            //Silkscreen
            #declare col_slk =  texture{
                                    pigment{White}
                                    finish{ambient (0.1 * global_ambient_mul)}
                                }
            //Vias
            #declare col_thl =  texture{
                                    pigment{Gray70}
                                    finish{F_MetalB ambient (0.3 * global_ambient_mul)}
                                }
            //Polygons
            #declare col_pol = col_wrs
        #break
        #case(3)//PCB LĂśtstop MĂźcke 2
            #declare col_brd = texture{     pigment{rgb<0.117647,0.243137,0.015686>}
                                            normal {bumps 0.2 scale 0.00015}
                                            finish {ambient 0.2 diffuse 0.5 phong 0.1}}     //Farbe der Platine
            #declare col_wrs = texture{     pigment{rgb<0.368627,0.352941,0.054902>}
                                            normal{bumps 0.1 scale 0.0001}
                                            finish{ambient 0.2 diffuse 0.5 phong 0.1}}      //Farbe der Leiterbahnen
            #declare col_pds = texture{pigment{Gray70} finish{F_MetalB}}                    //Farbe der Pad's und SMD's
            #declare col_hls = texture{pigment{Black}}                                      //Farbe der Pseudobohrungen
            #declare col_bgr = Gray50;                                                      //Hintergrundfarbe wenn keine Umgebung aktiviert
            #declare col_slk = texture{pigment{White}}                                      //Farbe des BestĂźckungsdruck
            #declare col_thl = texture{pigment{Gray70} finish{F_MetalB}}                    //Farbe der Durchkontaktierungen
            #declare col_pol = col_wrs                                                      //Farbe der Polygone
        #break
        #case(4)//Homemade PCB (with black silkscreen)
            #declare col_brd = texture{pigment{rgb< 0.470588,0.313725,0.000000>}}           //Farbe der Platine
            #declare col_wrs = texture{col_gold}                                            //Farbe der Leiterbahnen
            #declare col_pds = texture{col_gold}                                            //Farbe der Pad's und SMD's
            #declare col_hls = texture{pigment{Black}}                                      //Farbe der Pseudobohrungen
            #declare col_bgr = White;                                                       //Hintergrundfarbe wenn keine Umgebung aktiviert
            #declare col_slk = texture{pigment{Black}}                                      //Farbe des BestĂźckungsdruck
            #declare col_thl = texture{col_silver}                                          //Farbe der Durchkontaktierungen
            #declare col_pol = texture{T_Stone1}                                            //Farbe der Polygone
        #break
        #case(5)//Bunt
            #declare col_brd = texture{pigment{Red}}                                        //Farbe der Platine
            #declare col_wrs = texture{pigment{Blue}}                                       //Farbe der Leiterbahnen
            #declare col_pds = texture{T_Silver_5A}                                         //Farbe der Pad's und SMD's
            #declare col_hls = texture{pigment{Black}}                                      //Farbe der Pseudobohrungen
            #declare col_bgr = White;                                                       //Hintergrundfarbe wenn keine Umgebung aktiviert
            #declare col_slk = texture{pigment{Green}}                                      //Farbe des BestĂźckungsdruck
            #declare col_thl = texture{pigment{White}}                                      //Farbe der Durchkontaktierungen
            #declare col_pol = texture{T_Stone1}                                            //Farbe der Polygone
        #break
        #case(6)//Glass
            #declare col_brd = texture{T_Dark_Green_Glass  }                                //Farbe der Platine
            #declare col_wrs = texture{pigment{rgb<0.368627,0.352941,0.054902>}}            //Farbe der Leiterbahnen
            #declare col_pds = texture{pigment{Gray70} finish{F_MetalB}}                    //Farbe der Pad's und SMD's
            #declare col_hls = texture{pigment{Black}}                                      //Farbe der Pseudobohrungen
            #declare col_bgr = White;                                                       //Hintergrundfarbe wenn keine Umgebung aktiviert
            #declare col_slk = texture{pigment{White}}                                      //Farbe des BestĂźckungsdruck
            #declare col_thl = texture{pigment{Gray70} finish{F_MetalB}}                    //Farbe der Durchkontaktierungen
            #declare col_pol = col_wrs                                                      //Farbe der Polygone
        #break
        #range(7,2000)//Standard wenn Auswahlfehler
            #declare col_brd = texture{pigment{DarkGreen}}                                  //Farbe der Platine
            #declare col_wrs = texture{pigment{ForestGreen}}                                //Farbe der Leiterbahnen
            #declare col_pds = texture{T_Silver_5A}                                         //Farbe der Pad's und SMD's
            #declare col_hls = texture{pigment{Black}}                                      //Farbe der Pseudobohrungen
            #declare col_bgr = White;                                                       //Hintergrundfarbe wenn keine Umgebung aktiviert
            #declare col_slk = texture{pigment{White}}                                      //Farbe des BestĂźckungsdruck
            #declare col_thl = texture{T_Silver_5A}                                         //Farbe der Durchkontaktierungen
            #declare col_pol = col_wrs                                                      //Farbe der Polygone
        #break
    #end
#end


//Zeichnet einen Bogen
//rad = radius
//wid = width of the "line"
//st_wi = start angle
//en_wi = end angle
//height = well, the height
#macro ARC(rad,wid,st_wi,en_wi,height)
    union{
        #local i=st_wi;
        #local l=((rad*pi)/360) * 1.1;
        
        cylinder{<0,0,-rad> <0,height,-rad> wid/2 pigment{Red} rotate<0,-i-90,0> }
        
        #while(i<=en_wi)
            box{<-l,0,-rad-wid/2><l,height,-rad+wid/2> rotate<0,-i-90,0>}
            #declare i=i+1;
        #end
        
        cylinder{<0,0,-rad> <0,height,-rad> wid/2 pigment{Red} rotate<0,-i+1-90,0> }
    }    
#end  


//Joseph Zeglinski
#macro TOOLS_WIRE_LEADS (Length, Width, Wirelength, Wirewidth,  Raster,  BendRadius, Seperation, H_V)

    //Erzeugt DrahtbĂźgel passend fĂźr ein Bauteil
    //Length:   LĂ¤nge des Bauteils (length of body part)
    //Width:    Durchmesser des Bauteils (diameter of body part)
    //Wirelength:   LĂ¤nge des eines Drahtes (length of one wire lead)
    //Wirewidth:    Durchmesser des Drahtes (diameter of the wire)
    //Raster:   Raster
    //BendRadius:   Biegeradius (bending radius)
    //Seperation:   Distance between component bottom and pcb for heat dissipation
    //H_V:          Part Orientation - "H" for horizontal; "V" for vertical (quotes required)

    //      Adds Resistor (or any component), Horizontal or Vertical wire leads, based on (raster,body & wire)
    //      dimensions. It forms a semi-circular bend  with a radius with the value of "BendRadius".
    //      The component making the call must be centred at the origin, at that point. Lead clipping is also handled.

    //      This macro will handle "RADIAL LEAD COMPONENTS as well. Here, the "RASTER" argument is set equal to, or narrower than
    //      the body "LENGTH" argument, and "H_V" is specified as "H" - for Horizontal orientation. For Tall" components,
    //      the "body Length" is the horizontal width, as mounted. Similarly, the "body Width", is the height of the
    //      fully mounted radial-leaded component (e.g  capacitor, or vertical ceramic block resistor PVxx).

    //      Finally, "Seperation" - (height above the PCB, after attaching wires), is also accounted for, in the wires.
    //      This seperation is typically for raising power components >= 1 watt, 1.5 mm above the surface to prevent
    //      scorching the PCB. However, for items like Radial Lead Capacitors, this value can be any size. The calling module
    //      must perform the actual "translate" of the fully assembled part, from the origin, to the final position, upon return.

    // ********************
    // PWB Assembly Pratice:  For Components drawing LESS than 1 watt, should be in contact with PCB.
    //                        Seperation above pcb must NOT exceed 3.0 mm (CLASS 1 and CLASS 2),
    //                        or 0.7 mm for CLASS 3 components.
    //
    //                        The calling routine should have tested the WATTS argument
    //                        and added the seperation, there, to the "Width" argument.

    //
    //      COMMON construction of lead-wires for ALL COMPONENTS:
    //      Correct PWB assembly practice requires that, a bend NOT begin, closer than
    //      "one lead wire diameter (thickness) from the body, with a minimum of at least 0.8 mm"

    #if (Width > Wirewidth)
            #local W=Width/2;
    #else
            #local W=Wirewidth/2
    #end

    #local L=Length/2;
    #local LW=Wirewidth/2;
    #local WA=(Width-Wirewidth)/2;
    #local Stub = max( 0.8, Wirewidth );               // Set the component's "Stub Length" from the body to the start of bending
    #local Horizontal = !(strcmp(strupr(H_V), "H") );  // string compare returns "0" (false) if equal; therefore, Negate this.


    // Special section to handle "RADIAL LEAD" components, like capacitors, inductors, or ceramic block vertical power resistors.
    #if(Horizontal=yes)
        #if ( Raster <= Length )        
            #local BendRadius = 0.0; // Special case for "Leads inside of the body length" (e.g. "RADIAL LEAD" Components)        
            #local Stub = 0.0;
        #end
    #end

    // ********************

    union {

    //
    // Attach the wire leads to the "COMPONENT" body:
    #if (Horizontal = no)     // Which way will the wires go?

        // Wires for "VERTICAL"  Component:
        //TOP axial stub
        cylinder{<0,L/2,0> <0, (L+Stub) ,0> Wirewidth/2}

        //TOP (Perpendicular to body,  WIRE)
        cylinder{<BendRadius, (L+BendRadius+Stub),0> <(Raster-BendRadius), (L+BendRadius+Stub), 0> Wirewidth/2 }

        difference{                                                                      //LEFT-TOP (wire elbow bend)
            torus{BendRadius, Wirewidth/2 rotate<90,0,0>}
            box{<-2*BendRadius, 0, BendRadius>  <2*BendRadius, -2*BendRadius, -BendRadius>}
            box{<2*BendRadius, -BendRadius, BendRadius> <0, 2*BendRadius, -BendRadius>}
            translate <BendRadius, (L+Stub), 0>
        }

        difference{                                                                      //RIGHT-TOP (second wire elbow bend)
            torus{BendRadius, Wirewidth/2 rotate<90,0,0>}
            box{<-2*BendRadius, 0, BendRadius>  <2*BendRadius, -2*BendRadius, -BendRadius>}
            box{<2*BendRadius, -BendRadius, BendRadius> <0, 2*BendRadius, -BendRadius>} rotate<0,180,0>
            translate <(Raster-BendRadius), (L+Stub), 0>
        }


        #if(pin_short = on)
        difference{union{
        #end

        //RIGHT (vertical wire) - if "Raster" happens to be LONGER than remaining lead wire length, then
        //      "solder-on an extension wire", to reach the PCB cutoff position

        #local cutoff = (pin_length+pcb_height) + (L+Stub+Seperation) ;

        cylinder{<Raster, min(-cutoff, (L+Stub)-(Wirelength-(pi*BendRadius+Raster)) ) ,0 > <Raster,(L+Stub),0> Wirewidth/2}

        //LEFT-BOTTOM (axial wire)
        cylinder{<0,-(L),0> <0,min(-cutoff, -(Wirelength+(L+Stub)) ),0> Wirewidth/2 }

        #if(pin_short = on)
        }box{<-LW,-cutoff,LW><Raster+LW,-(cutoff+Wirelength),-LW> }}
        #end

        #else

            // Otherwise, Wires for "HORIZONTAL" Component:

            difference{                                                                          //LEFT (wire elbow bend)
                torus{BendRadius, Wirewidth/2 rotate<90,0,0>}
                box{<-2*BendRadius, 0, BendRadius>  <2*BendRadius, -2*BendRadius, -BendRadius>}
                box{<2*BendRadius, -BendRadius, BendRadius> <0, 2*BendRadius, -BendRadius>}
                translate <-(Raster/2-BendRadius), -BendRadius, 0>
            }

            difference{                                                                          //RIGHT (second wire elbow bend)
                torus{BendRadius, Wirewidth/2 rotate<90,0,0>}
                box{<-2*BendRadius, 0, BendRadius>  <2*BendRadius, -2*BendRadius, -BendRadius>}
                box{<2*BendRadius, -BendRadius, BendRadius> <0, 2*BendRadius, -BendRadius>} rotate<0,180,0>
                translate <(Raster/2-BendRadius), -BendRadius, 0>
            }

            cylinder{<-(Raster/2-BendRadius), 0, 0> <(Raster/2-BendRadius), 0, 0> Wirewidth/2}   //Horizontal WIRE end-to-end, between elbows

            #if(pin_short = on)
            difference{union{
            #end

            // If lead wire is somehow specified too short, then "solder-on an extension wire", to reach the PCB cutoff position, anyway
            #local cutoff = (pin_length+pcb_height) + (W + Seperation) ;

            //RIGHT vertical wire
            cylinder{<Raster/2,-BendRadius,0 > <Raster/2, min(-cutoff, -(Wirelength-pi*BendRadius/2) ),0> Wirewidth/2 }

            //LEFT  vertical wire
            cylinder{<-Raster/2,-BendRadius,0> <-Raster/2, min(-cutoff, -(Wirelength-pi*BendRadius/2) ),0> Wirewidth/2 }

            #if(pin_short = on)
            }box{<-Raster/2-LW, -cutoff, LW> <Raster/2+LW,  -(cutoff+Wirelength),-LW>}}
            #end
        
        #end
        texture{col_silver}
    }    
#end

/**********************************************************************
//Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
//Privat: <fbleikamp@web.de>
//Macro fuer gebogene Rechteckprofile mit Oeffnungswinkel von 1-179 Grad
//Der Schenkel mit der laenge1 liegt mittig auf der x-Achse
//bei einem Winkel von 90Grad der andere auf der y-Achse
//der Innenradius muss >= 0 sein,
//der Winkel zwischen den Schenkeln 0 > Winkel <180,
//mittlerer Biegeradius = i_radius + dicke/2
**********************************************************************/
#macro TOOLS_RECT_BOGEN(i_radius,winkel,dicke,breite,laenge1,laenge2)
union{
    difference {
        cylinder{<(breite/2) * -1,0,0><breite/2,0,0>(i_radius + dicke)}
        cylinder{<(breite/2 + 0.1) * -1,0,0><breite/2 + 0.1,0,0>i_radius}
        box{ <(breite/2 + 0.1) * -1,(i_radius + dicke + 0.1) * -1, 0>,
             <breite/2 + 0.1, (i_radius + dicke + 0.1), (i_radius + dicke + 0.1)>
        }
        box{ <(breite/2 + 0.1) * -1,(i_radius + dicke + 0.1) * -1, 0>,
             <breite/2 + 0.1, (i_radius + dicke + 0.1), (i_radius + dicke + 0.1)> rotate <winkel,0,0>}
        }
        box{<(breite/2) * -1,i_radius, 0>, <breite/2,i_radius + dicke, laenge1 >}
        box{<(breite/2) * -1, 0, i_radius * -1>, <breite/2,laenge2 * -1, (i_radius + dicke) * -1>
            rotate <(90 - winkel) * -1,0,0>
        }
        translate < 0,(i_radius + dicke/2) * -1,(i_radius + dicke/2)> rotate <0,-90,180>
    }
#end


/**********************************************************************
//Generates a VIA
//dia_min:  diameter of the hole
//dia_max:  diameter of the via
//upper:    the upper layer which the via contains to
//lower:    the lower layer which the via contains to
//shape:    the shape of the via
//      0 square
//      1 octagon
//      2 round
//      3 long
//      4 offset
//      if shape >= 100 solder will be added to the via
**********************************************************************/
#macro TOOLS_PCB_VIA(dia_max,dia_min,upper,lower,shape,elongation)

#if((global_solder=on)&(shape>=100))
union{
#else
object{
#end

#local lupper = -global_pcb_layer_dis[upper-1]+pcb_cuheight+0.002;
#local llower = -global_pcb_layer_dis[lower-1]-0.002;


#if(shape>=100)
    #local shape=shape-100;
    #if(global_solder=on)
        difference{
            #local dia = dia_max*0.5;
            cylinder{<0,lupper,0>, <0,lupper+dia,0>dia}
            torus{ dia,dia translate<0,dia,0> scale<1,2,1> translate<0,lupper,0>}
        }

        difference{
            #local dia = dia_max*0.5;
            cylinder{<0,llower,0>, <0,llower-dia,0>dia}
            torus{ dia,dia translate<0,-dia,0> scale<1,2,1> translate<0,llower,0>}
        }
    #end
#end


#if(dia_min>=global_pcb_real_hole)
difference{
#end

//square
#if(shape=0)
    box{<dia_max/2,lupper,dia_max/2><-dia_max/2,llower,-dia_max/2>}
#end
//round
#if(shape=1)
    cylinder{<0,lupper,0><0,llower,0>dia_max/2}
#end
//octagon
#if(shape=2)
prism {
    linear_spline
    lupper, llower, 9,
    #local i = 0;
    #while(i<9)
        <vrotate(<dia_max/2/cos(pi/8),0,0>,<0,i*45+22.5,0>).x,vrotate(<dia_max/2/cos(pi/8),0,0>,<0,i*45+22.5,0>).z>
        #local i = i + 1;
    #end
}
#end
//long
#if(shape=3)
prism {
    linear_spline
    lupper, llower, 9,
    #local i = 0;
    #while(i<9)
        #local pos = <vrotate(<dia_max/2/cos(pi/8),0,0>,<0,i*45+22.5,0>).x,0,vrotate(<dia_max/2/cos(pi/8),0,0>,<0,i*45+22.5,0>).z>;
        #if((i=0)|(i=1)|(i=6)|(i=7)|(i=8))
            <pos.x+(dia_max/2)*(elongation/100),pos.z>
        #else
            <pos.x-(dia_max/2)*(elongation/100),pos.z>
        #end
        #local i = i + 1;
    #end
}
#end
//offset
#if(shape=4)
prism {
    linear_spline
    lupper, llower, 9,
    #local i = 0;
    #while(i<9)
        #local pos = <vrotate(<dia_max/2/cos(pi/8),0,0>,<0,i*45+22.5,0>).x,0,vrotate(<dia_max/2/cos(pi/8),0,0>,<0,i*45+22.5,0>).z>;
        #if((i=2)|(i=3)|(i=4)|(i=5))
            <pos.x,pos.z>
        #else
            <pos.x+(dia_max)*(elongation/100),pos.z>
        #end
        #local i = i + 1;
    #end
}
#end

#if(dia_min>=global_pcb_real_hole)
cylinder{<0,lupper+0.1,0><0,llower-0.1,0> dia_min/2-0.001}
}
#end
}
#end

/**********************************************************************
//Generates an SMD
//xsize:    x-size of the SMD
//ysize:    y-size of the SMD
//thick:    the thikness of the copper
//r:        roundness (0%-100%)
**********************************************************************/
#macro TOOLS_PCB_SMD(xsize,ysize,thick,r)

    #if(r=0)
        box{<-xsize/2,0,-ysize/2><xsize/2,thick,ysize/2>}
    #else
        union{

            #if(xsize>ysize)

                #local xsmall=xsize-(ysize)*(r/100);
                    #local ysmall=ysize-(ysize)*(r/100);
                    #local cyldif=(ysize)*(r/100);

            #else
                #local xsmall=xsize-(xsize)*(r/100);
                    #local ysmall=ysize-(xsize)*(r/100);
                    #local cyldif=(xsize)*(r/100);

            #end

            box{<-xsmall/2,0,-ysize/2><xsmall/2,thick,ysize/2>}
            box{<-xsize/2,0,-ysmall/2><xsize/2,thick,ysmall/2>}

            cylinder{<-xsize/2+cyldif/2,0,-ysize/2+cyldif/2><-xsize/2+cyldif/2,thick,-ysize/2+cyldif/2>cyldif/2}
            cylinder{<-xsize/2+cyldif/2,0, ysize/2-cyldif/2><-xsize/2+cyldif/2,thick, ysize/2-cyldif/2>cyldif/2}
            cylinder{< xsize/2-cyldif/2,0,-ysize/2+cyldif/2>< xsize/2-cyldif/2,thick,-ysize/2+cyldif/2>cyldif/2}
            cylinder{< xsize/2-cyldif/2,0, ysize/2-cyldif/2>< xsize/2-cyldif/2,thick, ysize/2-cyldif/2>cyldif/2}

        }
    #end
#end

/**********************************************************************
//By John van Sickle
//
//    This macro creates a bar with four of its edges rounded. It fills the same
//space as box { Startcorner,EndCorner }, except that the edges running along the
//y-axis are rounded. StartCorner and EndCorner are opposite corners of the box,
//and Radius is the radius of the rounded edges.
//   The bar is made up of a prism object and four cylinder objects that run
//parallel to the y-axis. If you want the bar to run along any other axis, you
//will have to transform it just as you would any prism object. There is no merge
//or union declared around them, to leave the choice up to the user; merge is
//better for applications with transparency, union is better for others. Here is
//an example of the macro's use:
//
//object {
//  TOOLS_ROUNDED_BAR(<-10,0,0>,<10,40,20>,2)
//  pigment { rgb .75 }
//}
//
//Although the example code uses vector literals for StartCorner and EndCorner,
//you can use any vector expression, and scalars will be promoted to full vectors.
//
//Modified by fbleikamp(replace with at)web.de for Eagle3D objects
//
**********************************************************************/

#macro TOOLS_ROUNDED_BAR(v_SP,v_EP,R)
  #local vSP=(v_SP)*<1,1,1>;
  #local vEP=(v_EP)*<1,1,1>;
#if (vSP.x > vEP.x)
  #local tSave=vSP.x;
  #local vSP=<vEP.x,vSP.y,vSP.z>;
  #local vEP=<tSave,vEP.y,vEP.z>;
#end
#if (vSP.y > vEP.y)
  #local tSave=vSP.y;
  #local vSP=<vSP.x,vEP.y,vSP.z>;
  #local vEP=<vEP.x,tSave,vEP.z>;
#end
#if (vSP.z > vEP.z)
  #local tSave=vSP.z;
  #local vSP=<vSP.x,vSP.y,vEP.z>;
  #local vEP=<vEP.x,vEP.y,tSave>;
#end
#union{
  box {<vSP.x+R,vSP.y,vSP.z>,<vEP.x-R,vEP.y,vEP.z>}
  box {<vSP.x,vSP.y+R,vSP.z>,<vEP.x,vEP.y-R,vEP.z>}

  cylinder { <vSP.x+R,vSP.y+R,vSP.z>,<vSP.x+R,vSP.y+R,vEP.z>,R }
  cylinder { <vEP.x-R,vSP.y+R,vSP.z>,<vEP.x-R,vSP.y+R,vEP.z>,R }
  cylinder { <vSP.x+R,vEP.y-R,vSP.z>,<vSP.x+R,vEP.y-R,vEP.z>,R }
  cylinder { <vEP.x-R,vEP.y-R,vSP.z>,<vEP.x-R,vEP.y-R,vEP.z>,R }
   }

#end

/**********************************************************************
//TOOLS_TORUS_SPLINE() By: Ron Parker
//
//    This macro is used to create a smooth spline of toruses connecting
//a sequence of points.  To use it, use code like the following:
//
//#declare Pts=array[5]{<0,0,0>, <1,1,1>, <-.5,1,2>, <.5,1,3>, <0,1,4>}
//object {
//  TOOLS_TORUS_SPLINE( .1, Pts, <1,0,.5> )
//  texture {...}
//  }
//
//The first parameter to the TorusSpline macro is the minor radius of
//the toruses to be used in creating the spline.
//
//The second parameter is the array of points through which the spline
//should pass.
//
//The third parameter is the direction vector to be used at the start
//of the spline.  Varying this vector can have surprising results on
//the resulting object.  If the spline should leave another object at
//a specific angle, as with a lamp cord or rope, use this vector to
//show the angle.  If it is zero, The first torus will be calculated to
//pass through the first three points.  This is usually what you want,
//but you can get some neat effects if you override the default.
//
//It is possible to specify invalid parameters.  If you do, you will
//likely get a parse error.
//
//Achtung!!! Axis in MyAxis umbenannt, konflikt mit macro-name in special.inc <fbleikamp(replace with at)web.de>
//Fehler in Verbindung mit bentpipe.mcr abgefangen bei vcross((B-A),V) = 0 und den daraus folgenden Fehlern.
*********************************************************************/

#macro TOOLS_TORUS_SPLINE( TorRadius, Points, StartVect )

  // promote the start vector to a vector, even if they gave us a scalar (e.g. 0)
  #local V=<0,0,0>+StartVect;
  #local Numpoints = dimension_size( Points, 1 );
  #local Cur = 0;

  union {

    #while (Cur < Numpoints-1 )
      #local A=Points[Cur];
      #local B=Points[Cur+1];
      #if (V.x=0&V.y=0&V.z=0)
        #local C=Points[Cur+2];
        #if (vlength(vcross(C-A,B-A))=0)
          #local V=B-A;
          #local Cos=0;
          #local MyAxis=<0,0,0>;
        #else
          #local MyAxis=vnormalize(vcross((C-A),(B-A)));
          #local Base1=vnormalize(C-A);
          #local Base2=vnormalize(vcross(MyAxis,Base1));
          #local VB=<0.5*vlength(C-A),0,0>;
          #local VA=vcross(VB,z);
          #local VD=.5*<vdot(B-A,Base1),vdot(B-A,Base2),0>;
          #local VC=vcross(VD,z);
          #local Beta=((VD-VB).y*VA.x-(VD-VB).x*VA.y)/(VC.x*VA.y-VC.y*VA.x);
          #local Center=A+VD.x*Base1+VD.y*Base2+Beta*(VC.x*Base1+VC.y*Base2);
          #local Radius=vlength(Center-A);
          #local Cos=1;
          #local V=vcross( MyAxis,Center-A );
        #end
        #local B=C;
        #local Cur=Cur+1;
      #else
         #local C=vcross((B-A),V);  // fbleikamp(replace with at)web.de
         #if ( C.x!=0|C.y!=0|C.z!=0)
            #local MyAxis=vnormalize(vcross((B-A),V));
            #local Dir=vnormalize(vcross(V, MyAxis ));
            #local Cos=vdot(vnormalize(B-A), Dir);
            #local Radius=abs(.5*vlength(B-A)/Cos);
            #local Center=A+Radius*Dir;
         #else
            #local MyAxis=<0,0,0>;
            #local Center=A;
            #local Cos=0;
         #end
      #end

      #local V1=V;

      #if ( Cos & (MyAxis.x!=0|MyAxis.y!=0|MyAxis.z!=0))
        #if (MyAxis.y = 0 & vlength(<MyAxis.x,0,MyAxis.z>) = 0)
          #local RZ=0;
        #else
          #local RZ=-degrees(atan2(vlength(<MyAxis.x,0,MyAxis.z>), MyAxis.y));
        #end
        #if (MyAxis.z = 0 & MyAxis.x = 0 )
          #local RY=0;
        #else
          #local RY=-degrees(atan2(MyAxis.z, MyAxis.x));
        #end
        #local V1=vcross(B-Center, MyAxis);

        #if ( vdot(vcross(V,A-Center),vcross(V, V1))>0 )
          #local Planes =  union{
            plane{-V, vdot( A-.0001*TorRadius*V, vnormalize(-V) ) }
            plane{V1, vdot( .0001*TorRadius*V1+B, vnormalize(V1))}
          }
        #else
          #local Planes =  intersection {
            plane{-V, vdot( A-.0001*TorRadius*V, vnormalize(-V) ) }
            plane{V1, vdot( .0001*TorRadius*V1+B, vnormalize(V1))}
          }
        #end

        intersection{
          object {Planes}
          torus{ Radius, TorRadius rotate RZ*z rotate RY*y translate Center }
        }
      #else
        cylinder {A-.0001*TorRadius*V, B+.0001*TorRadius*V, TorRadius}
      #end
      #declare Cur=Cur+1;
      #declare V=V1;
    #end
  }
#end

/**********************************************************************
//TOOLS_BENTPIPE() By: Ron Parker
//
//   This macro allows you to specify a TorusSpline as a series of "turtle-like" moves rather than as
//   a series of points.  You tell it to start at a particular position and orientation and give it
//   a series of commands (go straight x units, turn left/right x degrees with radius r)
//   and a radius for the pipe and it creates the specified pipe.
//   It does assume you are operating in the X-Y plane.
//   This macro requires my TorusSpline macro as well.  It is possible to provide bad arguments;
//   if you do, you'll get bad results.
//   For example, a 1-unit bend in a 2-unit radius pipe is probably not too smart.
//
//Sample usage:
//#declare bends=array[6] {
//    // <angle, radius, 0> or <0, distance, 0> for straight pipe
//    // negative angles bend left, positive bend right.
//    <0, 10, 0>,  <-45, 5, 0>,  <225,5,0>,  <-225,5,0>,  <45, 5, 0>,  <0, 10, 0>
//}
//
//object {
//    // this pipe has a radius of 1, starts at the origin, and initially goes in the x direction
//    TOOLS_BENTPIPE( 1, <0,0,0>, x, bends )
//    texture {pigment {color rgb 1}}
//}
**********************************************************************/

#macro TOOLS_BENTPIPE( PipeRadius, Loc, Dir, Bends )
  #local Pts=array[dimension_size( Bends, 1 )+1]
  #local Pts[0] = <0,0,0>+Loc;
  #local StartDir = <0,0,0>+Dir;
  #local Cur = 0;
  #while ( Cur < dimension_size( Bends, 1 ) )
    #if (Bends[Cur].u = 0 )
      #local Pts[Cur+1] = Pts[Cur]+Bends[Cur].v*vnormalize(Dir);
    #else
      #local Offset = Bends[Cur].v * vnormalize(vcross( Dir, -Bends[Cur].u*z ));
      #local Pts[Cur+1]=Pts[Cur]-Offset+vrotate(Offset, -Bends[Cur].u*z);
      #local Dir = vrotate( Dir, -Bends[Cur].u*z );
    #end
    #local Cur=Cur+1;
  #end

  TOOLS_TORUS_SPLINE( PipeRadius, Pts, StartDir )
#end

/********************************************************************************************************************************************
//Macros for Screws : M2 M2.5 M3 M4 M5
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1 - 04/01/06
//Lg=lenght Col= color
//Hd:0=PAN 1=PHILIPS-ROUND-PAN 10=SLOTTED HEXA 11=FULL-BEARING 20=CHEESE 21=RAISED-CHEESE
//30=RAISED-COUNTER-SUNK 31=PHILIPS-RAISED-COUNTER-SUNK 32=COUNTER-SUNK 33=PHILIPS-COUNTER-SUNK  34=COUNTER-SUNK-HEXA-SOCKET
//zero is under head for #0 to #21 headed screws and on top for all counter sunk headed screws
********************************************************************************************************************************************/
#macro TOOLS_SCREW (M,lg,Hd,Col)

#switch (M)
    #case(2)
        #local R = 1.6;  //4 0.8
        #local r = 0.4;
        #local ep = 1.3;
        #local r1 = 0.65;
        #local A = 3.6;
        #local delta = 1.12;
        #local B = 1.2;
        #local H = 1.5;
        #local T = 0.4;
        #local S = 1.3;
    #break
    #case(2.5)
        #local R = 2;
        #local r = 0.5; //5  0.8
        #local ep = 1.6;
        #local r1 = 0.8;
        #local A = 4.4;
        #local delta = 1.32;
        #local B = 1.5;
        #local H = 2;
        #local T = 0.45;
        #local S = 1.6;
    #break
    #case(3)
        #local R = 2.4;  // 6  0.8
        #local r = 0.6;
        #local ep = 2;
        #local r1 = 1;
        #local A = 5.3;
        #local delta = 1.52;
        #local B = 1.65;
        #local H = 2.5;
        #local T = 0.5;
        #local S = 1.94;
    #break
    #case(4)
        #local R = 3.2; //8 0.8
        #local r = 0.8;
        #local ep = 2.6;
        #local r1 = 1.3;
        #local A = 6.6;
        #local delta = 1.82;
        #local B = 2.2;
        #local H = 3;
        #local T = 0.7;
        #local S = 2.42;
    #break
    #case(5)
        #local R = 4; //10 0.8
        #local r = 1;
        #local ep = 3.3;
        #local r1 = 1.65;
        #local A = 8;
        #local delta = 2.05;
        #local B = 2.5;
        #local H = 4;
        #local T = 0.8;
        #local S = 2.92;
    #break
#end

union{

    #if(Hd > -1)

        difference //head
        {
            #switch (Hd)
                #range(0,1) // PAN HEAD & PHILIPS ROUND-PAN
                    union
                    {
                        torus {R+r-r1,r1 translate (ep-r1)*y}        // round edge
                        cylinder {<0,0,0>, <0,ep,0>, R+r-r1}       // base
                        cylinder {<0,0.1,0>, <0,ep-r1,0>, R+r}   // top
                    }
                    #if(Hd=0)
                        box {<-r,ep*.5,-R-2*r>, <+r,+10,R+2*r>  } // Grove
                    #else
                        box {<-r,-R/2,-R/2>, <+r,+R/2,+R/2> rotate 45*x translate ep*y  } // Grove
                        box {<-r,-R/2,-R/2>, <+r,+R/2,+R/2> rotate 45*x translate ep*y  rotate 90*y} // Grove
                    #end
                #break

                #range(10,11) // SLOTTED HEXA HEAD & FULL BEARING HEAD
                    intersection {
                        //3 boxes for Hexa nut
                        box {<-A/2,0,-2*M>, <+A/2,+ep+0.1,+2*M> }
                        box {<-A/2,0,-2*M>, <+A/2,+ep+0.1,+2*M> rotate -60*y}
                        box {<-A/2,0,-2*M>, <+A/2,+ep+.01,+2*M> rotate +60*y}
                        sphere {  <0, -delta, 0>  0.83*A }
                    }
                    union{
                        cylinder {<0,+ep,0>, <0,+ep+0.2,0> A/2+r } // to get spotless surface
                        #if(Hd=10)
                            box {<-r,ep*.5,-R-2*r>, <+r,+10,R+2*r>  rotate -30*y } // Grove
                        #end
                    }

                #break

                #case(20) // CHEESE
                    #local R=0.8*R;
                    cylinder {<0,0,0>, <0,ep,0>, R+r}       // base
                    box {<-r,ep*.5,-R-2*r>, <+r,+10,R+2*r>  } // Grove
                #break

                #case(21) // RAISED CHEESE
                    #local R=0.8*R;
                    intersection{
                        sphere{<0,-R/2,0> 1.7*R}
                        cylinder {<0,0,0>, <0,2*ep,0>, R+r}       // base
                    }
                    box {<-r,ep*.4,-R-2*r>, <+r,+10,R+2*r>  } // Grove
                #break

                #range(30,31) // RAISED-COUNTER-SUNK & PHILIPS-RAISED-COUNTER-SUNK
                    union{
                        intersection{
                            sphere{<0,-A/2-S,0> A}
                            cylinder {<0,0,0>, <0,2*ep,0>, A*0.5}       // base
                        }
                        cone{0*y, A*0.5, -B*y,M/2}
                    }
                    #if(Hd=30)
                        box {<-r,-ep*.4,-R-2*r>, <+r,A,R+2*r>  } // Grove
                    #else
                        box {<-r,-R/2,-R/2>, <+r,+R/2,+R/2> rotate 45*x translate ep/3*y  } // Grove
                        box {<-r,-R/2,-R/2>, <+r,+R/2,+R/2> rotate 45*x translate ep/3*y  rotate 90*y} // Grove
                    #end
                #break

                #range(32,34) // COUNTER SUNK
                    cone{0*y, A*0.5, -B*y, M/2.1 }
                    #switch(Hd)
                        #case(32)
                            box {<-r,-ep*.4,-R-2*r>, <+r,0.1,R+2*r>  } // Grove
                        #break
                        #case(33)
                            box {<-r,-R/2,-R/2>, <+r,+R/2,+R/2> rotate 45*x translate 0*y  } // Grove
                            box {<-r,-R/2,-R/2>, <+r,+R/2,+R/2> rotate 45*x translate 0*y  rotate 90*y} // Grove
                        #break
                        #case(34)
                            difference{
                                intersection{
                                    box {<-H/2,0.1,-2*M>, <+H/2,-ep,+2*M> }
                                    box {<-H/2,0.1,-2*M>, <+H/2,-ep,+2*M> rotate -60*y}
                                    box {<-H/2,0.1,-2*M>, <+H/2,-ep,+2*M> rotate +60*y}
                                }
                                cylinder {<0,-ep*.6,0>, <0,-ep,0> A/2+r } // to get spotless surface
                            }
                        #break
                    #end
                #break
            #end

            rotate(rand(global_seed)*180)*y
        }
    #end

    #if(Hd<30)
        #local B1=0;
        #local N=2;
    #else
        #local B1=B;
        #local N=0;
    #end
    difference //body
    {
        union
        {
            cylinder {<0,-B1,0>, <0,-lg+r,0>, M/2}
            cone
            {
              <0,-lg+r,0>, M/2,
              <0,-lg,0>, M/3
            }
        }
        union
        {
            #while (N < (lg/T+1))
                torus {M/1.95,T/2.6 translate (-B1-N*T)*y}
                #local N = N + 1;
            #end
        }
    }

    pigment{Col}
}
#end


/********************************************************************************************************************************************
//Macros for Washers : diameter 2, 2.5, 3, 4, 5
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1 - 04/01/06
//Col= color Type: 0=Z, 1=M, 2=L, 3=LL
********************************************************************************************************************************************/

#macro TOOLS_WASHER (d,Type,Col)
#switch (d)
    #case(2)
        #local AZ = 4;
        #local AM = 6;
        #local AL = 8;
        #local ALL = 10;
        #local C = 0.6;
        #local B = 2.25;
    #break
    #case(2.5)
        #local AZ = 5;
        #local AM = 7;
        #local AL = 9;
        #local ALL = 11;
        #local C = 0.7;
        #local B = 2.75;
    #break
    #case(3)
        #local AZ = 6;
        #local AM = 8;
        #local AL = 12;
        #local ALL = 14;
        #local C = 0.8;
        #local B = 3.25;
    #break
    #case(4)
        #local AZ = 8;
        #local AM = 10;
        #local AL = 14;
        #local ALL = 16;
        #local C = 0.8;
        #local B = 4.25;
    #break
    #case(5)
        #local AZ = 10;
        #local AM = 12;
        #local AL = 16;
        #local ALL = 20;
        #local C = 1;
        #local B = 5.25;
    #break
#end
#switch (Type)
    #case(0)
        #local A=AZ;
    #break
    #case(1)
        #local A=AM;
    #break
    #case(2)
        #local A=AL;
    #break
    #case(3)
        #local A=ALL;
    #break
#end

difference
{
    cylinder {<0,0,0>, <0,C,0>, A/2}
    cylinder {<0,-0.1,0>, <0,C+0.1,0>, B/2}
    pigment{Col}
}
#end

/********************************************************************************************************************************************
//Macros for Nuts : M2, M2.5, M3, M4, M5
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1 - 04/01/06
//Col= color Type: 0=Hu, 1=Hh
********************************************************************************************************************************************/
#macro TOOLS_NUT (M, Type, Col)
#switch (M)
    #case(2)
        #local A = 3.6;
        #local B = 1.4;
        #local T = 0.4;
        #local Delta = 1.75;
    #break
    #case(2.5)
        #local A = 4.5;
        #local B = 1.7;
        #local T = 0.45;
        #local Delta = 2.2;
    #break
    #case(3)
        #local A = 5.5;
        #local B = 2.4;
        #local T = 0.5;
        #local Delta = 2.5;
    #break
    #case(4)
        #local A = 7;
        #local B = 3.2;
        #local T = 0.7;
        #local Delta = 3.1;
    #break
    #case(5)
        #local A = 8;
        #local B = 4;
        #local T = 0.8;
        #local Delta = 3.35;
    #break
#end

#if(Type=1)
    #local Delta = Delta-(M-B)/2;
    #local B=M;
#end

difference
    {
        intersection {
            //3 boxes for hexagonal shape
            box {<-A/2,-2*M,-B/2-0.1>, <+A/2,+2*M,+B/2+0.1> }
            box {<-A/2,-2*M,-B/2-0.1>, <+A/2,+2*M,+B/2+0.1> rotate -60*z}
            box {<-A/2,-2*M,-B/2-0.1>, <+A/2,+2*M,+B/2+0.1> rotate +60*z}
            //make some roundness
            sphere {  <0, 0, +Delta>  0.83*A }
            sphere {  <0, 0, -Delta>  0.83*A }
        }

        union {
            //hole
            cylinder {<0,0,-B>, <0,0,+B>, M/2}
            //thread
            union
            {
                #local N=0;
                # while (N < 10)
                    torus {M/1.95,T/2.6 rotate 90*x translate (-M/2+N*T)*z}
                #local N = N + 1;
                #end
            }
            cylinder {<0,0,+B/2+0.2>, <0,0,+B/2> A/2+T } // to get spotless surface
            cylinder {<0,0,-B/2-0.2>, <0,0,-B/2> A/2+T } // to get spotless surface
        }
        pigment{Col}
        rotate 90*x
        translate B/2*y
        rotate(rand(global_seed)*180)*y
    }
#end


#macro TOOLS_LOGO_AND_CAPTION(caption, logo, min_p, max_p)
union{

#local tgt_size = <max_p.x, 1, max_p.y> - <min_p.x, 1, min_p.y>;

#if(strcmp(logo,"AMD") = 0.0)
    #local logo_obj = text{ttf global_fontfile_eagle3d "6" 0.01,0}
    #local logo_extra_scale = 0.3;
#end

#if(strcmp(logo,"ATMEL") = 0.0)
    #local logo_obj = text{ttf global_fontfile_eagle3d "a" 0.01,0}
    #local logo_extra_scale = 0.7;
#end

#if(strcmp(logo,"FTDI") = 0.0)
    #local logo_obj = text{ttf global_fontfile_eagle3d "f" 0.01,0}
    #local logo_extra_scale = 0.7;
#end

#if(strcmp(logo,"MAXIM") = 0.0)
    #local logo_obj = text{ttf global_fontfile_eagle3d "-" 0.01,0}
    #local logo_extra_scale = 0.9;
#end

//Size and other calculations for logo placement
#local logo_min = min_extent(logo_obj);
#local logo_max = max_extent(logo_obj);
#local logo_size = logo_max - logo_min;
#local logo_obj = object{logo_obj translate -(logo_size / 2) rotate<90, 0, 0>};
#local logo_min = min_extent(logo_obj);
#local logo_max = max_extent(logo_obj);
#local logo_size = logo_max - logo_min;
#if(tgt_size.x < tgt_size.z)
    #local logo_size = <logo_size.z, logo_size.y, logo_size.x>;
#end
#local logo_scale = min((tgt_size / logo_size).x, (tgt_size / logo_size).z) * logo_extra_scale;

//Size and other calculations for caption placement
#local caption_obj = text{ttf global_fontfile_arial caption 0.01, 0}
#local caption_min = min_extent(caption_obj);
#local caption_max = max_extent(caption_obj);
#local caption_size = caption_max - caption_min;
#local caption_obj = object{caption_obj translate -(caption_size / 2) rotate<90, 0, 0>};
#local caption_min = min_extent(caption_obj);
#local caption_max = max_extent(caption_obj);
#local caption_size = caption_max - caption_min;
#if(tgt_size.x < tgt_size.z)
    #local caption_size = <caption_size.z, caption_size.y, caption_size.x>;
#end
#local caption_scale = min((tgt_size / caption_size).x, (tgt_size / caption_size).z) * (0.9 - logo_extra_scale);

union
{
    //Logo placement
    object{
        logo_obj
        scale <logo_scale, 1, logo_scale>
        #if(tgt_size.x >= tgt_size.z)
            translate -<tgt_size.x / 2 - logo_size.x / 2 * logo_scale, 0, 0>
            translate <0, 0, tgt_size.z / 2 - logo_size.z / 2 * logo_scale>

        #else
            rotate<0, 90, 0>
            translate <tgt_size.x / 2 - logo_size.x / 2 * logo_scale, 0, 0>
            translate <0, 0, tgt_size.z / 2 - logo_size.z / 2 * logo_scale>

        #end
    }
    /*
    //Caption placement
    object{
        caption_obj
        scale <caption_scale, 1, caption_scale>
        #if(tgt_size.x >= tgt_size.z)

        #else
            rotate<0, 90, 0>
            translate <tgt_size.x / 2 - logo_size.x * logo_scale - caption_size.x, 0, 0>
            translate <0, 0, tgt_size.z / 2 - caption_size.z / 2 * caption_scale>

        #end

        pigment{Red}
    }
    */


}

//box{logo_min, logo_max}

}
#end

/**********************************************************************
This macro is used for simple object generation
**********************************************************************/
#macro TOOLS_SSDL_BOX( corner1, corner2, trans, rot, sca, c)
#ifdef(global_create_ssdl_file)

#local corner1 = vrotate(corner1,B)

#write( ssdl_file, "BOX:", corner1, corner2, c, "\n")
#end
#end

#end
