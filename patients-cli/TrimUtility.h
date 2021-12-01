#pragma once
#include <iostream>

std::string TrimWhitespaceAndApostrophes(std::string stringToTrim)
{
	stringToTrim.erase(
		stringToTrim.begin(),
		std::find_if(stringToTrim.begin(), stringToTrim.end(), [](unsigned char ch) {
			return !std::isspace(ch) && ch != '"';
		})
	);

	stringToTrim.erase(
		std::find_if(stringToTrim.rbegin(), stringToTrim.rend(), [](unsigned char ch) {
			return !std::isspace(ch) && ch != '"';
		}).base(),
		stringToTrim.end());

	return stringToTrim;
}