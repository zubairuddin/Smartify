//
//  ViewController.m
//  Smartify
//
//  Created by Zubair.Nagori on 15/11/18.
//  Copyright © 2018 Applligent. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    self.device = [[TuyaSmartDevice alloc] initWithDeviceId:@"your_device_id"];

    //[self registerByEmail];
    //[self reloadDeviceList];
    [self loginByEmail];
}

- (void)registerByEmail {
    [[TuyaSmartUser sharedInstance] registerByEmail:@"91" email:@"zubairuddin33@gmail.com" password:@"Smartify@123" success:^{
        NSLog(@"register success");
    } failure:^(NSError *error) {
        NSLog(@"register failure: %@", error);
    }];
}
- (void)loginByEmail {
    [[TuyaSmartUser sharedInstance] loginByEmail:@"91" email:@"zubairuddin33@gmail.com" password:@"Smartify@123" success:^{
        NSLog(@"login success");
    } failure:^(NSError *error) {
        NSLog(@"login failure: %@", error);
    }];
}
- (void)reloadDeviceList {
    [[TuyaSmartUser sharedInstance] syncDeviceWithCloud:^{
        NSLog(@"syncDeviceWithCloud success");
        NSLog(@"deviceArray: %@", [TuyaSmartUser sharedInstance].deviceArray);
        NSLog(@"groupList: %@", [TuyaSmartUser sharedInstance].groupList);
    } failure:^(NSError *error){
        NSLog(@"syncDeviceWithCloud failure %@", error.localizedDescription);
    }];
}

@end
