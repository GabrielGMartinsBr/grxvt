# grxvt (Gabriel's rxvt-unicode)

**grxvt** is a personal fork of the popular terminal emulator [rxvt-unicode (urxvt)](https://wiki.archlinux.org/title/Rxvt-unicode). This project aims to modernize and simplify the codebase by adopting CMake as the build system. It serves both as a learning experience for improving C++ skills and enhancing an essential tool for developers and system administrators.

## Table of Contents
- [grxvt (Gabriel's rxvt-unicode)](#grxvt-gabriels-rxvt-unicode)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Features](#features)
  - [Getting Started](#getting-started)
  - [Building](#building)
  - [Future Roadmap](#future-roadmap)
  - [Contact](#contact)

## Introduction

grxvt is a personal project that aims to modernize and simplify the rxvt-unicode terminal emulator. The project's primary focus is on refactoring the codebase to make it more maintainable and efficient while also serving as a platform for improving C++ programming skills.

## Features

- Integration of CMake as the modern build system.
- Streamlined codebase for enhanced maintainability.
- Adoption of updated compiler flags for improved performance.
- Removal of non-essential features for simplicity and efficiency.
- Improved integration with modern libraries like FreeType and X11.

## Getting Started

To get started with grxvt, follow these steps:

1. Clone the repository: `git clone https://github.com/your_username/grxvt.git`
2. Navigate to the project directory: `cd grxvt`
3. Build the project using CMake: Refer to the [Building](#building) section for instructions.
4. Run the executable: Depending on your setup, the executables might be named `grxvt`, `grxvtc`, and `grxvtd`.

## Building

To build the project, ensure you have CMake installed, then follow these steps:

1. Create a build directory: `mkdir build && cd build`
2. Generate the build files: `cmake ..`
3. Build the project: `cmake --build .`

Note: You might need to adjust the build configurations or install necessary dependencies based on your system.


<!-- ## Contributing

We welcome contributions from the community. If you're interested in contributing, please follow the guidelines detailed in [CONTRIBUTING.md](CONTRIBUTING.md). -->

## Future Roadmap

The project's roadmap includes but is not limited to:

- Refining text selection and clipboard support.
- Creating a dedicated settings window for customization.
- Enhancing performance through code optimizations.
- Incorporating a context menu for improved user interaction.

## Contact

For questions, feedback, or collaboration opportunities, you can reach out to:

- Gabriel - [GitHub Profile](https://github.com/GabrielGMartinsBr)
