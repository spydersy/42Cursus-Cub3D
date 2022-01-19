# 42Cursus-cub3D [![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/abelarif/cub3d)](https://github.com/JaeSeoKim/badge42)

This project is inspired by the world-famous eponymous 90’s game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you’ll have to find your way.

## Goals:
This project’s objectives are similar to all this first year’s objectives: Rigor, use of C, use of basic algorithms, information research etc.
As a graphic design project, cub3D will enable you to improve your skills in these areas: windows, colors, events, fill shapes, etc.
To conclude cub3D is a remarkable playground to explore the playful practical applications of mathematics without having to understand the specifics.
With the help of the numerous documents available on the internet, you will use mathematics as a tool to create elegant and efficient algorithms.<br/>
<p align="center">
	<img src="./imgs/image-011.png" >
</p>
it's recommended to test the original game before starting this project:

http://users.atw.hu/wolf3d/



### Common Instructions:

- You must create a “realistic” 3D graphical representation of the inside of a maze from a first person perspective. You have to create this representation using the Ray-Casting principles mentioned earlier.<br/>

- External functs:
  - open, close, read, write, malloc, free, perror, strerror, exit.
  - All functions of the math library (-lm man man 3 math)
  - All functions of the [MinilibX](https://github.com/spydersy/minilibx-linux).

The constraints are as follows:

- You must use the miniLibX. Either the version that is available on the operating system, or from its sources. If you choose to work with the sources, you will need to apply the same rules for your libft as those written above in Common Instructions part.
- The management of your window must remain smooth: changing to another window, minimizing, etc.
- Display different wall textures (the choice is yours) that vary depending on which side the wall is facing (North, South, East, West).


<!-- - Not interpret unclosed quotes or unspecified special characters like \ or ;.<br/>
- Not use more than one global variable, think about it and be ready to explain why you do it.<br/>
- Show a prompt when waiting for a new command.<br/>
- Have a working History.<br/>
- Search and launch the right executable (based on the PATH variable or by using relative or absolute path)<br/>
- It must implement the builtins:<br/>
  - echo with option -n<br/>
  - cd with only a relative or absolute path<br/>
  - pwd with no options<br/>
  - export with no options<br/>
  - unset with no options<br/>
  - env with no options or arguments<br/>
  - exit with no options<br/>
- ’ inhibit all interpretation of a sequence of characters.<br/>
- " inhibit all interpretation of a sequence of characters except for $.<br/>
- Redirections:<br/>
  - “<“ should redirect input.<br/>
  - “>“ should redirect output.<br/>
  - “<<” read input from the current source until a line containing only the delimiter is seen. it doesn’t need to update history!<br/>
  - “>>” should redirect output with append mode.<br/>
- Pipes | The output of each command in the pipeline is connected via a pipe to the input of the next command.<br/>
- Environment variables ($ followed by characters) should expand to their values.<br/>
- $? should expand to the exit status of the most recently executed foreground pipeline.<br/>
- ctrl-C ctrl-D ctrl-\ should work like in bash.<br/>
- When interactive:<br/>
  - ctrl-C print a new prompt on a newline.<br/>
  - ctrl-D exit the shell.<br/>
  - ctrl-\ do nothing.<br/>

<p readline function can produce some leak you don’t need to fix this.<br/>
But beware your own code should not produce leaks.<br/>
You should limit yourself to the subject description.<br/>
Anything not asked is not required.<br/>
For every point, if you have any doubt take bash as a reference.<br/></p> -->
