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