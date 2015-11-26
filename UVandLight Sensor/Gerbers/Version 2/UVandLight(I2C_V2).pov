//POVRay-File created by 3d41.ulp v20110101
//C:/Users/JC/Dropbox/MiniWear/Eagle/EZ-I2C/UVandLight Sensor/UVandLight(I2C_V2).brd
//10/11/2014 00:34:25

#version 3.5;

//Set to on if the file should be used as .inc
#local use_file_as_inc = off;
#if(use_file_as_inc=off)


//changes the apperance of resistors (1 Blob / 0 real)
#declare global_res_shape = 1;
//randomize color of resistors 1=random 0=same color
#declare global_res_colselect = 0;
//Number of the color for the resistors
//0=Green, 1="normal color" 2=Blue 3=Brown
#declare global_res_col = 1;
//Set to on if you want to render the PCB upside-down
#declare pcb_upsidedown = off;
//Set to x or z to rotate around the corresponding axis (referring to pcb_upsidedown)
#declare pcb_rotdir = x;
//Set the length off short pins over the PCB
#declare pin_length = 2.5;
#declare global_diode_bend_radius = 1;
#declare global_res_bend_radius = 1;
#declare global_solder = on;

#declare global_show_screws = on;
#declare global_show_washers = on;
#declare global_show_nuts = on;

#declare global_use_radiosity = on;

#declare global_ambient_mul = 1;
#declare global_ambient_mul_emit = 0;

//Animation
#declare global_anim = off;
#local global_anim_showcampath = no;

#declare global_fast_mode = off;

#declare col_preset = 2;
#declare pin_short = on;

#declare e3d_environment = off;

#local cam_x = 0;
#local cam_y = 65;
#local cam_z = -35;
#local cam_a = 20;
#local cam_look_x = 0;
#local cam_look_y = -1;
#local cam_look_z = 0;

#local pcb_rotate_x = 0;
#local pcb_rotate_y = 0;
#local pcb_rotate_z = 0;

#local pcb_board = on;
#local pcb_parts = on;
#local pcb_wire_bridges = off;
#if(global_fast_mode=off)
	#local pcb_polygons = on;
	#local pcb_silkscreen = on;
	#local pcb_wires = on;
	#local pcb_pads_smds = on;
#else
	#local pcb_polygons = off;
	#local pcb_silkscreen = off;
	#local pcb_wires = off;
	#local pcb_pads_smds = off;
#end

#local lgt1_pos_x = 7;
#local lgt1_pos_y = 11;
#local lgt1_pos_z = 8;
#local lgt1_intense = 0.704320;
#local lgt2_pos_x = -7;
#local lgt2_pos_y = 11;
#local lgt2_pos_z = 8;
#local lgt2_intense = 0.704320;
#local lgt3_pos_x = 7;
#local lgt3_pos_y = 11;
#local lgt3_pos_z = -5;
#local lgt3_intense = 0.704320;
#local lgt4_pos_x = -7;
#local lgt4_pos_y = 11;
#local lgt4_pos_z = -5;
#local lgt4_intense = 0.704320;

//Do not change these values
#declare pcb_height = 1.500000;
#declare pcb_cuheight = 0.035000;
#declare pcb_x_size = 19.855000;
#declare pcb_y_size = 15.230000;
#declare pcb_layer1_used = 1;
#declare pcb_layer16_used = 1;
#declare inc_testmode = off;
#declare global_seed=seed(983);
#declare global_pcb_layer_dis = array[16]
{
	0.000000,
	0.000000,
	0.000000,
	0.000000,
	0.000000,
	0.000000,
	0.000000,
	0.000000,
	0.000000,
	0.000000,
	0.000000,
	0.000000,
	0.000000,
	0.000000,
	0.000000,
	1.535000,
}
#declare global_pcb_real_hole = 2.000000;

#include "e3d_tools.inc"
#include "e3d_user.inc"

global_settings{charset utf8}

#if(e3d_environment=on)
sky_sphere {pigment {Navy}
pigment {bozo turbulence 0.65 octaves 7 omega 0.7 lambda 2
color_map {
[0.0 0.1 color rgb <0.85, 0.85, 0.85> color rgb <0.75, 0.75, 0.75>]
[0.1 0.5 color rgb <0.75, 0.75, 0.75> color rgbt <1, 1, 1, 1>]
[0.5 1.0 color rgbt <1, 1, 1, 1> color rgbt <1, 1, 1, 1>]}
scale <0.1, 0.5, 0.1>} rotate -90*x}
plane{y, -10.0-max(pcb_x_size,pcb_y_size)*abs(max(sin((pcb_rotate_x/180)*pi),sin((pcb_rotate_z/180)*pi)))
texture{T_Chrome_2D
normal{waves 0.1 frequency 3000.0 scale 3000.0}} translate<0,0,0>}
#end

//Animation data
#if(global_anim=on)
#declare global_anim_showcampath = no;
#end

#if((global_anim=on)|(global_anim_showcampath=yes))
#declare global_anim_npoints_cam_flight=0;
#warning "No/not enough Animation Data available (min. 3 points) (Flight path)"
#end

#if((global_anim=on)|(global_anim_showcampath=yes))
#declare global_anim_npoints_cam_view=0;
#warning "No/not enough Animation Data available (min. 3 points) (View path)"
#end

#if((global_anim=on)|(global_anim_showcampath=yes))
#end

#if((global_anim_showcampath=yes)&(global_anim=off))
#end
#if(global_anim=on)
camera
{
	location global_anim_spline_cam_flight(clock)
	#if(global_anim_npoints_cam_view>2)
		look_at global_anim_spline_cam_view(clock)
	#else
		look_at global_anim_spline_cam_flight(clock+0.01)-<0,-0.01,0>
	#end
	angle 45
}
light_source
{
	global_anim_spline_cam_flight(clock)
	color rgb <1,1,1>
	spotlight point_at 
	#if(global_anim_npoints_cam_view>2)
		global_anim_spline_cam_view(clock)
	#else
		global_anim_spline_cam_flight(clock+0.01)-<0,-0.01,0>
	#end
	radius 35 falloff  40
}
#else
camera
{
	location <cam_x,cam_y,cam_z>
	look_at <cam_look_x,cam_look_y,cam_look_z>
	angle cam_a
	//translates the camera that <0,0,0> is over the Eagle <0,0>
	//translate<-9.927500,0,-7.615000>
}
#end

background{col_bgr}
light_source{<lgt1_pos_x,lgt1_pos_y,lgt1_pos_z> White*lgt1_intense}
light_source{<lgt2_pos_x,lgt2_pos_y,lgt2_pos_z> White*lgt2_intense}
light_source{<lgt3_pos_x,lgt3_pos_y,lgt3_pos_z> White*lgt3_intense}
light_source{<lgt4_pos_x,lgt4_pos_y,lgt4_pos_z> White*lgt4_intense}
#end


#macro UVANDLIGHT_I2C_V2_(mac_x_ver,mac_y_ver,mac_z_ver,mac_x_rot,mac_y_rot,mac_z_rot)
union{
#if(pcb_board = on)
difference{
union{
//Board
prism{-1.500000,0.000000,8
<0.210000,6.610000><20.055000,6.610000>
<20.055000,6.610000><20.065000,21.840000>
<20.065000,21.840000><0.210000,21.820000>
<0.210000,21.820000><0.210000,6.610000>
texture{col_brd}}
}//End union(PCB)
//Holes(real)/Parts
//Holes(real)/Board
//Holes(real)/Vias
}//End difference(reale Bohrungen/Durchbrüche)
#end
#if(pcb_parts=on)//Parts
union{
#ifndef(pack_C1) #declare global_pack_C1=yes; object {CAP_SMD_CHIP_0402()translate<0,0,0> rotate<0,0.000000,0>rotate<0,0.000000,0> rotate<0,0,0> translate<10.190000,0.000000,7.520000>translate<0,0.035000,0> }#end		//SMD Capacitor 0402 C1 0.1uf 0402-CAP
#ifndef(pack_R1) #declare global_pack_R1=yes; object {RES_SMD_CHIP_0402("103",)translate<0,0,0> rotate<0,0.000000,0>rotate<0,0.000000,0> rotate<0,0,0> translate<10.060000,0.000000,18.190000>translate<0,0.035000,0> }#end		//SMD Resistor 0402 R1 10K 0402
#ifndef(pack_R2) #declare global_pack_R2=yes; object {RES_SMD_CHIP_0402("103",)translate<0,0,0> rotate<0,0.000000,0>rotate<0,0.000000,0> rotate<0,0,0> translate<10.210000,0.000000,9.390000>translate<0,0.035000,0> }#end		//SMD Resistor 0402 R2 10K 0402
#ifndef(pack_R3) #declare global_pack_R3=yes; object {RES_SMD_CHIP_0402("103",)translate<0,0,0> rotate<0,0.000000,0>rotate<0,0.000000,0> rotate<0,0,0> translate<10.250000,0.000000,11.140000>translate<0,0.035000,0> }#end		//SMD Resistor 0402 R3 10K 0402
}//End union
#end
#if(pcb_pads_smds=on)
//Pads&SMD/Parts
object{TOOLS_PCB_SMD(0.700000,0.900000,0.037000,0) rotate<0,-0.000000,0> texture{col_pds} translate<9.540000,0.000000,7.520000>}
object{TOOLS_PCB_SMD(0.700000,0.900000,0.037000,0) rotate<0,-0.000000,0> texture{col_pds} translate<10.840000,0.000000,7.520000>}
object{TOOLS_PCB_SMD(0.700000,0.900000,0.037000,0) rotate<0,-0.000000,0> texture{col_pds} translate<9.410000,0.000000,18.190000>}
object{TOOLS_PCB_SMD(0.700000,0.900000,0.037000,0) rotate<0,-0.000000,0> texture{col_pds} translate<10.710000,0.000000,18.190000>}
object{TOOLS_PCB_SMD(0.700000,0.900000,0.037000,0) rotate<0,-0.000000,0> texture{col_pds} translate<9.560000,0.000000,9.390000>}
object{TOOLS_PCB_SMD(0.700000,0.900000,0.037000,0) rotate<0,-0.000000,0> texture{col_pds} translate<10.860000,0.000000,9.390000>}
object{TOOLS_PCB_SMD(0.700000,0.900000,0.037000,0) rotate<0,-0.000000,0> texture{col_pds} translate<9.600000,0.000000,11.140000>}
object{TOOLS_PCB_SMD(0.700000,0.900000,0.037000,0) rotate<0,-0.000000,0> texture{col_pds} translate<10.900000,0.000000,11.140000>}
#ifndef(global_pack_U_1) #local global_tmp=0; #else #local global_tmp=100; #end object{TOOLS_PCB_VIA(1.879600,1.016000,1,16,1+global_tmp,0) rotate<0,-180.000000,0>translate<1.240000,0,20.340000> texture{col_thl}}
#ifndef(global_pack_U_1) #local global_tmp=0; #else #local global_tmp=100; #end object{TOOLS_PCB_VIA(1.879600,1.016000,1,16,1+global_tmp,0) rotate<0,-180.000000,0>translate<19.020000,0,20.340000> texture{col_thl}}
#ifndef(global_pack_U_1) #local global_tmp=0; #else #local global_tmp=100; #end object{TOOLS_PCB_VIA(1.879600,1.016000,1,16,1+global_tmp,0) rotate<0,-180.000000,0>translate<1.240000,0,15.260000> texture{col_thl}}
#ifndef(global_pack_U_1) #local global_tmp=0; #else #local global_tmp=100; #end object{TOOLS_PCB_VIA(1.879600,1.016000,1,16,1+global_tmp,0) rotate<0,-180.000000,0>translate<19.020000,0,15.260000> texture{col_thl}}
#ifndef(global_pack_U_1) #local global_tmp=0; #else #local global_tmp=100; #end object{TOOLS_PCB_VIA(1.879600,1.016000,1,16,1+global_tmp,0) rotate<0,-180.000000,0>translate<1.240000,0,7.640000> texture{col_thl}}
#ifndef(global_pack_U_1) #local global_tmp=0; #else #local global_tmp=100; #end object{TOOLS_PCB_VIA(1.879600,1.016000,1,16,1+global_tmp,0) rotate<0,-180.000000,0>translate<19.020000,0,7.640000> texture{col_thl}}
#ifndef(global_pack_U_1) #local global_tmp=0; #else #local global_tmp=100; #end object{TOOLS_PCB_VIA(1.879600,1.016000,1,16,1+global_tmp,0) rotate<0,-180.000000,0>translate<1.240000,0,10.180000> texture{col_thl}}
#ifndef(global_pack_U_1) #local global_tmp=0; #else #local global_tmp=100; #end object{TOOLS_PCB_VIA(1.879600,1.016000,1,16,1+global_tmp,0) rotate<0,-180.000000,0>translate<19.020000,0,10.180000> texture{col_thl}}
#ifndef(global_pack_U_1) #local global_tmp=0; #else #local global_tmp=100; #end object{TOOLS_PCB_VIA(1.879600,1.016000,1,16,1+global_tmp,0) rotate<0,-180.000000,0>translate<1.240000,0,12.720000> texture{col_thl}}
#ifndef(global_pack_U_1) #local global_tmp=0; #else #local global_tmp=100; #end object{TOOLS_PCB_VIA(1.879600,1.016000,1,16,1+global_tmp,0) rotate<0,-180.000000,0>translate<19.020000,0,12.720000> texture{col_thl}}
#ifndef(global_pack_U_1) #local global_tmp=0; #else #local global_tmp=100; #end object{TOOLS_PCB_VIA(1.879600,1.016000,1,16,1+global_tmp,0) rotate<0,-180.000000,0>translate<1.240000,0,17.800000> texture{col_thl}}
#ifndef(global_pack_U_1) #local global_tmp=0; #else #local global_tmp=100; #end object{TOOLS_PCB_VIA(1.879600,1.016000,1,16,1+global_tmp,0) rotate<0,-180.000000,0>translate<19.020000,0,17.800000> texture{col_thl}}
object{TOOLS_PCB_SMD(0.800000,0.300000,0.037000,0) rotate<0,-0.000000,0> texture{col_pds} translate<9.160000,0.000000,14.960000>}
object{TOOLS_PCB_SMD(0.800000,0.300000,0.037000,0) rotate<0,-0.000000,0> texture{col_pds} translate<9.160000,0.000000,14.460000>}
object{TOOLS_PCB_SMD(0.800000,0.300000,0.037000,0) rotate<0,-0.000000,0> texture{col_pds} translate<9.160000,0.000000,13.960000>}
object{TOOLS_PCB_SMD(0.800000,0.300000,0.037000,0) rotate<0,-0.000000,0> texture{col_pds} translate<9.160000,0.000000,13.460000>}
object{TOOLS_PCB_SMD(0.800000,0.300000,0.037000,0) rotate<0,-270.000000,0> texture{col_pds} translate<10.110000,0.000000,13.260000>}
object{TOOLS_PCB_SMD(0.800000,0.300000,0.037000,0) rotate<0,-180.000000,0> texture{col_pds} translate<11.060000,0.000000,13.460000>}
object{TOOLS_PCB_SMD(0.800000,0.300000,0.037000,0) rotate<0,-180.000000,0> texture{col_pds} translate<11.060000,0.000000,13.960000>}
object{TOOLS_PCB_SMD(0.800000,0.300000,0.037000,0) rotate<0,-180.000000,0> texture{col_pds} translate<11.060000,0.000000,14.460000>}
object{TOOLS_PCB_SMD(0.800000,0.300000,0.037000,0) rotate<0,-180.000000,0> texture{col_pds} translate<11.060000,0.000000,14.960000>}
object{TOOLS_PCB_SMD(0.800000,0.300000,0.037000,0) rotate<0,-90.000000,0> texture{col_pds} translate<10.110000,0.000000,15.160000>}
//Pads/Vias
object{TOOLS_PCB_VIA(0.955600,0.600000,1,16,1,0) translate<4.170000,0,15.540000> texture{col_thl}}
object{TOOLS_PCB_VIA(0.955600,0.600000,1,16,1,0) translate<12.670000,0,15.690000> texture{col_thl}}
object{TOOLS_PCB_VIA(0.955600,0.600000,1,16,1,0) translate<15.490000,0,15.320000> texture{col_thl}}
object{TOOLS_PCB_VIA(0.955600,0.600000,1,16,1,0) translate<4.280000,0,19.690000> texture{col_thl}}
object{TOOLS_PCB_VIA(0.955600,0.600000,1,16,1,0) translate<13.750000,0,10.590000> texture{col_thl}}
object{TOOLS_PCB_VIA(0.955600,0.600000,1,16,1,0) translate<8.010000,0,10.570000> texture{col_thl}}
object{TOOLS_PCB_VIA(0.955600,0.600000,1,16,1,0) translate<12.620000,0,13.810000> texture{col_thl}}
object{TOOLS_PCB_VIA(0.955600,0.600000,1,16,1,0) translate<8.210000,0,12.730000> texture{col_thl}}
#end
#if(pcb_wires=on)
union{
//Signals
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<1.240000,0.000000,12.720000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<1.470000,0.000000,12.750000>}
box{<0,0,-0.127000><0.231948,0.035000,0.127000> rotate<0,-7.430918,0> translate<1.240000,0.000000,12.720000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<1.240000,-1.535000,10.180000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<3.000000,-1.535000,10.190000>}
box{<0,0,-0.127000><1.760028,0.035000,0.127000> rotate<0,-0.325519,0> translate<1.240000,-1.535000,10.180000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<3.000000,-1.535000,9.230000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<3.000000,-1.535000,10.190000>}
box{<0,0,-0.127000><0.960000,0.035000,0.127000> rotate<0,90.000000,0> translate<3.000000,-1.535000,10.190000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<1.240000,-1.535000,20.340000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<3.000000,-1.535000,20.350000>}
box{<0,0,-0.127000><1.760028,0.035000,0.127000> rotate<0,-0.325519,0> translate<1.240000,-1.535000,20.340000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<3.000000,-1.535000,20.350000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<3.000000,-1.535000,21.000000>}
box{<0,0,-0.127000><0.650000,0.035000,0.127000> rotate<0,90.000000,0> translate<3.000000,-1.535000,21.000000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<5.000000,-1.535000,12.730000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<5.000000,-1.535000,11.940000>}
box{<0,0,-0.127000><0.790000,0.035000,0.127000> rotate<0,-90.000000,0> translate<5.000000,-1.535000,11.940000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<1.240000,-1.535000,12.720000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<5.000000,-1.535000,12.730000>}
box{<0,0,-0.127000><3.760013,0.035000,0.127000> rotate<0,-0.152372,0> translate<1.240000,-1.535000,12.720000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<1.470000,0.000000,12.750000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<5.410000,0.000000,12.750000>}
box{<0,0,-0.127000><3.940000,0.035000,0.127000> rotate<0,0.000000,0> translate<1.470000,0.000000,12.750000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<5.410000,0.000000,12.750000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<5.440000,0.000000,15.680000>}
box{<0,0,-0.127000><2.930154,0.035000,0.127000> rotate<0,-89.407473,0> translate<5.410000,0.000000,12.750000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<6.780000,0.000000,14.490000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<6.800000,0.000000,9.380000>}
box{<0,0,-0.152400><5.110039,0.035000,0.152400> rotate<0,89.769827,0> translate<6.780000,0.000000,14.490000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<6.800000,0.000000,10.190000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<6.800000,0.000000,9.380000>}
box{<0,0,-0.127000><0.810000,0.035000,0.127000> rotate<0,-90.000000,0> translate<6.800000,0.000000,9.380000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<1.240000,0.000000,10.180000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<6.800000,0.000000,10.190000>}
box{<0,0,-0.127000><5.560009,0.035000,0.127000> rotate<0,-0.103043,0> translate<1.240000,0.000000,10.180000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<6.800000,0.000000,10.540000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<6.800000,0.000000,10.190000>}
box{<0,0,-0.127000><0.350000,0.035000,0.127000> rotate<0,-90.000000,0> translate<6.800000,0.000000,10.190000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<7.960000,0.000000,11.140000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<8.010000,0.000000,10.570000>}
box{<0,0,-0.127000><0.572189,0.035000,0.127000> rotate<0,84.981277,0> translate<7.960000,0.000000,11.140000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<6.780000,0.000000,14.490000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<8.090000,0.000000,14.470000>}
box{<0,0,-0.152400><1.310153,0.035000,0.152400> rotate<0,0.874619,0> translate<6.780000,0.000000,14.490000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<8.170000,0.000000,13.960000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<8.210000,0.000000,12.730000>}
box{<0,0,-0.152400><1.230650,0.035000,0.152400> rotate<0,88.131562,0> translate<8.170000,0.000000,13.960000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<8.170000,0.000000,13.960000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<9.160000,0.000000,13.960000>}
box{<0,0,-0.152400><0.990000,0.035000,0.152400> rotate<0,0.000000,0> translate<8.170000,0.000000,13.960000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<8.090000,0.000000,14.470000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<9.160000,0.000000,14.460000>}
box{<0,0,-0.152400><1.070047,0.035000,0.152400> rotate<0,0.535424,0> translate<8.090000,0.000000,14.470000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<5.440000,0.000000,15.680000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<9.210000,0.000000,15.680000>}
box{<0,0,-0.127000><3.770000,0.035000,0.127000> rotate<0,0.000000,0> translate<5.440000,0.000000,15.680000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<9.160000,0.000000,14.960000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<9.210000,0.000000,15.680000>}
box{<0,0,-0.152400><0.721734,0.035000,0.152400> rotate<0,-86.021827,0> translate<9.160000,0.000000,14.960000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<9.180000,0.000000,17.960000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<9.210000,0.000000,15.680000>}
box{<0,0,-0.152400><2.280197,0.035000,0.152400> rotate<0,89.240262,0> translate<9.180000,0.000000,17.960000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<9.180000,0.000000,17.960000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<9.410000,0.000000,18.190000>}
box{<0,0,-0.152400><0.325269,0.035000,0.152400> rotate<0,-44.997030,0> translate<9.180000,0.000000,17.960000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<9.530000,0.000000,8.330000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<9.540000,0.000000,7.520000>}
box{<0,0,-0.152400><0.810062,0.035000,0.152400> rotate<0,89.286788,0> translate<9.530000,0.000000,8.330000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<6.800000,0.000000,9.380000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<9.560000,0.000000,9.390000>}
box{<0,0,-0.152400><2.760018,0.035000,0.152400> rotate<0,-0.207579,0> translate<6.800000,0.000000,9.380000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<7.960000,0.000000,11.140000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<9.600000,0.000000,11.140000>}
box{<0,0,-0.127000><1.640000,0.035000,0.127000> rotate<0,0.000000,0> translate<7.960000,0.000000,11.140000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<9.160000,0.000000,13.460000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<9.600000,0.000000,13.480000>}
box{<0,0,-0.127000><0.440454,0.035000,0.127000> rotate<0,-2.602390,0> translate<9.160000,0.000000,13.460000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<9.600000,0.000000,11.140000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<9.600000,0.000000,13.480000>}
box{<0,0,-0.127000><2.340000,0.035000,0.127000> rotate<0,90.000000,0> translate<9.600000,0.000000,13.480000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<9.530000,0.000000,8.330000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<10.840000,0.000000,8.330000>}
box{<0,0,-0.152400><1.310000,0.035000,0.152400> rotate<0,0.000000,0> translate<9.530000,0.000000,8.330000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<10.840000,0.000000,8.330000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<10.870000,0.000000,9.880000>}
box{<0,0,-0.152400><1.550290,0.035000,0.152400> rotate<0,-88.885321,0> translate<10.840000,0.000000,8.330000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<10.860000,0.000000,9.390000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<10.870000,0.000000,9.880000>}
box{<0,0,-0.152400><0.490102,0.035000,0.152400> rotate<0,-88.824998,0> translate<10.860000,0.000000,9.390000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<10.890000,0.000000,11.250000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<10.900000,0.000000,11.140000>}
box{<0,0,-0.152400><0.110454,0.035000,0.152400> rotate<0,84.799974,0> translate<10.890000,0.000000,11.250000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<10.860000,0.000000,9.390000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<10.920000,0.000000,10.210000>}
box{<0,0,-0.152400><0.822192,0.035000,0.152400> rotate<0,-85.809420,0> translate<10.860000,0.000000,9.390000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<10.890000,0.000000,11.250000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<10.920000,0.000000,10.210000>}
box{<0,0,-0.152400><1.040433,0.035000,0.152400> rotate<0,88.341865,0> translate<10.890000,0.000000,11.250000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<10.710000,0.000000,18.190000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<10.930000,0.000000,18.340000>}
box{<0,0,-0.152400><0.266271,0.035000,0.152400> rotate<0,-34.284614,0> translate<10.710000,0.000000,18.190000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<10.890000,0.000000,11.250000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<11.060000,0.000000,13.460000>}
box{<0,0,-0.152400><2.216529,0.035000,0.152400> rotate<0,-85.595645,0> translate<10.890000,0.000000,11.250000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<11.060000,0.000000,12.970000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<11.060000,0.000000,13.460000>}
box{<0,0,-0.152400><0.490000,0.035000,0.152400> rotate<0,90.000000,0> translate<11.060000,0.000000,13.460000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<11.060000,0.000000,13.460000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<11.060000,0.000000,13.960000>}
box{<0,0,-0.152400><0.500000,0.035000,0.152400> rotate<0,90.000000,0> translate<11.060000,0.000000,13.960000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<11.060000,0.000000,14.960000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<11.110000,0.000000,16.700000>}
box{<0,0,-0.152400><1.740718,0.035000,0.152400> rotate<0,-88.348191,0> translate<11.060000,0.000000,14.960000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<11.110000,0.000000,18.380000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<11.110000,0.000000,16.700000>}
box{<0,0,-0.152400><1.680000,0.035000,0.152400> rotate<0,-90.000000,0> translate<11.110000,0.000000,16.700000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<10.930000,0.000000,18.340000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<11.110000,0.000000,18.380000>}
box{<0,0,-0.152400><0.184391,0.035000,0.152400> rotate<0,-12.527981,0> translate<10.930000,0.000000,18.340000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<11.060000,0.000000,14.460000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<11.930000,0.000000,14.470000>}
box{<0,0,-0.152400><0.870057,0.035000,0.152400> rotate<0,-0.658500,0> translate<11.060000,0.000000,14.460000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<11.060000,0.000000,12.970000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<12.110000,0.000000,12.970000>}
box{<0,0,-0.152400><1.050000,0.035000,0.152400> rotate<0,0.000000,0> translate<11.060000,0.000000,12.970000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<11.060000,0.000000,13.960000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<12.590000,0.000000,13.960000>}
box{<0,0,-0.152400><1.530000,0.035000,0.152400> rotate<0,0.000000,0> translate<11.060000,0.000000,13.960000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<12.590000,0.000000,13.960000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<12.620000,0.000000,13.810000>}
box{<0,0,-0.152400><0.152971,0.035000,0.152400> rotate<0,78.684874,0> translate<12.590000,0.000000,13.960000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<8.210000,-1.535000,12.730000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<12.640000,-1.535000,12.730000>}
box{<0,0,-0.152400><4.430000,0.035000,0.152400> rotate<0,0.000000,0> translate<8.210000,-1.535000,12.730000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<12.620000,-1.535000,13.810000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<12.640000,-1.535000,12.730000>}
box{<0,0,-0.152400><1.080185,0.035000,0.152400> rotate<0,88.933219,0> translate<12.620000,-1.535000,13.810000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<11.930000,0.000000,14.470000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<12.670000,0.000000,15.690000>}
box{<0,0,-0.152400><1.426885,0.035000,0.152400> rotate<0,-58.756907,0> translate<11.930000,0.000000,14.470000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<8.010000,-1.535000,10.570000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<13.750000,-1.535000,10.590000>}
box{<0,0,-0.127000><5.740035,0.035000,0.127000> rotate<0,-0.199623,0> translate<8.010000,-1.535000,10.570000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<12.110000,0.000000,12.970000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<13.800000,0.000000,13.000000>}
box{<0,0,-0.152400><1.690266,0.035000,0.152400> rotate<0,-1.016911,0> translate<12.110000,0.000000,12.970000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<11.110000,0.000000,16.700000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<13.800000,0.000000,16.700000>}
box{<0,0,-0.152400><2.690000,0.035000,0.152400> rotate<0,0.000000,0> translate<11.110000,0.000000,16.700000> }
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<13.800000,0.000000,13.000000>}
cylinder{<0,0,0><0,0.035000,0>0.152400 translate<13.800000,0.000000,16.700000>}
box{<0,0,-0.152400><3.700000,0.035000,0.152400> rotate<0,90.000000,0> translate<13.800000,0.000000,16.700000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<13.750000,0.000000,10.590000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<14.300000,0.000000,10.570000>}
box{<0,0,-0.127000><0.550364,0.035000,0.127000> rotate<0,2.082428,0> translate<13.750000,0.000000,10.590000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<14.300000,0.000000,7.650000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<14.300000,0.000000,10.570000>}
box{<0,0,-0.127000><2.920000,0.035000,0.127000> rotate<0,90.000000,0> translate<14.300000,0.000000,10.570000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<5.000000,-1.535000,11.940000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<15.970000,-1.535000,11.950000>}
box{<0,0,-0.127000><10.970005,0.035000,0.127000> rotate<0,-0.052226,0> translate<5.000000,-1.535000,11.940000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<15.970000,-1.535000,11.950000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<15.970000,-1.535000,12.770000>}
box{<0,0,-0.127000><0.820000,0.035000,0.127000> rotate<0,90.000000,0> translate<15.970000,-1.535000,12.770000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<3.000000,-1.535000,9.230000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<16.100000,-1.535000,9.230000>}
box{<0,0,-0.127000><13.100000,0.035000,0.127000> rotate<0,0.000000,0> translate<3.000000,-1.535000,9.230000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<16.100000,-1.535000,10.190000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<16.100000,-1.535000,9.230000>}
box{<0,0,-0.127000><0.960000,0.035000,0.127000> rotate<0,-90.000000,0> translate<16.100000,-1.535000,9.230000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<16.530000,-1.535000,21.000000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<16.530000,-1.535000,20.400000>}
box{<0,0,-0.127000><0.600000,0.035000,0.127000> rotate<0,-90.000000,0> translate<16.530000,-1.535000,20.400000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<3.000000,-1.535000,21.000000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<16.530000,-1.535000,21.000000>}
box{<0,0,-0.127000><13.530000,0.035000,0.127000> rotate<0,0.000000,0> translate<3.000000,-1.535000,21.000000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<11.110000,0.000000,18.380000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<18.000000,0.000000,18.380000>}
box{<0,0,-0.127000><6.890000,0.035000,0.127000> rotate<0,0.000000,0> translate<11.110000,0.000000,18.380000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<18.000000,0.000000,17.810000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<18.000000,0.000000,18.380000>}
box{<0,0,-0.127000><0.570000,0.035000,0.127000> rotate<0,90.000000,0> translate<18.000000,0.000000,18.380000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<15.970000,-1.535000,12.770000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<18.010000,-1.535000,12.770000>}
box{<0,0,-0.127000><2.040000,0.035000,0.127000> rotate<0,0.000000,0> translate<15.970000,-1.535000,12.770000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<16.530000,-1.535000,20.400000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<18.010000,-1.535000,20.400000>}
box{<0,0,-0.127000><1.480000,0.035000,0.127000> rotate<0,0.000000,0> translate<16.530000,-1.535000,20.400000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<1.240000,-1.535000,7.640000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<19.020000,-1.535000,7.640000>}
box{<0,0,-0.127000><17.780000,0.035000,0.127000> rotate<0,0.000000,0> translate<1.240000,-1.535000,7.640000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<14.300000,0.000000,7.650000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<19.020000,0.000000,7.640000>}
box{<0,0,-0.127000><4.720011,0.035000,0.127000> rotate<0,0.121381,0> translate<14.300000,0.000000,7.650000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<16.100000,-1.535000,10.190000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<19.020000,-1.535000,10.180000>}
box{<0,0,-0.127000><2.920017,0.035000,0.127000> rotate<0,0.196205,0> translate<16.100000,-1.535000,10.190000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<18.010000,-1.535000,12.770000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<19.020000,-1.535000,12.720000>}
box{<0,0,-0.127000><1.011237,0.035000,0.127000> rotate<0,2.833924,0> translate<18.010000,-1.535000,12.770000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<1.240000,-1.535000,17.800000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<19.020000,-1.535000,17.800000>}
box{<0,0,-0.127000><17.780000,0.035000,0.127000> rotate<0,0.000000,0> translate<1.240000,-1.535000,17.800000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<18.000000,0.000000,17.810000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<19.020000,0.000000,17.800000>}
box{<0,0,-0.127000><1.020049,0.035000,0.127000> rotate<0,0.561668,0> translate<18.000000,0.000000,17.810000> }
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<18.010000,-1.535000,20.400000>}
cylinder{<0,0,0><0,0.035000,0>0.127000 translate<19.020000,-1.535000,20.340000>}
box{<0,0,-0.127000><1.011781,0.035000,0.127000> rotate<0,3.399490,0> translate<18.010000,-1.535000,20.400000> }
//Text
//Rect
union{
texture{col_pds}
}
texture{col_wrs}
}
#end
#if(pcb_polygons=on)
union{
//Polygons
cylinder{<0,0,0><0,0.035000,0>0.203200 translate<0.000000,-1.535000,6.730000>}
cylinder{<0,0,0><0,0.035000,0>0.203200 translate<0.080000,-1.535000,22.180000>}
box{<0,0,-0.203200><15.450207,0.035000,0.203200> rotate<0,-89.697405,0> translate<0.000000,-1.535000,6.730000> }
cylinder{<0,0,0><0,0.035000,0>0.203200 translate<0.000000,-1.535000,6.730000>}
cylinder{<0,0,0><0,0.035000,0>0.203200 translate<19.050000,-1.535000,6.730000>}
box{<0,0,-0.203200><19.050000,0.035000,0.203200> rotate<0,0.000000,0> translate<0.000000,-1.535000,6.730000> }
cylinder{<0,0,0><0,0.035000,0>0.203200 translate<0.080000,-1.535000,22.180000>}
cylinder{<0,0,0><0,0.035000,0>0.203200 translate<19.130000,-1.535000,22.180000>}
box{<0,0,-0.203200><19.050000,0.035000,0.203200> rotate<0,0.000000,0> translate<0.080000,-1.535000,22.180000> }
cylinder{<0,0,0><0,0.035000,0>0.203200 translate<0.120000,0.000000,6.640000>}
cylinder{<0,0,0><0,0.035000,0>0.203200 translate<0.280000,0.000000,21.750000>}
box{<0,0,-0.203200><15.110847,0.035000,0.203200> rotate<0,-89.387417,0> translate<0.120000,0.000000,6.640000> }
cylinder{<0,0,0><0,0.035000,0>0.203200 translate<0.120000,0.000000,6.640000>}
cylinder{<0,0,0><0,0.035000,0>0.203200 translate<20.010000,0.000000,6.640000>}
box{<0,0,-0.203200><19.890000,0.035000,0.203200> rotate<0,0.000000,0> translate<0.120000,0.000000,6.640000> }
cylinder{<0,0,0><0,0.035000,0>0.203200 translate<0.280000,0.000000,21.750000>}
cylinder{<0,0,0><0,0.035000,0>0.203200 translate<20.170000,0.000000,21.750000>}
box{<0,0,-0.203200><19.890000,0.035000,0.203200> rotate<0,0.000000,0> translate<0.280000,0.000000,21.750000> }
cylinder{<0,0,0><0,0.035000,0>0.203200 translate<19.050000,-1.535000,6.730000>}
cylinder{<0,0,0><0,0.035000,0>0.203200 translate<19.130000,-1.535000,22.180000>}
box{<0,0,-0.203200><15.450207,0.035000,0.203200> rotate<0,-89.697405,0> translate<19.050000,-1.535000,6.730000> }
cylinder{<0,0,0><0,0.035000,0>0.203200 translate<20.010000,0.000000,6.640000>}
cylinder{<0,0,0><0,0.035000,0>0.203200 translate<20.170000,0.000000,21.750000>}
box{<0,0,-0.203200><15.110847,0.035000,0.203200> rotate<0,-89.387417,0> translate<20.010000,0.000000,6.640000> }
texture{col_pol}
}
#end
union{
cylinder{<1.240000,0.038000,20.340000><1.240000,-1.538000,20.340000>0.508000}
cylinder{<19.020000,0.038000,20.340000><19.020000,-1.538000,20.340000>0.508000}
cylinder{<1.240000,0.038000,15.260000><1.240000,-1.538000,15.260000>0.508000}
cylinder{<19.020000,0.038000,15.260000><19.020000,-1.538000,15.260000>0.508000}
cylinder{<1.240000,0.038000,7.640000><1.240000,-1.538000,7.640000>0.508000}
cylinder{<19.020000,0.038000,7.640000><19.020000,-1.538000,7.640000>0.508000}
cylinder{<1.240000,0.038000,10.180000><1.240000,-1.538000,10.180000>0.508000}
cylinder{<19.020000,0.038000,10.180000><19.020000,-1.538000,10.180000>0.508000}
cylinder{<1.240000,0.038000,12.720000><1.240000,-1.538000,12.720000>0.508000}
cylinder{<19.020000,0.038000,12.720000><19.020000,-1.538000,12.720000>0.508000}
cylinder{<1.240000,0.038000,17.800000><1.240000,-1.538000,17.800000>0.508000}
cylinder{<19.020000,0.038000,17.800000><19.020000,-1.538000,17.800000>0.508000}
//Holes(fast)/Vias
cylinder{<4.170000,0.038000,15.540000><4.170000,-1.538000,15.540000>0.300000 }
cylinder{<12.670000,0.038000,15.690000><12.670000,-1.538000,15.690000>0.300000 }
cylinder{<15.490000,0.038000,15.320000><15.490000,-1.538000,15.320000>0.300000 }
cylinder{<4.280000,0.038000,19.690000><4.280000,-1.538000,19.690000>0.300000 }
cylinder{<13.750000,0.038000,10.590000><13.750000,-1.538000,10.590000>0.300000 }
cylinder{<8.010000,0.038000,10.570000><8.010000,-1.538000,10.570000>0.300000 }
cylinder{<12.620000,0.038000,13.810000><12.620000,-1.538000,13.810000>0.300000 }
cylinder{<8.210000,0.038000,12.730000><8.210000,-1.538000,12.730000>0.300000 }
//Holes(fast)/Board
texture{col_hls}
}
#if(pcb_silkscreen=on)
//Silk Screen
union{
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<5.230847,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<4.891891,0.000000,19.544434>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<4.891891,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<4.891891,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<4.891891,0.000000,19.036000>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,-90.000000,0> translate<4.891891,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<4.891891,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<5.230847,0.000000,19.036000>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<4.891891,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<4.891891,0.000000,19.290216>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<5.061369,0.000000,19.290216>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<4.891891,0.000000,19.290216> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<5.453200,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<5.792156,0.000000,19.544434>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<5.453200,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<5.792156,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<5.792156,0.000000,19.459694>}
box{<0,0,-0.050800><0.084741,0.036000,0.050800> rotate<0,-90.000000,0> translate<5.792156,0.000000,19.459694> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<5.792156,0.000000,19.459694>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<5.453200,0.000000,19.120738>}
box{<0,0,-0.050800><0.479357,0.036000,0.050800> rotate<0,-44.997030,0> translate<5.453200,0.000000,19.120738> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<5.453200,0.000000,19.120738>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<5.453200,0.000000,19.036000>}
box{<0,0,-0.050800><0.084737,0.036000,0.050800> rotate<0,-90.000000,0> translate<5.453200,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<5.453200,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<5.792156,0.000000,19.036000>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<5.453200,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<6.014509,0.000000,19.290216>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<6.353466,0.000000,19.290216>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<6.014509,0.000000,19.290216> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<6.575819,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<6.745297,0.000000,19.036000>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<6.575819,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<6.660556,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<6.660556,0.000000,19.544434>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,90.000000,0> translate<6.660556,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<6.575819,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<6.745297,0.000000,19.544434>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<6.575819,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.288981,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<6.950025,0.000000,19.036000>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<6.950025,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<6.950025,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.288981,0.000000,19.374956>}
box{<0,0,-0.050800><0.479357,0.036000,0.050800> rotate<0,-44.997030,0> translate<6.950025,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.288981,0.000000,19.374956>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.288981,0.000000,19.459694>}
box{<0,0,-0.050800><0.084737,0.036000,0.050800> rotate<0,90.000000,0> translate<7.288981,0.000000,19.459694> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.288981,0.000000,19.459694>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.204241,0.000000,19.544434>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<7.204241,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.204241,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.034763,0.000000,19.544434>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<7.034763,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.034763,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<6.950025,0.000000,19.459694>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<6.950025,0.000000,19.459694> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.850291,0.000000,19.459694>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.765550,0.000000,19.544434>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<7.765550,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.765550,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.596072,0.000000,19.544434>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<7.596072,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.596072,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.511334,0.000000,19.459694>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<7.511334,0.000000,19.459694> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.511334,0.000000,19.459694>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.511334,0.000000,19.120738>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,-90.000000,0> translate<7.511334,0.000000,19.120738> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.511334,0.000000,19.120738>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.596072,0.000000,19.036000>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,44.997030,0> translate<7.511334,0.000000,19.120738> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.596072,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.765550,0.000000,19.036000>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<7.596072,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.765550,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.850291,0.000000,19.120738>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<7.765550,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<8.633953,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<8.633953,0.000000,19.120738>}
box{<0,0,-0.050800><0.423697,0.036000,0.050800> rotate<0,-90.000000,0> translate<8.633953,0.000000,19.120738> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<8.633953,0.000000,19.120738>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<8.718691,0.000000,19.036000>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,44.997030,0> translate<8.633953,0.000000,19.120738> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<8.718691,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<8.888169,0.000000,19.036000>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<8.718691,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<8.888169,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<8.972909,0.000000,19.120738>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<8.888169,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<8.972909,0.000000,19.120738>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<8.972909,0.000000,19.544434>}
box{<0,0,-0.050800><0.423697,0.036000,0.050800> rotate<0,90.000000,0> translate<8.972909,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<9.195263,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<9.195263,0.000000,19.205478>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,-90.000000,0> translate<9.195263,0.000000,19.205478> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<9.195263,0.000000,19.205478>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<9.364741,0.000000,19.036000>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<9.195263,0.000000,19.205478> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<9.364741,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<9.534219,0.000000,19.205478>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,-44.997030,0> translate<9.364741,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<9.534219,0.000000,19.205478>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<9.534219,0.000000,19.544434>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<9.534219,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.656837,0.000000,19.459694>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.572097,0.000000,19.544434>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<10.572097,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.572097,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.402619,0.000000,19.544434>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<10.402619,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.402619,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.317881,0.000000,19.459694>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<10.317881,0.000000,19.459694> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.317881,0.000000,19.459694>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.317881,0.000000,19.374956>}
box{<0,0,-0.050800><0.084737,0.036000,0.050800> rotate<0,-90.000000,0> translate<10.317881,0.000000,19.374956> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.317881,0.000000,19.374956>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.402619,0.000000,19.290216>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<10.317881,0.000000,19.374956> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.402619,0.000000,19.290216>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.572097,0.000000,19.290216>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<10.402619,0.000000,19.290216> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.572097,0.000000,19.290216>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.656837,0.000000,19.205478>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<10.572097,0.000000,19.290216> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.656837,0.000000,19.205478>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.656837,0.000000,19.120738>}
box{<0,0,-0.050800><0.084741,0.036000,0.050800> rotate<0,-90.000000,0> translate<10.656837,0.000000,19.120738> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.656837,0.000000,19.120738>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.572097,0.000000,19.036000>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<10.572097,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.572097,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.402619,0.000000,19.036000>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<10.402619,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.402619,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.317881,0.000000,19.120738>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,44.997030,0> translate<10.317881,0.000000,19.120738> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.218147,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.879191,0.000000,19.544434>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<10.879191,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.879191,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.879191,0.000000,19.036000>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,-90.000000,0> translate<10.879191,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.879191,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.218147,0.000000,19.036000>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<10.879191,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<10.879191,0.000000,19.290216>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.048669,0.000000,19.290216>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<10.879191,0.000000,19.290216> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.440500,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.440500,0.000000,19.544434>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,90.000000,0> translate<11.440500,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.440500,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.779456,0.000000,19.036000>}
box{<0,0,-0.050800><0.611062,0.036000,0.050800> rotate<0,56.306216,0> translate<11.440500,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.779456,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.779456,0.000000,19.544434>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,90.000000,0> translate<11.779456,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.340766,0.000000,19.459694>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.256025,0.000000,19.544434>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<12.256025,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.256025,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.086547,0.000000,19.544434>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<12.086547,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.086547,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.001809,0.000000,19.459694>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<12.001809,0.000000,19.459694> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.001809,0.000000,19.459694>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.001809,0.000000,19.374956>}
box{<0,0,-0.050800><0.084737,0.036000,0.050800> rotate<0,-90.000000,0> translate<12.001809,0.000000,19.374956> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.001809,0.000000,19.374956>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.086547,0.000000,19.290216>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<12.001809,0.000000,19.374956> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.086547,0.000000,19.290216>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.256025,0.000000,19.290216>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<12.086547,0.000000,19.290216> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.256025,0.000000,19.290216>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.340766,0.000000,19.205478>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<12.256025,0.000000,19.290216> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.340766,0.000000,19.205478>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.340766,0.000000,19.120738>}
box{<0,0,-0.050800><0.084741,0.036000,0.050800> rotate<0,-90.000000,0> translate<12.340766,0.000000,19.120738> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.340766,0.000000,19.120738>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.256025,0.000000,19.036000>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<12.256025,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.256025,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.086547,0.000000,19.036000>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<12.086547,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.086547,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.001809,0.000000,19.120738>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,44.997030,0> translate<12.001809,0.000000,19.120738> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.817334,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.647856,0.000000,19.544434>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<12.647856,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.647856,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.563119,0.000000,19.459694>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<12.563119,0.000000,19.459694> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.563119,0.000000,19.459694>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.563119,0.000000,19.120738>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,-90.000000,0> translate<12.563119,0.000000,19.120738> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.563119,0.000000,19.120738>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.647856,0.000000,19.036000>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,44.997030,0> translate<12.563119,0.000000,19.120738> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.647856,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.817334,0.000000,19.036000>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<12.647856,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.817334,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.902075,0.000000,19.120738>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<12.817334,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.902075,0.000000,19.120738>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.902075,0.000000,19.459694>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<12.902075,0.000000,19.459694> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.902075,0.000000,19.459694>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.817334,0.000000,19.544434>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<12.817334,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<13.124428,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<13.124428,0.000000,19.544434>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,90.000000,0> translate<13.124428,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<13.124428,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<13.378644,0.000000,19.544434>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<13.124428,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<13.378644,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<13.463384,0.000000,19.459694>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<13.378644,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<13.463384,0.000000,19.459694>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<13.463384,0.000000,19.290216>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<13.463384,0.000000,19.290216> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<13.463384,0.000000,19.290216>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<13.378644,0.000000,19.205478>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<13.378644,0.000000,19.205478> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<13.378644,0.000000,19.205478>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<13.124428,0.000000,19.205478>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<13.124428,0.000000,19.205478> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<13.293906,0.000000,19.205478>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<13.463384,0.000000,19.036000>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<13.293906,0.000000,19.205478> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<14.247047,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<14.247047,0.000000,19.205478>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,-90.000000,0> translate<14.247047,0.000000,19.205478> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<14.247047,0.000000,19.205478>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<14.416525,0.000000,19.036000>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<14.247047,0.000000,19.205478> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<14.416525,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<14.586003,0.000000,19.205478>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,-44.997030,0> translate<14.416525,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<14.586003,0.000000,19.205478>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<14.586003,0.000000,19.544434>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<14.586003,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<15.147312,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<14.808356,0.000000,19.036000>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<14.808356,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<14.808356,0.000000,19.036000>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<15.147312,0.000000,19.374956>}
box{<0,0,-0.050800><0.479357,0.036000,0.050800> rotate<0,-44.997030,0> translate<14.808356,0.000000,19.036000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<15.147312,0.000000,19.374956>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<15.147312,0.000000,19.459694>}
box{<0,0,-0.050800><0.084737,0.036000,0.050800> rotate<0,90.000000,0> translate<15.147312,0.000000,19.459694> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<15.147312,0.000000,19.459694>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<15.062572,0.000000,19.544434>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<15.062572,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<15.062572,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<14.893094,0.000000,19.544434>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<14.893094,0.000000,19.544434> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<14.893094,0.000000,19.544434>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<14.808356,0.000000,19.459694>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<14.808356,0.000000,19.459694> }
cylinder{<0,0,0><0,0.036000,0>0.000000 translate<0.210000,-1.536000,6.610000>}
cylinder{<0,0,0><0,0.036000,0>0.000000 translate<20.055000,-1.536000,6.610000>}
box{<0,0,0.000000><19.845000,0.036000,0.000000> rotate<0,0.000000,0> translate<0.210000,-1.536000,6.610000> }
cylinder{<0,0,0><0,0.036000,0>0.000000 translate<20.055000,-1.536000,6.610000>}
cylinder{<0,0,0><0,0.036000,0>0.000000 translate<20.065000,-1.536000,21.840000>}
box{<0,0,0.000000><15.230003,0.036000,0.000000> rotate<0,-89.956443,0> translate<20.055000,-1.536000,6.610000> }
cylinder{<0,0,0><0,0.036000,0>0.000000 translate<20.065000,-1.536000,21.840000>}
cylinder{<0,0,0><0,0.036000,0>0.000000 translate<0.210000,-1.536000,21.820000>}
box{<0,0,0.000000><19.855010,0.036000,0.000000> rotate<0,-0.057710,0> translate<0.210000,-1.536000,21.820000> }
cylinder{<0,0,0><0,0.036000,0>0.000000 translate<0.210000,-1.536000,21.820000>}
cylinder{<0,0,0><0,0.036000,0>0.000000 translate<0.210000,-1.536000,6.610000>}
box{<0,0,0.000000><15.210000,0.036000,0.000000> rotate<0,-90.000000,0> translate<0.210000,-1.536000,6.610000> }
//C1 silk screen
cylinder{<0,0,0><0,0.036000,0>0.203200 translate<10.190000,0.000000,7.550500>}
cylinder{<0,0,0><0,0.036000,0>0.203200 translate<10.190000,0.000000,7.489500>}
box{<0,0,-0.203200><0.061000,0.036000,0.203200> rotate<0,-90.000000,0> translate<10.190000,0.000000,7.489500> }
cylinder{<0,0,0><0,0.036000,0>0.025400 translate<7.899250,0.000000,7.459963>}
cylinder{<0,0,0><0,0.036000,0>0.025400 translate<7.806038,0.000000,7.553175>}
box{<0,0,-0.025400><0.131822,0.036000,0.025400> rotate<0,44.997030,0> translate<7.806038,0.000000,7.553175> }
cylinder{<0,0,0><0,0.036000,0>0.025400 translate<7.806038,0.000000,7.553175>}
cylinder{<0,0,0><0,0.036000,0>0.025400 translate<7.619613,0.000000,7.553175>}
box{<0,0,-0.025400><0.186425,0.036000,0.025400> rotate<0,0.000000,0> translate<7.619613,0.000000,7.553175> }
cylinder{<0,0,0><0,0.036000,0>0.025400 translate<7.619613,0.000000,7.553175>}
cylinder{<0,0,0><0,0.036000,0>0.025400 translate<7.526400,0.000000,7.459963>}
box{<0,0,-0.025400><0.131822,0.036000,0.025400> rotate<0,-44.997030,0> translate<7.526400,0.000000,7.459963> }
cylinder{<0,0,0><0,0.036000,0>0.025400 translate<7.526400,0.000000,7.459963>}
cylinder{<0,0,0><0,0.036000,0>0.025400 translate<7.526400,0.000000,7.087112>}
box{<0,0,-0.025400><0.372850,0.036000,0.025400> rotate<0,-90.000000,0> translate<7.526400,0.000000,7.087112> }
cylinder{<0,0,0><0,0.036000,0>0.025400 translate<7.526400,0.000000,7.087112>}
cylinder{<0,0,0><0,0.036000,0>0.025400 translate<7.619613,0.000000,6.993900>}
box{<0,0,-0.025400><0.131822,0.036000,0.025400> rotate<0,44.997030,0> translate<7.526400,0.000000,7.087112> }
cylinder{<0,0,0><0,0.036000,0>0.025400 translate<7.619613,0.000000,6.993900>}
cylinder{<0,0,0><0,0.036000,0>0.025400 translate<7.806038,0.000000,6.993900>}
box{<0,0,-0.025400><0.186425,0.036000,0.025400> rotate<0,0.000000,0> translate<7.619613,0.000000,6.993900> }
cylinder{<0,0,0><0,0.036000,0>0.025400 translate<7.806038,0.000000,6.993900>}
cylinder{<0,0,0><0,0.036000,0>0.025400 translate<7.899250,0.000000,7.087112>}
box{<0,0,-0.025400><0.131822,0.036000,0.025400> rotate<0,-44.997030,0> translate<7.806038,0.000000,6.993900> }
cylinder{<0,0,0><0,0.036000,0>0.025400 translate<8.087709,0.000000,7.366750>}
cylinder{<0,0,0><0,0.036000,0>0.025400 translate<8.274134,0.000000,7.553175>}
box{<0,0,-0.025400><0.263645,0.036000,0.025400> rotate<0,-44.997030,0> translate<8.087709,0.000000,7.366750> }
cylinder{<0,0,0><0,0.036000,0>0.025400 translate<8.274134,0.000000,7.553175>}
cylinder{<0,0,0><0,0.036000,0>0.025400 translate<8.274134,0.000000,6.993900>}
box{<0,0,-0.025400><0.559275,0.036000,0.025400> rotate<0,-90.000000,0> translate<8.274134,0.000000,6.993900> }
cylinder{<0,0,0><0,0.036000,0>0.025400 translate<8.087709,0.000000,6.993900>}
cylinder{<0,0,0><0,0.036000,0>0.025400 translate<8.460559,0.000000,6.993900>}
box{<0,0,-0.025400><0.372850,0.036000,0.025400> rotate<0,0.000000,0> translate<8.087709,0.000000,6.993900> }
//R1 silk screen
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<8.790000,0.000000,17.555000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<8.790000,0.000000,18.825000>}
box{<0,0,-0.101600><1.270000,0.036000,0.101600> rotate<0,90.000000,0> translate<8.790000,0.000000,18.825000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<8.790000,0.000000,18.825000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<11.330000,0.000000,18.825000>}
box{<0,0,-0.101600><2.540000,0.036000,0.101600> rotate<0,0.000000,0> translate<8.790000,0.000000,18.825000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<11.330000,0.000000,18.825000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<11.330000,0.000000,17.555000>}
box{<0,0,-0.101600><1.270000,0.036000,0.101600> rotate<0,-90.000000,0> translate<11.330000,0.000000,17.555000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<11.330000,0.000000,17.555000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<8.790000,0.000000,17.555000>}
box{<0,0,-0.101600><2.540000,0.036000,0.101600> rotate<0,0.000000,0> translate<8.790000,0.000000,17.555000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.677800,0.000000,18.220300>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.677800,0.000000,18.728734>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,90.000000,0> translate<7.677800,0.000000,18.728734> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.677800,0.000000,18.728734>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.932016,0.000000,18.728734>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<7.677800,0.000000,18.728734> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.932016,0.000000,18.728734>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<8.016756,0.000000,18.643994>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<7.932016,0.000000,18.728734> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<8.016756,0.000000,18.643994>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<8.016756,0.000000,18.474516>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<8.016756,0.000000,18.474516> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<8.016756,0.000000,18.474516>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.932016,0.000000,18.389778>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<7.932016,0.000000,18.389778> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.932016,0.000000,18.389778>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.677800,0.000000,18.389778>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<7.677800,0.000000,18.389778> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<7.847278,0.000000,18.389778>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<8.016756,0.000000,18.220300>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<7.847278,0.000000,18.389778> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<8.239109,0.000000,18.559256>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<8.408588,0.000000,18.728734>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,-44.997030,0> translate<8.239109,0.000000,18.559256> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<8.408588,0.000000,18.728734>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<8.408588,0.000000,18.220300>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,-90.000000,0> translate<8.408588,0.000000,18.220300> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<8.239109,0.000000,18.220300>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<8.578066,0.000000,18.220300>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<8.239109,0.000000,18.220300> }
//R2 silk screen
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<8.940000,0.000000,8.755000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<8.940000,0.000000,10.025000>}
box{<0,0,-0.101600><1.270000,0.036000,0.101600> rotate<0,90.000000,0> translate<8.940000,0.000000,10.025000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<8.940000,0.000000,10.025000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<11.480000,0.000000,10.025000>}
box{<0,0,-0.101600><2.540000,0.036000,0.101600> rotate<0,0.000000,0> translate<8.940000,0.000000,10.025000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<11.480000,0.000000,10.025000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<11.480000,0.000000,8.755000>}
box{<0,0,-0.101600><1.270000,0.036000,0.101600> rotate<0,-90.000000,0> translate<11.480000,0.000000,8.755000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<11.480000,0.000000,8.755000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<8.940000,0.000000,8.755000>}
box{<0,0,-0.101600><2.540000,0.036000,0.101600> rotate<0,0.000000,0> translate<8.940000,0.000000,8.755000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.657800,0.000000,9.400300>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.657800,0.000000,9.908734>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,90.000000,0> translate<11.657800,0.000000,9.908734> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.657800,0.000000,9.908734>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.912016,0.000000,9.908734>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<11.657800,0.000000,9.908734> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.912016,0.000000,9.908734>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.996756,0.000000,9.823994>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<11.912016,0.000000,9.908734> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.996756,0.000000,9.823994>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.996756,0.000000,9.654516>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<11.996756,0.000000,9.654516> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.996756,0.000000,9.654516>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.912016,0.000000,9.569778>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<11.912016,0.000000,9.569778> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.912016,0.000000,9.569778>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.657800,0.000000,9.569778>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<11.657800,0.000000,9.569778> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.827278,0.000000,9.569778>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.996756,0.000000,9.400300>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<11.827278,0.000000,9.569778> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.558066,0.000000,9.400300>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.219109,0.000000,9.400300>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<12.219109,0.000000,9.400300> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.219109,0.000000,9.400300>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.558066,0.000000,9.739256>}
box{<0,0,-0.050800><0.479357,0.036000,0.050800> rotate<0,-44.997030,0> translate<12.219109,0.000000,9.400300> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.558066,0.000000,9.739256>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.558066,0.000000,9.823994>}
box{<0,0,-0.050800><0.084737,0.036000,0.050800> rotate<0,90.000000,0> translate<12.558066,0.000000,9.823994> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.558066,0.000000,9.823994>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.473325,0.000000,9.908734>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<12.473325,0.000000,9.908734> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.473325,0.000000,9.908734>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.303847,0.000000,9.908734>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<12.303847,0.000000,9.908734> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.303847,0.000000,9.908734>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.219109,0.000000,9.823994>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<12.219109,0.000000,9.823994> }
//R3 silk screen
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<8.980000,0.000000,10.505000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<8.980000,0.000000,11.775000>}
box{<0,0,-0.101600><1.270000,0.036000,0.101600> rotate<0,90.000000,0> translate<8.980000,0.000000,11.775000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<8.980000,0.000000,11.775000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<11.520000,0.000000,11.775000>}
box{<0,0,-0.101600><2.540000,0.036000,0.101600> rotate<0,0.000000,0> translate<8.980000,0.000000,11.775000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<11.520000,0.000000,11.775000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<11.520000,0.000000,10.505000>}
box{<0,0,-0.101600><1.270000,0.036000,0.101600> rotate<0,-90.000000,0> translate<11.520000,0.000000,10.505000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<11.520000,0.000000,10.505000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<8.980000,0.000000,10.505000>}
box{<0,0,-0.101600><2.540000,0.036000,0.101600> rotate<0,0.000000,0> translate<8.980000,0.000000,10.505000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.697800,0.000000,11.000300>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.697800,0.000000,11.508734>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,90.000000,0> translate<11.697800,0.000000,11.508734> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.697800,0.000000,11.508734>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.952016,0.000000,11.508734>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<11.697800,0.000000,11.508734> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.952016,0.000000,11.508734>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.036756,0.000000,11.423994>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<11.952016,0.000000,11.508734> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.036756,0.000000,11.423994>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.036756,0.000000,11.254516>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<12.036756,0.000000,11.254516> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.036756,0.000000,11.254516>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.952016,0.000000,11.169778>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<11.952016,0.000000,11.169778> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.952016,0.000000,11.169778>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.697800,0.000000,11.169778>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<11.697800,0.000000,11.169778> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<11.867278,0.000000,11.169778>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.036756,0.000000,11.000300>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<11.867278,0.000000,11.169778> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.259109,0.000000,11.423994>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.343847,0.000000,11.508734>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<12.259109,0.000000,11.423994> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.343847,0.000000,11.508734>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.513325,0.000000,11.508734>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<12.343847,0.000000,11.508734> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.513325,0.000000,11.508734>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.598066,0.000000,11.423994>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<12.513325,0.000000,11.508734> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.598066,0.000000,11.423994>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.598066,0.000000,11.339256>}
box{<0,0,-0.050800><0.084738,0.036000,0.050800> rotate<0,-90.000000,0> translate<12.598066,0.000000,11.339256> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.598066,0.000000,11.339256>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.513325,0.000000,11.254516>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<12.513325,0.000000,11.254516> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.513325,0.000000,11.254516>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.428588,0.000000,11.254516>}
box{<0,0,-0.050800><0.084737,0.036000,0.050800> rotate<0,0.000000,0> translate<12.428588,0.000000,11.254516> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.513325,0.000000,11.254516>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.598066,0.000000,11.169778>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<12.513325,0.000000,11.254516> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.598066,0.000000,11.169778>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.598066,0.000000,11.085038>}
box{<0,0,-0.050800><0.084741,0.036000,0.050800> rotate<0,-90.000000,0> translate<12.598066,0.000000,11.085038> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.598066,0.000000,11.085038>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.513325,0.000000,11.000300>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<12.513325,0.000000,11.000300> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.513325,0.000000,11.000300>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.343847,0.000000,11.000300>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<12.343847,0.000000,11.000300> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.343847,0.000000,11.000300>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<12.259109,0.000000,11.085038>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,44.997030,0> translate<12.259109,0.000000,11.085038> }
//U$1 silk screen
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,20.975000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,19.705000>}
box{<0,0,-0.101600><1.270000,0.036000,0.101600> rotate<0,-90.000000,0> translate<2.310000,0.000000,19.705000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,19.705000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.175000,0.000000,19.070000>}
box{<0,0,-0.101600><0.649192,0.036000,0.101600> rotate<0,-77.992558,0> translate<2.175000,0.000000,19.070000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.175000,0.000000,16.530000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,15.895000>}
box{<0,0,-0.101600><0.649192,0.036000,0.101600> rotate<0,77.992558,0> translate<2.175000,0.000000,16.530000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.175000,0.000000,19.070000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,18.435000>}
box{<0,0,-0.101600><0.649192,0.036000,0.101600> rotate<0,77.992558,0> translate<2.175000,0.000000,19.070000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,18.435000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,17.165000>}
box{<0,0,-0.101600><1.270000,0.036000,0.101600> rotate<0,-90.000000,0> translate<2.310000,0.000000,17.165000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,17.165000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.175000,0.000000,16.530000>}
box{<0,0,-0.101600><0.649192,0.036000,0.101600> rotate<0,-77.992558,0> translate<2.175000,0.000000,16.530000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.175000,0.000000,13.990000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,13.355000>}
box{<0,0,-0.101600><0.649192,0.036000,0.101600> rotate<0,77.992558,0> translate<2.175000,0.000000,13.990000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,13.355000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,12.085000>}
box{<0,0,-0.101600><1.270000,0.036000,0.101600> rotate<0,-90.000000,0> translate<2.310000,0.000000,12.085000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,12.085000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.175000,0.000000,11.450000>}
box{<0,0,-0.101600><0.649192,0.036000,0.101600> rotate<0,-77.992558,0> translate<2.175000,0.000000,11.450000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.175000,0.000000,13.990000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,14.625000>}
box{<0,0,-0.101600><0.649192,0.036000,0.101600> rotate<0,-77.992558,0> translate<2.175000,0.000000,13.990000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,15.895000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,14.625000>}
box{<0,0,-0.101600><1.270000,0.036000,0.101600> rotate<0,-90.000000,0> translate<2.310000,0.000000,14.625000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.175000,0.000000,8.910000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,8.275000>}
box{<0,0,-0.101600><0.649192,0.036000,0.101600> rotate<0,77.992558,0> translate<2.175000,0.000000,8.910000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.175000,0.000000,11.450000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,10.815000>}
box{<0,0,-0.101600><0.649192,0.036000,0.101600> rotate<0,77.992558,0> translate<2.175000,0.000000,11.450000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,10.815000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,9.545000>}
box{<0,0,-0.101600><1.270000,0.036000,0.101600> rotate<0,-90.000000,0> translate<2.310000,0.000000,9.545000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,9.545000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.175000,0.000000,8.910000>}
box{<0,0,-0.101600><0.649192,0.036000,0.101600> rotate<0,-77.992558,0> translate<2.175000,0.000000,8.910000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,8.275000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<2.310000,0.000000,7.005000>}
box{<0,0,-0.101600><1.270000,0.036000,0.101600> rotate<0,-90.000000,0> translate<2.310000,0.000000,7.005000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<18.085000,0.000000,19.070000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,19.705000>}
box{<0,0,-0.101600><0.649192,0.036000,0.101600> rotate<0,77.992558,0> translate<17.950000,0.000000,19.705000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,19.705000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,20.975000>}
box{<0,0,-0.101600><1.270000,0.036000,0.101600> rotate<0,90.000000,0> translate<17.950000,0.000000,20.975000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,14.625000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,15.895000>}
box{<0,0,-0.101600><1.270000,0.036000,0.101600> rotate<0,90.000000,0> translate<17.950000,0.000000,15.895000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,15.895000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<18.085000,0.000000,16.530000>}
box{<0,0,-0.101600><0.649192,0.036000,0.101600> rotate<0,-77.992558,0> translate<17.950000,0.000000,15.895000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<18.085000,0.000000,16.530000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,17.165000>}
box{<0,0,-0.101600><0.649192,0.036000,0.101600> rotate<0,77.992558,0> translate<17.950000,0.000000,17.165000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,17.165000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,18.435000>}
box{<0,0,-0.101600><1.270000,0.036000,0.101600> rotate<0,90.000000,0> translate<17.950000,0.000000,18.435000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,18.435000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<18.085000,0.000000,19.070000>}
box{<0,0,-0.101600><0.649192,0.036000,0.101600> rotate<0,-77.992558,0> translate<17.950000,0.000000,18.435000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<18.085000,0.000000,11.450000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,12.085000>}
box{<0,0,-0.101600><0.649192,0.036000,0.101600> rotate<0,77.992558,0> translate<17.950000,0.000000,12.085000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,12.085000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,13.355000>}
box{<0,0,-0.101600><1.270000,0.036000,0.101600> rotate<0,90.000000,0> translate<17.950000,0.000000,13.355000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,13.355000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<18.085000,0.000000,13.990000>}
box{<0,0,-0.101600><0.649192,0.036000,0.101600> rotate<0,-77.992558,0> translate<17.950000,0.000000,13.355000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,14.625000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<18.085000,0.000000,13.990000>}
box{<0,0,-0.101600><0.649192,0.036000,0.101600> rotate<0,77.992558,0> translate<17.950000,0.000000,14.625000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,7.005000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,8.275000>}
box{<0,0,-0.101600><1.270000,0.036000,0.101600> rotate<0,90.000000,0> translate<17.950000,0.000000,8.275000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,8.275000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<18.085000,0.000000,8.910000>}
box{<0,0,-0.101600><0.649192,0.036000,0.101600> rotate<0,-77.992558,0> translate<17.950000,0.000000,8.275000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<18.085000,0.000000,8.910000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,9.545000>}
box{<0,0,-0.101600><0.649192,0.036000,0.101600> rotate<0,77.992558,0> translate<17.950000,0.000000,9.545000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,9.545000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,10.815000>}
box{<0,0,-0.101600><1.270000,0.036000,0.101600> rotate<0,90.000000,0> translate<17.950000,0.000000,10.815000> }
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<17.950000,0.000000,10.815000>}
cylinder{<0,0,0><0,0.036000,0>0.101600 translate<18.085000,0.000000,11.450000>}
box{<0,0,-0.101600><0.649192,0.036000,0.101600> rotate<0,-77.992558,0> translate<17.950000,0.000000,10.815000> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.550800,0.000000,21.320800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.550800,0.000000,21.829234>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,90.000000,0> translate<0.550800,0.000000,21.829234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.550800,0.000000,21.829234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.805016,0.000000,21.829234>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<0.550800,0.000000,21.829234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.805016,0.000000,21.829234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.889756,0.000000,21.744494>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<0.805016,0.000000,21.829234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.889756,0.000000,21.744494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.889756,0.000000,21.659756>}
box{<0,0,-0.050800><0.084737,0.036000,0.050800> rotate<0,-90.000000,0> translate<0.889756,0.000000,21.659756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.889756,0.000000,21.659756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.805016,0.000000,21.575016>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<0.805016,0.000000,21.575016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.805016,0.000000,21.575016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.889756,0.000000,21.490278>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<0.805016,0.000000,21.575016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.889756,0.000000,21.490278>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.889756,0.000000,21.405538>}
box{<0,0,-0.050800><0.084741,0.036000,0.050800> rotate<0,-90.000000,0> translate<0.889756,0.000000,21.405538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.889756,0.000000,21.405538>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.805016,0.000000,21.320800>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<0.805016,0.000000,21.320800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.805016,0.000000,21.320800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.550800,0.000000,21.320800>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<0.550800,0.000000,21.320800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.550800,0.000000,21.575016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.805016,0.000000,21.575016>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<0.550800,0.000000,21.575016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.112109,0.000000,21.320800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.112109,0.000000,21.659756>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<1.112109,0.000000,21.659756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.112109,0.000000,21.659756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.281588,0.000000,21.829234>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,-44.997030,0> translate<1.112109,0.000000,21.659756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.281588,0.000000,21.829234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.451066,0.000000,21.659756>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<1.281588,0.000000,21.829234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.451066,0.000000,21.659756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.451066,0.000000,21.320800>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,-90.000000,0> translate<1.451066,0.000000,21.320800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.112109,0.000000,21.575016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.451066,0.000000,21.575016>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<1.112109,0.000000,21.575016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.842897,0.000000,21.320800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.842897,0.000000,21.829234>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,90.000000,0> translate<1.842897,0.000000,21.829234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.673419,0.000000,21.829234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.012375,0.000000,21.829234>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<1.673419,0.000000,21.829234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.450800,0.000000,19.229234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.450800,0.000000,18.890278>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,-90.000000,0> translate<0.450800,0.000000,18.890278> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.450800,0.000000,18.890278>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.620278,0.000000,18.720800>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<0.450800,0.000000,18.890278> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.620278,0.000000,18.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.789756,0.000000,18.890278>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,-44.997030,0> translate<0.620278,0.000000,18.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.789756,0.000000,18.890278>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.789756,0.000000,19.229234>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<0.789756,0.000000,19.229234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.351066,0.000000,19.144494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.266325,0.000000,19.229234>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<1.266325,0.000000,19.229234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.266325,0.000000,19.229234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.096847,0.000000,19.229234>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<1.096847,0.000000,19.229234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.096847,0.000000,19.229234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.012109,0.000000,19.144494>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<1.012109,0.000000,19.144494> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.012109,0.000000,19.144494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.012109,0.000000,18.805537>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,-90.000000,0> translate<1.012109,0.000000,18.805537> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.012109,0.000000,18.805537>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.096847,0.000000,18.720800>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,44.997030,0> translate<1.012109,0.000000,18.805537> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.096847,0.000000,18.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.266325,0.000000,18.720800>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<1.096847,0.000000,18.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.266325,0.000000,18.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.351066,0.000000,18.805537>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<1.266325,0.000000,18.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.912375,0.000000,19.144494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.827634,0.000000,19.229234>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<1.827634,0.000000,19.229234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.827634,0.000000,19.229234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.658156,0.000000,19.229234>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<1.658156,0.000000,19.229234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.658156,0.000000,19.229234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.573419,0.000000,19.144494>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<1.573419,0.000000,19.144494> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.573419,0.000000,19.144494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.573419,0.000000,18.805537>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,-90.000000,0> translate<1.573419,0.000000,18.805537> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.573419,0.000000,18.805537>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.658156,0.000000,18.720800>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,44.997030,0> translate<1.573419,0.000000,18.805537> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.658156,0.000000,18.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.827634,0.000000,18.720800>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<1.658156,0.000000,18.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.827634,0.000000,18.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.912375,0.000000,18.805537>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<1.827634,0.000000,18.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.689756,0.000000,16.644494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.605016,0.000000,16.729234>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<0.605016,0.000000,16.729234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.605016,0.000000,16.729234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.435538,0.000000,16.729234>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<0.435538,0.000000,16.729234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.435538,0.000000,16.729234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.350800,0.000000,16.644494>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<0.350800,0.000000,16.644494> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.350800,0.000000,16.644494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.350800,0.000000,16.305537>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,-90.000000,0> translate<0.350800,0.000000,16.305537> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.350800,0.000000,16.305537>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.435538,0.000000,16.220800>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,44.997030,0> translate<0.350800,0.000000,16.305537> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.435538,0.000000,16.220800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.605016,0.000000,16.220800>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<0.435538,0.000000,16.220800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.605016,0.000000,16.220800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.689756,0.000000,16.305537>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<0.605016,0.000000,16.220800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.689756,0.000000,16.305537>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.689756,0.000000,16.475016>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,90.000000,0> translate<0.689756,0.000000,16.475016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.689756,0.000000,16.475016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.520278,0.000000,16.475016>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<0.520278,0.000000,16.475016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.912109,0.000000,16.220800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.912109,0.000000,16.729234>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,90.000000,0> translate<0.912109,0.000000,16.729234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.912109,0.000000,16.729234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.251066,0.000000,16.220800>}
box{<0,0,-0.050800><0.611062,0.036000,0.050800> rotate<0,56.306216,0> translate<0.912109,0.000000,16.729234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.251066,0.000000,16.220800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.251066,0.000000,16.729234>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,90.000000,0> translate<1.251066,0.000000,16.729234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.473419,0.000000,16.729234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.473419,0.000000,16.220800>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,-90.000000,0> translate<1.473419,0.000000,16.220800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.473419,0.000000,16.220800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.727634,0.000000,16.220800>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<1.473419,0.000000,16.220800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.727634,0.000000,16.220800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.812375,0.000000,16.305537>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<1.727634,0.000000,16.220800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.812375,0.000000,16.305537>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.812375,0.000000,16.644494>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<1.812375,0.000000,16.644494> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.812375,0.000000,16.644494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.727634,0.000000,16.729234>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<1.727634,0.000000,16.729234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.727634,0.000000,16.729234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.473419,0.000000,16.729234>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<1.473419,0.000000,16.729234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.789756,0.000000,14.144494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.705016,0.000000,14.229234>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<0.705016,0.000000,14.229234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.705016,0.000000,14.229234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.535537,0.000000,14.229234>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<0.535537,0.000000,14.229234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.535537,0.000000,14.229234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.450800,0.000000,14.144494>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<0.450800,0.000000,14.144494> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.450800,0.000000,14.144494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.450800,0.000000,14.059756>}
box{<0,0,-0.050800><0.084737,0.036000,0.050800> rotate<0,-90.000000,0> translate<0.450800,0.000000,14.059756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.450800,0.000000,14.059756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.535537,0.000000,13.975016>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<0.450800,0.000000,14.059756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.535537,0.000000,13.975016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.705016,0.000000,13.975016>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<0.535537,0.000000,13.975016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.705016,0.000000,13.975016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.789756,0.000000,13.890278>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<0.705016,0.000000,13.975016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.789756,0.000000,13.890278>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.789756,0.000000,13.805537>}
box{<0,0,-0.050800><0.084741,0.036000,0.050800> rotate<0,-90.000000,0> translate<0.789756,0.000000,13.805537> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.789756,0.000000,13.805537>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.705016,0.000000,13.720800>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<0.705016,0.000000,13.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.705016,0.000000,13.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.535537,0.000000,13.720800>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<0.535537,0.000000,13.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.535537,0.000000,13.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.450800,0.000000,13.805537>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,44.997030,0> translate<0.450800,0.000000,13.805537> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.012109,0.000000,14.229234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.012109,0.000000,13.720800>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,-90.000000,0> translate<1.012109,0.000000,13.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.012109,0.000000,13.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.266325,0.000000,13.720800>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<1.012109,0.000000,13.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.266325,0.000000,13.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.351066,0.000000,13.805537>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<1.266325,0.000000,13.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.351066,0.000000,13.805537>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.351066,0.000000,14.144494>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<1.351066,0.000000,14.144494> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.351066,0.000000,14.144494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.266325,0.000000,14.229234>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<1.266325,0.000000,14.229234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.266325,0.000000,14.229234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.012109,0.000000,14.229234>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<1.012109,0.000000,14.229234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.573419,0.000000,13.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.573419,0.000000,14.059756>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<1.573419,0.000000,14.059756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.573419,0.000000,14.059756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.742897,0.000000,14.229234>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,-44.997030,0> translate<1.573419,0.000000,14.059756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.742897,0.000000,14.229234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.912375,0.000000,14.059756>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<1.742897,0.000000,14.229234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.912375,0.000000,14.059756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.912375,0.000000,13.720800>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,-90.000000,0> translate<1.912375,0.000000,13.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.573419,0.000000,13.975016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.912375,0.000000,13.975016>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<1.573419,0.000000,13.975016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.889756,0.000000,11.544494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.805016,0.000000,11.629234>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<0.805016,0.000000,11.629234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.805016,0.000000,11.629234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.635537,0.000000,11.629234>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<0.635537,0.000000,11.629234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.635537,0.000000,11.629234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.550800,0.000000,11.544494>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<0.550800,0.000000,11.544494> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.550800,0.000000,11.544494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.550800,0.000000,11.459756>}
box{<0,0,-0.050800><0.084738,0.036000,0.050800> rotate<0,-90.000000,0> translate<0.550800,0.000000,11.459756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.550800,0.000000,11.459756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.635537,0.000000,11.375016>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<0.550800,0.000000,11.459756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.635537,0.000000,11.375016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.805016,0.000000,11.375016>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<0.635537,0.000000,11.375016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.805016,0.000000,11.375016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.889756,0.000000,11.290278>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<0.805016,0.000000,11.375016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.889756,0.000000,11.290278>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.889756,0.000000,11.205538>}
box{<0,0,-0.050800><0.084741,0.036000,0.050800> rotate<0,-90.000000,0> translate<0.889756,0.000000,11.205538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.889756,0.000000,11.205538>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.805016,0.000000,11.120800>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<0.805016,0.000000,11.120800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.805016,0.000000,11.120800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.635537,0.000000,11.120800>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<0.635537,0.000000,11.120800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.635537,0.000000,11.120800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.550800,0.000000,11.205538>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,44.997030,0> translate<0.550800,0.000000,11.205538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.451066,0.000000,11.544494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.366325,0.000000,11.629234>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<1.366325,0.000000,11.629234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.366325,0.000000,11.629234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.196847,0.000000,11.629234>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<1.196847,0.000000,11.629234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.196847,0.000000,11.629234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.112109,0.000000,11.544494>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<1.112109,0.000000,11.544494> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.112109,0.000000,11.544494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.112109,0.000000,11.205538>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,-90.000000,0> translate<1.112109,0.000000,11.205538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.112109,0.000000,11.205538>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.196847,0.000000,11.120800>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,44.997030,0> translate<1.112109,0.000000,11.205538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.196847,0.000000,11.120800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.366325,0.000000,11.120800>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<1.196847,0.000000,11.120800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.366325,0.000000,11.120800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.451066,0.000000,11.205538>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<1.366325,0.000000,11.120800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.673419,0.000000,11.629234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.673419,0.000000,11.120800>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,-90.000000,0> translate<1.673419,0.000000,11.120800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.673419,0.000000,11.120800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.012375,0.000000,11.120800>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<1.673419,0.000000,11.120800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.350800,0.000000,9.129234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.350800,0.000000,8.620800>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,-90.000000,0> translate<0.350800,0.000000,8.620800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.350800,0.000000,8.620800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.689756,0.000000,8.620800>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<0.350800,0.000000,8.620800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.912109,0.000000,8.620800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.912109,0.000000,9.129234>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,90.000000,0> translate<0.912109,0.000000,9.129234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.912109,0.000000,9.129234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.166325,0.000000,9.129234>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<0.912109,0.000000,9.129234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.166325,0.000000,9.129234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.251066,0.000000,9.044494>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<1.166325,0.000000,9.129234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.251066,0.000000,9.044494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.251066,0.000000,8.875016>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<1.251066,0.000000,8.875016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.251066,0.000000,8.875016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.166325,0.000000,8.790278>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<1.166325,0.000000,8.790278> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.166325,0.000000,8.790278>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<0.912109,0.000000,8.790278>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<0.912109,0.000000,8.790278> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.473419,0.000000,9.129234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.473419,0.000000,8.620800>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,-90.000000,0> translate<1.473419,0.000000,8.620800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.473419,0.000000,8.620800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.642897,0.000000,8.790278>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,-44.997030,0> translate<1.473419,0.000000,8.620800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.642897,0.000000,8.790278>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.812375,0.000000,8.620800>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<1.642897,0.000000,8.790278> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.812375,0.000000,8.620800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<1.812375,0.000000,9.129234>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,90.000000,0> translate<1.812375,0.000000,9.129234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.330800,0.000000,21.320800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.330800,0.000000,21.829234>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,90.000000,0> translate<18.330800,0.000000,21.829234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.330800,0.000000,21.829234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.585016,0.000000,21.829234>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<18.330800,0.000000,21.829234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.585016,0.000000,21.829234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.669756,0.000000,21.744494>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<18.585016,0.000000,21.829234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.669756,0.000000,21.744494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.669756,0.000000,21.659756>}
box{<0,0,-0.050800><0.084737,0.036000,0.050800> rotate<0,-90.000000,0> translate<18.669756,0.000000,21.659756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.669756,0.000000,21.659756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.585016,0.000000,21.575016>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<18.585016,0.000000,21.575016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.585016,0.000000,21.575016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.669756,0.000000,21.490278>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<18.585016,0.000000,21.575016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.669756,0.000000,21.490278>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.669756,0.000000,21.405538>}
box{<0,0,-0.050800><0.084741,0.036000,0.050800> rotate<0,-90.000000,0> translate<18.669756,0.000000,21.405538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.669756,0.000000,21.405538>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.585016,0.000000,21.320800>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<18.585016,0.000000,21.320800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.585016,0.000000,21.320800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.330800,0.000000,21.320800>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<18.330800,0.000000,21.320800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.330800,0.000000,21.575016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.585016,0.000000,21.575016>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<18.330800,0.000000,21.575016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.892109,0.000000,21.320800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.892109,0.000000,21.659756>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<18.892109,0.000000,21.659756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.892109,0.000000,21.659756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.061588,0.000000,21.829234>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,-44.997030,0> translate<18.892109,0.000000,21.659756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.061588,0.000000,21.829234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.231066,0.000000,21.659756>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<19.061588,0.000000,21.829234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.231066,0.000000,21.659756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.231066,0.000000,21.320800>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,-90.000000,0> translate<19.231066,0.000000,21.320800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.892109,0.000000,21.575016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.231066,0.000000,21.575016>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<18.892109,0.000000,21.575016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.622897,0.000000,21.320800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.622897,0.000000,21.829234>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,90.000000,0> translate<19.622897,0.000000,21.829234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.453419,0.000000,21.829234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.792375,0.000000,21.829234>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<19.453419,0.000000,21.829234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.230800,0.000000,19.229234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.230800,0.000000,18.890278>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,-90.000000,0> translate<18.230800,0.000000,18.890278> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.230800,0.000000,18.890278>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.400278,0.000000,18.720800>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<18.230800,0.000000,18.890278> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.400278,0.000000,18.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.569756,0.000000,18.890278>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,-44.997030,0> translate<18.400278,0.000000,18.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.569756,0.000000,18.890278>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.569756,0.000000,19.229234>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<18.569756,0.000000,19.229234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.131066,0.000000,19.144494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.046325,0.000000,19.229234>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<19.046325,0.000000,19.229234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.046325,0.000000,19.229234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.876847,0.000000,19.229234>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<18.876847,0.000000,19.229234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.876847,0.000000,19.229234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.792109,0.000000,19.144494>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<18.792109,0.000000,19.144494> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.792109,0.000000,19.144494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.792109,0.000000,18.805537>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,-90.000000,0> translate<18.792109,0.000000,18.805537> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.792109,0.000000,18.805537>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.876847,0.000000,18.720800>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,44.997030,0> translate<18.792109,0.000000,18.805537> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.876847,0.000000,18.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.046325,0.000000,18.720800>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<18.876847,0.000000,18.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.046325,0.000000,18.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.131066,0.000000,18.805537>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<19.046325,0.000000,18.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.692375,0.000000,19.144494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.607634,0.000000,19.229234>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<19.607634,0.000000,19.229234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.607634,0.000000,19.229234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.438156,0.000000,19.229234>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<19.438156,0.000000,19.229234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.438156,0.000000,19.229234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.353419,0.000000,19.144494>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<19.353419,0.000000,19.144494> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.353419,0.000000,19.144494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.353419,0.000000,18.805537>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,-90.000000,0> translate<19.353419,0.000000,18.805537> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.353419,0.000000,18.805537>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.438156,0.000000,18.720800>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,44.997030,0> translate<19.353419,0.000000,18.805537> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.438156,0.000000,18.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.607634,0.000000,18.720800>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<19.438156,0.000000,18.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.607634,0.000000,18.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.692375,0.000000,18.805537>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<19.607634,0.000000,18.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.469756,0.000000,16.644494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.385016,0.000000,16.729234>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<18.385016,0.000000,16.729234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.385016,0.000000,16.729234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.215537,0.000000,16.729234>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<18.215537,0.000000,16.729234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.215537,0.000000,16.729234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.130800,0.000000,16.644494>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<18.130800,0.000000,16.644494> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.130800,0.000000,16.644494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.130800,0.000000,16.305537>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,-90.000000,0> translate<18.130800,0.000000,16.305537> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.130800,0.000000,16.305537>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.215537,0.000000,16.220800>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,44.997030,0> translate<18.130800,0.000000,16.305537> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.215537,0.000000,16.220800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.385016,0.000000,16.220800>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<18.215537,0.000000,16.220800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.385016,0.000000,16.220800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.469756,0.000000,16.305537>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<18.385016,0.000000,16.220800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.469756,0.000000,16.305537>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.469756,0.000000,16.475016>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,90.000000,0> translate<18.469756,0.000000,16.475016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.469756,0.000000,16.475016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.300278,0.000000,16.475016>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<18.300278,0.000000,16.475016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.692109,0.000000,16.220800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.692109,0.000000,16.729234>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,90.000000,0> translate<18.692109,0.000000,16.729234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.692109,0.000000,16.729234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.031066,0.000000,16.220800>}
box{<0,0,-0.050800><0.611062,0.036000,0.050800> rotate<0,56.306216,0> translate<18.692109,0.000000,16.729234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.031066,0.000000,16.220800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.031066,0.000000,16.729234>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,90.000000,0> translate<19.031066,0.000000,16.729234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.253419,0.000000,16.729234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.253419,0.000000,16.220800>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,-90.000000,0> translate<19.253419,0.000000,16.220800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.253419,0.000000,16.220800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.507634,0.000000,16.220800>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<19.253419,0.000000,16.220800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.507634,0.000000,16.220800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.592375,0.000000,16.305537>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<19.507634,0.000000,16.220800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.592375,0.000000,16.305537>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.592375,0.000000,16.644494>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<19.592375,0.000000,16.644494> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.592375,0.000000,16.644494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.507634,0.000000,16.729234>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<19.507634,0.000000,16.729234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.507634,0.000000,16.729234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.253419,0.000000,16.729234>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<19.253419,0.000000,16.729234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.569756,0.000000,14.144494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.485016,0.000000,14.229234>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<18.485016,0.000000,14.229234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.485016,0.000000,14.229234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.315538,0.000000,14.229234>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<18.315538,0.000000,14.229234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.315538,0.000000,14.229234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.230800,0.000000,14.144494>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<18.230800,0.000000,14.144494> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.230800,0.000000,14.144494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.230800,0.000000,14.059756>}
box{<0,0,-0.050800><0.084737,0.036000,0.050800> rotate<0,-90.000000,0> translate<18.230800,0.000000,14.059756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.230800,0.000000,14.059756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.315538,0.000000,13.975016>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<18.230800,0.000000,14.059756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.315538,0.000000,13.975016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.485016,0.000000,13.975016>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<18.315538,0.000000,13.975016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.485016,0.000000,13.975016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.569756,0.000000,13.890278>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<18.485016,0.000000,13.975016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.569756,0.000000,13.890278>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.569756,0.000000,13.805537>}
box{<0,0,-0.050800><0.084741,0.036000,0.050800> rotate<0,-90.000000,0> translate<18.569756,0.000000,13.805537> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.569756,0.000000,13.805537>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.485016,0.000000,13.720800>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<18.485016,0.000000,13.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.485016,0.000000,13.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.315538,0.000000,13.720800>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<18.315538,0.000000,13.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.315538,0.000000,13.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.230800,0.000000,13.805537>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,44.997030,0> translate<18.230800,0.000000,13.805537> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.792109,0.000000,14.229234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.792109,0.000000,13.720800>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,-90.000000,0> translate<18.792109,0.000000,13.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.792109,0.000000,13.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.046325,0.000000,13.720800>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<18.792109,0.000000,13.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.046325,0.000000,13.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.131066,0.000000,13.805537>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<19.046325,0.000000,13.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.131066,0.000000,13.805537>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.131066,0.000000,14.144494>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<19.131066,0.000000,14.144494> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.131066,0.000000,14.144494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.046325,0.000000,14.229234>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<19.046325,0.000000,14.229234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.046325,0.000000,14.229234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.792109,0.000000,14.229234>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<18.792109,0.000000,14.229234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.353419,0.000000,13.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.353419,0.000000,14.059756>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<19.353419,0.000000,14.059756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.353419,0.000000,14.059756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.522897,0.000000,14.229234>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,-44.997030,0> translate<19.353419,0.000000,14.059756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.522897,0.000000,14.229234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.692375,0.000000,14.059756>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<19.522897,0.000000,14.229234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.692375,0.000000,14.059756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.692375,0.000000,13.720800>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,-90.000000,0> translate<19.692375,0.000000,13.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.353419,0.000000,13.975016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.692375,0.000000,13.975016>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<19.353419,0.000000,13.975016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.669756,0.000000,11.544494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.585016,0.000000,11.629234>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<18.585016,0.000000,11.629234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.585016,0.000000,11.629234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.415537,0.000000,11.629234>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<18.415537,0.000000,11.629234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.415537,0.000000,11.629234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.330800,0.000000,11.544494>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<18.330800,0.000000,11.544494> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.330800,0.000000,11.544494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.330800,0.000000,11.459756>}
box{<0,0,-0.050800><0.084738,0.036000,0.050800> rotate<0,-90.000000,0> translate<18.330800,0.000000,11.459756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.330800,0.000000,11.459756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.415537,0.000000,11.375016>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<18.330800,0.000000,11.459756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.415537,0.000000,11.375016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.585016,0.000000,11.375016>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<18.415537,0.000000,11.375016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.585016,0.000000,11.375016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.669756,0.000000,11.290278>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<18.585016,0.000000,11.375016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.669756,0.000000,11.290278>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.669756,0.000000,11.205538>}
box{<0,0,-0.050800><0.084741,0.036000,0.050800> rotate<0,-90.000000,0> translate<18.669756,0.000000,11.205538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.669756,0.000000,11.205538>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.585016,0.000000,11.120800>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<18.585016,0.000000,11.120800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.585016,0.000000,11.120800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.415537,0.000000,11.120800>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<18.415537,0.000000,11.120800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.415537,0.000000,11.120800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.330800,0.000000,11.205538>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,44.997030,0> translate<18.330800,0.000000,11.205538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.231066,0.000000,11.544494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.146325,0.000000,11.629234>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<19.146325,0.000000,11.629234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.146325,0.000000,11.629234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.976847,0.000000,11.629234>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<18.976847,0.000000,11.629234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.976847,0.000000,11.629234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.892109,0.000000,11.544494>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<18.892109,0.000000,11.544494> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.892109,0.000000,11.544494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.892109,0.000000,11.205538>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,-90.000000,0> translate<18.892109,0.000000,11.205538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.892109,0.000000,11.205538>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.976847,0.000000,11.120800>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,44.997030,0> translate<18.892109,0.000000,11.205538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.976847,0.000000,11.120800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.146325,0.000000,11.120800>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<18.976847,0.000000,11.120800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.146325,0.000000,11.120800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.231066,0.000000,11.205538>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<19.146325,0.000000,11.120800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.453419,0.000000,11.629234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.453419,0.000000,11.120800>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,-90.000000,0> translate<19.453419,0.000000,11.120800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.453419,0.000000,11.120800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.792375,0.000000,11.120800>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<19.453419,0.000000,11.120800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.130800,0.000000,9.129234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.130800,0.000000,8.620800>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,-90.000000,0> translate<18.130800,0.000000,8.620800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.130800,0.000000,8.620800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.469756,0.000000,8.620800>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<18.130800,0.000000,8.620800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.692109,0.000000,8.620800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.692109,0.000000,9.129234>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,90.000000,0> translate<18.692109,0.000000,9.129234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.692109,0.000000,9.129234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.946325,0.000000,9.129234>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<18.692109,0.000000,9.129234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.946325,0.000000,9.129234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.031066,0.000000,9.044494>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<18.946325,0.000000,9.129234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.031066,0.000000,9.044494>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.031066,0.000000,8.875016>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<19.031066,0.000000,8.875016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.031066,0.000000,8.875016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.946325,0.000000,8.790278>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<18.946325,0.000000,8.790278> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.946325,0.000000,8.790278>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<18.692109,0.000000,8.790278>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,0.000000,0> translate<18.692109,0.000000,8.790278> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.253419,0.000000,9.129234>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.253419,0.000000,8.620800>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,-90.000000,0> translate<19.253419,0.000000,8.620800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.253419,0.000000,8.620800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.422897,0.000000,8.790278>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,-44.997030,0> translate<19.253419,0.000000,8.620800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.422897,0.000000,8.790278>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.592375,0.000000,8.620800>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<19.422897,0.000000,8.790278> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.592375,0.000000,8.620800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<19.592375,0.000000,9.129234>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,90.000000,0> translate<19.592375,0.000000,9.129234> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.018800,0.000000,19.341866>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.510366,0.000000,19.341866>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<2.510366,0.000000,19.341866> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.510366,0.000000,19.341866>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.510366,0.000000,19.596081>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,90.000000,0> translate<2.510366,0.000000,19.596081> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.510366,0.000000,19.596081>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.595106,0.000000,19.680822>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.510366,0.000000,19.596081> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.595106,0.000000,19.680822>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.679844,0.000000,19.680822>}
box{<0,0,-0.050800><0.084738,0.036000,0.050800> rotate<0,0.000000,0> translate<2.595106,0.000000,19.680822> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.679844,0.000000,19.680822>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.764584,0.000000,19.596081>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<2.679844,0.000000,19.680822> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.764584,0.000000,19.596081>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.849322,0.000000,19.680822>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<2.764584,0.000000,19.596081> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.849322,0.000000,19.680822>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.934063,0.000000,19.680822>}
box{<0,0,-0.050800><0.084741,0.036000,0.050800> rotate<0,0.000000,0> translate<2.849322,0.000000,19.680822> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.934063,0.000000,19.680822>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.018800,0.000000,19.596081>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<2.934063,0.000000,19.680822> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.018800,0.000000,19.596081>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.018800,0.000000,19.341866>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,-90.000000,0> translate<3.018800,0.000000,19.341866> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.764584,0.000000,19.341866>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.764584,0.000000,19.596081>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,90.000000,0> translate<2.764584,0.000000,19.596081> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.018800,0.000000,19.903175>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.679844,0.000000,19.903175>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<2.679844,0.000000,19.903175> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.679844,0.000000,19.903175>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.510366,0.000000,20.072653>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<2.510366,0.000000,20.072653> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.510366,0.000000,20.072653>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.679844,0.000000,20.242131>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.510366,0.000000,20.072653> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.679844,0.000000,20.242131>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.018800,0.000000,20.242131>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<2.679844,0.000000,20.242131> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.764584,0.000000,19.903175>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.764584,0.000000,20.242131>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<2.764584,0.000000,20.242131> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.018800,0.000000,20.633963>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.510366,0.000000,20.633963>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<2.510366,0.000000,20.633963> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.510366,0.000000,20.464484>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.510366,0.000000,20.803441>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<2.510366,0.000000,20.803441> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.550366,0.000000,16.936866>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.889322,0.000000,16.936866>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<2.550366,0.000000,16.936866> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.889322,0.000000,16.936866>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.058800,0.000000,17.106344>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.889322,0.000000,16.936866> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.058800,0.000000,17.106344>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.889322,0.000000,17.275822>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<2.889322,0.000000,17.275822> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.889322,0.000000,17.275822>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.550366,0.000000,17.275822>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<2.550366,0.000000,17.275822> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.635106,0.000000,17.837131>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.550366,0.000000,17.752391>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.550366,0.000000,17.752391> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.550366,0.000000,17.752391>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.550366,0.000000,17.582913>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<2.550366,0.000000,17.582913> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.550366,0.000000,17.582913>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.635106,0.000000,17.498175>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<2.550366,0.000000,17.582913> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.635106,0.000000,17.498175>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.974063,0.000000,17.498175>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<2.635106,0.000000,17.498175> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.974063,0.000000,17.498175>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.058800,0.000000,17.582913>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.974063,0.000000,17.498175> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.058800,0.000000,17.582913>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.058800,0.000000,17.752391>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,90.000000,0> translate<3.058800,0.000000,17.752391> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.058800,0.000000,17.752391>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.974063,0.000000,17.837131>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<2.974063,0.000000,17.837131> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.635106,0.000000,18.398441>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.550366,0.000000,18.313700>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.550366,0.000000,18.313700> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.550366,0.000000,18.313700>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.550366,0.000000,18.144222>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<2.550366,0.000000,18.144222> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.550366,0.000000,18.144222>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.635106,0.000000,18.059484>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<2.550366,0.000000,18.144222> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.635106,0.000000,18.059484>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.974063,0.000000,18.059484>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<2.635106,0.000000,18.059484> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.974063,0.000000,18.059484>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.058800,0.000000,18.144222>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.974063,0.000000,18.059484> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.058800,0.000000,18.144222>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.058800,0.000000,18.313700>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,90.000000,0> translate<3.058800,0.000000,18.313700> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.058800,0.000000,18.313700>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.974063,0.000000,18.398441>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<2.974063,0.000000,18.398441> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.625506,0.000000,14.559756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,14.475016>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.540766,0.000000,14.475016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,14.475016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,14.305538>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<2.540766,0.000000,14.305538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,14.305538>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.625506,0.000000,14.220800>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<2.540766,0.000000,14.305538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.625506,0.000000,14.220800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.964463,0.000000,14.220800>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<2.625506,0.000000,14.220800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.964463,0.000000,14.220800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,14.305538>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.964463,0.000000,14.220800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,14.305538>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,14.475016>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,90.000000,0> translate<3.049200,0.000000,14.475016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,14.475016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.964463,0.000000,14.559756>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<2.964463,0.000000,14.559756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.964463,0.000000,14.559756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.794984,0.000000,14.559756>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<2.794984,0.000000,14.559756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.794984,0.000000,14.559756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.794984,0.000000,14.390278>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<2.794984,0.000000,14.390278> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,14.782109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,14.782109>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<2.540766,0.000000,14.782109> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,14.782109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,15.121066>}
box{<0,0,-0.050800><0.611062,0.036000,0.050800> rotate<0,-33.687844,0> translate<2.540766,0.000000,14.782109> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,15.121066>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,15.121066>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<2.540766,0.000000,15.121066> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,15.343419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,15.343419>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<2.540766,0.000000,15.343419> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,15.343419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,15.597634>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,90.000000,0> translate<3.049200,0.000000,15.597634> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,15.597634>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.964463,0.000000,15.682375>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<2.964463,0.000000,15.682375> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.964463,0.000000,15.682375>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.625506,0.000000,15.682375>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<2.625506,0.000000,15.682375> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.625506,0.000000,15.682375>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,15.597634>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.540766,0.000000,15.597634> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,15.597634>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,15.343419>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,-90.000000,0> translate<2.540766,0.000000,15.343419> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.625506,0.000000,12.159756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,12.075016>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.540766,0.000000,12.075016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,12.075016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,11.905538>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<2.540766,0.000000,11.905538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,11.905538>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.625506,0.000000,11.820800>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<2.540766,0.000000,11.905538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.625506,0.000000,11.820800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.710244,0.000000,11.820800>}
box{<0,0,-0.050800><0.084738,0.036000,0.050800> rotate<0,0.000000,0> translate<2.625506,0.000000,11.820800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.710244,0.000000,11.820800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.794984,0.000000,11.905538>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<2.710244,0.000000,11.820800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.794984,0.000000,11.905538>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.794984,0.000000,12.075016>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,90.000000,0> translate<2.794984,0.000000,12.075016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.794984,0.000000,12.075016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.879722,0.000000,12.159756>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<2.794984,0.000000,12.075016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.879722,0.000000,12.159756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.964463,0.000000,12.159756>}
box{<0,0,-0.050800><0.084741,0.036000,0.050800> rotate<0,0.000000,0> translate<2.879722,0.000000,12.159756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.964463,0.000000,12.159756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,12.075016>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<2.964463,0.000000,12.159756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,12.075016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,11.905538>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<3.049200,0.000000,11.905538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,11.905538>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.964463,0.000000,11.820800>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.964463,0.000000,11.820800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,12.382109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,12.382109>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<2.540766,0.000000,12.382109> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,12.382109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,12.636325>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,90.000000,0> translate<3.049200,0.000000,12.636325> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,12.636325>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.964463,0.000000,12.721066>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<2.964463,0.000000,12.721066> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.964463,0.000000,12.721066>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.625506,0.000000,12.721066>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<2.625506,0.000000,12.721066> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.625506,0.000000,12.721066>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,12.636325>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.540766,0.000000,12.636325> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,12.636325>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,12.382109>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,-90.000000,0> translate<2.540766,0.000000,12.382109> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,12.943419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.710244,0.000000,12.943419>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<2.710244,0.000000,12.943419> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.710244,0.000000,12.943419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,13.112897>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<2.540766,0.000000,13.112897> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,13.112897>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.710244,0.000000,13.282375>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.540766,0.000000,13.112897> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.710244,0.000000,13.282375>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,13.282375>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<2.710244,0.000000,13.282375> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.794984,0.000000,12.943419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.794984,0.000000,13.282375>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<2.794984,0.000000,13.282375> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.605506,0.000000,9.719756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.520766,0.000000,9.635016>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.520766,0.000000,9.635016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.520766,0.000000,9.635016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.520766,0.000000,9.465537>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<2.520766,0.000000,9.465537> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.520766,0.000000,9.465537>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.605506,0.000000,9.380800>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<2.520766,0.000000,9.465537> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.605506,0.000000,9.380800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.690244,0.000000,9.380800>}
box{<0,0,-0.050800><0.084738,0.036000,0.050800> rotate<0,0.000000,0> translate<2.605506,0.000000,9.380800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.690244,0.000000,9.380800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.774984,0.000000,9.465537>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<2.690244,0.000000,9.380800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.774984,0.000000,9.465537>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.774984,0.000000,9.635016>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,90.000000,0> translate<2.774984,0.000000,9.635016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.774984,0.000000,9.635016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.859722,0.000000,9.719756>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<2.774984,0.000000,9.635016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.859722,0.000000,9.719756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.944463,0.000000,9.719756>}
box{<0,0,-0.050800><0.084741,0.036000,0.050800> rotate<0,0.000000,0> translate<2.859722,0.000000,9.719756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.944463,0.000000,9.719756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.029200,0.000000,9.635016>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<2.944463,0.000000,9.719756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.029200,0.000000,9.635016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.029200,0.000000,9.465537>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<3.029200,0.000000,9.465537> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.029200,0.000000,9.465537>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.944463,0.000000,9.380800>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.944463,0.000000,9.380800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.605506,0.000000,10.281066>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.520766,0.000000,10.196325>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.520766,0.000000,10.196325> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.520766,0.000000,10.196325>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.520766,0.000000,10.026847>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<2.520766,0.000000,10.026847> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.520766,0.000000,10.026847>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.605506,0.000000,9.942109>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<2.520766,0.000000,10.026847> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.605506,0.000000,9.942109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.944463,0.000000,9.942109>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<2.605506,0.000000,9.942109> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.944463,0.000000,9.942109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.029200,0.000000,10.026847>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.944463,0.000000,9.942109> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.029200,0.000000,10.026847>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.029200,0.000000,10.196325>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,90.000000,0> translate<3.029200,0.000000,10.196325> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.029200,0.000000,10.196325>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.944463,0.000000,10.281066>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<2.944463,0.000000,10.281066> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.520766,0.000000,10.503419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.029200,0.000000,10.503419>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<2.520766,0.000000,10.503419> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.029200,0.000000,10.503419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.029200,0.000000,10.842375>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<3.029200,0.000000,10.842375> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,6.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,6.720800>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<2.540766,0.000000,6.720800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,6.720800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,7.059756>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<3.049200,0.000000,7.059756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,7.282109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,7.282109>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<2.540766,0.000000,7.282109> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,7.282109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,7.536325>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,90.000000,0> translate<2.540766,0.000000,7.536325> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,7.536325>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.625506,0.000000,7.621066>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.540766,0.000000,7.536325> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.625506,0.000000,7.621066>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.794984,0.000000,7.621066>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<2.625506,0.000000,7.621066> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.794984,0.000000,7.621066>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.879722,0.000000,7.536325>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<2.794984,0.000000,7.621066> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.879722,0.000000,7.536325>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.879722,0.000000,7.282109>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,-90.000000,0> translate<2.879722,0.000000,7.282109> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,7.843419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,7.843419>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<2.540766,0.000000,7.843419> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,7.843419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.879722,0.000000,8.012897>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<2.879722,0.000000,8.012897> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.879722,0.000000,8.012897>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,8.182375>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.879722,0.000000,8.012897> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,8.182375>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,8.182375>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<2.540766,0.000000,8.182375> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.659200,0.000000,19.850800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.150766,0.000000,19.850800>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<17.150766,0.000000,19.850800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.150766,0.000000,19.850800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.150766,0.000000,20.105016>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,90.000000,0> translate<17.150766,0.000000,20.105016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.150766,0.000000,20.105016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.235506,0.000000,20.189756>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<17.150766,0.000000,20.105016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.235506,0.000000,20.189756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.320244,0.000000,20.189756>}
box{<0,0,-0.050800><0.084737,0.036000,0.050800> rotate<0,0.000000,0> translate<17.235506,0.000000,20.189756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.320244,0.000000,20.189756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.404984,0.000000,20.105016>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,44.997030,0> translate<17.320244,0.000000,20.189756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.404984,0.000000,20.105016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.489722,0.000000,20.189756>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<17.404984,0.000000,20.105016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.489722,0.000000,20.189756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.574462,0.000000,20.189756>}
box{<0,0,-0.050800><0.084741,0.036000,0.050800> rotate<0,0.000000,0> translate<17.489722,0.000000,20.189756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.574462,0.000000,20.189756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.659200,0.000000,20.105016>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<17.574462,0.000000,20.189756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.659200,0.000000,20.105016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.659200,0.000000,19.850800>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,-90.000000,0> translate<17.659200,0.000000,19.850800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.404984,0.000000,19.850800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.404984,0.000000,20.105016>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,90.000000,0> translate<17.404984,0.000000,20.105016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.659200,0.000000,20.412109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.320244,0.000000,20.412109>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<17.320244,0.000000,20.412109> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.320244,0.000000,20.412109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.150766,0.000000,20.581588>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<17.150766,0.000000,20.581588> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.150766,0.000000,20.581588>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.320244,0.000000,20.751066>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,-44.997030,0> translate<17.150766,0.000000,20.581588> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.320244,0.000000,20.751066>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.659200,0.000000,20.751066>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<17.320244,0.000000,20.751066> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.404984,0.000000,20.412109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.404984,0.000000,20.751066>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<17.404984,0.000000,20.751066> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.659200,0.000000,21.142897>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.150766,0.000000,21.142897>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<17.150766,0.000000,21.142897> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.150766,0.000000,20.973419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.150766,0.000000,21.312375>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<17.150766,0.000000,21.312375> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,16.930800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.549722,0.000000,16.930800>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<17.210766,0.000000,16.930800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.549722,0.000000,16.930800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,17.100278>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,-44.997030,0> translate<17.549722,0.000000,16.930800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,17.100278>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.549722,0.000000,17.269756>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<17.549722,0.000000,17.269756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.549722,0.000000,17.269756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,17.269756>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<17.210766,0.000000,17.269756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,17.831066>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,17.746325>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<17.210766,0.000000,17.746325> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,17.746325>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,17.576847>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<17.210766,0.000000,17.576847> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,17.576847>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,17.492109>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<17.210766,0.000000,17.576847> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,17.492109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,17.492109>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<17.295506,0.000000,17.492109> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,17.492109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,17.576847>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,-44.997030,0> translate<17.634463,0.000000,17.492109> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,17.576847>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,17.746325>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,90.000000,0> translate<17.719200,0.000000,17.746325> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,17.746325>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,17.831066>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<17.634463,0.000000,17.831066> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,18.392375>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,18.307634>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<17.210766,0.000000,18.307634> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,18.307634>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,18.138156>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<17.210766,0.000000,18.138156> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,18.138156>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,18.053419>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<17.210766,0.000000,18.138156> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,18.053419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,18.053419>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<17.295506,0.000000,18.053419> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,18.053419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,18.138156>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,-44.997030,0> translate<17.634463,0.000000,18.053419> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,18.138156>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,18.307634>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,90.000000,0> translate<17.719200,0.000000,18.307634> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,18.307634>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,18.392375>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<17.634463,0.000000,18.392375> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,14.769756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,14.685016>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<17.210766,0.000000,14.685016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,14.685016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,14.515538>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<17.210766,0.000000,14.515538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,14.515538>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,14.430800>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<17.210766,0.000000,14.515538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,14.430800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,14.430800>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<17.295506,0.000000,14.430800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,14.430800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,14.515538>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,-44.997030,0> translate<17.634463,0.000000,14.430800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,14.515538>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,14.685016>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,90.000000,0> translate<17.719200,0.000000,14.685016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,14.685016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,14.769756>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<17.634463,0.000000,14.769756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,14.769756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.464984,0.000000,14.769756>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<17.464984,0.000000,14.769756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.464984,0.000000,14.769756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.464984,0.000000,14.600278>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<17.464984,0.000000,14.600278> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,14.992109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,14.992109>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<17.210766,0.000000,14.992109> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,14.992109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,15.331066>}
box{<0,0,-0.050800><0.611062,0.036000,0.050800> rotate<0,-33.687844,0> translate<17.210766,0.000000,14.992109> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,15.331066>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,15.331066>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<17.210766,0.000000,15.331066> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,15.553419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,15.553419>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<17.210766,0.000000,15.553419> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,15.553419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,15.807634>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,90.000000,0> translate<17.719200,0.000000,15.807634> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,15.807634>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,15.892375>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<17.634463,0.000000,15.892375> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,15.892375>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,15.892375>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<17.295506,0.000000,15.892375> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,15.892375>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,15.807634>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<17.210766,0.000000,15.807634> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,15.807634>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,15.553419>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,-90.000000,0> translate<17.210766,0.000000,15.553419> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,12.269756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,12.185016>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<17.210766,0.000000,12.185016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,12.185016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,12.015538>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<17.210766,0.000000,12.015538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,12.015538>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,11.930800>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<17.210766,0.000000,12.015538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,11.930800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.380244,0.000000,11.930800>}
box{<0,0,-0.050800><0.084737,0.036000,0.050800> rotate<0,0.000000,0> translate<17.295506,0.000000,11.930800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.380244,0.000000,11.930800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.464984,0.000000,12.015538>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<17.380244,0.000000,11.930800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.464984,0.000000,12.015538>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.464984,0.000000,12.185016>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,90.000000,0> translate<17.464984,0.000000,12.185016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.464984,0.000000,12.185016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.549722,0.000000,12.269756>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<17.464984,0.000000,12.185016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.549722,0.000000,12.269756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,12.269756>}
box{<0,0,-0.050800><0.084741,0.036000,0.050800> rotate<0,0.000000,0> translate<17.549722,0.000000,12.269756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,12.269756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,12.185016>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<17.634463,0.000000,12.269756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,12.185016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,12.015538>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<17.719200,0.000000,12.015538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,12.015538>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,11.930800>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,-44.997030,0> translate<17.634463,0.000000,11.930800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,12.492109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,12.492109>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<17.210766,0.000000,12.492109> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,12.492109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,12.746325>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,90.000000,0> translate<17.719200,0.000000,12.746325> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,12.746325>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,12.831066>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<17.634463,0.000000,12.831066> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,12.831066>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,12.831066>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<17.295506,0.000000,12.831066> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,12.831066>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,12.746325>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<17.210766,0.000000,12.746325> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,12.746325>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,12.492109>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,-90.000000,0> translate<17.210766,0.000000,12.492109> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,13.053419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.380244,0.000000,13.053419>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<17.380244,0.000000,13.053419> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.380244,0.000000,13.053419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,13.222897>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<17.210766,0.000000,13.222897> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,13.222897>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.380244,0.000000,13.392375>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,-44.997030,0> translate<17.210766,0.000000,13.222897> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.380244,0.000000,13.392375>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,13.392375>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<17.380244,0.000000,13.392375> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.464984,0.000000,13.053419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.464984,0.000000,13.392375>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<17.464984,0.000000,13.392375> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,9.869756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,9.785016>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<17.210766,0.000000,9.785016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,9.785016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,9.615538>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<17.210766,0.000000,9.615538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,9.615538>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,9.530800>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<17.210766,0.000000,9.615538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,9.530800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.380244,0.000000,9.530800>}
box{<0,0,-0.050800><0.084737,0.036000,0.050800> rotate<0,0.000000,0> translate<17.295506,0.000000,9.530800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.380244,0.000000,9.530800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.464984,0.000000,9.615538>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.995974,0> translate<17.380244,0.000000,9.530800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.464984,0.000000,9.615538>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.464984,0.000000,9.785016>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,90.000000,0> translate<17.464984,0.000000,9.785016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.464984,0.000000,9.785016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.549722,0.000000,9.869756>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,-44.998087,0> translate<17.464984,0.000000,9.785016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.549722,0.000000,9.869756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,9.869756>}
box{<0,0,-0.050800><0.084741,0.036000,0.050800> rotate<0,0.000000,0> translate<17.549722,0.000000,9.869756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,9.869756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,9.785016>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<17.634463,0.000000,9.869756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,9.785016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,9.615538>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<17.719200,0.000000,9.615538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,9.615538>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,9.530800>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,-44.997030,0> translate<17.634463,0.000000,9.530800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,10.431066>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,10.346325>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<17.210766,0.000000,10.346325> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,10.346325>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,10.176847>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<17.210766,0.000000,10.176847> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,10.176847>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,10.092109>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<17.210766,0.000000,10.176847> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,10.092109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,10.092109>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<17.295506,0.000000,10.092109> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,10.092109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,10.176847>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,-44.997030,0> translate<17.634463,0.000000,10.092109> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,10.176847>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,10.346325>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,90.000000,0> translate<17.719200,0.000000,10.346325> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,10.346325>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.634463,0.000000,10.431066>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<17.634463,0.000000,10.431066> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,10.653419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,10.653419>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<17.210766,0.000000,10.653419> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,10.653419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,10.992375>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<17.719200,0.000000,10.992375> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,6.830800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,6.830800>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<17.210766,0.000000,6.830800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,6.830800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,7.169756>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,90.000000,0> translate<17.719200,0.000000,7.169756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,7.392109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,7.392109>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<17.210766,0.000000,7.392109> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,7.392109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,7.646325>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,90.000000,0> translate<17.210766,0.000000,7.646325> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,7.646325>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,7.731066>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<17.210766,0.000000,7.646325> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.295506,0.000000,7.731066>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.464984,0.000000,7.731066>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<17.295506,0.000000,7.731066> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.464984,0.000000,7.731066>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.549722,0.000000,7.646325>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<17.464984,0.000000,7.731066> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.549722,0.000000,7.646325>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.549722,0.000000,7.392109>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,-90.000000,0> translate<17.549722,0.000000,7.392109> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,7.953419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,7.953419>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<17.210766,0.000000,7.953419> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,7.953419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.549722,0.000000,8.122897>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,44.997030,0> translate<17.549722,0.000000,8.122897> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.549722,0.000000,8.122897>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,8.292375>}
box{<0,0,-0.050800><0.239678,0.036000,0.050800> rotate<0,-44.997030,0> translate<17.549722,0.000000,8.122897> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.719200,0.000000,8.292375>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<17.210766,0.000000,8.292375>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<17.210766,0.000000,8.292375> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.625506,0.000000,14.559756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,14.475016>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.540766,0.000000,14.475016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,14.475016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,14.305538>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<2.540766,0.000000,14.305538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,14.305538>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.625506,0.000000,14.220800>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.995974,0> translate<2.540766,0.000000,14.305538> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.625506,0.000000,14.220800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.964463,0.000000,14.220800>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<2.625506,0.000000,14.220800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.964463,0.000000,14.220800>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,14.305538>}
box{<0,0,-0.050800><0.119837,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.964463,0.000000,14.220800> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,14.305538>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,14.475016>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,90.000000,0> translate<3.049200,0.000000,14.475016> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,14.475016>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.964463,0.000000,14.559756>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<2.964463,0.000000,14.559756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.964463,0.000000,14.559756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.794984,0.000000,14.559756>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,0.000000,0> translate<2.794984,0.000000,14.559756> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.794984,0.000000,14.559756>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.794984,0.000000,14.390278>}
box{<0,0,-0.050800><0.169478,0.036000,0.050800> rotate<0,-90.000000,0> translate<2.794984,0.000000,14.390278> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,14.782109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,14.782109>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<2.540766,0.000000,14.782109> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,14.782109>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,15.121066>}
box{<0,0,-0.050800><0.611062,0.036000,0.050800> rotate<0,-33.687844,0> translate<2.540766,0.000000,14.782109> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,15.121066>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,15.121066>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<2.540766,0.000000,15.121066> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,15.343419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,15.343419>}
box{<0,0,-0.050800><0.508434,0.036000,0.050800> rotate<0,0.000000,0> translate<2.540766,0.000000,15.343419> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,15.343419>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,15.597634>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,90.000000,0> translate<3.049200,0.000000,15.597634> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<3.049200,0.000000,15.597634>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.964463,0.000000,15.682375>}
box{<0,0,-0.050800><0.119839,0.036000,0.050800> rotate<0,44.998087,0> translate<2.964463,0.000000,15.682375> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.964463,0.000000,15.682375>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.625506,0.000000,15.682375>}
box{<0,0,-0.050800><0.338956,0.036000,0.050800> rotate<0,0.000000,0> translate<2.625506,0.000000,15.682375> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.625506,0.000000,15.682375>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,15.597634>}
box{<0,0,-0.050800><0.119841,0.036000,0.050800> rotate<0,-44.997030,0> translate<2.540766,0.000000,15.597634> }
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,15.597634>}
cylinder{<0,0,0><0,0.036000,0>0.050800 translate<2.540766,0.000000,15.343419>}
box{<0,0,-0.050800><0.254216,0.036000,0.050800> rotate<0,-90.000000,0> translate<2.540766,0.000000,15.343419> }
//U$2 silk screen
difference{
cylinder{<8.586000,0,15.292000><8.586000,0.036000,15.292000>0.190500 translate<0,0.000000,0>}
cylinder{<8.586000,-0.1,15.292000><8.586000,0.135000,15.292000>0.063500 translate<0,0.000000,0>}}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<8.852700,0.000000,17.438625>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<8.852700,0.000000,17.120853>}
box{<0,0,-0.012700><0.317772,0.036000,0.012700> rotate<0,-90.000000,0> translate<8.852700,0.000000,17.120853> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<8.852700,0.000000,17.120853>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<8.916253,0.000000,17.057300>}
box{<0,0,-0.012700><0.089878,0.036000,0.012700> rotate<0,44.997030,0> translate<8.852700,0.000000,17.120853> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<8.916253,0.000000,17.057300>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.043363,0.000000,17.057300>}
box{<0,0,-0.012700><0.127109,0.036000,0.012700> rotate<0,0.000000,0> translate<8.916253,0.000000,17.057300> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.043363,0.000000,17.057300>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.106916,0.000000,17.120853>}
box{<0,0,-0.012700><0.089878,0.036000,0.012700> rotate<0,-44.997030,0> translate<9.043363,0.000000,17.057300> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.106916,0.000000,17.120853>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.106916,0.000000,17.438625>}
box{<0,0,-0.012700><0.317772,0.036000,0.012700> rotate<0,90.000000,0> translate<9.106916,0.000000,17.438625> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.226906,0.000000,17.438625>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.226906,0.000000,17.184406>}
box{<0,0,-0.012700><0.254219,0.036000,0.012700> rotate<0,-90.000000,0> translate<9.226906,0.000000,17.184406> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.226906,0.000000,17.184406>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.354012,0.000000,17.057300>}
box{<0,0,-0.012700><0.179755,0.036000,0.012700> rotate<0,44.997030,0> translate<9.226906,0.000000,17.184406> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.354012,0.000000,17.057300>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.481122,0.000000,17.184406>}
box{<0,0,-0.012700><0.179758,0.036000,0.012700> rotate<0,-44.996326,0> translate<9.354012,0.000000,17.057300> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.481122,0.000000,17.184406>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.481122,0.000000,17.438625>}
box{<0,0,-0.012700><0.254219,0.036000,0.012700> rotate<0,90.000000,0> translate<9.481122,0.000000,17.438625> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.229534,0.000000,17.184406>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.102425,0.000000,17.057300>}
box{<0,0,-0.012700><0.179758,0.036000,0.012700> rotate<0,-44.996326,0> translate<10.102425,0.000000,17.057300> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.102425,0.000000,17.057300>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.038872,0.000000,17.057300>}
box{<0,0,-0.012700><0.063553,0.036000,0.012700> rotate<0,0.000000,0> translate<10.038872,0.000000,17.057300> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.038872,0.000000,17.057300>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.975319,0.000000,17.120853>}
box{<0,0,-0.012700><0.089878,0.036000,0.012700> rotate<0,44.997030,0> translate<9.975319,0.000000,17.120853> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.975319,0.000000,17.120853>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.975319,0.000000,17.184406>}
box{<0,0,-0.012700><0.063553,0.036000,0.012700> rotate<0,90.000000,0> translate<9.975319,0.000000,17.184406> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.975319,0.000000,17.184406>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.102425,0.000000,17.311516>}
box{<0,0,-0.012700><0.179758,0.036000,0.012700> rotate<0,-44.997734,0> translate<9.975319,0.000000,17.184406> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.102425,0.000000,17.311516>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.102425,0.000000,17.375069>}
box{<0,0,-0.012700><0.063553,0.036000,0.012700> rotate<0,90.000000,0> translate<10.102425,0.000000,17.375069> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.102425,0.000000,17.375069>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.038872,0.000000,17.438625>}
box{<0,0,-0.012700><0.089880,0.036000,0.012700> rotate<0,44.998439,0> translate<10.038872,0.000000,17.438625> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.038872,0.000000,17.438625>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.975319,0.000000,17.375069>}
box{<0,0,-0.012700><0.089880,0.036000,0.012700> rotate<0,-44.998439,0> translate<9.975319,0.000000,17.375069> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.975319,0.000000,17.375069>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.975319,0.000000,17.311516>}
box{<0,0,-0.012700><0.063553,0.036000,0.012700> rotate<0,-90.000000,0> translate<9.975319,0.000000,17.311516> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.975319,0.000000,17.311516>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.229534,0.000000,17.057300>}
box{<0,0,-0.012700><0.359515,0.036000,0.012700> rotate<0,44.997030,0> translate<9.975319,0.000000,17.311516> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.723731,0.000000,17.438625>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.723731,0.000000,17.057300>}
box{<0,0,-0.012700><0.381325,0.036000,0.012700> rotate<0,-90.000000,0> translate<10.723731,0.000000,17.057300> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.723731,0.000000,17.057300>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.977947,0.000000,17.057300>}
box{<0,0,-0.012700><0.254216,0.036000,0.012700> rotate<0,0.000000,0> translate<10.723731,0.000000,17.057300> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.097938,0.000000,17.311516>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.161491,0.000000,17.311516>}
box{<0,0,-0.012700><0.063553,0.036000,0.012700> rotate<0,0.000000,0> translate<11.097938,0.000000,17.311516> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.161491,0.000000,17.311516>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.161491,0.000000,17.057300>}
box{<0,0,-0.012700><0.254216,0.036000,0.012700> rotate<0,-90.000000,0> translate<11.161491,0.000000,17.057300> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.097938,0.000000,17.057300>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.225044,0.000000,17.057300>}
box{<0,0,-0.012700><0.127106,0.036000,0.012700> rotate<0,0.000000,0> translate<11.097938,0.000000,17.057300> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.161491,0.000000,17.502178>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.161491,0.000000,17.438625>}
box{<0,0,-0.012700><0.063553,0.036000,0.012700> rotate<0,-90.000000,0> translate<11.161491,0.000000,17.438625> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.474516,0.000000,16.930194>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.538072,0.000000,16.930194>}
box{<0,0,-0.012700><0.063556,0.036000,0.012700> rotate<0,0.000000,0> translate<11.474516,0.000000,16.930194> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.538072,0.000000,16.930194>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.601625,0.000000,16.993747>}
box{<0,0,-0.012700><0.089878,0.036000,0.012700> rotate<0,-44.997030,0> translate<11.538072,0.000000,16.930194> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.601625,0.000000,16.993747>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.601625,0.000000,17.311516>}
box{<0,0,-0.012700><0.317769,0.036000,0.012700> rotate<0,90.000000,0> translate<11.601625,0.000000,17.311516> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.601625,0.000000,17.311516>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.410963,0.000000,17.311516>}
box{<0,0,-0.012700><0.190663,0.036000,0.012700> rotate<0,0.000000,0> translate<11.410963,0.000000,17.311516> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.410963,0.000000,17.311516>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.347409,0.000000,17.247962>}
box{<0,0,-0.012700><0.089878,0.036000,0.012700> rotate<0,-44.997030,0> translate<11.347409,0.000000,17.247962> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.347409,0.000000,17.247962>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.347409,0.000000,17.120853>}
box{<0,0,-0.012700><0.127109,0.036000,0.012700> rotate<0,-90.000000,0> translate<11.347409,0.000000,17.120853> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.347409,0.000000,17.120853>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.410963,0.000000,17.057300>}
box{<0,0,-0.012700><0.089878,0.036000,0.012700> rotate<0,44.997030,0> translate<11.347409,0.000000,17.120853> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.410963,0.000000,17.057300>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.601625,0.000000,17.057300>}
box{<0,0,-0.012700><0.190663,0.036000,0.012700> rotate<0,0.000000,0> translate<11.410963,0.000000,17.057300> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.721616,0.000000,17.438625>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.721616,0.000000,17.057300>}
box{<0,0,-0.012700><0.381325,0.036000,0.012700> rotate<0,-90.000000,0> translate<11.721616,0.000000,17.057300> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.721616,0.000000,17.247962>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.785169,0.000000,17.311516>}
box{<0,0,-0.012700><0.089878,0.036000,0.012700> rotate<0,-44.997030,0> translate<11.721616,0.000000,17.247962> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.785169,0.000000,17.311516>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.912278,0.000000,17.311516>}
box{<0,0,-0.012700><0.127109,0.036000,0.012700> rotate<0,0.000000,0> translate<11.785169,0.000000,17.311516> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.912278,0.000000,17.311516>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.975831,0.000000,17.247962>}
box{<0,0,-0.012700><0.089878,0.036000,0.012700> rotate<0,44.997030,0> translate<11.912278,0.000000,17.311516> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.975831,0.000000,17.247962>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.975831,0.000000,17.057300>}
box{<0,0,-0.012700><0.190662,0.036000,0.012700> rotate<0,-90.000000,0> translate<11.975831,0.000000,17.057300> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<12.159375,0.000000,17.375069>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<12.159375,0.000000,17.120853>}
box{<0,0,-0.012700><0.254216,0.036000,0.012700> rotate<0,-90.000000,0> translate<12.159375,0.000000,17.120853> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<12.159375,0.000000,17.120853>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<12.222928,0.000000,17.057300>}
box{<0,0,-0.012700><0.089878,0.036000,0.012700> rotate<0,44.997030,0> translate<12.159375,0.000000,17.120853> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<12.095822,0.000000,17.311516>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<12.222928,0.000000,17.311516>}
box{<0,0,-0.012700><0.127106,0.036000,0.012700> rotate<0,0.000000,0> translate<12.095822,0.000000,17.311516> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.481122,0.000000,16.765469>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.417569,0.000000,16.829025>}
box{<0,0,-0.012700><0.089880,0.036000,0.012700> rotate<0,44.998439,0> translate<9.417569,0.000000,16.829025> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.417569,0.000000,16.829025>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.290459,0.000000,16.829025>}
box{<0,0,-0.012700><0.127109,0.036000,0.012700> rotate<0,0.000000,0> translate<9.290459,0.000000,16.829025> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.290459,0.000000,16.829025>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.226906,0.000000,16.765469>}
box{<0,0,-0.012700><0.089880,0.036000,0.012700> rotate<0,-44.998439,0> translate<9.226906,0.000000,16.765469> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.226906,0.000000,16.765469>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.226906,0.000000,16.701916>}
box{<0,0,-0.012700><0.063553,0.036000,0.012700> rotate<0,-90.000000,0> translate<9.226906,0.000000,16.701916> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.226906,0.000000,16.701916>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.290459,0.000000,16.638362>}
box{<0,0,-0.012700><0.089878,0.036000,0.012700> rotate<0,44.997030,0> translate<9.226906,0.000000,16.701916> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.290459,0.000000,16.638362>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.417569,0.000000,16.638362>}
box{<0,0,-0.012700><0.127109,0.036000,0.012700> rotate<0,0.000000,0> translate<9.290459,0.000000,16.638362> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.417569,0.000000,16.638362>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.481122,0.000000,16.574806>}
box{<0,0,-0.012700><0.089880,0.036000,0.012700> rotate<0,44.998439,0> translate<9.417569,0.000000,16.638362> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.481122,0.000000,16.574806>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.481122,0.000000,16.511253>}
box{<0,0,-0.012700><0.063553,0.036000,0.012700> rotate<0,-90.000000,0> translate<9.481122,0.000000,16.511253> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.481122,0.000000,16.511253>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.417569,0.000000,16.447700>}
box{<0,0,-0.012700><0.089878,0.036000,0.012700> rotate<0,-44.997030,0> translate<9.417569,0.000000,16.447700> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.417569,0.000000,16.447700>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.290459,0.000000,16.447700>}
box{<0,0,-0.012700><0.127109,0.036000,0.012700> rotate<0,0.000000,0> translate<9.290459,0.000000,16.447700> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.290459,0.000000,16.447700>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.226906,0.000000,16.511253>}
box{<0,0,-0.012700><0.089878,0.036000,0.012700> rotate<0,44.997030,0> translate<9.226906,0.000000,16.511253> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.601113,0.000000,16.701916>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.664666,0.000000,16.701916>}
box{<0,0,-0.012700><0.063553,0.036000,0.012700> rotate<0,0.000000,0> translate<9.601113,0.000000,16.701916> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.664666,0.000000,16.701916>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.664666,0.000000,16.447700>}
box{<0,0,-0.012700><0.254216,0.036000,0.012700> rotate<0,-90.000000,0> translate<9.664666,0.000000,16.447700> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.601113,0.000000,16.447700>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.728219,0.000000,16.447700>}
box{<0,0,-0.012700><0.127106,0.036000,0.012700> rotate<0,0.000000,0> translate<9.601113,0.000000,16.447700> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.664666,0.000000,16.892578>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.664666,0.000000,16.829025>}
box{<0,0,-0.012700><0.063553,0.036000,0.012700> rotate<0,-90.000000,0> translate<9.664666,0.000000,16.829025> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.850584,0.000000,16.701916>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.977691,0.000000,16.829025>}
box{<0,0,-0.012700><0.179758,0.036000,0.012700> rotate<0,-44.997734,0> translate<9.850584,0.000000,16.701916> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.977691,0.000000,16.829025>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.977691,0.000000,16.447700>}
box{<0,0,-0.012700><0.381325,0.036000,0.012700> rotate<0,-90.000000,0> translate<9.977691,0.000000,16.447700> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<9.850584,0.000000,16.447700>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.104800,0.000000,16.447700>}
box{<0,0,-0.012700><0.254216,0.036000,0.012700> rotate<0,0.000000,0> translate<9.850584,0.000000,16.447700> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.224791,0.000000,16.701916>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.351897,0.000000,16.829025>}
box{<0,0,-0.012700><0.179758,0.036000,0.012700> rotate<0,-44.997734,0> translate<10.224791,0.000000,16.701916> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.351897,0.000000,16.829025>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.351897,0.000000,16.447700>}
box{<0,0,-0.012700><0.381325,0.036000,0.012700> rotate<0,-90.000000,0> translate<10.351897,0.000000,16.447700> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.224791,0.000000,16.447700>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.479006,0.000000,16.447700>}
box{<0,0,-0.012700><0.254216,0.036000,0.012700> rotate<0,0.000000,0> translate<10.224791,0.000000,16.447700> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.598997,0.000000,16.765469>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.662550,0.000000,16.829025>}
box{<0,0,-0.012700><0.089880,0.036000,0.012700> rotate<0,-44.998439,0> translate<10.598997,0.000000,16.765469> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.662550,0.000000,16.829025>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.789659,0.000000,16.829025>}
box{<0,0,-0.012700><0.127109,0.036000,0.012700> rotate<0,0.000000,0> translate<10.662550,0.000000,16.829025> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.789659,0.000000,16.829025>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.853212,0.000000,16.765469>}
box{<0,0,-0.012700><0.089880,0.036000,0.012700> rotate<0,44.998439,0> translate<10.789659,0.000000,16.829025> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.853212,0.000000,16.765469>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.853212,0.000000,16.701916>}
box{<0,0,-0.012700><0.063553,0.036000,0.012700> rotate<0,-90.000000,0> translate<10.853212,0.000000,16.701916> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.853212,0.000000,16.701916>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.789659,0.000000,16.638362>}
box{<0,0,-0.012700><0.089878,0.036000,0.012700> rotate<0,-44.997030,0> translate<10.789659,0.000000,16.638362> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.789659,0.000000,16.638362>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.726103,0.000000,16.638362>}
box{<0,0,-0.012700><0.063556,0.036000,0.012700> rotate<0,0.000000,0> translate<10.726103,0.000000,16.638362> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.789659,0.000000,16.638362>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.853212,0.000000,16.574806>}
box{<0,0,-0.012700><0.089880,0.036000,0.012700> rotate<0,44.998439,0> translate<10.789659,0.000000,16.638362> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.853212,0.000000,16.574806>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.853212,0.000000,16.511253>}
box{<0,0,-0.012700><0.063553,0.036000,0.012700> rotate<0,-90.000000,0> translate<10.853212,0.000000,16.511253> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.853212,0.000000,16.511253>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.789659,0.000000,16.447700>}
box{<0,0,-0.012700><0.089878,0.036000,0.012700> rotate<0,-44.997030,0> translate<10.789659,0.000000,16.447700> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.789659,0.000000,16.447700>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.662550,0.000000,16.447700>}
box{<0,0,-0.012700><0.127109,0.036000,0.012700> rotate<0,0.000000,0> translate<10.662550,0.000000,16.447700> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.662550,0.000000,16.447700>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.598997,0.000000,16.511253>}
box{<0,0,-0.012700><0.089878,0.036000,0.012700> rotate<0,44.997030,0> translate<10.598997,0.000000,16.511253> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.227419,0.000000,16.447700>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.973203,0.000000,16.447700>}
box{<0,0,-0.012700><0.254216,0.036000,0.012700> rotate<0,0.000000,0> translate<10.973203,0.000000,16.447700> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.973203,0.000000,16.447700>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.227419,0.000000,16.701916>}
box{<0,0,-0.012700><0.359515,0.036000,0.012700> rotate<0,-44.997030,0> translate<10.973203,0.000000,16.447700> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.227419,0.000000,16.701916>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.227419,0.000000,16.765469>}
box{<0,0,-0.012700><0.063553,0.036000,0.012700> rotate<0,90.000000,0> translate<11.227419,0.000000,16.765469> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.227419,0.000000,16.765469>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.163866,0.000000,16.829025>}
box{<0,0,-0.012700><0.089880,0.036000,0.012700> rotate<0,44.998439,0> translate<11.163866,0.000000,16.829025> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.163866,0.000000,16.829025>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.036756,0.000000,16.829025>}
box{<0,0,-0.012700><0.127109,0.036000,0.012700> rotate<0,0.000000,0> translate<11.036756,0.000000,16.829025> }
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<11.036756,0.000000,16.829025>}
cylinder{<0,0,0><0,0.036000,0>0.012700 translate<10.973203,0.000000,16.765469>}
box{<0,0,-0.012700><0.089880,0.036000,0.012700> rotate<0,-44.998439,0> translate<10.973203,0.000000,16.765469> }
//U$3 silk screen
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.476750,0.000000,19.789853>}
box{<-0.045000,0,-0.008994><0.045000,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.313100,0.000000,19.789853>}
box{<-0.035950,0,-0.008994><0.035950,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.336450,0.000000,19.789853>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.422800,0.000000,19.807841>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.935400,0.000000,19.807841>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.448000,0.000000,19.807841>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.825700,0.000000,19.807841>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.194400,0.000000,19.807841>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.832900,0.000000,19.807841>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.201600,0.000000,19.807841>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.912000,0.000000,19.807841>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.595500,0.000000,19.807841>}
box{<-0.152850,0,-0.008991><0.152850,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.467750,0.000000,19.807841>}
box{<-0.143900,0,-0.008991><0.143900,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.304100,0.000000,19.807841>}
box{<-0.107950,0,-0.008991><0.107950,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.753750,0.000000,19.807841>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.113500,0.000000,19.807841>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.572100,0.000000,19.807841>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.931800,0.000000,19.807841>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.336500,0.000000,19.807841>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.984000,0.000000,19.807841>}
box{<-0.422650,0,-0.008991><0.422650,0.036000,0.008991> rotate<0,-0.000000,0> translate<14.622450,0.000000,19.807841>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,19.825825>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.935400,0.000000,19.825825>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,19.825825>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,19.825825>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,19.825825>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.832900,0.000000,19.825825>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,19.825825>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.912000,0.000000,19.825825>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.595500,0.000000,19.825825>}
box{<-0.206850,0,-0.008994><0.206850,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.467750,0.000000,19.825825>}
box{<-0.188850,0,-0.008994><0.188850,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.313050,0.000000,19.825825>}
box{<-0.116950,0,-0.008994><0.116950,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.744750,0.000000,19.825825>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.113500,0.000000,19.825825>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.572100,0.000000,19.825825>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,19.825825>}
box{<-0.161850,0,-0.008994><0.161850,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.336450,0.000000,19.825825>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,19.825825>}
box{<-0.422650,0,-0.008994><0.422650,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.622450,0.000000,19.825825>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,19.843813>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.935400,0.000000,19.843813>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,19.843813>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,19.843813>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,19.843813>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.832900,0.000000,19.843813>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,19.843813>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.903000,0.000000,19.843813>}
box{<-0.143900,0,-0.008994><0.143900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.595500,0.000000,19.843813>}
box{<-0.242800,0,-0.008994><0.242800,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.467800,0.000000,19.843813>}
box{<-0.224800,0,-0.008994><0.224800,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.313100,0.000000,19.843813>}
box{<-0.116950,0,-0.008994><0.116950,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.744750,0.000000,19.843813>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.113500,0.000000,19.843813>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.572100,0.000000,19.843813>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,19.843813>}
box{<-0.188850,0,-0.008994><0.188850,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.345450,0.000000,19.843813>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,19.843813>}
box{<-0.422650,0,-0.008994><0.422650,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.622450,0.000000,19.843813>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.422800,0.000000,19.861800>}
box{<-0.152900,0,-0.008991><0.152900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.935400,0.000000,19.861800>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.448000,0.000000,19.861800>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.825700,0.000000,19.861800>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.194400,0.000000,19.861800>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.832900,0.000000,19.861800>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.201600,0.000000,19.861800>}
box{<-0.143900,0,-0.008991><0.143900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.912000,0.000000,19.861800>}
box{<-0.143900,0,-0.008991><0.143900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.595500,0.000000,19.861800>}
box{<-0.269800,0,-0.008991><0.269800,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.458800,0.000000,19.861800>}
box{<-0.242800,0,-0.008991><0.242800,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.313100,0.000000,19.861800>}
box{<-0.116950,0,-0.008991><0.116950,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.744750,0.000000,19.861800>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.113500,0.000000,19.861800>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.572100,0.000000,19.861800>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.931800,0.000000,19.861800>}
box{<-0.224850,0,-0.008991><0.224850,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.345450,0.000000,19.861800>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.984000,0.000000,19.861800>}
box{<-0.422650,0,-0.008991><0.422650,0.036000,0.008991> rotate<0,-0.000000,0> translate<14.622450,0.000000,19.861800>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,19.879784>}
box{<-0.152900,0,-0.008994><0.152900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.935400,0.000000,19.879784>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,19.879784>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,19.879784>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,19.879784>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.832900,0.000000,19.879784>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,19.879784>}
box{<-0.143900,0,-0.008994><0.143900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.912000,0.000000,19.879784>}
box{<-0.143900,0,-0.008994><0.143900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.595500,0.000000,19.879784>}
box{<-0.296750,0,-0.008994><0.296750,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.467750,0.000000,19.879784>}
box{<-0.260800,0,-0.008994><0.260800,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.313100,0.000000,19.879784>}
box{<-0.116950,0,-0.008994><0.116950,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.744750,0.000000,19.879784>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.113500,0.000000,19.879784>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.572100,0.000000,19.879784>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,19.879784>}
box{<-0.242800,0,-0.008994><0.242800,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.345500,0.000000,19.879784>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,19.879784>}
box{<-0.422650,0,-0.008994><0.422650,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.622450,0.000000,19.879784>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.422800,0.000000,19.897769>}
box{<-0.152900,0,-0.008988><0.152900,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.935400,0.000000,19.897769>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.448000,0.000000,19.897769>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.825700,0.000000,19.897769>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<7.194400,0.000000,19.897769>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<7.832900,0.000000,19.897769>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.201600,0.000000,19.897769>}
box{<-0.143900,0,-0.008988><0.143900,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.912000,0.000000,19.897769>}
box{<-0.152850,0,-0.008988><0.152850,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.604450,0.000000,19.897769>}
box{<-0.323750,0,-0.008988><0.323750,0.036000,0.008988> rotate<0,-0.000000,0> translate<10.458750,0.000000,19.897769>}
box{<-0.278800,0,-0.008988><0.278800,0.036000,0.008988> rotate<0,-0.000000,0> translate<11.313100,0.000000,19.897769>}
box{<-0.116950,0,-0.008988><0.116950,0.036000,0.008988> rotate<0,-0.000000,0> translate<11.744750,0.000000,19.897769>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.113500,0.000000,19.897769>}
box{<-0.134900,0,-0.008988><0.134900,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.572100,0.000000,19.897769>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.931800,0.000000,19.897769>}
box{<-0.251800,0,-0.008988><0.251800,0.036000,0.008988> rotate<0,-0.000000,0> translate<13.354500,0.000000,19.897769>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<13.984000,0.000000,19.897769>}
box{<-0.422650,0,-0.008988><0.422650,0.036000,0.008988> rotate<0,-0.000000,0> translate<14.622450,0.000000,19.897769>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,19.915753>}
box{<-0.170900,0,-0.008994><0.170900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.935400,0.000000,19.915753>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,19.915753>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,19.915753>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,19.915753>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.832900,0.000000,19.915753>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,19.915753>}
box{<-0.152900,0,-0.008994><0.152900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.903000,0.000000,19.915753>}
box{<-0.161850,0,-0.008994><0.161850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.595450,0.000000,19.915753>}
box{<-0.341700,0,-0.008994><0.341700,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.458800,0.000000,19.915753>}
box{<-0.413700,0,-0.008994><0.413700,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.448000,0.000000,19.915753>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.113500,0.000000,19.915753>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.572100,0.000000,19.915753>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,19.915753>}
box{<-0.269750,0,-0.008994><0.269750,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.354450,0.000000,19.915753>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,19.915753>}
box{<-0.422650,0,-0.008994><0.422650,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.622450,0.000000,19.915753>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.422800,0.000000,19.933741>}
box{<-0.170900,0,-0.008991><0.170900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.935400,0.000000,19.933741>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.448000,0.000000,19.933741>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.825700,0.000000,19.933741>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.194400,0.000000,19.933741>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.832900,0.000000,19.933741>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.201600,0.000000,19.933741>}
box{<-0.161900,0,-0.008991><0.161900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.912000,0.000000,19.933741>}
box{<-0.161850,0,-0.008991><0.161850,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.595450,0.000000,19.933741>}
box{<-0.359700,0,-0.008991><0.359700,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.458800,0.000000,19.933741>}
box{<-0.422700,0,-0.008991><0.422700,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.439000,0.000000,19.933741>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.113500,0.000000,19.933741>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.572100,0.000000,19.933741>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.931800,0.000000,19.933741>}
box{<-0.287750,0,-0.008991><0.287750,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.354450,0.000000,19.933741>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.984000,0.000000,19.933741>}
box{<-0.422650,0,-0.008991><0.422650,0.036000,0.008991> rotate<0,-0.000000,0> translate<14.622450,0.000000,19.933741>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,19.951725>}
box{<-0.170900,0,-0.008994><0.170900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.935400,0.000000,19.951725>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,19.951725>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,19.951725>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,19.951725>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.832900,0.000000,19.951725>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,19.951725>}
box{<-0.161900,0,-0.008994><0.161900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.912000,0.000000,19.951725>}
box{<-0.161850,0,-0.008994><0.161850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.595450,0.000000,19.951725>}
box{<-0.368700,0,-0.008994><0.368700,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.467800,0.000000,19.951725>}
box{<-0.422700,0,-0.008994><0.422700,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.439000,0.000000,19.951725>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.113500,0.000000,19.951725>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.572100,0.000000,19.951725>}
box{<-0.422650,0,-0.008994><0.422650,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.237550,0.000000,19.951725>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,19.951725>}
box{<-0.422650,0,-0.008994><0.422650,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.622450,0.000000,19.951725>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,19.969712>}
box{<-0.170900,0,-0.008994><0.170900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.935400,0.000000,19.969712>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,19.969712>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,19.969712>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,19.969712>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.832900,0.000000,19.969712>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,19.969712>}
box{<-0.170850,0,-0.008994><0.170850,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.903050,0.000000,19.969712>}
box{<-0.170850,0,-0.008994><0.170850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.604450,0.000000,19.969712>}
box{<-0.377700,0,-0.008994><0.377700,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.458800,0.000000,19.969712>}
box{<-0.431700,0,-0.008994><0.431700,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.430000,0.000000,19.969712>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.113500,0.000000,19.969712>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.572100,0.000000,19.969712>}
box{<-0.422650,0,-0.008994><0.422650,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.237550,0.000000,19.969712>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,19.969712>}
box{<-0.422650,0,-0.008994><0.422650,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.622450,0.000000,19.969712>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.422800,0.000000,19.987700>}
box{<-0.188850,0,-0.008991><0.188850,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.935350,0.000000,19.987700>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.448000,0.000000,19.987700>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.825700,0.000000,19.987700>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.194400,0.000000,19.987700>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.832900,0.000000,19.987700>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.201600,0.000000,19.987700>}
box{<-0.170850,0,-0.008991><0.170850,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.903050,0.000000,19.987700>}
box{<-0.179850,0,-0.008991><0.179850,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.595450,0.000000,19.987700>}
box{<-0.395700,0,-0.008991><0.395700,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.458800,0.000000,19.987700>}
box{<-0.143900,0,-0.008991><0.143900,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.142200,0.000000,19.987700>}
box{<-0.197850,0,-0.008991><0.197850,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.663850,0.000000,19.987700>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.113500,0.000000,19.987700>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.572100,0.000000,19.987700>}
box{<-0.431650,0,-0.008991><0.431650,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.246550,0.000000,19.987700>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.984000,0.000000,19.987700>}
box{<-0.422650,0,-0.008991><0.422650,0.036000,0.008991> rotate<0,-0.000000,0> translate<14.622450,0.000000,19.987700>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.005684>}
box{<-0.188850,0,-0.008994><0.188850,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.935350,0.000000,20.005684>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.005684>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.005684>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.005684>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.005684>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.005684>}
box{<-0.179850,0,-0.008994><0.179850,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.912050,0.000000,20.005684>}
box{<-0.179850,0,-0.008994><0.179850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.595450,0.000000,20.005684>}
box{<-0.152850,0,-0.008994><0.152850,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.215950,0.000000,20.005684>}
box{<-0.152850,0,-0.008994><0.152850,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.719550,0.000000,20.005684>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.133200,0.000000,20.005684>}
box{<-0.179900,0,-0.008994><0.179900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.681800,0.000000,20.005684>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.005684>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.572100,0.000000,20.005684>}
box{<-0.188850,0,-0.008994><0.188850,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.003750,0.000000,20.005684>}
box{<-0.170850,0,-0.008994><0.170850,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.525350,0.000000,20.005684>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.005684>}
box{<-0.413650,0,-0.008994><0.413650,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.631450,0.000000,20.005684>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.023669>}
box{<-0.188850,0,-0.008988><0.188850,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.935350,0.000000,20.023669>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.023669>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.023669>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.023669>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.023669>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.023669>}
box{<-0.179850,0,-0.008988><0.179850,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.912050,0.000000,20.023669>}
box{<-0.188850,0,-0.008988><0.188850,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.604450,0.000000,20.023669>}
box{<-0.143900,0,-0.008988><0.143900,0.036000,0.008988> rotate<0,-0.000000,0> translate<10.189000,0.000000,20.023669>}
box{<-0.134850,0,-0.008988><0.134850,0.036000,0.008988> rotate<0,-0.000000,0> translate<10.737550,0.000000,20.023669>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<11.124200,0.000000,20.023669>}
box{<-0.161900,0,-0.008988><0.161900,0.036000,0.008988> rotate<0,-0.000000,0> translate<11.699800,0.000000,20.023669>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.023669>}
box{<-0.134900,0,-0.008988><0.134900,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.572100,0.000000,20.023669>}
box{<-0.170850,0,-0.008988><0.170850,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.985750,0.000000,20.023669>}
box{<-0.152900,0,-0.008988><0.152900,0.036000,0.008988> rotate<0,-0.000000,0> translate<13.543300,0.000000,20.023669>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.023669>}
box{<-0.143850,0,-0.008988><0.143850,0.036000,0.008988> rotate<0,-0.000000,0> translate<14.379650,0.000000,20.023669>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.041653>}
box{<-0.188850,0,-0.008994><0.188850,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.935350,0.000000,20.041653>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.041653>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.041653>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.041653>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.041653>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.041653>}
box{<-0.188850,0,-0.008994><0.188850,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.903050,0.000000,20.041653>}
box{<-0.188850,0,-0.008994><0.188850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.604450,0.000000,20.041653>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.180000,0.000000,20.041653>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.755500,0.000000,20.041653>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.124200,0.000000,20.041653>}
box{<-0.152900,0,-0.008994><0.152900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.708800,0.000000,20.041653>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.041653>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.572100,0.000000,20.041653>}
box{<-0.161850,0,-0.008994><0.161850,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.976750,0.000000,20.041653>}
box{<-0.152900,0,-0.008994><0.152900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.561300,0.000000,20.041653>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.041653>}
box{<-0.143900,0,-0.008994><0.143900,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.397600,0.000000,20.041653>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.059641>}
box{<-0.206800,0,-0.008991><0.206800,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.935400,0.000000,20.059641>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.059641>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.059641>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.059641>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.059641>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.059641>}
box{<-0.188850,0,-0.008991><0.188850,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.903050,0.000000,20.059641>}
box{<-0.197850,0,-0.008991><0.197850,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.595450,0.000000,20.059641>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.162000,0.000000,20.059641>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.764500,0.000000,20.059641>}
box{<-0.116950,0,-0.008991><0.116950,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.115250,0.000000,20.059641>}
box{<-0.143900,0,-0.008991><0.143900,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.717800,0.000000,20.059641>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.059641>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.572100,0.000000,20.059641>}
box{<-0.152850,0,-0.008991><0.152850,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.967750,0.000000,20.059641>}
box{<-0.143900,0,-0.008991><0.143900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.570300,0.000000,20.059641>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.059641>}
box{<-0.143900,0,-0.008991><0.143900,0.036000,0.008991> rotate<0,-0.000000,0> translate<14.415600,0.000000,20.059641>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.077625>}
box{<-0.206800,0,-0.008994><0.206800,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.935400,0.000000,20.077625>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.077625>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.077625>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.077625>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.077625>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.077625>}
box{<-0.197850,0,-0.008994><0.197850,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.912050,0.000000,20.077625>}
box{<-0.197850,0,-0.008994><0.197850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.595450,0.000000,20.077625>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.153000,0.000000,20.077625>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.764500,0.000000,20.077625>}
box{<-0.116950,0,-0.008994><0.116950,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.115250,0.000000,20.077625>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.726800,0.000000,20.077625>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.077625>}
box{<-0.143900,0,-0.008994><0.143900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.958800,0.000000,20.077625>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.579300,0.000000,20.077625>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.077625>}
box{<-0.152900,0,-0.008994><0.152900,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.424600,0.000000,20.077625>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.095609>}
box{<-0.206800,0,-0.008991><0.206800,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.935400,0.000000,20.095609>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.095609>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.095609>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.095609>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.095609>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.095609>}
box{<-0.206850,0,-0.008991><0.206850,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.903050,0.000000,20.095609>}
box{<-0.206850,0,-0.008991><0.206850,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.604450,0.000000,20.095609>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.153000,0.000000,20.095609>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.782500,0.000000,20.095609>}
box{<-0.116950,0,-0.008991><0.116950,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.115250,0.000000,20.095609>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.726800,0.000000,20.095609>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.095609>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.949800,0.000000,20.095609>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.597300,0.000000,20.095609>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.095609>}
box{<-0.152900,0,-0.008991><0.152900,0.036000,0.008991> rotate<0,-0.000000,0> translate<14.442600,0.000000,20.095609>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.113594>}
box{<-0.224800,0,-0.008994><0.224800,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.935400,0.000000,20.113594>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.113594>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.113594>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.113594>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.113594>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.113594>}
box{<-0.206850,0,-0.008994><0.206850,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.903050,0.000000,20.113594>}
box{<-0.206850,0,-0.008994><0.206850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.604450,0.000000,20.113594>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.135000,0.000000,20.113594>}
box{<-0.116950,0,-0.008994><0.116950,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.115250,0.000000,20.113594>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.735800,0.000000,20.113594>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.113594>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.949800,0.000000,20.113594>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.597300,0.000000,20.113594>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.113594>}
box{<-0.152900,0,-0.008994><0.152900,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.460600,0.000000,20.113594>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.131584>}
box{<-0.224800,0,-0.008994><0.224800,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.935400,0.000000,20.131584>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.131584>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.131584>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.131584>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.131584>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.131584>}
box{<-0.206850,0,-0.008994><0.206850,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.903050,0.000000,20.131584>}
box{<-0.206850,0,-0.008994><0.206850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.604450,0.000000,20.131584>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.135000,0.000000,20.131584>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.124200,0.000000,20.131584>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.735800,0.000000,20.131584>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.131584>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.940800,0.000000,20.131584>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.606300,0.000000,20.131584>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.131584>}
box{<-0.143900,0,-0.008994><0.143900,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.469600,0.000000,20.131584>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.149569>}
box{<-0.107900,0,-0.008988><0.107900,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.818500,0.000000,20.149569>}
box{<-0.107900,0,-0.008988><0.107900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.052300,0.000000,20.149569>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.149569>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.149569>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.149569>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.149569>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.149569>}
box{<-0.215800,0,-0.008988><0.215800,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.912000,0.000000,20.149569>}
box{<-0.224850,0,-0.008988><0.224850,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.604450,0.000000,20.149569>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<10.135000,0.000000,20.149569>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<11.124200,0.000000,20.149569>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<11.735800,0.000000,20.149569>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.149569>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.940800,0.000000,20.149569>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<13.606300,0.000000,20.149569>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.149569>}
box{<-0.143850,0,-0.008988><0.143850,0.036000,0.008988> rotate<0,-0.000000,0> translate<14.487550,0.000000,20.149569>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.167553>}
box{<-0.107900,0,-0.008994><0.107900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.818500,0.000000,20.167553>}
box{<-0.098900,0,-0.008994><0.098900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.061300,0.000000,20.167553>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.167553>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.167553>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.167553>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.167553>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.167553>}
box{<-0.224800,0,-0.008994><0.224800,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.903000,0.000000,20.167553>}
box{<-0.224850,0,-0.008994><0.224850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.604450,0.000000,20.167553>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.126000,0.000000,20.167553>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.133200,0.000000,20.167553>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.735800,0.000000,20.167553>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.167553>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.940800,0.000000,20.167553>}
box{<-0.134850,0,-0.008994><0.134850,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.615250,0.000000,20.167553>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.167553>}
box{<-0.143850,0,-0.008994><0.143850,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.505550,0.000000,20.167553>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.185541>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.809500,0.000000,20.185541>}
box{<-0.107900,0,-0.008991><0.107900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.070300,0.000000,20.185541>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.185541>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.185541>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.185541>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.185541>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.185541>}
box{<-0.224800,0,-0.008991><0.224800,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.903000,0.000000,20.185541>}
box{<-0.224850,0,-0.008991><0.224850,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.604450,0.000000,20.185541>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.126000,0.000000,20.185541>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.142200,0.000000,20.185541>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.735800,0.000000,20.185541>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.185541>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.185541>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.624200,0.000000,20.185541>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.185541>}
box{<-0.143900,0,-0.008991><0.143900,0.036000,0.008991> rotate<0,-0.000000,0> translate<14.523500,0.000000,20.185541>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.203525>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.809500,0.000000,20.203525>}
box{<-0.107900,0,-0.008994><0.107900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.070300,0.000000,20.203525>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.203525>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.203525>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.203525>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.203525>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.203525>}
box{<-0.224800,0,-0.008994><0.224800,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.903000,0.000000,20.203525>}
box{<-0.224850,0,-0.008994><0.224850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.604450,0.000000,20.203525>}
box{<-0.125850,0,-0.008994><0.125850,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.117050,0.000000,20.203525>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.151200,0.000000,20.203525>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.735800,0.000000,20.203525>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.203525>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.203525>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.624200,0.000000,20.203525>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.203525>}
box{<-0.143900,0,-0.008994><0.143900,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.541500,0.000000,20.203525>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.221509>}
box{<-0.107900,0,-0.008991><0.107900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.800500,0.000000,20.221509>}
box{<-0.107900,0,-0.008991><0.107900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.070300,0.000000,20.221509>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.221509>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.221509>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.221509>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.221509>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.221509>}
box{<-0.233800,0,-0.008991><0.233800,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.894000,0.000000,20.221509>}
box{<-0.242800,0,-0.008991><0.242800,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.604500,0.000000,20.221509>}
box{<-0.125850,0,-0.008991><0.125850,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.117050,0.000000,20.221509>}
box{<-0.143900,0,-0.008991><0.143900,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.178200,0.000000,20.221509>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.735800,0.000000,20.221509>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.221509>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.221509>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.624200,0.000000,20.221509>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.221509>}
box{<-0.152900,0,-0.008991><0.152900,0.036000,0.008991> rotate<0,-0.000000,0> translate<14.550500,0.000000,20.221509>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.239494>}
box{<-0.107900,0,-0.008994><0.107900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.800500,0.000000,20.239494>}
box{<-0.107900,0,-0.008994><0.107900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.070300,0.000000,20.239494>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.239494>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.239494>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.239494>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.239494>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.239494>}
box{<-0.242800,0,-0.008994><0.242800,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.903000,0.000000,20.239494>}
box{<-0.242800,0,-0.008994><0.242800,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.604500,0.000000,20.239494>}
box{<-0.467600,0,-0.008994><0.467600,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.458800,0.000000,20.239494>}
box{<-0.161850,0,-0.008994><0.161850,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.214150,0.000000,20.239494>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.735800,0.000000,20.239494>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.239494>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.239494>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.624200,0.000000,20.239494>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.239494>}
box{<-0.152900,0,-0.008994><0.152900,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.568500,0.000000,20.239494>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.257478>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.791500,0.000000,20.257478>}
box{<-0.107900,0,-0.008988><0.107900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.088300,0.000000,20.257478>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.257478>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.257478>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.257478>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.257478>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.257478>}
box{<-0.242800,0,-0.008988><0.242800,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.903000,0.000000,20.257478>}
box{<-0.242800,0,-0.008988><0.242800,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.604500,0.000000,20.257478>}
box{<-0.467600,0,-0.008988><0.467600,0.036000,0.008988> rotate<0,-0.000000,0> translate<10.458800,0.000000,20.257478>}
box{<-0.206850,0,-0.008988><0.206850,0.036000,0.008988> rotate<0,-0.000000,0> translate<11.259150,0.000000,20.257478>}
box{<-0.116950,0,-0.008988><0.116950,0.036000,0.008988> rotate<0,-0.000000,0> translate<11.744750,0.000000,20.257478>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.257478>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.257478>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<13.624200,0.000000,20.257478>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.257478>}
box{<-0.152900,0,-0.008988><0.152900,0.036000,0.008988> rotate<0,-0.000000,0> translate<14.586500,0.000000,20.257478>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.275462>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.791500,0.000000,20.275462>}
box{<-0.107900,0,-0.008994><0.107900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.088300,0.000000,20.275462>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.275462>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.275462>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.275462>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.275462>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.275462>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.786100,0.000000,20.275462>}
box{<-0.107900,0,-0.008994><0.107900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.037900,0.000000,20.275462>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.478600,0.000000,20.275462>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.730400,0.000000,20.275462>}
box{<-0.467600,0,-0.008994><0.467600,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.458800,0.000000,20.275462>}
box{<-0.233800,0,-0.008994><0.233800,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.304100,0.000000,20.275462>}
box{<-0.116950,0,-0.008994><0.116950,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.744750,0.000000,20.275462>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.275462>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.275462>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.624200,0.000000,20.275462>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.275462>}
box{<-0.152850,0,-0.008994><0.152850,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.604450,0.000000,20.275462>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.293453>}
box{<-0.107900,0,-0.008994><0.107900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.782500,0.000000,20.293453>}
box{<-0.107900,0,-0.008994><0.107900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.088300,0.000000,20.293453>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.293453>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.293453>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.293453>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.293453>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.293453>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.777100,0.000000,20.293453>}
box{<-0.107900,0,-0.008994><0.107900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.037900,0.000000,20.293453>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.469600,0.000000,20.293453>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.739400,0.000000,20.293453>}
box{<-0.467600,0,-0.008994><0.467600,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.458800,0.000000,20.293453>}
box{<-0.242800,0,-0.008994><0.242800,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.349100,0.000000,20.293453>}
box{<-0.116950,0,-0.008994><0.116950,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.744750,0.000000,20.293453>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.293453>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.293453>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.624200,0.000000,20.293453>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.293453>}
box{<-0.152850,0,-0.008994><0.152850,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.622450,0.000000,20.293453>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.311441>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.773500,0.000000,20.311441>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.097300,0.000000,20.311441>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.311441>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.311441>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.311441>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.311441>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.311441>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.768100,0.000000,20.311441>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.046900,0.000000,20.311441>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.460600,0.000000,20.311441>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.739400,0.000000,20.311441>}
box{<-0.467600,0,-0.008991><0.467600,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.458800,0.000000,20.311441>}
box{<-0.368750,0,-0.008991><0.368750,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.492950,0.000000,20.311441>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.311441>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.311441>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.624200,0.000000,20.311441>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.311441>}
box{<-0.143850,0,-0.008991><0.143850,0.036000,0.008991> rotate<0,-0.000000,0> translate<14.631450,0.000000,20.311441>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.329425>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.773500,0.000000,20.329425>}
box{<-0.107950,0,-0.008994><0.107950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.106250,0.000000,20.329425>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.329425>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.329425>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.329425>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.329425>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.329425>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.768100,0.000000,20.329425>}
box{<-0.107900,0,-0.008994><0.107900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.055900,0.000000,20.329425>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.460600,0.000000,20.329425>}
box{<-0.116950,0,-0.008994><0.116950,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.748350,0.000000,20.329425>}
box{<-0.467600,0,-0.008994><0.467600,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.458800,0.000000,20.329425>}
box{<-0.350750,0,-0.008994><0.350750,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.510950,0.000000,20.329425>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.329425>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.329425>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.624200,0.000000,20.329425>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.329425>}
box{<-0.143900,0,-0.008994><0.143900,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.649400,0.000000,20.329425>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.347409>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.773500,0.000000,20.347409>}
box{<-0.107950,0,-0.008991><0.107950,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.106250,0.000000,20.347409>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.347409>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.347409>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.347409>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.347409>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.347409>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.759100,0.000000,20.347409>}
box{<-0.107900,0,-0.008991><0.107900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.055900,0.000000,20.347409>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.460600,0.000000,20.347409>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.757300,0.000000,20.347409>}
box{<-0.458600,0,-0.008991><0.458600,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.449800,0.000000,20.347409>}
box{<-0.323750,0,-0.008991><0.323750,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.537950,0.000000,20.347409>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.347409>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.347409>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.624200,0.000000,20.347409>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.347409>}
box{<-0.143900,0,-0.008991><0.143900,0.036000,0.008991> rotate<0,-0.000000,0> translate<14.667400,0.000000,20.347409>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.365394>}
box{<-0.107900,0,-0.008994><0.107900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.764500,0.000000,20.365394>}
box{<-0.107950,0,-0.008994><0.107950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.106250,0.000000,20.365394>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.365394>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.365394>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.365394>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.365394>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.365394>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.759100,0.000000,20.365394>}
box{<-0.107900,0,-0.008994><0.107900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.055900,0.000000,20.365394>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.451600,0.000000,20.365394>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.757300,0.000000,20.365394>}
box{<-0.458600,0,-0.008994><0.458600,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.449800,0.000000,20.365394>}
box{<-0.278800,0,-0.008994><0.278800,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.582900,0.000000,20.365394>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.365394>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.365394>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.624200,0.000000,20.365394>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.365394>}
box{<-0.152900,0,-0.008994><0.152900,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.676400,0.000000,20.365394>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.383378>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.755500,0.000000,20.383378>}
box{<-0.116950,0,-0.008988><0.116950,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.115250,0.000000,20.383378>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.383378>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.383378>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.383378>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.383378>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.383378>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.750100,0.000000,20.383378>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.064900,0.000000,20.383378>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.442600,0.000000,20.383378>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.757300,0.000000,20.383378>}
box{<-0.458600,0,-0.008988><0.458600,0.036000,0.008988> rotate<0,-0.000000,0> translate<10.449800,0.000000,20.383378>}
box{<-0.224850,0,-0.008988><0.224850,0.036000,0.008988> rotate<0,-0.000000,0> translate<11.636850,0.000000,20.383378>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.383378>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.383378>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<13.624200,0.000000,20.383378>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.383378>}
box{<-0.152900,0,-0.008988><0.152900,0.036000,0.008988> rotate<0,-0.000000,0> translate<14.694400,0.000000,20.383378>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.401363>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.755500,0.000000,20.401363>}
box{<-0.107950,0,-0.008994><0.107950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.124250,0.000000,20.401363>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.401363>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.401363>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.401363>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.401363>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.401363>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.750100,0.000000,20.401363>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.064900,0.000000,20.401363>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.442600,0.000000,20.401363>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.766300,0.000000,20.401363>}
box{<-0.125850,0,-0.008994><0.125850,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.117050,0.000000,20.401363>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.791500,0.000000,20.401363>}
box{<-0.170900,0,-0.008994><0.170900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.690800,0.000000,20.401363>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.401363>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.401363>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.624200,0.000000,20.401363>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.401363>}
box{<-0.152900,0,-0.008994><0.152900,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.712400,0.000000,20.401363>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.419353>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.755500,0.000000,20.419353>}
box{<-0.107950,0,-0.008994><0.107950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.124250,0.000000,20.419353>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.419353>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.419353>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.203400,0.000000,20.419353>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.419353>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.419353>}
box{<-0.134850,0,-0.008994><0.134850,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.741150,0.000000,20.419353>}
box{<-0.107900,0,-0.008994><0.107900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.073900,0.000000,20.419353>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.442600,0.000000,20.419353>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.775300,0.000000,20.419353>}
box{<-0.125850,0,-0.008994><0.125850,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.117050,0.000000,20.419353>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.782500,0.000000,20.419353>}
box{<-0.143900,0,-0.008994><0.143900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.717800,0.000000,20.419353>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.113500,0.000000,20.419353>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.940800,0.000000,20.419353>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.624200,0.000000,20.419353>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.419353>}
box{<-0.152850,0,-0.008994><0.152850,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.730350,0.000000,20.419353>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.437341>}
box{<-0.107950,0,-0.008991><0.107950,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.746550,0.000000,20.437341>}
box{<-0.107950,0,-0.008991><0.107950,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.124250,0.000000,20.437341>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.437341>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.437341>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.203400,0.000000,20.437341>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.437341>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.437341>}
box{<-0.134850,0,-0.008991><0.134850,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.741150,0.000000,20.437341>}
box{<-0.107900,0,-0.008991><0.107900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.073900,0.000000,20.437341>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.433600,0.000000,20.437341>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.775300,0.000000,20.437341>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.135000,0.000000,20.437341>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.782500,0.000000,20.437341>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.726800,0.000000,20.437341>}
box{<-0.134850,0,-0.008991><0.134850,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.122450,0.000000,20.437341>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.940800,0.000000,20.437341>}
box{<-0.134850,0,-0.008991><0.134850,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.615250,0.000000,20.437341>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.437341>}
box{<-0.152850,0,-0.008991><0.152850,0.036000,0.008991> rotate<0,-0.000000,0> translate<14.748350,0.000000,20.437341>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.455325>}
box{<-0.116950,0,-0.008994><0.116950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.737550,0.000000,20.455325>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.133200,0.000000,20.455325>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.455325>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.455325>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.203400,0.000000,20.455325>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.455325>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.455325>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.732200,0.000000,20.455325>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.082900,0.000000,20.455325>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.424600,0.000000,20.455325>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.775300,0.000000,20.455325>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.135000,0.000000,20.455325>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.782500,0.000000,20.455325>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.735800,0.000000,20.455325>}
box{<-0.134850,0,-0.008994><0.134850,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.122450,0.000000,20.455325>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.940800,0.000000,20.455325>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.606300,0.000000,20.455325>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.455325>}
box{<-0.152850,0,-0.008994><0.152850,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.766350,0.000000,20.455325>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.473309>}
box{<-0.116950,0,-0.008991><0.116950,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.737550,0.000000,20.473309>}
box{<-0.107900,0,-0.008991><0.107900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.142200,0.000000,20.473309>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.473309>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.473309>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.203400,0.000000,20.473309>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.832900,0.000000,20.473309>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.473309>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.723200,0.000000,20.473309>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.082900,0.000000,20.473309>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.424600,0.000000,20.473309>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.793300,0.000000,20.473309>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.135000,0.000000,20.473309>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.773500,0.000000,20.473309>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.133200,0.000000,20.473309>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.735800,0.000000,20.473309>}
box{<-0.143850,0,-0.008991><0.143850,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.131450,0.000000,20.473309>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.949800,0.000000,20.473309>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.606300,0.000000,20.473309>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.473309>}
box{<-0.152900,0,-0.008991><0.152900,0.036000,0.008991> rotate<0,-0.000000,0> translate<14.784300,0.000000,20.473309>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.491294>}
box{<-0.116950,0,-0.008994><0.116950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.737550,0.000000,20.491294>}
box{<-0.107900,0,-0.008994><0.107900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.142200,0.000000,20.491294>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.491294>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.491294>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.212400,0.000000,20.491294>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.823900,0.000000,20.491294>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.491294>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.723200,0.000000,20.491294>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.082900,0.000000,20.491294>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.424600,0.000000,20.491294>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.793300,0.000000,20.491294>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.135000,0.000000,20.491294>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.773500,0.000000,20.491294>}
box{<-0.107900,0,-0.008994><0.107900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.142200,0.000000,20.491294>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.735800,0.000000,20.491294>}
box{<-0.143850,0,-0.008994><0.143850,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.131450,0.000000,20.491294>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.949800,0.000000,20.491294>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.597300,0.000000,20.491294>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.491294>}
box{<-0.143900,0,-0.008994><0.143900,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.793300,0.000000,20.491294>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.509278>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.719600,0.000000,20.509278>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.151200,0.000000,20.509278>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.509278>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.509278>}
box{<-0.134900,0,-0.008988><0.134900,0.036000,0.008988> rotate<0,-0.000000,0> translate<7.212400,0.000000,20.509278>}
box{<-0.134900,0,-0.008988><0.134900,0.036000,0.008988> rotate<0,-0.000000,0> translate<7.823900,0.000000,20.509278>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.509278>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.714200,0.000000,20.509278>}
box{<-0.107900,0,-0.008988><0.107900,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.091900,0.000000,20.509278>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.424600,0.000000,20.509278>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.793300,0.000000,20.509278>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<10.153000,0.000000,20.509278>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<10.764500,0.000000,20.509278>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<11.151200,0.000000,20.509278>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<11.735800,0.000000,20.509278>}
box{<-0.152850,0,-0.008988><0.152850,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.140450,0.000000,20.509278>}
box{<-0.143900,0,-0.008988><0.143900,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.958800,0.000000,20.509278>}
box{<-0.134900,0,-0.008988><0.134900,0.036000,0.008988> rotate<0,-0.000000,0> translate<13.597300,0.000000,20.509278>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.509278>}
box{<-0.143900,0,-0.008988><0.143900,0.036000,0.008988> rotate<0,-0.000000,0> translate<14.811300,0.000000,20.509278>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.527263>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.719600,0.000000,20.527263>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.151200,0.000000,20.527263>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.527263>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.527263>}
box{<-0.143900,0,-0.008994><0.143900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.221400,0.000000,20.527263>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.823900,0.000000,20.527263>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.527263>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.714200,0.000000,20.527263>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.100900,0.000000,20.527263>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.406600,0.000000,20.527263>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.793300,0.000000,20.527263>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.162000,0.000000,20.527263>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.755500,0.000000,20.527263>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.151200,0.000000,20.527263>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.735800,0.000000,20.527263>}
box{<-0.170850,0,-0.008994><0.170850,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.158450,0.000000,20.527263>}
box{<-0.143900,0,-0.008994><0.143900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.958800,0.000000,20.527263>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.579300,0.000000,20.527263>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.527263>}
box{<-0.152900,0,-0.008994><0.152900,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.820300,0.000000,20.527263>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.545250>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.719600,0.000000,20.545250>}
box{<-0.107900,0,-0.008991><0.107900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.160200,0.000000,20.545250>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.545250>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.545250>}
box{<-0.143900,0,-0.008991><0.143900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.221400,0.000000,20.545250>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.805900,0.000000,20.545250>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.545250>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.705200,0.000000,20.545250>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.100900,0.000000,20.545250>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.406600,0.000000,20.545250>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.811300,0.000000,20.545250>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.162000,0.000000,20.545250>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.746500,0.000000,20.545250>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.160200,0.000000,20.545250>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.735800,0.000000,20.545250>}
box{<-0.188850,0,-0.008991><0.188850,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.176450,0.000000,20.545250>}
box{<-0.152850,0,-0.008991><0.152850,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.967750,0.000000,20.545250>}
box{<-0.143900,0,-0.008991><0.143900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.570300,0.000000,20.545250>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.545250>}
box{<-0.152900,0,-0.008991><0.152900,0.036000,0.008991> rotate<0,-0.000000,0> translate<14.838300,0.000000,20.545250>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.563234>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.719600,0.000000,20.563234>}
box{<-0.107900,0,-0.008994><0.107900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.160200,0.000000,20.563234>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.563234>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.563234>}
box{<-0.161850,0,-0.008994><0.161850,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.239350,0.000000,20.563234>}
box{<-0.143900,0,-0.008994><0.143900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.796900,0.000000,20.563234>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.563234>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.705200,0.000000,20.563234>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.100900,0.000000,20.563234>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.406600,0.000000,20.563234>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.811300,0.000000,20.563234>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.180000,0.000000,20.563234>}
box{<-0.134850,0,-0.008994><0.134850,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.737550,0.000000,20.563234>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.160200,0.000000,20.563234>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.717800,0.000000,20.563234>}
box{<-0.278750,0,-0.008994><0.278750,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.266350,0.000000,20.563234>}
box{<-0.161850,0,-0.008994><0.161850,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.976750,0.000000,20.563234>}
box{<-0.152900,0,-0.008994><0.152900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.561300,0.000000,20.563234>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.563234>}
box{<-0.152850,0,-0.008994><0.152850,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.856250,0.000000,20.563234>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.581225>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.701600,0.000000,20.581225>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.169200,0.000000,20.581225>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.581225>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.581225>}
box{<-0.179850,0,-0.008994><0.179850,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.257350,0.000000,20.581225>}
box{<-0.152900,0,-0.008994><0.152900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.787900,0.000000,20.581225>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.581225>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.696200,0.000000,20.581225>}
box{<-0.107950,0,-0.008994><0.107950,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.109850,0.000000,20.581225>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.406600,0.000000,20.581225>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.811300,0.000000,20.581225>}
box{<-0.143900,0,-0.008994><0.143900,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.189000,0.000000,20.581225>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.719600,0.000000,20.581225>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.178200,0.000000,20.581225>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.708800,0.000000,20.581225>}
box{<-0.278750,0,-0.008994><0.278750,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.266350,0.000000,20.581225>}
box{<-0.179850,0,-0.008994><0.179850,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.994750,0.000000,20.581225>}
box{<-0.161900,0,-0.008994><0.161900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.534300,0.000000,20.581225>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.581225>}
box{<-0.395650,0,-0.008994><0.395650,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.631450,0.000000,20.581225>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.599209>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.701600,0.000000,20.599209>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.169200,0.000000,20.599209>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.599209>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.599209>}
box{<-0.431650,0,-0.008991><0.431650,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.509150,0.000000,20.599209>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.599209>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.687200,0.000000,20.599209>}
box{<-0.116950,0,-0.008991><0.116950,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.118850,0.000000,20.599209>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.397600,0.000000,20.599209>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.820300,0.000000,20.599209>}
box{<-0.152850,0,-0.008991><0.152850,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.215950,0.000000,20.599209>}
box{<-0.152900,0,-0.008991><0.152900,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.701600,0.000000,20.599209>}
box{<-0.143900,0,-0.008991><0.143900,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.196200,0.000000,20.599209>}
box{<-0.152900,0,-0.008991><0.152900,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.690800,0.000000,20.599209>}
box{<-0.278750,0,-0.008991><0.278750,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.266350,0.000000,20.599209>}
box{<-0.440650,0,-0.008991><0.440650,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.255550,0.000000,20.599209>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.599209>}
box{<-0.395650,0,-0.008991><0.395650,0.036000,0.008991> rotate<0,-0.000000,0> translate<14.631450,0.000000,20.599209>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.617194>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.701600,0.000000,20.617194>}
box{<-0.107900,0,-0.008994><0.107900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.178200,0.000000,20.617194>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.617194>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.617194>}
box{<-0.422650,0,-0.008994><0.422650,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.500150,0.000000,20.617194>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.617194>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.687200,0.000000,20.617194>}
box{<-0.116950,0,-0.008994><0.116950,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.118850,0.000000,20.617194>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.388600,0.000000,20.617194>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.829300,0.000000,20.617194>}
box{<-0.386700,0,-0.008994><0.386700,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.449800,0.000000,20.617194>}
box{<-0.386700,0,-0.008994><0.386700,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.439000,0.000000,20.617194>}
box{<-0.278750,0,-0.008994><0.278750,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.266350,0.000000,20.617194>}
box{<-0.431650,0,-0.008994><0.431650,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.246550,0.000000,20.617194>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.617194>}
box{<-0.395650,0,-0.008994><0.395650,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.631450,0.000000,20.617194>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.635178>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.701600,0.000000,20.635178>}
box{<-0.107900,0,-0.008988><0.107900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.178200,0.000000,20.635178>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.635178>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.635178>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.635178>}
box{<-0.296750,0,-0.008988><0.296750,0.036000,0.008988> rotate<0,-0.000000,0> translate<7.626050,0.000000,20.635178>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.635178>}
box{<-0.134900,0,-0.008988><0.134900,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.687200,0.000000,20.635178>}
box{<-0.116950,0,-0.008988><0.116950,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.118850,0.000000,20.635178>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.388600,0.000000,20.635178>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.829300,0.000000,20.635178>}
box{<-0.377700,0,-0.008988><0.377700,0.036000,0.008988> rotate<0,-0.000000,0> translate<10.458800,0.000000,20.635178>}
box{<-0.377700,0,-0.008988><0.377700,0.036000,0.008988> rotate<0,-0.000000,0> translate<11.448000,0.000000,20.635178>}
box{<-0.278750,0,-0.008988><0.278750,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.266350,0.000000,20.635178>}
box{<-0.422650,0,-0.008988><0.422650,0.036000,0.008988> rotate<0,-0.000000,0> translate<13.237550,0.000000,20.635178>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.635178>}
box{<-0.395650,0,-0.008988><0.395650,0.036000,0.008988> rotate<0,-0.000000,0> translate<14.631450,0.000000,20.635178>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.653163>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.683600,0.000000,20.653163>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.187200,0.000000,20.653163>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.653163>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.653163>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.653163>}
box{<-0.287750,0,-0.008994><0.287750,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.617050,0.000000,20.653163>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.653163>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.678200,0.000000,20.653163>}
box{<-0.116950,0,-0.008994><0.116950,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.118850,0.000000,20.653163>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.388600,0.000000,20.653163>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.829300,0.000000,20.653163>}
box{<-0.359700,0,-0.008994><0.359700,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.458800,0.000000,20.653163>}
box{<-0.368700,0,-0.008994><0.368700,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.439000,0.000000,20.653163>}
box{<-0.278750,0,-0.008994><0.278750,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.266350,0.000000,20.653163>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.653163>}
box{<-0.296750,0,-0.008994><0.296750,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.363450,0.000000,20.653163>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.653163>}
box{<-0.395650,0,-0.008994><0.395650,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.631450,0.000000,20.653163>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.671150>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.683600,0.000000,20.671150>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.187200,0.000000,20.671150>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.671150>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.671150>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.671150>}
box{<-0.278750,0,-0.008991><0.278750,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.626050,0.000000,20.671150>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.671150>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.669200,0.000000,20.671150>}
box{<-0.242800,0,-0.008991><0.242800,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.262700,0.000000,20.671150>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.838300,0.000000,20.671150>}
box{<-0.341700,0,-0.008991><0.341700,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.458800,0.000000,20.671150>}
box{<-0.359700,0,-0.008991><0.359700,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.448000,0.000000,20.671150>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.104500,0.000000,20.671150>}
box{<-0.152850,0,-0.008991><0.152850,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.392250,0.000000,20.671150>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.671150>}
box{<-0.278750,0,-0.008991><0.278750,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.363450,0.000000,20.671150>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.671150>}
box{<-0.395650,0,-0.008991><0.395650,0.036000,0.008991> rotate<0,-0.000000,0> translate<14.631450,0.000000,20.671150>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.422800,0.000000,20.689134>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.683600,0.000000,20.689134>}
box{<-0.107900,0,-0.008994><0.107900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.196200,0.000000,20.689134>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.448000,0.000000,20.689134>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.689134>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.689134>}
box{<-0.260750,0,-0.008994><0.260750,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.626050,0.000000,20.689134>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.689134>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.669200,0.000000,20.689134>}
box{<-0.233850,0,-0.008994><0.233850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.253750,0.000000,20.689134>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.847300,0.000000,20.689134>}
box{<-0.323750,0,-0.008994><0.323750,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.458750,0.000000,20.689134>}
box{<-0.341700,0,-0.008994><0.341700,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.448000,0.000000,20.689134>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.104500,0.000000,20.689134>}
box{<-0.152850,0,-0.008994><0.152850,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.392250,0.000000,20.689134>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.689134>}
box{<-0.260750,0,-0.008994><0.260750,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.363450,0.000000,20.689134>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.689134>}
box{<-0.395650,0,-0.008994><0.395650,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.631450,0.000000,20.689134>}
box{<-0.251800,0,-0.008994><0.251800,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.548700,0.000000,20.707125>}
box{<-0.242800,0,-0.008994><0.242800,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.331100,0.000000,20.707125>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.707125>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.707125>}
box{<-0.242800,0,-0.008994><0.242800,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.626000,0.000000,20.707125>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.707125>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.669200,0.000000,20.707125>}
box{<-0.233850,0,-0.008994><0.233850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.253750,0.000000,20.707125>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.847300,0.000000,20.707125>}
box{<-0.305750,0,-0.008994><0.305750,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.458750,0.000000,20.707125>}
box{<-0.323750,0,-0.008994><0.323750,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.447950,0.000000,20.707125>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.104500,0.000000,20.707125>}
box{<-0.143900,0,-0.008994><0.143900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.401200,0.000000,20.707125>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.707125>}
box{<-0.242850,0,-0.008994><0.242850,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.363450,0.000000,20.707125>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.707125>}
box{<-0.395650,0,-0.008994><0.395650,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.631450,0.000000,20.707125>}
box{<-0.251800,0,-0.008991><0.251800,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.548700,0.000000,20.725109>}
box{<-0.242800,0,-0.008991><0.242800,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.331100,0.000000,20.725109>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.725109>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.725109>}
box{<-0.224850,0,-0.008991><0.224850,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.626050,0.000000,20.725109>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.725109>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.651200,0.000000,20.725109>}
box{<-0.233850,0,-0.008991><0.233850,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.253750,0.000000,20.725109>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.856300,0.000000,20.725109>}
box{<-0.287750,0,-0.008991><0.287750,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.458750,0.000000,20.725109>}
box{<-0.296800,0,-0.008991><0.296800,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.439000,0.000000,20.725109>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.104500,0.000000,20.725109>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.410200,0.000000,20.725109>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.725109>}
box{<-0.224850,0,-0.008991><0.224850,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.363450,0.000000,20.725109>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.725109>}
box{<-0.395650,0,-0.008991><0.395650,0.036000,0.008991> rotate<0,-0.000000,0> translate<14.631450,0.000000,20.725109>}
box{<-0.242800,0,-0.008994><0.242800,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.539700,0.000000,20.743094>}
box{<-0.242800,0,-0.008994><0.242800,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.331100,0.000000,20.743094>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.743094>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.743094>}
box{<-0.206850,0,-0.008994><0.206850,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.626050,0.000000,20.743094>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.743094>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.651200,0.000000,20.743094>}
box{<-0.224850,0,-0.008994><0.224850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.262750,0.000000,20.743094>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.856300,0.000000,20.743094>}
box{<-0.269800,0,-0.008994><0.269800,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.458800,0.000000,20.743094>}
box{<-0.269800,0,-0.008994><0.269800,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.448000,0.000000,20.743094>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.104500,0.000000,20.743094>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.419200,0.000000,20.743094>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.743094>}
box{<-0.188850,0,-0.008994><0.188850,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.363450,0.000000,20.743094>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.743094>}
box{<-0.395650,0,-0.008994><0.395650,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.631450,0.000000,20.743094>}
box{<-0.242800,0,-0.008988><0.242800,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.539700,0.000000,20.761078>}
box{<-0.233800,0,-0.008988><0.233800,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.340100,0.000000,20.761078>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.761078>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.761078>}
box{<-0.170850,0,-0.008988><0.170850,0.036000,0.008988> rotate<0,-0.000000,0> translate<7.626050,0.000000,20.761078>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.761078>}
box{<-0.134900,0,-0.008988><0.134900,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.651200,0.000000,20.761078>}
box{<-0.215850,0,-0.008988><0.215850,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.253750,0.000000,20.761078>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.865300,0.000000,20.761078>}
box{<-0.233800,0,-0.008988><0.233800,0.036000,0.008988> rotate<0,-0.000000,0> translate<10.458800,0.000000,20.761078>}
box{<-0.233800,0,-0.008988><0.233800,0.036000,0.008988> rotate<0,-0.000000,0> translate<11.448000,0.000000,20.761078>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.104500,0.000000,20.761078>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.428200,0.000000,20.761078>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.761078>}
box{<-0.170850,0,-0.008988><0.170850,0.036000,0.008988> rotate<0,-0.000000,0> translate<13.363450,0.000000,20.761078>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.761078>}
box{<-0.395650,0,-0.008988><0.395650,0.036000,0.008988> rotate<0,-0.000000,0> translate<14.631450,0.000000,20.761078>}
box{<-0.242800,0,-0.008994><0.242800,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.539700,0.000000,20.779063>}
box{<-0.233800,0,-0.008994><0.233800,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.340100,0.000000,20.779063>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.779063>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.194400,0.000000,20.779063>}
box{<-0.134850,0,-0.008994><0.134850,0.036000,0.008994> rotate<0,-0.000000,0> translate<7.626050,0.000000,20.779063>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.779063>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.651200,0.000000,20.779063>}
box{<-0.215850,0,-0.008994><0.215850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.253750,0.000000,20.779063>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.865300,0.000000,20.779063>}
box{<-0.197850,0,-0.008994><0.197850,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.458750,0.000000,20.779063>}
box{<-0.179850,0,-0.008994><0.179850,0.036000,0.008994> rotate<0,-0.000000,0> translate<11.447950,0.000000,20.779063>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.104500,0.000000,20.779063>}
box{<-0.098900,0,-0.008994><0.098900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.446200,0.000000,20.779063>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.779063>}
box{<-0.116950,0,-0.008994><0.116950,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.363450,0.000000,20.779063>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.779063>}
box{<-0.395650,0,-0.008994><0.395650,0.036000,0.008994> rotate<0,-0.000000,0> translate<14.631450,0.000000,20.779063>}
box{<-0.242800,0,-0.008991><0.242800,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.539700,0.000000,20.797050>}
box{<-0.233800,0,-0.008991><0.233800,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.340100,0.000000,20.797050>}
box{<-0.044950,0,-0.008991><0.044950,0.036000,0.008991> rotate<0,-0.000000,0> translate<7.626050,0.000000,20.797050>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.633200,0.000000,20.797050>}
box{<-0.215850,0,-0.008991><0.215850,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.253750,0.000000,20.797050>}
box{<-0.134850,0,-0.008991><0.134850,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.874250,0.000000,20.797050>}
box{<-0.152850,0,-0.008991><0.152850,0.036000,0.008991> rotate<0,-0.000000,0> translate<10.467750,0.000000,20.797050>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<11.447950,0.000000,20.797050>}
box{<-0.080950,0,-0.008991><0.080950,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.464150,0.000000,20.797050>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.797050>}
box{<-0.035950,0,-0.008991><0.035950,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.354450,0.000000,20.797050>}
box{<-0.233800,0,-0.008994><0.233800,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.530700,0.000000,20.815034>}
box{<-0.233800,0,-0.008994><0.233800,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.340100,0.000000,20.815034>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.633200,0.000000,20.815034>}
box{<-0.215850,0,-0.008994><0.215850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.253750,0.000000,20.815034>}
box{<-0.134850,0,-0.008994><0.134850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.874250,0.000000,20.815034>}
box{<-0.044950,0,-0.008994><0.044950,0.036000,0.008994> rotate<0,-0.000000,0> translate<10.467750,0.000000,20.815034>}
box{<-0.035950,0,-0.008994><0.035950,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.509150,0.000000,20.815034>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.815034>}
box{<-0.233800,0,-0.008988><0.233800,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.530700,0.000000,20.833019>}
box{<-0.224850,0,-0.008988><0.224850,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.349050,0.000000,20.833019>}
box{<-0.134900,0,-0.008988><0.134900,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.633200,0.000000,20.833019>}
box{<-0.197850,0,-0.008988><0.197850,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.253750,0.000000,20.833019>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.883200,0.000000,20.833019>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.833019>}
box{<-0.233800,0,-0.008994><0.233800,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.530700,0.000000,20.851003>}
box{<-0.224850,0,-0.008994><0.224850,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.349050,0.000000,20.851003>}
box{<-0.143850,0,-0.008994><0.143850,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.624250,0.000000,20.851003>}
box{<-0.197850,0,-0.008994><0.197850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.253750,0.000000,20.851003>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.883200,0.000000,20.851003>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.851003>}
box{<-0.233800,0,-0.008994><0.233800,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.530700,0.000000,20.868994>}
box{<-0.224850,0,-0.008994><0.224850,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.349050,0.000000,20.868994>}
box{<-0.134850,0,-0.008994><0.134850,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.615250,0.000000,20.868994>}
box{<-0.197850,0,-0.008994><0.197850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.253750,0.000000,20.868994>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.892200,0.000000,20.868994>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.868994>}
box{<-0.224800,0,-0.008988><0.224800,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.521700,0.000000,20.886978>}
box{<-0.224850,0,-0.008988><0.224850,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.349050,0.000000,20.886978>}
box{<-0.134850,0,-0.008988><0.134850,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.615250,0.000000,20.886978>}
box{<-0.197850,0,-0.008988><0.197850,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.253750,0.000000,20.886978>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.901200,0.000000,20.886978>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.886978>}
box{<-0.224800,0,-0.008994><0.224800,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.521700,0.000000,20.904962>}
box{<-0.215850,0,-0.008994><0.215850,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.358050,0.000000,20.904962>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.904962>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.904962>}
box{<-0.134850,0,-0.008994><0.134850,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.615250,0.000000,20.904962>}
box{<-0.197850,0,-0.008994><0.197850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.253750,0.000000,20.904962>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.901200,0.000000,20.904962>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.904962>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.904962>}
box{<-0.224800,0,-0.008991><0.224800,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.521700,0.000000,20.922950>}
box{<-0.215850,0,-0.008991><0.215850,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.358050,0.000000,20.922950>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.922950>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.922950>}
box{<-0.143850,0,-0.008991><0.143850,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.606250,0.000000,20.922950>}
box{<-0.179850,0,-0.008991><0.179850,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.253750,0.000000,20.922950>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.910200,0.000000,20.922950>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.922950>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.922950>}
box{<-0.224800,0,-0.008994><0.224800,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.521700,0.000000,20.940934>}
box{<-0.215850,0,-0.008994><0.215850,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.358050,0.000000,20.940934>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.940934>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.940934>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.597300,0.000000,20.940934>}
box{<-0.179850,0,-0.008994><0.179850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.253750,0.000000,20.940934>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.910200,0.000000,20.940934>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.940934>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.940934>}
box{<-0.215850,0,-0.008988><0.215850,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.512750,0.000000,20.958919>}
box{<-0.215850,0,-0.008988><0.215850,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.358050,0.000000,20.958919>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.958919>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.958919>}
box{<-0.134900,0,-0.008988><0.134900,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.597300,0.000000,20.958919>}
box{<-0.179850,0,-0.008988><0.179850,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.253750,0.000000,20.958919>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.919200,0.000000,20.958919>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.958919>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.958919>}
box{<-0.215850,0,-0.008994><0.215850,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.512750,0.000000,20.976903>}
box{<-0.206850,0,-0.008994><0.206850,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.367050,0.000000,20.976903>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.976903>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.976903>}
box{<-0.143900,0,-0.008994><0.143900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.588300,0.000000,20.976903>}
box{<-0.179850,0,-0.008994><0.179850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.253750,0.000000,20.976903>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.919200,0.000000,20.976903>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.976903>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.976903>}
box{<-0.215850,0,-0.008991><0.215850,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.512750,0.000000,20.994891>}
box{<-0.206850,0,-0.008991><0.206850,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.367050,0.000000,20.994891>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.825700,0.000000,20.994891>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.201600,0.000000,20.994891>}
box{<-0.143900,0,-0.008991><0.143900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.588300,0.000000,20.994891>}
box{<-0.161850,0,-0.008991><0.161850,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.253750,0.000000,20.994891>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.928200,0.000000,20.994891>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.931800,0.000000,20.994891>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.984000,0.000000,20.994891>}
box{<-0.215850,0,-0.008994><0.215850,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.512750,0.000000,21.012875>}
box{<-0.206850,0,-0.008994><0.206850,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.367050,0.000000,21.012875>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,21.012875>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,21.012875>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.579300,0.000000,21.012875>}
box{<-0.161850,0,-0.008994><0.161850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.253750,0.000000,21.012875>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.928200,0.000000,21.012875>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,21.012875>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,21.012875>}
box{<-0.206850,0,-0.008994><0.206850,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.503750,0.000000,21.030863>}
box{<-0.206850,0,-0.008994><0.206850,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.367050,0.000000,21.030863>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,21.030863>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,21.030863>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.579300,0.000000,21.030863>}
box{<-0.161850,0,-0.008994><0.161850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.253750,0.000000,21.030863>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.937200,0.000000,21.030863>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,21.030863>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,21.030863>}
box{<-0.206850,0,-0.008991><0.206850,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.503750,0.000000,21.048850>}
box{<-0.197850,0,-0.008991><0.197850,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.376050,0.000000,21.048850>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.825700,0.000000,21.048850>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.201600,0.000000,21.048850>}
box{<-0.143900,0,-0.008991><0.143900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.570300,0.000000,21.048850>}
box{<-0.161850,0,-0.008991><0.161850,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.253750,0.000000,21.048850>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.946200,0.000000,21.048850>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.931800,0.000000,21.048850>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.984000,0.000000,21.048850>}
box{<-0.206850,0,-0.008994><0.206850,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.503750,0.000000,21.066834>}
box{<-0.197850,0,-0.008994><0.197850,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.376050,0.000000,21.066834>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,21.066834>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,21.066834>}
box{<-0.143900,0,-0.008994><0.143900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.570300,0.000000,21.066834>}
box{<-0.152850,0,-0.008994><0.152850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.244750,0.000000,21.066834>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.946200,0.000000,21.066834>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,21.066834>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,21.066834>}
box{<-0.206850,0,-0.008988><0.206850,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.503750,0.000000,21.084819>}
box{<-0.197850,0,-0.008988><0.197850,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.376050,0.000000,21.084819>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.825700,0.000000,21.084819>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.201600,0.000000,21.084819>}
box{<-0.134900,0,-0.008988><0.134900,0.036000,0.008988> rotate<0,-0.000000,0> translate<8.561300,0.000000,21.084819>}
box{<-0.143850,0,-0.008988><0.143850,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.253750,0.000000,21.084819>}
box{<-0.134900,0,-0.008988><0.134900,0.036000,0.008988> rotate<0,-0.000000,0> translate<9.946200,0.000000,21.084819>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<12.931800,0.000000,21.084819>}
box{<-0.125900,0,-0.008988><0.125900,0.036000,0.008988> rotate<0,-0.000000,0> translate<13.984000,0.000000,21.084819>}
box{<-0.197850,0,-0.008994><0.197850,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.494750,0.000000,21.102803>}
box{<-0.197850,0,-0.008994><0.197850,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.376050,0.000000,21.102803>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,21.102803>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,21.102803>}
box{<-0.134900,0,-0.008994><0.134900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.561300,0.000000,21.102803>}
box{<-0.143850,0,-0.008994><0.143850,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.253750,0.000000,21.102803>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<9.955200,0.000000,21.102803>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,21.102803>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,21.102803>}
box{<-0.197850,0,-0.008991><0.197850,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.494750,0.000000,21.120791>}
box{<-0.188850,0,-0.008991><0.188850,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.385050,0.000000,21.120791>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.825700,0.000000,21.120791>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.201600,0.000000,21.120791>}
box{<-0.143900,0,-0.008991><0.143900,0.036000,0.008991> rotate<0,-0.000000,0> translate<8.552300,0.000000,21.120791>}
box{<-0.143850,0,-0.008991><0.143850,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.253750,0.000000,21.120791>}
box{<-0.134900,0,-0.008991><0.134900,0.036000,0.008991> rotate<0,-0.000000,0> translate<9.964200,0.000000,21.120791>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<12.931800,0.000000,21.120791>}
box{<-0.125900,0,-0.008991><0.125900,0.036000,0.008991> rotate<0,-0.000000,0> translate<13.984000,0.000000,21.120791>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.825700,0.000000,21.138775>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<8.201600,0.000000,21.138775>}
box{<-0.116900,0,-0.008994><0.116900,0.036000,0.008994> rotate<0,-0.000000,0> translate<12.931800,0.000000,21.138775>}
box{<-0.125900,0,-0.008994><0.125900,0.036000,0.008994> rotate<0,-0.000000,0> translate<13.984000,0.000000,21.138775>}
box{<-0.036000,0,-0.008994><0.036000,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.440800,0.000000,21.264675>}
box{<-0.036000,0,-0.008994><0.036000,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.782500,0.000000,21.264675>}
box{<-0.035950,0,-0.008994><0.035950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.124250,0.000000,21.264675>}
box{<-0.035950,0,-0.008994><0.035950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.465950,0.000000,21.264675>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.440750,0.000000,21.282659>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.782550,0.000000,21.282659>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.124250,0.000000,21.282659>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.465950,0.000000,21.282659>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.440750,0.000000,21.300644>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.782550,0.000000,21.300644>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.124250,0.000000,21.300644>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.465950,0.000000,21.300644>}
box{<-0.071950,0,-0.008994><0.071950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.440750,0.000000,21.318634>}
box{<-0.071950,0,-0.008994><0.071950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.782550,0.000000,21.318634>}
box{<-0.071950,0,-0.008994><0.071950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.124250,0.000000,21.318634>}
box{<-0.071950,0,-0.008994><0.071950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.465950,0.000000,21.318634>}
box{<-0.071950,0,-0.008988><0.071950,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.440750,0.000000,21.336619>}
box{<-0.071950,0,-0.008988><0.071950,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.782550,0.000000,21.336619>}
box{<-0.071950,0,-0.008988><0.071950,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.124250,0.000000,21.336619>}
box{<-0.071950,0,-0.008988><0.071950,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.465950,0.000000,21.336619>}
box{<-0.107900,0,-0.008994><0.107900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.440800,0.000000,21.354603>}
box{<-0.107900,0,-0.008994><0.107900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.782500,0.000000,21.354603>}
box{<-0.107950,0,-0.008994><0.107950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.124250,0.000000,21.354603>}
box{<-0.107900,0,-0.008994><0.107900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.466000,0.000000,21.354603>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.431800,0.000000,21.372591>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.773500,0.000000,21.372591>}
box{<-0.116950,0,-0.008991><0.116950,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.115250,0.000000,21.372591>}
box{<-0.116900,0,-0.008991><0.116900,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.457000,0.000000,21.372591>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.368850,0.000000,21.390575>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.512750,0.000000,21.390575>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.710550,0.000000,21.390575>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.854450,0.000000,21.390575>}
box{<-0.054000,0,-0.008994><0.054000,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.052300,0.000000,21.390575>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.196150,0.000000,21.390575>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.394050,0.000000,21.390575>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.537950,0.000000,21.390575>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.350850,0.000000,21.408559>}
box{<-0.062950,0,-0.008991><0.062950,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.521750,0.000000,21.408559>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.692550,0.000000,21.408559>}
box{<-0.062950,0,-0.008991><0.062950,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.863450,0.000000,21.408559>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.034350,0.000000,21.408559>}
box{<-0.062950,0,-0.008991><0.062950,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.205150,0.000000,21.408559>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.376050,0.000000,21.408559>}
box{<-0.062950,0,-0.008991><0.062950,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.546950,0.000000,21.408559>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.332850,0.000000,21.426544>}
box{<-0.062950,0,-0.008994><0.062950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.539750,0.000000,21.426544>}
box{<-0.054000,0,-0.008994><0.054000,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.674600,0.000000,21.426544>}
box{<-0.062950,0,-0.008994><0.062950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.881450,0.000000,21.426544>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.016350,0.000000,21.426544>}
box{<-0.062950,0,-0.008994><0.062950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.223150,0.000000,21.426544>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.358050,0.000000,21.426544>}
box{<-0.062950,0,-0.008994><0.062950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.564850,0.000000,21.426544>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.332850,0.000000,21.444534>}
box{<-0.054000,0,-0.008994><0.054000,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.548700,0.000000,21.444534>}
box{<-0.054000,0,-0.008994><0.054000,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.674600,0.000000,21.444534>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.890450,0.000000,21.444534>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.016350,0.000000,21.444534>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.232150,0.000000,21.444534>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.358050,0.000000,21.444534>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.573850,0.000000,21.444534>}
box{<-0.062950,0,-0.008991><0.062950,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.323850,0.000000,21.498491>}
box{<-0.054000,0,-0.008991><0.054000,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.548700,0.000000,21.498491>}
box{<-0.054000,0,-0.008991><0.054000,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.674600,0.000000,21.498491>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.890450,0.000000,21.498491>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.016350,0.000000,21.498491>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.232150,0.000000,21.498491>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.358050,0.000000,21.498491>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.573850,0.000000,21.498491>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.332850,0.000000,21.516475>}
box{<-0.045000,0,-0.008994><0.045000,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.539700,0.000000,21.516475>}
box{<-0.054000,0,-0.008994><0.054000,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.674600,0.000000,21.516475>}
box{<-0.044950,0,-0.008994><0.044950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.881450,0.000000,21.516475>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.016350,0.000000,21.516475>}
box{<-0.044950,0,-0.008994><0.044950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.223150,0.000000,21.516475>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.358050,0.000000,21.516475>}
box{<-0.045000,0,-0.008994><0.045000,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.564900,0.000000,21.516475>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.350850,0.000000,21.534459>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.530750,0.000000,21.534459>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.692550,0.000000,21.534459>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.872450,0.000000,21.534459>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.034350,0.000000,21.534459>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.214150,0.000000,21.534459>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.376050,0.000000,21.534459>}
box{<-0.054000,0,-0.008991><0.054000,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.555900,0.000000,21.534459>}
box{<-0.062950,0,-0.008994><0.062950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.359850,0.000000,21.552444>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.512750,0.000000,21.552444>}
box{<-0.062950,0,-0.008994><0.062950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.701550,0.000000,21.552444>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.854450,0.000000,21.552444>}
box{<-0.062950,0,-0.008994><0.062950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.043350,0.000000,21.552444>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.196150,0.000000,21.552444>}
box{<-0.062950,0,-0.008994><0.062950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.385050,0.000000,21.552444>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.537950,0.000000,21.552444>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.431800,0.000000,21.570428>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<5.773500,0.000000,21.570428>}
box{<-0.116950,0,-0.008988><0.116950,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.115250,0.000000,21.570428>}
box{<-0.116900,0,-0.008988><0.116900,0.036000,0.008988> rotate<0,-0.000000,0> translate<6.457000,0.000000,21.570428>}
box{<-0.098900,0,-0.008994><0.098900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.431800,0.000000,21.588413>}
box{<-0.098900,0,-0.008994><0.098900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.773500,0.000000,21.588413>}
box{<-0.098950,0,-0.008994><0.098950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.115250,0.000000,21.588413>}
box{<-0.098900,0,-0.008994><0.098900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.457000,0.000000,21.588413>}
box{<-0.098900,0,-0.008994><0.098900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.431800,0.000000,21.606403>}
box{<-0.098900,0,-0.008994><0.098900,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.773500,0.000000,21.606403>}
box{<-0.098950,0,-0.008994><0.098950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.115250,0.000000,21.606403>}
box{<-0.098900,0,-0.008994><0.098900,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.457000,0.000000,21.606403>}
box{<-0.080900,0,-0.008991><0.080900,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.431800,0.000000,21.624391>}
box{<-0.080950,0,-0.008991><0.080950,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.773550,0.000000,21.624391>}
box{<-0.080950,0,-0.008991><0.080950,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.115250,0.000000,21.624391>}
box{<-0.080950,0,-0.008991><0.080950,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.456950,0.000000,21.624391>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.440750,0.000000,21.642375>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.782550,0.000000,21.642375>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.124250,0.000000,21.642375>}
box{<-0.053950,0,-0.008994><0.053950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.465950,0.000000,21.642375>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.440750,0.000000,21.660359>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<5.782550,0.000000,21.660359>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.124250,0.000000,21.660359>}
box{<-0.053950,0,-0.008991><0.053950,0.036000,0.008991> rotate<0,-0.000000,0> translate<6.465950,0.000000,21.660359>}
box{<-0.045000,0,-0.008994><0.045000,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.431800,0.000000,21.678344>}
box{<-0.044950,0,-0.008994><0.044950,0.036000,0.008994> rotate<0,-0.000000,0> translate<5.773550,0.000000,21.678344>}
box{<-0.044950,0,-0.008994><0.044950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.115250,0.000000,21.678344>}
box{<-0.044950,0,-0.008994><0.044950,0.036000,0.008994> rotate<0,-0.000000,0> translate<6.456950,0.000000,21.678344>}
texture{col_slk}
}
#end
translate<mac_x_ver,mac_y_ver,mac_z_ver>
rotate<mac_x_rot,mac_y_rot,mac_z_rot>
}//End union
#end

#if(use_file_as_inc=off)
object{  UVANDLIGHT_I2C_V2_(-10.137500,0,-14.225000,pcb_rotate_x,pcb_rotate_y,pcb_rotate_z)
#if(pcb_upsidedown=on)
rotate pcb_rotdir*180
#end
}
#end


//Parts not found in 3dpack.dat or 3dusrpac.dat are:
//U$1	EZ-I2CHEADERV1	EZ-I2CHEADERV1
//U$2	UV-SI1132	UV-SI1132
//U$3		LOGO2
