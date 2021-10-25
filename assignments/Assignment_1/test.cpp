#include "pch.h"
#include "Assignment1.h"


int vectorInitial[] = { 23,67,89,102,560,1000 };
int nrElemente = 6;

double balance = 5000;

TEST(TestWithdraw, TestNegativeBalance) {
	double negative_balance = -5;
	withdraw(&negative_balance, 2000);
	EXPECT_TRUE(negative_balance == -5.5);
}

TEST(TestWithdraw, TestNegativeAmount) {
	double balance = 10;
	withdraw(&balance, -10);
	EXPECT_EQ(balance, 20);
}

TEST(TestWithdraw, TestBalanceTooLow) {
	double balance = 1000;
	withdraw(&balance, 1100);
	EXPECT_EQ(balance, 1000);
}

TEST(TestWithdraw, TestZeroAmount) {
	double balance = 5000;
	withdraw(&balance, 0);
	EXPECT_EQ(balance, 4750);
}

TEST(TestWithdraw, RightTest) {
	double balance = 2000;
	withdraw(&balance, 1000);
	EXPECT_EQ(balance, 1000);
}

//withdraw2

TEST(TestWithdraw2, TestNegativeBalance) {
	double negative_balance = -5;
	withdraw2(negative_balance, 2000);
	EXPECT_TRUE(negative_balance == -5.5);
}

TEST(TestWithdraw2, TestNegativeAmount) {
	double balance = 10;
	withdraw2(balance, -10);
	EXPECT_EQ(balance, 20);
}

TEST(TestWithdraw2, TestBalanceTooLow) {
	double balance = 1000;
	withdraw2(balance, 1100);
	EXPECT_EQ(balance, 1000);
}

TEST(TestWithdraw2, TestZeroAmount) {
	double balance = 5000;
	withdraw2(balance, 0);
	EXPECT_EQ(balance, 4750);
}

TEST(TestWithdraw2, RightTest) {
	double balance = 2000;
	withdraw2(balance, 1000);
	EXPECT_EQ(balance, 1000);
}

// titlecase

TEST(TestTitleCase1, RightTest) {
	char* text = "salut. ce mai faci";
	char* newText = toTitleCase(text);
	ASSERT_TRUE(newText != nullptr);
	EXPECT_EQ(strcmp(newText, "Salut. Ce Mai Faci"), 0);
}

TEST(TestTitleCase2, RightTest) {
	char* text = "01 salut. Ce mai Faci?";
	char* newText = toTitleCase(text);
	ASSERT_TRUE(newText != nullptr);
	EXPECT_EQ(strcmp(newText, "01 Salut. Ce Mai Faci?"), 0);
}

TEST(TestTitleCase3, SameReferenceTest) {
	char* text = "01 salut. Ce mai Faci?";
	char* newText = toTitleCase(text);
	ASSERT_TRUE(newText != nullptr);
	EXPECT_NE(text, newText);
}

// removeSpaces

TEST(TestRemoveSpaces, RightTest) {
	char* text = " salut.   acesta este un test ";
	char* newText = removeSpaces(text);
	ASSERT_TRUE(newText != nullptr);
	EXPECT_EQ(strcmp(newText, "salut.acestaesteuntest"), 0);
}


TEST(NumarElementeMaiMari, TestNormal) {
	int valoarePrag = 100;
	int rezultat = numarElementeMaiMari(vectorInitial, nrElemente, valoarePrag);
	EXPECT_EQ(rezultat, 3);
}

TEST(NumarElementeMaiMari, TestLimita) {
	int valoarePrag = 102;
	int rezultat = numarElementeMaiMari(vectorInitial, nrElemente, valoarePrag);
	EXPECT_EQ(rezultat, 3);
}

TEST(NumarElementeMaiMari, TestOut) {
	int valoarePrag = 2000;
	int rezultat = numarElementeMaiMari(vectorInitial, nrElemente, valoarePrag);
	EXPECT_EQ(rezultat, 0);
}

TEST(FiltrareElementeMaiMari, TestNormal1) {
	int valoarePrag = 100;
	int* rezultat = filtrareElementeMaiMari(vectorInitial, nrElemente, valoarePrag);
	ASSERT_TRUE(rezultat != nullptr);
	EXPECT_EQ(rezultat[0], 102);
}

TEST(FiltrareElementeMaiMari, TestNormal2) {
	int valoarePrag = 100;
	int* rezultat = filtrareElementeMaiMari(vectorInitial, nrElemente, valoarePrag);
	ASSERT_TRUE(rezultat != nullptr);
	EXPECT_EQ(rezultat[2], 1000);
}

TEST(FiltrareElementeMaiMari, TestNULL) {
	int valoarePrag = 2000;
	int* rezultat = filtrareElementeMaiMari(vectorInitial, nrElemente, valoarePrag);
	ASSERT_TRUE(rezultat == NULL);
}

TEST(FiltrareElementeMaiMari2, TestNormal1) {
	int valoarePrag = 100;
	int* rezultat = nullptr;
	filtrareElementeMaiMari2(vectorInitial, nrElemente, valoarePrag, &rezultat);
	ASSERT_TRUE(rezultat != nullptr);
	EXPECT_EQ(rezultat[1], 560);
}

TEST(FiltrareElementeMaiMari2, TestNormal2) {
	int valoarePrag = 100;
	int* rezultat = nullptr;
	filtrareElementeMaiMari2(vectorInitial, nrElemente, valoarePrag, &rezultat);
	ASSERT_TRUE(rezultat != nullptr);
	EXPECT_EQ(rezultat[2], 1000);
}

TEST(FiltrareElementeMaiMari2, TestNULL) {
	int valoarePrag = 2000;
	int* rezultat;
	filtrareElementeMaiMari2(vectorInitial, nrElemente, valoarePrag, &rezultat);
	EXPECT_TRUE(rezultat == NULL);
}


TEST(GetElement, TestNormal1) {
	int rezultat = getElement(vectorInitial, nrElemente, 1);
	EXPECT_EQ(rezultat, 67);
}

TEST(GetElement, TestNormal2) {
	for (int i = 0; i < nrElemente; i++) {
		int rezultat = getElement(vectorInitial, nrElemente, i);
		EXPECT_EQ(rezultat, vectorInitial[i]);
	}
}

TEST(GetElement, TestExceptieIndexNegativ) {
	try {
		int rezultat = getElement(vectorInitial, nrElemente, -1);
		FAIL();
	}
	catch (ExceptieAssignment2* ex) {
		SUCCEED();
	}
	catch (...) {
		FAIL();
	}
}

TEST(GetElement, TestExceptieIndexLimita) {
	try {
		int rezultat = getElement(vectorInitial, nrElemente, nrElemente);
		FAIL();
	}
	catch (ExceptieAssignment2* ex) {
		SUCCEED();
	}
	catch (...) {
		FAIL();
	}
}

TEST(GetElement, TestExceptieIndexPreaMare) {
	try {
		int rezultat = getElement(vectorInitial, nrElemente, 1000);
		FAIL();
	}
	catch (ExceptieAssignment2* ex) {
		SUCCEED();
	}
	catch (...) {
		FAIL();
	}
}


TEST(Slice, TestNormal1) {
	//89,102,560
	int dimSlice;
	int* rezultat = slice(vectorInitial, nrElemente, 2, 4, dimSlice);
	ASSERT_TRUE(rezultat != nullptr);
	EXPECT_EQ(rezultat[0], 89);
}

TEST(Slice, TestNormal2) {
	//89,102,560
	int dimSlice;
	int* rezultat = slice(vectorInitial, nrElemente, 2, 4, dimSlice);
	ASSERT_TRUE(rezultat != nullptr);
	EXPECT_EQ(rezultat[2], 560);
}

TEST(Slice, TestNormal3) {
	//89,102,560
	int dimSlice;
	int* rezultat = slice(vectorInitial, nrElemente, 2, 4, dimSlice);
	EXPECT_EQ(dimSlice, 3);
}

TEST(Slice, TestNormalIndexEgal1) {
	//89,102,560
	int dimSlice;
	int* rezultat = slice(vectorInitial, nrElemente, 2, 2, dimSlice);
	ASSERT_TRUE(rezultat != nullptr);
	EXPECT_EQ(dimSlice, 1);
}

TEST(Slice, TestNormalIndexEgal2) {
	//89,102,560
	int dimSlice;
	int* rezultat = slice(vectorInitial, nrElemente, 2, 2, dimSlice);
	ASSERT_TRUE(rezultat != nullptr);
	EXPECT_EQ(rezultat[0], 89);
}

TEST(Slice, TestExceptieIndexStartNegativ) {
	try {
		int dimSlice;
		int* rezultat = slice(vectorInitial, nrElemente, -2, 4, dimSlice);
		FAIL();
	}
	catch (ExceptieAssignment2* ex) {
		SUCCEED();
	}
	catch (...) {
		FAIL();
	}
}

TEST(Slice, TestExceptieIndexFinalNegativ) {
	try {
		int dimSlice;
		int* rezultat = slice(vectorInitial, nrElemente, 2, -4, dimSlice);
		FAIL();
	}
	catch (ExceptieAssignment2* ex) {
		SUCCEED();
	}
	catch (...) {
		FAIL();
	}
}

TEST(Slice, TestExceptieIndexFinalPreaMare) {
	try {
		int dimSlice;
		int* rezultat = slice(vectorInitial, nrElemente, 2, 40, dimSlice);
		FAIL();
	}
	catch (ExceptieAssignment2* ex) {
		SUCCEED();
	}
	catch (...) {
		FAIL();
	}
}

TEST(Slice, TestExceptieIndex) {
	try {
		int dimSlice;
		int* rezultat = slice(vectorInitial, nrElemente, 2, 1, dimSlice);
		FAIL();
	}
	catch (ExceptieAssignment2* ex) {
		SUCCEED();
	}
	catch (...) {
		FAIL();
	}
}

