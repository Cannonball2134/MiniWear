
// perspective (default, not required) camera
camera {
  perspective
  location  <0, 0, -1>
  look_at   <0, 0,  0>
  right     x*image_width/image_height  // aspect
  // direction z                        // direction and zoom
  // angle 67                           // field (overides direction zoom)
}

// An area light (creates soft shadows)
// WARNING: This special light can significantly slow down rendering times!
light_source {
  <0,0,0>             // light's position (translated below)
  color rgb 1.0       // light's color
  area_light
  <8, 0, 0> <0, 0, 8> // lights spread out across this distance (x * z)
  4, 4                // total number of lights in grid (4x*4z = 16 lights)
  adaptive 0          // 0,1,2,3...
  jitter              // adds random softening of light
  circular            // make the shape of the light circular
  orient              // orient light
  translate <40, 80, -40>   // <x y z> position of light
}



//---------------------------------------------------------------------------- 
#include "shapes3.inc"
//----------------------------------------------------------------------------
global_settings { max_trace_level 30 } // for transparent materials
//----------------------------------------------------------------------------
object{ Round_N_Tube_Polygon ( // A round polygon tube ring with N corners 
                            4, // number of corners must be >= 3 !!!
                            0.125+0.05,// tube radius < base width
                            0.775,     // base width (center to edge middle)
                            0.25,      // corner torus segment major radius
                            1, // 1 = filled, 0 = ring
                            1 // 0 uses union; 1 uses merge for transparent
                          ) //-------------------------------------------------
      material{   //-----------------------------------------------------------
        texture { pigment{ rgbf <0.98, 0.98, 0.98, 0.9> }
                  finish { diffuse 0.1 reflection 0.2
                          specular 0.8 roughness 0.0003 phong 1 phong_size 400}
                } // end of texture -------------------------------------------
        interior{ ior 1.35 caustics 0.5
                } // end of interior ------------------------------------------
      } // end of material ----------------------------------------------------

  /*
      texture{ pigment{ color rgbf<1,1,1,0.9>}
               finish { phong 1}
             } // end of texture
  */
   // rotate<90,0,0>
      translate< 0,0,0>
} // end of object -----------------------------------------------------------
//----------------------------------------------------------------------------
