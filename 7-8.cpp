#include "7-8.h"
#include <iostream>
using namespace std;


PCB::PCB(int ID, string Name, string Status, int Counter)
    {
		processID = ID;
        processName = Name;
        processStatus = Status;
        commandCounter = Counter;
        for (int i =0 ; i < 8; i++ )
		{
			cpuRegisters[i] = 0;
		}
		
    }

PCB::~PCB()
{
	delete[] *cpuRegisters;
}

ListNode::ListNode(const PCB& pcb): data(pcb), next(nullptr) {}

ListNode::~ListNode(){};


ProcessList::ProcessList(): head(nullptr){};
ProcessList::~ProcessList()
{
	while (head!=nullptr)
	{
		ListNode  *temp = head;
		head = head -> next;
		delete temp;
	}
};

bool ProcessList::insert(const PCB newPCB)
{
	//Первая запись относительно нового узла
	//Если больше новой, то вставляет новый на его место 
	if (head == nullptr || head -> data.processID > newPCB.processID)
	{
		
		ListNode *node = new ListNode(newPCB);
		
		node->next = head;
		head = node;
		return true;
	}
	//Ищем по ID запись после которой надо вставить новую
	ListNode *curr = head;
	while(curr->next && curr->next->data.processID < newPCB.processID)
	{
		curr = curr->next;
	}
	//Если такой ID уже существует -> ошибка
	if (newPCB.processID == curr->data.processID)
	{
		return false;
	}
	else
	{
		// Записываем новый на свое место в список
		ListNode *node = new ListNode(newPCB);
		node->next = curr->next;
		curr->next = node; 
		return true;
	}
}

bool ProcessList::remove(int pid)
{
	// если список пустой -> ошибка
	if(head == nullptr)
	{
		return false;
	}
	// если главный равен pid -> удаляем и сдвигаем 
	if (head->data.processID == pid)
	{
		ListNode *temp = head;
		head = head->next;
		delete temp;
		return true;
	}
	// Ищем соответствующий pid
	ListNode* curr = head;
	while(curr->next && curr->next->data.processID != pid)
	{
		curr = curr->next;
	}

	// если элемента нет -> ошибка
	if(curr->next == nullptr)
	{
		return false;
	}

	// если значения ID совпадают -> удаляем
		ListNode *temp = curr->next;
		curr->next = curr->next->next;
		delete temp;
		return true;
}

void ProcessList::printList()
{
	ListNode *curr = head;
	while (curr)
	{
		cout << "ProcessID:" << curr->data.processID << endl;
		cout << "\t processName:    " << curr->data.processName << endl;
        cout << "\t processStatus:  " << curr->data.processStatus << endl;
        cout << "\t commandCounter: " << curr->data.commandCounter << "\n";

		curr = curr->next;		
	}
}
