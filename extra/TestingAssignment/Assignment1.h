#pragma once

#include <iostream>
#include <exception>
#include <string.h>


class ExceptieAssignment2 : public std::exception {

};

using namespace std;

/*
	Sa se implementeze functia withdraw ce accepta doi parametri:
	- balance - reprezinta balanta contului curent
	- amount - reprezinta suma pe care dorim sa o extragem din cont
	Functia trebuie sa respecte urmatoarele cerinte:
	- La apelul functiei withdraw se va extrage din balanta suma dorita
	(Exemplu: In urma apelului withdraw(2000, 1000), balanta va avea valoarea 1000)
	- Daca balanta este negativa si se incearca efectuarea unei tranzactii
	se va aplica o penalizare de 10% asupra balantei, fara a efectua tranzactia
	(Exemplu: pentru o balanta de -1000, la incercarea efectuarii unei tranzactii
	balanta va avea valoarea de -1100).
	- Daca suma pe care dorim sa o extragem este negativa, se va efectua operatia de
	depunere. (pentru o balanta de 1000, la apelul functiei cu un amount de -200, vom
	obtine balanta cu valoarae 1200)
	- Daca suma dorita este mai mare decat valoarea balantei, nu se va efectua nicio operatie
	- Daca se va efectua operatia de withdraw cu amount 0, se va aplica o penalizare de 5% asupra balantei
*/

/*

	Implement the withdraw function that accepts two parameters:
	- balance - represents the balance of the current account
	- amount - represents the amount we want to withdraw from the account
	The function must meet the following requirements:
	- When calling the withdraw function, the desired amount will be extracted from the balance
	(Example: Following the withdraw call (2000, 1000), the balance will have the value 1000)
	- If the balance is negative and an attempt is made to make a transaction
	a 10% penalty will be applied on the balance, without making the transaction
	(Example: for a balance of -1000, when trying to make a transaction
	the balance will have the value of -1100).
	- If the amount we want to withdraw is negative, the operation will be performed
	deposit. (for a balance of 1000, at the call of the function with an amount of -200, we
	get the balance with values ??1200)
	- If the desired amount is greater than the balance value, no operation will be performed
	- If the withdrawal operation is performed with amount 0, a penalty of 5% will be applied on the balance
*/

void withdraw(double* balance, double amount) {
	if (*balance < 0) {
		*balance = *balance - (10 / 100) * (*balance);
	}
	if (amount < 0) {
		*balance = *balance - amount;
	}
	else if (amount == 0) {
		*balance = *balance - (5 / 100) * (*balance);
	}
	else if (amount > *balance) {
		return;
	}
	else *balance = *balance - amount;   //amount <balance
}

/*
	Aceeasi cerinta si pentru withdraw2
	Same requirement for withdraw2
*/

void withdraw2(double& balance, double amount) {
	if (balance < 0) {
		balance = balance - (10 / 100) * (balance);
	}
	if (amount < 0) {
		balance = balance - amount;
	}
	else if (amount == 0) {
		balance = balance - (5 / 100) * (balance);
	}
	else if (amount > balance) {
		return;
	}
	else balance = balance - amount;   //amount <balance
}

/*
	Sa se implementeze metoda toTitleCase(char* text) care transforma un text primit in formatul Title Case
	- toate cuvintele incep cu majuscula
	- ex: "salut. acesta este un test" devine "Salut. Acesta Este Un Test"

	Implement the toTitleCase (char * text) method that converts received text to Title Case format
	- all words start with a capital letter
	- ex: "hello. this is a test" becomes "Hello. This Is A Test"
*/

char* toTitleCase(const char* text) {
	char* text2;
	strcpy(text2, text);
	if (text2[0] > 'a' && text2[0] < 'z') {
		text2[0] = text2[0] - 32;
	}
	for (int i = 1; i < strlen(text2); i++) {
		if (text2[i] == ' ') {
			if (text2[i + 1] > 'a' && text2[i + 1] < 'z') {
				text2[i + 1] = text2[i + 1] - 32;
			}
		}
	}
}

	/*
		Sa se implementeze metoda removeSpaces(char* text) care elimina toate spatiile dintr-un text primit
		- se iau in considerare toate spatiile (la inceput, la final si in interior)
		- ex: " salut.   acesta este un test " devine "salut.acestaesteuntest"


		Implement the removeSpaces (char * text) method which removes all spaces from a received text
		- all spaces are taken into account (at the beginning, at the end and inside)
		- ex: "hello. this is a test" becomes "hello.thisisatest"
	*/

	char* removeSpaces(const char* text) {
		char* text3;
		strcpy(text3, text);
		for (int i = 0; i < strlen(text3) + 1; i++) {
			if (text3[i] == ' ') {
				strcpy(text3, (text3)+1);
			}
		}
	}


	/*
	input
	- un vector de numere intregi
	- dimensiunea vectorului
	- o valoare data
	return
	- numarul de elemente din vector ce sunt mai mari sau egale cu valoarea data
	*/

	int numarElementeMaiMari(int* valori, int nrValori, int valoarePrag) {
		int nr = 0;
		for (int i = 0; i < nrValori; i++) {
			if (valori[i] >= valoarePrag) {
				nr++;
			}
		}
		return nr;
	}

	/*
	Functia extrage dintr-un vector dat toate elementele ce sunt mai mari sau egale cu o valoare prag data

	input
	- un vector de numere intregi
	- dimensiunea vectorului
	- o valoare data
	return
	- un vector nou (creat in HEAP) ce contine toate elementele mai mari sau egale cu valoarea prag
	- NULL daca in vectorul initial nu exista elemente mai mari sau egale
	*/

	int* filtrareElementeMaiMari(int* valori, int nrValori, int valoarePrag) {
		int* vectorNou = new int[nrValori];
		int nr = 0;
		for (int i = 0; i < nrValori; i++) {
			if (valori[i] >= valoarePrag) {
				vectorNou[i] = valori[i];
				nr++;
			}
		}
		if (nr > 0) {
			return vectorNou;
		}
		else return nullptr;
	}


	/*
	Functia extrage dintr-un vector dat toate elementele ce sunt mai mari sau egale cu o valoare prag data

	input
	- un vector de numere intregi
	- dimensiunea vectorului
	- o valoare data
	return
	- un vector nou ce contine toate elementele mai mari sau egale cu valoarea prag; pointerul catre noul vector este primit in lista de argumente
	- NULL daca in vectorul initial nu exista elemente mai mari sau egale
	*/

	void filtrareElementeMaiMari2(const int* valori, int nrValori, int valoarePrag, int** valoriMaiMari) {
		for (int i = 0; i < nrValori; i++) {
			if (valori[i] >= valoarePrag) {
				*valoriMaiMari[i] = valori[i];
			}
		}
	}

	/*
	Functia extrage elementul de pe pozitia index

	input
	- un vector de numere intregi
	- dimensiunea vectorului
	- indexul elementului (valoare pentru index trebuie sa fie validata) - daca valoarea pentru index nu este ok atunci se arunca o exceptie de tip
			ExceptieAssignment2 cu "throw new ExceptieAssignment2()"
	return
	- elementul de pe pozitia index
	- exceptie daca indexul nu este valid
	*/


	/*
	The function extracts the item from the index position

	input
	- an integer vector
	- vector size
	- element index (value for index must be validated) - if the value for index is not ok then throw a type exception
	ExceptionAssignment2 with "throw new ExceptionAssignment2 ()"
	return
	- the item on the index position
	- exception if the index is invalid
	*/

	int getElement(const int* valori, int nrValori, int index) {
		if (index > nrValori || index < 0) {
			throw new ExceptieAssignment2();
		}
		else {
			int element;
			element = valori[index];
			return element;
		}

	}


	/*
	Functia extrage un subvector din vectorul primit - [index_start, index_final]

	input
	- un vector de numere intregi
	- dimensiunea vectorului
	- index start si index final
		- daca valoarea pentru oricare index nu este ok atunci se arunca o exceptie de tip
			ExceptieAssignment2 cu "throw new ExceptieAssignment2()"
		- daca index start este egal cu index final atunci se returneaza un sub-vector ce contine elementul de pe pozitia index start
		- daca index start este mai mare decat index final atunci se arunca o exceptie de tip ExceptieAssignment2
	return
	- un vector nou
	- dimensiunea vectorului nou este returnata prin referinta dimensiuneSubvector din lista de argumente
	- exceptie daca indexul nu este valid
	*/

	/*

	The function extracts a subvector from the received vector - [index_start, index_final]

	input
	- an integer vector
	- vector size
	- start index and final index
	- if the value for any index is not ok then an ExceptionAssignment2 exception is thrown with "throw new ExceptionAssignment2 ()"
	- if the start index is equal to the final index then a sub-vector is returned that contains the element from the start index position
	- if the start index is higher than the final index then an ExceptionAssignment2 exception is thrown
	return
	- a new vector
	- the size of the new vector is returned by the sizeSubvector reference in the argument list
	- exception if the index is invalid

	*/

	int* slice(const int* valori, int nrValori, int indexStart, int indexFinal, int& dimensiuneSubvector) {
		int* subvector = new int[indexFinal - indexStart + 1];
		int nrElemente = 0;
		if ((indexStart < 0 || indexFinal > nrValori) || (indexStart < 0 && indexFinal > nrValori)){
			throw new ExceptieAssignment2();
		}
		if (indexStart == indexFinal) {
			return subvector;
		}
		else if (indexStart > indexFinal) {
			throw new ExceptieAssignment2();
		}
		else {                                 //indexStart < indexFinal
			for (int i = indexStart; i <= indexFinal; i++) {
				subvector[i] = valori[i];
				nrElemente++;
			}
			dimensiuneSubvector = nrElemente;
			return subvector;
		}

	}



