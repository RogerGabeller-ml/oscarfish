# Oscarfish
![Oscar|700](https://upload.wikimedia.org/wikipedia/commons/0/08/Astronotus_ocellatus.jpg)


*The Oscar [(Astronotus ocellatus)](https://en.wikipedia.org/wiki/Oscar_(fish)) is known to be a very aggressive species of fish, so you should avoid keeping any small fish in the Oscar fish tank. Besides, **Oscar is also one of the most intelligent fish in the aquarium hobby** *

## Overview

Oscarfish is a [Stockfish](https://github.com/official-stockfish/Stockfish) inspired, [Glaurang](https://github.com/phenri/glaurung) derived chess engine, that has been programmed in C++. Although the implimentation was inspired by [Stockfish](https://github.com/official-stockfish/Stockfish), much of the implimentation has come from the [Chess Programming WIKI](https://www.chessprogramming.org/Main_Page)

## Compilling Oscarfish from this repository
The [Makefile](https://github.com/JunglePython-ml/Oscarfish/blob/master/Makefile) uses a `g++` compiler driver. You should install this before compiling

Then use
``` bash
git clone https://github.com/JunglePython-ml/Oscarfish.git
make
#NOTE: This has only been tested on Ubuntu Linux 20.04.3 LTS
```
to clone from this repository and build.

To run the program execute `./oscarfish` in Unix systems or `oscarfish.exe` if in Windows OS.

## Terms of use
Oscarfish is an opensource chess engine, that is free to use and distribute under the [GNU General Public Licence v3](https://github.com/JunglePython-ml/Oscarfish/blob/master/LICENSE). If you wish to distribute or change the code you must include the source code for any modified or prexisting code.

Any modified or prexisting code should be made avalible under the GPL v3.