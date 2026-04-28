#include <iostream>//stack is automatically managed memory, variables are created and destroyed as functions are called and return
 void stackExcercise(){//this is in the stack
    double learningRate;
    int epochs;
//allowsuser to input learning rate and epochs for training a model
    std::cout<<"Learning rate:";
    std::cin>>learningRate;;

    std::cout<<"Epochs:";
    std::cin>>epochs;
    
 }//the 2 variables are automatically destroyed here

 int main(){
    stackExcercise();
    std::cout<<"Function cest complete,stack variable finir"<<std::endl;
    return 0;
 }