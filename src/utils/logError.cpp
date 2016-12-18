#include "logError.h"

namespace fission{

	static void LogError(ErrorTypes type, char* errorMessage){

		std::cout << std::to_string(type) << ": ..." << errorMessage << std::endl;

	}

}