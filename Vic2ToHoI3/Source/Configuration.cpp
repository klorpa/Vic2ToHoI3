/*Copyright (c) 2019 The Paradox Game Converters Project

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.*/



#include "Configuration.h"
#include "ParadoxParserUTF8.h"
#include "Object.h"
#include "Log.h"
#include <cstdlib>
#include <vector>
using namespace std;



Configuration* Configuration::instance = NULL;

Configuration::Configuration()
{
	LOG(LogLevel::Info) << "Reading configuration file";

	std::shared_ptr<Object> oneObj = parser_UTF8::doParseFile("configuration.txt");	// the parsed configuration file
	if (oneObj == NULL)
	{
		LOG(LogLevel::Error) << "Could not open configuration.txt";
		std::exit(-1);
	}

	vector<std::shared_ptr<Object>> obj = oneObj->getValue("configuration");	// the configuration section
	if (obj.size() != 1)
	{
		LOG(LogLevel::Error) << "Configuration file must contain exactly one configuration section";
		exit (-1);
	}

	V2Path				= obj[0]->safeGetString("V2directory");
	V2DocumentsPath	= obj[0]->safeGetString("V2Documentsdirectory");
	HoI3Path				= obj[0]->safeGetString("HoI3directory");
	HoI3DocumentsPath = obj[0]->safeGetString("HoI3Documentsdirectory");
	outputName			= "";

	vector<std::shared_ptr<Object>> modsObj = obj[0]->getValue("Vic2Mods");
	if (modsObj.size() > 0)
	{
		Vic2Mods = modsObj[0]->getTokens();
	}

	factionLeaderAlgorithm	= obj[0]->safeGetString("faction_leader");
	if (factionLeaderAlgorithm == "manual")
	{
		vector<std::shared_ptr<Object>> factionObj = obj[0]->getValue("axis_faction");
		if (factionObj.size() > 0)
		{
			manualAxisFaction = factionObj[0]->getTokens();
		}
		factionObj = obj[0]->getValue("allies_faction");
		if (factionObj.size() > 0)
		{
			manualAlliesFaction = factionObj[0]->getTokens();
		}
		factionObj = obj[0]->getValue("comintern_faction");
		if (factionObj.size() > 0)
		{
			manualCominternFaction = factionObj[0]->getTokens();
		}
	}

	minInfra					= obj[0]->safeGetFloat("min_infrastructure");
	icConversion			= obj[0]->safeGetString("ic_conversion");
	icFactor					= obj[0]->safeGetFloat("ic_factor");
	manpowerConversion	= obj[0]->safeGetString("manpower_conversion");
	manpowerFactor			= obj[0]->safeGetFloat("manpower_factor");
	leadershipConversion	= obj[0]->safeGetString("leadership_conversion");
	leadershipFactor		= obj[0]->safeGetFloat("leadership_factor");
	literacyWeight			= obj[0]->safeGetFloat("literacy_weight");
	practicalsScale		= obj[0]->safeGetFloat("practicals_scale");

	leaderID					= 1000;
	leaderIDCountryIdx	= 1;
}