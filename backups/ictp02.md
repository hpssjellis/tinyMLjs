# ICTP Presentation July 2023
Version 0.2.0-7  

### qrcode
<a href="#intro"> Next Page </a>



Finding the fun, while teaching machine learning with microcontrollers to the general population.

<img src="https://github.com/hpssjellis/tinyMLjs/assets/5605614/c1ebc04f-cf69-40fb-b662-1b828558fa25" width=300 />

QR Code is for this link <https://hpssjellis.github.io/tinyMLjs/public/acceleration/a00-best-acceleration.html> To the main acceleration TinyMLjs webpage

TinyMLjs by Jeremy Ellis. Github Profile at <https://github.com/hpssjellis>



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

### Intro

<a href="#j-ellis"> Next Page </a>

1. When I heard of the ICTP <a href="https://indico.ictp.it/event/10185">Workshop on Widening Access to TinyML Network by Establishing Best Practices in Education</a> I wanted to find a group of like minded Educators
who could work for a year on creating a method to teach machine learning on microcontrollers while making it more fun for the general population.<br><br>
1. And by fun I mean: open-source, powerful, can create a passion for learning, building proof of concepts, cheap, fast, easy, client-side, secure, full process, future edge devices now, is hardware independent and also internet/cloud independent<br><br>


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

### J-Ellis

<a href="#progress"> Next Page </a>

1. I am Jeremy Ellis (@rocksetta, jerteach, hpssjellis) machine learning self taught and questionably intelligent.<br><br>
1. My Robotics course is called [Maker100](https://github.com/hpssjellis/maker100) and the corresponding PortentaH7 library is called the [Portenta Pro Community Solutions](https://github.com/hpssjellis/portenta-pro-community-solutions) with over 100 of my examples relevant to my course.<br><br>
1. I have computer programmed for 48 years, taught high school coding for 35, made neural networks for 20, and taught Robotics and TensorflowJS on microcontrollers for 8 with the last 3 using [EdgeImpulse.com](https://www.edgeimpulse.com/)<br><br>
1. The only consistent thing about teaching coding for that many years is the amount of times all my work has been deprecated. It doesn't matter if the cloud platform has been sold: (Cloud9 to AWS) or the software has been updated: (Too many to mention), or the IDE has changed (Arduino IDE 1.8.19 to 2.10), the board has changed (too many to mention) the software has changed (Python 2 to Python 3), and each deprecation destroys any relevant lesson plans or videos.<br><br>
1. One of the methods that has been reasonably stable is Javascript mainly because it's script tag can be versioned
   &#60;script src="https://cdn.jsdelivr.net/npm/@tensorflow/tfjs@4.8.0"> </script><br><br>
1. Quote of Atwood's Law: “Any application that can be written in JavaScript, will eventually be written in JavaScript."<br><br>
1. But Javascript Machine Learning can't be converted to microcontrollers! <br><br>
1. Yes it can, I have done it years ago [here](https://github.com/hpssjellis/my-examples-for-the-arduino-portentaH7/tree/master/m09-Tensoflow/tfjs-convert-to-arduino-header) but perhaps that is not needed, if the data from any hardware
   can be saved as a CSV file, it can later be loaded onto any cloud platform.


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

1. At the start of June 2023 I had webSerial/polyfill (Android Pixel Phones) and microcontroller data to CSV files working and was messing around with pitting coPilot, against chatGPT and BingChat.<br><br>
1. Long story short, I got done what I thought would take a year to do. On a webpage we can now load CSV raw data, or load data directly from a connected microcontroller's ```println();``` command to a webpage on a desktop/laptop computer.
   Clean the data if needed. Then convert that data to a tensor, then train a machine learning model, then load more data, clean and classify that data. If needed send the classification results back to the microcontroller (Turn on an LED etc)<br><br>
1. ~1000 lines of code on a single webpage to load any sensor data from any microcontroller to quickly test if machine learning is a viable option.<br><br>
1. Since you can save the CSV files you can now load that data onto your favorite Cloud platform for programming to the microcontroller.<br><br>



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

Click ```Choose Files```. Presently the file name is important and no column headings just raw, cleaned data   

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

Information here about number of samples, and sensors. Click ```Convert Data to Tensor``` then ```Train Model```. <br>
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
   
Now tuning a model becomes very evident. This is a Sound model.

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

And here is a vision model 

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

and here is what we are interested in the Acceleration or any sensor combination model<br>

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

When done more than 2 labels you can go back to the model training part of the webpage and train your model.


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
Note: The code to be loaded onto the Nano33BleSense (Rev1) is in the textarea so it is easy to copy<br>

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

This is just a rough proof of concept, hopefully with some help it can become a useful tool for helping create some passion for beginning with machine learning on microcontrollers

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

The github is at: <https://github.com/hpssjellis/tinyMLjs>

The index webpage is at <a href="https://hpssjellis.github.io/tinyMLjs/public/index.html">https://hpssjellis.github.io/tinyMLjs/public/index.html</a>

This is just a starting point, but shows that powerful full process machine learning on edge devices does not have to be cloud or hardware dependent, and could be done in the field or in a classroom without internet.<br><br>


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



