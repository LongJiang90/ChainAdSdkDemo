//
//  JLCustomKeys.h
//  YLSDKCommon
//
//  Created by 蒋龙 on 2020/1/6.
//  Copyright © 2020 com.youloft.cq. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


///消耗虚拟道具
static NSString *customKey_SpendVirtualProps = @"spend_virtual_props";

/// 调用是否有激励视频方法上报，参数：channel-上报用户渠道来源
static NSString *customKey_VideoReadyInvoke = @"IsVideoReadyInvoke";
///激励视频填充是否成功 参数：Suc-1表示填充成功，0表示填充失败
static NSString *customKey_VideoReady = @"IsVideoReady";
///激励视频填充是否成功 参数：Suc-1表示填充成功，0表示填充失败
static NSString *customKey_VideoNotReady = @"NotVideoReady";

///用户等级提升 参数：Level-当前等级
static NSString *customKey_UserLevelUp = @"user_level_up";

///用户离线
static NSString *customKey_UserOutLine = @"user_out_line";

///创建角色
static NSString *customKey_CreateRoles = @"create_roles";

///更新角色信息 参数：itemName-变更信息名称，changeName-变更为什么了的名称或者ID
static NSString *customKey_UpdateRolesInfo = @"update_roles_info";

///关卡扫荡 参数：level-关卡名称或ID
static NSString *customKey_CheckpointSweep = @"checkpoint_sweep";

///游戏模式被进入 参数：model-模式名称或ID
static NSString *customKey_GameModeIsEnter = @"game_mode_is_enter";

///竞技胜利
static NSString *customKey_CompetitionVictory = @"competition_victory";

///竞技失败
static NSString *customKey_CompetitionFailure = @"competition_failure";



// ---------------本地存储Key-------------------------------------------
static NSString *k_Previous_Eventid = @"previous_eventid";
static NSString *k_Channel = @"channel";
static NSString *k_Platform = @"platform";
static NSString *k_PottingMobSDKVersion = @"PottingMobSDKVersion_CN";

/// 接口Token
static NSString *k_JK_Signture = @"Signture";
/// 接口获取到的数据字典
static NSString *k_JK_DataDic = @"DataDic";


// -------------------------------------------------------------------




//TODO: 友盟统计自定义Key的字符串枚举
// 事件名称
typedef NSString *YLoftEvent NS_STRING_ENUM;

FOUNDATION_EXPORT YLoftEvent const kYLoftEventGamePay;
FOUNDATION_EXPORT YLoftEvent const kYLoftEventGameUse;
FOUNDATION_EXPORT YLoftEvent const kYLoftEventGameStartLevel;
FOUNDATION_EXPORT YLoftEvent const kYLoftEventGameFinishLevel;
FOUNDATION_EXPORT YLoftEvent const kYLoftEventGameFailLevel;
FOUNDATION_EXPORT YLoftEvent const kYLoftEventGameBonus;

//NSString * const kYLoftEventGamePay = @"um_plus_game_pay";                 // 充值/游戏内购买
//NSString * const kYLoftEventGameUse = @"um_plus_game_use";                 // 消耗
//NSString * const kYLoftEventGameStartLevel = @"um_plus_game_startlevel";   // 开始关卡
//NSString * const kYLoftEventGameFinishLevel = @"um_plus_game_finishlevel"; // 关卡成功
//NSString * const kYLoftEventGameFailLevel = @"um_plus_game_faillevel";     // 关卡失败
//NSString * const kYLoftEventGameBonus = @"um_plus_game_bonus";             // 奖励

// 事件的参数
typedef NSString *YLoftEventParameter NS_STRING_ENUM;

FOUNDATION_EXPORT YLoftEventParameter const kYLoftEventParameterCash;
FOUNDATION_EXPORT YLoftEventParameter const kYLoftEventParameterSource;
FOUNDATION_EXPORT YLoftEventParameter const kYLoftEventParameterCoin;
FOUNDATION_EXPORT YLoftEventParameter const kYLoftEventParameterItemName;
FOUNDATION_EXPORT YLoftEventParameter const kYLoftEventParameterAmount;
FOUNDATION_EXPORT YLoftEventParameter const kYLoftEventParameterPrice;
FOUNDATION_EXPORT YLoftEventParameter const kYLoftEventParameterLevel;
FOUNDATION_EXPORT YLoftEventParameter const kYLoftEventParameterLevelName;

//NSString * const kYLoftEventParameterCash = @"game_cash"; // 真实货币
//NSString * const kYLoftEventParameterSource = @"game_source"; // 支付渠道
//NSString * const kYLoftEventParameterCoin = @"game_coin"; // 虚拟币数量
//NSString * const kYLoftEventParameterItemName = @"game_item"; // 道具名称
//NSString * const kYLoftEventParameterAmount = @"game_amount"; // 数量
//NSString * const kYLoftEventParameterPrice = @"game_price"; // 价格
//NSString * const kYLoftEventParameterLevel = @"game_level"; //等级或者关卡id
//NSString * const kYLoftEventParameterLevelName = @"game_level_name"; //等级或者关卡名称

@interface JLCustomKeys : NSObject

@end

NS_ASSUME_NONNULL_END
