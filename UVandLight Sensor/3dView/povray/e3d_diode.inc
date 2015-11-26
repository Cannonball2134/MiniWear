//Eagle3D 20110101 INC-File e3d_diode.inc
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
 
#ifndef(__diode_inc)
#declare __diode_inc = true;

#ifndef(inc_testmode)
#declare inc_testmode=true;
#include "e3d_tools.inc"
#undef inc_testmode
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_DIODE_DIS_LED_7SEG_SYMBOL.inc.src
// 7 segment Symbol
// BuFran <BuFran@hi-web.cz>
// //////////
#macro DIODE_DIS_LED_7SEG_SYMBOL(tra, sca)
union{
        prism{  linear_spline 0,0.036,6,            // segment "A"
                <8.890000,30.480000>,<9.753600,31.165800>,<8.991600,31.750000>,
                <3.886200,31.750000>,<3.479800,31.394400>,<4.241800,30.480000>
        }
        prism{  linear_spline 0,0.036,6,            // segment "B"
                <9.2456,30.1498>,<10.1346,30.8610>,<10.5918,30.5308>,
                <9.7028,25.8064>,<8.5598,26.4414>,<9.2456,30.1498>
         }
        prism{  linear_spline 0,0.036,6,            // segment "C"
         <8.178800,24.206200>,<9.525000,24.892000>,<8.636000,19.989800>,
         <8.305800,19.710400>,<7.518400,20.650200>,<8.178800,24.206200>
        }
        prism{  linear_spline 0,0.036,6,            // segment "D"
          <7.188200,20.320000>,<7.950200,19.405600>,<7.543800,19.050000>,
          <2.438400,19.050000>,<1.676400,19.634200>, <2.540000,20.320000>
        }
        prism{  linear_spline 0,0.036,6,            // segment "E"
          <2.184400,20.650200>,<1.295400,19.939000>,<0.838200,20.269200>,
          <1.727200,24.993600>,<2.870200,24.358600>,<2.184400,20.650200>
        }
        prism{  linear_spline 0,0.036,6,            // segment "F"
          <3.251200,26.593800>,<1.905000,25.908000>,<2.794000,30.810200>,
          <3.124200,31.089600>,<3.911600,30.149800>,<3.251200,26.593800>
        }
        prism{  linear_spline 0,0.036,6,            // segment "G"
          <8.255000,26.035000>,<9.398000,25.400000>,<8.128000,24.765000>,
          <3.175000,24.765000>,<2.032000,25.400000>,<3.302000,26.035000>
        }
	union{
		cylinder{<10.287000,0,19.685000><10.287000,0.036000,19.685000>0.762000 translate<0,0.000000,0>} // Segment DP
	}
        translate tra
        scale sca
}
#end

/********************************************************************************************************************************************
//Discrete Axial Lead Diode Macro from
//REV 1.2
//Joseph Zeglinski

// **********************************
// Individual DIODE TYPE DEFINITIONS:

//   JEDEC DIODE AXIAL PACKAGE TYPES: //Maximums: Body: (Length, Width)
//						  Wire: (Length, Width)
//                 BODY        WIRES
//             LENGTH WIDTH LENGTH WIDTH

// DO-7  =      7.62, 2.71, 38.10, 0.55
// DO-14 =      7.62, 3.55, 38.10, 0.55
// DO-15 =      7.62, 3.55, 38.10, 0.88      //Same as: DO-204AC
// DO-16 =      2.54, 1.27, 19.05, 0.33
// DO-27 =      9.28, 5.2,  25.4,  1.3
// DO-32 =      9.52, 6.35, 38.10, 0.812     //Cone shape: 1.98 mm cone
// DO-34 =      2.2,  1.85, 25.4,  0.56
// DO-35 =      3.85, 1.75, 13.0,  0.45
// DO-39 =      4.06, 3.81, 38.10, 0.914     //Cone shape: 1.14 mm
// DO-41 =      5.2,  2.71, 25.4,  0.86      //Same as: DO-204AL
// DO-41G =     4.1,  2.6,  28.0,  0.86      //D0-41 GLASS and DO-204AL GLASS
// DO-201AD =   9.5,  5.3,  25.4,  1.32
// DO-204AP =   9.5,  5.3,  25.4,  1.07

// 1,5KA =      9.5,  5.3,  25.4,  1.07      //Same as: 1.5KE & DO-204AP
// F126 =       6.35, 3.05, 31.0,  0.86
// GP20 =       9.5,  5.3,  25.4,  1.07
// MPG06 =      3.18, 2.54, 25.4,  0.635
// P600 =       9.1,  9.1,  25.4,  1.32
// R-1 =        3.2,  2.6,  20.0,  0.65

//Define a Vertical Diode

// CALLING PARAMETERS: #macro DIC_DIO(Length, Width, Wirelength, Wirewidth,  value, raster, H_V, Cathode_Down)
//
// CATHODE BAND (Wire Lead) Downward is the default configuration - "Cathode_Down = 1 true"
// Anode Wire Lead across the top and down to through hole pad.
// Change to Cathode_Down = 0 false, to create a new macro with the band at the top - top lead is cathode.

// Choose RASTER: (2.54, 5.08, 7.62, 10.16, 12.7, 15.24) millimetres
********************************************************************************************************************************************/
#macro DIODE_DIS_GRND(Length, Width, Wirelength, Wirewidth,  value, raster, H_V, Cathode_Down)

// ********************
// PWB Assembly Pratice:  For Components drawing LESS than 1 watt, should be in contact with PCB.
//                        Seperation must NOT exceed 3.0 mm (CLASS 1 and CLASS 2), 
//                        or 0.7 mm for CLASS 3 components
//                        Seperation should be 1.5 mm for WATTS >= 1.0


#ifndef (Seperation) #local Seperation = 0.0; #end   // Standard vertical component seperation above board (1 watt or greater) 
 
// *********************        

#local L=Length/2;
#local W=Width/2;
#local LW=Wirewidth/2;
#local Horizontal = !(strcmp(strupr(H_V), "H") ); // string compare returns "0" (false) if equal; therefore, Negate this.
#local Stub = max( 0.8, Wirewidth );    // Set the component's "Stub Length" from the body to the start of bending
#local Bend_Radius = global_diode_bend_radius;   // wire bending radius for ALL diodes - set globally


union {
union {

// Build the DIODE body Vertically:

cylinder{<0,-L,0> <0,L,0> W}
torus{W-W/10,W/10 rotate<0,90,0> translate<0,-L,0>}             // Rounded end
torus{W-W/10,W/10 rotate<0,90,0> translate<0,L,0>}              // Rounded end
cylinder{<0,-L,0> <0,-(L+W/10),0> (W-W/10) }                    // End cap
cylinder{<0,L,0> <0,(L+W/10),0> (W-W/10) }                      // End cap
cylinder{<0,0.78*L,0> <0,0.9*L,0>(W+W/10000) pigment{White}}  // Cathode Band
intersection{
cylinder{<-L,0,0><L,0,0> (W+W/10000)}
union{
//
// Print IDENT (value) on all 4 sides, for viewability:

        // create a TrueType text shape
        #local astring = text {
        // one string
        ttf // font type (only TrueType format for now)
        besch_font, // Microsoft Windows-format TrueType font file name
        value, // the string to create
        1.0, // the extrusion depth
        0 // inter-character spacing
        }

        #local astrscale = 1.56*L/(max_extent(astring).x) ;
                // (1.56*L) is print area (mm), one band-distance from each end. Scale only in X-direction.  
        object{astring scale <astrscale,1,1> translate< (-0.7*L), -0.375, -(W+0.3) > rotate<270,0,0>}
        object{astring scale <astrscale,1,1> translate< (-0.7*L), -0.375, -(W+0.3) > rotate<180,0,(Horizontal ? 180 : 0)>}
        object{astring scale <astrscale,1,1> translate< (-0.7*L), -0.375, -(W+0.3) > rotate<90,0,0>}
        object{astring scale <astrscale,1,1> translate< (-0.7*L), -0.375, -(W+0.3) > }
        }
//
        rotate<0,0,-90>       // Align the lettering cylinder, vertically
        pigment{White}        // Paint the lettering white
          } 
          
        pigment{Gray20}        // Paint the diode body dark gray
        finish { phong 0.3  ambient (0.1 * global_ambient_mul)}

        #if (Horizontal=yes)  
        rotate<0,0,90>                        // Rotate built diode into horizontal position, Cathode on the left side.
                                              // Cathode_Down is not relevant - deos not matter -  for horizontal diodes
        #else rotate<0,0,(Cathode_Down*180)>  // Flip a vertical diode to cathode band downward if Cathode_Down is "TRUE".
        #end 
        }

//
// Attach the wire leads to the diode body:

// Go build the wires, after setting up the arguments for the common routine.

    
     object{ TOOLS_WIRE_LEADS((Length+2*W/10), Width, Wirelength, Wirewidth,  raster,  Bend_Radius, Seperation, H_V)  }  // Common bent wire generator

       


// Still need to RAISE the DIODE an appropriate amount above PCB surface
// Position the component above the PCB

        #if (Horizontal=no)
           translate < -raster/2, (L+W/10+Stub + Seperation)  ,0 >
        #else
           translate < 0, (W + Seperation), 0 >
        #end

// ALL DONE: Horizontal or Vertical Diode is positioned.

}
#end

//Horizontal from Eagle-Lib
#macro DIODE_DIS_DO7_102MM_H(value)
DIODE_DIS_GRND(7.62, 2.71, 38.10, 0.55, value,  10.16, "H",  0) pigment{Gray20}
#end
#macro DIODE_DIS_DO15_127MM_H(value)
DIODE_DIS_GRND(7.62, 3.55, 38.10, 0.88, value,  12.70, "H",  0) pigment{Gray20}
#end
#macro DIODE_DIS_DO27_152MM_H(value)
DIODE_DIS_GRND(9.28, 5.20, 25.40, 1.30, value,  15.24, "H",  0) pigment{Gray20}
#end
#macro DIODE_DIS_DO34_050MM_H(value)
DIODE_DIS_GRND(2.20, 1.85, 25.40, 0.56, value,  05.08, "H",  0) pigment{Gray20}
#end
#macro DIODE_DIS_DO34_076MM_H(value)
DIODE_DIS_GRND(2.20, 1.85, 25.40, 0.56, value,  07.62, "H",  0) pigment{Gray20}
#end
#macro DIODE_DIS_DO35_076MM_H(value)
DIODE_DIS_GRND(3.85, 1.75, 13.00, 0.45, value,  07.62, "H",  0) pigment{Gray20}
#end
#macro DIODE_DIS_DO35_102MM_H(value)
DIODE_DIS_GRND(3.85, 1.75, 13.00, 0.45, value,  10.16, "H",  0) pigment{Gray20}
#end
#macro DIODE_DIS_DO41_076MM_H(value)
DIODE_DIS_GRND(5.20, 2.71, 25.40, 0.86, value,  07.62, "H",  0) pigment{Gray20}
#end
#macro DIODE_DIS_DO41_102MM_H(value)
DIODE_DIS_GRND(5.20, 2.71, 25.40, 0.86, value,  10.16, "H",  0) pigment{Gray20}
#end
#macro DIODE_DIS_DO201_152MM_H(value)
DIODE_DIS_GRND(9.50, 5.30, 25.40, 1.32, value,  15.24, "H",  0) pigment{Gray20}
#end
//Vertical from Eagle-Lib
#macro DIODE_DIS_DO35_050MM_V(value)
DIODE_DIS_GRND(3.85, 1.75, 13.00, 0.45, value,  05.08, "V",  1) pigment{Gray20}
#end
#macro DIODE_DIS_DO16_025MM_V(value)
DIODE_DIS_GRND(2.54, 1.27, 19.05, 0.33, value,  02.54, "V",  1) pigment{Gray20}
#end
#macro DIODE_DIS_DO41_050MM_V(value)
DIODE_DIS_GRND(5.20, 2.71, 25.40, 0.86, value,  05.08, "V",  1) pigment{Gray20}
#end
// VERTICAL Macros:
#macro DIODE_DIS_DO7_025MM_V(value)
DIODE_DIS_GRND(7.62, 2.71, 38.10, 0.55, value,  2.54,  "V",  1) pigment{Gray45}
#end
#macro DIODE_DIS_DO14_025MM_V(value)
DIODE_DIS_GRND(7.62, 3.55, 38.10, 0.55, value,  2.54,  "V",  1) pigment{Gray45}
#end
#macro DIODE_DIS_DO15_025MM_V(value)
DIODE_DIS_GRND(7.62, 3.55, 38.10, 0.88, value,  2.54,  "V",  1) pigment{Gray45}
#end
#macro DIODE_DIS_DO16_025MM_V(value)
DIODE_DIS_GRND(2.54, 1.27, 19.05, 0.33, value,  2.54,  "V",  1) pigment{Gray45}
#end
#macro DIODE_DIS_DO34_025MM_V(value)
DIODE_DIS_GRND(2.2,  1.85, 25.4,  0.56, value,  2.54,  "V",  1) pigment{Gray45}
#end
#macro DIODE_DIS_DO35_025MM_V(value)
DIODE_DIS_GRND(3.85, 1.75, 13.0,  0.45, value,  2.54,  "V",  1) pigment{Gray45}
#end
#macro DIODE_DIS_DO39_025MM_V(value)
DIODE_DIS_GRND(4.06, 3.81, 38.10, 0.914, value, 2.54,  "V",  1) pigment{Gray45}
#end
#macro DIODE_DIS_DO41_025MM_V(value)
DIODE_DIS_GRND(5.2,  2.71, 25.4,  0.86, value,  2.54,  "V",  1) pigment{Gray45}
#end
#macro DIODE_DIS_DO41G_025MM_V(value)
DIODE_DIS_GRND(4.1,  2.6,  28.0,  0.86, value,  2.54,  "V",  1) pigment{Gray45}
#end
#macro DIODE_DIS_DO204AC_025MM_V(value)
DIODE_DIS_GRND(7.62, 3.55, 38.10, 0.88, value,  2.54,  "V",  1) pigment{Gray45}
#end
#macro DIODE_DIS_DO204AL_025MM_V(value)
DIODE_DIS_GRND(4.1,  2.6,  28.0,  0.86, value,  2.54,  "V",  1) pigment{Gray45}
#end
#macro DIODE_DIS_F126_025MM_V(value)
DIODE_DIS_GRND(4.1,  2.6,  28.0,  0.86, value,  2.54,  "V",  1) pigment{Gray45}
#end
#macro DIODE_DIS_R1_025MM_V(value)
DIODE_DIS_GRND(3.2,  2.6,  20.0,  0.65, value,  2.54,  "V",  1) pigment{Gray45}
#end
#macro DIODE_DIS_DO27_050MM_V(value)
DIODE_DIS_GRND(9.28, 5.2,  25.4,  1.3,  value,  5.08,  "V",  1) pigment{Gray45}
#end
#macro DIODE_DIS_DO32_050MM_V(value)
DIODE_DIS_GRND(9.52, 6.35, 38.10, 0.812, value, 5.08,  "V",  1) pigment{Gray45}
#end
#macro DIODE_DIS_DO201AD_050MM_V(value)
DIODE_DIS_GRND(9.5,  5.3,  25.4,  1.32, value,  5.08,  "V",  1) pigment{Gray45}
#end
#macro DIODE_DIS_DO204AP_050MM_V(value)
DIODE_DIS_GRND(9.5,  5.3,  25.4,  1.07, value,  5.08,  "V",  1) pigment{Gray45}
#end
#macro DIODE_DIS_1_5KA_050MM_V(value)
DIODE_DIS_GRND(9.5,  5.3,  25.4,  1.07, value,  5.08,  "V",  1) pigment{Gray45}
#end
#macro DIODE_DIS_1_5KE_050MM_V(value)
DIODE_DIS_GRND(9.5,  5.3,  25.4,  1.07, value,  5.08,  "V",  1) pigment{Gray45}
#end
#macro DIODE_DIS_GP20_050MM_V(value)
DIODE_DIS_GRND(9.5,  5.3,  25.4,  1.07, value,  5.08,  "V",  1) pigment{Gray45}
#end
#macro DIODE_DIS_P600_076MM_V(value)
DIODE_DIS_GRND(9.1,  9.1,  25.4,  1.32, value,  7.62,  "V",  1) pigment{Gray45}
#end
#macro DIODE_DIS_DO204AC_050MM_V(value)
DIODE_DIS_GRND(7.62, 3.55, 38.10, 0.88, value,  5.08,  "V",  1) pigment{Gray45}
#end
// HORIZONTAL MACROS:
#macro DIODE_DIS_DO7_102MM_H(value)
DIODE_DIS_GRND(7.62, 2.71, 38.10, 0.55, value,  10.16, "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_DO14_102MM_H(value)
DIODE_DIS_GRND(7.62, 3.55, 38.10, 0.55, value,  10.16, "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_DO15_102MM_H(value)
DIODE_DIS_GRND(7.62, 3.55, 38.10, 0.88, value,  10.16, "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_DO16_050MM_H(value)
DIODE_DIS_GRND(2.54, 1.27, 19.05, 0.33, value,  5.08,  "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_DO34_050MM_H(value)
DIODE_DIS_GRND(2.2,  1.85, 25.4,  0.56, value,  5.08,  "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_DO35_050MM_H(value)
DIODE_DIS_GRND(3.85, 1.75, 13.0,  0.45, value,  5.08,  "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_DO39_050MM_H(value)
DIODE_DIS_GRND(4.06, 3.81, 38.10, 0.914, value, 5.08,  "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_DO41_076MM_H(value)
DIODE_DIS_GRND(5.2,  2.71, 25.4,  0.86, value,  7.62,  "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_DO41G_050MM_H(value)
DIODE_DIS_GRND(4.1,  2.6,  28.0,  0.86, value,  5.08,  "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_DO204AC_101MM_H(value)
DIODE_DIS_GRND(7.62, 3.55, 38.10, 0.88, value,  10.16, "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_DO204AL_050MM_H(value)
DIODE_DIS_GRND(4.1,  2.6,  28.0,  0.86, value,  5.08,  "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_F126_050MM_H(value)
DIODE_DIS_GRND(4.1,  2.6,  28.0,  0.86, value,  5.08,  "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_R1_050MM_H(value)
DIODE_DIS_GRND(3.2,  2.6,  20.0,  0.65, value,  5.08,  "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_DO27_127MM_H(value)
DIODE_DIS_GRND(9.28, 5.2,  25.4,  1.3,  value,  12.7,  "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_DO32_127MM_H(value)
DIODE_DIS_GRND(9.52, 6.35, 38.10, 0.812, value, 12.7,  "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_DO201AD_127MM_H(value)
DIODE_DIS_GRND(9.5,  5.3,  25.4,  1.32, value,  12.7,  "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_DO204AP_127MM_H(value)
DIODE_DIS_GRND(9.5,  5.3,  25.4,  1.07, value,  12.7,  "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_1_5KA_127MM_H(value)
DIODE_DIS_GRND(9.5,  5.3,  25.4,  1.07, value,  12.7,  "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_1_5KE_127MM_H(value)
DIODE_DIS_GRND(9.5,  5.3,  25.4,  1.07, value,  12.7,  "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_GP20_127MM_H(value)
DIODE_DIS_GRND(9.5,  5.3,  25.4,  1.07, value,  12.7,  "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_P600_127MM_H(value)
DIODE_DIS_GRND(9.1,  9.1,  25.4,  1.32, value,  12.7,  "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_CB417_127MM_H(value)
DIODE_DIS_GRND(8.8,  3.6,  25.4,  1.00, value,  12.7,  "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_CB417_152MM_H(value)
DIODE_DIS_GRND(8.8,  3.6,  25.4,  1.00, value,  15.24,  "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_CB429_178MM_H(value)
DIODE_DIS_GRND(9.5,  5.0,  25.4,  1.00, value,  17.8,  "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_CB429_152MM_H(value)
DIODE_DIS_GRND(9.5,  5.0,  25.4,  1.00, value,  15.24,  "H",  0) pigment{Gray45}
#end
#macro DIODE_DIS_P600_152MM_H(value)
DIODE_DIS_GRND(9.1,  9.1,  25.4,  1.32, value,  15.24,  "H",  0) pigment{Gray45}
#end


/********************************************************************************************************************************************
//Macros Laser Diode or Receiver pigtail from PD-LD
//Designed by Philippe Boucheny <philippe.boucheny(at)free.fr>
//Rev. 1.0  13/04/06   
********************************************************************************************************************************************/
#macro DIODE_DIS_LASER_PDLD_PIGTAIL_GRND()
#macro DIODE_DIS_LASER_PDLD_PIGTAIL_PIN(L1,L2,Dx,Dy,Case)
union{
    #declare bends=array[3] {<0, L1, 0>,  <-90, 0.5, 0>,  <0,L2,0>}
    
    #object {
        TOOLS_BENTPIPE( 0.225, <0,0,0>, x, bends )
        rotate <180,90,0> translate <Dx,3.7+Dy,-12> texture {Gold_Texture}
    }
    #if(Case=0)
    cylinder{<Dx,3.7+Dy,-12><Dx,3.7+Dy,-12.05> 0.4 pigment{Black}}
    #end
}
#end

union{
    difference{
        union{
            box{<-8.35,0,-2><+8.35,+1,+2>}
            box{<-3.7,0,-2><+3.7,7.4,+2> }
        }
        cylinder{<-6.35,-0.1,0><-6.35,2.1,0> 1.1}
        cylinder{<+6.35,-0.1,0><+6.35,2.1,0> 1.1}
        cylinder{<0,3.7,-2.1><0,3.7,+2.1> 3}
        box{<-1.5,+1.5,-2.1><+1.5,-1.5,+2.1> rotate 45*z translate<-3.7,7.4,0>}
        box{<-1.5,+1.5,-2.1><+1.5,-1.5,+2.1> rotate 45*z translate<+3.7,7.4,0>}
        box{<-0.75,+3.7,-2.1><+0.75,+7.5,+2.1>}
    
        pigment{Gray15}
        finish {
           diffuse 0.5 
           specular 0.5
           ambient (0.1 * global_ambient_mul)
        }
    }  
    
    cylinder{<0,3.7,15><0,3.7,40> 0.45 pigment{White}} 
       
    union{
       cylinder{<0,3.7,12.6><0,3.7,15> 1.5} 
       cone{<0,3.7,11.6>,1.95,<0,3.7,12.6> 1.5} 
       cylinder{<0,3.7,8><0,3.7,11.6> 1.95} 
       cone{<0,3.7,6>,3,<0,3.7,8> 1.95} 
       cylinder{<0,3.7,6><0,3.7,-5.5> 3} 
       cylinder{<0,3.7,-10.5><0,3.7,-10.3> 2.8} 
        pigment{Gray10}
        finish {
           diffuse 0.5
           specular 0.5
           ambient (0.1 * global_ambient_mul)
        }
    }  
    
    cylinder{<0,3.7,-10.5><0,3.7,-12> 3 texture {Gold_Texture}} 
    cylinder{<0,3.7,-5.5><0,3.7,-10.3> 3 texture{Aluminum}} 
       
    #if(global_show_screws=on)
        object { TOOLS_SCREW(2,6,1,Silver) translate <+6.35,1,0> }
        object { TOOLS_SCREW(2,6,1,Silver) translate <-6.35,1,0> }
    #end
    #if(global_show_washers=on)
        object { TOOLS_WASHER(2,0,Silver)  translate <+6.35,-1.6-0.7,0> }
        object { TOOLS_WASHER(2,0,Silver)  translate <-6.35,-1.6-0.7,0> }
    #end
    #if(global_show_nuts=on)
        object { TOOLS_NUT(2,0,Silver)     translate <+6.35,-1.6-0.7-1.4,0> }
        object { TOOLS_NUT(2,0,Silver)     translate <-6.35,-1.6-0.7-1.4,0> }
    #end
    
    #declare bends=array[3] {<0, 3, 0>, <-90, 0.5, 0>, <0,5,0>}
    #local Dp = 1;
    #local Lp = 4.5;
    #object { DIODE_DIS_LASER_PDLD_PIGTAIL_PIN( 1.335-0.5+2.54,Lp+2*Dp,+Dp,+Dp,0 ) }
    #object { DIODE_DIS_LASER_PDLD_PIGTAIL_PIN( 1.335-0.5+2.54,Lp+2*Dp,-Dp,+Dp,1 ) }
    #object { DIODE_DIS_LASER_PDLD_PIGTAIL_PIN( 1.335-0.5,Lp,+Dp,-Dp,0 ) }
    #object { DIODE_DIS_LASER_PDLD_PIGTAIL_PIN( 1.335-0.5,Lp,-Dp,-Dp,0 ) }
    
    //rotate 180*y
}
#end

#macro DIODE_DIS_LASER_PDLD_PIGTAIL()
DIODE_DIS_LASER_PDLD_PIGTAIL_GRND()
#end


/********************************************************************************************************************************************
//LED 3mm
********************************************************************************************************************************************/
#macro DIODE_DIS_LED_3MM_GRND(col,tra,height)
union{
	merge{
		cylinder{<0,0.75,0><0,3,0>1.5}
		difference{
			cylinder{<0,0,0><0,0.75,0>1.7}
			box{<1.501,-0.1,-3><3,2,3>}
		}
		sphere{<0,3,0>1.5}
	}
	
	#if(pin_short=off)
		box{<-0.2,1.5,-0.2><0.2,-30.4,0.2> texture{col_silver}translate<-1.27,0,0>}
	#else
		box{<-0.2,1.5,-0.2><0.2,-1*(pcb_height+pin_length+height)-0.2,0.2> texture{col_silver}translate<-1.27,0,0>}
	#end
	
	difference{
		box{<-0.2,1.5,-0.2><2,2.5,0.2>texture{col_silver}translate<-1.27,0,0>}
		box{<0,0,-0.201><2,1,0.201>texture{col_silver} rotate<0,0,15> translate<0,0.5,0>}
		lathe{
			linear_spline 3,
			<0, 0>, <1.2, 1> <0,1> texture{col_silver} translate<0,1.7,0>}
		}
		lathe{
			linear_spline 4,
			<0, 0>, <1, 1>, <1.2,1>,<0.2,0>
			texture{col_silver} translate<0,1.7,0>
		}
		
		box{<-0.4,0,-0.4><0.4,0.3,0.4>pigment{col} finish{ ambient (1 * global_ambient_mul)} translate<0,2.2,0>}
		
		difference{
		#if(pin_short=off)
			box{<-0.2,1.1,-0.2><0.2,-25.4,0.2> texture{col_silver}translate<1.27,0,0>}
		#else
			box{<-0.2,1.1,-0.2><0.2,-1*(pcb_height+pin_length+height)-0.2,0.2> texture{col_silver}translate<1.27,0,0>}
		#end
		cylinder{<-0.2,1.1,-0.201><-0.2,1.1,0.201>0.2 translate<1.24,0,0>}
	}
	
	box{<0,1,-0.2><0.2,2.6,0.2>translate<1.27,0,0> texture{col_silver}}
	
	pigment{col filter tra}
	interior { ior 1.5 }
	translate<0,0.2,0>
	 	
	translate<0,height,0>
}
#end
#macro DIODE_DIS_LED_3MM(col,tra,height)
DIODE_DIS_LED_3MM_GRND(col,tra,height)
#end


/********************************************************************************************************************************************
//LED 5mm
********************************************************************************************************************************************/
#macro DIODE_DIS_LED_5MM_GRND(col,tra,height)
union{
	merge{
		cylinder{<0,0.75,0><0,6,0>2.5}
		difference{
			cylinder{<0,0,0><0,0.75,0>2.8}
			box{<2.501,-0.1,-3><3,2,3>}
		}
		sphere{<0,6,0>2.5}
	}
	#if(pin_short=off)
		box{<-0.2,2,-0.2><0.2,-30.4,0.2> texture{col_silver}translate<-1.27,0,0>}
	#else
		box{<-0.2,2,-0.2><0.2,-1*(pcb_height+pin_length+height)-0.2,0.2> texture{col_silver}translate<-1.27,0,0>}
	#end
	difference{
		box{<-0.2,2,-0.2><2,3,0.2>texture{col_silver}translate<-1.27,0,0>}
		box{<0,0,-0.201><2,1,0.201>texture{col_silver} rotate<0,0,15> translate<0,1,0>}
		lathe{
			linear_spline 3,
			<0, 0>, <1.2, 1> <0,1> 
			texture{col_silver} translate<0,2.2,0>
		}
	}
	lathe{
		linear_spline 4,
		<0, 0>, <1, 1>, <1.2,1>,<0.2,0>
		texture{col_silver} translate<0,2.2,0>
	}
	box{<-0.4,0,-0.4><0.4,0.3,0.4>pigment{col} finish{ ambient (1 * global_ambient_mul)} translate<0,2.7,0>}
	difference{
		#if(pin_short=off)
			box{<-0.2,1.8,-0.2><0.2,-25.4,0.2> texture{col_silver}translate<1.27,0,0>}
		#else
			box{<-0.2,1.8,-0.2><0.2,-1*(pcb_height+pin_length+height)-0.2,0.2> texture{col_silver}translate<1.27,0,0>}
		#end
		cylinder{<-0.2,1.8,-0.201><-0.2,1.8,0.201>0.2 translate<1.24,0,0>}
	}
	box{<0,1,-0.2><0.2,3.3,0.2>translate<1.27,0,0> texture{col_silver}}
	
	pigment{col filter tra}
	interior { ior 1.5 }
	translate<0,0.2,0>
	 
	translate<0,height,0>
}
#end
#macro DIODE_DIS_LED_5MM(col,tra,height)
DIODE_DIS_LED_5MM_GRND(col,tra,height)
#end


/********************************************************************************************************************************************
//7 segment Grundmakro
//BuFran <BuFran@hi-web.cz>
********************************************************************************************************************************************/
#macro DIODE_DIS_LED_7SEG_GRND(value)
union{
        #if(pin_short=off)
                #local pp=7.0;
        #else
                #local pp=pcb_height+pin_length;
        #end
        
        difference{
                box{<-17.9,0,-12.9><17.9,10.5,12.9> pigment{White}}
                box{<-18,10,-13><18,10.7,13> pigment{Gray30}}
                box{<-18,-0.1,-11><18,1,11> pigment{Gray70}}
                box{<-16,-0.2,-13><16,1.1,13> pigment{Gray70}}        
        }
        
        union{
                DIODE_DIS_LED_7SEG_SYMBOL(<-6,0,-25.5>, <0.1,1,0.09>)
                scale<16,1,16>
                translate<-9,10,0>
                pigment{Red}
        }
        
        union{
                DIODE_DIS_LED_7SEG_SYMBOL(<-6,0,-25.5>, <0.1,1,0.09>)
                scale<16,1,16>
                translate<9,10,0>
                pigment{Red}
        }
        
        text{ttf besch_font "M" 0.5,0 pigment{Black} scale<3,5.5,3> translate<-7.5,3,-13>}
        text{ttf besch_font "KINGBRIGHT" 0.5,0.1*x pigment{Black} scale<1,2,1> translate<-3.5,5,-13>}
        text{ttf besch_font value 0.5,0.1*x pigment{Black} scale<1,2,1> translate<-3.5,3,-13>}
        
        union{
                cylinder{<0,2,-11>,<0,-pp,-11>,0.25 translate<10.16,0,0>}
                cylinder{<0,2,-11>,<0,-pp,-11>,0.25 translate<7.62,0,0>}
                cylinder{<0,2,-11>,<0,-pp,-11>,0.25 translate<5.08,0,0>}
                cylinder{<0,2,-11>,<0,-pp,-11>,0.25 translate<2.54,0,0>}
                cylinder{<0,2,-11>,<0,-pp,-11>,0.25}
                cylinder{<0,2,-11>,<0,-pp,-11>,0.25 translate<-2.54,0,0>}
                cylinder{<0,2,-11>,<0,-pp,-11>,0.25 translate<-5.08,0,0>}
                cylinder{<0,2,-11>,<0,-pp,-11>,0.25 translate<-7.62,0,0>}
                cylinder{<0,2,-11>,<0,-pp,-11>,0.25 translate<-10.16,0,0>}
                
                cylinder{<0,2,11>,<0,-pp,11>,0.25 translate<10.16,0,0>}
                cylinder{<0,2,11>,<0,-pp,11>,0.25 translate<7.62,0,0>}
                cylinder{<0,2,11>,<0,-pp,11>,0.25 translate<5.08,0,0>}
                cylinder{<0,2,11>,<0,-pp,11>,0.25 translate<2.54,0,0>}
                cylinder{<0,2,11>,<0,-pp,11>,0.25}
                cylinder{<0,2,11>,<0,-pp,11>,0.25 translate<-2.54,0,0>}
                cylinder{<0,2,11>,<0,-pp,11>,0.25 translate<-5.08,0,0>}
                cylinder{<0,2,11>,<0,-pp,11>,0.25 translate<-7.62,0,0>}
                cylinder{<0,2,11>,<0,-pp,11>,0.25 translate<-10.16,0,0>}

                pigment{Silver}
        }
        
}
#end
#macro DIODE_DIS_LED_7SEG_2(value)
DIODE_DIS_LED_7SEG_GRND(value)
#end


/********************************************************************************************************************************************
//7 segment Grundmakro
//ChristophGraf(replace with at)web.de
********************************************************************************************************************************************/
#macro DIODE_DIS_LED_7SEG_HDSP_Q_GRND(value)

#macro DIODE_DIS_LED_7SEG_20CM_EAGLE_SYMBOL()
union{
        prism{  linear_spline 0,0.036,6,            // segment "A"
                <8.890000,30.480000>,<9.753600,31.165800>,<8.991600,31.750000>,
                <3.886200,31.750000>,<3.479800,31.394400>,<4.241800,30.480000>
        }
        prism{  linear_spline 0,0.036,6,            // segment "B"
                <9.2456,30.1498>,<10.1346,30.8610>,<10.5918,30.5308>,
                <9.7028,25.8064>,<8.5598,26.4414>,<9.2456,30.1498>
         }
        prism{  linear_spline 0,0.036,6,            // segment "C"
         <8.178800,24.206200>,<9.525000,24.892000>,<8.636000,19.989800>,
         <8.305800,19.710400>,<7.518400,20.650200>,<8.178800,24.206200>       
        }
        prism{  linear_spline 0,0.036,6,            // segment "D"
          <7.188200,20.320000>,<7.950200,19.405600>,<7.543800,19.050000>,
          <2.438400,19.050000>,<1.676400,19.634200>, <2.540000,20.320000>     
        }
        prism{  linear_spline 0,0.036,6,            // segment "E"
          <2.184400,20.650200>,<1.295400,19.939000>,<0.838200,20.269200>,
          <1.727200,24.993600>,<2.870200,24.358600>,<2.184400,20.650200>
        }
        prism{  linear_spline 0,0.036,6,            // segment "F"
          <3.251200,26.593800>,<1.905000,25.908000>,<2.794000,30.810200>,
          <3.124200,31.089600>,<3.911600,30.149800>,<3.251200,26.593800>
        }
        prism{  linear_spline 0,0.036,6,            // segment "G"
          <8.255000,26.035000>,<9.398000,25.400000>,<8.128000,24.765000>,
          <3.175000,24.765000>,<2.032000,25.400000>,<3.302000,26.035000>     
        }
	union{
		cylinder{<10.287000,0,19.685000><10.287000,0.036000,19.685000>0.762000 translate<0,0.000000,0>} // Segment DP
	}
       translate<-10.9869,0,-25.4092>
        scale<0.1,1,0.1>
}
#end

union{
        #if(pin_short=off)
                #local pp=7.0;
        #else
                #local pp=pcb_height+pin_length;
        #end
        difference{
             box{<-10.1092,0,13.9192><10.1092,8.9,-13.9192> pigment{White}}            
             box{<-10.9092,8.4,14.4192><11.1092,9.1,-14.1192> pigment{Gray30}}
             box{<-9.1092,-0.1,13.1192><9.1092,1,-13.1192> pigment{Gray70}}
             box{<-8.1092,-0.2,14.9192><8.1092,1.1,-14.9192> pigment{Gray70}}    
        }     

      

        
        union{
                DIODE_DIS_LED_7SEG_20CM_EAGLE_SYMBOL()
                scale<16,1,16>
               translate<9,8.4,0>
                pigment{Red}
           }
        
        text{ttf besch_font "M" 0.5,0 pigment{Black} scale<3,5.5,3> translate<-7.5,3,-14.1338>}
        text{ttf besch_font "KINGBRIGHT" 0.5,0.1*x pigment{Black} scale<1,2,1> translate<-3.5,5,-14.1338>}
        text{ttf besch_font value 0.5,0.1*x pigment{Black} scale<1,2,1> translate<-3.5,3,-14.1338>}
        
        union{
                cylinder{<-11.1331,2,18.9992>,<-11.1331,-pp,18.9992>,0.25 }
                cylinder{<-11.1331,2,16.4592>,<-11.1331,-pp,16.4592>,0.25 }
                cylinder{<-11.1331,2,13.9192>,<-11.1331,-pp,13.9192>,0.25 }
                cylinder{<-11.1331,2,11.3792>,<-11.1331,-pp,11.3792>,0.25 }
                cylinder{<-11.1331,2,8.8392>,<-11.1331,-pp,8.8392>,0.25}
                cylinder{<4.1069,2,18.9992>,<4.1069,-pp,18.9992>,0.25 }
                cylinder{<4.1069,2,13.9192>,<4.1069,-pp,13.9192>,0.25 }
                cylinder{<4.1069,2,11.3792>,<4.1069,-pp,11.3792>,0.25 }
                cylinder{<4.1069,2,8.8392>,<4.1069,-pp,8.8392>,0.25 }  
                cylinder{<4.1069,2,6.2992>,<4.1069,-pp,6.2992>,0.25 }
                cylinder{<4.1069,2,3.7592>,<4.1069,-pp,3.7592>,0.25 }
                cylinder{<4.1069,2,1.2192>,<4.1069,-pp,1.2192>,0.25 }
                
                  translate<3.5131,0,-10.1092>
     
                pigment{Silver}
        }
        
}
#end


#macro DIODE_DIS_LED_7SEG_20CM_EAGLE(value)
DIODE_DIS_LED_7SEG_HDSP_Q_GRND(value)
#end


/********************************************************************************************************************************************
// TOT 4301FE-1N  -  3 stelliges LED-Display rot                       Joerg Bredendiek <sprut(replace with at)sprut.de>   
// TOT 4301NG-1   -  2 1/2 stelliges LED-Display gruen     
// 
// verwendet segment Grundmakro DIODE_DIS_LED_7SEG_SYMBOL() von BuFran <BuFran(replace with at)hi-web.cz>              
//
// Mittelpunkt in geometrischer Mitte
********************************************************************************************************************************************/
#macro DIODE_DIS_LED_7SEG_TOT_GRND(value)
#local tot_pastic= texture { pigment{Gray40} finish {specular 1 roughness 0.001 reflection 0.2 ambient (0.1 * global_ambient_mul)} } ;   //etwas glatter/glaenzender

union{
        #if(pin_short=off)
                #local pp=5.0;
        #else
                #local pp=pcb_height+pin_length;
        #end
        
        difference{
                box{<-15  ,  0  , -8  ><15  , 7  , 8  > pigment{White}}     // weisser Grundkoerper
                box{<-16  ,  7.1, -9  ><16  , 6.9, 9  > pigment{Gray30}}    // graue Platte oben
                box{<-16  , -0.1, -3.5><16  , 1  , 3.5> pigment{White}}     // Ausspartung unten
                box{<-13.5, -0.1, -9  ><13.5, 1  , 9  > pigment{White}}     // Ausspartung unten    
                //3 Anzeigestellen
                union{
                        DIODE_DIS_LED_7SEG_SYMBOL(<-6,0,-25.5>, <0.1,10,0.09>)
                        scale<7,1,9>
                        translate<-10,6.8,0>
                        texture{tot_pastic} 
                }        
                union{
                        DIODE_DIS_LED_7SEG_SYMBOL(<-6,0,-25.5>, <0.1,10,0.09>)
                        scale<7,1,9>
                        translate< 0,6.8,0>
                        texture{tot_pastic} 
                }        
                union{
                        DIODE_DIS_LED_7SEG_SYMBOL(<-6,0,-25.5>, <0.1,10,0.09>)
                        scale<7,1,9>
                        translate<+10,6.8,0>
                        texture{tot_pastic} 
                } 
        }
         
        // Beschriftung      
        text{ttf besch_font value 0.5,0.1*x pigment{Black} scale<3,4,1> translate<-12.5,2.5,-8.02>}
        
        //pins
        union{    
                //untere Pinreihe
                cylinder{<0,2,-6.35>,<0,-pp,-6.35>,0.25 translate<-5*1.27,0,0>}
                cylinder{<0,2,-6.35>,<0,-pp,-6.35>,0.25 translate<-3*1.27,0,0>}
                cylinder{<0,2,-6.35>,<0,-pp,-6.35>,0.25 translate<-1*1.27,0,0>}
                cylinder{<0,2,-6.35>,<0,-pp,-6.35>,0.25 translate< 1*1.27,0,0>}
                cylinder{<0,2,-6.35>,<0,-pp,-6.35>,0.25 translate< 3*1.27,0,0>}
                //obere Pinreihe                
                cylinder{<0,2,6.35>,<0,-pp,6.35>,0.25 translate<-5*1.27,0,0>}
                cylinder{<0,2,6.35>,<0,-pp,6.35>,0.25 translate<-3*1.27,0,0>}
                cylinder{<0,2,6.35>,<0,-pp,6.35>,0.25 translate<-1*1.27,0,0>}
                cylinder{<0,2,6.35>,<0,-pp,6.35>,0.25 translate< 1*1.27,0,0>}
                cylinder{<0,2,6.35>,<0,-pp,6.35>,0.25 translate< 3*1.27,0,0>}
                cylinder{<0,2,6.35>,<0,-pp,6.35>,0.25 translate< 5*1.27,0,0>}
                pigment{Silver}
        }
}
#end


#macro DIODE_DIS_LED_7SEG_TOT4301(value)
DIODE_DIS_LED_7SEG_TOT_GRND(value)
#end


/********************************************************************************************************************************************
// LED-7-Segment-Anzeigen aus DDR-Bestaenden                       Joerg Bredendiek <sprut(replace with at)sprut.de>   
// VQE14 VQE24 u.s.w.        
//
// VQE13  rot  , gemeinsame Kathode, 2-stellig    (= Toshiba TLR324)
// VQE14  rot  , gemeinsame Anode,   2-stellig    (= Toshiba TLR325)
// VQE11  rot  , gemeinsame Kathode, 1.5-stellig  (= Toshiba TLR326)
// VQE12  rot  , gemeinsame Anode,   1.5-stellig  (= Toshiba TLR327)
// VQE23  gruen, gemeinsame Kathode, 2-stellig    (= Toshiba TLG324)
// VQE24  gruen, gemeinsame Anode,   2-stellig    (= Toshiba TLG325)
// VQE21  gruen, gemeinsame Kathode, 1.5-stellig  (= Toshiba TLG326)
// VQE22  gruen, gemeinsame Anode,   1.5-stellig  (= Toshiba TLG327)
// 
// benutzt das segment Grundmakro DIODE_DIS_LED_7SEG_SYMBOL() von BuFran <BuFran(replace with at)hi-web.cz>              
//
// Mittelpunkt in geometrischer Mitte
********************************************************************************************************************************************/
#macro DIODE_DIS_LED_7SEG_VQE_GRND(value, col, tra, height)
#local vqe_col=col*0.3;        //Farbe abdunkeln
#local tra=0.9;                //Transparenz fest einstellen
#local vqe_pastic= texture { pigment{vqe_col filter tra} finish {roughness 0.5 diffuse 0.7 crand 0.1  ambient (0.1 * global_ambient_mul)} } ;   // rauh

union{
        #if(pin_short=off)
                #local pp=3.1;
        #else
                #local pp=pcb_height+pin_length;
        #end   
        
        // transparenter Koerper        
        // offizielle Aussenmasse sind 24.8 x 20 x 9.5 mm
        // offizielle Pinlaenge ist 3.1 mm
        difference{                                                                                   
                union{
                        box{<-12.4  ,  0.5  , -10  >< 12.4  , 9.5  , 10  >}     // Grundkoerper in rot oder gruen
                        box{<-12.4  ,  9.5  , -10  >< 12.4  , 9.7  ,-8.5 > texture{vqe_pastic}}     // rauer Streifen
                        box{<-12.4  ,  9.5  ,  10  >< 12.4  , 9.7  , 8.5 > texture{vqe_pastic}}     // 
                        box{<-12.2  ,  0.5  , -7.5 ><-12    , 0    ,-4   >}     // Fuss
                        box{<-12.2  ,  0.5  ,  7.5 ><-12    , 0    , 4   >}     // Fuss
                        box{< 12.2  ,  0.5  , -7.5 >< 12    , 0    ,-4   >}     // Fuss
                        box{< 12.2  ,  0.5  ,  7.5 >< 12    , 0    , 4   >}     // Fuss
                }
                box{<-2  , -2, -2><2  , 10, 2> rotate <0,45,0> translate <13.5,  0  ,-10  >}     // Ecke ab  
                box{<-4.5, -2, -2><4.5,  2, 2> rotate <45,0,0> translate < 0  , 10.7,-11.2>}     // Vorderkante ab 
                pigment{vqe_col filter tra}
        }     
            
        // weisser Chiptraeger    
        difference{
                box{<-11.6, 6, -8.8><11.6, 8.5, 8.8> pigment{Gray50}}      //keramischer Grundkoerper
                //2 Anzeigestellen
                union{
                        DIODE_DIS_LED_7SEG_SYMBOL(<-6,0,-25.5>, <0.1,10,0.09>)
                        scale<9,1,12>
                        translate<-6.35,8.4,0>
                        pigment{White} 
                }        
                union{
                        DIODE_DIS_LED_7SEG_SYMBOL(<-6,0,-25.5>, <0.1,10,0.09>)
                        scale<9,1,12>
                        translate< 6.35,8.4,0>
                        pigment{White}
                }        
        }
         
        // Beschriftung      
        text{ttf besch_font "WF"  0.5,0.1*x pigment{White} scale<2,3,0.1> translate<-10, 4,-10.02>}
        text{ttf besch_font value 0.5,0.1*x pigment{White} scale<2,3,0.1> translate< -4, 4,-10.02>}
        
        //pins
        union{    
                //untere Pinreihe
                cylinder{<0,2,-7.62>,<0,-pp,-7.62>,0.225 translate<-8*1.27,0,0>}
                cylinder{<0,2,-7.62>,<0,-pp,-7.62>,0.225 translate<-6*1.27,0,0>}
                cylinder{<0,2,-7.62>,<0,-pp,-7.62>,0.225 translate<-4*1.27,0,0>}
                cylinder{<0,2,-7.62>,<0,-pp,-7.62>,0.225 translate<-2*1.27,0,0>}
                cylinder{<0,2,-7.62>,<0,-pp,-7.62>,0.225 translate< 0*1.27,0,0>}
                cylinder{<0,2,-7.62>,<0,-pp,-7.62>,0.225 translate< 2*1.27,0,0>}
                cylinder{<0,2,-7.62>,<0,-pp,-7.62>,0.225 translate< 4*1.27,0,0>}
                cylinder{<0,2,-7.62>,<0,-pp,-7.62>,0.225 translate< 6*1.27,0,0>}
                cylinder{<0,2,-7.62>,<0,-pp,-7.62>,0.225 translate< 8*1.27,0,0>}
                //obere Pinreihe                
                cylinder{<0,2, 7.62>,<0,-pp, 7.62>,0.225 translate<-8*1.27,0,0>}
                cylinder{<0,2, 7.62>,<0,-pp, 7.62>,0.225 translate<-6*1.27,0,0>}
                cylinder{<0,2, 7.62>,<0,-pp, 7.62>,0.225 translate<-4*1.27,0,0>}
                cylinder{<0,2, 7.62>,<0,-pp, 7.62>,0.225 translate<-2*1.27,0,0>}
                cylinder{<0,2, 7.62>,<0,-pp, 7.62>,0.225 translate< 0*1.27,0,0>}
                cylinder{<0,2, 7.62>,<0,-pp, 7.62>,0.225 translate< 2*1.27,0,0>}
                cylinder{<0,2, 7.62>,<0,-pp, 7.62>,0.225 translate< 4*1.27,0,0>}
                cylinder{<0,2, 7.62>,<0,-pp, 7.62>,0.225 translate< 6*1.27,0,0>}
                cylinder{<0,2, 7.62>,<0,-pp, 7.62>,0.225 translate< 8*1.27,0,0>}
                pigment{Silver}
        }  
}
#end

#macro DIODE_DIS_LED_7SEG_VQE(value, col, tra, height)
DIODE_DIS_LED_7SEG_VQE_GRND(value, col, tra, height)
#end


/********************************************************************************************************************************************
// Rectangular led
// 
// By BuFran <BuFran@hi-web.cz>
//
// col				: The color of led
// tra				: Transparence of LED
// height			: The LED is lifted up 
// w / h   			: Width / height of LED
********************************************************************************************************************************************/
#macro DIODE_DIS_LED_RECT_GRND(col,tra,height,w,h)
union{
		box{<0,0,0><h,7,w> pigment { col filter tra}
			translate <-h/2,height-7,-w/2>
        }
        
        #if(pin_short=off)
                #local pp=-30.0+height;
        #else
                #local pp=-pcb_height-pin_length-8;
        #end
        
        box {<0.24,height+3,0.24><-0.24,pp,-0.24> translate <-1.27,-7,0>}
        box {<0.24,height+3,0.24><-0.24,pp,-0.24> translate <1.27,-7,0>}
        
        box {<-0.34,0,-0.24><0.34,1,0.24> translate <-1.27,height-9,0>} 
        box {<-0.34,0,-0.24><0.34,1,0.24> translate <1.27,height-9,0>}
        
        prism{                                                          // inner box
                linear_spline -0.24 0.24 7
                <0,0><0,6><5,6><3,1><1,1><1,0><0,0>
                scale <0.48,1,0.48>
                rotate <-90,0,0>
                translate <-1.51,height-6,0>
        }
        prism{
                linear_spline -0.24 0.24 7
                <0,0><0,6><-0.5,6><-2.5,1><-1,1><-1,0><0,0>
                scale <0.48,1,0.48>
                rotate <-90,0,0>
                translate <1.51,height-6,0>
        
        }
        
        cone{<0,-0.8,0>,0,<0,0,0>,0.6 translate <0,height-3.1,0>}
        
        pigment{Silver}
        
        translate<0,8,0>
}
#end
#macro DIODE_DIS_LED_RECT_2_5MM(col,tra,height)
DIODE_DIS_LED_RECT_GRND(col,tra,height,2.5,2.5)
#end


/********************************************************************************************************************************************
//Reihen-LEDs LZR181 - LZR185 Siemens
//Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de> 
//Privat: <fbleikamp@web.de>
//a = Anzahl
********************************************************************************************************************************************/
#macro DIODE_DIS_ROW_2MM_GRND(a,col,tra,height)
#macro DRLED_2MM(col,tra,height)
union{
	merge{
		//Body
		difference{
			cylinder{<0,0,0><0,1.6,0>2.1 translate<-0.4,0,0>} 
			box{<-2.6,-0.1,-2.6><1.3,1.7,2.6>}}
			box{<-1.6,0,-1.27><1.3,1.6,1.27>} 
			cylinder{<0,0.75,0><0,2,0>1}
			sphere{<0,2,0>1}
		}
		//Anode
		#if(pin_short=off)
			box{<-0.2,0.5,-0.2><0.2,-30.4,0.2> texture{col_silver}translate<-1.27,0,0>}
		#else
			box{<-0.2,0.5,-0.2><0.2,-1*(pcb_height+pin_length+height)-0.2,0.2> texture{col_silver}translate<-1.27,0,0>}
		#end
		difference{
			box{<-0.2,0.5,-0.2><2,1.5,0.2>texture{col_silver}translate<-1.27,0,0>}
			box{<0,-1.0,-0.201><2,0,0.201>texture{col_silver} rotate<0,0,15> translate<0,0.5,0>}
			lathe{
				linear_spline 3,
				<0, 0>, <1.2, 1> <0,1> 
				texture{col_silver} translate<0,0.6,0>
			}
		}
		//Kathode
		difference{
			#if(pin_short=off)
				box{<-0.2,0.5,-0.2><0.2,-25.4,0.2> texture{col_silver}translate<1.27,0,0>}
			#else
				box{<-0.2,0.5,-0.2><0.2,-1*(pcb_height+pin_length+height)-0.2,0.2> texture{col_silver}translate<1.27,0,0>}
			#end
			cylinder{<-0.2,0.5,-0.201><-0.2,0.5,0.201>0.2 texture{col_silver} translate<1.24,0,0>
		}
	}
	box{<0,0.1,-0.2><0.2,1.4,0.2>translate<1.27,0,0> texture{col_silver}}
	box{<0.7,1.2,-0.2><1.27,1.4,0.2>translate<0,0,0> texture{col_silver}}
	//Cristal
	box{<-0.3,0,-0.3><0.3,0.3,0.3>pigment{col} finish{ ambient (1 * global_ambient_mul)} translate<0,1,0>}
	
	//Reflector
	//lathe{linear_spline 4,<0, 0>, <0.6,0.6>, <0.8,0.6>,<0.2,0> texture{col_silver}translate<0,0.6,0>}
	pigment{col filter tra}
	translate<0,0.1,0>
	translate<0,0.1+height,0>
}
#end


#if(a>1)
union{
#else
object{
#end
#local i=0;
        #while(i<a)
                object{DRLED_2MM(col,tra,height) translate<0,0,i*2.54>}
                #local i=i+1;
        #end
        #if(a>1)
        translate<0,0,-(a-1)*1.27>
        #end
}
#end
#macro DIODE_DIS_ROW_2MM_1(col,tra,height)
DIODE_DIS_ROW_2MM_GRND(1,col,tra,height)
#end
#macro DIODE_DIS_ROW_2MM_2(col,tra,height)
DIODE_DIS_ROW_2MM_GRND(2,col,tra,height)
#end
#macro DIODE_DIS_ROW_2MM_3(col,tra,height)
DIODE_DIS_ROW_2MM_GRND(3,col,tra,height)
#end
#macro DIODE_DIS_ROW_2MM_4(col,tra,height)
DIODE_DIS_ROW_2MM_GRND(4,col,tra,height)
#end
#macro DIODE_DIS_ROW_2MM_5(col,tra,height)
DIODE_DIS_ROW_2MM_GRND(5,col,tra,height)
#end


/********************************************************************************************************************************************
//Macros for horizontal TO220 diodes with shortly bended pins
//Modified by Philippe Boucheny <philippe.boucheny(at)numericable.fr>
//from Tobias Mueller's TO220 transistor package : TR_TO220_L2
//Rev. 1.0  04/06/07
********************************************************************************************************************************************/
#macro DIODE_DIS_TO220_L2_GRND(value)
union{
union{
union{
difference{
box{<-0.375,0,0><0.375,8.5,0.6>}
box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45-0.375,0,-0.2>}
box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3-0.375,0,-0.2>}}
difference{
cylinder{<-0.375,8.5,0.6><0.375,8.5,0.6>0.6}
cylinder{<-0.38,8.0,1.1><0.38,8.0,1.1>0.5}}
box{<-0.375,8.5,0.6><0.375,9.1,4.0>}
translate<-2.54,0,2.54>}
union{
difference{
box{<-0.375,0,0><0.375,8.5,0.6>}
box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45-0.375,0,-0.2>}
box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3-0.375,0,-0.2>}}
difference{
cylinder{<-0.375,8.5,0.6><0.375,8.5,0.6>0.6}
cylinder{<-0.38,8.0,1.1><0.38,8.0,1.1>0.5}}
box{<-0.375,8.5,0.6><0.375,9.1,4.0>}
translate<2.54,0,2.54>}
translate<0,-6.58,-4>}
union{
difference{ // metal base
box{<-5.1,22.6,4.5><5.1,29,4.5-1.27>}
cylinder{<0,0,0><0,0,2>1.9 translate<0,26.2,2.6>}
cylinder{<0,0,0><0,0,2>0.5 translate<+5.1,26.2,2.6>}
cylinder{<0,0,0><0,0,2>0.5 translate<-5.1,26.2,2.6>}
}
box{<-4,22.6,4.5><4,16,4.501>}
difference{
box{<-5.1,13.5,0><5.1,22.6,4.5>}
box{<-5.5,0,0><5.5,3,-2> rotate<45,0,0> translate<0,22.6-1.8,0> }
box{<-5.5,0,0><5.5,-1,2> rotate<-20,0,0> translate<0,13.5,3.7> }
cylinder{<0,14.5,0.1><0,14.5,-0.05>0.7}
pigment{Gray30}}
text{ttf besch_font value 0.5,0 pigment{White} scale<1.7,2,1.7>
translate<-3.5,18,-0.01>}
box{<0,2,0><1.5,3.7,0.6> translate<-0.75,0,1.5>
translate<2.54,9.8,0>}
box{<0,2,0><1.5,3.7,0.6> translate<-0.75,0,1.5>
translate<-2.54,9.8,0>}
translate<-0,-13.5,0>rotate<90,0,0>translate<-0,4,1.3>}
translate<0,0.6,-2.7>
texture{col_silver}}
#end

#macro DIODE_DIS_TO220_L2(value)
DIODE_DIS_TO220_L2_GRND(value)
#end


/********************************************************************************************************************************************
//Macros for horizontal TO220 diodes with bended pins
//Modified by Philippe Boucheny <philippe.boucheny(at)numericable.fr>
//from Tobias Mueller's TO220 transistor package : TR_TO220_L
//Rev. 1.0  04/06/07
********************************************************************************************************************************************/
#macro DIODE_DIS_TO220_L_GRND(value)
union{union{
union{
difference{
box{<-0.375,0,0><0.375,8.5,0.6>}
box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45-0.375,0,-0.2>}
box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3-0.375,0,-0.2>}}
difference{
cylinder{<-0.375,8.5,0.6><0.375,8.5,0.6>0.6}
cylinder{<-0.38,8.0,1.1><0.38,8.0,1.1>0.5}}
box{<-0.375,8.5,0.6><0.375,9.1,4.0>}translate<-2.54,0,0>}
union{
difference{
box{<-0.375,0,0><0.375,8.5,0.6>}
box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45-0.375,0,-0.2>}
box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3-0.375,0,-0.2>}}
difference{
cylinder{<-0.375,8.5,0.6><0.375,8.5,0.6>0.6}
cylinder{<-0.38,8.0,1.1><0.38,8.0,1.1>0.5}}
box{<-0.375,8.5,0.6><0.375,9.1,4.0>}translate<2.54,0,0>}
translate<0,-6.58,-4>}
union{
difference{
box{<-5.1,22.6,4.5><5.1,29,4.5-1.27>}
cylinder{<0,0,0><0,0,2>1.9 translate<0,26.2,2.6>}
cylinder{<0,0,0><0,0,2>0.5 translate<+5.1,26.2,2.6>}
cylinder{<0,0,0><0,0,2>0.5 translate<-5.1,26.2,2.6>}
}
box{<-4,22.6,4.5><4,16,4.501>}
difference{
box{<-5.1,13.5,0><5.1,22.6,4.5>}
box{<-5.5,0,0><5.5,3,-2> rotate<45,0,0> translate<0,22.6-1.8,0> }
box{<-5.5,0,0><5.5,-1,2> rotate<-20,0,0> translate<0,13.5,3.7> }
pigment{Gray30}}
text{ttf besch_font value 0.5,0 pigment{White} scale<1.7,2,1.7> translate<-3.5,18,-0.01>}
box{<0,0,0><1.5,3.7,0.6> translate<-0.75,0,1.5> translate<2.54,9.8,0>}
box{<0,0,0><1.5,3.7,0.6> translate<-0.75,0,1.5> translate<-2.54,9.8,0>}
translate<-0,-13.5,0>rotate<90,0,0>translate<-0,4,1.3>}
translate<0,0.6,-2.7>
texture{col_silver}}
#end
#macro DIODE_DIS_TO220_L(value)
DIODE_DIS_TO220_L_GRND(value)
#end


/********************************************************************************************************************************************
//Macros for horizontal TO220 diodes with bended pins
//Modified by Philippe Boucheny <philippe.boucheny(at)numericable.fr>
//from Tobias Mueller's TO220 transistor package : TR_TO220_L
//Rev. 1.0  04/06/07
********************************************************************************************************************************************/
#macro DIODE_DIS_TO220_S_GRND(value)
union{union{union{
#if(pin_short=off)
#local tr_to220_s_pin = 9.5;
#else
#local tr_to220_s_pin = 9.5-(pcb_height+pin_length);
#end
difference{
box{<0,tr_to220_s_pin,0><0.75,13.5,0.6>}
box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45,tr_to220_s_pin,-0.2>}
box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3,tr_to220_s_pin,-0.2>}
translate<-2.54,0,0>}
difference{
box{<0,tr_to220_s_pin,0><0.75,13.5,0.6>}
box{<0,0,0><1,1,1> rotate<0,0,-25> translate<0.45,tr_to220_s_pin,-0.2>}
box{<0,0,0><-1,1,1> rotate<0,0,25> translate<0.3,tr_to220_s_pin,-0.2>}
translate<2.54,0,0>}
box{<0,0,0><1.5,3.7,0.6> translate<-0.375,0,0> translate<2.54,9.8,0>}
box{<0,0,0><1.5,3.7,0.6> translate<-0.375,0,0> translate<-2.54,9.8,0>}
translate<-0.75/2,0,1.6>}
difference{
box{<-5.1,22.6,4.5><5.1,29,4.5-1.27>}
cylinder{<0,0,0><0,0,2>1.9 translate<0,26.2,2.6>}
cylinder{<0,0,0><0,0,2>0.5 translate<+5.1,26.2,2.6>}
cylinder{<0,0,0><0,0,2>0.5 translate<-5.1,26.2,2.6>}
}
box{<-4,22.6,4.5><4,16,4.501>}
texture{col_silver}}
difference{
box{<-5.1,13.5,0><5.1,22.6,4.5>}
box{<-5.5,0,0><5.5,3,-2> rotate<45,0,0> translate<0,22.6-1.8,0> }
box{<-5.5,0,0><5.5,-1,2> rotate<-20,0,0> translate<0,13.5,3.7> }
pigment{Gray30}}
text{ttf besch_font value 0.5,0 pigment{White} scale<1.7,2,1.7> translate<-3.5,18,-0.01>}
translate<0,-9.5,-4.5>}
#end

#macro DIODE_DIS_TO220_S(value)
DIODE_DIS_TO220_S_GRND(value)
#end


/********************************************************************************************************************************************
// SMD-LED die zur Seite leuchtet - EVERLIGHT 12-215SURC/S530-A2/TR8
// col = Farbe
// tra = Durchsichtigkeit
// height = Höhe
// everyone1@freenet.de
********************************************************************************************************************************************/
#macro DIODE_LED_SMD_SIDE_GRND(col,tra,height)

union{
        difference{
                merge{
                        cylinder{ <-0.35, 0.01, 0.25> <-0.35, 0.61, 0.25> 0.5 }
                        cylinder{ < 0.35, 0.01, 0.25> < 0.35, 0.61, 0.25> 0.5 }
                        box{ <-0.35, 0.01, 0.25> < 0.35, 0.61, 0.75> }
                                texture{
                                pigment{col filter tra}
	                }
	        }
	        box{ <-1.0, 0, -0.25> < 1.0, 0.62, 0.25>}
                texture{ pigment{col filter tra}}
        }
	
	difference{
        	union{
	                box{ <-1.05, 0.015,-0.27> <-0.75, 0.605, 0.27> }
	                box{ < 1.05, 0.015,-0.27> < 0.75, 0.605, 0.27> }
	        }
	        box{ <-1.03, 0.0, -0.25> < 1.03, 0.62, 0.25>}
	        texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}
	}
	box{ <-1.03, 0.01, -0.25> < 1.03, 0.61, 0.25> texture{ pigment{ White }}}
 
        box{<-0.65, 0.02,-0.251> < 0, 0.60,-0.25> texture{ pigment{ color rgb< 0, 0.5, 0> }}}
}
#end
#macro DIODE_LED_SMD_SIDE(col,tra,height)
DIODE_LED_SMD_SIDE_GRND(col,tra,height)
#end


/********************************************************************************************************************************************
//  Base macro for AC/DC converter.
//  Designed by Thomas Wirtgen.
//  Revision History:
//    - 29.10.2006   V1.0   Thomas Wirtgen
//  Macro Arguments:
//    - value1 : text (value from Eagle)
//    - value2 : second text line
//    - outer1 : outer dimensions x,y,z - left,bottom,back
//    - outer2 : outer dimensions x,y,z - right,top,front
//    - rad    : radius of rounded edges
//    - tri    : triangle length in x- and y-direction, can also be 0
//    - t1x    : x-coodinate of terminal 1 ("+")
//    - t2x    : x-coodinate of terminal 2 ("~1")
//    - t3x    : x-coodinate of terminal 3 ("~2")
//    - t4x    : x-coodinate of terminal 4 ("-")
//
//GBU4:0:1:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:DIODE_REC_GBU4(:Gleichrichter:AC/DC-Converter
// geht nicht, da pins immer auf der Z-Mitte liegen muessen
********************************************************************************************************************************************/
#macro DIODE_REC_FB100_GRND(value1, value2, outer1, outer2, rad, tri, t1x, t2x, t3x, t4x)
#local inner1 = outer1 + <rad, rad, rad>;
  #local inner2 = outer2 - <rad, rad, rad>;
  #local outer_size = outer2 - outer1;
  #local outer_center = (outer1 + outer2) / 2;
  #local epsilon = 0.001;

  // terminals
  union {
    cylinder { <0, 0, 0> <0, outer_center.y, 0> 0.24*2
      texture { pigment { color Silver } }
      translate <t1x, 0, 0>
    }
    cylinder { <0, 0, 0> <0, outer_center.y, 0> 0.24*2
      texture { pigment { color Silver } }
      translate <t2x, 0, 0>
    }
    cylinder { <0, 0, 0> <0, outer_center.y, 0> 0.24*2
      texture { pigment { color Silver } }
      translate <t3x, 0, 0>
    }
    cylinder { <0, 0, 0> <0, outer_center.y, 0> 0.24*2
      texture { pigment { color Silver } }
      translate <t4x, 0, 0>
    }

  #if (global_fast_mode)

    // simple box
    box { outer1 outer2
//    pigment { color rgbt <0.8, 0.6, 0.6, 0.45>/*Red*/ }
      pigment { color rgb 0.30 }   // pretty dark
//    translate <0.12, 13.9, 0>
//    rotate <0, -90, 0>
    }

  #else // if (global_fast_mode)

    #macro frame(z1, tri, rad)
      merge {
        cylinder { <inner1.x    , outer1.y    , z1> <inner1.x    , inner2.y    , z1> rad }   // l--: left

       #if (tri)   // if we have a triangle
        cylinder { <inner2.x    , outer1.y    , z1> <inner2.x    , inner2.y-tri, z1> rad }   // r--: rght
        cylinder { <inner1.x    , inner2.y    , z1> <inner2.x-tri, inner2.y    , z1> rad }   // -t-: top

        cylinder { <inner2.x-tri, inner2.y    , z1> <inner2.x    , inner2.y-tri, z1> rad }   // diagonal
        sphere   { <inner2.x-tri, inner2.y    , z1> rad }                                    // rght top
        sphere   { <inner2.x    , inner2.y-tri, z1> rad }                                    // rght top
       #else   // no triangle
        cylinder { <inner2.x    , outer1.y    , z1> <inner2.x    , inner2.y    , z1> rad }   // r-b: rght back
        cylinder { <inner1.x    , inner2.y    , z1> <inner2.x    , inner2.y    , z1> rad }   // -tb: top back
        sphere   { <inner2.x    , inner2.y    , z1> rad }                                    // rght top
       #end

        sphere   { <inner1.x    , inner2.y    , z1> rad }                                    // left top
      }
    #end

    object {
      difference {
        merge {
#if (1)
          frame(inner1.z, tri, rad)   //  back-frame made of cylinders and spheres, rough shape is similar to a small "n"
          frame(inner2.z, tri, rad)   // front-frame made of cylinders and spheres, rough shape is similar to a small "n"
#end

#if (1)
         // solid prism (without rounded edges)
         #if (tri)   // if we have to cut out a triangle on one side
          cylinder { <inner1.x    , inner2.y    , inner1.z> <inner1.x    , inner2.y    , inner2.z> rad }   // lt-: top left
          cylinder { <inner2.x-tri, inner2.y    , inner1.z> <inner2.x-tri, inner2.y    , inner2.z> rad }   // rt-: top rght
          cylinder { <inner2.x    , inner2.y-tri, inner1.z> <inner2.x    , inner2.y-tri, inner2.z> rad }   // rt-: top rght
          #local dx1 = rad/sqrt(2);
          #local dy1 = dx1;
          prism {
            linear_sweep linear_spline
            inner1.z, inner2.z, 8+1
            <outer1.x        , outer1.y>
            <outer1.x        , inner2.y>
            <inner1.x        , outer2.y>
            <inner2.x-tri    , outer2.y>
            <inner2.x-tri+dx1, inner2.y+dy1>
            <inner2.x    +dx1, inner2.y-tri+dy1>
            <outer2.x        , inner2.y-tri>
            <outer2.x        , outer1.y>
            <outer1.x        , outer1.y>   // closing the prism
            rotate <-90, 0, 0>
          }
          prism {
            linear_sweep linear_spline
            outer1.z, outer2.z, 5+1
            <inner1.x    , outer1.y>
            <inner1.x    , inner2.y>
            <inner2.x-tri, inner2.y>
            <inner2.x    , inner2.y-tri>
            <inner2.x    , outer1.y>
            <inner1.x    , outer1.y>   // closing the prism
            rotate <-90, 0, 0>
          }
         #else   // otherwise the object is just a rouded box
          cylinder { <inner1.x, inner2.y, inner1.z> <inner1.x, inner2.y, inner2.z> rad }   // lt-: top left
          cylinder { <inner2.x, inner2.y, inner1.z> <inner2.x, inner2.y, inner2.z> rad }   // rt-: top rght
          box      { <inner1.x, outer1.y, inner1.z> <inner2.x, outer2.y, inner2.z> }
          box      { <inner1.x, outer1.y, outer1.z> <inner2.x, inner2.y, outer2.z> }
          box      { <outer1.x, outer1.y, inner1.z> <outer2.x, inner2.y, inner2.z> }
         #end
#end

#if (0)
        merge {
          cylinder { <outer1.x+3*rad, + outer1.y,     outer1.z-epsilon> <outer1.x+3*rad, + outer1.y,     outer2.z+epsilon> rad }
          cylinder { <outer2.x-3*rad, + outer1.y,     outer1.z-epsilon> <outer2.x-3*rad, + outer1.y,     outer2.z+epsilon> rad }
          box      { <outer1.x+3*rad, + outer1.y-rad, outer1.z-epsilon> <outer2.x-3*rad, + outer1.y+rad, outer2.z+epsilon> }
        }
#end
        } // end merge
        // bottom cut-out
#if (1)
        merge {
          cylinder { <outer1.x+3*rad, + outer1.y,     outer1.z-epsilon> <outer1.x+3*rad, + outer1.y,     outer2.z+epsilon> rad }
          cylinder { <outer2.x-3*rad, + outer1.y,     outer1.z-epsilon> <outer2.x-3*rad, + outer1.y,     outer2.z+epsilon> rad }
          box      { <outer1.x+3*rad, + outer1.y-rad, outer1.z-epsilon> <outer2.x-3*rad, + outer1.y+rad, outer2.z+epsilon> }
        }
#end
        cutaway_textures
      } // end difference
      #if (0)
        // just for testing, reddish surface with light-transmitting effect
        pigment { color rgbt <0.8, 0.6, 0.6, 0.45> }
      #else
        // real texture
        texture {
          pigment { color rgb /*<0.8, 0.2, 0.1>*/0.30 }   // pretty dark
          normal { bumps 0.2 scale 0.15 }   // { bumps 0.2 scale 0.3 }
          finish { ambient 0.1 diffuse 0.6 brilliance 1.0  ambient (0.1 * global_ambient_mul)}
        }
      #end
    } // end object

//  #local large_font_size = outer_size.x / 36 * 4;
//  #local small_font_size = outer_size.x / 36 * 3;

    #local large_font_size = 2 + outer_size.x / 36 * 2;
    #local small_font_size = 2 + outer_size.x / 36 * 1;

    #local large_font_line = large_font_size * 5/4;
    #local small_font_line = small_font_size * 4/3;

    #if (0)
      // this generates text on top of the part, not used here
      text {
        ttf besch_font value1 0.1, 0
        pigment { color rgb 0.95 }   // not quite white
        scale <large_font_size, large_font_size, 1>
        rotate <90, 0, 0>
        translate <0, outer2.y+epsilon, -1.5>
      }
    #end
    #if (1)
      #local t0x = inner1.x + rad * 1.5;
      #local t1y = outer2.y - rad * 1.0 - small_font_size * 1.25;
      #local t3y = outer1.y + rad * 1.0 + large_font_size * 0.25;
      #local t2y = (t1y+t3y) / 2;
      // this generates text on the side of the part
      union {
        text { ttf besch_font value1 0.1, 0 scale <small_font_size, small_font_size, 1> translate <t0x, t1y, outer1.z-epsilon> }
        text { ttf besch_font value2 0.1, 0 scale <small_font_size, small_font_size, 1> translate <t0x, t2y, outer1.z-epsilon> }
        text { ttf besch_font "+"    0.1, 0 scale <large_font_size, large_font_size, 1> translate <t1x, t3y, outer1.z-epsilon> }
        text { ttf besch_font "~"    0.1, 0 scale <large_font_size, large_font_size, 1> translate <t2x, t3y, outer1.z-epsilon> }
        text { ttf besch_font "~"    0.1, 0 scale <large_font_size, large_font_size, 1> translate <t3x, t3y, outer1.z-epsilon> }
        text { ttf besch_font "-"    0.1, 0 scale <large_font_size, large_font_size, 1> translate <t4x, t3y, outer1.z-epsilon> }
        pigment { color rgb 0.95 }   // not quite white
      } // end union
    #end

  #end // if (global_fast_mode)

//  translate <0, 0, 0>
//  rotate <0, 0, 0>
  } // end union
#end

#macro DIODE_REC_FB100(value)
DIODE_REC_FB100_GRND(value, "B40 C 5000/3300", <-6, +3, -3>, <+30, +20, +3>,   1, 5,   00.0000, 10.0076, 17.3656, 24.9836) 
#end
#macro DIODE_REC_2KBP(value)
DIODE_REC_FB100_GRND(value, "2KBP",     <-9.5, +3, -3.5>, <+9.5, +15, +3.5>,   1, 4,   05.7150, 01.9050, -1.9050, -5.7150) 
#end
#macro DIODE_REC_2KBB_R(value) 
DIODE_REC_FB100_GRND(value, "2KBB-R",   <-9.5, +3, -3.5>, <+9.5, +15, +3.5>,   1, 3,   -7.6200, -2.5600,  2.5600,  7.6200) 
#end
#macro DIODE_REC_2KBB(value) 
DIODE_REC_FB100_GRND(value, "2KBB",     <-9.5, +3, -3.5>, <+9.5, +15, +3.5>,   1, 3,   -2.5600, -7.6200,  2.5600,  7.6200) 
#end
#macro DIODE_REC_GBU4(value) 
DIODE_REC_FB100_GRND(value, "GBU4",     <-11.5, +3, -4.4>, <+11.5, +17, +2.6>, 1, 5,    7.6200, -2.5600,  2.5600, -7.6200) 
#end
#macro DIODE_REC_SKBB(value) 
DIODE_REC_FB100_GRND(value, "SKBB",     <-9.5, +3, -2.5>, <+9.5, +15, +2.5>,   1, 3.5, -2.5600,  2.5600, -7.6200,  7.6200) 
#end
#macro DIODE_REC_FB15A(value) 
DIODE_REC_FB100_GRND(value, "FB15A",    <-11.7, +3, -2.5>, <+9.4, +15, +2.5>,  1, 3.5, -7.6200,  2.5600, -2.5600,  7.6200) 
#end
#macro DIODE_REC_FB15(value) 
DIODE_REC_FB100_GRND(value, "FB15",     <-10, +3, -2.5>, <+10, +15, +2.5>,     1, 3.5, -7.6200,  2.5600, -2.5600,  7.6200) 
#end
#macro DIODE_REC_FB32(value) 
DIODE_REC_FB100_GRND(value, "FB32",     <-16, +3, -3>, <+16, +20, +3>,         1, 5,   -13.600, -3.5600,  3.2000, 11.4500) 
#end


/********************************************************************************************************************************************
//Macros for rectifier bridge KBU8A from General Semiconductor
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.0 30/12/05
********************************************************************************************************************************************/
#macro DIODE_REC_KBU_GRND(value)
union{
    difference{
        union{
            box{<-11,0,-3.19><11,+19.3,+3.81>} // case
        }
        union{
            box{<-0,-5,-4><+5,+5,+6> rotate -60*z translate<-15,+22,0> }  // left corner
            box{<-0,-5,-4><+5,+5,+6> rotate 45*z translate<+9,+17.3,0> }  // right corner
            intersection{
                cylinder{<0,10,-5><0,10,+5> 2.5}
                box{<-2,5,-5><+2,15,+5>} 
            }
            box{<-8.9,-.1,-5><8.9,+1.5,+5>} // base
            box{<-0,-5,-4><+5,+5,+6> rotate -30*z translate<-11.5,-2.8,0> }  
            box{<-0,-5,-4><+5,+5,+6> rotate -30*z translate<-11.5,-2.8,0> rotate 180*y }  
        }
        pigment{Gray25}
    }
    //pins
    cylinder{<-7.5,2,2.54><-7.5,-min(25,(pin_length+pcb_height)),2.54> .5 texture { pigment{P_Silver2} } }        
    cylinder{<-2.5,2,2.54><-2.5,-min(25,(pin_length+pcb_height)),2.54> .5 texture { pigment{P_Silver2} } }        
    cylinder{<+2.5,2,2.54><+2.5,-min(25,(pin_length+pcb_height)),2.54> .5 texture { pigment{P_Silver2} } }        
    cylinder{<+7.5,2,2.54><+7.5,-min(30,(pin_length+pcb_height)),2.54> .5 texture { pigment{P_Silver2} } } 
    // Marking
    text {ttf global_fontfile_eagle3d "1" -0.05, 0 pigment{White} scale 5  translate<3,4,-2.95>}  // Marking
    text {ttf global_fontfile_arial "+" -0.05, 0 pigment{White} scale 2  translate<7,2,-3.1>}  // Marking
    text {ttf global_fontfile_arial "~" -0.05, 0 pigment{White} scale 2  translate<7-5,2,-3.1>}  // Marking
    text {ttf global_fontfile_arial "~" -0.05, 0 pigment{White} scale 2  translate<7-10,2,-3.1>}  // Marking
    text {ttf global_fontfile_arial "-" -0.05, 0 pigment{White} scale 2  translate<7-15,2,-3.1>}  // Marking
    text {ttf global_fontfile_arial_bold value -0.05, 0 pigment{White} scale 2.5 translate<7-12,15,-3.1>}  // Marking
  
    //rotate 90*y     
}
#end
#macro DIODE_REC_KBU_4_6_8(value)
DIODE_REC_KBU_GRND(value)
#end


/********************************************************************************************************************************************
//Macro für Brückengleichrichter RUND
//franz.riedmueller@web.de
********************************************************************************************************************************************/
#macro DIODE_REC_RB1A_GRND(value)
union {
 difference { 
  union {
   cylinder {<0, 0, 0>,
             <0, 4.8, 0>,  4.8
             finish { ambient (0.15 * global_ambient_mul) diffuse 0.85 phong 1.0 phong_size 40}
   }
   cone {<0,4.8,0>, 4.8,
         <0,5.0,0>, 4.8
         finish { ambient (0.15 * global_ambient_mul) diffuse 0.85 phong 1.0 phong_size 40}
   }
  }
  box {<-4.1, -0.1, 4.0>
       < -20, 5.1,  -3.8>
       finish { ambient (0.15 * global_ambient_mul) diffuse 0.85 reflection 0.05 phong 1.0 phong_size 40}
  }
 }
 cylinder {<-2.55, 0, 2.55>
           <-2.55, -8, 2.55>, 0.3
           texture{col_silver}
 }
 cylinder {<2.55, 0, 2.55>
           <2.55, -8, 2.55>, 0.3
           texture{col_silver}
 }
 cylinder {<2.55, 0, -2.55>
           <2.55, -8, -2.55>, 0.3
           texture{col_silver}
 }
 cylinder {<-2.55, 0, -2.55>
           <-2.55, -8, -2.55>, 0.3
           texture{col_silver}
 }
 text {ttf besch_font "+        ~", 0.2, 0
       pigment{Gray30}
       rotate<90,0,0>
       translate<-2.5,5.01,2.5>
 }
 text {ttf besch_font "~        -", 0.2, 0  
       pigment{Gray30}
       rotate<90,0,0>
       translate<-2.5,5.01,-3>
 }
 text {ttf besch_font value, 0.2, 0  
       pigment{Gray30}
       rotate<90,0,0>
       translate<-2.5,5.01,0>
 }
 translate<0,5,0>
}
#end


#macro DIODE_REC_RB1A(value)
DIODE_REC_RB1A_GRND(value)
#end


/********************************************************************************************************************************************
// Tilmann Reh <tilmann.reh@autometer.de>
// SMD-Diodengehäuse DO214, drei Varianten: -AA (SMB), -AB (SMC), -AC (SMA).
// Parameter: Länge, Breite, Höhe des Kunststoffkörpers, Länge incl. Pins, Breite der Anschlüsse.
********************************************************************************************************************************************/
#macro DIODE_SMD_DO214_GRND(L,B,H,LG,BP,DP)
#macro SD_DO214_PIN(H,LP,BP,DP,R)
union{
	difference{
		cylinder{<0,-BP/2,0><0,BP/2,0> R+DP/2}
		cylinder{<0,-BP,0><0,BP,0> R-DP/2}
		box{<-R-DP,-BP,-R-DP><0,BP,R+DP>}
		box{<-R-DP,-BP,-R-DP><R+DP,BP,0>}
		rotate<0,0,90> 
		translate<0,H-R,-R> 
	}
	difference{
		cylinder{<0,-BP/2,0><0,BP/2,0> R+DP/2}
		cylinder{<0,-BP,0><0,BP,0> R-DP/2}
		box{<-R-DP,-BP,-R-DP><0,BP,R+DP>}
		box{<-R-DP,-BP,-R-DP><R+DP,BP,0>}
		rotate<0,0,90> 
		rotate<90,0,0> 
		translate<0,R+DP/2,-R> 
	}
	box{<-BP/2,R+DP/2,-DP/2><BP/2,H-R,DP/2>}
	box{<-BP/2,0,-LP><BP/2,DP,-R>}
	box{<-BP/2,H-DP/2,-LP><BP/2,H+DP/2,-R>}
	texture{col_silver}
}
#end
union{
difference{
box{<-L/2,0.2,-B/2><L/2,H,B/2>}
box{<0,0,-B><H,H,B> rotate<0,0,10> translate<L/2,H/2+DP/2,0>}
box{<0,0,-B><-H,H,B> rotate<0,0,-10> translate<-L/2,H/2+DP/2,0>}
box{<0,0,-B><H,-H,B> rotate<0,0,-10> translate<L/2,H/2-DP/2,0>}
box{<0,0,-B><-H,-H,B> rotate<0,0,10> translate<-L/2,H/2-DP/2,0>}
box{<-L,0,0><L,H,H> rotate<-10,0,0> translate<0,H/2+DP/2,B/2>}
box{<-L,0,0><L,H,-H> rotate<10,0,0> translate<0,H/2+DP/2,-B/2>}
box{<-L,0,0><L,-H,H> rotate<10,0,0> translate<0,H/2-DP/2,B/2>}
box{<-L,0,0><L,-H,-H> rotate<-10,0,0> translate<0,H/2-DP/2,-B/2>}
box{<0,0,-B><1.2,1.5*DP,B> translate<-L/2,0,0>}
box{<0,0,-B><-1.2,1.5*DP,B> translate<L/2,0,0>}}
box{<-L/2+L/10,H,-B/2+B/10><-L/2+L/10+L/10,H+0.01,B/2-B/10> pigment{White}}
object{SD_DO214_PIN (H/2,1.14,BP,DP,0.2) rotate<0,90,0> translate<LG/2-DP/2,0,0>}
object{SD_DO214_PIN (H/2,1.14,BP,DP,0.2) rotate<0,-90,0> translate<-LG/2+DP/2,0,0>}
pigment{Gray20}}
#end

#macro DIODE_SMD_DO214AC()
DIODE_SMD_DO214_GRND(4.25,2.65,2.15,5.1,1.45,0.22)
#end
#macro DIODE_SMD_DO214AA()
DIODE_SMD_DO214_GRND(4.27,3.62,2.29,5.4,2.08,0.22)
#end
#macro DIODE_SMD_DO214AB()
DIODE_SMD_DO214_GRND(6.85,5.91,2.34,7.94,3.05,0.22)
#end
#macro DIODE_SMD_SMA()
DIODE_SMD_DO214_GRND(4.25,2.65,2.15,5.1,1.45,0.22)
#end
#macro DIODE_SMD_SMB()
DIODE_SMD_DO214_GRND(4.27,3.62,2.29,5.4,2.08,0.22)
#end
#macro DIODE_SMD_SMC()
DIODE_SMD_DO214_GRND(6.85,5.91,2.34,7.94,3.05,0.22)
#end


/********************************************************************************************************************************************
//LED 0805
********************************************************************************************************************************************/
#macro DIODE_SMD_LED_CHIP_GRND(s,col,tra)
union{
//The light emitting part of the led
box{
    <0.1,0,0.1> <1.9,0.60,1.15> 
    translate<0,0.05,0>
    texture{
        pigment{col filter tra} 
        #if(global_use_radiosity = on)
            finish{ambient (1.0 * global_ambient_mul_emit)}
        #else
            finish{ambient (0.7 * global_ambient_mul)}
        #end
        
    }
}

box{<0,0.0,0><0.6,0.3,1.25> }                                        //Metall links
box{<0,0.0,0><0.6,0.3,1.25> translate<2.0-0.6,0,0>}                 //Metall rechts
box{<0.4,0.3,0.5><0.6,0.5,0.75>}
box{<1.4,0.3,0.5><1.6,0.5,0.75>}
box{<0.85,0.3,0.475><1.15,0.4,0.775> pigment{col} finish{ ambient (1 * global_ambient_mul)}}
lathe{linear_spline 4, <0, 0>, <0.4, 0.4>, <0.5,0.4>,<0.05,0>
translate<1,0.1,0.625>}
texture{col_silver} 
translate<-1,0,-0.625>
scale s
}
#end
#macro DIODE_SMD_LED_CHIP_1206(col,tra,height)
DIODE_SMD_LED_CHIP_GRND(<1.5,1.5,1.2>,col,tra)
#end
#macro DIODE_SMD_LED_CHIP_0805(col,tra,height)
DIODE_SMD_LED_CHIP_GRND(<1.0,1.0,1.0>,col,tra)
#end
#macro DIODE_SMD_LED_CHIP_0603(col,tra,height)
DIODE_SMD_LED_CHIP_GRND(<0.75,0.6,0.6>,col,tra)
#end


/********************************************************************************************************************************************
//LED PLCC2
********************************************************************************************************************************************/
#macro DIODE_SMD_LED_PLCC2_GRND(typeOfCase)
union{

	//default to PLCC2
	#local L = 3.7;
	#local W = 3.0;
	#local H = 2.0;
	#local LT = 3.3;
	#local WT = 2.6;
	#local HT = 1.6;
	#local P = 2;
	
	#if(strcmp(typeOfCase,"PLCC2")=0.0)

		#local L = 3.7;
		#local W = 3.0;
		#local H = 2.0;
		#local LT = 3.3;
		#local WT = 2.6;
		#local HT = 1.6;
		#local P = 2;
		
	#end

	#if(strcmp(typeOfCase,"MiniTopled")=0.0)

		#local L = 2.3;
		#local W = 1.5;
		#local H = 1.4;
		#local LT = 2.1;
		#local WT = 1.3;
		#local HT = 1.2;
		#local P = 2;
		
	#end
		
	difference{
		
		object{Round_Box(<0,0,0>, <LT,H,W>, 0.1, no) translate<-LT/2,(L-LT)/2,-W/2>}
		cylinder{<0,H+(L-LT)/2-0.4,0> <0,H+(L-LT)/2+0.1,0>W/3.5}
		cone{ <0,H+(L-LT)/2-0.4,0> W/2.9 <0,H+(L-LT)/2+0.1,0>W/2.2}
	        pigment{White}
	}
	
	box{<-0.2,H+(L-LT)/2-0.4,-0.2><0.2,H+(L-LT)/2-0.3,0.2> pigment{Gray80}}
	
	//rechter Anschluss
	difference{
		box{<0,0,0><-P,HT,WT>}
		box{<0,(L-LT)/2,-0.002><-P-0.002,HT-(L-LT)/2,WT+0.002> translate<-(L-LT)/2,0,0>}
		cylinder{<0,HT,-0.002><0,HT,WT+0.002>(L-LT)/2}
		cylinder{<0,0,-0.002><0,0,WT+0.002>(L-LT)/2}
		texture{col_silver} 
		translate<LT/2+(L-LT)/2+0.02,0,-WT/2>
	}
	//rechter Anschlus
	difference{
		cylinder{<-(L-LT)/2,HT-(L-LT)/2,><-(L-LT)/2,HT-(L-LT)/2,WT>(L-LT)/2}
		cylinder{<-3*(L-LT)/4,HT-3*(L-LT)/4,-0.04><-3*(L-LT)/4,HT-3*(L-LT)/4,WT+0.002>(L-LT)/4}
		box{<-(L-LT)/2,HT-3*(L-LT)/4,-0.04><-(L-LT),HT-5,WT+0.002>}
		box{<-3*(L-LT)/4,HT-(L-LT)/2,-0.04><-(L-LT),HT-5,WT+0.002>}
		texture{col_silver}
		translate<LT/2+(L-LT)/2+0.02,0,-WT/2>
	}
	//rechter Anschlus
	difference{
		cylinder{<-(L-LT)/2,(L-LT)/2,0><-(L-LT)/2,(L-LT)/2,WT>(L-LT)/2}
		cylinder{<-3*(L-LT)/4,3*(L-LT)/4,-0.04><-3*(L-LT)/4,3*(L-LT)/4,WT+0.002>(L-LT)/4}
		box{<(-L-LT)/2,3*(L-LT)/4,-0.04><-(L-LT),5,WT+0.002>}
		box{<0,0,-0.04><(L-LT)/2,(L-LT)/2,WT+0.002> translate<-(L-LT),0.75*(L-LT),0>}
		box{<(L-LT)/2,(L-LT)/2,-0.04><(L-LT),L-LT,WT+0.002> translate<-1.75*(L-LT),0,0>}
		texture{col_silver}
		translate<LT/2+(L-LT)/2+0.02,0,-WT/2>
	}
	//linker (positiver) Anschlus
	difference{
		box{<0,0,0><P,HT,WT>}
		box{<(L-LT)/2,(L-LT)/2,-0.002><P+0.002,HT-(L-LT)/2,WT+0.002>}
		cylinder{<0,HT,-0.002><0,HT,WT+0.002>(L-LT)/2}
		cylinder{<0,0,-0.002><0,0,WT+0.002>(L-LT)/2}
		box{<-0.002,HT/2,0><P+0.002,HT+0.002,WT*0.3> translate<0,0,WT*0.35>}
		texture{col_silver}
		translate<-L/2-0.02,0,-WT/2>
	}
	//linker (positiver) Anschlus
	difference{
		cylinder{<(L-LT)/2,HT-(L-LT)/2,-0.002><(L-LT)/2,HT-(L-LT)/2,WT+0.002>(L-LT)/2}
		cylinder{<3*(L-LT)/4,HT-3*(L-LT)/4,-0.04><3*(L-LT)/4,HT-3*(L-LT)/4,WT+0.002>(L-LT)/4}
		box{<(L-LT)/2,HT-3*(L-LT)/4,-0.04><L-LT,HT-5,WT+0.002>}
		box{<3*(L-LT)/4,HT-(L-LT)/2,-0.04><L-LT,HT-5,WT+0.002>}
		box{<-0.002,HT/2,0><P+0.002,HT+0.002,WT*0.3> translate<0,0,WT*0.35>}
		texture{col_silver}
		translate<-L/2-0.02,0,-WT/2>
	}
	//linker (positiver) Anschlus
	difference{
		cylinder{<(L-LT)/2,(L-LT)/2,-0.002><(L-LT)/2,(L-LT)/2,WT+0.002>(L-LT)/2}
		cylinder{<3*(L-LT)/4,3*(L-LT)/4,-0.04><3*(L-LT)/4,HT-3*(L-LT)/4,WT+0.002>(L-LT)/4}
		box{<(L-LT)/2,3*(L-LT)/4,-0.04><L-LT,5,WT+0.002>}
		box{<3*(L-LT)/4,(L-LT)/2,-0.04><L-LT,L-LT,WT+0.002>}
		texture{col_silver} 
		translate<-L/2-0.02,0,-WT/2>
	}
}
#end   
#macro DIODE_SMD_LED_PLCC2()
DIODE_SMD_LED_PLCC2_GRND("PLCC2")
#end
#macro DIODE_SMD_LED_MINITOPLED()
DIODE_SMD_LED_PLCC2_GRND("MiniTopled")
#end


/********************************************************************************************************************************************
//MELF
********************************************************************************************************************************************/
#macro DIODE_SMD_MELF_GRND(value)
union{                                                                                                               
cylinder{<1.7,0,0><-1.6,0,0>1.25}                                                                                    
torus{1.05,0.2 rotate<90,90,0> translate<1.7,0,0>}                                                                   
torus{1.05,0.2 rotate<90,90,0> translate<-1.6,0,0>}                                                                  
cylinder{<2,0,0><-2,0,0>1.05}                                                                                        
cylinder{<2,0,0><2.5,0,0>1.25 texture{col_silver} finish{F_MetalC ambient (0.1 * global_ambient_mul)}}                                                  
cylinder{<-2,0,0><-2.5,0,0>1.25 texture{col_silver} finish{F_MetalC ambient (0.1 * global_ambient_mul)}}                                                
cylinder{<-1.4,0,0><-0.6,0,0>1.2501 pigment{Gray20} finish{F_MetalB ambient (0.1 * global_ambient_mul)}}                                                
intersection{                                                                                                        
  cylinder{<1.8,0,0><-1.6,0,0>1.2502 pigment{White}}                                                                 
    union{                                                                                                           
    text {ttf besch_font value 0.5, 0 scale<0.5,0.5,0.5> translate<-0.9,-0.2,-1.2501> rotate<0,0,0> pigment{White}}  
    text {ttf besch_font value 0.5, 0 scale<0.5,0.5,0.5> translate<-0.9,-0.2,-1.2501> rotate<90,0,0> pigment{White}} 
    text {ttf besch_font value 0.5, 0 scale<0.5,0.5,0.5> translate<-0.9,-0.2,-1.2501> rotate<180,0,0> pigment{White}}
    }                                                                                                                
  }                                                                                                                  
pigment{P_Copper4} finish{F_MetalC ambient (0.1 * global_ambient_mul)}                                                                                  
translate<0,1.25,0>                                                                                                  
}                                                                                                                    
#end                                                                                                                 
#macro DIODE_SMD_MELF(value)
DIODE_SMD_MELF_GRND(value)
#end


/********************************************************************************************************************************************
//neu von Walter Mücke                                                                                             
********************************************************************************************************************************************/
#macro DIODE_SMD_MINIMELF_GRND(value, s)
union{                                                                                                             
/*cylinder{<1,0,0><-0.9,0,0>0.8}                                                                                   
torus{0.6,0.2 rotate<90,90,0> translate<1,0,0>}                                                                    
torus{0.6,0.2 rotate<90,90,0> translate<-0.9,0,0>}                                                                 
cylinder{<1.2,0,0><1.7,0,0>0.8 COL_SILVER()}                                                                       
cylinder{<-1.25,0,0><-1.7,0,0>0.8 COL_SILVER()}*/                                                                  
object{Round_Cylinder_Union(<-1.1,0,0><1.2,0,0>0.8,0.2)}                                                           
cylinder{<-1.6,0,0><1.6,0,0>0.32 texture{col_silver}}                                                              
object{Round_Cylinder_Union(<1.25,0,0><1.7,0,0>0.8,0.2) texture{col_silver}}                                       
object{Round_Cylinder_Union(<-1.7,0,0><-1.25,0,0>0.8,0.2) texture{col_silver}}                                     
cylinder{<-0.95,0,0><-.350,0,0>0.8001 pigment{Gray20} finish{F_MetalC ambient (0.1 * global_ambient_mul)}}    //Markierung                            
intersection{                                                                                                      
  cylinder{<1.8,0,0><-1.6,0,0>0.8002 pigment{White}}                                                               
  union{                                                                                                           
    text {ttf besch_font value 0.5, 0 scale<0.3,0.3,0.3> translate<-0.45,-0.2,-0.9> rotate<0,0,0> pigment{White}}  
    text {ttf besch_font value 0.5, 0 scale<0.3,0.3,0.3> translate<-0.45,-0.2,-0.9> rotate<90,0,0> pigment{White}} 
    text {ttf besch_font value 0.5, 0 scale<0.3,0.3,0.5> translate<-0.45,-0.2,-0.9> rotate<180,0,0> pigment{White}}
    }                                                                                                              
  }                                                                                                                
pigment{P_Copper4} finish{F_MetalC ambient (0.1 * global_ambient_mul)}                                                                                
translate<0,0.8,0>                                                                                               
scale s
}                                                                                                                  
#end                                                                                                               
#macro DIODE_SMD_MINIMELF(value)
DIODE_SMD_MINIMELF_GRND(value, <1.0,1.0,1.0>)
#end
#macro DIODE_SMD_MICROMELF(value)
DIODE_SMD_MINIMELF_GRND(value, <0.52,0.7,0.7>)
#end


/********************************************************************************************************************************************
// Joerg Bredendiek
// SMD-Diodengehäuse SOD123/323/523
// Parameter: Länge, Breite, Höhe des Kunststoffkörpers, Länge incl. Pins, Breite der Anschlüsse.Pindicke
********************************************************************************************************************************************/
#macro DIODE_SMD_SOD123_GRND(L,B,H,LG,BP,DP)
union{
	difference{
		box{<-L/2,0.2,-B/2><L/2,H,B/2>}
		box{<0,0,-B><H,H,B> rotate<0,0,10> translate<L/2,H/2+DP/2,0>}
		box{<0,0,-B><-H,H,B> rotate<0,0,-10> translate<-L/2,H/2+DP/2,0>}
		box{<0,0,-B><H,-H,B> rotate<0,0,-10> translate<L/2,H/2-DP/2,0>}
		box{<0,0,-B><-H,-H,B> rotate<0,0,10> translate<-L/2,H/2-DP/2,0>}
		box{<-L,0,0><L,H,H> rotate<-10,0,0> translate<0,H/2+DP/2,B/2>}
		box{<-L,0,0><L,H,-H> rotate<10,0,0> translate<0,H/2+DP/2,-B/2>}
		box{<-L,0,0><L,-H,H> rotate<10,0,0> translate<0,H/2-DP/2,B/2>}
		box{<-L,0,0><L,-H,-H> rotate<-10,0,0> translate<0,H/2-DP/2,-B/2>}
		box{<0,0,-B><1.2,1.5*DP,B> translate<-L/2,0,0>}
		box{<0,0,-B><-1.2,1.5*DP,B> translate<L/2,0,0>}}

	box{<-L/2+L/10,H,-B/2+B/10><-L/2+L/10+L/10,H+0.01,B/2-B/10> pigment{White}}

	box{<-1, 0, -BP/2><1, DP, BP/2> translate<-(LG/2-1), 0, 0> texture{col_silver}}
	box{<-1, 0, -BP/2><1, DP, BP/2> translate< (LG/2-1), 0, 0> texture{col_silver}}

	pigment{Gray20}}
#end

#macro DIODE_SMD_SOD123_1()
DIODE_SMD_SOD123_GRND(2.6, 1.6, 1.1, 3.5, 0.65, 0.2)
#end
#macro DIODE_SMD_SOD123_3()
DIODE_SMD_SOD123_GRND(1.7, 1.25, 1, 2.5, 0.35, 0.2)
#end
#macro DIODE_SMD_SOD123_5()
DIODE_SMD_SOD123_GRND(1.6, 1.8, 0.6, 1.6, 0.3, 0.15)
#end


/********************************************************************************************************************************************
//SOD80
********************************************************************************************************************************************/
#macro DIODE_SMD_SOD80_GRND(value)
union{
cylinder{<-1.45,0,0><1.45,0,0>0.7}
cylinder{<-1.45,0,0><-1.75,0,0>0.8 texture{col_silver}}
cylinder{<1.45,0,0><1.75,0,0>0.8 texture{col_silver}}
cylinder{<1.1,0,0><0.8,0,0>0.701 pigment{Gray80}}
intersection{
cylinder{<0.7,0,0><-1.5,0,0>0.7001 pigment{White}}
union{
text {ttf besch_font value 0.4, 0 scale<0.4,0.4,0.4> translate<-1,-0.2,-0.75> rotate<0,0,0> pigment{White}}
text {ttf besch_font value 0.4, 0 scale<0.4,0.4,0.4> translate<-1,-0.2,-0.75> rotate<90,0,0> pigment{White}}
text {ttf besch_font value 0.4, 0 scale<0.4,0.4,0.4> translate<-1,-0.2,-0.75> rotate<180,0,0> pigment{White}}}}
rotate<0,180,0> translate<0,0.8,0> pigment{Gray30}}
#end
#macro DIODE_SMD_SOD80(value)
DIODE_SMD_SOD80_GRND(value)
#end


/********************************************************************************************************************************************
//SOD87
********************************************************************************************************************************************/
#macro DIODE_SMD_SOD87_GRND(value)
union{
cylinder{<-1.45,0,0><1.45,0,0>0.9}
cylinder{<-1.45,0,0><-1.75,0,0>1.025 texture{col_silver}}
cylinder{<1.45,0,0><1.75,0,0>1.025 texture{col_silver}}
cylinder{<1.1,0,0><0.8,0,0>0.901 pigment{Gray80}}
intersection{
cylinder{<0.7,0,0><-1.5,0,0>0.9001 pigment{White}}
union{
text {ttf besch_font value 0.4, 0 scale<0.4,0.4,0.4> translate<-1,-0.2,-0.95> rotate<0,0,0> pigment{White}}
text {ttf besch_font value 0.4, 0 scale<0.4,0.4,0.4> translate<-1,-0.2,-0.95> rotate<90,0,0> pigment{White}}
text {ttf besch_font value 0.4, 0 scale<0.4,0.4,0.4> translate<-1,-0.2,-0.95> rotate<180,0,0> pigment{White}}}}
rotate<0,180,0> translate<0,1.025,0> pigment{Gray30}}
#end
#macro DIODE_SMD_SOD87(value)
DIODE_SMD_SOD87_GRND(value)
#end


/********************************************************************************************************************************************
// Joerg Bredendiek <sprut(replace with at)sprut.de>   
//SOD64 Gehäuse liegend 
********************************************************************************************************************************************/
#macro DIODE_SOD64_GRND(value, L, BD, BL)
union{

	//Beschriftung
	intersection{                                                                                                      
		sphere{<0,0,0> BD/2+0.01 scale<BL/BD,1,1>  pigment{Gray30}}                                                               
		union{                                                                                                           
			text {ttf besch_font value 3, 0  translate<-BL/2+1.2,-0.4,-BD/2-0.5> rotate<90,0,0>} 
			pigment{Gray30}
		}  
   		translate<0, 2.5, 0>                                                                                                         
	}  
                  
        //ring
	intersection{                                                                                                      
		sphere{<0,0,0> BD/2+0.01 scale<BL/BD,1,1>  pigment{Gray30}}                                                               
		cylinder{<-BL/2+0.5, 0, 0><-BL/2+1, 0, 0> BD/2+0.05 pigment{Black} }
   		translate<0, 2.5, 0> 
        }
                          
        // koerper          
	union{
		cylinder{<-BL/2, 0, 0>< BL/2, 0, 0> 0.5 texture{col_silver} }  
		sphere{<0,0,0> BD/2 scale<BL/BD,1,1> pigment{LightBlue} finish { phong 0.5 }}
		translate<0, 2.5, 0>
	}

	// anschluesse
	union{
	        // pin unterteil
		#if  (pin_short=off)
			cylinder{<-L/2,0,0><-L/2,-12,0>0.3 }
			cylinder{< L/2,0,0>< L/2,-12,0>0.3 }
		#else
			cylinder{<-L/2,0,0><-L/2,-1*(pin_length+pcb_height),0>0.3 }
			cylinder{< L/2,0,0>< L/2,-1*(pin_length+pcb_height),0>0.3 }
		#end
	        //pin oberteil                 
	        #declare bends1=array[3] {<0, 2, 0>,  <90, 0.5, 0>,  <0,4,0> }  
	        object { TOOLS_BENTPIPE( 0.3, <0,0,0>, y, bends1 ) rotate<0,0,0> translate<-L/2,0,0>}               
	        object { TOOLS_BENTPIPE( 0.3, <0,0,0>, y, bends1 ) rotate<0,180,0> translate< L/2,0,0>}               
		texture{col_silver}
	}
}
#end

#macro DIODE_SOD64_1(value)
DIODE_SOD64_GRND(value, 10.16, 4.5, 5)
#end
#macro DIODE_SOD64_2(value)
DIODE_SOD64_GRND(value, 12.7, 4.5, 5)
#end
#macro DIODE_SOD57_3(value)
DIODE_SOD64_GRND(value, 10.16, 3.8, 6.1)          
#end
#macro DIODE_SOD61_A(value)
DIODE_SOD64_GRND(value, 10.16, 2.5, 5.5)   
#end
#macro DIODE_SOD61_B(value)
DIODE_SOD64_GRND(value, 15.24, 2.5, 8.7)
#end
#macro DIODE_SOD61_C(value)
DIODE_SOD64_GRND(value, 17.78, 2.5, 11.5)
#end
#macro DIODE_SOD61_D(value)
DIODE_SOD64_GRND(value, 15.24, 2.5, 9.9)
#end
#macro DIODE_SOD61_E(value)
DIODE_SOD64_GRND(value, 20.32, 2.5, 13.5)
#end


/********************************************************************************************************************************************
// Joerg Bredendiek <sprut(replace with at)sprut.de>   
//SOD81 Gehäuse liegend 
********************************************************************************************************************************************/
#macro DIODE_SOD81_GRND(value)
union{
	union{

		//Glaskoerper
		union{
			cylinder{<-1.9, 0, 0>< 1.9, 0, 0> 1.05-0.25 }
			cylinder{<-1.65,0, 0>< 1.65,0, 0> 1.05 }
			torus{0.8, 0.25 rotate<0,0,90> translate<-1.65, 0, 0>}
			torus{0.8, 0.25 rotate<0,0,90> translate< 1.65, 0, 0>}
			cone{<0,0,0>0.7 <-1,0,0> 0 translate<-1.8,0,0>}
			cone{<0,0,0>0.7 < 1,0,0> 0 translate< 1.8,0,0>}
			pigment{Col_Glass_General}
		}
		cylinder{<-1.5,0,0><-1.1,0,0> 1.06 pigment{Black} }    //Markierung

		//Beschriftung
		intersection{                                                                                                      
			cylinder{<1.8,0,0><-1.6,0,0>1.06 pigment{Col_Glass_General}}                                                               
			union{                                                                                                           
				text {ttf besch_font value 0.5, 0 scale<0.6,0.6,0.6> translate<-0.8,-0.4,-1.0> rotate<0,0,0> pigment{Black}}  
				text {ttf besch_font value 0.5, 0 scale<0.6,0.6,0.6> translate<-0.8,-0.4,-1.0> rotate<90,0,0> pigment{Black}} 
				text {ttf besch_font value 0.5, 0 scale<0.6,0.6,0.6> translate<-0.8,-0.4,-1.0> rotate<180,0,0> pigment{Black}}
			}                                                                                                              
		}  

		// innenleben
		cylinder{<-1.55, 0, 0>< -0.2, 0, 0> 0.9 pigment{color Red} } 
		cylinder{< 1.55, 0, 0><  0.2, 0, 0> 0.9 pigment{color Red} }
		cylinder{< 0.2,  0, 0>< -0.2, 0, 0> 0.1 texture{col_silver} }
		translate<0, 1.5, 0>
	}

	// anschluesse
	union{
	        // pin unterteil
		#if  (pin_short=off)
			cylinder{<-5.08,0,0><-5.08,-12,0>0.3 }
			cylinder{< 5.08,0,0>< 5.08,-12,0>0.3 }
		#else
			cylinder{<-5.08,0,0><-5.08,-1*(pin_length+pcb_height),0>0.3 }
			cylinder{< 5.08,0,0>< 5.08,-1*(pin_length+pcb_height),0>0.3 }
		#end
	        //pin oberteil                 
	        #declare bends1=array[3] {<0, 1, 0>,  <90, 0.5, 0>,  <0,3,0> }  
	        object { TOOLS_BENTPIPE( 0.3, <0,0,0>, y, bends1 ) rotate<0,0,0> translate<-5.08,0,0>}               
	        object { TOOLS_BENTPIPE( 0.3, <0,0,0>, y, bends1 ) rotate<0,180,0> translate< 5.08,0,0>}               
		texture{col_silver}
	}
}
#end

#macro DIODE_SOD81_1(value)
DIODE_SOD81_GRND(value)
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
