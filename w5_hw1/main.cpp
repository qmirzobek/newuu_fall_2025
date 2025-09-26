#include <bits/stdc++.h>
typedef std::string ElemType;
typedef int EmpIdType;

class Employee {

public:
    Employee() {
        next=nullptr;
    }
    EmpIdType EmployeeID;
    ElemType name;
    ElemType DateOfBirth;
    ElemType PhoneNumber;
    ElemType Address;
    Employee* next;
    friend class EmpLinkedList;
};

class EmpLinkedList {
private:
    Employee* head;
public:
    EmpLinkedList() ;
    ~EmpLinkedList();
    bool isEmpty();
    Employee* Front();
    Employee* Back();
    void PrintList();
    void AddFront(Employee* e);
    void AddBack(Employee* e);
    void DeleteFront();
    void DeleteBack();
    Employee* Find(EmpIdType employeeID);
    void Modify(Employee* node, ElemType name,ElemType DateOfBirth,ElemType PhoneNumber,ElemType Address);
    void Add(Employee* e);
    void Delete(Employee* e);
    int Count();

};

EmpLinkedList::EmpLinkedList(): head(nullptr){}
EmpLinkedList::~EmpLinkedList() {
    Employee* temp=head;
    Employee* temp2=nullptr;
    while(temp!=nullptr) {
        temp2=temp;
        temp=temp->next;
        delete temp2;
    }
}

bool EmpLinkedList::isEmpty() {
    return head == nullptr;
}

Employee* EmpLinkedList::Front() {
    return head;
}

Employee* EmpLinkedList::Back() {
    if (isEmpty()) return nullptr;
    Employee* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    return temp;
}
void EmpLinkedList::PrintList() {
    if (isEmpty()) {
        std::cout<<"List is empty."<<std::endl; return;
        };
    Employee* temp = head;
    std::cout<<"Employee List"<<std::endl;
    while (temp != nullptr) {
        std::cout<<"{ "<<std::endl;
        std::cout <<"\tEmployee ID: "<< temp->EmployeeID << std::endl;
        std::cout <<"\tName: "<< temp->name << std::endl;
        std::cout <<"\tDate of birth: "<< temp->DateOfBirth << std::endl;
        std::cout <<"\tPhone Number: "<< temp->PhoneNumber << std::endl;
        std::cout <<"\tAddress: "<< temp->Address << std::endl;
        std::cout<<"}"<<std::endl;
        temp = temp->next;
    }
    std::cout<<"------------------------------"<<std::endl;
}

void EmpLinkedList::AddFront(Employee* node) {
    if (isEmpty()) {
        head=node;
        // delete node;
    }else {
        // Employee* temp = head;
        node->next=head;
        head=node;
        // delete node;
    }
}
void EmpLinkedList::AddBack(Employee* node) {
    if (isEmpty()) {
        head=node;
    }else {
        Employee* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next=node;
        // delete node;
    }
}

void EmpLinkedList::DeleteFront() {
    if (!isEmpty()) {
        Employee* temp = head;
        head = head->next;
        delete temp;
    }
}
void EmpLinkedList::DeleteBack() {
    if (!isEmpty()) {
        Employee* temp = head;
        if (head->next == nullptr) {
            head=nullptr;
            delete temp;
            return;
        }
        while (temp->next->next != nullptr) temp = temp->next;
        delete temp->next;
        temp->next=nullptr;
    }
}
Employee* EmpLinkedList::Find(EmpIdType employeeID) {
    if (isEmpty()) return nullptr;
    Employee* temp = head;
    // bool found = false;
    while (temp != nullptr) {
        if (temp->EmployeeID == employeeID) {
            // found = true;
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}


int EmpLinkedList::Count() {
    if (isEmpty()) return 0;
    Employee* temp = head;
    int count = 0;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}


void EmpLinkedList::Delete(Employee* node) {
    if (!isEmpty()) {
        // Employee* temp = head;
        if (head==node) {
            DeleteFront();
            return;
        }
        Employee* temp = head;
        while (temp->next != nullptr) {
            if (temp->next==node) {
                temp->next=temp->next->next;
                delete node;
                return;
            }
        }
    }
}


void EmpLinkedList::Add(Employee *e) {
    if (isEmpty()) {
        head=e;
        return;
    }
    if (head->EmployeeID > e->EmployeeID) {
        AddFront(e);
        return;
    }
    Employee* temp = head;
    Employee* prev = nullptr;
    while (temp != nullptr) {
        // std::cout<<"Employee ID: "<<temp->EmployeeID<<std::endl;
        // std::cout<<(temp->EmployeeID>e->EmployeeID)<<std::endl;
        if (temp->EmployeeID > e->EmployeeID) {
            // std::cout<<"Employee ID: "<<temp->EmployeeID<<std::endl;
            e->next=temp;
            prev->next=e;
            // temp->next=e;
            return;
        }
        prev=temp;
        temp = temp->next;
    }
    AddBack(e);
}

void EmpLinkedList::Modify(Employee* node,ElemType name, ElemType DateOfBirth, ElemType PhoneNumber, ElemType Address ) {
    // node->EmployeeID = node->EmployeeID;
    node->name=name;
    node->DateOfBirth=DateOfBirth;
    node->PhoneNumber=PhoneNumber;
    node->Address=Address;
}


class Manager {
private:
    std::vector<std::string> operations={"1. Display Front Employee's Info",
        "2. Display Back Employee's Info",
        "3. Print Employee's list",
        "4. Insert an Employee at Front",
        "5. Insert an Employee at Back",
        "6. Delete Employee at the Front",
        "7. Delete Employee at the Back",
        "8. Search for an Employee (based on Employee's ID)",
        "9. Modify an Employee data (Name, Date of Birth, Phone, Address)",
        "10. Add a New Employee (order of ID)",
        "11. Delete an Employee",
        "12. Count Employees",
        "0. Exit"};
    EmpLinkedList L;
public:
    // Manager() = default;
    Manager(){};
    ~Manager();
    void Menu();
    void Front();
    void Back();
    void addFront();
    void addBack();
    void deleteFront();
    void deleteBack();
    void print();
    void modify();
    void search();
    void addEmployee();
    void deleteEmployee();
    void count();
    void printEmployee(Employee* e);
};
Manager::~Manager() {
    L.~EmpLinkedList();
}

void Manager::Menu() {
    // Let's do some pretty printing
    std::cout<<"[ ======== Menu ========]"<<std::endl;
    for (int i=0;i<operations.size();i++) {
        // std::cout<<"|#| "<<operations[i]<<std::endl; //this line looks cool
        std::cout<<operations[i]<<std::endl;
    }
}
void Manager::printEmployee(Employee* temp) {
    if (temp!=nullptr) {
        std::cout<<"{ "<<std::endl;
        std::cout <<"\tEmployee ID: "<< temp->EmployeeID << std::endl;
        std::cout <<"\tName: "<< temp->name << std::endl;
        std::cout <<"\tDate of birth: "<< temp->DateOfBirth << std::endl;
        std::cout <<"\tPhone Number: "<< temp->PhoneNumber << std::endl;
        std::cout <<"\tAddress: "<< temp->Address << std::endl;
        std::cout<<"}"<<std::endl;
    }
}
void Manager::Front() {
    if (L.isEmpty()) {
        std::cout<<"No Employees exist"<<std::endl;
        return;
    }
    Employee* temp = L.Front();
    if (temp!=nullptr) {
        printEmployee(temp);
    }
}
void Manager::Back() {
    if (L.isEmpty()) {
        std::cout<<"No Employees exist"<<std::endl;
        return;
    }
    Employee* temp = L.Back();
    if (temp!=nullptr) {
        printEmployee(temp);
    }

}
void Manager::addFront() {
    Employee* temp=new Employee();
    std::cout<<"Enter Employee ID (Employee ID must be integer):"<<std::endl;
    std::cin>>temp->EmployeeID;
    std::cout<<"Enter Employee Name"<<std::endl;
    std::cin>>temp->name;
    std::cout<<"Enter Employee Date (DD/MM/YYYY)"<<std::endl;
    std::cin>>temp->DateOfBirth;
    std::cout<<"Enter Employee Phone (99-999-99-99)"<<std::endl;
    std::cin>>temp->PhoneNumber;
    std::cout<<"Enter Employee Address"<<std::endl;
    std::cin>>temp->Address;
    L.AddFront(temp);
}

void Manager::addBack() {
    Employee* temp=new Employee();
    std::cout<<"Enter Employee ID (Employee ID must be integer):"<<std::endl;
    std::cin>>temp->EmployeeID;
    std::cout<<"Enter Employee Name"<<std::endl;
    std::cin>>temp->name;
    std::cout<<"Enter Employee Date (DD/MM/YYYY)"<<std::endl;
    std::cin>>temp->DateOfBirth;
    std::cout<<"Enter Employee Phone (99-999-99-99)"<<std::endl;
    std::cin>>temp->PhoneNumber;
    std::cout<<"Enter Employee Address"<<std::endl;
    std::cin>>temp->Address;
    L.AddBack(temp);
}

void Manager::deleteFront() {
    L.DeleteFront();
}
void Manager::print() {
    L.PrintList();
}

void Manager::deleteBack() {
    L.DeleteBack();
}

void Manager::search() {
    EmpIdType search;
    std::cout<<"Enter Employee ID (Employee ID must be integer): "<<std::endl;
    std::cin>>search;
    Employee* e=L.Find(search);
    if(e!=nullptr){
        printEmployee(e);
    }else{
        std::cout<<"No Employee exist"<<std::endl;
    }
    // return e;
}
void Manager::modify() {
    EmpIdType search;
    std::cout<<"Enter Employee ID (Employee ID must be integer): "<<std::endl;
    std::cin>>search;
    Employee* e=L.Find(search);
    printEmployee(e);
    ElemType name;
    ElemType date;
    ElemType phone;
    ElemType address;
    std::cout<<"Enter Employee Name: "<<std::endl;
    std::cin>>name;
    std::cout<<"Enter Employee Date of birth: "<<std::endl;
    std::cin>>date;
    std::cout<<"Enter Employee Phone number: "<<std::endl;
    std::cin>>phone;
    std::cout<<"Enter Employee Address: "<<std::endl;
    std::cin>>address;
    L.Modify(e,name,date,phone,address);
    std::cout<<"Employee data probably modified"<<std::endl;
}
void Manager::addEmployee() {
    Employee* temp=new Employee();
    std::cout<<"Enter Employee ID (Employee ID must be integer): "<<std::endl;
    std::cin>>temp->EmployeeID;
    std::cout<<"Enter Employee Name"<<std::endl;
    std::cin>>temp->name;
    std::cout<<"Enter Employee Date of birth: "<<std::endl;
    std::cin>>temp->DateOfBirth;
    std::cout<<"Enter Employee Phone number: "<<std::endl;
    std::cin>>temp->PhoneNumber;
    std::cout<<"Enter Employee Address: "<<std::endl;
    std::cin>>temp->Address;
    L.Add(temp);
}
void Manager::deleteEmployee() {
    std::cout<<"Enter Employee ID (Employee ID must be integer): "<<std::endl;
    EmpIdType id;
    std::cin>>id;
    Employee* e=L.Find(id);
    if(e!=nullptr){
        printEmployee(e);
        std::cout<<"Are you sure you want to delete? [Y/n]:";
        char answer;
        std::cin>>answer;
        if (answer=='Y') {
            L.Delete(e);
            std::cout<<"Deleted Employee ID"<<std::endl;
        }
    }else{
        std::cout<<"No Employee exist"<<std::endl;
    }
}
void Manager::count() {

    int count=L.Count();
    std::cout<<"Number of employees: "<<count<<std::endl;
}


int main() {
    // EmpLinkedList L;
    Manager manager;
    int choice=13;

    while (choice!=0) {
        manager.Menu();
        std::cout<<"Enter your choice : ";
        std::cin>>choice;
        // std::cout<<"your choice "<<choice<<std::endl;
        // switch (choice) {
        //     case 1:
        //         manager.Front();
        //     case 2:
        //         manager.Back();
        //     case 3:
        //         std::cout<<"ID"<<std::endl;
        //         manager.print();
        //     case 4:
        //         manager.addFront();
        //     case 5:
        //         manager.addBack();
        //     case 6:
        //         manager.deleteFront();
        //     case 7:
        //         manager.deleteBack();
        //     case 8:
        //         manager.search();
        //     case 9:
        //         manager.modify();
        //     case 10:
        //         manager.addEmployee();
        //     case 11:
        //         manager.deleteEmployee();
        //     case 12:
        //         manager.count();
        // }
        if (choice==1) manager.Front();
        else if (choice==2) manager.Back();
        else if (choice==3) manager.print();
        else if (choice==4) manager.addFront();
        else if (choice==5) manager.addBack();
        else if (choice==6) manager.deleteFront();
        else if (choice==7) manager.deleteBack();
        else if (choice==8) manager.search();
        else if (choice==9) manager.modify();
        else if (choice==10) manager.addEmployee();
        else if (choice==11) manager.deleteEmployee();
        else if (choice==12) manager.count();
        else {
            std::cout<<"Wrong choice"<<std::endl;
        }

    }
}


