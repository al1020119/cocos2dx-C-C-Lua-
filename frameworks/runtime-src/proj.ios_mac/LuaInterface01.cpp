//
//  LuaInterface01.cpp
//  LuaInterface01-mobile
//
//  Created by iCocos on 2018/10/10.
//

#include "LuaInterface01.h"
#include "cocos2d.h"
#include <string>

USING_NS_CC;
using namespace std;

LuaInterface01 *LuaInterface01::i = NULL;

LuaInterface01 *LuaInterface01::shareInterface() {
    if (!i) {
        i = new LuaInterface01;
        i -> init();
    }
    return i;
}

void LuaInterface01::init() {
    // 创建一个Lua状态指针
    lua_State *luaState = luaL_newstate();
    luaL_openlibs(luaState);
    string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("Interface01.lua");
    luaL_dofile(luaState, path.c_str());
    lua_pcall(luaState, 0, 0, 0); // Hello iCocos LuaInterface01!
}
