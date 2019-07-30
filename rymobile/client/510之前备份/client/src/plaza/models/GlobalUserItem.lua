local logincmd = appdf.req(appdf.HEADER_SRC .. "CMD_LogonServer")
GlobalUserItem = GlobalUserItem or {}

--原始游戏列表
GlobalUserItem.m_tabOriginGameList = {}
GlobalUserItem.bEnableRoomCard 							= false 	-- 激活房卡功能
--重置数据
function GlobalUserItem.reSetData()
	GlobalUserItem.bVisitor 									= nil		
	GlobalUserItem.bWeChat									= false
	GlobalUserItem.dwGameID									= 0
	GlobalUserItem.dwUserID									= 0			
	GlobalUserItem.bDayAble								    = true
	GlobalUserItem.dwExperience								= 0			
	GlobalUserItem.dwLoveLiness								= 0		

	GlobalUserItem.szAccount								= ""
	GlobalUserItem.szPassword								= ""	
	GlobalUserItem.szMachine								= ""
	GlobalUserItem.szMobilePhone							= ""
	GlobalUserItem.szRoomPasswd								= ""
					
	GlobalUserItem.szNickName								= ""						
	GlobalUserItem.szInsurePass								= ""						
	GlobalUserItem.szDynamicPass							= ""
	-- 个人信息附加包
	GlobalUserItem.szSign									= ""        -- "此人很懒，没有签名"	
	GlobalUserItem.szSpreaderAccount 						= "" 		-- 推广员
	GlobalUserItem.szQQNumber 								= "" 		-- qq号码
	GlobalUserItem.szEmailAddress 							= "" 		-- 邮箱地址
	GlobalUserItem.szSeatPhone 								= "" 		-- 座机
	GlobalUserItem.szTrueName 								= "" 		-- 真实姓名
	GlobalUserItem.szAddress 								= "" 		-- 联系地址
	GlobalUserItem.szPassportID 							= "" 		-- 身份ID
	-- 个人信息附加包

	GlobalUserItem.lUserScore								= 0						--用户金币
	GlobalUserItem.lUserIngot								= 0						--用户元宝
	GlobalUserItem.lUserInsure								= 0						--银行存款
	GlobalUserItem.dUserBeans								= 0.00 					--游戏豆
	GlobalUserItem.cbInsureEnabled							= 0	
	GlobalUserItem.nLargeTrumpetCount						= 0						--大喇叭数量	

	GlobalUserItem.cbGender									= 0							
	GlobalUserItem.cbMemberOrder							= 0
	GlobalUserItem.MemberOverDate							= 0		
	GlobalUserItem.MemberList								= {}			

	GlobalUserItem.wFaceID									= 0							
	GlobalUserItem.dwCustomID								= 0	

	GlobalUserItem.dwStationID								= 0	

	GlobalUserItem.nCurGameKind								= 122
	GlobalUserItem.szCurGameName							= ""
	GlobalUserItem.roomlist 								= {}
	GlobalUserItem.tasklist 								= {}
	GlobalUserItem.wTaskCount 								= 0

	GlobalUserItem.nCurRoomIndex 							= -1

	GlobalUserItem.nGameResType								= 0

	GlobalUserItem.bVoiceAble								= true
	GlobalUserItem.bSoundAble								= true

	GlobalUserItem.nSound									= 100
	GlobalUserItem.nMusic									= 100
	GlobalUserItem.bShake									= true

	GlobalUserItem.szHelp									= nil

	GlobalUserItem.bAutoLogon								= false
	GlobalUserItem.bSavePassword							= true		--默认记住密码
	GlobalUserItem.bHasLogon								= false  	--已经登录过
	GlobalUserItem.bVisitor									= false

	GlobalUserItem.LogonTime								= 0

	GlobalUserItem.wCurrLevelID 							= 0
	GlobalUserItem.dwExperience 							= 0
	GlobalUserItem.dwUpgradeExperience 						= 0
	GlobalUserItem.lUpgradeRewardGold 						= 0
	GlobalUserItem.lUpgradeRewardIngot						= 0

	GlobalUserItem.wSeriesDate								= 0 		--连续日期
	GlobalUserItem.bTodayChecked							= true 	    --今日签到
	GlobalUserItem.lCheckinRewards 						    = {0,0,0,0,0,0,0}		--签到奖励
	GlobalUserItem.nContinuouDay							= 0 		--已领天数

	GlobalUserItem.buyItem									= nil
	GlobalUserItem.useItem 									= nil

    GlobalUserItem.dwLotteryQuotas                          = {0,0,0,0,0,0,0,0,0,0} --抽奖奖励
    GlobalUserItem.cbLotteryTypes                           = {0,0,0,0,0,0,0,0,0,0} --奖励类型
    GlobalUserItem.bLotteryConfiged                         = false     --抽奖是否已配置

    GlobalUserItem.bNewActivity								= false		--是否有新活动
    --GlobalUserItem.dwActivityList							= {}		--活动列表
              
	GlobalUserItem.szThirdPartyUrl							= ""		--第三方头像url
	GlobalUserItem.bThirdPartyLogin							= false
	GlobalUserItem.thirdPartyData 							= {}		--第三方登陆数据	
	GlobalUserItem.tabEnterGame							    = nil 		--保存进入游戏的数据
	GlobalUserItem.dwServerRule								= 0			--房间规则
	GlobalUserItem.bEnterGame								= false 	--进入游戏
	GlobalUserItem.bIsAngentAccount							= false 	--是否是代理商帐号	

	GlobalUserItem.bQueryCheckInData						= false

	GlobalUserItem.nTableFreeCount							= 0			--转盘免费次数
	GlobalUserItem.nShareSend								= 0			--每日分享赠送

	GlobalUserItem.bJftPay									= false
	GlobalUserItem.szSpreaderURL							= nil 		--普通分享链接
	GlobalUserItem.szWXSpreaderURL 							= nil 		--微信分享链接

    GlobalUserItem.bFirstPay                                = false     --是否首充
	GlobalUserItem.tabShopCache								= {} 		--商店信息缓存
	GlobalUserItem.tabExchangeCache							= {}		--兑换信息缓存

	GlobalUserItem.tabRankCache								= {} 		--排行信息缓存
	GlobalUserItem.bFilterTask								= false 	--是否过滤任务 (只显示单个游戏任务)

	GlobalUserItem.bPrivateRoom 							= false 	-- 私人房
    GlobalUserItem.tabRoomParamCache                        = {}        -- 私人房参数缓存
    GlobalUserItem.tabRoomFeeParamCache                     = {}        -- 私人房费用参数缓存
    GlobalUserItem.tabPriRoomData                           = {}        -- 私人房数据

	GlobalUserItem.lRoomCard 								= 0			-- 房卡数量
	GlobalUserItem.dwLockServerID 							= 0			-- 锁定房间
	GlobalUserItem.dwLockKindID 							= 0 		-- 锁定游戏
	GlobalUserItem.bWaitQuit 								= false 	-- 等待退出
	GlobalUserItem.bAutoConnect 							= true 		-- 是否自动断线重连(游戏切换到主页再切换回)

	GlobalUserItem.cbLockMachine 							= 0 		-- 是否锁定设备
	GlobalUserItem.szIpAdress 								= "" 		-- ip地址
	GlobalUserItem.tabCoordinate 							= {lo = 360.0, la = 360.0} 		-- 坐标
	GlobalUserItem.bUpdateCoordinate 						= false 	-- 是否更新坐标
	GlobalUserItem.tabDayTaskCache 							= {} 		-- 每日必做列表
	GlobalUserItem.nInviteSend 								= 0			-- 邀请奖励
	GlobalUserItem.bEnableCheckIn 							= false 	-- 激活签到
	GlobalUserItem.bEnableTask 								= false 	-- 激活任务
	GlobalUserItem.bEnableEveryDay							= false 	-- 激活每日任务开关

	GlobalUserItem.szCopyRoomId 							= "" 		-- 复制房间id 	

	GlobalUserItem.bMatch									= false   	-- 比赛
	GlobalUserItem.tabIntroduceCache 						= {} 		-- 玩法介绍

	GlobalUserItem.bIsChangeTableUser						= false		-- 是否换桌用户
end

--读取配置
function GlobalUserItem.LoadData()
	--声音设置
	GlobalUserItem.bVoiceAble = cc.UserDefault:getInstance():getBoolForKey("vocieable",true)
	GlobalUserItem.bSoundAble = cc.UserDefault:getInstance():getBoolForKey("soundable", true)
	--音量设置
	GlobalUserItem.nSound = cc.UserDefault:getInstance():getIntegerForKey("soundvalue",100)
	GlobalUserItem.nMusic = cc.UserDefault:getInstance():getIntegerForKey("musicvalue",100)
	--震动设置
	GlobalUserItem.bShake = cc.UserDefault:getInstance():getBoolForKey("shakeable",true)
	--自动登录
	GlobalUserItem.bAutoLogon = cc.UserDefault:getInstance():getBoolForKey("autologon",false)

    --第三方登录数据
    GlobalUserItem.thirdPartyData.accounts = cc.UserDefault:getInstance():getStringForKey("thirdparty_accounts")
    GlobalUserItem.thirdPartyData.nickname = cc.UserDefault:getInstance():getStringForKey("thirdparty_nickname")
    GlobalUserItem.thirdPartyData.headurl = cc.UserDefault:getInstance():getStringForKey("thirdparty_headurl")
    GlobalUserItem.thirdPartyData.gender = cc.UserDefault:getInstance():getIntegerForKey("thirdparty_gender")
	GlobalUserItem.thirdPartyData.platform = cc.UserDefault:getInstance():getIntegerForKey("thirdparty_platform")
	GlobalUserItem.thirdPartyData.pwd = cc.UserDefault:getInstance():getStringForKey("thirdparty_pwd")
--    cc.UserDefault:getInstance():deleteValueForKey("thirdparty_accounts")
--    cc.UserDefault:getInstance():deleteValueForKey("thirdparty_nickname")
--    cc.UserDefault:getInstance():deleteValueForKey("thirdparty_headurl")
--    cc.UserDefault:getInstance():deleteValueForKey("thirdparty_gender")
--    cc.UserDefault:getInstance():deleteValueForKey("thirdparty_platform")

	if GlobalUserItem.bVoiceAble then
		AudioEngine.setMusicVolume(GlobalUserItem.nMusic/100.0)		
	else
		AudioEngine.setMusicVolume(0)
	end
	
	if GlobalUserItem.bSoundAble then
		AudioEngine.setEffectsVolume(GlobalUserItem.nSound/100.00) 
	else
		AudioEngine.setEffectsVolume(0) 
	end	

	--账号密码
	local sp = ""

	local tmpInfo = readByDecrypt(sp.."user_gameconfig.plist","code_1")
	
	--检验
	if tmpInfo ~= nil and #tmpInfo >32 then
		local md5Test = string.sub(tmpInfo,1,32)
		tmpInfo = string.sub(tmpInfo,33,#tmpInfo)
		if md5Test ~= md5(tmpInfo) then
			print("test:"..md5Test.."#"..tmpInfo)
			tmpInfo = nil
		end
	else
		tmpInfo = nil
	end

	if tmpInfo ~= nil then
		GlobalUserItem.szAccount = tmpInfo
		tmpInfo = readByDecrypt(sp.."user_gameconfig.plist","code_2")
		--检验
		if tmpInfo ~= nil and #tmpInfo >32 then
			local md5Test = string.sub(tmpInfo,1,32)
			tmpInfo = string.sub(tmpInfo,33,#tmpInfo)
			if md5Test ~= md5(tmpInfo) then
				print("test:"..md5Test.."#"..tmpInfo)
				tmpInfo = nil
			end
		else
			tmpInfo = nil
		end
		if tmpInfo ~= nil then
			GlobalUserItem.szPassword = tmpInfo
			GlobalUserItem.bSavePassword = true
		else
			GlobalUserItem.szPassword = ""
			GlobalUserItem.bSavePassword = true
		end
	else
		GlobalUserItem.szAccount = ""
		GlobalUserItem.szPassword = ""
		GlobalUserItem.bAutoLogon = false
		GlobalUserItem.bSavePassword = true
	end

	GlobalUserItem.wCurrLevelID 							= 0
	GlobalUserItem.dwExperience 							= 0
	GlobalUserItem.dwUpgradeExperience 						= 0
	GlobalUserItem.lUpgradeRewardGold 						= 0
	GlobalUserItem.lUpgradeRewardIngot						= 0
end

GlobalUserItem.reSetData()

--保存配置参数
function GlobalUserItem.onSaveAccountConfig()

	local szSaveInfo = ""

	if  GlobalUserItem.szAccount ~= nil and #GlobalUserItem.szAccount >0  then
	 	szSaveInfo = md5(GlobalUserItem.szAccount)..GlobalUserItem.szAccount
	end

	local sp = ""

	saveByEncrypt(sp.."user_gameconfig.plist","code_1",szSaveInfo)

	szSaveInfo = ""

	if GlobalUserItem.bSavePassword == true and GlobalUserItem.szPassword ~= nil and #GlobalUserItem.szPassword >0 then
		szSaveInfo = md5(GlobalUserItem.szPassword)..GlobalUserItem.szPassword
	end

	saveByEncrypt(sp.."user_gameconfig.plist","code_2",szSaveInfo)

	cc.UserDefault:getInstance():setBoolForKey("autologon",GlobalUserItem.bAutoLogon)
end

function GlobalUserItem.setShakeAble(able)
	GlobalUserItem.bShake = able
	cc.UserDefault:getInstance():setBoolForKey("shakeable",GlobalUserItem.bShake)
end

function GlobalUserItem.setSoundAble(able)
	GlobalUserItem.bSoundAble = able
	if true == able then
		AudioEngine.setEffectsVolume(GlobalUserItem.nSound/100.00)
	else
		AudioEngine.setEffectsVolume(0)
	end
	cc.UserDefault:getInstance():setBoolForKey("soundable",GlobalUserItem.bSoundAble)
end

function GlobalUserItem.setVoiceAble(able)
	GlobalUserItem.bVoiceAble = able
	if  GlobalUserItem.bVoiceAble == true then
		AudioEngine.setMusicVolume(GlobalUserItem.nMusic/100.0)
	else		
		AudioEngine.setMusicVolume(0)
		AudioEngine.stopMusic() -- 暂停音乐  
	end
	cc.UserDefault:getInstance():setBoolForKey("vocieable",GlobalUserItem.bVoiceAble)
end

function GlobalUserItem.setMusicVolume(music) 
	local tmp = music 
	if tmp >100 then
		tmp = 100
	elseif tmp < 0 then
		tmp = 0
	end
	AudioEngine.setMusicVolume(tmp/100.0) 
	GlobalUserItem.nMusic = tmp
	cc.UserDefault:getInstance():setIntegerForKey("musicvalue",GlobalUserItem.nMusic)
end

function GlobalUserItem.setEffectsVolume(sound) 
	local tmp = sound 
	if tmp >100 then
		tmp = 100
	elseif tmp < 0 then
		tmp = 0
	end
	AudioEngine.setEffectsVolume(tmp/100.00) 
	GlobalUserItem.nSound = tmp
	cc.UserDefault:getInstance():setIntegerForKey("soundvalue",GlobalUserItem.nSound)
end

--获取游戏房间数目
function GlobalUserItem.getRoomCount(wKindID)

    local roomList = GlobalUserItem.roomlist[wKindID]
    local roomCount = roomList and #roomList or 0

    return roomCount
end

--获取游戏普通房数目
function GlobalUserItem.getNormalRoomCount(wKindID)

    local roomList = GlobalUserItem.roomlist[wKindID] or {}
    local roomCount = 0

    for i = 1, #roomList do
        
        if roomList[i].wServerType ~= yl.GAME_GENRE_PERSONAL then
            roomCount = roomCount + 1
        end
    end

    return roomCount
end

--获取游戏私人房数目
function GlobalUserItem.getPrivateRoomCount(wKindID)

    local roomList = GlobalUserItem.roomlist[wKindID] or {}
    local roomCount = 0

    for i = 1, #roomList do
        
        if roomList[i].wServerType == yl.GAME_GENRE_PERSONAL then
            roomCount = roomCount + 1
        end
    end

    return roomCount
end

--获取房间信息
function GlobalUserItem.getRoomInfo(wServerID)
    
    print("......................")
    for k, v in pairs(GlobalUserItem.roomlist) do
        for i = 1, #v do
            if v[i].wServerID == wServerID then
                return v[i]
            end
        end
    end

    return nil
end

--获取游戏房间信息
function GlobalUserItem.getGameRoomInfo(wKindID, wServerID)

    local roomList = GlobalUserItem.roomlist[wKindID] or {}
    local roomCount = 0

    for i = 1, #roomList do
        
        if roomList[i].wServerID == wServerID then
            return roomList[i]
        end
    end

    return nil
end

--获取真实在线人数
function GlobalUserItem.getRealOnlineCount()

    local count = 0

    for k, v in pairs(GlobalUserItem.roomlist) do
        for i = 1, #v do
            local roomInfo = v[i]
            count = count + roomInfo.dwOnLineCount
        end
    end

    return count

end

--获取在线人数总数
function GlobalUserItem.getTotalOnlineCount()
    
    local count = 0

    for k, v in pairs(GlobalUserItem.roomlist) do
        for i = 1, #v do
            local roomInfo = v[i]
            count = count + roomInfo.dwOnLineCount
            count = count + roomInfo.dwAndroidCount
        end
    end

    return count
end

--加载用户信息
function GlobalUserItem.onLoadData(pData)
	if pData == nil then
		print("GlobalUserItem-LoadData-null")
		return
	end
	--登录时间
	GlobalUserItem.LogonTime = currentTime()

	GlobalUserItem.wFaceID = pData:readword()
	GlobalUserItem.cbGender = pData:readbyte()
	GlobalUserItem.dwCustomID = pData:readdword()
	GlobalUserItem.dwUserID = pData:readdword()
	GlobalUserItem.dwGameID = pData:readdword()
	GlobalUserItem.dwExperience = pData:readdword()
	GlobalUserItem.dwLoveLiness = GlobalUserItem:readScore(pData)--pData:readdword()
	GlobalUserItem.szAccount = pData:readstring(32)
	GlobalUserItem.szNickName = pData:readstring(32)
	GlobalUserItem.szDynamicPass= pData:readstring(33)
	GlobalUserItem.szMobilePhone = pData:readstring(12)
	GlobalUserItem.bFirstPay = pData:readbool()
	GlobalUserItem.lUserScore = GlobalUserItem:readScore(pData)
	GlobalUserItem.lUserIngot = GlobalUserItem:readScore(pData)
	GlobalUserItem.lUserInsure= GlobalUserItem:readScore(pData)
	GlobalUserItem.dUserBeans = pData:readdouble()
	GlobalUserItem.cbInsureEnabled = pData:readbyte()
	local bAngent = pData:readbyte() or 0
	GlobalUserItem.bIsAngentAccount = (bAngent == 1)
	GlobalUserItem.cbLockMachine = pData:readbyte()
	GlobalUserItem.lRoomCard = GlobalUserItem:readScore(pData)
	GlobalUserItem.dwLockServerID = pData:readdword()
	GlobalUserItem.dwLockKindID = pData:readdword()
	print("lock server " .. GlobalUserItem.dwLockServerID)
	print("lock kind " .. GlobalUserItem.dwLockKindID)

	local curlen = pData:getcurlen()
	local datalen = pData:getlen()

	print("*** curlen-"..curlen)
	print("*** datalen-"..datalen)

	local tmpSize 
	local tmpCmd
	while curlen<datalen do
		 tmpSize = pData:readword()
		 tmpCmd = pData:readword()
		if not tmpSize or not tmpCmd then
		 	break
		end

		print("*** tmpSize-"..tmpSize)
		print("*** tmpCmd-"..tmpCmd)
		if tmpCmd == yl.DTP_GP_UI_UNDER_WRITE then
			GlobalUserItem.szSign = pData:readstring(tmpSize/2)
			--if not GlobalUserItem.szSign then
			--	GlobalUserItem.szSign = "此人很懒，没有签名"
			--end
		elseif tmpCmd == yl.DTP_GP_MEMBER_INFO then
			GlobalUserItem.cbMemberOrder = pData:readbyte();
			for i=1,8 do
				print("systemtime-"..pData:readword())
			end
		elseif tmpCmd == logincmd.DTP_GP_UI_QQ then
			GlobalUserItem.szQQNumber = pData:readstring(tmpSize/2) or ""
			print("qq " .. GlobalUserItem.szQQNumber)
		elseif tmpCmd == logincmd.DTP_GP_UI_EMAIL then
			GlobalUserItem.szEmailAddress = pData:readstring(tmpSize/2) or ""
			print("email " .. GlobalUserItem.szEmailAddress)
		elseif tmpCmd == logincmd.DTP_GP_UI_SEAT_PHONE then
			GlobalUserItem.szSeatPhone = pData:readstring(tmpSize/2) or ""
			print("szSeatPhone " .. GlobalUserItem.szSeatPhone)
		elseif tmpCmd == logincmd.DTP_GP_UI_MOBILE_PHONE then
			GlobalUserItem.szMobilePhone = pData:readstring(tmpSize/2) or ""
			print("szMobilePhone " .. GlobalUserItem.szMobilePhone)
		elseif tmpCmd == logincmd.DTP_GP_UI_COMPELLATION then
			GlobalUserItem.szTrueName = pData:readstring(tmpSize/2) or ""
			print("szTrueName " .. GlobalUserItem.szTrueName)
		elseif tmpCmd == logincmd.DTP_GP_UI_DWELLING_PLACE then
			GlobalUserItem.szAddress = pData:readstring(tmpSize/2) or ""
			print("szAddress " .. GlobalUserItem.szAddress)
		elseif tmpCmd == logincmd.DTP_GP_UI_PASSPORTID then
			GlobalUserItem.szPassportID = pData:readstring(tmpSize/2) or ""
			print("szPassportID " .. GlobalUserItem.szPassportID)
		elseif tmpCmd == logincmd.DTP_GP_UI_SPREADER then
			GlobalUserItem.szSpreaderAccount = pData:readstring(tmpSize/2) or ""
			print("szSpreaderAccount " .. GlobalUserItem.szSpreaderAccount)
		elseif tmpCmd == 0 then
			break
		else
			for i = 1, tmpSize do
				if not pData:readbyte() then
					break
				end
			end
		end
		curlen = pData:getcurlen()
	end
    --c++ call
    local pGlobalUserInfo = ds.CGlobalUserInfo:GetInstance()
    pGlobalUserInfo:setFaceID(GlobalUserItem.wFaceID)
	pGlobalUserInfo:setGender(GlobalUserItem.cbGender)
	pGlobalUserInfo:setCustomID(GlobalUserItem.dwCustomID)
	pGlobalUserInfo:setUserID(GlobalUserItem.dwUserID)
	pGlobalUserInfo:setGameID(GlobalUserItem.dwGameID)
	pGlobalUserInfo:setExperience(GlobalUserItem.dwExperience)
	pGlobalUserInfo:setLoveLiness(GlobalUserItem.dwLoveLiness)
	pGlobalUserInfo:setAccounts(GlobalUserItem.szAccount,32)
	pGlobalUserInfo:setDynamicPass(GlobalUserItem.szDynamicPass,33)
    pGlobalUserInfo:setNickName(GlobalUserItem.szNickName,32)
	pGlobalUserInfo:setUserScore(GlobalUserItem.lUserScore)
	pGlobalUserInfo:setUserIngot(GlobalUserItem.lUserIngot)
	pGlobalUserInfo:setUserInsure(GlobalUserItem.lUserInsure)
	pGlobalUserInfo:setUserBeans(GlobalUserItem.dUserBeans)

	GlobalUserItem:testlog()
end

function GlobalUserItem:testlog() 
	print("**************************************************")
	--dump(self, "GlobalUserItem", 6)
	print("**************************************************")
end

function GlobalUserItem:readScore(dataBuffer)
    if self._int64 == nil then
       self._int64 = Integer64.new():retain()
    end
    dataBuffer:readscore(self._int64)
    return self._int64:getvalue()
end

function GlobalUserItem:getSignature(times)
    local timevalue = times
    print("timevalue-"..timevalue)
    local timestr = ""..timevalue
    local pstr = ""..GlobalUserItem.dwUserID
    --pstr = pstr..GlobalUserItem.szDynamicPass..timestr.."game316_SyncLoginKey"
    pstr = pstr..GlobalUserItem.szDynamicPass..timestr.."RYSyncLoginKey"
    pstr = md5(pstr)
    print("signature-"..pstr)
    return pstr
end

function GlobalUserItem:getSignatureN(times)
    local timevalue = times
    print("timevalue-"..timevalue)
    local timestr = ""..timevalue
    local pstr = ""..GlobalUserItem.dwUserID
    pstr = pstr..GlobalUserItem.szDynamicPass..timestr.."^_^()_#)@_#)_RQUIWWWW*)"
	pstr = md5(pstr)
	pstr = string.lower(pstr)
	pstr = md5(pstr)
	pstr = string.lower(pstr)

    print("signature- "..pstr)
    return pstr
end

function GlobalUserItem:getDateNumber(datestr)
	local index,b = string.find(datestr, "%(")
	local strname = ""
	local dwnum = ""
	if index then
		dwnum = string.sub(datestr, index+1,-1)
		strname = string.sub(datestr,1,index-1)
	end

	index = string.find(dwnum, "%)")
	if index then
		dwnum = string.sub(dwnum,1,index-1)
	end
	return dwnum
end

--是否是防作弊
function GlobalUserItem.isAntiCheat()
	return (bit:_and(GlobalUserItem.dwServerRule, yl.SR_ALLOW_AVERT_CHEAT_MODE) ~= 0)
end

--防作弊是否有效(是否进入了游戏)
function GlobalUserItem.isAntiCheatValid(userid)
	if false == GlobalUserItem.bEnterGame then
		return false
	end

	--自己排除
	if userid == GlobalUserItem.dwUserID then
		return false
	end
	return GlobalUserItem.isAntiCheat()
end

function GlobalUserItem.todayCheck(date)
	if nil == date then
		return false
	end
	local curDate = os.date("*t")
	local checkDate = os.date("*t", date)
	if curDate.year == checkDate.year and curDate.month == checkDate.month and curDate.day == checkDate.day then
		return true
	end
	return false
end

function GlobalUserItem.setTodayFirstAction(key, value)
	cc.UserDefault:getInstance():setStringForKey(key, value .. "")
	cc.UserDefault:getInstance():flush()
end

--当日首次签到
function GlobalUserItem.isFirstCheckIn()
	local everyDayCheck = cc.UserDefault:getInstance():getStringForKey(GlobalUserItem.dwUserID .. "everyDayCheck", "nil")
	--print(everyDayCheck)
	if "nil" ~= everyDayCheck then
		local n = tonumber(everyDayCheck)
		return not GlobalUserItem.todayCheck(n)
	end
	return true
end

function GlobalUserItem.setTodayCheckIn()
	if GlobalUserItem.isFirstCheckIn() then
		GlobalUserItem.setTodayFirstAction(GlobalUserItem.dwUserID .. "everyDayCheck", os.time())
	end	
end

--当日首次充值
function GlobalUserItem.isFirstPay()
	local everyDayPay = cc.UserDefault:getInstance():getStringForKey(GlobalUserItem.dwUserID .. "everyDayPay", "nil")
	if "nil" ~= everyDayPay then
		local n = tonumber(everyDayPay)
		return not GlobalUserItem.todayCheck(n)
	end
	return true
end

function GlobalUserItem.setTodayPay()
	if GlobalUserItem.isFirstPay() then
		GlobalUserItem.setTodayFirstAction(GlobalUserItem.dwUserID .. "everyDayPay", os.time())
	end	
end

--当日首次分享
function GlobalUserItem.isFirstShare()
	local everyDayShare = cc.UserDefault:getInstance():getStringForKey(GlobalUserItem.dwUserID .. "everyDayShare", "nil")
	if "nil" ~= everyDayShare then
		local n = tonumber(everyDayShare)
		return not GlobalUserItem.todayCheck(n)
	end
	return true
end

function GlobalUserItem.setTodayShare()
	if GlobalUserItem.isFirstShare() then
		GlobalUserItem.setTodayFirstAction(GlobalUserItem.dwUserID .. "everyDayShare", os.time())
	end	
end

--当日首次转盘
function GlobalUserItem.isFirstTable()
	local everyDayTable = cc.UserDefault:getInstance():getStringForKey(GlobalUserItem.dwUserID .. "everyDayTable", "nil")
	if "nil" ~= everyDayTable then
		local n = tonumber(everyDayTable)
		return not GlobalUserItem.todayCheck(n)
	end
	return true
end

function GlobalUserItem.setTodayTable()
	if GlobalUserItem.isFirstTable() then
		GlobalUserItem.setTodayFirstAction(GlobalUserItem.dwUserID .. "everyDayTable", os.time())
	end	
end

-- 当日首页广告
function GlobalUserItem.isShowAdNotice()
	local everyDayAdNotice = cc.UserDefault:getInstance():getStringForKey(GlobalUserItem.dwUserID .. "everyDayNoAdNotice", "nil")
	if "nil" ~= everyDayAdNotice then
		local n = tonumber(everyDayAdNotice)
		return not GlobalUserItem.todayCheck(n)
	end
	return true
end

function GlobalUserItem.setTodayNoAdNotice( noAds )
	if noAds then
		GlobalUserItem.setTodayFirstAction(GlobalUserItem.dwUserID .. "everyDayNoAdNotice", os.time())	
	else
		GlobalUserItem.setTodayFirstAction(GlobalUserItem.dwUserID .. "everyDayNoAdNotice", "nil")
	end
end

--判断是否是代理商帐号
function GlobalUserItem.isAngentAccount(nottip)
	nottip = nottip or false
	if GlobalUserItem.bIsAngentAccount then
		local runScene = cc.Director:getInstance():getRunningScene()
		if nil ~= runScene and not nottip then
			showToast(runScene, "您是代理商帐号，无法操作！", 2)
		end
		return true
	end
	return false
end

--设置是否绑定账号
function GlobalUserItem.setBindingAccount()
	cc.UserDefault:getInstance():setBoolForKey("isBingdingAccount", true)
end

--获取是否绑定账号
function GlobalUserItem.getBindingAccount()
	return cc.UserDefault:getInstance():getBoolForKey("isBingdingAccount", false)
end

--判断是否能修改信息
function GlobalUserItem.notEditAble(nottip)
	nottip = nottip or false
	if --[[GlobalUserItem.bVisitor or]] GlobalUserItem.bWeChat then
		local runScene = cc.Director:getInstance():getRunningScene()
		if nil ~= runScene and not nottip then
			local str = ""
			if GlobalUserItem.bVisitor then
				str = "游客登录无法修改信息"
			elseif GlobalUserItem.bWeChat then
				str = "微信登录无法修改信息"
			end
			showToast(runScene, str, 2)
		end
		return true
	end
	return false
end

-- 无定位数据
function GlobalUserItem.noCoordinateData()
	if nil == GlobalUserItem.tabCoordinate 
		or nil == GlobalUserItem.tabCoordinate.la 
		or 360.0 == GlobalUserItem.tabCoordinate.la
		or nil == GlobalUserItem.tabCoordinate.lo
		or 360.0 == GlobalUserItem.tabCoordinate.lo then
		return true
	end
	return false
end

--密码加密
function GlobalUserItem.PasswordEncryption( szPassword )
	-- body
	local pass1 = szPassword
	local pass2 = szPassword

	--[[if string.len( szPassword ) < 30  then
		local pass = string.lower(md5("sjdoe0390232jkdj23033ij34" .. szPassword)) .. "43059dkleow03490dk094dkxd"
		pass2 = string.lower( md5(pass) )
		
	end
	return pass2]]
    if string.len( szPassword ) < 30  then
        pass2 = string.lower( md5(szPassword) )
    end
    return pass2
end
function GlobalUserItem.setDayAble(able)
	GlobalUserItem.bDayAble = able
	cc.UserDefault:getInstance():setBoolForKey("dayable",GlobalUserItem.bDayAble)
end
function GlobalUserItem.setAutoAble(able)
	GlobalUserItem.bAutoAble = able
	cc.UserDefault:getInstance():setBoolForKey("autoable",GlobalUserItem.bAutoAble)
end