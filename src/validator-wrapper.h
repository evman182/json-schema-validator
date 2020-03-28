#include <nlohmann/json-schema.hpp>
using nlohmann::json_schema::json_validator;

#ifndef JSONVALIDATORWRAPPER_LIBRARY_H
#define JSONVALIDATORWRAPPER_LIBRARY_H

#if defined DLL_EXPORTS
#	if defined WIN32
#		define LIB_API(RetType) extern "C" __declspec(dllexport) RetType
#	else
#		define LIB_API(RetType) extern "C" RetType __attribute__((visibility("default")))
#	endif
#else
#	if defined WIN32
#		define LIB_API(RetType) extern "C" __declspec(dllimport) RetType
#	else
#		define LIB_API(RetType) extern "C" RetType
#	endif
#endif

LIB_API(json_validator*) NewJsonValidator(const char *schema);

LIB_API(void) DeleteJsonValidator(json_validator* validator);

LIB_API(bool) Validate(json_validator* validator, const char *jsonObject, char* errors);

#endif //TESTLIB_LIBRARY_H