#include "doctest.h"
#include "sources/MagicalContainer.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("1")
{
    CHECK_NOTHROW(MagicalContainer cont);
    MagicalContainer cont;

    CHECK_NOTHROW(cont.size());
    CHECK(cont.size()== 0);

    
    CHECK_NOTHROW(cont.addElement(2));
    cont.addElement(4);
    CHECK_NOTHROW(*(cont.end()));
    CHECK_NOTHROW(*(cont.begin()));
    CHECK(cont.begin() == cont.end());

    CHECK(cont.size()== 1);
    cont.addElement(5);
    CHECK(cont.size()== 2);

    CHECK_NOTHROW(cont.removeElement(4));
    cont.removeElement(4);
    CHECK(cont.size()== 1);
    cont.removeElement(5);
    CHECK(cont.size()== 0);

    MagicalContainer cont2;
    cont2.addElement(1);
    cont2.addElement(2);
    cont2.addElement(3);

    CHECK_THROWS(cont2.removeElement(5));
    CHECK(cont2.size() == 3);

    
}

TEST_CASE("PrimeIterator")
 {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(9);
    container.addElement(11);
    CHECK_NOTHROW(MagicalContainer::PrimeIterator it(container));
    CHECK_NOTHROW(MagicalContainer::AscendingIterator it(container));
    CHECK_NOTHROW(MagicalContainer::SideCrossIterator it(container));
    MagicalContainer::PrimeIterator it(container);
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(*it == 11);   

 }
