//
//  ApplePayAgent.h
//  TestProj
//
//  Created by DLWX on 2017/6/21.
//  Copyright © 2017年 DLWX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

static NSString *PayResultKey = @"payResult"; //支付状态：0-失败，1-成功
static NSString *PayReasonKey = @"payReason"; //支付结果：文字
static NSString *PayTradeIdKey = @"payTradeId"; //唯一支付凭证 unique server-provided identifier
static NSString *PayDescriptionKey = @"payDescription"; //支付详细信息


//json字符串里面包括购买过的商品id “productId”
//* 订单ID“orderId”
//* 订单消耗时间“purchaseTime”
//* 商品是否被消耗“acknowledged”


/// 商品名称
static NSString *Des_ProductName_Key = @"productName";
/// 商品ID
static NSString *Des_ProductId_Key = @"productId";
/// 订单ID
static NSString *Des_OrderId_Key = @"orderId";
/// 商品消耗时间
static NSString *Des_PurchaseTime_Key = @"purchaseTime";
/// 商品状态-是否被消耗
static NSString *Des_acknowledged_Key = @"acknowledged";



@protocol ApplePayDelegate <NSObject>

@optional

/// 支付有结果了
/// @param msgDic 回调字典
-(void)applePayHaveResultWithMsg:(NSDictionary *)msgDic;

/// 恢复购买回调
/// @param msgDic 回调字典
-(void)reStoreHaveResultWithMsg:(NSDictionary *)msgDic;

@end


@interface ApplePayAgent : NSObject

/// 回调协议
@property (nonatomic, weak) id<ApplePayDelegate> delegate;

+ (instancetype)shareManager;

/// 添加内购购买
/// @param productId 商品ID
-(void)payParams:(NSString *)productId;


/// 恢复购买
-(void)restore;


@end
