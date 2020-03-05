#include <utility>
#include <stdexcept>

namespace tree
{
  template <typename T, typename T_Comparator, typename T_UnderlyingContainer>
  template <typename... T_Args>
  BinaryHeap<T, T_Comparator, T_UnderlyingContainer>
  ::BinaryHeap(T_Args&&... args) : _uc(std::forward<T_Args>(args)...) { }

  template <typename T, typename T_Comparator, typename T_UnderlyingContainer>
  void BinaryHeap<T, T_Comparator, T_UnderlyingContainer>
  ::reorganize() noexcept
  {
    for (std::uint32_t i = 1; i < _uc.size(); ++i)
      percolateUp(i);
  }

  template <typename T, typename T_Comparator, typename T_UnderlyingContainer>
  void BinaryHeap<T, T_Comparator, T_UnderlyingContainer>::push(const T& value)
  {
    _uc.emplace_back(value);
    percolateUp(_uc.size() - 1);
  }

  template <typename T, typename T_Comparator, typename T_UnderlyingContainer>
  void BinaryHeap<T, T_Comparator, T_UnderlyingContainer>::push(T&& value)
  {
    _uc.emplace_back(std::move(value));
    percolateUp(_uc.size() - 1);
  }

  template <typename T, typename T_Comparator, typename T_UnderlyingContainer>
  T BinaryHeap<T, T_Comparator, T_UnderlyingContainer>::pop()
  {
    std::size_t size = _uc.size();
    
    if (size == 0)
      throw std::out_of_range("No elements for pop");
    
    T value = _uc[0];
    std::size_t newSize = size - 1;

    if (size > 1)
      _uc[0] = _uc[newSize];
    _uc.resize(newSize);
    percolateDown(newSize);
    return value;
  }
  
  template <typename T, typename T_Comparator, typename T_UnderlyingContainer>
  void BinaryHeap<T, T_Comparator, T_UnderlyingContainer>::sort() noexcept
  {
    for (int i = _uc.size() - 1; i >= 0; --i)
      {
	std::swap(_uc[0], _uc[i]);
	percolateDown(i);
      }
  }

  template <typename T, typename T_Comparator, typename T_UnderlyingContainer>
  std::size_t BinaryHeap<T, T_Comparator, T_UnderlyingContainer>
  ::size() const noexcept
  {
    return _uc.size();
  }
  
  template <typename T, typename T_Comparator, typename T_UnderlyingContainer>
  template <typename T_Functor>
  void BinaryHeap<T, T_Comparator, T_UnderlyingContainer>
  ::apply(const T_Functor& functor) const
  {
    for (const auto& value : _uc)
      functor(value);
  }

  template <typename T, typename T_Comparator, typename T_UnderlyingContainer>
  void BinaryHeap<T, T_Comparator, T_UnderlyingContainer>
  ::percolateUp(std::uint32_t elemIndex) noexcept
  {
    if (elemIndex == 0)
      return;
    
    std::uint32_t parentIndex = 0;
    bool swapped = false;
    
    do
      {
	parentIndex = (elemIndex - 1) / 2;
	if (_comparator(_uc[parentIndex], _uc[elemIndex]))
	  {
	    std::swap(_uc[parentIndex], _uc[elemIndex]);
	    elemIndex = parentIndex;
	    swapped = true;
	  }
	  else
	    swapped = false;
      }
    while (parentIndex != 0 && swapped);
  }
  
  template <typename T, typename T_Comparator, typename T_UnderlyingContainer>
  void BinaryHeap<T, T_Comparator, T_UnderlyingContainer>
  ::percolateDown(std::size_t size) noexcept
  {
    if (size < 2)
      return;
    
    std::uint32_t elemIndex = 0;
    std::uint32_t leftChildIndex = 0;
    std::uint32_t rightChildIndex = 0;
    std::uint32_t highestChildIndex = 0;
    std::uint32_t highestIndex = size - 1;
    bool swapped = false;

    do
      {
	leftChildIndex = 2 * elemIndex + 1;
	rightChildIndex = 2 * elemIndex + 2;
	if (rightChildIndex <= highestIndex)
	  {
	    highestChildIndex =
	      _comparator(_uc[leftChildIndex], _uc[rightChildIndex]) ?
	      rightChildIndex : leftChildIndex;
	  }
	else if (leftChildIndex <= highestIndex)
	  highestChildIndex = leftChildIndex;
	if (_comparator(_uc[elemIndex], _uc[highestChildIndex]))
	  {
	    std::swap(_uc[elemIndex], _uc[highestChildIndex]);
	    elemIndex = highestChildIndex;
	    swapped = true;
	  }
	else
	  swapped = false;
      }
    while (elemIndex < highestIndex && swapped);
  }
}
