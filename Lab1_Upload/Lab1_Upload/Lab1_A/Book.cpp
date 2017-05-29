#include "Book.h"

Book::Book(double price) : Product(price)
{
}

double Book::getGrossPrice()
{
	return NetPrice;
}
