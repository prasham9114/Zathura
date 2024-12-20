# Zathura: The Space Adventure

Zathura: The Space Adventure is a 2D arcade-style space shooter game built using C++ and SFML (Simple and Fast Multimedia Library). In this game, players navigate a spaceship, defeat enemies, and aim for a high score while surviving waves of enemy attacks.

## Table of Contents

- [Features](#features)
- [Gameplay](#gameplay)
- [Installation](#installation)
- [How to Play](#how-to-play)
- [Controls](#controls)
- [Screenshots](#screenshots)
- [Dependencies](#dependencies)
- [Credits](#credits)

## Features

- **Dynamic Gameplay**:  
  Dodge incoming enemies and projectiles. Shoot and destroy enemies to earn points.
  
- **Health Bar**:  
  A visual representation of your spaceship's remaining health.
  
- **Game Over Screen**:  
  Displays when the player’s health reaches zero.
  
- **Point Tracking**:  
  Keep track of your score as you progress.

- **Enemy Spawning**:  
  Enemies spawn at random positions and move towards the player.

- **Smooth Animations**:  
  Built with the high-performance SFML framework for smooth gameplay.

## Gameplay

Take control of your spaceship to destroy enemies and survive for as long as possible. Dodge enemy ships and bullets to avoid damage. Your goal is to achieve the highest score possible!

## Installation

### Prerequisites

- C++ Compiler (e.g., GCC, MSVC)
- SFML 2.6.1 (or compatible version)

### Steps

1. Clone this repository to your local machine:
    ```bash
    git clone https://github.com/your-repo/zathura-game.git
    ```

2. Install SFML (if not already installed):

   **Linux**:
    ```bash
    sudo apt-get install libsfml-dev
    ```

   **Windows**:
   - Download the precompiled SFML library from [SFML Downloads](https://www.sfml-dev.org/download.php).
   - Configure your project to include SFML headers and libraries.

3. Build the project:

   - Using Makefile:
     ```bash
     make
     ```

   - Using your IDE (e.g., Visual Studio or Code::Blocks):
     - Add all source files to the project.
     - Link SFML libraries (`graphics`, `window`, `system`).

4. Run the executable:
    ```bash
    ./zathura
    ```

## How to Play

1. Launch the game.
2. Use the keyboard to move your spaceship and dodge enemies.
3. Fire bullets to destroy enemies and earn points.
4. Survive for as long as possible. When your health reaches zero, the game ends.

## Controls

- **W/A/S/D**: Move the spaceship (Up/Left/Down/Right).
- **Mouse Left Button**: Shoot bullets.
- **Escape**: Quit the game.

## Dependencies

- **SFML 2.6.1**: Simple and Fast Multimedia Library for graphics, audio, and input.

## Credits

- **Developer**: Prasham Desai
- **Font**: Knight Warrior
- **Game Assets**: Bullets and enemy sprites are sourced from your game’s asset library.

---

Enjoy the game! Feel free to contribute or suggest improvements.
