open_lib ./outputs/ORCA_TOP.nlib
open_block ORCA_TOP
link_block
start_gui


#Floorplan : #SIDE RATIO METHOD

initialize_floorplan -shape L -side ratio {2 1 1 2} -core_offset 5 -core_utilization 0.75 -use_site_row -site_def unit

save block -as L SIDE



load_upf./inputs/ORCA_TOP.upf



create_keepout_margin -outer {1 1 1 1} [get_flat_cells -filter "is_hard_macro"]

derive_placement_blockage 

#To fix the macro

set_fixed_objects [get_flat_cells -filter "is_hard_macro"]

create placement -floorplan

#std cell will be overlapping

legalize_placement

#place all std cells

#use M2 to M6 metal layers for routing purpose 
set_ignored_layers -max_routing_layer M6 -min_routing_layer M2

#check congestion

report_congestion rerun_global_router

#the congestion should be less than 0.5

#0.1

reset_placement




set_fixed_objects [get_flat_cells filter "is_hard_macro"]

# if u want to change the port placement

#select the ports

move objects -to (0 0)

#create placement blockage

set a [[get_attribute] [get selection] bbox]

remove_pin_guides -all

create_pin_guide -layers M5 -pin_spacing 1 -boundary $a [remove_from_collection [all_inputs] [get_ports *clk*]]

place_pins -ports [remove_from_collection [all_inputs] [get_ports *clk*]]

# do same for clk ports and output ports 

#creating boundary cells


set_boundary_cell_rules -left_boundary_cell DCAP_HVT -right_boundary_cell DCAP_HVT -at_va_boundary

compile_boundary_cells

check_boundary_cells

create_tap_cells -lib_cell DCAP_HVT -pattern stagger -distance 30 -skip_fixed_cells

# if u want to remove cells  

remove_cells [get_flat_cells -all tapfiller]
