Testing an online method to convert tensorflowJS files to microcontrollers



My first tests using piodide were not very good.


## emsrcipten  


https://wasmbyexample.dev/examples/hello-world/hello-world.c.en-us.html

on linux

```

git clone https://github.com/emscripten-core/emsdk.git
cd emsdk







./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh



// hello.c
#include <stdio.h>

int main() {
  printf("hello, world!\n");
  return 0;
}



emcc hello.c -o hello.js







```


on widows


```

download and unzip

https://github.com/emscripten-core/emsdk.git


emcmdprompt.bat





emsdk install latest
emsdk activate latest



// hello.c
#include <stdio.h>

int main() {
  printf("hello, world!\n");
  return 0;
}



emcc hello.c -o hello.js


```


Presently easiest to work in the main folder as I need to figure out how to sedt the path for it to work in other folders. Have a look at the ```emsdk_env.sh file```



