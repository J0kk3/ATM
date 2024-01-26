#include "Currency.h"
#include <stdexcept>
#include <random>

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
	double newAmount = (amount * fromRate) / toRate;
	return newAmount;
}

double Currency::reverseConvert(const std::string& toCurrencyCode, double newAmount)
{
	double toRate = getRate(toCurrencyCode);
	double reversedAmount = newAmount * toRate;
	return reversedAmount;
}

// Method to get the exchange rate for a given currency code
double Currency::getRate(const std::string& currencyCode)
{
	std::string upperCaseCode = currencyCode;
	// Convert currency code to uppercase
	std::transform(upperCaseCode.begin(), upperCaseCode.end(), upperCaseCode.begin(), ::toupper);

	if (upperCaseCode == "SEK") return SEK_RATE;
	if (upperCaseCode == "DKK") return DKK_RATE;
	if (upperCaseCode == "EUR") return EUR_RATE;
	if (upperCaseCode == "GBP") return GBP_RATE;
	if (upperCaseCode == "USD") return USD_RATE;
	throw std::runtime_error("Invalid currency code");
}