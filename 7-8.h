#include <iostream>
#include <string>
using namespace std;

struct PCB
{
    int processID;
    string processName;
    string processStatus;
    //Running, Waiting, Stopped
    int commandCounter;
    int *cpuRegisters[10];

    PCB(int, string, string, int); //Конструктор класса
    ~PCB();                       //Деструктор класса

};

class ListNode
{
    public:
    PCB data;
    ListNode *next;

    ListNode(const PCB& pcb);
    ~ListNode();
};

class ProcessList
{
 private:
    ListNode *head;
 public:
    bool insert(const PCB);
    bool remove(int);
    void printList();

    ProcessList();
    ~ProcessList();


};

