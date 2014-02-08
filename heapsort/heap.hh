#ifndef ASD_HEAP_HH
#define ASD_HEAP_HH

#include <cstdlib>

namespace Asd
{
  
  typedef unsigned long Node;
  
  template<typename Element>
  class Heap
  {
  public:
    Heap();
    ~Heap();
    
    void insert(Element&);
    Element& min();
    void delMin();
    bool empty() const;
    
  private:
    void upheap(Node); 
    void downheap(Node);
    void resize();
    
    unsigned long length_;
    size_t size_;
    Element* tab_;
  };
  
  Node parent(Node n)
  {
    return ((n+1)/2)-1;
  }
  
  Node left(Node n)
  {
    return ((n+1)*2)-1;
  }
  
  Node right(Node n)
  {
    return ((n+1)*2);
  }

  template<typename Element> 
  Heap<Element>::Heap()
    :length_(0), 
     size_(1), 
     tab_(static_cast<Element*>(std::malloc(size_ * sizeof(Element))))
  {}
  
  template<typename Element>
  Heap<Element>::~Heap()
  {
    free(tab_);
  }

  template<typename Element>
  void Heap<Element>::insert(Element& e)
  {
    if(size_ < length_+1)
      resize();
    
    tab_[length_] = e;

    upheap(length_++);
  }

  template<typename Element>
  Element& Heap<Element>::min()
  {
    return tab_[0];
  }

  template<typename Element>
  void Heap<Element>::delMin()
  {
    if(empty())
      return;

    std::swap(tab_[0], tab_[length_-1]);

    length_--;
    
    downheap(0);
  }

  template<typename Element>
  bool Heap<Element>::empty() const
  {
    return length_ == 0;
  }

  template<typename Element>
  void Heap<Element>::upheap(Node node)
  {
    if(node == 0 || tab_[parent(node)] <= tab_[node])
      return;
    
    std::swap(tab_[node], tab_[parent(node)]);

    upheap(parent(node));
  }

  template<typename Element>
  void Heap<Element>::downheap(Node node)
  {
    Node min = node;

    if(left(node) < length_ && tab_[left(node)] < tab_[min])
      min = left(node);

    if(right(node) < length_ && tab_[right(node)] < tab_[min])
      min = right(node);

    if(node != min)
    {
      std::swap(tab_[node], tab_[min]);
      downheap(min);
    }
  }
  
  template<typename Element>
  void Heap<Element>::resize()
  {
    size_ *= 2;
    tab_ = static_cast<Element*>(std::realloc(tab_, size_ * sizeof(Element)));
  }
}

#endif
