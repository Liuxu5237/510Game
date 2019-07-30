#include "NickReadInfo.h"
#include "tools/StringUtility.h"
#include "tools/tools/Convert.h"

CNickReadInfo * CNickReadInfo::m_pInfo = nullptr;

CNickReadInfo * CNickReadInfo::shared()
{
	if (m_pInfo == nullptr)
	{
		try
		{
			m_pInfo = new CNickReadInfo;
			if (m_pInfo == nullptr)
			{
				throw 0;
			}
			
		}
		catch (...)
		{
			CCASSERT(false, "error:  \" create CNickReadInfo fail! \" ");
			return nullptr;
		}
	}
	return m_pInfo;
}

void CNickReadInfo::Release()
{
	if (m_pInfo != nullptr)
	{
		delete m_pInfo;
		m_pInfo = nullptr;
	}
}

CNickReadInfo::CNickReadInfo()
{
	//this->Init();
}

CNickReadInfo::~CNickReadInfo()
{

}

std::string CNickReadInfo::RandNick()
{
	if (m_vString.empty())
	{
		if (!Init())
		{
			return "";
		}
	}
	std::string name;
	for (size_t i = 0; i < m_vString.size(); ++i)
	{
		std::map<size_t, std::string> &mapBranch = m_vString[i];
		if (mapBranch.size() > 0)
		{
			size_t nIndex = rand() % mapBranch.size();
			auto itmap = mapBranch.find(nIndex);
			if (itmap == mapBranch.end())
			{
				itmap = mapBranch.begin();
			}
			name += itmap->second;
		} 
	}
	return a_u8(name.c_str());
}

bool CNickReadInfo::Init()
{
	Data data = FileUtils::getInstance()->getDataFromFile("PlatForm/RandNick.txt");
	if (data.isNull())
	{
		CCASSERT(false, "error: read RandNick.txt fail! data=null");
		return false;
	}
	std::string strBuffer = (const char*)data.getBytes();
	bool b = Split(strBuffer, '|');
	CCASSERT(b, "error:  RandNick  Split fail.");
	return b;
}

bool CNickReadInfo::Split(const std::string & str, char ch)
{
	if (str.empty())
	{
		CCASSERT(false,"null data");
		return false;
	}
	std::list<std::string>  lstString;
	size_t  nBeginPos = 0, nEndPos = 0;
	while ((nEndPos = str.find_first_of(ch, nBeginPos)) != std::string::npos)
	{
		lstString.push_back(str.substr(nBeginPos, nEndPos - nBeginPos));
		nBeginPos = ++nEndPos;
	}

	if (lstString.size() == 3)
	{
		m_vString.resize(lstString.size());
		size_t _index = 0;
		for (auto &itList : lstString)
		{
			std::map<size_t, std::string> &mapBranch = m_vString[_index];
			nBeginPos = 0, nEndPos = 0;			

			while ((nEndPos = itList.find_first_of(',', nBeginPos)) != std::string::npos)
			{
				const std::string & strBranch = itList.substr(nBeginPos, nEndPos - nBeginPos);
				if (strBranch.size() > 0)
				{
					size_t nb = 0, ne = 0;
					std::string buffer;
					if ((ne = strBranch.find_first_of("\n", nb)) != std::string::npos)
					{
						nb = ne + 1;
						buffer += strBranch.substr(nb, strBranch.size() - nb);
					}

					mapBranch[mapBranch.size()] = buffer.empty() ? strBranch : buffer;
				}
				nBeginPos = nEndPos + 1;
			}
			if (++_index >= m_vString.size())
			{
				break;
			}
		}
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////
CHarmonyString * CHarmonyString::m_pHarmony = nullptr;
CHarmonyString * CHarmonyString::shared()
{
	if (m_pHarmony == nullptr)
	{
		try
		{
			m_pHarmony = new CHarmonyString;
			if (m_pHarmony == nullptr)
			{
				throw 0;
			}

		}
		catch (...)
		{
			CCASSERT(false, "error:  \"CHarmonyString read fail! \" ");
			return nullptr;
		}
	}
	return m_pHarmony;
}

void CHarmonyString::Release()
{
	if (m_pHarmony != nullptr)
	{
		delete m_pHarmony;
		m_pHarmony = nullptr;
	}
}

CHarmonyString::CHarmonyString()
{
	//this->Init();
}

CHarmonyString::~CHarmonyString()
{

}

bool CHarmonyString::Init()
{
	Data data = FileUtils::getInstance()->getDataFromFile("PlatForm/Harmony.txt");
	if (data.isNull())
	{
		CCASSERT(false, "error: read Harmony.txt fail! data=null");
		return false;
	}
	
	m_string = (const char*)data.getBytes();
	if (m_string.empty())
	{
		CCASSERT(false, "error: Harmony m_string=null.");
		return false;
	}
	return true;
}

bool CHarmonyString::CheckString(const std::string & str)
{
	if (m_string.empty())
	{
		if (!Init())
		{
			return false;
		}
	}
	std::string StrBuffer = u8_a(str.c_str());
	size_t npos = 0, nb = 0, ne = 0;
	while ((npos = m_string.find_first_of(StrBuffer, npos)) != std::string::npos)
	{
		if ((nb = m_string.find_last_of(',', npos)) == std::string::npos)
			nb = 0;
		else
			++nb;
		if ((ne = m_string.find_first_of(',', npos)) == std::string::npos)
			ne = m_string.length();
		std::string buffer = m_string.substr(nb, ne-nb);
		if (buffer == StrBuffer)
		{
			return true;
		}
		else if (IsHave(buffer, StrBuffer))
		{
			return true;
		}
		++npos;
	}
	return false;
}

bool CHarmonyString::IsHave(const std::string &str1, const std::string &str2)
{
	if (str1.length() > str2.length())
		return false;
	size_t npos = 0;
	while ((npos = str2.find_first_of(str1, npos)) != std::string::npos)
	{
		size_t nend = str1.length();
		std::string buffer = str2.substr(npos, nend);
		if (buffer == str1)
		{
			return true;
		}
		++npos;
	}
	return false;
}
