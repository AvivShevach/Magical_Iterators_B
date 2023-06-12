#include "MagicalContainer.hpp"

void MagicalContainer::addElement(int element)
{
    elements.push_back(element);  //.add(element);
}

int MagicalContainer::size()
{
    return elements.size();
}

vector<int> MagicalContainer::getCollection() const
{
    return elements;
}

void MagicalContainer::removeElement(int element)
{
     auto it = find(elements.begin(), elements.end(), element);

    // Check if the element was found
    if (it != elements.end()) {
        // Erase the element from the vector
        elements.erase(it);
     //   std::cout << "Element removed successfully!" << endl;
    } 
    else
    {
        throw runtime_error("Element not found in the vector.");
    }
}

//AscendingIterator

// MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& cont, int index = 0): container(cont){

// //sortedCollection = cont;
// for (size_t i = 0; i < cont.size(); i++)
// {
//    sortedCollection.push_back(cont.elements[i]); 
// }

// sort(sortedCollection.begin(), sortedCollection.end(), greater<int>());

// }

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other)
 {
    if (this != &other)
        {
        container = other.container;
        index = other.index;
    }
    return *this;
 }
// MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
//     return AscendingIterator(cont, cont.size());
// }
// MagicalContainer::AscendingIterator::AscendingIterator(std::vector<int>::const_iterator iterator) : iter(iterator) {

// };


// bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator otherIter) const
// {
//     return this->index == otherIter.index;
// }

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& otherIter) const
{
    return container == otherIter.container && index == otherIter.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& otherIter) const
{
    return !(*this == otherIter);
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& otherIter) const
{
    if (container != otherIter.container) {
                throw std::runtime_error("Cannot compare iterators from different containers.");
            }
            return index < otherIter.index;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& otherIter) const
{
     if (container != otherIter.container) {
                throw std::runtime_error("Cannot compare iterators from different containers.");
            }
            return index > otherIter.index;
}

int MagicalContainer::AscendingIterator::operator*()
{
    if (container == nullptr || index >= container->size()) {
                throw std::runtime_error("Iterator is out of range.");
            }
            return container->elements[(vector<int>::size_type)index];
}
    
 MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
{
    if(index + 1 > this->container->size())
    {
        throw runtime_error("cant increase");
    }
    ++index;
    return *this;
}

// MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(MagicalContainer& container)
// {
//             return AscendingIterator(container);
// }

// MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(MagicalContainer& container)
// {
//     return AscendingIterator(container, container.size());
// }

static MagicalContainer::AscendingIterator begin(MagicalContainer& container) {
            return MagicalContainer::AscendingIterator(container);
        }

        static MagicalContainer::AscendingIterator end(MagicalContainer& container) {
            return MagicalContainer::AscendingIterator(container, container.size());
        }



// PrimeIterator
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& otherIter) const
{
    return this->index == otherIter.index;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& otherIter) const
{
    return this->index != otherIter.index;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& otherIter) const
{
    return this->index > otherIter.index;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& otherIter) const
{
    return this->index < otherIter.index;
}