//
//  LuaInterface02.h
//  SingleLua-mobile
//
//  Created by iCocos on 2018/10/10.
//

#ifndef LuaInterface02_h
#define LuaInterface02_h

#include <stdio.h>
#include "lua.hpp"

#include "cocos2d.h"
USING_NS_CC;

class LuaInterface02 {
    
public:
    LuaInterface02();
    ~LuaInterface02();
    static LuaInterface02 *shareInterface();
    void init();
    
    void readVariable();
    void loadFunstion();
    
private:
    static LuaInterface02 *i;
    lua_State *m_pLuaState;
    
};


#endif /* LuaInterface02_h */
