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

