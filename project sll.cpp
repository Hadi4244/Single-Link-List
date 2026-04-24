#include <iostream>
using namespace std;
struct node{
	node* next; 
	int value;
};
node* head = NULL;

void createLL();
void display();
int Length();
void insertAtHead();
void insertAtTail();
void insertAfterPosition();
void insertBeforePosition();
void insertBeforePositionifEven();
void insertAfterValue();
void insertBeforeValue();
void deleteHead();
void deleteTail();
void deleteAtPosition();
void deleteAtValue();
void TailToHead();
void HeadToTail();
void SortLinkedList();

int main(){
	int x;
	do {
        cout << "1: Create Link list " << endl;
        cout << "2: Get Length of link list " << endl;
        cout << "3: Display Link List " << endl;
        cout << "4: Insert at head " << endl;
        cout << "5: Insert at Tail " << endl;
        cout << "6: Insert After Position " << endl;
        cout << "7: Insert Before Position " << endl;
        cout << "8: Insert Before Position if Value is Even : " << endl;
        cout << "9: Insert After Value " << endl;
        cout << "10: Insert Before Value " << endl;
        cout << "11: Delete Head " << endl;
        cout << "12: Delete Tail" << endl;
        cout << "13: Delete At Position " << endl;
        cout << "14: Delete At Value " << endl;
        cout << "15: Move Tail to Head " << endl;
        cout << "16:Move Head To Tail" << endl;
        cout << "17: Sort Linked List" << endl;
        cout << "0: Exit" << endl << endl;

        cin >> x;

        switch (x) {

        case 1:
            createLL();
            break;

        case 2:
            cout << "Length of current LL : " << Length() << endl;
            break;

        case 3:
            cout << "Link List : ";
            display();
            break;

        case 4:
            insertAtHead();
            break;

        case 5:
            insertAtTail();
            break;
        case 6:
            insertAfterPosition();
            break;
        case 7:
            insertBeforePosition();
            break;
        case 8:
            insertBeforePositionifEven();
            break;

        case 9:
            insertAfterValue();
            break;
        case 10:
            insertBeforeValue();
            break;

        case 11:
            deleteHead();
            break;
        case 12:
            deleteTail();
            break;
        case 13:
            deleteAtPosition();
            break;
        case 14:
            deleteAtValue();
            break;
        case 15:
            TailToHead();
            break;
        case 16:
            HeadToTail();
            break;
        case 17:
            SortLinkedList();
            break;
        }
    } while (x != 0);

}
void createLL(){
	int n;
	cout<<"enter the number of nodes you want"<<endl;
	cin>>n;
	for(int i=0 ; i<n ; i++){
	
	node* newnode = new node;
	cout<<"enter the value  of the node"<<endl;
	cin>>newnode->value;
	newnode->next=NULL;
	if (head==NULL){
		head= newnode;
	}
	else{
		node* temp = head;
		while(temp->next!= NULL)
		temp=temp->next;
		temp->next=newnode;
		
	}
}
}

void display(){
	node* temp =head;
	while (temp!=NULL){
		cout<<temp->value;
		temp=temp->next;
		cout<<" , ";
	}
	cout<<endl;
	
}

int Length(){
	int count=0;
	node* temp=head;
	while(temp!=NULL){
		count++;
		temp = temp->next;
		
	}
	return count;
	
}
void insertAtHead(){
	node* newnode = new node;
	cout<<"enter the value you want "<<endl;
	cin>>newnode->value;
	
	if(head==NULL){
		 head= newnode;
	}
	
	else{
		
		newnode->next= head;
		head= newnode;
	}
}

void insertAtTail(){
	node* newnode = new node;
	if(head == NULL){
    head = newnode;
    return;
}
	
	cout<<"enter the value"<<endl;
	cin>>newnode->value;
	
	newnode->next=NULL;
	node* temp= head;
	while(temp->next!=NULL){
		temp=temp->next;
		
	}
	temp->next=newnode;
	
}
void insertAfterPosition(){

	int pos;
	int i=1;
	int l=  Length();
	cout<<"enter the position"<<endl;
	cin>>pos;
	node* temp = head;
	
	if(pos<1 || pos>l){
		cout<<"pos not found"<<endl;
		return;
	}
	while(i<pos){
		
		
		temp=temp->next;
		i++;
	}
	if( temp->next==NULL){
		insertAtTail();
		return;
	}
	node* newnode= new node;
	cout<<"enter the val of new node"<<endl;
	cin>>newnode->value;
    newnode->next=temp->next;
    temp->next=newnode;
	
}
void insertBeforePosition(){
	
	int pos;
	int i=1;
	int l= Length();
	
	
	cout<<"enter the pos you want"<<endl;
	cin>>pos;
	
	if(pos<1 || pos>l){
		cout<<"pos not found"<<endl;
		return;
	}
	node* temp = head;
	while(i< pos-1){
		temp=temp->next;
		i++;
	}
	if(temp->next==NULL){
		insertAtTail();
		return;
	}
	
	node* newnode= new node;
		cout<<"enter the val of new node"<<endl;
	cin>>newnode->value;
	newnode->next=temp->next;
	temp->next=newnode;
}

void insertBeforePositionifEven(){
	
	node* newnode = new node;
	cout<<"enter the value for the node"<<endl;
	cin>>newnode->value;
	if(newnode->value % 2 ==0){
			
	int pos;
	int i=1;
	int l=Length();
	node* temp = head;
	cout<<"enter the pos "<<endl;
	cin>>pos;
	
	if(pos<1 || pos>l){
		cout<<"pos not found"<<endl;
		return;
	}
	while(i<pos-1){
		temp=temp->next;
		i++;
	}
	if(temp->next==NULL){
	insertAtTail();
		return;	
	}
	newnode->next=temp->next;
	temp->next=newnode;
	
	
}
else{
	cout<<"value is odd"<<endl;
	
}
}

void insertAfterValue(){
	
	int val;
	cout<<"enter the value "<<endl;
	cin>>val;
	node* temp= head;
	
	while(temp->next != NULL && temp->next->value != val){
    temp = temp->next;
		
	}
	if ( temp != NULL){
		node* newnode= new node;
		cout<<"enter the val of node"<<endl;
		cin>>newnode->value;
		newnode->next=temp->next;
		temp->next=newnode;
	}
	else{
		cout<<"val don't found"<<endl;
		
	}
	
}

void insertBeforeValue(){
	int val;
	cout<<"enter the val"<<endl;
	cin>>val;
	
	node* temp= head;
	while(temp->next->value != val && temp!= NULL){
		temp=temp->next;
		
	}
	if(temp!= NULL){
		node* newnode= new node;
		cout<<"enter the node val"<<endl;
		cin>>newnode->value;
		newnode->next=temp->next;
		temp->next=newnode;
	}
	else{
		cout<<"val not found"<<endl;
		
	}
}

void deleteHead(){
	node* temp = head;
	head= temp->next;
	delete temp;
}

void deleteTail(){
	node* temp = head;
	node* prev = NULL;
	
	while( temp->next != NULL){
		prev = temp;
		temp=temp->next;
		
	}
	prev->next=NULL;
	delete temp;
}

void deleteAtPosition(){
	
	int pos;
	
	cout<<"enter the pos to delete"<<endl;
	cin>>pos;
	node* temp= head;
	node* prev = NULL;
	
	if ( head = NULL){
		cout<<"list is empty"<<endl;
		return;
	}
	if ( pos==1 ){
		head= head->next;
		delete temp;
		return;
	}
	
	int count = 1;
	while ( temp != NULL && count < pos){
		prev= temp;
		temp= temp->next;
		count++;
	
	
	if ( temp==NULL){
		return;
	}
	prev->next=temp->next;
	delete temp;
	
	
}	
}
void deleteAtValue() {
    int val;
    cout << "Enter the value to delete : ";
    cin >> val;
    node* temp = head;
    node* PREV = NULL;
    if (head == NULL)
        return;
    if (head->value == val) {
        head = head->next;
        delete temp;
        return;
    }
    while (temp != NULL && temp->value != val) {
        PREV = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Value not found";
        return;
    }
    PREV->next = temp->next;
    delete temp;
}

void HeadToTail(){
	node* temp= head;
	
	while( temp->next != NULL ){
		temp=temp->next;
		
	}
	temp->next=head;
	head= head->next;
	temp->next->next=NULL;
		
		cout << "Head Moved to Tail Successfully !! " << endl;
    cout << "Updated Linked List : ";
    display();
}

void TailToHead() {
    node* temp = head;
    node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    temp->next = head;
    head = temp;
    prev->next = NULL;
    cout << "Tail moved to Head Successfully !! " << endl;
    cout << "Updated Linked List : ";
    display();
}


void SortLinkedList() {
    node* temp= head;
    	int swap;
    while(temp != NULL){
    node* nextnode= temp->next;	
     
      while(nextnode != NULL){
      	if(temp->value<nextnode->value){
      	
      		swap = temp->value;
      		temp->value=nextnode->value;
      		nextnode->value=swap;
		  }
		  nextnode =nextnode->next;
	  }
	  temp= temp->next;

}
cout << "Linked List Sorted Successfully !! " << endl;
    cout << "Updated Linked List : ";
    display();
}
