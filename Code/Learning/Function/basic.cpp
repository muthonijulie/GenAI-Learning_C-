#include <iostream>

//function that claculates the loss
double calculateLoss(double predicted, double actual){
    return predicted-actual;

}
int main(){
    double loss=calculateLoss(0.7,1.0);
    std::cout<<"Loss:"<<loss<<std::endl;
    return 0;
}