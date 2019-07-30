//
//  Game_Path_Manager.cpp
//  qipaicocos
//
//  Created by keven on 16/8/12.
//
//
#include <stdio.h>
#include "Game_Path_Manager.h"
#include "cocos2d.h"
#include "../DictionaryAide.h"

USING_NS_CC;
using namespace std;
//////////////////////////////////////////////////////////////////////////

Game_Path_Manager* Game_Path_Manager::msInstance = 0;

Game_Path_Manager* Game_Path_Manager::shared()
{
    if (msInstance == 0)
    {
        msInstance = new Game_Path_Manager();
    }
    
    return msInstance;
}

void Game_Path_Manager::purge()
{
    if (msInstance)
        delete msInstance;
    msInstance = 0;
}

///////////////////////////////////////////////////////////////////////////
Game_Path_Manager::Game_Path_Manager()
{
}

Game_Path_Manager::~Game_Path_Manager()
{
	map<int,vector<Move_Points>>::iterator it = _map.begin();
	if(it != _map.end()){
		it->second.clear();
	}
}

size_t game_pfwrite(void* data, int elemsize, int count, std::string &sz_path)
{
    unsigned char dataa[1024];
    int size_byte = elemsize*count;
    
    unsigned char* src = (unsigned char*)data;
    unsigned char* dest = dataa;
    
    for (int i = 0; i < size_byte; i++)
        *(dest++) = (*src++) ^ 0xDE;
    
    dataa[size_byte] = '\0';
    sz_path += (char*)dataa;
    
    return size_byte;
}

bool game_get_string_line(std::string& path, const std::string& all, unsigned int& start_pos)
{
    path.clear();
    int end_pos = 0;
    unsigned int  n = all.length();
    
    if ((start_pos >= 0) && (start_pos < n))
    {
        end_pos = all.find_first_of("\n ", start_pos);
        
        if ((end_pos < 0) && (end_pos >n))
            end_pos = n;
        
        path += all.substr(start_pos, end_pos - start_pos);
        start_pos = end_pos + 1;
        
    }
    return !path.empty();
}

bool game_path_load(std::vector<Move_Points>& paths, int count, const char* format)
{
    paths.clear();
    std::string sData;
    std::string line;
    
    for (int i = 0; i < count; i++)
    {
        
        char filename[128] = { 0 };
        sprintf(filename, format, i);
        //获得文件在系统的绝对路径
        std::string filepath = CCFileUtils::sharedFileUtils()->fullPathForFilename(filename);
        //读取的字节数，读取失败则为0
        ssize_t nread = 0;
        unsigned char * rdata = CCFileUtils::sharedFileUtils()->getFileData(filepath.c_str(), "rb", &nread);
        if (nread <= 0 || rdata == 0)
            return false;
        
        //解密
        sData.clear();
        sData.resize(nread, 0);
        for (int i = 0; i < nread; i++)
        {
            //printf(" %c" , rdata[i]);
            sData[i] = rdata[i] ^ 0xDE;
        }
        delete[] rdata;
    
        
        
        //新加路径
        paths.push_back(Move_Points());
        Move_Points &move_points = paths[paths.size() - 1];
        
        //每行读取
        unsigned int start_pos = 0;
        game_get_string_line(line, sData, start_pos);
        
        while (game_get_string_line(line, sData, start_pos))
        {
            int x, y, staff;
            float angle;
            //读取路径节点信息
            sscanf(line.c_str(), "(%d,%d,%f,%d)", &x, &y, &angle, &staff);
            //CCLOG("(%d,%d,%d,%d)", i, x, y, staff);
            move_points.push_back(Move_Point(xPoint(x, y), angle));
        }
    

    }
    
    return true;
}

static __Array* visitArray(const ValueVector& array);
static __Dictionary* visitDict(const ValueMap& dict)
{
	__Dictionary* ret = new __Dictionary();
	ret->init();

	for (auto iter = dict.begin(); iter != dict.end(); ++iter)
	{
		if (iter->second.getType() == Value::Type::MAP)
		{
			const ValueMap& subDict = iter->second.asValueMap();
			auto sub = visitDict(subDict);
			ret->setObject(sub, iter->first);
			sub->release();
		}
		else if (iter->second.getType() == Value::Type::VECTOR)
		{
			const ValueVector& arr = iter->second.asValueVector();
			auto sub = visitArray(arr);
			ret->setObject(sub, iter->first);
			sub->release();
		}
		else
		{
			auto str = new __String(iter->second.asString());
			ret->setObject(str, iter->first);
			str->release();
		}
	}
	return ret;
}

static __Array* visitArray(const ValueVector& array)
{
	__Array* ret = new __Array();
	ret->init();

	for (const auto &value : array) {
		if (value.getType() == Value::Type::MAP)
		{
			const ValueMap& subDict = value.asValueMap();
			auto sub = visitDict(subDict);
			ret->addObject(sub);
			sub->release();
		}
		else if (value.getType() == Value::Type::VECTOR)
		{
			const ValueVector& arr = value.asValueVector();
			auto sub = visitArray(arr);
			ret->addObject(sub);
			sub->release();
		}
		else
		{
			auto str = new __String(value.asString());
			ret->addObject(str);
			str->release();
		}
	}

	return ret;
}

bool Game_Path_Manager::initialise_paths(const std::string &directory)
{
	std::string fullPath = FileUtils::getInstance()->fullPathForFilename(directory);
	ValueVector arr2_ = FileUtils::getInstance()->getValueVectorFromFile(fullPath);

	__Array *arr2 = visitArray(arr2_);
	if (arr2){
		arr2->autorelease();
	}

	for (int j = 0, jl = (int)arr2->count(); j < jl; ++j)
	{
		__Dictionary* ani = (__Dictionary*)arr2->getObjectAtIndex(j);
		if(ani){
			DictionaryAide aide(ani);

			int type			= aide.intFromKey("path_type");
			int num				= aide.intFromKey("path_num");	
			const char* path	= aide.stringFromKey("path");

			if(_map.find(type) == _map.end()){

				vector<Move_Points>   save_paths_;
				game_path_load(save_paths_,num,path);

				_map.insert(pair<int,vector<Move_Points>>(type,save_paths_));
			}
		}
	}

    return true;
}



Move_Points &Game_Path_Manager::get_paths(unsigned short path_id, unsigned char path_type)
{
	 map<int,vector<Move_Points>>::iterator it = _map.find(path_type);
	if(it != _map.end()){

		vector<Move_Points> & vecPoints = it->second;
		if(vecPoints.size() > path_id){
			return vecPoints[path_id];
		}
	}

	return movePointsNull;	
}


///////////////////////////////////////////////////////////////////////////
