# ICTP Presentation July 2023
Version 0.2.0-7  

### qrcode
<a href="#introduction"> Next Page </a>



Finding the fun, while teaching machine learning with microcontrollers to the general population.

<img src="https://github.com/hpssjellis/tinyMLjs/assets/5605614/c1ebc04f-cf69-40fb-b662-1b828558fa25" width=300 />

QR Code is for this link <https://hpssjellis.github.io/tinyMLjs/public/acceleration/a00-best-acceleration.html> To the main acceleration TinyMLjs webpage

[TinyMLjs](https://github.com/hpssjellis/tinyMLjs) by Jeremy Ellis. My Github Profile at <https://github.com/hpssjellis>



</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  

### Introduction

<a href="#about-me"> Next Page </a>

1. When I heard of the ICTP <a href="https://indico.ictp.it/event/10185">Workshop on Widening Access to TinyML Network by Establishing Best Practices in Education</a>, I was eager to connect with like-minded educators who could collaborate on creating an engaging method for teaching machine learning on microcontrollers to a wider audience.<br><br>
1. By "fun," I mean an approach that is open-source, powerful, fosters a passion for learning, enables building proof of concepts, affordable, fast, user-friendly, operates on the client-side, ensures security, covers the entire process, supports future edge devices, is hardware and internet/cloud independent.<br><br>


</br>  
</br>  
</br>  
</br>  
</br>  
</br>  

</br>  
</br>  
</br>  
</br>  
</br>  

</br>  
</br>  
</br>  
</br>  
</br>  

</br>  
</br>  
</br>  
</br>  
</br>  

### About-Me

<a href="#progress"> Next Page </a>

1. I am Jeremy Ellis, known online as @rocksetta, jerteach, or hpssjellis. As an unconventional learner, I am self-taught in machine learning but probably have no chance of a PhD. My strength lies in simplifying technology.<br><br>
1. Around 2017 I made a [machine learning curriculum based on TensorflowJS](https://hpssjellis.github.io/beginner-tensorflowjs-examples-in-javascript/), but deprecated it when I found out about EdgeImpulse.com<br><br>
1. My Robotics course is called [Maker100](https://github.com/hpssjellis/maker100) based on the Arduino PortentaH7 with LoRa vision Shield and the corresponding PortentaH7 library is called the [Portenta Pro Community Solutions](https://github.com/hpssjellis/portenta-pro-community-solutions) with over 100 of my examples relevant to my course.<br><br>
1. With 48 years of computer programming experience, 35 years of teaching high school coding, 30 years of obsession with coding neural networks, and 8 years of teaching robotics and TensorflowJS on microcontrollers (the last 3 using EdgeImpulse.com), the only constant in my journey has been the deprecation of my work.<br><br>
1. The only consistent thing about teaching coding for that many years is the amount of times all my work has been deprecated! It doesn't matter if the cloud platform has been sold: (Cloud9 to AWS) or the software has been updated: (Too many to mention), or the IDE has changed (Arduino IDE 1.8.19 to 2.10), the board has changed (too many to mention) the software has changed (Python 2 to Python 3),  and each deprecation destroys any relevant lesson plans or videos.<br><br>
1. One of the methods that has been reasonably stable is Javascript, mainly because it's script tag can be versioned<br>  
   &#60;script src="https://cdn.jsdelivr.net/npm/@tensorflow/tfjs@4.8.0"> </script><br><br>
1. However, converting TensorflowJS machine learning to microcontrollers has been a challenge. Although I managed to accomplish it years ago [here](https://github.com/hpssjellis/my-examples-for-the-arduino-portentaH7/tree/master/m09-Tensoflow/tfjs-convert-to-arduino-header) (though it may be deprecated now), it may no longer be necessary. If data from any hardware can be saved as a CSV file, it can later be loaded onto any cloud platform.

</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  


### Progress

<a href="#tinymljs-csv"> Next Page </a>

1. At the start of June 2023 I had successfully implemented  desktop  webSerial/polyfill (also works on Android Pixel Phones) and achieved functionality for saving microcontroller data to CSV files. I also experimented with using coPilot, chatGPT, and BingChat.<br><br>
1. In summary, I accomplished in a much shorter timeframe what I initially believed would take a year. On a webpage, we can now load raw CSV data or data directly from a connected microcontroller using the `println()` command to a desktop or laptop computer. We can clean the data if necessary, convert it to a tensor, train a machine learning model, load more data, clean and classify it, and finally send the classification results back to the microcontroller (e.g., turning on an LED, etc).<br><br>
1. All this functionality is encapsulated in approximately 1000 lines of code on a single webpage, allowing for quick testing of machine learning viability with any sensor data from any microcontroller.<br><br>
1. Since CSV files can be saved, you can now load that data onto your favorite cloud platform, such as EdgeImpulse.com, for microcontroller programming.<br><br>



</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  

</br>  
</br>  
</br>  
</br>  
</br>  

### tinyMLjs-csv

<a href="#tinymljs-tensor"> Next Page </a>  

Let's have a look at sections of the webpage:

Click `Choose Files` to select CSV files. Currently, the file name is important, and there are no column headings—just raw, cleaned data.   

<img src="https://github.com/hpssjellis/tinyMLjs/assets/5605614/faf822e4-3080-4e21-ac9a-efe8e8e42d47" alt="tensor" title="tensor"  width="900px" />





</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  


</br>  
</br>  
</br>  
</br>  
</br>  

### tinyMLjs-tensor

<a href="#vision-model"> Next Page </a>

Information here about number of samples, and sensors. Click ```Convert Data to Tensor``` then ```Train Model```. View console ctrl-shift-i for any issues<br>
Here we can save the model or upload a previously saved model. Note: Labels are not loaded with the model. This is a work in progress.<br>
<img src="https://github.com/hpssjellis/tinyMLjs/assets/5605614/0d185e27-94dd-4461-b7b3-2f1da75acfc0" alt="model" title="model"  width="900px" />




</br>  
</br>  
</br>  
</br>  

</br>  
</br>  
</br>  
</br>  
</br>  
</br>  

</br>  
</br>  
</br>  
</br>  
</br>  


### Vision-Model

<a href="#sound-model"> Next Page </a>
   
This section focuses on tuning a vision model.<br>

<img src="https://github.com/hpssjellis/tinyMLjs/assets/5605614/c40ba2f5-6634-4df1-830e-3b4d7b261c2a" alt="vision" title="vision" width="500px" />

</br>  
</br>  
</br>  
</br>  

</br>  
</br>  
</br>  
</br>  

</br>  
</br>  


### Sound-Model

<a href="#sensor-model"> Next Page </a>

Here, we can tune a sound model.<br>

<img src="https://github.com/hpssjellis/tinyMLjs/assets/5605614/c9698885-aea6-470e-87b1-8da57aa1a953" alt="sound" title="sound"  width="700px" />

</br>  
</br>  
</br>  
</br>  

</br>  
</br>  
</br>  
</br>  
</br>  
</br>  

</br>  
</br>  
</br>  
</br>  
</br>  

### Sensor-Model

<a href="#tinymljs-webserial"> Next Page </a>

This section demonstrates the model for acceleration or any other sensor combination.<br>

<img src="https://github.com/hpssjellis/tinyMLjs/assets/5605614/07125d95-adba-4dd2-810d-61105aa7658f" alt="sensor" title="sensor"  width="900px" />

</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  


</br>  
</br>  
</br>  
</br>  
</br>  


### tinyMLjs-webSerial

<a href="#tinymljs-chart"> Next Page </a>

Here is where we connect a microcontroller ```Connect via Serial Port``` Then ```Clear and send Start ```<br>
```Clean``` check the label name and ```Keep``` and/or ```Save CSV``` checking the file name.<br>

When using more than two labels, you can return to the model training part of the webpage to train your model.<br>


<img src="https://github.com/hpssjellis/tinyMLjs/assets/5605614/234de628-32be-46a1-b63e-d3413d0e1b8d" alt="webserial" title="webserial"  width="900px" />



</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  

</br>  
</br>  
</br>  
</br>  
</br>  

### tinyMLjs-Chart

<a href="#tinymljs-gotchas"> Next Page </a>

Now it is time to test your model. Load more data, clean if needed and click ```Classify Data```<br>
Note that the code to be loaded onto the Nano33BleSense (Rev1) is displayed in the textarea for easy copying.<br>

<img src="https://github.com/hpssjellis/tinyMLjs/assets/5605614/3fcb12d2-67f4-4f32-ad52-55c0ae58b699" alt="chart" title="chart"  width="900px" />



</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  
</br>  

</br>  
</br>  
</br>  
</br>  
</br>  

### tinyMLjs-Gotchas

<a href="#conclusion"> Next Page </a>


<img src="https://github.com/hpssjellis/tinyMLjs/assets/5605614/90ea5bfa-ac04-4042-9319-83e340e33592" alt="gotchas" title="gotchas"  width="900px" />





</br>  
</br>  
</br>  
</br>  


</br>  
</br>  
</br>  
</br>  
</br>  
</br>  




### Conclusion

<a href="#qrcode"> Back to the top</a>

Tutorial playlist Video [here](https://www.youtube.com/watch?v=3f4led32SL8&list=PL57Dnr1H_egsQPnEObWHPhK1Q4g_IDWcR&index=18&pp=iAQB)  
 
Direct link [https://youtu.be/3f4led32SL8](https://youtu.be/3f4led32SL8)


<img src="https://github.com/hpssjellis/tinyMLjs/assets/5605614/f591c01e-50f1-4f7d-be9d-6341b2ba45dd" alt="tinyMLjs" title="tinyMLjs"  width="600px" />








The github is at: <https://github.com/hpssjellis/tinyMLjs>

The index webpage is at <a href="https://hpssjellis.github.io/tinyMLjs/public/index.html">https://hpssjellis.github.io/tinyMLjs/public/index.html</a>

While this presentation represents a starting point, it demonstrates that powerful, proof of concept, end-to-end machine learning on edge devices does not have to rely on the cloud or specific hardware. It can be done in the field or in a classroom without internet access.<br><br>


By Jeremy Ellis @rocksetta  

Github Profile at <https://github.com/hpssjellis>
</br>  
</br>  
</br>  
</br>  
</br>  

</br>  
</br>  
</br>  
</br>  
</br>  

</br>  
</br>  
</br>  
</br>  

</br>  
</br>  
</br>  
</br>  
</br>  

<a href="#qrcode"> Back to the top</a>




