#include <iostream>

#include "test/tester.h"

using namespace std;

int main(int argc, char const *argv[]) {
    Tester::execute();

    /*
    cout << "-- Self Organized List - Move method \n";
    SelfList<int> selforglist(SelfList<int>::Move);
    cout << "SelfList \n";
    selforglist.insert(1);
    selforglist.insert(3);
    selforglist.insert(5);
    selforglist.insert(10);
    selforglist.insert(20);
    selforglist.insert(30);
    selforglist.insert(40);
    selforglist.print();
    cout << "size: " << selforglist.size() << '\n';
    cout << "remove '30' \n";
    cout << selforglist.remove(30) << '\n';
    selforglist.print();
    cout << "size: " << selforglist.size() << '\n';
    cout << "Find '10' \n";
    selforglist.find(10);
    selforglist.print();
    cout << "Find '3' \n";
    selforglist.find(3);
    selforglist.print();
    cout << "Find '3' \n";
    selforglist.find(3);
    selforglist.print();
    cout << "Find '1' \n";
    selforglist.find(1);
    selforglist.print();
    cout << selforglist[2] <<'\n';
    */
    /*
    cout << "-- Self Organized List - Count method \n";
    SelfList<int> self_list_Count(SelfList<int>::Count);
    self_list_Count.insert(100);
    self_list_Count.insert(200);
    self_list_Count.insert(300);
    self_list_Count.insert(400);
    self_list_Count.print();
    cout << "size: " << self_list_Count.size() << '\n';
    self_list_Count.find(100);
    self_list_Count.print();
    self_list_Count.find(100);
    self_list_Count.print();
    self_list_Count.find(300);
    self_list_Count.print();
    self_list_Count.find(300);
    self_list_Count.print();
    self_list_Count.find(200);
    self_list_Count.print();

    cout << "-- Self Organized List - Transpose method \n";
    SelfList<int> self_list_Trans(SelfList<int>::Transpose);
    self_list_Trans.insert(60);
    self_list_Trans.insert(70);
    self_list_Trans.insert(80);
    self_list_Trans.insert(90);
    self_list_Trans.print();
    cout << "size: " << self_list_Trans.size() << '\n';
    self_list_Trans.find(70);
    self_list_Trans.print();
    self_list_Trans.find(60);
    self_list_Trans.print();
    self_list_Trans.find(70);
    self_list_Trans.print();*/

    /*cout << "Type Traits List \n";
    TraitsList<Integer> listTrait;
    listTrait.insert(10);
    listTrait.insert(50);
    listTrait.insert(20);
    listTrait.print();
    cout << "size: " << listTrait.size() << '\n';
    listTrait.insert(2);
    listTrait.print();
    cout << "size: " << listTrait.size() << '\n';
    listTrait.insert(15);
    listTrait.print();
    cout << "size: " << listTrait.size() << '\n';
    listTrait.remove(10);
    listTrait.print();
    cout << "size: " << listTrait.size() << '\n';
    cout << listTrait.find(10) << '\n';
    cout << listTrait.find(50) << '\n';
    cout << listTrait[0] << '\n';
    cout << listTrait[3] << '\n';*/
    return EXIT_SUCCESS;
}

