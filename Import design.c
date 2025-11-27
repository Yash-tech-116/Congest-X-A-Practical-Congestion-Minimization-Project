#providing the path where input files are present [tech related & design realted ]

set search path {./inputs/CLIBS/./inputs/ }

#Assign all ndm files to variable "a"

set a {saed32 1p9m tech.ndm saed32 hvt.ndm saed32 lvt.ndm saed32 rvt.ndm saed32 sram lp.ndm}

#create a library assign all the ndm files [5]

create_lib-ref_libs $a./outputs/ORCA_Tooooops.nlib

#save the library

save lib

#sanity checks

report_ref_libs

#help *block*
--> print all the commands which contain keyword "block"
#man create block
-> display the manual of the command "create block" in the terminal
#gui show man page create block -> open a new window which contains the entire manual of the tool
#create a block

create block ORCA TOP
read_verilog./inputs/ORCA TOP.v
save block