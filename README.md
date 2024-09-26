# bad-term
Simple app to display Bad Apple on terminal as ASCII characters.
# Installation
Currently project only can be installed from the source.
## Build from source
### Requirements
 - CMake v3.15+
 - C++ Compiler with C++17 support
 - NCURSES -  for display and input handling
 - OpenCV 4 - for video and image processing
### Build
``` bash
git clone https://github.com/Ali-SZ/bad-term.git
cd bad-term
mkdir build && cd build
cmake ..
make
```
### Install
```
sudo make install
```
# Usage
`bad-term [arg [...]]`

### Arguments
| Argument | Description |
|--------|-------------|
| `--help`, `-h` | Shows help message and exits. |
| `--reverse`, `-r` | Reverses the character map. |
### Runtime keys
| Key | Description |
|--------|-------------|
| `r` | Reverses the character map. |
| `q` | Quits. |

# License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.