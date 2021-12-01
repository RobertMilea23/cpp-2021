#include <iostream>
#include <string>
using namespace std;

// a fidelity card class that records the number of points that a clietn will get for each payment
// clasa Card Fidelitate ce inregistreaza numarul de puncte castigate de client de fiecare data cand efectueaza o plata
class FidelityCard {
public:
	const int id;			//constant attribute - generated based on noCards value
private:
	char owner[50];
	string cardType;		//the service that provides the card (ex. Rompetrol, Mega Image, etc)

	int* points;			//points accumulated each time the client buys something
	int noPayments;			//number of pamyments done by the client

	static int noCards;		//incremented for each created card
public:
	const static int MIN_POINTS_FOR_PREMIUM;		//init with 1000 - the minimum points for becoming a premium member

public:
	/*
		//constructors
		//constructori
	*/

	FidelityCard();			//sets name to John Doe and cardType to "None" | initializeaza numele cu John Doe si tipul cardului cu "None"
	FidelityCard(const char* name, string cardName);
	FidelityCard(const char* name, string cardName, int* existingPoints, int noPoints);

	//copy constructor
	//TO DO

	//destructor
	//TO DO

	// overload operator =
	//TO DO

	/*

	//public interface - your choice
	//interfata publica

	*/


	/*

		//requried operators - check main
		//operatori - verifica cerintele din main()

	*/

	//TO DO
	//implement the required operators as class member functions or global functions so the examples from main will work
	//implementeaza operatorii indicati in main ca functii membre in clasa sau functii globale, astfel incat exemplele din main vor rula
};

int FidelityCard::noCards = 0;

void main() {

	//test class functions


	//test destructor


	//operators section

	FidelityCard card1("No Name", "Blank");
	FidelityCard card2 = card1;


	// cout << card1
	// cout << card2;
	// cin >> card1
	// cout << card1

	int somePoints[] = { 15,5,10,30 };
	int noPoints = 4;
	FidelityCard card3("John", "ACME Inc", somePoints, noPoints);
	FidelityCard card4 = card3;

	//operator =
	//without MEMORY LEAKS
	//card2 = card1;			//copy data to card 1 from card 2 | copiaza datele cardului 1 in cardul 2
	// cout << card2;


	//card1 = card3 + 15;   //adds new points | adauga puncte noi
	//card1 = 20 + card1;   //adds new points | adauga puncte noi
	//card1 += 10;		    //adds new points | adauga puncte noi

	//cout << card1;

	FidelityCard card5("No Name", "Blank");
	//card5 = card1 - 20;		//spends 20 points | utilizeaza 20 de puncte de pe card
	//card5 -= 10;				//spends 10 more points | utilizeaza inca 10 de puncte de pe card

	//card5 = card5 * 2;		//doubles all existing points | dubleaza toate punctele existente
	
	//cout << card5;

	FidelityCard card6("No Name", "Blank");

	//postincrement
	//card6 = card3++;			// adds 10 more points | adauga inca 10 puncte
	//cout << card6;
	//cout << card3;


	//preincrement
	//card6 = ++card;			// adds 10 more points | adauga inca 10 puncte
	//cout << card6;
	//cout << card3;

	//postdecrement
	//card6 = card3--;			// removes the last entr in the points array
	//cout << card6;
	//cout << card3;


	//predecrement
	//card6 = --card;			// removes the last entry in the points array
	//cout << card6;
	//cout << card3;


	//if (card6 > card2) {
	//	cout << endl << card6.getName() << " has more points than " << card2.getName();
	//}

	//if (card6 < card2) {
	//	cout << endl << card6.getName() << " has less points than " << card2.getName();
	//}

	//if (card6 == card2) {
	//	cout << endl << card6.getName() << " has the same amount of points as " << card2.getName();
	//}

	//if (card6 >= card2) {
	//	cout << endl << card6.getName() << " has more or equal points than " << card2.getName();
	//}


	//explicit cast
	//int totalPoints = (int)card3;		//get total points on the card | determina numarul total de puncte


	//int somePoints = card3[1];			//returns the number of points from the array on index 1 | intorce numarul de puncte de pe pozitia 1 din vectorul de puncte
	//card3[0] = 25;						//allows you to change the points value at index 0 in the array | iti permite sa modifici numarul de puncte de la index 0 in vectorul de puncte					

	//int partialSum = card3(1, 3);			//determines the sum of points from index 1 to 3 (including 3) | determina numarul de puncte de la indexul 1 pana la 3 (inclusiv)

	//card6 = !card3;						//returns a copy of card with 0 points | returneaza o copie a cardului 3 fara a pastra punctele


}