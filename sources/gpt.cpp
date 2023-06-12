// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <stdexcept>
// #include <algorithm>

// class MagicalContainer {
// private:
//     std::vector<int> elements;

// public:
//     void addElement(int element) {
//         elements.push_back(element);
//     }

//     void removeElement(int element) {
//         auto it = std::find(elements.begin(), elements.end(), element);
//         if (it != elements.end()) {
//             elements.erase(it);
//         }
//     }

//     int getSize() const {
//         return elements.size();
//     }

//     class AscendingIterator {
//     private:
//         MagicalContainer* container;
//         int index;

//     public:
//         AscendingIterator() : container(nullptr), index(0) {}

//         explicit AscendingIterator(MagicalContainer& container, int index = 0) : container(&container), index(index) {}

//         AscendingIterator(const AscendingIterator& other) : container(other.container), index(other.index) {}

//         AscendingIterator& operator=(const AscendingIterator& other) {
//             if (this != &other) {
//                 container = other.container;
//                 index = other.index;
//             }
//             return *this;
//         }

//         bool operator==(const AscendingIterator& other) const {
//             return container == other.container && index == other.index;
//         }

//         bool operator!=(const AscendingIterator& other) const {
//             return !(*this == other);
//         }

//         bool operator<(const AscendingIterator& other) const {
//             if (container != other.container) {
//                 throw std::runtime_error("Cannot compare iterators from different containers.");
//             }
//             return index < other.index;
//         }

//         bool operator>(const AscendingIterator& other) const {
//             if (container != other.container) {
//                 throw std::runtime_error("Cannot compare iterators from different containers.");
//             }
//             return index > other.index;
//         }

//         int operator*() const {
//             if (container == nullptr || index >= container->getSize()) {
//                 throw std::runtime_error("Iterator is out of range.");
//             }
//             return container->elements[index];
//         }

//         AscendingIterator& operator++() {
//             ++index;
//             return *this;
//         }

//         static AscendingIterator begin(MagicalContainer& container) {
//             return AscendingIterator(container);
//         }

//         static AscendingIterator end(MagicalContainer& container) {
//             return AscendingIterator(container, container.getSize());
//         }
//     };

//     class SideCrossIterator {
//     private:
//         MagicalContainer* container;
//         int leftIndex;
//         int rightIndex;
//         bool moveToLeft;

//     public:
//         SideCrossIterator() : container(nullptr), leftIndex(0), rightIndex(-1), moveToLeft(true) {}

//         explicit SideCrossIterator(MagicalContainer& container, int leftIndex = 0, int rightIndex = -1, bool moveToLeft = true)
//             : container(&container), leftIndex(leftIndex), rightIndex(rightIndex), moveToLeft(moveToLeft) {}

//         SideCrossIterator(const SideCrossIterator& other)
//             : container(other.container), leftIndex(other.leftIndex), rightIndex(other.rightIndex), moveToLeft(other.moveToLeft) {}

//         SideCrossIterator& operator=(const SideCrossIterator& other) {
//             if (this != &other) {
//                 container = other.container;
//                 leftIndex = other.leftIndex;
//                 rightIndex = other.rightIndex;
//                 moveToLeft = other.moveToLeft;
//             }
//             return *this;
//         }

//         bool operator==(const SideCrossIterator& other) const {
//             return container == other.container && leftIndex == other.leftIndex && rightIndex == other.rightIndex && moveToLeft == other.moveToLeft;
//         }

//         bool operator!=(const SideCrossIterator& other) const {
//             return !(*this == other);
//         }

//         bool operator<(const SideCrossIterator& other) const {
//             if (container != other.container) {
//                 throw std::runtime_error("Cannot compare iterators from different containers.");
//             }
//             if (moveToLeft != other.moveToLeft) {
//                 throw std::runtime_error("Cannot compare iterators with different movement directions.");
//             }
//             return leftIndex < other.leftIndex;
//         }

//         bool operator>(const SideCrossIterator& other) const {
//             if (container != other.container) {
//                 throw std::runtime_error("Cannot compare iterators from different containers.");
//             }
//             if (moveToLeft != other.moveToLeft) {
//                 throw std::runtime_error("Cannot compare iterators with different movement directions.");
//             }
//             return leftIndex > other.leftIndex;
//         }

//         int operator*() const {
//             if (container == nullptr || leftIndex >= container->getSize() || rightIndex < 0) {
//                 throw std::runtime_error("Iterator is out of range.");
//             }
//             if (moveToLeft) {
//                 return container->elements[leftIndex];
//             } else {
//                 return container->elements[rightIndex];
//             }
//         }

//         SideCrossIterator& operator++() {
//             if (moveToLeft) {
//                 ++leftIndex;
//             } else {
//                 --rightIndex;
//             }
//             moveToLeft = !moveToLeft;
//             return *this;
//         }

//         static SideCrossIterator begin(MagicalContainer& container) {
//             return SideCrossIterator(container);
//         }

//         static SideCrossIterator end(MagicalContainer& container) {
//             return SideCrossIterator(container, container.getSize() - 1, -1, false);
//         }
//     };

//     class PrimeIterator {
//     private:
//         MagicalContainer* container;
//         int index;

//         bool isPrime(int number) const {
//             if (number < 2) {
//                 return false;
//             }
//             int sqrtNumber = static_cast<int>(std::sqrt(number));
//             for (int i = 2; i <= sqrtNumber; ++i) {
//                 if (number % i == 0) {
//                     return false;
//                 }
//             }
//             return true;
//         }

//     public:
//         PrimeIterator() : container(nullptr), index(0) {}

//         explicit PrimeIterator(MagicalContainer& container, int index = 0) : container(&container), index(index) {
//             while (index < container.getSize() && !isPrime(container.elements[index])) {
//                 ++index;
//             }
//         }

//         PrimeIterator(const PrimeIterator& other) : container(other.container), index(other.index) {}

//         PrimeIterator& operator=(const PrimeIterator& other) {
//             if (this != &other) {
//                 container = other.container;
//                 index = other.index;
//             }
//             return *this;
//         }

//         bool operator==(const PrimeIterator& other) const {
//             return container == other.container && index == other.index;
//         }

//         bool operator!=(const PrimeIterator& other) const {
//             return !(*this == other);
//         }

//         bool operator<(const PrimeIterator& other) const {
//             if (container != other.container) {
//                 throw std::runtime_error("Cannot compare iterators from different containers.");
//             }
//             return index < other.index;
//         }

//         bool operator>(const PrimeIterator& other) const {
//             if (container != other.container) {
//                 throw std::runtime_error("Cannot compare iterators from different containers.");
//             }
//             return index > other.index;
//         }

//         int operator*() const {
//             if (container == nullptr || index >= container->getSize()) {
//                 throw std::runtime_error("Iterator is out of range.");
//             }
//             return container->elements[index];
//         }

//         PrimeIterator& operator++() {
//             ++index;
//             while (index < container->getSize() && !isPrime(container->elements[index])) {
//                 ++index;
//             }
//             return *this;
//         }

//         static PrimeIterator begin(MagicalContainer& container) {
//             return PrimeIterator(container);
//         }

//         static PrimeIterator end(MagicalContainer& container) {
//             return PrimeIterator(container, container.getSize());
//         }
//     };
// };

// int main() {
//     MagicalContainer container;
//     container.addElement(1);
//     container.addElement(2);
//     container.addElement(4);
//     container.addElement(5);
//     container.addElement(14);

//     std::cout << "Ascending order: ";
//     for (auto it = MagicalContainer::AscendingIterator::begin(container); it != MagicalContainer::AscendingIterator::end(container); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     std::cout << "Prime numbers only: ";
//     for (auto it = MagicalContainer::PrimeIterator::begin(container); it != MagicalContainer::PrimeIterator::end(container); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     std::cout << "Side cross order: ";
//     for (auto it = MagicalContainer::SideCrossIterator::begin(container); it != MagicalContainer::SideCrossIterator::end(container); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }
