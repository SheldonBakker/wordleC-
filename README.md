# WordleCpp

A C++ implementation of the popular word puzzle game Wordle, built with SFML graphics library.

## About

WordleCpp is a desktop Wordle clone where players guess a random 5-letter word within 6 attempts. Features include animated tile flips, word validation against an extensive dictionary, and a clean visual interface.

## Project Structure

```
WordleCpp/
├── src/                    # Source files
│   ├── main.cpp            # Application entry point
│   ├── Game.cpp            # Main game controller
│   ├── GameState.cpp       # Game state and logic
│   ├── WordValidator.cpp   # Word validation
│   └── ui/                 # UI components
│       ├── Renderer.cpp    # SFML rendering
│       ├── Grid.cpp        # Tile grid
│       ├── InputHandler.cpp
│       └── Animation.cpp   # Tile animations
│
├── include/                # Header files
│   ├── Game.hpp
│   ├── GameState.hpp
│   ├── WordValidator.hpp
│   ├── Constants.hpp
│   └── ui/
│       ├── Renderer.hpp
│       ├── Grid.hpp
│       ├── InputHandler.hpp
│       └── Animation.hpp
│
├── data/                   # Embedded word data
│   └── EmbeddedWords.hpp
│
├── resources/              # Game assets
│   ├── fonts/
│   │   └── ClearSans-Bold.ttf
│   ├── words/
│   │   └── valid_guesses.txt
│   ├── icon.png
│   ├── icon.ico
│   └── app.rc
│
├── tests/                  # Unit tests
├── CMakeLists.txt          # Build configuration
└── dist/                   # Distribution builds
```

## Prerequisites

- **C++17** compatible compiler (MSVC, GCC, Clang)
- **CMake 3.21** or newer
- **Git** (for fetching dependencies)

SFML 3.0.0 is automatically downloaded during the build process via CMake FetchContent.

## Building

### Windows (Visual Studio)

```bash
# Clone the repository
git clone https://github.com/yourusername/wordleC-.git
cd wordleC-

# Configure and build
cmake -B build -S .
cmake --build build --config Release

# The executable will be in build/Release/WordleCpp.exe
```

### Windows (MinGW)

```bash
cmake -B build -S . -G "MinGW Makefiles"
cmake --build build
```

### Linux

```bash
cmake -B build -S .
cmake --build build
```

## Running

After building, run the executable from the build directory. The `resources` folder is automatically copied to the output directory during build.

```bash
./build/Release/WordleCpp.exe   # Windows
./build/WordleCpp               # Linux
```

## How to Play

- Type letters A-Z to enter your guess
- Press **Backspace** to remove a letter
- Press **Enter** to submit your guess (must be a valid 5-letter word)
- Tile colors indicate:
  - **Green**: Letter is correct and in the right position
  - **Yellow**: Letter is in the word but wrong position
  - **Gray**: Letter is not in the word
- You have 6 attempts to guess the word
- Press **Enter** after game over to start a new game
- Press **Esc** to quit

## License

This project is open source and available under the MIT License.
