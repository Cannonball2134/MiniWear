//Eagle3D 20110101 INC-File e3d_trafo.inc
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
 
#ifndef(__trafo_inc)
#declare __trafo_inc = true;

#ifndef(inc_testmode)
#declare inc_testmode=true;
#include "e3d_tools.inc"
#undef inc_testmode
#end

/********************************************************************************************************************************************
// Printtransformator Grundmakro era-Trafos mit EI-Schnitt
// von Thomas Wiens <thomas.wiens at twiens.de> 5.11.2004 
// Parameter: value = Beschriftungsdruck, breite = Gesamtbreite des Gehäuses, tiefe = Gesamttiefe des Gehäuses, abs_oben = Abstand des kleinen Quaders von oben
//            abs_seite = Abstand des kleinen Quaders von der Seite, druck_hoehe = Höhe des Beschriftungsdrucks, druck_text = aufgedruckter Text,
//            anz_laschen = Anzahl der Befestigungslaschen, la_laenge = Länge der Lasche, la_breite = Breite der Lasche, la_hoehe = Höhe der Lasche, 
//            la_lochabstand = Lochabstand der Bohrungen in der Lasche, la_lochdurchm = Durchmesser der Laschenbohrungen,
//            trafo_pin_laenge = Länge der Pins, pinabstand = Abstand der Pins von Primä zu Sekundär, pin_aus = Pinabstand von Mittellinie nach äußerster Pin, 
//            pin_in = Pinabstand von Mittellinie zum inneren Pin, dia_schraube = Durchmesser der Schraube (M2.5, M3 oder M4)
********************************************************************************************************************************************/
#macro TRAFO_ERA_EI_GRND(value, breite, tiefe, hoehe, abs_oben, abs_seite, druck_hoehe, druck_text, anz_laschen, la_laenge, la_breite, la_hoehe, la_lochabst, la_lochdurchm, trafo_pin_laenge, pinabstand, pin_aus, pin_in, dia_schraube)

/********************************************************************************************************************************************
// Makro: Abgerundeter Quader 
// Breite=B , Tiefe = T, Hoehe = H
********************************************************************************************************************************************/
#macro TRAFO_ERA_EI_ROUNDED_BOX(B,T,H) 
union{
#local rundung = 0.8;    // Stärke der Abrundung am Gehäuse
box{<-B/2+rundung, 0,     T/2>     <B/2-rundung,H-rundung,-T/2>      rotate<0,0,0> translate<0,0,0>} //Grundkoerper
box{<-B/2,     0,    -T/2+rundung> <B/2,    H-rundung, T/2-rundung>  rotate<0,0,0> translate<0,0,0>} //Kleine Box innen
box{<-B/2+rundung, H-rundung,-T/2+rundung> <B/2-rundung,H    , T/2-rundung>  rotate<0,0,0> translate<0,0,0>} //Kleine Box oben

cylinder{<-B/2+rundung,0,0> <-B/2+rundung, H-rundung> rundung  rotate<0,0,0> translate <0, 0,  T/2-rundung>} //Rundungen rechts
cylinder{<-B/2+rundung,0,0> <-B/2+rundung, H-rundung> rundung  rotate<0,0,0> translate <0, 0, -T/2+rundung>} //Rundungen rechts
cylinder{< B/2-rundung,0,0> < B/2-rundung, H-rundung> rundung  rotate<0,0,0> translate <0, 0,  T/2-rundung>} //Rundungen links
cylinder{< B/2-rundung,0,0> < B/2-rundung, H-rundung> rundung  rotate<0,0,0> translate <0, 0, -T/2+rundung>} //Rundungen links

sphere{< B/2-rundung, H-rundung, T/2-rundung> rundung scale <1,1,1>  translate<0,0,0>}  //Rundungen oben
sphere{< B/2-rundung, H-rundung,-T/2+rundung> rundung scale <1,1,1>  translate<0,0,0>}  //Rundungen oben
sphere{<-B/2+rundung, H-rundung, T/2-rundung> rundung scale <1,1,1>  translate<0,0,0>}  //Rundungen oben
sphere{<-B/2+rundung, H-rundung,-T/2+rundung> rundung scale <1,1,1>  translate<0,0,0>}  //Rundungen oben

cylinder{<-B/2+rundung,  H-rundung> < B/2-rundung, H-rundung> rundung rotate<0,0,0> translate <0, 0, T/2-rundung>}   //Rundungen vorne
cylinder{<-B/2+rundung,  H-rundung> < B/2-rundung, H-rundung> rundung rotate<0,0,0> translate <0, 0,-T/2+rundung>}   //Rundungen hinten
cylinder{<-T/2+rundung,  H-rundung> < 0, H-rundung> rundung rotate<0, 90,0> translate <-B/2+rundung, 0, 0>}  //Rundungen rechts kurz
cylinder{<-T/2+rundung,  H-rundung> < 0, H-rundung> rundung rotate<0,-90,0> translate <-B/2+rundung, 0, 0>}  //Rundungen rechts kurz
cylinder{<-T/2+rundung,  H-rundung> < 0, H-rundung> rundung rotate<0, 90,0> translate < B/2-rundung, 0, 0>}  //Rundungen links kurz
cylinder{<-T/2+rundung,  H-rundung> < 0, H-rundung> rundung rotate<0,-90,0> translate < B/2-rundung, 0, 0>}  //Rundungen links kurz
}
#end 
/***********************************************************************************************
// Makro für die Befestigungslaschen der größeren Transformatoren
// Gesamtlänge = ges_l, Breite, Höhe der Platte, Lochabstand = hole_dist, Lochdurchmesser = hole
***********************************************************************************************/
#macro TRAFO_ERA_EI_BEF_LASCHE(ges_l, breite, hoehe, hole_dist, hole)
#local D = 0.001;
union{
difference {
box{<- breite/2, 0, - ges_l/2> < breite/2, hoehe, ges_l/2>      rotate<0,0,0> translate<0 ,0,0>}
union { 
cylinder {<0, -D, 0> , <0, hoehe + D, 0>, hole/2 translate <0,0,hole_dist/2>  }   
cylinder {<0, -D, 0> , <0, hoehe + D, 0>, hole/2 translate <0,0,- hole_dist/2>  }
}
} 
// Versteifungen
prism{ -hoehe/2, hoehe/2, 4
   < 0.00, 0.00>,
   < 10.00, 0.00>,
   < 0.00, 20.00>,
   < 0.00, 0.00>
   rotate<-90,90,0> 
   translate <breite/2 - hoehe /2 ,0,-ges_l/2 + 10.0>
}
prism{ -hoehe/2, hoehe/2, 4
   < 0.00, 0.00>,
   < 10.00, 0.00>,
   < 0.00, 20.00>,
   < 0.00, 0.00>
   rotate<-90,90,0> 
   translate <-breite/2 + hoehe /2,0,-ges_l/2 + 10.0>
}
prism{ -hoehe/2, hoehe/2, 4
   < 0.00, 0.00>,
   < 10.00, 0.00>,
   < 0.00, 20.00>,
   < 0.00, 0.00>
   rotate<-90,-90,0> 
   translate <breite/2 - hoehe /2,0, ges_l/2 - 10.0>
} 
prism{ -hoehe/2, hoehe/2, 4
   < 0.00, 0.00>,
   < 10.00, 0.00>,
   < 0.00, 20.00>,
   < 0.00, 0.00>
   rotate<-90,-90,0> 
   translate <-breite/2 + hoehe /2,0,ges_l/2 - 10.0>
}    
}
#end 
/***********************************************************************************************
// Schraube M2,5, M3 oder M4 mit Mutter
***********************************************************************************************/
#macro TRAFO_ERA_EI_SCHRAUBE (RotY, Gewinde, Hoe_Kopf, Hoe_Mutt)

#if (Gewinde = 2.5) #local SW = 4.0; #local Height = 2.0; #end
#if (Gewinde = 3.0) #local SW = 5.5; #local Height = 2.5; #end
#if (Gewinde = 4.0) #local SW = 7.0; #local Height = 3.0; #end
union {   
   union {
      // Kopf mit Kreuzschlitz
      difference {
         union {
            cylinder {<0, 0.1, 0>, <0, Gewinde / 2 - 0.05, 0>, SW / 2}
            sphere {0, SW / 2 scale <1, 0.5, 1> translate (Gewinde / 2 - 0.05 )* y}
            torus {SW / 2 - 0.1, 0.1 translate 0.1 * y}
            cylinder {<0, 0.0, 0>, <0, 0.1, 0>, SW / 2 - 0.1}
            cylinder {<0, 0.0, 0>, <0, -(Hoe_Kopf + Hoe_Mutt + Height + 0.5), 0>, Gewinde / 2 - 0.05}
         }
         box {<-0.4, 0, 0>, <+0.4, 5, 5> rotate -45 * x translate 0.5 * y}
         box {<0, 0, -0.4>, <+5, 5, +0.4> rotate 45 * z translate 0.5 * y}
      } 
       texture {
            pigment {rgb 0.5}
            finish {
                phong 0.6
                phong_size 7
                reflection 0.3
                ambient (0.1 * global_ambient_mul)
            }
      }      
      translate <0, Hoe_Kopf, 0>
      // Gesamtposition
      rotate RotY * y
   }
      // Mutter
   intersection{
         prism {
            linear_spline
            linear_sweep
            0, -Height, 7
            < 0, +sqrt(1 / 3) * 2>,
            <+1, +sqrt(1 / 3)>,
            <+1, -sqrt(1 / 3)>,
            < 0, -sqrt(1 / 3) * 2>,
            <-1, -sqrt(1 / 3)>,
            <-1, +sqrt(1 / 3)>,
            < 0, +sqrt(1 / 3) * 2>
            scale <SW / 2, 1, SW / 2>
         }
         cylinder {          // Innen
            <0, 2, 0>, <0, -(Height + 5), 0>,
            Gewinde / 2 + 0.1
            inverse
         }
         texture {
            pigment {rgb 0.5}
            finish {
                phong 0.6
                phong_size 7
                reflection 0.3
                ambient (0.1 * global_ambient_mul)
            }            
         }
         translate <0, -Hoe_Mutt, 0>
     }
}       
#end

union { 
        union {                 
                object {TRAFO_ERA_EI_ROUNDED_BOX (breite, tiefe, hoehe - abs_oben)}                       // Quader ohne Aufsatz
                object {TRAFO_ERA_EI_ROUNDED_BOX (breite - abs_seite, tiefe - abs_seite, hoehe)}          // Aufsatz
                // Befestigungslaschen falls vorhanden
                #if (anz_laschen = 1)
                        object {TRAFO_ERA_EI_BEF_LASCHE ( la_laenge, la_breite, la_hoehe, la_lochabst, la_lochdurchm)} 
                #end
                #if (anz_laschen = 2)
                        object {TRAFO_ERA_EI_BEF_LASCHE ( la_laenge, la_breite, la_hoehe, la_lochabst, la_lochdurchm) translate < -tiefe/2 + la_breite, 0, 0>}
                        object {TRAFO_ERA_EI_BEF_LASCHE ( la_laenge, la_breite, la_hoehe, la_lochabst, la_lochdurchm) translate <  tiefe/2 - la_breite, 0, 0>}
                #end
                texture {              
                        pigment {Blue}
                        normal { bumps 0.02 scale 0.002 } 
                        finish {
                                ambient (0.15 * global_ambient_mul)
                                diffuse 0.85
                                phong 0.4
                                phong_size 40
                                reflection 0.01                 
                        }
                }
        }
        // Schrauben
        #if (anz_laschen = 1)
                object {TRAFO_ERA_EI_SCHRAUBE( +30, dia_schraube, la_hoehe, pcb_height) translate <0, 0, la_lochabst / 2>} 
                object {TRAFO_ERA_EI_SCHRAUBE( +30, dia_schraube, la_hoehe, pcb_height) translate <0, 0, -la_lochabst / 2>}
        #end
        #if (anz_laschen = 2)
                object {TRAFO_ERA_EI_SCHRAUBE ( +30, dia_schraube, la_hoehe, pcb_height) translate < tiefe/2 - la_breite, 0, la_lochabst / 2>} 
                object {TRAFO_ERA_EI_SCHRAUBE ( +30, dia_schraube, la_hoehe, pcb_height) translate <-tiefe/2 + la_breite, 0, la_lochabst / 2>}
                object {TRAFO_ERA_EI_SCHRAUBE ( +30, dia_schraube, la_hoehe, pcb_height) translate < tiefe/2 - la_breite, 0, -la_lochabst / 2>}
                object {TRAFO_ERA_EI_SCHRAUBE ( +30, dia_schraube, la_hoehe, pcb_height) translate <-tiefe/2 + la_breite, 0, -la_lochabst / 2>}
                
        #end
        // Anschlussbeine
        #if(pin_short=on)
                #local trafo_pin_length = -1*(pin_length+pcb_height);
        #else
                #local trafo_pin_length = -trafo_pin_laenge;
        #end
        cylinder{<-pinabstand/2 ,0, pin_aus> <-pinabstand/2,trafo_pin_length, pin_aus> 0.40 texture{col_silver}}   // Draht links  prim1
        cylinder{< pinabstand/2 ,0, pin_aus> < pinabstand/2,trafo_pin_length, pin_aus> 0.40 texture{col_silver}}   // Draht rechts sek1  
        cylinder{< pinabstand/2 ,0,  pin_in> < pinabstand/2,trafo_pin_length,  pin_in> 0.40 texture{col_silver}}   // Draht rechts sek1
        cylinder{< pinabstand/2 ,0, -pin_in> < pinabstand/2,trafo_pin_length, -pin_in> 0.40 texture{col_silver}}   // Draht rechts sek2
        cylinder{< pinabstand/2 ,0,-pin_aus> < pinabstand/2,trafo_pin_length,-pin_aus> 0.40 texture{col_silver}}   // Draht rechts sek2  
        cylinder{<-pinabstand/2 ,0,-pin_aus> <-pinabstand/2,trafo_pin_length,-pin_aus> 0.40 texture{col_silver}}   // Draht rechts prim1
        // Beschriftung
        text {ttf besch_font "era"      0.1, 0 scale<druck_hoehe, druck_hoehe, druck_hoehe> pigment {White}
                         rotate<0,90,0> translate<-breite/2 - 0.01 , hoehe - abs_oben - 2* druck_hoehe , tiefe/2 - druck_hoehe>} //Beschriftung era
        text {ttf besch_font druck_text 0.1, 0 scale<druck_hoehe, druck_hoehe, druck_hoehe> pigment {White}
                         rotate<0,90,0> translate<-breite/2 - 0.01 , hoehe - abs_oben - 3* druck_hoehe,  tiefe/2 - druck_hoehe>} //Beschriftung Typ 
        text {ttf besch_font value      0.1, 0 scale<druck_hoehe, druck_hoehe, druck_hoehe> pigment {White} 
                         rotate<0,90,0> translate<-breite/2 - 0.01 , hoehe - abs_oben - 4* druck_hoehe,  tiefe/2 - druck_hoehe>} //Beschriftung Value

} 
#end
// Printtransformator era EI30/23 2,8VA 
#macro TRAFO_ERA_EI_30_2(value)
TRAFO_ERA_EI_GRND(value, 27.5, 32.5, 34.0, 4, 10, 3.0, "Typ EI 30/23", 0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.5, 20.0, 10.0, 5.0, 4.0)
#end
// Printtransformator era EI38/13,6 3,2VA  
#macro TRAFO_ERA_EI_38_2(value)
TRAFO_ERA_EI_GRND(value, 35.5, 42.0, 28.0, 5, 12, 3.0, "Typ EI 38/13,6", 0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.5, 25.0, 10.0, 5.0, 4.0)
#end
// Printtransformator era EI42/14,8 5VA  
#macro TRAFO_ERA_EI_42_2(value)
TRAFO_ERA_EI_GRND(value, 38.5, 45.5, 32.0, 6, 13, 3.5, "Typ EI 42/14,8", 0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.5, 25.0, 12.5, 7.5, 4.0)
#end
// Printtransformator era EI42/14,8 5VA mit Befestigungslasche    
#macro TRAFO_ERA_EI_42_2B(value)
TRAFO_ERA_EI_GRND(value, 38.5, 45.5, 32.0, 6, 13, 3.5, "Typ EI 42/14,8", 1, 64.0, 10.0, 2.0, 55.0, 4.2, 3.5, 25.0, 12.5, 7.5, 4.0)
#end
// Printtransformator era EI48/15,8 10VA
#macro TRAFO_ERA_EI_48_2(value)
TRAFO_ERA_EI_GRND(value, 42.5, 50.5, 34.5, 6, 14, 4.0, "Typ EI 48/15,8", 0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.5, 27.5, 12.5, 7.5, 4.0)
#end
// Printtransformator era EI48/15,8 10VA mit Befestigungslaschen
#macro TRAFO_ERA_EI_48_2B(value)
TRAFO_ERA_EI_GRND(value, 42.5, 50.5, 34.5, 6, 14, 4.0, "Typ EI 48/15,8", 1, 69.0, 10.0, 2.0, 60.0, 4.2, 3.5, 27.5, 12.5, 7.5, 4.0)
#end
// Printtransformator era EI54/18,8 16VA
#macro TRAFO_ERA_EI_54_2(value)
TRAFO_ERA_EI_GRND(value, 48.0, 57.0, 39.0, 7, 16, 4.0, "Typ EI 54/18,8", 0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.5, 30.0, 15.0, 10.0, 4.0)
#end
// Printtransformator era EI54/18,8 16VA mit Befestigungslaschen
#macro TRAFO_ERA_EI_54_2B(value)
TRAFO_ERA_EI_GRND(value, 48.0, 57.0, 39.0, 7, 16, 4.0, "Typ EI 54/18,8", 2, 75.3, 10.0, 2.0, 65.0, 4.2, 4.5, 30.0, 15.0, 10.0, 4.0)
#end
// Printtransformator era EI60/25,5 25VA mit Befestigungslaschen
#macro TRAFO_ERA_EI_60_2(value)
TRAFO_ERA_EI_GRND(value, 55.0, 66.0, 49.2, 9, 21, 4.0, "Typ EI 60/23", 2, 81.5, 11.2, 2.0, 72.5, 4.2, 4.5, 32.5, 15.0, 10.0, 4.0)
#end
// Printtransformator era EI66/23 36VA mit Befestigungslaschen
#macro TRAFO_ERA_EI_66_2(value)
TRAFO_ERA_EI_GRND(value, 61.0, 71.0, 48.5, 9, 21, 4.0, "Typ EI 66/23", 2, 87.2, 10.8, 2.0, 77.5, 4.2, 4.5, 35.0, 17.5, 12.5, 4.0)
#end


/********************************************************************************************************************************************
//Macros for EI Transformer
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.0 du 29/12/05
********************************************************************************************************************************************/
#macro TRAFO_MYRRA_EI_GRND(L,W,H,L1,W1,H1,Lp,Wp,D,Sw,Fx,Pl,Lh)

#local MyrraBrown = color red 0.7 green 0.3 blue 0.164706;
#local r = 0.4;     //pin ray
#if(L1=0)
    #local L1=L/1.2;  //20% if unknown
#end
#if(W1=0)
    #local W1=W/1.2;  //20% if unknown
#end
#if(H1=0)
    #local H1=H/1.2;  //20% if unknown
#end
union{
    difference{
        union{
            difference{
                superellipsoid { <0.06, 0.06> scale <L/2, H1/2+2,W/2> translate <0, H1/2-2, 0>}
                box{<-L/2-1,-4.5,-W/2-1><+L/2+1,0,+W/2+1>}
            }
            superellipsoid { <0.06, 0.06> scale <L1/2,H/2,W1/2> translate <0, H/2, 0> }  
            pigment{MyrraBrown }
        }
        union{
            cylinder{<-Lh/2,-1,0><-Lh/2,10,0> D/2}
            cylinder{<+Lh/2,-1,0><+Lh/2,10,0> D/2}
            pigment{Gray50}
        }      
    }
    //Pins #1 & 5
    cylinder{<-Lp/2,0,-Wp/2><-Lp/2,-Pl,-Wp/2> r texture { pigment{Silver} } }        
    cylinder{<+Lp/2,0,-Wp/2><+Lp/2,-Pl,-Wp/2> r texture { pigment{Silver} } }        
    //Pins #7 & 9
    cylinder{<-Lp/2+5,0,+Wp/2><-Lp/2+5,-Pl,+Wp/2> r texture { pigment{Silver} } }        
    cylinder{<+Lp/2-5,0,+Wp/2><+Lp/2-5,-Pl,+Wp/2> r texture { pigment{Silver} } }        
    #if (Sw = 2)
        //Pins #6 & 10        
        cylinder{<-Lp/2,0,+Wp/2><-Lp/2,-Pl,+Wp/2> r texture { pigment{Silver} } }        
        cylinder{<+Lp/2,0,+Wp/2><+Lp/2,-Pl,+Wp/2> r texture { pigment{Silver} } }        
    #end 
    
    // Top marking
    union{
    box{<-12,H,+2><+8,H+0.01,+8> pigment{White}}
    box{<-12+0.3,H+0.01,+2+0.3><+8-0.3,H+0.02,+8-0.3> pigment{MyrraBrown}}
    text {ttf global_fontfile_arial "myrra" 0.05, 0 pigment{White} scale 5 rotate<90,0,0> translate<-10.5,H+0.05,4>}  // Marking
    //disc {<-10, H+0.02, -8> y,2,1.8 pigment{White}}
    //disc {<-5, H+0.02, -8> y,2,1.8 pigment{White}}
    //disc {<-0, H+0.02, -8> y,2,1.8 pigment{White}}
    //disc {<+5, H+0.02, -8> y,2,1.8 pigment{White}}
    //text {ttf global_fontfile_arial "FI" 0.05, 0 pigment{White} scale 3 rotate<90,0,0> translate<-11,H+0.05,-9>}      // Marking
    text {ttf global_fontfile_eagle3d "O" 0.05, 0 pigment{White} scale 4.5 rotate<90,0,0> translate<-12,H+0.05,-10>}      // Marking
    //text {ttf global_fontfile_arial "S" 0.05, 0 pigment{White} scale 3 rotate<90,0,0> translate<-11+5.2,H+0.05,-9>}   // Marking
    text {ttf global_fontfile_eagle3d "P" 0.05, 0 pigment{White} scale 4.5 rotate<90,0,0> translate<-12+5.1,H+0.05,-10>}      // Marking
    //text {ttf global_fontfile_arial "N" 0.05, 0 pigment{White} scale 3 rotate<90,0,0> translate<-11+10.1,H+0.05,-9>}  // Marking
    text {ttf global_fontfile_eagle3d "Q" 0.05, 0 pigment{White} scale 4.5 rotate<90,0,0> translate<-12+10.4,H+0.05,-10>}      // Marking
    //text {ttf global_fontfile_arial "D" 0.05, 0 pigment{White} scale 3 rotate<90,0,0> translate<-11+15.3,H+0.05,-9>}  // Marking
    text {ttf global_fontfile_eagle3d "N" 0.05, 0 pigment{White} scale 4.5 rotate<90,0,0> translate<-12+15.6,H+0.05,-10>}      // Marking
    text {ttf global_fontfile_eagle3d "I" 0.05, 0 pigment{White} scale 5 rotate<90,0,0> translate<+2,H+0.08,-4>}       // RU Marking
    text {ttf global_fontfile_eagle3d "B" 0.05, 0 pigment{White} scale 5 rotate<90,0,0> translate<-4.5,H+0.08,-4>}       // DVE Marking
    text {ttf global_fontfile_eagle3d "E" 0.05, 0 pigment{White} scale 6 rotate<90,0,0> translate<-13,H+0.08,-4.5>}    // CE Marking
    text {ttf global_fontfile_eagle3d "H" 0.05, 0 pigment{White} scale 6 rotate<90,0,0> translate<+3,H+0.08,+2.3>}     // MYRRA LOGO Marking 
    translate 2*x
    scale <L1/33,0,L1/33>
    }

    rotate 90*y     
}
#end
#macro TRAFO_MYRRA_EI_30_1_005()
TRAFO_MYRRA_EI_GRND(32.6,27.6,15.8,0,0,11.5,20,20,0,1,0,4.5,0)
#end
#macro TRAFO_MYRRA_EI_30_2_005()
TRAFO_MYRRA_EI_GRND(32.6,27.6,15.8,0,0,11.5,20,20,0,2,0,4.5,0)
#end
#macro TRAFO_MYRRA_EI_30_1_105()
TRAFO_MYRRA_EI_GRND(32.6,27.6,22.2,0,0,18.4,20,20,0,1,0,4.5,0)
#end
#macro TRAFO_MYRRA_EI_30_2_105()
TRAFO_MYRRA_EI_GRND(32.6,27.6,22.2,0,0,18.4,20,20,0,2,0,4.5,0)
#end
#macro TRAFO_MYRRA_EI_30_1_125()
TRAFO_MYRRA_EI_GRND(32.6,27.6,24.5,0,0,20.5,20,20,0,1,0,4.5,0)
#end
#macro TRAFO_MYRRA_EI_30_2_125()
TRAFO_MYRRA_EI_GRND(32.6,27.6,24.5,0,0,20.5,20,20,0,2,0,4.5,0)
#end
#macro TRAFO_MYRRA_EI_30_1_155()
TRAFO_MYRRA_EI_GRND(32.6,27.6,27.3,0,0,23.5,20,20,0,1,0,4.5,0)
#end
#macro TRAFO_MYRRA_EI_30_2_155()
TRAFO_MYRRA_EI_GRND(32.6,27.6,27.3,0,0,23.5,20,20,0,2,0,4.5,0)
#end
#macro TRAFO_MYRRA_EI_30_1_180()
TRAFO_MYRRA_EI_GRND(32.6,27.6,29.8,0,0,26.0,20,20,0,1,0,4.5,0)
#end
#macro TRAFO_MYRRA_EI_30_2()
TRAFO_MYRRA_EI_GRND(32.6,27.6,29.8,0,0,26.0,20,20,0,2,0,4.5,0)
#end
#macro TRAFO_MYRRA_EI_38_1()
TRAFO_MYRRA_EI_GRND(41.0,35.0,28.0,30.5,25.7,23.0,20,25,0,1,0,4,0)
#end
#macro TRAFO_MYRRA_EI_38_2()
TRAFO_MYRRA_EI_GRND(41.0,35.0,28.0,30.5,25.7,23.0,20,25,0,2,0,4,0)
#end
#macro TRAFO_MYRRA_EI_42_1()
TRAFO_MYRRA_EI_GRND(44.25,37.0,32.25,32.25,27.70,26.0,25,25,0,1,0,4,0)
#end
#macro TRAFO_MYRRA_EI_42_2()
TRAFO_MYRRA_EI_GRND(44.25,37.0,32.25,32.25,27.70,26.0,25,25,0,2,0,4,0)
#end
#macro TRAFO_MYRRA_EI_48_1()
TRAFO_MYRRA_EI_GRND(50.50,42.5,34.75,33.60,25.6,0,25,27.5,2.5,1,0,3.5,40)
#end
#macro TRAFO_MYRRA_EI_48_2()
TRAFO_MYRRA_EI_GRND(50.50,42.5,34.75,33.60,25.6,0,25,27.5,2.5,2,0,3.5,40)
#end
#macro TRAFO_MYRRA_EI_54_1()
TRAFO_MYRRA_EI_GRND(56.50,47.25,38.75,37.50,29.25,33,30,30,2.5,1,0,4,45)
#end
#macro TRAFO_MYRRA_EI_54_2()
TRAFO_MYRRA_EI_GRND(56.50,47.25,38.75,37.50,29.25,33,30,30,2.5,2,0,4,45)
#end
#macro TRAFO_MYRRA_EI_60_1()
TRAFO_MYRRA_EI_GRND(63.5,53.5,45.5,0,0,36.5,30,32.5,2.5,1,0,4,50)
#end
#macro TRAFO_MYRRA_EI_60_2()
TRAFO_MYRRA_EI_GRND(63.5,53.5,45.5,0,0,36.5,30,32.5,2.5,2,0,4,50)
#end
#macro TRAFO_MYRRA_EI_66_1()
TRAFO_MYRRA_EI_GRND(70,59,48.75,0,0,0,35,35,2.5,1,0,4.5,55)
#end
#macro TRAFO_MYRRA_EI_66_2()
TRAFO_MYRRA_EI_GRND(70,59,48.75,0,0,0,35,35,2.5,2,0,4.5,55)
#end


/********************************************************************************************************************************************
//Macros for Transformer UI48 60VA
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1  10/01/06
********************************************************************************************************************************************/
#macro TRAFO_MYRRA_UI48_GRND(value,pw)

#macro LABEL_R (L,W,R)
#local e=0.005;
    union{
        cylinder{<-L/2+R,0,-W/2+R><-L/2+R,e,-W/2+R> R}
        cylinder{<+L/2-R,0,-W/2+R><+L/2-R,e,-W/2+R> R}
        cylinder{<-L/2+R,0,+W/2-R><-L/2+R,e,+W/2-R> R}
        cylinder{<+L/2-R,0,+W/2-R><+L/2-R,e,+W/2-R> R}
        box{<-L/2+R,0,-W/2><+L/2-R,e,+W/2>}
        box{<-L/2,0,-W/2+R><+L/2,e,+W/2-R>}
        texture{col_silver}
    }
#end
//**********************************************************************

#if (pw = 60)
    #local A = 24.25;
    #local B = 7.25;
    #local C = 43;
    #local D = A; //3*A/4;
    #local E = 34;
#else
    #local A = 19.25;
    #local B = 6.75;
    #local C = 41.5;
    #local D = 15;  //3*A/4;
    #local E = 27.5;
#end
union{
    difference{
        union{
            superellipsoid { <0.05, 0.05> scale <E, A,35> translate <0, A, 0> pigment{Gray50} }
            superellipsoid { <0.05, 0.05> scale <C, D, 26.25> translate <0, D, 0> pigment{Gray50} }
            superellipsoid { <0.05, 0.05> scale <C, B, 35> translate <0, B, 0> pigment{Gray50} }
        }
        union{
            cylinder{<-37.5,15,30><-37.5,-1,30> 1.55 }        
            cylinder{<37.5,15,-30><37.5,-1,-30> 1.55 }        
            cylinder{<-37.5,15,-30><-37.5,-1,-30> 1.55 }        
            cylinder{<37.5,15,30><37.5,-1,30> 1.55 }        
            cylinder{<0,2*A-0.5,0><0,2*A+0.5,0> 0.5 }        
            pigment{Gray20}
        }
    }
    #if(global_show_screws=on)
        object { TOOLS_SCREW(4,5,1,Silver) rotate 180*x translate <-37.5,-pcb_height,+30> }
        object { TOOLS_SCREW(4,5,1,Silver) rotate 180*x translate <-37.5,-pcb_height,-30> }
        object { TOOLS_SCREW(4,5,1,Silver) rotate 180*x translate <+37.5,-pcb_height,+30> }
        object { TOOLS_SCREW(4,5,1,Silver) rotate 180*x translate <+37.5,-pcb_height,-30> }
    #end

    union{
        object{LABEL_R(15,30,1.5)}
        text {ttf global_fontfile_eagle3d "H" 0.05, 0 pigment{Black} scale 4.5 rotate<90,0,0> translate<-6.5,0.05,10.5>}    // Myrra logo
        text {ttf global_fontfile_eagle3d "Z" 0.05, 0 pigment{Black} scale 3.5 rotate<90,0,0> translate<-5.8,0.05,7>}       // logo
        text {ttf global_fontfile_eagle3d "A" 0.05, 0 pigment{Black} scale 3.5 rotate<90,0,0> translate<-5.8,0.05,-8>}      // UL Marking
        text {ttf global_fontfile_eagle3d "I" 0.05, 0 pigment{Black} scale 3.5 rotate<90,0,0> translate<-6.5,0.05,-12.5>}     // Canada UL Marking
        text {ttf global_fontfile_eagle3d "/" 0.05, 0 pigment{Black} scale 1 rotate<90,0,0> translate<-6.5,0.05,5.5>}     // Fuse Marking
        text {ttf global_fontfile_eagle3d "/" 0.05, 0 pigment{Black} scale 1 rotate<90,0,0> translate<-6.5,0.05,2.5>}     // Fuse Marking
        box{<2.5,0,-7><5.5,0.05,-13> pigment{Black}}
        text {ttf global_fontfile_arial_bold "63801" 0.05, 0 pigment{White} scale <1.8,2.2,1> rotate<90,90,0> translate<3.2,0.07,-7.7>} // Marking
        
        text {ttf global_fontfile_arial_bold value 0.05, 0 pigment{Black} scale 2 rotate<90,0,0> translate<-0.8,0.05,12.8>}     // Ref Marking
        text {ttf global_fontfile_arial_bold "2x115V" 0.05, 0 pigment{Black} scale 2 rotate<90,0,0> translate<-1,0.05,10.8>}  // Marking
        text {ttf global_fontfile_arial_bold "50/60Hz" 0.05, 0 pigment{Black} scale 2 rotate<90,0,0> translate<-2,0.05,7.7>} // Marking
        #if(pw=60)
            text {ttf global_fontfile_arial_bold "315mA(230V)" 0.05, 0 pigment{Black} scale 1.5 rotate<90,0,0> translate<-5,0.05,4>} // Marking
            text {ttf global_fontfile_arial_bold "630mA(115V)" 0.05, 0 pigment{Black} scale 1.5 rotate<90,0,0> translate<-5,0.05,1>} // Marking
        #else
            text {ttf global_fontfile_arial_bold "200mA(230V)" 0.05, 0 pigment{Black} scale 1.5 rotate<90,0,0> translate<-5,0.05,4>} // Marking
            text {ttf global_fontfile_arial_bold "400mA(115V)" 0.05, 0 pigment{Black} scale 1.5 rotate<90,0,0> translate<-5,0.05,1>} // Marking
        #end
        text {ttf global_fontfile_arial_bold "T" 0.05, 0 pigment{Black} scale 0.8 rotate<90,0,0> translate<-3,0.05,6.2>} // Marking
        text {ttf global_fontfile_arial_bold "T" 0.05, 0 pigment{Black} scale 0.8 rotate<90,0,0> translate<-3,0.05,3.2>} // Marking
        text {ttf global_fontfile_arial_bold "1           4           9           12" 0.05, 0 pigment{Black} scale 1 rotate<90,0,0> translate<-6,0.05,-14>} // Marking
        #if(pw=60)
            text {ttf global_fontfile_arial_bold "15V 30VA" 0.05, 0 pigment{Black} scale 2 rotate<90,0,0> translate<-4,0.05,-1.5>}      // Marking
            text {ttf global_fontfile_arial_bold "15V 30VA" 0.05, 0 pigment{Black} scale 2 rotate<90,0,0> translate<-4,0.05,-4>}      // Marking
        #else
            text {ttf global_fontfile_arial_bold "15V 20VA" 0.05, 0 pigment{Black} scale 2 rotate<90,0,0> translate<-4,0.05,-1.5>}      // Marking
            text {ttf global_fontfile_arial_bold "15V 20VA" 0.05, 0 pigment{Black} scale 2 rotate<90,0,0> translate<-4,0.05,-4>}      // Marking
        #end
        text {ttf global_fontfile_arial_bold "ta 50/B" 0.05, 0 pigment{Black} scale 1.5 rotate<90,0,0> translate<1,0.05,-6>} // Marking
        rotate 180*y
        #if(pw=60)
            translate<34-8,2*A,35-17-2>
        #else
            translate<27.5-3,2*A,35-17-8>
        #end
        rotate -90*y
    }
    box{<-0.25,0,-0.6><+0.25,-4,+0.6> translate<-26.5,0,-28.5> texture{col_silver}}        
    box{<-0.25,0,-0.6><+0.25,-4,+0.6> translate<-26.5,0,+28.5> texture{col_silver}}        
    box{<-0.25,0,-0.6><+0.25,-4,+0.6> translate<-26.5,0,-13.5> texture{col_silver}}        
    box{<-0.25,0,-0.6><+0.25,-4,+0.6> translate<-26.5,0,+13.5> texture{col_silver}}        

    box{<-0.25,0,-0.6><+0.25,-4,+0.6> translate<+26.5,0,-23.5> texture{col_silver}}        
    box{<-0.25,0,-0.6><+0.25,-4,+0.6> translate<+26.5,0,+23.5> texture{col_silver}}        
    box{<-0.25,0,-0.6><+0.25,-4,+0.6> translate<+26.5,0,-8.5> texture{col_silver}}        
    box{<-0.25,0,-0.6><+0.25,-4,+0.6> translate<+26.5,0,+8.5> texture{col_silver}}        
    
//    rotate 90*y     
}
#end
#macro TRAFO_MYRRA_UI48_40(value)
TRAFO_MYRRA_UI48_GRND(value,40)
#end
#macro TRAFO_MYRRA_UI48_60(value)
TRAFO_MYRRA_UI48_GRND(value,60)
#end


/********************************************************************************************************************************************
//Macros for SMD 600ohm 1:1 transformer ref SM-LP-5001 from Bourns
//Designed by Philippe Boucheny <philippe.boucheny(at)free.fr>
//Rev. 1.1  12/04/06
********************************************************************************************************************************************/
#macro TRAFO_SM_LP_GRND()
#macro TRAFO_SMD_PIN(H,B,T,S)
union{
    box{<0,H,T/2><B/4,H-S,-T/2>}
    difference{
        cylinder{<B/4,H-S,-T/2><B/4,H-S,T/2>S}
        box{<-1,H-S,-T/2-0.01><B/2,H-S-3,T/2+0.01>}
    }
    box{<B/4,H-S,-T/2><B/4+S,S,T/2>}
    difference{
        cylinder{<B/4+S,S,-T/2><B/4+S,S,T/2>S}
        box{<0,S,-T/2-0.01><B,S+3,T/2+0.01>}
    }
    box{<B/4+S,0,-T/2><B,S,T/2>}
    difference{
        box{<B/4+S,S,-T/2><B/4+S+S/2,1.5*S,T/2>}
        cylinder{<B/4+S+S/2,S+S/2,T/2+0.01><B/4+S+S/2,S+S/2,-T/2-0.01>,S/2}
    }
    texture{col_silver}
}
#end

union{
    box{<-6.25,1,-4.8><+6.25,7.1,+4.8> pigment{Gray20}}
    text {ttf global_fontfile_eagle3d "<" 0.05, 0 pigment{White} scale 1.8 rotate<90,0,0> translate<-1,7.1+0.05,+2.1>}      // Marking
    text {ttf global_fontfile_courier_bold value 0.05, 0 pigment{White} scale 2 rotate<90,0,0> translate<-5.8,7.1+0.05,-0.8>}  // Marking
    text {ttf global_fontfile_courier_bold "9545" 0.05, 0 pigment{White} scale 2 rotate<90,0,0> translate<-2,7.1+0.05,-3.5>}  // Marking
	object {TRAFO_SMD_PIN(1.5,2.0,0.7,0.3) translate<4.5,0,-2.54>}
	object {TRAFO_SMD_PIN(1.5,2.0,0.7,0.3) translate<4.5,0,0>}
	object {TRAFO_SMD_PIN(1.5,2.0,0.7,0.3) translate<4.5,0,+2.54>}
	object {TRAFO_SMD_PIN(1.5,2.0,0.7,0.3) rotate 180*y translate<-4.5,0,-2.54>}
	object {TRAFO_SMD_PIN(1.5,2.0,0.7,0.3) rotate 180*y translate<-4.5,0,0>}
	object {TRAFO_SMD_PIN(1.5,2.0,0.7,0.3) rotate 180*y translate<-4.5,0,+2.54>}
}
#end

#macro TRAFO_SM_LP_500X(value)
TRAFO_SM_LP_GRND()
#end


/********************************************************************************************************************************************
//Macros for common mode smd line filter WE-SL2 from Wurth Electronik
//Designed by Philippe Boucheny <philippe.boucheny(at)free.fr>
//Rev. 1.0  13/04/06
********************************************************************************************************************************************/
#macro TRAFO_SM_SL2_GRND ()
union{
    difference{
        superellipsoid { <0.05, 0.05> scale <4.6, 2.5,3> translate <0, 2.5, 0> }
        box { <-4.7, -0.1, -4>, <+4.7, 1, 4> }
        box { <-4.7, -0.1, -3>, <+4.7, 1.4, -2.8> }
        box { <-4.7, -0.1, +3>, <+4.7, 1.4, +2.8> }
        text {ttf global_fontfile_arial value 0.2, 0 pigment{Black} scale 3 rotate<90,0,0> translate<-3.25,+5.1,-2>}  // Marking
    }
    
    difference{
        box { <-4.3, 0, -2.8>, <+4.3, 1, 2.8> }  
        box { <-4.7, -0.1, -3.8>, <-2, 0.2, 3.8> }  
        box { <+4.7, -0.1, -3.8>, <+2, 0.2, 3.8> }  
    }

    union{
        box { <-0.1, 0, -0.5>, <+0.1, 0.8, 0.5> translate <-4.5,0,+1.27> }
        box { <-0.1, 0, -0.5>, <+0.1, 0.8, 0.5> translate <-4.5,0,-1.27> } 
        box { <-0.1, 0, -0.5>, <+0.1, 0.8, 0.5> translate <+4.5,0,+1.27> } 
        box { <-0.1, 0, -0.5>, <+0.1, 0.8, 0.5> translate <+4.5,0,-1.27> }
        box { <-0.7, 0, -0.5>, <+0.7, 0.2, 0.5> translate <-4.6+0.7,0,+1.27> }
        box { <-0.7, 0, -0.5>, <+0.7, 0.2, 0.5> translate <-4.6+0.7,0,-1.27> }
        box { <-0.7, 0, -0.5>, <+0.7, 0.2, 0.5> translate <+4.6-0.7,0,+1.27> }
        box { <-0.7, 0, -0.5>, <+0.7, 0.2, 0.5> translate <+4.6-0.7,0,-1.27> }
        pigment{Silver}  
    }
    
    pigment{Gray15}
}
#end

#macro TRAFO_SM_SL2(value)
TRAFO_SM_SL2_GRND ()
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
