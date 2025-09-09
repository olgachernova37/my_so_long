# 🎮 So Long - A Simple 2D Adventure Game

![Game Status](https://img.shields.io/badge/Status-Completed-brightgreen)
![Language](https://img.shields.io/badge/Language-C-blue)
![Platform](https://img.shields.io/badge/Platform-Linux-orange)


<h1 align="center"> so_long - @42Prague </h1>

<p align="center">:information_source: A small 2D Game made using the MiniLibX Graphics Library - Textures, sprites and tiles included. </p>
<p align="center"><a href="https://github.com/augustobecker/so_long" target="_blank"><img align="center" alt="so_long" src="https://user-images.githubusercontent.com/81205527/179134510-48689e9e-f8e4-4165-be40-2e0ec8f5d60d.png"> </a></p>
<p align="center">123/100 :white_check_mark:</p>
<p align="center"><img src="https://user-images.githubusercontent.com/81205527/174392536-21619238-638a-4173-a77c-1b168c6c7898.png"> </p>

## 📖 What is So Long?

**So Long** is a simple 2D adventure game where you control a character who needs to collect all coins scattered throughout a maze and then escape through the exit. It's like a digital treasure hunt! 

Think of it as a classic arcade-style game similar to Pac-Man, but instead of eating dots, you're collecting coins to unlock your way out.

## 🎯 Game Objective

- **Your Mission**: Navigate through the maze and collect ALL coins (💰)
- **Victory Condition**: After collecting all coins, reach the exit door (🚪)
- **Challenge**: Find the most efficient path while avoiding dead ends!

## 🕹️ How to Play

### Game Controls
- **W** or **↑** - Move Up
- **A** or **←** - Move Left  
- **S** or **↓** - Move Down
- **D** or **→** - Move Right
- **ESC** - Quit the game

### Game Elements
- **P** (👤) - That's you! The player
- **C** (💰) - Coins to collect
- **E** (🚪) - Exit door (only opens after collecting all coins)
- **1** (🧱) - Walls (you can't walk through these)
- **0** (⬜) - Empty space (safe to walk on)

## 🚀 Quick Start Guide (For Everyone!)

### What You'll Need
- A computer running Linux
- About 5 minutes of your time
- Basic familiarity with using a terminal (don't worry, we'll guide you!)

### Step 1: Open the Terminal
1. Press `Ctrl + Alt + T` on your keyboard
2. A black window will appear - this is called a "terminal"
3. Don't worry, it's just a way to give commands to your computer!

### Step 2: Navigate to the Game Folder
```bash
# Type this command and press Enter (replace the path with where you saved the game)
cd /path/to/so_long_game_folder
```

### Step 3: Build the Game
```bash
# This command will prepare the game for you to play
make
```

**What's happening?** The computer is reading the game's source code and converting it into a program you can run. This might take 10-30 seconds.

### Step 4: Start Playing!
```bash
# Replace 'mapname.ber' with any map file from the maps folder
./so_long src/maps/mandatory/valid_maps/map1.ber
```

**Available Maps:**
- `map1.ber` - Beginner friendly
- `map2.ber` - Small challenge  
- `map3.ber` - Medium difficulty
- `map4.ber` - Getting tricky
- `map5.ber` - Advanced
- `map6.ber` - Expert level
- `map7.ber` - Master challenge
- `map8.ber` - Ultimate test

### Step 5: Clean Up (Optional)
```bash
# If you want to remove the compiled files later
make clean
```

## 🛠️ Technical Details (For Developers)

### Compilation Requirements
- GCC compiler
- X11 development libraries
- Make utility

### Build Commands
```bash
make          # Compile the game
make clean    # Remove object files
make fclean   # Remove all generated files
make re       # Rebuild everything from scratch
```

### Project Structure
```
so_long/
├── src/           # Source code files
├── libs/          # External libraries
│   ├── libft/     # Custom C library
│   ├── libftprintf/ # Custom printf implementation
│   └── minilibx/  # Graphics library
├── Makefile       # Build configuration
└── so_long.h      # Header file
```



   ## 🎮 Game in Action
   
   ![Gameplay Demo](screenshots_and_gifs/gameplay.gif)
   
   ### Level 1 Walkthrough
   ![Level 1](screenshots_and_gifs/level1_demo.gif)

## 🏆 Game Features

- **Multiple Levels**: 8 different maps with increasing difficulty
- **Simple Graphics**: Clean, pixel-art style visuals
- **Responsive Controls**: Smooth character movement
- **Win Condition Tracking**: Game tracks your progress
- **Step Counter**: See how efficiently you solve each level

## 🐛 Troubleshooting

### Common Issues

**"Command not found" error:**
- Make sure you're in the correct folder
- Try typing `ls` to see if you can see the game files

**"Permission denied" error:**
- Try running: `chmod +x so_long`

**Game window doesn't appear:**
- Make sure you have X11 installed: `sudo apt-get install libx11-dev`

**Black screen:**
- Check that your map file exists and is in the correct format

## 👨‍💻 About the Developer

This game was created as part of the 42 School curriculum, demonstrating skills in:
- C programming language
- Memory management
- Graphics programming with MiniLibX
- Game logic implementation
- Linux development environment

## 📄 License

This project is created for educational purposes as part of the 42 School curriculum.

---

**Ready to play?** Follow the Quick Start Guide above and start your adventure! 🎮

*Need help? Don't hesitate to ask - gaming should be fun, not frustrating!*
