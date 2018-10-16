//
//  LuaInterface02.cpp
//  SingleLua-mobile
//
//  Created by iCocos on 2018/10/10.
//


/**
 
 Lua与C/C++或C/C++语言之前那通信过程中，实际上更多的时候是对栈顶的元素进行操作
 从栈顶往下看索引是-1-2-3...
 从栈底往上看索引是1，2，3...
 无论从Lua调C/C++，还是C/C++调Lua，参数值都是最先被压入到栈顶的，最后结果值才会被压入到栈顶
 */

/**
 
 // 接入Lua到C/C++
 
     //删除
     //lua.c
     //luac.c
     //MakeFile
 
     //llex.c中trydecopoint, 修改里面decopoint=“.”
 
 */


#include "LuaInterface02.h"
#include <string>

using namespace std;

LuaInterface02 *LuaInterface02::i = NULL;

LuaInterface02::LuaInterface02() {
    
}
LuaInterface02::~LuaInterface02() {
    if (m_pLuaState) {
        lua_close(m_pLuaState);
        m_pLuaState = NULL;
    }
}

LuaInterface02 *LuaInterface02::shareInterface() {
    if (!i) {
        i = new LuaInterface02;
        i -> init();
    }
    return i;
}

// 调用C++
static int l_show(lua_State * L) {
    lua_pushstring(L, "String from C/C++");
    return 1;
}

void LuaInterface02::init() {
    m_pLuaState = luaL_newstate();
    luaL_openlibs(m_pLuaState);
    
    // 调用C++
    lua_pushcfunction(m_pLuaState, l_show);
    lua_setglobal(m_pLuaState, "show");
}

void LuaInterface02::readVariable() {
    string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("Interface02.lua");
    luaL_dofile(m_pLuaState, path.c_str());
    int err_relt = lua_pcall(m_pLuaState, 0, 0, 0);
    
    CCAssert(err_relt, "读取Lua文件错误");
    
    lua_getglobal(m_pLuaState, "username");
    char *rlt = (char*)lua_tostring(m_pLuaState, -1);  //lua_tonumber,lua_toboolean
    CCLOG("rlt is : %s", rlt);
    lua_pop(m_pLuaState, 1);
}

void LuaInterface02::loadFunstion() {
    string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("Interface02.lua");
    luaL_dofile(m_pLuaState, path.c_str());
    int err_relt = lua_pcall(m_pLuaState, 0, 0, -1);
    
    CCAssert(err_relt != -1, "读取Lua文件错误");
    
    lua_getglobal(m_pLuaState, "getResult");
    lua_pushnumber(m_pLuaState, 12);
    err_relt = lua_pcall(m_pLuaState, 1, 2, -1); // 1： 一个参数， 2：两个参数 ， -1：当出错的时候的返回值
    CCAssert(err_relt != -1, "访问函数报错");
    
    char *rlt = (char*)lua_tostring(m_pLuaState, -1);  //lua_tonumber,lua_toboolean
    CCLOG("rlt is : %s", rlt);
    char *rlt2 = (char*)lua_tostring(m_pLuaState, -2);  //lua_tonumber,lua_toboolean
    CCLOG("rlt2 is : %s", rlt2);
}

/**
 Hello iCocos LuaInterface01!
 rlt is : iCocos
 Enter Result
 x:12
 rlt is : Function
 rlt2 is : OK
 */
