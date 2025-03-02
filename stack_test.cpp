#include <vector>
#include <stdexcept>
#include <iostream>
#include "stack.h"

int main(int argc, char* argv[])
{
  Stack<int> mystack;
  if(mystack.empty()){
    std::cout << "empty" << std::endl;
  }else{
    std::cout << "not empty" << std::endl;
  }
  mystack.push(5);
  mystack.push(4); 
  mystack.push(3); 
  mystack.push(2); 
  mystack.push(1);
  if(mystack.empty()){
    std::cout << "empty" << std::endl;
  }else{
    std::cout << "not empty" << std::endl;
  }
  std::cout << mystack.top() << std::endl;
  std::cout << mystack.size() << std::endl;
  mystack.pop();
  std::cout << mystack.top() << std::endl;
  mystack.pop();    
  mystack.pop();
  std::cout << mystack.top() << std::endl;
  std::cout << mystack.size() << std::endl;  
  return 0;
}