# 🚀 Embedded C Journey: From Software Fundamentals to MCAL Drivers

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Standard](https://img.shields.io/badge/Standard-C99%2FC11-green.svg)]()
[![Domain](https://img.shields.io/badge/Domain-Embedded%20Systems%20%26%20MCAL-orange.svg)]()
[![Architecture](https://img.shields.io/badge/Architecture-Layered%20%26%20Modular-brightgreen.svg)]()

Welcome to my **Embedded C Journey** repository! This repository documents my step-by-step progress in mastering Embedded C programming, clean software architecture, and bare-metal microcontroller abstraction layers (MCAL) targeting production-grade standards.

---

## 📂 Repository Architecture

The project is structured chronologically by weekly learning milestones, separating hardware-independent libraries from hardware-dependent drivers:

```text
Embedded-C-Journey/
├── 01_Week1_GCC_Compilation_Pipeline/
│   ├── main.c                # Source C file
│   ├── main.i                # Preprocessed code
│   ├── main.s                # Assembly code
│   ├── main.o                # Relocatable Object file
│   └── main.exe              # Final Executable
│
├── 02_Week2_Static_Library/
│   ├── BIT_MATH.h            # Bitwise manipulation macros
│   ├── STD_TYPES.h           # Explicit-width data types
│   └── main.c                # Test application
│
├── 03_Week3_DIO_Driver/
│   ├── LIB/                  # Reusable Infrastructure Libraries
│   │   ├── BIT_MATH.h
│   │   └── STD_TYPES.h
│   ├── MCAL/
│   │   └── DIO/              # Microcontroller Abstraction Layer (DIO Driver)
│   │       ├── DIO_interface.h # Public APIs and strongly-typed Enums
│   │       ├── DIO_private.h   # Register memory maps & hidden macros
│   │       └── DIO_program.c   # Driver implementation logic
│   ├── .gitignore            # Excludes compiled binaries from Git tracking
│   └── README.md             # Project documentation
│
└── 04_Week4_Advanced_C_Pointers_Callbacks/
    └── main.c                # Advanced C concepts: Function Pointers, Callbacks & Jump Tables
```

---

## 🛠️ Weekly Breakdown & Milestones

### 🔹 Week 1: C Compilation Pipeline & Under the Hood Execution
**Core Focus:** Understanding how C code translates into executable machine code for microcontrollers.  
**Key Topics:**
* Detailed study of the 4-stage build process: Preprocessing → Compilation → Assembly → Linking.
* Memory layout analysis: `.text`, `.rodata`, `.data`, `.bss`, Stack, and Heap.
* Understanding standard object formats (`.elf`, `.hex`) and linker scripts.

### 🔹 Week 2: Infrastructure Layer (LIB)
**Core Focus:** Building a solid software foundation to ensure code portability, safety, and zero function overhead.  
**Deliverables:**
* **`STD_TYPES.h`:** Resolved cross-compiler data type variations by introducing explicit-width types (`u8`, `u16`, `u32`, `s8`, `f32`, etc.) and standard status enumerations (`ErrorStatus_t`).
* **`BIT_MATH.h`:** Implemented high-performance macros (`SET_BIT`, `CLR_BIT`, `TOG_BIT`, `GET_BIT`, `WRITE_BIT`, `ROR`, `ROL`) with strict operator precedence protection.

### 🔹 Week 3: MCAL Layer - Digital Input/Output (DIO) Driver
**Core Focus:** Bridging pure software with hardware control by implementing a 3-file modular DIO Driver.  
**Architecture & Features:**
* **Information Hiding (`DIO_private.h`):** Encapsulated hardware register addresses away from higher application layers.
* **Public Interface (`DIO_interface.h`):** Exposed strongly-typed Enums and API prototypes.
* **Implementation (`DIO_program.c`):** Combined `BIT_MATH` macros with register dereferencing for optimal execution speed.  
**Core APIs Provided:** `DIO_SetPinDirection()`, `DIO_SetPinValue()`, `DIO_GetPinValue()`, `DIO_SetPortDirection()`, and `DIO_SetPortValue()`.

### 🔹 Week 4: Advanced C Concepts - Pointers, Callbacks & Jump Tables
**Core Focus:** Mastering advanced C pointers, callback mechanisms for architectural decoupling, and Jump Tables for $O(1)$ state management.  
**Key Deliverables:**
* **Function Pointers & Callbacks:** Implemented decoupled communication between asynchronous driver events (e.g., UART transmission complete) and upper application layers without tight coupling.
* **Jump Tables (Array of Function Pointers):** Designed high-performance lookup tables to replace slow conditional branching (`switch-case` / `if-else`) with $O(1)$ time complexity for automotive state machine management.

---

## 🎯 Key Software Engineering Practices Applied
* **Layered Software Architecture:** Complete decoupling between Application, HAL, MCAL, and LIB layers.
* **MISRA C & Clean Code Guidelines:** Explicit data sizing, avoidance of magic numbers, and clear naming conventions.
* **Reusability & Portability:** Drivers engineered to be easily ported across different microcontroller architectures (AVR, ARM Cortex-M).

---

## 🚀 Upcoming Roadmap
* [x] **Week 1-3:** Compilation Pipeline, LIB Infrastructure, and MCAL DIO Driver.
* [x] **Week 4:** Advanced C Concepts - Function Pointers, Callbacks, and Jump Tables.
* [ ] **Week 5:** Memory Mapping & Direct Register Manipulation (Bare-Metal Peripheral Access).
* [ ] **Week 6+:** Interrupts (EXI), Timers & PWM, and Communication Protocols (UART, SPI, I2C, CAN Bus).

---

## 👨‍💻 Maintained by: Ziad Khiralla
**Target Goal:** Automotive Embedded Software Engineer (AUTOSAR / CAN Bus / Real-Time Systems)