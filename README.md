# AI Powered Robotic Arm Lab Assistant

## A customizable, low cost robotic arm created to serve as an educational and lab-based assistant using AI based processing to understand and operate in its environment

## What It Is

## Why We Made This

   We designed this robotic arm to fill a major gap that we observed in educational and laboratory environments. Most advanced tools that assist with automating procedures are extremely expensive and proprietary, which makes  them inaccessible to students and researchers who work in small scale labs who need the most help from this technology. Though the industrial level robotic arms are relatively common in well funded labs and non-educational environments, their high cost and closed ecosystems make the technology significantly less viable to classrooms that could possibly use this as an educational tool, community labs, and underfunded research labs. <br><br>
   In many labs, repetitive tasks like pipetting, sample transfers, positioning instruments, and handling hazardous materials are done manually by the researchers. This seriously limits the possible efficiency of the lab and increases the likelihood of fatigue, human error, and safety hazards. The current industry systems that could automate these tasks cost tens of thousands of dollars and need hgihly specialized maintenance because of their closed off design, which makes them very unrealistic for small scale labs and most schools. <br><br>
   Our main goal with this design was to create a robotic arm that will help significantly reduce the entry barrier to this technology while still remaining functional and precise. By prioritizing the ability to 3D print the majority of the components, open source electronics, and the modular design, we were able to reduce the cost by almost 90% while still creating a highly capable robotic assistant. This arm can be scaled up into a system of communicating assistive devices that can work together. The reduced cost also makes it possible for a high level lab to deploy several of these arms in comparison to a single high cost version. This system will help schools with low funding and small labs create a much more hands on learning environment, run parallel experiments, and scale their automation of tasks. <br><br>
   We chose to make this project fully open source with minimal protections (Reference MIT Licence, txt and CERN Open Hardware Licence Version - Permissive.txt) because we believe that the development  and usage of this technology should not be limited by proprietary constraints like the majority of mainstream robotics technologies. By releasing all of the CAD files, schematics, and software that we have, we hope that the users of this repository will understand the system itself, repair it on their own, and adapt or even improve on our work. We hope that this approach will encourage learning robotics through doing and designing independently. We would love for the global community on GitHub to improve the design over time by creating new end effectors, tools, control strategies, and AI implementations. <br><br>
   Overall, this robotic arm was designed to spread lab automation. It was created to not just be a tool for innovation but also a platform for developing independent work. We hope that our contribution and efforts here will support education, research, and lab automation by making advanced robotic technologies significantly more affordable and customizable to anyone in the community willing to learn and build this technology further.<br>



## Images

### 3D CAD Model
![Render](docs/slc_render.png)
*Full assembly*

### AI Performance (Vision)
![Confusion Matrix](docs/confusion_matrix.png)
*Confusion matrix from the YOLOv11 training*


## Bill of Materials

| Item | Description | Quantity | Link |
| :--- | :--- | :--- | :--- |
| Raspberry Pi 5 | 8GB RAM AI Controller | 1 | [Link](https://www.raspberrypi.com/products/raspberry-pi-5/) |
| Arduino Mega | Motor Interface | 1 | [Link](https://store.arduino.cc/products/arduino-mega-2560-rev3) |
| NEMA 17 Stepper | Actuators | 5 | [Link](https://www.adafruit.com/product/324) |
| L298N Motor Driver | Silent Stepper Drivers | 5 | [Link](https://www.amazon.com/gp/product/B07BK1QL5T/?AssociateTag=sacsite-20&tag=sacsite-20) |


*update_bom.py is a script
