#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
namespace ariel{};
class MagicalContainer
{
   private:
        vector<int> elements;

 public:
    void addElement(int);
    int size();
    void removeElement(int);
    vector<int> getCollection() const;
   class AscendingIterator
   {
    MagicalContainer* container;
    vector<int> sortedCollection;
    size_t index;
    public:
    AscendingIterator(MagicalContainer& cont); 
    AscendingIterator(MagicalContainer *cont, size_t ind = 0);

    AscendingIterator(const AscendingIterator& other) : container(other.container), index(other.index) {
    }
      AscendingIterator& operator=(const AscendingIterator& other);
      bool operator==(const AscendingIterator& otherIter) const;
      bool operator>(const AscendingIterator& otherIter) const;
      bool operator<(const AscendingIterator& otherIter) const;
      bool operator!=(const AscendingIterator& otherIter) const;
      int operator*();

      AscendingIterator& operator++();
      
     AscendingIterator begin() const;
     AscendingIterator end() const;

   };
   class SideCrossIterator {
    private:
        MagicalContainer* container;
        vector<int> sortedCollection;
        size_t index;

    public:
        SideCrossIterator(MagicalContainer& cont); 
        SideCrossIterator(MagicalContainer *cont, size_t ind = 0);
        SideCrossIterator(const SideCrossIterator& other) : container(other.container), index(other.index) {}

        SideCrossIterator& operator=(const SideCrossIterator& other);
        bool operator==(const SideCrossIterator& otherIter) const;
        bool operator>(const SideCrossIterator& otherIter) const;
        bool operator<(const SideCrossIterator& otherIter) const;
        bool operator!=(const SideCrossIterator& otherIter) const;
        int operator*();
        SideCrossIterator& operator++();

          
        SideCrossIterator begin() const;
        SideCrossIterator end() const;
    };
    class PrimeIterator
    {
    private:
        MagicalContainer* container;
        vector<int> sortedCollection;
        size_t index;

        
    public:
        PrimeIterator(MagicalContainer& cont); 
        PrimeIterator(MagicalContainer *cont, size_t ind = 0);
        PrimeIterator(const PrimeIterator& other) : container(other.container), index(other.index) {}

        PrimeIterator& operator=(const PrimeIterator& other);
        bool operator==(const PrimeIterator& otherIter) const;
        bool operator>(const PrimeIterator& otherIter) const;
        bool operator<(const PrimeIterator& otherIter) const;
        bool operator!=(const PrimeIterator& otherIter) const;
        int operator*();
        PrimeIterator& operator++();

          
        PrimeIterator begin() const;
        PrimeIterator end() const;

        bool isPrime(int num);
    };
};
