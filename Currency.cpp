#include "Currency.h"
#include <stdexcept>

/*
* @brief Currency class
* @param currencyCode - the currency code of the currency
* @param rate - the exchange rate of the currency relative to SEK
*
* This class is used to store currency codes and convert between currencies
* using fixed rates.
*/

// Initialize the static array of currency codes
std::string Currency::currencyCodes[5] = { "SEK", "DKK", "EUR", "GBP", "USD" };

// Default Constructor
Currency::Currency(std::string currencyCode) : currencyCode(std::move(currencyCode)) {}

//Parameterized constructor
std::string Currency::getCurrencyCode() const
{
	return currencyCode;
}

// Method to convert amount from this currency to another
double Currency::convertAmount(const std::string& fromCurrencyCode, const std::string& toCurrencyCode, double amount)
{
	double fromRate = getRate(fromCurrencyCode);
	double toRate = getRate(toCurrencyCode);
	return (amount * fromRate) / toRate;
}

double Currency::reverseConvert(const std::string& fromCurrencyCode, const std::string& toCurrencyCode, double amount)
{
	double fromRate = 1.0;
	double toRate = getRate(toCurrencyCode);
	return (amount * fromRate) * toRate;
}

// Method to get the exchange rate for a given currency code
double Currency::getRate(const std::string& currencyCode)
{
	if (currencyCode == "SEK") return SEK_RATE;
	if (currencyCode == "DKK") return DKK_RATE;
	if (currencyCode == "EUR") return EUR_RATE;
	if (currencyCode == "GBP") return GBP_RATE;
	if (currencyCode == "USD") return USD_RATE;
	throw std::runtime_error("Invalid currency code");
}