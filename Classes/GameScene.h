//
//  GameScene.h
//  nyangame
//
//  Created by nishihara on 13/09/06.
//
//

#ifndef __nyangame__GameScene__
#define __nyangame__GameScene__

//#include <iostream>
#include "cocos2d.h"
#include "Config.h"

// 縦・横のコマ数
#define MAX_BLOCK_X 8
#define MAX_BLOCK_Y 8

// アニメーション
#define REMOVING_TIME 0.1f

// 背景画像のファイル名
#define PNG_BACKGROUND "background.png"

class GameScene : public cocos2d::CCLayer
{
protected:
    enum kTag
    {
        kTagBackground = 1,
        kTagBaseBlock = 10000, // コマの基準タグ
    };
    
    enum kZOrder
    {
        kZOrderBackground,
        kZOrderBlock, // コマの基準タグ
    };
    
    // 2-2-3
    cocos2d::CCSprite* m_background;
    void showBackground();
    
    // 2-2-4
    float m_blockSize; // コマの一片のサイズを記録
    std::map<kBlock, std::list<int> > m_blockTags; // コマの種類ごとのグループ
    // 関数定義
    void initForVariables();
    void showBlock();
    cocos2d::CCPoint getPosition(int posIndexX, int posIndexY);
    int getTag(int posIndexX, int posIndexY);
    
    // 2-2-5
    void getTouchBlockTag(cocos2d::CCPoint touchPoint, int &tag, kBlock &blockType);
    std::list<int> getSameColorBlockTags(int baseTag, kBlock blockType);
    void removeBlock(std::list<int> blockTags, kBlock blockType);
    bool hasSameColorBlock(std::list<int> blockTagList, int searchBlockTag);
    
    // 2-3-1
    void removingBlock(cocos2d::CCNode* block);
    
    
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameScene);
    
    virtual bool ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
};

#endif /* defined(__nyangame__GameScene__) */
