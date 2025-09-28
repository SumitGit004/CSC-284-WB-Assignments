#include<print>
#include<memory>
using namespace std;


int main() {
    
   //raw pointer to demonstrate memory leak
   char *rawCharArrayPointer = nullptr;
 
   //smart pointer to demonstrate memory leak prevention
  // unique_ptr<char []> smartCharArrayPointer; 
  
    int size = 15;
    while(true) {
    
     // assigning dynamically allocated char array of size 15 in each iteration of inifinte loop
    rawCharArrayPointer = new char[size]{};
  
     
    // smartCharArrayPointer  = make_unique<char []>(size);

     println("{} bytes of memory allocated\n", size);
     
     
     //commenting the below line to demonstrate memory leak.
    delete[] rawCharArrayPointer;
     }
   
     return 0;
}