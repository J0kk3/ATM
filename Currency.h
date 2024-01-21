#pragma once
#include <string>

class Currency
{
private:
	// Array with currencyCodes
	static std::string currencyCodes[5];
	std::string currencyCode;

	// Constants for exchange rates relative to SEK
	static constexpr double SEK_RATE = 1.0;
	static constexpr double EUR_RATE = 11.40;
	static constexpr double DKK_RATE = 1.53;
	static constexpr double GBP_RATE = 13.29;
	static constexpr double USD_RATE = 10.46;

public:
	// Constructor
	Currency(std::string currencyCode);

	// Getters
	std::string getCurrencyCode() const;

	// Method to convert amount from this currency to another
	static double convertAmount(const std::string& fromCurrencyCode, const std::string& toCurrencyCode, double amount);

	// Method to get the exchange rate for a given currency code
	static double getRate(const std::string& currencyCode);
};