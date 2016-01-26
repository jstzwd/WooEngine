#include "FileUtility.h"

namespace Woo{
	namespace Utility {
		std::string ReadFile(const char* filePath) {
			FILE* file = fopen(filePath, "rt");
			fseek(file, 0, SEEK_END);
			unsigned int length = ftell(file);
			char* fileData = new char[length + 1];
			memset(fileData, 0, length);
			fseek(file, 0, SEEK_SET);
			fread(fileData, 1, length, file);
			fclose(file);
			std::string readString(fileData);
			delete[] fileData;
			return readString;
		}

	}

}