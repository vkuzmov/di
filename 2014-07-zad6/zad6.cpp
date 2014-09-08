#include <iostream>
#include <list>
using namespace std;

struct ChessPosition {
	char posX;  // A-H
	int posY;   // 1-8

	ChessPosition(): posX('A'), posY(1){
	}
	ChessPosition(char x, int y): posX(x), posY(y) { 
	}

	static bool isValid(char x, int y) {
		return (int)x <= (int)'H' && (int)x >= 'A' && y <=8 && y >=1;
	}

	void print() {
		cout<<posX<<posY;
	}
};

bool operator==(const ChessPosition & x, const ChessPosition & y) {
	return x.posX == y.posX && x.posY == y.posY;
}

class ChessPiece {
	protected: 
		ChessPosition cp;

	public:
		ChessPiece(){			
		}

		~ChessPiece(){			
		}

		ChessPiece(const ChessPiece & obj) {
		}

		ChessPiece& operator=( const ChessPiece& other );

		ChessPosition getPosition() {
			return cp;
		}

		virtual list<ChessPosition> allowedMoves() = 0;

		bool captures(ChessPosition pos) {	
			list<ChessPosition> l = this->allowedMoves();	
			list<ChessPosition>::iterator it;
    		for(it = l.begin(); it != l.end(); it++) {
        		if((*it) == pos)
        			return true;
    		}

    		return false;
		}

		void printAllowedMoves() {	
			list<ChessPosition> l = this->allowedMoves();	
			list<ChessPosition>::iterator it;
    		for(it = l.begin(); it != l.end(); it++) {
        		cout<<(*it).posX<<(*it).posY<<" ";
    		}

    		cout<<endl;
		}

		virtual void print() {
			getPosition().print();
		}
};

ChessPiece& ChessPiece::operator=( const ChessPiece& other ) {
      cp = other.cp;
      return *this;
  }

class Rook : public ChessPiece {

	public:

		Rook():ChessPiece(){

		}

		Rook(char x, int y) {
			this->cp.posX = x;
			this->cp.posY = y;
		}

		list<ChessPosition> allowedMoves(){

			list<ChessPosition> list;
			for(int i=0; i<8; i++) {
				char x = (char)(i + (int)'A');
				if(x != cp.posX) {
					list.push_back(ChessPosition(x, cp.posY));
				}
			}
			for(int i=0; i<8; i++) {
				if((i+1) !=cp.posY) {
					list.push_back(ChessPosition(cp.posX, i+1));
				}
			}

			return list;
		}

		void print() {
			cout<<"Rook ";
			ChessPiece::print();
		}
};

class Knight : public ChessPiece {

	public:
		Knight():ChessPiece(){

		}

		Knight(char x, int y) {
			this->cp.posX = x;
			this->cp.posY = y;
		}

		list<ChessPosition> allowedMoves(){

			list<ChessPosition> list;
			int xdiff[8] = {-2, 2, -2,  2, -1, -1, 1, 1};
			int ydiff[8] = { 1, 1, -1, -1,  2, -2, 2,-2};

			for(int i=0; i<8; i++) {
				ChessPosition cp = this->getPosition();

				if(ChessPosition::isValid(cp.posX + xdiff[i], cp.posY + ydiff[i])) {
					ChessPosition np = ChessPosition(cp.posX + xdiff[i], cp.posY + ydiff[i]);
					list.push_back(np);
				}
			}

			return list;
		}

		void print() {
			cout<<"Knight ";
			ChessPiece::print();
		}

};

void allMoves(list<ChessPiece*>* pieces) {

	list<ChessPiece*>::iterator it, jt;	
	list<ChessPosition>::iterator i;

	bool isCaptured = false;

	for(it = pieces->begin(); it!=pieces->end(); it++) {
		ChessPiece* cur = (*it);
		list<ChessPosition> l = cur->allowedMoves();

		cur->print();
		cout<<endl;

		for(i = l.begin(); i != l.end(); i++) {

			//(*i).print();

			isCaptured = false;
			for(jt = pieces->begin(); jt != pieces->end(); jt++) {
				//(*jt)->print();
				if(cur == (*jt))
					continue;

				isCaptured = (*jt)->captures(*i);
				if(isCaptured)
					break;
			}

			if(!isCaptured) {
				cur->print();
				cout<<" -> ";
				(*i).print();
				cout<<endl;
			} else {
				cur->print();
				cout<<" -> ";
				(*i).print();
				cout<<" CAPTURED\n";
			}


		}
	}
}

int main() {

	ChessPiece* rook = new Rook('B',3);
	ChessPosition pos = rook->getPosition();
	list<ChessPosition> l = rook->allowedMoves();

	cout<<"Rook: "<<pos.posX<<pos.posY<<endl;
	rook->printAllowedMoves();

	ChessPiece* knight = new Knight('D', 4);
	ChessPosition kp = knight->getPosition();
	cout<<"Knight: "<<kp.posX<<kp.posY<<endl;
	knight->printAllowedMoves();

	bool cap = knight->captures((new Rook('C',3))->getPosition());
	if(cap == true) {
		cout<<"Knight captures C3\n";
	} else {
		cout<<"no capture\n\n";
	}

	list<ChessPiece*>* all = new list<ChessPiece*>();
	all->push_back(rook);
	all->push_back(knight);

	allMoves(all);

	return 0;
}