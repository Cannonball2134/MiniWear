//Eagle3D 20110101 INC-File e3d_connector.inc
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
 
#ifndef(__connector_inc)
#declare __connector_inc = true;

#ifndef(inc_testmode)
#declare inc_testmode=true;
#include "e3d_tools.inc"
#undef inc_testmode
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_AMP_HE14_1S.inc.src
// Macros for HE14 serie Right-Angle Single-Row
// Designed by Philippe Boucheny <philippe.boucheny(replace with at)numericable.fr>
// Rev. 1.0  09/02/08
// //////////
#macro AMP_HE14_1S(Pins)
#local HE14Blue = color green 0.5 blue 1;
union{
    difference{
        union{
                box{<0,0.8,-2.54><Pins*2.54,2.6,2.54>}
                #local i=0; #while (i<Pins) box{<0.87+i*2.54,0,2.1><1.67+i*2.54,0.8,+2.54>} #local i=i+1; #end

                difference{
                    box{<0,0,-2.1><Pins*2.54,2.6,-2.54>}
                    #local i=0; #while (i<Pins) box{<0.4+i*2.54,-0.1,-2><2.14+i*2.54,0.8,-3>} #local i=i+1; #end
                    box{<-0.01,-0.01,0><0.41,0.8,-3>}
                    box{<Pins*2.54+0.01,-0.01,0><Pins*2.54-0.41,0.8,-3>}
                }
            }
        union{
                cylinder{<0,-2,-2.54+0.2><0,3,-2.54+0.2> 1.2}
                box{<Pins*2.54-0.4,-2,+2.541><Pins*2.55,3,+2.54-0.4>}
                box{<Pins*2.54-0.4,-2,-2.541><Pins*2.55,3,-2.54+1.2>}//front right
                box{<Pins*2.54-1.27,-2,-2.541><Pins*2.55,3,-2.54+0.4>}//front right
                box{<+0.4,-2,+2.541><-0.01,3,+2.54-0.4>} //back right
        }
    }

    difference{
        box{<1.27,2.6,-2.54><(Pins-0.5)*2.54,11.4,-1.9>}
        box{<1.27-1,9,-2.54><(Pins-0.5)*2.54+1,13,-1.9> rotate -8.5*x translate 2*z}
    }
    box{<1.27,8,-2.54><(Pins-0.5)*2.54,8.5,-1.7>}
    box{<1.27,8,-2><(Pins-0.5)*2.54,8.5,-1.7> rotate -30*x translate <0,2.45,3.75>}

    difference{
        box{<0.4,2.6,+2.54><Pins*2.54-0.4,11.4,+1.9>}
        box{<0.4-1,9,+2.54><Pins*2.54-0.4+1,13,+1.9> rotate 8.5*x translate -2*z}
    }
    translate <-Pins*1.27,0,0> pigment {HE14Blue}
}
#end



// ////////////////////////////////////////////////////////////
// Original file: ./1_ARK_PIN.inc.src
// Schraubenkopf
// Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
// Privat: <fbleikamp@web.de>
// //////////
#macro ARK_PIN()
union{
	cylinder{<0,-3,0><0,1.1,0>0.4 texture{col_silver}}
	cone{<0,-3,0>0.4<0,-3.5,0>0.1 texture{col_silver}}
	difference{
		box{<-2.54,0,-4><2.54,10,4>}
		box{<-2.04,1,-4.01><2.04,6,3>}
		box{<-0.75,-0.1,-4.01><0.75,1.1,1>}
		box{<-2.6,5,0><2.6,0,-3> rotate<30,0,0> translate<0,7,-4>}
		box{<-2.6,5,0><2.6,0,3> rotate<-30,0,0> translate<0,7,4>}
		cylinder{<0,5.9,0><0,10.1,0>1.4}
		cone{<0,9,0>1.4<0,10.1,0>1.8}
	}
	superellipsoid{<1,0.1> rotate<90,0,0> scale<1,2.3,1> texture{col_silver} translate<0,7,0>}
	difference{
		superellipsoid{<1,0.1> rotate<90,0,0> scale<1.3,0.5,1.3> texture{col_silver} translate<0,9.5,0>}
		box{<0.25,0,-2><-0.25,1,2>rotate<0,rand(global_seed)*180,0> translate<0,9.8,0>}
	}
	difference{
		box{<-2,1.1,-2.5><2,5.9,2.5>}
		cylinder{<0,3.5,-2.6><0,3.5,2.6>1.4}
		cylinder{<0,3.5,0><0,6,0>1.4}
		texture{col_silver}
	}
	pigment{Gray60}
	translate<0,0.2,0>
}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_CON_JUMPER.inc.src
//  MOSES <iloff@mosesele.de>
//  Jumper
// //////////
#macro CON_JUMPER()
union{
difference{
box{<0,0,0><2.54,6.0,2.00> translate<-1.27,2.5,-1.27>}
box{<0,0,0><0.635,10.0,0.635> translate<-0.3175,2.5,-0.3175>}
pigment{MediumBlue}translate<-1.27,0,0>}
difference{
box{<0,0,0><2.54,6.0,2.00> translate<-1.27,2.5,-1.27>}
box{<0,0,0><0.635,10.0,0.635> translate<-0.3175,2.5,-0.3175>}
pigment{MediumBlue} translate<1.27,0,0>}}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_CON_PBL_F.inc.src
// Pin fuer Buchsenleiste (flache Bauform), hinzugefügt von B.Redemann www.b-redemann.de
// //////////
#macro CON_PBL_F()
union{

difference{
	box{<0,0,0><0.5,3,0.3> translate<-0.25,-3,-0.15>}
	box{<0,0,-0.5><0.5,0.5,0.5> rotate<0,0,-30> translate<0.1,-3,0>}
	box{<0,0,-0.5><-0.5,0.5,0.5> rotate<0,0,30> translate<-0.1,-3,0>}
	box{<-0.5,0,0><0.5,0.5,0.5> rotate<30,0,0> translate<0,-3,0.05>}
	box{<-0.5,0,0><0.5,0.5,-0.5> rotate<-30,0,0> translate<0,-3,-0.05>}
	texture{col_gold}
}
difference{
	difference{
		box{<-1.27,0,-1.27><1.27,3,1.27>}
		box{<-1.27,-0.1,-1.27><1.27,3.1,1.27> rotate<0,45,0> translate<-1.95,0,-1.95> }
		box{<-1.27,-0.1,-1.27><1.27,3.1,1.27> rotate<0,45,0> translate< 1.95,0,-1.95> }
		box{<-1.27,-0.1,-1.27><1.27,3.1,1.27> rotate<0,45,0> translate<-1.95,0, 1.95> }
		box{<-1.27,-0.1,-1.27><1.27,3.1,1.27> rotate<0,45,0> translate< 1.95,0, 1.95> }
	}
	cylinder{<0,1,0><0,3.1,0>1.0}
}

difference{
	cylinder{<0,2.5,0><0,3.03,0>1.0}
	cylinder{<0,1.9,0><0,3.2,0>0.9}
	texture{col_silver}
}

difference{
	cylinder{<0,0.5,0><0,2.55,0>0.9}
	cylinder{<0,0.4,0><0,2.6,0>0.7}
	texture{col_gold}
}
pigment{Gray30}}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_CON_PHOENIX_381_PHGH.inc.src
// Phoenix - Grund-Gehaeuse Kunststoff
// Macros fuer Phoenix Mini-Combicon 3.81mm Klemmen und Gegenstecker
// Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
// Privat: <fbleikamp@web.de>
// Phoenix - Grund-Gehaeuse Kunststoff
// //////////
#macro CON_PHOENIX_381_PHGH()
union{
	difference{
		box{<-1,0,-1.905><8,7,1.905> }
		cylinder{<-1.1,5,0><0.6,5,0>0.65 }
		box{<-1.1,6,-1.4><-0.8,6.5,1.4> }
		box{<-1.1,-0.1,-1.4><-0.8,4,1.4> }
		box{<-1.1,-0.1,-0.5><-0.2,3,0.5> }
		box{<-1.1,-0.1,-1.4><1.2,1.3,1.4> }
		box{<-1.1,-0.1,-1.4><2.4,0.3,1.4> }
		box{<2,0.6,-1.7><8.1,5.5,1.7> }
		box{<2,5.4,-0.6><8.1,6,0.6> }
		box{<2,5.9,-1.5><8.1,6.7,1.5> }
		pigment{ForestGreen}
	}
	//Rundung unten
	difference{
		cylinder{<2,-1.0,0><8,-1.0,0>2.0 }
		box{<1.9,-3.1,-2.1><8.1,0.1,2.1> }
		pigment{ForestGreen}
	}
	//Oben auf
	cylinder{<5,7,-1.905><5,7,1.905>0.2 pigment{ForestGreen}}
	//Links
	box{<6,2,-1.9><8,3.3,-2.1> pigment{ForestGreen}}
	box{<7.5,0.5,-1.9><8,6.5,-2.1> pigment{ForestGreen}}
	//Rechts
	box{<6,2,1.9><8,3.3,2.1> pigment{ForestGreen}}
	box{<7.5,0.5,1.9><8,6.5,2.1> pigment{ForestGreen}}
}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_CON_PHOENIX_381_PHGSG.inc.src
// Macros fuer Phoenix Mini-Combicon 3.81mm Klemmen und Gegenstecker
// Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
// Privat: <fbleikamp@web.de>
// Phoenix - Gegenstecker Kunststoff MC 1,5/xx-ST-381
// //////////
#macro CON_PHOENIX_381_PHGSG()
union{
   difference {
   merge{
      box{<0,0,-1.905><9,9.5,1.905> }
      box{<4,9.5,-1.905><9,11,1.905> }
      box{<-6.2,4,-1.5><0,8,1.5> }
      box{<-6.1,8,-0.4><-4,9,0.4> }
      sphere { <2.05, 9.5, 0>, 0.5 }
      cylinder{<4,9.5,0><4,11,0>1.905 }
      cylinder{<9,7.1,-1.905><9,7.1,1.905>0.3 }

   }
      box{<0.3,0.8,-0.75><9.5,5.5,0.75> }
      box{<8.5,0.5,-1.2><9.5,6.5,1.2> }
      box{<6.3,10.5,-0.9><7,11.1,0.9> }
      box{<-2,-2,-2><2,2,2> rotate<0,0,12> translate<9.9,9.5,0>}
      cylinder{<4,7,0><4,11.1,0>1.4 }
      cylinder{<-6.3,6.5,0><1.5,6.5,0>0.5}
      cylinder{<-6.3,6.5,0><-5.8,6.5,0>0.9}
      cylinder{<-6.3,2.5,0><0,2.5,0>2.0}
   }
   cylinder{<7.5,10.70,-1.905><7.5,10.70,1.905>0.3 }
   pigment{ForestGreen}
}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_CON_PHOENIX_381_PHGSRW.inc.src
// Phoenix - Gegenstecker MCVW 1,5/xx-ST-381 (type =0)
// Macros fuer Phoenix Mini-Combicon 3.81mm Klemmen und Gegenstecker
// Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
// Privat: <fbleikamp@web.de>
// Phoenix - Gegenstecker MCVW 1,5/xx-ST-381 (type =0)
// und MCVR 1,5/xx-ST-381 (type =1) Kunststoffteil
// //////////
#macro CON_PHOENIX_381_PHGSRW(typ)
union{
	difference{
	union{
		box{<-1.5,0,-1.9><1.5,-6.6,2.2>}
		box{<-0.4,-6.5,-1.9><0.4,-4,-3.2> }
	}
	cylinder{<0,0.1,3.7><0,-6.7,3.7>2.0}
	cylinder{<0,0.1,0><0,-6.7,0>0.5}
	cylinder{<0,-6.0,0><0,-6.7,0>0.9}
	#if (typ = 1) //MVCR
	   rotate <0,180,0>
	#end
	}
	difference{
		union{
			box{<-1.905,0,3.7><1.905,11.6,-4.6>}
			cylinder{<-1.905,7.3,4.9><1.905,7.3,4.9>0.3 }
			box{<-1.905,0,3.7><1.905,7.3,5.2>}
			box{<-1.905,7.3,3.7><1.905,7.6,4.9>}
			box{<-1.905,0,-4.6><1.905,2.45,-5.2>}
		}
		box{<-1.95,0,-2.2><1.95,2.0,2.2> rotate <70,0,0> translate <0,9.7,2.9>}
		box{<-0.9,2.7,5.3><0.9,5.5,-4>}
		box{<-1.5,2.5,5.3><1.5,6.6,4>}
	}
	difference{
		union{
			cylinder{<-1.905,12.2,2.7><1.905,12.2,2.7>0.3 }
			cylinder{<-1.905,12.2,-1.65><1.905,12.2,-1.65>0.3 }
			box{<-1.905,11.9,2.7><1.905,12.5,-1.65>}
			cylinder{<-1.905,11.9,-4.9><1.905,11.9,-4.9>0.3 }
			box{<-1.905,11.6,2.1><1.905,12.2,-4.9>}
		}
		cylinder{<0,10.6,0><0,12.6,0>1.4}
	}
	pigment{ForestGreen}
}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_CON_PHOENIX_381_PHNR.inc.src
// //////////
// Macros fuer Phoenix Mini-Combicon 3.81mm Klemmen und Gegenstecker
// Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
// Privat: <fbleikamp@web.de>
// Nummer
#macro CON_PHOENIX_381_PHNR(n)
union{
	box{<-1.905,0,-1.75><1.905,0.1,1.75> pigment{White}}
	box{<-1.89,0,-1.75><-1.905,0.25,1.75> pigment{Gray20}}
	box{<1.905,0,-1.75><1.89,0.25,1.75> pigment{Gray20}}
	#if (n < 10)
		text {ttf besch_font str(n,0,0) 0.2,0  scale<3.5,3.5,3.5> pigment{Gray20} rotate<90,180,0> translate<0.8,0.2,1.2> }
	#else
		text {ttf besch_font str(n,0,0) 0.2,0  scale<3.0,3.5,3.5> pigment{Gray20} rotate<90,180,0> translate<1.5,0.2,1.2> }
	#end
}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_CON_PHOENIX_381_PHPIN.inc.src
// Macros fuer Phoenix Mini-Combicon 3.81mm Klemmen und Gegenstecker
// Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
// Privat: <fbleikamp@web.de>
// Phoenix - Kontakt (gerade)
// //////////
#macro CON_PHOENIX_381_PHPIN()
difference{
	box{<-0.35,-3.5,-0.35><0.35,7.5,0.35>}
	// anspitzen oben
	box{<0,0,-0.7><0.7,0.7,0.7> rotate<0,0,30> translate<0.4,7,0>}
	box{<0,0,-0.7><-0.7,0.7,0.7> rotate<0,0,-30> translate<-0.4,7,0>}
	box{<-0.7,0,0><0.7,0.7,0.7> rotate<-30,0,0> translate<0,7,0.4>}
	box{<-0.7,0,0><0.7,0.7,-0.7> rotate<30,0,0> translate<0,7,-0.4>}
	// anspitzen unten
	box{<0,0,-0.7><0.7,0.7,0.7> rotate<0,0,-30> translate<0.1,-3.5,0>}
	box{<0,0,-0.7><-0.7,0.7,0.7> rotate<0,0,30> translate<-0.1,-3.5,0>}
	box{<-0.7,0,0><0.7,0.7,0.7> rotate<30,0,0> translate<0,-3.5,0.1>}
	box{<-0.7,0,0><0.7,0.7,-0.7> rotate<-30,0,0> translate<0,-3.5,-0.1>}
	texture{col_silver}
}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_CON_PHOENIX_381_PHPINW.inc.src
// Macros fuer Phoenix Mini-Combicon 3.81mm Klemmen und Gegenstecker
// Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
// Privat: <fbleikamp@web.de>
// Phoenix - Kontakt Winkel
// //////////
#macro CON_PHOENIX_381_PHPINW()
difference{
	//#macro RECT_BOGEN(i_radius,winkel,dicke,breite,laenge1,laenge2)
	object {TOOLS_RECT_BOGEN(0.1,90,0.7,0.7,6,7)}
	//laenge1 anspitzen
	box{<0,0,-0.7><0.7,0.7,0.7> rotate<0,0,30> translate<0.4,7,0>}
	box{<0,0,-0.7><-0.7,0.7,0.7> rotate<0,0,-30> translate<-0.4,7,0>}
	box{<-0.7,0,0><0.7,0.7,0.7> rotate<-30,0,0> translate<0,7,0.4>}
	box{<-0.7,0,0><0.7,0.7,-0.7> rotate<30,0,0> translate<0,7,-0.4>}
	//laenge2 anspitzen
	box{<0,0,-0.7><0.7,0.7,0.7> rotate<0,0,-30> translate<6,0.4,0>}
	box{<0,0,-0.7><0.7,-0.7,0.7> rotate<0,0,30> translate<6,-0.4,0>}
	box{<0,-0.7,0><0.7,0.7,0.7> rotate<0,30,0> translate<6,0,0.4>}
	box{<0,-0.7,0><0.7,0.7,-0.7> rotate<0,-30,0> translate<6,0,-0.4>}
	texture{col_silver} rotate<0,0,-90> translate<0,3.0,0>
}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_CON_PHOENIX_381_SCREWHEAD.inc.src
// Macros fuer Phoenix Mini-Combicon 3.81mm Klemmen und Gegenstecker
// Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
// Privat: <fbleikamp@web.de>
// Schraubenkopf
// //////////
#macro CON_PHOENIX_381_SCREWHEAD()
difference{
	superellipsoid{<1,0.1> rotate<90,0,0> scale<1.4,0.5,1.4> translate<0,0,0>}
	box{<0.25,0,-2><-0.25,1,2>rotate<0,30,0> translate<0,0,0>}
	texture{col_silver}
}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_MOLEX254.inc.src
// Tilmann Reh <tilmann.reh@autometer.de>
// Grundmakro: Kunststoffkörper von geraden und abgewinkelten Molex-Stiftleisten RM 2.54.
// Parameter: Anzahl Pins. (-> Breite. Höhe/Tiefe sind konstant für alle Größen.)
// Bezugspunkt: Mitte der Pins in Auflagefläche (gerade Ausführung).
// Kunststoffkörper von geraden und abgewinkelten Molex-Stiftleisten
// //////////
#macro MOLEX254(Pins)
union{
difference{
box{<0,0,-2.5><Pins*2.54,3,3>}
#local i=0; #while (i<Pins) box{<0.77+i*2.54,-0.1,-3><1.77+i*2.54,0.8,4>} #local i=i+1; #end }
box{<1.27,2,-2.5><(Pins-0.5)*2.54,11.3,-1.7>}
box{<1.27,5.8,-2><(Pins-0.5)*2.54,7.5,-1.4>}
translate <-Pins*1.27,0,0> texture {col_Molex}}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_PBL.inc.src
// Pin für Buchsenleiste
// //////////
#macro PBL()
union{

difference{
	box{<0,0,0><0.5,3,0.3> translate<-0.25,-3,-0.15>}
	box{<0,0,-0.5><0.5,0.5,0.5> rotate<0,0,-30> translate<0.1,-3,0>}
	box{<0,0,-0.5><-0.5,0.5,0.5> rotate<0,0,30> translate<-0.1,-3,0>}
	box{<-0.5,0,0><0.5,0.5,0.5> rotate<30,0,0> translate<0,-3,0.05>}
	box{<-0.5,0,0><0.5,0.5,-0.5> rotate<-30,0,0> translate<0,-3,-0.05>}
	texture{col_gold}
}
difference{
	difference{
		box{<-1.27,0,-1.27><1.27,8,1.27>}
		box{<-1.27,-0.1,-1.27><1.27,8.1,1.27> rotate<0,45,0> translate<-1.95,0,-1.95> }
		box{<-1.27,-0.1,-1.27><1.27,8.1,1.27> rotate<0,45,0> translate< 1.95,0,-1.95> }
		box{<-1.27,-0.1,-1.27><1.27,8.1,1.27> rotate<0,45,0> translate<-1.95,0, 1.95> }
		box{<-1.27,-0.1,-1.27><1.27,8.1,1.27> rotate<0,45,0> translate< 1.95,0, 1.95> }
	}
	cylinder{<0,1,0><0,8.1,0>1.0}
}

difference{
	cylinder{<0,7.5,0><0,8.03,0>1.0}
	cylinder{<0,6.9,0><0,8.2,0>0.9}
	texture{col_silver}
}

difference{
	cylinder{<0,0.5,0><0,7.55,0>0.9}
	cylinder{<0,0.4,0><0,7.6,0>0.7}
	texture{col_gold}
}

pigment{Gray30}
finish {ambient (0.1 * global_ambient_mul)}
}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_PFOSTENWANNE.inc.src
// //////////
// Tilmann Reh <tilmann.reh@autometer.de>
// Grundmakro: Kunststoffkörper von Pfostenwannen.
// Verwendung für gerade und abgewinkelte Bauform jeweils in Verbindung mit entspr. Pinreihen.
// Parameter: Breite. (Höhe/Tiefe sind konstant für alle Größen.)
// Bezugspunkt: Mitte der Auflagefläche (gerade Ausführung).
// Kunststoffkörper von Pfostenwannen
#macro PFOSTENWANNE(B)
union{
difference{
box{<-B/2,0.3,-4.2><B/2,9,4.5>}
box{<-B/2+1,2.5,-3.2><B/2-1,10,3.5>}
box{<-2.2,2,2.5><2.2,10,5>}
box{<B/2-1.1,0,-1.75><B/2+0.1,6.5,1.75>}
box{<-B/2+1.1,0,-1.75><-B/2-0.1,6.5,1.75>}}
difference{
box{<B/2-6.08,6,4><B/2-4.08,8,4.6>}
box{<0,0,0><2,3,0.7> rotate<0,0,-30> translate<B/2-5.08,6,4>}
box{<0,0,0><-2,3,0.7> rotate<0,0,30> translate<B/2-5.08,6,4>}}
cylinder{<0,0.3,-4.2><0,8.5,-4.2> 0.3}
sphere{<0,0.3,-3.2> 0.3}
sphere{<0,0.3,3.2> 0.3}
#local xc=7.62;
#while (xc<B/2-1)
cylinder{<xc,0.3,-4.2><xc,8.5,-4.2> 0.3}
cylinder{<-xc,0.3,-4.2><-xc,8.5,-4.2> 0.3}
sphere{<xc,0.3,-3.2> 0.3}
sphere{<xc,0.3,3.2> 0.3}
sphere{<-xc,0.3,-3.2> 0.3}
sphere{<-xc,0.3,3.2> 0.3}
#local xc=xc+7.62;
#end
texture {col_Wannen}}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_PHW2.inc.src
// Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
// Privat: <fbleikamp@web.de>
// Pin für Stiftleisten Winkel obere Reihe
// //////////
#macro PHW2()
union{
//PIN Loetseite
difference{
box{<0,0,0><0.6,5.54,0.6> texture{col_gold} translate<-0.3,0,-0.3>}
box{<0,0,-0.5><0.5,0.5,0.5> texture{col_gold} rotate<0,0,-30> translate<0.1,0,0>}
box{<0,0,-0.5><-0.5,0.5,0.5> texture{col_gold} rotate<0,0,30> translate<-0.1,0,0>}
box{<-0.5,0,0><0.5,0.5,0.5> texture{col_gold} rotate<30,0,0> translate<0,0,0.1>}
box{<-0.5,0,0><0.5,0.5,-0.5> texture{col_gold} rotate<-30,0,0> translate<0,0,-0.1>}
translate<0,-2.22,0>}
//PIN Steckseite
difference{
box{<0,0,0><0.6,11.54,0.6> texture{col_gold} translate<-0.3,0,-0.3>}
box{<0,0,-0.5><0.5,0.5,0.5> texture{col_gold} rotate<0,0,-60> translate<0.1,11.54,0>}
box{<0,0,-0.5><-0.5,0.5,0.5> texture{col_gold} rotate<0,0,60> translate<-0.1,11.54,0>}
box{<-0.5,0,0><0.5,0.5,0.5> texture{col_gold} rotate<60,0,0> translate<0,11.54,0.1>}
box{<-0.5,0,0><0.5,0.5,-0.5> texture{col_gold} rotate<-60,0,0> translate<0,11.54,-0.1>}
rotate<0,0,-90> translate<0.5,3.81,0>}
//PIN Bogen
difference{
box{<0,0,0><0.6,0.4,0.4> texture{col_gold} translate<0,0.0,0.0>}
cylinder{<-0.1,0,0><0.8,0,0>0.2 texture{col_gold} translate<0,0.0,0.0>}
rotate<0,-90,0> translate<0.5,3.31,-0.3>}
difference{
cylinder{<0,0,0><0.6,0,0>0.8 texture{col_gold} translate<0,0,0> }
box{<0,0,0><2,2.2,-2> texture{col_gold} translate<-0.1,0,-0.1>}
box{<0,0,0><2,2.2,-2> texture{col_gold} translate<-0.1,-1.8,0.4>}
rotate<0,-90,0> translate<0.5,3.31,-0.3>}
//Kunststoff
difference{
box{<0,-2,-1.27><2,1.27,1.27> pigment{Gray30} translate<0,0,0>}
box{<-0.5,-1,-1><2.5,1,1> pigment{Gray30} rotate<45,0,0> translate<0,1.76,1.76>}
box{<-0.5,-1,-1><2.5,1,1> pigment{Gray30} rotate<45,0,0> translate<0,1.76,-1.76>}
translate<4.04,3.81,0>}
rotate<0,-90,0>
}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_PHW.inc.src
// Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
// Privat: <fbleikamp@web.de>
// Pin für Stiftleisten Winkel
// //////////
#macro PHW()
union{
//PIN Loetseite
difference{
box{<0,0,0><0.6,3,0.6> texture{col_gold} translate<-0.3,0,-0.3>}
box{<0,0,-0.5><0.5,0.5,0.5> texture{col_gold} rotate<0,0,-30> translate<0.1,0,0>}
box{<0,0,-0.5><-0.5,0.5,0.5> texture{col_gold} rotate<0,0,30> translate<-0.1,0,0>}
box{<-0.5,0,0><0.5,0.5,0.5> texture{col_gold} rotate<30,0,0> translate<0,0,0.1>}
box{<-0.5,0,0><0.5,0.5,-0.5> texture{col_gold} rotate<-30,0,0> translate<0,0,-0.1>}
translate<0,-2.22,0>}
//PIN Steckseite
difference{
box{<0,0,0><0.6,9,0.6> texture{col_gold} translate<-0.3,0,-0.3>}
box{<0,0,-0.5><0.5,0.5,0.5> texture{col_gold} rotate<0,0,-60> translate<0.1,9,0>}
box{<0,0,-0.5><-0.5,0.5,0.5> texture{col_gold} rotate<0,0,60> translate<-0.1,9,0>}
box{<-0.5,0,0><0.5,0.5,0.5> texture{col_gold} rotate<60,0,0> translate<0,9,0.1>}
box{<-0.5,0,0><0.5,0.5,-0.5> texture{col_gold} rotate<-60,0,0> translate<0,9,-0.1>}
rotate<0,0,-90> translate<0.5,1.27,0>}
//PIN Bogen
difference{
box{<0,0,0><0.6,0.4,0.4> texture{col_gold} translate<0,0.0,0.0>}
cylinder{<-0.1,0,0><0.8,0,0>0.2 texture{col_gold} translate<0,0.0,0.0>}
rotate<0,-90,0> translate<0.5,0.77,-0.3>}
difference{
cylinder{<0,0,0><0.6,0,0>0.8 texture{col_gold} translate<0,0,0> }
box{<0,0,0><2,2.2,-2> texture{col_gold} translate<-0.1,0,-0.1>}
box{<0,0,0><2,2.2,-2> texture{col_gold} translate<-0.1,-1.8,0.4>}
rotate<0,-90,0> translate<0.5,0.77,-0.3>}
//Kunststoff
difference{
box{<0,-1.27,-1.27><2,1.27,1.27> pigment{Gray30} translate<0,0,0>}
box{<-0.5,-1,-1><2.5,1,1> pigment{Gray30} rotate<45,0,0> translate<0,1.76,1.76>}
box{<-0.5,-1,-1><2.5,1,1> pigment{Gray30} rotate<45,0,0> translate<0,1.76,-1.76>}
box{<-0.5,-1,-1><2.5,1,1> pigment{Gray30} rotate<45,0,0> translate<0,-1.76,-1.76>}
box{<-0.5,-1,-1><2.5,1,1> pigment{Gray30} rotate<45,0,0> translate<0,-1.76,1.76>}
translate<1.5,1.27,0>}
rotate<0,-90,0>
}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_PIN_BENDED.inc.src
// Tilmann Reh <tilmann.reh@autometer.de>
// Grundmakro: Um 90° gebogener, quadratischer Stift eines Steckverbinders.
// Verwendung für abgewinkelte Pfostenwannen sowie z.B. Wago-Steckerleisten.
// Parameter: Stärke, Biegeradius (Mitte), Höhe über/unter PCB-Oberkante, Länge nach vorn (-Z), Farbe
// //////////
#macro PIN_BENDED(D,R,HO,HU,L,col)
union{
difference{
cylinder{<0,-D/2,0><0,D/2,0> R+D/2}
cylinder{<0,-D,0><0,D,0> R-D/2}
box{<-R-D,-D,-R-D><0,D,R+D>}
box{<-R-D,-D,-R-D><R+D,D,0>}
rotate<0,0,90> translate<0,HO-R,-R>}
difference{
box{<-D/2,-HU,-D/2><D/2,HO-R,D/2>}
box{<0,0,-0.6*D><0.6*D,0.6*D,0.6*D> rotate<0,0,-45> translate<D/4,-HU,0>}
box{<0,0,-0.6*D><-0.6*D,0.6*D,0.6*D> rotate<0,0,45> translate<-D/4,-HU,0>}
box{<-0.6*D,0,0><0.6*D,0.6*D,0.6*D> rotate<45,0,0> translate<0,-HU,D/4>}
box{<-0.6*D,0,0><0.6*D,0.6*D,-0.6*D> rotate<-45,0,0> translate<0,-HU,-D/4>}}
difference{
box{<-D/2,HO-D/2,-L><D/2,HO+D/2,-R>}
box{<0,-0.6*D,0><0.6*D,0.6*D,0.6*D> rotate<0,45,0> translate<D/4,HO,-L>}
box{<0,-0.6*D,0><-0.6*D,0.6*D,0.6*D> rotate<0,-45,0> translate<-D/4,HO,-L>}
box{<-0.6*D,0,0><0.6*D,-0.6*D,-0.6*D> rotate<-45,0,0> translate<0,HO-D/4,-L>}
box{<-0.6*D,0,0><0.6*D,0.6*D,-0.6*D> rotate<45,0,0> translate<0,HO+D/4,-L>}}
texture{col}}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_PIN_STRAIGHT.inc.src
// Tilmann Reh <tilmann.reh@autometer.de>
// Grundmakro: Gerader, quadratischer Stift eines Steckverbinders.
// Verwendung für gerade Pfostenwannen sowie z.B. Wago-Steckerleisten.
// Parameter: Stärke, Höhe über/unter PCB-Oberkante, Farbe
// Gerader, quadratischer Stift eines Steckverbinders
// //////////
#macro PIN_STRAIGHT(D,HO,HU,col)
difference{
box{<-D/2,-HU,-D/2><D/2,HO,D/2>}
box{<-0.6*D,0,0><0.6*D,0.6*D,0.6*D> rotate<45,0,0> translate<0,HO,D/4>}
box{<-0.6*D,0,0><0.6*D,0.6*D,-0.6*D> rotate<-45,0,0> translate<0,HO,-D/4>}
box{<0,0,-0.6*D><0.6*D,0.6*D,0.6*D> rotate<0,0,-45> translate<D/4,HO,0>}
box{<0,0,-0.6*D><-0.6*D,0.6*D,0.6*D> rotate<0,0,45> translate<-D/4,HO,0>}
box{<0,0,-0.6*D><0.6*D,0.6*D,0.6*D> rotate<0,0,-45> translate<D/4,-HU,0>}
box{<0,0,-0.6*D><-0.6*D,0.6*D,0.6*D> rotate<0,0,45> translate<-D/4,-HU,0>}
box{<-0.6*D,0,0><0.6*D,0.6*D,0.6*D> rotate<45,0,0> translate<0,-HU,D/4>}
box{<-0.6*D,0,0><0.6*D,0.6*D,-0.6*D> rotate<-45,0,0> translate<0,-HU,-D/4>}
texture{col}}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./1_SMA_THREADS.inc.src
//Threads for SMA
//Duane Clark <dclark@akamail.com>
// //////////
#macro SMA_THREADS(od,id,pitch,len)
difference
{
  #local ParAMin = id/2;
  #local ParAMax = od/2;
  #local ParBMin = 0;
  #local ParBMax = 2*pi;
  #local ParCMin = 0;
  #local ParCMax = 1;
  #local td = ParAMax-ParAMin; // thread depth
  #local threads = len/pitch;

  union
  {
    #local i = 0;
    #while(i<threads)
      cone{<0,0,i*pitch> id/2 <0,0,(i+0.5)*pitch> od/2}
      cone{<0,0,(i+0.5)*pitch> od/2 <0,0,(i+1)*pitch> id/2}
      #local i = i+1;
    #end
  }

  // trim the left end
  difference
  {
    cylinder{<0,0,-1.1*pitch><0,0,td*0.99> 1.1*od/2}
    cone{<0,0,0> id/2 <0,0,td> id/1.99+td}
  }
  // trim the right end
  difference
  {
    cylinder{<0,0,len-0.99*td><0,0,len+pitch*2> 1.1*od/2}
    cone{<0,0,len-td> id/1.99+td <0,0,len> id/2}
  }
}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./2_PH.inc.src
// Pin für Stiftleisten
// //////////
#macro PH()
union{
object{PIN_STRAIGHT(0.5,9,3,col_gold)}
difference{
box{<0,0,0><2.54,2,2.54> pigment{Gray30} translate<-1.27,0,-1.27>}
box{<0,-0.5,0><1,2.5,1> pigment{Gray30} rotate<0,45,0> translate<0.635,0,1.27>}
box{<0,-0.5,0><1,2.5,1> pigment{Gray30} rotate<0,-45,0> translate<-1.27,0,0.635>}
box{<0,-0.5,0><1,2.5,1> pigment{Gray30} rotate<0,45,0> translate<0.635,0,-1.27>}
box{<0,-0.5,0><1,2.5,1> pigment{Gray30} rotate<0,-135,0> translate<-0.635,0,-1.27>}
box{<-0.635,-0.1,-1.3><0.635,0.5,1.3> pigment{Gray30} rotate<0,0,0> translate<0,0,0>}
box{<-1.3,-0.1,-0.635><1.3,0.5,0.635> pigment{Gray30} rotate<0,0,0> translate<0,0,0>}
}}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./2_PIN_BENDED_ROW.inc.src
// Tilmann Reh <tilmann.reh@autometer.de>
// Grundmakro: Reihe gebogener quadratischer Stifte z.B. für Pfostenwannen oder Wago-Stecker.
// Parameter: Anzahl Pins, Pitch, Stärke, Radius, Höhen über/unter PCB, Länge, Farbe.
// Bezugspunkt: Mitte der Pinreihe.
// Reihe gebogener quadratischer Stifte
// //////////
#macro PIN_BENDED_ROW(Pins,Pitch,D,R,HO,HU,L,col)
union{
#local i=0;
#while(i<Pins) object{PIN_BENDED (D,R,HO,HU,L,col) translate<i*Pitch,0,0>} #local i=i+1; #end
translate<-(Pins-1)*Pitch/2,0,0>}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./2_PIN_STRAIGHT_ROW.inc.src
// //////////
// Tilmann Reh <tilmann.reh@autometer.de>
// Grundmakro: Reihe gerader quadratischer Stifte z.B. für Pfostenwannen oder Wago-Stecker.
// Parameter: Anzahl Pins, Pitch, Stärke, Höhen über/unter PCB, Farbe.
// Bezugspunkt: Mitte der Pinreihe.
// Reihe gerader quadratischer Stifte
#macro PIN_STRAIGHT_ROW(Pins,Pitch,D,HO,HU,col)
union{
#local i=0;
#while(i<Pins) object{PIN_STRAIGHT (D,HO,HU,col) translate<i*Pitch,0,0>} #local i=i+1; #end
translate<-(Pins-1)*Pitch/2,0,0>}
#end


// ////////////////////////////////////////////////////////////
// Original file: ./2_SMA_JACK.inc.src
// SMA
// Duane Clark <dclark@akamail.com>
// //////////
#macro SMA_JACK(l)
union
{
  difference
  {
    union
    {
      object{SMA_THREADS(6.35,5.38,0.71,3.56)
        rotate<0,0,-90>
        translate<0,0,0.76>
      }
      cylinder{<0,0,0> <0,0,l> 2.69 }
    }
    cylinder{<0,0,-0.1> <0,0,l+0.1> 2.3 }
  }
  difference
  {
    cylinder{<0,0,1.93> <0,0,4> 2.3 pigment{White}}
    cylinder{<0,0,1.9> <0,0,3.9> 0.92 pigment{White}}
  }
  difference
  {
    cylinder{<0,0,1.95> <0,0,3.6> 0.90}
    cylinder{<0,0,1.9> <0,0,3.5> 0.70}
  }
  texture{col_gold}
}
#end
/********************************************************************************************************************************************
//AK-700 Klemme ohne Mittelanschluss RM 5.0 Uwe Lorenz <u.lorenz@er-dresden.net>
********************************************************************************************************************************************/
#macro CON_AK700_3_5_GRND()
union{
//***** Lötstift
cylinder{<-5,-4,0><-5,1.1,0>0.6 texture{col_silver}}
cylinder{<5,-4,0><5,1.1,0>0.6 texture{col_silver}}
//***** Ende Lötstifte
//
//***** Grundkörper
difference{
box{<-7.5,0,-5><7.5,19,5>}
//*****mittlerer Anschluß
box{<-2,3.9,-5.01><2,9.5,3.5>}
//*****linker Anschluß
box{<-6.5,3.9,-5.01><-2.5,9.5,3.5>}
//*****rechter Anschluß
box{<2.5,3.9,-5.01><6.5,9.5,3.5>}
//***** vordere Schräge
box{<-7.6,9,-6.0><7.6,25,-1.1> rotate<20,0,0> translate<0,0,-8.7>}
//box{<-7.6,12,-5.1><7.6,12.5,-4.6>}
//***** hintere Kante
box{<-7.6,10,3><7.6,19.1,5.1> }
//***** Aussparungen hinten
box{<-1.4,6,3.4><1.4,10.1,5.1> }
box{<-6.2,6,3.4><-3.1,10.1,5.1> }
box{<3.1,6,3.4><6.2,10.1,5.1> }
//***** mittleres Borhloch
cylinder{<0,15.9,0><0,19.1,0>1.8}
//cone{<0,18,0>1.5<0,19.1,0>1.8}
//***** linkes Borhloch
cylinder{<-5,15.9,0><-5,19.1,0>1.8}
//cone{<-5,18,0>1.5<-5,19.1,0>1.8}
//***** rechtes Borhloch
cylinder{<5,15.9,0><5,19.1,0>1.8}
//cone{<5,18,0>1.5<5,19.1,0>1.8}
//***** Nut an der rechten Seite
box{<7.0,0.0,-3.4><7.6,13.0,-4.0> }
}
//***** Ende Grundkörper
//
//***** Steg an der linken Seite
box{<-7.4,1.0,-3.4><-8.0,13.0,-4.0> }
//***** Silberfahnen hinten
box{<-6.0,6,3.8><-3.4,9.1,4.5> texture{col_silver} }
box{<3.4,6,3.8><6.0,9.1,4.5> texture{col_silver} }
//Silberknubbeln an den Silberfahnen
box{<-5.4,6.3,3.8><-4.0,7.3,4.8> texture{col_silver} }
box{<4.0,6.3,3.8><5.4,7.3,4.8> texture{col_silver} }
//***** Ende hintere Silberfahnen
//
//***** rechter Schraubenkopf
difference{
superellipsoid{<1,0.1> rotate<90,0,0> scale<1.5,0.5,1.5> texture{col_silver} translate<-5,18.2,0>}
box{<0.25,0,-2><-0.25,1,2>rotate<0,30,0> texture{col_silver} translate<-5,18.2,0>}}
//***** linker Schraubenkopf
difference{
superellipsoid{<1,0.1> rotate<90,0,0> scale<1.5,0.5,1.5> texture{col_silver} translate<5,18.2,0>}
box{<0.25,0,-2><-0.25,1,2>rotate<0,30,0> texture{col_silver} translate<5,18.2,0>}}
//***** Ende Schraubenköpfe
//
//***** linke Zugbügelklemme
difference{
box{<-6.4,4.1,-3.5><-2.6,9.4,2.5>}
box{<-6.2,4.2,-3.6><-2.8,9.4,2.6>}
texture{col_silver}}
cylinder{<-5.8,9.0,-3.3><-3.1,9.0,-3.3>1.0 texture{col_silver}}
//***** rechte Zugbügelklemme
difference{
box{<2.6,4.1,-3.5><6.4,9.4,2.5>}
box{<2.8,4.2,-3.6><6.2,9.4,2.6>}
texture{col_silver}}
cylinder{<3.2,9.0,-3.3><5.8,9.0,-3.3>1.0 texture{col_silver}}
//***** Ende Zugbügelklemme
//
pigment{LimeGreen} translate<0,0.2,0>}
#end

#macro CON_AK700_3_5()
CON_AK700_3_5_GRND()
#end


/********************************************************************************************************************************************
//Macro fuer WAGO Leiterplattenklemme Serie 233, con-wago.lib,    Joerg Bredendiek <sprut(replace with at)sprut.de>
//
//  WAGO 233-1xx        Rastermass 2.50 mm, grau
//  WAGO 233-2xx        Rastermass 2.50 mm, grau    Klemmhebel
//  WAGO 233-4xx        Rastermass 2.54 mm, orange
//  WAGO 233-5xx        Rastermass 2.54 mm, orange  Klemmhebel
//
// Nullpunkt:
//      mittig zwischen den Pins
//
// a = Anzahl der Reihen
********************************************************************************************************************************************/
#macro CON_AMPMT_S_GRND(n) 


union {
  #local L = n * 2.54;
  #local l = 5.715;
  #local h = 2.54;
   difference {
   union {
        box {<-L/2,0,-l/2><L/2,h,-l/2+l/8>} 
        box {<-L/2,0,-l/2><L/2,3*h,-l/2+l/8> translate <0,0,l-l/8> }   
        box {<-L/2,h/4,-l/2+l/8><L/2,h,l/2-l/8>} 
        cylinder{<-L/2,9*h/4,l/2-l/8><L/2,9*h/4,l/2-l/8> l/8 }
        pigment{Gray80} }   
        #local hueco=
        box {<-0.3175,0,-l><0.3175,0.635,l> pigment {Gray80}}
        #local i = 0;
        #while(i<n)
                object{hueco translate< -(n-1)*2.54/2+i*2.54, 0, 0>}
        #local i = i + 1;
        #end   
        cylinder {<-L,h,l/2-l/8><L,h,l/2-l/8> l/10 }
        
        }
  #local pin =  
  intersection {
    box{<-0.3175, -3.556 , -0.3175 > <0.3175, 9.033, 0.3175 >  }
    cone{<0,-3.556,0>, 0.5,<0,10.033,0>, 0.2 }    
    cone{<0,10.033,0>, 0.5,<0,-3.556,0>, 0.2 } 
    texture{col_gold}     }
 #local i = 0;
  #while(i<n)
    object{pin translate< -(n-1)*2.54/2+i*2.54, 0.556*l, 0>}
  #local i = i + 1;
  #end   
  } 
#end 
#macro CON_AMPMT_S_2(value) 
CON_AMPMT_S_GRND(2)
#end
#macro CON_AMPMT_S_3(value)
CON_AMPMT_S_GRND(3)
#end
#macro CON_AMPMT_S_4(value)
CON_AMPMT_S_GRND(4)
#end
#macro CON_AMPMT_S_5(value) 
CON_AMPMT_S_GRND(5)
#end
#macro CON_AMPMT_S_6(value) 
CON_AMPMT_S_GRND(6)
#end
#macro CON_AMPMT_S_7(value) 
CON_AMPMT_S_GRND(7)
#end
#macro CON_AMPMT_S_8(value) 
CON_AMPMT_S_GRND(8)
#end
#macro CON_AMPMT_S_9(value) 
CON_AMPMT_S_GRND(9)
#end
#macro CON_AMPMT_S_10(value) 
CON_AMPMT_S_GRND(10)
#end
#macro CON_AMPMT_S_12(value) 
CON_AMPMT_S_GRND(12)
#end


/********************************************************************************************************************************************
//Macros for HE14 serie Right-Angle Single-Row
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)numericable.fr>
//Rev. 1.0  09/02/08
********************************************************************************************************************************************/
#macro CON_AMP_HE14_1R_GRND(Pins)
union{
object{AMP_HE14_1S(Pins) rotate<90,180,0> translate<0,2.54,-1.2>}
object{PIN_BENDED_ROW (Pins,2.54,0.63,0.8,2.5,3,12.5,col_silver) translate<0,0,0>}}
rotate 180*y
#end

#macro CON_AMP_HE14_1R_02()
CON_AMP_HE14_1R_GRND(2)
#end
#macro CON_AMP_HE14_1R_03()
CON_AMP_HE14_1R_GRND(3)
#end
#macro CON_AMP_HE14_1R_04()
CON_AMP_HE14_1R_GRND(4)
#end
#macro CON_AMP_HE14_1R_05()
CON_AMP_HE14_1R_GRND(5)
#end
#macro CON_AMP_HE14_1R_06()
CON_AMP_HE14_1R_GRND(6)
#end
#macro CON_AMP_HE14_1R_07()
CON_AMP_HE14_1R_GRND(7)
#end
#macro CON_AMP_HE14_1R_08()
CON_AMP_HE14_1R_GRND(8)
#end
#macro CON_AMP_HE14_1R_09()
CON_AMP_HE14_1R_GRND(9)
#end
#macro CON_AMP_HE14_1R_10()
CON_AMP_HE14_1R_GRND(10)
#end


/********************************************************************************************************************************************
//Macros for HE14 serie Right-Angle Single-Row
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)numericable.fr>
//Rev. 1.0  09/02/08
********************************************************************************************************************************************/
#macro CON_AMP_HE14_1S_GRND(Pins)
union{
object{AMP_HE14_1S(Pins)}
object{PIN_STRAIGHT_ROW (Pins,2.54,0.635,11,3,col_silver)}}
#end

#macro CON_AMP_HE14__1S_02()
CON_AMP_HE14_1S_GRND(2)
#end
#macro CON_AMP_HE14__1S_03()
CON_AMP_HE14_1S_GRND(3)
#end
#macro CON_AMP_HE14__1S_04()
CON_AMP_HE14_1S_GRND(4)
#end
#macro CON_AMP_HE14__1S_05()
CON_AMP_HE14_1S_GRND(5)
#end
#macro CON_AMP_HE14__1S_06()
CON_AMP_HE14_1S_GRND(6)
#end
#macro CON_AMP_HE14__1S_07()
CON_AMP_HE14_1S_GRND(7)
#end
#macro CON_AMP_HE14__1S_08()
CON_AMP_HE14_1S_GRND(8)
#end
#macro CON_AMP_HE14__1S_09()
CON_AMP_HE14_1S_GRND(9)
#end
#macro CON_AMP_HE14__1S_10()
CON_AMP_HE14_1S_GRND(10)
#end


/********************************************************************************************************************************************
//Grundmakro für Anreiklemme 3,50mm; Modified by Carsten Kögler, FTZ-Leipzig <koegler@ftz-leipzig.de>
********************************************************************************************************************************************/
#macro CON_ARK_350MM_GRND(j)
// Makro für einpolige Reihenklemme -> siehe ARK_350MM_GRND
// Based on Macro "ARK_PIN", Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
// Modified by Carsten Kögler, FTZ-Leipzig <koegler@ftz-leipzig.de>
// Vorlage: RIA Anschlussklemme AKL 059-xx
#macro ARK_PIN_350MM()
union{

// Einlötstift
	cylinder{<0,-3.0,0><0,1.0,0>0.45 texture{col_silver}}
	cone{<0,-3.0,0>0.45<0,-3.4,0>0.1 texture{col_silver}}

// Plastikkörper
	difference{
		box{<-1.75,0,-3.7><1.75,8.2,2.8>}               // Hauptbox
		box{<-1.4 ,0.6,-4><1.4 ,5.1,2.2>}               // Loch für Drahteinführung
		box{<-0.75,-0.1,-4.01><0.75,1.1,1>}             // Schlitz in der unteren Mitte
		box{<-1.5 ,-0.1,-1.5><1.5,0.7,1.5> rotate<0,45,0> translate<0,0,-4.8>}         // Schlitz etwas abrunden
                box{<-2.6,5,0><2.6,0,-3> rotate<30,0,0> translate<0,4.6,-4>}      // Klemme vorne oben abschrägen
		cylinder{<0,5.2,0><0,10,0>1.5}                  // Senkrechte Löcher für die Schraube - oben etwas weiter
		cylinder{<0,2.2,0><0,5.2,0>1.1}                 //                                    - unten kleiner

	}

// Abgeschrägten Innenteil hinzufügen (siehe Datenblatt)
	box{<-1.4 , 4.6,-1.9><1.4,5.1,2.8>}
        difference{
        	box{<-1.4 , -0.25,-0.25><1.4,0.25,0.25>}
          	box{<-1.5 , -0.35,-0.35><1.5,0.35,0.35>rotate<45,0,0> translate<0,-0.25,-0.25>}
                translate<0,4.85,-2.15>
        }

// Schraube
	superellipsoid{<1,0.1> rotate<90,0,0> scale<0.9,2.0,1> texture{col_silver} translate<0,5.0,0>}
	difference{
		superellipsoid{<1,0.1> rotate<90,0,0> scale<1.3,0.5,1.3> texture{col_silver} translate<0,7.3,0>}
		box{<0.25,0,-2><-0.25,1,2>rotate<0,rand(global_seed)*180,0> translate<0,7.6,0>}
	}

// metallenes Innenleben
	difference{
		box{<-1.35,0.65,-1.9><1.35,4.4,2.5>}   // Hauptkörper
		cylinder{<0,2.2,-2.0><0,2.2,2.6>1.1}    // Loch
		cylinder{<0,2.2,0><0,5.2,0>1.1}
		texture{col_silver}
	}

// Drahtschutz
	box{<-0.95,4.45,-2.0><0.95,4.5,2.5>texture{col_silver}}    // oberer Teil
        difference{                                                // oberer Bogen
                cylinder {<-0.95,-0.1 ,0>,< 0.95,-0.1 ,0>,0.1 }
                cylinder {<-1.0 ,-0.1 ,0>,< 1.0 ,-0.1 ,0>,0.05}
                box{<-1,-1.0,-2><1,-0.1,2>}
                box{<-1,-1.0,0><1, 1.0,1>}
                texture{col_silver}
                rotate<0,0,0>
                translate<0,4.5,-2.0 >
        }
	box{<-0.95,2.2,-2.1><0.95,4.4,-2.05>texture{col_silver}}   // vorderer Teil
        difference{                                                // unterer Bogen
                cylinder {<-0.95,-0.1 ,0>,< 0.95,-0.1 ,0>,0.1 }
                cylinder {<-1.0 ,-0.1 ,0>,< 1.0 ,-0.1 ,0>,0.05}
                box{<-1,-1.0,-2><1,-0.1,2>}
                box{<-1,-1.0,0><1, 1.0,1>}
                texture{col_silver}
                rotate<0,0,180>
                translate<0,2.1,-2.0 >
        }
	box{<-0.95,2.1,-2.0><0.95,2.15,2>texture{col_silver}}    // unterer Teil



	pigment{Gray30}
}
#end

union{
	#local i = 0;
	#while(i<j)
		object{ARK_PIN_350MM() translate<i*3.5,0,0>}
		#local i=i+1;
	#end

	union{
		#local i = 0;
		#while(i<j)
			text {ttf besch_font str(j-i,0,0) 0.2,0  scale<2,2,2> rotate<30,0,0> translate<-i*3.5-1.27,6.1,-3> translate<0,0.3,0.1> pigment{Black}}
			#local i=i+1;
		#end
		translate<(i-1)*3.5,0,0>
	}
	translate<-j*1.75+1.75,0,0>
}
#end

#macro CON_ARK_350MM_2()
CON_ARK_350MM_GRND(2)
#end
#macro CON_ARK_350MM_3()
CON_ARK_350MM_GRND(3)
#end
#macro CON_ARK_350MM_4()
CON_ARK_350MM_GRND(4)
#end
#macro CON_ARK_350MM_5()
CON_ARK_350MM_GRND(5)
#end
#macro CON_ARK_350MM_6()
CON_ARK_350MM_GRND(6)
#end
#macro CON_ARK_350MM_7()
CON_ARK_350MM_GRND(7)
#end
#macro CON_ARK_350MM_8()
CON_ARK_350MM_GRND(8)
#end
#macro CON_ARK_350MM_9()
CON_ARK_350MM_GRND(9)
#end
#macro CON_ARK_350MM_10()
CON_ARK_350MM_GRND(10)
#end
#macro CON_ARK_350MM_11()
CON_ARK_350MM_GRND(11)
#end
#macro CON_ARK_350MM_12()
CON_ARK_350MM_GRND(12)
#end


/********************************************************************************************************************************************
//Grundmakro für Anreiklemme 5mm
********************************************************************************************************************************************/
#macro CON_ARK_5MM_GRND(j)
union{
	#local i = 0;
	#while(i<j)
		object{ARK_PIN() translate<i*5.08,0,0>}
		#local i=i+1;
	#end

	union{
		#local i = 0;
		#while(i<j)
			text {ttf besch_font str(j-i,0,0) 0.2,0  scale<3,3,3> rotate<30,0,0> translate<-i*5.08-1.27,7.21,-4> translate<0,0.3,0.1> pigment{Black}}
			#local i=i+1;
		#end
		translate<(i-1)*5.08,0,0>
	}
	translate<-j*2.54+2.54,0,0>
}
#end
#macro CON_ARK_5MM_2()
CON_ARK_5MM_GRND(2)
#end
#macro CON_ARK_5MM_3()
CON_ARK_5MM_GRND(3)
#end
#macro CON_ARK_5MM_4()
CON_ARK_5MM_GRND(4)
#end
#macro CON_ARK_5MM_5()
CON_ARK_5MM_GRND(5)
#end
#macro CON_ARK_5MM_6()
CON_ARK_5MM_GRND(6)
#end
#macro CON_ARK_5MM_7()
CON_ARK_5MM_GRND(7)
#end
#macro CON_ARK_5MM_8()
CON_ARK_5MM_GRND(8)
#end
#macro CON_ARK_5MM_9()
CON_ARK_5MM_GRND(9)
#end
#macro CON_ARK_5MM_10()
CON_ARK_5MM_GRND(10)
#end
#macro CON_ARK_5MM_11()
CON_ARK_5MM_GRND(11)
#end
#macro CON_ARK_5MM_12()
CON_ARK_5MM_GRND(12)
#end


/********************************************************************************************************************************************
//Grundmakro fuer Buchsenleisten abgewinkelt ,     con-lsta.lib,    Joerg Bredendiek <sprut(replace with at)sprut.de>   
// 2.54mm  Pinabstand
//
// pin = pins pro Reihe
// row = Reihen (1 oder 2)
********************************************************************************************************************************************/
#macro CON_BLW_GRND(pin,row)
//Pin fuer 1- & 2-reihige Buchsenleiste abgewinkelt obere Reihe  ,     con-lsta.lib,    Joerg Bredendiek <sprut(replace with at)sprut.de>  
// 
// a=0 untere Reihe
// a=1 obere  Reihe
#macro CON_BLW_PIN(a)
#local ii = a*2.54;
union{
union{
	//PIN Loetseite 4mm, etwas angespitzt
	difference{
		box{<0,0,0><0.4,4.1+ii,0.4> texture{col_silver} translate<-0.2,0,-0.2>}
		box{<0,0,-0.5><0.5,0.5,0.5> texture{col_silver} rotate<0,0,-30> translate<0.1,0,0>}
		box{<0,0,-0.5><-0.5,0.5,0.5> texture{col_silver} rotate<0,0,30> translate<-0.1,0,0>}
		box{<-0.5,0,0><0.5,0.5,0.5> texture{col_silver} rotate<30,0,0> translate<0,0,0.1>}
		box{<-0.5,0,0><0.5,0.5,-0.5> texture{col_silver} rotate<-30,0,0> translate<0,0,-0.1>}
		translate<0,-3.22,0>
	}
	//PIN vom Bogen zum Plastik
	#if(ii>0)
		box{<0,0,0><0.4,5,0.4> texture{col_silver} translate<-0.2,0,-0.2> rotate<0,0,-90> translate<0.4,3.81,0> }
	#end

	//PIN Bogen 
	//innenkurve
	difference{
		box{<0,0,0><0.4,0.4,0.4> texture{col_silver} translate<0,0.0,0.0>}
		cylinder{<-0.1,0,0><0.8,0,0>0.2 texture{col_silver} translate<0,0.0,0.0>}
		rotate<0,-90,0> translate<0.5,0.77+ii,-0.2>
		translate<-0.1,0.1,0> 
	}
	//aussenkurve
	difference{
		cylinder{<0,0,0><0.4,0,0>0.6 texture{col_silver} translate<0,0,0> }
		box{<0,0,0><2,2.2,-2> texture{col_silver} translate<-0.1,0,-0.1>}
		box{<0,0,0><2,2.2,-2> texture{col_silver} translate<-0.1,-1.8,0.4>}
		rotate<0,-90,0> translate<0.5,0.77+ii,-0.2>
		translate<-0.1,0.1,0> 
	} 
	rotate<0,-90,0>
}
union{
	//schwarzes plastik mit loch 8mm lang   
	// wird vertikal gebaut                        
	difference{
		difference{
			box{<-1.27,0,-1.27><1.27,8,1.27>}
			box{<-1.27,-0.1,-1.27><1.27,8.1,1.27> rotate<0,45,0> translate<-1.95,0,-1.95> }
			box{<-1.27,-0.1,-1.27><1.27,8.1,1.27> rotate<0,45,0> translate< 1.95,0,-1.95> }
			box{<-1.27,-0.1,-1.27><1.27,8.1,1.27> rotate<0,45,0> translate<-1.95,0, 1.95> }
			box{<-1.27,-0.1,-1.27><1.27,8.1,1.27> rotate<0,45,0> translate< 1.95,0, 1.95> }
		}
		cylinder{<0,1,0><0,8.1,0>1.0}
	}
	//rundes buchsenloch versilbert
	difference{
		cylinder{<0,7.5,0><0,8.03,0>1.0}
		cylinder{<0,6.9,0><0,8.2,0>0.9}	
		texture{col_silver}
	}
	//vergoldeter Kontakt im siblernen Buchsenloch
	difference{
		cylinder{<0,0.5,0><0,7.55,0>0.9}
		cylinder{<0,0.4,0><0,7.6,0>0.7}	
		texture{col_gold}
	}
	pigment{Gray30}
	rotate<90,0,0>		//in die horizontale drehen
	translate<0,1.27,0>	//auf die platine legen

	#if(ii>0)
		translate<0,2.54,2.54>	//in 2. ebene und um 1 Raster noch von schieben
	#end
}
}
#end

union{
	#local i=0;
	#while(i<pin)
		object{CON_BLW_PIN(0) translate<i*2.54,0,0>}
		#local i=i+1;
	#end
	#if(row=2)
		#local i=0;
		#while(i<pin)
			object{CON_BLW_PIN(1) translate<i*2.54,0,-2.54>}
			#local i=i+1;
		#end
		translate<0,0,1.27>
	#end
	translate<pin*-1.27+1.27,0,0>}
#end



#macro CON_BLW_1X2()
CON_BLW_GRND(2,1)
#end
#macro CON_BLW_1X5()
CON_BLW_GRND(5,1)
#end
#macro CON_BLW_1X6()
CON_BLW_GRND(6,1)
#end
#macro CON_BLW_1X7()
CON_BLW_GRND(7,1)
#end
#macro CON_BLW_1X8()
CON_BLW_GRND(8,1)
#end
#macro CON_BLW_1X9()
CON_BLW_GRND(9,1)
#end
#macro CON_BLW_1X10()
CON_BLW_GRND(10,1)
#end
#macro CON_BLW_1X12()
CON_BLW_GRND(12,1)
#end
#macro CON_BLW_1X13()
CON_BLW_GRND(13,1)
#end
#macro CON_BLW_1X15()
CON_BLW_GRND(15,1)
#end
#macro CON_BLW_1X17()
CON_BLW_GRND(17,1)
#end
#macro CON_BLW_1X18()
CON_BLW_GRND(18,1)
#end
#macro CON_BLW_1X20()
CON_BLW_GRND(20,1)
#end
#macro CON_BLW_2X5()
CON_BLW_GRND(5,2)
#end
#macro CON_BLW_2X6()
CON_BLW_GRND(6,2)
#end
#macro CON_BLW_2X7()
CON_BLW_GRND(7,2)
#end
#macro CON_BLW_2X8()
CON_BLW_GRND(8,2)
#end
#macro CON_BLW_2X9()
CON_BLW_GRND(9,2)
#end
#macro CON_BLW_2X10()
CON_BLW_GRND(10,2)
#end
#macro CON_BLW_2X12()
CON_BLW_GRND(12,2)
#end
#macro CON_BLW_2X13()
CON_BLW_GRND(13,2)
#end
#macro CON_BLW_2X15()
CON_BLW_GRND(15,2)
#end
#macro CON_BLW_2X17()
CON_BLW_GRND(17,2)
#end
#macro CON_BLW_2X18()
CON_BLW_GRND(18,2)
#end
#macro CON_BLW_2X20()
CON_BLW_GRND(20,2)
#end


/********************************************************************************************************************************************
//Grundmakro für Buchsenleisten (flach)
********************************************************************************************************************************************/
#macro CON_BL_F_GRND(pin,row)
union{
#local i=0;
#while(i<pin)
object{CON_PBL_F() translate<i*2.54,0,0>}
#local i=i+1;
#end
#if(row=2)
#local i=0;
#while(i<pin)
object{CON_PBL_F() translate<i*2.54,0,-2.54>}
#local i=i+1;
#end
translate<0,0,1.27>
#end
translate<pin*-1.27+1.27,0,0>}
#end
#macro CON_BL_F_1X5()
CON_BL_F_GRND(5,1)
#end
#macro CON_BL_F_1X6()
CON_BL_F_GRND(6,1)
#end
#macro CON_BL_F_1X7()
CON_BL_F_GRND(7,1)
#end
#macro CON_BL_F_1X8()
CON_BL_F_GRND(8,1)
#end
#macro CON_BL_F_1X9()
CON_BL_F_GRND(9,1)
#end
#macro CON_BL_F_1X10()
CON_BL_F_GRND(10,1)
#end
#macro CON_BL_F_1X12()
CON_BL_F_GRND(12,1)
#end
#macro CON_BL_F_1X13()
CON_BL_F_GRND(13,1)
#end
#macro CON_BL_F_1X15()
CON_BL_F_GRND(15,1)
#end
#macro CON_BL_F_1X17()
CON_BL_F_GRND(17,1)
#end
#macro CON_BL_F_1X18()
CON_BL_F_GRND(18,1)
#end
#macro CON_BL_F_1X20()
CON_BL_F_GRND(20,1)
#end
#macro CON_BL_F_2X5()
CON_BL_F_GRND(5,2)
#end
#macro CON_BL_F_2X6()
CON_BL_F_GRND(6,2)
#end
#macro CON_BL_F_2X7()
CON_BL_F_GRND(7,2)
#end
#macro CON_BL_F_2X8()
CON_BL_F_GRND(8,2)
#end
#macro CON_BL_F_2X9()
CON_BL_F_GRND(9,2)
#end
#macro CON_BL_F_2X10()
CON_BL_F_GRND(10,2)
#end
#macro CON_BL_F_2X12()
CON_BL_F_GRND(12,2)
#end
#macro CON_BL_F_2X13()
CON_BL_F_GRND(13,2)
#end
#macro CON_BL_F_2X15()
CON_BL_F_GRND(15,2)
#end
#macro CON_BL_F_2X17()
CON_BL_F_GRND(17,2)
#end
#macro CON_BL_F_2X18()
CON_BL_F_GRND(18,2)
#end
#macro CON_BL_F_2X20()
CON_BL_F_GRND(20,2)
#end


/********************************************************************************************************************************************
//Grundmakro für Buchsenleisten
********************************************************************************************************************************************/
#macro CON_BL_GRND(pin,row)
union{
#local i=0;
#while(i<pin)
object{PBL() translate<i*2.54,0,0>}
#local i=i+1;
#end
#if(row=2)
#local i=0;
#while(i<pin)
object{PBL() translate<i*2.54,0,-2.54>}
#local i=i+1;
#end
translate<0,0,1.27>
#end
translate<pin*-1.27+1.27,0,0>}
#end
#macro CON_BL_1X5()
CON_BL_GRND(5,1)
#end
#macro CON_BL_1X6()
CON_BL_GRND(6,1)
#end
#macro CON_BL_1X7()
CON_BL_GRND(7,1)
#end
#macro CON_BL_1X8()
CON_BL_GRND(8,1)
#end
#macro CON_BL_1X9()
CON_BL_GRND(9,1)
#end
#macro CON_BL_1X10()
CON_BL_GRND(10,1)
#end
#macro CON_BL_1X12()
CON_BL_GRND(12,1)
#end
#macro CON_BL_1X13()
CON_BL_GRND(13,1)
#end
#macro CON_BL_1X15()
CON_BL_GRND(15,1)
#end
#macro CON_BL_1X17()
CON_BL_GRND(17,1)
#end
#macro CON_BL_1X18()
CON_BL_GRND(18,1)
#end
#macro CON_BL_1X20()
CON_BL_GRND(20,1)
#end
#macro CON_BL_2X5()
CON_BL_GRND(5,2)
#end
#macro CON_BL_2X6()
CON_BL_GRND(6,2)
#end
#macro CON_BL_2X7()
CON_BL_GRND(7,2)
#end
#macro CON_BL_2X8()
CON_BL_GRND(8,2)
#end
#macro CON_BL_2X9()
CON_BL_GRND(9,2)
#end
#macro CON_BL_2X10()
CON_BL_GRND(10,2)
#end
#macro CON_BL_2X12()
CON_BL_GRND(12,2)
#end
#macro CON_BL_2X13()
CON_BL_GRND(13,2)
#end
#macro CON_BL_2X15()
CON_BL_GRND(15,2)
#end
#macro CON_BL_2X17()
CON_BL_GRND(17,2)
#end
#macro CON_BL_2X18()
CON_BL_GRND(18,2)
#end
#macro CON_BL_2X20()
CON_BL_GRND(20,2)
#end


/********************************************************************************************************************************************
//Macro fuer Präzisions Buchsenleisten
//franz.riedmueller@web.de
********************************************************************************************************************************************/
#macro CON_BL_PRECISION_GRND(pin,row)
//Single Pin
#macro CON_BL_PRECISION_PIN()
union{
  difference{
             box{<0,0,0><2.54,2,2.54> pigment{Gray10} translate<-1.27,0,-1.27>}
             box{<0,-0.5,0><1,2.5,1> pigment{Gray10} rotate<0,45,0> translate<0.635,0,1.27>}
             box{<0,-0.5,0><1,2.5,1> pigment{Gray10} rotate<0,-45,0> translate<-1.27,0,0.635>}
             box{<0,-0.5,0><1,2.5,1> pigment{Gray10} rotate<0,45,0> translate<0.635,0,-1.27>}
             box{<0,-0.5,0><1,2.5,1> pigment{Gray10} rotate<0,-135,0> translate<-0.635,0,-1.27>} 
             cylinder{<0,-0.5,0> <0,2.5,0> 0.7 pigment{Gray10} finish {ambient (0.1 * global_ambient_mul)}}
  translate<0,5.10,0>
  }
  
 difference{
  union{
        cylinder{<0,0,0><0,2.95,0>0.25}
        sphere{<0,0,0>0.25}
        cone{<0,2.95,0>0.25<0,3.45,0>0.6}
        cylinder{<0,3.45,0><0,7.15,0>0.6}
        cylinder{<0,6.4,0><0,7.15,0>0.85}}
        cylinder{<0,4,0><0,7.16,0>0.5}
        texture{col_silver}
  }
  translate<0,-2.95,0>
 } 
#end

union{
	#local i=0;
	#while(i<pin)
		object{CON_BL_PRECISION_PIN() translate<i*2.54,0,0>}
		#local i=i+1;
	#end
	
	#if(row=2)
		#local i=0;
		#while(i<pin)
			object{CON_BL_PRECISION_PIN() translate<i*2.54,0,-2.54>}
		#local i=i+1;
		#end
		translate<0,0,1.27>
	#end
	translate<pin*-1.27+1.27,0,0>}
#end

#macro CON_BL_PRECISION_1X1()
CON_BL_PRECISION_GRND(1,1)
#end
#macro CON_BL_PRECISION_1X2()
CON_BL_PRECISION_GRND(2,1)
#end
#macro CON_BL_PRECISION_1X3()
CON_BL_PRECISION_GRND(3,1)
#end
#macro CON_BL_PRECISION_1X4()
CON_BL_PRECISION_GRND(4,1)
#end
#macro CON_BL_PRECISION_1X5()
CON_BL_PRECISION_GRND(5,1)
#end
#macro CON_BL_PRECISION_1X6()
CON_BL_PRECISION_GRND(6,1)
#end
#macro CON_BL_PRECISION_1X7()
CON_BL_PRECISION_GRND(7,1)
#end
#macro CON_BL_PRECISION_1X8()
CON_BL_PRECISION_GRND(8,1)
#end
#macro CON_BL_PRECISION_1X9()
CON_BL_PRECISION_GRND(9,1)
#end
#macro CON_BL_PRECISION_1X10()
CON_BL_PRECISION_GRND(10,1)
#end
#macro CON_BL_PRECISION_1X11()
CON_BL_PRECISION_GRND(11,1)
#end
#macro CON_BL_PRECISION_1X12()
CON_BL_PRECISION_GRND(12,1)
#end
#macro CON_BL_PRECISION_1X13()
CON_BL_PRECISION_GRND(13,1)
#end
#macro CON_BL_PRECISION_2X2()
CON_BL_PRECISION_GRND(2,2)
#end
#macro CON_BL_PRECISION_2X3()
CON_BL_PRECISION_GRND(3,2)
#end
#macro CON_BL_PRECISION_2X4()
CON_BL_PRECISION_GRND(4,2)
#end
#macro CON_BL_PRECISION_2X5()
CON_BL_PRECISION_GRND(5,2)
#end
#macro CON_BL_PRECISION_2X6()
CON_BL_PRECISION_GRND(6,2)
#end
#macro CON_BL_PRECISION_2X7()
CON_BL_PRECISION_GRND(7,2)
#end
#macro CON_BL_PRECISION_2X8()
CON_BL_PRECISION_GRND(8,2)
#end
#macro CON_BL_PRECISION_2X9()
CON_BL_PRECISION_GRND(9,2)
#end
#macro CON_BL_PRECISION_2X10()
CON_BL_PRECISION_GRND(10,2)
#end
#macro CON_BL_PRECISION_2X11()
CON_BL_PRECISION_GRND(11,2)
#end
#macro CON_BL_PRECISION_2X12()
CON_BL_PRECISION_GRND(12,2)
#end
#macro CON_BL_PRECISION_2X13()
CON_BL_PRECISION_GRND(13,2)
#end


/********************************************************************************************************************************************
//Makro für BNC-Buchse, gewinckelt von Felix Schad <felix_schad@gmx.de>
********************************************************************************************************************************************/
#macro CON_BNC_W_GRND()
  union{
        union { // Korpus
                difference {
                        box {
                                <0,0,0><14.5,12.5,14>
                                pigment{Gray70}
                                clipped_by {
                                        plane { <1,0,0>,0 rotate<0,0,45> translate<0,25,0> }
                                        plane { <-1,0,0>,0 rotate<0,0,-45>translate<0,10.5,0>}
                                }
                        }

                        cylinder { // Mittlerer Ausschnitt fuer Anschlusspins
                                <0,0,0>,<0,2,0>,3
                                open
                                rotate<90,0,0>
                                translate <7.5,6.25,0>
                                pigment{Gray50}
                        }
                        box { // unterer Aussschnitt fuer Anschlusspins
                                <0,0,-1><5,3.8,2>
                                translate <4.75,0,0>
                                pigment{Gray70}
                        }

                }


                // freigeschnittene Aussenbereiche der Box fuellen
                box {
                        <0,0,0><4,2.9,14>
                        rotate<0,0,45>
                        translate<11.65,7.65,0>
                        pigment{Gray70}
                }

                box {
                        <0,0,0><4,2.9,14>
                        rotate<0,0,-45>
                        translate<0,10.4,0>
                        pigment{Gray70}
                }

                // freigeschnittenen Innenbereich der Box fuellen
                box{ <0,0,0><5,3.8,2> translate <4.75,0,0.5> pigment{Gray70}}


                disc {
                        <0,0,0>, <0,0,-1>, 3
                        translate <7.5,6.25,2>
                        texture{T_Silver_1A}

                }

                cylinder {
                        <0,0,0>,<0,2,0>,1.6
                        rotate<90,0,0>
                        translate <7.5,6.25,1.8>
                        pigment{Gray70}
                }

        } // Ende Korpus

        //TOOLS_RECT_BOGEN(i_radius,winkel,dicke,breite,laenge1,laenge2)
        object { // Massepin
                TOOLS_RECT_BOGEN(1,90,0.8,0.8,7,1)
                rotate<90,0,-90>
                translate<5.2,6.5,-0.5>
                texture { col_silver finish { phong 1 ambient (0.1 * global_ambient_mul) }}
        }
        #include "metals.inc"
        object { // Signalpin
                TOOLS_RECT_BOGEN(1,90,0.8,0.8,7,1)
                rotate<90,0,-90>
                translate<5.2+2.54,6.5,-0.5>
                texture{col_gold}


        }

        union { // Haltebolzen 1
                cylinder {
                        <0,1,0><0,-4,0>,1
                        translate<2.75,0,4.45>
                }
                sphere {
                        <0,0,0>,1
                        translate<2.75,-3.5,4.45>

                }
                texture{T_Silver_1A finish {phong 1.0 ambient (0.1 * global_ambient_mul)}}
        }

        union { // Haltebolzen 2
                cylinder {
                        <0,1,0><0,-4,0>,1
                        translate<2.75+10.2,0,4.45>
                }
                sphere {
                        <0,0,0>,1
                        translate<2.75+10.2,-3.5,4.45>

        }
        texture{T_Silver_1A finish {phong 1.0 ambient (0.1 * global_ambient_mul)}}
}


        difference {
                union {
                        cylinder { // Verschraubung
                                <0,0,0>,<0,0,9>,5.5
                                translate<7.25,6.25,14>
                        }

                        cylinder { // 'Schraubenlinien'
                                <0,0,0>,<0,0,0.2>,5.7
                                translate<7.25,6.25,16>
                        }

                        cylinder { // 'Schraubenlinien'
                                <0,0,0>,<0,0,0.2>,5.7
                                translate<7.25,6.25,17>
                        }

                        cylinder { // 'Schraubenlinien'
                                <0,0,0>,<0,0,0.2>,5.7
                                translate<7.25,6.25,18>
                        }

                        cylinder { // 'Schraubenlinien'
                                <0,0,0>,<0,0,0.2>,5.7
                                translate<7.25,6.25,19>
                        }

                        cylinder { // 'Schraubenlinien'
                                <0,0,0>,<0,0,0.2>,5.7
                                translate<7.25,6.25,20>
                        }

                        cylinder { // 'Schraubenlinien'
                                <0,0,0>,<0,0,0.2>,5.7
                                translate<7.25,6.25,21>
                        }

                        cylinder { // 'Schraubenlinien'
                                <0,0,0>,<0,0,0.2>,5.7
                                translate<7.25,6.25,22>
                        }
                        pigment{Gray70}

                } // end inner union

                box {
                        <0,0,0>,<16,3.3,9>
                        translate<2.25,11.5,14>
                        pigment{Gray70}
                }
        } // end difference


        cylinder { // aeusserer Anschluss
                <0,0,0>,<0,0,12>,4.7
                open
                translate<7.25,6.25,5.5+14>
                texture{T_Silver_1A finish { phong 1 ambient (0.1 * global_ambient_mul)}}
        }

        difference{
                cylinder { // innerer Anschluss A
                        <0,0,0>,<0,0,1>,3.8
                        translate<7.25,6.25,29>
                        pigment{Gray70}
                }

                cylinder { // innerer Anschluss B
                        <0,0,0>,<0,0,1>,1
                        translate<7.25,6.25,29.1>
                        texture{col_gold}
                }

                cylinder { // innerer Anschluss C
                        <0,0,0>,<0,0,1>,0.5
                        translate<7.25,6.25,29>
                        pigment{Black}
                }
        }
        cylinder { // Einrastpunkt 1
                <0,0,0>,<0,0,1>,1
                rotate<90,0,0>
                translate<7.25,12,29>
                texture { col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}
        }

        cylinder { // Einrastpunkt 2
                <0,0,0>,<0,0,1>,1
                rotate<90,0,0>
                translate<7.25,1.5,29>
                texture { col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}
        }


  translate <-7.25,0,-7>
  rotate <0,180,0>
  }
#end
#macro CON_BNC_W()
CON_BNC_W_GRND()
#end


/********************************************************************************************************************************************
//Makro fuer CENTRONICS_Steckverbinder, female, Printmontage,    con-amp-champ.lib,      Joerg Bredendiek <sprut(replace with at)sprut.de>         
// eine male-Version fuer Printmontage existiert nicht
//         
// pinraster 2,159 mm                                                               
// Nullpunkt linke Ecke des auesseren Plastikkoerpers
// Plastikkoerperbreite = ps + 29
// Dshellbreite = ps+10
//
//basiert auf DSUB von Andreas Fecht <info(replace with at)vetter-und-fecht.de>
//modifiziert und erweitert von Duane Clark <dclark(replace with at)akamail.com>
********************************************************************************************************************************************/
#macro CON_CENTRONICS_GRND(pin, female)
  #local centcolor = color red 0.24 green 0.41 blue 0.81;	//blauer farbton fuer plastikkoerper  
                 
  #local j  = pin/2;      // number of pins in bottom row
  #local hs = 2.159;      // horizontal pin spacing
  #local hc = 9.525;      // horizontal centerline
  #local vs = 2*hs;       // vertical pin spacing
  #local vc = 7.5;        // vertical centerline
  #local ps = (j-1)*hs;   // total pin spacing
  #local bo = 31.3;       // body offset = body size - ps   
  #local po = bo/2;       // offset to first pin 
  #local so = 4.064;      // screwlock offset from body sides
    

#macro DSHELL(ps, vc)
  // 
  #local do = 12.5;       // dshell offset,   the dshell offset is (body size - dshell size)/2 + radius
  #local ds = do+6.3;     // do + dshell size - ps - (radius*2)     12.5 + ps+12.3 -ps -6
  union
  {
    cylinder{<do,     vc+3, 0> <do,     vc+3, -9> 3 }	//oben  links
    cylinder{<ds+ps,  vc+3, 0> <ds+ps,  vc+3, -9> 3 }	//oben  rechts
    cylinder{<do+1,   vc-3, 0> <do+1,   vc-3, -9> 3 }	//unten links
    cylinder{<ds+ps-1,vc-3, 0> <ds+ps-1,vc-3, -9> 3 }	//unten rechts

    box{<do,  vc-0.1  ,  0> <ds+ps,  vc+6, -9>}									// oben
    box{<do+1,vc  ,  0> <ds+ps-1,vc-6, -9>}									// unten
    box{<-2,   vc+3, 0> <3.5,    vc-3, -9> rotate<0,0,-9.62> translate<ds+ps-2.20,0,0> }	// links
    box{<-2,   vc+3, 0> <3.5,    vc-3, -9> rotate<0,0, 9.62> translate<do+0.65,   0,0> }	// rechts
  }
#end 
                                        
                                        
//Metalloese in Frontplatte fuer den Buegel        
#macro OESE(ho,vo)
  difference{
        cylinder{<ho,vo-1.5,-1><ho,vo+1.5,-1>1.8 texture{col_silver} }
        cylinder{<ho,vo-1.6,-1><ho,vo+1.6,-1>1.2 texture{col_silver} }       
        texture{T_Chrome_5B} 
  }          
#end      
                     

//Buegel an Frontplatte                     
#macro BUEGEL() 
    #local bends=array[15] {
    // <angle, radius, 0> or <0, distance, 0> for straight pipe
    // negative angles bend left, positive bend right.
    <0, 3, 0>,  <-90, 1, 0>,  <0,10,0>,  <-45,1,0>,  <0, 6, 0>,  <90, 1, 0>, <0,9,0>, <90, 1, 0>, <0,9,0>,<90, 1, 0>, <0,6,0>, <-45,1,0>, <0,10,0>, <-90,1,0>, <0,3,0>
    }
    // this pipe has a radius of 0.4, starts at the origin, and initially goes in the x direction
    TOOLS_BENTPIPE( 0.4, <0,0,0>, y, bends )
#end
    

//los gehts    
union
{                 
      // the D shaped shell
      difference
      {
                object
                {
                        DSHELL(ps, vc)
                        translate<-0.5,-0.25,0>
                        scale<1.04-(0.0015*j),1.04,1>
                        texture{T_Chrome_5B}
                }

                object
                {
                        DSHELL(ps, vc)
                        scale<1,1,1.1>
                        texture{T_Chrome_5B}
                }
        }

        #if (female)
        // gefuellt mit blauer plastik
	        difference{
		        DSHELL(ps, vc)               
		        box{<po-2.5, vc-vs/2, -2> <po+ps+2.5, vc+vs/2, -9.2>pigment{centcolor} }   //mit einem 5 mm breitem schacht in der Mitte, 5mm breiter als pinspacing     
		        // loecher ueber/unter den Pins 
                        #local i = 0;
                        #while(i<j)   
                                box{<po+hs*i-0.5, vc+vs/2+0.5, -2><po+hs*i+0.5, vc+vs/2+1.5, -9.2>}
                                box{<po+hs*i-0.5, vc-vs/2-0.5, -2><po+hs*i+0.5, vc-vs/2-1.5, -9.2>}
                                #local i = i+1;
                        #end   		        		        
                        pigment{centcolor} 
	        }
                // buchsenpins
                #local i = 0;
                #while(i<j)
                        cylinder{<po+hs*i, vc+vs/2, -2> <po+hs*i, vc+vs/2    , -7.5> 0.5 texture{col_gold} }   
                        sphere{                         <po+hs*i, vc+vs/2    , -7.5> 0.5 texture{col_gold} }
                        sphere{                         <po+hs*i, vc+vs/2+0.5, -8  > 0.5 texture{col_gold} }
                        cylinder{<po+hs*i, vc-vs/2, -2> <po+hs*i, vc-vs/2    , -7.5> 0.5 texture{col_gold} }  
                        sphere{                         <po+hs*i, vc-vs/2    , -7.5> 0.5 texture{col_gold} }  
                        sphere{                         <po+hs*i, vc-vs/2-0.5, -8  > 0.5 texture{col_gold} }                        
                        #local i = i+1;
                #end 
        #else
        // dshell pins male   
                box{<po-1.5, vc-vs/2, -0.5> <po+ps+1.5, vc+vs/2, -7>}   // 4 mm breiter Steg in der Mitte , 3mm breiter asl pinspacing
                pigment{centcolor}

                union
                {
                        #local i = 0;
                        #while(i<j)
                        cylinder{<po+hs*i,vc+vs/2,-0.5> <po+hs*i, vc+vs/2, -7> 0.5 texture{col_gold} } 
                        sphere{                         <po+hs*i, vc+vs/2, -7> 0.5 texture{col_gold} }
                        cylinder{<po+hs*i,vc-vs/2,-0.5> <po+hs*i, vc-vs/2, -7> 0.5 texture{col_gold} } 
                        sphere{                         <po+hs*i, vc-vs/2, -7> 0.5 texture{col_gold} }                         
                        #local i = i+1;
                        #end
                }
      #end

      // board pins
      union
      {
        #local i = 0;
        #while(i<j)
        cylinder{<po+hs*i,0,hc+vs/2><po+hs*i,-3,hc+vs/2> 0.3 texture{col_gold} }
        cylinder{<po+hs*i,0,hc-vs/2><po+hs*i,-3,hc-vs/2> 0.3 texture{col_gold} }
        #local i = i+1;
    #end
  }

  // screwlock backplates
  box{<bo+ps-so+2.5,3,4><bo+ps-so+2.5,9.5,4.5> texture{T_Chrome_5B} }
  box{<so-2.5,3,4><so+2.5,9.5,4.5> texture{T_Chrome_5B} }
  // lower plates
  box{<bo+ps-so-1.5,3,4><bo+ps-so+1.5,3.25,hc+0.5> texture{T_Chrome_5B} }
  box{<so-1.5,3,4><so+1.5,3.25,hc+0.5> texture{T_Chrome_5B} }
  // mounting tabs
  box{<bo+ps-so-1.5,-4,hc-0.5><bo+ps-so-0.5,3.25,hc+0.5> texture{col_silver} }
  box{<so-1.5,-4,hc-0.5><so-0.5,3.25,hc+0.5> texture{col_silver} }

  box{<bo+ps-so+1.5,-4,hc-0.5><bo+ps-so+0.5,3.25,hc+0.5> texture{col_silver} }
  box{<so+1.5,-4,hc-0.5><so+0.5,3.25,hc+0.5> texture{col_silver} }
                            
                            
  // the main plastic body
  difference
  {
    box{< 0,      0, 0> <bo+ps,    13.5, 15>}                 //alles          
    box{<bo-7+ps, 3, 4> <bo+0.1+ps,13.6, 15.1>}               // 1. ecke ab
    box{<-0.1,    3, 4> <7,        13.6, 15.1>}               // 2. ecke ab 
    cylinder{<bo-7+ps, 13, 4>  <bo-7+ps, 13, 15.1> 1}         // seitliche obere kanten ausbohren
    cylinder{<7,       13, 4>  <7,       13, 15.1> 1}    
    
    cylinder{<bo-so+ps, 3.1,  hc> <bo-so+ps, -0.1, hc>   1.7}     // vertikale 3.4 mm Loecher fuer Platinenbefestigung
    cylinder{<so,       3.1,  hc> <so,       -0.1, hc>   1.7}
  }                                          

  // seitliche obere ausgebohrte Kanten abrunden
  cylinder{<bo-8+ps,12.5,4><bo-8+ps,12.5,15> 1} 
  cylinder{<8,12.5,4><8,12.5,15> 1}

  // duenne plastik-Lage hinter Frontplatte  oberhalb des main body, mit runden ecken, 2mm dick
  box{<1.5,13,0><bo+ps-1.5,15,2>}
  cylinder{<bo-1.5+ps,13.5,0><bo-1.5+ps,13.5,2> 1.5}
  cylinder{<1.5,13.5,0><1.5,13.5,2> 1.5}

  // Blech hinter der D shell , 1 mm dick, Rundungsradius 1,5 mm an allen ecken
  box{<0,1.5,0><bo+ps,13.5,-1>  texture{T_Chrome_5B} }
  box{<1.5,13.5,0><bo+ps-1.5,15,-1> texture{T_Chrome_5B} }
  cylinder{<bo+ps-1.5,13.5,0><bo+ps-1.5,13.5,-1> 1.5 texture{T_Chrome_5B} }
  cylinder{<1.5,13.5,0><1.5,13.5,-1> 1.5 texture{T_Chrome_5B} }
  box{<1.5,0,0><bo+ps-1.5,1.5,-1> texture{T_Chrome_5B} }
  cylinder{<bo+ps-1.5,1.5,0><bo+ps-1.5,1.5,-1> 1.5 texture{T_Chrome_5B} }
  cylinder{<1.5,1.5,0><1.5,1.5,-1> 1.5 texture{T_Chrome_5B} }
                                        
  //Schrauben                  
  object{TOOLS_SCREW (2.5,7,1,centcolor) rotate<-90,0,0> translate<so      ,vc,-1> texture{col_silver} }
  object{TOOLS_SCREW (2.5,7,1,centcolor) rotate<-90,0,0> translate<bo+ps-so,vc,-1> texture{col_silver} }          
  
  //Oesen 
  object{OESE(so+2      , vc-4.5) texture{T_Chrome_5B} }  
  object{OESE(so+2      , vc+4.5) texture{T_Chrome_5B} }
  object{OESE(bo+ps-so-2, vc-4.5) texture{T_Chrome_5B} }
  object{OESE(bo+ps-so-2, vc+4.5) texture{T_Chrome_5B} }  
  
  //Buegel
  object{BUEGEL() rotate<0,-30,0> translate<so+2      , vc-6.5,-1.5> texture{T_Chrome_5B} }  
  object{BUEGEL() rotate<0,210,0> translate<bo+ps-so-2, vc-6.5,-1.5> texture{T_Chrome_5B} } 
                     
  translate<0-po-ps/2,0,0-hc>
  rotate<0,180,0>
  pigment{centcolor} 
}
#end



#macro CON_CENTRONICS_F14()
CON_CENTRONICS_GRND(14, true)
#end
#macro CON_CENTRONICS_F24()
CON_CENTRONICS_GRND(24, true)
#end
#macro CON_CENTRONICS_F36()
CON_CENTRONICS_GRND(36, true)
#end
#macro CON_CENTRONICS_F50()
CON_CENTRONICS_GRND(50, true)
#end


/********************************************************************************************************************************************
// CF card+ holder
********************************************************************************************************************************************/
#macro CON_CF_AND_CARD_GRND(value)
union{
      union {
         box{<0,0,0><43,3.5,36.4> pigment{Gray10}} // Card
         box{<0,-0.6,0><43,3.5,0.7> pigment{Gray10}} // Card
                                                   
         // Label                                                  
         box{<2,3.50,2><41,3.51,36> pigment{Gray70}}
         text {ttf besch_font "COMPACT FLASH CARD" 0.1, 0 pigment{Gray10} scale 3  rotate<90,0,0> translate<4,3.511,23>}
         box{<4,3.5,21><21,3.51,21.5> pigment{Red}}
         text {ttf besch_font value 0.1, 0 pigment{Gray20} scale 24  rotate<90,0,0> translate<20,3.511,4>}
         translate <1.7,2.7,-17.5>
      } 


      difference {
          union {
                box{<0,0,0> <1.8,6.7,2.5> pigment{Wheat}} // Left
                box{<0,0,0> <1.8,6.7,2.5> translate <44.7,0,0> pigment{Wheat}} // Right

                box{<0,0,0> <5.7,2,7.5> translate <0,0,19> pigment{Wheat}} // Right
                box{<0,0,0> <5.7,2,7.5> translate <40.6,0,19> pigment{Wheat}} // Right


                box{<0,0,0> <46.3,5,22.6> translate <0,1.7,0> pigment{Wheat}} // main
          }
         
         box{<0,0,0> <36,2,11.4> translate <5,5.0,-0.1> }
         box{<0,0,0> <13,2.7,4.3> translate <3.2,4.7,15.1>}
         box{<0,0,0> <13,2.7,4.3> translate <30.2,4.7,15.1> }

         box{<0,0,0> <50,2,10> translate <-0.01,6,19.3> }
         
         box{<0,0,0> <3,4,10> translate <3.1,3.4,18.5> }
         box{<0,0,0> <3,4,10> translate <39.8,3.4,18.5> }
         
         cylinder{<0,0,0><0,3,0> 1 translate <3,0,23.5> }
         cylinder{<0,0,0><0,3,0> 1 translate <43.5,0,23.5> }
      }

}
pigment{color red 0.847059 green 0.847059 blue 0.54902}
translate<-23.15,0,-15>
#end
#macro CON_CF_AND_CARD(value)
CON_CF_AND_CARD_GRND(value)
#end


/********************************************************************************************************************************************
//rogerlight@gmail.com
********************************************************************************************************************************************/
#macro CON_COAX_B35N61_GRND()
union {
	cylinder { <0,0,0>, <0,-4.9,0>, 0.48 texture{col_gold}} // Centre contact
	cylinder { <-3.13, 0, -3.13>, <-3.13, -4.5, -3.13>, 0.58 texture{col_silver}}
	cylinder { <-3.13, 0, 3.13>, <-3.13, -4.5, 3.13>, 0.58 texture{col_silver}}
	cylinder { <3.13, 0, -3.13>, <3.13, -4.5, -3.13>, 0.58 texture{col_silver}}
	cylinder { <3.13, 0, 3.13>, <3.13, -4.5, 3.13>, 0.58 texture{col_silver}}

	cylinder { <0,0,0>, <0,2,0>, 5.5 texture{col_silver}}

	// This is the main body of the socket
  	difference {
		difference {
			merge {
				cylinder { <0,0,0>, <0,13.7,0>, 4.8 }
				cylinder { <5.5, 13.7-3.3-1,0>, <-5.5, 13.7-3.30-1,0>, 1.0 }
			}
			cylinder { <0,5.3,0>, <0,14.0,0>, 4.2 }
		}
		cone { <0,13.8,0> 4.9 <0,10,0>, 2.4 }
		texture{col_silver}
	}

	difference {
		cylinder { <0,1,0>, <0,13.7-3.3,0>, 1.5}
		cylinder { <0,1,0>, <0,13.7,0>, 1.0}
		texture{pigment{ rgb <1,1,1> }}
	}

	difference {
		cylinder { <0,1,0>, <0,13.7-3.3,0>, 1.0}
		cylinder { <0,1,0>, <0,13.7,0>, 0.6}
		texture{col_gold}
	}
}
#end
#macro CON_COAX_B35N61()
CON_COAX_B35N61_GRND()
#end


/********************************************************************************************************************************************
//DC-Power-Connector by Nigel Eke
********************************************************************************************************************************************/
#macro CON_DCPOWERCONNECTOR_GRND()
  #local endcutaway = union { cylinder { <10,5,3> <11.01,5,3> 3.01 }
                              box { <10,1.99,-.01> <11.01,5,6.01> }
                              box { <10,-.01,2> <11.01,2.01,4> }
                              pigment { Gray20} }
  #local innercutaway = cylinder { <-.01,5,3> <9,5,3> 2 pigment { Gray75} }
  #local housing_rough = union { box { <0,0,0> <2,8,6> }
                                 cylinder { <2,5,3> <11,5,3> 3 }
                                 box { <2,0,0> <11,5,6> }
                                 pigment { Gray20 }
                                 finish { Shiny  ambient (0.1 * global_ambient_mul)} }
  #local housing_refined = difference { object { housing_rough }
                                        object { endcutaway }
                                        object { innercutaway } }
  #local innerconnector = union { cylinder { <1,5,3> <8.5,5,3> .25 }
                                  cylinder { <8.5,5,3> <9,5,3> .75 }
                                   texture { Silver_Metal } }
  #local pin = box { <-1,-4,-.25> <1,3.5,.25> texture { Silver_Metal } }
  #local endconnector = difference { union { cylinder { <0,0,-.25><0,0,.25> 2 }
                                             cylinder { <0,0,-.99><0,0,.7> .8 } }
                                     cylinder { <0,0,-1> <0,0,.71> .6 }
                                     texture { Silver_Metal }
                                     translate <0,5,0> }

  union { object { housing_refined }
          object { innerconnector }
          object { pin rotate<0,90,0> translate<6,0,3> }
          object { pin translate<8,0,1> }
          union { difference { object { pin }
                               cylinder { <0,2,-.26> <0,2,.26> .2
texture { Silver_Metal} } }
                  object { endconnector }
                  rotate<0,90,0>
                  translate<10,0,3> } }

  translate<-5.5,0,-3>
  rotate<0,-90,0>
  scale 2.54/2
#end
#macro CON_DCPOWERCONNECTOR()
CON_DCPOWERCONNECTOR_GRND()
#end


/********************************************************************************************************************************************
//Macro für Hohlstecker-Printeinbau (HEBO 13 - Reichelt.de)
//franz.riedmueller@web.de
********************************************************************************************************************************************/
#macro CON_DC_JACK_HEBO_13_GRND()
union{ 
 //Stift 
 union{
       cylinder{<0, 4.5, 0><5.5, 4.5, 0> 0.65}
       cylinder{<0, 4.5, 0><0.2, 4.5, 0> 0.9} 
       sphere {<5.5, 4.5, 0> 0.65}
       texture{col_silver}
       translate<-0.7, 0, 0>
 } 
 //Gehäuse
 difference{
        union{
        box{<-5.75,0,-2.5><5.75,4.5,2.5>}
        cylinder{<-5.75, 4.5, 0><5.75, 4.5, 0> 2.5}
  }
  box{<-5.25,2.5,-10><-10, 20, 10>}
  box{<-0.75,2.5,-10><10, 20, 10>}
 } 
 //PIN
 union{
       box{<0,0,0.9><3.6-0.9, 0.3,-0.9>}
       cylinder{<3.6-0.9, 0,0><3.6-0.9, 0.3,0> 0.9}
       rotate<0,0,-90>
       translate<-1.05,0,0>
       texture{col_silver}
 }
 //PIN
 union{
       box{<0,0,0.9><3.6-0.9, 0.3,-0.9>}
       cylinder{<3.6-0.9, 0,0><3.6-0.9, 0.3,0> 0.9}
       rotate<0,0,-90>
       translate<-5.75,0,0>
       texture{col_silver}
 }
 //PIN
 union{
       box{<0,0,0.9><3.6-0.9, 0.3,-0.9>}
       cylinder{<3.6-0.9, 0,0><3.6-0.9, 0.3,0> 0.9}
       rotate<-90,0,-90>
       translate<-3.2,0,3.25>
       texture{col_silver}
 } 
 difference{
            cylinder{<0,0,0><1.8,0,0>0.75}
            cylinder{<-1,0,0><2.8,0,0>0.45} 
            box{<-10,0,-10><10,-10,10>}
            box{<-10,-10,0><10,10,-10>}
            texture{col_silver}
            translate<-4.1,0,2.5>
 }
 //Feder
 union{ 
       difference{
                  cylinder{<0,0,0><2.6,0,0>0.75}
                  cylinder{<-1,0,0><3.6,0,0>0.45} 
                  box{<-10,0,-10><10,-10,10>}
                  box{<-10,-10,0><10,10,-10>}
       }
       box{<2.6,0,0.45><0,-3,0.75>}
       box{<0,0.45,0><2.6,0.75,-3>}
       texture{col_silver}
       rotate<0,90,45>
       translate<2.5,3,1.3>
 }
 //Heckplatte
 difference{
           union{
                 cylinder{<0,0,0><0,0.3,0>1.5}
                 cylinder{<0,0,0><0,0.4,0>0.75}
                 box{<0,0,-1.5><2.5,0.3,1.5>}
                 texture{col_silver}
           }
           cylinder{<0,-1,0><0,1,0>0.3}
           rotate<0,180,90>
           translate<-5.45,4.5,0>
 }
 //translate<0,3.6,0>
 translate<0,0.2,0>
}
#end

#macro CON_DC_JACK_HEBO_13()
CON_DC_JACK_HEBO_13_GRND()
#end


/********************************************************************************************************************************************
// Wolfgang Moser <womo (a) d81.de>
// DIN-Buchse(n) Hirschmann MAx-XX
// 10.02.2006 ... 21.02.2006
********************************************************************************************************************************************/
#macro CON_DIN_MA_XX_GRND(MA_Typ, MA_Subtyp)

#macro CON_DIN_MA_Inlet_Kontaktfeder(Oesenlaenge, Verschraenkungsart, VSchraenkungwinkel)
	// Oesenlaenge:        Laenge der Kontaktoese oder des Kontaktpins,
	//                     bei Buchsen mit direktem Drahtanschluss
	// Verschraenkungsart: Art der "Verriegelung" der Kontaktfeder in
	//                     der Buchse. Ende gedreht oder abgewinkelt
	// VSchraenkungwinkel: Drehwinkel der Verschraenkung für beide
	//                     Arten

union{

	#local Federdicke=0.5;
		// Hauptteil der Kontaktfeder
	union{
		difference{
				// Basis: box
			box { <1.7,Federdicke/2,0>, <-1.7,-Federdicke/2,8.4> }
				// Ausschnitt: box 45 Grad gedreht, Einführung für Stift vom Stecker
 			box { <1,Federdicke/2+0.01,1>, <-1,-(Federdicke/2+0.01),-1> rotate<0,45,0>}
				// Ausschnitt: Freihaltung Innenbereich, Abrundung
			cylinder { <0,Federdicke/2+0.01,2.5> <0,-(Federdicke/2+0.01),2.5> 0.75 }
				// Ausschnitt: Freihaltung für Stift vom Stecker, Innenbereich
			box { <0.75,Federdicke/2+0.01,2.5>, <-0.75,-(Federdicke/2+0.01),7>}
				// Ausschnitt: Freihaltung Innenbereich, Abrundung
			cylinder { <0,Federdicke/2+0.01,7> <0,-(Federdicke/2+0.01),7> 0.75 }
				// Ausschnitt: Freihaltung für Stift vom Stecker im Kontaktbereich
			box { <0.5,Federdicke/2+0.01,0>, <-0.5,-(Federdicke/2+0.01),2.5>}
			}
			// Ergänzung: box, Führung der Kontaktfeder im Durchsteckbereich
		box { <1.15,Federdicke/2,8.0>, <-1.15,-Federdicke/2,10.5> }
			// Ergänzung: box, Stummel des Oesenanschlusses im Durchsteckbereich
		box { <0.35,Federdicke/2,8.0>, <-0.35,-Federdicke/2,11.85> }
		}

		// Endstück der Kontaktfeder

	difference{
		union{
				// Ergänzung: box, Weiterführung des Stummels (ohne Überschneidung!)
			box { <0.35,Federdicke/2,0>, <-0.35,-Federdicke/2,1.15> }
				// Ergänzung: box, Körper der Öse, variable Länge
			box { <1.15,Federdicke/2,1.15>, <-1.15,-Federdicke/2,2.15+Oesenlaenge> }
				// Ergänzung: cylinder, Abschluss der Öse, variable Position
			cylinder { <0,Federdicke/2,2.15+Oesenlaenge> <0,-Federdicke/2,2.15+Oesenlaenge> 1.15 }
			}
				// Ausschnitt: Freihaltung Innenbereich Öse, Abrundung
		cylinder { <0,Federdicke/2+0.01,2.15> <0,-(Federdicke/2+0.01),2.15> 0.5 }
				// Ausschnitt: Freihaltung für Ösenanschluss, Innenbereich
		box { <0.5,Federdicke/2+0.01,2.15>, <-0.5,-(Federdicke/2+0.01),2.15+Oesenlaenge>}
				// Ausschnitt: Freihaltung Innenbereich Öse, Abrundung
		cylinder { <0,Federdicke/2+0.01,2.15+Oesenlaenge> <0,-(Federdicke/2+0.01),2.15+Oesenlaenge> 0.5 }


		#switch(Verschraenkungsart)                                                         
			#case(0)	// Verdrehung (Schraube)
				translate<0,0, 11.85>
				rotate <0,0,VSchraenkungwinkel>
			#break
			#case(4)	// sowohl Abwinkelung als auch zusätzlich zweifache Verdrehung
				rotate <-VSchraenkungwinkel,0,0>
				rotate <0,0,2*VSchraenkungwinkel>
				translate<0,0, 11.85>
			#break
			#case(3)	// sowohl Abwinkelung als auch zusätzlich Verdrehung (invers)
				rotate <-VSchraenkungwinkel,0,0>
				rotate <0,0,-VSchraenkungwinkel>
				translate<0,0, 11.85>
			#break
			#case(2)	// sowohl Abwinkelung als auch zusätzlich Verdrehung
				rotate <-VSchraenkungwinkel,0,0>
				rotate <0,0,VSchraenkungwinkel>
				translate<0,0, 11.85>
			#break
			#case(1)	// Abwinkelung
				rotate <-VSchraenkungwinkel,0,0>
				// translate<0,0, 11.85>
			// #break	// fall through and execute the  #else  following
			#else
				translate<0,0, 11.85>
		#end
		}

	#switch(Verschraenkungsart)                                                         
		#range(1, 4)	// Abwinkelung (nicht perfekt bei cases 2 und 3)
				// bei Abwinkelung noch zusätzlich Abrundung und Auffüllen des "Biegeloches"
			cylinder { <0.35,0,11.85> <-0.35,0,11.85> Federdicke/2 }
		#break
	#end

	translate <0,0,1.0>
	#ifdef(CON_DIN_MA_Debug_Viewmode)
		pigment{Yellow}
	#else
		texture {col_silver}
	#end
	}
#end

#macro CON_DIN_MA_Inlet_Basebody(Einsatzart)
		// Einsatzart: Ausprägung des "Wulstes" am Ende zwecks Befestigung
		//             in einem Metallbecher oder zwei Metallhalbschalen
		//             einer Kupplung
#local Gesamtlaenge=13;
difference{
	union{
		cylinder { <0,0,0>  <0,0,Gesamtlaenge> 5.85 }

		#switch(Einsatzart)
			#case(0)	// Scheibenwulst für Metallbechermontage
				cylinder { <0,0,Gesamtlaenge-3>  <0,0,Gesamtlaenge-2> 7 }
					// Stützwulst in Durchführung von Metallbecher
				cylinder { <0,0,Gesamtlaenge-2.001>  <0,0,Gesamtlaenge> 6.15 }
			#break
			#case(1)	// unterteilter Wulst für Metallhalbschalenmontage
						// in Kupplungen (wie auch Steckern)
					// "dünner" Stützwulst
				cylinder { <0,0,Gesamtlaenge-4>  <0,0,Gesamtlaenge> 6 }

				difference{
						// "dickerer" Haltewulst
					cylinder { <0,0,Gesamtlaenge-3>  <0,0,Gesamtlaenge-1> 6.55 }

						// "gerade" Begrenzug des Wulstes für abnehmbare Metallabschirmung
					box      { < 5.5, 2.5,Gesamtlaenge-3.001>, <    7,-4,Gesamtlaenge-0.999>}
					box      { <-5.5, 2.5,Gesamtlaenge-3.001>, <   -7,-4,Gesamtlaenge-0.999>}

						// "abgeschrägte" Begrenzug des Wulstes für die nicht abnehmbare
						// Metallabschirmung mit der aufgenieteten Massekontaktzunge
					box      { <0.75,   0,Gesamtlaenge-3.001>, <-0.75,-3,Gesamtlaenge-0.999>
						translate< -6.25,0,0>
						rotate   < 0,0,-30>
						}
					box      { <0.75,   0,Gesamtlaenge-3.001>, <-0.75,-3,Gesamtlaenge-0.999>
						translate<  6.25,0,0>
						rotate   < 0,0, 30>
						}
					}
			#break
			#else		// keine Veränderung
					// Dummy: dünner Stützwulst für Metallhalbschalenmontage
				cylinder { <0,0,Gesamtlaenge-4>  <0,0,Gesamtlaenge> 6 }
		#end
		}

	#switch(Einsatzart)
		#case(0)
				// Ausschnitt für Massefederkontakt (etwas kürzer)
			box { <1.3,3.4,-0.01>, <-1.3,7.001,Gesamtlaenge-1.998> }
					// Breiterer Ausschnitt für Befestigung des
					// Massefederkontaktes am Metallbecher
			box { <2.1,3.45,Gesamtlaenge-1.999>, <-2.1,6.201,Gesamtlaenge+0.01> }
		#break
		#else
				// Ausschnitt für Massefederkontakt
			box { <1.3,3.4,-0.01>, <-1.3,7.001,Gesamtlaenge+0.01> }
	#end

	#ifdef(CON_DIN_MA_Debug_Viewmode)
		texture {col_Kerko}
	#else
		texture {pigment{Gray15} finish{F_MetalB  ambient (0.1 * global_ambient_mul)}}
	#end
	}
#end

#macro CON_DIN_MA_Inlet_Millbody()
#local Gesamtlaenge=13;
#local Stanzlochbreite=3.9;
union{
		// Basisbox bis 3mm vor Grund
	box { <Stanzlochbreite/2,0.4,-0.001>, <-Stanzlochbreite/2,-0.4,Gesamtlaenge-3> }
		// Röhre für Pin vom Stecker
	cylinder { <  0,  0,-0.001>  <   0,   0,Gesamtlaenge-3> 0.8 }
		// Durchbruch für Pinanschluss
	box { <1.25,0.4,Gesamtlaenge-3.001>, <-1.25,-0.4,Gesamtlaenge+0.001> }

	#ifdef(CON_DIN_MA_Debug_Viewmode)
		texture {col_Kerko}
	#else
		texture {pigment{Gray15} finish{F_MetalB  ambient (0.1 * global_ambient_mul)}}
	#end
	}
#end

#macro TIEFZIEH_ABRUNDUNG_VIERTELTORTORUS(Major Minor, Dicke, Quadrant)
	// Parametrisierung ähnlich zu der eines Torus
	// Major:    Radius des Ringes zur gedachten Mittellinie des zu
	//           einem Viertel aufgeschnittenen Ringtoruses
	// Minor:    Radius zur Außenkante des zu einem Viertel
	//           aufgeschnittenen Torusringes
	// Dicke:    Die Blechdicke bestimmt abhängig vom Minor-Außenradius
	//           in der Folge den Innenradius des zu einem Viertel
	//           aufgeschnittenen Torusringes. Dicke sollte im Bereich
	//           0<=Dicke<=Minor  liegen.
	//           Ist  Dicke<0  oder  Dicke>2*Minor, dann wird kein
	//           Torus dargestellt, weil die Schnittmenge leer wird.
	// Quadrant: Wahl des Viertels des Torusringes (1, 2, 3, 4)

#local SelectioningCylinder1 = cylinder { <0,0,0>   <0,Minor+0.001,0> Major+Minor+0.001 }
#local SelectioningCylinder2 = cylinder { <0,Minor+0.001,0>  <0,-(Minor+0.001),0> Major }
#if(Quadrant=3)
	object{
#else
	intersection{
#end
		difference{
			torus{Major, Minor}
			torus{Major, Minor-Dicke}

			#if(Quadrant=4 | Quadrant=3)
				SelectioningCylinder1
			#end
			#if(Quadrant=2 | Quadrant=3)
				SelectioningCylinder2
			#end
			}

		#if(Quadrant=1 | Quadrant=2)
			SelectioningCylinder1
		#end
		#if(Quadrant=1 | Quadrant=4)
			SelectioningCylinder2
		#end
		}
#end

#macro CON_DIN_MA_Outlet_BecherBase()
#local Gesamtlaenge=13;
union{
		// Hauptteil des Metallbechers, aufgebaut aus
		// ausgeschnittenen Ringtori und Zylinderringen
	difference{
		union{
			cylinder { <0,1,0>  <0,Gesamtlaenge-2,0> 7.4 }
			cylinder { <0,Gesamtlaenge-1.4,0>  <0,Gesamtlaenge-1,0> 6.4 }
			}
		cylinder { <0, 0.999,0>  <0,Gesamtlaenge-1.999,0> 7.0 }
		cylinder { <0,Gesamtlaenge-1.4001,0>  <0,Gesamtlaenge-0.999,0> 6.2 }
		}

	object{ TIEFZIEH_ABRUNDUNG_VIERTELTORTORUS(8.0, 1.0, 0.4, 4) translate<0,1,0> }
	object{ TIEFZIEH_ABRUNDUNG_VIERTELTORTORUS(6.4, 1.0, 0.4, 2) translate<0,Gesamtlaenge-2,0> }

		// Winkelstück zur Befestigung der Massekontakzunge
	union{
			// Viertelrohr als Biegeradius des Winkelstückes
		intersection{
			cylinder { <2,0.5,-0.5>  <-2,0.5,-0.5> 0.5 }
			cylinder { <2.001,0.5,-0.5>  <-2.001,0.5,-0.5> 0.1 inverse}
			box{<2.001,-0.001,-0.001>, <-2.001,0.5,-0.5>}
			}

			// Anschluss an den Metallbecher inklusive radialer Begrenzung
		intersection{
			box{<2,0,-0.5>, <-2,0.4,-2.5> }
			cylinder { <0,-0.001,0>  <0,0.401,0> 6.201 translate<0,0,4.0> }
			}

			// Kombination der Konstruktion von abgewinkeltem Anschlussstück
			// und der Massekontaktzunge in einer difference/union-Sektion,
			// was ein paar Anweisungen spart, die ganze Beschreibung
			// allerdings etwas unübersichtlich macht.
		difference{
			union{
					// Haltezunge für Niet
				box{<2,3.5,-0.4>, <-2,0.5,0>}

					// Kontaktzunge für Massekontaktierung als Cubic-Spline
				prism {
					linear_sweep cubic_spline
					-1.15, 1.15, 14, // the number of points making up the shape ...
					<2.45-Gesamtlaenge,-4.0>, < 2.45-Gesamtlaenge,0.5>,
					
					<5.4-Gesamtlaenge,-1.65>,

					<11.4-Gesamtlaenge,-0.02>, <12.4-Gesamtlaenge,0.2>, <13.4-Gesamtlaenge,0.2>, <16.4-Gesamtlaenge,0.175>,
					<16.4-Gesamtlaenge, 0.025>, <13.4-Gesamtlaenge,0.0>, <12.4-Gesamtlaenge,0.0>, <11.4-Gesamtlaenge,-0.22>,

					<5.4-Gesamtlaenge,-1.85>,
					
					< 2.45-Gesamtlaenge,0.5>, <6.95-Gesamtlaenge,0.5>
					rotate<0,0,90>
					}
					// Ergänzung des Cubic-Spline am hinteren Ende
				box  { <-1.15,13.30-(Gesamtlaenge),0.2>, <1.15,19.65-Gesamtlaenge,0> }
				cylinder { <0,19.65-(Gesamtlaenge),0.2>     <0,19.65-Gesamtlaenge,0> 1.15 }
	#ifdef(CON_DIN_MA_Debug_Viewmode)
		pigment{White}
	#end		
				}

				// Abschrägen der Haltezunge
			box{< 2.05,-0.501,0.001>, < 3.0,3.075,-0.401> rotate <0,0, 15> }
			box{<-2.05,-0.501,0.001>, <-3.0,3.075,-0.401> rotate <0,0,-15> }

				// Ausschneiden des Langloches in der Massekontaktzunge			
			box   { <-0.5,18.15-Gesamtlaenge,0.201>, <0.5,19.65-Gesamtlaenge,-0.001> }
			cylinder { <0,19.65-Gesamtlaenge,0.201>  <0,  19.65-Gesamtlaenge,-0.001> 0.5 }
			cylinder { <0,18.15-Gesamtlaenge,0.201>  <0,  18.15-Gesamtlaenge,-0.001> 0.5 }
	#ifdef(CON_DIN_MA_Debug_Viewmode)
		pigment{Red}
	#end		
			}

			// Messingniet zur Verbindung von Haltezunge und Massekontaktzunge
		cylinder { <0,2,0.25>  <0,2,-0.45> 0.875 texture {T_Gold_5E}} 	// Messing!

		translate<0,Gesamtlaenge-1.4,-4.0>
		}
	}
#end

#macro CON_DIN_MA_Outlet_FrontHlpr1(Winkel, Bauteil)
	#local ZielLaenge = (2*(Winkel>=0)-1)*9.138 ;
	#local ZielWinkel = Winkel+(2*(Winkel>=0)-1)*34.58078 ;
	#switch(Bauteil)
		#case(0)	// Boxen für "difference" der Viertel-Torusse, allerdings
					// nur oberhalb Blechdicke, nicht (mehr) komplett
			box {
				<0, -0.001,  -5.0   >, <ZielLaenge,1.001,0.001>
				#ifdef(CON_DIN_MA_Debug_Viewmode)
					pigment{Green}
				#end		
		#break

			// Teile zur Konstruktion der geraden Randbögen vom Tiefziehen
			// intersection{ 1 object{2 inverse} 3 }
		#case(1)	// Zylinder als Blechkante für Montageflügel
			cylinder{
				<0,1,-1>, <ZielLaenge,1,  -1  > 1.0
				#ifdef(CON_DIN_MA_Debug_Viewmode)
					pigment{Red}
				#end		
		#break
		#case(2)	// Innenzylinder für "intersection" mit Modifizierer
					// "inverse", Radius weniger Blechdicke (0.4)
					//
					// Realisierung der Überstände für "difference" (aka
					// inverse intersection) hier nicht absolut (+/- 0.001),
					// sondern relativ:  +/- FinLen * 0.001
			cylinder{
				<-ZielLaenge*0.001,1,-1>, <ZielLaenge*1.001,1,-1> 0.6
				#ifdef(CON_DIN_MA_Debug_Viewmode)
					pigment{Yellow}
				#end		
		#break
		#case(3)	// Box für "intersection" zum Freischneiden des richtigen Viertels
					// inklusive Überstände für Nicht-Schnittflächen
			box {
				<-0.001,0,  -1.001  >, <ZielLaenge+0.001,1.001,  0  >
				#ifdef(CON_DIN_MA_Debug_Viewmode)
					pigment{Pink}
				#end		
		#break

		#else
		// #case(4)	// Box zum Ausfüllen mit Blechdicke bis zur Biegekante
			box {
				<0,0,-7.5>, <ZielLaenge,0.4,-1>
	#end

				translate <0,0,   9.5  >
				rotate <0,ZielWinkel,0>
				}
#end

#macro CON_DIN_MA_Outlet_FrontHlpr2(Winkel)
intersection{
	CON_DIN_MA_Outlet_FrontHlpr1(Winkel, 1)
	object{ CON_DIN_MA_Outlet_FrontHlpr1(Winkel, 2) inverse }
	CON_DIN_MA_Outlet_FrontHlpr1(Winkel, 3)
	}
#end

#macro CON_DIN_MA_Outlet_FrontFlansch()
	// Dazu kommt die Frontplatte mit den beiden Flansch"ohren", welche
	// wiederum die beiden Befestigungslöcher enthalten
difference{
	union{
			// Der vorne überstehende Ring
		cylinder { <0,0,0>  <0,0.4,0> 8.5 }

			// Das Freischneiden der Ringtori an den Übergängen zu
			// den geraden Randstücken kann "schlierenfrei" nur
			// durch eine weitere explizite difference/union-
			// Beschreibung durchgeführt werden
		difference{
			union{
					// Der vorne überstehende Torus am Ring
				object{TIEFZIEH_ABRUNDUNG_VIERTELTORTORUS(8.5, 1.0, 0.4, 3) translate<0,1,0> }
			
					// Die Flanschohren
				object{ TIEFZIEH_ABRUNDUNG_VIERTELTORTORUS(2.2, 1.0, 0.4, 3) translate< 11.1,1,0> }
				object{ TIEFZIEH_ABRUNDUNG_VIERTELTORTORUS(2.2, 1.0, 0.4, 3) translate<-11.1,1,0> }
				}

				// Abschneiden der Tori an den Übergängen
				// zu den geraden Kantenverbindern
			CON_DIN_MA_Outlet_FrontHlpr1(   0, 0)
			CON_DIN_MA_Outlet_FrontHlpr1( 180, 0)
			CON_DIN_MA_Outlet_FrontHlpr1(-180, 0)
			CON_DIN_MA_Outlet_FrontHlpr1(-360, 0)
			#ifdef(CON_DIN_MA_Debug_Viewmode)
				pigment{Magenta}
			#end		
			}

			// Ausfüllung der Ohrentori
		object{ cylinder { <0,0,0>  <0,0.4,0> 2.2 } translate< 11.1,0,0> }
		object{ cylinder { <0,0,0>  <0,0.4,0> 2.2 } translate<-11.1,0,0> }

			// Die gebogenen Ränder zu den Ohren hin
		CON_DIN_MA_Outlet_FrontHlpr2(   0)
		CON_DIN_MA_Outlet_FrontHlpr2( 180)
		CON_DIN_MA_Outlet_FrontHlpr2(-180)
		CON_DIN_MA_Outlet_FrontHlpr2(-360)
		
			// Verlängerung der gebogenen Ränder zu den Ohren mit Blech
		CON_DIN_MA_Outlet_FrontHlpr1(   0, 4)
		CON_DIN_MA_Outlet_FrontHlpr1( 180, 4)
		CON_DIN_MA_Outlet_FrontHlpr1(-180, 4)
		CON_DIN_MA_Outlet_FrontHlpr1(-360, 4)
		#ifdef(CON_DIN_MA_Debug_Viewmode)
			pigment{Cyan}
		#end		
		}

		// Ausschneiden des großen Loches in der Mitte
	cylinder { <0,-0.001,0>  <0,0.401,0> 8.0 }

		// Ausschneiden der beiden kleinen Befestigungsbohrlöcher in den Ohren
	object{ cylinder { <0,-0.001,0>  <0,0.401,0> 1.6 } translate< 11.1,0,0> }
	object{ cylinder { <0,-0.001,0>  <0,0.401,0> 1.6 } translate<-11.1,0,0> }
	}
#end

#macro CON_DIN_MA_Outlet_Becher(Flansch)
	// Flansch: on/off

#if(Flansch=on)
	union{
			// Hauptbecher
		CON_DIN_MA_Outlet_BecherBase()
			// Frontflansch
		CON_DIN_MA_Outlet_FrontFlansch()
#else
	object{
		CON_DIN_MA_Outlet_BecherBase()
#end
	
			// Hier lediglich noch Positionierarbeiten
		rotate<90,0,0>
	
		#ifdef(CON_DIN_MA_Debug_Viewmode)
			// pigment{Green}
			texture {col_gold}
		#else
			texture {col_silver}
		#end
		}
#end

/*##########################################################################*/
/*##########################################################################*/
/*# Ende der Bauteildefinitionen, Anwendung durch Gruppierungen und Muster #*/
/*##########################################################################*/
/*##########################################################################*/

#macro CON_DIN_MA_InletAction(Typ, LochRotWinkel, LochPosWinkel)
	// Typ:           Art der Bearbeitung, derzeit definiert sind:
	//                0 - Fräsen bzw. Ausstanzen des kontaktfederloches
	//                1 - Kontaktfedereinsatz, Anschluss gebogen, Öse lang
	//                2 - Kontaktfedereinsatz, Anschluss gedreht, Öse lang
	//                3 - Kontaktfedereinsatz, Anschluss gedreht, Öse kurz
	//                4 - Kontaktfedereinsatz, Anschluss gebogen und
	//                    gedreht, Öse lang
	//                5 - Kontaktfedereinsatz, Anschluss gebogen und
	//                    invers gedreht, Öse lang
	//                6 - Kontaktfedereinsatz, Anschluss gebogen und
	//                    zweifach gedreht (60° statt 30°), Öse lang
	//
	// LochRotWinkel: Rotation des Stanzloches um die eigene Achse
	//                (dieser wird gegen "LochPosWinkel" kompensiert
	// LochPosWinkel: Rotation des Loches auf einem Radius von 3.5
	//                innerhalb des Buchseninlets
	//
	// Spezialfall: Wenn  LochPosWinkel=180  dann wird das Stanzloch
	// Mitelloch    genau in der Mitte des Inlets positioniert. Da
	//              das Loch ansonsten im Ausschnitt für den
	//              Massekontakt zu liegen käme, ist das "Fehlen" des
	//              180'er Winkels daher nicht tragisch.
	//
#local PositionRadius=3.5;
object{
	#switch(Typ)
		#case(6)	// Anschluss gebogen und zweifach verdreht, Öse lang
			CON_DIN_MA_Inlet_Kontaktfeder(3, 4, 30)
		#break
		#case(5)	// Anschluss gebogen und invers verdreht, Öse lang
			CON_DIN_MA_Inlet_Kontaktfeder(3, 3, 30)
		#break
		#case(4)	// Anschluss gebogen und verdreht, Öse lang
			CON_DIN_MA_Inlet_Kontaktfeder(3, 2, 30)
		#break
		#case(1)	// Anschluss gebogen, Öse lang
			CON_DIN_MA_Inlet_Kontaktfeder(3, 1, 30)
		#break
		#case(2)	// Anschluss gedreht, Öse lang
			CON_DIN_MA_Inlet_Kontaktfeder(3, 0,-30)
		#break
		#case(3)	// Anschluss gedreht, Öse kurz
			CON_DIN_MA_Inlet_Kontaktfeder(1, 0,-30)
		#break
		#else		// wie #case(0), Fräsen bzw. Ausstanzen der Löcher
			CON_DIN_MA_Inlet_Millbody()
	#end

 	rotate<0,0,90+LochRotWinkel-LochPosWinkel>
	#if(LochPosWinkel!=180)
	 	translate<0,-3.5,0>
	 	rotate<0,0,LochPosWinkel>
	#end
	}
#end

#macro CON_DIN_MA_InletPinComposition(MA_Typ, PinAction, MidPinAct)
	// MA_Typ:    Selektion der Buchsenart, Anzahl der Pins,
	//            Winkelstellung der Pins usw. über Typcodes.
	//
	//		Derzeit definitiert:
	//			30 - Anordnung wie bei:				MAB_3_S
	//			40 - Anordnung wie bei:				MAB_4
	//			51 - Anordnung wie bei:				MAB_5_S
	//			52 - Anordnung wie bei:				MAB_5
	//			53 - Anordnung wie bei:	(kreuzförmig, nicht Hirschmann)
	//			61 - Anordnung wie bei:				MAB_6
	//			62 - Anordnung wie bei (exklusiv):	MAB_6_V
	//			63 - Anordnung wie bei (exklusiv):	MAB_6_H
	//			71 - Anordnung wie bei (exklusiv):	MAB_7_SH
	//			72 - Anordnung wie bei:				MAB_7_S
	//			81 - Anordnung wie bei:				MAB_8_S
	//			82 - Anordnung wie bei:				MAB_8_SN
	//
	//			39 - Für rekursive Aufrufe benötigt
	//			58 - Für rekursive Aufrufe benötigt
	//			59 - Für rekursive Aufrufe benötigt
	//
	//		"Vererbungshierarchien":
	//				30 <|-- 51 <|-- 81
	//				59 <|-- 72 <|-- 82
	//				39 <|-- 58 <|-- 61
	//				ohne: 40, 52, 53, 62, 63, 71
	//
	// PinAction: Art der Bearbeitung, derzeit definiert sind:
	//            0 - Fräsen bzw. Ausstanzen des Kontaktfederloches
	//            1 - Kontaktfedereinsatz, Anschluss gebogen, Öse lang
	//            2 - Kontaktfedereinsatz, Anschluss gedreht, Öse lang
	//            3 - Kontaktfedereinsatz, Anschluss gedreht, Öse kurz
	//
	// MidPinAct: Gesondert definierbare Bearbeitungsart für das Mittelloch
	//
	// ACHTUNG: Der äußere aufrufende Kontext sollte diesem Makro eine
	//          klammernde Struktur umstellen, wie z.B.:  union{}
	//

	#switch(MA_Typ)
		#case(81)
				// Mittelloch ausstanzen, exzentrisch (0.9 mm) positioniert
			object{CON_DIN_MA_InletAction(MidPinAct, 0,180) translate<0,0.9,0>}
				// Die beiden speziell ausgerichteten Kontaktbohrungen unten
			object{CON_DIN_MA_InletAction((PinAction!=1?PinAction:4), -45,-135) translate<-1, 0.5, 0>}
			object{CON_DIN_MA_InletAction((PinAction!=1?PinAction:5),-135, 135) translate< 1, 0.5, 0>}
			// fall through to next case, adding more pins
		#case(51)
				// 45° links
			CON_DIN_MA_InletAction((PinAction!=1?PinAction:4), -45,-45)
				// 45° rechts
			CON_DIN_MA_InletAction((PinAction!=1?PinAction:5),-135, 45)
		#case(30)
				// 90° links
			CON_DIN_MA_InletAction((PinAction!=1?PinAction:4), -45,-90)
				// 90° rechts
			CON_DIN_MA_InletAction((PinAction!=1?PinAction:5),-135, 90)
				// center
			CON_DIN_MA_InletAction((PinAction!=1?PinAction:6),   0,  0)
		#break;
		//############################################

		#case(82)
				// Mittelloch ausstanzen, exzentrisch (0.7 mm) positioniert
			object{CON_DIN_MA_InletAction(MidPinAct, 0,180) translate<0,0.7,0>}

		#case(72)
				// Kontakte 6 und 7 unten ergänzen
			CON_DIN_MA_InletAction((PinAction!=1?PinAction:6),-135,-135)
			CON_DIN_MA_InletAction((PinAction!=1?PinAction:4), 135, 135)

		#case(59)
				// virtuelle 5'er Buchse, da nicht nach Norm
			#local Rotator=-90;
			#while (Rotator<=90)
				CON_DIN_MA_InletAction((PinAction!=1?PinAction:6), Rotator, Rotator)
				#local Rotator=Rotator+45;
			#end
		#break;
		//############################################

		#case(61)
				// Loch rechts unten ausstanzen und befüllen
			CON_DIN_MA_InletAction(PinAction, 300,-120)
		#case(58)
				// Mittelloch ausstanzen (6'er Buchse)
			CON_DIN_MA_InletAction(MidPinAct,  60, 180)
				// Loch rechts unten ausstanzen und befüllen
			CON_DIN_MA_InletAction(PinAction, 240, 120)
		#case(39)
				// 3 Löcher mit 60°-"Abständen" ausstanzen (für 6'er Buchse)
			#local Rotator=-60;
			#while (Rotator<=60)
				CON_DIN_MA_InletAction(PinAction, Rotator+120, Rotator)
				#local Rotator=Rotator+60;
			#end
		#break;
		//############################################

		#case(40)
				// Loch links unten ausstanzen und befüllen
			CON_DIN_MA_InletAction(PinAction, -18,-108)
				// Links oben
			CON_DIN_MA_InletAction(PinAction,  72, -36)
				// Rechts oben
			CON_DIN_MA_InletAction(PinAction, 108,  36)
				// Loch rechts unten ausstanzen und befüllen
			CON_DIN_MA_InletAction(PinAction, 198, 108)
		#break;
		//############################################

		#case(52)
				// rekursives "Holen" der 3'er Basis
			CON_DIN_MA_InletPinComposition(39, (PinAction!=1?PinAction:5), MidPinAct)
				// Loch rechts unten ausstanzen und befüllen
				//   diese Ausrichtung (nach Spec!!!) kann so nicht
				//   sein (Überschneidungen), müsste eigentlich einer
				//   62'er ohne Mittelpin entsprechen, bzw. der Anw.:
				//     CON_DIN_MA_InletAction(PinAction, 240, 120)
			CON_DIN_MA_InletAction((PinAction!=1?PinAction:6), 120, 120)
				// Loch links unten ausstanzen und befüllen
			CON_DIN_MA_InletAction((PinAction!=1?PinAction:5),   0,-120)
		#break;
		//############################################

		#case(53)
				// Mittelloch ausstanzen (5'er Kreuz-Buchse)
			CON_DIN_MA_InletAction(MidPinAct,  0, 180)
				// 2 Löcher oben mit 90°-"Abstand" ausstanzen
			CON_DIN_MA_InletAction((PinAction!=1?PinAction:4), -45, -45)
			CON_DIN_MA_InletAction((PinAction!=1?PinAction:5),-135,  45)
				// 2 Löcher unten mit 90°-"Abstand" ausstanzen
			CON_DIN_MA_InletAction((PinAction!=1?PinAction:4),-82.5,-135)
			CON_DIN_MA_InletAction((PinAction!=1?PinAction:5),-97.5, 135)
		#break;
		//############################################

		#case(62)
				// rekursives "Holen" der 5'er Basis
			CON_DIN_MA_InletPinComposition(58, PinAction, MidPinAct)
				// Loch links unten ausstanzen und befüllen
			CON_DIN_MA_InletAction(PinAction, 0,-120)
		#break;
		//############################################

		#case(63)
				// Mittelloch ausstanzen (6'er Buchse)
			CON_DIN_MA_InletAction(MidPinAct,  90, 180)


				// 5 Löcher mit 60°-"Abständen" ausstanzen (für 6'er Buchse)
			CON_DIN_MA_InletAction(PinAction,   0, -120)
			CON_DIN_MA_InletAction(PinAction, 120,   60)
			CON_DIN_MA_InletAction(PinAction, 180,  120)

				// bei Abwinkelung zusätzlich Verdrehung
			CON_DIN_MA_InletAction((PinAction!=1?PinAction:6),   0,    0)
				// bei Abwinkelung zusätzlich inverse Verdrehung
			CON_DIN_MA_InletAction((PinAction!=1?PinAction:5),  60,  -60)
		#break;
		//############################################

		#case(71)
				// rekursives "Holen" der 5'er Basis
			CON_DIN_MA_InletPinComposition(59, PinAction, MidPinAct)
				// Ergänzen der beiden Pins 6 und 7
			CON_DIN_MA_InletAction((PinAction!=1?PinAction:4),-90,-135)
			CON_DIN_MA_InletAction((PinAction!=1?PinAction:5),-90, 135)
		#break;
		//############################################
	#end
#end

	// MA_Typ:    Selektion der Buchsenart, Anzahl der Pins,
	//            Winkelstellung der Pins usw. über Typcodes.
	//            Die Typcodes sind derzeit noch nicht mit dem
	//            DIN-Standard abgestimmt
	//
	// MA_Subtyp: Selektion der weiteren Ausprägung, derzeit definiert:
	//            0 - Buchse im Metallbecher mit Flansch
	//                 (es fehlt noch der Masseanschluss)
	//            1 - Buchse im Metallbecher ohne Flansch
	//                (nicht fertiggestellt, Ösen statt Pins)
	//            2 - Kupplung (nicht fertiggestellt, Metallabschirmung
	//                [Becher] und Ummantelung fehlen noch komplett)

union{
	#local AllParts=3;
	#switch(MA_Subtyp)
		#case(1)
			#if(AllParts>=3)
				CON_DIN_MA_Outlet_Becher(off)
				#end

			#local Wulst=0;		// Metallbechermontage

				// die folgenden Definitionen verlangen eigentlich
				// einen Pin. Leider ist anhand der Specs nicht
				// ersichtlich, wie die Verankerung im Gehäuse
				// stattfindet, noch wie groß der Offset des
				// Anschlusspins vom Mittelpunkt ist.
				// Daher zunächst Verwendung langer Ösen mit
				// Verriegelung durch Verdrehen.
			#local PinEnde=2;		// Öse lang, verdreht
			#local MLPEnde=2;		// Öse lang, verdreht
		#break
		#case(2)
			// Makro für Kupplungs-/Steckergehäuse fehlt (noch)
			#if(AllParts>=3)
				#end

			#local Wulst=1;		// Halbschalenmontage
			#local PinEnde=3;		// Öse kurz, verdreht
			#local MLPEnde=2;		// Öse lang, verdreht
		#break
		#else	// selbe wie case(0)
			#if(AllParts>=3)
				CON_DIN_MA_Outlet_Becher(on)
				#end

			#local Wulst=0;		// Metallbechermontage
			#local PinEnde=1;		// Öse lang, abgebogen
			#local MLPEnde=2;		// Öse lang, verdreht
		#end

		// noch eine extra union, damit nur ein Objekt
		// "translationiert" (verschoben) werden braucht
	union{
		#if(AllParts>=2)
			difference{
				CON_DIN_MA_Inlet_Basebody(Wulst)
					// Ausfräsungen für die Kontaktfedern: 0,0
				CON_DIN_MA_InletPinComposition(MA_Typ, 0, 0)
				}
			#end

		#if(AllParts>=1)
				// Einbringen der Kontaktfedern
			CON_DIN_MA_InletPinComposition(MA_Typ, PinEnde, MLPEnde)
			#end

			// Gesamtlänge über alles ohne Pins laut Hirschmann-Spec: 13.6
			// Body ist aber nur 13.0, wobei jenes Inlet aber etwas im
			// Gehäuse (Becher) versenkt ist. Daher Positionierung desselben
		translate<0,0,0.6>
		}
	}
#end
#macro CON_DIN_MAB_3S()
CON_DIN_MA_XX_GRND(30, 0)
#end
#macro CON_DIN_MAB_4()
CON_DIN_MA_XX_GRND(40, 0)
#end
#macro CON_DIN_MAB_5()
CON_DIN_MA_XX_GRND(52, 0)
#end
#macro CON_DIN_MAB_5S()
CON_DIN_MA_XX_GRND(51, 0)
#end
#macro CON_DIN_MAB_6()
CON_DIN_MA_XX_GRND(61, 0)
#end
#macro CON_DIN_MAB_7S()
CON_DIN_MA_XX_GRND(72, 0)
#end
#macro CON_DIN_MAB_8S()
CON_DIN_MA_XX_GRND(81, 0)
#end
#macro CON_DIN_MAB_8SN()
CON_DIN_MA_XX_GRND(82, 0)
#end
// (noch) keine richtigen Pinanschlüsse
#macro CON_DIN_MAB_5SV()	
CON_DIN_MA_XX_GRND(51, 1)
#end
// (noch) keine richtigen Pinanschlüsse
#macro CON_DIN_MAB_6V()		
CON_DIN_MA_XX_GRND(62, 1)
#end
// (noch) keine richtigen Pinanschlüsse
#macro CON_DIN_MAB_7SV()	
CON_DIN_MA_XX_GRND(72, 1)
#end
// (noch) keine richtigen Pinanschlüsse
#macro CON_DIN_MAB_8SV()	
CON_DIN_MA_XX_GRND(81, 1)
#end
// (noch) keine richtigen Pinanschlüsse
#macro CON_DIN_MAB_8SNV()
CON_DIN_MA_XX_GRND(82, 1)
#end


/********************************************************************************************************************************************
// Grundmakro: Stiftleiste nach DIN41617.
// J.Bartels@arcor.de, www.mec-krefeld.de
********************************************************************************************************************************************/
#macro CON_DIS_DIN41617_GRND(Pins)
// Grundmakro: Um 90° gebogener, runder Stift eines Steckverbinders nach DIN41617.
// Parameter: Stärke über/unter PCB, Biegeradius (Mitte), Höhe über/unter PCB-Oberkante, Länge nach vorn (-Z), Farbe
// J.Bartels@arcor.de, www.mec-krefeld.de
#macro PIN41617 (DO,DU,R,HO,HU,L,col)
union{
	intersection{ 
		torus{ R, DO/2 rotate<0,0,90> translate<0,HO-R,-R> }
		box{ <DO/2,HO-R,DO/2><-DO/2,HO+DO/2,-R> }
	}
	cylinder{<0,-HU,0><0,HO-R-0.1,0> DU/2}
	cone{ <0,HO-R-0.1,0> DU/2 <0,HO-R,0> DO/2 }
	cylinder{<0,HO,-L+1><0,HO,-R> DO/2}
	cone{ <0, HO,-L+1>,DO/2,<0,HO,-L>,DO/2-0.3}
	texture{col}
} 
#end

// Grundmakro: Reihe von Stiften eines Steckverbinders nach DIN41617.
// J.Bartels@arcor.de, www.mec-krefeld.de
#macro PIN41617_ROW (Pins)
union{
	#local i=0;
	#while(i<Pins) 
		object{PIN41617 (1,0.8,1.2,1.6,3.3,13.9,col_gold) translate<i*2.5,0,-1.25>} 
		#local i=i+2; 
	#end
	#local i=1;
	#while(i<Pins) 
		object{PIN41617 (1,0.8,1.2,1.6+3.8,3.3,13.9+2.5,col_gold) translate<i*2.5,0,1.25>} 
		#local i=i+2; 
	#end
	translate<-(Pins/2)*2.5+1.25,0,4.5/2+2.5>
}
#end

#local A=(Pins-1)*2.5+15.6;
#local D=(Pins-1)*2.5+10;
#local E=Pins*2.5;
union{
 PIN41617_ROW( Pins )
 box{ <-E/2,0,-4.5/2><E/2,8.5,4.5/2> }
 //Befestigungs-Ohr
difference{ 
 box{ <A/2,0,-4.5/2><E/2,4.2,8.1-4.5/2> }
 intersection{
   cylinder{<D/2,-1,4.5/2><D/2,1+4.2,4.5/2>,1.6}
   box{ <D/2-1.6,-1,4.5/2-1.4><D/2+1.6,1+4.2,4.5/2+1.4>}
 }  
 box{ <-(A-E-5)/2,-1,0><0,1+4.2,8.1-4.5+10> rotate<0,20,0> translate<E/2,0,4.5/2> }
}
 //Befestigungs-Ohr
difference{ 
 box{ <-A/2,0,-4.5/2><-E/2,4.2,8.1-4.5/2> }
 intersection{
   cylinder{<-D/2,-1,4.5/2><-D/2,1+4.2,4.5/2>,1.6}
   box{ <-D/2+1.6,-1,4.5/2-1.4><-D/2-1.6,1+4.2,4.5/2+1.4>}
 }  
 box{ <(A-E-5)/2,-1,0><0,1+4.2,8.1-4.5+10> rotate<0,-20,0> translate<-E/2,0,4.5/2> }
}
pigment{Gray80}
}
#end

#macro CON_DIS_DIN41617_13()
CON_DIS_DIN41617_GRND(13)
#end
#macro CON_DIS_DIN41617_21()
CON_DIS_DIN41617_GRND(21)
#end
#macro CON_DIS_DIN41617_31()
CON_DIS_DIN41617_GRND(31)
#end


/********************************************************************************************************************************************
//Macros for connector MATE-N-LOK vertical 9263 serie from AMP
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.0 31-12-05
********************************************************************************************************************************************/
#macro CON_DIS_MATNLOK_9263_GRND(n,c)
#switch(c)
#case(1)
#local col=Gray90;
#break
#case(2)
#local col=Gray10;
#break
#case(3)
#local col=Brown;
#break
#case(4)
#local col=Gray90;
#break
#case(5)
#local col=Orange;
#break
#end

union{
    
    difference{
        merge{
            //body
        	box{<-6.35*n/2-.5,-3.8,0><6.35*n/2+.5,3.8,14>}

        	
        	//lateral grips
        	box{<-6.35*n/2,-1.5,6><-6.35*n/2-2.5,1.5,13.99>}
        	box{<6.35*n/2,-1.5,6><6.35*n/2+2.5,1.5,13.99>}
        	

        	//little blocs	
            #local i=0; #while (i<n+1) box{<-(6.35*n/2)+(i*6.35)-.5,-3.8,0><-(6.35*n/2)+(i*6.35)+.5,-4.6,2> } #local i=i+1; #end
         }
         
         merge{
            //Cylindrical holes
            #local i=0; #while (i<n) cylinder{<-(6.35/2*(n-1))+(i*6.35),0,1><-(6.35/2*(n-1))+(i*6.35),0,15> 3 } #local i=i+1; #end
            //Half square holes in the first hole
            #local i=0; 
            box{<-(6.35/2*(n-1))+(i*6.35)+3,0,1><-(6.35/2*(n-1))+(i*6.35)-3,-3,15> }
            //Half square holes in the last hole
            #local i=n-1;
            box{<-(6.35/2*(n-1))+(i*6.35)+3,0,1><-(6.35/2*(n-1))+(i*6.35)-3,-3,15> }
                        
        	//lateral grips
        	box{<-6.35*n/2-1.5,-1.6,5><-6.35*n/2-3.5,1.6,7.5> }
        	box{<+6.35*n/2+1.5,-1.6,5><+6.35*n/2+3.5,1.6,7.5> }
        	
        	box{<-2.5,-1.6,5><+2.5,1.6,20>  rotate -25*y translate +(6.35*n/2+9.8)*x}
        	box{<-2.5,-1.6,5><+2.5,1.6,20>  rotate +25*y translate -(6.35*n/2+9.8)*x}
         }
        #if(c=1)
             texture{
               pigment { rgbf <1,1,1,0.3> }
               normal{
                 agate 0.05
                 scale 0.1
               }
               finish{ phong 0.8 phong_size 200  ambient (0.1 * global_ambient_mul)}
             }
        #else
            pigment{col}
        #end
    }
    #local i=0; #while (i<n)
        difference{
            union{
                //Pin
                cylinder{<-(6.35/2*(n-1))+(i*6.35),0,-2><-(6.35/2*(n-1))+(i*6.35),0,4> 0.85  }
                cylinder{<-(6.35/2*(n-1))+(i*6.35),0,4><-(6.35/2*(n-1))+(i*6.35),0,10.5> 1.05  }
                //Top
                cone {<-(6.35/2*(n-1))+(i*6.35),0,+10.5>, 1.05, <-(6.35/2*(n-1))+(i*6.35),0,+12>, 0.3 }
                //Base
                cone {<-(6.35/2*(n-1))+(i*6.35),0,-2>, 0.85, <-(6.35/2*(n-1))+(i*6.35),0,-4>, 0.5 }
                
                texture { pigment{P_Silver2}}
            }
            //gap
            box{<+1,-0.1,7><-1,+0.1,14> texture{pigment{P_Silver2}} rotate(rand(global_seed)*180)*z translate<-(6.35/2*(n-1))+(i*6.35),0,0>   }
        }
    #local i=i+1; #end
    rotate <-90, 180,0>
       
}
#end
// 2 pins Nature
#macro CON_DIS_MATNLOK_9263_10_1() 
CON_DIS_MATNLOK_9263_GRND(2,1)
#end
// Black
#macro CON_DIS_MATNLOK_9263_10_2() 
CON_DIS_MATNLOK_9263_GRND(2,2)
#end
// BrickRed
#macro CON_DIS_MATNLOK_9263_10_3() 
CON_DIS_MATNLOK_9263_GRND(2,3)
#end
// White
#macro CON_DIS_MATNLOK_9263_10_4() 
CON_DIS_MATNLOK_9263_GRND(2,4)
#end
// Orange
#macro CON_DIS_MATNLOK_9263_10_5() 
CON_DIS_MATNLOK_9263_GRND(2,5)
#end
// 3 pins
#macro CON_DIS_MATNLOK_9263_11_1()
CON_DIS_MATNLOK_9263_GRND(3,1)
#end
#macro CON_DIS_MATNLOK_9263_11_2()
CON_DIS_MATNLOK_9263_GRND(3,2)
#end
#macro CON_DIS_MATNLOK_9263_11_3()
CON_DIS_MATNLOK_9263_GRND(3,3)
#end
#macro CON_DIS_MATNLOK_9263_11_4()
CON_DIS_MATNLOK_9263_GRND(3,4)
#end
#macro CON_DIS_MATNLOK_9263_11_5()
CON_DIS_MATNLOK_9263_GRND(3,5)
#end
//4 pins
#macro CON_DIS_MATNLOK_9263_12_1()
CON_DIS_MATNLOK_9263_GRND(4,1)
#end
#macro CON_DIS_MATNLOK_9263_12_2()
CON_DIS_MATNLOK_9263_GRND(4,2)
#end
#macro CON_DIS_MATNLOK_9263_12_3()
CON_DIS_MATNLOK_9263_GRND(4,3)
#end
#macro CON_DIS_MATNLOK_9263_12_4()
CON_DIS_MATNLOK_9263_GRND(4,4)
#end
#macro CON_DIS_MATNLOK_9263_12_5()
CON_DIS_MATNLOK_9263_GRND(4,5)
#end
// 5 pins
#macro CON_DIS_MATNLOK_9263_13_1()
CON_DIS_MATNLOK_9263_GRND(5,1)
#end
#macro CON_DIS_MATNLOK_9263_13_2()
CON_DIS_MATNLOK_9263_GRND(5,2)
#end
#macro CON_DIS_MATNLOK_9263_13_3()
CON_DIS_MATNLOK_9263_GRND(5,3)
#end
#macro CON_DIS_MATNLOK_9263_13_4()
CON_DIS_MATNLOK_9263_GRND(5,4)
#end
#macro CON_DIS_MATNLOK_9263_13_5()
CON_DIS_MATNLOK_9263_GRND(5,5)
#end
// 6 pins
#macro CON_DIS_MATNLOK_9263_14_1()
CON_DIS_MATNLOK_9263_GRND(6,1)
#end
#macro CON_DIS_MATNLOK_9263_14_2()
CON_DIS_MATNLOK_9263_GRND(6,2)
#end
#macro CON_DIS_MATNLOK_9263_14_3()
CON_DIS_MATNLOK_9263_GRND(6,3)
#end
#macro CON_DIS_MATNLOK_9263_14_4()
CON_DIS_MATNLOK_9263_GRND(6,4)
#end
#macro CON_DIS_MATNLOK_9263_14_5()
CON_DIS_MATNLOK_9263_GRND(6,5)
#end
// 8 pins
#macro CON_DIS_MATNLOK_9263_15_1()
CON_DIS_MATNLOK_9263_GRND(8,1)
#end
#macro CON_DIS_MATNLOK_9263_15_2()
CON_DIS_MATNLOK_9263_GRND(8,2)
#end
#macro CON_DIS_MATNLOK_9263_15_3()
CON_DIS_MATNLOK_9263_GRND(8,3)
#end
#macro CON_DIS_MATNLOK_9263_15_4()
CON_DIS_MATNLOK_9263_GRND(8,4)
#end
#macro CON_DIS_MATNLOK_9263_15_5()
CON_DIS_MATNLOK_9263_GRND(8,5)
#end
// 10 pins
#macro CON_DIS_MATNLOK_9263_16_1()
CON_DIS_MATNLOK_9263_GRND(10,1)
#end
#macro CON_DIS_MATNLOK_9263_16_2()
CON_DIS_MATNLOK_9263_GRND(10,2)
#end
#macro CON_DIS_MATNLOK_9263_16_3()
CON_DIS_MATNLOK_9263_GRND(10,3)
#end
#macro CON_DIS_MATNLOK_9263_16_4()
CON_DIS_MATNLOK_9263_GRND(10,4)
#end
#macro CON_DIS_MATNLOK_9263_16_5()
CON_DIS_MATNLOK_9263_GRND(10,5)
#end


/********************************************************************************************************************************************
//Makro für DSUBD Andreas Fecht <info@vetter-und-fecht.de>
//modifiziert und erweitert von Duane Clark <dclark@akamail.com>
//etwas mißbraucht zur Kantenmontage durch USER_Ma(China)
//Modifikation zur exakten Ausrichtung auf halbe Platinenhöhe: Wolfgang Moser <womo (a) d81.de>
//Erweitert für stehende print Montage von Stefan Seegel
********************************************************************************************************************************************/
#macro CON_DSUBD_GRND(pin, female, print)

#macro DSHELLD(ps, vc)
  // the dshell offset is (body size - dshell size)/2 + radius
  #local do = 8.33;    // dshell offset
  #local ds = 11.61;   // do + dshell size - ps - (radius*2)
  union
  {
    cylinder{<do,vc+3,4><do,vc+3,0> 1 }
    cylinder{<ds+ps,vc+3,4><ds+ps,vc+3,0> 1 }
    cylinder{<do+1,vc-3,4><do+1,vc-3,0> 1}
    cylinder{<ds+ps-1,vc-3,4><ds+ps-1,vc-3,0> 1 }
    box{<do,vc+2,4><ds+ps,vc+4,0>}
    box{<do+1,vc-2,4><ds+ps-1,vc-4,0>}
    box{<0,vc+3,4><1.5,vc-3,0> rotate<0,0,-9.62> translate<ds+ps-2.10,0,0> }
    box{<0,vc+3,4><1.5,vc-3,0> rotate<0,0,9.62> translate<do+0.55,0,0> }
  }
#end

#macro DSHELL(ps, vc)
  // the dshell offset is (body size - dshell size)/2 + radius
  #local do = 8.33;    // dshell offset
  #local ds = 11.61;   // do + dshell size - ps - (radius*2)
  union
  {
    cylinder{<do,vc+3,0><do,vc+3,-5.8> 1 }
    cylinder{<ds+ps,vc+3,0><ds+ps,vc+3,-5.8> 1 }
    cylinder{<do+1,vc-3,0><do+1,vc-3,-5.8> 1 }
    cylinder{<ds+ps-1,vc-3,0><ds+ps-1,vc-3,-5.8> 1 }
    box{<do,vc+2,-0.5><ds+ps,vc+4,-5.8>}
    box{<do+1,vc-2,-0.5><ds+ps-1,vc-4,-5.8>}
    box{<0,vc+3,-0.5><1.5,vc-3,-5.8> rotate<0,0,-9.62>
translate<ds+ps-2.10,0,0> }
    box{<0,vc+3,-0.5><1.5,vc-3,-5.8> rotate<0,0,9.62> translate<do+0.55,0,0>
}
  }
#end

union
{
  #local j = (pin-1)/2; // number of pins in bottom row
  #local hs = 2.758;    // horizontal pin spacing
  #local hc = 0;//9.525;    // horizontal centerline
  #local vs = 2.845;    // vertical pin spacing
  #local vc = 6.274;    // vertical centerline
  #local po = 9.97;     // offset to first pin
  #local ps = j*hs;     // total pin spacing
  #local bo = 20;       // body offset = body size - ps
  #local so = 3;        // screwlock offset from body sides
  #local pin_col=col_silver;         //Color of pins

  // the D shaped shell
  difference
  {
    object
    {
      DSHELLD(ps, vc)
      //DSHELLD(ps, vc)
      translate<-0.5,-0.25,0>
      scale<1.04-(0.0015*j),1.04,1>
      texture{col_silver}
    }

    object
    {
      DSHELLD(ps, vc)
      //DSHELLD(ps, vc)
      scale<1,1,1.1>
      texture{col_silver}
    }
  }

    difference
  {
    object
    {
      DSHELL(ps, vc)
      //DSHELLD(ps, vc)
      translate<-0.5,-0.25,0>
      scale<1.04-(0.0015*j),1.04,1>
      texture{col_silver}
    }

    object
    {
      DSHELL(ps, vc)
      //DSHELLD(ps, vc)
      scale<1,1,1.1>
      texture{col_silver}
    }


  }

  #if (female)
    // the plastic piece inside the female dshell
    DSHELLD(ps, vc)
     DSHELL(ps, vc)
    // dshell sockets
    difference
    {
      box{<po-1,vc-4,-0.5><po+ps+1,vc+4,-5.8>}
      #local i = 0;
      #while(i<j)
        cylinder{<po+hs*i,vc+vs/2,-2><po+hs*i,vc+vs/2,-10> 0.5 texture{col_gold} }
        cylinder{<po+hs*(i+0.5),vc-vs/2,-2><po+hs*(i+0.5),vc-vs/2,-10> 0.5 texture{col_gold} }
        #local i = i+1;
      #end
      cylinder{<po+hs*i,vc+vs/2,-2><po+hs*i,vc+vs/2,-10> 0.5 texture{col_gold} }

    }
    difference
    {
      box{<po-1.0,vc-4,0.5><po+ps+1,vc+4,4.8>}
      #local i = 0;
      #while(i<j)
        cylinder{<po+hs*i,vc+vs/2,0.5><po+hs*i,vc+vs/2,3.8> 0.8 texture{col_gold} }
        cylinder{<po+hs*(i+0.5),vc-vs/2,0.5><po+hs*(i+0.5),vc-vs/2,3.8> 0.8 texture{col_gold} }
        #local i = i+1;
      #end
      cylinder{<po+hs*i,vc+vs/2,0.5><po+hs*i,vc+vs/2,3.8> 0.8 texture{col_gold} }

    }

  #else
    DSHELLD(ps, vc)
    // dshell pins
   union
    {
      #local i = 0;
      #while(i<j)
        cylinder{<po+hs*i,vc+vs/2,0.5><po+hs*i,vc+vs/2,-5.8> 0.5 texture{col_gold} }
        cylinder{<po+hs*(i+0.5),vc-vs/2,0.5><po+hs*(i+0.5),vc-vs/2,-5.8> 0.5 texture{col_gold} }
        #local i = i+1;
      #end
      cylinder{<po+hs*i,vc+vs/2,0.5><po+hs*i,vc+vs/2,-5.8> 0.5 texture{col_gold} }
    }
    difference
    {
      box{<po-1.0,vc-4,0.5><po+ps+1,vc+4,4.8>}
      #local i = 0;
      #while(i<j)
        cylinder{<po+hs*i,vc+vs/2,0.5><po+hs*i,vc+vs/2,3.8> 0.8 texture{col_gold} }
        cylinder{<po+hs*(i+0.5),vc-vs/2,0.5><po+hs*(i+0.5),vc-vs/2,3.8> 0.8 texture{col_gold} }
        #local i = i+1;
      #end
      cylinder{<po+hs*i,vc+vs/2,0.5><po+hs*i,vc+vs/2,3.8> 0.8 texture{col_gold} }
    }

  #end


  // board pins

  #if (!print)
                        #local pin_l = 7.8;   // Pin length (from plate)
            #local pin_diao = 1.4;    //Pin outer diameter
            #local pin_diai = 1.2;     //Pin inner diameter

            union
            {
            #local i = 0;
            #while(i<j)
                        difference{
            cylinder{<po+hs*i,vc+vs/2,0.5><po+hs*i,vc+vs/2,pin_l> pin_diao/2}
            cylinder{<po+hs*i,vc+vs/2,0.5><po+hs*i,vc+vs/2,pin_l+1> pin_diai/2}

			cylinder{<po-hs,vc+vs/2+pin_diao/2,pin_l-1.5><po+ps+hs,vc+vs/2+pin_diao/2,pin_l-1.5> pin_diao/2}
            box{<po-hs,vc+vs/2, pin_l><po+ps+hs,vc+vs/2+pin_diao,pin_l+3> translate<0,0,-1.5>}
            texture{pin_col}
            }

                  difference{

				cylinder{<po+hs*(i+0.5),vc-vs/2,0.5><po+hs*(i+0.5),vc-vs/2,pin_l> pin_diao/2}

				cylinder{<po+hs*(i+0.5),vc-vs/2,0.5><po+hs*(i+0.5),vc-vs/2,pin_l+1> pin_diai/2}

				cylinder{<po-hs,vc-vs/2-pin_diao/2,pin_l-1.5><po+ps+hs,vc-vs/2-pin_diao/2,pin_l-1.5> pin_diao/2}

                        box{<po-hs,vc-vs/2,pin_l><po+ps+hs,vc-vs/2-pin_diao,pin_l+3> translate<0,0,-1.5>}

                        texture{pin_col}
            }

                  #local i = i+1;
            #end


                                   difference{

					cylinder{<po+hs*i,vc+vs/2,0.5><po+hs*i,vc+vs/2,pin_l> pin_diao/2}

					cylinder{<po+hs*i,vc+vs/2,0.5><po+hs*i,vc+vs/2,pin_l+1> pin_diai/2}

					cylinder{<po-hs,vc+vs/2+pin_diao/2,pin_l-1.5><po+ps+hs,vc+vs/2+pin_diao/2,pin_l-1.5> pin_diao/2}
					            box{<po-hs,vc+vs/2, pin_l><po+ps+hs,vc+vs/2+pin_diao,pin_l+3>translate<0,0,-1.5>}
					                        texture{pin_col}
                                   }
            }
  #end


  // thin metal plate backing D shell
difference
{

 box{<0,1.5,0><bo+ps,11,-0.5>  texture{col_silver} }
 cylinder{<0,0,0><0,0,-0.5> 1.5 open texture{col_silver} translate<so,vc,0>
}
 cylinder{<0,0,0><0,0,-0.5> 1.5 open texture{col_silver}
translate<bo+ps-so,vc,0> }

 }
 box{<1.5,12.5,0><bo+ps-1.5,10.5,-0.5> texture{col_silver} }
 cylinder{<bo+ps-1.5,11,0><bo+ps-1.5,11,-0.5> 1.5 texture{col_silver} }
 cylinder{<1.5,11,0><1.5,11,-0.5> 1.5 texture{col_silver} }

 box{<1.5,0,0><bo+ps-1.5,1.5,-0.5> texture{col_silver} }
 cylinder{<bo+ps-1.5,1.5,0><bo+ps-1.5,1.5,-0.5> 1.5 texture{col_silver} }
 cylinder{<1.5,1.5,0><1.5,1.5,-0.5> 1.5 texture{col_silver} }

  translate<0-po-ps/2,-6.8,-1-hc>
  rotate<0,180,0>
  pigment{Gray30}
}
#end

#macro CON_DSUB_F9D()
CON_DSUBD_GRND(9, true, false)
#end
#macro CON_DSUB_F15D()
CON_DSUBD_GRND(15, true, false)
#end
#macro CON_DSUB_F25D()
CON_DSUBD_GRND(25, true, false)
#end
#macro CON_DSUB_F37D()
CON_DSUBD_GRND(37, true, false)
#end
#macro CON_DSUB_M9D()
CON_DSUBD_GRND(9, false, false)
#end
#macro CON_DSUB_M15D()
CON_DSUBD_GRND(15, false, false)
#end
#macro CON_DSUB_M25D()
CON_DSUBD_GRND(25, false, false)
#end
#macro CON_DSUB_M37D()
CON_DSUBD_GRND(37, false, false)
#end
#macro CON_DSUB_F9DV()
CON_DSUBD_GRND(9,true,true)
#end
#macro CON_DSUB_F15DV()
CON_DSUBD_GRND(15,true,true)
#end
#macro CON_DSUB_F25DV()
CON_DSUBD_GRND(25,true,true)
#end
#macro CON_DSUB_F37DV()
CON_DSUBD_GRND(37,true,true)
#end
#macro CON_DSUB_M9DV()
CON_DSUBD_GRND(9,false,true)
#end
#macro CON_DSUB_M15DV()
CON_DSUBD_GRND(15,false,true)
#end
#macro CON_DSUB_M25DV()
CON_DSUBD_GRND(25,false,true)
#end
#macro CON_DSUB_M37DV()
CON_DSUBD_GRND(37,false,true)
#end


/********************************************************************************************************************************************
//Makro für DSUB Andreas Fecht <info@vetter-und-fecht.de>
//modifiziert und erweitert von Duane Clark <dclark@akamail.com>
********************************************************************************************************************************************/
#macro CON_DSUB_GRND(pin, female)
#macro DSHELL(ps, vc)
  // the dshell offset is (body size - dshell size)/2 + radius
  #local do = 8.33;    // dshell offset
  #local ds = 11.61;   // do + dshell size - ps - (radius*2)
  union
  {
    cylinder{<do,vc+3,0><do,vc+3,-5.8> 1 }
    cylinder{<ds+ps,vc+3,0><ds+ps,vc+3,-5.8> 1 }
    cylinder{<do+1,vc-3,0><do+1,vc-3,-5.8> 1 }
    cylinder{<ds+ps-1,vc-3,0><ds+ps-1,vc-3,-5.8> 1 }
    box{<do,vc+2,-0.5><ds+ps,vc+4,-5.8>}
    box{<do+1,vc-2,-0.5><ds+ps-1,vc-4,-5.8>}
    box{<0,vc+3,-0.5><1.5,vc-3,-5.8> rotate<0,0,-9.62> translate<ds+ps-2.10,0,0> }
    box{<0,vc+3,-0.5><1.5,vc-3,-5.8> rotate<0,0,9.62> translate<do+0.55,0,0> }
  }
#end

union
{
  #local j = (pin-1)/2; // number of pins in bottom row
  #local hs = 2.758;    // horizontal pin spacing
  #local hc = 9.525;    // vertical centerline
  #local vs = 2.845;    // vertical pin spacing
  #local vc = 6.274;    // vertical centerline
  #local po = 9.97;     // offset to first pin
  #local ps = j*hs;     // total pin spacing
  #local bo = 20;       // body offset = body size - ps
  #local so = 3;        // screwlock offset from body sides

  // the D shaped shell
  difference
  {
    object
    {
      DSHELL(ps, vc)
      translate<-0.5,-0.25,0>
      scale<1.04-(0.0015*j),1.04,1>
      texture{col_silver}
    }

    object
    {
      DSHELL(ps, vc)
      scale<1,1,1.1>
      texture{col_silver}
    }
  }

  #if (female)
    // the plastic piece inside the female dshell
    DSHELL(ps, vc)

    // dshell sockets
    difference
    {
      box{<po-1,vc-4,-0.5><po+ps+1,vc+4,-5.8>}
      #local i = 0;
      #while(i<j)
        cylinder{<po+hs*i,vc+vs/2,-2><po+hs*i,vc+vs/2,-10> 0.5 texture{col_gold} }
        cylinder{<po+hs*(i+0.5),vc-vs/2,-2><po+hs*(i+0.5),vc-vs/2,-10> 0.5 texture{col_gold} }
        #local i = i+1;
      #end
      cylinder{<po+hs*i,vc+vs/2,-2><po+hs*i,vc+vs/2,-10> 0.5 texture{col_gold} }
    }
  #else
    // dshell pins
    union
    {
      #local i = 0;
      #while(i<j)
        cylinder{<po+hs*i,vc+vs/2,-0.5><po+hs*i,vc+vs/2,-5.8> 0.5 texture{col_gold} }
        cylinder{<po+hs*(i+0.5),vc-vs/2,-0.5><po+hs*(i+0.5),vc-vs/2,-5.8> 0.5 texture{col_gold} }
        #local i = i+1;
      #end
      cylinder{<po+hs*i,vc+vs/2,-0.5><po+hs*i,vc+vs/2,-5.8> 0.5 texture{col_gold} }
    }
  #end

  // board pins
  union
  {
    #local i = 0;
    #while(i<j)
      cylinder{<po+hs*i,0,hc+vs/2><po+hs*i,-3,hc+vs/2> 0.5 texture{col_gold} }
      cylinder{<po+hs*(i+0.5),0,hc-vs/2><po+hs*(i+0.5),-3,hc-vs/2> 0.5 texture{col_gold} }
      #local i = i+1;
    #end
    cylinder{<po+hs*i,0,hc+vs/2><po+hs*i,-3,hc+vs/2> 0.5 texture{col_gold} }
  }

  // screwlock backplates
  box{<bo+ps-5.5,3,4><bo+ps-0.5,9.5,4.5> texture{col_silver} }
  box{<0.5,3,4><5.5,9.5,4.5> texture{col_silver} }
  // lower plates
  box{<bo+ps-4.5,3,4><bo+ps-1.5,3.25,hc> texture{col_silver} }
  box{<1.5,3,4><4.5,3.25,hc> texture{col_silver} }
  // mounting tabs
  box{<bo+ps-4.5,0,hc-1><bo+ps-3.5,3.25,hc> texture{col_silver} }
  box{<3.5,0,hc-1><4.5,3.25,hc> texture{col_silver} }

  box{<bo+ps-2.5,0,hc-1><bo+ps-1.5,3.25,hc> texture{col_silver} }
  box{<1.5,0,hc-1><2.5,3.25,hc> texture{col_silver} }

  // the main plastic body
  difference
  {
    box{<0,0,0><bo+ps,10.5,12.6>}
    box{<bo-7+ps,3,4><bo+0.1+ps,12.5,12.7>}
    box{<-0.1,3,4><7,12.5,12.7>}
    cylinder{<bo-7+ps,10.5,4><bo-7+ps,10.5,12.7> 1}
    cylinder{<7,10.5,4><7,10.5,12.7> 1}
    cylinder{<bo-3+ps,3.1,hc><bo-3+ps,-0.1,hc> 1.5}
    cylinder{<3,3.1,hc><3,-0.1,hc> 1.5}
  }

  // upper radius on plastic body
  cylinder{<bo-8+ps,9.5,4><bo-8+ps,9.5,12> 1}
  cylinder{<8,9.5,4><8,9.5,12> 1}

  // thin part of plastic body against the front
  box{<2,12.5,0><bo+ps-2,10.5,2>}
  cylinder{<bo-2+ps,10.5,0><bo-2+ps,10.5,2> 2}
  cylinder{<2,10.5,0><2,10.5,2> 2}

  // thin metal plate backing D shell
  box{<0,1.5,0><bo+ps,11,-0.5>  texture{col_silver} }

  box{<1.5,12.5,0><bo+ps-1.5,10.5,-0.5> texture{col_silver} }
  cylinder{<bo+ps-1.5,11,0><bo+ps-1.5,11,-0.5> 1.5 texture{col_silver} }
  cylinder{<1.5,11,0><1.5,11,-0.5> 1.5 texture{col_silver} }

  box{<1.5,0,0><bo+ps-1.5,1.5,-0.5> texture{col_silver} }
  cylinder{<bo+ps-1.5,1.5,0><bo+ps-1.5,1.5,-0.5> 1.5 texture{col_silver} }
  cylinder{<1.5,1.5,0><1.5,1.5,-0.5> 1.5 texture{col_silver} }

  // screwlocks
  difference
  {
    prism { 0, 5, 7, <3,5>, <-3,5>, <-5,0>, <-3,-5>, <3, -5>, <5,0>, <3,5>  texture{col_silver}
    scale<0.5,1,0.5>
    rotate<90,0,0> }

    cylinder{<0,0,-1><0,0,5> 1.5 texture{col_silver}  }
    translate<so,vc,-5.5>
  }


  difference
  {
    prism { 0, 5, 7, <3,5>, <-3,5>, <-5,0>, <-3,-5>, <3, -5>, <5,0>, <3,5>  texture{col_silver}
    scale<0.5,1,0.5>
    rotate<90,0,0> }

    cylinder{<0,0,-1><0,0,5> 1.5 texture{col_silver}  }
    translate<bo+ps-so,vc,-5.5>
  }

  // internal threads of the screwlocks
  #local i = 0;
    #while(i<12)
      torus { 1.5, 0.25  rotate <90,10,0>  texture{col_silver}
        translate<so,vc, 0.5-i/2> }
      torus { 1.5, 0.25  rotate <90,10,0>  texture{col_silver}
        translate<bo+ps-so,vc,0.5-i/2> }
    #local i = i+1;
  #end

  // screwlock mounting threads (in back)
  #local i = 5;
    #while(i<12)
      torus { 1.2, 0.25  rotate <90,10,0>  texture{col_silver}
        translate<so,vc, 10-i/2> }
      torus { 1.2, 0.25  rotate <90,10,0>  texture{col_silver}
        translate<bo+ps-so,vc,10-i/2> }
    #local i = i+1;
  #end


  cylinder{<0,0,-1><0,0,2.4> 1.2 texture{col_silver} translate<so,vc,5.5> }
  cylinder{<0,0,-1><0,0,2.4> 1.2 texture{col_silver} translate<bo+ps-so,vc,5.5> }

  translate<0-po-ps/2,0,0-hc>
  rotate<0,180,0>
  pigment{Gray30}
}
#end
#macro CON_DSUB_F9()
CON_DSUB_GRND(9, true)
#end
#macro CON_DSUB_F15()
CON_DSUB_GRND(15, true)
#end
#macro CON_DSUB_F25()
CON_DSUB_GRND(25, true)
#end
#macro CON_DSUB_F37()
CON_DSUB_GRND(37, true)
#end
#macro CON_DSUB_M9()
CON_DSUB_GRND(9, false)
#end
#macro CON_DSUB_M15()
CON_DSUB_GRND(15, false)
#end
#macro CON_DSUB_M25()
CON_DSUB_GRND(25, false)
#end
#macro CON_DSUB_M37()
CON_DSUB_GRND(37, false)
#end


/********************************************************************************************************************************************
//Eurocard Verbinder
//Duane Clark <dclark@akamail.com>
********************************************************************************************************************************************/
#macro CON_EUROCARD_GRND(pins, rows)
union
{
  #local j = pins/rows;   // number of pins in row
  #local hs = 2.54;       // horizontal pin spacing
  #local hc = 0.9;        // horizontal centerline
  #local vs = 2.54;       // vertical pin spacing
  #local vc = 5.475;      // vertical centerline
  #local po = 7.63;       // offset to first pin
  #local ps = (j-1)*hs;   // total pin spacing
  #local mo = 2.55;       // offset to first mounting hole
  #local d = hc+10.1;     // overall body depth
  #local id = 6.4;        // inside depth
  #local w = ps+po*2;     // overall body width
  #local h = 10.95;       // overall body height
  #local io = 4.4;        // inner housing offset
  #local r = 0.5;         // pin inner radius
  #local pw = 0.60;       // pin width
  #local ph = 0.60;       // pin height
  #local pl = 8.5+vs;     // length of lower pins
  #local pcb = 1.625;     // pc board cutout height
  #local kh = 0.4;        // key height

  difference
  {
    union {
      box{<0,0,0><d,h,w> }
      // mounting hole tabs
      box{<d-12.5,0,0><0,7.125,5.1> }
      box{<d-12.5,0,w><0,7.125,w-5.1> }
    }
    // mounting hole cutouts
    box{<d-12.6,7.126,-0.1><d-7,h+0.1,5.1> }
    box{<d-12.6,7.126,-0.1><d-7,h+0.1,5.1> translate<0,0,w-5> }
    // mounting holes
    cylinder{<hc,-0.1,mo><hc,h,mo>1.4 }
    cylinder{<hc,-0.1,w-mo><hc,h,w-mo>1.4 }
    // pc board cutout
    box{<d-12.6,-0.1,-0.1><d-id-0.7,pcb,w+0.1> }
    // pin area cutout
    box{<d-id-0.001,1.125,io><d+0.1,h-3.625,w-io> }
    box{<d-id,2,io+1><d+0.1,h-1.125,w-io-1> }
    // upper side key outer cutouts
    box{<d-5.601,8.45,-0.1><d+0.1,h+0.1,4.275> }
    box{<d-5.601,8.45,-0.1><d+0.1,h+0.1,4.275> translate<0,0,w-4.175> }
    // front side cutouts
    box{<d-5.6,-0.1,-0.1><d+0.1,h+0.1,3.275> }
    box{<d-5.6,-0.1,-0.1><d+0.1,h+0.1,3.275> translate<0,0,w-3.175> }
    // front notches
    box{<d-1,-0.1,po+hs*0.5><d+0.1,h+0.1,po+hs*2.5> }
    box{<d-1,-0.1,po+hs*6.5><d+0.1,h+0.1,po+hs*8.5> }
    box{<d-1,-0.1,po+hs*16.5><d+0.1,h+0.1,po+hs*18.5> }
    box{<d-1,-0.1,po+ps-hs*6.5><d+0.1,h+0.1,po+ps-hs*8.5> }
    box{<d-1,-0.1,po+ps-hs*0.5><d+0.1,h+0.1,po+ps-hs*2.5> }
    // lower keys
    box{<d-id,1.126,po+hs*1><d,1.125-kh,po+hs*2> }
    box{<d-id,1.126,po+hs*7><d,1.125-kh,po+hs*8> }
    box{<d-id,1.126,po+hs*17><d,1.125-kh,po+hs*18> }
    box{<d-id,1.126,po+ps-hs*7><d,1.125-kh,po+ps-hs*8> }
    box{<d-id,1.126,po+ps-hs*1><d,1.125-kh,po+ps-hs*2> }
    // upper keys
    box{<d-id,h-1.126,po+hs*1><d,h-1.125+kh,po+hs*2> }
    box{<d-id,h-1.126,po+hs*7><d,h-1.125+kh,po+hs*8> }
    box{<d-id,h-1.126,po+hs*17><d,h-1.125+kh,po+hs*18> }
    box{<d-id,h-1.126,po+ps-hs*7><d,h-1.125+kh,po+ps-hs*8> }
    box{<d-id,h-1.126,po+ps-hs*1><d,h-1.125+kh,po+ps-hs*2> }
    pigment{Gray85}
  }

  // pins
  union
  {
    #local k = 0;
    #while(k<rows)
      #if (rows<3)
        #if (k>0)
          // if only two rows, then the center row is the one that is missing
          #local k = k+1;
        #end
      #end
      #local i = 0;
      #while(i<j)
        // horizontal pin
        box{<r+ph/2-pl-k*vs,0-ph/2,0-pw/2><0,ph/2,pw/2> translate<hc+8.5,vc+(k-1)*vs,po+i*hs>}
        // pin radius
        difference {
          cylinder{<0,0,0><0,0,pw>r+ph}
          cylinder{<0,0,-0.1><0,0,pw+0.1>r}
          box{<0,-2,-0.1><2,2,pw+0.1>}
          box{<-2,-2,-0.1><2,0,pw+0.1>}
          translate<hc-(k+1)*vs+r+ph/2,vc+(k-1)*vs-r-ph/2,po+i*hs-pw/2>
        }
        // vertical pin
        box{<-ph/2,-2,-pw/2><ph/2,vc+(k-1)*vs-r-ph/2,pw/2> translate<hc-(k+1)*vs,0,po+i*hs>}
        #local i = i+1;
      #end
      #local k = k+1;
    #end
    texture{col_gold}
  }

  translate<0-hc,0-pcb,0-w/2>
  translate<0,2,0>
}
#end
#macro CON_EUROCARD_96M_3_L()
CON_EUROCARD_GRND(96,3)
#end
#macro CON_EUROCARD_64M_2_L()
CON_EUROCARD_GRND(64,2)
#end


/********************************************************************************************************************************************
//Macros for 6.35 Faston terminal
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1 du 09/01/06
********************************************************************************************************************************************/
#macro CON_FASTON_GRND ()
union{
    difference{
        union{
            box{<-0.4,0,-3.175><+0.4,+15.8,+3.175>  rotate<0,0,0> translate<0,0,0> } 
            box{<-0.4,0,-3.75><+0.4,+6.8,+3.75>     rotate<0,0,0> translate<0,0,0> }
        }
        
        union{  
            box{<-1,-1,-3.2><+1,+1,+3.2>    rotate<0,0,45> translate<-1.5,16,0> }
            box{<-1,-1,-3.2><+1,+1,+3.2>    rotate<0,0,45> translate<+1.5,16,0> }
            box{<-1,-1,-1><+1,+1,+1>        rotate<45,0,0> translate<0,16,3.8> }
            box{<-1,-1,-1><+1,+1,+1>        rotate<45,0,0> translate<0,16,-3.8> }
            
            box{<-1,-1,-1><+1,+1,+1>        rotate<45,0,0> translate<0,6.9,4.6> }
            box{<-1,-1,-1><+1,+1,+1>        rotate<45,0,0> translate<0,6.9,-4.6> }
            box{<-0.8,-0.1,-2><+0.8,+3,+2>  rotate<0,0,0>  translate<0,0,0> } 
            box{<-0.8,-0.1,-4><+0.8,+3,-3>  rotate<0,0,0>  translate<0,0,0> } 
            box{<-0.8,-0.1,+4><+0.8,+3,+3>  rotate<0,0,0>  translate<0,0,0> } 
            cylinder { -2*x, +2*x, 1  translate <0, 12, 0> }
            text {ttf global_fontfile_arial_bold "AMP" 0.1, 0  scale 1.5 scale <1,0.6,1> rotate<180,+90,0> translate<0.45,4.8,1.55>}  // Marking
            text {ttf global_fontfile_arial_bold "AMP" 0.1, 0  pigment{Silver} scale 1.5 scale <1,0.6,1> rotate<180,-90,0> translate<-0.45,4.8,-1.55>}  // Marking
        }
    }
    texture{ col_silver }
    translate -3*y
    rotate 90*y
}
#end
#macro CON_FASTON_V()
CON_FASTON_GRND ()
#end


/********************************************************************************************************************************************
//FEMALE PRINT CONNECTOR DIN 45323 (34V/3A), ROKA, distributor Conrad
// Friedrich Bleikamp <fbleikamp@web.de>
********************************************************************************************************************************************/
#macro CON_FPCON65_GRND()
union {
//Kunstoff
difference {
merge {
cylinder{<0,6.5,0><10.5,6.5,0>4.25}
box {<0,0,-6>,<5.2,6.2,6>}
box {<0,0,-4>,<1.6,13,4> translate<-1.6,0,0>}
box {<0,0,-6>,<1.1,14,6> translate<-2.7,0,0>}
cylinder{<10.0,6.5,0><14.0,6.5,0>2.5}
}
cylinder{<-3,6.5,0><8.7,6.5,0>3.25}
cylinder{<8.5,6.5,0><14.6,6.5,0>2.25}
box {<0.1,-0.1,-3>,<9,14,3>}
box {<0.1,-0.1,-4.5>,<9,4.5,-5.5>}
box {<0.1,-0.1,4.5>,<9,4.5,5.5>}
pigment{Gray30}}

difference {
merge {
cylinder{<12.6,6.5,0><14,6.5,0>4.5}
box {<12.6,0,-4.5>,<14,6.5,4.5>}
box {<14,0,-4.5>,<15.5,2.5,4.5>}
}
cylinder{<12.5,6.5,0><14.1,6.5,0>2.55}
box {<0,0,-4.6>,<2,3.5,4.6> rotate <0, 0, 20> translate<15.4,-0.2,0>}
pigment{Gray30}}

//Mittenkontakt
difference {
merge {
sphere { <0, 6.5, 0>, 1.05}
cylinder{<0,6.5,0><6,6.5,0>1.05}
cylinder{<6,6.5,0><6.6,6.5,0>3}
cylinder{<6.6,6.5,0><12.1,6.5,0>2.1}
//Vernietung
difference {
torus { 2.1, 0.5 }
box {<-10,0,-10>,<10,-2.5,10> }
rotate <0, 0, -90> translate<12.0,6.5,0>}
translate<2.6,0,0> }
cone { <14.01, 6.5, 0>, 1.7, <13, 6.5, 0>, 0.0 }
cylinder{<14.0,6.5,0><18,6.5,0>1.7 }
texture{col_silver}}

//Loetanschluss Mitte
difference {
merge {
cylinder{<14,6.5,0><14.5,6.5,0>4}
box {<14,2.5,-4>,<14.5,6.5,4>}
//#macro TOOLS_RECT_BOGEN(i_radius,winkel,dicke,breite,laenge1,laenge2)
object {TOOLS_RECT_BOGEN(0.2,90,0.5,2,0.8,13.25) rotate <90,90,180> translate<14.25,3.5,5.25>}
cylinder{<0.5,3.5,5><0.5,3.5,5.5>1 }
box {<1.25,0,5>,<3.75,2.5,5.5> }
object {TOOLS_RECT_BOGEN(0.2,90,0.5,2,0.8,13.25) rotate <-90,-90,180> translate<14.25,3.5,-5.25>}
box {<2,-2.5,5>,<3,0,5.5> }
cylinder{<0,3.5,-5><0,3.5,-5.5>1 translate<0.5,0,0>}
box {<1.25,0,-5>,<3.75,2.5,-5.5> }
box {<2,-2.5,-5>,<3,0,-5.5> }
}
cylinder{<13.9,6.5,0><14.6,6.5,0>2 }
texture{col_silver} }

//Loetanschluss Schalter
difference {
merge {
cylinder{<10.5,6.5,0><11.0,6.5,0>4 }
//#macro TOOLS_RECT_BOGEN(i_radius,winkel,dicke,breite,laenge1,laenge2)
object {TOOLS_RECT_BOGEN(0.3,85,0.5,4,3,5) rotate <0,180,90> translate<10.75,11.75,0>}
sphere { <6.5, 11.6, 0>, 0.5 translate<0,0,0>}
object {TOOLS_RECT_BOGEN(0.3,125,0.5,3,3,2.2) rotate <0,0.0,90> translate<10.75,1.8,0>}
object {TOOLS_RECT_BOGEN(0.3,125,0.51,1,2.5,0.3) rotate <0,0,-90> translate<8.4,0.6,0>}
}
cylinder{<10.4,6.5,0><11.1,6.5,0>2.55}
texture{col_silver}}

//Isolierscheibe
difference {
cylinder{<11.0,6.5,0><11.5,6.5,0>4.5 }
cylinder{<10.9,6.5,0><11.6,6.5,0>2.51 }
pigment{Sienna}}

//Federkontakt Aussen
difference {
merge {
cylinder{<11.5,6.5,0><12.0,6.5,0>4 }
box {<11.5,4.5,-3.25>,<12.0,1.0,3.25>}
}
cylinder{<11.4,6.5,0><12.1,6.5,0>2.55 }
texture{col_silver}}

//Loetanschluss Aussen u. Schalter
difference {
merge {
cylinder{<12.05,6.5,0><12.6,6.5,0>4 }
object {TOOLS_RECT_BOGEN(0.75,39.85,0.5,4,4,0) rotate <0,180,90> translate<12.3,13.5,0>}
object {TOOLS_RECT_BOGEN(0.3,132.0,0.5,4,7.98,0) rotate <0,180,7.5> translate<10.7,13,0>}
object {TOOLS_RECT_BOGEN(0.3,90,0.5,4,0,1.65) rotate <180,0,7.5> translate<1.8,11.83,0>}
object {TOOLS_RECT_BOGEN(0.3,125,0.5,4,2,0) rotate <0,0,-27.5> translate<1.88,9.52,0>}
object {TOOLS_RECT_BOGEN(0.5,125,0.5,4,2,0) rotate <0,0,22.5> translate<4.08,8.03,0>}
box {<12.05,4.5,-1.5>,<12.6,0,1.5>}
box {<12.05,0,-0.5>,<12.5,-2.5,0.5>}
}
cylinder{<11.9,6.5,0><12.7,6.5,0>2.55 }
texture{col_silver}}
}
#end
#macro CON_FPCON65()
CON_FPCON65_GRND()
#end


/********************************************************************************************************************************************
//Macros for L115 100 junction bloc by LMI
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1 du 04/01/06
********************************************************************************************************************************************/
#macro CON_LMI_L115_GRND(n)
// Macro for pin
#local CosseL115 =
union{
    difference{
        union{
            box{<-0.25,-4.5,-1.4><+0.25,+15,+1.4>  } 
            box{<-0.25,-4.5,-1.8><+0.25,+6.8,+1.4> }
        }
        
        union{  
            //connexion side pin bisel
            //length bisel
            box{<-1,-1,-3><+1,+1,+3>        rotate<0,0,45> translate<-1.1,15.4,0> }
            box{<-1,-1,-3><+1,+1,+3>        rotate<0,0,45> translate<+1.1,15.4,0> }
            //width bisel
            box{<-1,-1,-1><+1,+1,+1>        rotate<45,0,0> translate<0,15,+2.5> }
            box{<-1,-1,-1><+1,+1,+1>        rotate<45,0,0> translate<0,15,-2.5> }
            //solder side pin bisel
            box{<-0.8,0,-0.65><+0.8,-5,-5>  rotate<0,0,0>  translate<0,0,0> } 
            box{<-0.8,0,+0.65><+0.8,-5,+5>  rotate<0,0,0>  translate<0,0,0> } 
            box{<-1,-1,-1><+1,+1,+1>        rotate<120,0,0> translate<0,-4.5,+1.3> }
            box{<-1,-1,-1><+1,+1,+1>        rotate<60,0,0> translate<0,-4.55,-1.3> }
            //holes
            cylinder { -2*x, +2*x, .4       translate <0, 12, 0> }
            cylinder { -2*x, +2*x, 1.1      translate <0, 3, 0> }
        }
    }
    texture{ pigment{P_Silver2} }
    rotate 90*y
}

#local PAS = 5.08;
union{
    //terminals
    #local i=0; 
    #while (i<n)
        //Pins
        object{CosseL115 translate<0,0,-(PAS/2*(n-1))+(i*PAS)>}
    #local i=i+1; #end
    //body
    difference{
        union{
            difference{
                box{<2.75,5,-PAS*n/2><-2.75,6,+PAS*n/2> }
                box{<1.6,5.6,-PAS*n/2-0.01><-2.0,6.01,+PAS*n/2+0.01> }
            }
            box{<-2.75,0,-PAS*n/2><-1.8,5,+PAS*n/2> }
        }  
        #local i=1; 
        #while (i<n)
            //rectangular holes
            box{<-1.2,4,-0.25><+0.8,7,+0.25> translate<0,0,-(PAS/2*(n-1))+(i*PAS)-PAS/2>}
        #local i=i+1; #end
    }
    pigment{Gray80}
    rotate 90*y

}
#end
#macro CON_LMI_L115_2()
CON_LMI_L115_GRND(2)
#end
#macro CON_LMI_L115_3()
CON_LMI_L115_GRND(3)
#end
#macro CON_LMI_L115_5()
CON_LMI_L115_GRND(5)
#end
#macro CON_LMI_L115_10()
CON_LMI_L115_GRND(10)
#end
#macro CON_LMI_L115_20()
CON_LMI_L115_GRND(20)
#end


/********************************************************************************************************************************************
//Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
//Privat: <fbleikamp@web.de>
//Loetoese 1.0mm Drill fuer Drahtanschluss oder Testklemme
********************************************************************************************************************************************/
#macro CON_LSP_GRND(s)
union {
	difference{
		box { <-0.8,0,-0.2>,<0.8,5,0.2> texture{col_silver} translate<0,0,0>}
		box { <-0.8,-0.2,-0.3>,<0.8,5.2,0.3> texture{col_silver} rotate<0,0,-3> translate<1.1,0,0>}
		box { <-0.8,-0.2,-0.3>,<0.8,5.2,0.3> texture{col_silver} rotate<0,0,3> translate<-1.1,0,0>}
		translate<0,-5.0,0>
	}
	difference{
		box { <-1.5,0,-0.2>,<1.5,3,0.2> texture{col_silver} translate<0,0,0>}
		box { <-0.5,1.5,-0.3>,<0.5,3.1,0.3> texture{col_silver} translate<0,0,0>}
		cylinder{<0,0,-0.3><0,0,0.3>0.5 texture{col_silver} translate<0,1.5,0>}
	}
	difference{
		cylinder{<0,0,-0.2><0,0,0.2>1.5 texture{col_silver} translate<0,3,0>}
		cylinder{<0,0,-0.3><0,0,0.3>0.5 texture{col_silver} translate<0,3,0>}
		box { <-1.5,0,-0.3>,<1.5,3,0.3> texture{col_silver} translate<0,0,0>}
	}
	scale (s/13)
}
#end
#macro CON_LSP_10()
CON_LSP_GRND(10)
#end
#macro CON_LSP_11()
CON_LSP_GRND(11)
#end
#macro CON_LSP_13()
CON_LSP_GRND(13)
#end


/********************************************************************************************************************************************
//Macros for Micro-Match female from AMP
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)numericable.fr>
//Rev. 1.1  16/12/07
********************************************************************************************************************************************/
#macro CON_MICROMATCH_FEMALE_GRND(pin)

#local CON_MMTCH_PLASTIC_TEXTURE = texture {pigment{Red*0.6}};
#local pitch=1.27;
#local plastic_z=5;

#local plastic_x=pitch*(pin-1)+3.37;

union{
    difference {
        union{
            box{<-plastic_x/2,0.5,-plastic_z/2><plastic_x/2,2.1,plastic_z/2> } //Main box
            box{<-plastic_x/2+0.5,0.5,-plastic_z/2+0.5><plastic_x/2-0.5,4,plastic_z/2-0.5> } //Main box
        }
        box{<-plastic_x/2+0.5,0,-plastic_z/2+1><-plastic_x/2-0.1,4.1,plastic_z/2-1>}//Main box hollowing out
        box{<+plastic_x/2-0.5,0,-plastic_z/2+1><+plastic_x/2+0.1,4.1,plastic_z/2-1>}//Main box hollowing out
                #local i=0;
                #while(i<(pin/2)) //contacts apertures
                        box{<-0.2,-1,0><0.2,6,1.5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0> }
                        box{<-0.35,-1,0.5><0.35,6,1> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.4,-1,-0.4><0.4,6,-0.9> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        cylinder{<0,-1,-1.4><0,6,-1.4> 0.2 translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.2,-1,0><0.2,6,-1.5> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.35,-1,-0.5><0.35,6,-1> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.4,-1,0.4><0.4,6,0.9> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        cylinder{<0,-1,1.4><0,6,1.4> 0.2 translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        #local i=i+1;
                #end
        texture{CON_MMTCH_PLASTIC_TEXTURE}
    }
    #local i=0;
    #while(i<(pin/2))
    //pins
        box{<-0.25,-3.15+.25,-0.2><+0.25,1,+0.2> translate<-(plastic_x-3.37)/2+i*2.54,0,-1.27>}
        cylinder{<0,-3.15+0.25,-0.2><0,-3.15+0.25,+0.2> 0.25 translate<-(plastic_x-3.37)/2+i*2.54,0,-1.27>}
        box{<-0.25,-3.15+.25,-0.2><+0.25,1,+0.2> translate<-(plastic_x-3.37)/2+1.27+i*2.54,0,+1.27>}
        cylinder{<0,-3.15+0.25,-0.2><0,-3.15+0.25,+0.2> 0.25 translate<-(plastic_x-3.37)/2+1.27+i*2.54,0,+1.27>}
        
        cylinder{<0,1,-1.4><0,3.9,-1.4> 0.15 translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
        cylinder{<0,1,1.4><0,3.9,1.4> 0.2 translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
        difference{
            box{<-0.15,1,0><0.15,3.9,1.5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0> }
            box{<-0.2,1,0.5><0.2,4,1> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0> }
        }
        difference{
            box{<-0.15,1,0><0.15,3.9,-1.5> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0> }
            box{<-0.2,1,-0.5><0.2,4,-1> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0> }
        }
        #local i=i+1;
    #end
    pigment {Silver}
}
        
#end


#macro CON_MICROMATCH_FEMALE_4()
CON_MICROMATCH_FEMALE_GRND(4)
#end
#macro CON_MICROMATCH_FEMALE_6()
CON_MICROMATCH_FEMALE_GRND(6)
#end
#macro CON_MICROMATCH_FEMALE_8()
CON_MICROMATCH_FEMALE_GRND(8)
#end
#macro CON_MICROMATCH_FEMALE_10()
CON_MICROMATCH_FEMALE_GRND(10)
#end
#macro CON_MICROMATCH_FEMALE_12()
CON_MICROMATCH_FEMALE_GRND(12)
#end
#macro CON_MICROMATCH_FEMALE_14()
CON_MICROMATCH_FEMALE_GRND(14)
#end
#macro CON_MICROMATCH_FEMALE_16()
CON_MICROMATCH_FEMALE_GRND(16)
#end
#macro CON_MICROMATCH_FEMALE_18()
CON_MICROMATCH_FEMALE_GRND(18)
#end
#macro CON_MICROMATCH_FEMALE_20()
CON_MICROMATCH_FEMALE_GRND(20)
#end


/********************************************************************************************************************************************
// Makro fuer AMP-tyco MicroMatch-Federleiste SMD-Ausfuehrung
// pin  - Anzahl Kontakte
// frm = 0 - smd, != 0 - Bedrahtet
// everyone1@freenet.de
********************************************************************************************************************************************/
#macro CON_MICROMATCH_GRND(pin, frm)

#local CON_MMTCH_PLASTIC_TEXTURE = texture {pigment{Red*0.6} finish{ambient (0.1 * global_ambient_mul)}};
#local pitch=1.27;
#local plastic_z=5;
#local plastic_x=pitch*pin+2; // formula is a good match to the table in the datasheet
#if (frm = 0)
        #local plastic_Y=5.3;
#else
        #local plastic_Y=4.0;
#end

union   {
        difference{
                union   {
                        // Grundkörper
                        box{<-plastic_x/2+0.5, 0 ,-plastic_z/2+0.5> <plastic_x/2-0.5, plastic_Y, plastic_z/2-0.5> }
                        
                        // Kranz

                        #if (frm = 0)
                                // SMD
                                difference {
                                        box{<-plastic_x/2,1.9,-plastic_z/2> <plastic_x/2    ,3.3,plastic_z/2>}
                                        #local i=0;
                                        #while(i<(pin/2))
                                                box{<-0.5,2.4,0><0.5,3.5,5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                                                box{<-0.5,2.4,-5><0.5,3.5,0> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                                                #local i=i+1;
                                        #end
                                        box{<0,0,-plastic_z/4><plastic_x+1,5,plastic_z/4>}
                                }
                        #else                   
                                // Bedrahtet
                                box{<-plastic_x/2, 0.4 ,-plastic_z/2> <plastic_x/2, 2.0, -1.2>}
                                box{<-plastic_x/2, 0.4 , plastic_z/2> <plastic_x/2, 2.0, 1.2>}
                        #end
                }
                        
                // Ausschnitte im Kunststoff für SMD Pins
                #if (frm = 0)
                        #local i=0;
                        #while(i<(pin/2))
                                box{<-0.18,-1,-5><0.18,1.8,5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                                box{<-0.18,-1,-5><0.18,1.8,5> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                                #local i=i+1;
                        #end
                #end

                // Löcher für Stecker
                #local i=0;
                #while(i<(pin/2))
                        box{<-0.2,-1,0><0.2,6,1.5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.35,-1,0.5><0.35,6,1> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.4,-1,-0.4><0.4,6,-0.9> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        cylinder{<0,-1,-1.4><0,6,-1.4> 0.2 translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.2,-1,0><0.2,6,-1.5> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.35,-1,-0.5><0.35,6,-1> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.4,-1,0.4><0.4,6,0.9> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        cylinder{<0,-1,1.4><0,6,1.4> 0.2 translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        #local i=i+1;
                #end

                texture{CON_MMTCH_PLASTIC_TEXTURE}
        }

        #if (frm = 0)
                // SMD Pins
                #local i=0;
                #while(i<(pin/2))
                        object{TOOLS_PCB_SMD(1,6,0.25,8) translate<0.5,-0.125,0.5> rotate<0,0,90> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0> texture{col_silver}}
                        object{TOOLS_PCB_SMD(1,6,0.25,8) translate<-0.5,-0.125,-0.5> rotate<0,0,-90> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0> texture{col_silver}}        
                        #local i=i+1;
                #end
        #else
                // Anschlußdraht
                #if(pin_short=off)
                        #local pp=3.0;
                #else
                        #local pp=pcb_height+pin_length;
                #end
        
                #local i=0;
                #local j=1;
                #while(i<(pin/2))
                        box{ <-pitch/2-pitch*i-0.1, 1,-pitch*j-0.25> <-pitch/2-pitch*i+0.1, -pp,-pitch*j+0.25> texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}}
                        box{ < pitch/2+pitch*i+0.1, 1, pitch*j+0.25> < pitch/2+pitch*i-0.1, -pp, pitch*j-0.25> texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)}}}
                        #local j=j*-1;
                        #local i=i+1;
                #end
        #end
}
        
#end
#macro CON_MICROMATCH_4()
CON_MICROMATCH_GRND(4,1)
#end
#macro CON_MICROMATCH_6()
CON_MICROMATCH_GRND(6,1)
#end
#macro CON_MICROMATCH_8()
CON_MICROMATCH_GRND(8,1)
#end
#macro CON_MICROMATCH_10()
CON_MICROMATCH_GRND(10,1)
#end
#macro CON_MICROMATCH_12()
CON_MICROMATCH_GRND(12,1)
#end
#macro CON_MICROMATCH_14()
CON_MICROMATCH_GRND(14,1)
#end
#macro CON_MICROMATCH_16()
CON_MICROMATCH_GRND(16,1)
#end
#macro CON_MICROMATCH_18()
CON_MICROMATCH_GRND(16,1)
#end
#macro CON_MICROMATCH_20()
CON_MICROMATCH_GRND(20,1)
#end


/********************************************************************************************************************************************
//Macros for Micro-Match male from AMP
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)numericable.fr>
//Rev. 1.1  16/12/07
********************************************************************************************************************************************/
#macro CON_MICROMATCH_MALE_GRND(pin)

#local CON_MMTCH_PLASTIC_TEXTURE = texture {pigment{Red*0.6}};
#local pitch=1.27;
#local plastic_z=5;

#local plastic_x=pitch*(pin-1)+3.37;

union{
    difference {
        union{
            box{<-plastic_x/2,0,-plastic_z/2><plastic_x/2,3.6,plastic_z/2> } //Main box
            difference{//left hook
                box{<-0.5,-1,-0.5><0.5,1,0.5> rotate<0,0,30> translate<-plastic_x/2+0.2,2,0> }
                box{<-1,-1,-1><1,1,1> rotate<0,0,0> translate<-plastic_x/2,3.5,0> }
                box{<-1,-1,-1><1,1,1> rotate<0,0,0> translate<-plastic_x/2-1.5,2.5,0> }
            }
            difference{//right hook
                box{<-0.5,-1,-0.5><0.5,1,0.5> rotate<0,0,-30> translate<+plastic_x/2-0.2,2,0> }
                box{<-1,-1,-1><1,1,1> rotate<0,0,0> translate<+plastic_x/2,3.5,0> }
                box{<-1,-1,-1><1,1,1> rotate<0,0,0> translate<+plastic_x/2+1.5,2.5,0> }
            }
        }
        box{<-plastic_x/2+0.65,1.7,-plastic_z/2+0.5><plastic_x/2-0.65,3.61,plastic_z/2-0.5>}//Main box hollowing out
        box{<-plastic_x/2+0.65,-0.1,-plastic_z/2-0.5><plastic_x/2-0.65,0.4,plastic_z/2+0.5>}//Base hollowing out
        box{<-plastic_x/2-0.65,-0.1,-0.65><plastic_x/2+0.65,0.4,+0.65>}//Base hollowing out
        texture{CON_MMTCH_PLASTIC_TEXTURE}
    }
    difference {//Détrompeur
        union{
            box{<-plastic_x/2,3.6,-1.16><-plastic_x/2+0.65,7.1,1.16> } //top part
            box{<-plastic_x/2,3.6,-1.16-0.3><-plastic_x/2+0.65,3.6+0.3,1.16+0.3> } //down part        
        }
        cylinder{<-plastic_x/2-0.1,3.6+0.3,-1.16-0.3><-plastic_x/2+0.66,3.6+0.3,-1.16-0.3> 0.3}
        cylinder{<-plastic_x/2-0.1,3.6+0.3,+1.16+0.3><-plastic_x/2+0.66,3.6+0.3,+1.16+0.3> 0.3}
        box{<-plastic_x/2-0.1,5.5,0><-plastic_x/2+0.66,7.11,+1.161>}
        box{<-0.5,-0.82,-0.82><+0.5,+0.82,+0.82> rotate<45,0,0> translate<-plastic_x/2+0.3,5.5,+1.16>}                        
        box{<-0.5,-0.2,-0.2><+0.5,+0.2,+0.2> rotate<45,0,0> translate<-plastic_x/2+0.3,7.1+0.1,+0.1>}//biseaux
        box{<-0.5,-0.2,-0.2><+0.5,+0.2,+0.2> rotate<45,0,0> translate<-plastic_x/2+0.3,7.1+0.1,-1.16-0.1>}
        rotate 180*y    
            
        texture{CON_MMTCH_PLASTIC_TEXTURE}
    }
    #local i=0;
    #while(i<(pin/2))
    //pins
        box{<-0.25,-3.15+.25,-0.2><+0.25,1,+0.2> translate<-(plastic_x-3.37)/2+i*2.54,0,-1.27>}
        cylinder{<0,-3.15+0.25,-0.2><0,-3.15+0.25,+0.2> 0.25 translate<-(plastic_x-3.37)/2+i*2.54,0,-1.27>}
        box{<-0.25,-3.15+.25,-0.2><+0.25,1,+0.2> translate<-(plastic_x-3.37)/2+1.27+i*2.54,0,+1.27>}
        cylinder{<0,-3.15+0.25,-0.2><0,-3.15+0.25,+0.2> 0.25 translate<-(plastic_x-3.37)/2+1.27+i*2.54,0,+1.27>}
    //contacts    
        difference{
            box{<-0.35,1,-0.2><+0.35,3.6-0.2,+0.2> translate<-(plastic_x-3.37)/2+i*2.54,0,-0.75> }
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<-10,0,0> translate<-(plastic_x-3.37)/2+i*2.54,3.6-0.2,-0.75+0.32> }
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<+10,0,0> translate<-(plastic_x-3.37)/2+i*2.54,3.6-0.2,-0.75-0.32> }
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<-10,90,0> translate<-(plastic_x-3.37)/2+i*2.54+0.5,3.6-0.2,-0.75> }
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<-10,-90,0> translate<-(plastic_x-3.37)/2+i*2.54-0.5,3.6-0.2,-0.75> }
        }
        difference{
            box{<-0.35,1,-0.2><+0.35,3.6-0.2,+0.2> translate<-(plastic_x-3.37)/2+1.27+i*2.54,0,+0.75>}
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<-10,0,0> translate<-(plastic_x-3.37)/2+1.27+i*2.54,3.6-0.2,+0.75+0.32> }
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<+10,0,0> translate<-(plastic_x-3.37)/2+1.27+i*2.54,3.6-0.2,+0.75-0.32> }
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<-10,90,0> translate<-(plastic_x-3.37)/2+1.27+i*2.54+0.5,3.6-0.2,+0.75> }
            box{<-0.36,-0.5,-0.2><+0.36,+0.5,+0.2> rotate<-10,-90,0> translate<-(plastic_x-3.37)/2+1.27+i*2.54-0.5,3.6-0.2,+0.75> }
        }
        #local i=i+1;
    #end
    pigment {Silver}
}
        
#end


#macro CON_MICROMATCH_MALE_4()
CON_MICROMATCH_MALE_GRND(4)
#end
#macro CON_MICROMATCH_MALE_6()
CON_MICROMATCH_MALE_GRND(6)
#end
#macro CON_MICROMATCH_MALE_8()
CON_MICROMATCH_MALE_GRND(8)
#end
#macro CON_MICROMATCH_MALE_10()
CON_MICROMATCH_MALE_GRND(10)
#end
#macro CON_MICROMATCH_MALE_12()
CON_MICROMATCH_MALE_GRND(12)
#end
#macro CON_MICROMATCH_MALE_14()
CON_MICROMATCH_MALE_GRND(14)
#end
#macro CON_MICROMATCH_MALE_16()
CON_MICROMATCH_MALE_GRND(16)
#end
#macro CON_MICROMATCH_MALE_18()
CON_MICROMATCH_MALE_GRND(18)
#end
#macro CON_MICROMATCH_MALE_20()
CON_MICROMATCH_MALE_GRND(20)
#end


/********************************************************************************************************************************************
// Makro fuer AMP-tyco MicroMatch-Federleiste SMD-Ausführung
// pin  - Anzahl Kontakte
********************************************************************************************************************************************/
#macro CON_MICROMATCH_SMD_GRND(pin)
#local CON_MMTCH_PLASTIC_TEXTURE = texture {pigment{Red*0.6} finish{ambient (0.1 * global_ambient_mul)}};
#local pitch=1.27;
#local plastic_z=5;
#local plastic_x=pitch*pin+2; // formula is a good match to the table in the datasheet

union   {
        difference{
                union   {
                        box{<-plastic_x/2+0.5,0,-plastic_z/2+0.5><plastic_x/2-0.5,5.3,plastic_z/2-0.5>}
                        difference {
                                box{<-plastic_x/2,1.9,-plastic_z/2>      <plastic_x/2    ,3.3,plastic_z/2>}
                                #local i=0;
                                #while(i<(pin/2))
                                        box{<-0.5,2.4,0><0.5,3.5,5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                                        box{<-0.5,2.4,-5><0.5,3.5,0> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                                        #local i=i+1;
                                #end
                                box{<0,0,-plastic_z/4><plastic_x+1,5,plastic_z/4>}
                                }
                        }
                #local i=0;
                #while(i<(pin/2))
                        box{<-0.18,-1,-5><0.18,1.8,5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.18,-1,-5><0.18,1.8,5> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        #local i=i+1;
                #end
                #local i=0;
                #while(i<(pin/2))
                        box{<-0.2,-1,0><0.2,6,1.5> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.35,-1,0.5><0.35,6,1> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.4,-1,-0.4><0.4,6,-0.9> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        cylinder{<0,-1,-1.4><0,6,-1.4> 0.2 translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.2,-1,0><0.2,6,-1.5> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.35,-1,-0.5><0.35,6,-1> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        box{<-0.4,-1,0.4><0.4,6,0.9> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        cylinder{<0,-1,1.4><0,6,1.4> 0.2 translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0>}
                        #local i=i+1;
                #end
                texture{CON_MMTCH_PLASTIC_TEXTURE}
                }
        #local i=0;
        #while(i<(pin/2))
                object{TOOLS_PCB_SMD(1,6,0.25,8) translate<0.5,-0.125,0.5> rotate<0,0,90> translate<-(pin/2-0.5)*pitch+pitch*i*2,0,0> texture{col_silver}}
                object{TOOLS_PCB_SMD(1,6,0.25,8) translate<-0.5,-0.125,-0.5> rotate<0,0,-90> translate<-(pin/2-1.5)*pitch+pitch*i*2,0,0> texture{col_silver}}        
                #local i=i+1;
        #end
        }
        
#end
#macro CON_MICROMATCH_SMD_4()
CON_MICROMATCH_SMD_GRND(4)
#end
#macro CON_MICROMATCH_SMD_6()
CON_MICROMATCH_SMD_GRND(6)
#end
#macro CON_MICROMATCH_SMD_8()
CON_MICROMATCH_SMD_GRND(8)
#end
#macro CON_MICROMATCH_SMD_10()
CON_MICROMATCH_SMD_GRND(10)
#end
#macro CON_MICROMATCH_SMD_12()
CON_MICROMATCH_SMD_GRND(12)
#end
#macro CON_MICROMATCH_SMD_14()
CON_MICROMATCH_SMD_GRND(14)
#end
#macro CON_MICROMATCH_SMD_16()
CON_MICROMATCH_SMD_GRND(16)
#end
#macro CON_MICROMATCH_SMD_18()
CON_MICROMATCH_SMD_GRND(16)
#end
#macro CON_MICROMATCH_SMD_20()
CON_MICROMATCH_SMD_GRND(20)
#end


/********************************************************************************************************************************************
// Makro fuer einfache MODULAR-Buchsen RJ-45 (8pol) RJ-12 (6pol) RJ11 (4pol) u.ae.,    con-amp.lib ,     Joerg Bredendiek <sprut(replace with at)sprut.de>   
//
// plastik schwarz, Schirmung Silber
// Darstellung ist vereinfacht 
// 
//
// pins   = Anzahl der Pins , 2, 4, 6, 8
// a      = Abstand zwischen den Mitten der Montagestifte  
// o      = Abstand zwischen Mittlepunkt und Verbindungslinie der Befestigungszapfen (Offset)  
// schirm = 0-kein, 1-voll, 2-teilweise  
// stop   = 0-kein, 1-panel-stop
********************************************************************************************************************************************/
#macro CON_MODULAR_GRND(pins,a,o,schirm,stop)
#local tex_rj45_pastic1= texture { pigment{White*0.3} finish {specular 1 roughness 0.001 reflection 0.07 ambient (0.1 * global_ambient_mul)} } ;   //etwas glatter/glaenzender
#local tex_rj45_pastic = texture { pigment{White*0.3} finish {specular 0.1 roughness 0.1 reflection 0.07 ambient (0.1 * global_ambient_mul)} } ;
// Aussenabmasse 6 pins : 13.4  x  12.8  x  18.0 BHT   
// Breite ist bauformabhaengig

#local bb = a+3;
#local bh = 12.8;
#local bt = 18.0;          


// Ausbruch im Kunststoff
// 4 pin ??
// 6 pin - 10 mm
// 8 pin - 12 mm
#local stecker2 = 
      difference
      {
         union
         {
            box{<-bb/2+1.5,  3.7, -11.7><bb/2-1.5, 11.5, 4.8>}
            box{<-bb/2+3.1,  2.5, -11.7><bb/2-3.1, 11.5, 4.8>}
            box{<-bb/2+5.6,  0.7, -11.7><bb/2-5.6, 11.5, 4.8>}
            box{<-1  , -1  , -2><16      ,  1  ,  2  >rotate<-30,0,0>translate<-bb/2,4.4,-21.4/2> pigment{White*0.5}}
            box{<-1  ,  0  , -1><16      ,  0.5,  1  >rotate<-30,0,0>translate<-bb/20,2.0,-21.4/2> pigment{White*0.5}}
         }
         box{<-bb/2-1   , -1  ,  4.3 >< -bb/2+ 16  ,15 , 5.3>}
         box{<-bb/2-1   , -1  ,-11.7 >< -bb/2+ 1.6 ,15 , 5.3>}
         box{<-bb/2+14.2, -1  ,-11.7 >< -bb/2+ 16  ,15 , 5.3>}
      }; 
      

#local pin_intern =
   sphere_sweep {
      b_spline
      9,
      <-0.635, 10.0,  17-21.4/2>,   0.2
      <-0.635, 12.0,  17-21.4/2>,   0.2
      <-0.635, 12.5,  17-21.4/2>,   0.2
      <-0.635, 12.5,  6-21.4/2>,   0.2
      <-0.635, 11.7,  6-21.4/2>,   0.2
      <-0.635, 11.0,  6.5-21.4/2>, 0.2
      <-0.635, 10.3, 10-21.4/2>,  0.2
      <-0.635, 8.0, 16-21.4/2>,  0.2
      <-0.635, 8.0, 18-21.4/2>,  0.2
      texture{col_gold} 
   }              
   
#local pin_channel = box{<-0.635-0.31 , bh-0.5, -5>< -0.635+0.31 , bh+1 , -8+bt> texture{tex_rj45_pastic}}  
           
           
union
{                 
        #if (schirm=1)  
        // voll geschrimt
        #local tex_modul_metal = texture { T_Chrome_5B } ;
        #local bb = a+3;
        #local bh = 12.8;
        #local bt = 18.0;  
        #local sb = 14+1;
        #if (a>11)
                #local sb = 15.5+1;
        #end        
        //Metallhuelle, quaderfoermig mit abgerundeten Ecken und Kanten        
        union{          
                difference{
                        box{<-sb/2, 0, -8.5 > < sb/2, bh+1 , -8+bt+1> texture{T_Chrome_5B}}                      //Ummantelung                      
                        box{<-bb/2, 0, -8   > < bb/2, bh   , -8+bt  > texture{T_Chrome_5B}}                      //Aushoehlung
                        box{<-sb/2-0.1, bh+0.5, -8.6 > < -sb/2+0.5, bh+1.1 , -8+bt+1> texture{T_Chrome_5B}}      //obere Seitenkannten ausfraesen                  
                        box{< sb/2+0.1, bh+0.5, -8.6 > <  sb/2-0.5, bh+1.1 , -8+bt+1> texture{T_Chrome_5B}}  
                        box{<-sb/2-0.1, bh+0.5, -8+bt+1.1 > <  sb/2+0.1, bh+1.1, -8+bt+0.5> texture{T_Chrome_5B}}//obere hinterkannte     
                        box{<-sb/2-0.1, bh+0.5, -8        > <  sb/2+0.1, bh+1.1, -8.6   > texture{T_Chrome_5B}}  //obere vorderkannte
                        box{< sb/2+0.1, bh+1.1, -8+bt+0.5 > <  sb/2-0.5, -0.1, -8+bt+1.1> texture{T_Chrome_5B}}  //senkrechte hinterkannten
                        box{<-sb/2-0.1, bh+1.1, -8+bt+0.5 > < -sb/2+0.5, -0.1, -8+bt+1.1> texture{T_Chrome_5B}}                        
                        box{< sb/2+0.1, bh+1.1, -8        > <  sb/2-0.5, -0.1, -8.6> texture{T_Chrome_5B}}  //senkrechte vordererkannten
                        box{<-sb/2-0.1, bh+1.1, -8        > < -sb/2+0.5, -0.1, -8.6> texture{T_Chrome_5B}}  
                        stecker2                                           
                }                           
                box { <-sb/2+1, 3, -3.05-0.5>, <-sb/2+0.5, -3, -3.05+0.5> texture{col_silver}}                     // linke Loetlasche
                box { < sb/2-1, 3, -3.05-0.5>, < sb/2-0.5, -3, -3.05+0.5> texture{col_silver}}                     // rechte Loetasche                   
                cylinder{<-sb/2+0.5, bh+0.5, -8        > < -sb/2+0.5, bh+0.5, -8+bt+0.5> 0.5 texture{col_silver}}  // obere Seitenkannten abrunden       
                cylinder{< sb/2-0.5, bh+0.5, -8        > <  sb/2-0.5, bh+0.5, -8+bt+0.5> 0.5 texture{col_silver}}    
                cylinder{<-sb/2+0.5, bh+0.5, -8+bt+0.5 > <  sb/2-0.5, bh+0.5, -8+bt+0.5> 0.5 texture{col_silver}}  // obere hinterkannte 
                cylinder{<-sb/2+0.5, bh+0.5, -8        > <  sb/2-0.5, bh+0.5, -8       > 0.5 texture{col_silver}}  // obere vorderkannte                                
                cylinder{<-sb/2+0.5, bh+0.5, -8+bt+0.5 > < -sb/2+0.5, 0, -8+bt+0.5> 0.5 texture{col_silver}}       // senkrechte hinterkannten   
                cylinder{< sb/2-0.5, bh+0.5, -8+bt+0.5 > <  sb/2-0.5, 0, -8+bt+0.5> 0.5 texture{col_silver}}  
                cylinder{<-sb/2+0.5, bh+0.5, -8        > < -sb/2+0.5, 0, -8       > 0.5 texture{col_silver}}       // senkrechte vorderkannten   
                cylinder{< sb/2-0.5, bh+0.5, -8        > <  sb/2-0.5, 0, -8       > 0.5 texture{col_silver}}  
                sphere{< sb/2-0.5, bh+0.5, -8+bt+0.5> 0.5  texture{col_silver}} 
                sphere{<-sb/2+0.5, bh+0.5, -8+bt+0.5> 0.5  texture{col_silver}}                                    // Eck-Kugeln hinten
                sphere{< sb/2-0.5, bh+0.5, -8       > 0.5  texture{col_silver}} 
                sphere{<-sb/2+0.5, bh+0.5, -8       > 0.5  texture{col_silver}}                                    // Eck-Kugeln vorn
        }                                   
        #end
        
                   
           
        
        #if (schirm=2)        
        //teilgeschirmt
        #local tex_modul_metal = texture { T_Chrome_5B } ;
        #local sb = bb+0.8;
        #if (a>11)
                #local sb = 15.5+1;
        #end           
        //Metallhuelle, quaderfoermig mit abgerundeten Ecken und Kanten       
        union{          
                difference{
                        box{<-sb/2+0.5, 0, -8.5 > < sb/2-0.5, bh+0.5 ,  -8  > texture{T_Chrome_5B}}                // Frontplatte                                            
                        stecker2                                                                                   // Durchbrueche
                }                                                                                                     
                box { <-sb/2+1, 3, -3.05-0.5>, <-sb/2+0.5, -3, -3.05+0.5> texture{col_silver}}                     // linke Loetlasche
                box { < sb/2-1, 3, -3.05-0.5>, < sb/2-0.5, -3, -3.05+0.5> texture{col_silver}}                     // rechte Loetasche        
                cylinder{<-sb/2+0.5, bh, -8        > <  sb/2-0.5, bh, -8       > 0.5 texture{col_silver}}  // obere vorderkannte                                
                cylinder{<-sb/2+0.5, bh, -8        > < -sb/2+0.5, 0, -8       > 0.5 texture{col_silver}}       // senkrechte vorderkannten   
                cylinder{< sb/2-0.5, bh, -8        > <  sb/2-0.5, 0, -8       > 0.5 texture{col_silver}}  

                box{<-sb/2, 0, -8 > < -sb/2+0.4, bh ,  -2  > texture{T_Chrome_5B}}                         // linkes Seitenblech                                    
                box{< sb/2, 0, -8 > <  sb/2-0.4, bh ,  -2  > texture{T_Chrome_5B}}                         // rechtes Seitenblech  
                
                box{<-sb/2+0.5, bh, -8 > < -sb/2+2.5, bh+0.5 ,  -2  > texture{T_Chrome_5B}}                // oben links
                box{< sb/2-2.5, bh, -8 > <  sb/2-0.5, bh+0.5 ,  -2  > texture{T_Chrome_5B}}                // oben rechts      
                
                box{<sb/2-2.7, -0.50, 0><-sb/2+2.7, 0, 6> rotate<-15,0,0> translate<0, bh+0.5, -8.3> texture{T_Chrome_5B} }
                
             //   box{< sb/2-2.7, bh, -8 > < -sb/2+2.7, bh+0.5 ,  -2  > rotate<-30,0,0> texture{T_Chrome_5B} }           // oben Mitte           
                
        }               
        #end
        
           
           
        
        #if (schirm=3)        
        //teilgeschirmt
        #local tex_modul_metal = texture { T_Chrome_5B } ;
        #local sb = bb+0.8;
        #if (a>11)
                #local sb = 15.5+1;
        #end           
        //Metallhuelle, quaderfoermig mit abgerundeten Ecken und Kanten       
        union{          
                difference{
                        box{<-sb/2, 0, -8.2 > < sb/2, bh+0.4 ,  -2  > texture{T_Chrome_5B}}                      //Ummantelung                      
                        box{<-bb/2, 0, -8   > < bb/2, bh   , -8+bt  > texture{T_Chrome_5B}}                      //Aushoehlung
                        box{<-sb/2-0.1, bh+0.5, -8 > < -sb/2+0.5, bh+1.1 , -8+bt+1> texture{T_Chrome_5B}}        //obere Seitenkannten ausfraesen                  
                        box{< sb/2+0.1, bh+0.5, -8 > <  sb/2-0.5, bh+1.1 , -8+bt+1> texture{T_Chrome_5B}} 
                        stecker2 
                }                           
                box { <-sb/2+1, 3, -3.05-0.5>, <-sb/2+0.5, -3, -3.05+0.5> texture{col_silver}}                  // linke Loetlasche
                box { < sb/2-1, 3, -3.05-0.5>, < sb/2-0.5, -3, -3.05+0.5> texture{col_silver}}                  // rechte Loetasche 
        }               
        #end
        
           
           
           
	// Plastik
	difference
	{         
	        union
	        {             
		        box{<-bb/2 , 0, -5>< bb/2 , bh , -8+bt> texture{tex_rj45_pastic}}  // hinterer Teil matter
		        box{<-bb/2 , 0, -8>< bb/2 , bh , -5   > texture{tex_rj45_pastic1}} // vordere 3mm glaenzen mehr         
		}
		stecker2                                                                   // Ausspartungen fuer Stecker
		box{<-bb/2-1 , -2, -8+bt+5>< bb/2+1 , bh+2 , -8+bt+1> rotate<-20,0,0> texture{tex_rj45_pastic}}  //hintere Abschaegung  
		// Kanaele fuer Anschlussdraehte an der Oberseite der Buchse
	        pin_channel	
	        object{pin_channel  translate<+1.27     , 0, 0>}
	        #if (pins>2)
	        object { pin_channel  translate<+1.27-2.54, 0, 0>}
	        object { pin_channel  translate< 2.54     , 0, 0>}                                                             
	        #end
	        #if (pins>4)
	        object { pin_channel  translate<+1.27+2.54,0,0>}
	        object { pin_channel  translate<-2.54,0,0>}
	        #end                                                                                                   
	        #if (pins=8)
	        object { pin_channel  translate<+5.08,0,0>}
	        object { pin_channel  translate<+1.27-5.08,0,0>}
                #end
		//texture{tex_rj45_pastic}
	}       
	    
	//Panel-stops 
	#if (schirm>1)  
	          #local stop=1;
        #end

	#if (stop=1)   
	//seitliche plastik-laschen 1.4mm dick
	box{<-bb/2-1 , 3, -6.4>< -bb/2 , bh-3 , -5>  texture{tex_rj45_pastic}}
	box{< bb/2+1 , 3, -6.4><  bb/2 , bh-3 , -5>  texture{tex_rj45_pastic}}   
	#end
	
	
 
	// Plastikfuesse zur Befestigung
	difference
	{
		cylinder{< a/2, -3.5, 0>< a/2, 1, 0> 1.4}
		box{<a/2-0.3,-4,-5><a/2+0.3,-0.5,5>}
		texture{tex_rj45_pastic}
	}
	difference
	{
		cylinder{<-a/2, -3.5, 0><-a/2, 1, 0> 1.4}
		box{<-a/2-0.3,-4,-5><-a/2+0.3,-0.5,5>}
		texture{tex_rj45_pastic}
	}
     
	// Pins auf der Platine   
	// hintere Pinreihe liegt 8.89 mm hinter den Befestigungsstiften
	cylinder{<-0.635     , 1, 8.89     ><-0.635     , -3.5, 8.89     > 0.25 texture{col_gold}}   
	cylinder{<+0.635     , 1, 8.89-2.54><+0.635     , -3.5, 8.89-2.54> 0.25 texture{col_gold}}	
	#if (pins>2)	
	cylinder{<-0.635+2.54, 1, 8.89     ><-0.635+2.54, -3.5, 8.89     > 0.25 texture{col_gold}}
	cylinder{<+0.635-2.54, 1, 8.89-2.54><+0.635-2.54, -3.5, 8.89-2.54> 0.25 texture{col_gold}}  
	#end
	#if (pins>4)
	cylinder{<+0.635+2.54, 1, 8.89-2.54><+0.635+2.54, -3.5, 8.89-2.54> 0.25 texture{col_gold}}
	cylinder{<-0.635-2.54, 1, 8.89     ><-0.635-2.54, -3.5, 8.89     > 0.25 texture{col_gold}}
	#end
	#if (pins=8)
	cylinder{<-0.635+5.08, 1, 8.89     ><-0.635+5.08, -3.5, 8.89     > 0.25 texture{col_gold}}
	cylinder{<+0.635-5.08, 1, 8.89-2.54><+0.635-5.08, -3.5, 8.89-2.54> 0.25 texture{col_gold}}
	#end
        
        //Pins innerhalb der Buchse
	object { pin_intern }	
	object { pin_intern  translate<+1.27     , 0, 0>}
	#if (pins>2)
	object { pin_intern  translate<+1.27-2.54, 0, 0>}
	object { pin_intern  translate< 2.54     , 0, 0>}                                                             
	#end
	#if (pins>4)
	object { pin_intern  translate<+1.27+2.54,0,0>}
	object { pin_intern  translate<-2.54,0,0>}
	#end                                                                                                   
	#if (pins=8)
	object { pin_intern  translate<+5.08,0,0>}
	object { pin_intern  translate<+1.27-5.08,0,0>}
	#end      
	
	translate<0, 0, -o>
}
#end



#macro CON_MODULAR_RJ45()
CON_MODULAR_GRND(8, 11.43, 0, 0, 0)
#end
#macro CON_MODULAR_RJ12()
CON_MODULAR_GRND(6, 11.43, 0, 0, 0)
#end
#macro CON_MODULAR_RJ11()
CON_MODULAR_GRND(4, 11.43, 0, 0, 0)
#end
#macro CON_MODULAR_RJ45_SCH()
CON_MODULAR_GRND(8, 11.43, 0, 1, 0)
#end
#macro CON_MODULAR_RJ12_SCH()
CON_MODULAR_GRND(6, 11.43, 0, 1, 0)
#end
#macro CON_MODULAR_RJ11_SCH()
CON_MODULAR_GRND(4, 11.43, 0, 1, 0)
#end
#macro CON_MODULAR_215875_3()
CON_MODULAR_GRND(4, 6*1.27, 0, 0, 0)
#end
#macro CON_MODULAR_215876_6()
CON_MODULAR_GRND(4, 8*1.27, 0, 0, 0)
#end
#macro CON_MODULAR_215876_7()
CON_MODULAR_GRND(2, 8*1.27, 0, 0, 0)
#end
#macro CON_MODULAR_215877_4()
CON_MODULAR_GRND(8, 9*1.27, 0, 0, 0)
#end
#macro CON_MODULAR_215877_7()
CON_MODULAR_GRND(8, 9*1.27, 0, 0, 0)
#end
#macro CON_MODULAR_215878_2()
CON_MODULAR_GRND(8, 9*1.27, 0, 0, 0)
#end
#macro CON_MODULAR_555164_1()
CON_MODULAR_GRND(8, 9*1.27, 1.27, 0, 0)
#end
#macro CON_MODULAR_555165_1()
CON_MODULAR_GRND(6, 8*1.27, 1.27, 0, 0)
#end
#macro CON_MODULAR_555165_2()
CON_MODULAR_GRND(4, 8*1.27, 1.27, 0, 0)
#end
#macro CON_MODULAR_555165_5()
CON_MODULAR_GRND(2, 8*1.27, 1.27, 0, 0)
#end
#macro CON_MODULAR_555166_1()
CON_MODULAR_GRND(8, 9*1.27, 1.27, 0, 1)
#end
#macro CON_MODULAR_555165_3()
CON_MODULAR_GRND(4, 9*1.27, 1.27, 0, 1)
#end
#macro CON_MODULAR_555167_1()
CON_MODULAR_GRND(8, 9*1.27, 1.27, 0, 0)
#end
#macro CON_MODULAR_555167_2()
CON_MODULAR_GRND(6, 9*1.27, 1.27, 0, 0)
#end
#macro CON_MODULAR_555162_1()
CON_MODULAR_GRND(8, 9*1.27, 1.27, 0, 1)
#end
#macro CON_MODULAR_555163_1()
CON_MODULAR_GRND(6, 8*1.27, 1.27, 0, 1)
#end
#macro CON_MODULAR_555163_2()
CON_MODULAR_GRND(4, 8*1.27, 1.27, 0, 1)
#end
#macro CON_MODULAR_555140_1()
CON_MODULAR_GRND(6, 8*1.27, 0, 2, 1)
#end
#macro CON_MODULAR_555140_2()
CON_MODULAR_GRND(4, 8*1.27, 0, 2, 1)
#end
#macro CON_MODULAR_555153_1()
CON_MODULAR_GRND(8, 9*1.27, 0, 2, 1)
#end
#macro CON_MODULAR_555154_1()
CON_MODULAR_GRND(6, 8*1.27, 0, 2, 1)
#end
#macro CON_MODULAR_555154_2()
CON_MODULAR_GRND(4, 8*1.27, 0, 2, 1)
#end


/********************************************************************************************************************************************
//Molex 53047 ( 1.25 pitch, vertical feeding, through holes )
//antoine.drouin@free.fr
//n		Number of Pins
********************************************************************************************************************************************/
#macro CON_MOLEX_53047_GRND(n)
union{
  #local L = n * 1.25 + 1.75;
  #local l = 3.2;
  #local h = 4.2;
   difference {
     box {<-L/2, 0, -l/2><L/2, h, l/2> }
     box {<-L/2+0.6, 1.3, -l/2+0.45><L/2-0.6, h+0.1, l/2-0.45>}
     box {<-L/2+1, 2.7, 0><L/2-1, h+0.1, l/2+0.1>}
     box {<-L/2+0.35, 1.31, -0.35><L/2-0.35, h+0.1, 0.35>}
     box {<-L/2-0.1, 3.21, l/2-0.46><L/2+0.1, h+0.1, l/2+0.1>}
     #local j = 0;
     #while(j<n)
     box {<-0.35, -0.1, -l/2-0.1><0.35, 0.3, l/2+0.1>  translate< -(n-1)*1.25/2+j*1.25, 0, 0> }
     #local j = j + 1;
     #end
     box {<-L/2+1.6, 1.6, -l/2+0.46><-L/2+2.9, 2.9, -l/2-0.1>}
     box {<L/2-1.6, 1.6, -l/2+0.46><L/2-2.9, 2.9, -l/2-0.1>}
     pigment{White}
   }
  #local pin =
  union{
    cylinder {<0, 0, -0.5> <0, -2, -0.5> 0.18}
    box{<-0.2, 0 , -1 > <0.2, 3.1, 0 > }
    cylinder {<0, 1.555, -1.> <0, 1.555, 0.> 0.2 scale < 1, 2, 1>}
    texture{col_gold}
  }  
  #local i = 0;
  #while(i<n)
    object{pin translate< -(n-1)*1.25/2+i*1.25, 0, 0>}
  #local i = i + 1;
  #end

}
#end

#macro CON_MOLEX_53047_2()
CON_MOLEX_53047_GRND(2)
#end
#macro CON_MOLEX_53047_3()
CON_MOLEX_53047_GRND(3)
#end
#macro CON_MOLEX_53047_4()
CON_MOLEX_53047_GRND(4)
#end
#macro CON_MOLEX_53047_5()
CON_MOLEX_53047_GRND(5)
#end
#macro CON_MOLEX_53047_6()
CON_MOLEX_53047_GRND(6)
#end
#macro CON_MOLEX_53047_7()
CON_MOLEX_53047_GRND(7)
#end
#macro CON_MOLEX_53047_8()
CON_MOLEX_53047_GRND(8)
#end
#macro CON_MOLEX_53047_9()
CON_MOLEX_53047_GRND(9)
#end
#macro CON_MOLEX_53047_10()
CON_MOLEX_53047_GRND(10)
#end
#macro CON_MOLEX_53047_11()
CON_MOLEX_53047_GRND(11)
#end
#macro CON_MOLEX_53047_12()
CON_MOLEX_53047_GRND(12)
#end
#macro CON_MOLEX_53047_13()
CON_MOLEX_53047_GRND(13)
#end
#macro CON_MOLEX_53047_14()
CON_MOLEX_53047_GRND(14)
#end
#macro CON_MOLEX_53047_15()
CON_MOLEX_53047_GRND(15)
#end


/********************************************************************************************************************************************
// Molex 53048 ( 1.25 pitch, horizontal feeding, through holes )
//antoine.drouin@free.fr
//n		Number of Pins
********************************************************************************************************************************************/
#macro CON_MOLEX_53048_GRND(n)
union{
  #local L = n * 1.25 + 1.75;
  #local l = 5.5;
  #local h = 3.5;
  difference {
    box {<-L/2, 0, -2.3><L/2, h, 3.2> }
    box {<-L/2+0.6, 0.8, 0.3><L/2-0.6, h-0.4, 3.3>}
    box {<-L/2+1, h-0.5, 1.6><L/2-1, h+0.1, 3.3>}
    box {<-L/2-0.1, h-0.41, 2.3><L/2+0.1, h+0.1, 3.3>}
    box {<-L/2+0.6, -0.1, -2.4><L/2-0.6, 0.3, 3.3>}
    box {<-L/2+0.8, -0.1, -2.4><L/2-0.8, h+0.1, -1.58>}
    box {<-L/2+0.81, 1.3, -2.4><L/2-0.81, h+0.1, -1.>}
    box {<-L/2-0.1, h-1, -2.4><L/2+0.1, h+0.1, -1.01>}
    #local j = 0;
    #while(j<n)
        box {<-0.3, h-0.6, -1.1><0.3, h+0.1, -0.7>  translate< -(n-1)*1.25/2+j*1.25, 0, 0> }
	cylinder {<0, -0.1, -1.3> <0, h+0.1, -1.3> 0.3  translate< -(n-1)*1.25/2+j*1.25, 0, 0> }
    #local j = j + 1;
    #end
        box {<-L/2+1.6, 0, 2.7><-L/2+2.9, 0.9, 1.1>}
        box {<L/2-1.6, 0, 2.7><L/2-2.9, 2.9, 1.1>}
    pigment{White}
  }
  #local pin =
  union{
    cylinder {<0, -2.3, -1.25> <0, 1.27, -1.25> 0.18}
    cylinder {<0, 1.52, -1> <0, 1.52, -0.75> 0.18}
    intersection {
      torus { 0.25 0.18 rotate < 0, 0, 90> }
      box { < 1, 0, 0> <-1, 1, -11> }
      translate < 0, 1.27, -1>
    }
    union {
      box{<-0.2, 1.2 , -0.75 > <0.2, 2, 1.95 > }
      cylinder {<0, 1.2, 1.02> <0, 2., 1.02> 0.2 scale < 1, 1, 2>}
    }
    texture{col_gold}
  }  
  #local i = 0;
  #while(i<n)
    object{pin translate< -(n-1)*1.25/2+i*1.25, 0, 0>}
  #local i = i + 1;
  #end

}
#end

#macro CON_MOLEX_53048_2()
CON_MOLEX_53048_GRND(2)
#end
#macro CON_MOLEX_53048_3()
CON_MOLEX_53048_GRND(3)
#end
#macro CON_MOLEX_53048_4()
CON_MOLEX_53048_GRND(4)
#end
#macro CON_MOLEX_53048_5()
CON_MOLEX_53048_GRND(5)
#end
#macro CON_MOLEX_53048_6()
CON_MOLEX_53048_GRND(6)
#end
#macro CON_MOLEX_53048_7()
CON_MOLEX_53048_GRND(7)
#end
#macro CON_MOLEX_53048_8()
CON_MOLEX_53048_GRND(8)
#end
#macro CON_MOLEX_53048_9()
CON_MOLEX_53048_GRND(9)
#end
#macro CON_MOLEX_53048_10()
CON_MOLEX_53048_GRND(10)
#end
#macro CON_MOLEX_53048_11()
CON_MOLEX_53048_GRND(11)
#end
#macro CON_MOLEX_53048_12()
CON_MOLEX_53048_GRND(12)
#end
#macro CON_MOLEX_53048_13()
CON_MOLEX_53048_GRND(13)
#end
#macro CON_MOLEX_53048_14()
CON_MOLEX_53048_GRND(14)
#end
#macro CON_MOLEX_53048_15()
CON_MOLEX_53048_GRND(15)
#end


/********************************************************************************************************************************************
// Tilmann Reh <tilmann.reh@autometer.de>
// gerade Molex-Stiftleisten RM 2.54.
// Bezugspunkt: Mitte der Pins auf PCB-Oberfläche
********************************************************************************************************************************************/
#macro CON_MOLEX_PSL_XX_G_GRND(Pins)
union{
object{MOLEX254(Pins)}
object{PIN_STRAIGHT_ROW (Pins,2.54,0.635,11,3,col_silver)}}
#end
#macro CON_MOLEX_PSL2G()
CON_MOLEX_PSL_XX_G_GRND(2)
#end
#macro CON_MOLEX_PSL3G()
CON_MOLEX_PSL_XX_G_GRND(3)
#end
#macro CON_MOLEX_PSL4G()
CON_MOLEX_PSL_XX_G_GRND(4)
#end
#macro CON_MOLEX_PSL5G()
CON_MOLEX_PSL_XX_G_GRND(5)
#end
#macro CON_MOLEX_PSL6G()
CON_MOLEX_PSL_XX_G_GRND(6)
#end
#macro CON_MOLEX_PSL7G()
CON_MOLEX_PSL_XX_G_GRND(7)
#end
#macro CON_MOLEX_PSL8G()
CON_MOLEX_PSL_XX_G_GRND(8)
#end
#macro CON_MOLEX_PSL9G()
CON_MOLEX_PSL_XX_G_GRND(9)
#end
#macro CON_MOLEX_PSL10G()
CON_MOLEX_PSL_XX_G_GRND(10)
#end


/********************************************************************************************************************************************
// Tilmann Reh <tilmann.reh@autometer.de>
// abgewinkelte Molex-Stiftleisten RM 2.54.
// Bezugspunkt: Mitte der Pins auf PCB-Oberfläche
********************************************************************************************************************************************/
#macro CON_MOLEX_PSL_XX_W_GRND(Pins)
union{
object{MOLEX254(Pins) rotate<-90,0,0> translate<0,2.5,-1.8>}
object{PIN_BENDED_ROW (Pins,2.54,0.635,0.8,2.5,3,12.5,col_silver) translate<0,0,0>}}
#end


#macro CON_MOLEX_PSL2W()
CON_MOLEX_PSL_XX_W_GRND(2)
#end
#macro CON_MOLEX_PSL3W()
CON_MOLEX_PSL_XX_W_GRND(3)
#end
#macro CON_MOLEX_PSL4W()
CON_MOLEX_PSL_XX_W_GRND(4)
#end
#macro CON_MOLEX_PSL5W()
CON_MOLEX_PSL_XX_W_GRND(5)
#end
#macro CON_MOLEX_PSL6W()
CON_MOLEX_PSL_XX_W_GRND(6)
#end
#macro CON_MOLEX_PSL7W()
CON_MOLEX_PSL_XX_W_GRND(7)
#end
#macro CON_MOLEX_PSL8W()
CON_MOLEX_PSL_XX_W_GRND(8)
#end
#macro CON_MOLEX_PSL9W()
CON_MOLEX_PSL_XX_W_GRND(9)
#end
#macro CON_MOLEX_PSL10W()
CON_MOLEX_PSL_XX_W_GRND(10)
#end


/********************************************************************************************************************************************
// PC power connector male
********************************************************************************************************************************************/
#macro CON_PCPWR514M_GRND()
union{
        difference {
        box{<0,0,0><23.2,10,8.4> translate <-11.6,0.5,-4.20> }
        box{<0,0,0><21,8,6.4> translate <-10.5,2.6,-3.20> }
        }
     box{<0,0,0><1,3,3> translate <-12.6,0.5,-1.5> }
     box{<0,0,0><1,3,3> translate <11.6,0.5,-1.5> }

     box{<0,0,0><3,10,1.5> rotate <0,-45,0> translate <-10.5,0.5,1> }
     box{<0,0,0><3,10,1.5> rotate <0,45,0> translate <8.5,0.5,3.1> }


     #local p = 0;
     #while(p<5)    
        box{<0,0,0><1.5,3,1> translate <-11.6+p*5,0.5,-5.2> }
     #local p = p+1;
     #end


     #local p = 0;
     #while(p<4)    
             cylinder {<0,0,0><0,12.5,0> 0.8 translate <-7.5+p*5.08,-3.5,0> texture{col_gold}}
             sphere {<-7.5+p*5.08,9,0> 0.8 texture{col_gold}}   
     #local p = p+1;
     #end
 }        

 pigment{VLightGray}
 rotate <0,-90,0>
 
#end
#macro CON_PCPWR514M()
CON_PCPWR514M_GRND()
#end


/********************************************************************************************************************************************
//Stefan Seegel <post(replace with at)seegel-systeme.de
//SMD Stiftleisten 2-reihig RM 2.0
********************************************************************************************************************************************/
#macro CON_PH2SMD_2MM_GRND(Pins)
union
{
	object{PIN_BENDED_ROW (Pins, 2.00, 0.5, 0.8, 1.75, 0, 6.77, col_gold) rotate<90,0,0> translate<0,0.25,-2.75>}
	object{PIN_BENDED_ROW (Pins, 2.00, 0.5, 0.8, 1.75, 0, 6.77, col_gold) rotate<90,180,0> translate<0,0.25,2.75>}
	difference
	{
		box{<-Pins, 0.6, -2><Pins,2.6, 2> pigment{Gray30} translate<0,0,0>}
		//box{<0,-1.27,-1.27><2,1.27,1.27> pigment{Gray30} translate<0,0,0>}
		box{<-Pins-0.5,0.9,-1.7><Pins + 0.5, 2.3,1.7> pigment{Gray30} rotate<45,0,0> translate<0,1.5,1.5>}
		box{<-Pins-0.5,0.9,-1.7><Pins + 0.5, 2.3,1.7> pigment{Gray30} rotate<-45,0,0> translate<0,1.5,-1.5>}
	}
}
#end


#macro CON_PHSMD_2MM_2X2()
CON_PH2SMD_2MM_GRND(2)
#end
#macro CON_PHSMD_2MM_2X3()
CON_PH2SMD_2MM_GRND(3)
#end
#macro CON_PHSMD_2MM_2X4()
CON_PH2SMD_2MM_GRND(4)
#end
#macro CON_PHSMD_2MM_2X5()
CON_PH2SMD_2MM_GRND(5)
#end
#macro CON_PHSMD_2MM_2X6()
CON_PH2SMD_2MM_GRND(6)
#end
#macro CON_PHSMD_2MM_2X7()
CON_PH2SMD_2MM_GRND(7)
#end
#macro CON_PHSMD_2MM_2X8()
CON_PH2SMD_2MM_GRND(8)
#end
#macro CON_PHSMD_2MM_2X9()
CON_PH2SMD_2MM_GRND(9)
#end
#macro CON_PHSMD_2MM_2X10()
CON_PH2SMD_2MM_GRND(10)
#end
#macro CON_PHSMD_2MM_2X11()
CON_PH2SMD_2MM_GRND(11)
#end
#macro CON_PHSMD_2MM_2X12()
CON_PH2SMD_2MM_GRND(12)
#end
#macro CON_PHSMD_2MM_2X13()
CON_PH2SMD_2MM_GRND(13)
#end
#macro CON_PHSMD_2MM_2X14()
CON_PH2SMD_2MM_GRND(14)
#end
#macro CON_PHSMD_2MM_2X15()
CON_PH2SMD_2MM_GRND(15)
#end
#macro CON_PHSMD_2MM_2X16()
CON_PH2SMD_2MM_GRND(16)
#end


/********************************************************************************************************************************************
//Macros fuer Phoenix Mini-Combicon 3.81mm Klemmen und Gegenstecker
//Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
//Privat: <fbleikamp@web.de>
//Grundmacro fuer Phoenix Mini-Combicon 3.81mm Klemmen Winkel (horizontal) mit Gegenstecker
********************************************************************************************************************************************/
#macro CON_PHOENIX_381_PHGGHWS_GRND(j)
union{
	#local i = 0;
	#while(i<j)
		object {CON_PHOENIX_381_PHPINW() translate<0,0,i*3.81>}
		object {CON_PHOENIX_381_PHGH() translate<0,0,i*3.81>}
		object {CON_PHOENIX_381_PHGSG() translate<8,-2.9,i*3.81>}
		object {CON_PHOENIX_381_SCREWHEAD()rotate<0,i*75,0> translate<12,7.2,i*3.81> texture{col_silver}}
		object {CON_PHOENIX_381_PHNR(i+1) rotate <78,0,0> translate <0,5.9,16.0> translate<-i*3.81,0,0> rotate<0,90,0> }
	#local i=i+1;
	#end
	translate<0,0,-j*1.905+1.905> rotate<0,90,0>
}
#end
#macro CON_PHOENIX_381_MC_2G()
CON_PHOENIX_381_PHGGHWS_GRND(2)
#end
#macro CON_PHOENIX_381_MC_3G()
CON_PHOENIX_381_PHGGHWS_GRND(3)
#end
#macro CON_PHOENIX_381_MC_4G()
CON_PHOENIX_381_PHGGHWS_GRND(4)
#end
#macro CON_PHOENIX_381_MC_5G()
CON_PHOENIX_381_PHGGHWS_GRND(5)
#end
#macro CON_PHOENIX_381_MC_6G()
CON_PHOENIX_381_PHGGHWS_GRND(6)
#end
#macro CON_PHOENIX_381_MC_7G()
CON_PHOENIX_381_PHGGHWS_GRND(7)
#end
#macro CON_PHOENIX_381_MC_8G()
CON_PHOENIX_381_PHGGHWS_GRND(8)
#end
#macro CON_PHOENIX_381_MC_9G()
CON_PHOENIX_381_PHGGHWS_GRND(9)
#end
#macro CON_PHOENIX_381_MC_10G()
CON_PHOENIX_381_PHGGHWS_GRND(10)
#end
#macro CON_PHOENIX_381_MC_11G()
CON_PHOENIX_381_PHGGHWS_GRND(11)
#end
#macro CON_PHOENIX_381_MC_12G()
CON_PHOENIX_381_PHGGHWS_GRND(12)
#end
#macro CON_PHOENIX_381_MC_13G()
CON_PHOENIX_381_PHGGHWS_GRND(13)
#end


/********************************************************************************************************************************************
//Macros fuer Phoenix Mini-Combicon 3.81mm Klemmen und Gegenstecker
//Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
//Privat: <fbleikamp@web.de>
//Grundmacro fuer Phoenix Mini-Combicon 3.81mm Klemmen Winkel MC 1,5/xx-G-381 (horizontal)
********************************************************************************************************************************************/
#macro CON_PHOENIX_381_PHGGHW_GRND(j)
union{
	#local i = 0;
	#while(i<j)
		object {CON_PHOENIX_381_PHPINW() translate<0,0,i*3.81>}
		object {CON_PHOENIX_381_PHGH() translate<0,0,i*3.81>}
		#local i=i+1;
	#end
	translate<0,0,-j*1.905+1.905> rotate<0,90,0>
}
#end
#macro CON_PHOENIX_381_MC_2()
CON_PHOENIX_381_PHGGHW_GRND(2)
#end
#macro CON_PHOENIX_381_MC_3()
CON_PHOENIX_381_PHGGHW_GRND(3)
#end
#macro CON_PHOENIX_381_MC_4()
CON_PHOENIX_381_PHGGHW_GRND(4)
#end
#macro CON_PHOENIX_381_MC_5()
CON_PHOENIX_381_PHGGHW_GRND(5)
#end
#macro CON_PHOENIX_381_MC_6()
CON_PHOENIX_381_PHGGHW_GRND(6)
#end
#macro CON_PHOENIX_381_MC_7()
CON_PHOENIX_381_PHGGHW_GRND(7)
#end
#macro CON_PHOENIX_381_MC_8()
CON_PHOENIX_381_PHGGHW_GRND(8)
#end
#macro CON_PHOENIX_381_MC_9()
CON_PHOENIX_381_PHGGHW_GRND(9)
#end
#macro CON_PHOENIX_381_MC_10()
CON_PHOENIX_381_PHGGHW_GRND(10)
#end
#macro CON_PHOENIX_381_MC_11()
CON_PHOENIX_381_PHGGHW_GRND(11)
#end
#macro CON_PHOENIX_381_MC_12()
CON_PHOENIX_381_PHGGHW_GRND(12)
#end
#macro CON_PHOENIX_381_MC_13()
CON_PHOENIX_381_PHGGHW_GRND(13)
#end


/********************************************************************************************************************************************
//Macros fuer Phoenix Mini-Combicon 3.81mm Klemmen und Gegenstecker
//Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
//Privat: <fbleikamp@web.de>
//Grundmacro fuer Phoenix Mini-Combicon 3.81mm Klemmen MCV 1,5/xx-G-381 (vertical)
********************************************************************************************************************************************/
#macro CON_PHOENIX_381_PHGGH_GRND(j)
union{
	#local i = 0;
	#while(i<j)
		object {CON_PHOENIX_381_PHPIN() translate<0,0,i*3.81>}
		object {CON_PHOENIX_381_PHGH()rotate<0,0,90> translate<3,0,i*3.81>}
		#local i=i+1;
	#end
	translate<0,1,-j*1.905+1.905>
	rotate<0,90,0>
}
#end
#macro CON_PHOENIX_381_MCV_2()
CON_PHOENIX_381_PHGGH_GRND(2)
#end
#macro CON_PHOENIX_381_MCV_3()
CON_PHOENIX_381_PHGGH_GRND(3)
#end
#macro CON_PHOENIX_381_MCV_4()
CON_PHOENIX_381_PHGGH_GRND(4)
#end
#macro CON_PHOENIX_381_MCV_5()
CON_PHOENIX_381_PHGGH_GRND(5)
#end
#macro CON_PHOENIX_381_MCV_6()
CON_PHOENIX_381_PHGGH_GRND(6)
#end
#macro CON_PHOENIX_381_MCV_7()
CON_PHOENIX_381_PHGGH_GRND(7)
#end
#macro CON_PHOENIX_381_MCV_8()
CON_PHOENIX_381_PHGGH_GRND(8)
#end
#macro CON_PHOENIX_381_MCV_9()
CON_PHOENIX_381_PHGGH_GRND(9)
#end
#macro CON_PHOENIX_381_MCV_10()
CON_PHOENIX_381_PHGGH_GRND(10)
#end
#macro CON_PHOENIX_381_MCV_11()
CON_PHOENIX_381_PHGGH_GRND(11)
#end
#macro CON_PHOENIX_381_MCV_12()
CON_PHOENIX_381_PHGGH_GRND(12)
#end
#macro CON_PHOENIX_381_MCV_13()
CON_PHOENIX_381_PHGGH_GRND(13)
#end


/********************************************************************************************************************************************
//Macros fuer Phoenix Mini-Combicon 3.81mm Klemmen und Gegenstecker
//Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
//Privat: <fbleikamp@web.de>
//Grundmacro fuer Phoenix Mini-Combicon 3.81mm Gegenstecker (vertikal)
// MCVW 1,5/xx-ST-381 (k=0) und MCVR 1,5/xx-ST-381 (k=1)
********************************************************************************************************************************************/
#macro CON_PHOENIX_381_PHMCVRW_GRND(j,k)
union{
	#local i = 0;
	#while(i<j)
		object {CON_PHOENIX_381_PHGSRW(k) translate<-i*3.81,0,0>}
		object {CON_PHOENIX_381_SCREWHEAD()rotate<0,i*75,0> translate<-i*3.81,11.7,0> texture{col_silver}}
		object {CON_PHOENIX_381_PHNR(i+1) rotate <70,0,0> translate <0,9.5,3.0> translate<-i*3.81,0,0> }
		#local i=i+1;
	#end

	#if (k = 1) //MVCR
		translate<j*1.905-1.905,9.0,0> rotate<0,0,0>}
	#else
		translate<j*1.905-1.905,9.0,0> rotate<0,180,0>}
	#end
#end

//Phoenix Mini-Combicon 3.81mm Gegenstecker MCVW 1,5/xx-ST-381
#macro CON_PHOENIX_381_MCVW_2()
CON_PHOENIX_381_PHMCVRW_GRND(2,0)
#end
#macro CON_PHOENIX_381_MCVW_3()
CON_PHOENIX_381_PHMCVRW_GRND(3,0)
#end
#macro CON_PHOENIX_381_MCVW_4()
CON_PHOENIX_381_PHMCVRW_GRND(4,0)
#end
#macro CON_PHOENIX_381_MCVW_5()
CON_PHOENIX_381_PHMCVRW_GRND(5,0)
#end
#macro CON_PHOENIX_381_MCVW_6()
CON_PHOENIX_381_PHMCVRW_GRND(6,0)
#end
#macro CON_PHOENIX_381_MCVW_7()
CON_PHOENIX_381_PHMCVRW_GRND(7,0)
#end
#macro CON_PHOENIX_381_MCVW_8()
CON_PHOENIX_381_PHMCVRW_GRND(8,0)
#end
#macro CON_PHOENIX_381_MCVW_9()
CON_PHOENIX_381_PHMCVRW_GRND(9,0)
#end
#macro CON_PHOENIX_381_MCVW_10()
CON_PHOENIX_381_PHMCVRW_GRND(10,0)
#end
#macro CON_PHOENIX_381_MCVW_11()
CON_PHOENIX_381_PHMCVRW_GRND(11,0)
#end
#macro CON_PHOENIX_381_MCVW_12()
CON_PHOENIX_381_PHMCVRW_GRND(12,0)
#end
#macro CON_PHOENIX_381_MCVW_13()
CON_PHOENIX_381_PHMCVRW_GRND(13,0)
#end
//Phoenix Mini-Combicon 3.81mm Gegenstecker MCVR 1,5/xx-ST-381
#macro CON_PHOENIX_381_MCVR_2()
CON_PHOENIX_381_PHMCVRW_GRND(2,1)
#end
#macro CON_PHOENIX_381_MCVR_3()
CON_PHOENIX_381_PHMCVRW_GRND(3,1)
#end
#macro CON_PHOENIX_381_MCVR_4()
CON_PHOENIX_381_PHMCVRW_GRND(4,1)
#end
#macro CON_PHOENIX_381_MCVR_5()
CON_PHOENIX_381_PHMCVRW_GRND(5,1)
#end
#macro CON_PHOENIX_381_MCVR_6()
CON_PHOENIX_381_PHMCVRW_GRND(6,1)
#end
#macro CON_PHOENIX_381_MCVR_7()
CON_PHOENIX_381_PHMCVRW_GRND(7,1)
#end
#macro CON_PHOENIX_381_MCVR_8()
CON_PHOENIX_381_PHMCVRW_GRND(8,1)
#end
#macro CON_PHOENIX_381_MCVR_9()
CON_PHOENIX_381_PHMCVRW_GRND(9,1)
#end
#macro CON_PHOENIX_381_MCVR_10()
CON_PHOENIX_381_PHMCVRW_GRND(10,1)
#end
#macro CON_PHOENIX_381_MCVR_11()
CON_PHOENIX_381_PHMCVRW_GRND(11,1)
#end
#macro CON_PHOENIX_381_MCVR_12()
CON_PHOENIX_381_PHMCVRW_GRND(12,1)
#end
#macro CON_PHOENIX_381_MCVR_13()
CON_PHOENIX_381_PHMCVRW_GRND(13,1)
#end


/********************************************************************************************************************************************
//Macros fuer Phoenix Mini-Combicon 3.81mm Klemmen und Gegenstecker
//Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
//Privat: <fbleikamp@web.de>
//Grundmacro fuer Phoenix Mini-Combicon 3.81mm Gegenstecker MC 1,5/xx-ST-381 (horizontal)
********************************************************************************************************************************************/
#macro CON_PHOENIX_381_PHWS_GRND(j)
union{
	#local i = 0;
	#while(i<j)
		object {CON_PHOENIX_381_PHGSG() translate<8,-2.9,i*3.81>}
		object {CON_PHOENIX_381_SCREWHEAD()rotate<0,i*75,0> translate<12,7.2,i*3.81> texture{col_silver}}
		object {CON_PHOENIX_381_PHNR(i+1) rotate <78,0,0> translate <0,5.9,16.0> translate<-i*3.81,0,0> rotate<0,90,0> }
		#local i=i+1;
	#end
	translate<0,0,-j*1.905+1.905> rotate<0,90,0>
}
#end
#macro CON_PHOENIX_381_MC_2ST()
CON_PHOENIX_381_PHWS_GRND(2)
#end
#macro CON_PHOENIX_381_MC_3ST()
CON_PHOENIX_381_PHWS_GRND(3)
#end
#macro CON_PHOENIX_381_MC_4ST()
CON_PHOENIX_381_PHWS_GRND(4)
#end
#macro CON_PHOENIX_381_MC_5ST()
CON_PHOENIX_381_PHWS_GRND(5)
#end
#macro CON_PHOENIX_381_MC_6ST()
CON_PHOENIX_381_PHWS_GRND(6)
#end
#macro CON_PHOENIX_381_MC_7ST()
CON_PHOENIX_381_PHWS_GRND(7)
#end
#macro CON_PHOENIX_381_MC_8ST()
CON_PHOENIX_381_PHWS_GRND(8)
#end
#macro CON_PHOENIX_381_MC_9ST()
CON_PHOENIX_381_PHWS_GRND(9)
#end
#macro CON_PHOENIX_381_MC_10ST()
CON_PHOENIX_381_PHWS_GRND(10)
#end
#macro CON_PHOENIX_381_MC_11ST()
CON_PHOENIX_381_PHWS_GRND(11)
#end
#macro CON_PHOENIX_381_MC_12ST()
CON_PHOENIX_381_PHWS_GRND(12)
#end
#macro CON_PHOENIX_381_MC_13ST()
CON_PHOENIX_381_PHWS_GRND(13)
#end


/********************************************************************************************************************************************
//Macros for connector PHOENIX type MINICONNEC 5.08
//Designed by Philippe Boucheny <philippe.boucheny(replace with at)free.fr>
//Rev. 1.1  06/01/06
********************************************************************************************************************************************/
#macro CON_PHOENIX_508_GRND(n,vertical,a)
// n = pins ; Vertical = 1 if yes ; With border a = 1 / Whithout border a = 0
union{
    difference{
        union{
            #local PAS = 5.08;
            //body
        	box{<-PAS*n/2-a,-4.15,0><+PAS*n/2+a,4.15,12> }
        	//up additional thickness
        	box{<-PAS*n/2-a,+4.15,9><+PAS*n/2+a,4.15+0.5,12> }
         }
         
         union{
            
            #local i=0; 
            #while (i<n)
                //Half Cylindrical holes
                intersection{
                    cylinder{<-(PAS/2*(n-1))+(i*PAS),0.35,2.5><-(PAS/2*(n-1))+(i*PAS),0.35,12.1> 4 }
                    box{<-(PAS/2*(n-1))+(i*PAS)+2.541,+0.1,2.51><-(PAS/2*(n-1))+(i*PAS)-2.541,-5.1,12.1> }
                }
                //Crenels at the top
                box{<-(PAS/2*(n-1))+(i*PAS)+1,3,11><-(PAS/2*(n-1))+(i*PAS)-1,6,12.5> }
                //Crenels for pins
                box{<-(PAS/2*(n-1))+(i*PAS)+0.5,0,-0.1><-(PAS/2*(n-1))+(i*PAS)-0.5,-6,2> }
                box{<-(PAS/2*(n-1))+(i*PAS)+1.5,-4,-0.1><-(PAS/2*(n-1))+(i*PAS)-1.5,-6,3> }
             #local i=i+1; #end
          
             //Half squared hole               
             box{<-PAS*n/2-0.01,0,2.5><+PAS*n/2+0.01,3.25,12.1> }
                                     
            //bisel   
        	box{<-PAS*n/2-a-0.1,+4.15,9><+PAS*n/2+a+0.1,4.15+0.7,12> rotate 20*x translate 4*y}
        	
         }
         pigment{ForestGreen}
    }
    #if(vertical)
        #local i=0; #while (i<n)
            union{
                //pin body
                box{<-(PAS/2*(n-1))+(i*PAS)-0.4,-0.4,-4><-(PAS/2*(n-1))+(i*PAS)+0.4,+0.4,9> }
                //pin top
                intersection{
                    box{<-(PAS/2*(n-1))+(i*PAS)-0.4,-0.4,9><-(PAS/2*(n-1))+(i*PAS)+0.4,+0.4,10> }
                    cone{<-(PAS/2*(n-1))+(i*PAS),0,9>, 0.565, <-(PAS/2*(n-1))+(i*PAS),0,10.01>, 0.25}
                }
                texture { pigment{P_Silver2} }
            }
        #local i=i+1; #end
        rotate <-90,180,0>
    #else
        #local i=0; #while (i<n)
            //inside part pin
            union{
                //pin body
                box{<-(PAS/2*(n-1))+(i*PAS)-0.4,-0.4,2><-(PAS/2*(n-1))+(i*PAS)+0.4,+0.4,9> texture { pigment{P_Silver2} }}
                //pin top
                intersection{
                    box{<-(PAS/2*(n-1))+(i*PAS)-0.4,-0.4,9><-(PAS/2*(n-1))+(i*PAS)+0.4,+0.4,10> }
                    cone{<-(PAS/2*(n-1))+(i*PAS),0,9>, 0.565, <-(PAS/2*(n-1))+(i*PAS),0,10.01>, 0.25}
                }
                texture { pigment{P_Silver2} }
            }


            //outside part pin
            box{<-(PAS/2*(n-1))+(i*PAS)-0.4,0,1.1><-(PAS/2*(n-1))+(i*PAS)+0.4,-7.5,1.9> texture { pigment{P_Silver2} }}
        #local i=i+1; #end
        translate <0,4.1,-5.08-1.5> //-1.5>
        rotate 180*y
    #end
}
#end
// Vertical whithout border
#macro CON_PHOENIX_508_MSTBV_2()
CON_PHOENIX_508_GRND(2,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_3()
CON_PHOENIX_508_GRND(3,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_4()
CON_PHOENIX_508_GRND(4,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_5()
CON_PHOENIX_508_GRND(5,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_6()
CON_PHOENIX_508_GRND(6,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_7()
CON_PHOENIX_508_GRND(7,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_8()
CON_PHOENIX_508_GRND(8,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_9()
CON_PHOENIX_508_GRND(9,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_10()
CON_PHOENIX_508_GRND(10,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_11()
CON_PHOENIX_508_GRND(11,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_12()
CON_PHOENIX_508_GRND(12,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_13()
CON_PHOENIX_508_GRND(13,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_14()
CON_PHOENIX_508_GRND(14,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_15()
CON_PHOENIX_508_GRND(15,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_16()
CON_PHOENIX_508_GRND(16,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_17()
CON_PHOENIX_508_GRND(17,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_18()
CON_PHOENIX_508_GRND(18,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_19()
CON_PHOENIX_508_GRND(19,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_20()
CON_PHOENIX_508_GRND(20,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_21()
CON_PHOENIX_508_GRND(21,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_22()
CON_PHOENIX_508_GRND(22,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_23()
CON_PHOENIX_508_GRND(23,1,0)
#end
#macro CON_PHOENIX_508_MSTBV_24()
CON_PHOENIX_508_GRND(24,1,0)
#end
// Horizontal whithout border
#macro CON_PHOENIX_508_MSTB_2()
CON_PHOENIX_508_GRND(2,0,0)
#end
#macro CON_PHOENIX_508_MSTB_3()
CON_PHOENIX_508_GRND(3,0,0)
#end
#macro CON_PHOENIX_508_MSTB_4()
CON_PHOENIX_508_GRND(4,0,0)
#end
#macro CON_PHOENIX_508_MSTB_5()
CON_PHOENIX_508_GRND(5,0,0)
#end
#macro CON_PHOENIX_508_MSTB_6()
CON_PHOENIX_508_GRND(6,0,0)
#end
#macro CON_PHOENIX_508_MSTB_7()
CON_PHOENIX_508_GRND(7,0,0)
#end
#macro CON_PHOENIX_508_MSTB_8()
CON_PHOENIX_508_GRND(8,0,0)
#end
#macro CON_PHOENIX_508_MSTB_9()
CON_PHOENIX_508_GRND(9,0,0)
#end
#macro CON_PHOENIX_508_MSTB_10()
CON_PHOENIX_508_GRND(10,0,0)
#end
#macro CON_PHOENIX_508_MSTB_11()
CON_PHOENIX_508_GRND(11,0,0)
#end
#macro CON_PHOENIX_508_MSTB_12()
CON_PHOENIX_508_GRND(12,0,0)
#end
#macro CON_PHOENIX_508_MSTB_13()
CON_PHOENIX_508_GRND(13,0,0)
#end
#macro CON_PHOENIX_508_MSTB_14()
CON_PHOENIX_508_GRND(14,0,0)
#end
#macro CON_PHOENIX_508_MSTB_15()
CON_PHOENIX_508_GRND(15,0,0)
#end
#macro CON_PHOENIX_508_MSTB_16()
CON_PHOENIX_508_GRND(16,0,0)
#end
#macro CON_PHOENIX_508_MSTB_17()
CON_PHOENIX_508_GRND(17,0,0)
#end
#macro CON_PHOENIX_508_MSTB_18()
CON_PHOENIX_508_GRND(18,0,0)
#end
#macro CON_PHOENIX_508_MSTB_19()
CON_PHOENIX_508_GRND(19,0,0)
#end
#macro CON_PHOENIX_508_MSTB_20()
CON_PHOENIX_508_GRND(20,0,0)
#end
#macro CON_PHOENIX_508_MSTB_21()
CON_PHOENIX_508_GRND(21,0,0)
#end
#macro CON_PHOENIX_508_MSTB_22()
CON_PHOENIX_508_GRND(22,0,0)
#end
#macro CON_PHOENIX_508_MSTB_23()
CON_PHOENIX_508_GRND(23,0,0)
#end
#macro CON_PHOENIX_508_MSTB_24()
CON_PHOENIX_508_GRND(24,0,0)
#end
// Vertical whith border
#macro CON_PHOENIX_508_MSTBVA_2()
CON_PHOENIX_508_GRND(2,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_3()
CON_PHOENIX_508_GRND(3,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_4()
CON_PHOENIX_508_GRND(4,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_5()
CON_PHOENIX_508_GRND(5,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_6()
CON_PHOENIX_508_GRND(6,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_7()
CON_PHOENIX_508_GRND(7,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_8()
CON_PHOENIX_508_GRND(8,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_9()
CON_PHOENIX_508_GRND(9,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_10()
CON_PHOENIX_508_GRND(10,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_11()
CON_PHOENIX_508_GRND(11,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_12()
CON_PHOENIX_508_GRND(12,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_13()
CON_PHOENIX_508_GRND(13,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_14()
CON_PHOENIX_508_GRND(14,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_15()
CON_PHOENIX_508_GRND(15,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_16()
CON_PHOENIX_508_GRND(16,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_17()
CON_PHOENIX_508_GRND(17,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_18()
CON_PHOENIX_508_GRND(18,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_19()
CON_PHOENIX_508_GRND(19,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_20()
CON_PHOENIX_508_GRND(20,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_21()
CON_PHOENIX_508_GRND(21,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_22()
CON_PHOENIX_508_GRND(22,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_23()
CON_PHOENIX_508_GRND(23,1,1)
#end
#macro CON_PHOENIX_508_MSTBVA_24()
CON_PHOENIX_508_GRND(24,1,1)
#end
// Horizontal whith border
#macro CON_PHOENIX_508_MSTBA_2()
CON_PHOENIX_508_GRND(2,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_3()
CON_PHOENIX_508_GRND(3,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_4()
CON_PHOENIX_508_GRND(4,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_5()
CON_PHOENIX_508_GRND(5,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_6()
CON_PHOENIX_508_GRND(6,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_7()
CON_PHOENIX_508_GRND(7,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_8()
CON_PHOENIX_508_GRND(8,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_9()
CON_PHOENIX_508_GRND(9,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_10()
CON_PHOENIX_508_GRND(10,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_11()
CON_PHOENIX_508_GRND(11,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_12()
CON_PHOENIX_508_GRND(12,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_13()
CON_PHOENIX_508_GRND(13,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_14()
CON_PHOENIX_508_GRND(14,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_15()
CON_PHOENIX_508_GRND(15,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_16()
CON_PHOENIX_508_GRND(16,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_17()
CON_PHOENIX_508_GRND(17,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_18()
CON_PHOENIX_508_GRND(18,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_19()
CON_PHOENIX_508_GRND(19,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_20()
CON_PHOENIX_508_GRND(20,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_21()
CON_PHOENIX_508_GRND(21,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_22()
CON_PHOENIX_508_GRND(22,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_23()
CON_PHOENIX_508_GRND(23,0,1)
#end
#macro CON_PHOENIX_508_MSTBA_24()
CON_PHOENIX_508_GRND(24,0,1)
#end


/********************************************************************************************************************************************
//ChristophGraf@web.de
********************************************************************************************************************************************/
#macro CON_PHONE_JACK_GRND(value)

union{
        #if(pin_short=off)
                #local pp=7.0;
        #else
                #local pp=pcb_height+pin_length;
        #end
        
        difference{
                box{<-7.1882,-0.1,5.9182><7.1882,5,-5.9182> pigment{Black}}
                box{<-6.4882,-0.2,5.2182><6.4882,6,-5.2182> pigment{Black}}}

               box{<-7.1882,5,5.9182><7.1882,6,-5.9182> pigment{White filter 0.91}}
               box{<-7.1882,0,5.9182><7.1882,1,-5.9182> pigment{Black}}
           

        
        difference{
        cylinder { < -7.1882 , 3 , 0 >,< -10.7442, 3 , 0 >,2.6  pigment{White}}
        cylinder { < -7.1882 , 3 , 0 >,< -11.7442, 3 , 0 >,1.75  pigment{White}}
          }
        union{
                lathe { linear_spline 13,<2.6, -10.7442>,<2.9, -10.4442>, <2.6, -10.1442>,<2.9, -9.8442>,<2.6, -9.5442>,
                <2.9, -9.2442>,<2.6, -8.9442>,<2.9, -8.6442>,<2.6, -8.3442>,<2.9, -8.0442>,
                <2.6, -7.7442>,<2.9, -7.4442>,<2.6, -7.1442>pigment {Silver} } 
                rotate<0,0,-90>
                translate<0,3,0> 
             }

        
        union{
                cylinder{<2.8494,2,4.8996>,<2.8494,-pp,4.8996>,0.25 }
                cylinder{<-4.9979,2,-0.2035>,<-4.9979,-pp,-0.2035>,0.25 }
                cylinder{<1.4575,2,2.3985>,<1.4575,-pp,2.3985>,0.25 }  
                cylinder{<-1.75,2,-4.9032>,<-1.75,-pp,-4.9032>,0.25 }
                cylinder{<5.7543,2,-4.3787>,<5.7543,-pp,-4.3787>,0.25 }
                pigment{Silver}
        }
        union{
               box{<3.5543,1,-1.3><5.85,5,-1.6> pigment{Silver}}
               box{<5.5543,1,-4.3787><5.85,5,-0.4787> pigment{Silver}} 
               prism{linear_sweep 0,5,11,            // segment "A"
                <-1.45,-4.6032>,<-5.55,-4.6032>,<-1.25,-0.5332>,<-0.55,-2.1332>,<4.75,-2.1332>,
                <4.75,-1.8332>,<-0.35,-1.8332>,<-1.1436,-0.0194>,<-5.9492,-4.568>,<-5.8324,-4.9032>,<-1.45,-4.9032>
                pigment{Silver}}
               prism{linear_sweep 0,5,13,            // segment "A"
                <2.8494,5.1996>,<6.6829,5.1996>,<6.6829,2.8981>,<-2.2639,2.812>,<-3.2967,0.7465>,
                <-4.5539,3.0096>,<-4.2139,3.0152>,<-3.3106,1.3894>,<-2.4502,3.1104>,<6.2829,3.1954>,<6.2829,4.8996>,<2.8494,4.8996>,<2.8494,5.1996>
                pigment{Silver}} 
                 prism{linear_sweep 0,5,5,            // segment "A"
                <-2.2125,2.3985>,<2.5575,2.3985>,<2.5575,2.6985>,<-2.2125,2.6985>,<-2.2125,2.3985>
                pigment{Silver}}
        }

}
#end

#macro CON_PHONE_JACK(value)
CON_PHONE_JACK_GRND(value)
#end


/********************************************************************************************************************************************
//Designed by Friedrich Bleikamp, Lenord, Bauer & Co. Gmbh <fbleikamp@lenord.de>
//Privat: <fbleikamp@web.de>
//Grundmakro Stiftleisten Winkel (Macro aus connector.inc abgewandelt)
//a = Reihen
//b = Pins
********************************************************************************************************************************************/
#macro CON_PHW_GRND(a,b)
union{
#if(a=1)
#local i=0;
        #while(i<b)
                object{PHW() translate<i*2.54,0,0>}
                #local i=i+1;
        #end
        translate<-(b-1)*1.27,0,0>
#else
        #local i=0;
        #while(i<b)
                object{PHW() translate<i*2.54,0,1.27>}
                object{PHW2() translate<i*2.54,0,-1.27>}
                #local i=i+1;
        #end
        translate<-(b-1)*1.27,0,0>
#end
}
#end
#macro CON_PHW_1X1()
CON_PHW_GRND(1,1)
#end
#macro CON_PHW_1X2()
CON_PHW_GRND(1,2)
#end
#macro CON_PHW_1X3()
CON_PHW_GRND(1,3)
#end
#macro CON_PHW_1X4()
CON_PHW_GRND(1,4)
#end
#macro CON_PHW_1X5()
CON_PHW_GRND(1,5)
#end
#macro CON_PHW_1X6()
CON_PHW_GRND(1,6)
#end
#macro CON_PHW_1X7()
CON_PHW_GRND(1,7)
#end
#macro CON_PHW_1X8()
CON_PHW_GRND(1,8)
#end
#macro CON_PHW_1X9()
CON_PHW_GRND(1,9)
#end
#macro CON_PHW_1X10()
CON_PHW_GRND(1,10)
#end
#macro CON_PHW_1X11()
CON_PHW_GRND(1,11)
#end
#macro CON_PHW_1X12()
CON_PHW_GRND(1,12)
#end
#macro CON_PHW_1X13()
CON_PHW_GRND(1,13)
#end
#macro CON_PHW_1X14()
CON_PHW_GRND(1,14)
#end
#macro CON_PHW_1X15()
CON_PHW_GRND(1,15)
#end
#macro CON_PHW_1X16()
CON_PHW_GRND(1,16)
#end
#macro CON_PHW_1X17()
CON_PHW_GRND(1,17)
#end
#macro CON_PHW_1X18()
CON_PHW_GRND(1,18)
#end
#macro CON_PHW_1X19()
CON_PHW_GRND(1,19)
#end
#macro CON_PHW_1X20()
CON_PHW_GRND(1,20)
#end
#macro CON_PHW_1X21()
CON_PHW_GRND(1,21)
#end
#macro CON_PHW_1X22()
CON_PHW_GRND(1,22)
#end
#macro CON_PHW_1X23()
CON_PHW_GRND(1,23)
#end
#macro CON_PHW_1X24()
CON_PHW_GRND(1,24)
#end
#macro CON_PHW_1X25()
CON_PHW_GRND(1,25)
#end
#macro CON_PHW_1X26()
CON_PHW_GRND(1,26)
#end
#macro CON_PHW_1X27()
CON_PHW_GRND(1,27)
#end
#macro CON_PHW_1X28()
CON_PHW_GRND(1,28)
#end
#macro CON_PHW_1X29()
CON_PHW_GRND(1,29)
#end
#macro CON_PHW_1X30()
CON_PHW_GRND(1,30)
#end
//Zweireihige Stiftleisten Winkel
#macro CON_PHW_2X2()
CON_PHW_GRND(2,2)
#end
#macro CON_PHW_2X3()
CON_PHW_GRND(2,3)
#end
#macro CON_PHW_2X4()
CON_PHW_GRND(2,4)
#end
#macro CON_PHW_2X5()
CON_PHW_GRND(2,5)
#end
#macro CON_PHW_2X6()
CON_PHW_GRND(2,6)
#end
#macro CON_PHW_2X7()
CON_PHW_GRND(2,7)
#end
#macro CON_PHW_2X8()
CON_PHW_GRND(2,8)
#end
#macro CON_PHW_2X9()
CON_PHW_GRND(2,9)
#end
#macro CON_PHW_2X10()
CON_PHW_GRND(2,10)
#end
#macro CON_PHW_2X11()
CON_PHW_GRND(2,11)
#end
#macro CON_PHW_2X12()
CON_PHW_GRND(2,12)
#end
#macro CON_PHW_2X13()
CON_PHW_GRND(2,13)
#end
#macro CON_PHW_2X14()
CON_PHW_GRND(2,14)
#end
#macro CON_PHW_2X15()
CON_PHW_GRND(2,15)
#end
#macro CON_PHW_2X16()
CON_PHW_GRND(2,16)
#end
#macro CON_PHW_2X17()
CON_PHW_GRND(2,17)
#end
#macro CON_PHW_2X18()
CON_PHW_GRND(2,18)
#end
#macro CON_PHW_2X19()
CON_PHW_GRND(2,19)
#end
#macro CON_PHW_2X20()
CON_PHW_GRND(2,20)
#end
#macro CON_PHW_2X21()
CON_PHW_GRND(2,21)
#end
#macro CON_PHW_2X22()
CON_PHW_GRND(2,22)
#end
#macro CON_PHW_2X23()
CON_PHW_GRND(2,23)
#end
#macro CON_PHW_2X24()
CON_PHW_GRND(2,24)
#end
#macro CON_PHW_2X25()
CON_PHW_GRND(2,25)
#end
#macro CON_PHW_2X26()
CON_PHW_GRND(2,26)
#end
#macro CON_PHW_2X27()
CON_PHW_GRND(2,27)
#end
#macro CON_PHW_2X28()
CON_PHW_GRND(2,28)
#end
#macro CON_PHW_2X29()
CON_PHW_GRND(2,29)
#end
#macro CON_PHW_2X30()
CON_PHW_GRND(2,30)
#end


/********************************************************************************************************************************************
//Grundmakro Stiftleisten
//a = Rows
//b = Pins
//j = (0=no Jumper, 1=open, 2=closed)
//pitch = The space between two pins
********************************************************************************************************************************************/
#macro CON_PH_GRND(a,b,j,pitch)
#if((a>1)|(b>1))
union{
#else
object{
#end
#if(a=1)
#local i=0;
        #while(i<b)
                object{PH() translate<i*2.54,0,0>}
                #local i=i+1;
        #end
        translate<-(b-1)*(2.54/2),0,0>
#else
        #local i=0;
        #while(i<b)
                object{PH() translate<i*2.54,0,-(2.54/2)>}
                object{PH() translate<i*2.54,0,(2.54/2)>}

                #if(j=1)
                object{CON_JUMPER() rotate<0,90,0> translate<i*2.54,0,(2.54)>}
                #end

                #if(j=2)
                object{CON_JUMPER() rotate<0,90,0> translate<i*2.54,0,0>}
                #end

                #local i=i+1;
        #end
        translate<-(b-1)*(2.54/2),0,0>
#end
scale (pitch/2.54)
}
#end
//Stiftleisten (2,54mm)
#macro CON_PH_1X1()
CON_PH_GRND(1,1,0,2.54)
#end
#macro CON_PH_1X2()
CON_PH_GRND(1,2,0,2.54)
#end
#macro CON_PH_1X3()
CON_PH_GRND(1,3,0,2.54)
#end
#macro CON_PH_1X4()
CON_PH_GRND(1,4,0,2.54)
#end
#macro CON_PH_1X5()
CON_PH_GRND(1,5,0,2.54)
#end
#macro CON_PH_1X6()
CON_PH_GRND(1,6,0,2.54)
#end
#macro CON_PH_1X7()
CON_PH_GRND(1,7,0,2.54)
#end
#macro CON_PH_1X8()
CON_PH_GRND(1,8,0,2.54)
#end
#macro CON_PH_1X9()
CON_PH_GRND(1,9,0,2.54)
#end
#macro CON_PH_1X10()
CON_PH_GRND(1,10,0,2.54)
#end
#macro CON_PH_1X11()
CON_PH_GRND(1,11,0,2.54)
#end
#macro CON_PH_1X12()
CON_PH_GRND(1,12,0,2.54)
#end
#macro CON_PH_1X13()
CON_PH_GRND(1,13,0,2.54)
#end
#macro CON_PH_1X14()
CON_PH_GRND(1,14,0,2.54)
#end
#macro CON_PH_1X15()
CON_PH_GRND(1,15,0,2.54)
#end
#macro CON_PH_1X16()
CON_PH_GRND(1,16,0,2.54)
#end
#macro CON_PH_1X17()
CON_PH_GRND(1,17,0,2.54)
#end
#macro CON_PH_1X18()
CON_PH_GRND(1,18,0,2.54)
#end
#macro CON_PH_1X19()
CON_PH_GRND(1,19,0,2.54)
#end
#macro CON_PH_1X20()
CON_PH_GRND(1,20,0,2.54)
#end
#macro CON_PH_1X21()
CON_PH_GRND(1,21,0,2.54)
#end
#macro CON_PH_1X22()
CON_PH_GRND(1,22,0,2.54)
#end
#macro CON_PH_1X23()
CON_PH_GRND(1,23,0,2.54)
#end
#macro CON_PH_1X24()
CON_PH_GRND(1,24,0,2.54)
#end
#macro CON_PH_1X25()
CON_PH_GRND(1,25,0,2.54)
#end
#macro CON_PH_1X26()
CON_PH_GRND(1,26,0,2.54)
#end
#macro CON_PH_1X27()
CON_PH_GRND(1,27,0,2.54)
#end
#macro CON_PH_1X28()
CON_PH_GRND(1,28,0,2.54)
#end
#macro CON_PH_1X29()
CON_PH_GRND(1,29,0,2.54)
#end
#macro CON_PH_1X30()
CON_PH_GRND(1,30,0,2.54)
#end
//Zweireihige Stiftleisten (2,54mm)
#macro CON_PH_2X2()
CON_PH_GRND(2,2,0,2.54)
#end
#macro CON_PH_2X3()
CON_PH_GRND(2,3,0,2.54)
#end
#macro CON_PH_2X4()
CON_PH_GRND(2,4,0,2.54)
#end
#macro CON_PH_2X5()
CON_PH_GRND(2,5,0,2.54)
#end
#macro CON_PH_2X6()
CON_PH_GRND(2,6,0,2.54)
#end
#macro CON_PH_2X7()
CON_PH_GRND(2,7,0,2.54)
#end
#macro CON_PH_2X8()
CON_PH_GRND(2,8,0,2.54)
#end
#macro CON_PH_2X9()
CON_PH_GRND(2,9,0,2.54)
#end
#macro CON_PH_2X10()
CON_PH_GRND(2,10,0,2.54)
#end
#macro CON_PH_2X11()
CON_PH_GRND(2,11,0,2.54)
#end
#macro CON_PH_2X12()
CON_PH_GRND(2,12,0,2.54)
#end
#macro CON_PH_2X13()
CON_PH_GRND(2,13,0,2.54)
#end
#macro CON_PH_2X14()
CON_PH_GRND(2,14,0,2.54)
#end
#macro CON_PH_2X15()
CON_PH_GRND(2,15,0,2.54)
#end
#macro CON_PH_2X16()
CON_PH_GRND(2,16,0,2.54)
#end
#macro CON_PH_2X17()
CON_PH_GRND(2,17,0,2.54)
#end
#macro CON_PH_2X18()
CON_PH_GRND(2,18,0,2.54)
#end
#macro CON_PH_2X19()
CON_PH_GRND(2,19,0,2.54)
#end
#macro CON_PH_2X20()
CON_PH_GRND(2,20,0,2.54)
#end
#macro CON_PH_2X21()
CON_PH_GRND(2,21,0,2.54)
#end
#macro CON_PH_2X22()
CON_PH_GRND(2,22,0,2.54)
#end
#macro CON_PH_2X23()
CON_PH_GRND(2,23,0,2.54)
#end
#macro CON_PH_2X24()
CON_PH_GRND(2,24,0,2.54)
#end
#macro CON_PH_2X25()
CON_PH_GRND(2,25,0,2.54)
#end
#macro CON_PH_2X26()
CON_PH_GRND(2,26,0,2.54)
#end
#macro CON_PH_2X27()
CON_PH_GRND(2,27,0,2.54)
#end
#macro CON_PH_2X28()
CON_PH_GRND(2,28,0,2.54)
#end
#macro CON_PH_2X29()
CON_PH_GRND(2,29,0,2.54)
#end
#macro CON_PH_2X30()
CON_PH_GRND(2,30,0,2.54)
#end
//Zweireihige Stiftleisten (2,54) mit Jumper
#macro CON_PH_2X1J(j)
CON_PH_GRND(2,1,j,2.54)
#end
#macro CON_PH_2X2J(j)
CON_PH_GRND(2,2,j,2.54)
#end
#macro CON_PH_2X3J(j)
CON_PH_GRND(2,3,j,2.54)
#end
#macro CON_PH_2X4J(j)
CON_PH_GRND(2,4,j,2.54)
#end
#macro CON_PH_2X5J(j)
CON_PH_GRND(2,5,j,2.54)
#end
#macro CON_PH_2X6J(j)
CON_PH_GRND(2,6,j,2.54)
#end
#macro CON_PH_2X7J(j)
CON_PH_GRND(2,7,j,2.54)
#end
#macro CON_PH_2X8J(j)
CON_PH_GRND(2,8,j,2.54)
#end
#macro CON_PH_2X9J(j)
CON_PH_GRND(2,9,j,2.54)
#end
#macro CON_PH_2X10J(j)
CON_PH_GRND(2,10,j,2.54)
#end
//one row pinheader (2mm)
#macro CON_PH_2MM_1X1()
CON_PH_GRND(1,1,0,2.00)
#end
#macro CON_PH_2MM_1X2()
CON_PH_GRND(1,2,0,2.00)
#end
#macro CON_PH_2MM_1X3()
CON_PH_GRND(1,3,0,2.00)
#end
#macro CON_PH_2MM_1X4()
CON_PH_GRND(1,4,0,2.00)
#end
#macro CON_PH_2MM_1X5()
CON_PH_GRND(1,5,0,2.00)
#end
#macro CON_PH_2MM_1X6()
CON_PH_GRND(1,6,0,2.00)
#end
#macro CON_PH_2MM_1X7()
CON_PH_GRND(1,7,0,2.00)
#end
#macro CON_PH_2MM_1X8()
CON_PH_GRND(1,8,0,2.00)
#end
#macro CON_PH_2MM_1X9()
CON_PH_GRND(1,9,0,2.00)
#end
#macro CON_PH_2MM_1X10()
CON_PH_GRND(1,10,0,2.00)
#end
#macro CON_PH_2MM_1X11()
CON_PH_GRND(1,11,0,2.00)
#end
#macro CON_PH_2MM_1X12()
CON_PH_GRND(1,12,0,2.00)
#end
#macro CON_PH_2MM_1X13()
CON_PH_GRND(1,13,0,2.00)
#end
#macro CON_PH_2MM_1X14()
CON_PH_GRND(1,14,0,2.00)
#end
#macro CON_PH_2MM_1X15()
CON_PH_GRND(1,15,0,2.00)
#end
#macro CON_PH_2MM_1X16()
CON_PH_GRND(1,16,0,2.00)
#end
#macro CON_PH_2MM_1X17()
CON_PH_GRND(1,17,0,2.00)
#end
#macro CON_PH_2MM_1X18()
CON_PH_GRND(1,18,0,2.00)
#end
#macro CON_PH_2MM_1X19()
CON_PH_GRND(1,19,0,2.00)
#end
#macro CON_PH_2MM_1X20()
CON_PH_GRND(1,20,0,2.00)
#end
#macro CON_PH_2MM_1X21()
CON_PH_GRND(1,21,0,2.00)
#end
#macro CON_PH_2MM_1X22()
CON_PH_GRND(1,22,0,2.00)
#end
#macro CON_PH_2MM_1X23()
CON_PH_GRND(1,23,0,2.00)
#end
#macro CON_PH_2MM_1X24()
CON_PH_GRND(1,24,0,2.00)
#end
#macro CON_PH_2MM_1X25()
CON_PH_GRND(1,25,0,2.00)
#end
#macro CON_PH_2MM_1X26()
CON_PH_GRND(1,26,0,2.00)
#end
#macro CON_PH_2MM_1X27()
CON_PH_GRND(1,27,0,2.00)
#end
#macro CON_PH_2MM_1X28()
CON_PH_GRND(1,28,0,2.00)
#end
#macro CON_PH_2MM_1X29()
CON_PH_GRND(1,29,0,2.00)
#end
#macro CON_PH_2MM_1X30()
CON_PH_GRND(1,30,0,2.00)
#end
//two row pinheader (2mm)
#macro CON_PH_2MM_2X2()
CON_PH_GRND(2,2,0,2.00)
#end
#macro CON_PH_2MM_2X3()
CON_PH_GRND(2,3,0,2.00)
#end
#macro CON_PH_2MM_2X4()
CON_PH_GRND(2,4,0,2.00)
#end
#macro CON_PH_2MM_2X5()
CON_PH_GRND(2,5,0,2.00)
#end
#macro CON_PH_2MM_2X6()
CON_PH_GRND(2,6,0,2.00)
#end
#macro CON_PH_2MM_2X7()
CON_PH_GRND(2,7,0,2.00)
#end
#macro CON_PH_2MM_2X8()
CON_PH_GRND(2,8,0,2.00)
#end
#macro CON_PH_2MM_2X9()
CON_PH_GRND(2,9,0,2.00)
#end
#macro CON_PH_2MM_2X10()
CON_PH_GRND(2,10,0,2.00)
#end
#macro CON_PH_2MM_2X11()
CON_PH_GRND(2,11,0,2.00)
#end
#macro CON_PH_2MM_2X12()
CON_PH_GRND(2,12,0,2.00)
#end
#macro CON_PH_2MM_2X13()
CON_PH_GRND(2,13,0,2.00)
#end
#macro CON_PH_2MM_2X14()
CON_PH_GRND(2,14,0,2.00)
#end
#macro CON_PH_2MM_2X15()
CON_PH_GRND(2,15,0,2.00)
#end
#macro CON_PH_2MM_2X16()
CON_PH_GRND(2,16,0,2.00)
#end
#macro CON_PH_2MM_2X17()
CON_PH_GRND(2,17,0,2.00)
#end
#macro CON_PH_2MM_2X18()
CON_PH_GRND(2,18,0,2.00)
#end
#macro CON_PH_2MM_2X19()
CON_PH_GRND(2,19,0,2.00)
#end
#macro CON_PH_2MM_2X20()
CON_PH_GRND(2,20,0,2.00)
#end
#macro CON_PH_2MM_2X21()
CON_PH_GRND(2,21,0,2.00)
#end
#macro CON_PH_2MM_2X22()
CON_PH_GRND(2,22,0,2.00)
#end
#macro CON_PH_2MM_2X23()
CON_PH_GRND(2,23,0,2.00)
#end
#macro CON_PH_2MM_2X24()
CON_PH_GRND(2,24,0,2.00)
#end
#macro CON_PH_2MM_2X25()
CON_PH_GRND(2,25,0,2.00)
#end
#macro CON_PH_2MM_2X26()
CON_PH_GRND(2,26,0,2.00)
#end
#macro CON_PH_2MM_2X27()
CON_PH_GRND(2,27,0,2.00)
#end
#macro CON_PH_2MM_2X28()
CON_PH_GRND(2,28,0,2.00)
#end
#macro CON_PH_2MM_2X29()
CON_PH_GRND(2,29,0,2.00)
#end
#macro CON_PH_2MM_2X30()
CON_PH_GRND(2,30,0,2.00)
#end
//two row pinheader (2mm) with jumper
#macro CON_PH_2MM_2X1J(j)
CON_PH_GRND(2,1,j,2.00)
#end
#macro CON_PH_2MM_2X2J(j)
CON_PH_GRND(2,2,j,2.00)
#end
#macro CON_PH_2MM_2X3J(j)
CON_PH_GRND(2,3,j,2.00)
#end
#macro CON_PH_2MM_2X4J(j)
CON_PH_GRND(2,4,j,2.00)
#end
#macro CON_PH_2MM_2X5J(j)
CON_PH_GRND(2,5,j,2.00)
#end
#macro CON_PH_2MM_2X6J(j)
CON_PH_GRND(2,6,j,2.00)
#end
#macro CON_PH_2MM_2X7J(j)
CON_PH_GRND(2,7,j,2.00)
#end
#macro CON_PH_2MM_2X8J(j)
CON_PH_GRND(2,8,j,2.00)
#end
#macro CON_PH_2MM_2X9J(j)
CON_PH_GRND(2,9,j,2.00)
#end
#macro CON_PH_2MM_2X10J(j)
CON_PH_GRND(2,10,j,2.00)
#end


/********************************************************************************************************************************************
// Makro fuer geschirmte Ethernet-Buchse RJ-45 8-polig
// Designed by Carsten Koegler, FTZ-Leipzig <koegler(replace with at)ftz-leipzig.de>
// Vorlage: MEBP 8-8PG Reichelt Elektronik
********************************************************************************************************************************************/
#macro CON_RJ45_GRND()
//#local tex_rj45_metal = texture { T_Chrome_3D } ;
#local tex_rj45_metal = texture { T_Chrome_5B } ;
#local tex_rj45_pastic = texture { pigment{White*0.3} finish {specular 1 roughness 0.001 reflection 0.07 ambient (0.1 * global_ambient_mul)} } ;

#macro body(B,H,T,R)
union {

    // Grundkoerper
    box{<-B/2+R,0  , T/2  > <B/2-R,H-R,-T/2  >}
    box{<-B/2  ,0  ,-T/2+R> <B/2  ,H-R, T/2-R>}
    box{<-B/2+R,0  ,-T/2+R> <B/2-R,H    , T/2-R>}


    // senkrechte Seiten als Zylinder
    // linke hintere Ecke
    cylinder{<-B/2+R, 0, 0> <-B/2+R, H-R> R
             translate <0, 0, T/2-R>}
    // linke vordere Ecke
    cylinder{<-B/2+R, 0, 0> <-B/2+R, H-R> R
             translate <0, 0,-T/2+R>}
    // rechte hintere Ecke
    cylinder{< B/2-R, 0, 0> < B/2-R, H-R> R
             translate <0, 0, T/2-R>}
    // rechte vordere Ecke
    cylinder{< B/2-R, 0, 0> < B/2-R, H-R> R
             translate <0, 0,-T/2+R>}

    sphere{< B/2-R, H-R, T/2-R> R scale <1,1,1>}
    sphere{< B/2-R, H-R,-T/2+R> R scale <1,1,1>}
    sphere{<-B/2+R, H-R, T/2-R> R scale <1,1,1>}
    sphere{<-B/2+R, H-R,-T/2+R> R scale <1,1,1>}


    cylinder{<-B/2+R,  H-R> < B/2-R, H-R> R
             translate <0, 0, T/2-R>}

    cylinder{<-B/2+R,  H-R> < B/2-R, H-R> R
             translate <0, 0,-T/2+R>}
    cylinder{<-T/2+R,  H-R> < T/2-R, H-R> R rotate<0, 90,0>
             translate < B/2-R, 0, 0>}
    cylinder{<-T/2+R,  H-R> < T/2-R, H-R> R rotate<0, 90,0>
             translate < -B/2+R, 0, 0>}
  }
#end 

// Ausbruch in der metallenen Vorderseite
#local stecker1 = 
      difference
      {
         box{<1.5,0.5,-1><15.8-1.5,11.5,15.0>}
         box{<0  ,0  ,-2><3.0     ,3.3 ,15.0>}
         box{<16 ,0  ,-2><15.8-3.0,3.3 ,15.0>}
         box{<0  ,0  ,-2><5.5     ,2.1 ,15.0>}
         box{<16 ,0  ,-2><15.8-5.5,2.1 ,15.0>}
      };

// Ausbruch im Kunststoff
#local stecker2 = 
      difference
      {
         union
         {
            box{<1.5, 3.7, -1><15.8-1.5, 11.5, 15.5>}
            box{<3.1, 2.5, -1><15.8-3.1, 11.5, 15.5>}
            box{<5.6, 0.7, -1><15.8-5.6, 11.5, 15.5>}
            box{<-1,-1,-2><16,1  ,2>rotate<-30,0,0>translate<0,4.4,0> pigment{White*0.5}}
            box{<-1,0 ,-1><16,0.5,1>rotate<-30,0,0>translate<0,2.0,0> pigment{White*0.5}}
         }
         box{<-1      ,-1  ,15.0><16  ,15 ,16.0>}
         box{<-1      ,-1  ,-1  ><1.6 ,15 ,16.0>}
         box{<15.8-1.6,-1  ,-1  ><16  ,15 ,16.0>}
      };

#local pin_intern =
   sphere_sweep {
      b_spline
      6,
      <15.8/2-0.635, 14.0, 6>,   0.2
      <15.8/2-0.635, 12.7, 6>,   0.2
      <15.8/2-0.635, 12.0, 6.5>, 0.2
      <15.8/2-0.635, 11.3, 10>,  0.2
      <15.8/2-0.635, 11.0, 16>,  0.2
      <15.8/2-0.635, 11.0, 18>,  0.2
      texture{col_gold}
   }

union
{
   difference
   {
      // Aussenabmaße : 15.8  x  13.0  x  21.4 mm
      union
      {
         object {body(15.8,13.0,21.4,0.3) translate<7.9,0,10.7>  }
         box{<0,12.0,0.2><0.5,13,7.7> }
         box{<15.5,12.0,0.2><15.8,13,7.7>}
      }
      // das Ganze aushöhlen
      box{<0.25 ,-1 , 0.2><15.8-0.25 ,13.0-0.25,21.4-0.25>}
      
      // Vorne typischer Ausbruch für Stecker
      stecker1

      // kleiner Schlitz hinten oben
      box{<3.5,13-0.35,21.4-0.35><15.8-3.5,13+0.35,21.4+0.35> }

      // Schlitze an den Seiten
      // Schrägen hinten (links und rechts)
      box{<-0.3,-0.1,-1.64><0.3,0.1,2.0> rotate<-45,0,0> translate<0,10.5+1.15+0.04,10-1.15+0.02+11.2>}
      box{<15.8-0.3,-0.1,-1.64><16,0.1,2.0> rotate<-45,0,0> translate<0,10.5+1.15+0.04,10-1.15+0.02+11.2>}
      // Senkrechten
      box{<-1,-1,18.8><20,10.6,19.00>}
      // waagerechte hinten
      box{<-1,10.45,10><20,10.65,18.8> }
      // Schrägen vorne
      box{<-1,-0.1,-1.52><20,0.1,1.64> rotate<45,0,0> translate<0,10.5+1.15+0.04,10-1.15+0.02> }
      // waagerechte vorn
      box{<-1,12.6,0.2><20,12.8,7.82>}

      // Verbindungspunkte hinten
      box{<-1,1,19.7><20,1.8,20.5>}
      box{<-1,8,19.7><20,8.8,20.5>}
      texture{tex_rj45_metal}
   }

   // Verbindungspunkte hinten
   superellipsoid{<0.3,0.3> scale<0.35,0.35,0.35> translate<     0.35,1.4,20.1> texture{tex_rj45_metal}}
   superellipsoid{<0.3,0.3> scale<0.35,0.35,0.35> translate<     0.35,8.4,20.1> texture{tex_rj45_metal}}
   superellipsoid{<0.3,0.3> scale<0.35,0.35,0.35> translate<15.8-0.35,1.4,20.1> texture{tex_rj45_metal}}
   superellipsoid{<0.3,0.3> scale<0.35,0.35,0.35> translate<15.8-0.35,8.4,20.1> texture{tex_rj45_metal}}

   // Schirmanschlüsse
   box     {<0   , 1, 14-0.75><0.2     , -4,14+0.75> texture{tex_rj45_metal}}
   cylinder{<0   ,-4, 14     ><0.2     , -4,14     > 0.75 texture{tex_rj45_metal}}
   box     {<15.8, 1, 14-0.75><15.8-0.2, -4,14+0.75> texture{tex_rj45_metal}}
   cylinder{<15.8,-4, 14     ><15.8-0.2, -4,14     > 0.75 texture{tex_rj45_metal}}

   // Plastikinnenleben
   difference
   {
      box{<0.4 ,0 , 0.3><15.8-0.4 ,13.0-0.4,21.4-0.4>}
      stecker2

      texture{tex_rj45_pastic}
    }
 
   // Plastikfüße zur Befestigung
   difference
   {
      cylinder{<2,-3.5,14-3.05><2,1,14-3.05> 1.5}
      box{<2-0.3,-4,0><2+0.3,-0.5,20>}
      texture{tex_rj45_pastic}
   }
   difference
   {
      cylinder{<15.8-2,-3.5,14-3.05><15.8-2,1,14-3.05> 1.5}
      box{<15.8-2-0.3,-4,0><15.8-2+0.3,-0.5,20>}
      texture{tex_rj45_pastic}
   }
   cylinder{<2,0,5><2,0,15> 0.5 texture{tex_rj45_pastic}}
   cylinder{<15.8-2,0,5><15.8-2,0,15> 0.5 texture{tex_rj45_pastic}}
   
      
   object {TOOLS_RECT_BOGEN(0.2, // i_radius
                            90 , // winkel
                            0.2, // dicke
                            2  , // breite
                            1 , // laenge1
                            5)  // laenge2
                            rotate<90,0,0>
                            translate <15.8-1.5-0.2,7,0.1>
                            texture{tex_rj45_metal}}
   object {TOOLS_RECT_BOGEN(0.2, // i_radius
                            90 , // winkel
                            0.2, // dicke
                            2  , // breite
                            5 , // laenge1
                            1)  // laenge2
                            rotate<90,0,0>
                            rotate<0,-90,0>
                            translate <1.5+0.2,7,0.1>
                            texture{tex_rj45_metal}}

   // Pins (8)
   cylinder{<15.8/2-0.635     ,1,14-3.05+8.89     ><15.8/2-0.635     ,-3.5,14-3.05+8.89     > 0.25 texture{col_gold}}
   cylinder{<15.8/2-0.635+2.54,1,14-3.05+8.89     ><15.8/2-0.635+2.54,-3.5,14-3.05+8.89     > 0.25 texture{col_gold}}
   cylinder{<15.8/2-0.635-2.54,1,14-3.05+8.89     ><15.8/2-0.635-2.54,-3.5,14-3.05+8.89     > 0.25 texture{col_gold}}
   cylinder{<15.8/2-0.635+5.08,1,14-3.05+8.89     ><15.8/2-0.635+5.08,-3.5,14-3.05+8.89     > 0.25 texture{col_gold}}

   cylinder{<15.8/2+0.635     ,1,14-3.05+8.89-2.54><15.8/2+0.635     ,-3.5,14-3.05+8.89-2.54> 0.25 texture{col_gold}}
   cylinder{<15.8/2+0.635+2.54,1,14-3.05+8.89-2.54><15.8/2+0.635+2.54,-3.5,14-3.05+8.89-2.54> 0.25 texture{col_gold}}
   cylinder{<15.8/2+0.635-2.54,1,14-3.05+8.89-2.54><15.8/2+0.635-2.54,-3.5,14-3.05+8.89-2.54> 0.25 texture{col_gold}}
   cylinder{<15.8/2+0.635-5.08,1,14-3.05+8.89-2.54><15.8/2+0.635-5.08,-3.5,14-3.05+8.89-2.54> 0.25 texture{col_gold}}
   
   object { pin_intern }
   object { pin_intern  translate< 2.54,0,0>}
   object { pin_intern  translate<-2.54,0,0>}
   object { pin_intern  translate<+5.08,0,0>}
   
   object { pin_intern  translate<+1.27,0,0>}
   object { pin_intern  translate<+1.27+2.54,0,0>}
   object { pin_intern  translate<+1.27-2.54,0,0>}
   object { pin_intern  translate<+1.27-5.08,0,0>}
 
   translate<0,0.5,0>  // Anhebung um höhe der Plastikrollen
   translate<-15.8/2,0,-21.4/2>  // 0-Punkt in die Mitte der Buchse platzieren
}
#end
#macro CON_RJ45()
CON_RJ45_GRND()
#end


/********************************************************************************************************************************************
// Model einer SD-Karte
// col = Farbe der Karte (Kunststoff)
// everyone1@freenet.de
********************************************************************************************************************************************/
#macro CON_SD_CARD_GRND(col)
#local b  = 24.0;       // Breite        
#local b1 = 22.5;       // Breite dicker Teil
#local l  = 32.0;       // Länge
#local h  = 2.1;        // Höhe
#local h1 = 1.4;        // Höhe dünner Teil
#local s  = 4.0;        // Schräge
#local s1 = s+b1-b;     // Schräge dicker Teil
#local r1 = 1.0;        // Radius
#local r2 = 0.5;        // Radius
#local k1 = sin(pi/4)*r1;
#local k2 = sin(pi/4)*r2;

#local labs_z = 1.0;
#local labs_l = 15.2;
#local labs_b = 0.6;
#local labs_t = 0.2;
#local labl_z = 2.2;
#local labl_l = 21.0;
#local labl_b = 13.8;
#local labl_r = 1.5;

#local pin_h = 1.4;     // Höhe der Pins
#local pin_a = 2.5;     // Pin Abstand
#local pin_l = 6.05;    // Pinposition
#local pin_s = 0.6;     // Steg zwischen den Pins
#local pin_b = pin_a-pin_s;                       

#local sw_b = (b-b1)/2; // Schalter Breite
#local sw_l = 6.7/2-0.1;
#local sw_r = 0.3;

#macro SD_CARD_AUSSCHNITT(l,b,h)
#local r3 = 0.3;        // Radius
difference{
        prism{ -1, h+1, 9
                < 0,-l/2>, < b-r3,-l/2>, < b,-l/2-r3>, < b+1,-l/2-r3>, < b+1, l/2+r3>, < b, l/2+r3>, < b-r3, l/2>, < 0, l/2>, < 0,-l/2>
        }
        cylinder{ < b-r3, -1,-l/2-r3> < b-r3, h+1.01,-l/2-r3> r3 }
        cylinder{ < b-r3, -1, l/2+r3> < b-r3, h+1.01, l/2+r3> r3 }
}
#end 

union{
        // Kunststoffkörper
        difference{
                merge{
                        prism{ 0, h1 11
                                < -b/2+r1, 0>, < b/2-r1, 0>, < b/2, r1>, < b/2, l-r1>, < b/2-r1, l>,
                                < -b/2+s, l>, <-b/2+s-k1, l-r1+k1>, < -b/2+r1-k1, l-s+k1>, < -b/2, l-s>,
                                < -b/2, r1>, < -b/2+r1, 0>
                        }
                        cylinder{ < -b/2+r1, 0, r1> < -b/2+r1, h1, r1> r1 }
                        cylinder{ <  b/2-r1, 0, r1> <  b/2-r1, h1, r1> r1 }
                        cylinder{ <  b/2-r1, 0, l-r1> <  b/2-r1, h1, l-r1> r1 }
                        cylinder{ < -b/2+s, 0, l-r1> <  -b/2+s, h1, l-r1> r1}
                        cylinder{ < -b/2+r1, 0, l-s> < -b/2+r1, h1, l-s> r1 }

                        prism{ h1-0.001, h 11
                                < -b1/2+r2, 0>, < b1/2-r2, 0>, < b1/2, r2>, < b1/2, l-r2>, < b1/2-r2, l>,
                                < -b1/2+s1, l>, <-b1/2+s1-k2, l-r2+k2>, < -b1/2+r2-k2, l-s1+k2>, < -b1/2, l-s1>,
                                < -b1/2, r2>, < -b1/2+r2, 0>
                        }
                        cylinder{ < -b1/2+r2, 0, r2>   < -b1/2+r2, h, r2> r2 }
                        cylinder{ <  b1/2-r2, 0, r2>   <  b1/2-r2, h, r2> r2 }
                        cylinder{ <  b1/2-r2, 0, l-r2> <  b1/2-r2, h, l-r2> r2 }
                        cylinder{ < -b1/2+s1, 0, l-r2> < -b1/2+s1, h, l-r2> r2 }
                        cylinder{ < -b1/2+r2, 0, l-s1> < -b1/2+r2, h, l-s1> r2 }
                }
        
                // Seitlichen Ausschnitte
                object{ SD_CARD_AUSSCHNITT( 6.7, (b-b1)/2,h) translate< b1/2, 0, 20.85> }
                object{ SD_CARD_AUSSCHNITT( 1.5, (b-b1)/2,h) rotate< 0, 180, 0> translate<-b1/2, 0, 21.25> }
        
                // Schlitz Labelseite
                merge{
                        box{ < -labs_l/2+labs_b/2, 0, -labs_b/2> < labs_l/2-labs_b/2, -h, labs_b/2> }
                        cylinder{ < -labs_l/2+labs_b/2, 0, 0> < -labs_l/2+labs_b/2, -h, 0> labs_b/2 } 
                        cylinder{ <  labs_l/2-labs_b/2, 0, 0> <  labs_l/2-labs_b/2, -h, 0> labs_b/2 } 
                        translate< 0, labs_t, labs_z>
                }

                // Labelfläche
                merge{
                        prism{ 0, -h, 9
                                < -labl_l/2+labl_r, 0>, < labl_l/2-labl_r, 0>, < labl_l/2, labl_r>, < labl_l/2, labl_b-labl_r>,
                                < labl_l/2-labl_r, labl_b>, < -labl_l/2+labl_r, labl_b>, < -labl_l/2, labl_b-labl_r>, < -labl_l/2, labl_r>,
                                < -labl_l/2+labl_r, 0>
                        }
                        cylinder{ < -labl_l/2+labl_r, 0, labl_r> < -labl_l/2+labl_r, -h, labl_r> labl_r } 
                        cylinder{ < labl_l/2-labl_r, 0, labl_r> < labl_l/2-labl_r, -h, labl_r> labl_r } 
                        cylinder{ < -labl_l/2+labl_r, 0, labl_b-labl_r> < -labl_l/2+labl_r, -h, labl_b-labl_r> labl_r } 
                        cylinder{ < labl_l/2-labl_r, 0, labl_b-labl_r> < labl_l/2-labl_r, -h, labl_b-labl_r> labl_r } 
                        translate< 0, labs_t, labl_z>
                }
        
                // Pin Ausschnitte
                #local i = 0;
                #local pin_x = -10.275; // Position Pin 1
                box{ < pin_x, pin_h, l-8.1> < pin_x+pin_b, h+1, l+1>}
                #local pin_x = pin_x + pin_a;
                #while (i<6)
                        box{ < pin_x, pin_h, l-pin_l> < pin_x+pin_b, h+1, l+1>}
                        #local pin_x = pin_x + pin_a;
                        #local i = i + 1;
                #end
                box{ < pin_x, pin_h, l-pin_l> < pin_x+3.6, h+1, l+1>}
                
                pigment{ color col }
                normal { bumps 2.0 scale 0.01 }
                finish { ambient (1 * global_ambient_mul) diffuse 0.2 phong 0.01 phong_size 50 reflection 0.01}
        }

        // Pads
        union{
                #local i = 0;
                #local pin_x = -10.3; // Position Pin 1
                box{ < pin_x, pin_h+0.001, l-7.8> < pin_x+pin_b-0.05, pin_h+0.035, l-3.3>}
                #local pin_x = pin_x + pin_a;
                #while (i<7)
                        box{ < pin_x, pin_h+0.001, l-5.75> < pin_x+pin_b-0.05, pin_h+0.035, l-1.25>}
                        #local pin_x = pin_x + pin_a;
                        #local i = i + 1;
                #end
                #local pin_x = pin_x - pin_s+0.2;
                box{ < pin_x, pin_h+0.001, l-5.75> < pin_x+1.475, pin_h+0.035, l-1.25>}
                
                texture{ Gold_Metal }
        }
        
        // Lock-Schalter
        prism{ 0, h1, 7
                < 0, -sw_l/2>, < sw_b-sw_r, -sw_l/2>, < sw_b, -sw_l/2+sw_r>,
                < sw_b, sw_l/2-sw_r>, < sw_b-sw_r, sw_l/2>, < 0, sw_l/2>, < 0, -sw_l/2>
                translate< b1/2, 0, l-9.475>
                pigment{ rgb< 1.0, 0.8, 0> }
        }

}
#end


#macro CON_SD_CARD_RED()
CON_SD_CARD_GRND(rgb< 1.0, 0.0, 0.0>)
#end
#macro CON_SD_CARD_BLACK()
CON_SD_CARD_GRND(rgb< 0.1, 0.1, 0.1>)
#end


/********************************************************************************************************************************************
// SD- / MMC-Karten Slot YAMAICHI FPS-Series
// card = 0 - Keine Karte im Slot, 1 - Karte im Slot, 2 - Karte Vor dem Slot
********************************************************************************************************************************************/
#macro CON_SD_CONNECTOR_YAMAICHI_FPS_GRND(card)
#local ua = 0.01;
#local h = 2.8;
#local bl_d = 0.2;

        #macro PIN_AUSSCHNITT(b)
                box{ <-b/2, 0.5, -ua> < b/2, 1.9, 7.0> }
        #end

        #macro CON_MS_SMD_PIN( l, l1, h, b, s, col)
        #local ua = 0.001;
        #local rf = 0.3;
        #local r1 = s*(rf+1);
        #local r2 = s*rf;

                #macro SMD_PIN_AUSSCHNITT()
                merge{
                        cylinder{ < r2, r2, -ua> < r2, r2, b+ua> r2 }
                        prism{ -ua, b+ua, 6 < r2, 0>, < r1+r2+ua, 0>, < r1+r2+ua, -r1-r2-ua>, < 0, -r1-r2-ua>, < 0, -r2>, < r2, 0> 
                                rotate< 90, 0, 0> 
                        }
                }
                #end

        union{
                difference{
                        merge{
                                box{ < 0, 0, 0> < l1-r1, s, b>}
                                cylinder{ < l1-r1, r1, 0> < l1-r1, r1, b> r1}
                                box{ < l1-s, r1, 0> < l1, h-r1, b>}
                                cylinder{ < l1+r2, h-r1, 0> < l1+r2, h-r1, b> r1}
                                box{ < l1+r2, h-s, 0> < l, h, b>} 
                        }
                        object{ SMD_PIN_AUSSCHNITT() rotate< 0, 0, 90> translate< l1-s-ua, s+ua, 0> }
                        object{ SMD_PIN_AUSSCHNITT() rotate< 0, 0,-90> translate< l1+ua, h-s-ua, 0> }
                }
                translate< 0, 0, -b/2>
                texture{ col }
        }
        #end


union{
        // Metallkörper
//        box{ <-4.98, 0, 0> < 23.02, h, 29.0> }
        difference{
                prism{ 0, h, 25
                        <-4.98, 1.0>, <-3.98, 1.0>, <-3.98, 0>, <-1.5, 0>, <-1.5, 0.5>, < 5.5, 0.5>, < 5.5, 2.0>, < 7.5, 2.0>,
                        < 7.5, 0.5>, < 10.0, 0.5>, < 10.0, 2.0>, < 12.0, 2.0>, < 12.0, 0.5>, < 15.0, 0.5>, < 15.0, 2.0>,
                        < 17.0, 2.0>, < 17.0, 0.5>, < 23.02, 0.5>, < 23.02, 29.0>, < 21.32, 29.0>, < 19.02, 25.0>, <-0.98, 25.0>,
                        < -3.18, 29.00>, <-4.98, 29.0>, <-4.98, 1.0>
                }          
                box{ <-4.98+bl_d, -ua, -ua> < 23.02-bl_d, h-bl_d, 29.0+ua> }
                box{ < 22.52, 1.7, 2.2> < 23.2+ua, h+ua, 5.8> }
                box{ < 22.52, 0.3, 7.3> < 23.2+ua, h+ua, 11.8> }
                box{ < 22.52, 0.3, 12.9> < 23.2+ua, h+ua, 19.3> }
                prism{ -ua, h+ua, 20
                        <-2.63, 12.7>, < 20.67, 12.7>, < 20.67, 22.13>, 
                        < 20.47, 22.13>, < 20.47, 14.2>, < 20.27, 14.0>, < 19.07, 14.0>, < 18.87, 14.2>, < 18.87, 17.3>, < 17.07, 22.13>,
                        <-0.93, 22.13>, <-1.53, 18.63>, <-0.73, 18.63>, <-0.73, 17.6>, <-0.93, 17.4>, <-2.23, 17.4>, <-2.43, 17.6>, <-2.43, 22.13>,
                        <-2.63, 22.13>, <-2.63, 12.7> 
                }
                texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)} }
        }
        
        // Kunststoffkörper
        difference{
                merge{
                        prism{ 0, h-bl_d-ua, 9
                                <-4.98+bl_d+ua, 0>, < 23.02-bl_d-ua, 0>, < 23.02-bl_d-ua, 29.0>, < 20.72, 29.0>, < 20.72, 25.2>, <-1.78, 25.2>, <-1.78, 29.0>,
                                <-4.98+bl_d+ua, 29.0>, <-4.98+bl_d+ua, 0>
                        }
                        cylinder{ < 21.48, -0.6, 23.5> < 21.48, ua, 23.5> 0.7 }
                        cylinder{ < -2.72, -0.6, 23.5> < -2.72, ua, 23.5> 0.7 }
                }          
                box{ < -4.98-ua, -ua, 25.0> < 23.02-ua, bl_d, 29.0+ua> }
                // SD-Karte
                prism{ h-bl_d-2.3, h, 6
                        < 1.38, 2.0>, < 21.38, 2.0>, < 21.38, 34.0>, <-2.62, 34.0>, <-2.62, 6.0>, < 1.38, 2.0>
                }
                // Ausschnitt im Boden
                merge{
                        #local r = 0.5;
                        prism{ -ua, h+ua, 9
                                < 0.08, 10.5>, < 18.18, 10.5>, < 18.68, 11.0>, < 18.68, 20.2>, < 18.18, 20.7>, < 0.08, 20.7>, <-0.42, 20.2>,
                                <-0.42, 11.0>, < 0.08, 10.5>
                        }
                        cylinder{ < 0.08, -ua, 11.0> < 0.08, h+ua, 11.0> r }
                        cylinder{ < 18.18, -ua, 11.0> < 18.18, h+ua, 11.0> r }
                        cylinder{ < 18.18, -ua, 20.2> < 18.18, h+ua, 20.2> r }
                        cylinder{ < 0.08, -ua, 20.2> < 0.08, h+ua, 20.2> r }
                }
                object{PIN_AUSSCHNITT(1.2) translate< -3.78, 0, 0> }
                object{PIN_AUSSCHNITT(5.8) translate< 1.0, 0, 0> }
                object{PIN_AUSSCHNITT(1) translate< 5.0, 0, 0> }
                object{PIN_AUSSCHNITT(1) translate< 7.5, 0, 0> }
                object{PIN_AUSSCHNITT(1) translate< 10.0, 0, 0> }
                object{PIN_AUSSCHNITT(1) translate< 12.5, 0, 0> }
                object{PIN_AUSSCHNITT(1) translate< 15.0, 0, 0> }
                object{PIN_AUSSCHNITT(1) translate< 17.43, 0, 0> }
                object{PIN_AUSSCHNITT(1) translate< 19.12, 0, 0> }
                object{PIN_AUSSCHNITT(1) translate< 21.12, 0, 0> }
                pigment{ Gray10 }
        }
        
        // Pins und Pads
        #local col = texture{ col_silver finish { phong 1  ambient (0.1 * global_ambient_mul)} };
        object{CON_MS_SMD_PIN( 2.5, 1.1, 0.7, 0.5, 0.2, col) rotate< 0, -90, 0> translate< -3.78, 0, -1.5> }
        object{CON_MS_SMD_PIN( 2.5, 1.1, 0.7, 0.45, 0.2, col) rotate< 0, -90, 0> translate< 0, 0, -1.5> }
        object{CON_MS_SMD_PIN( 2.5, 1.1, 0.7, 0.45, 0.2, col) rotate< 0, -90, 0> translate< 2.5, 0, -1.5> }
        object{CON_MS_SMD_PIN( 2.5, 1.1, 0.7, 0.45, 0.2, col) rotate< 0, -90, 0> translate< 5.0, 0, -1.5> }
        object{CON_MS_SMD_PIN( 2.5, 1.1, 0.7, 0.45, 0.2, col) rotate< 0, -90, 0> translate< 7.5, 0, -1.5> }
        object{CON_MS_SMD_PIN( 2.5, 1.1, 0.7, 0.45, 0.2, col) rotate< 0, -90, 0> translate< 10.0, 0, -1.5> }
        object{CON_MS_SMD_PIN( 2.5, 1.1, 0.7, 0.45, 0.2, col) rotate< 0, -90, 0> translate< 12.5, 0, -1.5> }
        object{CON_MS_SMD_PIN( 2.5, 1.1, 0.7, 0.45, 0.2, col) rotate< 0, -90, 0> translate< 15.0, 0, -1.5> }
        object{CON_MS_SMD_PIN( 2.5, 1.1, 0.7, 0.45, 0.2, col) rotate< 0, -90, 0> translate< 17.43, 0, -1.5> }
        object{CON_MS_SMD_PIN( 2.5, 1.1, 0.7, 0.45, 0.2, col) rotate< 0, -90, 0> translate< 19.12, 0, -1.5> }
        object{CON_MS_SMD_PIN( 2.5, 1.1, 0.7, 0.35, 0.2, col) rotate< 0, -90, 0> translate< 20.62, 0, -1.5> }
        object{CON_MS_SMD_PIN( 2.5, 1.1, 0.7, 0.35, 0.2, col) rotate< 0, -90, 0> translate< 21.62, 0, -1.5> }

        box{ < 19.7, 0, 25.7> < 21.85, bl_d-ua, 29.1> texture{ col } }
        box{ < -3.0, 0, 25.7> < -0.75, bl_d-ua, 29.1> texture{ col } }
        
        #if (card>0)
                #if (card=1)
                        object{CON_SD_CARD_GRND(rgb< 0.0, 0.0, 0.2>)  rotate < 0,180, 180> translate<9.38, h-bl_d-0.1, 36.0> }
                #else
                        object{CON_SD_CARD_GRND(rgb< 0.0, 0.0, 0.2>)  rotate < 0,200, 180> translate< -2, h-bl_d-0.1, 65.0> }
                #end
        #end 

}
#end


#macro CON_SD_CONNECTOR_YAMAICHI_FPS_CARD_EXTERNAL()
CON_SD_CONNECTOR_YAMAICHI_FPS_GRND(2)
#end
#macro CON_SD_CONNECTOR_YAMAICHI_FPS_CARD()
CON_SD_CONNECTOR_YAMAICHI_FPS_GRND(1)
#end
#macro CON_SD_CONNECTOR_YAMAICHI_FPS_NO_CARD()
CON_SD_CONNECTOR_YAMAICHI_FPS_GRND(0)
#end


/********************************************************************************************************************************************
//Duane Clark <dclark@akamail.com>
********************************************************************************************************************************************/
#macro CON_SMA_JH_GRND()
union
{
  union
  {
    object{
      SMA_JACK(8.25) 
      rotate<0,180,0> 
      translate<0,0,11.68>
    }
    cone{<0,0,3.43> 3.19 <0,0,3.93> 2.68 }
    translate<0,6.35,0>
  }
  
  // the body piece
  object
  {
    intersection
    {
      box{<-3.43,-3.43,4.75><3.43,3.43,13.47> }
      sphere{<0,0,9.2>,5.85 }
      cylinder{<0,0,4> <0,0,14> 4.7 }
      cylinder{<-4,0,9.11> <4,0,9.11> 5.35 }
      cylinder{<0,-4,9.11> <0,4,9.11> 5.35 }
    }
    translate<0,0,-2.79>
    rotate<-90,0,0>
  }
  
  // the base piece
  union
  {
    difference{
      cylinder{<0,0,2.79> <0,0,4.25> 4.10 }
      cylinder{<0,0,2.7> <0,0,3.3> 3.08 }
      box{<-2,-2,-2><2,2,2> rotate<0,0,45> translate<4.6,0,1.3>}
      box{<-2,-2,-2><2,2,2> rotate<0,0,45> translate<0,4.6,1.3>}
      box{<-2,-2,-2><2,2,2> rotate<0,0,45> translate<-4.6,0,1.3>}
      box{<-2,-2,-2><2,2,2> rotate<0,0,45> translate<0,-4.6,1.3>}
    }
    box{<-0.51,-0.51,0><0.51,0.51,2.79> rotate<0,0,45> translate<2.54,2.54,0> }
    box{<-0.51,-0.51,0><0.51,0.51,2.79> rotate<0,0,45> translate<-2.54,2.54,0> }
    box{<-0.51,-0.51,0><0.51,0.51,2.79> rotate<0,0,45> translate<2.54,-2.54,0> }
    box{<-0.51,-0.51,0><0.51,0.51,2.79> rotate<0,0,45> translate<-2.54,-2.54,0> }
    cylinder{<0,0,0.25> <0,0,4.25> 0.635 }
    cone{<0,0,0> 0.5 <0,0,0.25> 0.635 }
    cone{<0,0,4.25> 4.10 <0,0,4.75> 3.60 }
    translate<0,0,-2.79>
    rotate<-90,0,0>
  }
  texture{col_gold}
  rotate<0,90,0>
}
#end
#macro CON_SMA_JH()
CON_SMA_JH_GRND()
#end


/********************************************************************************************************************************************
//Duane Clark <dclark@akamail.com>
********************************************************************************************************************************************/
#macro CON_SMA_JV_GRND()
union
{
  object{
    SMA_JACK(8.06) 
    rotate<0,180,0> 
    translate<0,0,12.31>
  }
  cone{<0,0,4.24> 3.19 <0,0,4.75> 2.68 }
  difference{
    cylinder{<0,0,2.79> <0,0,4.25> 4.10 }
    cylinder{<0,0,2.7> <0,0,3.3> 3.08 }
    box{<-2,-2,-2><2,2,2> rotate<0,0,45> translate<4.6,0,1.3>}
    box{<-2,-2,-2><2,2,2> rotate<0,0,45> translate<0,4.6,1.3> }
    box{<-2,-2,-2><2,2,2> rotate<0,0,45> translate<-4.6,0,1.3>}
    box{<-2,-2,-2><2,2,2> rotate<0,0,45> translate<0,-4.6,1.3>}
  }
  box{<-0.51,-0.51,0><0.51,0.51,2.79> rotate<0,0,45> translate<2.54,2.54,0>}
  box{<-0.51,-0.51,0><0.51,0.51,2.79> rotate<0,0,45> translate<-2.54,2.54,0>}
  box{<-0.51,-0.51,0><0.51,0.51,2.79> rotate<0,0,45> translate<2.54,-2.54,0>}
  box{<-0.51,-0.51,0><0.51,0.51,2.79> rotate<0,0,45> translate<-2.54,-2.54,0>}
  cylinder{<0,0,0.25> <0,0,4.25> 0.635}
  cone{<0,0,0> 0.5 <0,0,0.25> 0.635}
  translate<0,0,-2.79>
  texture{col_gold}
  rotate<-90,0,0>
}
#end
#macro CON_SMA_JV()
CON_SMA_JV_GRND()
#end


/********************************************************************************************************************************************
//AMP 147323
//n		Number of Pins
********************************************************************************************************************************************/
#macro CON_SMD_AMP_147323_GRND(n)
union{

	#local pin =
	union{
		object{TOOLS_RECT_BOGEN(0.5,90,0.64,0.64,2.5,1.5) rotate<0,90,0> translate<0,0.32,0>}
		object{TOOLS_RECT_BOGEN(0.5,90,0.64,0.64,10,1.5) rotate<0,90,0> rotate<180,0,0> translate<0,3.32,0>}
	
	}

	//Pins
	union{
		#local i = 0;
		#while(i<n)
			object{pin translate<-(n-1)*2.54/2+i*2.54,0,0>}
			#local i = i + 1;
		#end
		
		box{<(n+3)*2.54/2-0.4,0,7.3><(n+3)*2.54/2-3.5,0.3,3.7>}
		box{<-(n+3)*2.54/2+0.4,0,7.3><-(n+3)*2.54/2+3.5,0.3,3.7>}
		
		texture{col_silver}
	}

	//Plastikkoerper
	union{
		difference{
			union{
				object{Round_Box_Union(<(n+3)*2.54/2-0.8,0.2,0>,<-(n+3)*2.54/2+0.8,5.3,13.6>,0.1)}
				object{Round_Box_Union(<-1.27*2-0.5,5,10.6>,<1.27*2+0.5,6.9,13.6>,0.1)}
				
			}
			object{Round_Box_Union(<(n+3)*2.54/2-2.8,1.2,4.6>,<-(n+3)*2.54/2+2.8,4.3,13.7>,0.1)}
			box{<-1.27,4.2,4.6><1.27,5.4,13.7>}
			box{<-1.27*2,4.2,10.6><1.27*2,6.2,13.7>}
			

			#local i = 0;
			#while(i<n+2)
				box{<-0.3,0,-0.1> <0.3,5.4,0.6> translate<-(n+1)*2.54/2+i*2.54,0,0>}
				#local i = i + 1;
			#end
		}

		texture{pigment{Gray30}}
	}
}
#end

#macro CON_SMD_AMP_147323_2()
CON_SMD_AMP_147323_GRND(2)
#end
#macro CON_SMD_AMP_147323_3()
CON_SMD_AMP_147323_GRND(3)
#end
#macro CON_SMD_AMP_147323_4()
CON_SMD_AMP_147323_GRND(4)
#end
#macro CON_SMD_AMP_147323_5()
CON_SMD_AMP_147323_GRND(5)
#end
#macro CON_SMD_AMP_147323_6()
CON_SMD_AMP_147323_GRND(6)
#end
#macro CON_SMD_AMP_147323_7()
CON_SMD_AMP_147323_GRND(7)
#end
#macro CON_SMD_AMP_147323_8()
CON_SMD_AMP_147323_GRND(8)
#end
#macro CON_SMD_AMP_147323_9()
CON_SMD_AMP_147323_GRND(9)
#end
#macro CON_SMD_AMP_147323_10()
CON_SMD_AMP_147323_GRND(10)
#end


/********************************************************************************************************************************************
//Molex 53261
//n		Number of Pins
********************************************************************************************************************************************/
#macro CON_SMD_MOLEX_53261_GRND(n)
union{

	#local pin =
	union{
		box{<-0.18,-0.35,0><0.18,0.35,3.6> translate<0,1.375,0>}
		box{<-0.18,0.8,0><0.18,1.375,-0.3> }
		box{<-0.18,0.0,-0.3><0.18,1.375,-1.0> }
	}

	//Pins
	union{
		#local i = 0;
		#while(i<n)
			object{pin translate<-(n-1)*1.25/2+i*1.25,0,0>}
			#local i = i + 1;
		#end
		
		object{ TOOLS_RECT_BOGEN(0.5,90,0.25,2.2,1.2,1) rotate<0,180,0> translate<-(4.25+(n-2)*1.25)/2-0.2,0.125,2.1>  }
		object{ TOOLS_RECT_BOGEN(0.5,90,0.25,2.2,1.2,1) rotate<0,0,0> translate<(4.25+(n-2)*1.25)/2+0.2,0.125,2.1>  }
		texture{col_silver}
	}

	//Plastikkoerper
	union{
		difference{
			box{<-(4.25+(n-2)*1.25)/2,0,0.01><(4.25+(n-2)*1.25)/2,3.4,4.2>}
			box{<-(3.05+(n-2)*1.25)/2,0.6,0.8><(3.05+(n-2)*1.25)/2,3.0,4.3>}
			box{<-(4.3+(n-2)*1.25)/2,2.99,3.2><(4.3+(n-2)*1.25)/2,3.41,4.3>}
			box{<-(2.5+(n-2)*1.25)/2,2.99,2.8><(2.5+(n-2)*1.25)/2,3.41,4.3>}

			#local i = 0;
			#while(i<n+2)
				box{<-0.3,2.8,0> <0.3,3.41,0.6> translate<-(n+1)*1.25/2+i*1.25,0,0>}
				#local i = i + 1;
			#end
		}
		
		box{<-(4.25+(n-2)*1.25)/2,0.25,0.9><-(4.25+(n-2)*1.25)/2-1.5,2,3.8>}
		box{<(4.25+(n-2)*1.25)/2,0.25,0.9><(4.25+(n-2)*1.25)/2+1.5,2,3.8>}

		texture{pigment{Gray30}}
	}

}
#end

#macro CON_SMD_MOLEX_53261_2()
CON_SMD_MOLEX_53261_GRND(2)
#end
#macro CON_SMD_MOLEX_53261_3()
CON_SMD_MOLEX_53261_GRND(3)
#end
#macro CON_SMD_MOLEX_53261_4()
CON_SMD_MOLEX_53261_GRND(4)
#end
#macro CON_SMD_MOLEX_53261_5()
CON_SMD_MOLEX_53261_GRND(5)
#end
#macro CON_SMD_MOLEX_53261_6()
CON_SMD_MOLEX_53261_GRND(6)
#end
#macro CON_SMD_MOLEX_53261_7()
CON_SMD_MOLEX_53261_GRND(7)
#end
#macro CON_SMD_MOLEX_53261_8()
CON_SMD_MOLEX_53261_GRND(8)
#end
#macro CON_SMD_MOLEX_53261_9()
CON_SMD_MOLEX_53261_GRND(9)
#end
#macro CON_SMD_MOLEX_53261_10()
CON_SMD_MOLEX_53261_GRND(10)
#end
#macro CON_SMD_MOLEX_53261_11()
CON_SMD_MOLEX_53261_GRND(11)
#end
#macro CON_SMD_MOLEX_53261_12()
CON_SMD_MOLEX_53261_GRND(12)
#end
#macro CON_SMD_MOLEX_53261_13()
CON_SMD_MOLEX_53261_GRND(13)
#end
#macro CON_SMD_MOLEX_53261_14()
CON_SMD_MOLEX_53261_GRND(14)
#end
#macro CON_SMD_MOLEX_53261_15()
CON_SMD_MOLEX_53261_GRND(15)
#end


/********************************************************************************************************************************************
// Small stereo 3.5mm
********************************************************************************************************************************************/
#macro CON_STEREO_35MM_GRND()
union{
difference {
union{
  box{<0,0,0><7,5,12> translate <-3.5,1,2>}
  box{<0,0,0><5,1,10> translate <-2.5,1,2>}
  cylinder {<0,0,0><0,0,2> 3 translate <0,3,0>}
 }
 cylinder {<0,0,12><0,0,-0.1> 1.75 translate <0,3,0>}
 box{<0,0,0><3.5,2.5,3.5> translate <-1.75,3.6,8>}
 box{<0,0,0><6,4.5,10.5> translate <-3,1,4>}

}

 cylinder {<0,0,0><0,1,0> 0.5 translate <0,0,4.5>}
 cylinder {<0,0,0><0,1,0> 0.5 translate <0,0,11.5>}

union{
  // Legs front
  box{<0,0,0><0.3,8.5,1.1> translate <-3.65,-2.5,4>}
  box{<0,0,0><0.3,8.5,1.1> translate <3.35,-2.5,4>}

  // legs rear
  box{<0,0,0><0.3,8.4,1.1> translate <-3.5,-2.5,12.9>}
  box{<0,0,0><0.3,8.4,1.1> translate <3.2,-2.5,12.9>}

  // left,right side
  box{<0,0,0><0.3,5,3.5> translate <-3.65,1,2.7>}
  box{<0,0,0><0.3,5,3.5> translate <3.35,1,2.7>}

  // top
  box{<0,0,0><7,0.3,3.5> translate <-3.65,5.8,2.7>}
  box{<0,0,0><2.5,0.3,8> translate <-1.25,5.8,2.7>}

  box{<0,0,0><2.5,0.3,5> translate <-1.25,3.8,8>}

  texture{T_Chrome_5A}
}


}
pigment{Gray20}
translate <0,0,-8>
#end




#macro CON_STEREO_35MM()
CON_STEREO_35MM_GRND()
#end


/********************************************************************************************************************************************
//Macro für USB-Buchse USB-787616 aus der con-amp.lib
//12.10.2004
//Designed by hebel23 <hebel(replace with at)hebel23.de> 
********************************************************************************************************************************************/
#macro CON_USB_A_001_GRND()
union{
        /* Blechgehäuse  */               
        difference{
                box { <-7,2,0>,<7,8,14>} // Außenhülle
                box { <-6.5, 2.5, -1>, <6.5, 7.5, 14> } // Aussparung in der Mitte
                box { <-6.5, 0, 12>, <6.5, 7.5, 15> }  // Aussparung hinten
                difference{                                      // Feder links oben                                      
                           cone {<-3,8,8> , 1.5 , <-3,8,1> , 1.0}
                           cone {<-3,8,8> , 1 , <-3,8,2> , 0.5}
                          }
                difference{                                      // Feder rechts oben                                      
                           cone {<3,8,8> , 1.5 , <3,8,1> , 1.0}
                           cone {<3,8,8> , 1 , <3,8,2> , 0.5}
                          }
                difference{                                      // Feder links unten                                     
                           cone {<-3,2,8> , 1.5 , <-3,2,1> , 1.0}
                           cone {<-3,2,8> , 1 , <-3,2,2> , 0.5}
                          }
                difference{                                      // Feder rechts unten                                      
                           cone {<3,2,8> , 1.5 , <3,2,1> , 1.0}
                           cone {<3,2,8> , 1 , <3,2,2> , 0.5}
                          }
                difference{                                      // Feder links                                      
                           cone {<-7,5,8> , 1.5 , <-7,5,1> , 1.0}
                           cone {<-7,5,8> , 1 , <-7,5,2> , 0.5}
                          }
                difference{                                      // Feder rechts                                      
                           cone {<7,5,8> , 1.5 , <7,5,1> , 1.0}
                           cone {<7,5,8> , 1 , <7,5,2> , 0.5}
                          }
                texture{col_silver}
                } 
        union{
                box { <-7, -2, 9.5>, <-6.5, 3, 11> }            // linke Lötlasche
                box { <7, -2, 9.5>, <6.5, 3, 11> }              // rechte Lötasche
                texture{col_silver}
               }
        union{       
                union{TOOLS_RECT_BOGEN(0.5,90,0.5,4,0,0)rotate<90,0,0>translate<6.75,5,-0.5>}
                union{TOOLS_RECT_BOGEN(0.5,90,0.5,4,0,0)rotate<90,270,0>translate<-6.75,5,-0.5>}
                union{TOOLS_RECT_BOGEN(0.5,90,0.5,4,0,0)rotate<90,0,90>translate<-3.5,7.75,-0.5>}
                union{TOOLS_RECT_BOGEN(0.5,90,0.5,4,0,0)rotate<90,0,90>translate<3.5,7.75,-0.5>}
                union{TOOLS_RECT_BOGEN(0.5,90,0.5,4,0,0)rotate<90,0,270>translate<-3.5,2.25,-0.5>}
                union{TOOLS_RECT_BOGEN(0.5,90,0.5,4,0,0)rotate<90,0,270>translate<3.5,2.25,-0.5>}
                texture{col_silver}
               }
        /* weißer Kontaktträger */
        difference{
                box { <-5,4,1>,<5,6,12>} // Quader in der Mitte
                union{
                      box{<-6,5.3,0>,<6,7,5>}
                      rotate <-10, 0, 0>        // Abflachung oben
                      }
                union{
                      box{<-6,4.3,0>,<6,3.5,5>}
                      rotate <10, 0, 0>        // Abflachung unten
                     }
                 texture{pigment{color White}}
                }  
        /* Kontakte */
        difference{    
                  union{
                        box { <-3.8,3.5,3>,<-3,4,8>} // Kontakt 1
                        box { <-1.8,3.5,3>,<-0.8,4,8>} // Kontakt 2
                        box { <1.8,3.5,3>,<0.8,4,8>} // Kontakt 3
                        box { <3.8,3.5,3>,<3,4,8>} // Kontakt 4
                        texture{col_gold}
                        }   
                  union{
                        box{<-4,4,1>,<4,3.5,5>}
                        rotate <5, 0, 0> // Abflachung der Kontakte
                        }
                }
        union{
                box { <-3.8,-2,12.5>,<-3.2,5,13>} // Kontakt 1 hinten
                box { <-1.3,-2,12.5>,<-0.7,5,13>} // Kontakt 2 hinten
                box { <0.7,-2,12.5>,<1.3,5,13>} // Kontakt 3 hinten
                box { <3.2,-2,12.5>,<3.8,5,13>} // Kontakt 4 hinten
                texture{col_gold}
             }
        /* weißer Sockel */
        union{      
                difference{
                        box { <-6,0,2>,<6,2,12>} // Sockel links
                        box { <-1,0,1>,<1,2,12>} // Sockel rechts
                        union{
                                box{<1.5,0,0>,<7,2,12>}
                                rotate <-10, 0, 0>        // Abflachung links
                                }
                         union{
                                box{<-1.5,0,0>,<-7,2,12>}
                                rotate <-10, 0, 0>        // Abflachung links
                                }
                               }                
                        difference{
                        box { <-6.5, 0.5, 12>, <6.5, 7.5, 14> } // Sockel hinten
                        box { <-6, 2.5, 12.5>, <6, 8, 15> }  // Aussparung für Kontakte
                        box { <-3.8,-2,12>,<-3.2,5,15> }  // Aussparung für Kontakte
                        box { <-1.3,-2,12>,<-0.7,5,15> }  // Aussparung für Kontakte
                        box { <0.7,-2,12>,<1.3,5,15> }  // Aussparung für Kontakte
                        box { <3.2,-2,12>,<3.8,5,15> }  // Aussparung für Kontakte
                texture{pigment{color White}}
                                }
             }  
}
#end
#macro CON_USB_A_001()
CON_USB_A_001_GRND()
#end


/********************************************************************************************************************************************
//Macro fuer USB-Stecker, flach, Platinenmontage,   keine eagle-library,     Joerg Bredendiek <sprut(replace with at)sprut.de>    
//
// Nullpunkt zwischen den Massestiften
// pinabstand 2   mm
// pinbreite  1   mm
// pindicke   0.4 mm
// Loetpunkte 2   mm hinter Mittlepunkt
// Befestigungspunkte seitlich je 6 mm von Mitte entfernt  
********************************************************************************************************************************************/
#macro CON_USB_A_002_GRND()
#local tex_usb_metal = texture { T_Chrome_5B } ;
union{                          
        #local a = -9;
        /* Blechgehaeuse  0.3mm dickes Blech*/               
        difference{                                                                   
                union{
                        box{<-5.7, 4.2, 1><+5.7, 4.5, a-8.65>}            //oben
                        box{<-5.7, 0, 1><-0.1, 0.3, a-8.65>}              //unten links
                        box{< 0.1, 0, 1><+5.7, 0.3, a-8.65>}              //unten rechts
                        box{<-6, 4.2, 1><-5.7, 0.3, a-8.65>}              //links
                        box{< 6, 4.2, 1>< 5.7, 0.3, a-8.65>}              //rechts
                        cylinder{<-5.7, 4.2, 1><-5.7, 4.2, a-8.65> 0.3 }  //runde Kanten
                        cylinder{< 5.7, 4.2, 1>< 5.7, 4.2, a-8.65> 0.3 }
                        cylinder{<-5.7, 0.3, 1><-5.7, 0.3, a-8.65> 0.3 }
                        cylinder{< 5.7, 0.3, 1>< 5.7, 0.3, a-8.65> 0.3 }
                } 
                box { <-5.7, 0.3, 1.1> <5.7, 4.2, a-8.7> } // Aussparung in der Mitte       
                box { <-3.5, -0.1, -11>, <-1, 4.6, -13> }  // Aussparung oben und unten
                box { < 3.5, -0.1, -11>, < 1, 4.6, -13> }  // Aussparung oben und unten 
                sphere {<0, 4.75, a> 0.5}                  // Delle in oberem Blech
                texture{ T_Chrome_5B}
                }             

         union{
                box { <-5.75, -2, -0.75>, <-6.25, 3, 0.75> }            // linke Loetlasche
                box { < 5.75, -2, -0.75>, < 6.25, 3, 0.75> }            // rechte Loetasche
                texture{col_silver}
               }

        // weisser Kontakttraeger 
        box { <-5.6, 0.3,a>,<5.6, 2.25,a-8.65> texture{pigment{color White}}}// Zunge vorn
        box { <-5.7, 0.3,a>,<5.7, 4.2 , 1>     texture{pigment{color White}}}// Quader hinten
     

        // Kontakte 
       union{
                box { <-3.8, 2, a>,<-3  , 2.4, a-7.41>} // Kontakt 1
                box { <-1.8, 2, a>,<-0.8, 2.4, a-6.41>} // Kontakt 2
                box { < 1.8, 2, a>,< 0.8, 2.4, a-6.41>} // Kontakt 3
                box { < 3.8, 2, a>,< 3,   2.4, a-7.41>} // Kontakt 4
                texture{col_gold}
        }   
        union{
		box { <-3.8, 2, 2>,<-3.2, 2.4, a-7.41>} // Kontakt 1
		box { <-1.3, 2, 2>,<-0.7, 2.4, a-6.41>} // Kontakt 2
		box { < 0.7, 2, 2>,< 1.3, 2.4, a-6.41>} // Kontakt 3
		box { < 3.2, 2, 2>,< 3.8, 2.4, a-7.41>} // Kontakt 4

                box { <-3.8, -4, 2.25>,<-3.2, 2.4, 1.75>} // Kontakt 1 hinten
                box { <-1.3, -4, 2.25>,<-0.7, 2.4, 1.75>} // Kontakt 2 hinten
                box { < 0.7, -4, 2.25>,< 1.3, 2.4, 1.75>} // Kontakt 3 hinten
                box { < 3.2, -4, 2.25>,< 3.8, 2.4, 1.75>} // Kontakt 4 hinten
                texture{col_gold}
             }
}
#end

#macro CON_USB_A_002()
CON_USB_A_002_GRND()
#end


/********************************************************************************************************************************************
// Desc: USB Connector Type B, AMP 787780
// Date: 22.03.2004
// Auth: Friedrich Bleikamp, <fbleikamp(replace with at)web.de>
********************************************************************************************************************************************/
#macro CON_USB_B_001_GRND()
union {

#macro SHELL_PIN_USB_B()
   merge{
      difference {
         box { <-0.2,-3.5,-1.15> <0.2,0.5,1.15>}
         box { <-0.21,-4,-1.15> <0.21,1,1.15> translate <0,0,2.3> rotate<6.5,0,0>}
         box { <-0.21,-4,-1.15> <0.21,1,1.15> translate <0,0,-2.3> rotate<-6.5,0,0>}
      }
      cylinder { <-0.2,0,0> <0.2,0,0>, 0.75 translate <0,-3.5,0>}
   }texture{col_silver}
#end

   //Metall shell
   union {
      difference {
         union {
            box { <0,0.5,-5.6> <0.4,10.7,5.6>}                 // front
            box { <0.6,0.5,5.8> <11.5,10.8,6.2>}               // left side
            box { <0.6,0.5,-5.8> <11.5,10.8,-6.2>}             // right side
            object{ TOOLS_RECT_BOGEN(0.2,90,0.4,10.0,0,0) rotate<0,90,-90> translate<0.2,5.5,6.0>}      
            object{ TOOLS_RECT_BOGEN(0.2,90,0.4,10.0,0,0) rotate<0,-90,-90> translate<0.2,5.5,-6.0>}      
         }    
         box { <-1,-1,-6.5> <1,1,6.5> translate<8.5,3.6,0>}       // cutout bottom
         box { <-1,-1,-6.5> <1,1,6.5> translate<8.5,7.6,0>}       // cutout top
         box { <-0.4,-0.25,-6.5> <0.4,0.25,6.5> translate<0.35,2.75,0>}// cutout front
         cylinder { <0,0,-6.5> <0,0,6.5>, 0.25 translate <0.75,2.75,0>} 
         box { <-0.4,-0.25,-6.5> <0.4,0.25,6.5> translate<0.35,6.25,0>}// cutout front
         cylinder { <0,0,-6.5> <0,0,6.5>, 0.25 translate <0.75,6.25,0>} 
         prism {linear_sweep linear_spline 0, 0.6, 7,             // cutout front
         < 0,-4.85>, < 6,-4.85>, < 7.85,-3.0>, < 7.85,3.0>, < 6,4.85>, <0,4.85>,< 0,-4.85>
         rotate<0,0,90> translate <0.5,1.5,0>}
      }
   box { <0.6,10.9,-5.8> <11.5,11.3,5.8>}                      // top
   object{ TOOLS_RECT_BOGEN(0.2,90,0.4,11.2,0,0) rotate<0,0,-90> translate<0.2,11.1,0>}      
   object{ TOOLS_RECT_BOGEN(0.2,90,0.4,3,3,1) rotate<90,0,0> translate<0.2,4.5,4.2>}      
   object{ TOOLS_RECT_BOGEN(0.2,90,0.4,3,3,1) rotate<-90,0,0> translate<0.2,4.5,-4.2>}      
   object{ SHELL_PIN_USB_B() rotate<0,90,0> translate<10.3,0.5,6.0>}
   object{ SHELL_PIN_USB_B() rotate<0,90,0> translate<10.3,0.5,-6.0>}   
   texture{col_silver}
   }
   
   //Housing: Thermoplastic, glass filled (UL94V-0)
   union { 
      difference {
         TOOLS_ROUNDED_BAR(<-5.5,0.4,0>,<5.5,10.9,15.3>,0.5)
         box { <-4.0,1.5,-0.1> <4.0,8.5,3.5> } 
         box { <-1.7,0,-0.1> <-0.8,8.5,4.5> }
         box { <0.8,0,-0.1> <1.7,8.5,4.5> }
         box { <-5.6,4.2,-0.1> <5.6,7.7,3.4> }   
         object{ TOOLS_ROUNDED_BAR(<-4.25,2.0,8.5>,<4.25,7.0,16.1>,0.5)} 
         object{ TOOLS_ROUNDED_BAR(<-2.90,7.0,8.5>,<2.90,8.5,16.1>,0.5)} 
         object{ TOOLS_ROUNDED_BAR( <-1.41,-1.41,8.5> <1.41,1.41,16.1>,0.5) rotate<0,0,45> translate<2.45,6.6,0>}
         object{ TOOLS_ROUNDED_BAR( <-1.41,-1.41,8.5> <1.41,1.41,16.1>,0.5) rotate<0,0,45> translate<-2.45,6.6,0>}
      }
   object{ Round_Box_Union( <-2.8,3.7,8.5> <2.8,6.7,15.5>,0.5)}
   box { <-0.25,-0.6,0> <0.25,0.6,4> translate<5.7,2.0,0>}
   box { <-0.25,-0.6,0> <0.25,0.6,4> translate<-5.7,2.0,0>}
   box { <-0.25,-0.6,0> <0.25,0.6,4> translate<5.7,9.75,0>}
   box { <-0.25,-0.6,0> <0.25,0.6,4> translate<-5.7,9.75,0>} 
   box { <-6.0,-0.7,-1> <6.0,0.7,0.6> translate<0,3.5,7>}
   box { <-6.0,-0.7,-1> <6.0,0.7,0.6> translate<0,7.5,7>}
   pigment{Gray25} rotate<0,-90,0> translate<15.7,0,0>
   } 

   //Contacts
   union {
      object{ TOOLS_RECT_BOGEN(0.2,90,0.25,0.7,12.2,7.25) rotate<0,0,180> translate<13.0,3.6,-1.25>}      
      object{ TOOLS_RECT_BOGEN(0.2,90,0.25,0.7,12.2,7.25) rotate<0,0,180> translate<13.0,3.6,1.25>}      
      object{ TOOLS_RECT_BOGEN(0.2,90,0.25,0.7,14.2,10.25) rotate<0,0,180> translate<15.0,6.8,-1.25>}      
      object{ TOOLS_RECT_BOGEN(0.2,90,0.25,0.7,14.2,10.25) rotate<0,0,180> translate<15.0,6.8,1.25>}
      texture{col_gold}     
   }
}     
#end
#macro CON_USB_B_001()
CON_USB_B_001_GRND()
#end


/********************************************************************************************************************************************
//Macro für USB-Mini-Buchse MOLEX 54919-0578 (RS-Components Artikel: 418-0172)
//Designed by hebel23 <hebel(replace with at)hebel23.de>
//24.10.2004
********************************************************************************************************************************************/
#macro CON_USB_B_002_GRND()
union{
    union{      
     // Blechgehäuse                    
    difference{      
    union{      
          union{TOOLS_RECT_BOGEN(0.25,90,0.25,8,4,0)translate<-3.355,0.15,-4>}
          union{TOOLS_RECT_BOGEN(0.25,90,0.25,8,4,0)rotate<0,180,0>translate<3.355,0.15,-4>}
          union{TOOLS_RECT_BOGEN(0.25,90,0.25,8,0,1)translate<-3.85,2.15,-4>}
          union{TOOLS_RECT_BOGEN(0.25,90,0.25,8,0,1)rotate<0,180,0>translate<3.85,2.15,-4>}
          union{TOOLS_RECT_BOGEN(0.25,90,0.25,8,0,1.3)rotate<0,0,180>translate<-3.35,2.2,-4>}
          union{TOOLS_RECT_BOGEN(0.25,90,0.25,8,0,1.3)rotate<0,180,180>translate<3.35,2.2,-4>}
          union{TOOLS_RECT_BOGEN(0.25,90,0.25,8,4,0)rotate<0,0,180>translate<3.85,3.85,-4>}
          union{TOOLS_RECT_BOGEN(0.25,90,0.25,8,4,0)rotate<0,180,180>translate<-3.85,3.85,-4>}
         }     
          box { <-4.5, -0.1, -2.9>, <4.5,2.75,-9> }       
             difference{                                                                           
             cone {<-2.5,4,-4.5> , 0.75 , <-2.5,4,-1> , 0.5}
             cone {<-2.5,4,-4.5> , 0.5 , <-2.5,4,-2> , 0.25}
                }
             difference{                                                                          
             cone {<2.5,4,-4.5> , 0.75 , <2.5,4,-1> , 0.5}
             cone {<2.5,4,-4.5> , 0.5 , <2.5,4,-2> , 0.25}
                }
             difference{                                                                           
             box { <-0.75, 3, -1>, <0.75,5,-6> }      
             box { <-0.5, 3, -1>, <0.5,5,-5> }      
                }
          }
     // Lötfahnen
     difference{     
     union{
          union{TOOLS_RECT_BOGEN(0.5,90,0.25,5.5,0.5,2.5)translate<3.85,0.1,-5.75>}
          union{TOOLS_RECT_BOGEN(0.5,90,0.25,5.5,0.5,2.5)rotate<0,180,0>translate<-3.85,0.1,-5.75>}
          }
                box { <-4.01, -0.1, -5>, <-5.1,1,-7> }     
                box { <4.01, -0.1, -5>, <5.1,1,-7> }       
          }
          texture{col_silver}
         }
     // schwarzer Kontaktträger in der Mitte
        difference{
                box { <-2.5,1,-1>,<2.5,2,-7>} 
                box { <-0.25,1.25,0>,<0.25,1.75,-8>} 
                box { <-1.00,1.25,0>,<-0.50,1.75,-8>} 
                box { <-1.75,1.25,0>,<-1.25,1.75,-8>} 
                box { <1.00,1.25,0>,<0.50,1.75,-8>} 
                box { <1.75,1.25,0>,<1.25,1.75,-8>} 
                texture{pigment{color rgb <0.1, 0.1, 0.1>}}
                }
     // schwarzer Kontaktträger Hinten
         difference{
                box { <-3.75,0,-6>,<3.75,3.75,-8.5>} 
                box { <-2,1.9,-7>,<3,4,-8.6>} 
                box { <-4,3,-8>,<4,4,-8.6>} 
                box { <-3,-0.1,-7.5>,<3,4,-8.6>} 
                box { <-0.25,-0.1,0>,<0.25,2,-8.6>} 
                box { <-1.00,-0.1,0>,<-0.50,2,-8.6>} 
                box { <-1.75,-0.1,0>,<-1.25,2,-8.6>} 
                box { <1.00,-0.1,0>,<0.50,2,-8.6>} 
                box { <1.75,-0.1,0>,<1.25,2,-8.6>} 
                texture{pigment{color rgb <0.1, 0.1, 0.1>}}
                }                
        // Kontakte
                difference{
                union{
                      union{TOOLS_RECT_BOGEN(0.25,90,0.25,3.5,1,0.65)rotate<0,90,0>translate<0,0.125,-7.3>}
                      union{TOOLS_RECT_BOGEN(0.25,90,0.25,3.5,0,0)rotate<180,270,0>translate<0,1.5,-7.3>}
                      box { <-0.25,1.5,-1>,<0.25,1.75,-7>rotate<7,0,0>} 
                      box { <-1.00,1.5,-1>,<-0.50,1.75,-7>rotate<7,0,0>} 
                      box { <-1.25,1.5,-1>,<-1.75,1.75,-7>rotate<7,0,0>} 
                      box { <1.00,1.5,-1>,<0.50,1.75,-7>rotate<7,0,0>} 
                      box { <1.25,1.5,-1>,<1.75,1.75,-7>rotate<7,0,0>} 
                     }   
                box { <-0.5,-0.1,-7>,<-0.25,1.25,-9.5>}      
                box { <0.5,-0.1,-7>,<0.25,1.25,-9.5>}      
                box { <-1.0,-0.1,-7>,<-1.25,1.25,-9.5>}      
                box { <1.0,-0.1,-7>,<1.25,1.25,-9.5>}      
                texture{col_silver}
                }
        // Aufkleber
                union{
                box{<-3.2,3.9,-0.5><3.2,4.05,-7>}
                pigment{color rgbf <1, 0, 0, 0.9>}
               }
}
#end
#macro CON_USB_B_002()
CON_USB_B_002_GRND()
#end


/********************************************************************************************************************************************
// Wago 733/734
// Stefan Seegel <dahamm@gmx.net>
********************************************************************************************************************************************/
#macro CON_WAGO73X_PINHEADER_GRND(pins, rm, wo, height, depth, h1, h2, h3, n1, n2, p1, p2, pw, ph)

#macro WAGOSTIFT(w, h)
difference{
  box{<-w/2,0,-w/2><w/2,h,w/2>}
texture{col_silver}
}
#end

#local WIDTH = pins * rm + wo;
union{
  union{
    difference{
      box{<-WIDTH/2,0,-depth/2><WIDTH/2,height,depth/2>}

      box{<-WIDTH/2+1,h1,-depth/2+1.9><WIDTH/2-1,height+1,depth/2-1.7>}

      box{<-WIDTH/2-0.5,-1,-2.5><-WIDTH/2+0.4,height-1.9,2.5>}
      box{<WIDTH/2+0.5,-1,-2.5><WIDTH/2-0.4,height-1.9,2.5>}

      box{<-WIDTH/2+0.7,-1,-0.75><-WIDTH/2+1.3,height+1,0.75>}
      box{<WIDTH/2-0.7,-1,-0.75><WIDTH/2-1.3,height+1,0.75>}

      box{<-WIDTH/2+0.7,-1,-0.75><-WIDTH/2+1.3,height+1,0.75>}
      box{<WIDTH/2-0.7,-1,-0.75><WIDTH/2-1.3,height+1,0.75>}

      box{<-WIDTH/2-0.1,2,-0.75><-WIDTH/2+1.1,height-1.9,0.75>}
      box{<WIDTH/2+0.1,2,-0.75><WIDTH/2-1.1,height-1.9,0.75>}

      box{<WIDTH/2-1,height-5.9,-depth/2+0.3><WIDTH/2-2.4,height+1,-depth/2+2.0>}

      box{<-WIDTH/2+n1,height-5.9,-depth/2+0.3><-WIDTH/2+n1+n2,height+1,-depth/2+2.0>}

      box{<-(pins-1)*rm/2-0.5,2,depth/2+1><-(pins-1)*rm/2+0.5,height-2,depth/2-1.8>}
      box{<(pins-1)*rm/2-0.5,2,depth/2+1><(pins-1)*rm/2+0.5,height-2,depth/2-1.8>}

      box{<-(pins-1)*rm/2-p1/2,-1,-depth/2-1><-(pins-1)*rm/2+p1/2,h3,-depth/2+0.3>}
      box{<(pins-1)*rm/2-p1/2,-1,-depth/2-1><(pins-1)*rm/2+p1/2,h3,-depth/2+0.3>}
      box{<-(pins-1)*rm/2-p2/2,-1,-depth/2-1><-(pins-1)*rm/2+p2/2,h3,-depth/2+2>}
      box{<(pins-1)*rm/2-p2/2,-1,-depth/2-1><(pins-1)*rm/2+p2/2,h3,-depth/2+2>}

      #declare pin=0;
      #while (pin < pins)
        box{<-(pins-1)*rm/2+pin*rm-p1/2,-1,depth/2+1><-(pins-1)*rm/2+pin*rm+p1/2,height-h2,depth/2-1>}
        #declare pin=pin+1;
      #end

      #declare pin=1;
      #while (pin < pins - 1)
        box{<-(pins-1)*rm/2+pin*rm-p1/2,-1,-depth/2-1><-(pins-1)*rm/2+pin*rm+p1/2,height-h2,-depth/2+0.3>}
        box{<-(pins-1)*rm/2+pin*rm-p2/2,-1,-depth/2-1><-(pins-1)*rm/2+pin*rm+p2/2,height-h2,-depth/2+2>}
        #declare pin=pin+1;
      #end

      pigment{Gray70}
    }

    #declare pin=0;
    #while (pin < pins)
      box{<-(pins-1)*rm/2+pin*rm-1,0,-1><-(pins-1)*rm/2+pin*rm+1,3,1> pigment{Gray70}}
      #object{WAGOSTIFT(pw, ph) translate<-(pins-1)*rm/2+pin*rm,height-ph-1.2,0>}
      #declare pin=pin+1;
    #end

  }
}
#end
#macro CON_WAGO_733_332()
CON_WAGO73X_PINHEADER_GRND(2, 2.5, 2.5, 8.9, 7.8, 2, 0.7, 3, 2.4, 1.4, 2, 0.8, 0.6, 12.3)
#end
#macro CON_WAGO_733_333()
CON_WAGO73X_PINHEADER_GRND(3, 2.5, 2.5, 8.9, 7.8, 2, 0.7, 3, 2.4, 1.4, 2, 0.8, 0.6, 12.3)
#end
#macro CON_WAGO_733_334()
CON_WAGO73X_PINHEADER_GRND(4, 2.5, 2.5, 8.9, 7.8, 2, 0.7, 3, 2.4, 1.4, 2, 0.8, 0.6, 12.3)
#end
#macro CON_WAGO_733_335()
CON_WAGO73X_PINHEADER_GRND(5, 2.5, 2.5, 8.9, 7.8, 2, 0.7, 3, 2.4, 1.4, 2, 0.8, 0.6, 12.3)
#end
#macro CON_WAGO_733_336()
CON_WAGO73X_PINHEADER_GRND(6, 2.5, 2.5, 8.9, 7.8, 2, 0.7, 3, 2.4, 1.4, 2, 0.8, 0.6, 12.3)
#end
#macro CON_WAGO_733_337()
CON_WAGO73X_PINHEADER_GRND(7, 2.5, 2.5, 8.9, 7.8, 2, 0.7, 3, 2.4, 1.4, 2, 0.8, 0.6, 12.3)
#end
#macro CON_WAGO_733_338()
CON_WAGO73X_PINHEADER_GRND(8, 2.5, 2.5, 8.9, 7.8, 2, 0.7, 3, 2.4, 1.4, 2, 0.8, 0.6, 12.3)
#end
#macro CON_WAGO_733_340()
CON_WAGO73X_PINHEADER_GRND(10, 2.5, 2.5, 8.9, 7.8, 2, 0.7, 3, 2.4, 1.4, 2, 0.8, 0.6, 12.3)
#end
#macro CON_WAGO_733_342()
CON_WAGO73X_PINHEADER_GRND(12, 2.5, 2.5, 8.9, 7.8, 2, 0.7, 3, 2.4, 1.4, 2, 0.8, 0.6, 12.3)
#end
#macro CON_WAGO_734_132()
CON_WAGO73X_PINHEADER_GRND(2, 3.5, 2.4, 10.3, 8.5, 2.5, 1.0, 4, 2.6, 2.0, 2.6, 1, 0.8, 13.6)
#end
#macro CON_WAGO_734_133()
CON_WAGO73X_PINHEADER_GRND(3, 3.5, 2.4, 10.3, 8.5, 2.5, 1.0, 4, 2.6, 2.0, 2.6, 1, 0.8, 13.6)
#end
#macro CON_WAGO_734_134()
CON_WAGO73X_PINHEADER_GRND(4, 3.5, 2.4, 10.3, 8.5, 2.5, 1.0, 4, 2.6, 2.0, 2.6, 1, 0.8, 13.6)
#end
#macro CON_WAGO_734_135()
CON_WAGO73X_PINHEADER_GRND(5, 3.5, 2.4, 10.3, 8.5, 2.5, 1.0, 4, 2.6, 2.0, 2.6, 1, 0.8, 13.6)
#end
#macro CON_WAGO_734_136()
CON_WAGO73X_PINHEADER_GRND(6, 3.5, 2.4, 10.3, 8.5, 2.5, 1.0, 4, 2.6, 2.0, 2.6, 1, 0.8, 13.6)
#end
#macro CON_WAGO_734_137()
CON_WAGO73X_PINHEADER_GRND(7, 3.5, 2.4, 10.3, 8.5, 2.5, 1.0, 4, 2.6, 2.0, 2.6, 1, 0.8, 13.6)
#end
#macro CON_WAGO_734_138()
CON_WAGO73X_PINHEADER_GRND(8, 3.5, 2.4, 10.3, 8.5, 2.5, 1.0, 4, 2.6, 2.0, 2.6, 1, 0.8, 13.6)
#end
#macro CON_WAGO_734_139()
CON_WAGO73X_PINHEADER_GRND(9, 3.5, 2.4, 10.3, 8.5, 2.5, 1.0, 4, 2.6, 2.0, 2.6, 1, 0.8, 13.6)
#end
#macro CON_WAGO_734_140()
CON_WAGO73X_PINHEADER_GRND(10, 3.5, 2.4, 10.3, 8.5, 2.5, 1.0, 4, 2.6, 2.0, 2.6, 1, 0.8, 13.6)
#end
#macro CON_WAGO_734_142()
CON_WAGO73X_PINHEADER_GRND(12, 3.5, 2.4, 10.3, 8.5, 2.5, 1.0, 4, 2.6, 2.0, 2.6, 1, 0.8, 13.6)
#end
#macro CON_WAGO_734_143()
CON_WAGO73X_PINHEADER_GRND(13, 3.5, 2.4, 10.3, 8.5, 2.5, 1.0, 4, 2.6, 2.0, 2.6, 1, 0.8, 13.6)
#end
#macro CON_WAGO_734_146()
CON_WAGO73X_PINHEADER_GRND(16, 3.5, 2.4, 10.3, 8.5, 2.5, 1.0, 4, 2.6, 2.0, 2.6, 1, 0.8, 13.6)
#end
#macro CON_WAGO_734_148()
CON_WAGO73X_PINHEADER_GRND(18, 3.5, 2.4, 10.3, 8.5, 2.5, 1.0, 4, 2.6, 2.0, 2.6, 1, 0.8, 13.6)
#end
#macro CON_WAGO_734_150()
CON_WAGO73X_PINHEADER_GRND(20, 3.5, 2.4, 10.3, 8.5, 2.5, 1.0, 4, 2.6, 2.0, 2.6, 1, 0.8, 13.6)
#end
#macro CON_WAGO_734_154()
CON_WAGO73X_PINHEADER_GRND(24, 3.5, 2.4, 10.3, 8.5, 2.5, 1.0, 4, 2.6, 2.0, 2.6, 1, 0.8, 13.6)
#end


/********************************************************************************************************************************************
//Macro fuer WAGO Leiterplattenklemme Serie 233, con-wago.lib,    Joerg Bredendiek <sprut(replace with at)sprut.de>
//
//  WAGO 233-1xx        Rastermass 2.50 mm, grau
//  WAGO 233-2xx        Rastermass 2.50 mm, grau    Klemmhebel
//  WAGO 233-4xx        Rastermass 2.54 mm, orange
//  WAGO 233-5xx        Rastermass 2.54 mm, orange  Klemmhebel
//
// Nullpunkt:
//      mittig zwischen den Pins
//
// a = Anzahl der Reihen
********************************************************************************************************************************************/
#macro CON_WAGO_233_GRND(a,typ)
#local wagocolor1 = color red 0.6 green 0.6 blue 0.6;	        //farbton fuer Plastikkoerper 2.5 mm grau
#local wagocolor2 = color red 1 green 0.45 blue 0;	        //farbton fuer Plastikkoerper 2.54 mm orange
#local handcolor = color red 0.9 green 0.9 blue 0.9;         	//farbton weissen Plastikhebel


//ein weisser Klemmhebel
#macro CLAMP_WAGO_233_HAND()
        union{

                box{<-0.5, 0, 0><0.5, 10, 2> pigment{handcolor}}
                difference{
                        box{<-1  ,10, 0><1,   13.5,  4> pigment{handcolor}}
                        box{<-1.1, -5, -3><1.1, 0, +3> rotate<-45,0,0> translate<0,15,-2> pigment{handcolor}}
                        cylinder{<-0.5  ,13, 1><0.5  ,13, 1> 2 pigment{handcolor}}
                }
        }
#end



//eine einzelne Klemme
#macro CLAMP_WAGO_233_SLICE(typ, raster)
        union{
                difference{
                        object{
                                prism {
                                        linear_spline
                                        0, raster-0.05, 7,
                                        <0, 0>, <-2.5, 0>, <-5, 4>, <0, 12>, <7.5, 8>, <7.5 0>, <0, 0>
                                }
                                pigment{wagocolor}
                                rotate<0,-90,0>
                                rotate<0,0,-90>
                                translate<-2.54, 0, 0>
                        }
                        box{<-1.28, 0, 0.7><1.28, 1, 5.08-0.7>            pigment{wagocolor}}            // Kerbe an Unterseite
                        box{< -0.5, 0, -6><-2, 0.5, 10>                   pigment{wagocolor}}            // Kerbe an Unterseite
                        box{< -0.5, 1.5, -8><-2, 4.5, -3> rotate<30,0,0>  pigment{wagocolor}}            // Kerbe an Kontakt
                        #if (typ=1)
                                box{< -0.5, 6.5, -8><-2, 9.5, -3> rotate<30,0,0>  pigment{wagocolor}}    // obere Kerbe an Kontakt
                        #end
                        #if (typ=4)
                                box{< -0.5, 6.5, -8><-2, 9.5, -3> rotate<30,0,0>  pigment{wagocolor}}    // obere Kerbe an Kontakt
                        #end
                }
                #if (typ=5)
                        object{CLAMP_WAGO_233_HAND() translate<-1.27, 3, 2>}
                #end
                #if (typ=2)
                        object{CLAMP_WAGO_233_HAND() translate<-1.27, 3, 2>}
                #end
                //Pins
                box { <-1.27-0.35, -3, -0.25>     ,<-1.27+0.35, 2.4, 0.25     > texture{col_silver}} // Kontakt
                box { <-1.27-0.35, -3,  5.08-0.25>,<-1.27+0.35, 2.4, 5.05+0.25> texture{col_silver}} // Kontakt
     }
#end


// Endscheibe 1.27 mm dick
#macro CLAMP_WAGO_233_END(typ)
        prism {
                linear_spline
                0, 1.2, 7,
                <0, 0>, <-2.5, 0>, <-5, 4>, <0, 12>, <7.5, 8>, <7.5 0>, <0, 0>
        }
        pigment{wagocolor}
        rotate<0,-90,0>
        rotate<0,0,-90>
        translate<-2.54, 0, 0>
#end


//makro fuer WAGO-Klemmen Typ 233
#local wagocolor=wagocolor1; //grau
#local raster = 2.5;
#if (typ>2)
        #local wagocolor=wagocolor2;
        #local raster = 2.54;
#end

object{
        difference{
                union{
		        #local i=0;
		        #while(i<a)
			        object{CLAMP_WAGO_233_SLICE(typ, raster) translate< -i*raster, 0, 0>}
                                #local i=i+1;
		        #end
		        object{CLAMP_WAGO_233_END(typ) translate< -i*raster, 0, 0> translate< raster/2, 0, 0>}

	        }
	        cylinder{<-1.28,2,-2>   <1.28, 2  , -2 >0.5 pigment{wagocolor}}
	        cylinder{<-1.28,2, 6.5> <1.28, 2  , 6.5>0.3 pigment{wagocolor}}
	        cylinder{<-1.28,7.5,-2> <1.28, 7.5, -2 >0.4 pigment{wagocolor}}
	        cylinder{<-1.28,7.5,6.5><1.28, 7.5, 6.5>0.5 pigment{wagocolor}}
	        cylinder{<-1.28,11,0.2> <1.28, 11 , 0.2>0.3 pigment{wagocolor}}
	} translate< a/2*raster, 0, -raster>
}
#end

#macro CON_WAGO_233_102()
CON_WAGO_233_GRND(2,1)
#end
#macro CON_WAGO_233_103()
CON_WAGO_233_GRND(3,1)
#end
#macro CON_WAGO_233_104()
CON_WAGO_233_GRND(4,1)
#end
#macro CON_WAGO_233_105()
CON_WAGO_233_GRND(5,1)
#end
#macro CON_WAGO_233_106()
CON_WAGO_233_GRND(6,1)
#end
#macro CON_WAGO_233_107()
CON_WAGO_233_GRND(7,1)
#end
#macro CON_WAGO_233_108()
CON_WAGO_233_GRND(8,1)
#end
#macro CON_WAGO_233_109()
CON_WAGO_233_GRND(9,1)
#end
#macro CON_WAGO_233_110()
CON_WAGO_233_GRND(10,1)
#end
#macro CON_WAGO_233_112()
CON_WAGO_233_GRND(12,1)
#end
#macro CON_WAGO_233_116()
CON_WAGO_233_GRND(16,1)
#end
#macro CON_WAGO_233_124()
CON_WAGO_233_GRND(24,1)
#end
#macro CON_WAGO_233_136()
CON_WAGO_233_GRND(36,1)
#end
#macro CON_WAGO_233_148()
CON_WAGO_233_GRND(48,1)
#end
#macro CON_WAGO_233_202()
CON_WAGO_233_GRND(2,2)
#end
#macro CON_WAGO_233_203()
CON_WAGO_233_GRND(3,2)
#end
#macro CON_WAGO_233_204()
CON_WAGO_233_GRND(4,2)
#end
#macro CON_WAGO_233_205()
CON_WAGO_233_GRND(5,2)
#end
#macro CON_WAGO_233_206()
CON_WAGO_233_GRND(6,2)
#end
#macro CON_WAGO_233_207()
CON_WAGO_233_GRND(7,2)
#end
#macro CON_WAGO_233_208()
CON_WAGO_233_GRND(8,2)
#end
#macro CON_WAGO_233_209()
CON_WAGO_233_GRND(9,2)
#end
#macro CON_WAGO_233_210()
CON_WAGO_233_GRND(10,2)
#end
#macro CON_WAGO_233_212()
CON_WAGO_233_GRND(12,2)
#end
#macro CON_WAGO_233_216()
CON_WAGO_233_GRND(16,2)
#end
#macro CON_WAGO_233_224()
CON_WAGO_233_GRND(24,2)
#end
#macro CON_WAGO_233_236()
CON_WAGO_233_GRND(36,2)
#end
#macro CON_WAGO_233_248()
CON_WAGO_233_GRND(48,2)
#end
#macro CON_WAGO_233_402()
CON_WAGO_233_GRND(2,4)
#end
#macro CON_WAGO_233_403()
CON_WAGO_233_GRND(3,4)
#end
#macro CON_WAGO_233_404()
CON_WAGO_233_GRND(4,4)
#end
#macro CON_WAGO_233_405()
CON_WAGO_233_GRND(5,4)
#end
#macro CON_WAGO_233_406()
CON_WAGO_233_GRND(6,4)
#end
#macro CON_WAGO_233_407()
CON_WAGO_233_GRND(7,4)
#end
#macro CON_WAGO_233_408()
CON_WAGO_233_GRND(8,4)
#end
#macro CON_WAGO_233_409()
CON_WAGO_233_GRND(9,4)
#end
#macro CON_WAGO_233_410()
CON_WAGO_233_GRND(10,4)
#end
#macro CON_WAGO_233_412()
CON_WAGO_233_GRND(12,4)
#end
#macro CON_WAGO_233_416()
CON_WAGO_233_GRND(16,4)
#end
#macro CON_WAGO_233_424()
CON_WAGO_233_GRND(24,4)
#end
#macro CON_WAGO_233_436()
CON_WAGO_233_GRND(36,4)
#end
#macro CON_WAGO_233_448()
CON_WAGO_233_GRND(48,4)
#end
#macro CON_WAGO_233_502()
CON_WAGO_233_GRND(2,5)
#end
#macro CON_WAGO_233_503()
CON_WAGO_233_GRND(3,5)
#end
#macro CON_WAGO_233_504()
CON_WAGO_233_GRND(4,5)
#end
#macro CON_WAGO_233_505()
CON_WAGO_233_GRND(5,5)
#end
#macro CON_WAGO_233_506()
CON_WAGO_233_GRND(6,5)
#end
#macro CON_WAGO_233_507()
CON_WAGO_233_GRND(7,5)
#end
#macro CON_WAGO_233_508()
CON_WAGO_233_GRND(8,5)
#end
#macro CON_WAGO_233_509()
CON_WAGO_233_GRND(9,5)
#end
#macro CON_WAGO_233_510()
CON_WAGO_233_GRND(10,5)
#end
#macro CON_WAGO_233_512()
CON_WAGO_233_GRND(12,5)
#end
#macro CON_WAGO_233_516()
CON_WAGO_233_GRND(16,5)
#end
#macro CON_WAGO_233_524()
CON_WAGO_233_GRND(24,5)
#end
#macro CON_WAGO_233_536()
CON_WAGO_233_GRND(36,5)
#end
#macro CON_WAGO_233_548()
CON_WAGO_233_GRND(48,5)
#end


/********************************************************************************************************************************************
// Tilmann Reh <tilmann.reh@autometer.de>
// gerade Pfostenwannen
// Bezugspunkt: geometrische Mitte der Pins auf PCB-Oberfläche
********************************************************************************************************************************************/
#macro CON_WS_XX_G_GRND(Pins)
union{
object{PFOSTENWANNE(7.62+Pins*1.27)}
object{PIN_STRAIGHT_ROW (Pins/2,2.54,0.635,8.5,3,col_gold) translate<0,0,-1.27>}
object{PIN_STRAIGHT_ROW (Pins/2,2.54,0.635,8.5,3,col_gold) translate<0,0,1.27>}}
#end
#macro CON_DIS_WS6G()
CON_WS_XX_G_GRND(6)
#end
#macro CON_DIS_WS10G()
CON_WS_XX_G_GRND(10)
#end
#macro CON_DIS_WS14G()
CON_WS_XX_G_GRND(14)
#end
#macro CON_DIS_WS16G()
CON_WS_XX_G_GRND(16)
#end
#macro CON_DIS_WS20G()
CON_WS_XX_G_GRND(20)
#end
#macro CON_DIS_WS26G()
CON_WS_XX_G_GRND(26)
#end
#macro CON_DIS_WS34G()
CON_WS_XX_G_GRND(34)
#end
#macro CON_DIS_WS40G()
CON_WS_XX_G_GRND(40)
#end
#macro CON_DIS_WS50G()
CON_WS_XX_G_GRND(50)
#end
#macro CON_DIS_WS64G()
CON_WS_XX_G_GRND(64)
#end


/********************************************************************************************************************************************
// Tilmann Reh <tilmann.reh@autometer.de>
// abgewinkelte Pfostenwannen
// Bezugspunkt: mittig, 5.08mm vor der unteren/inneren Pinreihe.
********************************************************************************************************************************************/
#macro CON_WS_XX_W_GRND(Pins)
union{
object{PFOSTENWANNE(7.62+Pins*1.27) rotate<-90,0,0> translate<0,4.5,3.3>}
object{PIN_BENDED_ROW (Pins/2,2.54,0.635,0.8,4.5-1.27,3,10.5,col_gold) translate<0,0,5.08>}
object{PIN_BENDED_ROW (Pins/2,2.54,0.635,0.8,4.5+1.27,3,13.04,col_gold) translate<0,0,7.62>}}
#end
#macro CON_DIS_WS10W()
CON_WS_XX_W_GRND(10)
#end
#macro CON_DIS_WS14W()
CON_WS_XX_W_GRND(14)
#end
#macro CON_DIS_WS16W()
CON_WS_XX_W_GRND(16)
#end
#macro CON_DIS_WS20W()
CON_WS_XX_W_GRND(20)
#end
#macro CON_DIS_WS26W()
CON_WS_XX_W_GRND(26)
#end
#macro CON_DIS_WS34W()
CON_WS_XX_W_GRND(34)
#end
#macro CON_DIS_WS40W()
CON_WS_XX_W_GRND(40)
#end
#macro CON_DIS_WS50W()
CON_WS_XX_W_GRND(50)
#end
#macro CON_DIS_WS64W()
CON_WS_XX_W_GRND(64)
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
