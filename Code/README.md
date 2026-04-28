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
g++ (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
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
mkdir ~/cpp-test && cd ~/cpp-test
touch main.cpp
code .
```

Paste into `main.cpp`:

```cpp
#include <iostream>

int main() {
    std::cout << "C++ environment is ready!" << std::endl;
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
C++ environment is ready!
```

---

## Minimal Working Example

**What it does:** Simulates a single neuron — the basic unit of a neural network. It takes inputs, multiplies each by a weight, sums them, and passes the result through a ReLU activation function. This is exactly what PyTorch and TensorFlow do at their C++ core.

```bash
mkdir ~/cpp-ai-intro && cd ~/cpp-ai-intro
touch neuron.cpp
code .
```

```cpp
#include <iostream>
#include <vector>
#include <numeric>

// ReLU activation function
double relu(double value) {
    return value > 0 ? value : 0;
}

// Single neuron: weighted sum + bias + activation
double neuron(const std::vector<double>& inputs,
              const std::vector<double>& weights,
              double bias) {
    double weightedSum = std::inner_product(
        inputs.begin(), inputs.end(), weights.begin(), 0.0
    );
    return relu(weightedSum + bias);
}

int main() {
    std::vector<double> inputs  = {0.5, 0.3, 0.9};
    std::vector<double> weights = {0.4, 0.7, 0.2};
    double bias = 0.1;

    double output = neuron(inputs, weights, bias);
    std::cout << "Neuron Output: " << output << std::endl;

    return 0;
}
```

```bash
g++ neuron.cpp -o neuron
./neuron
```

Expected output:
```
Neuron Output: 0.63
```

---

## Learning Stages

All files go inside `~/cpp-ai-intro/`. Compile each with:
```bash
g++ <filename>.cpp -o <filename>
./<filename>
```

---

### Stage 1 – Variables, Data Types & I/O

```cpp
// stage1.cpp
#include <iostream>
#include <string>

int main() {
    int age           = 25;
    double weight     = 72.5;
    bool isActive     = true;
    char grade        = 'A';
    std::string name  = "Backend Dev";

    std::cout << "Name: "   << name     << std::endl;
    std::cout << "Age: "    << age      << std::endl;
    std::cout << "Weight: " << weight   << std::endl;
    std::cout << "Active: " << isActive << std::endl;
    std::cout << "Grade: "  << grade    << std::endl;

    return 0;
}
```

> **Backend relevance:** These types map directly to what you store in a database — integers for IDs, doubles for prices or model scores, strings for names and tokens.

---

### Stage 2 – Control Flow

**If / Else — Model deployment check:**

```cpp
// stage2_if.cpp
#include <iostream>

int main() {
    double modelAccuracy = 87.5;

    if (modelAccuracy >= 90.0) {
        std::cout << "Model is production ready!" << std::endl;
    } else if (modelAccuracy >= 75.0) {
        std::cout << "Model needs more training." << std::endl;
    } else {
        std::cout << "Model is underperforming. Check your data." << std::endl;
    }

    return 0;
}
```

**For Loop — Batch inference pipeline:**

```cpp
// stage2_loop.cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<double> confidenceScores = {0.95, 0.42, 0.88, 0.31, 0.76};

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
// stage2_while.cpp
#include <iostream>

int main() {
    int epoch    = 1;
    double loss  = 1.0;

    while (loss > 0.2) {
        loss -= 0.15;
        std::cout << "Epoch " << epoch << " | Loss: " << loss << std::endl;
        epoch++;
    }

    std::cout << "Training complete!" << std::endl;
    return 0;
}
```

**Switch — Backend status handler:**

```cpp
// stage2_switch.cpp
#include <iostream>

int main() {
    int statusCode = 2;

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
// stage3_ref.cpp
#include <iostream>

// Pass by VALUE - original unchanged
void doubleByValue(double score) {
    score = score * 2;
    std::cout << "Inside function: " << score << std::endl;
}

// Pass by REFERENCE - modifies original directly
void doubleByReference(double& score) {
    score = score * 2;
    std::cout << "Inside function: " << score << std::endl;
}

int main() {
    double score = 0.5;

    std::cout << "--- Pass by Value ---" << std::endl;
    doubleByValue(score);
    std::cout << "After function: " << score << std::endl;

    std::cout << "\n--- Pass by Reference ---" << std::endl;
    doubleByReference(score);
    std::cout << "After function: " << score << std::endl;

    return 0;
}
```

> **AI relevance:** Large tensors and matrices are always passed by reference to avoid expensive copying. This is how TensorFlow passes data between operations internally.

**Mini Inference Function:**

```cpp
// stage3_inference.cpp
#include <iostream>
#include <vector>
#include <numeric>

double relu(double value) { return value > 0 ? value : 0; }

double runInference(const std::vector<double>& inputs,
                    const std::vector<double>& weights,
                    double bias) {
    double weightedSum = std::inner_product(
        inputs.begin(), inputs.end(), weights.begin(), 0.0
    );
    return relu(weightedSum + bias);
}

int main() {
    std::vector<double> inputs  = {0.5, 0.3, 0.9};
    std::vector<double> weights = {0.4, 0.7, 0.2};
    double bias = 0.1;

    std::cout << "Inference result: " << runInference(inputs, weights, bias) << std::endl;
    return 0;
}
```

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
// stage4_pointers.cpp
#include <iostream>

int main() {
    double modelScore = 0.92;
    double* ptr = &modelScore;   // pointer holds the address

    std::cout << "Value: "        << modelScore << std::endl;
    std::cout << "Dereferenced: " << *ptr       << std::endl;

    *ptr = 0.95;   // modify through pointer
    std::cout << "Updated: "      << modelScore << std::endl;

    return 0;
}
```

**Heap Allocation:**

```cpp
// stage4_heap.cpp
#include <iostream>

int main() {
    double* weights = new double[5];

    weights[0] = 0.12; weights[1] = 0.45; weights[2] = 0.78;
    weights[3] = 0.33; weights[4] = 0.91;

    for (int i = 0; i < 5; i++) {
        std::cout << "w" << i + 1 << ": " << weights[i] << std::endl;
    }

    delete[] weights;   // Always free heap memory
    std::cout << "Memory freed." << std::endl;
    return 0;
}
```

**Smart Pointers (Modern C++):**

```cpp
// stage4_smartptr.cpp
#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<double[]> weights(new double[5]);

    weights[0] = 0.12; weights[1] = 0.45; weights[2] = 0.78;
    weights[3] = 0.33; weights[4] = 0.91;

    for (int i = 0; i < 5; i++) {
        std::cout << "w" << i + 1 << ": " << weights[i] << std::endl;
    }

    // Memory freed automatically - no delete needed
    return 0;
}
```

> **AI relevance:** PyTorch's C++ backend uses smart pointers to manage tensor memory. Every `torch::Tensor` is managed by a smart pointer — this is how it avoids memory leaks at scale.

---

### Stage 5 – Object-Oriented Programming

**Basic Class — Neuron:**

```cpp
// stage5_class.cpp
#include <iostream>
#include <vector>
#include <numeric>

class Neuron {
private:
    std::vector<double> weights;
    double bias;

public:
    Neuron(std::vector<double> w, double b) : weights(w), bias(b) {
        std::cout << "Neuron created with " << weights.size() << " inputs." << std::endl;
    }

    ~Neuron() { std::cout << "Neuron destroyed." << std::endl; }

    double relu(double value) { return value > 0 ? value : 0; }

    double forward(const std::vector<double>& inputs) {
        double weightedSum = std::inner_product(
            inputs.begin(), inputs.end(), weights.begin(), 0.0
        );
        return relu(weightedSum + bias);
    }
};

int main() {
    Neuron neuron({0.4, 0.7, 0.2}, 0.1);
    std::vector<double> inputs = {0.5, 0.3, 0.9};
    std::cout << "Neuron output: " << neuron.forward(inputs) << std::endl;
    return 0;
}
```

**Inheritance — Layer architecture (like PyTorch's `nn.Module`):**

```cpp
// stage5_inheritance.cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

class Layer {
protected:
    std::string layerName;
public:
    Layer(std::string name) : layerName(name) {
        std::cout << layerName << " layer initialized." << std::endl;
    }
    virtual double forward(const std::vector<double>& inputs,
                           const std::vector<double>& weights,
                           double bias) = 0;
    virtual ~Layer() { std::cout << layerName << " layer destroyed." << std::endl; }
};

class ReLULayer : public Layer {
public:
    ReLULayer() : Layer("ReLU") {}
    double forward(const std::vector<double>& inputs,
                   const std::vector<double>& weights,
                   double bias) override {
        double sum = std::inner_product(inputs.begin(), inputs.end(), weights.begin(), 0.0) + bias;
        return sum > 0 ? sum : 0;
    }
};

class SigmoidLayer : public Layer {
public:
    SigmoidLayer() : Layer("Sigmoid") {}
    double forward(const std::vector<double>& inputs,
                   const std::vector<double>& weights,
                   double bias) override {
        double sum = std::inner_product(inputs.begin(), inputs.end(), weights.begin(), 0.0) + bias;
        return 1.0 / (1.0 + std::exp(-sum));
    }
};

int main() {
    std::vector<double> inputs  = {0.5, 0.3, 0.9};
    std::vector<double> weights = {0.4, 0.7, 0.2};
    double bias = 0.1;

    ReLULayer relu;
    SigmoidLayer sigmoid;

    std::cout << "\nReLU output:    " << relu.forward(inputs, weights, bias)    << std::endl;
    std::cout << "Sigmoid output: " << sigmoid.forward(inputs, weights, bias)  << std::endl;
    return 0;
}
```

> **AI relevance:** This mirrors PyTorch's internal architecture exactly. `torch.nn.Module` is the base class; `torch.nn.Linear`, `torch.nn.ReLU`, and `torch.nn.Sigmoid` all inherit from it and override `forward()`.

---

### Stage 6 – The Standard Template Library (STL)

```cpp
// stage6_stl.cpp
#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
#include <string>

int main() {
    // --- VECTOR ---
    std::vector<double> losses = {0.9, 0.75, 0.6, 0.45, 0.2};
    losses.push_back(0.1);
    auto minLoss = std::min_element(losses.begin(), losses.end());
    std::cout << "Best loss: " << *minLoss << std::endl;

    // --- MAP ---
    std::map<std::string, double> metrics;
    metrics["accuracy"] = 0.94;
    metrics["loss"]     = 0.12;
    metrics["f1_score"] = 0.91;

    for (auto& pair : metrics) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // --- TUPLE ---
    std::vector<std::tuple<int, double, double>> trainingLog;
    trainingLog.push_back({1, 0.85, 0.72});
    trainingLog.push_back({2, 0.61, 0.84});
    trainingLog.push_back({3, 0.34, 0.93});

    for (auto& record : trainingLog) {
        std::cout << "Epoch: "   << std::get<0>(record)
                  << " | Loss: " << std::get<1>(record)
                  << " | Acc: "  << std::get<2>(record) << std::endl;
    }

    return 0;
}
```

```bash
g++ stage6_stl.cpp -o stage6_stl
./stage6_stl
```

> **Backend relevance:** Vectors store layer outputs and gradients internally in PyTorch. Maps are used for model registries and config management. Tuples are great for returning multiple values from functions — very common in AI pipelines.

---

## References

| Resource | Link |
|---|---|
| Official C++ Documentation | https://cppreference.com |
| GCC Compiler Docs | https://gcc.gnu.org/onlinedocs/ |
| C++ Tutorial (GeeksforGeeks) | https://www.geeksforgeeks.org/c-plus-plus/ |
| LibTorch (C++ frontend for PyTorch) | https://pytorch.org/cppdocs/ |
| TensorFlow C++ API | https://www.tensorflow.org/api_docs/cc |
| VS Code C++ Setup Guide | https://code.visualstudio.com/docs/languages/cpp |
| Learn C++ (learncpp.com) | https://www.learncpp.com |

---

*Built on Ubuntu/Debian Linux with VS Code. All examples compiled with g++ (GCC). Part of the AI Systems Toolkit series.*