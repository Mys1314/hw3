#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int dimension;
  PComparator Comp;
  std::vector<T> data_;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
  dimension = m;
  Comp = c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  int pos = data_.size();
  data_.push_back(item);
  while(pos > 0 && Comp(data_[pos],data_[(pos-1)/dimension])){
    T temp = data_[pos];
    data_[pos] = data_[(pos-1)/dimension];
    data_[(pos-1)/dimension] = temp;
    pos = (pos-1)/dimension;
  }
}



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty heap");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty heap");

  }
  //code from lab
  data_[0] = data_[data_.size()-1];
  data_.erase(data_.end()-1);
  std::size_t index = 0;
  std::size_t child_index = 0;
  while (index*dimension+1 < data_.size()) {
    child_index = index*dimension+1;
    for(int i = 2; i <= dimension; i++){
      if(index*dimension+i < data_.size() && Comp(data_[index*dimension+i],data_[child_index])){
        child_index = index*dimension+i;
      }
    }
    T& current = data_[index];
    T& child = data_[child_index];
    if (Comp(current,child)){
      break;
    }
    T temp = data_[index];
    data_[index] = data_[child_index];
    data_[child_index] = temp;
    index = child_index;
  }
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return data_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return data_.size();
}


#endif

