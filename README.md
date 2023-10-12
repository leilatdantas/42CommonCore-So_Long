<p align="center">
 <img src=https://img.shields.io/github/last-commit/leilatdantas/42CommonCore-So_Long?style=plastic&logo=github&labelColor=%23a667d6 /> 
<img src="https://img.shields.io/badge/125_%2F_100_%E2%98%86-success?style=plastic" />
</p>

<h1 align="center">So Long 🎮</h1>

## Table of Contents
- [Project Description 📋](#desc)
- [Getting Started 🚀](#start)
- [Bonus 🎁](#bonus)
- [Resources 📦](#resources)
- [Cross-Platform Compatibility 🖥️](#compatibility)

<a name="desc"></a>
## Project Description 📋
So_Long is a 42 project that challenges you to create a simple 2D game using the MinilibX library. The objective is to create a game where the player must navigate through a maze while collecting items and avoiding enemies. It's a great opportunity to practice your skills in graphics and game development.

<a name="start"></a>
## Getting Started 🚀
Clone this repository:
```bash
git clone https://github.com/leilatdantas/42CommonCore-So_Long.git
```
Compile the project: 
```bash
make
```
Run the game:
```bash
./so_long maps/map.ber
```
<p align="center">
  <img src="https://media.giphy.com/media/tVQLCJtAhfcdix64Yz/giphy.gif" alt="So Long Mandatory">
</p>

<a name="bonus"></a>
## Bonus 🎁
In the bonus version of the game, I've introduced animated characters, including random-moving enemies that you must skillfully avoid.
Compile the bonus: 
```bash
make bonus
```
Now, to play the bonus version, you can find the maps in the "bonus" folder.
Run the game:
```bash
./so_long maps/bonus/valid3.ber
```

<p align="center">
  <img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExaDUzaXc4cWVjbGV5amI2ZnN4aXFieHkxZGxyczdzaHRlaHMyYjZ2ZSZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/LEF41VQ8XJWxrKbCsl/giphy.gif" alt="So Long Bonus">
</p>

**Feel free to experiment with various maps provided in the 'maps' folder.**

<a name="resources"></a>
## Resources 📦
- [Subject PDF](en.subject.pdf)
- [MinilibX Guide](https://qst0.github.io/ft_libgfx/man_mlx.html) 
- [MinilibX Guide](https://harm-smits.github.io/42docs/libs/minilibx) - by hsmits and jvan-sni
- [MinilibX Tutorial](https://pulgamecanica.herokuapp.com/posts/minilibx-tutorial) - by arosado
- [MinilibX Starter Pack](https://pulgamecanica.herokuapp.com/posts/mlx-starter-pack) - by arosado
- [MLX Animations](https://pulgamecanica.herokuapp.com/posts/mlx-animations) - by arosado
- [Draw a Pollock painting with the minilibX](https://www.youtube.com/watch?v=9eAPbNUQD1Y) - by Oceano
- [Free Game Sprites](https://itch.io/game-assets/new-and-popular/free/tag-sprites)
- [Sprite Editor](https://ezgif.com/sprite-cutter)
- [PNG to XMP converter](https://anyconv.com/png-to-xpm-converter/)

<a name="compatibility"></a>
## Cross-Platform Compatibility 🖥️ 
I understand the importance of ensuring that the project compiles and runs smoothly on different operating systems, including Windows and Linux, even though they may have different library files.

If you encounter any compilation issues, please follow these steps:

1. **Check Library Installation:** Verify that you have the required libraries installed on your system. Depending on your operating system, you may need to use different libraries or package managers. Ensure you have the MinilibX library properly installed.

2. **Library Version:** Double-check that you are using the correct version of the libraries required for your platform. Sometimes, library versions can differ between systems.

3. **Makefile Adjustments:** Our provided Makefile is designed to work across different platforms. However, if you still encounter issues, review the Makefile and make necessary adjustments to accommodate your system.

4. **Seek Support:** If the issue persists, don't hesitate to seek help from your fellow developers or instructors. The 42 community is always ready to assist and provide solutions.

By following these steps, you can maximize the compatibility of the project across different systems and ensure a smooth compilation process. Remember, it's essential to have the required libraries properly installed to avoid any potential issues.
