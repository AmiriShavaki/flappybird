# Flappybird game using SDL graphics library

### How run executive file?

In order to play the game through executive file you have to copy SDL2.dll and put it inside of the 32 bit windows system directory (i.e WINDOWS\SYSTEM32) SDL2.dll file can be found in flappybird\requirements

Then just run flappybird\bin\Release\flappybird.exe and enjoy

### How compile and run the program?

In order to compile and run the program you have to install SDL2 and codeblocks 12.11 on windows first, and then follow instruction described in below link 
https://lazyfoo.net/tutorials/SDL/01_hello_SDL/index.php 

After all finally you can open flappybird/flappybird.cbp file by codeblocks 12.11 and compile and run the code

### How win the game?

It's simple you have to press spacebar to jump. when you hit the pipes or hit the ground you lose otherwise if your score reach 20 you will win the game.

### How does each file\folder in the project?

**bin\\release\\** An executable version of the project is located there and you can play the game from there. all of the pictures are placed there also.

**obj\\** Output objectfile (i.e main.o) stored there

**pictures\\** This folder contains all of required images of the project

**requirements\\** SDL2.dll stored there. what does this file is described above.

**Bird.h** Bird class

**Graphics.h** Graphics class writen using SDL2 functions by myself

**Hurdle.h** Hurdle class each Hurdle object involves two pipes with same x coordinate

**Score.h** Score class it is not for score calculation it's just for showing the score, all calculations of score are in bird class

**main.cpp** Main program includes mainloop

**flappybird.cbp** Codeblocks project file helps us to linkage our header files to main and use SDL2 in all of our project files

**flappybird.depend and flappybird.layout** Codeblocks files (I didn't write anything in them)

**README.md** A git formated readme file to present the project to you 

**.git\\** Git information files (private repository: gitlab.com/Amiri_Shavaki/flappybird)

**report.docx** Documentation of the project in persian (Word editable version)

**report.pdf** Documentation of the project in persian (PDF read-only version)