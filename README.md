# Action Platformer Game (C++)

A 2D platform game developed in C++, inspired by classic arcade platformers such as Super Mario. Developed as a group project for the "Computer Programming with C++" course (Academic Year 2024-25).

## Features

- Level progression across multiple stages, each with distinct hazards and mechanics
- Custom AABB (Axis-Aligned Bounding Box) collision system with directional detection (top, bottom, sideways) for accurate platform and obstacle interactions
- Level-specific hazards:
  - Falling bombs that must be avoided (Level 2)
  - Skeleton enemies that damage the player on contact (Level 3)
  - Instant death from falling into sea areas
- Health / lives system with damage and invulnerability cooldown (brief post-hit invulnerability to prevent repeated damage)
- Collectible items (cherries) with animated sprites
- Player animation system (idle, walking, jumping, death states)
- Object-oriented architecture using inheritance and polymorphism (`GameObject` base class hierarchy)
- Dynamic memory management for game entities
- `std::vector` used to store and manage level entities (enemies, collectibles, obstacles)

## Technical Overview

The project uses the **Simple Graphics Library (SGG)** exclusively for window management, input handling, rendering, and audio. All game objects derive from a common `GameObject` base class and are managed through a central `GameState` singleton class, which handles game flow, level transitions, and object lifecycle.

## Built With

- C++
- [Simple Graphics Library (SGG)]
- STL (Standard Template Library)

## How to Build

<!-- Συμπλήρωσε εδώ ανάλογα με το build system σου, π.χ. Visual Studio solution ή Makefile -->

```bash
# example
make
./game
```

## How to Play

- **SPACE** — Start the game / respawn after death
- **A / D** — Move left / right
- **W** — Jump
- **T** — Open settings (from start screen)
- **B** — Return from settings screen (to startscreen)
- Avoid falling bombs (Level 2), skeleton enemies (Level 3), and water — collect cherries and reach the end of each level

## Academic Context

Developed as a group project, coursework for the "Computer Programming with C++" course, Academic Year 2024-25.
