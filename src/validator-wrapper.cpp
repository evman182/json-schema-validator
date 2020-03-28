#include "validator-wrapper.h"

#include <iomanip>
#include <iostream>

#include <nlohmann/json-schema.hpp>

using nlohmann::json;
using nlohmann::json_schema::json_validator;


json_validator* NewJsonValidator(const char *schema)
{
	json parsedSchema = json::parse(schema);
	json_validator* validator = new json_validator();
	validator->set_root_schema(parsedSchema);
	return validator;
}

void DeleteJsonValidator(json_validator* validator)
{
	delete validator;
}

bool Validate(json_validator* validator, const char *jsonObject, char *errors)
{	
	json parsedJson = json::parse(jsonObject);

	try {
		validator->validate(parsedJson);
	} catch (const std::exception &e) {
		sprintf(errors, e.what());
		return false;
	}

	return true;
}