//
//  CCPlaySE.h
//  nyangame
//
//  Created by nishihara on 13/09/06.
//
//

#ifndef __nyangame__CCPlaySE__
#define __nyangame__CCPlaySE__

//#include <iostream>
#include "cocos2d.h"

class CCPlaySE : public cocos2d::CCActionInstant
{
public:
    CCPlaySE(std::string sound);
    virtual ~CCPlaySE(){};
    
    virtual void update(float time); // update関数に処理を記述する
    virtual CCFiniteTimeAction* reverse(void);
    virtual CCObject* copyWithZone(cocos2d::CCZone* pZone);
    
public:
    static CCPlaySE* create(std::string sound); // 効果音のファイル名を指定するcreate関数
    
protected:
    std::string m_sound; // ファイル名を保持するメンバ変数
};


#endif /* defined(__nyangame__CCPlaySE__) */
