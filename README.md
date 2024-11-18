# Ecosystem Simulator (Predator-Prey)

## Context
An Ecosystem Simulator models the interactions between organisms, specifically focusing on the dynamics between predators and prey. In this context, the simulator uses the **Lotka-Volterra model** to represent how these populations affect each other over time based on factors like birth rates and predation.

Creating an ecosystem simulator serves several purposes. It's a valuable educational tool that helps students and researchers visualize ecological principles and understand the balance within ecosystems. The simulation can also inform biodiversity studies, conservation efforts, and wildlife management policies by predicting the effects of changes in species populations. Additionally, it allows researchers to explore the potential impacts of climate change on ecosystem dynamics. Overall, the simulator illustrates the interconnectedness of species and emphasizes the delicate balance that sustains biodiversity.

## Description
This project is a C++ simulation designed to model the interactions between predator and prey populations in a closed ecosystem. The simulation leverages object-oriented programming principles to create classes that represent each population and applies the **Lotka-Volterra model** to calculate the changes over time. This project provides a simple console-based simulation where users can observe population changes based on adjustable parameters for birth, death, and predation rates.

## Features
- **Object-Oriented Modeling**: Predator and prey populations are modeled with separate classes.
- **Time-Step Simulation**: Advances in small, discrete time steps to show population changes at each interval.
- **Console Output**: Visualizes population updates with each simulation cycle.
- **No External Dependencies**: Uses only the standard C++ library, making it portable and easy to compile.

## Model Fundamentals
The simulation is based on the **Lotka-Volterra equations**, a pair of differential equations that describe predator-prey dynamics.
- **Prey Growth**: Prey population increases proportionally to its current population and decreases with predator hunting activity.
- **Predator Mortality**: Predator population grows based on prey availability and declines due to natural mortality.

### Equations
1. **Prey Growth**:  
   dP/dt = α⋅P − β⋅P⋅C
   
2. **Predator Growth**:  
   dC/dt = δ⋅P⋅C − γ⋅C

Where:
- **P**: Prey population
- **C**: Predator population
- **α**: Prey birth rate
- **β**: Predation rate
- **δ**: Predator reproduction rate
- **γ**: Predator mortality rate

## Code Structure
- **Predator.h**: Defines the **Predator** class, including parameters like reproduction and mortality rates.
- **Prey.h**: Defines the **Prey** class, including parameters like birth and predation rates.
- **Ecosystem.h**: Manages interactions between predators and prey, applying the Lotka-Volterra equations.
- **main.cpp**: Runs the simulation, initializes parameters, and outputs population changes over time.

---
![Ecosystem Simulator](https://github.com/user-attachments/assets/bb98f503-6a77-4f49-8847-ed6eccd9975c)
