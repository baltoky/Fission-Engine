#pragma once 

#include <iostream>
#include <string>

namespace fission{

	static enum ErrorTypes{
		logWarning, logError, logDebug
	};
	static void LogError(ErrorTypes type, char* errorMessage);

}