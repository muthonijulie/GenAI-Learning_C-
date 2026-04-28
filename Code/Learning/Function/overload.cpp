#include <iostream>

//overloaded function with same name 
double activate(double value){
    return value>0?value:0;// returns RELU for a single neuron

}
double activate(double value, double threshold){
    return value>threshold?value:0; // return threshold
}
int main(){
    double raw=0.5;
    std::cout<<"Default:"<<activate(raw)<<std::endl;
    std::cout<<"Result with threshold:"<<activate(raw,0.9)<<std::endl;
    return 0;
}