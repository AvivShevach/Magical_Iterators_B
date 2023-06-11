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
        std::cout << "Element removed successfully!" << endl;
    } 
    else
    {
        std::cout << "Element not found in the vector." << endl;
    }
}

//AscendingIterator
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& otherIter) const
{
    return this->index == otherIter.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& otherIter) const
{
    return this->index != otherIter.index;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& otherIter) const
{
    return this->index > otherIter.index;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& otherIter) const
{
    return this->index < otherIter.index;
}

// int MagicalContainer::AscendingIterator::operator*() const
// {
//     return this->MagicalContainer::getCollection().begin()[index];
// }
    

// MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
// {

//    // return *this;
// }



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