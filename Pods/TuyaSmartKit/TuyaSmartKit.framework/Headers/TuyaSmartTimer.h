//
//  TuyaSmartTimer.h
//  TuyaSmartKit
//
//  Created by remy on 16/4/28.
//  Copyright © 2016年 Tuya. All rights reserved.
//

#ifndef TuyaSmart_TuyaSmartTimer
#define TuyaSmart_TuyaSmartTimer

#import <Foundation/Foundation.h>
#import "TYModel.h"
#import "TuyaSmartKitConstants.h"

@interface TYTimerModel : TYModel

@property (nonatomic, strong) NSString *timerId;
@property (nonatomic, strong) NSString *date;
@property (nonatomic, strong) NSString *time;
@property (nonatomic, assign) BOOL     status;
@property (nonatomic, strong) NSString *loops;
@property (nonatomic, strong) NSDictionary *dps;

@end

@interface TYTimerTaskModel : TYModel

@property (nonatomic, strong) NSString  *taskName;
@property (nonatomic, assign) NSInteger status;

@end


/// 定时相关功能
@interface TuyaSmartTimer : NSObject

/**
 *  增加定时任务
 *
 *  @param task         定时任务名称
 *  @param loops        循环次数
 *  @param devId        设备Id或者群组Id
 *  @param time         定时任务下的定时钟
 *  @param dps          命令字典
 */
- (void)addTimerWithTask:(NSString *)task loops:(NSString *)loops devId:(NSString *)devId time:(NSString *)time dps:(NSDictionary *)dps success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/**
 *  获取定时任务状态
 *
 *  @param devId        设备Id或者群组Id
 */
- (void)getTimerTaskStatusWithDeviceId:(NSString *)devId success:(void(^)(NSArray<TYTimerTaskModel *> *list))success failure:(TYFailureError)failure;

/**
 *  更新定时任务状态
 *
 *  @param task         定时任务名称
 *  @param devId        设备Id或者群组Id
 *  @param status       定时组状态
 */
- (void)updateTimerTaskStatusWithTask:(NSString *)task devId:(NSString *)devId status:(NSInteger)status success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/**
 *  更新定时钟状态
 *
 *  @param task         定时任务名称
 *  @param devId        设备Id或者群组Id
 *  @param timerId      定时钟Id
 *  @param status       定时钟状态
 */
- (void)updateTimerStatusWithTask:(NSString *)task devId:(NSString *)devId timerId:(NSString *)timerId status:(NSInteger)status success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/**
 *  删除定时钟
 *
 *  @param task         定时任务名称
 *  @param devId        设备Id或者群组Id
 *  @param timerId      定时钟Id
 */
- (void)removeTimerWithTask:(NSString *)task devId:(NSString *)devId timerId:(NSString *)timerId success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/**
 *  更新定时钟
 *
 *  @param task         定时任务名称
 *  @param loops        循环次数
 *  @param devId        设备Id或者群组Id
 *  @param timerId      定时钟Id
 *  @param time         定时任务下的定时钟
 *  @param dps          命令字典
 */
- (void)updateTimerWithTask:(NSString *)task loops:(NSString *)loops devId:(NSString *)devId timerId:(NSString *)timerId time:(NSString *)time dps:(NSDictionary *)dps success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/**
 *  获取定时任务下所有定时钟
 *
 *  @param task         定时任务名称
 *  @param devId        设备Id或者群组Id
 */
- (void)getTimerWithTask:(NSString *)task devId:(NSString *)devId success:(void(^)(NSArray<TYTimerModel *> *list))success failure:(TYFailureError)failure;

/**
 *  获取设备所有定时任务下所有定时钟
 *  @param devId        设备Id或者群组Id
 */
- (void)getAllTimerWithDeviceId:(NSString *)devId success:(TYSuccessDict)success failure:(TYFailureError)failure;

/// 取消未完成的操作
- (void)cancelRequest;
@end

#endif
