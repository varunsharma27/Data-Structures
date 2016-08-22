#ifndef __LINKLISTS_H
#define __LINKLISTS_H

#include <iostream>

using namespace std;

class Node{
	Node* next;
	int data;
public:
	Node(){
		next = NULL;
		data = 0;
	}
	void putData(int value){
		data = value;
	}
	void putNext(Node* ptr){
		next = ptr;
	}
	int getData(){
		return data;
	}
	Node* getNext(){
		return next;
	}
};
class List{
	Node* head;
public:
	List(){
		head = NULL;
	}
	void Print(){
		if(head == NULL){
			cout<<"Empty List\n";
		}
		else{
			Node* temp = head;
			cout<<endl;
			do{
				cout<<temp->getData()<<"-->";
				temp = temp->getNext();
			}while(temp != NULL);
			cout<<"NULL";
		}
	}
	void Append(int value){
		Node* newNode = new Node();
		newNode->putData(value);
		if(head == NULL){
			head = newNode;
		}
		else{
			Node* temp;
			temp = head;
			while(temp->getNext() != NULL){
				temp = temp->getNext();
			}
			temp->putNext(newNode);
		}
	}
	void Delete(int value){
		if(head == NULL){
			cout<<"\nCannot Delete, List Empty";
		}
		else{
			Node* previous, *temp;
			int FLAG = 0;
			temp = head;
			do{
				if(temp->getData() == value){
					cout<<"\nElement Found at : "<<temp;
					FLAG = 1;
					break;
				}
				previous = temp;
				temp = temp->getNext();
			}while(temp != NULL);
			if(FLAG == 1){
				previous->putNext(temp->getNext());
				cout<<"\nDeleted...";
				delete temp;
			}
			else
				cout<<"\nUnable to Delete: Element Not Found";
		}
	}
};
#endif
