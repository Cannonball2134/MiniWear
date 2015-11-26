/*
 * Copyright 2010 Matthias Weisser <matthias@matwei.de>
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

/*
 * This is the global texture definition file. All texture definitions
 * for parts have to be taken from here or have to be defined here.
 */

#ifndef(__e3d_tex_inc)
#declare __e3d_tex_inc = true;

//------------------------------------------------------------------------------
//Texture settings

//Gold
#declare e3d_tex_gold = //texture{e3d_tex_gold}
    texture{
        T_Gold_5E 
        finish{
            F_MetalA 
            ambient(0.35 * global_ambient_mul)
        }
    };

//Silver
#declare e3d_tex_silver = //texture{e3d_tex_silver}
    texture{
        T_Silver_5A
        finish{
            F_MetalA 
            ambient(0.35 * global_ambient_mul)
        }
    };

//Plastic body of an IC
#declare e3d_tex_ic_body_1 = //texture{e3d_tex_ic_body_1}
    texture{
        pigment{Gray30}
        finish{ambient(0.1 * global_ambient_mul)}
    }

//Plastic body of an IC
#declare e3d_tex_ic_body_2 = //texture{e3d_tex_ic_body_2}
    texture{
        pigment{Gray30}
        finish{phong 0.1 phong_size 25  ambient (0.1 * global_ambient_mul)}
    }
    
//Bright IC marking
#declare e3d_tex_ic_marking_bright = //texture{e3d_tex_ic_marking_bright}
    texture{
        pigment{Gray60}
        finish{ambient(0.1 * global_ambient_mul)}
    }

//Black IC marking
#declare e3d_tex_ic_marking_black = //texture{e3d_tex_ic_marking_black}
    texture{
        pigment{Black}
        finish{ambient(0.1 * global_ambient_mul)}
    }
    
//Black cap marking
#declare e3d_tex_cap_marking_black = //texture{e3d_tex_cap_marking_black}
    texture{e3d_tex_ic_marking_black}
    
//Blue color for block cap
#declare e3d_tex_cap_block_blue = //texture{e3d_tex_cap_block_blue}
    texture{
        pigment {rgb<0.3,0.3,1>}
        finish{ambient(0.1 * global_ambient_mul)}
    }
    
//Red color for wima cap
#declare e3d_tex_cap_wima = //texture{e3d_tex_cap_wima}
    texture{
        pigment {Red}
        finish{ambient(0.1 * global_ambient_mul)}
    }
    
//Dark gray for SMD aluminium electrolytic cap base
#declare e3d_tex_cap_smd_electrolytic_base = //texture{e3d_tex_cap_smd_electrolytic_base}
    texture{
        pigment {Gray30}
        finish{ambient(0.1 * global_ambient_mul)}
    }
    
//The shade of brown you see on 100nF SMD ceramic caps
#declare e3d_tex_cap_smd_ceramic_1 = //texture{e3d_tex_cap_smd_ceramic_1}
    texture{
        pigment{DarkWood}
        finish{ambient(0.1 * global_ambient_mul)}
    }

//A silver heatsink as found on packages like TO220
#declare e3d_tex_heatsink_silver = //texture{e3d_tex_heatsink_silver}
    texture{
        T_Silver_5A 
        finish{phong 0.1 phong_size 10  ambient (0.1 * global_ambient_mul)}
    }


//------------------------------------------------------------------------------
//Shrouded Header
// hellgrauer Kunststoff
#declare col_Wannen = 
    texture{
        pigment{Gray70}
        finish{ambient (0.1 * global_ambient_mul)}
    };  

//----------------------------------------------------------------------
//Molex Stiftleisten
// hellbeiger Kunststoff Molex-Stiftleisten
#declare col_Molex =    
    texture {
        pigment{Wheat}
        finish{ambient (0.1 * global_ambient_mul)}
    };
//----------------------------------------------------------------------
//Keramik-Scheibenkondensatoren
// braune Keramik-Scheibenkondensatoren
#declare col_Kerko = 
    texture{
        pigment{MediumWood}
        finish{ambient (0.1 * global_ambient_mul)}
    }
//******************************************************************************************************

//------------------------------------------------------------------------------
//for backward compatibility (Will try to get rid of them)
#declare col_gold   = texture{e3d_tex_gold};
#declare col_silver = texture{e3d_tex_silver};


#end //__e3d_tex_inc


