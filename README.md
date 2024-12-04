# so_long

A tile-based adventure game built in C using the MLX42 graphics library. The player navigates a map, collects items, avoids monsters, and aims to reach the exit.

## Features

- **Graphics**: Textures for walls, ground, collectables, player, exit, and monsters.
- **Player Movement**: Navigate using keyboard controls.
- **Game Objectives**:
  - Collect all items to unlock the exit.
  - Avoid monsters to survive.
- **Dynamic Gameplay**: Includes random monster movements.
- **Flood Fill Algorithm**: Ensures map accessibility and validates the game's layout.

## Requirements

To build and run the project, you need:

- **C Compiler** (e.g., `gcc`)
- **MLX42 Library**: A lightweight graphics library.

## Installation and Setup

1. Clone the repository:

   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```

2. Install the **MLX42** library. For most Unix-based systems, refer to [MLX42](https://github.com/codam-coding-college/MLX42).

3. Modify the `Makefile` if needed to match your environment's configuration.

## Compilation

To compile the project, run:

```bash
make
```

This will produce an executable named `so_long`.

## Running the Game

Start the game by running:

```bash
./so_long <map_file>.ber
```

- `<map_file>.ber`: The path to a `.ber` file that defines the map layout.

### Example:

```bash
./so_long maps/sample_map.ber
```

## Controls

- **W / Arrow Up**: Move Up
- **A / Arrow Left**: Move Left
- **S / Arrow Down**: Move Down
- **D / Arrow Right**: Move Right
- **ESC**: Exit the game

## Notes

- The map file must be surrounded by walls and contain:
  - Exactly one player (`P`)
  - One exit (`E`)
  - At least one collectable (`C`)
- The game validates the map for proper format and accessibility using a flood-fill algorithm.

## Advanced Features

- **Monster Movement**: Monsters move randomly across the map, adding a layer of challenge.
- **Image Textures**: Uses `.png` files for graphical elements.
- **Game Over Conditions**:
  - Player reaches the exit after collecting all items: **You Win!**
  - Player collides with a monster: **Game Over**

## License

This project is open-source and available under the MIT License. Contributions are welcome!

---

Good luck and have fun exploring the game!
