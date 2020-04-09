//
//  AdManager.h
//  AdMopubSDK
//
//  Created by 蒋龙 on 2019/7/16.
//  Copyright © 2019 com.YouLoft.CQ. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


#define JLWeakSelf __weak typeof(self) weakSelf = self;
#define JLStrongSelf __strong typeof(self) strongSelf = weakSelf;

typedef NS_ENUM(NSInteger, BannerPosition) {
    BannerPosition_TopLeft = 0,
    BannerPosition_TopCenter = 1,
    BannerPosition_TopRight,
    BannerPosition_Centered,
    BannerPosition_BottomLeft,
    BannerPosition_BottomCenter,
    BannerPosition_BottomRight
};

NS_ASSUME_NONNULL_BEGIN

@protocol AdManagerDelegate <NSObject>

@optional
/**
 banner加载成功
 */
-(void)bannerDidLoadAdWithPosition:(NSString *)position;
/**
 banner加载失败

 @param errMsg 错误msg
 */
-(void)bannerDidFailToLoadWithPosition:(NSString *)position Msg:(NSString *)errMsg;
/**
 banner接收到点击事件
 */
-(void)bannerDidReceiveTapEventWithPosition:(NSString *)position;


/**
 interstitial加载成功
 */
-(void)interstitialDidLoadAdWithPosition:(NSString *)position;
/**
 interstitial加载失败， 仅在手动加载单条广告且加载失败时才会调用
 
 @param errMsg 错误msg
 */
-(void)interstitialDidFailToLoadWithPosition:(NSString *)position Msg:(NSString *)errMsg;
/**
 interstitial接收到点击事件
 */
-(void)interstitialDidReceiveTapEventWithPosition:(NSString *)position;
/**
 interstitial已经显示
 */
-(void)interstitialDidAppearWithPosition:(NSString *)position;
/**
 interstitial已经关闭
 */
-(void)interstitialDidDisappearWithPosition:(NSString *)position;



/**
 rewardedVideo加载成功
 */
-(void)rewardedVideoDidLoadAdWithPosition:(NSString *)position;
/**
 rewardedVideo加载失败， 仅在手动加载单条广告且加载失败时才会调用
 
 @param errMsg 错误msg
 */
-(void)rewardedVideoDidFailToLoadWithPosition:(NSString *)position Msg:(NSString *)errMsg;
/**
 rewardedVideo接收到点击事件
 */
-(void)rewardedVideoDidReceiveTapEventWithPosition:(NSString *)position;
/**
 rewardedVideo已经显示
 */
-(void)rewardedVideoDidAppearWithPosition:(NSString *)position;
/**
 rewardedVideo已经关闭
 */
-(void)rewardedVideoDidDisappearWithPosition:(NSString *)position;
/**
 rewardedVideo播放完成，应该给予奖励
 */
-(void)rewardedVideoAdShouldRewardWithPosition:(NSString *)position;


@end


@interface AdManager : UIViewController

/// 请求超时时间  默认30s
@property (nonatomic, assign) NSInteger timeOut;



/// 回调协议
@property (nonatomic, weak) id<AdManagerDelegate> delegate;


/**
 单例

 @return 返回当前单例对象
 */
+ (instancetype)sharedManager;


/**
 初始化Manager

 @param adJson json格式的所有参数，共计5个参数
 */
-(void)initAdWithAdJson:(NSString *)adJson;

/// 初始化友盟统计SDK
/// @param appKey 友盟appKey
/// @param channel 来源
- (void)initUmengWithAppkey:(NSString *)appKey channel:(NSString *)channel;

/// 初始化热云统计SDK
/// @param appKey 热云appKey
/// @param channel 来源
- (void)initReYunWithAppkey:(NSString *)appKey channel:(NSString *)channel;


//TODO:Banner相关函数
/**
 加载一个Banner类型的广告

 @param frame 广告位置、大小
 @param bannerSuperView 需要加载到那个视图上
 */
-(void)loadAndShowBannerAdWithFrame:(CGRect)frame InView:(UIView *)bannerSuperView Postion:(NSString *)postion;

/**
 隐藏当前显示的Banner
 */
-(void)hiddenBannerAd;


//TODO:interstitial相关函数
/**
 加载插屏广告
 */
-(void)loadInterstitialAdWithPostion:(NSString *)postion;

/**
 显示插屏广告到传入的VC上

 @param aVC 需要展示的VC
 */
-(void)showInterstitialAdWithViewController:(UIViewController *)aVC;

//TODO:rewardedVideo相关函数
/**
 加载奖励视频
 */
-(void)loadRewardedVideoAdWithPostion:(NSString *)postion;

/**
 判断是否有缓存就绪的广告
 
 @return 是否有就绪广告
 */
-(BOOL)hasRewardedVideo;

/**
 显示奖励视频到传入的VC上

 @param aVC 需要展示的VC
 */
-(void)showRewardedVideoAdWithViewController:(UIViewController *)aVC;




#pragma mark - Unavailable Initializers
/// 设置单例调用这些方法无效
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
