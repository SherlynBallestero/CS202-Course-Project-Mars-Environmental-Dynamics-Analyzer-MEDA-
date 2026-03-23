# Mars Environmental Dynamics Analyzer (MEDA)
## CS202 Course Project

---

## Table of Contents
- [Introduction](#introduction)
- [Objectives](#objectives)
- [Learning Outcomes](#learning-outcomes)
- [Project Overview](#project-overview)
- [Technologies](#technologies)
- [Project Structure](#project-structure)
- [Milestones](#milestones)
- [Getting Started](#getting-started)

---

## Introduction

A NASA rover is a mobile robotic system designed to explore and navigate environments that are hazardous or inaccessible to humans. Equipped with wheels or tracks for mobility, these rovers investigate planetary surfaces, moons, and other remote terrains. They collect data using advanced sensors, cameras, and scientific instruments to analyze environmental conditions, surface materials, and physical features.

The C programming language, known for its low-level hardware access, efficient memory management, and reliable performance, is often used to develop embedded systems for such missions. This course project introduces students to a practical C programming scenario, guiding them through the software development process while implementing secure coding practices and modular design.

---

## Objectives

The MEDA project simulates the development of the **Mars Environmental Dynamics Analyzer** to receive, validate, calculate, and store sensory data. The MEDA will handle environmental inputs such as:

- **Temperature** - Environmental temperature readings
- **Windspeed** - Wind velocity measurements
- **Dust Levels** - Atmospheric dust concentration
- **Radiation Levels** - Solar and cosmic radiation exposure

These readings are reported to the **NASA Jet Propulsion Laboratory (JPL)** for analysis and mission planning. The final program will implement modular functions, error checking, calculations, and file operations to produce a working C program suitable for real-world applications.

The project consists of **four (4) milestones**, with submissions in Unit 2, 4, 6, and 8. Each milestone corresponds to specific course topics, incrementally applying secure programming rules and recommendations.

---

## Learning Outcomes

By completing this project, students will:

✓ **Implement secure input validation and error handling**
  - Validate sensor data to ensure accuracy and reliability

✓ **Apply control statements, loops, and operators to process data**
  - Process multiple environmental readings efficiently

✓ **Use arrays, strings, pointers, and structures to manage and organize data**
  - Design data structures for sensor information and mission logs

✓ **Modularize code using functions for clarity and reusability**
  - Create well-organized, maintainable code with clear module separation

✓ **Securely write and read data to and from files**
  - Persist rover data for long-term analysis and archival

✓ **Follow secure coding standards to prevent errors and vulnerabilities**
  - Implement best practices to ensure mission-critical system reliability

---

## Project Overview

The MEDA project simulates a rover's data collection and reporting system. The program receives environmental sensor data, validates it against established criteria, performs necessary calculations, and stores the results for JPL analysis. This mimics real-world rover operations where accurate data handling is critical to mission success.

---

## Technologies

- **Language**: C (C99 or later)
- **Compiler**: GCC
- **IDE**: Visual Studio Code
- **Target Platform**: Windows / Linux / macOS

---

## Project Structure

```
CS202-Course-Project-Mars-Environmental-Dynamics-Analyzer-MEDA-/
├── README.md                    # Project documentation
├── m1_rover_main.c             # Main program file
└── [Additional files per milestone]
```

---

## Milestones

| Milestone | Unit | Focus Areas |
|-----------|------|------------|
| **M1** | Unit 2 | Basic input/output, data types, and simple calculations |
| **M2** | Unit 4 | Arrays, strings, control flow, and validation |
| **M3** | Unit 6 | Functions, modularization, and file I/O |
| **M4** | Unit 8 | Structures, advanced error handling, and system integration |

Each milestone builds upon the previous one, progressively enhancing the MEDA system with new features and secure coding practices.

---

## Getting Started

### Prerequisites
- GCC compiler installed and configured
- Visual Studio Code with C/C++ extension
- Basic knowledge of C programming

### Building the Project
```bash
gcc -o meda m1_rover_main.c
```

### Running the Program
```bash
./meda
```

---

## Contributing

This is a course project for Park University CS202. Students should follow the assignment guidelines and academic integrity policies.

---

## License

This project is developed as part of the CS202 course curriculum at Park University.