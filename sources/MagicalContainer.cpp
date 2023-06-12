#include "MagicalContainer.hpp"

///////////////////////////////////////////////
/// MagicalContainer
//////////////////////////////////////////////
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

/////////////////////////////////////////
// AscendingIterator
/////////////////////////////////////////

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& cont): MagicalContainer::AscendingIterator(&cont)  {
}

MagicalContainer::AscendingIterator::AscendingIterator( MagicalContainer *cont, size_t ind): container(cont), index(ind) {
    for (size_t i = 0; i < cont->size(); i++)
    {
        sortedCollection.push_back(cont->elements[i]); 
    }
    sort(sortedCollection.begin(), sortedCollection.end(), less<int>());
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
    return AscendingIterator(container, 0);
};

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
    size_t end_index = sortedCollection.size();
    return AscendingIterator(container, end_index);
};

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
    if (this->container != other.container) 
        throw runtime_error("");
    else
    {
        index = other.index;
    }
    return *this;
}


bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &otherIter) const
{
    return this->index == otherIter.index && this->sortedCollection == otherIter.sortedCollection;
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
            return index > otherIter.index;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& otherIter) const
{
     if (container != otherIter.container) {
                throw std::runtime_error("Cannot compare iterators from different containers.");
            }
            return index < otherIter.index;
}

int MagicalContainer::AscendingIterator::operator*()
{
    if (container == nullptr || index >= container->size()) {
                throw std::runtime_error("Iterator is out of range.");
            }
            return sortedCollection[index];
}
    
 MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
{
    if(index == this->sortedCollection.size())
    {
        throw runtime_error("");
    }
    ++index;
    return *this;
}


static MagicalContainer::AscendingIterator begin(MagicalContainer& container) {
            return MagicalContainer::AscendingIterator(container);
        }

        static MagicalContainer::AscendingIterator end(MagicalContainer& container) {
            return MagicalContainer::AscendingIterator(container);
        }
////////////////////////////////////////////////////
//SideCrossIterator
///////////////////////////////


MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& cont): MagicalContainer::SideCrossIterator(&cont)  {
}

MagicalContainer::SideCrossIterator::SideCrossIterator( MagicalContainer *cont, size_t ind): container(cont), index(ind) {
    for (int i = 0; i < cont->size() /2 +1 ; i++)
    {
        if(i < (int)cont->size() -i - 1)
        {
        sortedCollection.push_back(cont->elements[(size_t)i]); 
        sortedCollection.push_back(cont->elements[(size_t)((int)cont->size() -i - 1)]);
        }
        else if (i == (int)cont->size() -i - 1)
           sortedCollection.push_back(cont->elements[(size_t)i]);
    }
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
    return SideCrossIterator(container, 0);
};

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
    size_t end_index = sortedCollection.size();
    return SideCrossIterator(container, end_index);
};

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
    if (this->container != other.container) 
        throw runtime_error("");
    else
    {
        index = other.index;
    }
    return *this;
}


bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &otherIter) const
{
    return this->index == otherIter.index && this->sortedCollection == otherIter.sortedCollection;
}


bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& otherIter) const
{
    return !(*this == otherIter);
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& otherIter) const
{
    if (container != otherIter.container) {
                throw std::runtime_error("Cannot compare iterators from different containers.");
            }
            return index > otherIter.index;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& otherIter) const
{
     if (container != otherIter.container) {
                throw std::runtime_error("Cannot compare iterators from different containers.");
            }
            return index < otherIter.index;
}

int MagicalContainer::SideCrossIterator::operator*()
{
    if (container == nullptr || index >= container->size()) {
                throw std::runtime_error("Iterator is out of range.");
            }
            return sortedCollection[index];
}
    
 MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++()
{
    if(index == sortedCollection.size())
    {
        throw runtime_error("cant increase");
    }
    ++index;
    return *this;
}


/////////////////////////////////////////////////////////////////////
// PrimeIterator
////////////////////////////////////////////////////////////////////
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& cont): MagicalContainer::PrimeIterator(&cont)  {
}

MagicalContainer::PrimeIterator::PrimeIterator( MagicalContainer *cont, size_t ind): container(cont), index(ind) {
    for (size_t i = 0; i < cont->size(); i++)
    {
        if(isPrime(cont->elements[i]))
            sortedCollection.push_back(cont->elements[i]); 
    }
    sort(sortedCollection.begin(), sortedCollection.end(), less<int>());
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
    return PrimeIterator(container, 0);
};

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
    size_t end_index = sortedCollection.size();
    return PrimeIterator(container, end_index);
};

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
    if (this->container != other.container) 
        throw runtime_error("");
    else
    {
        index = other.index;
    }
    return *this;
}


bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &otherIter) const
{
    return this->index == otherIter.index && this->sortedCollection == otherIter.sortedCollection;
}


bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& otherIter) const
{
    return !(*this == otherIter);
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& otherIter) const
{
    if (container != otherIter.container) {
                throw std::runtime_error("Cannot compare iterators from different containers.");
            }
            return index > otherIter.index;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& otherIter) const
{
     if (container != otherIter.container) {
                throw std::runtime_error("Cannot compare iterators from different containers.");
            }
            return index < otherIter.index;
}

int MagicalContainer::PrimeIterator::operator*()
{
    if (container == nullptr || index >= container->size()) {
                throw std::runtime_error("Iterator is out of range.");
            }
            return sortedCollection[index];
}
    
 MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++()
{
    if(index == sortedCollection.size())
    {
        throw runtime_error("cant increase");
    }
    ++index;
    return *this;

}


bool MagicalContainer::PrimeIterator::isPrime(int num)
{
    if(num == 1)
        return false;
    if(num == 2)
        return true;
    
    for (size_t i = 2; i < num; i++)
    {
        if(num % (int)i == 0)
            return false;
    }
    return true;
    
}