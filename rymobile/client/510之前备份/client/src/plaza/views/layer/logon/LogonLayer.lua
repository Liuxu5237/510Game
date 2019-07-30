--登录界面

local LogonLayer = class("LogonLayer", cc.Layer)

local ExternalFun = appdf.req(appdf.EXTERNAL_SRC .. "ExternalFun")
local AnimationHelper = appdf.req(appdf.EXTERNAL_SRC .. "AnimationHelper")
local MultiPlatform = appdf.req(appdf.EXTERNAL_SRC .. "MultiPlatform")

local RegisterLayer = appdf.req(appdf.CLIENT_SRC.."plaza.views.layer.logon.RegisterLayer")
local RetrievePasswordLayer = appdf.req(appdf.CLIENT_SRC.."plaza.views.layer.logon.RetrievePasswordLayer")

local LogonCheckUser = appdf.req(appdf.CLIENT_SRC.."plaza.views.layer.logon.LogonCheckUserLayer")
local QueryDialog = appdf.req(appdf.BASE_SRC .. "app.views.layer.other.QueryDialog")

function LogonLayer:ctor(delegate)

    self._delegate = delegate

    local csbNode = ExternalFun.loadCSB("Logon/LogonLayer.csb"):addTo(self)
    self._content = csbNode:getChildByName("content")

--    local logo = self._content:getChildByName("Image_Center")
--    logo:setVisible(not yl.APPSTORE_VERSION)

    --返回
    local btnBack = self._content:getChildByName("btn_back")
    btnBack:addClickEventListener(function()

        --播放音效
        ExternalFun.playClickEffect()

        --通知关闭
        if self._delegate and self._delegate.onLogonLayerClose then
            self._delegate:onLogonLayerClose()
        end

        dismissPopupLayer(self)
    end)

    --输入框
    self._editAccount = self:onCreateEditBox(self._content:getChildByName("sp_edit_account_bg"), false, false, 18)
    self._editPassword = self:onCreateEditBox(self._content:getChildByName("sp_edit_pwd_bg"), true, false, 33)

    if GlobalUserItem.szAccount ~= nil and GlobalUserItem.szAccount ~= "" then
		self._editAccount:setText(GlobalUserItem.szAccount)
	end


    self.bLgoinPassword = true --使用默认代码
	if GlobalUserItem.szPassword ~= nil and GlobalUserItem.szPassword ~= "" then
		self._editPassword:setText(GlobalUserItem.szPassword)
	end


--     local editHanlder = function(event,editbox)
--        self:onEditEvent(event,editbox)
--    end



--   self._editPassword:registerScriptEditBoxHandler(editHanlder)


    --记住密码
    self._checkRemember = self._content:getChildByName("check_remember")
    self._checkRemember:setSelected(GlobalUserItem.bSavePassword)

    --忘记密码
    local btnForget = self._content:getChildByName("btn_forget")
    btnForget:addClickEventListener(function()

        --播放音效
        ExternalFun.playClickEffect()

        self:onClickForget()
    end)

    --注册
    local btnRegister = self._content:getChildByName("btn_register")
    btnRegister:addClickEventListener(function()

        --播放音效
        ExternalFun.playClickEffect()

        self:onClickRegister()
    end)

    --登录
    local btnLogon = self._content:getChildByName("btn_logon")
    btnLogon:addClickEventListener(function()

        --播放音效
        ExternalFun.playClickEffect()

        self:onClickLogon()
    end)
end


function LogonLayer:onEditEvent(event,editbox)
    
   if event == "changed" then
    self.bLgoinPassword = false
   end 
end

function LogonLayer:onShow()
    
    local px, py = self._content:getPosition()

    self._content:setPosition(px, py + appdf.HEIGHT / 2)

    --动画跳入
    self._content:runAction(cc.EaseBackOut:create(cc.MoveTo:create(0.4, cc.p(px, py))))
end

--创建输入框
function LogonLayer:onCreateEditBox(spEditBg, isPassword, isNumeric, maxLength)
    
    --editTxt:setPlaceHolder("请输入账号")               --设置预制提示文本  
    local inputMode = isNumeric and cc.EDITBOX_INPUT_MODE_NUMERIC or cc.EDITBOX_INPUT_MODE_SINGLELINE

    local sizeBg = spEditBg:getContentSize()
    local editBox = ccui.EditBox:create(cc.size(sizeBg.width - 100, sizeBg.height - 16), "")
		:move(sizeBg.width / 2+52, sizeBg.height / 2-3)
        :setFontSize(28)
        :setPlaceholderFontSize(24)
        :setFontColor(cc.WHITE)
		:setFontName("fonts/round_body.ttf")
		:setMaxLength(maxLength)
        :setInputMode(inputMode)
		:addTo(spEditBg) 

    --密码框
    if isPassword then
        editBox:setPlaceHolder("请输入密码")
        editBox:setInputFlag(cc.EDITBOX_INPUT_FLAG_PASSWORD) 
        --editBox:registerScriptEditBoxHandler(function(eventname,sender) self:editboxEventHandler(eventname,sender) end)
    else
        editBox:setPlaceHolder("请输入帐号")
    end

    return editBox
end

function LogonLayer:editboxEventHandler(eventType,sender)
    if eventType == "began" then
        -- 点击编辑框,输入法显示
        printf("点击编辑框,输入法显示")
        sender:setText("")
    elseif eventType == "ended" then
        -- 当编辑框失去焦点并且键盘消失的时候被调用
        printf("当编辑框失去焦点并且键盘消失的时候被调用")
    elseif eventType == "changed" then
        -- 输入内容改变时调用
        printf("输入内容改变时调用")
    elseif eventType == "return" then
        -- 用户点击编辑框的键盘以外的区域，或者键盘的Return按钮被点击时所调用
        printf("用户点击编辑框的键盘以外的区域，或者键盘的Return按钮被点击时所调用")
    end
end

--------------------------------------------------------------------------------------------------------------------
-- 事件处理

--忘记密码
function LogonLayer:onClickForget()
    showPopupLayer(RetrievePasswordLayer:create(self._delegate), false)
    --MultiPlatform:getInstance():openBrowser(yl.HTTP_URL .. "/Mobile/RetrievePassword.aspx")
end

--注册
function LogonLayer:onClickRegister()

    showPopupLayer(RegisterLayer:create(self._delegate), false)
end

--登录
function LogonLayer:onClickLogon()
    
    local szAccount = string.gsub(self._editAccount:getText(), " ", "")
    local szPassword = string.gsub(self._editPassword:getText(), " ", "")
    
    if szAccount == nil or szAccount == "" then
        showToast(nil, "请输入登录账号!", 1)
        return
    end

    if szPassword == nil or szPassword == "" then
        showToast(nil, "请输入登录密码!", 1)
        return
    end

    local len = ExternalFun.stringLen(szAccount)--#szAccount
	if len < 6 or len > 31 then
		showToast(nil, "游戏帐号必须为6~31个字符，请重新输入!", 1);
		return
	end

	len = ExternalFun.stringLen(szPassword)--#szPassword
	if len < 6 then
		showToast(nil, "密码必须大于6个字符，请重新输入！", 1);
		return
	end

    local bSave = self._checkRemember:isSelected()

    --通知登录
    if self._delegate and self._delegate.onLogonAccount then
        self._delegate:onLogonAccount(szAccount, szPassword, bSave, false)
    end
end

--验证登陆提示      
function LogonLayer:onChenckUsertips()
   
      QueryDialog:create("系统提示".."\n检测到您更换了登陆设备\n是否进行短信验证?",function(bReTry)
            if bReTry == true then
    
            local szAccount = string.gsub(self._editAccount:getText(), " ", "")
            showPopupLayer(LogonCheckUser:create(self._delegate, szAccount), false)
               
            else
                os.exit(0)
            end
        end)
        :addTo(self)
end
return LogonLayer