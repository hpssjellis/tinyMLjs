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






