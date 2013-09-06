//
//  BlockSprite.cpp
//  nyangame
//
//  Created by nishihara on 13/09/06.
//
//

#include "BlockSprite.h"

BlockSprite::BlockSprite()
{
    
}

BlockSprite::~BlockSprite()
{
    
}

BlockSprite* BlockSprite::createWithBlockType(kBlock blockType)
{
    BlockSprite *pRet = new BlockSprite();
    if (pRet && pRet->initWithBlockType(blockType))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

bool BlockSprite::initWithBlockType(kBlock blockType)
{
    if (!CCSprite::initWithFile(getBlockImageFileName(blockType))) {
        return false;
    }
    
    m_blockType = blockType;
    
    return true;
}

// コマのファイル名を返す
const char* BlockSprite::getBlockImageFileName(kBlock blockType)
{
    switch (blockType) {
        case kBlockRed:
            return "red.png";
            break;
        case kBlockBlue:
            return "blue.png";
            break;
        case kBlockYellow:
            return "yellow.png";
            break;
        case kBlockGreen:
            return "green.png";
            break;
        case kBlockGray:
            return "gray.png";
            break;

        default:
            CCAssert(false, "invalid blockType");
            break;
    }
}