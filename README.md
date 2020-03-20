# UCSD CSE 237C Winter '20 Final Project
## Neural Network with HLS
High Level Synthesis implementation of the [LeNet neural network](https://en.wikipedia.org/wiki/LeNet) for recognition of handwritten digits, trained on the [MNIST database](http://yann.lecun.com/exdb/mnist/) (a large collection of images of handwritten digits). Xilinx Vivado HLS is used for developement and the design is targeted for a variant of the Xilinx Zynq 7000 FPGAs. A Mentor Graphics' Catapult HLS version of the design has also been implemented targeted for an Application-Specific IC.

![LeNet](images/lenet.gif)
  
## Prerequisites
- Xilinx Vivado HLS - Design and Optimization
- Mentor Catapult HLS - Design and Optimization
- Jupyter Notebook(with TensorFlow) for Training, Evaluation, and Demo

## File structure
### Catapult
- **lenet_cnn_baseline/** - Contains the unoptimized version of LeNet
  - **reports/** - Contains Area and Timing csv reports of Baseline design from Catapult
  - bias.h - pre-trained bias values of LeNet
  - convolution.h - definition of convolution layers of lenet
    - with and without zero padding
    - accepts variable kernel and image sizes
    - works with different strides
  - expTable.h - table of exponent values
  - fc.h - definition of fully connected layers of lenet
  - lenet.cpp - Top-Level LeNet Function - instantiates layers from header files
  - lenet.h - function prototypes, datatypes, and NN parameters
  - lenet_tb.cpp - testbench to verify design with 1 input image from MNIST
  - pooling.h - definition of pooling layer - reduction of paramters / input size
  - relu.h - definition of  rectified linear unit layer
  - script.tcl - sets up project and constraints. add files to project
  - softmax.h - definition of softmax function - uses expTable.h
  - weights.h - pre-trained weights of LeNet
  - image*.dat - single image inputs

- **lenet_cnn_opt/** - Contains optimized version of LeNet. Has similar structure as baseline but with optimized code
  - **reports/** - Contains Area and Timing csv reports of Optimized design from Catapult
  - directives.tcl - contains the list of directives applied in Catapult to achieve the final optimized design of LeNet
 
 
### Vivado
- **Layers/** - every folder has its own directives.tcl (Vivado synthesis settings), log file, script.tcl (project file specification), and a **syn/** folder with a synthesis report and XML file
  - convolution/ - convolution layer (with 0 padding)
  - convolution_nopad/ - convolution layer without padding, meaning image gets "smaller" with every layer
  - fc/ - fully connected layer - "end" of most networks
  - flatten/ - unrolling image into one long array
  - pooling/ - a form of parameter reduction
  - relu/ - rectified linear unit activation
  - relu_fc/ - rectified linear unit activation for the dimensions of the FC layer
  - softmax/ - softmax activation (normalized exponential)
- **LeNet/**
  - syn/ - synthesis reports and XMLs of every layer in the complete optimized LeNet instatiation
  - syn_baseline/ - the baseline equivalent of the above
  - syn_old/ - an old version of the above
  -  _all the other files are Vivado equivalents of the same files in **Catapult/lenet_cnn/** - no algorithmic changes_ 
### Walkthroughs
- **Demo/**
  - LeNet.ipynb - Demo jupyter notebook running LeNet prediction on one image
  - design_1_wrapper.bit - (?)
  - design_1_wrapper.hwh - (?)
  - image_<x>_in.dat - some actual images (in matrix form) from the MNIST database
- **python/**
  - LeNet_NCHW2.h5 - (??)
  - LeNet_Train2.ipynb - jupyter notebook running Lenet training (with tensorflow) and prediction on one image
  -  _all the other files are similar jupyter notebooks running each layer of LeNet_ 
## Conclusion
The LeNet network was implemented in C++, synthesized using two industry-leading tools, and mapped to a hardware descriptive language - with "hardware-friendly" optimizations to the code such as loop unrolling, memory partitioning, pipelining etc - using a number of directives and pragmas (some of which are specific to the tool).
