
# PlanAhead Launch Script for Post-Synthesis floorplanning, created by Project Navigator

create_project -name TP1 -dir "/home/m1/seysn/Documents/Hugo/AEO/TP1/planAhead_run_4" -part xc6slx16csg324-3
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "/home/m1/seysn/Documents/Hugo/AEO/TP1/add4.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {/home/m1/seysn/Documents/Hugo/AEO/TP1} }
set_param project.paUcfFile  "add4.ucf"
add_files "add4.ucf" -fileset [get_property constrset [current_run]]
open_netlist_design
