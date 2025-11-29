#uti => 0.75

#cell area belongs to I RISC CORE

set a [get_attribute [get_flat_cells *RISC_CORE*] area ]

set sum 0

foreach i $a {

    set sum [expr $sum+ $i]
}
puts "cell area belonging to I_RISC_CORE: $sum"

set uti 0.75

set voltage_area [expr ($sum/$uti)]

puts $voltage area

#voltage area = height * width

set height 172

set h [expr {ceil ($height/1.672)} *1.672]

set width [expr ($voltage area / $height)]

set w [expr {ceil ($width/0.152)} * 0.152]

puts $width

#coordinates = {llx lly} {urx ury}

set llx 10.016

set lly 10.016

set urx [expr $w + 10.016]

set ury [expr $h + 10.016 + 1.672]

set a [list [list $llx $lly] [list $urx $ury]]

remove_voltage_areas -all

create_voltage_area -region $a -guard_band {(5.016 5.016)}  -power_domain PD_RISC_CORE