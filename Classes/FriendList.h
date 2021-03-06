//
//  FriendList.h
//  EziSocialDemo
//
//  Created by Paras Mendiratta on 04/05/13.
//
//


/***
 
 This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
 
 Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
 
 1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
 
 2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
 
 3. This notice may not be removed or altered from any source distribution.
 
 */

#ifndef __FacebookGameDemo__FriendList__
#define __FacebookGameDemo__FriendList__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "EziSocialDelegate.h"

class FriendList : public cocos2d::CCLayer,
                   public cocos2d::extension::CCTableViewDataSource,
                   public cocos2d::extension::CCTableViewDelegate,
                   public EziFacebookDelegate
{
    
public:
    
    virtual bool init();
                
    CREATE_FUNC(FriendList);
    
    // TableView Delegate Methods...
    virtual void scrollViewDidScroll(cocos2d::extension::CCScrollView* view) {};
    virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView* view) {}
    virtual void tableCellTouched(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);
    virtual cocos2d::CCSize cellSizeForTable(cocos2d::extension::CCTableView *table);
    virtual cocos2d::extension::CCTableViewCell* tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
    virtual unsigned int numberOfCellsInTableView(cocos2d::extension::CCTableView *table);
    
    // Facebook Delegate Methods...
    virtual void fbSessionCallback(int responseCode) {}
    virtual void fbUserDetailCallback(cocos2d::CCDictionary* data) {}
    virtual void fbMessageCallback(int responseCode) {}
    virtual void fbPageLikeCallback(int responseCode) {}
    virtual void fbFriendsCallback(cocos2d::CCArray* friends);
    virtual void fbHighScoresCallback(cocos2d::CCArray* highScores);
    virtual void fbUserPhotoCallback(const char *userPhotoPath);
    
    virtual void fbSendRequestCallback(int responseCode, cocos2d::CCArray* friendsGotRequests) {}
    virtual void fbRecieveRequestCallback(int responseCode,
                                          const char* message,
                                          const char* senderName,
                                          cocos2d::CCDictionary* dataDictionary) {}
    

    
    void setFriendsData(cocos2d::CCArray* friendList);
    
    virtual void update(float delta);
    
private:
    
    void showHomePage();
    void showHighScoreList();
    void showInstalledList();
    void showNotInstalledList();
    void showAllFriendsList();
    
    void downloadNextPhoto();
    void showLoadingAction();
    void hideLoadingAction();
    
    cocos2d::CCArray* mFriendList;
    cocos2d::extension::CCTableView* mTableView;
    cocos2d::CCSprite* mLoadingImage;
    
    bool mEnableHighScoreDisplay;
    bool mEnableInstalledDisplay;
    
    int mPhotoLoadIndex;
    
    bool mReadyForNextDownload;
};

    


#endif
