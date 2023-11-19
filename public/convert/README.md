Testing an online method to convert tensorflowJS files to microcontrollers



My first tests using piodide were not very good.


Nov 2023 Best approach is to either use iPython notebooks, which would do the trick or to get tensorflow and tfjs converters converted to WASM.

Presently the best options seem to convert the poython into C/C== code and use emascripten to convert it to  wesassembly code.

reference python t C   https://wiki.python.org/moin/PythonImplementations#Compilers








Below is things that I have tried.

# Pyodide

https://pyodide.org/en/stable/usage/quickstart.html

https://github.com/pyodide/pyodide

pyodide demos

https://hpssjellis.github.io/tinyMLjs/public/convert/pyodide01.html    
https://hpssjellis.github.io/tinyMLjs/public/convert/pyodide02.html    
https://hpssjellis.github.io/tinyMLjs/public/convert/pyodide03.html    
https://hpssjellis.github.io/tinyMLjs/public/convert/pyodide04.html    
https://hpssjellis.github.io/tinyMLjs/public/convert/pyodide05.html    
https://hpssjellis.github.io/tinyMLjs/public/convert/pyodide06.html    
https://hpssjellis.github.io/tinyMLjs/public/convert/pyodide07.html   
https://hpssjellis.github.io/tinyMLjs/public/convert/pyodide08.html   
https://hpssjellis.github.io/tinyMLjs/public/convert/pyodide09.html   
https://hpssjellis.github.io/tinyMLjs/public/convert/pyodide11.html   
https://hpssjellis.github.io/tinyMLjs/public/convert/pyodide12.html   
https://hpssjellis.github.io/tinyMLjs/public/convert/pyodide13.html   
https://hpssjellis.github.io/tinyMLjs/public/convert/pyodide14.html   


#  brython

1.   https://hpssjellis.github.io/tinyMLjs/public/convert/brython01.html
2.   2. https://brython.info/demo.html?lang=en#




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


Found an ipython notebook kind of like mine

https://colab.research.google.com/github/tensorflow/examples/blob/master/lite/examples/gesture_classification/ml/tensorflowjs_to_tflite_colab_notebook.ipynb#scrollTo=FbMsNJ4PAq2j



