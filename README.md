# FDF

This was the start of my journey in graphic programming, FdF offers to visualize “iron wire” meshing in 3D.
The program is supposed to read from a file (X, Y, Z) values, where X is the rows, Y is the columns and Z is height value.

# How to use it?

***REALLY IMPORTANT: You MUST have the graphical library used in the whole project called MinilibX installed and a MacOS in order to
use the keys to interact with the shapes!***

> git clone "my repo URL" "your folder path"

You can compile it through a Makefile in the root of my Repo
> make

This will compile my library with useful C functions, the graphical library MiniLibX and my FDF files,
creating an executable called **fdf**

In order to run the executable, type:
> ./fdf "file name you would like it to display"

**Buttons**
- Arrow Keys -------->"Move the drawing around in the window"
- W Key --------------->"Increase drawing height"
- S Key ---------------->"Decrease drawing height"
- I Key --------------->"Change to Isometric Projection"
- P Key --------------->"Change to Parallel Projection"
- Left Mouse Button -->"Change color"
- NumPad + Key ------>"Zoom in"
- NumPad - Key ------>"Zoom out"
- ESC Key ----------->"Close Program"

![Image of Subject](https://github.com/MuSuareZ/FDF/blob/master/42logo.png)
![Image of Subject](https://github.com/MuSuareZ/FDF/blob/master/mars.png)

***Remember that each coordinate should be separated by one space, check the file test.txt as an example***

***PS: You should always ignore the quotation marks, they are just comments of what you should input***
