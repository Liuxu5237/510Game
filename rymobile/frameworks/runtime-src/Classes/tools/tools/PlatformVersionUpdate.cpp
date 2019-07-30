#include "PlatformVersionUpdate.h"
#include "platform/df/DF.h"
#include "tools/tools/StaticData.h"
#include "tools/tools/StringData.h"
#include "platform/data/PlatformGameConfig.h"
/************************************************************************/
/* 构造函数                                                             */
/************************************************************************/
PlatformVersionUpdate::PlatformVersionUpdate() : DSFileUpdate("","","")
{
	
}

/************************************************************************/
/* 析构函数                                                             */
/************************************************************************/
PlatformVersionUpdate::~PlatformVersionUpdate()
{
	
}

/************************************************************************/
/* 得到下载模块的实例                                                    */
/************************************************************************/
PlatformVersionUpdate* PlatformVersionUpdate::getInstance()
{
	if (s_pFileUpdate == NULL){

		s_pFileUpdate = new PlatformVersionUpdate();

		if (s_updateData == NULL)
		{
			s_updateData = Array::create();
			s_updateData->retain();
		}
    }
    
	return (PlatformVersionUpdate *)s_pFileUpdate;
}

/************************************************************************/
/* 销毁下载模块的实例                                                    */
/************************************************************************/
void PlatformVersionUpdate::destroyInstance()
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
/* 检测版本                                                              */
/************************************************************************/
bool PlatformVersionUpdate::CheckVersion()
{
	// 平台的版本号保存在userdefault里面
	m_sCurVersion = UserDefault::getInstance()->getStringForKey(m_save_file_key.c_str());
	
	// 下载更新文件
	UpdateAndLoadVersionHistoryFile();

	if (m_vVersionList.size() > 0)
	{
		std::string newestVersion = m_vVersionList[m_vVersionList.size() - 1];
		m_updateType = getUpdateType(newestVersion, m_sCurVersion);
		// 无法完成更新，报错
		if (m_updateType == UT_ERROR)
		{
			DSUpdateData *updateData = new DSUpdateData(DSUpdateNetError, "");
			if (updateData)
			{
				s_updateData->addObject(updateData);
				CCDirector::sharedDirector()->getScheduler()->resumeTarget(this);
			}
			
			CCLOG("downListFile failed!");

			return false;
		}
		// 不需要更新
		else if (m_updateType == UT_DONT_NEED_UPDATE)
		{
			UserDefault::getInstance()->setStringForKey(m_save_file_key.c_str(), newestVersion);

			DSUpdateData *updateData = new DSUpdateData(DSUpdateNoNewVersion, "");
			if (updateData)
			{
				s_updateData->addObject(updateData);
				CCDirector::sharedDirector()->getScheduler()->resumeTarget(this);
			}
			
			CCLOG("there is no new version!");

			return false;
		}
		// 更新android的apk包
		else if (m_updateType == UT_UPDATE_APK)
		{
			std::string strFormat = StringData::shared()->stringFromKey("platform_update_apk");
			char szMessage[1024] = {0};
			sprintf(szMessage, strFormat.c_str(), m_sCurVersion.c_str(), newestVersion.c_str());

			DSUpdateData * updateData = new DSUpdateData(DSUpdateClientAPK, szMessage);
			if (updateData)
			{
				s_updateData->addObject(updateData);
				CCDirector::sharedDirector()->getScheduler()->resumeTarget(this);
			}

			return true;
		}
		// 更新ios的apk包
		else if (m_updateType == UT_UPDATE_IPA)
		{
			std::string strFormat = StringData::shared()->stringFromKey("platform_update_ipa");
			char szMessage[1024] = { 0 };
			sprintf(szMessage, strFormat.c_str(), m_sCurVersion.c_str(), newestVersion.c_str());

			DSUpdateData * updateData = new DSUpdateData(DSUpdateClientIPA, szMessage);
			if (updateData)
			{
				s_updateData->addObject(updateData);
				CCDirector::sharedDirector()->getScheduler()->resumeTarget(this);
			}
			
			return true;
		}
		// 热更新 可能因为目录不一样
		else if (m_updateType == UT_HOT_WINDOWS || m_updateType == UT_HOT_IOS_UPDATE || m_updateType == UT_HOT_ANDROID_UPDATE)
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
						DSUpdateData *updateData = new DSUpdateData(DSUpdateNetError, "");
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
			if (s_lTotalFileLenth < nConfirmSize)
			{
				std::ostringstream stream;
				stream << s_lTotalFileLenth;

				DSUpdateData * updateData = new DSUpdateData(DSUpdateNeedSmall, stream.str());
				if (updateData)
				{
					updateData->SetCurrentVersion(m_sCurVersion);
					updateData->SetNewestVersion(newestVersion);
					s_updateData->addObject(updateData);
					CCDirector::sharedDirector()->getScheduler()->resumeTarget(this);
				}
			}
			else
			{
	
				float fSizeMb = s_lTotalFileLenth / (1024.0 * 1024.0);
				if (bMustUpdate)
				{
					std::string strFormat = StringData::shared()->stringFromKey("platform_update_confirm_must");
					char szMessage[1024] = { 0 };
					sprintf(szMessage, strFormat.c_str(), m_sCurVersion.c_str(), newestVersion.c_str(), fSizeMb);

					DSUpdateData * updateData = new DSUpdateData(DSUpdateNeedMust, szMessage);
					if (updateData)
					{
						updateData->SetCurrentVersion(m_sCurVersion);
						updateData->SetNewestVersion(newestVersion);
						s_updateData->addObject(updateData);
						CCDirector::sharedDirector()->getScheduler()->resumeTarget(this);
					}
				}
				else
				{
					std::string strFormat = StringData::shared()->stringFromKey("platform_update_confirm");
					char szMessage[1024] = { 0 };
					sprintf(szMessage, strFormat.c_str(), m_sCurVersion.c_str(), newestVersion.c_str(), fSizeMb);

					DSUpdateData * updateData = new DSUpdateData(DSUpdateNeed, szMessage);
					if (updateData)
					{
						updateData->SetCurrentVersion(m_sCurVersion);
						updateData->SetNewestVersion(newestVersion);
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
		DSUpdateData *updateData = new DSUpdateData(DSUpdateNetError, "");
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
/* 更新版本                                                              */
/************************************************************************/
void PlatformVersionUpdate::UpdateVersion()
{
	if (m_updateType == UT_HOT_WINDOWS || m_updateType == UT_HOT_IOS_UPDATE || m_updateType == UT_HOT_ANDROID_UPDATE)
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
					DSUpdateData *updateData = new DSUpdateData(DSUpdateNetError, "");
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
	else if (m_updateType == UT_UPDATE_APK)
	{

	}
	else if (m_updateType == UT_UPDATE_IPA)
	{

	}
}


/************************************************************************/
/* 设置搜索路径                                                          */
/************************************************************************/
void PlatformVersionUpdate::SetSearchFilePath()
{
	vector<string> searchPaths = CCFileUtils::sharedFileUtils()->getSearchPaths();
	vector<string>::iterator itr = searchPaths.begin();

	std::string resPath = m_sPathToSave + "res/";
	std::string srcPath = m_sPathToSave + "src/";

	while (itr != searchPaths.end())
	{
		CCLOG("%s", (*itr).c_str());
		if (*itr == resPath || *itr == resPath)
		{
			itr = searchPaths.erase(itr);
		}
		else
		{
			++itr;
		}
	}

	searchPaths.insert(searchPaths.begin(), resPath);
	searchPaths.insert(searchPaths.begin(), srcPath);
	CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);
}

/************************************************************************/
/* 是否需要                                                                     */
/************************************************************************/
DSUpdateType PlatformVersionUpdate::getUpdateType(std::string strNewVerson, std::string strCurrentVersion)
{
	DSUpdateType ret = UT_ERROR;
	// 如果新版本非法，则报错，更新了也没有用
	int nNewVersion = DSFileUpdate::CheStringToInt(strNewVerson.c_str());
	if (nNewVersion == 0)
	{
		return ret;
	}

	int nCurrentVersion = DSFileUpdate::CheStringToInt(strCurrentVersion.c_str());
	// 如果是pc平台
	if (DF::shared()->GetDeviceType() == DEVICE_TYPE_PC_MOBILE)
	{
		//如果当前版本为非法，pc端就直接报错
		if (nCurrentVersion == 0)
		{
			ret = UT_HOT_WINDOWS;
			return ret;
		}
		else if (nCurrentVersion > nNewVersion)
		{
			ret =  UT_ERROR;
		}
		// 如果当前版本等于最新的版本，就不需要更新了
		else if (nCurrentVersion == nNewVersion)
		{
			ret = UT_DONT_NEED_UPDATE;
		}
		else
		{
			if (GetMainVer(nCurrentVersion) != GetMainVer(nNewVersion))
			{
				DeleteOldResourceDirAndCreateDir();
				ret = UT_DONT_NEED_UPDATE;
			}
			else
			{
				ret = UT_HOT_WINDOWS;
			}
		}
	}
	else if (DF::shared()->GetDeviceType() == DEVICE_TYPE_ANDROID)
	{
		// 
		if (nCurrentVersion == 0)
		{
			ret = UT_HOT_ANDROID_UPDATE;
			return ret;
		}
		else if (nCurrentVersion > nNewVersion)
		{
			ret = UT_UPDATE_APK;
		}
		// 版本号一致，则不需要更新
		else if (nCurrentVersion == nNewVersion)
		{
			ret = UT_DONT_NEED_UPDATE;
		}
		else
		{
			if (GetMainVer(nNewVersion) > GetMainVer(nCurrentVersion) || GetProductVer(nNewVersion) > GetProductVer(nCurrentVersion))
			{
				ret = UT_UPDATE_APK;
			}
			else
			{
				ret = UT_HOT_ANDROID_UPDATE;
			}
		}
	}
	else
	{
		// 版本号错误,则重新更新apk
		if (nCurrentVersion == 0)
		{
			ret = UT_HOT_IOS_UPDATE;
			return ret;
		}
		else if (nCurrentVersion > nNewVersion)
		{
			ret = UT_UPDATE_IPA;
		}
		// 版本号一致，则不需要更新
		else if (nCurrentVersion == nNewVersion)
		{
			ret = UT_DONT_NEED_UPDATE;
		}
		else
		{
			if (GetMainVer(nNewVersion) > GetMainVer(nCurrentVersion) || GetProductVer(nNewVersion) > GetProductVer(nCurrentVersion))
			{
				ret = UT_UPDATE_IPA;
			}
			else
			{
				ret = UT_HOT_IOS_UPDATE;
			}
		}
	}

	bool isBreak = false;
	for (unsigned int i = 0; i < m_vVersionList.size(); i++)
	{
		if (m_vVersionList[i] == m_sCurVersion)
		{
			isBreak = true;
			break;
		}
	}
	// 如果自己的版本找不到，那说明是有问题的。重新更新有设么用，pc端报错，手机端下载
	if (!isBreak)
	{
		if (ret == UT_HOT_WINDOWS)				ret = UT_ERROR;
		else if (ret == UT_HOT_IOS_UPDATE)		ret = UT_UPDATE_IPA;
		else if (ret == UT_HOT_ANDROID_UPDATE)	ret = UT_UPDATE_APK;
	}

	return ret;
}


