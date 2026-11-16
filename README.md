# Tiny Dungeon

A small turn-based terminal dungeon game written in C++17.

## Build and run

Requires a C++17 compiler and CMake 3.16+.

```bash
cmake -S . -B build
cmake --build build
./build/tiny-dungeon
```

## Controls
- W / A / S / D: move
- Q: quit

Collect the treasure ($), avoid the monster (M), and reach the exit (E). You have 5 health points.

## Concepts
2D arrays, structs, functions, turn-based game state, collision rules, and simple enemy behaviour.
