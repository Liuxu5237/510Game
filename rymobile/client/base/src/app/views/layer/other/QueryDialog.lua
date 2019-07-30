--[[
	询问对话框
		2016_04_27 C.P
	功能：确定/取消 对话框 与用户交互
]]
local QueryDialog = class("QueryDialog", function(msg,callback)
		local queryDialog = display.newLayer()
    return queryDialog
end)

--默认字体大小
QueryDialog.DEF_TEXT_SIZE 	= 32

--UI标识
QueryDialog.DG_QUERY_EXIT 	=  2 
QueryDialog.BT_CANCEL		=  0   
QueryDialog.BT_CONFIRM		=  1

QueryDialog.BT_CLOSE		=  3        --关闭按钮

-- 对话框类型
QueryDialog.QUERY_SURE 			= 1
QueryDialog.QUERY_SURE_CANCEL 	= 2

-- 进入场景而且过渡动画结束时候触发。
function QueryDialog:onEnterTransitionFinish()
    return self
end

-- 退出场景而且开始过渡动画时候触发。
function QueryDialog:onExitTransitionStart()
	self:unregisterScriptTouchHandler()
    return self
end

--窗外触碰
function QueryDialog:setCanTouchOutside(canTouchOutside)
	self._canTouchOutside = canTouchOutside
	return self
end


--msg 显示信息
--callback 交互回调
--txtsize 字体大小
function QueryDialog:ctor(msg, callback, txtsize, queryType)
	queryType = queryType or QueryDialog.QUERY_SURE_CANCEL
	self._callback = callback
	self._canTouchOutside = false

	local this = self 
	self:setContentSize(appdf.WIDTH,appdf.HEIGHT)
	--self:move(0,appdf.HEIGHT)

	--回调函数
	self:registerScriptHandler(function(eventType)
		if eventType == "enterTransitionFinish" then	-- 进入场景而且过渡动画结束时候触发。
			this:onEnterTransitionFinish()
		elseif eventType == "exitTransitionStart" then	-- 退出场景而且开始过渡动画时候触发。
			this:onExitTransitionStart()
		end
	end)

	--按键监听
	local  btcallback = function(ref, type)
        if type == ccui.TouchEventType.ended then
         	this:onButtonClickedEvent(ref:getTag(),ref)
        end
    end

	--区域外取消显示
	local  onQueryExitTouch = function(eventType, x, y)
		if not self._canTouchOutside then
			return true
		end

		if self._dismiss == true then
			return true
		end

		if eventType == "began" then
			local rect = this:getChildByTag(QueryDialog.DG_QUERY_EXIT):getBoundingBox()
        	if cc.rectContainsPoint(rect,cc.p(x,y)) == false then
        		self:dismiss()
    		end
		end
    	return true
    end
	self:setTouchEnabled(true)
	self:registerScriptTouchHandler(onQueryExitTouch)

    --创建遮罩
    local mask = ccui.Layout:create()
    mask:setContentSize(cc.Director:getInstance():getVisibleSize())
    mask:setBackGroundColorType(ccui.LayoutBackGroundColorType.solid)
    mask:setBackGroundColor(cc.BLACK)
    mask:setBackGroundColorOpacity(153)
    mask:addTo(self)

    mask:setOpacity(0)
    mask:runAction(cc.EaseSineOut:create(cc.FadeIn:create(0.4)))

    --背景
	self._content = display.newSprite("query_bg.png")
		:setTag(QueryDialog.DG_QUERY_EXIT)
		:move(appdf.WIDTH/2,appdf.HEIGHT/2)
		:addTo(self)
    local contentSize = self._content:getContentSize()

	if QueryDialog.QUERY_SURE == queryType then
		ccui.Button:create("bt_query_confirm_0.png","")
			:move(contentSize.width/2 , 100 )
			:setTag(QueryDialog.BT_CONFIRM)
			:addTo(self._content)
			:addTouchEventListener(btcallback)

            ccui.Button:create("btn_close.png","")
			:move(contentSize.width/2+327 , 450 )
			:setTag(QueryDialog.BT_CONFIRM)
			:addTo(self._content)
			:addTouchEventListener(btcallback)

	else


    ccui.Button:create("btn_close.png","")
			:move(contentSize.width/2+310 , 420 )
			:setTag(QueryDialog.BT_CANCEL)
			:addTo(self._content)
			:addTouchEventListener(btcallback)

		ccui.Button:create("bt_query_confirm_0.png","")
			:move(contentSize.width/2+180 , 100 )
			:setTag(QueryDialog.BT_CONFIRM)
			:addTo(self._content)
			:addTouchEventListener(btcallback)

		ccui.Button:create("bt_query_cancel_0.png","")
			:move(contentSize.width/2-180 ,100 )
			:setTag(QueryDialog.BT_CANCEL)
			:addTo(self._content)
			:addTouchEventListener(btcallback)
	end

--	cc.Label:createWithTTF("系统消息", "fonts/round_body.ttf", 36)
--		:setTextColor(cc.c4b(255,221,65,255))
--		:setAnchorPoint(cc.p(0.5,0.5))
--		:setDimensions(600, 120)
--		:setHorizontalAlignment(cc.TEXT_ALIGNMENT_CENTER)
--		:setVerticalAlignment(cc.VERTICAL_TEXT_ALIGNMENT_CENTER)
--		:move(appdf.WIDTH/2 ,545 )
--		:addTo(self)

	cc.Label:createWithTTF(msg, "fonts/round_body.ttf", not txtsize and QueryDialog.DEF_TEXT_SIZE or txtsize)
		:setTextColor(cc.c4b(255,255,255,255))
		:setAnchorPoint(cc.p(0.5,0.5))
		:setDimensions(640, 180)
		:setHorizontalAlignment(cc.TEXT_ALIGNMENT_CENTER)
		:setVerticalAlignment(cc.VERTICAL_TEXT_ALIGNMENT_CENTER)
		:move(contentSize.width/2 ,245 )
		:addTo(self._content)
	self._dismiss  = false
	--self:runAction(cc.MoveTo:create(0.3,cc.p(0,0)))

    self._content:setScale(0)
    self._content:runAction(cc.EaseBackOut:create(cc.ScaleTo:create(0.4, 1.0)))
end

--按键点击
function QueryDialog:onButtonClickedEvent(tag,ref)
	if self._dismiss == true then
		return
	end

	--通知回调
	if self._callback then
		self._callback(tag == QueryDialog.BT_CONFIRM)
	end

    --取消显示
	self:dismiss()
end

--取消消失
function QueryDialog:dismiss()
	self._dismiss = true
--	local this = self
	self:stopAllActions()
--	self:runAction(
--		cc.Sequence:create(
--			cc.MoveTo:create(0.3,cc.p(0,appdf.HEIGHT)),
--			cc.CallFunc:create(function()
--					this:removeSelf()
--				end)
--			))	
    self:removeFromParent()
end

return QueryDialog
