#ifndef BINARY_HEAP_HH_
# define BINARY_HEAP_HH_

# include <vector>
# include <functional>

namespace tree
{
  template <typename T,
	    typename TComparator = std::less<T>, // Tas-max by default
	    typename TUnderlyingContainer = std::vector<T>>
  class BinaryHeap
  {
    TComparator _comparator;
    TUnderlyingContainer _uc;
    
  public :
    BinaryHeap() = default;
    BinaryHeap(const BinaryHeap&) = default;
    BinaryHeap(BinaryHeap&&) = default;

    template <typename... TArgs>
    BinaryHeap(TArgs&&...);
    
    BinaryHeap& operator=(const BinaryHeap&) = default;
    BinaryHeap& operator=(BinaryHeap&&) = default;
    void reorganize() noexcept;
    void push(const T&);
    void push(T&&);
    T pop();
    void sort() noexcept;
    std::size_t size() const noexcept;
    
    template <typename TFunctor>
    void apply(const TFunctor&) const;
    
  private :
    void percolateUp(std::uint32_t) noexcept;
    void percolateDown(std::size_t) noexcept;
  };
}

# include "BinaryHeap.tpp"

#endif
