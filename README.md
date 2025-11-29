# Congest-X-A-Practical-Congestion-Minimization-Project
CongestX is a mini physical design project focused on routing congestion analysis and optimization using Synopsys ICC2. The design undergoes a complete placement → congestion mapping → blockage insertion → ECO-placement → final congestion validation flow

This repository contains a complete, structured Physical Design (PD) implementation flow for the ORCA_TOP design using Synopsys IC Compiler II (ICC2). The project covers technology import, reference library creation, block setup, voltage area generation, port placement, floorplanning, macro handling, congestion analysis, and boundary/tap cell insertion.

1. Project Overview

This project demonstrates an end-to-end ICC2 flow including:

Technology and NDM library import

Reference library creation

Block creation and RTL loading

Voltage area calculation & region generation

Automated port placement

L-shape floorplan creation using side-ratio

Macro placement and blockage derivation

Placement legalization

Routing layer definition & congestion analysis

Boundary and tap cell insertion

All scripts are modular for easy execution and reuse.

2. Repository Structure

/inputs/           – RTL, UPF, technology NDM files  
/scripts/          – TCL scripts for each physical design stage  
/outputs/          – .nlib database, blocks, reports  
  

3. Technology & Library Setup

3.1 Search Path Initialization

Search paths for technology libraries and design inputs are defined to ensure ICC2 can access all required files.

3.2 NDM Library Assignment

All technology and standard-cell .ndm files are grouped into a single variable and passed to create_lib.

3.3 Reference Library Creation

A unified .nlib reference library is generated.
Sanity checks using report_ref_libs confirm successful import.

4. Block Creation & RTL Import

A new block named ORCA_TOP is created.

RTL netlist (ORCA_TOP.v) is read.

The block is saved to establish the design database.

This forms the foundation for all subsequent physical design operations.

5. Voltage Area Generation (RISC_CORE Domain)

5.1 Cell Area Extraction

All flattened cells under RISC_CORE are collected and their area is summed.

5.2 Voltage-Area Computation

Required voltage area is calculated using:

Target utilization = 0.75

Snapped height aligned to site row height (1.672 µm)

Snapped width aligned to track pitch (0.152 µm)

5.3 Region Creation

Lower-left and upper-right coordinates are derived.

Existing voltage areas are removed.

A new voltage region is created using create_voltage_area and assigned to PD_RISC_CORE.

6. Port Placement Automation

6.1 Pin Constraint Setup

Port placement rules include:

Allowed routing layers (M5 / M6)

Pin spacing

Corner keep-out distance

Side-based constraints

6.2 Placement Execution

Input ports placed excluding clocks

Clock ports placed separately

Output ports placed on designated sides

6.3 Optional Re-Placement

Ports can be moved, pin guides regenerated, and placement repeated as needed.

7. Floorplanning (Side-Ratio L-Shape Method)

The floorplan is created using:

Shape: L

Side Ratio: {2 1 1 2}

Core Offset: 5 µm

Core Utilization: 0.75

Site Row Usage: Enabled

The resulting block is saved under a separate floorplan version.


![WhatsApp Image 2025-11-29 at 19 39 11_0e736802](https://github.com/user-attachments/assets/4a3a9639-bfdb-41db-a39c-ee1d75365e40)


8. Macro Handling & Placement Preparation

8.1 UPF Loading

Power intent is imported using load_upf.

8.2 Hard Macro Keep-Out

Keep-out margins are applied around all hard macros to avoid placement overlap.

8.3 Blockage Derivation

Automatic placement blockages are generated to guide standard-cell distribution.

8.4 Macro Fixing


![WhatsApp Image 2025-11-29 at 19 48 57_212e3652](https://github.com/user-attachments/assets/b5c44800-4c05-4d9f-8bc4-cb863ffef3ff)


All hard macros are fixed using set_fixed_objects.

9. Placement & Routing Preparation

9.1 Initial Placement

Standard cells are placed using ICC2’s placement engine.

9.2 Legalization

legalize_placement resolves overlaps and aligns cells to sites.

9.3 Routing Layer Constraint

Allowed routing layers are set between M2 and M6.

10. Congestion Analysis & Optimization

10.1 Initial Congestion Check

report_congestion and rerun_global_router generate the congestion map.

10.2 Target Congestion

Acceptable congestion < 0.5

Optimal congestion ~0.1


![WhatsApp Image 2025-11-29 at 22 30 51_e54ea556](https://github.com/user-attachments/assets/b0dc42ef-69f9-4ea2-9b4c-de82a0b4ccef)


10.3 Reset for Optimization

If required, placement is reset and re-run using improved blockages and macros.

11. Port Re-Placement (Optional)

Select ports

Move to new coordinates

Regenerate pin guides

Re-place inputs, clocks, and outputs

This ensures routing-friendly pin alignment.

12. Boundary & Tap Cell Insertion

12.1 Boundary Cells

Left/right boundary rules are defined

Boundary cells compiled and checked

12.2 Tap Cells

Inserted using:

Pattern: staggered

Distance: 30 µm


![WhatsApp Image 2025-11-29 at 20 01 02_4c887527](https://github.com/user-attachments/assets/319bdd51-f39e-4090-94f2-d2d555dc276f)


Skip fixed cells to avoid macro interference

12.3 Removal (if required)

remove_cells is used to delete tap/filler cells when regenerating.

13. Output & Results

The repository includes:

Floorplan snapshots

Macro placement map

Voltage area visualization

Port placement maps

Congestion heatmaps

Power report

![WhatsApp Image 2025-11-29 at 22 33 17_3e5acb77](https://github.com/user-attachments/assets/2fc0f353-9aff-485b-80c5-17f4e8acaae9)

Design Report

![WhatsApp Image 2025-11-29 at 22 35 00_1d799dcf](https://github.com/user-attachments/assets/41a222ef-dc9e-4f24-b229-881fd9a0c5ec)

Boundary/tap cell distribution

These outputs represent the final cleaned and structured physical layout after optimization.

14. Conclusion

This project demonstrates a complete, industry-standard ICC2 physical design flow for ORCA_TOP. It includes voltage-area creation, L-shape floorplanning, macro placement optimization, congestion-driven refinement, and boundary/tap cell insertion—designed to showcase strong practical PD skills for portfolios, LinkedIn, and job applications.






















