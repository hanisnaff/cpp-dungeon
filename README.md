# Tiny Dungeon

A small turn-based terminal dungeon game written in **C++17**.

## Features
- Explore a compact grid-based dungeon
- Collect treasure and find the exit
- Avoid a roaming monster
- Manage your health

## Build and run
Requires a C++17 compiler and CMake 3.16+.

```bash
cmake -S . -B build
cmake --build build
```

Run `build/tiny_dungeon` on Linux/macOS or `build\Debug\tiny_dungeon.exe` on Windows with Visual Studio.

## Controls
- W / A / S / D: move
- Q: quit

## Map legend
- `@`: player
- `$`: treasure
- `M`: monster
- `E`: exit
- `#`: wall

## Related projects
- [Tic-Tac-Toe AI](https://github.com/hanisnaff/cpp-tictactoe-ai)
- [Snake](https://github.com/hanisnaff/cpp-snake)
- [Portfolio](https://github.com/hanisnaff/README)

## License
MIT
