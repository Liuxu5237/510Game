#include "PlatformGameConfig.h"
#include "tools/StringUtility.h"


CPlatformGameConfig * CPlatformGameConfig::st_platformGameConfig = NULL;

/************************************************************************/
/* ��ȡ����                                                             */
/************************************************************************/
CPlatformGameConfig * CPlatformGameConfig::shared()
{
	if (st_platformGameConfig == NULL)
	{
		st_platformGameConfig = new CPlatformGameConfig;
		st_platformGameConfig->loadConfig();
	}
	return st_platformGameConfig;
}

/************************************************************************/
/* ���ٶ���                                                              */
/************************************************************************/
void CPlatformGameConfig::purge()
{
	if (st_platformGameConfig)
	{
		delete st_platformGameConfig;
	}
}

/************************************************************************/
/* ���캯��                                                             */
/************************************************************************/
CPlatformGameConfig::CPlatformGameConfig()
{
	m_configData = NULL;
}

/************************************************************************/
/* ��������                                                             */
/************************************************************************/
CPlatformGameConfig::~CPlatformGameConfig()
{
	m_configData->release();
}

/************************************************************************/
/* ���������ļ�                                                          */
/************************************************************************/
void CPlatformGameConfig::loadConfig()
{
	if (m_configData)
	{
		m_configData->release();
		m_configData = NULL;
	}

	ValueVector arr2_ = FileUtils::getInstance()->getValueVectorFromFile("platform_game_config.plist");

	m_configData = utility::visitArray(arr2_);
}

/************************************************************************/
/* �õ���ǰ���ַ���                                                      */
/************************************************************************/
std::string CPlatformGameConfig::getValue(int gameID, const char * key)
{
	if (m_configData)
	{
		for (int i = 0; i < m_configData->count(); i++)
		{
			__Dictionary* ani = (__Dictionary*)m_configData->getObjectAtIndex(i);
			if (ani)
			{
				DictionaryAide aide(ani);

				int id = aide.intFromKey("game_id");
				if (id == gameID)
				{
					return aide.stringFromKey(key);
				}
			}
		}
	}

	return "";
}