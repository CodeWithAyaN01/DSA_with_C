#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#define max_size 100
void Assign_ppl_to_counters(); // work on
int C1_sleep = 1, C2_sleep =1, C3_sleep = 1;
int Queue[max_size];
int front = -1 , rear = -1;
int RandomNum()  // for generating Random number bt 20 - 150; 
{
    srand((unsigned int)time(NULL)); 
    
    int randomValue;

    if ((rand() % 100) < 90) {
        randomValue = 91 + (rand() % (150 - 91 + 1)); 
    } else {
        randomValue = 21 + (rand() % (90 - 21 + 1)); 
    }

    return randomValue;
}
void EnQueue(int data) // inserting a value from read
{   
    if (rear == max_size - 1) // full->Condition
    {
        printf("Queue is Full\n");
    }
    else
    {
        if(front == -1) // Setting Front to 0 if Front == -1;
            front = 0;
        Queue[++rear] = data;
    }
}
void Dequeue() // removing the element .
{
    if (front == -1 || front > rear)
    {
        printf("The Queue is Empty Cannot Dequeue\n");
    }
    else
    {
        // printf("Dequed Element : %d ",Queue[front]);
        front++; // increasing the front to Dequeue.
        printf("\t\t\t\t\t\t\t\t\t\t%d\t\t\t\t\n",Queue[front]);
        if (front > rear) // resetting if front and rear if Queus is full
        {
            front = rear = -1;
        }
    }
}
void DisplayQue()
{
    if (front == -1){
        printf("The Queue is Empty : ");
    }
    else
    {
        printf("\nThe Present Que is\n\n\n\n\n");
        for (int i = front ; i<= rear ; i++)
        {
            Sleep(150);
            printf("\t\t\t\t\t\t\t\t\t\t%d\t\t\t\t\n",Queue[i]);
        }
    }
}
void No_of_Person()
{
    int person;
    printf("\nEnter the number of Person in Queue: ");
    scanf("%d",&person);
    for(int i = 0 ; i < person ; i++) // taking person in Queue
    {
        EnQueue(i+1);
    }
}
void DisplayDeQueue()
{
    DisplayQue();
    for (int i = front ; i < rear ; i++)
    {
        // Sleep(150);
        Dequeue();
        system("cls");
        DisplayQue();
    }
}
struct node
{
    int data;
    struct node* next;
};
struct node* CreatNode(int data)
{
    struct node *NewNode = (struct node*)malloc(sizeof(struct node));
    NewNode->data = data;
    NewNode->next = NULL;
    return NewNode;
}
void InsertAtBeg(struct node ** head,int data)
{
    struct node * NewNode = CreatNode(data);
    NewNode->data = data;
    NewNode->next = *head;
    *head = NewNode; // updating head to the next new node
}
void insertAtEnd(struct node ** head , int data) //  head stores the adders of the 
{
    struct node * NewNode = CreatNode(data);
    NewNode->data = data;
    NewNode->next = NULL;

    if (*head == NULL)
    {
        *head = NewNode; // list empty condition 
    }
    struct node * temp = *head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NewNode; // connecting to the last node !
    NewNode->next = *head; // points to the head !

} 
// Sleep Timing for all Counters
void counter_1()
{
    C1_sleep = 1;
    Sleep(RandomNum());
    C1_sleep = 0;
}
void counter_2()
{
    C2_sleep = 1;
    Sleep(RandomNum());
    C2_sleep = 0;
}
void counter_3()
{
    C3_sleep = 1;
    Sleep(RandomNum());
    C3_sleep = 0;
}
int main()
{
    struct node * head = NULL;
    No_of_Person();
    printf("<==============Counter1===============>\t\t\t\t<==============Counter2===============>\t\t\t\t<==============Counter3===============>\n\n");
    // DisplayQue();
    DisplayDeQueue();
}