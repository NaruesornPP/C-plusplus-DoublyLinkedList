#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<stdio.h>

using namespace std;

struct data{
	struct data *prev;
	char name[50];
	char surname[50];
	int age;
	struct data *next;
};

int count;

void display(struct data *head){
	struct data *ptr;
	ptr=(data*)malloc(sizeof(data));
	ptr->next=head;
	ptr=ptr->next;
	count=0;
	cout<<"------------------------------"<<endl;
	while(ptr->next!=NULL){
		ptr=ptr->next;
		cout<<"Index "<<count<<" :"<<endl<<ptr->name<<" "<<ptr->surname<<" "<<ptr->age<<endl;
		count++;
	}
	if(count==0){
		cout<<"Empty Double Linked List"<<endl;
	}
	cout<<"------------------------------"<<endl;
}

int main(){
	int input=3,tempage,tempdel;
	char tempname[50],tempsurname[50];
	struct data *head;
	head=(data*)malloc(sizeof(data));
	while(input!=0){
		cout<<"Input 1 for Insertion"<<endl<<"Input 2 for Deletion"<<endl<<"Input 3 for Sorting"<<endl<<"Input 0 to end this program"<<endl<<": ";
		cin>>input;
		if(input==1){
			cout<<endl<<"Insertion"<<endl;
			cout<<"Input name : ";
			cin>>tempname;
			cout<<"Input surname : ";
			cin>>tempsurname;
			cout<<"Input age : ";
			cin>>tempage;
			
			struct data *newnode;
			newnode=(data*)malloc(sizeof(data));
			newnode->next=head;
			newnode=newnode->next;
			while(newnode->next!=NULL){
				newnode=newnode->next;
			}
			newnode->next=(data*)malloc(sizeof(data));
			newnode->next->prev=newnode;
			newnode=newnode->next;
			
			memcpy(newnode->name,tempname,strlen(tempname)+1);
			memcpy(newnode->surname,tempsurname,strlen(tempsurname)+1);
			newnode->age=tempage;
			
			//cout<<newnode->name<<" "<<newnode->surname<<" "<<newnode->age;
			
			display(head);
		}
		else if(input==2){
			if(count==0){
				cout<<"Error!!!Empty Linked List"<<endl;	
			}
			else{
				cout<<"Input Index : ";
				cin>>tempdel;
				struct data *del;
				del=(data*)malloc(sizeof(data));
				del->next=head;
				del=del->next;
				count=0;
				while(count<tempdel){
					del=del->next;
					count++;
				}
				if(del->next->next==NULL){
					del->next->prev=NULL;
					del->next=NULL;
				}
				else{
					del->next=del->next->next;
					del->next->prev=del->next->prev->prev;
				}
				display(head);
			}
		}
		else if(input==3){
				
		}
	}
	return 0;
} 
