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
- **lenet_cnn/**
  - Catapult.ccs - setting up work directory for Catapult
  - bias.h - setting pre-trained bias values
  - catapult.log - entire log of terminal output
  - catapult.pinfo - error file
  - convolution.h - definition of convolution layer of lenet
    - two functions - with and without zero padding (?)
  - directives_127000.tcl - catapult project-level directives for various synthesis settings (including specifying target design)
  - expTable.h - table of exponent values
  - fc.h - definition of fully connected layer of lenet
    - three functions - (?)
  - lenet.cpp - the main function - instantiation of the entire network, with convolution, activation, maxpooling and fully connected layers (please see the Lenet link above to undestand the structure)
  - lenet.h - function prototypes for instantiations in lenet.cpp
  - lenet_cnn.h - same as above (?)
  - lenet_tb.cpp - testbench to check accuracy - checks if an (one) image is predicted correctly as its label
  - lenet_tb_Accuracy.cpp - extension of the previous to a specifiable "test size" i.e. number of images
  - pooling.h - definition of pooling layer - reduction of paramters / input size
    - two functions (?)
  - relu.h - definition of  layer - to introduce non-linearity in the network
    - four functions (?)
  - script.tcl - specifying project files to Catapult
  - softmax.h - definition of softmax function (another activation) - using values from expTable.h above
  - test_set_in_small.h - reduced set of images for testbench purposes
  - test_set_out.dat - correct labels for images in previous file
  - weights.h - setting weights for the LeNet network (pretrained) - this project deals with implementation of inference mode
- **pics/** - screenshot snippets from Catapult showing design hierarchy, loops, initiation intervals, and iterations of the synthesis process
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
