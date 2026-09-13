# Bohr Atom Simulation ⚛️

A visual physics simulation built in C++ that models the Bohr atom. This project demonstrates electron orbits, trigonometric positioning, and (upcoming) wave mechanics for photon emission and absorption.

## Features
* **Accurate Orbital Mechanics:** Electrons orbit the nucleus using continuous trigonometric transformations rather than static frames.
* **Real-time Rendering:** Built with [Raylib](https://www.raylib.com/) for smooth 2D graphics.
* **Wave Mechanics (WIP):** Implementing photon travel using sine wave functions to represent wavelength ($\lambda$) and amplitude.

## The Physics (Under the Hood)
The simulation translates theoretical physics into visual math:
* **Orbit Calculation:** Uses standard circular motion equations to update position per frame based on a central coordinate and a radius.
* **Photon Energy (Planned):** Will calculate wavelength using the Planck-Einstein relation:
  $$ \lambda = \frac{hc}{E} $$

## Prerequisites
To build this project from source, you will need:
* **C++ Compiler** (GCC/MinGW or MSVC)
* **CMake** (Version 3.10 or higher)
* **Raylib** (Configured locally in `external/raylib/`)

## Build Instructions
This project uses CMake for building. From the root of the project directory, run:

```bash
mkdir build
cd build
cmake ..
cmake --build .