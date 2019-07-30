#include "GameVersionUpdate.h"
#include "platform/df/DF.h"
#include "tools/tools/StaticData.h"
#include "tools/tools/StringData.h"

/************************************************************************/
/* ���캯��                                                             */
/************************************************************************/
GameVersionUpdate::GameVersionUpdate() : DSFileUpdate("", "", "")
{
	
}

/************************************************************************/
/* ��������                                                             */
/************************************************************************/
GameVersionUpdate::~GameVersionUpdate()
{

}

/************************************************************************/
/* �õ�����ģ���ʵ��                                                    */
/************************************************************************/
GameVersionUpdate* GameVersionUpdate::getInstance()
{
	if (s_pFileUpdate == NULL){

		s_pFileUpdate = new GameVersionUpdate();

		if (s_updateData == NULL)
		{
			s_updateData = Array::create();
			s_updateData->retain();
		}
	}

	return (GameVersionUpdate *)s_pFileUpdate;
}

/************************************************************************/
/* ��������ģ���ʵ��                                                    */
/************************************************************************/
void GameVersionUpdate::destroyInstance()
{
	if (s_pFileUpdate)
	{
		s_pFileUpdate->release();
		s_pFileUpdate = NULL;
	}

	if (s_updateData)
	{
		s_updateData->release();
		s_updateData = NULL;
	}
}

/************************************************************************/
/* ���汾                                                              */
/************************************************************************/
bool GameVersionUpdate::CheckVersion()
{
	m_sCurVersion = UserDefault::getInstance()->getStringForKey(m_save_file_key.c_str());

	// ���ظ����ļ�
	UpdateAndLoadVersionHistoryFile();

	if (m_vVersionList.size() > 0)
	{
		std::string newestVersion = m_vVersionList[m_vVersionList.size() - 1];

		m_updateType = getUpdateType(newestVersion, m_sCurVersion);
		// ��������
		if (m_updateType == UT_ERROR)
		{
			m_updateType = UT_GAME;
			m_sCurVersion = "";
		}
		
		if (m_updateType == UT_DONT_NEED_UPDATE)
		{
			SetSearchFilePath();

			DSUpdateData * updateData = new DSUpdateData(DSUpdateNoNewVersion, "");
			if (updateData)
			{
				s_updateData->addObject(updateData);
				CCDirector::sharedDirector()->getScheduler()->resumeTarget(this);
			}
			
			CCLOG("there is no new version!");
		}
		// �ȸ��� ������ΪĿ¼��һ��
		else if (m_updateType == UT_GAME)
		{
			s_lTotalFileLenth = 0;
			s_lCurFileLenth = 0;
			m_vListLenth.clear();
			m_nListCount = 0;

			bool bMustUpdate = false;

			for (size_t i = 0; i < m_vVersionList.size(); i++)
			{
				if (determineVersion(m_vVersionList[i], m_sCurVersion))
				{
					if (bMustUpdate == false && IsMustUpdate(m_vVersionList[i], m_sCurVersion))
					{
						bMustUpdate = true;
					}

					string fileName = m_sDownFileUrl;
					fileName += m_vVersionList[i];
					fileName += ".zip";

					float lenth = this->GetDownloadFileLenth(fileName.c_str());
					if (lenth != -1.0)
					{
						s_lTotalFileLenth += lenth;
						m_vListLenth.push_back(lenth);
					}
					else
					{
						DSUpdateData *updateData = new DSUpdateData(DSUpdateNetError, m_sCurVersion);
						if (updateData)
						{
							s_updateData->addObject(updateData);
							CCDirector::sharedDirector()->getScheduler()->resumeTarget(this);
						}
						
						CCLOG("downListFile failed!");
						return false;
					}
				}
			}

		
			int nConfirmSize = StaticData::shared()->intFromKey("downloadConfirmSize");
			int nCurrentVersion = DSFileUpdate::CheStringToInt(m_sCurVersion.c_str());
			if (s_lTotalFileLenth < nConfirmSize && nCurrentVersion != 0 )
			{
				std::ostringstream stream;
				stream << s_lTotalFileLenth;

				DSUpdateData * updateData = new DSUpdateData(DSUpdateNeedSmall, stream.str());
				if (updateData)
				{
					s_updateData->addObject(updateData);
					CCDirector::sharedDirector()->getScheduler()->resumeTarget(this);
				}
			}
			else if(nCurrentVersion == 0)
			{
				float fSizeMb = s_lTotalFileLenth / (1024.0 * 1024.0);
				char szMessage[1024] = { 0 };
				std::string strFormat = StringData::shared()->stringFromKey("game_download_confirm");
				sprintf(szMessage, strFormat.c_str(), newestVersion.c_str(), fSizeMb);

				DSUpdateData * updateData = new DSUpdateData(DSUpdateNeedMust, szMessage);
				if (updateData)
				{
					s_updateData->addObject(updateData);
					CCDirector::sharedDirector()->getScheduler()->resumeTarget(this);
				}
			}
			else
			{
				
	
				float fSizeMb = s_lTotalFileLenth / (1024.0 * 1024.0);
				if (bMustUpdate)
				{
					char szMessage[1024] = { 0 };
					std::string strFormat = StringData::shared()->stringFromKey("game_update_confirm_must");
					sprintf(szMessage, strFormat.c_str(), m_sCurVersion.c_str(), newestVersion.c_str(), fSizeMb);

					DSUpdateData * updateData = new DSUpdateData(DSUpdateNeedMust, szMessage);
					if (updateData)
					{
						s_updateData->addObject(updateData);
						CCDirector::sharedDirector()->getScheduler()->resumeTarget(this);
					}
				}
				else
				{
					std::string strFormat = StringData::shared()->stringFromKey("game_update_confirm");
					char szMessage[1024] = { 0 };
					sprintf(szMessage, strFormat.c_str(), m_sCurVersion.c_str(), newestVersion.c_str(), fSizeMb);

					DSUpdateData * updateData = new DSUpdateData(DSUpdateNeed, szMessage);
					if (updateData)
					{
						s_updateData->addObject(updateData);
						CCDirector::sharedDirector()->getScheduler()->resumeTarget(this);
					}
				}
			}

			return true;
		}
	}
	else
	{
		DSUpdateData *updateData = new DSUpdateData(DSUpdateNetError, m_sCurVersion);
		if (updateData)
		{
			s_updateData->addObject(updateData);
			CCDirector::sharedDirector()->getScheduler()->resumeTarget(this);
		}
		
		CCLOG("downListFile failed!");
	}

	return false;
}


/************************************************************************/
/* ���°汾                                                              */
/************************************************************************/
void GameVersionUpdate::UpdateVersion()
{
	if (m_updateType == UT_GAME)
	{
		for (unsigned int i = 0; i < m_vVersionList.size(); i++)
		{
			if (determineVersion(m_vVersionList[i], m_sCurVersion))
			{
				setPackageUrl((m_sDownFileUrl + m_vVersionList[i] + ".zip").c_str());
				setVersionFileUrl("");
				setStoragePath(m_sPathToSave.c_str());

				if (UpdateAndLoadVersionFile())
				{
					m_sCurVersion = m_vVersionList[i];
					if (m_save_file_key != "")
					{
						UserDefault::getInstance()->setStringForKey(m_save_file_key.c_str(), m_sCurVersion);
					}

					s_lCurFileLenth += m_vListLenth[m_nListCount];
					m_nListCount = m_nListCount + 1;
				}
				else
				{
					DSUpdateData *updateData = new DSUpdateData(DSUpdateNetError, m_sCurVersion);
					if (updateData)
					{
						s_updateData->addObject(updateData);
						CCDirector::sharedDirector()->getScheduler()->resumeTarget(this);
					}
					
					return;
				}
			}
		}

		DSUpdateData *updateData = new DSUpdateData(DSUpdateFinish, "");
		if (updateData)
		{
			s_updateData->addObject(updateData);
			CCDirector::sharedDirector()->getScheduler()->resumeTarget(this);
		}
		
		CCLOG("update Finish!");
	}
	else
	{
		DSUpdateData *updateData = new DSUpdateData(DSUpdateNetError, m_sCurVersion);
		if (updateData)
		{
			s_updateData->addObject(updateData);
			CCDirector::sharedDirector()->getScheduler()->resumeTarget(this);
		}
		
	}
}

/************************************************************************/
/* �õ����µ�����                                                        */
/************************************************************************/
DSUpdateType GameVersionUpdate::getUpdateType(std::string strNewVerson, std::string strCurrentVersion)
{
	DSUpdateType ret = UT_ERROR;
	// ����°汾�Ƿ����򱨴�������Ҳû����
	int nNewVersion = DSFileUpdate::CheStringToInt(strNewVerson.c_str());
	if (nNewVersion == 0)
	{
		return ret;
	}

	int nCurrentVersion = DSFileUpdate::CheStringToInt(strCurrentVersion.c_str());
	// �汾�Ŵ���,�����¸���apk
	if (nCurrentVersion == 0)
	{
		ret = UT_GAME;
	}
	else if (nCurrentVersion > nNewVersion)
	{
		ret = UT_ERROR;
	}
	// �汾��һ�£�����Ҫ����
	else if (nCurrentVersion == nNewVersion)
	{
		ret = UT_DONT_NEED_UPDATE;
	}
	else
	{
		ret = UT_GAME;
	}

	if (nCurrentVersion > 0)
	{
		bool isBreak = false;
		for (unsigned int i = 0; i < m_vVersionList.size(); i++)
		{
			if (m_vVersionList[i] == m_sCurVersion)
			{
				isBreak = true;
				break;
			}
		}

		if (!isBreak)
		{
			ret = UT_ERROR;
		}
	}
	
	return ret;
}


