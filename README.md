## OpenGL Fractals
______________
An C++ and OpenGL implementation to dynamically visualize the recursion and derecursion of fractals

#### Current Fractals
* Dragon Curve
* Koch Snowflake
* Sierpinski Triangle
* Uniform Mass Triangle

#### TODO:
* Hilbert Curve

### Running
Please load the main cmake project, build, then run.

This application was run and tested on the following platforms

* macOS Monterey 12.6
* Linux Mint 20
#### Issue with Linux you might encounter
When running on Linux Mint I encountered a CMAKE problem

```bash
-- Using X11 for window creation
CMake Error at thirdparty/glfw-3.3.2/CMakeLists.txt:206:
    RandR headers not found; install libxrandr development package
 ```

I fixed this by installing the libxranr development package as suggested by this GitHub issue
https://github.com/openMVG/openMVG/issues/85
```bash
sudo apt-get install xorg-dev libglu1-mesa-dev
```
That fixed my issue

## Photos
