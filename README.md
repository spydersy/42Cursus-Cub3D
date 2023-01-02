# Cub3D


Cub3D is a project made in C and was about building a 3D Game with [MiniLibX](https://github.com/keuhdall/images_example) using **Ray Casting Algorithm**. And without any external Library/Framework.

## MiniLibX
MiniLibX is a tiny graphics library which allows you to do the most basic things for rendering something in screens without any knowledge of X-Window and Cocoa. It provides so-called simple window creation, a questionable drawing tool, half-ass image functions and a weird event management system.
[MiniLibX documentation.](https://harm-smits.github.io/42docs/libs/minilibx)

## Run:
* Ensure that MLX is installed on your machine
* `$> make`
* run `./cub3D <CONF_FILE>` to execute the program or `./cub3D <CONF_FILE> --save` to take a screenshot of the first frame.
* You can edit the configuration file as you want:
  - **NO, EA, SO, WE** : Texture files in xpm format.
  - **C, F** : Floor and ceiling colors in RGB format.
  - **S** : Sprite object in xpm format.
  - **R** : Screen resolution.
  - The Map must be closed and can contain :
    - **0** : empty space.
    - **1** : wall.
    - **2** : sprite object.
    - **N, S, W, E** : player start position and spawning orientation.
   
### Example of a validated config file :

```
NO         xpm/N.xpm
C          25,153,0
EA         xpm/E.xpm
SO         xpm/S.xpm
WE         xpm/W.xpm
S          xpm/SP.xpm
F          25,51,255
R          1000 1000

 111111111111111111111111111111111111111111              1      111111111
1000000000000000000000000000000000000000001             101     100000001
 111111111111111111111111111111111111111111              1      100010101
                                                        1111    100010101
                                                        1111     111 1 1
                                                         11
                                                        1001
                11111  11111111111111111111             10001
           1111100001  100011111000000001001            100001
        1111100000001  100000011010111111101            1000001
  1111111100000000001  10000000000011    101            10000001
  1000000000000000001  10000000000111   11011111111     100000001
  1100000000000000001  10000000000001   11000000001     1000000001
  1111111111111111111  11111110111111   11111111101     11101100001
                            10001               101     100000000001
  11111111111111111     111110001111111111111   101111  1000000000001
 111000000000000011    1100000000000000000001   100001  10000000000001
  10000000000000001    1000000000000000000001   1100011 10000000000001
  11000000000000011    1100000000000111110001   1000001 10000010000001
  1000000000000001      1000000000001   10001   1000001 1000000000001
  11000000000000011111111000000000001   10001   11000011100000000001
   1000000100000010100000100000010001  100001   1000000000000000001
   100000000000000N000000000001111111   11111  1000111111000000001
   10000000002000000020000000000001            10001    100200001
 111000000000202000000000010001111111111111111110001    10000001
 111111000020000000000000100000000000000000000000001    1000001
     11111100000000000000000011111111111111111000001    100001
         1111110000000000111111            111111111    10001
             11111111111111                             1001
                                                        101
                                                        11
                                                        1
```

# Demo:
- The left and right arrow keys of the keyboard allow you to look left and right in the maze.
- The W, A, S, and D keys allow you to move the point of view through the maze.
- Pressing ESC close the window and quit the program cleanly.
- Clicking on the red cross on the window’s frame close the window and
quit the program cleanly.

### ./cub3D map.cub --save :
![saveCub3D GIF](https://github.com/spydersy/42Cursus-ft_containers/blob/master/gif/saveCub3D.gif)

### ./cub3D map.cub :
![Cub3D GIF](https://github.com/spydersy/42Cursus-ft_containers/blob/master/gif/cub3D.gif)

