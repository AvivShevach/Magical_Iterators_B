#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
namespace ariel{};
class MagicalContainer
{
   private:
  // public:
        vector<int> elements;
    //   vector<int> sortedCollection;

 public:
    void addElement(int);
    int size();
    void removeElement(int);
    vector<int> getCollection() const;

    // vector<int>::const_iterator begin() const{return sortedCollection.begin();};
    // vector<int>::const_iterator end() const{return sortedCollection.end();};

   class AscendingIterator
   {
    MagicalContainer* container;
    vector<int> sortedCollection;
    size_t index;
    public:
    //   AscendingIterator(MagicalContainer& cont, int index=0);
    //   AscendingIterator(const AscendingIterator& other);

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
    //  explicit AscendingIterator(std::vector<int>::const_iterator iterator);

      AscendingIterator& operator++();
      
     AscendingIterator begin() const;
     AscendingIterator end() const;

   };
    // static AscendingIterator begin(MagicalContainer& container);
    // static AscendingIterator end(MagicalContainer& container);
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
