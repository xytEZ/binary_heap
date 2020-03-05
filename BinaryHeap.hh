#ifndef BINARY_HEAP_HH_
# define BINARY_HEAP_HH_

# include <vector>
# include <functional>

namespace tree
{
  template <typename T,
	    typename T_Comparator = std::less<T>, // Tas-max by default
	    typename T_UnderlyingContainer = std::vector<T>>
  class BinaryHeap
  {
    T_Comparator _comparator;
    T_UnderlyingContainer _uc;
    
  public :
    BinaryHeap() = default;
    BinaryHeap(const BinaryHeap&) = default;
    BinaryHeap(BinaryHeap&&) = default;

    template <typename... T_Args>
    BinaryHeap(T_Args&&...);
    
    BinaryHeap& operator=(const BinaryHeap&) = default;
    BinaryHeap& operator=(BinaryHeap&&) = default;
    void reorganize() noexcept;
    void push(const T&);
    void push(T&&);
    T pop();
    void sort() noexcept;
    std::size_t size() const noexcept;
    
    template <typename T_Functor>
    void apply(const T_Functor&) const;
    
  private :
    void percolateUp(std::uint32_t) noexcept;
    void percolateDown(std::size_t) noexcept;
  };
}

# include "BinaryHeap.tpp"

#endif
