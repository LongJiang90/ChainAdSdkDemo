//
//  AdIDsModel.h
//  CHNAdMopubSDK
//
//  Created by 蒋龙 on 2019/11/26.
//  Copyright © 2019 com.youloft.cq. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface TTAD : NSObject

@property (nonatomic , copy) NSString     * appid;
@property (nonatomic , copy) NSString     * advertId;
@property (nonatomic , assign) NSInteger     rate;

@end

@interface GDTAD :NSObject

@property (nonatomic , copy) NSString    * appid;
@property (nonatomic , copy) NSString    * advertId;
@property (nonatomic , assign) NSInteger    rate;

@end

@interface AdIDsModel :NSObject
@property (nonatomic , assign) NSInteger              type;
@property (nonatomic , strong) TTAD              * TTAD;
@property (nonatomic , strong) GDTAD              * GDTAD;

@end
