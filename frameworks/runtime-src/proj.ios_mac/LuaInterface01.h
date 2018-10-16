//
//  LuaInterface01.hpp
//  LuaInterface01-mobile
//
//  Created by iCocos on 2018/10/10.
//

#ifndef LuaInterface01_h
#define LuaInterface01_h

#include <stdio.h>
#include "lua.hpp"

class LuaInterface01 {

public:
    static LuaInterface01 *shareInterface();
    
private:
    static LuaInterface01 *i;
    void init();
    
};

#endif /* LuaInterface01_hpp */
