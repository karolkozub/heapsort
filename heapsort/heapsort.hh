#ifndef ASD_HEAPSORT_HH
#define ASD_HEAPSORT_HH

#include "heap.hh"

namespace Asd
{
  template<typename Element>
  void heapsort(Element* tab, int size)
  {
    Heap<Element> heap;

    for(int i = 0; i < size; ++i)
    {
      heap.insert(tab[i]);
    }
    for(int i = 0; i < size; ++i)
    {
      tab[i] = heap.min();
      heap.delMin();
    }
  }
}

#endif
