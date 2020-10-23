## Github Actions Lua Library Cross Compile (GALLCC)

This library is to test how Github Actions work when cross compiling lua c module libraries.

### To Build
Note this library really does not do anything useful. Building it wont improve your life in any meaningful way.
``` sh
mkdir build
cd build
cmake ../
make
```

### To Run Tests
These are still a work in progress.

``` sh
cd tests
luajit extralib/fennel run.fnl
## lua 5.1 and luajit are binary compatable
# lua5.1 extralib/fennel run.fnl
```
