//
//  NSString+Extension.h
//  CheYiDao
//
//  Created by 吴强 on 15/9/14.
//  Copyright (c) 2015年 红旗工作室. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (Extension)


/**
 获取不为空的字符串

 @return 返回一个不为空的字符串（当为NULL 或者 nil都是返回：暂无）
 */
- (NSString *)notEmptyValue;


/**
 *  截取字符串中的对应字节数字符
 *
 *  @param count 要截取出来的字节数
 *
 *  @return 截取后的字符串
 */
- (NSString *)cutByteWithNSStingByeBytesCount:(int)count;

/**
 *  判断字符串是否全为数字 不能包含小数点这些
 *
 *  @param string 需要判断的字符串
 *
 *  @return 判断结果 YES:全是数字 NO:不全是
 */
-(BOOL)isPureNumandCharacters:(NSString *)string;

/**
 *  判断字符串是否为浮点型
 *
 *  @param string 需要判断的字符串
 *
 *  @return 判断结果 YES:是浮点型 NO:不是浮点型
 */
- (BOOL)isPureFloat:(NSString *)string;

/**
 *  判断字符串是否有效
 *
 *  @return 判断结果，有效为YES，无效而NO
 */
- (BOOL)isEffective;
/**
 *  把手机号码中间几位显示为*****
 *
 *  @return 加密号码
 */
- (NSString *)changeMobileNumber;
/**
 *  判断字符串是否为有效Vin码
 *
 *  @param string 需要判断的字符串
 *
 *  @return 判断结果 YES:有效VIN码 NO:无效VIN码
 */
-(BOOL)isValidVinCode:(NSString *)string;
/**
 *  将字典转换为字符串
 *
 *  @param dic 需要转换的字典
 *
 *  @return 转换后的字符串
 */
- (NSString*)dictionaryToJson:(NSDictionary *)dic;
/**
 *  判断是否是正确的身份证号
 *
 *  @param identityCard 需要判断的字符串
 *
 *  @return 是否是的BOOL值
 */
- (BOOL)validateIdentityCard:(NSString *)identityCard;

/**
 *  根据时间转换
 */
- (NSString *)changeTimeWithInterval;

/**
 *  获取拼音首字母(传入汉字字符串, 返回大写拼音首字母)
 *
 *  @return 大写拼音首字母
 */
- (NSString *)firstCharactor;

/**
 *  将字符串转换为不为空的字符串
 *
 *  @return 当字符串为空时，赋值为暂无字段
 */
+ (NSString *)stringChangeToNotEmptyString:(NSString *)str;

+ (NSString *)jl_NotRounding:(float)price afterPoint:(int)position;

/**
 *  将丢失精度的double类型（如：9.99-9.9899999）转为（9.99）字符串
 *
 *  @param conversionValue 精度丢失有问题的Double类型
 *
 *  @return 不会丢失精度的字符串
 */
+(NSString *)jl_DecimalNumberWithDouble:(double )conversionValue;
/**
 *  将金额的Number类型转换为格式化好的字符串
 *
 *  @param money 金额
 *
 *  @param numberStyle 格式化类型
 *
 *  @return 格式化好了的字符串
 */
+(NSString *)jl_FormatAmountByMoneyNum:(NSNumber *)money andNumberStyle:(NSNumberFormatterStyle)numberStyle;

/**
 *  @author YYang, 16-02-08 23:02:04
 *
 *  判断字符串是否为空
 *
 *
 */
+ (BOOL) isBlankString:(NSString *)string;

@end
