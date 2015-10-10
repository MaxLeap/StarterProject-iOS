//
//  ViewController.m
//  MaxLeapStarterProject
//
//  Created by Sun Jin on 11/19/14.
//  Copyright (c) 2014 MaxLeap. All rights reserved.
//

#import "ViewController.h"
#import <MLHelpCenter/MLHelpCenter.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
}
- (IBAction)showFAQ:(id)sender {
    [[MLHelpCenter sharedInstance] showFAQs:self];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
