//
//  NavigatorLeafView.h
//  PocketSword
//
//  Created by Nic Carter on 13/10/09.
//  Copyright 2009 The CrossWire Bible Society. All rights reserved.
//

#import "PSModuleDownloadItem.h"

@class SwordModule;

@interface NavigatorLeafView : UIViewController <UINavigationBarDelegate, PSModuleDownloadDelegate> {
	UIWebView *detailsWebView;

	SwordModule *module;
}

@property (strong, readwrite) SwordModule *module;
@property (strong) UIWebView *detailsWebView;

@end
