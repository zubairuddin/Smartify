//
//  TuyaSmartSceneActionModel.h
//  TuyaSmartKit
//
//  Created by xuyongbo on 2017/9/4.
//  Copyright © 2017年 Tuya. All rights reserved.
//

#import "TuyaSmartSceneDPModel.h"

typedef NS_ENUM(NSInteger, TYSceneActionStatus)
{
    TYSceneActionStatusLoading = 0,
    TYSceneActionStatusSuccess,
    TYSceneActionStatusOffline,
    TYSceneActionStatusTimeout,
};

@interface TuyaSmartSceneActionModel : TYModel

/**
 任务id
 */
@property (nonatomic, strong) NSString *actionId;

/**
 设备id
 */
@property (nonatomic, strong) NSString *entityId;

/**
 设备名称 如：“智能插座”
 */
@property (nonatomic, strong) NSString *entityName;

/**
 场景id
 */
@property (nonatomic, strong) NSString *scenarioId;

/**
 任务显示内容 如：“开关 : 关闭”
 */
@property (nonatomic, strong) NSString *actionDisplay;

/**
 任务执行属性 如："dpIssue"
 */
@property (nonatomic, strong) NSString *actionExecutor;

/**
 执行属性value 如："{1 = 0, ...}"
 */
@property (nonatomic, strong) NSDictionary *executorProperty;

/**
 执行状态
 */
@property (nonatomic, assign) TYSceneActionStatus status;


- (instancetype)initWithSceneDPModel:(NSArray<TuyaSmartSceneDPModel *> *)modelArray;

@end
