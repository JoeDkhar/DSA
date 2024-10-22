#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Employee{
    int id;
    char name[100];
    char departmentName[100];
    int departmentNumber;
    float salary;
} Employee;

typedef struct Node{
    Employee data;
    struct Node *next;
} Node;

// define the linked list structure
typedef struct LinkedList{
    Node *head;
}LinkedList;

// function to create a new employee
Employee createEmployee(int id,char *name,char *departmentName,int departmentNumber,float salary)
{
    Employee employee;
    employee.id = id;
    strcpy(employee.name, name);
    strcpy(employee.departmentName, departmentName);
    employee.departmentNumber = departmentNumber;
    employee.salary = salary;

    return employee;
}

//insert a node into the linked list 

void insert(LinkedList *list,Employee data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}


//delete a node from the linked list 

void delete(LinkedList *list,int id)
{
    Node *temp = list->head;
    Node *prev = NULL;
    while(temp !=NULL && temp->data.id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp==NULL)
        return ;
    
    if(prev == NULL)
    {
            list->head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
}

//traverse the linked list 

void traverse(LinkedList *list)
{
    Node *temp = list->head;
    while(temp !=NULL)
    {
        printf("Employee ID: %d\n",temp->data.id);
        printf("Employee Name: %s\n",temp->data.name);
        printf("Employee Department Name: %s\n",temp->data.departmentName);
        printf("Employee Department Number: %d\n",temp->data.departmentNumber);
        printf("Employee Salary: %f\n",temp->data.salary);
        printf("\n");
        temp = temp->next;
    }
}

//search for a node in the linked list 

void search(LinkedList *list,int id)
{
    Node *temp = list->head;
    while(temp !=NULL && temp->data.id != id)
    {
        temp = temp->next;
    }

    if(temp==NULL)
    {
        printf("Employee not found\n");
    }
    else
    {
        printf("Employee ID: %d\n",temp->data.id);
        printf("Employee Name: %s\n",temp->data.name);
        printf("Employee Department Name: %s\n",temp->data.departmentName);
        printf("Employee Department Number: %d\n",temp->data.departmentNumber);
        printf("Employee Salary: %f\n",temp->data.salary);
        printf("\n");
    }
}

int main()
{
    LinkedList list;
    list.head = NULL;
    int choice, id, departmentNumber;
    char name[50], departmentName[50];
    float salary;
    while (1) {
        printf("1. Insert\n2. Delete\n3. Traverse\n4. Search\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Salary: ");
                scanf("%f", &salary);
                printf("Enter Department Name: ");
                scanf("%s", departmentName);
                printf("Enter Department Number: ");
                scanf("%d", &departmentNumber);
                insert(&list, createEmployee(id, name,departmentName, departmentNumber, salary));
                break;
            case 2:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                delete(&list, id);
                break;
            case 3:
                traverse(&list);
                break;
            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                search(&list, id);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
