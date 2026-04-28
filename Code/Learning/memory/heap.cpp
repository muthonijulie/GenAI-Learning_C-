#include <iostream>//heap is manually managed memory, you have to allocate and deallocate memory yourself using new and delete keywords. It is used for dynamic memory allocation when the size of data is not known at compile time or when you want to create objects that outlive the scope of a function.


int main(){
    //allocating memory on heap manually
    double* weights=new double[6];
    //assigning values
    weights[0]=0.15;
    weights[1]=0.28;
    weights[2]=0.39;
    weights[3]=0.41;
    weights[4]=0.50;
    weights[5]=0.65;

    std::cout<<"Model weights:"<<std::endl;
    for (int i=0;i<6;i++){
        std::cout<<"weights:"<<i+1<<":"<<weights[i]<<std::endl;


}
delete[] weights;// in heap, memory should be freed when done.
std::cout<<"Memory freed!!"<<std::endl;
return 0;
}