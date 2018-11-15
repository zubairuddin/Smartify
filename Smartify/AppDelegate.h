//
//  AppDelegate.h
//  Smartify
//
//  Created by Zubair.Nagori on 15/11/18.
//  Copyright © 2018 Applligent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong) NSPersistentContainer *persistentContainer;

- (void)saveContext;


@end

