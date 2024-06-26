/**
 * @file ParseParams.hpp
 * @author Michal Solanik
 * @brief Parser of arguments from CLI
 * @version 0.1
 * @date 2021-07-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef PARSE_PARAMS_H
#define PARSE_PARAMS_H

#include <string>
#include "ParamsCarrier.hpp"

/**
 * @brief ParseParams is responsible for parsing arguments from CLI.
 * 
 */
class ParseParams
{
public:
	/**
	 * @brief Parse params from CLI.
	 * 
	 * @param argc Number of arguments
	 * @param argv Arguments
	 * @return 1 in the case of successfully parsed arguments and
	 * -1 in the case of failure. 
	 */
	int parseParams(int argc, char **argv);

	/**
	 * @brief Get the Params object
	 * 
	 * @return ParamsCarrier* with parsed arguments
	 */
	ParamsCarrier *getParams();
	
private:
	/**
	 * @brief Instance of ParamsCarrier for placing 
	 * parsed arguments.
	 * 
	 */
	ParamsCarrier *singleTone;

	/**
	 * @brief Print basic parameters which are used in simulation.
	 * 
	 * @param params Data structure holding input data.
	 */
	void printParameters(ParamsCarrier *params);

	/**
	 * @brief Return path where Geliosphere is located.
	 * 
	 * @param argv Geliosphere parameters
	 * @return Path where Geliosphere is located
	 */
	std::string getApplicationPath(char **argv);
};

#endif