//
//  ViewController.m
//  ChainAdSdkDemo
//
//  Created by 蒋龙 on 2020/4/9.
//  Copyright © 2020 com.youloft.cq. All rights reserved.
//

#import "ViewController.h"
#import <YLChnAdSDK/YLChnAdSDK.h>
#import <AuthenticationServices/AuthenticationServices.h>

#define BundleId [NSBundle mainBundle].bundleIdentifier
#define kTabBarHeight   50
#define kDeviceWidth [UIScreen mainScreen].bounds.size.width
#define KDeviceHeight [UIScreen mainScreen].bounds.size.height

#define isIOS7    ( [[[UIDevice currentDevice] systemVersion] compare:@"7.0"] != NSOrderedAscending )
#define isPad (UI_USER_INTERFACE_IDIOM()== UIUserInterfaceIdiomPad)
#define IS_IPHONE_X ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)
//判断iPHoneXr
#define IS_IPHONE_Xr ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
//判断iPhoneXs
#define IS_IPHONE_Xs ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
//判断iPhoneXs Max
#define IS_IPHONE_Xs_Max ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
// 是iPhone X 以上的机型
#define IS_IPHONE_X_UP ((IS_IPHONE_X==YES || IS_IPHONE_Xr ==YES || IS_IPHONE_Xs== YES || IS_IPHONE_Xs_Max== YES) ? YES : NO)

#define jl_weakify(var)   __weak typeof(var) weakSelf = var
#define jl_strongify(var) __strong typeof(var) strongSelf = var

//iPhoneX系列
#define Height_StatusBar ((IS_IPHONE_X==YES || IS_IPHONE_Xr ==YES || IS_IPHONE_Xs== YES || IS_IPHONE_Xs_Max== YES) ? 44.0 : 20.0)
#define Height_NavBar ((IS_IPHONE_X==YES || IS_IPHONE_Xr ==YES || IS_IPHONE_Xs== YES || IS_IPHONE_Xs_Max== YES) ? 88.0 : 64.0)
#define Height_TabBar ((IS_IPHONE_X==YES || IS_IPHONE_Xr ==YES || IS_IPHONE_Xs== YES || IS_IPHONE_Xs_Max== YES) ? 83.0 : 49.0)

static NSString *defKey = @"normal_reward_video";

@interface ViewController ()<AdManagerDelegate, ApplePayDelegate, ASAuthorizationControllerDelegate,ASAuthorizationControllerPresentationContextProviding>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    //如没有对应的id或不需要相应类型的广告，请在对应的类型下传入@[]
    NSDictionary *defDic = @{defKey:[NSDictionary convertJsonStringToNSDictionary:@"[{\"type\": 0, \"TTAD\": { \"appid\": \"5026701\", \"advertId\": \"926701392\", \"rate\": 100 }, \"GDTAD\": { \"appid\": \"1109896218\", \"advertId\": \"\", \"rate\": 0 } },{\"type\": 1, \"TTAD\": { \"appid\": \"5026701\", \"advertId\": \"926701189\", \"rate\": 100 }, \"GDTAD\": { \"appid\": \"1109896218\", \"advertId\": \"\", \"rate\": 0 } },{\"type\": 2, \"TTAD\": { \"appid\": \"5026701\", \"advertId\": \"945098384\", \"rate\": 100 }, \"GDTAD\": {\"appid\":\"1109896218\",\"advertId\": \"3011301479918697\", \"rate\": 0 } }]"]};
    
    NSDictionary *dic = @{@"gameid":@"9011e420-50fd-4b62-96b4-6dcaa26514ea",
                          @"gamesecret":@"",
                          @"appver":@"0",
                          @"lastver":@"0",
                          @"defaultjson":defDic
    };//9011e420-50fd-4b62-96b4-6dcaa26514ea 6ef864206a884e81819985c78767edad
    NSString *jsonStr = [NSDictionary convertNSDictionaryToJsonString:dic];

    [[AdManager sharedManager] initAdWithAdJson:jsonStr];
    [AdManager sharedManager].delegate = self;
    
    [[AdManager sharedManager] initUmengWithAppkey:@"appkey" channel:@"App Store"];
    [[AdManager sharedManager] initReYunWithAppkey:@"appKey" channel:@"App Store"];
    
    [[ApplePayAgent shareManager] setDelegate:self];
    
    [self addBtnsByArr:@[@"添加Banner广告", @"隐藏Banner广告", @"显示插屏广告", @"显示缓存视频", @"测试统计", @"发起内购"]];
    
    [self configUI];
    
}

-(void)addBtnsByArr:(NSArray *)titleArr {
    float viewW = CGRectGetWidth(self.view.frame);
    float btnX = viewW/2-100;
    
    for (int i=0; i<titleArr.count; i++) {
        NSString *title = titleArr[i];
        UIButton *btn = [UIButton buttonWithType:(UIButtonTypeSystem)];
        btn.frame = CGRectMake(btnX, 50 * (i+1), 200, 50);
        btn.tag = 100 + i;
        [btn addTarget:self action:@selector(btnAcWithSender:) forControlEvents:(UIControlEventTouchUpInside)];
        [btn setTitle:title forState:(UIControlStateNormal)];
//        [btn setTitleColor:[UIColor blackColor] forState:(UIControlStateNormal)];
        [self.view addSubview:btn];
    }
}

-(void)btnAcWithSender:(UIButton *)sender {
    switch (sender.tag-100) {
        case 0:
            [self loadAndShowBannerAdWithAdPostion:@"TopCenter"];//添加Banner广告
            break;
        case 1:
            [self hideBannerAd];//隐藏Banner广告
            break;
        case 2:
            [self loadInterstitialAd];//插屏广告
            break;
        case 3:
            [self loadRewardedVideoAd];//加载缓存视频
            break;
        case 4:
            [self customEventWithKey:@"AdLoadSucess" dicJsonStr:[NSDictionary convertNSDictionaryToJsonString:@{@"adID":@"1232141242131", @"adStates":@"0"}]];//测试统计
            break;
        case 5:
            [self applePayWithProductId:@"商品ID"];//加载缓存视频
            break;
            
        default:
            break;
    }
}

#pragma mark - 广告相关函数
- (UIViewController *)getRootViewController{
    UIWindow* window = nil;
    if (@available(iOS 13.0, *))
    {
        for (UIWindowScene* windowScene in [UIApplication sharedApplication].connectedScenes)
        {
            if (windowScene.activationState == UISceneActivationStateForegroundActive)
            {
                window = windowScene.windows.firstObject;

                break;
            }
        }
    }else{
        window = [UIApplication sharedApplication].keyWindow;
    }
    NSAssert(window, @"The window is empty");
    return window.rootViewController;
}

-(void)loadAndShowBannerAdWithAdPostion:(NSString *)adPostion {
//    TopLeft,TopCenter,TopRight,Centered,BottomLeft,BottomCenter,BottomRight
    if (adPostion != nil) {
        float adW = 320;
        float adH = 50;
        NSString *adPostionStr = adPostion.copy;
        CGRect frame = CGRectZero;
        if ([adPostionStr isEqualToString:@"TopLeft"]) {
            frame = CGRectMake(0, Height_StatusBar, adW, adH);
        }
        if ([adPostionStr isEqualToString:@"TopCenter"]) {
            frame = CGRectMake((kDeviceWidth-adW) / 2.0, Height_StatusBar, adW, adH);
        }
        if ([adPostionStr isEqualToString:@"TopRight"]) {
            frame = CGRectMake(kDeviceWidth-adW, Height_StatusBar, adW, adH);
        }
        if ([adPostionStr isEqualToString:@"Centered"]) {
            frame = CGRectMake((kDeviceWidth-adW) / 2.0, (KDeviceHeight/2.0 - adH/2.0), adW, adH);
        }
        if ([adPostionStr isEqualToString:@"BottomLeft"]) {
            frame = CGRectMake(0, KDeviceHeight - adH, adW, adH);
        }
        if ([adPostionStr isEqualToString:@"BottomCenter"]) {
            frame = CGRectMake((kDeviceWidth-adW) / 2.0, KDeviceHeight - adH, adW, adH);
        }
        if ([adPostionStr isEqualToString:@"BottomRight"]) {
            frame = CGRectMake(kDeviceWidth-adW, KDeviceHeight - adH, adW, adH);
        }
        
//        UIViewController *rootVC = [self getRootViewController];
        [[AdManager sharedManager] loadAndShowBannerAdWithFrame:frame InView:self.view Postion:defKey];
    }
}

-(void)hideBannerAd {
    [[AdManager sharedManager] hiddenBannerAd];
}

-(void)loadInterstitialAd {
    [[AdManager sharedManager] loadInterstitialAdWithPostion:defKey];
}

-(void)showInterstitialAd {
    UIViewController *rootVC = [self getRootViewController];
    [[AdManager sharedManager] showInterstitialAdWithViewController:rootVC];
}

-(void)loadRewardedVideoAd {
    [[AdManager sharedManager] loadRewardedVideoAdWithPostion:defKey];
}

-(bool)hasRewardedVideo {
    return [[AdManager sharedManager] hasRewardedVideo];
}

-(void)showRewardedVideoAd {
    UIViewController *rootVC = [self getRootViewController];
    [[AdManager sharedManager] showRewardedVideoAdWithViewController:rootVC];
}

#pragma mark - 统计相关函数
- (void)customEventWithKey:(NSString*)keyStr dicJsonStr:(NSString*)dicJsonStr {
    [AnalyticsManager customEventWithKey:keyStr dicJsonStr:dicJsonStr];
}

#pragma mark - 内购
- (void)applePayWithProductId:(NSString *)productId {
    if ([ApplePayAgent shareManager].delegate == nil) {
        [ApplePayAgent shareManager].delegate = self;
    }
    [[ApplePayAgent shareManager] payParams:productId];
}

-(void)configUI{
    if (@available(iOS 13.0, *)) {
        ASAuthorizationAppleIDButton *authorizationButton = [[ASAuthorizationAppleIDButton alloc]init];
        [authorizationButton addTarget:self action:@selector(click) forControlEvents:(UIControlEventTouchUpInside)];
//        authorizationButton.frame = CGRectMake(0, self.view.frame.size.height-80, 100, 44);
        authorizationButton.center = CGPointMake(self.view.center.x, self.view.center.y+100);
        [self.view addSubview:authorizationButton];
    } else {
        // Fallback on earlier versions
    }
}

-(void)click API_AVAILABLE(ios(13.0)){
    ASAuthorizationAppleIDProvider *appleIDProvider = [[ASAuthorizationAppleIDProvider alloc]init];
    ASAuthorizationAppleIDRequest *request = [appleIDProvider createRequest];
    request.requestedScopes = @[ASAuthorizationScopeFullName,ASAuthorizationScopeEmail];
    ASAuthorizationController *auth = [[ASAuthorizationController alloc]initWithAuthorizationRequests:@[request]];
    auth.delegate = self;
//    auth.presentationContextProvider = self;
    [auth performRequests];
}

///代理主要用于展示在哪里
//-(ASPresentationAnchor)presentationAnchorForAuthorizationController:(ASAuthorizationController *)controller API_AVAILABLE(ios(13.0)){
//    return self.view.window;
//}

-(void)authorizationController:(ASAuthorizationController *)controller didCompleteWithAuthorization:(ASAuthorization *)authorization API_AVAILABLE(ios(13.0)){
        if([authorization.credential isKindOfClass:[ASAuthorizationAppleIDCredential class]]){
            ASAuthorizationAppleIDCredential *credential = authorization.credential;
            
            NSString *state = credential.state;
            NSString *userID = credential.user;
            NSPersonNameComponents *fullName = credential.fullName;
            NSString *email = credential.email;
            NSString *authorizationCode = [[NSString alloc] initWithData:credential.authorizationCode encoding:NSUTF8StringEncoding]; // refresh token
            NSString *identityToken = [[NSString alloc] initWithData:credential.identityToken encoding:NSUTF8StringEncoding]; // access token
            ASUserDetectionStatus realUserStatus = credential.realUserStatus;
            
            NSLog(@"state: %@", state);
            NSLog(@"userID: %@", userID);
            NSLog(@"fullName: %@", fullName);
            NSLog(@"email: %@", email);
            NSLog(@"authorizationCode: %@", authorizationCode);
            NSLog(@"identityToken: %@", identityToken);
            NSLog(@"realUserStatus: %@", @(realUserStatus));
        }else if ([authorization.credential isKindOfClass:[ASPasswordCredential class]]){
            
            //// Sign in using an existing iCloud Keychain credential.
            ASPasswordCredential *pass = authorization.credential;
            NSString *username = pass.user;
            NSString *passw = pass.password;
            
        }
    
}

///回调失败
-(void)authorizationController:(ASAuthorizationController *)controller didCompleteWithError:(NSError *)error API_AVAILABLE(ios(13.0)){
    NSLog(@"%@",error);
}

#pragma mark - 回调函数
-(void)bannerDidLoadAdWithPosition:(NSString *)position{
    
}

-(void)bannerDidFailToLoadWithMsg:(NSString *)errMsg{
    NSLog(@"%@",errMsg);
}

-(void)bannerDidReceiveTapEventWithPosition:(NSString *)position{
    
}

-(void)interstitialDidLoadAdWithPosition:(NSString *)position {
    [[AdManager sharedManager] showInterstitialAdWithViewController:self];
}

-(void)interstitialDidFailToLoadWithMsg:(NSString *)errMsg{
    NSLog(@"%@",errMsg);
}

-(void)interstitialDidAppearWithPosition:(NSString *)position{
    
}

- (void)interstitialDidReceiveTapEventWithPosition:(NSString *)position{
    
}

-(void)interstitialDidDisappearWithPosition:(NSString *)position{
    
}

/**
 rewardedVideo加载成功
 */
-(void)rewardedVideoDidLoadAdWithPosition:(NSString *)position {
    [[AdManager sharedManager] showRewardedVideoAdWithViewController:self];
}
/**
 rewardedVideo加载失败， 仅在手动加载单条广告且加载失败时才会调用
 
 @param errMsg 错误msg
 */
-(void)rewardedVideoDidFailToLoadWithPosition:(NSString *)position Msg:(NSString *)errMsg{
// 调用unity或cocos函数
}
/**
 rewardedVideo接收到点击事件
 */
-(void)rewardedVideoDidReceiveTapEventWithPosition:(NSString *)position {
// 调用unity或cocos函数
}
/**
 rewardedVideo已经显示
 */
-(void)rewardedVideoDidAppearWithPosition:(NSString *)position {
// 调用unity或cocos函数
}
/**
 rewardedVideo已经关闭
 */
-(void)rewardedVideoDidDisappearWithPosition:(NSString *)position {
// 调用unity或cocos函数
}
/**
 rewardedVideo播放完成，应该给予奖励
 */
-(void)rewardedVideoAdShouldRewardWithPosition:(NSString *)position {
    
}

-(void)applePayHaveResultWithMsg:(NSDictionary *)msgDic{
    NSString *resStr = msgDic[@"payResult"];
    NSString *msg = msgDic[@"payReason"];
    NSLog(@"%@", msg);
    
    if (resStr.intValue == 1) { //支付成功
        NSLog(@"支付成功");
    }else{ //支付失败
        NSLog(@"支付失败");
    }
}


@end
