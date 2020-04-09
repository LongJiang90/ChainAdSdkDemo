//
//  Unitls.h
//  AdMopubSDK
//
//  Created by 蒋龙 on 2019/11/14.
//  Copyright © 2019 com.YouLoft.CQ. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface Unitls : NSObject

//获取当前屏幕显示的viewcontroller
+ (UIViewController *)getCurrentVC;



///存储 - 数据持久化保存的key
+ (void)mn_saveModel:(id)model key:(NSString *)key;

///读取 - 获取数据持久化保存的Model  - 要传入model的Class - 内部进行yyModel转模型
+ (id) mn_getSaveModelWithkey:(NSString *)key modelClass:(Class)modelClass;

@end

NS_ASSUME_NONNULL_END
