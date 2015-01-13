This read me will give you a brief description of what is in each folder.

code
This folder contains our loaded FPGA and PIC code. Although several variations of it exist, this is a stable rolled back version we can demo. There seems to be segfault in some of the newer versions we haven't hunted down yet. This folder is pretty complex since we modified a lot of existing code/libraries. If you're looking for PIC code, however, you're probably looking for /code/PIC/MDD File System-SD Card/PIC32. That is where our bitbanging interface, spi code, and game logic resides.

debug
Misc code writing when exploring. Not terribly useful, but worth saving.

game_logic_flowchars
The flowcharts used to plan out the game logic. Made with draw.io website.

misc
Some misc files. Again, not terribly useful.

old_code
An older code version.

original_sprites
The original Pokemon 3rd generation sprites. We do not own these, just using them for our fan based project!

our_sprites
The processed versions of the original sprites. Each sprite is named with its number and a _L or _R to indicate which direction they are look in. Each sprite has 3 versions in this folder a PNG version, a TXT version, and an extionsion-less version.
> The PNG version is a regular PNG file. It varies from the original by having black replace transparency and the *_R are flipped.
> The TXT version is an ASCII version of our binary file. That is, each character should represent 1 binary bit when encoded. This just improved readability during design process. We used a Python script to convert these text files into actual binary files.
> The extionsion-less version is the actual binary image files. These files are what the FPGA displays

pokemon_console_version
Contains a stable and development version of the console version of the game. The development version is also currently suffering from a segfault.

python_code_conversion
This folder contains some Python code written to scrape Pokemon data off of webpages and help generate some of the repetitive C code. This code wasn't written for reuse, just to automate some painful tasks.

python_sprite_scripts
This folder contains the Python code used to convert a original Pokemon sprite PNG into our custom file format.

teambuilder
This is the Python code that outputs a custom team binary to be run in our code. The process is pretty painful, since there are a lot of number that need to be specified (i.e., all EV's, IV's, move ids, etc). Even though this feature works, it is generally just easier to hardcode our teams in.