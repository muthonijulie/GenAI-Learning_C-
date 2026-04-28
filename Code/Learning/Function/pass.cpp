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