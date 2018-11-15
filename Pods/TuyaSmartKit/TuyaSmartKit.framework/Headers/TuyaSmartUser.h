//
//  TuyaSmartUser.h
//  TuyaSmartKit
//
//  Created by fengyu on 15/8/31.
//  Copyright (c) 2015年 Tuya. All rights reserved.
//

#ifndef TuyaSmart_TuyaSmartUser
#define TuyaSmart_TuyaSmartUser

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TuyaSmartKitConstants.h"
#import "TuyaSmartDeviceModel.h"
#import "TuyaSmartGroupModel.h"
#import "TuyaSmartDiscoveredDeviceModel.h"



/// 当用户登录信息过期后发出的通知
FOUNDATION_EXPORT NSString * const TuyaSmartUserNotificationUserSessionInvalid;

/// 当设备列表的数据有变化时发出的通知
FOUNDATION_EXPORT NSString * const TuyaSmartUserNotificationDeviceArrayChanged;

/// 当网络变化的时候发出的通知
FOUNDATION_EXPORT NSString * const TuyaSmartUserNotificationNetworkChanged;


@class TuyaSmartUser;

@protocol TuyaSmartUserDelegate <NSObject>

@optional

//发现局域网设备
- (void)user:(TuyaSmartUser *)user didDiscoveredLanDevice:(TuyaSmartDiscoveredDeviceModel *)deviceModel;

@end

/// 用户相关功能
@interface TuyaSmartUser : NSObject


/**
 *  单例
 */
+ (instancetype)sharedInstance;

//回调delegate
@property (nonatomic, weak) id <TuyaSmartUserDelegate> delegate;

/// Session ID
@property (nonatomic, strong, readonly) NSString *sid;

/// 用户唯一ID
@property (nonatomic, strong, readonly) NSString *uid;

/// 头像
@property (nonatomic, strong, readonly) NSString *headIconUrl;

/// 昵称
@property (nonatomic, strong, readonly) NSString *nickname;

/// 用户名 如果主账号是手机号，userName就是手机号 如果主账号是邮箱，userName就是邮箱
@property (nonatomic, strong, readonly) NSString *userName;

/// 手机号
@property (nonatomic, strong, readonly) NSString *phoneNumber;

/// 邮箱
@property (nonatomic, strong, readonly) NSString *email;

/// 国家区号
@property (nonatomic, strong, readonly) NSString *countryCode;

/// 是否已登录
@property (nonatomic, assign, readonly) BOOL isLogin;

/// 当前账号所在的国家区域 AY - 中国 、 AZ - 美国 、 EU - 欧洲
@property (nonatomic, strong, readonly) NSString *regionCode;

/// 当前账号所在区域的接口域名地址
@property (nonatomic, strong, readonly) NSDictionary *domain;

/// 设备列表
@property (nonatomic, strong, readonly) NSArray<TuyaSmartDeviceModel *> *deviceArray;

/// 群组列表
@property (nonatomic, strong, readonly) NSArray<TuyaSmartGroupModel *> *groupList;


#pragma mark - 手机验证码登录

/**
 *  发送验证码，用于手机验证码登录/注册，手机密码重置
 *
 *  @param countryCode 国家区号
 *  @param phoneNumber 手机号
 *  @param type        0 手机验证码登录 1 手机验证码注册 2 手机密码重置
 *  @param success     操作成功回调
 *  @param failure     操作失败回调
 */
- (void)sendVerifyCode:(NSString *)countryCode
           phoneNumber:(NSString *)phoneNumber
                  type:(NSInteger)type
               success:(TYSuccessHandler)success
               failure:(TYFailureError)failure;

/**
 *  发送验证码，用于手机验证码绑定手机号，更换手机号
 *
 *  @param countryCode 国家区号
 *  @param phoneNumber 手机号
 *  @param success     操作成功回调
 *  @param failure     操作失败回调
 */
- (void)sendBindVerifyCode:(NSString *)countryCode
               phoneNumber:(NSString *)phoneNumber
                   success:(TYSuccessHandler)success
                   failure:(TYFailureError)failure;

/**
 *  手机验证码登录
 *
 *  @param countryCode 国家区号
 *  @param phoneNumber 手机号
 *  @param code        验证码
 *  @param success     操作成功回调
 *  @param failure     操作失败回调
 */
- (void)login:(NSString *)countryCode
  phoneNumber:(NSString *)phoneNumber
         code:(NSString *)code
      success:(TYSuccessHandler)success
      failure:(TYFailureError)failure;

/**
 *  手机绑定
 *
 *  @param countryCode 国家区号
 *  @param phoneNumber 手机号
 *  @param code        验证码
 *  @param success     操作成功回调
 *  @param failure     操作失败回调
 */
- (void)mobileBinding:(NSString *)countryCode
          phoneNumber:(NSString *)phoneNumber
                 code:(NSString *)code
              success:(TYSuccessHandler)success
              failure:(TYFailureError)failure;

#pragma mark - 手机密码登录

/**
 *  手机注册
 *
 *  @param countryCode 国家区号
 *  @param phoneNumber 邮箱
 *  @param password    密码
 *  @param code        验证码
 *  @param success     操作成功回调
 *  @param failure     操作失败回调
 */
- (void)registerByPhone:(NSString *)countryCode
            phoneNumber:(NSString *)phoneNumber
               password:(NSString *)password
                   code:(NSString *)code
                success:(TYSuccessHandler)success
                failure:(TYFailureError)failure;

/**
 *  手机密码登录
 *
 *  @param countryCode 国家区号
 *  @param phoneNumber 手机号
 *  @param password    密码
 *  @param success     操作成功回调
 *  @param failure     操作失败回调
 */
- (void)loginByPhone:(NSString *)countryCode
         phoneNumber:(NSString *)phoneNumber
            password:(NSString *)password
             success:(TYSuccessHandler)success
             failure:(TYFailureError)failure;

/**
 *  手机密码重置
 *
 *  @param countryCode 国家区号
 *  @param phoneNumber 手机号
 *  @param newPassword 新密码
 *  @param code        验证码
 *  @param success     操作成功回调
 *  @param failure     操作失败回调
 */
- (void)resetPasswordByPhone:(NSString *)countryCode
                 phoneNumber:(NSString *)phoneNumber
                 newPassword:(NSString *)newPassword
                        code:(NSString *)code
                     success:(TYSuccessHandler)success
                     failure:(TYFailureError)failure;

#pragma mark - 邮箱登录

/**
 *  发送验证码，用于邮箱注册
 *
 *  @param countryCode 国家区号
 *  @param email       邮箱
 *  @param success     操作成功回调
 *  @param failure     操作失败回调
 */
- (void)sendVerifyCodeByRegisterEmail:(NSString *)countryCode
                                email:(NSString *)email
                              success:(TYSuccessHandler)success
                              failure:(TYFailureError)failure;



/**
 *  使用验证码进行邮箱注册
 *
 *  @param countryCode 国家区号
 *  @param email       邮箱
 *  @param password    密码
 *  @param code        验证码
 *  @param success     操作成功回调
 *  @param failure     操作失败回调
 */
- (void)registerByEmail:(NSString *)countryCode
                  email:(NSString *)email
               password:(NSString *)password
                   code:(NSString *)code
                success:(TYSuccessHandler)success
                failure:(TYFailureError)failure;




/**
 *  邮箱注册
 *
 *  @param countryCode 国家区号
 *  @param email       邮箱
 *  @param password    密码
 *  @param success     操作成功回调
 *  @param failure     操作失败回调
 */
- (void)registerByEmail:(NSString *)countryCode
                  email:(NSString *)email
               password:(NSString *)password
                success:(TYSuccessHandler)success
                failure:(TYFailureError)failure;

/**
 *  邮箱登录
 *
 *  @param countryCode 国家区号
 *  @param email       邮箱
 *  @param password    密码
 *  @param success     操作成功回调
 *  @param failure     操作失败回调
 */
- (void)loginByEmail:(NSString *)countryCode
               email:(NSString *)email
            password:(NSString *)password
             success:(TYSuccessHandler)success
             failure:(TYFailureError)failure;

/**
 *  发送验证码，用于邮箱密码重置
 *
 *  @param countryCode 国家区号
 *  @param email       邮箱
 *  @param success     操作成功回调
 *  @param failure     操作失败回调
 */
- (void)sendVerifyCodeByEmail:(NSString *)countryCode
                        email:(NSString *)email
                      success:(TYSuccessHandler)success
                      failure:(TYFailureError)failure;

/**
 *  邮箱密码重置
 *
 *  @param countryCode 国家区号
 *  @param email       邮箱
 *  @param newPassword 新密码
 *  @param code        验证码
 *  @param success     操作成功回调
 *  @param failure     操作失败回调
 */
- (void)resetPasswordByEmail:(NSString *)countryCode
                       email:(NSString *)email
                 newPassword:(NSString *)newPassword
                        code:(NSString *)code
                     success:(TYSuccessHandler)success
                     failure:(TYFailureError)failure;

#pragma mark - uid登录

/**
 *  uid注册
 *
 *  @param uid         uid
 *  @param password    密码
 *  @param countryCode 国家区号
 *  @param success     操作成功回调
 *  @param failure     操作失败回调
 */
- (void)registerByUid:(NSString *)uid
             password:(NSString *)password
          countryCode:(NSString *)countryCode
              success:(TYSuccessHandler)success
              failure:(TYFailureError)failure;

/**
 *  uid登录
 *
 *  @param uid         uid
 *  @param password    密码
 *  @param countryCode 国家区号
 *  @param success     操作成功回调
 *  @param failure     操作失败回调
 */
- (void)loginByUid:(NSString *)uid
          password:(NSString *)password
       countryCode:(NSString *)countryCode
           success:(TYSuccessHandler)success
           failure:(TYFailureError)failure;

/**
 *  uid密码重置
 *
 *  @param uid         uid
 *  @param newPassword 新密码
 *  @param countryCode 国家区号
 *  @param success     操作成功回调
 *  @param failure     操作失败回调
 */
- (void)resetPasswordByUid:(NSString *)uid
               newPassword:(NSString *)newPassword
               countryCode:(NSString *)countryCode
                   success:(TYSuccessHandler)success
                   failure:(TYFailureError)failure;


#pragma mark - 三方登录

/**
 *  QQ登录
 *
 *  @param countryCode 国家区号
 *  @param userId QQ授权登录获取的userId
 *  @param accessToken QQ授权登录获取的accessToken
 *  @param success 操作成功回调
 *  @param failure 操作失败回调
 */
- (void)loginByQQ:(NSString *)countryCode
           userId:(NSString *)userId
      accessToken:(NSString *)accessToken
          success:(TYSuccessHandler)success
          failure:(TYFailureError)failure;

/**
 *  微信登录
 *
 *  @param countryCode 国家区号
 *  @param code 微信授权登录获取的code
 *  @param success 操作成功回调
 *  @param failure 操作失败回调
 */
- (void)loginByWechat:(NSString *)countryCode
                 code:(NSString *)code
              success:(TYSuccessHandler)success
              failure:(TYFailureError)failure;


/**
 *  facebook登录
 *
 *  @param countryCode 国家区号
 *  @param token facebook授权登录获取的token
 *  @param success 操作成功回调
 *  @param failure 操作失败回调
 */
- (void)loginByFacebook:(NSString *)countryCode
                  token:(NSString *)token
                success:(TYSuccessHandler)success
                failure:(TYFailureError)failure;



/**
 *  twitter登录
 *
 *  @param countryCode 国家区号
 *  @param key twitter授权登录获取的key
 *  @param secret twitter授权登录获取的secret
 *  @param success 操作成功回调
 *  @param failure 操作失败回调
 */
- (void)loginByTwitter:(NSString *)countryCode
                   key:(NSString *)key
                secret:(NSString *)secret
               success:(TYSuccessHandler)success
               failure:(TYFailureError)failure;


#pragma mark - 


/**
 *  登出
 *
 *  @param success 操作成功回调
 *  @param failure 操作失败回调
 */
- (void)loginOut:(TYSuccessHandler)success
         failure:(TYFailureError)failure;

/**
 *  修改昵称
 *
 *  @param nickName 昵称
 *  @param success  操作成功回调
 *  @param failure  操作失败回调
 */
- (void)updateNickname:(NSString *)nickName
               success:(TYSuccessHandler)success
               failure:(TYFailureError)failure;

/**
 *  修改头像
 *
 *  @param headIcon 头像
 *  @param success  操作成功回调
 *  @param failure  操作失败回调
 */
- (void)updateHeadIcon:(UIImage *)headIcon
               success:(TYSuccessHandler)success
               failure:(TYFailureError)failure;

/**
 *  同步设备列表
 *
 *  @param success 操作成功回调
 *  @param failure 操作失败回调
 */
- (void)syncDeviceWithCloud:(TYSuccessHandler)success
                    failure:(TYFailureHandler)failure;


/**
 *  更新用户信息
 *
 *  @param success 操作成功回调
 *  @param failure 操作失败回调
 */
- (void)updateUserInfo:(TYSuccessHandler)success
               failure:(TYFailureError)failure;


/**
 *  获取体验中心设备列表
 *
 *  @param success 操作成功回调
 *  @param failure 操作失败回调
 */
- (void)getExperienceDeviceWithCloud:(void(^)(NSArray <TuyaSmartDeviceModel *> *list))success
                             failure:(TYFailureError)failure;




/**
 *  停用帐号（注销用户）
 *  一周后账号才会永久停用并删除以下你账户中的所有信息，在此之前重新登录，则你的停用请求将被取消
 *  @param success 操作成功回调
 *  @param failure 操作失败回调
 */
- (void)cancelAccount:(TYSuccessHandler)success
              failure:(TYFailureError)failure;



#pragma mark -

/// 取消未完成的操作
- (void)cancelRequest;

@end

#endif
