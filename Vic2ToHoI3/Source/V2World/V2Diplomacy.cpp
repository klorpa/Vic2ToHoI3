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



#include "V2Diplomacy.h"
#include "Log.h"



V2Agreement::V2Agreement(std::shared_ptr<Object> obj)
{
	type = obj->getKey();

	std::vector<std::shared_ptr<Object>> objFirst = obj->getValue("first");
	if (objFirst.size() > 0)
	{
		country1 = objFirst[0]->getLeaf();
	}
	else
	{
		LOG(LogLevel::Warning) << "Diplomatic agreement (" << type << ") has no first party";
	}

	std::vector<std::shared_ptr<Object>> objSecond = obj->getValue("second");
	if (objSecond.size() > 0)
	{
		country2 = objSecond[0]->getLeaf();
	}
	else
	{
		LOG(LogLevel::Warning) << "Diplomatic agreement (" << type << ") has no second party";
	}

	std::vector<std::shared_ptr<Object>> objDate = obj->getValue("start_date");
	if (objDate.size() > 0)
	{
		start_date = date(objDate[0]->getLeaf());
	}
}


V2Diplomacy::V2Diplomacy(std::shared_ptr<Object> obj)
{
	std::vector<std::shared_ptr<Object>> objVassals = obj->getValue("vassal");
	for (std::vector<std::shared_ptr<Object>>::iterator itr = objVassals.begin(); itr != objVassals.end(); ++itr)
	{
		V2Agreement agr(*itr);
		agreements.push_back(agr);
	}

	std::vector<std::shared_ptr<Object>> objAlliances = obj->getValue("alliance");
	for (std::vector<std::shared_ptr<Object>>::iterator itr = objAlliances.begin(); itr != objAlliances.end(); ++itr)
	{
		V2Agreement agr(*itr);
		agreements.push_back(agr);
	}

	std::vector<std::shared_ptr<Object>> objCBs = obj->getValue("causus_belli");
	for (std::vector<std::shared_ptr<Object>>::iterator itr = objCBs.begin(); itr != objCBs.end(); ++itr)
	{
		V2Agreement agr(*itr);
		agreements.push_back(agr);
	}

	std::vector<std::shared_ptr<Object>> objSubsidies = obj->getValue("warsubsidy");
	for (std::vector<std::shared_ptr<Object>>::iterator itr = objSubsidies.begin(); itr != objSubsidies.end(); ++itr)
	{
		V2Agreement agr(*itr);
		agreements.push_back(agr);
	}
}