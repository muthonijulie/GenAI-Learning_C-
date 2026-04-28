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