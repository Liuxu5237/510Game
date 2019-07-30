--排行榜列表
local RankingListLayer = class("RankingListLayer", function(size)
    return ccui.Layout:create():setContentSize(size)
end)

local ExternalFun = appdf.req(appdf.EXTERNAL_SRC .. "ExternalFun")
local HeadSprite = appdf.req(appdf.EXTERNAL_SRC .. "HeadSprite")

local ActivityIndicator = appdf.req(appdf.CLIENT_SRC .. "plaza.views.layer.general.ActivityIndicator")
local RankOpeningListLayer = appdf.req(appdf.CLIENT_SRC.."plaza.views.layer.plaza.RankOpeningListLayer")

local ListType = 
{
    GoldRank = 1,
    WinRank = 2
}

function RankingListLayer:ctor(size)
	
    --初始化变量
    self._listType = 0
    self._nickNameFontConfig = string.getConfig(appdf.DEF_FONT, 24)
    self._nickNameFontConfig.upperEnSize = 16
    --tableview 回调
    local numberOfCellsInTableView = function(view)
        return self:numberOfCellsInTableView(view)
    end
    local cellSizeForTable = function(view, idx)
        return self:cellSizeForTable(view, idx)
    end
    local tableCellAtIndex = function(view, idx)	
        return self:tableCellAtIndex(view, idx)
    end
    local tableCellTouched = function(view, cell)
        return self:tableCellTouched(view, cell)
    end

	self._tableView = cc.TableView:create(size)
	self._tableView:setDirection(cc.SCROLLVIEW_DIRECTION_VERTICAL)    
    self._tableView:setAnchorPoint(cc.p(0, 0))
	self._tableView:setPosition(cc.p(0, 0))
	self._tableView:setDelegate()
	self._tableView:addTo(self)
	self._tableView:setVerticalFillOrder(cc.TABLEVIEW_FILL_TOPDOWN)
    self._tableView:registerScriptHandler(numberOfCellsInTableView, cc.NUMBER_OF_CELLS_IN_TABLEVIEW)
	self._tableView:registerScriptHandler(cellSizeForTable, cc.TABLECELL_SIZE_FOR_INDEX)
	self._tableView:registerScriptHandler(tableCellAtIndex, cc.TABLECELL_SIZE_AT_INDEX)
    self._tableView:registerScriptHandler(tableCellTouched, cc.TABLECELL_TOUCHED)

    --活动指示器
    self._activity = ActivityIndicator:create()
    self._activity:setPosition(size.width / 2, size.height / 2)
    self._activity:addTo(self)

    self:loadRankingList(ListType.GoldRank)
end

--设置委托
function RankingListLayer:setDelegate(delegate)

    self._delegate = delegate

    return self
end

--加载排行榜列表
function RankingListLayer:loadRankingList(listType)
    
    self._listType = listType
    --self._rankList = GlobalUserItem.tabRankCache[listType]

    --if self._rankList == nil then
        self:requestRankList(listType)
    --end

    self._tableView:reloadData()
end

--------------------------------------------------------------------------------------------------------------------
-- 事件处理

--更新列表
function RankingListLayer:onUpdateRankingList(listType, list)

    if listType == self._listType then
        self._rankList = list
        self._tableView:reloadData()
    end
end

--------------------------------------------------------------------------------------------------------------------
-- TableView 数据源

--子视图数量
function RankingListLayer:numberOfCellsInTableView(view)
    
    return self._rankList and (#self._rankList - 1) or 0
end

--子视图大小
function RankingListLayer:cellSizeForTable(view, idx)

    return 290, 90
end

--获取子视图
function RankingListLayer:tableCellAtIndex(view, idx)	
    
    --修正下标
    idx = idx + 1

    local cell = view:dequeueCell()
    if nil == cell then

        cell = cc.TableViewCell:create()

        --背景按钮
        --[[local btnBg = ccui.Button:create("btn_rank_item_n.png", "btn_rank_item_s.png", "btn_rank_item_n.png", ccui.TextureResType.plistType)
            :setTag(1)
            :setAnchorPoint(0, 1)
            :setPosition(4, 90)
            :setSwallowTouches(false)
            :addTo(cell)
            :setScaleX(0.38)]]
        
        --头像
        HeadSprite:createClipHead(nil, 73, "sp_avatar_mask_73.png")
            :setTag(2)
            :setPosition(58, 45)
            :addTo(cell)

        --名次
        ccui.Text:create("", "fonts/round_body.ttf", 36)
            :setTag(3)
            :setPosition(26, 70)
            :setTextColor(cc.c3b(209, 104, 41))
            :enableOutline(cc.WHITE, 2)
            :enableShadow(cc.c3b(110, 100, 110), cc.size(2, -2))
            :setVisible(false)
            :addTo(cell)

        --奖牌
        cc.Sprite:create()
            :setTag(4)
            :setPosition(26, 84)
            :setVisible(false)
            :addTo(cell)

        --昵称
        --[[ccui.Text:create("玩家昵称", "fonts/round_body.ttf", 24)
            :setTag(5)
            :setAnchorPoint(0, 0.5)
            :setPosition(106, 65)
            :setTextColor(cc.c3b(185, 211, 255))
            :addTo(cell)

        --金币
        ccui.Text:create("0", "fonts/round_body.ttf", 30)
            :setTag(6)
            :setAnchorPoint(0, 0.5)
            :setPosition(107, 30)
            :setTextColor(cc.c3b(210, 211, 173))
            :addTo(cell)]]
    end

    --绑定下标
    cell:setTag(idx)

    local item = self._rankList[idx]
    --local btnBg = cell:getChildByTag(1)
    local headSprite = cell:getChildByTag(2)
    local txtRank = cell:getChildByTag(3)
    local spMedal = cell:getChildByTag(4)
    --[[local txtNickName = cell:getChildByTag(5)
    local txtGold = cell:getChildByTag(6)

    local scaling = 0.38
    if self._listExpansion then  
        scaling = 1
    end
    txtNickName:setVisible(self._listExpansion)
    txtGold:setVisible(self._listExpansion)
    --btnBg:setScaleX(scaling)]]

    --排名
    if idx >= 1 and idx <= 3 then
        local frame = cc.SpriteFrameCache:getInstance():getSpriteFrame(string.format("sp_rank_medal_%d.png", idx))
        spMedal:setSpriteFrame(frame)
        spMedal:setVisible(true)

        txtRank:setString("")
        txtRank:setVisible(false)
    else
        spMedal:setVisible(false)

        txtRank:setString(idx)
        txtRank:setVisible(true)
    end

    --头像
    headSprite:updateHead({ wFaceID = item.FaceID })

    --昵称
    --[[txtNickName:setString(string.EllipsisByConfig(item.NickName, 200, self._nickNameFontConfig))
    txtNickName:setString(item.NickName)

    --金币
    txtGold:setString(ExternalFun.formatScoreText(tonumber(item.RankScore)))]]

    return cell
end

--子视图点击
function RankingListLayer:tableCellTouched(view, cell)
    
    --[[local index = cell:getTag() 
    
    if self._listExpansion then
        if self._delegate and self._delegate.onClickRankUserItem then
            local item = self._rankList[index]
            self._delegate:onClickRankUserItem(item)
        end
    else
        self._listExpansion = true;
        self._tableView:reloadData()
    end]]
    self._delegate:onClickRankOpen()
end

--------------------------------------------------------------------------------------------------------------------
-- 网络请求

--请求排行榜
function RankingListLayer:requestRankList(listType)

    local actions = { "getscorerank", "getwinscorerank" }

    self._activity:start()

    appdf.onHttpJsionTable(yl.HTTP_URL .. "/WS/PhoneRank.ashx","GET","action="..actions[listType].."&pageindex=1&pagesize=30&userid="..GlobalUserItem.dwUserID,function(jstable,jsdata)

        --对象已经销毁
		if not appdf.isObject(self) then
            return
        end

        self._activity:stop()

		if type(jstable) ~= "table" then
            return
        end

        local tempList = {}
		for i = 1, #jstable do
			local item = jstable[i]

            if item.UnderWrite == nil or item.UnderWrite == "" then
                item.UnderWrite = "这个家伙很懒，什么都没留下"
            end
			table.insert(tempList, item)
		end

		GlobalUserItem.tabRankCache[listType] = tempList
		self:onUpdateRankingList(listType, tempList)
        self._rankOpenListLayer = RankOpeningListLayer:create(tempList)
                                :setDelegate(self)
                                :setAnchorPoint(0, 0)
                                :setPosition(55, 120)
                                :addTo(self._delegate._areaRankOpen_bg)
        self._delegate:setMySelfRankInfo(tempList[#tempList])
        self._delegate._bIsRankActionOver = true
	end)
end

return RankingListLayer