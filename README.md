# AI Powered Robotic Arm Lab Assistant

## What It Is

Our team proposes a low-cost, highly accessible lab robotic arm intended for use by students, educators, and small scale labs around the world. This design addresses the lack of access to advanced laboratory automation technologies in underfunded educational and research environments. By implementing additive manufacturing through 3D printing, open source electronics, and wide range mobility, the platform serves as a flexible, modular, and easily accessible laboratory assistant suitable for both instructional and research applications. <br><br>
Because the arm is primarily created using 3D printed components, the overall cost is reduced by approximately 90% compared to a commercially available lab assistant robot. This substantial cost reduction allows for schools, communities, and institutions to create multiple units, therefore increasing accessibility and supporting hands on, scalable learning experiences.<br><br>
All mechanical designs, electronic schematics, and software components have been released as open source materials. Users can independently manufacture the arm, replace individual components as needed, and modify the design files as per their own needs. This open framework also supports a collaborative ecosystem for shared enhancements, including the addition of new grippers, sensors, tools, and automation scripts, allowing for continuous improvements to the design. <br><br>
The robotic arm was designed with a strong emphasis on its mechanical simplicity, flexibility, and ease of construction. A 7 degree of freedom (DOF) configuration was used to create a range of motion beyond that of a human arm, allowing the system to reach complex orientations. All of the components were modeled using computer aided design (CAD), allowing for precision, control over joint geometry, and tolerances. Cycloidal drive mechanisms are implemented into the assemblies to provide high torque and smooth motion while mitigating or significantly reducing backlash, improving the overall positioning accuracy during laboratory tasks. The design of the end effector allows users to replace individual components, attach custom tools, and even integrate new sensors without having to redesign the entire system.<br><br>
	The robotic arm uses an integrated Controller Area Network (CANBUS) communication system to simplify the signal processing and reduce the amount of internal cabling required. In addition to its communication architecture, the system incorporates computer vision using a YOLOv11-based object detection model. Overall, these features improve system efficiency while supporting scalable and adaptable laboratory automation.<br>


## Why We Made This

   We designed this robotic arm to fill a major gap that we observed in educational and laboratory environments. Most advanced tools that assist with automating procedures are extremely expensive and proprietary, which makes  them inaccessible to students and researchers who work in small scale labs who need the most help from this technology. Though the industrial level robotic arms are relatively common in well funded labs and non-educational environments, their high cost and closed ecosystems make the technology significantly less viable to classrooms that could possibly use this as an educational tool, community labs, and underfunded research labs. <br><br>
   In many labs, repetitive tasks like pipetting, sample transfers, positioning instruments, and handling hazardous materials are done manually by the researchers. This seriously limits the possible efficiency of the lab and increases the likelihood of fatigue, human error, and safety hazards. The current industry systems that could automate these tasks cost tens of thousands of dollars and need hgihly specialized maintenance because of their closed off design, which makes them very unrealistic for small scale labs and most schools. <br><br>
   Our main goal with this design was to create a robotic arm that will help significantly reduce the entry barrier to this technology while still remaining functional and precise. By prioritizing the ability to 3D print the majority of the components, open source electronics, and the modular design, we were able to reduce the cost by almost 90% while still creating a highly capable robotic assistant. This arm can be scaled up into a system of communicating assistive devices that can work together. The reduced cost also makes it possible for a high level lab to deploy several of these arms in comparison to a single high cost version. This system will help schools with low funding and small labs create a much more hands on learning environment, run parallel experiments, and scale their automation of tasks. <br><br>
   We chose to make this project fully open source with minimal protections (Reference MIT Licence, txt and CERN Open Hardware Licence Version - Permissive.txt) because we believe that the development  and usage of this technology should not be limited by proprietary constraints like the majority of mainstream robotics technologies. By releasing all of the CAD files, schematics, and software that we have, we hope that the users of this repository will understand the system itself, repair it on their own, and adapt or even improve on our work. We hope that this approach will encourage learning robotics through doing and designing independently. We would love for the global community on GitHub to improve the design over time by creating new end effectors, tools, control strategies, and AI implementations. <br><br>
   Overall, this robotic arm was designed to spread lab automation. It was created to not just be a tool for innovation but also a platform for developing independent work. We hope that our contribution and efforts here will support education, research, and lab automation by making advanced robotic technologies significantly more affordable and customizable to anyone in the community willing to learn and build this technology further.<br>

## CAD Viewer

<script type="module" src="https://unpkg.com/@google/model-viewer/dist/model- viewer.min.js"></script>

<!-- <model-viewer 
  src="https://akkified.github.io/tsa-engineering-design/cad/model.glb" 
  alt="Interactive CAD model" 
  auto-rotate 
  camera-controls 
  ar 
  style="width: 100%; height: 400px;">
</model-viewer> -->


## Images

### 3D CAD Model
![Render](docs/slc_render.png)
![Robot Arm Gantry View](docs/Robot_Arm+Gantry_View.png)
![Turret CAD View](docs/Turrent_CAD_View.png)
![Turret Electrical Box View](docs/Turret+Electrical_Box_View.png)

### Wiring Diagram
![Render](docs/Schematic_Wiring.png)

### AI Performance (Vision)
![Confusion Matrix](docs/confusion_matrix.png)

### Cycloidal
![Complete Cycloidal](docs/Cycloidal_Complete.png)
![Exploded Cycloidal View](docs/Cycloidal_Exploded_View.png)
![Cycloidal Internal Top View](docs/Cycloidal_Internal_Top_View.png)
![Cycloidal Section View](docs/Cycloidal_Section_View.png)
![Cycloidal Side View](docs/Cycloidal_Side_View.png)
![Final Robot Arm Gantry Electrical](docs/Final_Robot_Arm+Gantry+Electrical.png)
![Gripper Mechanism](docs/Gripper_Mechanism.png)

### Gripper
![Gripper Mechanism](docs/Gripper_Mechanism.png)

## Bill of Materials

| Item | Description | Quantity | Link |
| :--- | :--- | :--- | :--- |
| TSA-26-P-1001 | Gantry Cart Plate - 1/4 Aluminum | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-1002 | Gantry Side Plate - 1/8 Aluminum | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-1003 | Gantry Side Plate 2 - 1/8 Aluminum | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-1004 | Bottom Belt Clamp - PETG | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-1005 | Top Gantry Clamp - PETG | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-1006 | Gantry Drive Block - PETG | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-1007 | Idler Drive Block - PETG | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-1008 | Stepper Drive Shaft - PA | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-1009 | Sideplate Support Block - PETG | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-1010 | Idler Pulley Shaft - PA | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-1011 | Gantry Motor Plate - PETG | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-1012 | Top Idler Shaft - PA | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-1013 | Bearing Clamp Block - PETG | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-1014 | Turret Mega Gear - 1/4 Aluminum | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-1015 | Turret Top Face Plate - PA | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-1016 | Turret Stepper Spur Gear - PA | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-1017 | 16T HTD Pulley - PETG | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-1018 | 12T HTD Pulley - PETG | 2 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| V-SLOT-20x20x500 | V-Slot 20x20x500 Aluminum Rail | 2 | [Link](https://www.amazon.com/dp/B0DY7HTF64) |
| WCP-0643 | HTD 5M 250T 9mm Timing Belt | 1 | [Link](https://wcproducts.com/products/htd-timing-belts-9mm-width) |
| 17HS13-0404S-PG5 | NEMA 17 Stepper Motor 14:1 Gearbox | 6 | [Link](https://www.amazon.com/dp/B00QA8XUGC) |
| 6816-2RS | 80x100x10mm Sealed Ball Bearing | 1 | [Link](https://www.amazon.com/dp/B07RQ4RXDR) |
| TSA-26-P-2001 | Cam Shaft Cap - PPA-CF | 4 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-2002 | Cam Shaft Upper - PPA-CF | 4 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-2003 | Cam Shaft Lower - PPA-CF | 4 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-2004 | ThunderHex Bearing 0.5in ID 1.25in OD | 4 | [Link](https://wcproducts.com/products/wcp-0778) |
| TSA-26-P-2005 | 12x18x4mm Ball Bearing | 16 | [Link](https://www.amazon.com/dp/B082PQ8DC2) |
| TSA-26-P-2006 | Output Shaft - PPA-CF | 4 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-2007 | Backplate - PLA PRO | 4 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-2008 | M5 x 60mm Socket Head Cap Screw | 36 | [Link](https://www.aliexpress.us/item/3256805692722422.html) |
| TSA-26-P-2009 | Housing - PLA PRO | 4 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-2010 | Cycloidal Disk - PPA-CF | 8 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-2011 | 5x9mm Needle Roller Bearing | 72 | [Link](https://www.amazon.com/dp/B07GC7LWPK) |
| TSA-26-P-2012 | Cap Plate - PLA PRO | 4 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-2013 | 30x37x4mm Ball Bearing Z2 | 8 | [Link](https://www.aliexpress.us/item/2255800723290638.html) |
| TSA-26-P-2014 | 4mm Spacer for M5 - PETG | 108 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-2015 | 1/2in Hex Bore Adapter - Thrifty Profile | 4 | [Link](https://wcproducts.com/products/wcp-1121) |
| TSA-26-P-3001 | Base Arm Segment - PETG | 3 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-3002 | Arm Segment Cap Plate - PETG | 4 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-3003 | Gripper Mount Arm Segment - PETG | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-3004 | Turret Mounted Arm Segment - PETG | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-4001 | 29T Spur Gear Non-Powered - PETG | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-4002 | 29T Spur Gear Motor Side - PETG | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-4003 | Claw Cap Plate - PETG | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-4004 | Servo Mount - PETG | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-4005 | Claw Secondary Bar - PETG | 2 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-4006 | Claw TPU Insert | 2 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-4007 | Claw Base - PETG | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-4008 | ArduCAM Snap-In Insert - PETG | 1 | [Link](https://cad.onshape.com/documents/f3370c452f54d75f3c4d6ebc) |
| TSA-26-P-4009 | VL53L0X Distance Sensor | 1 | [Link](https://www.amazon.com/dp/B0B6ZT7NRW) |
| TSA-26-P-4010 | ArduCAM IMX477 Camera | 1 | [Link](https://www.amazon.com/dp/B09VSVB4DT) |
| TSA-26-P-4011 | DSSERVO 30KG Servo Motor | 2 | [Link](https://www.amazon.com/dp/B0CNZSWM3T) |


*update_bom.py is a script
