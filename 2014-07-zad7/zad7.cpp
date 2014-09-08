/**
 * Not perfect, but working.
 */

#include <iostream> 
using namespace std;

struct Node {
	Node *next;
	int data;
};

void print(Node* l) {
	if(l == NULL)
		return;

	Node* start = l;
	while(l->next != start) {
		cout<<l->data<<", ";
		l = l->next;
	}

	cout<<l->data<<endl;
	l = l->next;
}

Node* precedes(Node* l, int m, int n) {
	Node* start = l;
	Node* target = NULL;
	while(true) {
		if(l->data == m && l->next->data == n)
			target = l;

		l = l->next;

		if(l == start)
			break;
	}

	return target;
}

static Node* merge(Node* l1, Node* l2) {
	Node* startL1 = l1;
	Node* targetL1 = NULL;
	Node* targetL2 = NULL;
	Node* t = NULL;
	bool init = false;
	int m, n, max = 0;

	while(true) {

		if(max < (l1->data + l1->next->data) || !init) {
			init = true;
			t = precedes(l2, l1->next->data, l1->data);
			if(t != NULL) {
				max = l1->data + l1->next->data;
				targetL1 = l1;
				targetL2 = t;
				cout<<"Possible(m,n): " <<targetL1<<", "<<targetL2<<endl;
			}
		}

		l1 = l1->next;

		if(l1 == startL1)
			break;
	}

	cout<<"Best (m,n): " <<targetL1<<", "<<targetL2<<endl;
	cout<<"Best (m,n): " <<targetL1->data<<", "<<targetL2->data<<endl;
	if(targetL1 == NULL || targetL2 == NULL) {
		cout<<"The lists were not compatible\n";
		return NULL;
	}

	Node* temp = targetL1->next->next;
	targetL1->next = targetL2->next->next;
	targetL2->next = temp;

	return startL1;
}

static int count(Node* l) {
	int size = 0;

	if(l == NULL) return 0;

	Node* start = l;
	while(l->next != start) {
		size++;
		l = l->next;
	}

	size++;
	l = l->next;

	return size;
}

static Node* split(Node* l, int m, int n) {
	Node* start = l;
	Node* targetA = NULL;
	Node* targetB = NULL;
	Node* tempStart = NULL;
	Node* prev = NULL;
	Node* tempPrev = NULL;

	int maxSteps = 0;
	bool init = false;
	int size = count(l);

	while(true) {
		int steps = 0;
		if(l->data == m) {
			cout<<"Found Match >>>>\n";
			tempStart = l;

			tempPrev = l;
			l = l->next;
			
			while(true) {
				steps++;
				if(l->data == n) {
					cout<<"Investigating opportunity!\n"; 
					if((size / 2 - steps) > (size / 2 - maxSteps) || !init) {
						init = true;
						targetB = l;
						targetA = tempStart;
						prev = tempPrev;
						cout<<"possible (m,n, prev->data): " <<targetA->data<<", "<<targetB->data<<","<<prev->data<<endl;
					}
				}

				tempPrev = l;

				l = l->next;
				if(l == tempStart)
					break;
			}

			l = tempStart;
			cout<<"Continuing... "<<l->next->data<<endl;
		}

		l = l->next;

		if(l == start)
			break;
	}

	cout<<"Best (m,n): " <<targetA<<", "<<targetB<<endl;
	cout<<"Best (m,n): " <<targetA->data<<", "<<targetB->data<<endl;

	Node* temp = targetA->next;
	//for the first list
	targetA->next = targetB;

	Node newListStart;
	newListStart.data = m;
	newListStart.next = temp;

	Node newListEnd;
	newListEnd.data = n;
	newListEnd.next = &newListStart;
	prev->next = &newListEnd;

	cout<<"The old list: ";
	print(l);

	Node* s = &newListStart;
	cout<<"New List: ";
	print(s);
	cout<<s<<endl;

	return s;
}

int main() {
	
	Node n1, n2, n3, n4, n5, n6;
	n1.data = 1;
	n2.data = 2;
	n3.data = 3;
	n4.data = 4;
	n5.data = 5;
	n6.data = 3;

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n1;

	Node a1, a2, a3, a4, a5;
	a1.data = 3;
	a2.data = 2;
	a3.data = 5;
	a4.data = 8;
	a5.data = 1; //4

	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;
	a5.next = &a1;

	Node* l1 = &n1;
	Node* l2 = &a1;

	print(l1);
	print(l2);
	Node* target = precedes(l2, 1, 3);

	if(target == NULL)
		cout<<"No match"<<endl; 
	else
		cout<<"Match address: "<<target<<" Value: "<<target->data<<endl;

	Node* b = merge(l1, l2);
	print(b);

	cout<<"List size: "<<count(b)<<endl;
	Node* c = split(b, 3, 1);
	
/*	cout<<(c)<<endl<< //n1
		((c->next))<<endl<< //n2
		((c->next->next))<<endl<< //n3
		((c->next->next->next))<<endl<< //n1
		((c->next->next->next->next))<<endl;
*/
}