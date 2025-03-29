//
//  PSModuleSearchController.h
//  PocketSword
//
//  Created by Nic Carter on 9/12/09.
//  Copyright 2009 The CrossWire Bible Society. All rights reserved.
//

#import "globals.h"
#import "PSIndexController.h"
#import "MBProgressHUD.h"
#import "PSSearchOptionTableViewController.h"

@class PSSearchHistoryItem;

@protocol PSModuleSearchControllerDelegate <NSObject>
@required
- (void)searchDidFinish:(PSSearchHistoryItem*)newSearchHistoryItem;
@end

@interface PSModuleSearchController : UIViewController <PSSearchOptionsDelegate, UITabBarControllerDelegate, MBProgressHUDDelegate, PSIndexControllerDelegate, UISearchBarDelegate, UITableViewDelegate, UITableViewDataSource> {

	id <PSModuleSearchControllerDelegate> __weak delegate;
	
	ShownTab listType;

	UITableView *searchQueryTable;
	UIView *searchQueryView;
	UITableView *searchResultsTable;
	UISearchBar *searchBar;
	BOOL switchingTabs;
	
	// the below are basically the current PSSearchHistoryItem
	//  should we remove them & simply have our own item instead?
	NSString *searchTerm;
	NSString *searchTermToDisplay;
	BOOL searchingEnabled;
	BOOL strongsSearch;
	BOOL fuzzySearch;
	PSSearchType searchType;
	PSSearchRange searchRange;
	NSString *bookName;
	NSMutableArray *results;
	NSArray *savedTablePosition;
}

@property (strong) UITableView *searchQueryTable;
@property (strong) UIView *searchQueryView;
@property (strong) UITableView *searchResultsTable;
@property (strong) UISearchBar *searchBar;

@property (nonatomic, weak) id <PSModuleSearchControllerDelegate> delegate;
@property (strong, readwrite) NSString *searchTerm;
@property (strong, readwrite) NSString *searchTermToDisplay;
@property (assign, readwrite) BOOL strongsSearch;
@property (assign, readwrite) BOOL fuzzySearch;
@property (assign, readwrite) PSSearchType searchType;
@property (assign, readwrite) PSSearchRange searchRange;
@property (strong, readwrite) NSString *bookName;
@property (strong, readwrite) NSMutableArray *results;
@property (strong, readwrite) NSArray *savedTablePosition;

- (id)initWithSearchHistoryItem:(PSSearchHistoryItem*)searchHistoryItem;

- (void)setSearchHistoryItem:(PSSearchHistoryItem*)searchHistoryItem;
- (void)setSearchTitle;

- (void)refreshView;
- (void)setListType:(ShownTab)listType;
- (ShownTab)listType;

- (void)saveTablePositionFromCurrentPosition;
- (void)notifyDelegateOfNewHistoryItem;

- (void)searchBarSearchButtonClicked:(UISearchBar *)sBar;

- (void)indexInstalled:(PSIndexController*)sender;

- (void)searchButtonPressed:(id)sender;

@end
