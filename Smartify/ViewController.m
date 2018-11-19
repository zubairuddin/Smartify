//
//  ViewController.m
//  Smartify
//
//  Created by Zubair.Nagori on 15/11/18.
//  Copyright © 2018 Applligent. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()<TuyaSmartDeviceDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    
    //[self registerByEmail];
    [self loginByEmail];
    //[self reloadDeviceList];
    //[self updateDeviceInfo];
    //[self getToken];
}

- (void)registerByEmail {
    [[TuyaSmartUser sharedInstance] registerByEmail:@"91" email:@"sohail.mansoori@gmail.com" password:@"Smartify@123" success:^{
        NSLog(@"register success");
    } failure:^(NSError *error) {
        NSLog(@"register failure: %@", error);
    }];
}
- (void)loginByEmail {
    [[TuyaSmartUser sharedInstance] loginByEmail:@"91" email:@"sohail.mansoori@gmail.com" password:@"Smartify@123" success:^{
        NSLog(@"login success");
        [self initDevice];
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

- (void)updateDeviceInfo {
    // self.device = [TuyaSmartDevice deviceWithDeviceId:@"your_device_id"];
    
    __weak typeof(self) weakSelf = self;
    
    //self.device = [[TuyaSmartDevice alloc] initWithDeviceId:@"vdevo154252546699219"];
    [self.device syncWithCloud:^{
        NSLog(@"syncWithCloud success");
        NSLog(@"deviceModel: %@", weakSelf.device.deviceModel);
        
    } failure:^(NSError *error) {
        NSLog(@"Unable to sync device : %@", error.localizedDescription);
    }];
}

- (void)getToken {
    [[TuyaSmartActivator sharedInstance] getToken:^(NSString *token) {
        NSLog(@"getToken success: %@", token);
        // TODO: startConfigWiFi
    } failure:^(NSError *error) {
        NSLog(@"getToken failure: %@", error.localizedDescription);
    }];
}

- (void)initDevice {
    self.device = [TuyaSmartDevice deviceWithDeviceId:@"vdevo154252546699219"];
    NSLog(@"Device is %@", self.device);
    
    self.device.delegate = self;
}

#pragma mark - TuyaSmartDeviceDelegate

- (void)device:(TuyaSmartDevice *)device dpsUpdate:(NSDictionary *)dps {
    NSLog(@"deviceDpsUpdate: %@", dps);
    // TODO: update UI
}

- (void)deviceInfoUpdate:(TuyaSmartDevice *)device {
    //device name,online update
}

- (void)deviceRemoved:(TuyaSmartDevice *)device {
    // device remove
}

@end
