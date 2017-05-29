#include "Book.h"
#include "Product.h"
#include "Software.h"

#include <iostream>
#include <string>

using namespace std;

//Karl Burke
//x00115288

int main()
{
	int const arraySize = 10;	
	Product *prods[arraySize];
	Book *book;
	Software *software;

	double PriceIn;	
	string ProdType;
	int next = 0;

	cout << "Enter Book Details ";
	cin >> PriceIn;
	book = new Book(PriceIn);

	cout << "Enter software details ";
	cin >> PriceIn;
	software = new Software(PriceIn);

	cout << "Book Price : " << book->getGrossPrice() << endl;
	cout << "Software Price : " << software->getGrossPrice() << endl;

	prods[next] = book;
	
	next++;

	prods[next] = software; 

	next++;

	while (next < arraySize)
	{
		cout << "Enter the product type ";
		cin >> ProdType;
		cout << "Enter the gross price ";
		cin >> PriceIn;

		if (ProdType == "Software" || ProdType == "software")
		{
			prods[next] = new Software(PriceIn);

			next++;
		}
		else if (ProdType == "Book" || ProdType == "book")
		{
			prods[next] = new Book(PriceIn);

			next++;
		}	
		else
		{
			cout << endl << "Item could not be found, Please try again";
		}

	}

	for (int i = 0; i < arraySize; i++)
	{
		cout << endl << "Item Price : " << prods[i]->getGrossPrice();
	}
		
	for (int i = 0; i < arraySize; i++)
	{
		for  (int y = 0; y < arraySize-1; y ++)
		{
			if (prods[y]->getGrossPrice() < prods[y + 1]->getGrossPrice())
			{
				Product* temp = prods[y];
				prods[y] = prods[y + 1];				
				prods[y + 1] = temp;
			}
		}
	}
	/*
	No they do not return the same values. This is because
	virtual was not added to the getGrossProfit() method in 
	the product class. As an array of Product pointers was
	used the system will use the getGrossProfit() from
	the Product class rather than the Book class
	*/

	cout << endl;
	cout << endl;

	for (int i = 0; i < arraySize; i++)
	{
		cout << endl << "Item Price : " << prods[i]->getGrossPrice();
	}
	
	system("PAUSE");

	return 0;

}