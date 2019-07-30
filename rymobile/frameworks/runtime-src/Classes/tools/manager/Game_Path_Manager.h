//
//  Game_Path_Manager.h
//  qipaicocos
//
//  Created by keven on 16/8/12.
//
//

#ifndef Game_Path_Manager_h
#define Game_Path_Manager_h

#include "Move_Point_Manager.h"
#include <map>

using namespace std;
class Game_Path_Manager
{
private:
    static Game_Path_Manager* msInstance;
public:
    static Game_Path_Manager* shared();
    static void purge();
    
public:
    Move_Points &get_paths(unsigned short path_id, unsigned char path_type);
    
private:
    Game_Path_Manager();
    ~Game_Path_Manager();
    
public:
    bool initialise_paths(const std::string &directory);
private:
    map<int,vector<Move_Points>> _map;
    
	Move_Points		movePointsNull;
};

#endif /* Game_Path_Manager_h */
