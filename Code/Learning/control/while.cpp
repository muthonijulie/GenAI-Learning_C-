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