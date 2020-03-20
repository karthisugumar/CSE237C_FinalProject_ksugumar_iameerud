# UCSD CSE 237C Winter '20 Final Project
## Neural Network with HLS
High Level Synthesis implementation of the [LeNet neural network](https://en.wikipedia.org/wiki/LeNet) for recognition of handwritten digits, trained on the [MNIST database](http://yann.lecun.com/exdb/mnist/) (a large collection of images of handwritten digits). Xilinx Vivado HLS is used for developement and the design is targeted for a variant of the Xilinx Zynq 7000 FPGAs. A Mentor Graphics' Catapult HLS version of the design has also been implemented targeted for an Application-Specific IC.

![LeNet](images/lenet.gif)
  
## Prerequisites
- Xilinx Vivado HLS - Design and Optimization
- Mentor Catapult HLS - Design and Optimization
- Jupyter Notebook(with TensorFlow) for Training, Evaluation, and Demo

## File structure
- **Vivado/**
  - **Layers/** - contains optimized versions of all layers. every folder has its own script.tcl for setting up project, and a **syn/** folder with a synthesis report and XML file.
    - convolution/ - convolution layer(with zero padding)
    - convolution_nopad/ - convolution layer(without padding)
    - fc/ - fully connected layer
    - flatten/ - unwind 3-dimensional tensor into 1-dimensional array
    - pooling/ - maxpool layer
    - relu/ - rectified linear unit activation for convolution layers
    - relu_fc/ - rectified linear unit activation for FC layers
    - softmax/ - softmax activation(normalized exponential)
  - **bitwidth_opt/** - contains synthesis reports of several, variable bitwidth experiments(more details in project report)
  - **demo/** - contains synthesis report of design with AXI4 interface used for demo
  - **lenet_cnn_baseline/** - 
    - **reports/** - contains Vivado synthesis report of unoptimized design
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
  - **lenet_cnn_opt/** - Contains code for optimized design. Has same file structure as baseline
      - **reports/** - contains Vivado synthesis report of Optimized design
      - lenet_tc_Accuracy.cpp - testbench developed to find accuracy of HLS design with 500 test images
      - expTable_400.h - contains exponential lookup table with 400 resolution(not used due to low accuracy)
  - **\*.PNG** - snippets of synthesis reports of baseline and optimized designs from Vivado 
    
    
- **Catapult/**
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
    
    
- **Demo/**
  - demo.ipynb - Jupyter notebook to run LeNet on PYNQ. Predicts several test samples and total runtime is measured to evaluate 10000 test images(Requires connection with PYNQ Z2) 
  - LeNet_wrapper.bit - bitstream generated using optimized design
  - LeNet_wrapper.hwh - hardware handoff file from Vivado
  - testset_x.dat.npy - numpy file that contains 10000 testset images
  - testset_y.dat.npy - numpy file that contains 10000 testset labels
  - image_<x>_in.dat - some actual images(in vector from) from the MNIST database
  - **synth/report/** - contains Vivado synthesis report for design with AXI4 interface used in demo

- **python/**
  - LeNet_Train.ipynb - jupyter notebook to train Lenet(with tensorflow) and evaluation on testset
  - LeNet_NCHW2.h5 - pretrained weights for LeNet(obtained from LeNet_Train.ipynb)
  - \*_tb.ipynb - jupyter notebooks to generate necessary files for layer-wise and complete testbenches
  - softmax_expTable.ipynb - jupyter notebook to generate exponential lookup table for softmax layer
  - LeNet_extract_weights.ipynb - jupyter notebook to extract weights & biases of convolution and fc layers of LeNet. Essential for LeNet design.
  - **data/** - contains all files dumped from above jupyter notebooks
 
- **images/**
  - contains images used in report and captured from tools while working on the project
  
## Conclusion
The LeNet network was implemented in C++, synthesized using two industry-leading tools, and mapped to a hardware descriptive language - with "hardware-friendly" optimizations to the code such as loop unrolling, memory partitioning, pipelining etc - using a number of directives and pragmas (some of which are specific to the tool).
