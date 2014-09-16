//
//  AppDelegate.m
//  Battalion
//
//  Copyright (c) 2014 trineroks. All rights reserved.
//

#import "AppDelegate.h"
#import "MainExec.h"
#import <Foundation/Foundation.h>

#import "Main.h"
#import "SDL.h"
#import "SDL_Setup.h"
#import "stdafx.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    // Override point for customization after application launch.
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];
    
    CGRect screenRect = [[UIScreen mainScreen] bounds];
    CGFloat screenWidth = screenRect.size.width;
    CGFloat screenHeight = screenRect.size.height;
    CGFloat screenScale = [[UIScreen mainScreen] scale];
    
    CMainExec* main = new CMainExec((int)(screenWidth * screenScale), (int)(screenHeight * screenScale));
	main->setNextState(STATE_GAME);
	main->exec();
	delete main;
    
//    int mouseX = 0;
//    int mouseY = 0;
//    int *board = NULL;
//    gamePoint boardDimensions;
//    boardDimensions.x = 14;
//    boardDimensions.y = 14;
//    
//    bool exit = false;
//    CSDL_Setup *csdl_setup = new CSDL_Setup(exit, (int)(screenWidth * screenScale), (int)(screenHeight * screenScale));
//    
//    CMain *test = new CMain(csdl_setup, board, boardDimensions, &mouseX, &mouseY);
//    
//    while (!exit && csdl_setup->getMainEvent()->type != SDL_QUIT)
//	{
//		SDL_GetMouseState(&mouseX, &mouseY);
//		csdl_setup->start();
//		test->GameExec();
//		csdl_setup->end();
//	}
//    
      return YES;
    
    
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
