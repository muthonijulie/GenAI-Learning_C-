# Getting Started with C++ for AI Systems – A Backend Developer's Deep Dive

> A practical, hands-on guide to learning C++ from scratch with a focus on backend development and AI systems. Built and tested on Ubuntu  Linux with VS Code.

---

## Table of Contents


1. [System Requirements](#system-requirements)
2. [Installation & Setup](#installation--setup)
3. [Minimal Working Example](#minimal-working-example)
4. [Learning Stages](#learning-stages)
   - [Stage 1 – Variables, Data Types & I/O](#stage-1--variables-data-types--io)
   - [Stage 2 – Control Flow](#stage-2--control-flow)
   - [Stage 3 – Functions](#stage-3--functions)
   - [Stage 4 – Memory Management](#stage-4--memory-management)
   - [Stage 5 – Object-Oriented Programming](#stage-5--object-oriented-programming)
   - [Stage 6 – The Standard Template Library (STL)](#stage-6--the-standard-template-library-stl)
5. [References](#references)

---


## System Requirements

| Requirement | Details |
|---|---|
| **OS** | Ubuntu Linux |
| **Compiler** | GCC (g++) |
| **Editor** | VS Code |
| **VS Code Extensions** | C/C++ by Microsoft, Code Runner by Jun Han |
| **Build Tool** | `make` / `cmake` |
| **Package Manager** | `apt` |

---

## Installation & Setup

### Step 1 — Update Your System

```bash
sudo apt update && sudo apt upgrade -y
```

### Step 2 — Install the C++ Compiler

```bash
sudo apt install build-essential -y
```

This installs `gcc`, `g++`, and `make` in one go.

Verify:

```bash
g++ --version
```

Expected output:
```
g++ (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0 
```

### Step 3 — Install CMake

```bash
sudo apt install cmake -y
```

Verify:

```bash
cmake --version
```

### Step 4 — Install VS Code Extensions

Install via terminal:

```bash
code --install-extension ms-vscode.cpptools
code --install-extension formulahendry.code-runner
```

Or search manually in VS Code:
- **C/C++** by Microsoft
- **Code Runner** by Jun Han

### Step 5 — Verify Everything Works

```bash
mkdir cpp-tes && cd cpp-test
touch main.cpp
code .
```

Paste into `main.cpp`:

```cpp
#include <iostream>
int main(){
    std::cout <<"Hello world! C++ environment is ready."<< std::endl;
    return 0;
}
```

Compile and run:

```bash
g++ main.cpp -o main
./main
```

Expected output:
```
Hello world! C++ environment is ready.
```

---

## Minimal Working Example

**What it does:** Simulates a single neuron — the basic unit of a neural network. It takes inputs, multiplies each by a weight, sums them, and passes the result through a ReLU activation function. This is exactly what PyTorch and TensorFlow do at their C++ core.

```bash
mkdir intro && cd intro
touch neuron.cpp
code .
```

```cpp
#include <iostream>
#include <vector>
#include <numeric>

double relu(double value){
    return value>0?value:0;//returns 0 if value equals 0 or negative and value if greater than 0
}
//in this case focus is on neuron which consist of input, output and weights
double neuron(const std::vector<double>& inputs,
//calculate the weighted sum
const std:: vector<double>& weights,
double bias){
    double weightedSum=std::inner_product(
        inputs.begin(),inputs.end(),weights.begin(),0.0);
    //add bias
    weightedSum+=bias;
    //Apply RELU to the weighted sum
    return relu(weightedSum);

}
int main(){
    //examples
    std::vector<double> inputs={0.5,0.3,0.9};
    std::vector<double> weights={0.2,0.4,0.6};
    double bias=0.1;
    double output=neuron(inputs,weights,bias);
    std::cout<<"Output of the neuron: "<<output<<std::endl;
    return 0;
}
```

```bash
g++ neuron.cpp -o neuron
./neuron
```

Expected output:
```
Neuron Output: 0.86
```

---

## Learning Stages

All files go inside `intro/`. Compile each with:
```bash
g++ <filename>.cpp -o <filename>
./<filename>
```

---

### Stage 1 – Variables, Data Types & I/O

```cpp
// data.cpp
#include <iostream>
#include <string>
int main(){
    int age=22;
    double weight=80;
    bool isStudent=true;
    std::string name="Lizzy-Backend dev";
    std::cout<<"Name: "<<name<<std::endl;
    std::cout<<"Age: "<<age<<std::endl;
    std::cout<<"Weight: "<<weight<<std::endl;
    std::cout<<"Is student: "<<std::boolalpha<<isStudent<<std::endl;
    return 0;


}
```
```cpp
//input.cpp
#include <iostream>
#include <string>

int main(){
    std::string name;
    std::cout<<"ENTER YOUR NAME: ";
    std::cin>>name;
    std::cout<<"Hello, "<<name<<"! Welcome to C++ programming."<<std::endl;
    return 0;
}
```

> **Backend relevance:** These types map directly to what you store in a database — integers for age, doubles for weight, strings for names.

---

### Stage 2 – Control Flow

**If / Else — Model deployment check:**

```cpp
// if.cpp
#include <iostream>

int main(){
    double accuracy=90;//simulating model accuracy
    //Evaluate model performance based on accuracy
    if(accuracy>=90){
        std::cout<<"Excellent performance"<<std::endl;
    }
    else if(accuracy>=75){
        std::cout<<"Good performance"<<std::endl;
    }
    else if(accuracy>=60){
        std::cout<<"Average performance"<<std::endl;
    }
    else{
        std::cout<<"Needs improvement"<<std::endl;
    }
    return 0;
}
```

**For Loop — Batch inference pipeline:**

```cpp
// for.cpp
#include <iostream>
#include <vector>

int main() {
    // Simulating a batch of AI model confidence scores
    std::vector<double> confidenceScores = {0.95, 0.42, 0.88, 0.31, 0.76};

    std::cout << "Processing batch predictions..." << std::endl;
// Using a for loop to evaluate each confidence score
    for (int i = 0; i < confidenceScores.size(); i++) {
        if (confidenceScores[i] >= 0.75) {
            std::cout << "Sample " << i + 1 << ": ACCEPTED (score: "
                      << confidenceScores[i] << ")" << std::endl;
        } else {
            std::cout << "Sample " << i + 1 << ": REJECTED (score: "
                      << confidenceScores[i] << ")" << std::endl;
        }
    }

    return 0;
}
```

**While Loop — Training epochs:**

```cpp
// while.cpp
#include <iostream>

int main(){
    int epoch=5;
    double loss=1;
    //keep training until loss is low
    while (loss>0.2){
        loss-=0.15; //simulating loss reduction
        std::cout<<"Epoch"<<epoch
        <<"|Loss:"<<loss<<std::endl;
        epoch++;
    }
    std::cout<<"Training done."<<std::endl;
    return 0;
}
```

**Switch — Backend status handler:**

```cpp
// switch.cpp
#include <iostream>
#include <string>

int main() {
    int statusCode = 2;

    // Simulating a backend API response handler
    switch (statusCode) {
        case 1:
            std::cout << "Status: Model training in progress..." << std::endl;
            break;
        case 2:
            std::cout << "Status: Model ready for inference." << std::endl;
            break;
        case 3:
            std::cout << "Status: Model failed. Check logs." << std::endl;
            break;
        default:
            std::cout << "Status: Unknown state." << std::endl;
    }

    return 0;
}
```

---

### Stage 3 – Functions

**Pass by Value vs Pass by Reference:**

```cpp
// pass by reference and pass by value
#include <iostream>
 //pass by value
 void doubleByValue(double score){
    score*=2;
    std::cout<<"Inside function:"<<score<<std::endl;
  
 }
 //pass by reference
 void doubleByReference(double& score){
    score*=2;
    std::cout<<"Inside function:"<<score<<std::endl;
 }
    int main(){
    double score=0.3;
    std::cout<<"Pass by value:"<<std::endl;
    doubleByValue(score);
    std::cout<<"Apres function:"<<score<<std::endl;
    std::cout<<"\nPass by reference.."<<std::endl;
    doubleByReference(score);
    std::cout<<"Apres function:"<<score<<std::endl;
    return 0;
 }
```

> **AI relevance:** Large tensors and matrices are always passed by reference to avoid expensive copying. This is how TensorFlow passes data between operations internally.

---

### Stage 4 – Memory Management

| | Stack | Heap |
|---|---|---|
| **Managed by** | C++ automatically | You manually |
| **Size** | Limited | Large |
| **Freed when** | Scope ends | You call `delete` |
| **Used for** | Small local variables | Tensors, model weights, large data |

**Raw Pointers:**

```cpp
// pointers.cpp
#include <iostream>
int main(){
    double model=0.95;
    //& means get the address
    //* means pointer
    double* modelPtr=&model;//pointer to model variable
    std::cout<<"Value:"<<model<<std::endl;
    std::cout<<"Address:"<<&model<<std::endl;
    std::cout<<"Pointer holds:"<<modelPtr<<std::endl;
    std::cout<<"Dereferenced:"<<*modelPtr<<std::endl;
    //modifying value through pointer
    *modelPtr=0.75;
    std::cout<<"Apres modification:"<<model<<std::endl;
    return 0;
}
```

**Heap Allocation:**

```cpp
// heap.cpp
#include <iostream>
//heap is manually managed memory, you have to allocate and deallocate memory yourself using new and delete keywords. It is used for dynamic memory allocation when the size of data is not known at compile time or when you want to create objects that outlive the scope of a function.


int main(){
    //allocating memory on heap manually
    double* weights=new double[6];
    //assigning values
    weights[0]=0.15;
    weights[1]=0.28;
    weights[2]=0.39;
    weights[3]=0.41;
    weights[4]=0.50;
    weights[5]=0.65;

    std::cout<<"Model weights:"<<std::endl;
    for (int i=0;i<6;i++){
        std::cout<<"weights:"<<i+1<<":"<<weights[i]<<std::endl;


}
delete[] weights;// in heap, memory should be freed when done.
std::cout<<"Memory freed!!"<<std::endl;
return 0;
}
```

> **AI relevance:** PyTorch's C++ backend uses smart pointers to manage tensor memory. Every `torch::Tensor` is managed by a smart pointer — this is how it avoids memory leaks at scale.

---

### Stage 5 – Object-Oriented Programming

**Basic Class — Neuron:**

```cpp
// class.cpp
#include <iostream>
#include <vector>
#include <numeric>

class Neuron{
    private:
    //this is ony accessible inside the class
    std::vector<double>weights;
    double bias;

    public://accessible everywhere
    //this is a constructor that runs when an object is created
    Neuron(std::vector<double>w,double b):weights(w),bias(b){
        std::cout<<"Neuron created with"<<weights.size()<<"inputs."<<std::endl;
    }
    //this is a destructor that runs when an object is destroyed
    ~Neuron(){
        std::cout<<"Neuron destroyed."<<std::endl;
    }
    double relu(double value){//activation function
        return value>0?value:0;

    }
    //forward pass
    double forward(const std::vector<double>& inputs){
        double weightedSum=std::inner_product(
            inputs.begin(),inputs.end(),weights.begin(),0.0
        );
        return relu(weightedSum+bias);
        
    }
    std::vector<double> getWeights(){
        return weights;
    }
};
int main(){
    //create a neuron object
    Neuron neuron({0.2,0.4,0.6},0.1);
    //forward pass with some inputs
    std::vector<double>inputs={0.5,0.3,0.9};
    double output=neuron.forward(inputs);
    std::cout<<"Outputs:"<<output<<std::endl;
    return 0;
}
```

**Inheritance — Layer architecture (like PyTorch's `nn.Module`):**

```cpp
// inheritance.cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

// BASE CLASS - defines the interface every layer must have
class Layer {
protected:
    std::string layerName;

public:
    Layer(std::string name) : layerName(name) {
        std::cout << layerName << " layer initialized." << std::endl;
    }

    // Virtual - allows child classes to override this method
    virtual double forward(const std::vector<double>& inputs,
                          const std::vector<double>& weights,
                          double bias) = 0; // = 0 means must be implemented

    virtual ~Layer() {
        std::cout << layerName << " layer destroyed." << std::endl;
    }
};

// CHILD CLASS 1 - ReLU activation layer
class ReLULayer : public Layer {
public:
    ReLULayer() : Layer("ReLU") {}

    double forward(const std::vector<double>& inputs,
                  const std::vector<double>& weights,
                  double bias) override {
        double weightedSum = std::inner_product(
            inputs.begin(), inputs.end(), weights.begin(), 0.0
        );
        double result = weightedSum + bias;
        // ReLU - returns 0 if negative
        return result > 0 ? result : 0;
    }
};

// CHILD CLASS 2 - Sigmoid activation layer
class SigmoidLayer : public Layer {
public:
    SigmoidLayer() : Layer("Sigmoid") {}

    double forward(const std::vector<double>& inputs,
                  const std::vector<double>& weights,
                  double bias) override {
        double weightedSum = std::inner_product(
            inputs.begin(), inputs.end(), weights.begin(), 0.0
        );
        double result = weightedSum + bias;
        // Sigmoid - squashes output between 0 and 1
        return 1.0 / (1.0 + std::exp(-result));
    }
};

int main() {
    std::vector<double> inputs  = {0.5, 0.3, 0.9};
    std::vector<double> weights = {0.4, 0.7, 0.2};
    double bias = 0.1;

    // Both layers share the same interface
    // but behave differently internally
    ReLULayer relu;
    SigmoidLayer sigmoid;

    std::cout << "\nReLU output:    "
              << relu.forward(inputs, weights, bias) << std::endl;
    std::cout << "Sigmoid output: "
              << sigmoid.forward(inputs, weights, bias) << std::endl;

    return 0;
}
```

> **AI relevance:** This mirrors PyTorch's internal architecture exactly. `torch.nn.Module` is the base class; `torch.nn.Linear`, `torch.nn.ReLU`, and `torch.nn.Sigmoid` all inherit from it and override `forward()`.

---

### Stage 6 – The Standard Template Library (STL)

```cpp
// tuple.cpp
#include <iostream>
#include <vector>
#include <tuple>

int main() {
    // Store epoch, loss, accuracy together
    std::vector<std::tuple<int, double, double>> trainingLog;

    trainingLog.push_back({1, 0.85, 0.72});
    trainingLog.push_back({2, 0.61, 0.84});
    trainingLog.push_back({3, 0.34, 0.93});

    for (auto& record : trainingLog) {
        std::cout << "Epoch: "    << std::get<0>(record)
                  << " | Loss: "  << std::get<1>(record)
                  << " | Acc: "   << std::get<2>(record) << std::endl;
    }

    return 0;
}
```
```cpp
//map.cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    // Store model metrics by name
    std::map<std::string, double> metrics;

    metrics["accuracy"] = 0.94;
    metrics["loss"]      = 0.12;
    metrics["f1_score"]  = 0.91;

    for (auto& pair : metrics) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
```


```bash
g++ tuple.cpp -o tuple
./tuple
```

> **Backend relevance:** Vectors store layer outputs and gradients internally in PyTorch. Maps are used for model registries and config management. Tuples are great for returning multiple values from functions — very common in AI pipelines.

---

## References

| Resource | Link |
|---|---|
| Official C++ Documentation https://cppreference.com|
| GCC Compiler Docs | https://gcc.gnu.org/onlinedocs/ |
| Learn C++ (Beginner Friendly) https://www.w3schools.com/CPP/default.asp|
| C++ Tutorial — GeeksforGeeks https://www.geeksforgeeks.org/c-plus-plus/|
| Stack Overflow — C++ Tag https://stackoverflow.com/questions/20616961 usr-bin-ld-cannot-find-no-such-file-or-directory|
| C++ real world use
https://www.geeksforgeeks.org/blogs/top-applications-of-cpp-in-real-world/|
---

*Built on Ubuntu/Debian Linux with VS Code. All examples compiled with g++ (GCC). Part of the AI Systems Toolkit series.*