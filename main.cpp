#include <iostream>
#include "7-8.cpp"
using namespace std;

int main()
{
    // Создаем элементы PCB
    PCB l1(1, "operation1", "Waiting",15);
    PCB l2(2, "operation2", "Running",1);
    PCB l3(3, "operation3", "Stopped",36); 
    PCB l4(4, "operation4", "Stopped",5);
    PCB uncor(1, "uncorrect", "Running", 8);

    // Добавляем элементы в список
    ProcessList list;
    list.insert(l1);
    list.insert(l4);
    list.insert(l3);
    list.insert(l2);
    
    // выводим список процессов
    cout << "First list: " << endl;
    list.printList();

    // удаляем некоторые процессы
    list.remove(2);
    list.remove(4);

    // выводим список после удаления
    cout << "\nList after removing: " << endl;
    list.printList();

    // добавление операции с уже существующим ID
    if( !list.insert(uncor))
    {
        cout << "\nError of inserting! \n";
    }
    cout << "\nList after uncorrect inserting: " << endl;
    list.printList();

    // удаление несуществующей операции
    if (!list.remove(2))
    {
        cout << "\nError of removing! \n";
    }
    cout << "\nList after uncorrect removing: " << endl;
    list.printList();


    return 0;
}
