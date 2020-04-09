//
//  NSString+DES.h
//  CHNAdMopubSDK
//
//  Created by Long on 2019/11/26.
//  Copyright © 2019 com.youloft.cq. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (DES)

- (NSData*)jm_hexStringConvertToBytesData;

- (NSString*)jm_urlDecode;

- (NSString*)jm_urlEncode;

/// 加密
/// @param key key
/// @param iv iv
- (NSString*)jm_encryptUseDESByKey:(NSString*)key iv:(NSString*)iv;

/// 解密
/// @param key key
/// @param iv iv
- (NSString*)jm_decryptUseDesByKey:(NSString*)key iv:(Byte [_Nullable])iv;

@end

NS_ASSUME_NONNULL_END
