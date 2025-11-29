# port placements 

#block pin constraints method 


set_block_pin_constraints -self sides 1 allowed_layers M5 -pin_spacing 1 -corner_keepout_distance 200

place_pins -ports [remove_from_collection [all_inputs] [get_ports clk]]

set_block_pin_constraints -self sides 2 allowed_layers M6 -pin spacing 1 -corner_keepout distance 300

place_pins -ports [get_ports clk]

set_block_pin_constraints -self sides 4 allowed_layers M5 -pin_spacing 1-corner_keepout_distance 200

place_pins-ports [all_outputs]