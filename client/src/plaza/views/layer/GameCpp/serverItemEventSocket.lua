module("serverItemEventSocket", package.seeall)

--ʹ��switch���
local switch = 
{
	[ds.GameServer.MDM_GR_LOGON]=function(subId,packet,dataSize)  return OnSocketMainLogon(subId,packet,dataSize) end,
	[ds.GameServer.MDM_GR_CONFIG]=function(subId,packet,dataSize)  return OnSocketMainConfig(subId,packet,dataSize) end,
	[ds.GameServer.MDM_GR_USER]=function(subId,packet,dataSize)  return OnSocketMainUser(subId,packet,dataSize) end,
	[ds.GameServer.MDM_GR_STATUS]=function(subId,packet,dataSize)  return OnSocketMainStatus(subId,packet,dataSize) end,
	[ds.GameServer.MDM_GR_INSURE]=function(subId,packet,dataSize)  return OnSocketMainInsure(subId,packet,dataSize) end,
	[ds.GameServer.MDM_GR_TASK]=function(subId,packet,dataSize)  return OnSocketMainTask(subId,packet,dataSize) end,
	[ds.GameServer.MDM_GR_MANAGE]=function(subId,packet,dataSize)  return OnSocketMainManager(subId,packet,dataSize) end,
	[ds.GameServer.MDM_GR_MATCH]=function(subId,packet,dataSize)  return OnSocketMainMatch(subId,packet,dataSize) end,
	[ds.GameServer.MDM_GR_PRIVATE]=function(subId,packet,dataSize)  return OnSocketMainPrivate(subId,packet,dataSize) end,
	[ds.GameServer.MDM_GF_FRAME]=function(subId,packet,dataSize)  return OnSocketMainGameFrame(subId,packet,dataSize) end,
	[ds.GameServer.MDM_CM_SYSTEM]=function(subId,packet,dataSize)  return OnSocketMainSystem(subId,packet,dataSize) end,
}


--c++����
--luaδ����Ҫ©��c++����,����Ҫ����false
function onEventTCPSocketRead(mainId,subId,packet,dataSize)
	ds.log("onEventTCPSocketRead mainid = "..mainId.." subId = "..subId.." dataSize = "..dataSize)
	local bSuccess = false
--	if ds.GameServer.MDM_GR_LOGON == mainId then
--		bSuccess = OnSocketMainLogon(subId,packet,dataSize)

--	elseif ds.GameServer.MDM_GR_CONFIG == mainId then
--		bSuccess = OnSocketMainConfig(subId,packet,dataSize)

--	elseif ds.GameServer.MDM_GR_USER == mainId then
--		bSuccess = OnSocketMainUser(subId,packet,dataSize)

--	elseif ds.GameServer.MDM_GR_STATUS == mainId then
--		bSuccess = OnSocketMainStatus(subId,packet,dataSize)

--	elseif ds.GameServer.MDM_GR_INSURE == mainId then
--		bSuccess = OnSocketMainInsure(subId,packet,dataSize)

--	elseif ds.GameServer.MDM_GR_MANAGE == mainId then
--		bSuccess = OnSocketMainManager(subId,packet,dataSize)

--	elseif ds.GameServer.MDM_GR_MATCH == mainId then
--		bSuccess = OnSocketMainMatch(subId,packet,dataSize)

--	elseif ds.GameServer.MDM_GR_PRIVATE == mainId then
--		bSuccess = OnSocketMainPrivate(subId,packet,dataSize)

--	elseif ds.GameServer.MDM_GF_FRAME == mainId or ds.GameServer.MDM_GF_GAME == mainId then
--		bSuccess = OnSocketMainGameFrame(subId,packet,dataSize)

--	elseif ds.GameServer.MDM_CM_SYSTEM == mainId then
--		bSuccess = OnSocketMainSystem(subId,packet,dataSize)
--	else
--		ds.log("onEventTCPSocketRead did not mainid = "..mainId.." subId = "..subId.." dataSize = "..dataSize)
--	end
	local f = switch[mainId]

	if nil ~= f then
		bSuccess = f(subId,packet,dataSize)
	end
	
	if nil == bSuccess then
	    bSuccess = false
		ds.log("onEventTCPSocketRead did not mainid = "..mainId.." subId = "..subId.." dataSize = "..dataSize)
	end
	return bSuccess
end


--��¼��Ϣ��luaδ����Ҫ©��c++����,����Ҫ����false��
function OnSocketMainLogon(subId,packet,dataSize)
	return false
end

--������Ϣ ��luaδ����Ҫ©��c++����,����Ҫ����false��
function OnSocketMainConfig(subId,packet,dataSize)
	return false
end

--�û���Ϣ ��luaδ����Ҫ©��c++����,����Ҫ����false��
function OnSocketMainUser(subId,packet,dataSize)
	return false
end

--״̬��Ϣ ��luaδ����Ҫ©��c++����,����Ҫ����false��
function OnSocketMainStatus(subId,packet,dataSize)
	return false
end

--������Ϣ ��luaδ����Ҫ©��c++����,����Ҫ����false��
function OnSocketMainInsure(subId,packet,dataSize)
	return false
end

--������Ϣ ��luaδ����Ҫ©��c++����,����Ҫ����false��
function OnSocketMainManager(subId,packet,dataSize)
	return false
end

--������� ��luaδ����Ҫ©��c++����,����Ҫ����false��
function OnSocketMainTask(subId,packet,dataSize)
	return false;
end

--ϵͳ���� ��luaδ����Ҫ©��c++����,����Ҫ����false��
function OnSocketMainSystem(subId,packet,dataSize)
	return false
end

--��Ϸ��Ϣ �����Ϣ ��luaδ����Ҫ©��c++����,����Ҫ����false��
function OnSocketMainGameFrame(subId,packet,dataSize)
	return false
end

--������Ϣ ��luaδ����Ҫ©��c++����,����Ҫ����false��
function OnSocketMainMatch(subId,packet,dataSize)
	return false
end

--˽�˳���Ϣ ��luaδ����Ҫ©��c++����,����Ҫ����false��
function OnSocketMainPrivate(subId,packet,dataSize)
	return false
end