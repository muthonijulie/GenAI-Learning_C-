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