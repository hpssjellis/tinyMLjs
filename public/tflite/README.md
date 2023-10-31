So it looks like tensorflowJS can now load tflite models. that is huge, I wonder if it can save tflite models?


```
import * as tf from '@tensorflow/tfjs';
import * as tflite from '@tensorflow/tfjs-tflite';

// Load the TFLite model.
const model = await tflite.Model.fromUrl('path/to/your/model.tflite');

// Get the model's input details.
const inputDetails = model.inputDetails[0];

// Create a tensor for the input data.
const input = tf.tensor([inputData], inputDetails.shape, inputDetails.dtype);

// Run inference with the input data.
const output = model.predict(input);

// Log the output data.
console.log(output.dataSync());

```









FRom TFJS to TFLITE

```
const saveResult = await model.save('localstorage://my-model-1');


tensorflowjs_converter --input_format=tfjs_layers_model --output_format=keras tfjs_model.json hdf5_keras_model.hdf5






```


Then in python


```

import tensorflow as tf

# Load the Keras HDF5 model.
keras_model = tf.keras.models.load_model('hdf5_keras_model.hdf5')

# Convert the Keras model to a TFLite model.
converter = tf.lite.TFLiteConverter.from_keras_model(keras_model)
tflite_model = converter.convert()

# Save the TFLite model.
with open('model.tflite', 'wb') as f:
    f.write(tflite_model)


```



To convert to WASM  in the cpython   Tools/wasm folder

```

cd cpython/Tools/wasm
./build.sh

make -j

wasmtime run your_python_script.py





```



a more complex option is   https://thenewstack.io/python-and-webassembly-elevating-performance-for-web-apps/


