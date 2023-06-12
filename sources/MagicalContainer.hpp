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
    //  MagicalContainer &container;
    MagicalContainer* container;
    //  vector<int> sortedCollection;
      int index;
    //   private:
    //   std::vector<int>::const_iterator iter;
    public:
    //   AscendingIterator(MagicalContainer& cont, int index=0);
    //   AscendingIterator(const AscendingIterator& other);

    AscendingIterator() : container(nullptr), index(0) {}
    explicit AscendingIterator(MagicalContainer& container, int index = 0) : container(&container), index(index) {}
    AscendingIterator(const AscendingIterator& other) : container(other.container), index(other.index) {}


     // vector<int> getCollection() const{return container.getCollection();};
     // void operator=(const AscendingIterator& otherIter) const;
    //   bool operator==(const AscendingIterator otherIter) const;
      AscendingIterator& operator=(const AscendingIterator& other);
      bool operator==(const AscendingIterator& otherIter) const;
      bool operator>(const AscendingIterator& otherIter) const;
      bool operator<(const AscendingIterator& otherIter) const;
      bool operator!=(const AscendingIterator& otherIter) const;
      int operator*();
      explicit AscendingIterator(std::vector<int>::const_iterator iterator);


      AscendingIterator& operator++();
      
    // AscendingIterator begin(MagicalContainer& container);
    // AscendingIterator end(MagicalContainer& container);
    //  vector<int>::const_iterator begin() const{return sortedCollection.begin();};
    //  vector<int>::const_iterator end() const{return sortedCollection.end();};
    //  AscendingIterator end() const {return AscendingIterator(sortedCollection, sortedCollection.size());};

   };
    static AscendingIterator begin(MagicalContainer& container);
    static AscendingIterator end(MagicalContainer& container);
   class SideCrossIterator {
    private:
        MagicalContainer& container;
        vector<int> sortedCollection;

        
        int indStart;
        int indEnd;

    public:
        SideCrossIterator(MagicalContainer& cont): container(cont), indStart(0), indEnd(cont.size()){};;
        SideCrossIterator(const SideCrossIterator& other);
        SideCrossIterator& operator=(const SideCrossIterator& other);
        bool operator==(const SideCrossIterator& otherIter) const {return true;}
        bool operator>(const SideCrossIterator& otherIter) const {return true;}
        bool operator<(const SideCrossIterator& otherIter) const {return true;}
        bool operator!=(const SideCrossIterator& otherIter) const {return false;}
        SideCrossIterator& operator++();
        vector<int>::const_iterator begin() const{return sortedCollection.begin();};
        vector<int>::const_iterator end() const{return sortedCollection.end();};

    };
    class PrimeIterator
    {
    private:
        MagicalContainer& container;
        vector<int> sortedCollection;
        int index;

        bool isPrime(int num);

    public:
        PrimeIterator(MagicalContainer& cont): container(cont), index(0){};
        PrimeIterator(const PrimeIterator& other);
        PrimeIterator& operator=(const PrimeIterator& other);
        bool operator==(const PrimeIterator& otherIter) const;
        bool operator>(const PrimeIterator& otherIter) const;
        bool operator<(const PrimeIterator& otherIter) const;
        bool operator!=(const PrimeIterator& otherIter) const;
        int& operator*() {return (int&)index;};
        PrimeIterator& operator++(){return *this;};
        vector<int>::const_iterator begin() const{return sortedCollection.begin();};
        vector<int>::const_iterator end() const{return sortedCollection.end();};
    };
};
